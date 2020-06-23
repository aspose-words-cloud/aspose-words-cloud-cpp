/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="paragraphTests.cpp">
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
/// Example of how to work with paragraph.
/// </summary>
class ParagraphTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentElements/Paragraphs");
    utility::string_t localFile = STCONVERT("Common/test_multi_pages.docx");
    utility::string_t fieldFolder = STCONVERT("DocumentElements/Fields");
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
        STCONVERT("sections/0"),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getParagraph(request).get();
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

    std::shared_ptr< GetParagraphWithoutNodePathRequest > request(new GetParagraphWithoutNodePathRequest(
        remoteFileName,
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getParagraphWithoutNodePath(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
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

    std::shared_ptr< GetParagraphsWithoutNodePathRequest > request(new GetParagraphsWithoutNodePathRequest(
        remoteFileName,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getParagraphsWithoutNodePath(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
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
        requestFontDto,
        STCONVERT("paragraphs/0"),
        0,
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

    std::shared_ptr< InsertParagraphWithoutNodePathRequest > request(new InsertParagraphWithoutNodePathRequest(
        remoteFileName,
        requestParagraph,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->insertParagraphWithoutNodePath(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
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
        STCONVERT(""),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->renderParagraph(request).get();
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

    std::shared_ptr< RenderParagraphWithoutNodePathRequest > request(new RenderParagraphWithoutNodePathRequest(
        remoteFileName,
        STCONVERT("png"),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->renderParagraphWithoutNodePath(request).get();
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
        STCONVERT(""),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getParagraphFormat(request).get();
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

    std::shared_ptr< GetParagraphFormatWithoutNodePathRequest > request(new GetParagraphFormatWithoutNodePathRequest(
        remoteFileName,
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getParagraphFormatWithoutNodePath(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
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

    auto requestDto = std::make_shared< ParagraphFormat >();
    requestDto->setAlignment(STCONVERT("Right"));

    std::shared_ptr< UpdateParagraphFormatRequest > request(new UpdateParagraphFormatRequest(
        remoteFileName,
        requestDto,
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

   auto actual = get_api()->updateParagraphFormat(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for updating  paragraph format settings without node path.
/// </summary>
TEST_F(ParagraphTests, TestUpdateParagraphFormatWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentParagraphsWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestDto = std::make_shared< ParagraphFormat >();
    requestDto->setAlignment(STCONVERT("Right"));

    std::shared_ptr< UpdateParagraphFormatWithoutNodePathRequest > request(new UpdateParagraphFormatWithoutNodePathRequest(
        remoteFileName,
        requestDto,
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->updateParagraphFormatWithoutNodePath(request).get();
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

   get_api()->deleteParagraph(request).get();
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

    std::shared_ptr< DeleteParagraphWithoutNodePathRequest > request(new DeleteParagraphWithoutNodePathRequest(
        remoteFileName,
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->deleteParagraphWithoutNodePath(request).get();
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
        STCONVERT(""),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getParagraphListFormat(request).get();
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

    std::shared_ptr< GetParagraphListFormatWithoutNodePathRequest > request(new GetParagraphListFormatWithoutNodePathRequest(
        remoteFileName,
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getParagraphListFormatWithoutNodePath(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
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

    auto requestDto = std::make_shared< ListFormatUpdate >();
    requestDto->setListId(2);

    std::shared_ptr< UpdateParagraphListFormatRequest > request(new UpdateParagraphListFormatRequest(
        remoteFileName,
        requestDto,
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

   auto actual = get_api()->updateParagraphListFormat(request).get();
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

    auto requestDto = std::make_shared< ListFormatUpdate >();
    requestDto->setListId(2);

    std::shared_ptr< UpdateParagraphListFormatWithoutNodePathRequest > request(new UpdateParagraphListFormatWithoutNodePathRequest(
        remoteFileName,
        requestDto,
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->updateParagraphListFormatWithoutNodePath(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
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

   auto actual = get_api()->deleteParagraphListFormat(request).get();
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

    std::shared_ptr< DeleteParagraphListFormatWithoutNodePathRequest > request(new DeleteParagraphListFormatWithoutNodePathRequest(
        remoteFileName,
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->deleteParagraphListFormatWithoutNodePath(request).get();
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
        STCONVERT(""),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getParagraphTabStops(request).get();
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

    std::shared_ptr< GetParagraphTabStopsWithoutNodePathRequest > request(new GetParagraphTabStopsWithoutNodePathRequest(
        remoteFileName,
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getParagraphTabStopsWithoutNodePath(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
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

    auto requestDto = std::make_shared< TabStopInsert >();
    requestDto->setAlignment(STCONVERT("Left"));
    requestDto->setLeader(STCONVERT("None"));
    requestDto->setPosition(72);

    std::shared_ptr< InsertOrUpdateParagraphTabStopRequest > request(new InsertOrUpdateParagraphTabStopRequest(
        remoteFileName,
        requestDto,
        STCONVERT(""),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->insertOrUpdateParagraphTabStop(request).get();
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

    auto requestDto = std::make_shared< TabStopInsert >();
    requestDto->setAlignment(STCONVERT("Left"));
    requestDto->setLeader(STCONVERT("None"));
    requestDto->setPosition(72);

    std::shared_ptr< InsertOrUpdateParagraphTabStopWithoutNodePathRequest > request(new InsertOrUpdateParagraphTabStopWithoutNodePathRequest(
        remoteFileName,
        requestDto,
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->insertOrUpdateParagraphTabStopWithoutNodePath(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
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
        STCONVERT(""),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->deleteAllParagraphTabStops(request).get();
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

    std::shared_ptr< DeleteAllParagraphTabStopsWithoutNodePathRequest > request(new DeleteAllParagraphTabStopsWithoutNodePathRequest(
        remoteFileName,
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->deleteAllParagraphTabStopsWithoutNodePath(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
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
        72,
        STCONVERT(""),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->deleteParagraphTabStop(request).get();
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

    std::shared_ptr< DeleteParagraphTabStopWithoutNodePathRequest > request(new DeleteParagraphTabStopWithoutNodePathRequest(
        remoteFileName,
        72,
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->deleteParagraphTabStopWithoutNodePath(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}
