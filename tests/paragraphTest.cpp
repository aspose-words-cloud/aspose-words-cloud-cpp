/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="paragraphTest.cpp">
*   Copyright (c) 2019 Aspose.Words for Cloud
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
#include "TestBase.h"

/// <summary>
/// Example of how to work with paragraph
/// </summary>
class ParagraphTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements/Paragraphs")),
		listFormatFolder = STCONVERT("DocumentElements/ParagraphListFormat"),
		fieldFolder = STCONVERT("DocumentElements/Fields"),
		tabStopFolder = STCONVERT("DocumentElements/Paragraphs");
};

/// <summary>
/// Test for getting paragraph
/// </summary>
TEST_F(ParagraphTest, TestGetDocumentParagraphByIndex) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentParagraphByIndex.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);
	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetParagraphRequest> request=
			std::make_shared<GetParagraphRequest>(remoteName, STCONVERT("sections/0"), index, dataFolder, boost::none,
		boost::none, boost::none);

	AsposeResponse<ParagraphResponse> actual = get_api()->getParagraph(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting all paragraphs
/// </summary>
TEST_F(ParagraphTest, TestGetDocumentParagraphs) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentParagraphs.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetParagraphsRequest> request=
			std::make_shared<GetParagraphsRequest>(remoteName, STCONVERT("sections/0"), dataFolder, boost::none,
		boost::none, boost::none);

	AsposeResponse<ParagraphLinkCollectionResponse> actual = get_api()->getParagraphs(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting first paragraph
/// </summary>
TEST_F(ParagraphTest, TestGetParagraphWithoutNodePath) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentParagraphWithoutNodePath.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);
	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetParagraphWithoutNodePathRequest> request=
			std::make_shared<GetParagraphWithoutNodePathRequest>(remoteName, index, dataFolder, boost::none,
		boost::none, boost::none);

	AsposeResponse<ParagraphResponse> actual = get_api()->getParagraphWithoutNodePath(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting paragraph
/// </summary>
TEST_F(ParagraphTest, TestDeleteParagraph) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestDeleteParagraph.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteParagraphRequest> request=
			std::make_shared<DeleteParagraphRequest>(remoteName, STCONVERT(""), 0, dataFolder, boost::none, boost::none,
					boost::none, boost::none, boost::none, boost::none);

	std::shared_ptr<web::http::http_response> actual = get_api()->deleteParagraph(request).get();

	ASSERT_EQ(200, actual->status_code());
}

/// <summary>
/// Test for paragraph rendering
/// </summary>
TEST_F(ParagraphTest, TestRenderParagraph) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestRenderParagraph.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName),
		format = STCONVERT("png");
	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<RenderParagraphRequest> request=
			std::make_shared<RenderParagraphRequest>(remoteName, format, STCONVERT(""), index,
		dataFolder, boost::none, boost::none, boost::none, boost::none);

	HttpContent result = get_api()->renderParagraph(request).get();

	ASSERT_TRUE(result.getData()->peek());
}

