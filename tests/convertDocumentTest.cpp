#include "TestBase.h"

class ConvertDocumentTest : public InfrastructureTest {
protected:
	const utility::string_t baseFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentActions\\ConvertDocument")),
		convertFolder = STCONVERT("DocumentActions\\ConvertDocument");
};

/// <summary>
/// Test for converting document to one of the available formats
/// </summary>
TEST_F(ConvertDocumentTest, TestPostDocumentSaveAs) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPostDocumentSaveAs.docx"),
		fullName = path_combine_url(baseFolder, remoteName),
		destFileName = path_combine_url(baseTestOutPath, cutFileExtension(remoteName) + STCONVERT(".pdf")),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	std::shared_ptr<SaveOptionsData> saveOptionsData(new SaveOptionsData);
	saveOptionsData->setSaveFormat(STCONVERT("pdf"));
	saveOptionsData->setFileName(destFileName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PostDocumentSaveAsRequest> request(new PostDocumentSaveAsRequest(remoteName, saveOptionsData, baseFolder, boost::none, boost::none
		, boost::none, boost::none, boost::none));

	std::shared_ptr<SaveResponse> actual = get_api()->postDocumentSaveAs(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for converting document to one of the available formats
/// </summary>
TEST_F(ConvertDocumentTest, TestPostDocumentSaveAsFromPdfToDoc) {
	utility::string_t
		localName = STCONVERT("45.pdf"),
		remoteName = STCONVERT("TestPostDocumentSaveAsFromPdfToDoc.pdf"),
		fullName = path_combine_url(baseFolder, remoteName),
		destFileName = path_combine_url(baseTestOutPath, cutFileExtension(remoteName) + STCONVERT(".docx")),
		filePath = path_combine(get_data_dir(convertFolder), localName);

	std::shared_ptr<SaveOptionsData> saveOptionsData(new SaveOptionsData);
	saveOptionsData->setSaveFormat(STCONVERT("docx"));
	saveOptionsData->setFileName(destFileName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PostDocumentSaveAsRequest> request(new PostDocumentSaveAsRequest(remoteName, saveOptionsData, baseFolder, boost::none, boost::none
		, boost::none, boost::none, boost::none));

	std::shared_ptr<SaveResponse> actual = get_api()->postDocumentSaveAs(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// A test for PutConvertDocument
/// </summary>
TEST_F(ConvertDocumentTest, TestPutConvertDocument) {
	utility::string_t format = STCONVERT("pdf");
	std::shared_ptr<PutConvertDocumentRequest> request(
		new PutConvertDocumentRequest(generate_http_content_from_file(path_combine(get_data_dir(convertFolder), STCONVERT("test_uploadfile.docx"))),
			format, boost::none, boost::none, boost::none, boost::none));

	auto result = get_api()->putConvertDocument(request).get();
	ASSERT_TRUE(result.getData()->peek());
}

/// <summary>
/// Test for saving document as a tiff file
/// </summary>
TEST_F(ConvertDocumentTest, TestPutDocumentAsTiff) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPutDocumentAsTiff.docx"),
		fullName = path_combine_url(baseFolder, remoteName),
		destFileName = path_combine_url(baseTestOutPath, cutFileExtension(remoteName) + STCONVERT(".tiff")),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	std::shared_ptr<TiffSaveOptionsData> saveOptionsData(new TiffSaveOptionsData);
	saveOptionsData->setSaveFormat(STCONVERT("tiff"));
	saveOptionsData->setFileName(STCONVERT("abc.tiff"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PutDocumentSaveAsTiffRequest> request(new PutDocumentSaveAsTiffRequest(remoteName, saveOptionsData, baseFolder, boost::none, boost::none
		, boost::none, destFileName, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none
		, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none,
		boost::none));

	std::shared_ptr<SaveResponse> actual = get_api()->putDocumentSaveAsTiff(request).get();

	ASSERT_EQ(200, actual->getCode());
}
