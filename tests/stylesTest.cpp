/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="stylesTest.cpp">
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
class StylesTest : public InfrastructureTest {
protected:
	const utility::string_t testPath = STCONVERT("DocumentElements/Styles");
	const utility::string_t localName = STCONVERT("GetStyles.docx");
};

/// <summary>
/// Test for GetStyles
/// </summary>
TEST_F(StylesTest, TestGetStyles) {
	utility::string_t
		remoteName = STCONVERT("TestGetStyles.docx"),
		remoteFolder = path_combine_url(remoteBaseTestDataFolder, testPath),
		fullName = path_combine_url(remoteFolder, remoteName),
		filePath = path_combine(get_data_dir(testPath), localName);

	UploadFileToStorage(fullName, filePath);

	auto request = std::make_shared<GetStylesRequest>(remoteName, remoteFolder, boost::none, boost::none, boost::none);
	AsposeResponse<StylesResponse> actual = get_api()->getStyles(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for GetStyle
/// </summary>
TEST_F(StylesTest, TestGetStyle) {
	utility::string_t
		remoteName = STCONVERT("TestGetStyle.docx"),
		remoteFolder = path_combine_url(remoteBaseTestDataFolder, testPath),
		fullName = path_combine_url(remoteFolder, remoteName),
		filePath = path_combine(get_data_dir(testPath), localName);

	UploadFileToStorage(fullName, filePath);

	auto request = std::make_shared<GetStyleRequest>(remoteName, STCONVERT("Heading 1"), remoteFolder, boost::none, boost::none, boost::none);
	AsposeResponse<StyleResponse> actual = get_api()->getStyle(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for UpdateStyle
/// </summary>
TEST_F(StylesTest, TestUpdateStyle) {
	utility::string_t
		remoteName = STCONVERT("TestUpdateStyle.docx"),
		remoteFolder = path_combine_url(remoteBaseTestDataFolder, testPath),
		fullName = path_combine_url(remoteFolder, remoteName),
		filePath = path_combine(get_data_dir(testPath), localName);

	UploadFileToStorage(fullName, filePath);

	auto styleUpdate = std::make_shared<StyleUpdate>();
	styleUpdate->setName(STCONVERT("My Style"));

	auto request = std::make_shared<UpdateStyleRequest>(remoteName, styleUpdate, STCONVERT("Heading 1"), remoteFolder, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
	AsposeResponse<StyleResponse> actual = get_api()->updateStyle(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for InsertStyle
/// </summary>
TEST_F(StylesTest, TestInsertStyle) {
	utility::string_t
		remoteName = STCONVERT("TestInsertStyle.docx"),
		remoteFolder = path_combine_url(remoteBaseTestDataFolder, testPath),
		fullName = path_combine_url(remoteFolder, remoteName),
		filePath = path_combine(get_data_dir(testPath), localName);

	UploadFileToStorage(fullName, filePath);

	auto styleInsert = std::make_shared<StyleInsert>();
	styleInsert->setStyleName(STCONVERT("My Style"));
	styleInsert->setStyleType(STCONVERT("Paragraph"));

	auto request = std::make_shared<InsertStyleRequest>(remoteName, styleInsert, remoteFolder, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
	AsposeResponse<StyleResponse> actual = get_api()->insertStyle(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for CopyStyle
/// </summary>
TEST_F(StylesTest, TestCopyStyle) {
	utility::string_t
		remoteName = STCONVERT("TestCopyStyle.docx"),
		remoteFolder = path_combine_url(remoteBaseTestDataFolder, testPath),
		fullName = path_combine_url(remoteFolder, remoteName),
		filePath = path_combine(get_data_dir(testPath), localName);

	UploadFileToStorage(fullName, filePath);

	auto styleInsert = std::make_shared<StyleCopy>();
	styleInsert->setStyleName(STCONVERT("Heading 1"));

	auto request = std::make_shared<CopyStyleRequest>(remoteName, styleInsert, remoteFolder, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
	AsposeResponse<StyleResponse> actual = get_api()->copyStyle(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}