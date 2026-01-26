/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="table_border_test.h">
*   Copyright (c) 2026 Aspose.Words for Cloud
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
/// Example of how to work with table borders.
/// </summary>
class TableBorderTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentElements/Tables";
    std::wstring localFile = L"DocumentElements/Tables/TablesGet.docx";

};

/// <summary>
/// Test for getting borders.
/// </summary>
TEST_F(TableBorderTests, TestGetBorders) {
    std::wstring remoteFileName = L"TestGetBorders.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetBordersRequest> request(new requests::GetBordersRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"tables/1/rows/0/cells/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getBorders(request);
    ASSERT_TRUE(actual->getBorders() != nullptr);
    ASSERT_TRUE(actual->getBorders()->getList() != nullptr);
    ASSERT_EQ(6, actual->getBorders()->getList()->size());
    ASSERT_TRUE(actual->getBorders()->getList()->at(0)->getColor() != nullptr);
    ASSERT_TRUE(actual->getBorders()->getList()->at(0)->getColor()->getWeb()->compare(L"#000000") == 0);
}

/// <summary>
/// Test for getting borders online.
/// </summary>
TEST_F(TableBorderTests, TestGetBordersOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetBordersOnlineRequest> request(new requests::GetBordersOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"tables/1/rows/0/cells/0"),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getBordersOnline(request);
}

/// <summary>
/// Test for getting border.
/// </summary>
TEST_F(TableBorderTests, TestGetBorder) {
    std::wstring remoteFileName = L"TestGetBorder.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetBorderRequest> request(new requests::GetBorderRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"left"),
        std::make_shared< std::wstring >(L"tables/1/rows/0/cells/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getBorder(request);
    ASSERT_TRUE(actual->getBorder() != nullptr);
    ASSERT_TRUE(actual->getBorder()->getColor() != nullptr);
    ASSERT_TRUE(actual->getBorder()->getColor()->getWeb()->compare(L"#000000") == 0);
}

/// <summary>
/// Test for getting border online.
/// </summary>
TEST_F(TableBorderTests, TestGetBorderOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetBorderOnlineRequest> request(new requests::GetBorderOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"left"),
        std::make_shared< std::wstring >(L"tables/1/rows/0/cells/0"),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getBorderOnline(request);
}

/// <summary>
/// Test for deleting borders.
/// </summary>
TEST_F(TableBorderTests, TestDeleteBorders) {
    std::wstring remoteFileName = L"TestDeleteBorders.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteBordersRequest> request(new requests::DeleteBordersRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"tables/1/rows/0/cells/0"),
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

    auto actual = getApi()->deleteBorders(request);
}

/// <summary>
/// Test for deleting borders online.
/// </summary>
TEST_F(TableBorderTests, TestDeleteBordersOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::DeleteBordersOnlineRequest> request(new requests::DeleteBordersOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"tables/1/rows/0/cells/0"),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteBordersOnline(request);
}

/// <summary>
/// Test for deleting border.
/// </summary>
TEST_F(TableBorderTests, TestDeleteBorder) {
    std::wstring remoteFileName = L"TestDeleteBorder.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteBorderRequest> request(new requests::DeleteBorderRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"left"),
        std::make_shared< std::wstring >(L"tables/1/rows/0/cells/0"),
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

    auto actual = getApi()->deleteBorder(request);
}

/// <summary>
/// Test for deleting border online.
/// </summary>
TEST_F(TableBorderTests, TestDeleteBorderOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::DeleteBorderOnlineRequest> request(new requests::DeleteBorderOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"left"),
        std::make_shared< std::wstring >(L"tables/1/rows/0/cells/0"),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteBorderOnline(request);
}

/// <summary>
/// Test for updating border.
/// </summary>
TEST_F(TableBorderTests, TestUpdateBorder) {
    std::wstring remoteFileName = L"TestUpdateBorder.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestBorderPropertiesColor = std::make_shared< aspose::words::cloud::models::XmlColor >();
    requestBorderPropertiesColor->setWeb(std::make_shared< std::wstring >(L"#AABBCC"));
    auto requestBorderProperties = std::make_shared< aspose::words::cloud::models::Border >();
    requestBorderProperties->setBorderType(std::make_shared< aspose::words::cloud::models::Border::BorderType >(aspose::words::cloud::models::Border::BorderType::LEFT));
    requestBorderProperties->setColor(requestBorderPropertiesColor);
    requestBorderProperties->setDistanceFromText(std::make_shared< double >(6.0));
    requestBorderProperties->setLineStyle(std::make_shared< aspose::words::cloud::models::Border::LineStyle >(aspose::words::cloud::models::Border::LineStyle::DASH_DOT_STROKER));
    requestBorderProperties->setLineWidth(std::make_shared< double >(2.0));
    requestBorderProperties->setShadow(std::make_shared< bool >(true));
    std::shared_ptr<requests::UpdateBorderRequest> request(new requests::UpdateBorderRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"left"),
        requestBorderProperties,
        std::make_shared< std::wstring >(L"tables/1/rows/0/cells/0"),
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

    auto actual = getApi()->updateBorder(request);
    ASSERT_TRUE(actual->getBorder() != nullptr);
    ASSERT_TRUE(actual->getBorder()->getColor() != nullptr);
    ASSERT_TRUE(actual->getBorder()->getColor()->getWeb()->compare(L"#AABBCC") == 0);
    ASSERT_EQ(6.0, *(actual->getBorder()->getDistanceFromText()));
    ASSERT_EQ(2.0, *(actual->getBorder()->getLineWidth()));
    ASSERT_TRUE(*(actual->getBorder()->getShadow()));
}

/// <summary>
/// Test for updating border online.
/// </summary>
TEST_F(TableBorderTests, TestUpdateBorderOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestBorderPropertiesColor = std::make_shared< aspose::words::cloud::models::XmlColor >();
    requestBorderPropertiesColor->setWeb(std::make_shared< std::wstring >(L"#AABBCC"));
    auto requestBorderProperties = std::make_shared< aspose::words::cloud::models::Border >();
    requestBorderProperties->setBorderType(std::make_shared< aspose::words::cloud::models::Border::BorderType >(aspose::words::cloud::models::Border::BorderType::LEFT));
    requestBorderProperties->setColor(requestBorderPropertiesColor);
    requestBorderProperties->setDistanceFromText(std::make_shared< double >(6));
    requestBorderProperties->setLineStyle(std::make_shared< aspose::words::cloud::models::Border::LineStyle >(aspose::words::cloud::models::Border::LineStyle::DASH_DOT_STROKER));
    requestBorderProperties->setLineWidth(std::make_shared< double >(2));
    requestBorderProperties->setShadow(std::make_shared< bool >(true));
    std::shared_ptr<requests::UpdateBorderOnlineRequest> request(new requests::UpdateBorderOnlineRequest(
        requestDocument,
        requestBorderProperties,
        std::make_shared< std::wstring >(L"left"),
        std::make_shared< std::wstring >(L"tables/1/rows/0/cells/0"),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateBorderOnline(request);
}
