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
        \"ClientSecret\" : \"$1\",
        \"ClientId\" : \"$2\",
        \"BaseUrl\" : \"$3\"
      }" > aspose-words-cloud-cpp/servercreds.json

# Run tests
cmake -E chdir aspose-words-cloud-cpp/build ctest -V -C Debug --gtest_output=xml:test_result.xml

# Run code check
cppcheck aspose-words-cloud-cpp  --quiet --xml -iboost/ -iinstall/ -ithirdparty/ -iCMakeFiles/ \
--platform=win32W --enable=all --force --std=c++11 --suppress=useInitializationList --suppress=unusedFunction \
-Iaspose-words-cloud-cpp/sources/ -Iaspose-words-cloud-cpp/sources/model -Iaspose-words-cloud-cpp/sources/model/requests --suppress=missingIncludeSystem --suppress=missingInclude \
--suppress=unmatchedSuppression --output-file=checkResult.xml

cp aspose-words-cloud-cpp/build/tests/test_result.xml /out
cp checkResult.xml /out

# end test section
set +e

chmod 777 -R out
