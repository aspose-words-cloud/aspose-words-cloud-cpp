/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="mail_merge_fileds_test.cpp">
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
/// Example of how to work with merge fields.
/// </summary>
class MailMergeFiledsTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentActions/MailMerge";
    std::wstring mailMergeFolder = L"DocumentActions/MailMerge";

};

/// <summary>
/// Test for getting mailmerge fields.
/// </summary>
TEST_F(MailMergeFiledsTests, TestGetDocumentFieldNames) {
    std::wstring remoteFileName = L"TestGetDocumentFieldNames.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + L"Common/test_multi_pages.docx",
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetDocumentFieldNamesRequest> request(new requests::GetDocumentFieldNamesRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getDocumentFieldNames(request);
    ASSERT_TRUE(actual->getFieldNames() != nullptr);
    ASSERT_TRUE(actual->getFieldNames()->getNames() != nullptr);
    ASSERT_EQ(0, actual->getFieldNames()->getNames()->size());
}
