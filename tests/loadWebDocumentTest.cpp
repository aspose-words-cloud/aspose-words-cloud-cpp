#include "TestBase.h"

/// <summary>
/// Example of how to load web document
/// </summary>
class LoadWebDocumentTest : public InfrastructureTest {
protected:
	const utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentActions\\DocumentWithFormat"));
};

/// <summary>
/// Test for loading web document
/// </summary>
TEST_F(LoadWebDocumentTest, TestPostLoadWebDocument) {
	std::shared_ptr<LoadWebDocumentData> body(new LoadWebDocumentData);
	std::shared_ptr<SaveOptionsData> saveOptions(new SaveOptionsData);
	saveOptions->setFileName(STCONVERT("google.doc"));
	saveOptions->setSaveFormat(STCONVERT("doc"));
	saveOptions->setColorMode(STCONVERT("1"));
	saveOptions->setDmlEffectsRenderingMode(STCONVERT("1"));
	saveOptions->setDmlRenderingMode(STCONVERT("1"));
	saveOptions->setUpdateSdtContent(false);
	saveOptions->setZipOutput(false);

	body->setLoadingDocumentUrl(STCONVERT("http://google.com"));
	body->setSaveOptions(saveOptions);

	std::shared_ptr<PostLoadWebDocumentRequest> request(new PostLoadWebDocumentRequest(body, boost::none));
	std::shared_ptr<SaveResponse> actual = get_api()->postLoadWebDocument(request).get();

	ASSERT_EQ(200, actual->getCode());
}

