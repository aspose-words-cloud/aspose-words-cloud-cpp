/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="revisions_test.cpp">
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

#include "../test_base.h"

/// <summary>
/// Example of how to accept all revisions in document.
/// </summary>
class RevisionsTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentActions/Revisions";
    std::wstring localFile = L"Common/test_multi_pages.docx";

};

/// <summary>
/// Test for accepting revisions in document.
/// </summary>
TEST_F(RevisionsTests, TestAcceptAllRevisions) {
    std::wstring remoteFileName = L"TestAcceptAllRevisions.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::AcceptAllRevisionsRequest> request(new requests::AcceptAllRevisionsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName)
    ));

    auto actual = getApi()->acceptAllRevisions(request);
    ASSERT_TRUE(actual->getResult() != nullptr);
    ASSERT_TRUE(actual->getResult()->getDest() != nullptr);
}



/// <summary>
/// Test for rejecting revisions in document.
/// </summary>
TEST_F(RevisionsTests, TestRejectAllRevisions) {
    std::wstring remoteFileName = L"TestRejectAllRevisions.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::RejectAllRevisionsRequest> request(new requests::RejectAllRevisionsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName)
    ));

    auto actual = getApi()->rejectAllRevisions(request);
    ASSERT_TRUE(actual->getResult() != nullptr);
    ASSERT_TRUE(actual->getResult()->getDest() != nullptr);
}


