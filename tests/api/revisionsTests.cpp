/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="revisionsTests.cpp">
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
/// Example of how to accept all revisions in document.
/// </summary>
class RevisionsTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentActions/Revisions");
    utility::string_t localFile = STCONVERT("Common/test_multi_pages.docx");

};

/// <summary>
/// Test for accepting revisions in document.
/// </summary>
TEST_F(RevisionsTests, TestAcceptAllRevisions) {
    utility::string_t remoteFileName = STCONVERT("TestAcceptAllRevisions.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< AcceptAllRevisionsRequest > request(new AcceptAllRevisionsRequest(
        remoteFileName,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        baseTestOutPath + STCONVERT("/") + remoteFileName
    ));

   auto actual = get_api()->acceptAllRevisions(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_EQ(true, actual.body->getResult() != nullptr);
   ASSERT_EQ(true, actual.body->getResult()->getDest() != nullptr);
   ASSERT_EQ(STCONVERT("TestOut/NET/TestAcceptAllRevisions.docx"), actual.body->getResult()->getDest()->getHref());
}

/// <summary>
/// Test for rejecting revisions in document.
/// </summary>
TEST_F(RevisionsTests, TestRejectAllRevisions) {
    utility::string_t remoteFileName = STCONVERT("TestRejectAllRevisions.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< RejectAllRevisionsRequest > request(new RejectAllRevisionsRequest(
        remoteFileName,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        baseTestOutPath + STCONVERT("/") + remoteFileName
    ));

   auto actual = get_api()->rejectAllRevisions(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_EQ(true, actual.body->getResult() != nullptr);
   ASSERT_EQ(true, actual.body->getResult()->getDest() != nullptr);
   ASSERT_EQ(STCONVERT("TestOut/NET/TestRejectAllRevisions.docx"), actual.body->getResult()->getDest()->getHref());
}
