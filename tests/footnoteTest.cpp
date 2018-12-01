#include "TestBase.h"

/// <summary>
/// Example of how to work with footnotes
/// </summary>
class FootnoteTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements\\Footnotes")),
		footnoteFolder = STCONVERT("DocumentElements\\Footnotes");
};

/// <summary>
/// Test for adding footnote
/// </summary>
TEST_F(FootnoteTest, TestPutFootnote) {
	utility::string_t
		localName = STCONVERT("Footnote.doc"),
		remoteName = STCONVERT("TestPutFootnote.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(footnoteFolder), localName);

	std::shared_ptr<Footnote> footnote(new Footnote);
	footnote->setFootnoteType(STCONVERT("Endnote"));
	footnote->setText(STCONVERT("test endnote"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PutFootnoteRequest> request(new PutFootnoteRequest(remoteName, footnote, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, boost::none));

	std::shared_ptr<FootnoteResponse> actual = get_api()->putFootnote(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for deleting footnote
/// </summary>
TEST_F(FootnoteTest, TestDeleteFootnote) {
	utility::string_t
		localName = STCONVERT("Footnote.doc"),
		remoteName = STCONVERT("TestDeleteFootnote.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(footnoteFolder), localName);

	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteFootnoteRequest> request(new DeleteFootnoteRequest(remoteName, index, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, boost::none));

	std::shared_ptr<AsposeResponse> actual = get_api()->deleteFootnote(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for getting footnotes
/// </summary>
TEST_F(FootnoteTest, TestGetFootnotes) {
	utility::string_t
		localName = STCONVERT("Footnote.doc"),
		remoteName = STCONVERT("TestGetFootnotes.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(footnoteFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetFootnotesRequest> request(new GetFootnotesRequest(remoteName, dataFolder, boost::none,
		boost::none, boost::none, boost::none));

	std::shared_ptr<FootnotesResponse> actual = get_api()->getFootnotes(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for getting footnote
/// </summary>
TEST_F(FootnoteTest, TestGetFootnote) {
	utility::string_t
		localName = STCONVERT("Footnote.doc"),
		remoteName = STCONVERT("TestGetFootnote.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(footnoteFolder), localName);
	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetFootnoteRequest> request(new GetFootnoteRequest(remoteName, index, dataFolder, boost::none,
		boost::none, boost::none, boost::none));

	std::shared_ptr<FootnoteResponse> actual = get_api()->getFootnote(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for updating footnote
/// </summary>
TEST_F(FootnoteTest, TestPostFootnote) {
	utility::string_t
		localName = STCONVERT("Footnote.doc"),
		remoteName = STCONVERT("TestPostFootnote.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(footnoteFolder), localName);
	int32_t index = 0;
	std::shared_ptr<Footnote> footnote(new Footnote);
	footnote->setText(STCONVERT("new text is here"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PostFootnoteRequest> request(new PostFootnoteRequest(remoteName, footnote, index, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, boost::none));

	std::shared_ptr<FootnoteResponse> actual = get_api()->postFootnote(request).get();

	ASSERT_EQ(200, actual->getCode());
}