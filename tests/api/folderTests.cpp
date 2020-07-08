/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="folderTests.cpp">
*   Copyright (c) 2020 Aspose.Words for Cloud
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
/// Example of how to work with folders.
/// </summary>
class FolderTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/Storage");
    utility::string_t localFile = STCONVERT("Common/test_multi_pages.docx");

};

/// <summary>
/// Test for create folder.
/// </summary>
TEST_F(FolderTests, TestCreateFolder) {
    std::shared_ptr< CreateFolderRequest > request(new CreateFolderRequest(
        remoteDataFolder + STCONVERT("/TestCreateFolder"),
        boost::none
    ));

   get_api()->createFolder(request).get();
}

/// <summary>
/// Test for delete folder.
/// </summary>
TEST_F(FolderTests, TestDeleteFolder) {
    utility::string_t testDeleteFolder = remoteDataFolder + STCONVERT("/TestDeleteFolder");

    UploadFileToStorage(
        testDeleteFolder + STCONVERT("/TestDeleteFolder.docx"),
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< DeleteFolderRequest > request(new DeleteFolderRequest(
        testDeleteFolder,
        boost::none,
        boost::none
    ));

   get_api()->deleteFolder(request).get();
}

/// <summary>
/// Test for get file list of folder.
/// </summary>
TEST_F(FolderTests, TestGetFilesList) {
    std::shared_ptr< GetFilesListRequest > request(new GetFilesListRequest(
        remoteDataFolder,
        boost::none
    ));

   auto actual = get_api()->getFilesList(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for copy folder.
/// </summary>
TEST_F(FolderTests, TestCopyFolder) {
    utility::string_t folderToCopy = remoteDataFolder + STCONVERT("/TestCopyFolder");

    UploadFileToStorage(
        folderToCopy + STCONVERT("Src/TestCopyFolderSrc.docx"),
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< CopyFolderRequest > request(new CopyFolderRequest(
        folderToCopy + STCONVERT("Dest"),
        folderToCopy + STCONVERT("Src"),
        boost::none,
        boost::none
    ));

   get_api()->copyFolder(request).get();
}

/// <summary>
/// Test for move folder.
/// </summary>
TEST_F(FolderTests, TestMoveFolder) {
    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/TestMoveFolderSrc/TestMoveFolderSrc.docx"),
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< MoveFolderRequest > request(new MoveFolderRequest(
        baseTestOutPath + STCONVERT("/TestMoveFolderDest_") + create_random_guid(),
        remoteDataFolder + STCONVERT("/TestMoveFolderSrc"),
        boost::none,
        boost::none
    ));

   get_api()->moveFolder(request).get();
}
