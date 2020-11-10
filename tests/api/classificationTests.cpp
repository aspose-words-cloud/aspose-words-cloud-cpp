/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="classificationTests.cpp">
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
/// Example of how to classify text.
/// </summary>
class ClassificationTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/Common");
    utility::string_t localFile = STCONVERT("Common/test_multi_pages.docx");

};

/// <summary>
/// Test for raw text classification.
/// </summary>
TEST_F(ClassificationTests, TestClassify) {
    std::shared_ptr< ClassifyRequest > request(new ClassifyRequest(
        STCONVERT("Try text classification"),
        STCONVERT("3")
    ));

   auto actual = get_api()->classify(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_EQ(STCONVERT("Science"), actual.body->getBestClassName());
   ASSERT_TRUE(actual.body->getBestResults());
   ASSERT_EQ(3, actual.body->getBestResults().size());
}

/// <summary>
/// Test for document classification.
/// </summary>
TEST_F(ClassificationTests, TestClassifyDocument) {
    utility::string_t remoteFileName = STCONVERT("TestClassifyDocument.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< ClassifyDocumentRequest > request(new ClassifyDocumentRequest(
        remoteFileName,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        STCONVERT("3"),
        boost::none
    ));

   auto actual = get_api()->classifyDocument(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_EQ(STCONVERT("Hobbies_&_Interests"), actual.body->getBestClassName());
   ASSERT_TRUE(actual.body->getBestResults());
   ASSERT_EQ(3, actual.body->getBestResults().size());
}
