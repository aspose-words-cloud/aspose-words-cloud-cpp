/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="table_test.h">
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
/// Example of how to work wtih table.
/// </summary>
class TableTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentElements/Tables";
    std::wstring localFile = L"DocumentElements/Tables/TablesGet.docx";

};

/// <summary>
/// Test for getting tables.
/// </summary>
TEST_F(TableTests, TestGetTables) {
    std::wstring remoteFileName = L"TestGetTables.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetTablesRequest> request(new requests::GetTablesRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getTables(request);
    ASSERT_TRUE(actual->getTables() != nullptr);
    ASSERT_TRUE(actual->getTables()->getTableLinkList() != nullptr);
    ASSERT_EQ(5, actual->getTables()->getTableLinkList()->size());
    ASSERT_TRUE(actual->getTables()->getTableLinkList()->at(0)->getNodeId()->compare(L"0.0.1") == 0);
}

/// <summary>
/// Test for getting tables online.
/// </summary>
TEST_F(TableTests, TestGetTablesOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetTablesOnlineRequest> request(new requests::GetTablesOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getTablesOnline(request);
}

/// <summary>
/// Test for getting tables without node path.
/// </summary>
TEST_F(TableTests, TestGetTablesWithoutNodePath) {
    std::wstring remoteFileName = L"TestGetTablesWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetTablesRequest> request(new requests::GetTablesRequest(
        std::make_shared< std::wstring >(remoteFileName),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getTables(request);
    ASSERT_TRUE(actual->getTables() != nullptr);
    ASSERT_TRUE(actual->getTables()->getTableLinkList() != nullptr);
    ASSERT_EQ(5, actual->getTables()->getTableLinkList()->size());
    ASSERT_TRUE(actual->getTables()->getTableLinkList()->at(0)->getNodeId()->compare(L"0.0.1") == 0);
}

/// <summary>
/// Test for getting table.
/// </summary>
TEST_F(TableTests, TestGetTable) {
    std::wstring remoteFileName = L"TestGetTable.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetTableRequest> request(new requests::GetTableRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(1),
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getTable(request);
    ASSERT_TRUE(actual->getTable() != nullptr);
    ASSERT_TRUE(actual->getTable()->getTableRowList() != nullptr);
    ASSERT_EQ(1, actual->getTable()->getTableRowList()->size());
    ASSERT_TRUE(actual->getTable()->getTableRowList()->at(0)->getTableCellList() != nullptr);
    ASSERT_EQ(2, actual->getTable()->getTableRowList()->at(0)->getTableCellList()->size());
}

/// <summary>
/// Test for getting table online.
/// </summary>
TEST_F(TableTests, TestGetTableOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetTableOnlineRequest> request(new requests::GetTableOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(1),
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getTableOnline(request);
}

/// <summary>
/// Test for getting table without node path.
/// </summary>
TEST_F(TableTests, TestGetTableWithoutNodePath) {
    std::wstring remoteFileName = L"TestGetTableWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetTableRequest> request(new requests::GetTableRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(1),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getTable(request);
    ASSERT_TRUE(actual->getTable() != nullptr);
    ASSERT_TRUE(actual->getTable()->getTableRowList() != nullptr);
    ASSERT_EQ(1, actual->getTable()->getTableRowList()->size());
    ASSERT_TRUE(actual->getTable()->getTableRowList()->at(0)->getTableCellList() != nullptr);
    ASSERT_EQ(2, actual->getTable()->getTableRowList()->at(0)->getTableCellList()->size());
}

/// <summary>
/// Test for deleting table.
/// </summary>
TEST_F(TableTests, TestDeleteTable) {
    std::wstring remoteFileName = L"TestDeleteTable.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteTableRequest> request(new requests::DeleteTableRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(1),
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

getApi()->deleteTable(request);
}

/// <summary>
/// Test for deleting table online.
/// </summary>
TEST_F(TableTests, TestDeleteTableOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::DeleteTableOnlineRequest> request(new requests::DeleteTableOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(1),
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteTableOnline(request);
}

/// <summary>
/// Test for deleting table without node path.
/// </summary>
TEST_F(TableTests, TestDeleteTableWithoutNodePath) {
    std::wstring remoteFileName = L"TestDeleteTableWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteTableRequest> request(new requests::DeleteTableRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(1),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

getApi()->deleteTable(request);
}

/// <summary>
/// Test for adding table.
/// </summary>
TEST_F(TableTests, TestInsertTable) {
    std::wstring remoteFileName = L"TestInsertTable.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestTable = std::make_shared< aspose::words::cloud::models::TableInsert >();
    requestTable->setColumnsCount(std::make_shared< int32_t >(5));
    requestTable->setRowsCount(std::make_shared< int32_t >(4));
    std::shared_ptr<requests::InsertTableRequest> request(new requests::InsertTableRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestTable,
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertTable(request);
    ASSERT_TRUE(actual->getTable() != nullptr);
    ASSERT_TRUE(actual->getTable()->getTableRowList() != nullptr);
    ASSERT_EQ(4, actual->getTable()->getTableRowList()->size());
    ASSERT_TRUE(actual->getTable()->getTableRowList()->at(0)->getTableCellList() != nullptr);
    ASSERT_EQ(5, actual->getTable()->getTableRowList()->at(0)->getTableCellList()->size());
}

/// <summary>
/// Test for adding table online.
/// </summary>
TEST_F(TableTests, TestInsertTableOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestTable = std::make_shared< aspose::words::cloud::models::TableInsert >();
    requestTable->setColumnsCount(std::make_shared< int32_t >(5));
    requestTable->setRowsCount(std::make_shared< int32_t >(4));
    std::shared_ptr<requests::InsertTableOnlineRequest> request(new requests::InsertTableOnlineRequest(
        requestDocument,
        requestTable,
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertTableOnline(request);
}

/// <summary>
/// Test for adding table without node path.
/// </summary>
TEST_F(TableTests, TestInsertTableWithoutNodePath) {
    std::wstring remoteFileName = L"TestInsertTableWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestTable = std::make_shared< aspose::words::cloud::models::TableInsert >();
    requestTable->setColumnsCount(std::make_shared< int32_t >(5));
    requestTable->setRowsCount(std::make_shared< int32_t >(4));
    std::shared_ptr<requests::InsertTableRequest> request(new requests::InsertTableRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestTable,
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertTable(request);
    ASSERT_TRUE(actual->getTable() != nullptr);
    ASSERT_TRUE(actual->getTable()->getTableRowList() != nullptr);
    ASSERT_EQ(4, actual->getTable()->getTableRowList()->size());
    ASSERT_TRUE(actual->getTable()->getTableRowList()->at(0)->getTableCellList() != nullptr);
    ASSERT_EQ(5, actual->getTable()->getTableRowList()->at(0)->getTableCellList()->size());
}

/// <summary>
/// Test for getting document properties.
/// </summary>
TEST_F(TableTests, TestGetTableProperties) {
    std::wstring remoteFileName = L"TestGetTableProperties.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetTablePropertiesRequest> request(new requests::GetTablePropertiesRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(1),
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getTableProperties(request);
    ASSERT_TRUE(actual->getProperties() != nullptr);
    ASSERT_TRUE(actual->getProperties()->getStyleName()->compare(L"Table Grid") == 0);
}

/// <summary>
/// Test for getting document properties online.
/// </summary>
TEST_F(TableTests, TestGetTablePropertiesOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetTablePropertiesOnlineRequest> request(new requests::GetTablePropertiesOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(1),
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getTablePropertiesOnline(request);
}

/// <summary>
/// Test for getting document properties without node path.
/// </summary>
TEST_F(TableTests, TestGetTablePropertiesWithoutNodePath) {
    std::wstring remoteFileName = L"TestGetTablePropertiesWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetTablePropertiesRequest> request(new requests::GetTablePropertiesRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(1),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getTableProperties(request);
    ASSERT_TRUE(actual->getProperties() != nullptr);
    ASSERT_TRUE(actual->getProperties()->getStyleName()->compare(L"Table Grid") == 0);
}

/// <summary>
/// Test for updating table properties.
/// </summary>
TEST_F(TableTests, TestUpdateTableProperties) {
    std::wstring remoteFileName = L"TestUpdateTableProperties.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestProperties = std::make_shared< aspose::words::cloud::models::TableProperties >();
    requestProperties->setAlignment(std::make_shared< aspose::words::cloud::models::TableProperties::Alignment >(aspose::words::cloud::models::TableProperties::Alignment::RIGHT));
    requestProperties->setAllowAutoFit(std::make_shared< bool >(false));
    requestProperties->setBidi(std::make_shared< bool >(true));
    requestProperties->setBottomPadding(std::make_shared< double >(1));
    requestProperties->setCellSpacing(std::make_shared< double >(2.0));
    requestProperties->setStyleOptions(std::make_shared< aspose::words::cloud::models::TableProperties::StyleOptions >(aspose::words::cloud::models::TableProperties::StyleOptions::COLUMN_BANDS));
    std::shared_ptr<requests::UpdateTablePropertiesRequest> request(new requests::UpdateTablePropertiesRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(1),
        requestProperties,
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateTableProperties(request);
    ASSERT_TRUE(actual->getProperties() != nullptr);
    ASSERT_FALSE(*(actual->getProperties()->getAllowAutoFit()));
    ASSERT_TRUE(*(actual->getProperties()->getBidi()));
    ASSERT_EQ(1.0, *(actual->getProperties()->getBottomPadding()));
    ASSERT_EQ(2.0, *(actual->getProperties()->getCellSpacing()));
}

/// <summary>
/// Test for updating table properties online.
/// </summary>
TEST_F(TableTests, TestUpdateTablePropertiesOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestProperties = std::make_shared< aspose::words::cloud::models::TableProperties >();
    requestProperties->setAlignment(std::make_shared< aspose::words::cloud::models::TableProperties::Alignment >(aspose::words::cloud::models::TableProperties::Alignment::RIGHT));
    requestProperties->setAllowAutoFit(std::make_shared< bool >(false));
    requestProperties->setBidi(std::make_shared< bool >(true));
    requestProperties->setBottomPadding(std::make_shared< double >(1));
    requestProperties->setCellSpacing(std::make_shared< double >(2));
    requestProperties->setStyleOptions(std::make_shared< aspose::words::cloud::models::TableProperties::StyleOptions >(aspose::words::cloud::models::TableProperties::StyleOptions::COLUMN_BANDS));
    std::shared_ptr<requests::UpdateTablePropertiesOnlineRequest> request(new requests::UpdateTablePropertiesOnlineRequest(
        requestDocument,
        requestProperties,
        std::make_shared< int32_t >(1),
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateTablePropertiesOnline(request);
}

/// <summary>
/// Test for updating table properties without node path.
/// </summary>
TEST_F(TableTests, TestUpdateTablePropertiesWithoutNodePath) {
    std::wstring remoteFileName = L"TestUpdateTablePropertiesWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestProperties = std::make_shared< aspose::words::cloud::models::TableProperties >();
    requestProperties->setAlignment(std::make_shared< aspose::words::cloud::models::TableProperties::Alignment >(aspose::words::cloud::models::TableProperties::Alignment::RIGHT));
    requestProperties->setAllowAutoFit(std::make_shared< bool >(false));
    requestProperties->setBidi(std::make_shared< bool >(true));
    requestProperties->setBottomPadding(std::make_shared< double >(1.0));
    requestProperties->setCellSpacing(std::make_shared< double >(2.0));
    requestProperties->setStyleOptions(std::make_shared< aspose::words::cloud::models::TableProperties::StyleOptions >(aspose::words::cloud::models::TableProperties::StyleOptions::COLUMN_BANDS));
    std::shared_ptr<requests::UpdateTablePropertiesRequest> request(new requests::UpdateTablePropertiesRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(1),
        requestProperties,
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateTableProperties(request);
    ASSERT_TRUE(actual->getProperties() != nullptr);
    ASSERT_FALSE(*(actual->getProperties()->getAllowAutoFit()));
    ASSERT_TRUE(*(actual->getProperties()->getBidi()));
    ASSERT_EQ(1.0, *(actual->getProperties()->getBottomPadding()));
    ASSERT_EQ(2.0, *(actual->getProperties()->getCellSpacing()));
}

/// <summary>
/// Test for getting table row.
/// </summary>
TEST_F(TableTests, TestGetTableRow) {
    std::wstring remoteFileName = L"TestGetTableRow.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetTableRowRequest> request(new requests::GetTableRowRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"tables/1"),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getTableRow(request);
    ASSERT_TRUE(actual->getRow() != nullptr);
    ASSERT_TRUE(actual->getRow()->getTableCellList() != nullptr);
    ASSERT_EQ(2, actual->getRow()->getTableCellList()->size());
}

/// <summary>
/// Test for getting table row online.
/// </summary>
TEST_F(TableTests, TestGetTableRowOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetTableRowOnlineRequest> request(new requests::GetTableRowOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"tables/1"),
        std::make_shared< int32_t >(0),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getTableRowOnline(request);
}

/// <summary>
/// Test for deleting table row.
/// </summary>
TEST_F(TableTests, TestDeleteTableRow) {
    std::wstring remoteFileName = L"TestDeleteTableRow.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteTableRowRequest> request(new requests::DeleteTableRowRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"tables/1"),
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

getApi()->deleteTableRow(request);
}

/// <summary>
/// Test for deleting table row online.
/// </summary>
TEST_F(TableTests, TestDeleteTableRowOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::DeleteTableRowOnlineRequest> request(new requests::DeleteTableRowOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"tables/1"),
        std::make_shared< int32_t >(0),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteTableRowOnline(request);
}

/// <summary>
/// Test for adding row.
/// </summary>
TEST_F(TableTests, TestInsertTableRow) {
    std::wstring remoteFileName = L"TestInsertTableRow.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestRow = std::make_shared< aspose::words::cloud::models::TableRowInsert >();
    requestRow->setColumnsCount(std::make_shared< int32_t >(5));
    std::shared_ptr<requests::InsertTableRowRequest> request(new requests::InsertTableRowRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"sections/0/tables/2"),
        requestRow,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertTableRow(request);
    ASSERT_TRUE(actual->getRow() != nullptr);
    ASSERT_TRUE(actual->getRow()->getTableCellList() != nullptr);
    ASSERT_EQ(5, actual->getRow()->getTableCellList()->size());
}

/// <summary>
/// Test for adding row online.
/// </summary>
TEST_F(TableTests, TestInsertTableRowOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestRow = std::make_shared< aspose::words::cloud::models::TableRowInsert >();
    requestRow->setColumnsCount(std::make_shared< int32_t >(5));
    std::shared_ptr<requests::InsertTableRowOnlineRequest> request(new requests::InsertTableRowOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"sections/0/tables/2"),
        requestRow,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertTableRowOnline(request);
}

/// <summary>
/// Test for getting row format.
/// </summary>
TEST_F(TableTests, TestGetTableRowFormat) {
    std::wstring remoteFileName = L"TestGetTableRowFormat.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetTableRowFormatRequest> request(new requests::GetTableRowFormatRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"sections/0/tables/2"),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getTableRowFormat(request);
    ASSERT_TRUE(actual->getRowFormat() != nullptr);
    ASSERT_TRUE(*(actual->getRowFormat()->getAllowBreakAcrossPages()));
}

/// <summary>
/// Test for getting row format online.
/// </summary>
TEST_F(TableTests, TestGetTableRowFormatOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetTableRowFormatOnlineRequest> request(new requests::GetTableRowFormatOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"sections/0/tables/2"),
        std::make_shared< int32_t >(0),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getTableRowFormatOnline(request);
}

/// <summary>
/// Test updating row format.
/// </summary>
TEST_F(TableTests, TestUpdateTableRowFormat) {
    std::wstring remoteFileName = L"TestUpdateTableRowFormat.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestFormat = std::make_shared< aspose::words::cloud::models::TableRowFormat >();
    requestFormat->setAllowBreakAcrossPages(std::make_shared< bool >(true));
    requestFormat->setHeadingFormat(std::make_shared< bool >(true));
    requestFormat->setHeight(std::make_shared< double >(10.0));
    requestFormat->setHeightRule(std::make_shared< aspose::words::cloud::models::TableRowFormat::HeightRule >(aspose::words::cloud::models::TableRowFormat::HeightRule::EXACTLY));
    std::shared_ptr<requests::UpdateTableRowFormatRequest> request(new requests::UpdateTableRowFormatRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"sections/0/tables/2"),
        std::make_shared< int32_t >(0),
        requestFormat,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateTableRowFormat(request);
    ASSERT_TRUE(actual->getRowFormat() != nullptr);
    ASSERT_TRUE(*(actual->getRowFormat()->getAllowBreakAcrossPages()));
    ASSERT_TRUE(*(actual->getRowFormat()->getHeadingFormat()));
    ASSERT_EQ(10.0, *(actual->getRowFormat()->getHeight()));
}

/// <summary>
/// Test updating row format online.
/// </summary>
TEST_F(TableTests, TestUpdateTableRowFormatOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestFormat = std::make_shared< aspose::words::cloud::models::TableRowFormat >();
    requestFormat->setAllowBreakAcrossPages(std::make_shared< bool >(true));
    requestFormat->setHeadingFormat(std::make_shared< bool >(true));
    requestFormat->setHeight(std::make_shared< double >(10));
    requestFormat->setHeightRule(std::make_shared< aspose::words::cloud::models::TableRowFormat::HeightRule >(aspose::words::cloud::models::TableRowFormat::HeightRule::AUTO));
    std::shared_ptr<requests::UpdateTableRowFormatOnlineRequest> request(new requests::UpdateTableRowFormatOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"sections/0/tables/2"),
        requestFormat,
        std::make_shared< int32_t >(0),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateTableRowFormatOnline(request);
}

/// <summary>
/// Test for getting table cell.
/// </summary>
TEST_F(TableTests, TestGetTableCell) {
    std::wstring remoteFileName = L"TestGetTableCell.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetTableCellRequest> request(new requests::GetTableCellRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"sections/0/tables/2/rows/0"),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getTableCell(request);
    ASSERT_TRUE(actual->getCell() != nullptr);
    ASSERT_TRUE(actual->getCell()->getNodeId()->compare(L"0.0.5.0.0") == 0);
}

/// <summary>
/// Test for getting table cell online.
/// </summary>
TEST_F(TableTests, TestGetTableCellOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetTableCellOnlineRequest> request(new requests::GetTableCellOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"sections/0/tables/2/rows/0"),
        std::make_shared< int32_t >(0),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getTableCellOnline(request);
}

/// <summary>
/// Test for deleting cell.
/// </summary>
TEST_F(TableTests, TestDeleteTableCell) {
    std::wstring remoteFileName = L"TestDeleteTableCell.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteTableCellRequest> request(new requests::DeleteTableCellRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"sections/0/tables/2/rows/0"),
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

getApi()->deleteTableCell(request);
}

/// <summary>
/// Test for deleting cell online.
/// </summary>
TEST_F(TableTests, TestDeleteTableCellOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::DeleteTableCellOnlineRequest> request(new requests::DeleteTableCellOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"sections/0/tables/2/rows/0"),
        std::make_shared< int32_t >(0),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteTableCellOnline(request);
}

/// <summary>
/// Test for adding cell.
/// </summary>
TEST_F(TableTests, TestInsertTableCell) {
    std::wstring remoteFileName = L"TestInsertTableCell.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestCell = std::make_shared< aspose::words::cloud::models::TableCellInsert >();

    std::shared_ptr<requests::InsertTableCellRequest> request(new requests::InsertTableCellRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"sections/0/tables/2/rows/0"),
        requestCell,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertTableCell(request);
    ASSERT_TRUE(actual->getCell() != nullptr);
    ASSERT_TRUE(actual->getCell()->getNodeId()->compare(L"0.0.5.0.3") == 0);
}

/// <summary>
/// Test for adding cell online.
/// </summary>
TEST_F(TableTests, TestInsertTableCellOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestCell = std::make_shared< aspose::words::cloud::models::TableCellInsert >();

    std::shared_ptr<requests::InsertTableCellOnlineRequest> request(new requests::InsertTableCellOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"sections/0/tables/2/rows/0"),
        requestCell,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertTableCellOnline(request);
}

/// <summary>
/// Test for getting cell format.
/// </summary>
TEST_F(TableTests, TestGetTableCellFormat) {
    std::wstring remoteFileName = L"TestGetTableCellFormat.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetTableCellFormatRequest> request(new requests::GetTableCellFormatRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"sections/0/tables/2/rows/0"),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getTableCellFormat(request);
    ASSERT_TRUE(actual->getCellFormat() != nullptr);
    ASSERT_TRUE(*(actual->getCellFormat()->getWrapText()));
}

/// <summary>
/// Test for getting cell format online.
/// </summary>
TEST_F(TableTests, TestGetTableCellFormatOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetTableCellFormatOnlineRequest> request(new requests::GetTableCellFormatOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"sections/0/tables/2/rows/0"),
        std::make_shared< int32_t >(0),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getTableCellFormatOnline(request);
}

/// <summary>
/// Test for updating cell format.
/// </summary>
TEST_F(TableTests, TestUpdateTableCellFormat) {
    std::wstring remoteFileName = L"TestUpdateTableCellFormat.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestFormat = std::make_shared< aspose::words::cloud::models::TableCellFormat >();
    requestFormat->setBottomPadding(std::make_shared< double >(5.0));
    requestFormat->setFitText(std::make_shared< bool >(true));
    requestFormat->setHorizontalMerge(std::make_shared< aspose::words::cloud::models::TableCellFormat::HorizontalMerge >(aspose::words::cloud::models::TableCellFormat::HorizontalMerge::FIRST));
    requestFormat->setWrapText(std::make_shared< bool >(true));
    std::shared_ptr<requests::UpdateTableCellFormatRequest> request(new requests::UpdateTableCellFormatRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"sections/0/tables/2/rows/0"),
        std::make_shared< int32_t >(0),
        requestFormat,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateTableCellFormat(request);
    ASSERT_TRUE(actual->getCellFormat() != nullptr);
    ASSERT_EQ(5.0, *(actual->getCellFormat()->getBottomPadding()));
    ASSERT_TRUE(*(actual->getCellFormat()->getFitText()));
    ASSERT_TRUE(*(actual->getCellFormat()->getWrapText()));
}

/// <summary>
/// Test for updating cell format online.
/// </summary>
TEST_F(TableTests, TestUpdateTableCellFormatOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestFormat = std::make_shared< aspose::words::cloud::models::TableCellFormat >();
    requestFormat->setBottomPadding(std::make_shared< double >(5));
    requestFormat->setFitText(std::make_shared< bool >(true));
    requestFormat->setHorizontalMerge(std::make_shared< aspose::words::cloud::models::TableCellFormat::HorizontalMerge >(aspose::words::cloud::models::TableCellFormat::HorizontalMerge::FIRST));
    requestFormat->setWrapText(std::make_shared< bool >(true));
    std::shared_ptr<requests::UpdateTableCellFormatOnlineRequest> request(new requests::UpdateTableCellFormatOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"sections/0/tables/2/rows/0"),
        requestFormat,
        std::make_shared< int32_t >(0),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateTableCellFormatOnline(request);
}

/// <summary>
/// Test for table rendering.
/// </summary>
TEST_F(TableTests, TestRenderTable) {
    std::wstring remoteFileName = L"TestRenderTable.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::RenderTableRequest> request(new requests::RenderTableRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"png"),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->renderTable(request);
}

/// <summary>
/// Test for table rendering.
/// </summary>
TEST_F(TableTests, TestRenderTableOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::RenderTableOnlineRequest> request(new requests::RenderTableOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"png"),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->renderTableOnline(request);
}

/// <summary>
/// Test for table rendering without node path.
/// </summary>
TEST_F(TableTests, TestRenderTableWithoutNodePath) {
    std::wstring remoteFileName = L"TestRenderTableWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::RenderTableRequest> request(new requests::RenderTableRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"png"),
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

    auto actual = getApi()->renderTable(request);
}
