/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="stylesTests.cpp">
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
/// Example of how to work with styles.
/// </summary>
class StylesTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentElements/Styles");
    utility::string_t localFile = STCONVERT("DocumentElements/Styles/GetStyles.docx");

};

/// <summary>
/// Test for getting styles from document.
/// </summary>
TEST_F(StylesTests, TestGetStyles) {
    utility::string_t remoteFileName = STCONVERT("TestGetStyles.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetStylesRequest > request(new GetStylesRequest(
        remoteFileName,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getStyles(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getStyles()));
   ASSERT_EQ(22, actual.body->getStyles().size());
   ASSERT_EQ(STCONVERT("Default Paragraph Font"), actual.body->getStyles()[0]->getName());
}

/// <summary>
/// Test for getting styles from document online.
/// </summary>
TEST_F(StylesTests, TestGetStylesOnline) {
    std::shared_ptr< GetStylesOnlineRequest > request(new GetStylesOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getStylesOnline(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting style from document.
/// </summary>
TEST_F(StylesTests, TestGetStyle) {
    utility::string_t remoteFileName = STCONVERT("TestGetStyle.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetStyleRequest > request(new GetStyleRequest(
        remoteFileName,
        STCONVERT("Heading 1"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getStyle(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getStyle()));
   ASSERT_EQ(STCONVERT("Heading 1"), actual.body->getStyle()->getName());
}

/// <summary>
/// Test for getting style from document online.
/// </summary>
TEST_F(StylesTests, TestGetStyleOnline) {
    std::shared_ptr< GetStyleOnlineRequest > request(new GetStyleOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        STCONVERT("Heading 1"),
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getStyleOnline(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for updating style from document.
/// </summary>
TEST_F(StylesTests, TestUpdateStyle) {
    utility::string_t remoteFileName = STCONVERT("TestUpdateStyle.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestStyleUpdate = std::make_shared< StyleUpdate >();
    requestStyleUpdate->setName(STCONVERT("My Style"));

    std::shared_ptr< UpdateStyleRequest > request(new UpdateStyleRequest(
        remoteFileName,
        STCONVERT("Heading 1"),
        requestStyleUpdate,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->updateStyle(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getStyle()));
   ASSERT_EQ(STCONVERT("My Style"), actual.body->getStyle()->getName());
}

/// <summary>
/// Test for updating style from document online.
/// </summary>
TEST_F(StylesTests, TestUpdateStyleOnline) {
    auto requestStyleUpdate = std::make_shared< StyleUpdate >();
    requestStyleUpdate->setName(STCONVERT("My Style"));

    std::shared_ptr< UpdateStyleOnlineRequest > request(new UpdateStyleOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        STCONVERT("Heading 1"),
        requestStyleUpdate,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

auto actual = get_api()->updateStyleOnline(request).get();
ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for inserting style from document.
/// </summary>
TEST_F(StylesTests, TestInsertStyle) {
    utility::string_t remoteFileName = STCONVERT("TestInsertStyle.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestStyleInsert = std::make_shared< StyleInsert >();
    requestStyleInsert->setStyleName(STCONVERT("My Style"));
    requestStyleInsert->setStyleType(STCONVERT("Paragraph"));

    std::shared_ptr< InsertStyleRequest > request(new InsertStyleRequest(
        remoteFileName,
        requestStyleInsert,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->insertStyle(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getStyle()));
   ASSERT_EQ(STCONVERT("My Style"), actual.body->getStyle()->getName());
}

/// <summary>
/// Test for inserting style from document online.
/// </summary>
TEST_F(StylesTests, TestInsertStyleOnline) {
    auto requestStyleInsert = std::make_shared< StyleInsert >();
    requestStyleInsert->setStyleName(STCONVERT("My Style"));
    requestStyleInsert->setStyleType(STCONVERT("Paragraph"));

    std::shared_ptr< InsertStyleOnlineRequest > request(new InsertStyleOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        requestStyleInsert,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

auto actual = get_api()->insertStyleOnline(request).get();
ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for coping style from document.
/// </summary>
TEST_F(StylesTests, TestCopyStyle) {
    utility::string_t remoteFileName = STCONVERT("TestCopyStyle.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestStyleCopy = std::make_shared< StyleCopy >();
    requestStyleCopy->setStyleName(STCONVERT("Heading 1"));

    std::shared_ptr< CopyStyleRequest > request(new CopyStyleRequest(
        remoteFileName,
        requestStyleCopy,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->copyStyle(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getStyle()));
   ASSERT_EQ(STCONVERT("Heading 1_0"), actual.body->getStyle()->getName());
}

/// <summary>
/// Test for coping style from document online.
/// </summary>
TEST_F(StylesTests, TestCopyStyleOnline) {
    auto requestStyleCopy = std::make_shared< StyleCopy >();
    requestStyleCopy->setStyleName(STCONVERT("Heading 1"));

    std::shared_ptr< CopyStyleOnlineRequest > request(new CopyStyleOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        requestStyleCopy,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

auto actual = get_api()->copyStyleOnline(request).get();
ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting style from document element.
/// </summary>
TEST_F(StylesTests, TestGetStyleFromDocumentElement) {
    utility::string_t remoteFileName = STCONVERT("TestGetStyleFromDocumentElement.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetStyleFromDocumentElementRequest > request(new GetStyleFromDocumentElementRequest(
        remoteFileName,
        STCONVERT("paragraphs/1/paragraphFormat"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getStyleFromDocumentElement(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getStyle()));
   ASSERT_EQ(STCONVERT("TOC 1"), actual.body->getStyle()->getName());
}

/// <summary>
/// Test for getting style from document element online.
/// </summary>
TEST_F(StylesTests, TestGetStyleFromDocumentElementOnline) {
    std::shared_ptr< GetStyleFromDocumentElementOnlineRequest > request(new GetStyleFromDocumentElementOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        STCONVERT("paragraphs/1/paragraphFormat"),
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getStyleFromDocumentElementOnline(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for applying style to document element.
/// </summary>
TEST_F(StylesTests, TestApplyStyleToDocumentElement) {
    utility::string_t remoteFileName = STCONVERT("TestApplyStyleToDocumentElement.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestStyleApply = std::make_shared< StyleApply >();
    requestStyleApply->setStyleName(STCONVERT("Heading 1"));

    std::shared_ptr< ApplyStyleToDocumentElementRequest > request(new ApplyStyleToDocumentElementRequest(
        remoteFileName,
        STCONVERT("paragraphs/1/paragraphFormat"),
        requestStyleApply,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->applyStyleToDocumentElement(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for applying style to document element online.
/// </summary>
TEST_F(StylesTests, TestApplyStyleToDocumentElementOnline) {
    auto requestStyleApply = std::make_shared< StyleApply >();
    requestStyleApply->setStyleName(STCONVERT("Heading 1"));

    std::shared_ptr< ApplyStyleToDocumentElementOnlineRequest > request(new ApplyStyleToDocumentElementOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        STCONVERT("paragraphs/1/paragraphFormat"),
        requestStyleApply,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

auto actual = get_api()->applyStyleToDocumentElementOnline(request).get();
ASSERT_EQ(200, actual.httpResponse->status_code());
}
