/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="mailMergeFiledsTests.cpp">
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
/// Example of how to work with merge fields.
/// </summary>
class MailMergeFiledsTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentActions/MailMerge");
    utility::string_t mailMergeFolder = STCONVERT("DocumentActions/MailMerge");

};

/// <summary>
/// Test for putting new fields.
/// </summary>
TEST_F(MailMergeFiledsTests, TestGetDocumentFieldNamesOnline) {
    utility::string_t localDocumentFile = STCONVERT("SampleExecuteTemplate.docx");

    std::shared_ptr< GetDocumentFieldNamesOnlineRequest > request(new GetDocumentFieldNamesOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, mailMergeFolder + STCONVERT("/") + localDocumentFile)),
        true
    ));

   auto actual = get_api()->getDocumentFieldNamesOnline(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting mailmerge fields.
/// </summary>
TEST_F(MailMergeFiledsTests, TestGetDocumentFieldNames) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentFieldNames.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, STCONVERT("Common/test_multi_pages.docx"))
    );

    std::shared_ptr< GetDocumentFieldNamesRequest > request(new GetDocumentFieldNamesRequest(
        remoteFileName,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getDocumentFieldNames(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}
