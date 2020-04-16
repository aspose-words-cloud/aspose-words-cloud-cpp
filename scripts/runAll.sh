# Compile cppcheck
cd /usr/bin/cppcheck-sources
make SRCBUILD=build CFGDIR=/usr/bin/cppcheck-sources
make install CFGDIR=/usr/bin/cppcheck-sources
cp cppcheck /usr/bin/cppcheck

# Compile cpprestsdk
cd /
git clone https://github.com/Microsoft/cpprestsdk.git
mkdir build
mkdir install
cmake -DCPPREST_EXCLUDE_WEBSOCKETS=ON -DCPPREST_EXCLUDE_COMPRESSION=ON -DCPPREST_EXCLUDE_BROTLI=ON -DBUILD_TESTS=OFF -DBUILD_SAMPLES=OFF -DCMAKE_INSTALL_PREFIX=install/cpprestsdk -S cpprestsdk -B build
cmake --build build --config Debug --target install
cmake --build build --config Release --target install

# Compile aw
mkdir -p aspose-words-cloud-cpp/build

# start test section
set -e

export CC=gcc 
export CXX=g++
cmake -Dcpprestsdk_ROOT=install/cpprestsdk -DCMAKE_BUILD_TYPE=Debug -S aspose-words-cloud-cpp -B aspose-words-cloud-cpp/build 
cmake --build aspose-words-cloud-cpp/build --config Debug --target all_unity -- VERBOSE=1

# Generate credentials
echo "{
        \"AppKey\" : \"$1\",
        \"AppSid\" : \"$2\",
        \"BaseUrl\" : \"$3\"
      }" > aspose-words-cloud-cpp/servercreds.json

# Run tests
cmake -E chdir aspose-words-cloud-cpp/build ctest -V -C Debug

# Run code check
cppcheck aspose-words-cloud-cpp  --quiet --xml -iboost/ -iinstall/ -ithirdparty/ -iCMakeFiles/ \
--platform=win32W --enable=all --force --std=c++11 --suppress=useInitializationList --suppress=unusedFunction \
-Iaspose-words-cloud-cpp/sources/ -Iaspose-words-cloud-cpp/sources/model -Iaspose-words-cloud-cpp/sources/model/requests --suppress=missingIncludeSystem --suppress=missingInclude \
--suppress=unmatchedSuppression --output-file=checkResult.xml

# end test section
set +e

