/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="rangeTests.cpp">
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
/// Example of how to work with ranges.
/// </summary>
class RangeTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentElements/Range");
    utility::string_t localFile = STCONVERT("DocumentElements/Range/RangeGet.doc");

};

/// <summary>
/// Test for getting the text from range.
/// </summary>
TEST_F(RangeTests, TestGetRangeText) {
    utility::string_t remoteFileName = STCONVERT("TestGetRangeText.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetRangeTextRequest > request(new GetRangeTextRequest(
        remoteFileName,
        STCONVERT("id0.0.0"),
        STCONVERT("id0.0.1"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getRangeText(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_EQ(STCONVERT("This is HEADER "), actual.body->getText());
}

/// <summary>
/// Test for removing the text for range.
/// </summary>
TEST_F(RangeTests, TestRemoveRange) {
    utility::string_t remoteFileName = STCONVERT("TestRemoveRange.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< RemoveRangeRequest > request(new RemoveRangeRequest(
        remoteFileName,
        STCONVERT("id0.0.0"),
        STCONVERT("id0.0.1"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->removeRange(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getDocument()));
   ASSERT_EQ(STCONVERT("TestRemoveRange.docx"), actual.body->getDocument()->getFileName());
}

/// <summary>
/// Test for saving a range as a new document.
/// </summary>
TEST_F(RangeTests, TestSaveAsRange) {
    utility::string_t remoteFileName = STCONVERT("TestSaveAsRange.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestDocumentParameters = std::make_shared< RangeDocument >();
    requestDocumentParameters->setDocumentName(remoteDataFolder + STCONVERT("/NewDoc.docx"));

    std::shared_ptr< SaveAsRangeRequest > request(new SaveAsRangeRequest(
        remoteFileName,
        STCONVERT("id0.0.0"),
        requestDocumentParameters,
        STCONVERT("id0.0.1"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->saveAsRange(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getDocument()));
   ASSERT_EQ(STCONVERT("NewDoc.docx"), actual.body->getDocument()->getFileName());
}

/// <summary>
/// Test for replacing text in range.
/// </summary>
TEST_F(RangeTests, TestReplaceWithText) {
    utility::string_t remoteFileName = STCONVERT("TestReplaceWithText.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestRangeText = std::make_shared< ReplaceRange >();
    requestRangeText->setText(STCONVERT("Replaced header"));

    std::shared_ptr< ReplaceWithTextRequest > request(new ReplaceWithTextRequest(
        remoteFileName,
        STCONVERT("id0.0.0"),
        requestRangeText,
        STCONVERT("id0.0.1"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->replaceWithText(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getDocument()));
   ASSERT_EQ(STCONVERT("TestReplaceWithText.docx"), actual.body->getDocument()->getFileName());
}
