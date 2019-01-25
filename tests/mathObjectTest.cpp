#include "TestBase.h"

/// <summary>
/// Example of how to work with MathObjects
/// </summary>
class MathObjectTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements\\MathObjects")),
		mathObjectFolder = STCONVERT("DocumentElements/MathObjects");
};

/// <summary>
/// Test for getting mathObjects
/// </summary>
TEST_F(MathObjectTest, TestGetOfficeMathObjects) {
	utility::string_t
		localName = STCONVERT("MathObjects.docx"),
		remoteName = STCONVERT("TestGetOfficeMathObjects.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(mathObjectFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetOfficeMathObjectsRequest> request(new GetOfficeMathObjectsRequest(remoteName, dataFolder, boost::none,
		boost::none, boost::none, boost::none));

	std::shared_ptr<OfficeMathObjectsResponse> actual = get_api()->getOfficeMathObjects(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for getting mathObject
/// </summary>
TEST_F(MathObjectTest, TestGetOfficeMathObject) {
	utility::string_t
		localName = STCONVERT("MathObjects.docx"),
		remoteName = STCONVERT("TestGetOfficeMathObject.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(mathObjectFolder), localName);

	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetOfficeMathObjectRequest> request(new GetOfficeMathObjectRequest(remoteName, index, dataFolder, boost::none,
		boost::none, boost::none, boost::none));

	std::shared_ptr<OfficeMathObjectResponse> actual = get_api()->getOfficeMathObject(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for rendering mathObject
/// </summary>
TEST_F(MathObjectTest, TestRenderMathObject) {
	utility::string_t
		localName = STCONVERT("MathObjects.docx"),
		remoteName = STCONVERT("TestRenderMathObject.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(mathObjectFolder), localName);

	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<RenderMathObjectRequest> request(new RenderMathObjectRequest(remoteName, STCONVERT("png"), index, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none));

	HttpContent result = get_api()->renderMathObject(request).get();

	ASSERT_TRUE(result.getData()->peek());
}

/// <summary>
/// Test for deleting mathObject
/// </summary>
TEST_F(MathObjectTest, TestDeleteMathObject) {
	utility::string_t
		localName = STCONVERT("MathObjects.docx"),
		remoteName = STCONVERT("TestDeleteMathObject.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(mathObjectFolder), localName);

	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteOfficeMathObjectRequest> request(new DeleteOfficeMathObjectRequest(remoteName, index, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, boost::none));

	std::shared_ptr<AsposeResponse> actual = get_api()->deleteOfficeMathObject(request).get();

	ASSERT_EQ(200, actual->getCode());
}