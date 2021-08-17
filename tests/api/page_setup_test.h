/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="page_setup_test.h">
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
class PageSetupTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentElements/PageSetup";
    std::wstring localFile = L"Common/test_multi_pages.docx";
    std::wstring localTextFile = L"DocumentElements/Text/SampleWordDocument.docx";

};

/// <summary>
/// Test for getting page settings.
/// </summary>
TEST_F(PageSetupTests, TestGetSectionPageSetup) {
    std::wstring remoteFileName = L"TestGetSectionPageSetup.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetSectionPageSetupRequest> request(new requests::GetSectionPageSetupRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getSectionPageSetup(request);
    ASSERT_TRUE(actual->getPageSetup() != nullptr);
    ASSERT_EQ(1, *(actual->getPageSetup()->getLineStartingNumber()));
}

/// <summary>
/// Test for getting page settings online.
/// </summary>
TEST_F(PageSetupTests, TestGetSectionPageSetupOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetSectionPageSetupOnlineRequest> request(new requests::GetSectionPageSetupOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getSectionPageSetupOnline(request);
}

/// <summary>
/// Test for updating page settings.
/// </summary>
TEST_F(PageSetupTests, TestUpdateSectionPageSetup) {
    std::wstring remoteFileName = L"TestUpdateSectionPageSetup.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestPageSetup = std::make_shared< aspose::words::cloud::models::PageSetup >();
    requestPageSetup->setRtlGutter(std::make_shared< bool >(true));
    requestPageSetup->setLeftMargin(std::make_shared< double >(10.0));
    requestPageSetup->setOrientation(std::make_shared< aspose::words::cloud::models::PageSetup::Orientation >(aspose::words::cloud::models::PageSetup::Orientation::LANDSCAPE));
    requestPageSetup->setPaperSize(std::make_shared< aspose::words::cloud::models::PageSetup::PaperSize >(aspose::words::cloud::models::PageSetup::PaperSize::A5));
    std::shared_ptr<requests::UpdateSectionPageSetupRequest> request(new requests::UpdateSectionPageSetupRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateSectionPageSetup(request);
    ASSERT_TRUE(actual->getPageSetup() != nullptr);
    ASSERT_TRUE(*(actual->getPageSetup()->getRtlGutter()));


}

/// <summary>
/// Test for updating page settings online.
/// </summary>
TEST_F(PageSetupTests, TestUpdateSectionPageSetupOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestPageSetup = std::make_shared< aspose::words::cloud::models::PageSetup >();
    requestPageSetup->setRtlGutter(std::make_shared< bool >(true));
    requestPageSetup->setLeftMargin(std::make_shared< double >(10));
    requestPageSetup->setOrientation(std::make_shared< aspose::words::cloud::models::PageSetup::Orientation >(aspose::words::cloud::models::PageSetup::Orientation::LANDSCAPE));
    requestPageSetup->setPaperSize(std::make_shared< aspose::words::cloud::models::PageSetup::PaperSize >(aspose::words::cloud::models::PageSetup::PaperSize::A5));
    std::shared_ptr<requests::UpdateSectionPageSetupOnlineRequest> request(new requests::UpdateSectionPageSetupOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateSectionPageSetupOnline(request);
}

/// <summary>
/// Test for page rendering.
/// </summary>
TEST_F(PageSetupTests, TestGetRenderPage) {
    std::wstring remoteFileName = L"TestGetRenderPage.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localTextFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::RenderPageRequest> request(new requests::RenderPageRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(1),
        std::make_shared< std::wstring >(L"bmp"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->renderPage(request);
}

/// <summary>
/// Test for page rendering.
/// </summary>
TEST_F(PageSetupTests, TestGetRenderPageOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localTextFile)), std::istream::binary));
    std::shared_ptr<requests::RenderPageOnlineRequest> request(new requests::RenderPageOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(1),
        std::make_shared< std::wstring >(L"bmp"),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->renderPageOnline(request);
}
