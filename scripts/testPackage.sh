git clone https://github.com/Microsoft/cpprestsdk.git

# Compile cppcheck
cd /usr/bin/cppcheck-sources
make SRCBUILD=build CFGDIR=/usr/bin/cppcheck-sources
make install CFGDIR=/usr/bin/cppcheck-sources
cp cppcheck /usr/bin/cppcheck./

# Compile cpprestsdk
cd /
mkdir build
mkdir install
cmake -DCPPREST_EXCLUDE_WEBSOCKETS=ON -DCPPREST_EXCLUDE_COMPRESSION=ON -DCPPREST_EXCLUDE_BROTLI=ON -DBUILD_TESTS=OFF -DBUILD_SAMPLES=OFF -DCMAKE_INSTALL_PREFIX=install/cpprestsdk -S cpprestsdk -B build
cmake --build build --config Release --target install

mkdir -p aspose-words-cloud-cpp/app/build

# start test section
set -e

# Generate credentials
echo "{
        \"AppKey\" : \"$1\",
        \"AppSid\" : \"$2\",
        \"BaseUrl\" : \"$3\"
      }" > aspose-words-cloud-cpp/app/servercreds.json

# Compile aw
cmake -Dcpprestsdk_ROOT=install/cpprestsdk -DCMAKE_BUILD_TYPE=Release -S aspose-words-cloud-cpp/app -B aspose-words-cloud-cpp/app/build 
cmake --build aspose-words-cloud-cpp/app/build --config Release --target all_unity -- VERBOSE=1

# end test section
set +e

# Run tests
cmake -E chdir aspose-words-cloud-cpp/app/build ctest -V -C Release
cp aspose-words-cloud-cpp/app/build/tests/test_result.xml /out
chmod 777 -R out

