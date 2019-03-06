/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="headersFooterTest.cpp">
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
/// Example of how to work with headers and footers
/// </summary>
class HeadersFooterTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements\\Footnotes")),
		headerFooterFolder = STCONVERT("DocumentElements/HeaderFooters");
};

/// <summary>
/// Test for getting headers and footers
/// </summary>
TEST_F(HeadersFooterTest, TestGetHeadersFooters) {
	utility::string_t
		localName = STCONVERT("HeadersFooters.doc"),
		remoteName = STCONVERT("TestGetHeadersFooters.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(headerFooterFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetHeaderFootersRequest> request=
			std::make_shared<GetHeaderFootersRequest>(remoteName, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none);

	std::shared_ptr<HeaderFootersResponse> actual = get_api()->getHeaderFooters(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for getting headerfooter
/// </summary>
TEST_F(HeadersFooterTest, TestGetHeaderFooter) {
	utility::string_t
		localName = STCONVERT("HeadersFooters.doc"),
		remoteName = STCONVERT("TestGetHeaderFooter.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(headerFooterFolder), localName);

	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetHeaderFooterRequest> request=
			std::make_shared<GetHeaderFooterRequest>(remoteName, index, dataFolder, boost::none,
		boost::none, boost::none, boost::none);

	std::shared_ptr<HeaderFooterResponse> actual = get_api()->getHeaderFooter(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for getting headerfooter of section
/// </summary>
TEST_F(HeadersFooterTest, TestGetHeaderFooterOfSection) {
	utility::string_t
		localName = STCONVERT("HeadersFooters.doc"),
		remoteName = STCONVERT("TestGetHeaderFooterOfSection.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(headerFooterFolder), localName);

	int32_t index = 0,
		sectionIndex = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetHeaderFooterOfSectionRequest> request=
			std::make_shared<GetHeaderFooterOfSectionRequest>(remoteName, index, sectionIndex, dataFolder,
					boost::none, boost::none, boost::none, boost::none);

	std::shared_ptr<HeaderFooterResponse> actual = get_api()->getHeaderFooterOfSection(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for deleting headerfooter
/// </summary>
TEST_F(HeadersFooterTest, TestDeleteHeaderFooter) {
	utility::string_t
		localName = STCONVERT("HeadersFooters.doc"),
		remoteName = STCONVERT("TestDeleteHeaderFooter.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(headerFooterFolder), localName);

	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteHeaderFooterRequest> request=
			std::make_shared<DeleteHeaderFooterRequest>(remoteName, index, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);

	std::shared_ptr<AsposeResponse> actual = get_api()->deleteHeaderFooter(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for deleting headerfooters
/// </summary>
TEST_F(HeadersFooterTest, TestDeleteHeaderFooters) {
	utility::string_t
		localName = STCONVERT("HeadersFooters.doc"),
		remoteName = STCONVERT("TestDeleteHeaderFooters.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(headerFooterFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteHeadersFootersRequest> request=
			std::make_shared<DeleteHeadersFootersRequest>(remoteName, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);

	std::shared_ptr<AsposeResponse> actual = get_api()->deleteHeadersFooters(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for adding headerfooters
/// </summary>
TEST_F(HeadersFooterTest, TestPutHeaderFooter) {
	utility::string_t
		localName = STCONVERT("HeadersFooters.doc"),
		remoteName = STCONVERT("TestPutHeaderFooter.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(headerFooterFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PutHeaderFooterRequest> request=
			std::make_shared<PutHeaderFooterRequest>(remoteName, STCONVERT("FooterEven"), dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);

	std::shared_ptr<AsposeResponse> actual = get_api()->putHeaderFooter(request).get();

	ASSERT_EQ(200, actual->getCode());
}