#include "TestBase.h"

/// <summary>
/// Example of how to work with sections
/// </summary>
class SectionTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements\\Section"));
};

/// <summary>
/// Test for getting section by index
/// </summary>
TEST_F(SectionTest, TestGetSection) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetSection.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);
	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetSectionRequest> request=
	        std::make_shared<GetSectionRequest>(remoteName, index, dataFolder, boost::none,
		boost::none, boost::none);

	std::shared_ptr<SectionResponse> actual = get_api()->getSection(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for getting sections
/// </summary>
TEST_F(SectionTest, TestGetSections) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetSections.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetSectionsRequest> request=
	        std::make_shared<GetSectionsRequest>(remoteName, dataFolder, boost::none,
		boost::none, boost::none);

	std::shared_ptr<SectionLinkCollectionResponse> actual = get_api()->getSections(request).get();

	ASSERT_EQ(200, actual->getCode());
}