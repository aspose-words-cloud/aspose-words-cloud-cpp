git clone https://github.com/aspose-words-cloud/aspose-words-cloud-cpp.git

REM Generate credentials
echo { "AppKey" : "%1", > C:\aspose-words-cloud-cpp\tests\servercreds.json
echo  "AppSid" : "%2", >> C:\aspose-words-cloud-cpp\tests\servercreds.json
echo  "BaseUrl" : "%3" >> C:\aspose-words-cloud-cpp\tests\servercreds.json
echo } >> aspose-words-cloud-cpp\tests\servercreds.json

REM Compile aw
mkdir aspose-words-cloud-cpp\build
cmake -G "Visual Studio 15 2017" -Thost=x64 -Ax64 -Dcpprestsdk_ROOT=install/cpprestsdk -S aspose-words-cloud-cpp -B aspose-words-cloud-cpp/build
cmake --build aspose-words-cloud-cpp/build --config Debug --target words-cloud-test

REM Run tests
cmake -E chdir aspose-words-cloud-cpp/build ctest -V -C Debug

REM Run code check
cppcheck aspose-words-cloud-cpp  --quiet --xml -iboost/ -iinstall/ -ithirdparty/ -iCMakeFiles/ --platform=win32W --enable=all --force --std=c++11 --suppress=useInitializationList --suppress=unusedFunction -Iaspose-words-cloud-cpp/sources/ -Iaspose-words-cloud-cpp/sources/model -Iaspose-words-cloud-cpp/sources/model/requests --suppress=missingIncludeSystem --suppress=missingInclude --suppress=unmatchedSuppression --output-file=checkResult.xml

xcopy .\aspose-words-cloud-cpp\build\tests\test_result.xml out\test_result.xml /Y
xcopy checkResult.xml out\checkResult.xml /Y
