/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="footnote_test.h">
*   Copyright (c) 2025 Aspose.Words for Cloud
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
/// Example of how to work with footnotes.
/// </summary>
class FootnoteTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentElements/Footnotes";
    std::wstring footnoteFolder = L"DocumentElements/Footnotes";

};

/// <summary>
/// Test for adding footnote.
/// </summary>
TEST_F(FootnoteTests, TestInsertFootnote) {
    std::wstring remoteFileName = L"TestInsertFootnote.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + footnoteFolder + L"/Footnote.doc",
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestFootnoteDto = std::make_shared< aspose::words::cloud::models::FootnoteInsert >();
    requestFootnoteDto->setFootnoteType(std::make_shared< aspose::words::cloud::models::FootnoteBase::FootnoteType >(aspose::words::cloud::models::FootnoteBase::FootnoteType::ENDNOTE));
    requestFootnoteDto->setText(std::make_shared< std::wstring >(L"test endnote"));
    std::shared_ptr<requests::InsertFootnoteRequest> request(new requests::InsertFootnoteRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestFootnoteDto,
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertFootnote(request);
    ASSERT_TRUE(actual->getFootnote() != nullptr);
    ASSERT_TRUE(actual->getFootnote()->getNodeId()->compare(L"0.1.7.1") == 0);
    ASSERT_TRUE(actual->getFootnote()->getText()->compare(L" test endnote" + std::wstring(L"\r\n")) == 0);
}

/// <summary>
/// Test for adding footnote online.
/// </summary>
TEST_F(FootnoteTests, TestInsertFootnoteOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(footnoteFolder + L"/Footnote.doc")), std::istream::binary));
    auto requestFootnoteDto = std::make_shared< aspose::words::cloud::models::FootnoteInsert >();
    requestFootnoteDto->setFootnoteType(std::make_shared< aspose::words::cloud::models::FootnoteBase::FootnoteType >(aspose::words::cloud::models::FootnoteBase::FootnoteType::ENDNOTE));
    requestFootnoteDto->setText(std::make_shared< std::wstring >(L"test endnote"));
    std::shared_ptr<requests::InsertFootnoteOnlineRequest> request(new requests::InsertFootnoteOnlineRequest(
        requestDocument,
        requestFootnoteDto,
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertFootnoteOnline(request);
}

/// <summary>
/// Test for adding footnote without node path.
/// </summary>
TEST_F(FootnoteTests, TestInsertFootnoteWithoutNodePath) {
    std::wstring remoteFileName = L"TestInsertFootnoteWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + footnoteFolder + L"/Footnote.doc",
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestFootnoteDto = std::make_shared< aspose::words::cloud::models::FootnoteInsert >();
    requestFootnoteDto->setFootnoteType(std::make_shared< aspose::words::cloud::models::FootnoteBase::FootnoteType >(aspose::words::cloud::models::FootnoteBase::FootnoteType::ENDNOTE));
    requestFootnoteDto->setText(std::make_shared< std::wstring >(L"test endnote"));
    std::shared_ptr<requests::InsertFootnoteRequest> request(new requests::InsertFootnoteRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestFootnoteDto,
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertFootnote(request);
    ASSERT_TRUE(actual->getFootnote() != nullptr);
    ASSERT_TRUE(actual->getFootnote()->getNodeId()->compare(L"0.1.7.1") == 0);
    ASSERT_TRUE(actual->getFootnote()->getText()->compare(L" test endnote" + std::wstring(L"\r\n")) == 0);
}

/// <summary>
/// Test for deleting footnote.
/// </summary>
TEST_F(FootnoteTests, TestDeleteFootnote) {
    std::wstring remoteFileName = L"TestDeleteFootnote.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + footnoteFolder + L"/Footnote.doc",
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteFootnoteRequest> request(new requests::DeleteFootnoteRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

getApi()->deleteFootnote(request);
}

/// <summary>
/// Test for deleting footnote online.
/// </summary>
TEST_F(FootnoteTests, TestDeleteFootnoteOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(footnoteFolder + L"/Footnote.doc")), std::istream::binary));
    std::shared_ptr<requests::DeleteFootnoteOnlineRequest> request(new requests::DeleteFootnoteOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteFootnoteOnline(request);
}

/// <summary>
/// Test for deleting footnote without node path.
/// </summary>
TEST_F(FootnoteTests, TestDeleteFootnoteWithoutNodePath) {
    std::wstring remoteFileName = L"TestDeleteFootnoteWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + footnoteFolder + L"/Footnote.doc",
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteFootnoteRequest> request(new requests::DeleteFootnoteRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

getApi()->deleteFootnote(request);
}

/// <summary>
/// Test for getting footnotes.
/// </summary>
TEST_F(FootnoteTests, TestGetFootnotes) {
    std::wstring remoteFileName = L"TestGetFootnotes.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + footnoteFolder + L"/Footnote.doc",
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetFootnotesRequest> request(new requests::GetFootnotesRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getFootnotes(request);
    ASSERT_TRUE(actual->getFootnotes() != nullptr);
    ASSERT_TRUE(actual->getFootnotes()->getList() != nullptr);
    ASSERT_EQ(6, actual->getFootnotes()->getList()->size());
    ASSERT_TRUE(actual->getFootnotes()->getList()->at(0)->getText()->compare(L" Footnote 1." + std::wstring(L"\r\n")) == 0);
}

/// <summary>
/// Test for getting footnotes online.
/// </summary>
TEST_F(FootnoteTests, TestGetFootnotesOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(footnoteFolder + L"/Footnote.doc")), std::istream::binary));
    std::shared_ptr<requests::GetFootnotesOnlineRequest> request(new requests::GetFootnotesOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getFootnotesOnline(request);
}

/// <summary>
/// Test for getting footnotes without node path.
/// </summary>
TEST_F(FootnoteTests, TestGetFootnotesWithoutNodePath) {
    std::wstring remoteFileName = L"TestGetFootnotesWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + footnoteFolder + L"/Footnote.doc",
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetFootnotesRequest> request(new requests::GetFootnotesRequest(
        std::make_shared< std::wstring >(remoteFileName),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getFootnotes(request);
    ASSERT_TRUE(actual->getFootnotes() != nullptr);
    ASSERT_TRUE(actual->getFootnotes()->getList() != nullptr);
    ASSERT_EQ(6, actual->getFootnotes()->getList()->size());
    ASSERT_TRUE(actual->getFootnotes()->getList()->at(0)->getText()->compare(L" Footnote 1." + std::wstring(L"\r\n")) == 0);
}

/// <summary>
/// Test for getting footnote.
/// </summary>
TEST_F(FootnoteTests, TestGetFootnote) {
    std::wstring remoteFileName = L"TestGetFootnote.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + footnoteFolder + L"/Footnote.doc",
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetFootnoteRequest> request(new requests::GetFootnoteRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getFootnote(request);
    ASSERT_TRUE(actual->getFootnote() != nullptr);
    ASSERT_TRUE(actual->getFootnote()->getText()->compare(L" Footnote 1." + std::wstring(L"\r\n")) == 0);
}

/// <summary>
/// Test for getting footnote online.
/// </summary>
TEST_F(FootnoteTests, TestGetFootnoteOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(footnoteFolder + L"/Footnote.doc")), std::istream::binary));
    std::shared_ptr<requests::GetFootnoteOnlineRequest> request(new requests::GetFootnoteOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getFootnoteOnline(request);
}

/// <summary>
/// Test for getting footnote without node path.
/// </summary>
TEST_F(FootnoteTests, TestGetFootnoteWithoutNodePath) {
    std::wstring remoteFileName = L"TestGetFootnoteWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + footnoteFolder + L"/Footnote.doc",
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetFootnoteRequest> request(new requests::GetFootnoteRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getFootnote(request);
    ASSERT_TRUE(actual->getFootnote() != nullptr);
    ASSERT_TRUE(actual->getFootnote()->getText()->compare(L" Footnote 1." + std::wstring(L"\r\n")) == 0);
}

/// <summary>
/// Test for updating footnote.
/// </summary>
TEST_F(FootnoteTests, TestUpdateFootnote) {
    std::wstring remoteFileName = L"TestUpdateFootnote.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + footnoteFolder + L"/Footnote.doc",
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestFootnoteDto = std::make_shared< aspose::words::cloud::models::FootnoteUpdate >();
    requestFootnoteDto->setText(std::make_shared< std::wstring >(L"new text is here"));
    std::shared_ptr<requests::UpdateFootnoteRequest> request(new requests::UpdateFootnoteRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        requestFootnoteDto,
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateFootnote(request);
    ASSERT_TRUE(actual->getFootnote() != nullptr);
    ASSERT_TRUE(actual->getFootnote()->getText()->compare(L" new text is here" + std::wstring(L"\r\n")) == 0);
}

/// <summary>
/// Test for updating footnote online.
/// </summary>
TEST_F(FootnoteTests, TestUpdateFootnoteOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(footnoteFolder + L"/Footnote.doc")), std::istream::binary));
    auto requestFootnoteDto = std::make_shared< aspose::words::cloud::models::FootnoteUpdate >();
    requestFootnoteDto->setText(std::make_shared< std::wstring >(L"new text is here"));
    std::shared_ptr<requests::UpdateFootnoteOnlineRequest> request(new requests::UpdateFootnoteOnlineRequest(
        requestDocument,
        requestFootnoteDto,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateFootnoteOnline(request);
}

/// <summary>
/// Test for updating footnote without node path.
/// </summary>
TEST_F(FootnoteTests, TestUpdateFootnoteWithoutNodePath) {
    std::wstring remoteFileName = L"TestUpdateFootnoteWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + footnoteFolder + L"/Footnote.doc",
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestFootnoteDto = std::make_shared< aspose::words::cloud::models::FootnoteUpdate >();
    requestFootnoteDto->setText(std::make_shared< std::wstring >(L"new text is here"));
    std::shared_ptr<requests::UpdateFootnoteRequest> request(new requests::UpdateFootnoteRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        requestFootnoteDto,
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateFootnote(request);
    ASSERT_TRUE(actual->getFootnote() != nullptr);
    ASSERT_TRUE(actual->getFootnote()->getText()->compare(L" new text is here" + std::wstring(L"\r\n")) == 0);
}
