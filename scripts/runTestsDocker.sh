# Compile aw
cd /aspose-words-cloud-cpp

if [ -d "build" ]; then rm -Rf build; fi
mkdir -p build

if [ -d "settings" ]; then rm -Rf settings; fi
mkdir -p settings

# start test section
set -e

export CC=gcc 
export CXX=g++
mkdir -p ./build/artifacts
cmake -DCMAKE_BUILD_TYPE=Debug -S . -B ./build
cmake --build ./build --config Debug --target aspose_words_cloud_sdk -- VERBOSE=1
cmake --build ./build --config Debug --target aspose_words_cloud_test -- VERBOSE=1
mkdir -p ./build/artifacts/bin/Debug
cp -v ./build/aspose_words_cloud_sdk/libaspose_words_cloud_sdk.so ./build/artifacts/bin/Debug/aspose_words_cloud_sdk.so
cp -v ./build/bin/aspose_words_cloud_test ./build/artifacts/bin/Debug/aspose_words_cloud_test

cmake --build ./build --config Release --target aspose_words_cloud_test -- VERBOSE=1
cmake --build ./build --config Release --target aspose_words_cloud_sdk -- VERBOSE=1
mkdir -p ./build/artifacts/bin/Release
cp -v ./build/aspose_words_cloud_sdk/libaspose_words_cloud_sdk.so ./build/artifacts/bin/Release/aspose_words_cloud_sdk.so
cp -v ./build/bin/aspose_words_cloud_test ./build/artifacts/bin/Release/aspose_words_cloud_test

cp -v -R ./include ./build/artifacts/include
cd ./build/artifacts
zip -r /out/linux-x64.zip ./*
cd ./../..

# Generate credentials
echo "{
        \"ClientId\" : \"$1\",
        \"ClientSecret\" : \"$2\",
        \"BaseUrl\" : \"$3\"
      }" > ./settings/servercreds.json

# Run tests
cmake -E chdir ./build ctest -V -C Debug --gtest_output=xml:test_result.xml

cp ./test_result.xml /out

# end test section
set +e

chmod 777 -R /out
