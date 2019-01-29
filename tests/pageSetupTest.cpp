#include "TestBase.h"

/// <summary>
/// Example of how to work with page settings
/// </summary>
class PageSetupTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements\\PageSetup")),
		textFolder = STCONVERT("DocumentElements/Text");
};

/// <summary>
/// Test for getting page settings
/// </summary>
TEST_F(PageSetupTest, TestGetSectionPageSetup) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetSectionPageSetup.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetSectionPageSetupRequest> request=
			std::make_shared<GetSectionPageSetupRequest>(remoteName, index, dataFolder, boost::none,
		boost::none, boost::none);

	std::shared_ptr<SectionPageSetupResponse> actual = get_api()->getSectionPageSetup(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for updating page settings
/// </summary>
TEST_F(PageSetupTest, TestUpdateSectionPageSetup) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestUpdateSectionPageSetup.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	int32_t index = 0;

	std::shared_ptr<PageSetup> body= std::make_shared<PageSetup>();
	body->setRtlGutter(true);
	body->setLeftMargin(10.0);
	body->setOrientation(STCONVERT("Landscape"));
	body->setPaperSize(STCONVERT("A5"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<UpdateSectionPageSetupRequest> request=
			std::make_shared<UpdateSectionPageSetupRequest>(remoteName, index, body, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none);

	std::shared_ptr<SectionPageSetupResponse> actual = get_api()->updateSectionPageSetup(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for page rendering
/// </summary>
TEST_F(PageSetupTest, TestGetRenderPage) {
	utility::string_t
		localName = STCONVERT("SampleWordDocument.docx"),
		remoteName = STCONVERT("TestGetRenderPage.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(textFolder), localName),
		format = STCONVERT("bmp");

	int32_t pageNumber = 1;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<RenderPageRequest> request=
			std::make_shared<RenderPageRequest>(remoteName, pageNumber, format, dataFolder, boost::none,
		boost::none, boost::none, boost::none);

	HttpContent result = get_api()->renderPage(request).get();

	ASSERT_TRUE(result.getData()->peek());
}