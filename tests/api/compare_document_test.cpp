/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="compare_document_test.cpp">
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
/// Example of document comparison.
/// </summary>
class CompareDocumentTests : public InfrastructureTest {
protected:
    std::wstring remoteFolder = remoteBaseTestDataFolder + L"/DocumentActions/CompareDocument";
    std::wstring localFolder = L"DocumentActions/CompareDocument";

};

/// <summary>
/// Test for document comparison.
/// </summary>
TEST_F(CompareDocumentTests, TestCompareDocument) {
    std::wstring localName1 = L"compareTestDoc1.doc";
    std::wstring localName2 = L"compareTestDoc2.doc";
    std::wstring remoteName1 = L"TestCompareDocument1.doc";
    std::wstring remoteName2 = L"TestCompareDocument2.doc";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFolder + L"/" + localName1,
        remoteFolder + L"/" + remoteName1
    );
    uploadFileToStorage(
        localTestDataFolder + L"/" + localFolder + L"/" + localName2,
        remoteFolder + L"/" + remoteName2
    );

    auto requestCompareData = std::make_shared< aspose::words::cloud::models::CompareData >();
    requestCompareData->setAuthor(std::make_shared< std::wstring >(L"author"));
    requestCompareData->setComparingWithDocument(std::make_shared< std::wstring >(remoteFolder + L"/" + remoteName2));
    requestCompareData->setDateTime(std::make_shared< std::wstring >(L"2015-10-26T00:00:00.0000000Z"));

    std::shared_ptr<requests::CompareDocumentRequest> request(new requests::CompareDocumentRequest(
        std::make_shared< std::wstring >(remoteName1),
        requestCompareData,
        std::make_shared< std::wstring >(remoteFolder),
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/TestCompareDocumentOut.doc")
    ));

    auto actual = getApi()->compareDocument(request);
    ASSERT_TRUE(actual->getDocument() != nullptr);
    ASSERT_TRUE(actual->getDocument()->getFileName()->compare(L"TestCompareDocumentOut.doc") == 0);
}


