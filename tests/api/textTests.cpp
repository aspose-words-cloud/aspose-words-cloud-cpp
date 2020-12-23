/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="textTests.cpp">
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
/// Example of how to work with macros.
/// </summary>
class TextTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentElements/Text");

};

/// <summary>
/// Test for replacing text.
/// </summary>
TEST_F(TextTests, TestReplaceText) {
    utility::string_t remoteFileName = STCONVERT("TestReplaceText.docx");
    utility::string_t localFile = STCONVERT("Common/test_multi_pages.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestReplaceText = std::make_shared< ReplaceTextParameters >();
    requestReplaceText->setOldValue(STCONVERT("Testing"));
    requestReplaceText->setNewValue(STCONVERT("Aspose testing"));

    std::shared_ptr< ReplaceTextRequest > request(new ReplaceTextRequest(
        remoteFileName,
        requestReplaceText,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        baseTestOutPath + STCONVERT("/") + remoteFileName,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->replaceText(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_EQ(3, actual.body->getMatches());
}

/// <summary>
/// Test for replacing text online.
/// </summary>
TEST_F(TextTests, TestReplaceTextOnline) {
    utility::string_t localFile = STCONVERT("Common/test_multi_pages.docx");

    auto requestReplaceText = std::make_shared< ReplaceTextParameters >();
    requestReplaceText->setOldValue(STCONVERT("aspose"));
    requestReplaceText->setNewValue(STCONVERT("aspose new"));

    std::shared_ptr< ReplaceTextOnlineRequest > request(new ReplaceTextOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        requestReplaceText,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

auto actual = get_api()->replaceTextOnline(request).get();
ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for searching.
/// </summary>
TEST_F(TextTests, TestSearch) {
    utility::string_t remoteFileName = STCONVERT("TestSearch.docx");
    utility::string_t localFile = STCONVERT("DocumentElements/Text/SampleWordDocument.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< SearchRequest > request(new SearchRequest(
        remoteFileName,
        STCONVERT("aspose"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->search(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getSearchResults()));
   ASSERT_TRUE(IsNotNull(actual.body->getSearchResults()->getResultsList()));
   ASSERT_EQ(23, actual.body->getSearchResults()->getResultsList().size());
   ASSERT_TRUE(IsNotNull(actual.body->getSearchResults()->getResultsList()[0]->getRangeStart()));
   ASSERT_EQ(65, actual.body->getSearchResults()->getResultsList()[0]->getRangeStart()->getOffset());
}

/// <summary>
/// Test for searching online.
/// </summary>
TEST_F(TextTests, TestSearchOnline) {
    utility::string_t localFile = STCONVERT("DocumentElements/Text/SampleWordDocument.docx");

    std::shared_ptr< SearchOnlineRequest > request(new SearchOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        STCONVERT("aspose"),
        boost::none,
        boost::none
    ));

   auto actual = get_api()->searchOnline(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}
