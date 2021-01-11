/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="paragraphTests.cpp">
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
/// Example of how to work with paragraph.
/// </summary>
class ParagraphTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentElements/Paragraphs");
    utility::string_t localFile = STCONVERT("Common/test_multi_pages.docx");
    utility::string_t listFolder = STCONVERT("DocumentElements/ParagraphListFormat");
    utility::string_t tabStopFolder = STCONVERT("DocumentElements/Paragraphs");

};

/// <summary>
/// Test for getting paragraph.
/// </summary>
TEST_F(ParagraphTests, TestGetDocumentParagraphByIndex) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentParagraphByIndex.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetParagraphRequest > request(new GetParagraphRequest(
        remoteFileName,
        0,
        STCONVERT("sections/0"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getParagraph(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getParagraph()));
   ASSERT_EQ(STCONVERT("0.0.0"), actual.body->getParagraph()->getNodeId());
}

/// <summary>
/// Test for getting paragraph online.
/// </summary>
TEST_F(ParagraphTests, TestGetDocumentParagraphOnline) {
    std::shared_ptr< GetParagraphOnlineRequest > request(new GetParagraphOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        0,
        STCONVERT("sections/0"),
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getParagraphOnline(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting paragraph without node path.
/// </summary>
TEST_F(ParagraphTests, TestGetDocumentParagraphByIndexWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentParagraphByIndexWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetParagraphRequest > request(new GetParagraphRequest(
        remoteFileName,
        0,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getParagraph(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getParagraph()));
   ASSERT_EQ(STCONVERT("0.0.0"), actual.body->getParagraph()->getNodeId());
}

/// <summary>
/// Test for getting all paragraphs.
/// </summary>
TEST_F(ParagraphTests, TestGetDocumentParagraphs) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentParagraphs.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetParagraphsRequest > request(new GetParagraphsRequest(
        remoteFileName,
        STCONVERT("sections/0"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getParagraphs(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getParagraphs()));
   ASSERT_TRUE(IsNotNull(actual.body->getParagraphs()->getParagraphLinkList()));
   ASSERT_EQ(15, actual.body->getParagraphs()->getParagraphLinkList().size());
   ASSERT_EQ(STCONVERT("Page 1 of 3"), actual.body->getParagraphs()->getParagraphLinkList()[0]->getText());
}

/// <summary>
/// Test for getting all paragraphs online.
/// </summary>
TEST_F(ParagraphTests, TestGetDocumentParagraphsOnline) {
    std::shared_ptr< GetParagraphsOnlineRequest > request(new GetParagraphsOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        STCONVERT("sections/0"),
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getParagraphsOnline(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting all paragraphs without node path.
/// </summary>
TEST_F(ParagraphTests, TestGetDocumentParagraphsWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentParagraphsWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetParagraphsRequest > request(new GetParagraphsRequest(
        remoteFileName,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getParagraphs(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getParagraphs()));
   ASSERT_TRUE(IsNotNull(actual.body->getParagraphs()->getParagraphLinkList()));
   ASSERT_EQ(15, actual.body->getParagraphs()->getParagraphLinkList().size());
   ASSERT_EQ(STCONVERT("Page 1 of 3"), actual.body->getParagraphs()->getParagraphLinkList()[0]->getText());
}

/// <summary>
/// Test for getting paragraph run.
/// </summary>
TEST_F(ParagraphTests, TestGetDocumentParagraphRun) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentParagraphRun.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetRunRequest > request(new GetRunRequest(
        remoteFileName,
        STCONVERT("paragraphs/0"),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getRun(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getRun()));
   ASSERT_EQ(STCONVERT("Page "), actual.body->getRun()->getText());
}

/// <summary>
/// Test for getting paragraph run online.
/// </summary>
TEST_F(ParagraphTests, TestGetDocumentParagraphRunOnline) {
    std::shared_ptr< GetRunOnlineRequest > request(new GetRunOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        STCONVERT("paragraphs/0"),
        0,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getRunOnline(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting paragraph run font.
/// </summary>
TEST_F(ParagraphTests, TestGetDocumentParagraphRunFont) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentParagraphRunFont.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetRunFontRequest > request(new GetRunFontRequest(
        remoteFileName,
        STCONVERT("paragraphs/0"),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getRunFont(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getFont()));
   ASSERT_EQ(STCONVERT("Times New Roman"), actual.body->getFont()->getName());
}

/// <summary>
/// Test for getting paragraph run font online.
/// </summary>
TEST_F(ParagraphTests, TestGetDocumentParagraphRunFontOnline) {
    std::shared_ptr< GetRunFontOnlineRequest > request(new GetRunFontOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        STCONVERT("paragraphs/0"),
        0,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getRunFontOnline(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting paragraph runs.
/// </summary>
TEST_F(ParagraphTests, TestGetParagraphRuns) {
    utility::string_t remoteFileName = STCONVERT("TestGetParagraphRuns.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetRunsRequest > request(new GetRunsRequest(
        remoteFileName,
        STCONVERT("sections/0/paragraphs/0"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getRuns(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getRuns()));
   ASSERT_TRUE(IsNotNull(actual.body->getRuns()->getList()));
   ASSERT_EQ(6, actual.body->getRuns()->getList().size());
   ASSERT_EQ(STCONVERT("Page "), actual.body->getRuns()->getList()[0]->getText());
}

/// <summary>
/// Test for getting paragraph runs online.
/// </summary>
TEST_F(ParagraphTests, TestGetParagraphRunsOnline) {
    std::shared_ptr< GetRunsOnlineRequest > request(new GetRunsOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        STCONVERT("sections/0/paragraphs/0"),
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getRunsOnline(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for updating paragraph run font.
/// </summary>
TEST_F(ParagraphTests, TestUpdateRunFont) {
    utility::string_t remoteFileName = STCONVERT("TestUpdateRunFont.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestFontDto = std::make_shared< Font >();
    requestFontDto->setBold(true);

    std::shared_ptr< UpdateRunFontRequest > request(new UpdateRunFontRequest(
        remoteFileName,
        STCONVERT("paragraphs/0"),
        0,
        requestFontDto,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        baseTestOutPath + STCONVERT("/") + remoteFileName,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->updateRunFont(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getFont()));
   ASSERT_TRUE(actual.body->getFont()->isBold());
}

/// <summary>
/// Test for updating paragraph run font online.
/// </summary>
TEST_F(ParagraphTests, TestUpdateRunFontOnline) {
    auto requestFontDto = std::make_shared< Font >();
    requestFontDto->setBold(true);

    std::shared_ptr< UpdateRunFontOnlineRequest > request(new UpdateRunFontOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        STCONVERT("paragraphs/0"),
        requestFontDto,
        0,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

auto actual = get_api()->updateRunFontOnline(request).get();
ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for adding paragraph.
/// </summary>
TEST_F(ParagraphTests, TestInsertParagraph) {
    utility::string_t remoteFileName = STCONVERT("TestInsertParagraph.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestParagraph = std::make_shared< ParagraphInsert >();
    requestParagraph->setText(STCONVERT("This is a new paragraph for your document"));

    std::shared_ptr< InsertParagraphRequest > request(new InsertParagraphRequest(
        remoteFileName,
        requestParagraph,
        STCONVERT("sections/0"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->insertParagraph(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getParagraph()));
   ASSERT_EQ(STCONVERT("0.3.8"), actual.body->getParagraph()->getNodeId());
}

/// <summary>
/// Test for adding paragraph online.
/// </summary>
TEST_F(ParagraphTests, TestInsertParagraphOnline) {
    auto requestParagraph = std::make_shared< ParagraphInsert >();
    requestParagraph->setText(STCONVERT("This is a new paragraph for your document"));

    std::shared_ptr< InsertParagraphOnlineRequest > request(new InsertParagraphOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        requestParagraph,
        STCONVERT("sections/0"),
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

auto actual = get_api()->insertParagraphOnline(request).get();
ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for adding paragraph without node path.
/// </summary>
TEST_F(ParagraphTests, TestInsertParagraphWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestInsertParagraphWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestParagraph = std::make_shared< ParagraphInsert >();
    requestParagraph->setText(STCONVERT("This is a new paragraph for your document"));

    std::shared_ptr< InsertParagraphRequest > request(new InsertParagraphRequest(
        remoteFileName,
        requestParagraph,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->insertParagraph(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getParagraph()));
   ASSERT_EQ(STCONVERT("0.3.8"), actual.body->getParagraph()->getNodeId());
}

/// <summary>
/// Test for paragraph rendering.
/// </summary>
TEST_F(ParagraphTests, TestRenderParagraph) {
    utility::string_t remoteFileName = STCONVERT("TestRenderParagraph.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< RenderParagraphRequest > request(new RenderParagraphRequest(
        remoteFileName,
        STCONVERT("png"),
        0,
        STCONVERT(""),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->renderParagraph(request).get();
}

/// <summary>
/// Test for paragraph rendering.
/// </summary>
TEST_F(ParagraphTests, TestRenderParagraphOnline) {
    std::shared_ptr< RenderParagraphOnlineRequest > request(new RenderParagraphOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        STCONVERT("png"),
        0,
        STCONVERT(""),
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

auto actual = get_api()->renderParagraphOnline(request).get();
ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for paragraph rendering without node path.
/// </summary>
TEST_F(ParagraphTests, TestRenderParagraphWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestRenderParagraphWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< RenderParagraphRequest > request(new RenderParagraphRequest(
        remoteFileName,
        STCONVERT("png"),
        0,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->renderParagraph(request).get();
}

/// <summary>
/// Test for getting paragraph format settings.
/// </summary>
TEST_F(ParagraphTests, TestGetParagraphFormat) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentParagraphs.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetParagraphFormatRequest > request(new GetParagraphFormatRequest(
        remoteFileName,
        0,
        STCONVERT(""),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getParagraphFormat(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getParagraphFormat()));
   ASSERT_EQ(STCONVERT("Normal"), actual.body->getParagraphFormat()->getStyleName());
}

/// <summary>
/// Test for getting paragraph format settings online.
/// </summary>
TEST_F(ParagraphTests, TestGetParagraphFormatOnline) {
    std::shared_ptr< GetParagraphFormatOnlineRequest > request(new GetParagraphFormatOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        0,
        STCONVERT(""),
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getParagraphFormatOnline(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting paragraph format settings without node path.
/// </summary>
TEST_F(ParagraphTests, TestGetParagraphFormatWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentParagraphsWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetParagraphFormatRequest > request(new GetParagraphFormatRequest(
        remoteFileName,
        0,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getParagraphFormat(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getParagraphFormat()));
   ASSERT_EQ(STCONVERT("Normal"), actual.body->getParagraphFormat()->getStyleName());
}

/// <summary>
/// Test for updating  paragraph format settings.
/// </summary>
TEST_F(ParagraphTests, TestUpdateParagraphFormat) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentParagraphs.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestParagraphFormatDto = std::make_shared< ParagraphFormatUpdate >();
    requestParagraphFormatDto->setAlignment(STCONVERT("Right"));

    std::shared_ptr< UpdateParagraphFormatRequest > request(new UpdateParagraphFormatRequest(
        remoteFileName,
        0,
        requestParagraphFormatDto,
        STCONVERT(""),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->updateParagraphFormat(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getParagraphFormat()));

}

/// <summary>
/// Test for updating  paragraph format settings online.
/// </summary>
TEST_F(ParagraphTests, TestUpdateParagraphFormatOnline) {
    auto requestParagraphFormatDto = std::make_shared< ParagraphFormatUpdate >();
    requestParagraphFormatDto->setAlignment(STCONVERT("Right"));

    std::shared_ptr< UpdateParagraphFormatOnlineRequest > request(new UpdateParagraphFormatOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        requestParagraphFormatDto,
        0,
        STCONVERT(""),
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

auto actual = get_api()->updateParagraphFormatOnline(request).get();
ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting  a paragraph.
/// </summary>
TEST_F(ParagraphTests, TestDeleteParagraph) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteParagraph.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< DeleteParagraphRequest > request(new DeleteParagraphRequest(
        remoteFileName,
        0,
        STCONVERT(""),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->deleteParagraph(request).get();
}

/// <summary>
/// Test for deleting  a paragraph online.
/// </summary>
TEST_F(ParagraphTests, TestDeleteParagraphOnline) {
    std::shared_ptr< DeleteParagraphOnlineRequest > request(new DeleteParagraphOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        0,
        STCONVERT(""),
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->deleteParagraphOnline(request).get();
}

/// <summary>
/// Test for deleting  a paragraph without node path.
/// </summary>
TEST_F(ParagraphTests, TestDeleteParagraphWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteParagraphWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< DeleteParagraphRequest > request(new DeleteParagraphRequest(
        remoteFileName,
        0,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->deleteParagraph(request).get();
}

/// <summary>
/// Test for getting paragraph list format.
/// </summary>
TEST_F(ParagraphTests, TestGetParagraphListFormat) {
    utility::string_t remoteFileName = STCONVERT("TestParagraphGetListFormat.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, listFolder + STCONVERT("/ParagraphGetListFormat.doc"))
    );

    std::shared_ptr< GetParagraphListFormatRequest > request(new GetParagraphListFormatRequest(
        remoteFileName,
        0,
        STCONVERT(""),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getParagraphListFormat(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getListFormat()));
   ASSERT_EQ(1, actual.body->getListFormat()->getListId());
}

/// <summary>
/// Test for getting paragraph list format online.
/// </summary>
TEST_F(ParagraphTests, TestGetParagraphListFormatOnline) {
    std::shared_ptr< GetParagraphListFormatOnlineRequest > request(new GetParagraphListFormatOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, listFolder + STCONVERT("/ParagraphGetListFormat.doc"))),
        0,
        STCONVERT(""),
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getParagraphListFormatOnline(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting paragraph list format without node path.
/// </summary>
TEST_F(ParagraphTests, TestGetParagraphListFormatWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestParagraphGetListFormatWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, listFolder + STCONVERT("/ParagraphGetListFormat.doc"))
    );

    std::shared_ptr< GetParagraphListFormatRequest > request(new GetParagraphListFormatRequest(
        remoteFileName,
        0,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getParagraphListFormat(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getListFormat()));
   ASSERT_EQ(1, actual.body->getListFormat()->getListId());
}

/// <summary>
/// Test for updating paragraph list format.
/// </summary>
TEST_F(ParagraphTests, TestUpdateParagraphListFormat) {
    utility::string_t remoteFileName = STCONVERT("TestUpdateParagraphListFormat.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, listFolder + STCONVERT("/ParagraphUpdateListFormat.doc"))
    );

    auto requestListFormatDto = std::make_shared< ListFormatUpdate >();
    requestListFormatDto->setListId(2);

    std::shared_ptr< UpdateParagraphListFormatRequest > request(new UpdateParagraphListFormatRequest(
        remoteFileName,
        0,
        requestListFormatDto,
        STCONVERT(""),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->updateParagraphListFormat(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getListFormat()));
   ASSERT_EQ(2, actual.body->getListFormat()->getListId());
}

/// <summary>
/// Test for updating paragraph list format online.
/// </summary>
TEST_F(ParagraphTests, TestUpdateParagraphListFormatOnline) {
    auto requestListFormatDto = std::make_shared< ListFormatUpdate >();
    requestListFormatDto->setListId(2);

    std::shared_ptr< UpdateParagraphListFormatOnlineRequest > request(new UpdateParagraphListFormatOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, listFolder + STCONVERT("/ParagraphUpdateListFormat.doc"))),
        requestListFormatDto,
        0,
        STCONVERT(""),
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

auto actual = get_api()->updateParagraphListFormatOnline(request).get();
ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for updating paragraph list format without node path.
/// </summary>
TEST_F(ParagraphTests, TestUpdateParagraphListFormatWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestUpdateParagraphListFormatWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, listFolder + STCONVERT("/ParagraphUpdateListFormat.doc"))
    );

    auto requestListFormatDto = std::make_shared< ListFormatUpdate >();
    requestListFormatDto->setListId(2);

    std::shared_ptr< UpdateParagraphListFormatRequest > request(new UpdateParagraphListFormatRequest(
        remoteFileName,
        0,
        requestListFormatDto,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->updateParagraphListFormat(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getListFormat()));
   ASSERT_EQ(2, actual.body->getListFormat()->getListId());
}

/// <summary>
/// Test for deleting paragraph list format.
/// </summary>
TEST_F(ParagraphTests, TestDeleteParagraphListFormat) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteParagraphListFormat.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, listFolder + STCONVERT("/ParagraphDeleteListFormat.doc"))
    );

    std::shared_ptr< DeleteParagraphListFormatRequest > request(new DeleteParagraphListFormatRequest(
        remoteFileName,
        0,
        STCONVERT(""),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->deleteParagraphListFormat(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting paragraph list format online.
/// </summary>
TEST_F(ParagraphTests, TestDeleteParagraphListFormatOnline) {
    std::shared_ptr< DeleteParagraphListFormatOnlineRequest > request(new DeleteParagraphListFormatOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, listFolder + STCONVERT("/ParagraphDeleteListFormat.doc"))),
        0,
        STCONVERT(""),
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

auto actual = get_api()->deleteParagraphListFormatOnline(request).get();
ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting paragraph list format without node path.
/// </summary>
TEST_F(ParagraphTests, TestDeleteParagraphListFormatWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteParagraphListFormatWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, listFolder + STCONVERT("/ParagraphDeleteListFormat.doc"))
    );

    std::shared_ptr< DeleteParagraphListFormatRequest > request(new DeleteParagraphListFormatRequest(
        remoteFileName,
        0,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->deleteParagraphListFormat(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting paragraph tab stops.
/// </summary>
TEST_F(ParagraphTests, TestGetParagraphTabStops) {
    utility::string_t remoteFileName = STCONVERT("TestGetParagraphTabStops.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, tabStopFolder + STCONVERT("/ParagraphTabStops.docx"))
    );

    std::shared_ptr< GetParagraphTabStopsRequest > request(new GetParagraphTabStopsRequest(
        remoteFileName,
        0,
        STCONVERT(""),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getParagraphTabStops(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getTabStops()));
   ASSERT_EQ(2, actual.body->getTabStops().size());
   ASSERT_EQ(72.0, actual.body->getTabStops()[0]->getPosition());
}

/// <summary>
/// Test for getting paragraph tab stops online.
/// </summary>
TEST_F(ParagraphTests, TestGetParagraphTabStopsOnline) {
    std::shared_ptr< GetParagraphTabStopsOnlineRequest > request(new GetParagraphTabStopsOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, tabStopFolder + STCONVERT("/ParagraphTabStops.docx"))),
        0,
        STCONVERT(""),
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getParagraphTabStopsOnline(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting paragraph tab stops without node path.
/// </summary>
TEST_F(ParagraphTests, TestGetParagraphTabStopsWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestGetParagraphTabStopsWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, tabStopFolder + STCONVERT("/ParagraphTabStops.docx"))
    );

    std::shared_ptr< GetParagraphTabStopsRequest > request(new GetParagraphTabStopsRequest(
        remoteFileName,
        0,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getParagraphTabStops(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getTabStops()));
   ASSERT_EQ(2, actual.body->getTabStops().size());
   ASSERT_EQ(72.0, actual.body->getTabStops()[0]->getPosition());
}

/// <summary>
/// Test for inserting paragraph tab stop.
/// </summary>
TEST_F(ParagraphTests, TestInsertParagraphTabStops) {
    utility::string_t remoteFileName = STCONVERT("TestInsertOrUpdateParagraphTabStop.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, tabStopFolder + STCONVERT("/ParagraphTabStops.docx"))
    );

    auto requestTabStopInsertDto = std::make_shared< TabStopInsert >();
    requestTabStopInsertDto->setAlignment(STCONVERT("Left"));
    requestTabStopInsertDto->setLeader(STCONVERT("None"));
    requestTabStopInsertDto->setPosition(100.0);

    std::shared_ptr< InsertOrUpdateParagraphTabStopRequest > request(new InsertOrUpdateParagraphTabStopRequest(
        remoteFileName,
        0,
        requestTabStopInsertDto,
        STCONVERT(""),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->insertOrUpdateParagraphTabStop(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getTabStops()));
   ASSERT_EQ(3, actual.body->getTabStops().size());
   ASSERT_EQ(100.0, actual.body->getTabStops()[1]->getPosition());


}

/// <summary>
/// Test for inserting paragraph tab stop online.
/// </summary>
TEST_F(ParagraphTests, TestInsertParagraphTabStopsOnline) {
    auto requestTabStopInsertDto = std::make_shared< TabStopInsert >();
    requestTabStopInsertDto->setAlignment(STCONVERT("Left"));
    requestTabStopInsertDto->setLeader(STCONVERT("None"));
    requestTabStopInsertDto->setPosition(72);

    std::shared_ptr< InsertOrUpdateParagraphTabStopOnlineRequest > request(new InsertOrUpdateParagraphTabStopOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, tabStopFolder + STCONVERT("/ParagraphTabStops.docx"))),
        requestTabStopInsertDto,
        0,
        STCONVERT(""),
        boost::none,
        boost::none,
        boost::none
    ));

auto actual = get_api()->insertOrUpdateParagraphTabStopOnline(request).get();
ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for inserting paragraph tab stop without node path.
/// </summary>
TEST_F(ParagraphTests, TestInsertParagraphTabStopsWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestInsertOrUpdateParagraphTabStopWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, tabStopFolder + STCONVERT("/ParagraphTabStops.docx"))
    );

    auto requestTabStopInsertDto = std::make_shared< TabStopInsert >();
    requestTabStopInsertDto->setAlignment(STCONVERT("Left"));
    requestTabStopInsertDto->setLeader(STCONVERT("None"));
    requestTabStopInsertDto->setPosition(100.0);

    std::shared_ptr< InsertOrUpdateParagraphTabStopRequest > request(new InsertOrUpdateParagraphTabStopRequest(
        remoteFileName,
        0,
        requestTabStopInsertDto,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->insertOrUpdateParagraphTabStop(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getTabStops()));
   ASSERT_EQ(3, actual.body->getTabStops().size());
   ASSERT_EQ(100.0, actual.body->getTabStops()[1]->getPosition());


}

/// <summary>
/// Test for deleting all paragraph tab stops.
/// </summary>
TEST_F(ParagraphTests, TestDeleteAllParagraphTabStops) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteAllParagraphTabStops.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, tabStopFolder + STCONVERT("/ParagraphTabStops.docx"))
    );

    std::shared_ptr< DeleteAllParagraphTabStopsRequest > request(new DeleteAllParagraphTabStopsRequest(
        remoteFileName,
        0,
        STCONVERT(""),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->deleteAllParagraphTabStops(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getTabStops()));
   ASSERT_EQ(0, actual.body->getTabStops().size());
}

/// <summary>
/// Test for deleting all paragraph tab stops online.
/// </summary>
TEST_F(ParagraphTests, TestDeleteAllParagraphTabStopsOnline) {
    std::shared_ptr< DeleteAllParagraphTabStopsOnlineRequest > request(new DeleteAllParagraphTabStopsOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, tabStopFolder + STCONVERT("/ParagraphTabStops.docx"))),
        0,
        STCONVERT(""),
        boost::none,
        boost::none,
        boost::none
    ));

auto actual = get_api()->deleteAllParagraphTabStopsOnline(request).get();
ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting all paragraph tab stops without node path.
/// </summary>
TEST_F(ParagraphTests, TestDeleteAllParagraphTabStopsWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteAllParagraphTabStopsWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, tabStopFolder + STCONVERT("/ParagraphTabStops.docx"))
    );

    std::shared_ptr< DeleteAllParagraphTabStopsRequest > request(new DeleteAllParagraphTabStopsRequest(
        remoteFileName,
        0,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->deleteAllParagraphTabStops(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getTabStops()));
   ASSERT_EQ(0, actual.body->getTabStops().size());
}

/// <summary>
/// Test for deleting a tab stops.
/// </summary>
TEST_F(ParagraphTests, TestDeleteParagraphTabStop) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteParagraphTabStop.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, tabStopFolder + STCONVERT("/ParagraphTabStops.docx"))
    );

    std::shared_ptr< DeleteParagraphTabStopRequest > request(new DeleteParagraphTabStopRequest(
        remoteFileName,
        72.0,
        0,
        STCONVERT(""),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->deleteParagraphTabStop(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getTabStops()));
   ASSERT_EQ(1, actual.body->getTabStops().size());
}

/// <summary>
/// Test for deleting a tab stops online.
/// </summary>
TEST_F(ParagraphTests, TestDeleteParagraphTabStopOnline) {
    std::shared_ptr< DeleteParagraphTabStopOnlineRequest > request(new DeleteParagraphTabStopOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, tabStopFolder + STCONVERT("/ParagraphTabStops.docx"))),
        72.0,
        0,
        STCONVERT(""),
        boost::none,
        boost::none,
        boost::none
    ));

auto actual = get_api()->deleteParagraphTabStopOnline(request).get();
ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting a tab stops without node path.
/// </summary>
TEST_F(ParagraphTests, TestDeleteParagraphTabStopWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteParagraphTabStopWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, tabStopFolder + STCONVERT("/ParagraphTabStops.docx"))
    );

    std::shared_ptr< DeleteParagraphTabStopRequest > request(new DeleteParagraphTabStopRequest(
        remoteFileName,
        72.0,
        0,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->deleteParagraphTabStop(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getTabStops()));
   ASSERT_EQ(1, actual.body->getTabStops().size());
}
