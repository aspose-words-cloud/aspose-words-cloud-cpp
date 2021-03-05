/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="fileTests.cpp">
*   Copyright (c) 2021 Aspose.Words for Cloud
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

#include "../TestBase.h"

/// <summary>
/// Example of how to work with files.
/// </summary>
class FileTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/Storage");
    utility::string_t localFile = STCONVERT("Common/test_multi_pages.docx");

};

/// <summary>
/// Test for uploading file.
/// </summary>
TEST_F(FileTests, TestUploadFile) {
    auto fileContentContent = generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile));
    utility::string_t remoteFileName = STCONVERT("TestUploadFile.docx");

    std::shared_ptr< UploadFileRequest > request(new UploadFileRequest(
        fileContentContent,
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        boost::none
    ));

   auto actual = get_api()->uploadFile(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getUploaded()));
   ASSERT_EQ(1, actual.body->getUploaded().size());
   ASSERT_EQ(STCONVERT("TestUploadFile.docx"), actual.body->getUploaded()[0]);
}

/// <summary>
/// Test for copy file.
/// </summary>
TEST_F(FileTests, TestCopyFile) {
    utility::string_t remoteFileName = STCONVERT("TestCopyFileSrc.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< CopyFileRequest > request(new CopyFileRequest(
        remoteDataFolder + STCONVERT("/TestCopyFileDest.docx"),
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->copyFile(request).get();
}

/// <summary>
/// Test for move file.
/// </summary>
TEST_F(FileTests, TestMoveFile) {
    utility::string_t remoteFileName = STCONVERT("TestMoveFileSrc.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< MoveFileRequest > request(new MoveFileRequest(
        baseTestOutPath + STCONVERT("/TestMoveFileDest_") + create_random_guid() + STCONVERT(".docx"),
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->moveFile(request).get();
}

/// <summary>
/// Test for delete file.
/// </summary>
TEST_F(FileTests, TestDeleteFile) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteFile.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< DeleteFileRequest > request(new DeleteFileRequest(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        boost::none,
        boost::none
    ));

   get_api()->deleteFile(request).get();
}

/// <summary>
/// Test for download file.
/// </summary>
TEST_F(FileTests, TestDownloadFile) {
    utility::string_t remoteFileName = STCONVERT("TestDownloadFile.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< DownloadFileRequest > request(new DownloadFileRequest(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        boost::none,
        boost::none
    ));

   get_api()->downloadFile(request).get();
}
