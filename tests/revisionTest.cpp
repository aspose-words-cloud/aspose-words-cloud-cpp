/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="revisionTest.cpp">
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
/// Example of how to accept all revisions in document
/// </summary>
class RevisionTest : public InfrastructureTest {
protected:
	const utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentActions\\Revisions"));
};

/// <summary>
/// Test for accepting revisions in document
/// </summary>
TEST_F(RevisionTest, TestAcceptAllRevisions) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestAcceptAllRevisions.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		destFileName = path_combine_url(baseTestOutPath, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<AcceptAllRevisionsRequest> request=
			std::make_shared<AcceptAllRevisionsRequest>(remoteName, dataFolder, boost::none,
		boost::none, boost::none, destFileName);

	AsposeResponse<RevisionsModificationResponse> actual = get_api()->acceptAllRevisions(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for rejecting revisions in document
/// </summary>
TEST_F(RevisionTest, TestRejectAllRevisions) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestRejectAllRevisions.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		destFileName = path_combine_url(baseTestOutPath, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<RejectAllRevisionsRequest> request=
			std::make_shared<RejectAllRevisionsRequest>(remoteName, dataFolder, boost::none,
		boost::none, boost::none, destFileName);

	AsposeResponse<RevisionsModificationResponse> actual = get_api()->rejectAllRevisions(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}
