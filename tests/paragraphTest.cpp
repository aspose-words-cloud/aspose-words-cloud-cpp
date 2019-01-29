#include "TestBase.h"

/// <summary>
/// Example of how to work with paragraph
/// </summary>
class ParagraphTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements\\Paragraphs")),
		fieldFolder = STCONVERT("DocumentElements/Fields");
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

	std::shared_ptr<GetDocumentParagraphRequest> request=
			std::make_shared<GetDocumentParagraphRequest>(remoteName, index, dataFolder, boost::none,
		boost::none, boost::none, STCONVERT("sections/0"));

	std::shared_ptr<ParagraphResponse> actual = get_api()->getDocumentParagraph(request).get();

	ASSERT_EQ(200, actual->getCode());
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

	std::shared_ptr<GetDocumentParagraphsRequest> request=
			std::make_shared<GetDocumentParagraphsRequest>(remoteName, dataFolder, boost::none,
		boost::none, boost::none, STCONVERT("sections/0"));

	std::shared_ptr<ParagraphLinkCollectionResponse> actual = get_api()->getDocumentParagraphs(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for getting first paragraph
/// </summary>
TEST_F(ParagraphTest, TestGetDocumentParagraphWithoutNodePath) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentParagraphWithoutNodePath.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);
	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetDocumentParagraphRequest> request=
			std::make_shared<GetDocumentParagraphRequest>(remoteName, index, dataFolder, boost::none,
		boost::none, boost::none, boost::none);

	std::shared_ptr<ParagraphResponse> actual = get_api()->getDocumentParagraph(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for getting paragraph run
/// </summary>
TEST_F(ParagraphTest, TestGetDocumentParagraphRun) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentParagraphRun.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);
	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetDocumentParagraphRunRequest> request=
			std::make_shared<GetDocumentParagraphRunRequest>(remoteName, STCONVERT("paragraphs/0"), index, dataFolder,
		boost::none, boost::none, boost::none);

	std::shared_ptr<RunResponse> actual = get_api()->getDocumentParagraphRun(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for getting paragraph run font
/// </summary>
TEST_F(ParagraphTest, TestGetDocumentParagraphRunFont) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentParagraphRunFont.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);
	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetDocumentParagraphRunFontRequest> request=
			std::make_shared<GetDocumentParagraphRunFontRequest>(remoteName, STCONVERT("paragraphs/0"),
		index, dataFolder, boost::none, boost::none, boost::none);

	std::shared_ptr<FontResponse> actual = get_api()->getDocumentParagraphRunFont(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for getting paragraph run
/// </summary>
TEST_F(ParagraphTest, TestGetParagraphRuns) {
	utility::string_t
		localName = STCONVERT("GetField.docx"),
		remoteName = STCONVERT("TestGetParagraphRuns.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(fieldFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetDocumentParagraphRunsRequest> request=
			std::make_shared<GetDocumentParagraphRunsRequest>(remoteName, STCONVERT("sections/0/paragraphs/0"),
		dataFolder, boost::none, boost::none, boost::none);

	std::shared_ptr<RunsResponse> actual = get_api()->getDocumentParagraphRuns(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for updating paragraph run fon
/// </summary>
TEST_F(ParagraphTest, TestPostDocumentParagraphRunFont) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPostDocumentParagraphRunFont.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName),
		destFileName = path_combine_url(baseTestOutPath, remoteName);
	int32_t index = 0;

	std::shared_ptr<Font> fontDto= std::make_shared<Font>();
	fontDto->setBold(true);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PostDocumentParagraphRunFontRequest> request=
			std::make_shared<PostDocumentParagraphRunFontRequest>(remoteName, fontDto, STCONVERT("paragraphs/0"),
		index, dataFolder, boost::none, boost::none, boost::none, destFileName, boost::none, boost::none);

	std::shared_ptr<FontResponse> actual = get_api()->postDocumentParagraphRunFont(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for adding paragraph
/// </summary>
TEST_F(ParagraphTest, TestPutParagraph) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPutParagraph.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	std::shared_ptr<ParagraphInsert> paragraph= std::make_shared<ParagraphInsert>();
	paragraph->setText(STCONVERT("This is a new paragraph for your document"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PutParagraphRequest> request=
			std::make_shared<PutParagraphRequest>(remoteName, paragraph, dataFolder, boost::none, boost::none,
					boost::none, boost::none, boost::none, boost::none, STCONVERT("sections/0"), boost::none);

	std::shared_ptr<ParagraphResponse> actual = get_api()->putParagraph(request).get();

	ASSERT_EQ(200, actual->getCode());
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
			std::make_shared<DeleteParagraphRequest>(remoteName,0, dataFolder, boost::none, boost::none,
					boost::none, boost::none, boost::none, boost::none, boost::none);

	std::shared_ptr<AsposeResponse> actual = get_api()->deleteParagraph(request).get();

	ASSERT_EQ(200, actual->getCode());
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
			std::make_shared<RenderParagraphRequest>(remoteName, format, index,
		dataFolder, boost::none, boost::none, boost::none, boost::none, boost::none);

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

	std::shared_ptr<GetDocumentParagraphFormatRequest> request=
			std::make_shared<GetDocumentParagraphFormatRequest>(remoteName, 0,
		dataFolder, boost::none, boost::none, boost::none, boost::none);

	std::shared_ptr<ParagraphFormatResponse> actual = get_api()->getDocumentParagraphFormat(request).get();

	ASSERT_EQ(200, actual->getCode());
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

	std::shared_ptr<PostDocumentParagraphFormatRequest> request=
			std::make_shared<PostDocumentParagraphFormatRequest>(remoteName, body, STCONVERT(""), 0,
		dataFolder, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);

	std::shared_ptr<ParagraphFormatResponse> actual = get_api()->postDocumentParagraphFormat(request).get();

	ASSERT_EQ(200, actual->getCode());
}

