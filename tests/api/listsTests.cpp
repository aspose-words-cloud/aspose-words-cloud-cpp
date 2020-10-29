/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="listsTests.cpp">
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
/// Example of how to work with lists.
/// </summary>
class ListsTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentElements/Lists");
    utility::string_t localFile = STCONVERT("DocumentElements/Lists/ListsGet.doc");

};

/// <summary>
/// Test for getting lists from document.
/// </summary>
TEST_F(ListsTests, TestGetLists) {
    utility::string_t remoteFileName = STCONVERT("TestGetLists.doc");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetListsRequest > request(new GetListsRequest(
        remoteFileName,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getLists(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_EQ(true, actual.body->getLists() != nullptr);
   ASSERT_EQ(true, actual.body->getLists()->getListInfo() != nullptr);
   ASSERT_EQ(2, actual.body->getLists()->getListInfo().size());
   ASSERT_EQ(1, actual.body->getLists()->getListInfo()[0]->getListId());
}

/// <summary>
/// Test for getting list from document.
/// </summary>
TEST_F(ListsTests, TestGetList) {
    utility::string_t remoteFileName = STCONVERT("TestGetList.doc");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetListRequest > request(new GetListRequest(
        remoteFileName,
        1,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getList(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_EQ(true, actual.body->getList() != nullptr);
   ASSERT_EQ(1, actual.body->getList()->getListId());
}

/// <summary>
/// Test for updating list from document.
/// </summary>
TEST_F(ListsTests, TestUpdateList) {
    utility::string_t remoteFileName = STCONVERT("TestUpdateList.doc");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestListUpdate = std::make_shared< ListUpdate >();
    requestListUpdate->setIsRestartAtEachSection(true);

    std::shared_ptr< UpdateListRequest > request(new UpdateListRequest(
        remoteFileName,
        requestListUpdate,
        1,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->updateList(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_EQ(true, actual.body->getList() != nullptr);
   ASSERT_EQ(1, actual.body->getList()->getListId());
   ASSERT_EQ(true, actual.body->getList()->getIsRestartAtEachSection());
}

/// <summary>
/// Test for updating list level from document.
/// </summary>
TEST_F(ListsTests, TestUpdateListLevel) {
    utility::string_t remoteFileName = STCONVERT("TestUpdateListLevel.doc");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestListUpdate = std::make_shared< ListLevelUpdate >();
    requestListUpdate->setAlignment(STCONVERT("Right"));

    std::shared_ptr< UpdateListLevelRequest > request(new UpdateListLevelRequest(
        remoteFileName,
        requestListUpdate,
        1,
        1,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->updateListLevel(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_EQ(true, actual.body->getList() != nullptr);
   ASSERT_EQ(true, actual.body->getList()->getListLevels() != nullptr);
   ASSERT_EQ(true, actual.body->getList()->getListLevels()->getListLevel() != nullptr);
   ASSERT_EQ(9, actual.body->getList()->getListLevels()->getListLevel().size());

}

/// <summary>
/// Test for inserting list from document.
/// </summary>
TEST_F(ListsTests, TestInsertList) {
    utility::string_t remoteFileName = STCONVERT("TestInsertList.doc");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestListInsert = std::make_shared< ListInsert >();
    requestListInsert->setTemplate(STCONVERT("OutlineLegal"));

    std::shared_ptr< InsertListRequest > request(new InsertListRequest(
        remoteFileName,
        requestListInsert,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->insertList(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_EQ(true, actual.body->getList() != nullptr);
   ASSERT_EQ(3, actual.body->getList()->getListId());
}
