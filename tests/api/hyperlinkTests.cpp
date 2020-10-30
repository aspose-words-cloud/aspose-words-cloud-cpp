/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="hyperlinkTests.cpp">
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
/// Example of how to work with hyperlinks.
/// </summary>
class HyperlinkTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentElements/Hyperlink");
    utility::string_t localFile = STCONVERT("Common/test_doc.docx");

};

/// <summary>
/// Test for getting hyperlink by specified index.
/// </summary>
TEST_F(HyperlinkTests, TestGetDocumentHyperlinkByIndex) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentHyperlinkByIndex.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetDocumentHyperlinkByIndexRequest > request(new GetDocumentHyperlinkByIndexRequest(
        remoteFileName,
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getDocumentHyperlinkByIndex(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_EQ(true, actual.body->getHyperlink() != nullptr);
   ASSERT_EQ(0, actual.body->getHyperlink()->getDisplayText().rfind(STCONVERT("Aspose"), 0));
}

/// <summary>
/// Test for getting hyperlinks.
/// </summary>
TEST_F(HyperlinkTests, TestGetDocumentHyperlinks) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentHyperlinks.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetDocumentHyperlinksRequest > request(new GetDocumentHyperlinksRequest(
        remoteFileName,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getDocumentHyperlinks(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_EQ(true, actual.body->getHyperlinks() != nullptr);
   ASSERT_EQ(true, actual.body->getHyperlinks()->getHyperlinkList() != nullptr);
   ASSERT_EQ(2, actual.body->getHyperlinks()->getHyperlinkList().size());
   ASSERT_EQ(0, actual.body->getHyperlinks()->getHyperlinkList()[0]->getDisplayText().rfind(STCONVERT("Aspose"), 0));
}
