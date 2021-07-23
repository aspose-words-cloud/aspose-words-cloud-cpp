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
cmake -DCMAKE_BUILD_TYPE=Debug -S . -B ./build 
cmake --build ./build --config Debug --target aspose_words_cloud_test -- VERBOSE=1
cmake --build ./build --config Release --target aspose_words_cloud_test -- VERBOSE=1

mkdir -p ./build/artifacts
cp -v -R ./build/bin ./build/artifacts/bin
cp -v -R ./include ./build/artifacts/include
zip -r /out/linux-x64.zip ./build/artifacts/*

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
