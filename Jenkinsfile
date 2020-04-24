properties([
	gitLabConnection('gitlab'),
	[$class: 'ParametersDefinitionProperty', 
		parameterDefinitions: [
			[$class: 'StringParameterDefinition', name: 'branch', defaultValue: 'master', description: 'the branch to build'],
			[$class: 'StringParameterDefinition', name: 'apiUrl', defaultValue: 'https://api-qa.aspose.cloud', description: 'api url']
		]
	]
])

parallel windows: {
    node('windows2016') {
        try {
            gitlabCommitStatus("windows_checkout") {
                stage('windows_checkout'){
                    checkout([$class: 'GitSCM', branches: [[name: params.branch]], doGenerateSubmoduleConfigurations: false, extensions: [[$class: 'LocalBranch', localBranch: "**"]], submoduleCfg: [], userRemoteConfigs: [[credentialsId: '361885ba-9425-4230-950e-0af201d90547', url: 'https://git.auckland.dynabic.com/words-cloud/words-cloud-cpp.git']]])
                }
            }
            
            gitlabCommitStatus("windows_tests") {
                stage('windows_tests'){
                    withCredentials([usernamePassword(credentialsId: '6839cbe8-39fa-40c0-86ce-90706f0bae5d', passwordVariable: 'WordsAppKey', usernameVariable: 'WordsAppSid')]) {
                        try {
                            bat 'docker build -f Dockerfile.windows -t aspose-words-cloud-cpp:windows .'
                            def apiUrl = params.apiUrl
                            bat 'runInDocker.windows.bat %WordsAppKey% %WordsAppSid% %apiUrl%'
                        } finally {
                            junit '**\\out\\test_result.xml'
                        }
                    }
                }
            }		
        } finally {
            bat 'docker system prune -f'
            deleteDir()
        }
    }
}, linux: {
    node('words-linux') {
        try {
            gitlabCommitStatus("linux_checkout") {
                stage('linux_checkout'){
                    checkout([$class: 'GitSCM', branches: [[name: params.branch]], doGenerateSubmoduleConfigurations: false, extensions: [[$class: 'LocalBranch', localBranch: "**"]], submoduleCfg: [], userRemoteConfigs: [[credentialsId: '361885ba-9425-4230-950e-0af201d90547', url: 'https://git.auckland.dynabic.com/words-cloud/words-cloud-cpp.git']]])
                }
            }
            
            gitlabCommitStatus("linux_tests") {
                stage('linux_tests'){
                    withCredentials([usernamePassword(credentialsId: '6839cbe8-39fa-40c0-86ce-90706f0bae5d', passwordVariable: 'WordsAppKey', usernameVariable: 'WordsAppSid')]) {
                        try {
                            sh 'docker build -f Dockerfile.linux -t aspose-words-cloud-cpp:linux .'
                            sh 'docker build -f Dockerfile.tests.linux -t aspose-words-cloud-cpp-tests:linux .'
                            sh 'docker run --rm -v "$PWD/out:/out/" aspose-words-cloud-cpp-tests:linux bash aspose-words-cloud-cpp/scripts/runAll.sh $WordsAppKey $WordsAppSid $apiUrl'
                        } finally {
                            junit '**\\out\\test_result.xml'
                        }
                    }
                }
            }		
        } finally {
            sh 'docker system prune -f'
            deleteDir()
        }
    }
}