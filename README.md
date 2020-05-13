ASpose.Words Cloud SDK for C++ wraps Aspose.Words REST API so you could seamlessly integrate Microsoft Word® document generation, manipulation, conversion & inspection features into your own C++ applications.

# Word Document Processing in the Cloud

[Aspose.Words Cloud SDK for C++](https://products.aspose.cloud/words/cpp) allows to work with document headers, footers, page numbering, tables, sections, document comments, drawing objects, FormFields, fonts, hyperlinks, ranges, paragraphs, math objects, watermarks, track changes and document protection. It also assists in appending documents, splitting documents as well as converting document to other supported file formats. 

Feel free to explore the [Developer's Guide](https://docs.aspose.cloud/display/wordscloud/Developer+Guide) & [API Reference](https://apireference.aspose.cloud/words/) to know all about Aspose.Words Cloud API. 

## Document Processing Features

- Convert between various document-related formats, including Word to PDF & vice versa.
- Mail merge and report generation in the Cloud.
- Split & merge Word documents.
- Access Word document metadata.
- Find and replace text.
- Add & remove watermarks and protection.
- Read & write access to Document Object Model.

## Enhancements in Version 20.5

- Added methods to work with Word document lists
  - getLists
  - getList
  - insertList
  - updateList
  - updateListLevel
- Added methods to work with styles
  - getStyles
  - updateStyle
  - insertStyle
  - copyStyle
  - getStyleFromDocumentElement
  - applyStyleToDocumentElement
- Added methods to work with paragraph list format
  - getParagraphListFormat
  - getParagraphListFormatWithoutNodePath
  - updateParagraphListFormat
  - deleteParagraphListFormat
- Added methods to work with paragraph tab stops
  - g1etParagraphTabStops
  - insertOrUpdateParagraphTabStop
  - deleteAllParagraphTabStops
  - deleteParagraphTabStop
- Added methods to build reports
  - buildReport
  - buildReportOnline
- Added Shading property to ParagraphFormat

## Read & Write Document Formats

**Microsoft Word:** DOC, DOCX, RTF, DOT, DOTX, DOTM, FlatOPC (XML)
**OpenOffice:** ODT, OTT
**WordprocessingML:** XML
**Web:** HTML, MHTML, HtmlFixed
**Text:** TXT
**Fixed Layout:** PDF

## Save Document As

**Fixed Layout:** PDF/A, XPS, OpenXPS, PS
**Images:** JPEG, PNG, BMP, SVG, TIFF, EMF
**Others:** PCL

## Getting Started with Aspose.Words Cloud SDK for C++

Firstly, create an account at [Aspose for Cloud](https://dashboard.aspose.cloud/#/apps) to get your application information and free quota to use the API. 

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

The complete source code is available at [GitHub Repository](https://github.com/aspose-words-cloud/aspose-words-cloud-cpp).

### SDK Dependencies

- gcc version 8+ for Linux
- [VS Build Tools](https://aka.ms/vs/15/release/vs_buildtools.exe) for Windows
- [Boost libraray](https://dl.bintray.com/boostorg/release/1.68.0/source/boost_1_68_0.tar.gz)
- [Microsoft/cpprestsdk](https://github.com/Microsoft/cpprestsdk)
- [CMake](https://github.com/Kitware/CMake/releases/download/v3.15.3/cmake-3.15.3-win64-x64.msi)

## Getting strted vith the SDK

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
	auto config = std::make_shared<ApiConfiguration>(yourApiKey, yourApiSid);

	// create API
	auto api = std::make_shared<WordsApi>(config);

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

[Product Page](https://products.aspose.cloud/words/cpp) | [Documentation](https://docs.aspose.cloud/display/wordscloud/Home) | [API Reference](https://apireference.aspose.cloud/words/) | [Code Samples](https://github.com/aspose-words-cloud/aspose-words-cloud-cpp) | [Blog](https://blog.aspose.cloud/category/words/) | [Free Support](https://forum.aspose.cloud/c/words) | [Free Trial](https://dashboard.aspose.cloud/#/apps)