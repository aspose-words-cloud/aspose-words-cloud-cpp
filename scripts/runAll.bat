

REM Generate credentials
echo { "ClientId" : "%1", > aspose-words-cloud-cpp\servercreds.json
echo  "ClientSecret" : "%2", >> aspose-words-cloud-cpp\servercreds.json
echo  "BaseUrl" : "%3" >> aspose-words-cloud-cpp\servercreds.json
echo } >> aspose-words-cloud-cpp\servercreds.json

REM remove build directory
rmdir aspose-words-cloud-cpp\build /s /q

REM Compile aw
mkdir aspose-words-cloud-cpp\build
cmake -G "Visual Studio 15 2017" -Thost=x64 -Ax64 -Dcpprestsdk_ROOT=install/cpprestsdk -S aspose-words-cloud-cpp -B aspose-words-cloud-cpp/build || goto end
cmake --build aspose-words-cloud-cpp/build --config Debug --target all_unity || goto end

REM Run tests
cmake -E chdir aspose-words-cloud-cpp/build ctest -V -C Debug --gtest_output=xml:test_result.xml || goto end

REM Run code check
cppcheck aspose-words-cloud-cpp  --quiet --xml -iboost/ -iinstall/ -ithirdparty/ -iCMakeFiles/ --platform=win32W --enable=all --force --std=c++11 --suppress=useInitializationList --suppress=unusedFunction -Iaspose-words-cloud-cpp/sources/ -Iaspose-words-cloud-cpp/sources/model -Iaspose-words-cloud-cpp/sources/model/requests --suppress=missingIncludeSystem --suppress=missingInclude --suppress=unmatchedSuppression --output-file=checkResult.xml  || goto end

:end
if exist .\aspose-words-cloud-cpp\build\tests\test_result.xml copy .\aspose-words-cloud-cpp\build\tests\test_result.xml c:\out
if exist checkResult.xml copy checkResult.xml c:\out
exit /b %ERRORLEVEL%