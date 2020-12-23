git.exe clone "https://github.com/aspose-words-cloud/aspose-words-cloud-cpp.git"
cd aspose-words-cloud-cpp & mkdir build & cd ../
cmake -G "Visual Studio 15 2017" -Thost=x64 -Ax64 -Dcpprestsdk_ROOT=install/cpprestsdk -S aspose-words-cloud-cpp/ -B aspose-words-cloud-cpp/build
cmake --build aspose-words-cloud-cpp/build --config Debug --target words-cloud-test
xcopy "C:\testdata" "C:\aspose-words-cloud-cpp\build\tests\testdata\" /Y /Q /S
copy "C:\testdata\servercreds.json" "C:\aspose-words-cloud-cpp\build\tests\servercreds.json" /Y