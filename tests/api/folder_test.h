/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="folder_test.h">
*   Copyright (c) 2022 Aspose.Words for Cloud
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

#pragma once
#include "../test_base.h"

/// <summary>
/// Example of how to work with folders.
/// </summary>
class FolderTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/Storage";
    std::wstring localFile = L"Common/test_multi_pages.docx";

};

/// <summary>
/// Test for create folder.
/// </summary>
TEST_F(FolderTests, TestCreateFolder) {
    std::shared_ptr<requests::CreateFolderRequest> request(new requests::CreateFolderRequest(
        std::make_shared< std::wstring >(remoteDataFolder + L"/TestCreateFolder"),
        nullptr
    ));

getApi()->createFolder(request);
}

/// <summary>
/// Test for delete folder.
/// </summary>
TEST_F(FolderTests, TestDeleteFolder) {
    std::wstring testDeleteFolder = remoteDataFolder + L"/TestDeleteFolder";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        testDeleteFolder + L"/TestDeleteFolder.docx"
    );

    std::shared_ptr<requests::DeleteFolderRequest> request(new requests::DeleteFolderRequest(
        std::make_shared< std::wstring >(testDeleteFolder),
        nullptr,
        nullptr
    ));

getApi()->deleteFolder(request);
}

/// <summary>
/// Test for get file list of folder.
/// </summary>
TEST_F(FolderTests, TestGetFilesList) {
    std::shared_ptr<requests::GetFilesListRequest> request(new requests::GetFilesListRequest(
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr
    ));

    auto actual = getApi()->getFilesList(request);
    ASSERT_TRUE(actual->getValue() != nullptr);
}

/// <summary>
/// Test for copy folder.
/// </summary>
TEST_F(FolderTests, TestCopyFolder) {
    std::wstring folderToCopy = remoteDataFolder + L"/TestCopyFolder";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        folderToCopy + L"Src/TestCopyFolderSrc.docx"
    );

    std::shared_ptr<requests::CopyFolderRequest> request(new requests::CopyFolderRequest(
        std::make_shared< std::wstring >(folderToCopy + L"Dest"),
        std::make_shared< std::wstring >(folderToCopy + L"Src"),
        nullptr,
        nullptr
    ));

getApi()->copyFolder(request);
}

/// <summary>
/// Test for move folder.
/// </summary>
TEST_F(FolderTests, TestMoveFolder) {
    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/TestMoveFolderSrc/TestMoveFolderSrc.docx"
    );

    std::shared_ptr<requests::MoveFolderRequest> request(new requests::MoveFolderRequest(
        std::make_shared< std::wstring >(baseTestOutPath + L"/TestMoveFolderDest_" + createRandomGuid()),
        std::make_shared< std::wstring >(remoteDataFolder + L"/TestMoveFolderSrc"),
        nullptr,
        nullptr
    ));

getApi()->moveFolder(request);
}
