

# Aspose.Words.Cloud API SDK for C++
This repository contains Aspose.Words.Cloud SDK for C++ source code. This SDK allows you to work with Aspose.Words Cloud REST APIs in your Ruby applications quickly and easily, with zero initial cost.

## Key Features
* Conversion between various document-related formats (20+ formats supported), including PDF<->Word conversion
* Mail merge and reports generation 
* Splitting Word documents
* Accessing Word document metadata and statistics
* Find and replace
* Watermarks and protection
* Full read & write access to Document Object Model, including sections, paragraphs, text, images, tables, headers/footers and many others

See [API Reference](https://apireference.aspose.cloud/words/) for full API specification.

## How to use the SDK?
The complete source code is available in this repository folder. For more details, please visit our [documentation website](https://docs.aspose.cloud/display/wordscloud/Available+SDKs).

### Prerequisites

To use Aspose Words Cloud SDK for C++ you need to register an account with [Aspose Cloud](https://www.aspose.cloud/) and lookup/create App Key and SID at [Cloud Dashboard](https://dashboard.aspose.cloud/#/apps). There is free quota available. For more details, see [Aspose Cloud Pricing](https://purchase.aspose.cloud/pricing) .

### How to build Aspose.Words.Cloud SDK on Windows
Download and run installer for [Boost library](https://downloads.sourceforge.net/project/boost/boost-binaries/1.68.0/boost_1_68_0-msvc-14.0-64.exe?r=https%3A%2F%2Fsourceforge.net%2Fprojects%2Fboost%2Ffiles%2Fboost-binaries%2F1.68.0%2Fboost_1_68_0-msvc-14.0-64.exe%2Fdownload&ts=1545814847)

Build [Microsoft/cpprestsdk](https://github.com/Microsoft/cpprestsdk)
```cmd
git clone https://github.com/Microsoft/cpprestsdk
mkdir build
mkdir install
cmake -G "Visual Studio 15 2017" -Thost=x64 -Ax64 -DCPPREST_EXCLUDE_WEBSOCKETS=ON -DCPPREST_EXCLUDE_COMPRESSION=ON -DCPPREST_EXCLUDE_BROTLI=ON -DBUILD_TESTS=OFF -DBUILD_SAMPLES=OFF -DCMAKE_INSTALL_PREFIX=install\cpprestsdk -S cpprestsdk -B build
cmake --build build --config Debug --target install
```

Build Aspose.Words.Cloud SDK
```cmd
git clone https://github.com/aspose-words-cloud/aspose-words-cloud-cpp
mkdir aspose-words-cloud-cpp\build
cmake -G "Visual Studio 15 2017" -Thost=x64 -Ax64 -DBOOST_ROOT=<path-to-boost> -Dcpprestsdk_ROOT=install\cpprestsdk -S aspose-words-cloud-cpp -B aspose-words-cloud-cpp\build
cmake --build aspose-words-cloud-cpp\build --config Debug --target words-cloud-test
```

Create servercreds.json in aspose-words-cloud-cpp directory:
````
{
	"AppKey" : "xxxxx",
	"AppSid" : "xxxx",
	"BaseUrl" : "xxx" 
}
````

Run tests
```cmd
cmake -E chdir aspose-words-cloud-cpp\build ctest -V -C Debug
```

### How to build and test Aspose.Words.Cloud SDK on Linux
Build [Boost libraray](https://dl.bintray.com/boostorg/release/1.68.0/source/boost_1_68_0.tar.gz)
```cmd
wget https://dl.bintray.com/boostorg/release/1.68.0/source/boost_1_68_0.tar.gz -O /tmp/boost.tar.gz \
    && tar -xvzf /tmp/boost.tar.gz \ 
	&& cd boost_1_68_0 \
	&& ./bootstrap.sh  \
	&& ./b2 install \
	&& ldconfig
```

Build [Microsoft/cpprestsdk](https://github.com/Microsoft/cpprestsdk)
```cmd
git clone https://github.com/Microsoft/cpprestsdk.git

cd /
mkdir build
mkdir install
cmake -DCPPREST_EXCLUDE_WEBSOCKETS=ON -DCPPREST_EXCLUDE_COMPRESSION=ON -DCPPREST_EXCLUDE_BROTLI=ON -DBUILD_TESTS=OFF -DBUILD_SAMPLES=OFF -DCMAKE_INSTALL_PREFIX=install/cpprestsdk -S cpprestsdk -B build
cmake --build build --config Debug --target install
```

Build Aspose.Words.Cloud SDK
```cmd
mkdir -p aspose-words-cloud-cpp/build

cmake -Dcpprestsdk_ROOT=install/cpprestsdk -DCMAKE_BUILD_TYPE=Debug -S aspose-words-cloud-cpp -B aspose-words-cloud-cpp/build 
cmake --build aspose-words-cloud-cpp/build --config Debug --target all_unity -- VERBOSE=1
```

Create servercreds.json in aspose-words-cloud-cpp directory:
````
{
	"AppKey" : "xxxxx",
	"AppSid" : "xxxx",
	"BaseUrl" : "xxx" 
}
````

Run tests
```cmd
cmake -E chdir aspose-words-cloud-cpp/build ctest -V -C Debug
```
## Getting Started

Copy SDK files from the repository to target directory
```powershell
Get-ChildItem -Path aspose-words-cloud-cpp/sources | Copy-Item -Destination targetFolderPath -Recurse -Exclude (".*", "*.sh")
```

Add the SDK to your application in CMakeLists.txt:
```
add_subdirectory(Aspose.Words.Cloud targetFolderPath)
....
target_link_libraries(your_app_target PRIVATE Aspose::Words.Cloud)
```

Typical usage of the SDK in code follows this template:
```
	//  create client configuration
	auto config = std::make_shared<ApiConfiguration>();
	config->setAppKey(yourApiKey);
	config->setAppSid(yourApiSecret);
	config->setBaseUrl(apiBaseUrl);
	config->setApiVersion(apiVersion);
	web::http::client::http_client_config httpConfig;
	httpConfig.set_timeout(std::chrono::seconds(timeout));
	config->setHttpConfig(httpConfig);

	// create API client
	auto client = std::make_shared<ApiClient>();
	client->setConfiguration(config);

	// create API
	auto api = std::make_shared<WordsApi>(client);

	try
	{
		// call one of API methods
		auto request = std::make_shared<GetSectionsRequest>(docName, boost::none, boost::none, boost::none, boost::none);
		auto response = api->getSections(request).get();
		auto sections = response->getSections();
	}
	catch (ApiException& exception)
	{
		cout << "Error code: " << exception.error_code() << endl;
	}
```
## Contact Us
Your feedback is very important to us. Please feel free to contact us using our [Support Forums](https://forum.aspose.cloud/c/words).




