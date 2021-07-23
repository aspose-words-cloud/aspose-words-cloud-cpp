properties([
	gitLabConnection('gitlab'),
	[$class: 'ParametersDefinitionProperty', 
		parameterDefinitions: [
			[$class: 'StringParameterDefinition', name: 'branch', defaultValue: 'master', description: 'the branch to build'],
			[$class: 'StringParameterDefinition', name: 'apiUrl', defaultValue: 'https://api-qa.aspose.cloud', description: 'api url'],
            [$class: 'BooleanParameterDefinition', name: 'ignoreCiSkip', defaultValue: false, description: 'ignore CI Skip'],
            [$class: 'StringParameterDefinition', name: 'credentialsId', defaultValue: '6839cbe8-39fa-40c0-86ce-90706f0bae5d', description: 'credentials id'],
		]
	]
])

def buildCacheImage = "git.auckland.dynabic.com:4567/words-cloud/api/cpp"
def needToBuildWindows = false
def needToBuildLinux = false

parallel windows: {
    node('windows2016') {
        try {
            gitlabCommitStatus("windows_checkout") {
                stage('windows_checkout'){
                    checkout([$class: 'GitSCM', branches: [[name: params.branch]], doGenerateSubmoduleConfigurations: false, extensions: [], submoduleCfg: [], userRemoteConfigs: [[credentialsId: '361885ba-9425-4230-950e-0af201d90547', url: 'https://git.auckland.dynabic.com/words-cloud/words-cloud-cpp.git']]])
                    bat 'git show -s HEAD > gitMessage'
                    def commitMessage = readFile('gitMessage').trim()
                    echo commitMessage
                    needToBuildWindows = params.ignoreCiSkip || !commitMessage.contains('[ci skip]')               
                    bat 'git clean -fdx'
                }
            }
            
            if (needToBuildWindows) {
                gitlabCommitStatus("windows_tests") {
                    stage('windows_tests'){
                        withCredentials([usernamePassword(credentialsId: 'cc2e3c9b-b3da-4455-b702-227bcce18895', usernameVariable: 'dockerrigistry_login', passwordVariable: 'dockerregistry_password')]) {
                            bat 'docker login -u "%dockerrigistry_login%" -p "%dockerregistry_password%" git.auckland.dynabic.com:4567'
                        }
                        withCredentials([usernamePassword(credentialsId: params.credentialsId, passwordVariable: 'WordsClientSecret', usernameVariable: 'WordsClientId')]) {
                            try {
                                bat """
                                    docker pull ${buildCacheImage}/wincore:latest || goto build
                                    exit /b 0
                                    
                                    :build
                                    docker build --cache-from=${buildCacheImage}/wincore:latest -t ${buildCacheImage}/wincore:latest -t aspose-words-cloud-cpp-tests:wincore - < Dockerfile.wincore || goto error
                                    docker build -t aspose-words-cloud-cpp-tests:windows -f Dockerfile.windows . || goto error
                                    exit /b 0
                                    
                                    :error
                                    exit /b 255
                                """
                            
                                bat (script: "docker build -t aspose-words-cloud-cpp-tests:windows -f Dockerfile.windows .")
                                def apiUrl = params.apiUrl
                                bat """
                                    if exist out rmdir out /s /q
                                    mkdir out

                                    docker run --rm --env accept_eula=Y --memory 4G -v "%cd%/out:C:/out" aspose-words-cloud-cpp-tests:windows cmd /c ".\\scripts\\runTestsDocker.bat %WordsClientId% %WordsClientSecret% %apiUrl%"
                                    exit /b %ERRORLEVEL%
                                    """
                            } finally {
                                archiveArtifacts artifacts: 'build/windows-x64.zip'
                                junit '**\\out\\test_result.xml'
                            }
                            
                            if (currentBuild.result == "UNSTABLE") {
                                currentBuild.result = "FAILURE"
                            }
                        }
                    }
                }
            }
        } finally {
            deleteDir()
        }
    }
}, linux: {
    node('words-linux') {
        try {
            gitlabCommitStatus("linux_checkout") {
                stage('linux_checkout'){                    
                    checkout([$class: 'GitSCM', branches: [[name: params.branch]], doGenerateSubmoduleConfigurations: false, extensions: [], submoduleCfg: [], userRemoteConfigs: [[credentialsId: '361885ba-9425-4230-950e-0af201d90547', url: 'https://git.auckland.dynabic.com/words-cloud/words-cloud-cpp.git']]])

                    sh 'git show -s HEAD > gitMessage'
                    def commitMessage = readFile('gitMessage').trim()
                    echo commitMessage
                    needToBuildLinux = params.ignoreCiSkip || !commitMessage.contains('[ci skip]')               
                    sh 'git clean -fdx'
                }
            }
            
            if (needToBuildLinux) {
                gitlabCommitStatus("linux_tests") {
                    stage('linux_tests'){
                        withCredentials([usernamePassword(credentialsId: 'cc2e3c9b-b3da-4455-b702-227bcce18895', usernameVariable: 'dockerrigistry_login', passwordVariable: 'dockerregistry_password')]) {
                            sh 'docker login -u "${dockerrigistry_login}" -p "${dockerregistry_password}" git.auckland.dynabic.com:4567'
                        }
                        withCredentials([usernamePassword(credentialsId: params.credentialsId, passwordVariable: 'WordsClientSecret', usernameVariable: 'WordsClientId')]) {
                            try {
                                sh (script: "docker pull ${buildCacheImage}/linux:latest")
                                sh (script: "docker build --cache-from=${buildCacheImage}/linux:latest -t ${buildCacheImage}/linux:latest -t aspose-words-cloud-cpp-tests:linux - < Dockerfile.linux")
                                sh (script: "docker push ${buildCacheImage}/linux:latest")

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
            }
        } finally {
            deleteDir()
        }
    }
}