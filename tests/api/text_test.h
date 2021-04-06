/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="text_test.h">
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

#pragma once
#include "../test_base.h"

/// <summary>
/// Example of how to work with macros.
/// </summary>
class TextTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentElements/Text";

};

/// <summary>
/// Test for replacing text.
/// </summary>
TEST_F(TextTests, TestReplaceText) {
    std::wstring remoteFileName = L"TestReplaceText.docx";
    std::wstring localFile = L"Common/test_multi_pages.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestReplaceText = std::make_shared< aspose::words::cloud::models::ReplaceTextParameters >();
    requestReplaceText->setOldValue(std::make_shared< std::wstring >(L"Testing"));
    requestReplaceText->setNewValue(std::make_shared< std::wstring >(L"Aspose testing"));

    std::shared_ptr<requests::ReplaceTextRequest> request(new requests::ReplaceTextRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestReplaceText,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->replaceText(request);
    ASSERT_EQ(3, *(actual->getMatches()));
}

/// <summary>
/// Test for replacing text online.
/// </summary>
TEST_F(TextTests, TestReplaceTextOnline) {
    std::wstring localFile = L"Common/test_multi_pages.docx";

    auto documentStream = std::shared_ptr<std::istream>(new std::ifstream(getDataDir(localFile).c_str(), std::istream::binary));
    auto requestReplaceText = std::make_shared< aspose::words::cloud::models::ReplaceTextParameters >();
    requestReplaceText->setOldValue(std::make_shared< std::wstring >(L"aspose"));
    requestReplaceText->setNewValue(std::make_shared< std::wstring >(L"aspose new"));

    std::shared_ptr<requests::ReplaceTextOnlineRequest> request(new requests::ReplaceTextOnlineRequest(
        documentStream,
        requestReplaceText,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->replaceTextOnline(request);
}

/// <summary>
/// Test for searching.
/// </summary>
TEST_F(TextTests, TestSearch) {
    std::wstring remoteFileName = L"TestSearch.docx";
    std::wstring localFile = L"DocumentElements/Text/SampleWordDocument.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::SearchRequest> request(new requests::SearchRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"aspose"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->search(request);
    ASSERT_TRUE(actual->getSearchResults() != nullptr);
    ASSERT_TRUE(actual->getSearchResults()->getResultsList() != nullptr);
    ASSERT_EQ(23, actual->getSearchResults()->getResultsList()->size());
    ASSERT_TRUE(actual->getSearchResults()->getResultsList()->at(0)->getRangeStart() != nullptr);
    ASSERT_EQ(65, *(actual->getSearchResults()->getResultsList()->at(0)->getRangeStart()->getOffset()));
}

/// <summary>
/// Test for searching online.
/// </summary>
TEST_F(TextTests, TestSearchOnline) {
    std::wstring localFile = L"DocumentElements/Text/SampleWordDocument.docx";

    auto documentStream = std::shared_ptr<std::istream>(new std::ifstream(getDataDir(localFile).c_str(), std::istream::binary));
    std::shared_ptr<requests::SearchOnlineRequest> request(new requests::SearchOnlineRequest(
        documentStream,
        std::make_shared< std::wstring >(L"aspose"),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->searchOnline(request);
}
