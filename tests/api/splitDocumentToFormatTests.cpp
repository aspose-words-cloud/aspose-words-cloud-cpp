/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="splitDocumentToFormatTests.cpp">
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
/// Example of how to split document and return result with specified format and page range.
/// </summary>
class SplitDocumentToFormatTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentActions/SplitDocument");
    utility::string_t localFile = STCONVERT("Common/test_multi_pages.docx");

};

/// <summary>
/// Test for document splitting.
/// </summary>
TEST_F(SplitDocumentToFormatTests, TestSplitDocument) {
    utility::string_t remoteFileName = STCONVERT("TestSplitDocument.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< SplitDocumentRequest > request(new SplitDocumentRequest(
        remoteFileName,
        STCONVERT("text"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        baseTestOutPath + STCONVERT("/TestSplitDocument.text"),
        1,
        2,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->splitDocument(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}
