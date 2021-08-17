/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="range_test.h">
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
/// Example of how to work with ranges.
/// </summary>
class RangeTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentElements/Range";
    std::wstring localFile = L"DocumentElements/Range/RangeGet.doc";

};

/// <summary>
/// Test for getting the text from range.
/// </summary>
TEST_F(RangeTests, TestGetRangeText) {
    std::wstring remoteFileName = L"TestGetRangeText.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetRangeTextRequest> request(new requests::GetRangeTextRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"id0.0.0"),
        std::make_shared< std::wstring >(L"id0.0.1"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getRangeText(request);
    ASSERT_TRUE(actual->getText()->compare(L"This is HEADER ") == 0);
}

/// <summary>
/// Test for getting the text from range online.
/// </summary>
TEST_F(RangeTests, TestGetRangeTextOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetRangeTextOnlineRequest> request(new requests::GetRangeTextOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"id0.0.0"),
        std::make_shared< std::wstring >(L"id0.0.1"),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getRangeTextOnline(request);
}

/// <summary>
/// Test for removing the text for range.
/// </summary>
TEST_F(RangeTests, TestRemoveRange) {
    std::wstring remoteFileName = L"TestRemoveRange.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::RemoveRangeRequest> request(new requests::RemoveRangeRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"id0.0.0"),
        std::make_shared< std::wstring >(L"id0.0.1"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->removeRange(request);
}

/// <summary>
/// Test for removing the text for range online.
/// </summary>
TEST_F(RangeTests, TestRemoveRangeOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::RemoveRangeOnlineRequest> request(new requests::RemoveRangeOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"id0.0.0"),
        std::make_shared< std::wstring >(L"id0.0.1"),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->removeRangeOnline(request);
}

/// <summary>
/// Test for saving a range as a new document.
/// </summary>
TEST_F(RangeTests, TestSaveAsRange) {
    std::wstring remoteFileName = L"TestSaveAsRange.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestDocumentParameters = std::make_shared< aspose::words::cloud::models::RangeDocument >();
    requestDocumentParameters->setDocumentName(std::make_shared< std::wstring >(remoteDataFolder + L"/NewDoc.docx"));
    std::shared_ptr<requests::SaveAsRangeRequest> request(new requests::SaveAsRangeRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"id0.0.0"),
        nullptr,
        std::make_shared< std::wstring >(L"id0.0.1"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->saveAsRange(request);
    ASSERT_TRUE(actual->getDocument() != nullptr);
    ASSERT_TRUE(actual->getDocument()->getFileName()->compare(L"NewDoc.docx") == 0);
}

/// <summary>
/// Test for saving a range as a new document online.
/// </summary>
TEST_F(RangeTests, TestSaveAsRangeOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestDocumentParameters = std::make_shared< aspose::words::cloud::models::RangeDocument >();
    requestDocumentParameters->setDocumentName(std::make_shared< std::wstring >(remoteDataFolder + L"/NewDoc.docx"));
    std::shared_ptr<requests::SaveAsRangeOnlineRequest> request(new requests::SaveAsRangeOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"id0.0.0"),
        nullptr,
        std::make_shared< std::wstring >(L"id0.0.1"),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->saveAsRangeOnline(request);
}

/// <summary>
/// Test for replacing text in range.
/// </summary>
TEST_F(RangeTests, TestReplaceWithText) {
    std::wstring remoteFileName = L"TestReplaceWithText.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestRangeText = std::make_shared< aspose::words::cloud::models::ReplaceRange >();
    requestRangeText->setText(std::make_shared< std::wstring >(L"Replaced header"));
    std::shared_ptr<requests::ReplaceWithTextRequest> request(new requests::ReplaceWithTextRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"id0.0.0"),
        nullptr,
        std::make_shared< std::wstring >(L"id0.0.1"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->replaceWithText(request);
    ASSERT_TRUE(actual->getDocument() != nullptr);
    ASSERT_TRUE(actual->getDocument()->getFileName()->compare(L"TestReplaceWithText.docx") == 0);
}

/// <summary>
/// Test for replacing text in range online.
/// </summary>
TEST_F(RangeTests, TestReplaceWithTextOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestRangeText = std::make_shared< aspose::words::cloud::models::ReplaceRange >();
    requestRangeText->setText(std::make_shared< std::wstring >(L"Replaced header"));
    std::shared_ptr<requests::ReplaceWithTextOnlineRequest> request(new requests::ReplaceWithTextOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"id0.0.0"),
        nullptr,
        std::make_shared< std::wstring >(L"id0.0.1"),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->replaceWithTextOnline(request);
}
