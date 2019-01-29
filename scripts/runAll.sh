git clone https://github.com/Microsoft/cpprestsdk.git
git clone https://github.com/aspose-words-cloud/aspose-words-cloud-cpp
# Compile cppcheck
cd /usr/bin/cppcheck-sources
make -SRCBUILD=build CFGDIR=/usr/bin/cppcheck-sources
make install CFGDIR=/usr/bin/cppcheck-sources
cp build/bin/cppcheck /usr/bin/cppcheck

# Compile cpprestsdk
mkdir build
mkdir install
cmake -DCPPREST_EXCLUDE_WEBSOCKETS=ON -DCPPREST_EXCLUDE_COMPRESSION=ON -DCPPREST_EXCLUDE_BROTLI=ON -DBUILD_TESTS=OFF -DBUILD_SAMPLES=OFF -DCMAKE_INSTALL_PREFIX=install/cpprestsdk -S cpprestsdk -B build
cmake --build build --config Debug --target install
cmake --build build --config Release --target install

# Compile aw
mkdir aspose-words-cloud-cpp/build
cmake -Dcpprestsdk_ROOT=install/cpprestsdk -S aspose-words-cloud-cpp -B aspose-words-cloud-cpp/build
cmake --build aspose-words-sdk/build --config Debug --target words-cloud-test 2>>log.txt

# Run tests
cd /
cmake -E chdir aspose-words-cloud-cpp/build ctest -V -C Debug
cp aspose-words-cloud-cpp/build/tests/test_result.xml /out/test_result.xml

# Run code check
cd aspose-words-cloud-cpp
cppcheck . --xml -iboost/ -iinstall/ -ithirdparty/ -iCMakeFiles/ --platform=win32W --enable=all --force --std=c++11 --suppress=useInitializationList --suppress=unusedFunction -Isources/ -Isources/model -Isources/model/requests --suppress=missingIncludeSystem --suppress=missingInclude --suppress=unmatchedSuppression --output-file=checkResult.xml
cp checkResult.xml ../out/checkResult.xml
