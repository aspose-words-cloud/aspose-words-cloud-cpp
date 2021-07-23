cd C:\\aspose-words-cloud-cpp

if exist build rmdir build /s /q
mkdir build

if exist settings rmdir settings /s /q
mkdir settings

REM Generate credentials
echo { "ClientId" : "%1", > .\settings\servercreds.json
echo  "ClientSecret" : "%2", >> .\settings\servercreds.json
echo  "BaseUrl" : "%3" >> .\settings\servercreds.json
echo } >> .\settings\servercreds.json

cmake -G "Visual Studio 15 2017" -Thost=x64 -Ax64 -S . -B ./build || goto end
cmake --build ./build --config Debug --target aspose_words_cloud_test || goto end
cmake --build ./build --config Release --target aspose_words_cloud_test || goto end

REM Copy artifacts
mkdir .\build\artifacts
Xcopy /E /I .\build\aspose_words_cloud_sdk\Debug .\build\artifacts\lib\Debug
Xcopy /E /I .\build\aspose_words_cloud_sdk\Release .\build\artifacts\lib\Release
Xcopy /E /I .\build\bin .\build\artifacts\bin
Xcopy /E /I .\include .\build\artifacts\include
powershell Compress-Archive .\build\artifacts\* c:\out\windows-x64.zip

REM Run tests
cmake -E chdir ./build ctest -V -C Debug --rerun-failed --output-on-failure --gtest_output=xml:test_result.xml || goto end

:end
if exist .\test_result.xml copy .\test_result.xml c:\out
exit /b %ERRORLEVEL%