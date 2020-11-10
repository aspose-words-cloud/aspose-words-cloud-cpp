/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="headerFooterTests.cpp">
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
/// Example of how to work with headers and footers.
/// </summary>
class HeaderFooterTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentElements/HeaderFooters");
    utility::string_t localFile = STCONVERT("DocumentElements/HeaderFooters/HeadersFooters.doc");

};

/// <summary>
/// Test for getting headers and footers.
/// </summary>
TEST_F(HeaderFooterTests, TestGetHeaderFooters) {
    utility::string_t remoteFileName = STCONVERT("TestGetHeadersFooters.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetHeaderFootersRequest > request(new GetHeaderFootersRequest(
        remoteFileName,
        STCONVERT(""),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getHeaderFooters(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(actual.body->getHeaderFooters());
   ASSERT_TRUE(actual.body->getHeaderFooters()->getList());
   ASSERT_EQ(6, actual.body->getHeaderFooters()->getList().size());
}

/// <summary>
/// Test for getting headerfooter.
/// </summary>
TEST_F(HeaderFooterTests, TestGetHeaderFooter) {
    utility::string_t remoteFileName = STCONVERT("TestGetHeaderFooter.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetHeaderFooterRequest > request(new GetHeaderFooterRequest(
        remoteFileName,
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getHeaderFooter(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(actual.body->getHeaderFooter());
   ASSERT_TRUE(actual.body->getHeaderFooter()->getChildNodes());
   ASSERT_EQ(1, actual.body->getHeaderFooter()->getChildNodes().size());
   ASSERT_EQ(STCONVERT("0.0.0"), actual.body->getHeaderFooter()->getChildNodes()[0]->getNodeId());
}

/// <summary>
/// Test for getting headerfooter of section.
/// </summary>
TEST_F(HeaderFooterTests, TestGetHeaderFooterOfSection) {
    utility::string_t remoteFileName = STCONVERT("TestGetHeaderFooterOfSection.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetHeaderFooterOfSectionRequest > request(new GetHeaderFooterOfSectionRequest(
        remoteFileName,
        0,
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getHeaderFooterOfSection(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(actual.body->getHeaderFooter());
   ASSERT_TRUE(actual.body->getHeaderFooter()->getChildNodes());
   ASSERT_EQ(1, actual.body->getHeaderFooter()->getChildNodes().size());
   ASSERT_EQ(STCONVERT("0.0.0"), actual.body->getHeaderFooter()->getChildNodes()[0]->getNodeId());
}

/// <summary>
/// Test for deleting headerfooter.
/// </summary>
TEST_F(HeaderFooterTests, TestDeleteHeaderFooter) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteHeaderFooter.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< DeleteHeaderFooterRequest > request(new DeleteHeaderFooterRequest(
        remoteFileName,
        STCONVERT(""),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->deleteHeaderFooter(request).get();
}

/// <summary>
/// Test for deleting headerfooters.
/// </summary>
TEST_F(HeaderFooterTests, TestDeleteHeadersFooters) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteHeadersFooters.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< DeleteHeadersFootersRequest > request(new DeleteHeadersFootersRequest(
        remoteFileName,
        STCONVERT(""),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->deleteHeadersFooters(request).get();
}

/// <summary>
/// Test for adding headerfooters.
/// </summary>
TEST_F(HeaderFooterTests, TestInsertHeaderFooter) {
    utility::string_t remoteFileName = STCONVERT("TestInsertHeaderFooter.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< InsertHeaderFooterRequest > request(new InsertHeaderFooterRequest(
        remoteFileName,
        STCONVERT("FooterEven"),
        STCONVERT(""),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->insertHeaderFooter(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(actual.body->getHeaderFooter());
   ASSERT_TRUE(actual.body->getHeaderFooter()->getChildNodes());
   ASSERT_EQ(1, actual.body->getHeaderFooter()->getChildNodes().size());
   ASSERT_EQ(STCONVERT("0.2.0"), actual.body->getHeaderFooter()->getChildNodes()[0]->getNodeId());
}
