/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="url_encode_test.cpp">
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

#include "test_base.h"

/// <summary>
/// URL encode test
/// </summary>
class UrlEncodeTest : public InfrastructureTest {
protected:
	std::wstring get_data_folder() override {
		return path_combine_url(STCONVERT("Temp/SdkTests/TestData"), STCONVERT("DocumentElements/Bookmarks"));
	}
};

/// <summary>
/// Test for URL encoding of document name
/// </summary>
TEST_F(UrlEncodeTest, TestUrlEncode) {
	std::wstring localName = STCONVERT("test_multi_pages.docx"),
		remoteName = web::uri::encode_uri(STCONVERT("[“Test_Two,_Inc.”]-_83(b)Election([“Bill_Gates”]).docx"), web::uri::components::fragment),
		fullName = path_combine(get_data_folder(), remoteName);
	std::wstring filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);
	std::shared_ptr<GetBookmarksRequest> req =
		std::make_shared<GetBookmarksRequest>(remoteName, get_data_folder(), std::none,
			std::none, std::none);

	auto requestTask = get_api()->getBookmarks(req);

	AsposeResponse<BookmarksResponse> actual = requestTask.get();
	ASSERT_EQ(200, actual.httpResponse->status_code());
}
