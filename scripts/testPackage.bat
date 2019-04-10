REM Copy all code
copy aspose-words-cloud-cpp\tests aspose-words-cloud-cpp\app
copy aspose-words-cloud-cpp\thirdparty aspose-words-cloud-cpp\app
copy aspose-words-cloud-cpp\Aspose.Words.Cloud aspose-words-cloud-cpp\app

REM Generate credentials
echo { "AppKey" : "%1", > aspose-words-cloud-cpp\servercreds.json
echo  "AppSid" : "%2", >> aspose-words-cloud-cpp\servercreds.json
echo  "BaseUrl" : "%3" >> aspose-words-cloud-cpp\servercreds.json
echo } >> aspose-words-cloud-cpp\test\servercreds.json

REM remove build directory
rmdir aspose-words-cloud-cpp\app\build /s /q
mkdir aspose-words-cloud-cpp\app\build

REM Compile aw
cmake -G "Visual Studio 15 2017" -Thost=x64 -Ax64 -Dcpprestsdk_ROOT=install/cpprestsdk -S aspose-words-cloud-cpp/app -B aspose-words-cloud-cpp/app/build
cmake --build aspose-words-cloud-cpp/app/build --config Release --target all_unity

REM Run tests
cmake -E chdir aspose-words-cloud-cpp/app/build ctest -V -C Release
copy .\aspose-words-cloud-cpp\app\build\tests\test_result.xml c:\out

