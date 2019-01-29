#include "TestBase.h"

/// <summary>
/// Example of how to work with hyperlinks
/// </summary>
class HyperlinkTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements\\Hyperlink"));
};

/// <summary>
/// Test for getting hyperlink by specified index
/// </summary>
TEST_F(HyperlinkTest, TestGetDocumentHyperlinkByIndex) {
	utility::string_t
		localName = STCONVERT("test_doc.docx"),
		remoteName = STCONVERT("TestGetDocumentHyperlinkByIndex.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	int32_t hyperlinkIndex = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetDocumentHyperlinkByIndexRequest> request=
			std::make_shared<GetDocumentHyperlinkByIndexRequest>(remoteName, hyperlinkIndex, dataFolder,
					boost::none, boost::none, boost::none);

	std::shared_ptr<HyperlinkResponse> actual = get_api()->getDocumentHyperlinkByIndex(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for getting hyperlinks
/// </summary>
TEST_F(HyperlinkTest, TestGetDocumentHyperlinks) {
	utility::string_t
		localName = STCONVERT("test_doc.docx"),
		remoteName = STCONVERT("TestGetDocumentHyperlinks.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetDocumentHyperlinksRequest> request=
			std::make_shared<GetDocumentHyperlinksRequest>(remoteName, dataFolder, boost::none,
		boost::none, boost::none);

	std::shared_ptr<HyperlinksResponse> actual = get_api()->getDocumentHyperlinks(request).get();

	ASSERT_EQ(200, actual->getCode());
}