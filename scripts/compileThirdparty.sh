git clone https://github.com/Microsoft/cpprestsdk.git
git clone https://github.com/aspose-words-cloud/aspose-words-cloud-cpp

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
