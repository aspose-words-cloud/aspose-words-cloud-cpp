/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="sectionTest.cpp">
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
/// Example of how to work with sections
/// </summary>
class SectionTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements\\Section"));
};

/// <summary>
/// Test for getting section by index
/// </summary>
TEST_F(SectionTest, TestGetSection) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetSection.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);
	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetSectionRequest> request=
	        std::make_shared<GetSectionRequest>(remoteName, index, dataFolder, boost::none,
		boost::none, boost::none);

	std::shared_ptr<SectionResponse> actual = get_api()->getSection(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for getting sections
/// </summary>
TEST_F(SectionTest, TestGetSections) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetSections.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetSectionsRequest> request=
	        std::make_shared<GetSectionsRequest>(remoteName, dataFolder, boost::none,
		boost::none, boost::none);

	std::shared_ptr<SectionLinkCollectionResponse> actual = get_api()->getSections(request).get();

	ASSERT_EQ(200, actual->getCode());
}