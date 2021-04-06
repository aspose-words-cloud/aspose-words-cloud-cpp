/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="lists_test.h">
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

#pragma once
#include "../test_base.h"

/// <summary>
/// Example of how to work with lists.
/// </summary>
class ListsTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentElements/Lists";
    std::wstring localFile = L"DocumentElements/Lists/ListsGet.doc";

};

/// <summary>
/// Test for getting lists from document.
/// </summary>
TEST_F(ListsTests, TestGetLists) {
    std::wstring remoteFileName = L"TestGetLists.doc";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetListsRequest> request(new requests::GetListsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getLists(request);
    ASSERT_TRUE(actual->getLists() != nullptr);
    ASSERT_TRUE(actual->getLists()->getListInfo() != nullptr);
    ASSERT_EQ(2, actual->getLists()->getListInfo()->size());
    ASSERT_EQ(1, *(actual->getLists()->getListInfo()->at(0)->getListId()));
}

/// <summary>
/// Test for getting lists from document online.
/// </summary>
TEST_F(ListsTests, TestGetListsOnline) {
    auto documentStream = std::shared_ptr<std::istream>(new std::ifstream(getDataDir(localFile), std::istream::binary));
    std::shared_ptr<requests::GetListsOnlineRequest> request(new requests::GetListsOnlineRequest(
        documentStream,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getListsOnline(request);
}

/// <summary>
/// Test for getting list from document.
/// </summary>
TEST_F(ListsTests, TestGetList) {
    std::wstring remoteFileName = L"TestGetList.doc";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetListRequest> request(new requests::GetListRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(1),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getList(request);
    ASSERT_TRUE(actual->getList() != nullptr);
    ASSERT_EQ(1, *(actual->getList()->getListId()));
}

/// <summary>
/// Test for getting list from document online.
/// </summary>
TEST_F(ListsTests, TestGetListOnline) {
    auto documentStream = std::shared_ptr<std::istream>(new std::ifstream(getDataDir(localFile), std::istream::binary));
    std::shared_ptr<requests::GetListOnlineRequest> request(new requests::GetListOnlineRequest(
        documentStream,
        std::make_shared< int32_t >(1),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getListOnline(request);
}

/// <summary>
/// Test for updating list from document.
/// </summary>
TEST_F(ListsTests, TestUpdateList) {
    std::wstring remoteFileName = L"TestUpdateList.doc";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestListUpdate = std::make_shared< aspose::words::cloud::models::ListUpdate >();
    requestListUpdate->setIsRestartAtEachSection(std::make_shared< bool >(true));

    std::shared_ptr<requests::UpdateListRequest> request(new requests::UpdateListRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(1),
        requestListUpdate,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateList(request);
}

/// <summary>
/// Test for updating list from document online.
/// </summary>
TEST_F(ListsTests, TestUpdateListOnline) {
    auto documentStream = std::shared_ptr<std::istream>(new std::ifstream(getDataDir(localFile), std::istream::binary));
    auto requestListUpdate = std::make_shared< aspose::words::cloud::models::ListUpdate >();
    requestListUpdate->setIsRestartAtEachSection(std::make_shared< bool >(true));

    std::shared_ptr<requests::UpdateListOnlineRequest> request(new requests::UpdateListOnlineRequest(
        documentStream,
        std::make_shared< int32_t >(1),
        requestListUpdate,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateListOnline(request);
    ASSERT_TRUE(actual->getModel()->getList() != nullptr);
    ASSERT_EQ(1, *(actual->getModel()->getList()->getListId()));
    ASSERT_TRUE(*(actual->getModel()->getList()->getIsRestartAtEachSection()));
}

/// <summary>
/// Test for updating list level from document.
/// </summary>
TEST_F(ListsTests, TestUpdateListLevel) {
    std::wstring remoteFileName = L"TestUpdateListLevel.doc";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestListUpdate = std::make_shared< aspose::words::cloud::models::ListLevelUpdate >();
    requestListUpdate->setAlignment(std::make_shared< aspose::words::cloud::models::ListLevelUpdate::Alignment >(aspose::words::cloud::models::ListLevelUpdate::Alignment::RIGHT));

    std::shared_ptr<requests::UpdateListLevelRequest> request(new requests::UpdateListLevelRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(1),
        std::make_shared< int32_t >(1),
        requestListUpdate,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateListLevel(request);
}

/// <summary>
/// Test for updating list level from document online.
/// </summary>
TEST_F(ListsTests, TestUpdateListLevelOnline) {
    auto documentStream = std::shared_ptr<std::istream>(new std::ifstream(getDataDir(localFile), std::istream::binary));
    auto requestListUpdate = std::make_shared< aspose::words::cloud::models::ListLevelUpdate >();
    requestListUpdate->setAlignment(std::make_shared< aspose::words::cloud::models::ListLevelUpdate::Alignment >(aspose::words::cloud::models::ListLevelUpdate::Alignment::RIGHT));

    std::shared_ptr<requests::UpdateListLevelOnlineRequest> request(new requests::UpdateListLevelOnlineRequest(
        documentStream,
        std::make_shared< int32_t >(1),
        requestListUpdate,
        std::make_shared< int32_t >(1),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateListLevelOnline(request);
    ASSERT_TRUE(actual->getModel()->getList() != nullptr);
    ASSERT_TRUE(actual->getModel()->getList()->getListLevels() != nullptr);
    ASSERT_TRUE(actual->getModel()->getList()->getListLevels()->getListLevel() != nullptr);
    ASSERT_EQ(9, actual->getModel()->getList()->getListLevels()->getListLevel()->size());

}

/// <summary>
/// Test for inserting list from document.
/// </summary>
TEST_F(ListsTests, TestInsertList) {
    std::wstring remoteFileName = L"TestInsertList.doc";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestListInsert = std::make_shared< aspose::words::cloud::models::ListInsert >();
    requestListInsert->setTemplate(std::make_shared< aspose::words::cloud::models::ListInsert::Template >(aspose::words::cloud::models::ListInsert::Template::OUTLINE_LEGAL));

    std::shared_ptr<requests::InsertListRequest> request(new requests::InsertListRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestListInsert,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertList(request);
    ASSERT_TRUE(actual->getList() != nullptr);
    ASSERT_EQ(3, *(actual->getList()->getListId()));
}

/// <summary>
/// Test for inserting list from document online.
/// </summary>
TEST_F(ListsTests, TestInsertListOnline) {
    auto documentStream = std::shared_ptr<std::istream>(new std::ifstream(getDataDir(localFile), std::istream::binary));
    auto requestListInsert = std::make_shared< aspose::words::cloud::models::ListInsert >();
    requestListInsert->setTemplate(std::make_shared< aspose::words::cloud::models::ListInsert::Template >(aspose::words::cloud::models::ListInsert::Template::OUTLINE_LEGAL));

    std::shared_ptr<requests::InsertListOnlineRequest> request(new requests::InsertListOnlineRequest(
        documentStream,
        requestListInsert,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertListOnline(request);
}
