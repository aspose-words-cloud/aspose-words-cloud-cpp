/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="tableTests.cpp">
*   Copyright (c) 2020 Aspose.Words for Cloud
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

#include "../TestBase.h"

/// <summary>
/// Example of how to work wtih table.
/// </summary>
class TableTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentElements/Tables");
    utility::string_t localFile = STCONVERT("DocumentElements/Tables/TablesGet.docx");

};

/// <summary>
/// Test for getting tables.
/// </summary>
TEST_F(TableTests, TestGetTables) {
    utility::string_t remoteFileName = STCONVERT("TestGetTables.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetTablesRequest > request(new GetTablesRequest(
        remoteFileName,
        STCONVERT(""),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getTables(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting tables without node path.
/// </summary>
TEST_F(TableTests, TestGetTablesWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestGetTablesWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetTablesWithoutNodePathRequest > request(new GetTablesWithoutNodePathRequest(
        remoteFileName,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getTablesWithoutNodePath(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting table.
/// </summary>
TEST_F(TableTests, TestGetTable) {
    utility::string_t remoteFileName = STCONVERT("TestGetTable.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetTableRequest > request(new GetTableRequest(
        remoteFileName,
        STCONVERT(""),
        1,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getTable(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting table without node path.
/// </summary>
TEST_F(TableTests, TestGetTableWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestGetTableWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetTableWithoutNodePathRequest > request(new GetTableWithoutNodePathRequest(
        remoteFileName,
        1,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getTableWithoutNodePath(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting table.
/// </summary>
TEST_F(TableTests, TestDeleteTable) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteTable.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< DeleteTableRequest > request(new DeleteTableRequest(
        remoteFileName,
        STCONVERT(""),
        1,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->deleteTable(request).get();
}

/// <summary>
/// Test for deleting table without node path.
/// </summary>
TEST_F(TableTests, TestDeleteTableWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteTableWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< DeleteTableWithoutNodePathRequest > request(new DeleteTableWithoutNodePathRequest(
        remoteFileName,
        1,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->deleteTableWithoutNodePath(request).get();
}

/// <summary>
/// Test for adding table.
/// </summary>
TEST_F(TableTests, TestInsertTable) {
    utility::string_t remoteFileName = STCONVERT("TestInsertTable.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestTable = std::make_shared< TableInsert >();
    requestTable->setColumnsCount(5);
    requestTable->setRowsCount(4);

    std::shared_ptr< InsertTableRequest > request(new InsertTableRequest(
        remoteFileName,
        requestTable,
        STCONVERT(""),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->insertTable(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for adding table without node path.
/// </summary>
TEST_F(TableTests, TestInsertTableWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestInsertTableWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestTable = std::make_shared< TableInsert >();
    requestTable->setColumnsCount(5);
    requestTable->setRowsCount(4);

    std::shared_ptr< InsertTableWithoutNodePathRequest > request(new InsertTableWithoutNodePathRequest(
        remoteFileName,
        requestTable,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->insertTableWithoutNodePath(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting document properties.
/// </summary>
TEST_F(TableTests, TestGetTableProperties) {
    utility::string_t remoteFileName = STCONVERT("TestGetTableProperties.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetTablePropertiesRequest > request(new GetTablePropertiesRequest(
        remoteFileName,
        STCONVERT(""),
        1,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getTableProperties(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting document properties without node path.
/// </summary>
TEST_F(TableTests, TestGetTablePropertiesWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestGetTablePropertiesWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetTablePropertiesWithoutNodePathRequest > request(new GetTablePropertiesWithoutNodePathRequest(
        remoteFileName,
        1,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getTablePropertiesWithoutNodePath(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for updating table properties.
/// </summary>
TEST_F(TableTests, TestUpdateTableProperties) {
    utility::string_t remoteFileName = STCONVERT("TestUpdateTableProperties.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestProperties = std::make_shared< TableProperties >();
    requestProperties->setAlignment(STCONVERT("Right"));
    requestProperties->setAllowAutoFit(false);
    requestProperties->setBidi(true);
    requestProperties->setBottomPadding(1);
    requestProperties->setCellSpacing(2);
    requestProperties->setStyleOptions(STCONVERT("ColumnBands"));

    std::shared_ptr< UpdateTablePropertiesRequest > request(new UpdateTablePropertiesRequest(
        remoteFileName,
        requestProperties,
        STCONVERT(""),
        1,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->updateTableProperties(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for updating table properties without node path.
/// </summary>
TEST_F(TableTests, TestUpdateTablePropertiesWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestUpdateTablePropertiesWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestProperties = std::make_shared< TableProperties >();
    requestProperties->setAlignment(STCONVERT("Right"));
    requestProperties->setAllowAutoFit(false);
    requestProperties->setBidi(true);
    requestProperties->setBottomPadding(1);
    requestProperties->setCellSpacing(2);
    requestProperties->setStyleOptions(STCONVERT("ColumnBands"));

    std::shared_ptr< UpdateTablePropertiesWithoutNodePathRequest > request(new UpdateTablePropertiesWithoutNodePathRequest(
        remoteFileName,
        requestProperties,
        1,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->updateTablePropertiesWithoutNodePath(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting table row.
/// </summary>
TEST_F(TableTests, TestGetTableRow) {
    utility::string_t remoteFileName = STCONVERT("TestGetTableRow.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetTableRowRequest > request(new GetTableRowRequest(
        remoteFileName,
        STCONVERT("tables/1"),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getTableRow(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting table row.
/// </summary>
TEST_F(TableTests, TestDeleteTableRow) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteTableRow.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< DeleteTableRowRequest > request(new DeleteTableRowRequest(
        remoteFileName,
        STCONVERT("tables/1"),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->deleteTableRow(request).get();
}

/// <summary>
/// Test for adding row.
/// </summary>
TEST_F(TableTests, TestInsertTableRow) {
    utility::string_t remoteFileName = STCONVERT("TestInsertTableRow.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestRow = std::make_shared< TableRowInsert >();
    requestRow->setColumnsCount(5);

    std::shared_ptr< InsertTableRowRequest > request(new InsertTableRowRequest(
        remoteFileName,
        requestRow,
        STCONVERT("sections/0/tables/2"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->insertTableRow(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting row format.
/// </summary>
TEST_F(TableTests, TestGetTableRowFormat) {
    utility::string_t remoteFileName = STCONVERT("TestGetTableRowFormat.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetTableRowFormatRequest > request(new GetTableRowFormatRequest(
        remoteFileName,
        STCONVERT("sections/0/tables/2"),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getTableRowFormat(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test updating row format.
/// </summary>
TEST_F(TableTests, TestUpdateTableRowFormat) {
    utility::string_t remoteFileName = STCONVERT("TestUpdateTableRowFormat.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestFormat = std::make_shared< TableRowFormat >();
    requestFormat->setAllowBreakAcrossPages(true);
    requestFormat->setHeadingFormat(true);
    requestFormat->setHeight(10);
    requestFormat->setHeightRule(STCONVERT("Auto"));

    std::shared_ptr< UpdateTableRowFormatRequest > request(new UpdateTableRowFormatRequest(
        remoteFileName,
        requestFormat,
        STCONVERT("sections/0/tables/2"),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->updateTableRowFormat(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting table cell.
/// </summary>
TEST_F(TableTests, TestGetTableCell) {
    utility::string_t remoteFileName = STCONVERT("TestGetTableCell.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetTableCellRequest > request(new GetTableCellRequest(
        remoteFileName,
        STCONVERT("sections/0/tables/2/rows/0"),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getTableCell(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting cell.
/// </summary>
TEST_F(TableTests, TestDeleteTableCell) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteTableCell.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< DeleteTableCellRequest > request(new DeleteTableCellRequest(
        remoteFileName,
        STCONVERT("sections/0/tables/2/rows/0"),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->deleteTableCell(request).get();
}

/// <summary>
/// Test for adding cell.
/// </summary>
TEST_F(TableTests, TestInsertTableCell) {
    utility::string_t remoteFileName = STCONVERT("TestInsertTableCell.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestCell = std::make_shared< TableCellInsert >();


    std::shared_ptr< InsertTableCellRequest > request(new InsertTableCellRequest(
        remoteFileName,
        requestCell,
        STCONVERT("sections/0/tables/2/rows/0"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->insertTableCell(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting cell format.
/// </summary>
TEST_F(TableTests, TestGetTableCellFormat) {
    utility::string_t remoteFileName = STCONVERT("TestGetTableCellFormat.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetTableCellFormatRequest > request(new GetTableCellFormatRequest(
        remoteFileName,
        STCONVERT("sections/0/tables/2/rows/0"),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getTableCellFormat(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for updating cell format.
/// </summary>
TEST_F(TableTests, TestUpdateTableCellFormat) {
    utility::string_t remoteFileName = STCONVERT("TestUpdateTableCellFormat.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestFormat = std::make_shared< TableCellFormat >();
    requestFormat->setBottomPadding(5);
    requestFormat->setFitText(true);
    requestFormat->setHorizontalMerge(STCONVERT("First"));
    requestFormat->setWrapText(true);

    std::shared_ptr< UpdateTableCellFormatRequest > request(new UpdateTableCellFormatRequest(
        remoteFileName,
        requestFormat,
        STCONVERT("sections/0/tables/2/rows/0"),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->updateTableCellFormat(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for table rendering.
/// </summary>
TEST_F(TableTests, TestRenderTable) {
    utility::string_t remoteFileName = STCONVERT("TestRenderTable.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< RenderTableRequest > request(new RenderTableRequest(
        remoteFileName,
        STCONVERT("png"),
        STCONVERT(""),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->renderTable(request).get();
}

/// <summary>
/// Test for table rendering without node path.
/// </summary>
TEST_F(TableTests, TestRenderTableWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestRenderTableWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< RenderTableWithoutNodePathRequest > request(new RenderTableWithoutNodePathRequest(
        remoteFileName,
        STCONVERT("png"),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->renderTableWithoutNodePath(request).get();
}
