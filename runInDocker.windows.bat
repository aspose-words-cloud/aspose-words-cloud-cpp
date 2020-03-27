if exist out rmdir out /s /q
mkdir out

docker build -f Dockerfile.tests.windows -t aspose-words-cloud-cpp-tests:windows --isolation=hyperv .
docker run --rm --env accept_eula=Y --memory 4G -v "%cd%/scripts:C:/scripts" -v "%cd%/out:C:/out" --isolation=hyperv aspose-words-cloud-cpp-tests:windows cmd /c ".\scripts\runAll.bat %1 %2 %3"
exit /b %ERRORLEVEL%