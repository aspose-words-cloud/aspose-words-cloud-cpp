properties([
	gitLabConnection('gitlab'),
	[$class: 'ParametersDefinitionProperty', 
		parameterDefinitions: [
			[$class: 'StringParameterDefinition', name: 'branch', defaultValue: 'master', description: 'the branch to build'],
			[$class: 'StringParameterDefinition', name: 'apiUrl', defaultValue: 'https://api-qa.aspose.cloud', description: 'api url'],
            [$class: 'BooleanParameterDefinition', name: 'ignoreCiSkip', defaultValue: false, description: 'ignore CI Skip'],
            [$class: 'StringParameterDefinition', name: 'credentialsId', defaultValue: '6839cbe8-39fa-40c0-86ce-90706f0bae5d', description: 'credentials id'],
            [$class: 'BooleanParameterDefinition', name: 'packageTesting', defaultValue: false, description: 'Testing package from repository without local sources. Used for prodhealthcheck'],
		]
	]
])

def buildCacheImage = "git.auckland.dynabic.com:4567/words-cloud/api/cpp"
def needToBuild = false
def packageTesting = false

node('words-linux') {
    try {
        stage('checkout'){
            packageTesting = params.packageTesting
            if (packageTesting) {
                needToBuild = true
                checkout([$class: 'GitSCM', branches: [[name: 'release']], doGenerateSubmoduleConfigurations: false, extensions: [], submoduleCfg: [], userRemoteConfigs: [[url: 'https://github.com/aspose-words-cloud/aspose-words-cloud-cpp.git']]])
            }
            else {
                checkout([$class: 'GitSCM', branches: [[name: params.branch]], doGenerateSubmoduleConfigurations: false, extensions: [], submoduleCfg: [], userRemoteConfigs: [[credentialsId: '361885ba-9425-4230-950e-0af201d90547', url: 'https://git.auckland.dynabic.com/words-cloud/words-cloud-cpp.git']]])
                sh 'git show -s HEAD > gitMessage'
                def commitMessage = readFile('gitMessage').trim()
                echo commitMessage
                needToBuild = params.ignoreCiSkip || !commitMessage.contains('[ci skip]')
            }
            
            sh 'git clean -fdx'
        }
        
        if (needToBuild) {
            stage('build') {
                withCredentials([usernamePassword(credentialsId: 'cc2e3c9b-b3da-4455-b702-227bcce18895', usernameVariable: 'dockerrigistry_login', passwordVariable: 'dockerregistry_password')]) {
                    sh 'docker login -u "${dockerrigistry_login}" -p "${dockerregistry_password}" git.auckland.dynabic.com:4567'
                    sh (script: "docker pull ${buildCacheImage}/linux:latest")
                    sh (script: "docker build --cache-from=${buildCacheImage}/linux:latest -t ${buildCacheImage}/linux:latest -t aspose-words-cloud-cpp-tests:linux - < Dockerfile.linux")
                    sh (script: "docker push ${buildCacheImage}/linux:latest")
                }
            }
            stage('tests') {
                withCredentials([usernamePassword(credentialsId: params.credentialsId, passwordVariable: 'WordsClientSecret', usernameVariable: 'WordsClientId')]) {
                    try {
                        sh 'docker run --rm -v "$PWD/out:/out/" -v "$PWD:/aspose-words-cloud-cpp" aspose-words-cloud-cpp-tests:linux bash /aspose-words-cloud-cpp/scripts/runTestsDocker.sh $WordsClientId $WordsClientSecret $apiUrl'
                    } finally {
                        junit '**\\out\\test_result.xml'
                    }
                    
                    if (currentBuild.result == "UNSTABLE") {
                        currentBuild.result = "FAILURE"
                    }
                }
            }
        }
    } finally {
        deleteDir()
    }
}