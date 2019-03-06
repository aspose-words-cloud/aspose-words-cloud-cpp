/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="mathObjectTest.cpp">
*   Copyright (c) 2019 Aspose.Words for Cloud
* </copyright>
* <summary>
*   Permission is hereby granted, free of charge, to any person obtaining a copy
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is
*  furnished to do so, subject to the following conditions:
* 
*  The above copyright notice and this permission notice shall be included in all
*  copies or substantial portions of the Software.
* 
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*  SOFTWARE.
* </summary> 
-------------------------------------------------------------------------------------------------------------------- **/
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

	std::shared_ptr<GetOfficeMathObjectsRequest> request=
			std::make_shared<GetOfficeMathObjectsRequest>(remoteName, dataFolder, boost::none,
		boost::none, boost::none, boost::none);

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

	std::shared_ptr<GetOfficeMathObjectRequest> request=
			std::make_shared<GetOfficeMathObjectRequest>(remoteName, index, dataFolder, boost::none,
		boost::none, boost::none, boost::none);

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

	std::shared_ptr<RenderMathObjectRequest> request=
			std::make_shared<RenderMathObjectRequest>(remoteName, STCONVERT("png"), index, dataFolder,
					boost::none, boost::none, boost::none, boost::none, boost::none);

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

	std::shared_ptr<DeleteOfficeMathObjectRequest> request=
			std::make_shared<DeleteOfficeMathObjectRequest>(remoteName, index, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);

	std::shared_ptr<AsposeResponse> actual = get_api()->deleteOfficeMathObject(request).get();

	ASSERT_EQ(200, actual->getCode());
}