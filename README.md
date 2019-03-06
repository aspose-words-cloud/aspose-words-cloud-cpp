# aspose-words-cloud-cpp
A C++library for communicating with the Aspose.Words Cloud API

## How to build on Windows

1. Build [Microsoft/cpprestsd](https://github.com/Microsoft/cpprestsdk)
```cmd
git clone https://github.com/Microsoft/cpprestsdk
mkdir build
mkdir install
cmake -G "Visual Studio 15 2017" -Thost=x64 -Ax64 -DCPPREST_EXCLUDE_WEBSOCKETS=ON -DCPPREST_EXCLUDE_COMPRESSION=ON -DCPPREST_EXCLUDE_BROTLI=ON -DBUILD_TESTS=OFF -DBUILD_SAMPLES=OFF -DCMAKE_INSTALL_PREFIX=install\cpprestsdk -S cpprestsdk -B build
cmake --build build --config Debug --target install
cmake --build build --config Release --target install
```

2. Build aspose-words-cloud-cpp
```cmd
git clone https://github.com/aspose-words-cloud/aspose-words-cloud-cpp
mkdir aspose-words-cloud-cpp\build
cmake -G "Visual Studio 15 2017" -Thost=x64 -Ax64 -DBOOST_ROOT=<path-to-boost> -Dcpprestsdk_ROOT=install\cpprestsdk -S aspose-words-cloud-cpp -B aspose-words-cloud-cpp\build
cmake --build aspose-words-cloud-cpp\build --config Debug --target words-cloud-test
```

3. Create servercreds.json in the root SDK directory:
````
{
	"AppKey" : "xxxxx",
	"AppSid" : "xxxx",
	"BaseUrl" : "xxx" 
}
````

4. Run tests
```cmd
cmake -E chdir aspose-words-cloud-cpp\build ctest -V -C Debug
```

## How to run tests in Windows Docker container

1. Create a base container
```cmd
docker build -f Dockerfile.windows -t aspose-words-cloud-cpp:windows .
```

2. Set CPPWC_AK, CPPWC_AS, CPPWC_BU environment variables to aaplication key, application SID, and base URL respectively.

3. Run tests
```cmd
runinDocker.windows
```

Reports are saved in out directory.

## How to run tests in Linux Docker container

1. Create a base container
```cmd
docker build -f Dockerfile.linux -t aspose-words-cloud-cpp:linux .
```

2. Set CPPWC_AK, CPPWC_AS, CPPWC_BU environment variables to aaplication key, application SID, and base URL respectively.

3. Run tests
```cmd
runinDocker.linux
```

Reports are saved in out directory.