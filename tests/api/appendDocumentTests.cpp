/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="appendDocumentTests.cpp">
*   Copyright (c) 2020 Aspose.Words for Cloud
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
/// Example of how to append document.
/// </summary>
class AppendDocumentTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentActions/AppendDocument");
    utility::string_t localFile = STCONVERT("Common/test_multi_pages.docx");

};

/// <summary>
/// Test for appending document.
/// </summary>
TEST_F(AppendDocumentTests, TestAppendDocument) {
    utility::string_t remoteFileName = STCONVERT("TestAppendDocument.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestDocumentListDocumentEntries0 = std::make_shared< DocumentEntry >();
    requestDocumentListDocumentEntries0->setHref(remoteDataFolder + STCONVERT("/") + remoteFileName);
    requestDocumentListDocumentEntries0->setImportFormatMode(STCONVERT("KeepSourceFormatting"));

    std::vector<std::shared_ptr<DocumentEntry>> requestDocumentListDocumentEntries;
    requestDocumentListDocumentEntries.push_back(requestDocumentListDocumentEntries0);

    auto requestDocumentList = std::make_shared< DocumentEntryList >();
    requestDocumentList->setDocumentEntries(requestDocumentListDocumentEntries);

    std::shared_ptr< AppendDocumentRequest > request(new AppendDocumentRequest(
        remoteFileName,
        requestDocumentList,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        baseTestOutPath + STCONVERT("/") + remoteFileName,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->appendDocument(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_EQ(true, actual.body->getDocument() != nullptr);
   ASSERT_EQ(0, actual.body->getDocument()->getFileName().rfind(STCONVERT("TestAppendDocument.docx"), 0));
}
