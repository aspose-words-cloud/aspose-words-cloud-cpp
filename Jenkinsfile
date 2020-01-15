properties([
	gitLabConnection('gitlab'),
	parameters([string(defaultValue: 'refs/heads/master', description: 'the branch to build', name: 'branch', trim: true)])
])

node('windows2019') {
	try {
		gitlabCommitStatus("checkout") {
			stage('checkout'){
				checkout([$class: 'GitSCM', branches: [[name: params.branch]], doGenerateSubmoduleConfigurations: false, extensions: [[$class: 'LocalBranch', localBranch: "**"]], submoduleCfg: [], userRemoteConfigs: [[credentialsId: '361885ba-9425-4230-950e-0af201d90547', url: 'https://git.auckland.dynabic.com/words-cloud/words-cloud-cpp.git']]])
			}
		}
		
		gitlabCommitStatus("windows_tests") {
			stage('windows_tests'){
				withCredentials([usernamePassword(credentialsId: '6839cbe8-39fa-40c0-86ce-90706f0bae5d', passwordVariable: 'WordsAppKey', usernameVariable: 'WordsAppSid')]) {
					bat 'docker build -f Dockerfile.windows -t aspose-words-cloud-cpp:windows --isolation=hyperv .'
					bat 'runInDocker.windows.bat %WordsAppKey% %WordsAppSid% https://api.aspose.cloud'
				}
			}
		}		
	} finally {
		bat 'docker system prune -f'
		deleteDir()
	}
}

node('words-lonux') {
	try {
		gitlabCommitStatus("checkout") {
			stage('checkout'){
				checkout([$class: 'GitSCM', branches: [[name: params.branch]], doGenerateSubmoduleConfigurations: false, extensions: [[$class: 'LocalBranch', localBranch: "**"]], submoduleCfg: [], userRemoteConfigs: [[credentialsId: '361885ba-9425-4230-950e-0af201d90547', url: 'https://git.auckland.dynabic.com/words-cloud/words-cloud-cpp.git']]])
			}
		}
		
		gitlabCommitStatus("linux_tests") {
			stage('linux_tests'){
				withCredentials([usernamePassword(credentialsId: '6839cbe8-39fa-40c0-86ce-90706f0bae5d', passwordVariable: 'WordsAppKey', usernameVariable: 'WordsAppSid')]) {
					sh 'docker build -f Dockerfile.linux -t aspose-words-cloud-cpp:linux .'
					sh 'docker build -f Dockerfile.tests.linux -t aspose-words-cloud-cpp-tests:linux .'
					sh 'docker run --rm -v "$PWD/out:/out/" aspose-words-cloud-cpp-tests:linux bash aspose-words-cloud-cpp/scripts/runAll.sh $WordsAppKey $WordsAppSid https://api.aspose.cloud'
				}
			}
		}		
	} finally {
		bat 'docker system prune -f'
		deleteDir()
	}
}