/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="header_footer_test.h">
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
/// Example of how to work with headers and footers.
/// </summary>
class HeaderFooterTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentElements/HeaderFooters";
    std::wstring localFile = L"DocumentElements/HeaderFooters/HeadersFooters.doc";

};

/// <summary>
/// Test for getting headers and footers.
/// </summary>
TEST_F(HeaderFooterTests, TestGetHeaderFooters) {
    std::wstring remoteFileName = L"TestGetHeadersFooters.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetHeaderFootersRequest> request(new requests::GetHeaderFootersRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getHeaderFooters(request);
    ASSERT_TRUE(actual->getHeaderFooters() != nullptr);
    ASSERT_TRUE(actual->getHeaderFooters()->getList() != nullptr);
    ASSERT_EQ(6, actual->getHeaderFooters()->getList()->size());
}

/// <summary>
/// Test for getting headers and footers online.
/// </summary>
TEST_F(HeaderFooterTests, TestGetHeaderFootersOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetHeaderFootersOnlineRequest> request(new requests::GetHeaderFootersOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getHeaderFootersOnline(request);
}

/// <summary>
/// Test for getting headerfooter.
/// </summary>
TEST_F(HeaderFooterTests, TestGetHeaderFooter) {
    std::wstring remoteFileName = L"TestGetHeaderFooter.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetHeaderFooterRequest> request(new requests::GetHeaderFooterRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getHeaderFooter(request);
    ASSERT_TRUE(actual->getHeaderFooter() != nullptr);
    ASSERT_TRUE(actual->getHeaderFooter()->getChildNodes() != nullptr);
    ASSERT_EQ(1, actual->getHeaderFooter()->getChildNodes()->size());
    ASSERT_TRUE(actual->getHeaderFooter()->getChildNodes()->at(0)->getNodeId()->compare(L"0.0.0") == 0);
}

/// <summary>
/// Test for getting headerfooter online.
/// </summary>
TEST_F(HeaderFooterTests, TestGetHeaderFooterOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetHeaderFooterOnlineRequest> request(new requests::GetHeaderFooterOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getHeaderFooterOnline(request);
}

/// <summary>
/// Test for getting headerfooter of section.
/// </summary>
TEST_F(HeaderFooterTests, TestGetHeaderFooterOfSection) {
    std::wstring remoteFileName = L"TestGetHeaderFooterOfSection.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetHeaderFooterOfSectionRequest> request(new requests::GetHeaderFooterOfSectionRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getHeaderFooterOfSection(request);
    ASSERT_TRUE(actual->getHeaderFooter() != nullptr);
    ASSERT_TRUE(actual->getHeaderFooter()->getChildNodes() != nullptr);
    ASSERT_EQ(1, actual->getHeaderFooter()->getChildNodes()->size());
    ASSERT_TRUE(actual->getHeaderFooter()->getChildNodes()->at(0)->getNodeId()->compare(L"0.0.0") == 0);
}

/// <summary>
/// Test for getting headerfooter of section online.
/// </summary>
TEST_F(HeaderFooterTests, TestGetHeaderFooterOfSectionOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetHeaderFooterOfSectionOnlineRequest> request(new requests::GetHeaderFooterOfSectionOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        std::make_shared< int32_t >(0),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getHeaderFooterOfSectionOnline(request);
}

/// <summary>
/// Test for deleting headerfooter.
/// </summary>
TEST_F(HeaderFooterTests, TestDeleteHeaderFooter) {
    std::wstring remoteFileName = L"TestDeleteHeaderFooter.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteHeaderFooterRequest> request(new requests::DeleteHeaderFooterRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L""),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

getApi()->deleteHeaderFooter(request);
}

/// <summary>
/// Test for deleting headerfooter online.
/// </summary>
TEST_F(HeaderFooterTests, TestDeleteHeaderFooterOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::DeleteHeaderFooterOnlineRequest> request(new requests::DeleteHeaderFooterOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L""),
        std::make_shared< int32_t >(0),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteHeaderFooterOnline(request);
}

/// <summary>
/// Test for deleting headerfooters.
/// </summary>
TEST_F(HeaderFooterTests, TestDeleteHeadersFooters) {
    std::wstring remoteFileName = L"TestDeleteHeadersFooters.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteHeadersFootersRequest> request(new requests::DeleteHeadersFootersRequest(
        std::make_shared< std::wstring >(remoteFileName),
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

getApi()->deleteHeadersFooters(request);
}

/// <summary>
/// Test for deleting headerfooters online.
/// </summary>
TEST_F(HeaderFooterTests, TestDeleteHeadersFootersOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::DeleteHeadersFootersOnlineRequest> request(new requests::DeleteHeadersFootersOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteHeadersFootersOnline(request);
}

/// <summary>
/// Test for adding headerfooters.
/// </summary>
TEST_F(HeaderFooterTests, TestInsertHeaderFooter) {
    std::wstring remoteFileName = L"TestInsertHeaderFooter.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::InsertHeaderFooterRequest> request(new requests::InsertHeaderFooterRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(L"FooterEven"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertHeaderFooter(request);
}

/// <summary>
/// Test for adding headerfooters online.
/// </summary>
TEST_F(HeaderFooterTests, TestInsertHeaderFooterOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::InsertHeaderFooterOnlineRequest> request(new requests::InsertHeaderFooterOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(L"FooterEven"),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertHeaderFooterOnline(request);
    ASSERT_TRUE(actual->getModel()->getHeaderFooter() != nullptr);
    ASSERT_TRUE(actual->getModel()->getHeaderFooter()->getChildNodes() != nullptr);
    ASSERT_EQ(1, actual->getModel()->getHeaderFooter()->getChildNodes()->size());
    ASSERT_TRUE(actual->getModel()->getHeaderFooter()->getChildNodes()->at(0)->getNodeId()->compare(L"0.2.0") == 0);
}
