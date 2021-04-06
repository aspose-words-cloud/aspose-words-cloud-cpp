cd aspose-words-cloud-cpp

rmdir settings /s /q
mkdir settings

REM Generate credentials
echo { "ClientId" : "%1", > .\servercreds.json
echo  "ClientSecret" : "%2", >> .\servercreds.json
echo  "BaseUrl" : "%3" >> .\servercreds.json
echo } >> .\settings\servercreds.json

REM remove build directory
rmdir .\build /s /q

REM Compile aw
mkdir .\build
cmake -G "Visual Studio 15 2017" -Thost=x64 -Ax64 -S . -B ./build || goto end
cmake --build ./build --config Debug --target aspose_words_cloud_test || goto end

REM Run tests
cmake -E chdir ./build ctest -V -C Debug --rerun-failed --output-on-failure --gtest_output=xml:test_result.xml || goto end

:end
if exist .\test_result.xml copy .\test_result.xml c:\out
exit /b %ERRORLEVEL%