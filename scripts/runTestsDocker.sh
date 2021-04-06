# Compile aw
cd aspose-words-cloud-cpp
mkdir -p build
mkdir -p settings

# start test section
set -e

export CC=gcc 
export CXX=g++
cmake -DCMAKE_BUILD_TYPE=Debug -S . -B ./build 
cmake --build ./build --config Debug --target aspose_words_cloud_test -- VERBOSE=1

# Generate credentials
echo "{
        \"ClientId\" : \"$1\",
        \"ClientSecret\" : \"$2\",
        \"BaseUrl\" : \"$3\"
      }" > ./settings/servercreds.json

# Run tests
cmake -E chdir ./build ctest -V -C Debug --gtest_output=xml:test_result.xml

cp ./build/tests/test_result.xml /out
cp checkResult.xml /out

# end test section
set +e

chmod 777 -R /out
