#include "TestBase.h"

/// <summary>
/// Example of how to work wtih table
/// </summary>
class TableTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements\\Tables")),
		tableFolder = STCONVERT("DocumentElements/Tables");
};

/// <summary>
/// Test for getting tables
/// </summary>
TEST_F(TableTest, TestGetTables) {
	utility::string_t
		localName = STCONVERT("TablesGet.docx"),
		remoteName = STCONVERT("TestGetTables.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(tableFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetTablesRequest> request=
			std::make_shared<GetTablesRequest>(remoteName, dataFolder, boost::none,
		boost::none, boost::none, boost::none);

	std::shared_ptr<TableLinkCollectionResponse> actual = get_api()->getTables(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for getting table
/// </summary>
TEST_F(TableTest, TestGetTable) {
	utility::string_t
		localName = STCONVERT("TablesGet.docx"),
		remoteName = STCONVERT("TestGetTable.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(tableFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetTableRequest> request=
			std::make_shared<GetTableRequest>(remoteName, 1, dataFolder, boost::none,
		boost::none, boost::none, boost::none);

	std::shared_ptr<TableResponse> actual = get_api()->getTable(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for deleting table
/// </summary>
TEST_F(TableTest, TestDeleteTable) {
	utility::string_t
		localName = STCONVERT("TablesGet.docx"),
		remoteName = STCONVERT("TestDeleteTable.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(tableFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteTableRequest> request=
			std::make_shared<DeleteTableRequest>(remoteName, 1, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);

	std::shared_ptr<AsposeResponse> actual = get_api()->deleteTable(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for adding table
/// </summary>
TEST_F(TableTest, TestInsertTable) {
	utility::string_t
		localName = STCONVERT("TablesGet.docx"),
		remoteName = STCONVERT("TestInsertTable.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(tableFolder), localName);
	std::shared_ptr<TableInsert> tableDto= std::make_shared<TableInsert>();
	tableDto->setColumnsCount(5);
	tableDto->setRowsCount(4);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<InsertTableRequest> request= std::make_shared<InsertTableRequest>(remoteName, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, tableDto, boost::none);

	std::shared_ptr<TableResponse> actual = get_api()->insertTable(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for getting document properties
/// </summary>
TEST_F(TableTest, TestGetTableProperties) {
	utility::string_t
		localName = STCONVERT("TablesGet.docx"),
		remoteName = STCONVERT("TestGetTableProperties.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(tableFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetTablePropertiesRequest> request= std::make_shared<GetTablePropertiesRequest>(remoteName, 1, dataFolder, boost::none,
		boost::none, boost::none, boost::none);

	std::shared_ptr<TablePropertiesResponse> actual = get_api()->getTableProperties(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for updating table properties
/// </summary>
TEST_F(TableTest, TestUpdateTableProperties) {
	utility::string_t
		localName = STCONVERT("TablesGet.docx"),
		remoteName = STCONVERT("TestUpdateTableProperties.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(tableFolder), localName);

	std::shared_ptr<TableProperties> newProperties= std::make_shared<TableProperties>();
	newProperties->setAlignment(STCONVERT("Right"));
	newProperties->setAllowAutoFit(false);
	newProperties->setBidi(true);
	newProperties->setBottomPadding(1);
	newProperties->setCellSpacing(2);
	newProperties->setLeftIndent(3);
	newProperties->setLeftPadding(4);
	newProperties->setRightPadding(5);
	newProperties->setStyleOptions(STCONVERT("ColumnBands"));
	newProperties->setTopPadding(6);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<UpdateTablePropertiesRequest> request=
			std::make_shared<UpdateTablePropertiesRequest>(remoteName, 1, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, newProperties, boost::none);

	std::shared_ptr<TablePropertiesResponse> actual = get_api()->updateTableProperties(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for getting table row
/// </summary>
TEST_F(TableTest, TestGetTableRow) {
	utility::string_t
		localName = STCONVERT("TablesGet.docx"),
		remoteName = STCONVERT("TestGetTableRow.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(tableFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetTableRowRequest> request= std::make_shared<GetTableRowRequest>(remoteName, STCONVERT("tables/1"), 0, dataFolder, boost::none,
		boost::none, boost::none);

	std::shared_ptr<TableRowResponse> actual = get_api()->getTableRow(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for deleting table row
/// </summary>
TEST_F(TableTest, TestDeleteTableRow) {
	utility::string_t
		localName = STCONVERT("TablesGet.docx"),
		remoteName = STCONVERT("TestDeleteTableRow.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(tableFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteTableRowRequest> request=
			std::make_shared<DeleteTableRowRequest>(remoteName, STCONVERT("tables/1"), 0, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none);

	std::shared_ptr<AsposeResponse> actual = get_api()->deleteTableRow(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for adding row
/// </summary>
TEST_F(TableTest, TestInsertTableRow) {
	utility::string_t
		localName = STCONVERT("TablesGet.docx"),
		remoteName = STCONVERT("TestInsertTableRow.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(tableFolder), localName);
	std::shared_ptr<TableRowInsert> row= std::make_shared<TableRowInsert>();
	row->setColumnsCount(5);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<InsertTableRowRequest> request=
			std::make_shared<InsertTableRowRequest>(remoteName, STCONVERT("sections/0/tables/2"), dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, row);

	std::shared_ptr<TableRowResponse> actual = get_api()->insertTableRow(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for getting row format
/// </summary>
TEST_F(TableTest, TestGetTableRowFormat) {
	utility::string_t
		localName = STCONVERT("TablesGet.docx"),
		remoteName = STCONVERT("TestGetTableRowFormat.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(tableFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetTableRowFormatRequest> request=
			std::make_shared<GetTableRowFormatRequest>(remoteName, STCONVERT("sections/0/tables/2"), 0, dataFolder, boost::none,
		boost::none, boost::none);

	std::shared_ptr<TableRowFormatResponse> actual = get_api()->getTableRowFormat(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test updating row format
/// </summary>
TEST_F(TableTest, TestUpdateTableRowFormat) {
	utility::string_t
		localName = STCONVERT("TablesGet.docx"),
		remoteName = STCONVERT("TestUpdateTableRowFormat.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(tableFolder), localName);
	std::shared_ptr<TableRowFormat> rowFormat= std::make_shared<TableRowFormat>();
	rowFormat->setAllowBreakAcrossPages(true);
	rowFormat->setHeadingFormat(true);
	rowFormat->setHeight(10);
	rowFormat->setHeightRule(STCONVERT("Auto"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<UpdateTableRowFormatRequest> request= std::make_shared<UpdateTableRowFormatRequest>(remoteName, STCONVERT("sections/0/tables/2"), 0, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, rowFormat);

	std::shared_ptr<TableRowFormatResponse> actual = get_api()->updateTableRowFormat(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for getting table cell
/// </summary>
TEST_F(TableTest, TestGetTableCell) {
	utility::string_t
		localName = STCONVERT("TablesGet.docx"),
		remoteName = STCONVERT("TestGetTableCell.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(tableFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetTableCellRequest> request= std::make_shared<GetTableCellRequest>(remoteName, STCONVERT("sections/0/tables/2/rows/0"), 0, dataFolder, boost::none,
		boost::none, boost::none);

	std::shared_ptr<TableCellResponse> actual = get_api()->getTableCell(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for deleting cell
/// </summary>
TEST_F(TableTest, TestDeleteCell) {
	utility::string_t
		localName = STCONVERT("TablesGet.docx"),
		remoteName = STCONVERT("TestDeleteCell.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(tableFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteTableCellRequest> request=
			std::make_shared<DeleteTableCellRequest>(remoteName, STCONVERT("sections/0/tables/2/rows/0"), 0,
		dataFolder, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);

	std::shared_ptr<AsposeResponse> actual = get_api()->deleteTableCell(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for adding cell
/// </summary>
TEST_F(TableTest, TestInsertTableCell) {
	utility::string_t
		localName = STCONVERT("TablesGet.docx"),
		remoteName = STCONVERT("TestInsertTableCell.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(tableFolder), localName);
	std::shared_ptr<TableCellInsert> cell= std::make_shared<TableCellInsert>();

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<InsertTableCellRequest> request=
			std::make_shared<InsertTableCellRequest>(remoteName, STCONVERT("sections/0/tables/2/rows/0"), dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, cell);

	std::shared_ptr<TableCellResponse> actual = get_api()->insertTableCell(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for getting cell format
/// </summary>
TEST_F(TableTest, TestGetTableCellFormat) {
	utility::string_t
		localName = STCONVERT("TablesGet.docx"),
		remoteName = STCONVERT("TestGetTableCellFormat.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(tableFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetTableCellFormatRequest> request=
			std::make_shared<GetTableCellFormatRequest>(remoteName, STCONVERT("sections/0/tables/2/rows/0"), 0, dataFolder, boost::none,
		boost::none, boost::none);

	std::shared_ptr<TableCellFormatResponse> actual = get_api()->getTableCellFormat(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for updating cell format
/// </summary>
TEST_F(TableTest, TestUpdateTableCellFormat) {
	utility::string_t
		localName = STCONVERT("TablesGet.docx"),
		remoteName = STCONVERT("TestUpdateTableCellFormat.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(tableFolder), localName);
	std::shared_ptr<TableCellFormat> cellFormat= std::make_shared<TableCellFormat>();
	cellFormat->setBottomPadding(5);
	cellFormat->setFitText(true);
	cellFormat->setHorizontalMerge(STCONVERT("First"));
	cellFormat->setWrapText(true);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<UpdateTableCellFormatRequest> request=
			std::make_shared<UpdateTableCellFormatRequest>(remoteName, STCONVERT("sections/0/tables/2/rows/0"), 0, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, cellFormat);

	std::shared_ptr<TableCellFormatResponse> actual = get_api()->updateTableCellFormat(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for table rendering
/// </summary>
TEST_F(TableTest, TestRenderTable) {
	utility::string_t
		localName = STCONVERT("TablesGet.docx"),
		remoteName = STCONVERT("TestRenderTable.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(tableFolder), localName),
		format = STCONVERT("png");
	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<RenderTableRequest> request=
			std::make_shared<RenderTableRequest>(remoteName, format, index, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none);

	HttpContent result = get_api()->renderTable(request).get();

	ASSERT_TRUE(result.getData()->peek());
}