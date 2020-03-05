/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="loadWebDocumentTest.cpp">
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
/// Example of how to load web document
/// </summary>
class LoadWebDocumentTest : public InfrastructureTest {
protected:
	const utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentActions\\DocumentWithFormat"));
};

/// <summary>
/// Test for loading web document
/// </summary>
TEST_F(LoadWebDocumentTest, TestPostLoadWebDocument) {
	std::shared_ptr<LoadWebDocumentData> body = std::make_shared<LoadWebDocumentData>();
	std::shared_ptr<SaveOptionsData> saveOptions = std::make_shared<SaveOptionsData>();
	saveOptions->setFileName(STCONVERT("google.doc"));
	saveOptions->setSaveFormat(STCONVERT("doc"));	
	saveOptions->setDmlEffectsRenderingMode(STCONVERT("1"));
	saveOptions->setDmlRenderingMode(STCONVERT("1"));
	saveOptions->setUpdateSdtContent(false);
	saveOptions->setZipOutput(false);

	body->setLoadingDocumentUrl(STCONVERT("http://google.com"));
	body->setSaveOptions(saveOptions);

	std::shared_ptr<LoadWebDocumentRequest> request=
			std::make_shared<LoadWebDocumentRequest>(body, boost::none);
	AsposeResponse<SaveResponse> actual = get_api()->loadWebDocument(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

