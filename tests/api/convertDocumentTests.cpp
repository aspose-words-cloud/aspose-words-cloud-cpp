/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="convertDocumentTests.cpp">
*   Copyright (c) 2021 Aspose.Words for Cloud
* </copyright>
* <summary>
*   Permission is hereby granted, free of charge, to any person obtaining a copy
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is
*  furnished to do so, subject to the following conditions:
* 
*  The above copyright notice and this permission notice shall be included in all
*  copies or substantial portions of the Software.
* 
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*  SOFTWARE.
* </summary> 
-------------------------------------------------------------------------------------------------------------------- **/

#include "../TestBase.h"

/// <summary>
/// Example of how to convert document to one of the available formats.
/// </summary>
class ConvertDocumentTests : public InfrastructureTest {
protected:
    utility::string_t remoteFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentActions/ConvertDocument");
    utility::string_t localFolder = STCONVERT("DocumentActions/ConvertDocument");

};

/// <summary>
/// Test for converting document to one of the available formats.
/// </summary>
TEST_F(ConvertDocumentTests, TestSaveAs) {
    utility::string_t localName = STCONVERT("test_multi_pages.docx");
    utility::string_t remoteName = STCONVERT("TestSaveAs.docx");

    UploadFileToStorage(
        remoteFolder + STCONVERT("/") + remoteName,
        path_combine(LocalTestDataFolder, STCONVERT("Common/") + localName)
    );

    auto requestSaveOptionsData = std::make_shared< SaveOptionsData >();
    requestSaveOptionsData->setSaveFormat(STCONVERT("pdf"));
    requestSaveOptionsData->setFileName(baseTestOutPath + STCONVERT("/TestSaveAs.pdf"));

    std::shared_ptr< SaveAsRequest > request(new SaveAsRequest(
        remoteName,
        requestSaveOptionsData,
        remoteFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->saveAs(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getSaveResult()));
   ASSERT_TRUE(IsNotNull(actual.body->getSaveResult()->getDestDocument()));
}



/// <summary>
/// Test for converting document to one of the available formats.
/// </summary>
TEST_F(ConvertDocumentTests, TestSaveAsDocx) {
    utility::string_t localName = STCONVERT("45.pdf");
    utility::string_t remoteName = STCONVERT("TestSaveAsFromPdfToDoc.pdf");

    UploadFileToStorage(
        remoteFolder + STCONVERT("/") + remoteName,
        path_combine(LocalTestDataFolder, localFolder + STCONVERT("/") + localName)
    );

    auto requestSaveOptionsData = std::make_shared< SaveOptionsData >();
    requestSaveOptionsData->setSaveFormat(STCONVERT("docx"));
    requestSaveOptionsData->setFileName(baseTestOutPath + STCONVERT("/TestSaveAsFromPdfToDoc.docx"));

    std::shared_ptr< SaveAsRequest > request(new SaveAsRequest(
        remoteName,
        requestSaveOptionsData,
        remoteFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->saveAs(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getSaveResult()));
   ASSERT_TRUE(IsNotNull(actual.body->getSaveResult()->getDestDocument()));
}

/// <summary>
/// Test for converting document to one of the available formats.
/// </summary>
TEST_F(ConvertDocumentTests, TestSaveAsTiff) {
    utility::string_t localName = STCONVERT("test_multi_pages.docx");
    utility::string_t remoteName = STCONVERT("TestSaveAsTiff.pdf");

    UploadFileToStorage(
        remoteFolder + STCONVERT("/") + remoteName,
        path_combine(LocalTestDataFolder, STCONVERT("Common/") + localName)
    );

    auto requestSaveOptions = std::make_shared< TiffSaveOptionsData >();
    requestSaveOptions->setSaveFormat(STCONVERT("tiff"));
    requestSaveOptions->setFileName(baseTestOutPath + STCONVERT("/abc.tiff"));

    std::shared_ptr< SaveAsTiffRequest > request(new SaveAsTiffRequest(
        remoteName,
        requestSaveOptions,
        remoteFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->saveAsTiff(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getSaveResult()));
   ASSERT_TRUE(IsNotNull(actual.body->getSaveResult()->getDestDocument()));
}



/// <summary>
/// A test for ConvertDocument.
/// </summary>
TEST_F(ConvertDocumentTests, TestConvertDocument) {
    auto documentContent = generate_http_content_from_file(path_combine(LocalTestDataFolder, localFolder + STCONVERT("/test_uploadfile.docx")));
    std::shared_ptr< ConvertDocumentRequest > request(new ConvertDocumentRequest(
        documentContent,
        STCONVERT("pdf"),
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->convertDocument(request).get();
}
