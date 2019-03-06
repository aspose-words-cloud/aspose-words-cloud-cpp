/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="pageSetupTest.cpp">
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
/// Example of how to work with page settings
/// </summary>
class PageSetupTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements\\PageSetup")),
		textFolder = STCONVERT("DocumentElements/Text");
};

/// <summary>
/// Test for getting page settings
/// </summary>
TEST_F(PageSetupTest, TestGetSectionPageSetup) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetSectionPageSetup.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetSectionPageSetupRequest> request=
			std::make_shared<GetSectionPageSetupRequest>(remoteName, index, dataFolder, boost::none,
		boost::none, boost::none);

	std::shared_ptr<SectionPageSetupResponse> actual = get_api()->getSectionPageSetup(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for updating page settings
/// </summary>
TEST_F(PageSetupTest, TestUpdateSectionPageSetup) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestUpdateSectionPageSetup.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	int32_t index = 0;

	std::shared_ptr<PageSetup> body= std::make_shared<PageSetup>();
	body->setRtlGutter(true);
	body->setLeftMargin(10.0);
	body->setOrientation(STCONVERT("Landscape"));
	body->setPaperSize(STCONVERT("A5"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<UpdateSectionPageSetupRequest> request=
			std::make_shared<UpdateSectionPageSetupRequest>(remoteName, index, body, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none);

	std::shared_ptr<SectionPageSetupResponse> actual = get_api()->updateSectionPageSetup(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for page rendering
/// </summary>
TEST_F(PageSetupTest, TestGetRenderPage) {
	utility::string_t
		localName = STCONVERT("SampleWordDocument.docx"),
		remoteName = STCONVERT("TestGetRenderPage.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(textFolder), localName),
		format = STCONVERT("bmp");

	int32_t pageNumber = 1;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<RenderPageRequest> request=
			std::make_shared<RenderPageRequest>(remoteName, pageNumber, format, dataFolder, boost::none,
		boost::none, boost::none, boost::none);

	HttpContent result = get_api()->renderPage(request).get();

	ASSERT_TRUE(result.getData()->peek());
}