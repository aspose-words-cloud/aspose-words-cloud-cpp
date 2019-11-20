/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="folderTest.cpp">
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
/// Example of how to work with folders
/// </summary>
class FolderTest : public InfrastructureTest {
protected:
	const utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentActions/Document"));
};

/// <summary>
/// Test for copying folder
/// </summary>
TEST_F(FolderTest, TestCopyFolder) {
	utility::string_t
		fullSrcName = path_combine_url(dataFolder, STCONVERT("CopyFolderSrc")),
		fullDestName = path_combine_url(dataFolder, STCONVERT("CopyFolderDest"));

	std::shared_ptr<CreateFolderRequest> createFolderRequest = std::make_shared<CreateFolderRequest>(fullSrcName, boost::none);
	auto result = get_api()->createFolder(createFolderRequest).get();

	ASSERT_EQ(200, result->status_code());

	std::shared_ptr<CopyFolderRequest> request = std::make_shared<CopyFolderRequest>(fullDestName, fullSrcName, boost::none, boost::none);
	std::shared_ptr<web::http::http_response> actual = get_api()->copyFolder(request).get();

	ASSERT_EQ(200, actual->status_code());
}

/// <summary>
/// Test for creating folder
/// </summary>
TEST_F(FolderTest, TestCreateFolder) {
	utility::string_t
		fullName = path_combine_url(dataFolder, STCONVERT("CreateFolder"));

	std::shared_ptr<CreateFolderRequest> createFolderRequest = std::make_shared<CreateFolderRequest>(fullName, boost::none);
	std::shared_ptr<web::http::http_response> actual = get_api()->createFolder(createFolderRequest).get();

	ASSERT_EQ(200, actual->status_code());
}

/// <summary>
/// Test for deleting folder
/// </summary>
TEST_F(FolderTest, TestDeleteFolder) {
	utility::string_t
		fullName = path_combine_url(dataFolder, STCONVERT("DeleteFolder"));

	std::shared_ptr<CreateFolderRequest> createFolderRequest = std::make_shared<CreateFolderRequest>(fullName, boost::none);
	auto result = get_api()->createFolder(createFolderRequest).get();

	ASSERT_EQ(200, result->status_code());

	std::shared_ptr<DeleteFolderRequest> request = std::make_shared<DeleteFolderRequest>(fullName, boost::none, boost::none);
	std::shared_ptr<web::http::http_response> actual = get_api()->deleteFolder(request).get();

	ASSERT_EQ(200, actual->status_code());
}

/// <summary>
/// Test for getting file list for folder
/// </summary>
TEST_F(FolderTest, TestGetFilesList) {
	utility::string_t
		fullName = path_combine_url(dataFolder, STCONVERT("GetFileList"));

	std::shared_ptr<CreateFolderRequest> createFolderRequest = std::make_shared<CreateFolderRequest>(fullName, boost::none);
	auto result = get_api()->createFolder(createFolderRequest).get();

	std::shared_ptr<GetFilesListRequest> request = std::make_shared<GetFilesListRequest>(dataFolder, boost::none);
	AsposeResponse<FilesList> actual = get_api()->getFilesList(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for moving folder
/// </summary>
TEST_F(FolderTest, TestMoveFolder) {
	utility::string_t
		fullSrcName = path_combine_url(dataFolder, STCONVERT("MoveFolderSrc")),
		fullDestName = path_combine_url(dataFolder, STCONVERT("MoveFolderDest"));

	std::shared_ptr<CreateFolderRequest> createFolderRequest = std::make_shared<CreateFolderRequest>(fullSrcName, boost::none);
	auto result = get_api()->createFolder(createFolderRequest).get();

	ASSERT_EQ(200, result->status_code());

	std::shared_ptr<MoveFolderRequest> request = std::make_shared<MoveFolderRequest>(fullDestName, fullSrcName, boost::none, boost::none);
	std::shared_ptr<web::http::http_response> actual = get_api()->moveFolder(request).get();

	ASSERT_EQ(200, actual->status_code());
}

