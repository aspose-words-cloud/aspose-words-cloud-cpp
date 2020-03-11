/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="fileTest.cpp">
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
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

/// <summary>
/// Example of how to work with a file
/// </summary>
class FileTest : public InfrastructureTest {
protected:
	const utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentActions/Document"));
};

/// <summary>
/// Test for uploading file
/// </summary>
TEST_F(FileTest, TestUploadFile) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestCopyFileSrc.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	std::shared_ptr<UploadFileRequest> request = std::make_shared<UploadFileRequest>(
		generate_http_content_from_file(filePath), fullName, boost::none);

	auto actual = get_api()->uploadFile(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for copying file
/// </summary>
TEST_F(FileTest, TestCopyFile) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteSrcName = STCONVERT("TestCopyFileSrc.docx"),
		remoteDestName = STCONVERT("TestCopyFileDest.docx"),
		fullSrcName = path_combine_url(dataFolder, remoteSrcName),
		fullDestName = path_combine_url(dataFolder, remoteDestName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullSrcName, filePath);

	std::shared_ptr<CopyFileRequest> request = std::make_shared<CopyFileRequest>(fullDestName, fullSrcName, boost::none, boost::none, boost::none);
	std::shared_ptr<web::http::http_response> actual = get_api()->copyFile(request).get();

	ASSERT_EQ(200, actual->status_code());

	ASSERT_TRUE(DoesFileExist(fullSrcName));
	ASSERT_TRUE(DoesFileExist(fullDestName));
}

/// <summary>
/// Test for deleting file
/// </summary>
TEST_F(FileTest, TestDeleteFile) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestDeleteFile.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteFileRequest> request = std::make_shared<DeleteFileRequest>(fullName, boost::none, boost::none);
	std::shared_ptr<web::http::http_response> actual = get_api()->deleteFile(request).get();

	ASSERT_EQ(200, actual->status_code());
	ASSERT_FALSE(DoesFileExist(fullName));
}

/// <summary>
/// Test for moving file
/// </summary>
TEST_F(FileTest, TestMoveFile) {
	boost::uuids::uuid uuid = boost::uuids::random_generator()();
	const std::string uuid_string = boost::uuids::to_string(uuid);

	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteSrcName = STCONVERT("TestMoveFileSrc.docx"),
		remoteDestName = STCONVERT("TestMoveFileDest" + uuid_string + ".docx"),
		fullSrcName = path_combine_url(dataFolder, remoteSrcName),
		fullDestName = path_combine_url(dataFolder, remoteDestName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullSrcName, filePath);

	std::shared_ptr<MoveFileRequest> request = std::make_shared<MoveFileRequest>(fullDestName, fullSrcName, boost::none, boost::none, boost::none);
	std::shared_ptr<web::http::http_response> actual = get_api()->moveFile(request).get();

	ASSERT_EQ(200, actual->status_code());

	ASSERT_FALSE(DoesFileExist(fullSrcName));
	ASSERT_TRUE(DoesFileExist(fullDestName));
}