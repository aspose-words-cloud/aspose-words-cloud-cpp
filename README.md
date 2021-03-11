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

## Enhancements in Version 21.3

- Added 'UpdateCreatedTimeProperty' save option
- Added Tables into HeaderFooter so it's possible to address paragraphs inside table which is located in headerfooter (sections/0/headersfooters/1/tables/0/rows/0/cells/0/paragraphs/0)


## Enhancements in Version 21.2

- Added delete all comments method


## Enhancements in Version 21.1

- Added online version for all API methods


## Enhancements in Version 20.11

- In configuration json file appSid / appKey has been replaced to clientId / clientSecret.
- In Words API initialization methods clientId parameter precedes clientSecret parameter.
- Fixed the problem with methods passing boolean values as query parameters (they were ignored by the server).

## Enhancements in Version 20.10

- Internal API changes.


## Enhancements in Version 20.9

- Added Batch API feature


## Enhancements in Version 20.8

- Added new api method (PUT '/words/{name}/compatibility/optimize') which is allows to optimize the document contents as well as default Aspose.Words behavior to a particular versions of MS Word
- Added 'ApplyBaseDocumentHeadersAndFootersToAppendingDocuments' option to 'DocumentEntryList' for AppendDocument API
- WithoutNodePath methods have been removed, pass null values instead


## Enhancements in Version 20.7

- Added 'Markdown' save format
- Added endpoint to update paragraph format without node path (PUT '/words/{name}/paragraphs/{index}/format')


## Enhancements in Version 20.6

- Added new methods:
  - DeleteAllParagraphTabStopsWithoutNodePath
  - DeleteParagraphTabStopWithoutNodePath
  - GetParagraphTabStopsWithoutNodePath
  - InsertOrUpdateParagraphTabStopWithoutNodePath
  - InsertParagraphWithoutNodePath
  - UpdateParagraphFormatWithoutNodePath
  - UpdateParagraphListFormatWithoutNodePath
  - DeleteParagraphListFormatWithoutNodePath
- DrawingObject related methods have been changed body content. Special request classes are introduced instead of strings.
- InsertOrUpdateParagraphTabStop, DeleteParagraphTabStop methods have been changed parameter order
- OoxmlSaveOptionsData.CompressionLevel property has been added


## Enhancements in Version 20.5

- Added methods to work with Word document lists
  - GetLists
  - GetList
  - InsertList
  - UpdateList
  - UpdateListLevel
- Added methods to work with styles
  - GetStyles
  - UpdateStyle
  - InsertStyle
  - CopyStyle
  - GetStyleFromDocumentElement
  - ApplyStyleToDocumentElement
- Added methods to work with paragraph list format
  - GetParagraphListFormat
  - GetParagraphListFormatWithoutNodePath
  - UpdateParagraphListFormat
  - DeleteParagraphListFormat
- Added methods to work with paragraph tab stops
  - GetParagraphTabStops
  - InsertOrUpdateParagraphTabStop
  - DeleteAllParagraphTabStops
  - DeleteParagraphTabStop
- Added methods to build reports
  - BuildReport
  - BuildReportOnline
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

Build Aspose.Words.Cloud SDK
```cmd
git clone https://github.com/aspose-words-cloud/aspose-words-cloud-cpp
cd aspose-words-cloud-cpp
mkdir .\build
cmake -G "Visual Studio 15 2017" -Thost=x64 -Ax64 -S . -B .\build
cmake --build .\build --config Debug --target words-cloud-test
```

Create servercreds.json in '<SDK-ROOT>\settings' directory:
````
{
	"ClientId" : "xxxx",
	"ClientSecret" : "xxxxx",
	"BaseUrl" : "xxx" 
}
````

Run tests
```cmd
cmake -E chdir aspose-words-cloud-cpp\build ctest -V -C Debug
```

### How to build and test Aspose.Words.Cloud SDK on Linux

Build Aspose.Words.Cloud SDK
```cmd
git clone https://github.com/aspose-words-cloud/aspose-words-cloud-cpp
cd aspose-words-cloud-cpp
mkdir -p ./build

cmake -DCMAKE_BUILD_TYPE=Debug -S . -B ./build 
cmake --build ./build --config Debug --target all_unity -- VERBOSE=1
```

Create servercreds.json in '<SDK-ROOT>/settings' directory:
````
{
	"ClientId" : "xxxx",
	"ClientSecret" : "xxxxx",
	"BaseUrl" : "xxx" 
}
````

Run tests
```cmd
cmake -E chdir ./build ctest -V -C Debug
```

The complete source code is available at [GitHub Repository](https://github.com/aspose-words-cloud/aspose-words-cloud-cpp).

### SDK Dependencies

- gcc version 8+ for Linux
- [VS Build Tools](https://aka.ms/vs/15/release/vs_buildtools.exe) for Windows
- [CMake](https://github.com/Kitware/CMake/releases/download/v3.15.3/cmake-3.15.3-win64-x64.msi)

## Getting started with the SDK

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
	// Start README example

	//  create client configuration
	auto config = std::make_shared<ApiConfiguration>(yourClientId, yourClientSecret);
	// optional step, default value is https://api.aspose.cloud
	config->setBaseUrl(baseUrl);

	// create API
	auto api = std::make_shared<WordsApi>(config);

	// read file content
	auto content = std::make_shared<HttpContent>();
	auto stream = std::make_shared<fs::ifstream>(localPath, std::ifstream::binary);
	content->setData(stream);
	content->setContentDisposition(_XPLATSTR("form-data"));

	// upload file
	std::shared_ptr<UploadFileRequest> uploadRequest = std::make_shared<UploadFileRequest>(content, remotePath, boost::none);
	api->uploadFile(uploadRequest).get();

	// call one of API methods
	auto request = std::make_shared<GetSectionsRequest>(remoteName, dataFolder, boost::none, boost::none, boost::none);
	auto response = api->getSections(request).get();
	auto sections = response.body->getSections();

	// End README example
```

[Product Page](https://products.aspose.cloud/words/cpp) | [Documentation](https://docs.aspose.cloud/display/wordscloud/Home) | [API Reference](https://apireference.aspose.cloud/words/) | [Code Samples](https://github.com/aspose-words-cloud/aspose-words-cloud-cpp) | [Blog](https://blog.aspose.cloud/category/words/) | [Free Support](https://forum.aspose.cloud/c/words) | [Free Trial](https://dashboard.aspose.cloud/#/apps)
