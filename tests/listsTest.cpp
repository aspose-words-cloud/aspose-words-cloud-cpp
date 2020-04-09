/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="listsTest.cpp">
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
/// Example of how to work with font
/// </summary>
class ListsTest : public InfrastructureTest {
protected:
	const utility::string_t testPath = STCONVERT("Lists");
	const utility::string_t localName = STCONVERT("ListsGet.doc");
};

/// <summary>
/// Test for GetLists
/// </summary>
TEST_F(ListsTest, TestGetLists) {
	utility::string_t
		remoteName = STCONVERT("TestGetLists.doc"),
		remoteFolder = path_combine_url(remoteBaseTestDataFolder, testPath),
		fullName = path_combine_url(remoteFolder, remoteName),
		filePath = path_combine(get_data_dir(testPath), localName);

	UploadFileToStorage(fullName, filePath);

	auto request = std::make_shared<GetListsRequest>(remoteName, remoteFolder, boost::none, boost::none, boost::none);
	AsposeResponse<ListsResponse> actual = get_api()->getLists(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
	ASSERT_EQ(2, actual.body->getLists()->getListCollection().size());
}

/// <summary>
/// Test for GetList
/// </summary>
TEST_F(ListsTest, TestGetList) {
	utility::string_t
		remoteName = STCONVERT("TestGetList.doc"),
		remoteFolder = path_combine_url(remoteBaseTestDataFolder, testPath),
		fullName = path_combine_url(remoteFolder, remoteName),
		filePath = path_combine(get_data_dir(testPath), localName);

	UploadFileToStorage(fullName, filePath);

	auto request = std::make_shared<GetListRequest>(remoteName, 1, remoteFolder, boost::none, boost::none, boost::none);
	AsposeResponse<ListResponse> actual = get_api()->getList(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for UpdateList
/// </summary>
TEST_F(ListsTest, TestUpdateList) {
	utility::string_t
		remoteName = STCONVERT("TestUpdateList.doc"),
		remoteFolder = path_combine_url(remoteBaseTestDataFolder, testPath),
		fullName = path_combine_url(remoteFolder, remoteName),
		filePath = path_combine(get_data_dir(testPath), localName);

	UploadFileToStorage(fullName, filePath);

	auto listUpdate = std::make_shared<ListUpdate>();
	listUpdate->setIsRestartAtEachSection(true);

	auto request = std::make_shared<UpdateListRequest>(remoteName, listUpdate, 1, remoteFolder, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
	AsposeResponse<ListResponse> actual = get_api()->updateList(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for UpdateListLevel
/// </summary>
TEST_F(ListsTest, TestUpdateListLevel) {
	utility::string_t
		remoteName = STCONVERT("TestUpdateListLevel.doc"),
		remoteFolder = path_combine_url(remoteBaseTestDataFolder, testPath),
		fullName = path_combine_url(remoteFolder, remoteName),
		filePath = path_combine(get_data_dir(testPath), localName);

	UploadFileToStorage(fullName, filePath);

	auto listUpdate = std::make_shared<ListLevelUpdate>();
	listUpdate->setAlignment(STCONVERT("Right"));

	auto request = std::make_shared<UpdateListLevelRequest>(remoteName, listUpdate, 1, 1, remoteFolder, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
	AsposeResponse<ListResponse> actual = get_api()->updateListLevel(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for InsertList
/// </summary>
TEST_F(ListsTest, TestInsertList) {
	utility::string_t
		remoteName = STCONVERT("TestInsertList.doc"),
		remoteFolder = path_combine_url(remoteBaseTestDataFolder, testPath),
		fullName = path_combine_url(remoteFolder, remoteName),
		filePath = path_combine(get_data_dir(testPath), localName);

	UploadFileToStorage(fullName, filePath);

	auto listInsert = std::make_shared<ListInsert>();
	listInsert->setTemplate(STCONVERT("OutlineLegal"));

	auto request = std::make_shared<InsertListRequest>(remoteName, listInsert, remoteFolder, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
	AsposeResponse<ListResponse> actual = get_api()->insertList(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}