/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="styles_test.h">
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
/// Example of how to work with styles.
/// </summary>
class StylesTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentElements/Styles";
    std::wstring localFile = L"DocumentElements/Styles/GetStyles.docx";

};

/// <summary>
/// Test for getting styles from document.
/// </summary>
TEST_F(StylesTests, TestGetStyles) {
    std::wstring remoteFileName = L"TestGetStyles.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetStylesRequest> request(new requests::GetStylesRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getStyles(request);
    ASSERT_TRUE(actual->getStyles() != nullptr);
    ASSERT_EQ(22, actual->getStyles()->size());
    ASSERT_TRUE(actual->getStyles()->at(0)->getName()->compare(L"Default Paragraph Font") == 0);
}

/// <summary>
/// Test for getting styles from document online.
/// </summary>
TEST_F(StylesTests, TestGetStylesOnline) {
    auto documentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetStylesOnlineRequest> request(new requests::GetStylesOnlineRequest(
        documentStream,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getStylesOnline(request);
}

/// <summary>
/// Test for getting style from document.
/// </summary>
TEST_F(StylesTests, TestGetStyle) {
    std::wstring remoteFileName = L"TestGetStyle.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetStyleRequest> request(new requests::GetStyleRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"Heading 1"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getStyle(request);
    ASSERT_TRUE(actual->getStyle() != nullptr);
    ASSERT_TRUE(actual->getStyle()->getName()->compare(L"Heading 1") == 0);
}

/// <summary>
/// Test for getting style from document online.
/// </summary>
TEST_F(StylesTests, TestGetStyleOnline) {
    auto documentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetStyleOnlineRequest> request(new requests::GetStyleOnlineRequest(
        documentStream,
        std::make_shared< std::wstring >(L"Heading 1"),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getStyleOnline(request);
}

/// <summary>
/// Test for updating style from document.
/// </summary>
TEST_F(StylesTests, TestUpdateStyle) {
    std::wstring remoteFileName = L"TestUpdateStyle.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestStyleUpdate = std::make_shared< aspose::words::cloud::models::StyleUpdate >();
    requestStyleUpdate->setName(std::make_shared< std::wstring >(L"My Style"));

    std::shared_ptr<requests::UpdateStyleRequest> request(new requests::UpdateStyleRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"Heading 1"),
        requestStyleUpdate,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateStyle(request);
    ASSERT_TRUE(actual->getStyle() != nullptr);
    ASSERT_TRUE(actual->getStyle()->getName()->compare(L"My Style") == 0);
}

/// <summary>
/// Test for updating style from document online.
/// </summary>
TEST_F(StylesTests, TestUpdateStyleOnline) {
    auto documentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestStyleUpdate = std::make_shared< aspose::words::cloud::models::StyleUpdate >();
    requestStyleUpdate->setName(std::make_shared< std::wstring >(L"My Style"));

    std::shared_ptr<requests::UpdateStyleOnlineRequest> request(new requests::UpdateStyleOnlineRequest(
        documentStream,
        std::make_shared< std::wstring >(L"Heading 1"),
        requestStyleUpdate,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateStyleOnline(request);
}

/// <summary>
/// Test for inserting style from document.
/// </summary>
TEST_F(StylesTests, TestInsertStyle) {
    std::wstring remoteFileName = L"TestInsertStyle.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestStyleInsert = std::make_shared< aspose::words::cloud::models::StyleInsert >();
    requestStyleInsert->setStyleName(std::make_shared< std::wstring >(L"My Style"));
    requestStyleInsert->setStyleType(std::make_shared< aspose::words::cloud::models::StyleInsert::StyleType >(aspose::words::cloud::models::StyleInsert::StyleType::PARAGRAPH));

    std::shared_ptr<requests::InsertStyleRequest> request(new requests::InsertStyleRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestStyleInsert,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertStyle(request);
    ASSERT_TRUE(actual->getStyle() != nullptr);
    ASSERT_TRUE(actual->getStyle()->getName()->compare(L"My Style") == 0);
}

/// <summary>
/// Test for inserting style from document online.
/// </summary>
TEST_F(StylesTests, TestInsertStyleOnline) {
    auto documentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestStyleInsert = std::make_shared< aspose::words::cloud::models::StyleInsert >();
    requestStyleInsert->setStyleName(std::make_shared< std::wstring >(L"My Style"));
    requestStyleInsert->setStyleType(std::make_shared< aspose::words::cloud::models::StyleInsert::StyleType >(aspose::words::cloud::models::StyleInsert::StyleType::PARAGRAPH));

    std::shared_ptr<requests::InsertStyleOnlineRequest> request(new requests::InsertStyleOnlineRequest(
        documentStream,
        requestStyleInsert,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertStyleOnline(request);
}

/// <summary>
/// Test for coping style from document.
/// </summary>
TEST_F(StylesTests, TestCopyStyle) {
    std::wstring remoteFileName = L"TestCopyStyle.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestStyleCopy = std::make_shared< aspose::words::cloud::models::StyleCopy >();
    requestStyleCopy->setStyleName(std::make_shared< std::wstring >(L"Heading 1"));

    std::shared_ptr<requests::CopyStyleRequest> request(new requests::CopyStyleRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestStyleCopy,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->copyStyle(request);
    ASSERT_TRUE(actual->getStyle() != nullptr);
    ASSERT_TRUE(actual->getStyle()->getName()->compare(L"Heading 1_0") == 0);
}

/// <summary>
/// Test for coping style from document online.
/// </summary>
TEST_F(StylesTests, TestCopyStyleOnline) {
    auto documentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestStyleCopy = std::make_shared< aspose::words::cloud::models::StyleCopy >();
    requestStyleCopy->setStyleName(std::make_shared< std::wstring >(L"Heading 1"));

    std::shared_ptr<requests::CopyStyleOnlineRequest> request(new requests::CopyStyleOnlineRequest(
        documentStream,
        requestStyleCopy,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->copyStyleOnline(request);
}

/// <summary>
/// Test for getting style from document element.
/// </summary>
TEST_F(StylesTests, TestGetStyleFromDocumentElement) {
    std::wstring remoteFileName = L"TestGetStyleFromDocumentElement.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetStyleFromDocumentElementRequest> request(new requests::GetStyleFromDocumentElementRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"paragraphs/1/paragraphFormat"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getStyleFromDocumentElement(request);
    ASSERT_TRUE(actual->getStyle() != nullptr);
    ASSERT_TRUE(actual->getStyle()->getName()->compare(L"TOC 1") == 0);
}

/// <summary>
/// Test for getting style from document element online.
/// </summary>
TEST_F(StylesTests, TestGetStyleFromDocumentElementOnline) {
    auto documentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetStyleFromDocumentElementOnlineRequest> request(new requests::GetStyleFromDocumentElementOnlineRequest(
        documentStream,
        std::make_shared< std::wstring >(L"paragraphs/1/paragraphFormat"),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getStyleFromDocumentElementOnline(request);
}

/// <summary>
/// Test for applying style to document element.
/// </summary>
TEST_F(StylesTests, TestApplyStyleToDocumentElement) {
    std::wstring remoteFileName = L"TestApplyStyleToDocumentElement.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestStyleApply = std::make_shared< aspose::words::cloud::models::StyleApply >();
    requestStyleApply->setStyleName(std::make_shared< std::wstring >(L"Heading 1"));

    std::shared_ptr<requests::ApplyStyleToDocumentElementRequest> request(new requests::ApplyStyleToDocumentElementRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"paragraphs/1/paragraphFormat"),
        requestStyleApply,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->applyStyleToDocumentElement(request);
}

/// <summary>
/// Test for applying style to document element online.
/// </summary>
TEST_F(StylesTests, TestApplyStyleToDocumentElementOnline) {
    auto documentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestStyleApply = std::make_shared< aspose::words::cloud::models::StyleApply >();
    requestStyleApply->setStyleName(std::make_shared< std::wstring >(L"Heading 1"));

    std::shared_ptr<requests::ApplyStyleToDocumentElementOnlineRequest> request(new requests::ApplyStyleToDocumentElementOnlineRequest(
        documentStream,
        std::make_shared< std::wstring >(L"paragraphs/1/paragraphFormat"),
        requestStyleApply,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->applyStyleToDocumentElementOnline(request);
}
