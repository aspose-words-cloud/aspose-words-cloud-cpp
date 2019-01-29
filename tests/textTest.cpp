#include "TestBase.h"

/// <summary>
/// Example of how to work with text
/// </summary>
class TextTest : public InfrastructureTest {
protected:
	utility::string_t textFolder = STCONVERT("DocumentElements/Text"),
		remoteTextFolder = path_combine_url(remoteBaseTestDataFolder, textFolder);
};

/// <summary>
/// Test for getting text from document
/// </summary>
TEST_F(TextTest, TestGetDocumentTextItems) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentTextItems.docx"),
		fullName = path_combine_url(remoteTextFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetDocumentTextItemsRequest> request=
			std::make_shared<GetDocumentTextItemsRequest>(remoteName, remoteTextFolder, boost::none,
		boost::none, boost::none);

	std::shared_ptr<TextItemsResponse> actual = get_api()->getDocumentTextItems(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for replacing text
/// </summary>
TEST_F(TextTest, TestPostReplaceText) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPostReplaceText.docx"),
		fullName = path_combine_url(remoteTextFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName),
		destFileName = path_combine_url(baseTestOutPath, remoteName);

	std::shared_ptr<ReplaceTextRequest> body = std::make_shared<ReplaceTextRequest>();
	body->setOldValue(STCONVERT("aspose"));
	body->setNewValue(STCONVERT("aspose new"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PostReplaceTextRequest> request= std::make_shared<PostReplaceTextRequest>(remoteName, body, remoteTextFolder, boost::none,
		boost::none, boost::none, destFileName, boost::none, boost::none);

	std::shared_ptr<ReplaceTextResponse> actual = get_api()->postReplaceText(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for searching
/// </summary>
TEST_F(TextTest, TestSearch) {
	utility::string_t
		localName = STCONVERT("SampleWordDocument.docx"),
		remoteName = STCONVERT("TestSearch.docx"),
		fullName = path_combine_url(remoteTextFolder, remoteName),
		filePath = path_combine(get_data_dir(textFolder), localName),
		pattern = STCONVERT("aspose");

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<SearchRequest> request=
			std::make_shared<SearchRequest>(remoteName, pattern, remoteTextFolder, boost::none,
		boost::none, boost::none);

	std::shared_ptr<SearchResponse> actual = get_api()->search(request).get();

	ASSERT_EQ(200, actual->getCode());
}