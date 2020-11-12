REM Generate credentials
echo { "ClientId" : "%1", > aspose-words-cloud-cpp\app\servercreds.json
echo  "ClientSecret" : "%2", >> aspose-words-cloud-cpp\app\servercreds.json
echo  "BaseUrl" : "%3" >> aspose-words-cloud-cpp\app\servercreds.json
echo } >> aspose-words-cloud-cpp\app\servercreds.json

REM remove build directory
rmdir aspose-words-cloud-cpp\app\build /s /q

REM Compile aw
mkdir aspose-words-cloud-cpp\app\build
cmake -G "Visual Studio 15 2017" -Thost=x64 -Ax64 -Dcpprestsdk_ROOT=install/cpprestsdk -S aspose-words-cloud-cpp\app -B aspose-words-cloud-cpp\app\build  || goto end
cmake --build aspose-words-cloud-cpp\app\build --config Release --target all_unity  || goto end

REM Run tests
cmake -E chdir aspose-words-cloud-cpp\app\build ctest -V -C Release  || goto end
copy .\aspose-words-cloud-cpp\app\build\tests\test_result.xml c:\out

:end
exit /b %ERRORLEVEL%
