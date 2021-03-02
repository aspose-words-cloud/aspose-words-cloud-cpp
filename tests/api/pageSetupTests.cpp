/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="pageSetupTests.cpp">
*   Copyright (c) 2021 Aspose.Words for Cloud
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
class PageSetupTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentElements/PageSetup");
    utility::string_t localFile = STCONVERT("Common/test_multi_pages.docx");
    utility::string_t localTextFile = STCONVERT("DocumentElements/Text/SampleWordDocument.docx");

};

/// <summary>
/// Test for getting page settings.
/// </summary>
TEST_F(PageSetupTests, TestGetSectionPageSetup) {
    utility::string_t remoteFileName = STCONVERT("TestGetSectionPageSetup.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetSectionPageSetupRequest > request(new GetSectionPageSetupRequest(
        remoteFileName,
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getSectionPageSetup(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getPageSetup()));
   ASSERT_EQ(1, actual.body->getPageSetup()->getLineStartingNumber());
}

/// <summary>
/// Test for getting page settings online.
/// </summary>
TEST_F(PageSetupTests, TestGetSectionPageSetupOnline) {
    std::shared_ptr< GetSectionPageSetupOnlineRequest > request(new GetSectionPageSetupOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        0,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getSectionPageSetupOnline(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for updating page settings.
/// </summary>
TEST_F(PageSetupTests, TestUpdateSectionPageSetup) {
    utility::string_t remoteFileName = STCONVERT("TestUpdateSectionPageSetup.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestPageSetup = std::make_shared< PageSetup >();
    requestPageSetup->setRtlGutter(true);
    requestPageSetup->setLeftMargin(10.0);
    requestPageSetup->setOrientation(STCONVERT("Landscape"));
    requestPageSetup->setPaperSize(STCONVERT("A5"));

    std::shared_ptr< UpdateSectionPageSetupRequest > request(new UpdateSectionPageSetupRequest(
        remoteFileName,
        0,
        requestPageSetup,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->updateSectionPageSetup(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getPageSetup()));
   ASSERT_TRUE(actual.body->getPageSetup()->isRtlGutter());


}

/// <summary>
/// Test for updating page settings online.
/// </summary>
TEST_F(PageSetupTests, TestUpdateSectionPageSetupOnline) {
    auto requestPageSetup = std::make_shared< PageSetup >();
    requestPageSetup->setRtlGutter(true);
    requestPageSetup->setLeftMargin(10);
    requestPageSetup->setOrientation(STCONVERT("Landscape"));
    requestPageSetup->setPaperSize(STCONVERT("A5"));

    std::shared_ptr< UpdateSectionPageSetupOnlineRequest > request(new UpdateSectionPageSetupOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        0,
        requestPageSetup,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

auto actual = get_api()->updateSectionPageSetupOnline(request).get();
ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for page rendering.
/// </summary>
TEST_F(PageSetupTests, TestGetRenderPage) {
    utility::string_t remoteFileName = STCONVERT("TestGetRenderPage.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localTextFile)
    );

    std::shared_ptr< RenderPageRequest > request(new RenderPageRequest(
        remoteFileName,
        1,
        STCONVERT("bmp"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->renderPage(request).get();
}

/// <summary>
/// Test for page rendering.
/// </summary>
TEST_F(PageSetupTests, TestGetRenderPageOnline) {
    std::shared_ptr< RenderPageOnlineRequest > request(new RenderPageOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localTextFile)),
        1,
        STCONVERT("bmp"),
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->renderPageOnline(request).get();
}
