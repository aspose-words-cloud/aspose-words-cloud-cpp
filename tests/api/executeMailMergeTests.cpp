/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="executeMailMergeTests.cpp">
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
/// Example of how to perform mail merge.
/// </summary>
class ExecuteMailMergeTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentActions/MailMerge");
    utility::string_t mailMergeFolder = STCONVERT("DocumentActions/MailMerge");

};

/// <summary>
/// Test for executing mail merge online.
/// </summary>
TEST_F(ExecuteMailMergeTests, TestExecuteMailMergeOnline) {
    utility::string_t localDocumentFile = STCONVERT("SampleExecuteTemplate.docx");
    utility::string_t localDataFile = STCONVERT("SampleExecuteTemplateData.txt");

    std::shared_ptr< ExecuteMailMergeOnlineRequest > request(new ExecuteMailMergeOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, mailMergeFolder + STCONVERT("/") + localDocumentFile)),
        generate_http_content_from_file(path_combine(LocalTestDataFolder, mailMergeFolder + STCONVERT("/") + localDataFile)),
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->executeMailMergeOnline(request).get();
}

/// <summary>
/// Test for executing mail merge.
/// </summary>
TEST_F(ExecuteMailMergeTests, TestExecuteMailMerge) {
    utility::string_t localDocumentFile = STCONVERT("SampleExecuteTemplate.docx");
    utility::string_t remoteFileName = STCONVERT("TestExecuteMailMerge.docx");
    utility::string_t localDataFile = get_file_text(path_combine(LocalTestDataFolder, mailMergeFolder + STCONVERT("/SampleMailMergeTemplateData.txt")));

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, mailMergeFolder + STCONVERT("/") + localDocumentFile)
    );

    std::shared_ptr< ExecuteMailMergeRequest > request(new ExecuteMailMergeRequest(
        remoteFileName,
        localDataFile,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        false,
        boost::none,
        boost::none,
        boost::none,
        baseTestOutPath + STCONVERT("/") + remoteFileName
    ));

   auto actual = get_api()->executeMailMerge(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getDocument()));
   ASSERT_EQ(STCONVERT("TestExecuteMailMerge.docx"), actual.body->getDocument()->getFileName());
}
