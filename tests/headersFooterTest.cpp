#include "TestBase.h"

/// <summary>
/// Example of how to work with headers and footers
/// </summary>
class HeadersFooterTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements\\Footnotes")),
		headerFooterFolder = STCONVERT("DocumentElements/HeaderFooters");
};

/// <summary>
/// Test for getting headers and footers
/// </summary>
TEST_F(HeadersFooterTest, TestGetHeadersFooters) {
	utility::string_t
		localName = STCONVERT("HeadersFooters.doc"),
		remoteName = STCONVERT("TestGetHeadersFooters.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(headerFooterFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetHeaderFootersRequest> request(new GetHeaderFootersRequest(remoteName, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none));

	std::shared_ptr<HeaderFootersResponse> actual = get_api()->getHeaderFooters(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for getting headerfooter
/// </summary>
TEST_F(HeadersFooterTest, TestGetHeaderFooter) {
	utility::string_t
		localName = STCONVERT("HeadersFooters.doc"),
		remoteName = STCONVERT("TestGetHeaderFooter.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(headerFooterFolder), localName);

	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetHeaderFooterRequest> request(new GetHeaderFooterRequest(remoteName, index, dataFolder, boost::none,
		boost::none, boost::none, boost::none));

	std::shared_ptr<HeaderFooterResponse> actual = get_api()->getHeaderFooter(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for getting headerfooter of section
/// </summary>
TEST_F(HeadersFooterTest, TestGetHeaderFooterOfSection) {
	utility::string_t
		localName = STCONVERT("HeadersFooters.doc"),
		remoteName = STCONVERT("TestGetHeaderFooterOfSection.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(headerFooterFolder), localName);

	int32_t index = 0,
		sectionIndex = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetHeaderFooterOfSectionRequest> request(new GetHeaderFooterOfSectionRequest(remoteName, index, sectionIndex, dataFolder, boost::none,
		boost::none, boost::none, boost::none));

	std::shared_ptr<HeaderFooterResponse> actual = get_api()->getHeaderFooterOfSection(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for deleting headerfooter
/// </summary>
TEST_F(HeadersFooterTest, TestDeleteHeaderFooter) {
	utility::string_t
		localName = STCONVERT("HeadersFooters.doc"),
		remoteName = STCONVERT("TestDeleteHeaderFooter.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(headerFooterFolder), localName);

	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteHeaderFooterRequest> request(new DeleteHeaderFooterRequest(remoteName, index, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, boost::none));

	std::shared_ptr<AsposeResponse> actual = get_api()->deleteHeaderFooter(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for deleting headerfooters
/// </summary>
TEST_F(HeadersFooterTest, TestDeleteHeaderFooters) {
	utility::string_t
		localName = STCONVERT("HeadersFooters.doc"),
		remoteName = STCONVERT("TestDeleteHeaderFooters.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(headerFooterFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteHeadersFootersRequest> request(new DeleteHeadersFootersRequest(remoteName, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none));

	std::shared_ptr<AsposeResponse> actual = get_api()->deleteHeadersFooters(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for adding headerfooters
/// </summary>
TEST_F(HeadersFooterTest, TestPutHeaderFooter) {
	utility::string_t
		localName = STCONVERT("HeadersFooters.doc"),
		remoteName = STCONVERT("TestPutHeaderFooter.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(headerFooterFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PutHeaderFooterRequest> request(new PutHeaderFooterRequest(remoteName, STCONVERT("FooterEven"), dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, boost::none));

	std::shared_ptr<AsposeResponse> actual = get_api()->putHeaderFooter(request).get();

	ASSERT_EQ(200, actual->getCode());
}