/// <summary>
/// Test for getting paragraph format settings
/// </summary>
TEST_F(ParagraphTest, TestGetParagraphFormat) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentParagraphs.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetParagraphFormatRequest> request=
			std::make_shared<GetParagraphFormatRequest>(remoteName, STCONVERT(""), 0,
		dataFolder, boost::none, boost::none, boost::none);

	AsposeResponse<ParagraphFormatResponse> actual = get_api()->getParagraphFormat(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for updating  paragraph format settings
/// </summary>
TEST_F(ParagraphTest, TestUpdateParagraphFormat) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestUpdateParagraphFormat.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	std::shared_ptr<ParagraphFormat> body= std::make_shared<ParagraphFormat>();
	body->setAlignment(STCONVERT("Right"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<UpdateParagraphFormatRequest> request=
			std::make_shared<UpdateParagraphFormatRequest>(remoteName, body, STCONVERT(""), 0,
		dataFolder, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);

	AsposeResponse<ParagraphFormatResponse> actual = get_api()->updateParagraphFormat(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for updating  paragraph format settings without node path
/// </summary>
TEST_F(ParagraphTest, TestUpdateParagraphFormatWithoutNodePath) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestUpdateParagraphFormat.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	std::shared_ptr<ParagraphFormat> body = std::make_shared<ParagraphFormat>();
	body->setAlignment(STCONVERT("Right"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<UpdateParagraphFormatWithoutNodePathRequest> request =
		std::make_shared<UpdateParagraphFormatWithoutNodePathRequest>(remoteName, body, 0,
			dataFolder, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);

	AsposeResponse<ParagraphFormatResponse> actual = get_api()->updateParagraphFormatWithoutNodePath(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for inserting  paragraph
/// </summary>
TEST_F(ParagraphTest, TestInsertParagraph) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestInsertParagraph.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	std::shared_ptr<ParagraphInsert> body = std::shared_ptr<ParagraphInsert>(new ParagraphInsert());
	body->setText(STCONVERT("text"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<InsertParagraphRequest> request =
		std::make_shared<InsertParagraphRequest>(remoteName, body, STCONVERT(""), dataFolder, 
			boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);

	AsposeResponse<ParagraphResponse> actual = get_api()->insertParagraph(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for inserting  paragraph without node path
/// </summary>
TEST_F(ParagraphTest, TestInsertParagraphWithoutNodePath) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestInsertParagraph.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	std::shared_ptr<ParagraphInsert> body = std::shared_ptr<ParagraphInsert>(new ParagraphInsert());
	body->setText(STCONVERT("text"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<InsertParagraphWithoutNodePathRequest> request =
		std::make_shared<InsertParagraphWithoutNodePathRequest>(remoteName, body, dataFolder,
			boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);

	AsposeResponse<ParagraphResponse> actual = get_api()->insertParagraphWithoutNodePath(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting all paragraphs
/// </summary>
TEST_F(ParagraphTest, TestGetDocumentParagraphsWithoutNodePath) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentParagraphsWithoutNodePath.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetParagraphsWithoutNodePathRequest> request =
		std::make_shared<GetParagraphsWithoutNodePathRequest>(remoteName, dataFolder, boost::none,
			boost::none, boost::none);

	AsposeResponse<ParagraphLinkCollectionResponse> actual = get_api()->getParagraphsWithoutNodePath(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting paragraph
/// </summary>
TEST_F(ParagraphTest, TestDeleteParagraphWithoutNodePath) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestDeleteParagraphWithoutNodePath.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteParagraphWithoutNodePathRequest> request =
		std::make_shared<DeleteParagraphWithoutNodePathRequest>(remoteName, 0, dataFolder, boost::none, boost::none,
			boost::none, boost::none, boost::none, boost::none);

	std::shared_ptr<web::http::http_response> actual = get_api()->deleteParagraphWithoutNodePath(request).get();

	ASSERT_EQ(200, actual->status_code());
}

/// <summary>
/// Test for paragraph rendering
/// </summary>
TEST_F(ParagraphTest, TestRenderParagraphWithoutNodePath) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestRenderParagraphWithoutNodePath.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName),
		format = STCONVERT("png");
	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<RenderParagraphWithoutNodePathRequest> request =
		std::make_shared<RenderParagraphWithoutNodePathRequest>(remoteName, format, index,
			dataFolder, boost::none, boost::none, boost::none, boost::none);

	HttpContent result = get_api()->renderParagraphWithoutNodePath(request).get();

	ASSERT_TRUE(result.getData()->peek());
}

/// <summary>
/// Test for getting paragraph format settings
/// </summary>
TEST_F(ParagraphTest, TestGetParagraphFormatWithoutNodePath) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentParagraphsWithoutNodePath.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetParagraphFormatWithoutNodePathRequest> request =
		std::make_shared<GetParagraphFormatWithoutNodePathRequest>(remoteName, 0,
			dataFolder, boost::none, boost::none, boost::none);

	AsposeResponse<ParagraphFormatResponse> actual = get_api()->getParagraphFormatWithoutNodePath(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting paragraph list format
/// </summary>
TEST_F(ParagraphTest, TestGetParagraphListFormat) {
	utility::string_t
		localName = STCONVERT("ParagraphGetListFormat.doc"),
		remoteName = localName,
		fullName = path_combine_url(remoteBaseTestDataFolder, path_combine_url(listFormatFolder, remoteName)),
		filePath = path_combine(get_data_dir(listFormatFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetParagraphListFormatRequest> request =
		std::make_shared<GetParagraphListFormatRequest>(remoteName, STCONVERT(""), 0, 
			path_combine_url(remoteBaseTestDataFolder, listFormatFolder), boost::none,
			boost::none, boost::none);

	AsposeResponse<ParagraphListFormatResponse> actual = get_api()->getParagraphListFormat(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting paragraph list format without node path
/// </summary>
TEST_F(ParagraphTest, TestGetParagraphListFormatWithoutNodePath) {
	utility::string_t
		localName = STCONVERT("ParagraphGetListFormat.doc"),
		remoteName = localName,
		fullName = path_combine_url(remoteBaseTestDataFolder, path_combine_url(listFormatFolder, remoteName)),
		filePath = path_combine(get_data_dir(listFormatFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetParagraphListFormatWithoutNodePathRequest> request =
		std::make_shared<GetParagraphListFormatWithoutNodePathRequest>(remoteName, 0,
			path_combine_url(remoteBaseTestDataFolder, listFormatFolder), boost::none,
			boost::none, boost::none);

	AsposeResponse<ParagraphListFormatResponse> actual = get_api()->getParagraphListFormatWithoutNodePath(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for updating paragraph list format
/// </summary>
TEST_F(ParagraphTest, TestUpdateParagraphListFormat) {
	utility::string_t
		localName = STCONVERT("ParagraphUpdateListFormat.doc"),
		remoteName = localName,
		fullName = path_combine_url(remoteBaseTestDataFolder, path_combine_url(listFormatFolder, remoteName)),
		filePath = path_combine(get_data_dir(listFormatFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<ListFormatUpdate> dto = std::make_shared<ListFormatUpdate>();
	dto->setListId(2);

	std::shared_ptr<UpdateParagraphListFormatRequest> request =
		std::make_shared<UpdateParagraphListFormatRequest>(remoteName, dto, STCONVERT(""), 0, 
			path_combine_url(remoteBaseTestDataFolder, listFormatFolder), boost::none,
			boost::none, boost::none, boost::none, boost::none, boost::none);

	AsposeResponse<ParagraphListFormatResponse> actual = get_api()->updateParagraphListFormat(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for updating paragraph list format without node path
/// </summary>
TEST_F(ParagraphTest, TestUpdateParagraphListFormatWithoutNodePath) {
	utility::string_t
		localName = STCONVERT("ParagraphUpdateListFormat.doc"),
		remoteName = localName,
		fullName = path_combine_url(remoteBaseTestDataFolder, path_combine_url(listFormatFolder, remoteName)),
		filePath = path_combine(get_data_dir(listFormatFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<ListFormatUpdate> dto = std::make_shared<ListFormatUpdate>();
	dto->setListId(2);

	std::shared_ptr<UpdateParagraphListFormatWithoutNodePathRequest> request =
		std::make_shared<UpdateParagraphListFormatWithoutNodePathRequest>(remoteName, dto, 0,
			path_combine_url(remoteBaseTestDataFolder, listFormatFolder), boost::none,
			boost::none, boost::none, boost::none, boost::none, boost::none);

	AsposeResponse<ParagraphListFormatResponse> actual = get_api()->updateParagraphListFormatWithoutNodePath(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting paragraph list format
/// </summary>
TEST_F(ParagraphTest, TestDeleteParagraphListFormat) {
	utility::string_t
		localName = STCONVERT("ParagraphDeleteListFormat.doc"),
		remoteName = localName,
		fullName = path_combine_url(remoteBaseTestDataFolder, path_combine_url(listFormatFolder, remoteName)),
		filePath = path_combine(get_data_dir(listFormatFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteParagraphListFormatRequest> request =
		std::make_shared<DeleteParagraphListFormatRequest>(remoteName, STCONVERT(""), 0, 
			path_combine_url(remoteBaseTestDataFolder, listFormatFolder), boost::none,
			boost::none, boost::none, boost::none, boost::none, boost::none);

	AsposeResponse<ParagraphListFormatResponse> actual = get_api()->deleteParagraphListFormat(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting paragraph list format without node path
/// </summary>
TEST_F(ParagraphTest, TestDeleteParagraphListFormatWithoutNodePath) {
	utility::string_t
		localName = STCONVERT("ParagraphDeleteListFormat.doc"),
		remoteName = localName,
		fullName = path_combine_url(remoteBaseTestDataFolder, path_combine_url(listFormatFolder, remoteName)),
		filePath = path_combine(get_data_dir(listFormatFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteParagraphListFormatWithoutNodePathRequest> request =
		std::make_shared<DeleteParagraphListFormatWithoutNodePathRequest>(remoteName, 0,
			path_combine_url(remoteBaseTestDataFolder, listFormatFolder), boost::none,
			boost::none, boost::none, boost::none, boost::none, boost::none);

	AsposeResponse<ParagraphListFormatResponse> actual = get_api()->deleteParagraphListFormatWithoutNodePath(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting paragraph tab stops
/// </summary>
TEST_F(ParagraphTest, TestGetParagraphTabStops) {
	utility::string_t
		localName = STCONVERT("ParagraphTabStops.docx"),
		remoteName = localName,
		fullName = path_combine_url(remoteBaseTestDataFolder, path_combine_url(tabStopFolder, remoteName)),
		filePath = path_combine(get_data_dir(tabStopFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetParagraphTabStopsRequest> request =
		std::make_shared<GetParagraphTabStopsRequest>(remoteName, STCONVERT(""), 0,
			path_combine_url(remoteBaseTestDataFolder, tabStopFolder), boost::none,
			boost::none, boost::none);

	AsposeResponse<TabStopsResponse> actual = get_api()->getParagraphTabStops(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting paragraph tab stops without node path
/// </summary>
TEST_F(ParagraphTest, TestGetParagraphTabStopsWithoutNodePath) {
	utility::string_t
		localName = STCONVERT("ParagraphTabStops.docx"),
		remoteName = localName,
		fullName = path_combine_url(remoteBaseTestDataFolder, path_combine_url(tabStopFolder, remoteName)),
		filePath = path_combine(get_data_dir(tabStopFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetParagraphTabStopsWithoutNodePathRequest> request =
		std::make_shared<GetParagraphTabStopsWithoutNodePathRequest>(remoteName, 0,
			path_combine_url(remoteBaseTestDataFolder, tabStopFolder), boost::none,
			boost::none, boost::none);

	AsposeResponse<TabStopsResponse> actual = get_api()->getParagraphTabStopsWithoutNodePath(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for inserting paragraph tab stop
/// </summary>
TEST_F(ParagraphTest, TestInsertOrUpdateParagraphTabStop) {
	utility::string_t
		localName = STCONVERT("ParagraphTabStops.docx"),
		remoteName = localName,
		fullName = path_combine_url(remoteBaseTestDataFolder, path_combine_url(tabStopFolder, remoteName)),
		filePath = path_combine(get_data_dir(tabStopFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<TabStopInsert> dto = std::make_shared<TabStopInsert>();
	dto->setAlignment(STCONVERT("Left"));
	dto->setLeader(STCONVERT("None"));
	dto->setPosition(72);

	std::shared_ptr<InsertOrUpdateParagraphTabStopRequest> request =
		std::make_shared<InsertOrUpdateParagraphTabStopRequest>(remoteName, dto, STCONVERT(""), 0,
			path_combine_url(remoteBaseTestDataFolder, tabStopFolder), boost::none,
			boost::none, boost::none, boost::none);

	AsposeResponse<TabStopsResponse> actual = get_api()->insertOrUpdateParagraphTabStop(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for inserting paragraph tab stop withou node path
/// </summary>
TEST_F(ParagraphTest, TestInsertOrUpdateParagraphTabStopWithoutNodePath) {
	utility::string_t
		localName = STCONVERT("ParagraphTabStops.docx"),
		remoteName = localName,
		fullName = path_combine_url(remoteBaseTestDataFolder, path_combine_url(tabStopFolder, remoteName)),
		filePath = path_combine(get_data_dir(tabStopFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<TabStopInsert> dto = std::make_shared<TabStopInsert>();
	dto->setAlignment(STCONVERT("Left"));
	dto->setLeader(STCONVERT("None"));
	dto->setPosition(72);

	std::shared_ptr<InsertOrUpdateParagraphTabStopWithoutNodePathRequest> request =
		std::make_shared<InsertOrUpdateParagraphTabStopWithoutNodePathRequest>(remoteName, dto, 0,
			path_combine_url(remoteBaseTestDataFolder, tabStopFolder), boost::none,
			boost::none, boost::none, boost::none);

	AsposeResponse<TabStopsResponse> actual = get_api()->insertOrUpdateParagraphTabStopWithoutNodePath(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting paragraph tab stops
/// </summary>
TEST_F(ParagraphTest, TestDeleteAllParagraphTabStops) {
	utility::string_t
		localName = STCONVERT("ParagraphTabStops.docx"),
		remoteName = localName,
		fullName = path_combine_url(remoteBaseTestDataFolder, path_combine_url(tabStopFolder, remoteName)),
		filePath = path_combine(get_data_dir(tabStopFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteAllParagraphTabStopsRequest> request =
		std::make_shared<DeleteAllParagraphTabStopsRequest>(remoteName, STCONVERT(""), 0,
			path_combine_url(remoteBaseTestDataFolder, tabStopFolder), boost::none,
			boost::none, boost::none, boost::none);

	AsposeResponse<TabStopsResponse> actual = get_api()->deleteAllParagraphTabStops(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting paragraph tab stops withot node path
/// </summary>
TEST_F(ParagraphTest, TestDeleteAllParagraphTabStopsWithoutNodePath) {
	utility::string_t
		localName = STCONVERT("ParagraphTabStops.docx"),
		remoteName = localName,
		fullName = path_combine_url(remoteBaseTestDataFolder, path_combine_url(tabStopFolder, remoteName)),
		filePath = path_combine(get_data_dir(tabStopFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteAllParagraphTabStopsWithoutNodePathRequest> request =
		std::make_shared<DeleteAllParagraphTabStopsWithoutNodePathRequest>(remoteName, 0,
			path_combine_url(remoteBaseTestDataFolder, tabStopFolder), boost::none,
			boost::none, boost::none, boost::none);

	AsposeResponse<TabStopsResponse> actual = get_api()->deleteAllParagraphTabStopsWithoutNodePath(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting a paragraph tab stop
/// </summary>
TEST_F(ParagraphTest, TestDeleteParagraphTabStop) {
	utility::string_t
		localName = STCONVERT("ParagraphTabStops.docx"),
		remoteName = localName,
		fullName = path_combine_url(remoteBaseTestDataFolder, path_combine_url(tabStopFolder, remoteName)),
		filePath = path_combine(get_data_dir(tabStopFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteParagraphTabStopRequest> request =
		std::make_shared<DeleteParagraphTabStopRequest>(remoteName, 72, STCONVERT(""), 0,
			path_combine_url(remoteBaseTestDataFolder, tabStopFolder), boost::none,
			boost::none, boost::none, boost::none);

	AsposeResponse<TabStopsResponse> actual = get_api()->deleteParagraphTabStop(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting a paragraph tab stop without node path
/// </summary>
TEST_F(ParagraphTest, TestDeleteParagraphTabStopWithoutNodePath) {
	utility::string_t
		localName = STCONVERT("ParagraphTabStops.docx"),
		remoteName = localName,
		fullName = path_combine_url(remoteBaseTestDataFolder, path_combine_url(tabStopFolder, remoteName)),
		filePath = path_combine(get_data_dir(tabStopFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteParagraphTabStopWithoutNodePathRequest> request =
		std::make_shared<DeleteParagraphTabStopWithoutNodePathRequest>(remoteName, 72, 0,
			path_combine_url(remoteBaseTestDataFolder, tabStopFolder), boost::none,
			boost::none, boost::none, boost::none);

	AsposeResponse<TabStopsResponse> actual = get_api()->deleteParagraphTabStopWithoutNodePath(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}