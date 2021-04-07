Aspose.Words Cloud SDK for C++ wraps Aspose.Words REST API so you could seamlessly integrate Microsoft Word® document generation, manipulation, conversion & inspection features into your own C++ applications.

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
- Thread safe

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

### SDK Dependencies

- [OpenSSL 1.1.1 or newer](https://www.openssl.org/)

### How to build Aspose.Words.Cloud SDK on Windows

Build Aspose.Words.Cloud SDK
- Install [Microsoft Visual Studio 2019](https://visualstudio.microsoft.com/)
- Intsall [CMake 3.7 or newer](https://cmake.org/download/) and add "<CMAKE_INSTALATION_FOLDER>/bin" to PATH environment variable.
- Install [VcPkg](https://github.com/Microsoft/vcpkg) and add "<VCPKG_INSTALATION_FOLDER>" and "<VCPKG_INSTALATION_FOLDER>/installed/x64-windows" to PATH environment variable.

```cmd
vcpkg install openssl:x64-windows
git clone https://github.com/aspose-words-cloud/aspose-words-cloud-cpp
cd aspose-words-cloud-cpp
mkdir .\build
cmake -G "Visual Studio 16 2019" -Thost=x64 -Ax64 -S . -B ./build
cmake --build ./build --config Release --target aspose_words_cloud_sdk
```

Create servercreds.json in '<SDK-ROOT>/settings' directory:
````
{
    "ClientId" : "xxxx",
    "ClientSecret" : "xxxxx"
}
````

Run tests
```cmd
cmake --build .\build --config Debug --target aspose_words_cloud_test
cmake -E chdir ./build ctest -V -C Debug
```

### How to build and test Aspose.Words.Cloud SDK on Linux

Required packages:
 - gcc >= 8.1
 - cmake >= 3.7
 - openssl >= 1.1.1

Build Aspose.Words.Cloud SDK
```cmd
sudo apt-get install gcc cmake openssl-dev
git clone https://github.com/aspose-words-cloud/aspose-words-cloud-cpp
cd aspose-words-cloud-cpp
mkdir -p ./build

cmake -DCMAKE_BUILD_TYPE=Release -S . -B ./build 
cmake --build ./build --config Release --target aspose_words_cloud_sdk
```

Create servercreds.json in '<SDK-ROOT>/settings' directory:
````
{
    "ClientId" : "xxxx",
    "ClientSecret" : "xxxxx"
}
````

Run tests
```cmd
cmake --build ./build --config Release --target aspose_words_cloud_test
cmake -E chdir ./build ctest -V -C Debug
```

The complete source code is available at [GitHub Repository](https://github.com/aspose-words-cloud/aspose-words-cloud-cpp).

## Getting started with the SDK

Add "<SDK_ROOT>/include" directory to your project includes path.
Link "<SDK_ROOT>/build/aspose_words_cloud_sdk/Release/aspose_words_cloud_sdk.lib" with your project.
Link "<SDK_ROOT>/build/bin/Release/aspose_words_cloud_sdk.dll" for windows or "<SDK_ROOT>/build/bin/Release/aspose_words_cloud_sdk.so" for linux with your project.

Typical usage of the SDK in code follows this template:
```
    // Start README example
    using namespace aspose::words::cloud;

    // Create client configuration
    auto config = std::make_shared<ApiConfiguration>(yourClientId, yourClientSecret, /*optional*/baseUrl);

    // Create API
    auto api = std::make_shared<api::WordsApi>(config);

    // Read file content
    auto stream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(localPath), std::ifstream::binary));

    // upload file
    auto uploadRequest = std::shared_ptr<requests::UploadFileRequest>(
        new requests::UploadFileRequest(stream, remotePath)
    );
    auto uploadResult = api->uploadFile(uploadRequest);

    // call one of API methods
    auto request = std::shared_ptr<requests::GetSectionsRequest>(
        new requests::GetSectionsRequest(remoteName, remoteDir)
    );
    auto response = api->getSections(request);
    auto sections = response->getSections();

    // End README example
```

[Product Page](https://products.aspose.cloud/words/cpp) | [Documentation](https://docs.aspose.cloud/display/wordscloud/Home) | [API Reference](https://apireference.aspose.cloud/words/) | [Code Samples](https://github.com/aspose-words-cloud/aspose-words-cloud-cpp) | [Blog](https://blog.aspose.cloud/category/words/) | [Free Support](https://forum.aspose.cloud/c/words) | [Free Trial](https://dashboard.aspose.cloud/#/apps)
