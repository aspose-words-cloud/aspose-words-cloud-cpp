/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="paragraph_test.h">
*   Copyright (c) 2023 Aspose.Words for Cloud
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

#pragma once
#include "../test_base.h"

/// <summary>
/// Example of how to work with paragraph.
/// </summary>
class ParagraphTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentElements/Paragraphs";
    std::wstring localFile = L"Common/test_multi_pages.docx";
    std::wstring listFolder = L"DocumentElements/ParagraphListFormat";
    std::wstring tabStopFolder = L"DocumentElements/Paragraphs";

};

/// <summary>
/// Test for getting paragraph.
/// </summary>
TEST_F(ParagraphTests, TestGetDocumentParagraphByIndex) {
    std::wstring remoteFileName = L"TestGetDocumentParagraphByIndex.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetParagraphRequest> request(new requests::GetParagraphRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L"sections/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getParagraph(request);
    ASSERT_TRUE(actual->getParagraph() != nullptr);
    ASSERT_TRUE(actual->getParagraph()->getNodeId()->compare(L"0.0.0") == 0);
}

/// <summary>
/// Test for getting paragraph online.
/// </summary>
TEST_F(ParagraphTests, TestGetDocumentParagraphOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetParagraphOnlineRequest> request(new requests::GetParagraphOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L"sections/0"),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getParagraphOnline(request);
}

/// <summary>
/// Test for getting paragraph without node path.
/// </summary>
TEST_F(ParagraphTests, TestGetDocumentParagraphByIndexWithoutNodePath) {
    std::wstring remoteFileName = L"TestGetDocumentParagraphByIndexWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetParagraphRequest> request(new requests::GetParagraphRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getParagraph(request);
    ASSERT_TRUE(actual->getParagraph() != nullptr);
    ASSERT_TRUE(actual->getParagraph()->getNodeId()->compare(L"0.0.0") == 0);
}

/// <summary>
/// Test for getting all paragraphs.
/// </summary>
TEST_F(ParagraphTests, TestGetDocumentParagraphs) {
    std::wstring remoteFileName = L"TestGetDocumentParagraphs.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetParagraphsRequest> request(new requests::GetParagraphsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"sections/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getParagraphs(request);
    ASSERT_TRUE(actual->getParagraphs() != nullptr);
    ASSERT_TRUE(actual->getParagraphs()->getParagraphLinkList() != nullptr);
    ASSERT_EQ(15, actual->getParagraphs()->getParagraphLinkList()->size());
    ASSERT_TRUE(actual->getParagraphs()->getParagraphLinkList()->at(0)->getText()->compare(L"Page 1 of 3") == 0);
}

/// <summary>
/// Test for getting all paragraphs online.
/// </summary>
TEST_F(ParagraphTests, TestGetDocumentParagraphsOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetParagraphsOnlineRequest> request(new requests::GetParagraphsOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"sections/0"),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getParagraphsOnline(request);
}

/// <summary>
/// Test for getting all paragraphs without node path.
/// </summary>
TEST_F(ParagraphTests, TestGetDocumentParagraphsWithoutNodePath) {
    std::wstring remoteFileName = L"TestGetDocumentParagraphsWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetParagraphsRequest> request(new requests::GetParagraphsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getParagraphs(request);
    ASSERT_TRUE(actual->getParagraphs() != nullptr);
    ASSERT_TRUE(actual->getParagraphs()->getParagraphLinkList() != nullptr);
    ASSERT_EQ(15, actual->getParagraphs()->getParagraphLinkList()->size());
    ASSERT_TRUE(actual->getParagraphs()->getParagraphLinkList()->at(0)->getText()->compare(L"Page 1 of 3") == 0);
}

/// <summary>
/// Test for getting paragraph run.
/// </summary>
TEST_F(ParagraphTests, TestGetDocumentParagraphRun) {
    std::wstring remoteFileName = L"TestGetDocumentParagraphRun.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetRunRequest> request(new requests::GetRunRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"paragraphs/0"),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getRun(request);
    ASSERT_TRUE(actual->getRun() != nullptr);
    ASSERT_TRUE(actual->getRun()->getText()->compare(L"Page ") == 0);
}

/// <summary>
/// Test for getting paragraph run online.
/// </summary>
TEST_F(ParagraphTests, TestGetDocumentParagraphRunOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetRunOnlineRequest> request(new requests::GetRunOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"paragraphs/0"),
        std::make_shared< int32_t >(0),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getRunOnline(request);
}

/// <summary>
/// Test for getting paragraph run font.
/// </summary>
TEST_F(ParagraphTests, TestGetDocumentParagraphRunFont) {
    std::wstring remoteFileName = L"TestGetDocumentParagraphRunFont.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetRunFontRequest> request(new requests::GetRunFontRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"paragraphs/0"),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getRunFont(request);
    ASSERT_TRUE(actual->getFont() != nullptr);
    ASSERT_TRUE(actual->getFont()->getName()->compare(L"Times New Roman") == 0);
}

/// <summary>
/// Test for getting paragraph run font online.
/// </summary>
TEST_F(ParagraphTests, TestGetDocumentParagraphRunFontOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetRunFontOnlineRequest> request(new requests::GetRunFontOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"paragraphs/0"),
        std::make_shared< int32_t >(0),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getRunFontOnline(request);
}

/// <summary>
/// Test for getting paragraph runs.
/// </summary>
TEST_F(ParagraphTests, TestGetParagraphRuns) {
    std::wstring remoteFileName = L"TestGetParagraphRuns.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetRunsRequest> request(new requests::GetRunsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"sections/0/paragraphs/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getRuns(request);
    ASSERT_TRUE(actual->getRuns() != nullptr);
    ASSERT_TRUE(actual->getRuns()->getList() != nullptr);
    ASSERT_EQ(6, actual->getRuns()->getList()->size());
    ASSERT_TRUE(actual->getRuns()->getList()->at(0)->getText()->compare(L"Page ") == 0);
}

/// <summary>
/// Test for getting paragraph runs online.
/// </summary>
TEST_F(ParagraphTests, TestGetParagraphRunsOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetRunsOnlineRequest> request(new requests::GetRunsOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"sections/0/paragraphs/0"),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getRunsOnline(request);
}

/// <summary>
/// Test for updating paragraph run font.
/// </summary>
TEST_F(ParagraphTests, TestUpdateRunFont) {
    std::wstring remoteFileName = L"TestUpdateRunFont.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestFontDto = std::make_shared< aspose::words::cloud::models::Font >();
    requestFontDto->setBold(std::make_shared< bool >(true));
    std::shared_ptr<requests::UpdateRunFontRequest> request(new requests::UpdateRunFontRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"paragraphs/0"),
        std::make_shared< int32_t >(0),
        requestFontDto,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateRunFont(request);
    ASSERT_TRUE(actual->getFont() != nullptr);
    ASSERT_TRUE(*(actual->getFont()->getBold()));
}

/// <summary>
/// Test for updating paragraph run font online.
/// </summary>
TEST_F(ParagraphTests, TestUpdateRunFontOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestFontDto = std::make_shared< aspose::words::cloud::models::Font >();
    requestFontDto->setBold(std::make_shared< bool >(true));
    std::shared_ptr<requests::UpdateRunFontOnlineRequest> request(new requests::UpdateRunFontOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"paragraphs/0"),
        requestFontDto,
        std::make_shared< int32_t >(0),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateRunFontOnline(request);
}

/// <summary>
/// Test for adding paragraph.
/// </summary>
TEST_F(ParagraphTests, TestInsertParagraph) {
    std::wstring remoteFileName = L"TestInsertParagraph.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestParagraph = std::make_shared< aspose::words::cloud::models::ParagraphInsert >();
    requestParagraph->setText(std::make_shared< std::wstring >(L"This is a new paragraph for your document"));
    std::shared_ptr<requests::InsertParagraphRequest> request(new requests::InsertParagraphRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestParagraph,
        std::make_shared< std::wstring >(L"sections/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertParagraph(request);
    ASSERT_TRUE(actual->getParagraph() != nullptr);
    ASSERT_TRUE(actual->getParagraph()->getNodeId()->compare(L"0.3.8") == 0);
}

/// <summary>
/// Test for adding paragraph online.
/// </summary>
TEST_F(ParagraphTests, TestInsertParagraphOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestParagraph = std::make_shared< aspose::words::cloud::models::ParagraphInsert >();
    requestParagraph->setText(std::make_shared< std::wstring >(L"This is a new paragraph for your document"));
    std::shared_ptr<requests::InsertParagraphOnlineRequest> request(new requests::InsertParagraphOnlineRequest(
        requestDocument,
        requestParagraph,
        std::make_shared< std::wstring >(L"sections/0"),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertParagraphOnline(request);
}

/// <summary>
/// Test for adding paragraph without node path.
/// </summary>
TEST_F(ParagraphTests, TestInsertParagraphWithoutNodePath) {
    std::wstring remoteFileName = L"TestInsertParagraphWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestParagraph = std::make_shared< aspose::words::cloud::models::ParagraphInsert >();
    requestParagraph->setText(std::make_shared< std::wstring >(L"This is a new paragraph for your document"));
    std::shared_ptr<requests::InsertParagraphRequest> request(new requests::InsertParagraphRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestParagraph,
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertParagraph(request);
    ASSERT_TRUE(actual->getParagraph() != nullptr);
    ASSERT_TRUE(actual->getParagraph()->getNodeId()->compare(L"0.3.8") == 0);
}

/// <summary>
/// Test for paragraph rendering.
/// </summary>
TEST_F(ParagraphTests, TestRenderParagraph) {
    std::wstring remoteFileName = L"TestRenderParagraph.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::RenderParagraphRequest> request(new requests::RenderParagraphRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"png"),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->renderParagraph(request);
}

/// <summary>
/// Test for paragraph rendering.
/// </summary>
TEST_F(ParagraphTests, TestRenderParagraphOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::RenderParagraphOnlineRequest> request(new requests::RenderParagraphOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"png"),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->renderParagraphOnline(request);
}

/// <summary>
/// Test for paragraph rendering without node path.
/// </summary>
TEST_F(ParagraphTests, TestRenderParagraphWithoutNodePath) {
    std::wstring remoteFileName = L"TestRenderParagraphWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::RenderParagraphRequest> request(new requests::RenderParagraphRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"png"),
        std::make_shared< int32_t >(0),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->renderParagraph(request);
}

/// <summary>
/// Test for getting paragraph format settings.
/// </summary>
TEST_F(ParagraphTests, TestGetParagraphFormat) {
    std::wstring remoteFileName = L"TestGetDocumentParagraphs.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetParagraphFormatRequest> request(new requests::GetParagraphFormatRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getParagraphFormat(request);
    ASSERT_TRUE(actual->getParagraphFormat() != nullptr);
    ASSERT_TRUE(actual->getParagraphFormat()->getStyleName()->compare(L"Normal") == 0);
}

/// <summary>
/// Test for getting paragraph format settings online.
/// </summary>
TEST_F(ParagraphTests, TestGetParagraphFormatOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetParagraphFormatOnlineRequest> request(new requests::GetParagraphFormatOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getParagraphFormatOnline(request);
}

/// <summary>
/// Test for getting paragraph format settings without node path.
/// </summary>
TEST_F(ParagraphTests, TestGetParagraphFormatWithoutNodePath) {
    std::wstring remoteFileName = L"TestGetDocumentParagraphsWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetParagraphFormatRequest> request(new requests::GetParagraphFormatRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getParagraphFormat(request);
    ASSERT_TRUE(actual->getParagraphFormat() != nullptr);
    ASSERT_TRUE(actual->getParagraphFormat()->getStyleName()->compare(L"Normal") == 0);
}

/// <summary>
/// Test for updating  paragraph format settings.
/// </summary>
TEST_F(ParagraphTests, TestUpdateParagraphFormat) {
    std::wstring remoteFileName = L"TestGetDocumentParagraphs.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestParagraphFormatDto = std::make_shared< aspose::words::cloud::models::ParagraphFormatUpdate >();
    requestParagraphFormatDto->setAlignment(std::make_shared< aspose::words::cloud::models::ParagraphFormatBase::Alignment >(aspose::words::cloud::models::ParagraphFormatBase::Alignment::RIGHT));
    std::shared_ptr<requests::UpdateParagraphFormatRequest> request(new requests::UpdateParagraphFormatRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        requestParagraphFormatDto,
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateParagraphFormat(request);
    ASSERT_TRUE(actual->getParagraphFormat() != nullptr);

}

/// <summary>
/// Test for updating  paragraph format settings online.
/// </summary>
TEST_F(ParagraphTests, TestUpdateParagraphFormatOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestParagraphFormatDto = std::make_shared< aspose::words::cloud::models::ParagraphFormatUpdate >();
    requestParagraphFormatDto->setAlignment(std::make_shared< aspose::words::cloud::models::ParagraphFormatBase::Alignment >(aspose::words::cloud::models::ParagraphFormatBase::Alignment::RIGHT));
    std::shared_ptr<requests::UpdateParagraphFormatOnlineRequest> request(new requests::UpdateParagraphFormatOnlineRequest(
        requestDocument,
        requestParagraphFormatDto,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateParagraphFormatOnline(request);
}

/// <summary>
/// Test for deleting  a paragraph.
/// </summary>
TEST_F(ParagraphTests, TestDeleteParagraph) {
    std::wstring remoteFileName = L"TestDeleteParagraph.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteParagraphRequest> request(new requests::DeleteParagraphRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

getApi()->deleteParagraph(request);
}

/// <summary>
/// Test for deleting  a paragraph online.
/// </summary>
TEST_F(ParagraphTests, TestDeleteParagraphOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::DeleteParagraphOnlineRequest> request(new requests::DeleteParagraphOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteParagraphOnline(request);
}

/// <summary>
/// Test for deleting  a paragraph without node path.
/// </summary>
TEST_F(ParagraphTests, TestDeleteParagraphWithoutNodePath) {
    std::wstring remoteFileName = L"TestDeleteParagraphWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteParagraphRequest> request(new requests::DeleteParagraphRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

getApi()->deleteParagraph(request);
}

/// <summary>
/// Test for getting paragraph list format.
/// </summary>
TEST_F(ParagraphTests, TestGetParagraphListFormat) {
    std::wstring remoteFileName = L"TestParagraphGetListFormat.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + listFolder + L"/ParagraphGetListFormat.doc",
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetParagraphListFormatRequest> request(new requests::GetParagraphListFormatRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getParagraphListFormat(request);
    ASSERT_TRUE(actual->getListFormat() != nullptr);
    ASSERT_EQ(1, *(actual->getListFormat()->getListId()));
}

/// <summary>
/// Test for getting paragraph list format online.
/// </summary>
TEST_F(ParagraphTests, TestGetParagraphListFormatOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(listFolder + L"/ParagraphGetListFormat.doc")), std::istream::binary));
    std::shared_ptr<requests::GetParagraphListFormatOnlineRequest> request(new requests::GetParagraphListFormatOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getParagraphListFormatOnline(request);
}

/// <summary>
/// Test for getting paragraph list format without node path.
/// </summary>
TEST_F(ParagraphTests, TestGetParagraphListFormatWithoutNodePath) {
    std::wstring remoteFileName = L"TestParagraphGetListFormatWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + listFolder + L"/ParagraphGetListFormat.doc",
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetParagraphListFormatRequest> request(new requests::GetParagraphListFormatRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getParagraphListFormat(request);
    ASSERT_TRUE(actual->getListFormat() != nullptr);
    ASSERT_EQ(1, *(actual->getListFormat()->getListId()));
}

/// <summary>
/// Test for updating paragraph list format.
/// </summary>
TEST_F(ParagraphTests, TestUpdateParagraphListFormat) {
    std::wstring remoteFileName = L"TestUpdateParagraphListFormat.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + listFolder + L"/ParagraphUpdateListFormat.doc",
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestListFormatDto = std::make_shared< aspose::words::cloud::models::ListFormatUpdate >();
    requestListFormatDto->setListId(std::make_shared< int32_t >(2));
    std::shared_ptr<requests::UpdateParagraphListFormatRequest> request(new requests::UpdateParagraphListFormatRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        requestListFormatDto,
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateParagraphListFormat(request);
    ASSERT_TRUE(actual->getListFormat() != nullptr);
    ASSERT_EQ(2, *(actual->getListFormat()->getListId()));
}

/// <summary>
/// Test for updating paragraph list format online.
/// </summary>
TEST_F(ParagraphTests, TestUpdateParagraphListFormatOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(listFolder + L"/ParagraphUpdateListFormat.doc")), std::istream::binary));
    auto requestListFormatDto = std::make_shared< aspose::words::cloud::models::ListFormatUpdate >();
    requestListFormatDto->setListId(std::make_shared< int32_t >(2));
    std::shared_ptr<requests::UpdateParagraphListFormatOnlineRequest> request(new requests::UpdateParagraphListFormatOnlineRequest(
        requestDocument,
        requestListFormatDto,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateParagraphListFormatOnline(request);
}

/// <summary>
/// Test for updating paragraph list format without node path.
/// </summary>
TEST_F(ParagraphTests, TestUpdateParagraphListFormatWithoutNodePath) {
    std::wstring remoteFileName = L"TestUpdateParagraphListFormatWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + listFolder + L"/ParagraphUpdateListFormat.doc",
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestListFormatDto = std::make_shared< aspose::words::cloud::models::ListFormatUpdate >();
    requestListFormatDto->setListId(std::make_shared< int32_t >(2));
    std::shared_ptr<requests::UpdateParagraphListFormatRequest> request(new requests::UpdateParagraphListFormatRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        requestListFormatDto,
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateParagraphListFormat(request);
    ASSERT_TRUE(actual->getListFormat() != nullptr);
    ASSERT_EQ(2, *(actual->getListFormat()->getListId()));
}

/// <summary>
/// Test for deleting paragraph list format.
/// </summary>
TEST_F(ParagraphTests, TestDeleteParagraphListFormat) {
    std::wstring remoteFileName = L"TestDeleteParagraphListFormat.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + listFolder + L"/ParagraphDeleteListFormat.doc",
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteParagraphListFormatRequest> request(new requests::DeleteParagraphListFormatRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteParagraphListFormat(request);
}

/// <summary>
/// Test for deleting paragraph list format online.
/// </summary>
TEST_F(ParagraphTests, TestDeleteParagraphListFormatOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(listFolder + L"/ParagraphDeleteListFormat.doc")), std::istream::binary));
    std::shared_ptr<requests::DeleteParagraphListFormatOnlineRequest> request(new requests::DeleteParagraphListFormatOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteParagraphListFormatOnline(request);
}

/// <summary>
/// Test for deleting paragraph list format without node path.
/// </summary>
TEST_F(ParagraphTests, TestDeleteParagraphListFormatWithoutNodePath) {
    std::wstring remoteFileName = L"TestDeleteParagraphListFormatWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + listFolder + L"/ParagraphDeleteListFormat.doc",
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteParagraphListFormatRequest> request(new requests::DeleteParagraphListFormatRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteParagraphListFormat(request);
}

/// <summary>
/// Test for getting paragraph tab stops.
/// </summary>
TEST_F(ParagraphTests, TestGetParagraphTabStops) {
    std::wstring remoteFileName = L"TestGetParagraphTabStops.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + tabStopFolder + L"/ParagraphTabStops.docx",
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetParagraphTabStopsRequest> request(new requests::GetParagraphTabStopsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getParagraphTabStops(request);
    ASSERT_TRUE(actual->getTabStops() != nullptr);
    ASSERT_EQ(2, actual->getTabStops()->size());
    ASSERT_EQ(72.0, *(actual->getTabStops()->at(0)->getPosition()));
}

/// <summary>
/// Test for getting paragraph tab stops online.
/// </summary>
TEST_F(ParagraphTests, TestGetParagraphTabStopsOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(tabStopFolder + L"/ParagraphTabStops.docx")), std::istream::binary));
    std::shared_ptr<requests::GetParagraphTabStopsOnlineRequest> request(new requests::GetParagraphTabStopsOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getParagraphTabStopsOnline(request);
}

/// <summary>
/// Test for getting paragraph tab stops without node path.
/// </summary>
TEST_F(ParagraphTests, TestGetParagraphTabStopsWithoutNodePath) {
    std::wstring remoteFileName = L"TestGetParagraphTabStopsWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + tabStopFolder + L"/ParagraphTabStops.docx",
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetParagraphTabStopsRequest> request(new requests::GetParagraphTabStopsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getParagraphTabStops(request);
    ASSERT_TRUE(actual->getTabStops() != nullptr);
    ASSERT_EQ(2, actual->getTabStops()->size());
    ASSERT_EQ(72.0, *(actual->getTabStops()->at(0)->getPosition()));
}

/// <summary>
/// Test for inserting paragraph tab stop.
/// </summary>
TEST_F(ParagraphTests, TestInsertParagraphTabStops) {
    std::wstring remoteFileName = L"TestInsertOrUpdateParagraphTabStop.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + tabStopFolder + L"/ParagraphTabStops.docx",
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestTabStopInsertDto = std::make_shared< aspose::words::cloud::models::TabStopInsert >();
    requestTabStopInsertDto->setAlignment(std::make_shared< aspose::words::cloud::models::TabStopBase::Alignment >(aspose::words::cloud::models::TabStopBase::Alignment::LEFT));
    requestTabStopInsertDto->setLeader(std::make_shared< aspose::words::cloud::models::TabStopBase::Leader >(aspose::words::cloud::models::TabStopBase::Leader::NONE));
    requestTabStopInsertDto->setPosition(std::make_shared< double >(100.0));
    std::shared_ptr<requests::InsertOrUpdateParagraphTabStopRequest> request(new requests::InsertOrUpdateParagraphTabStopRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        requestTabStopInsertDto,
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertOrUpdateParagraphTabStop(request);
    ASSERT_TRUE(actual->getTabStops() != nullptr);
    ASSERT_EQ(3, actual->getTabStops()->size());
    ASSERT_EQ(100.0, *(actual->getTabStops()->at(1)->getPosition()));


}

/// <summary>
/// Test for inserting paragraph tab stop online.
/// </summary>
TEST_F(ParagraphTests, TestInsertParagraphTabStopsOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(tabStopFolder + L"/ParagraphTabStops.docx")), std::istream::binary));
    auto requestTabStopInsertDto = std::make_shared< aspose::words::cloud::models::TabStopInsert >();
    requestTabStopInsertDto->setAlignment(std::make_shared< aspose::words::cloud::models::TabStopBase::Alignment >(aspose::words::cloud::models::TabStopBase::Alignment::LEFT));
    requestTabStopInsertDto->setLeader(std::make_shared< aspose::words::cloud::models::TabStopBase::Leader >(aspose::words::cloud::models::TabStopBase::Leader::NONE));
    requestTabStopInsertDto->setPosition(std::make_shared< double >(72));
    std::shared_ptr<requests::InsertOrUpdateParagraphTabStopOnlineRequest> request(new requests::InsertOrUpdateParagraphTabStopOnlineRequest(
        requestDocument,
        requestTabStopInsertDto,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertOrUpdateParagraphTabStopOnline(request);
}

/// <summary>
/// Test for inserting paragraph tab stop without node path.
/// </summary>
TEST_F(ParagraphTests, TestInsertParagraphTabStopsWithoutNodePath) {
    std::wstring remoteFileName = L"TestInsertOrUpdateParagraphTabStopWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + tabStopFolder + L"/ParagraphTabStops.docx",
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestTabStopInsertDto = std::make_shared< aspose::words::cloud::models::TabStopInsert >();
    requestTabStopInsertDto->setAlignment(std::make_shared< aspose::words::cloud::models::TabStopBase::Alignment >(aspose::words::cloud::models::TabStopBase::Alignment::LEFT));
    requestTabStopInsertDto->setLeader(std::make_shared< aspose::words::cloud::models::TabStopBase::Leader >(aspose::words::cloud::models::TabStopBase::Leader::NONE));
    requestTabStopInsertDto->setPosition(std::make_shared< double >(100.0));
    std::shared_ptr<requests::InsertOrUpdateParagraphTabStopRequest> request(new requests::InsertOrUpdateParagraphTabStopRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        requestTabStopInsertDto,
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertOrUpdateParagraphTabStop(request);
    ASSERT_TRUE(actual->getTabStops() != nullptr);
    ASSERT_EQ(3, actual->getTabStops()->size());
    ASSERT_EQ(100.0, *(actual->getTabStops()->at(1)->getPosition()));


}

/// <summary>
/// Test for deleting all paragraph tab stops.
/// </summary>
TEST_F(ParagraphTests, TestDeleteAllParagraphTabStops) {
    std::wstring remoteFileName = L"TestDeleteAllParagraphTabStops.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + tabStopFolder + L"/ParagraphTabStops.docx",
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteAllParagraphTabStopsRequest> request(new requests::DeleteAllParagraphTabStopsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteAllParagraphTabStops(request);
    ASSERT_TRUE(actual->getTabStops() != nullptr);
    ASSERT_EQ(0, actual->getTabStops()->size());
}

/// <summary>
/// Test for deleting all paragraph tab stops online.
/// </summary>
TEST_F(ParagraphTests, TestDeleteAllParagraphTabStopsOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(tabStopFolder + L"/ParagraphTabStops.docx")), std::istream::binary));
    std::shared_ptr<requests::DeleteAllParagraphTabStopsOnlineRequest> request(new requests::DeleteAllParagraphTabStopsOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteAllParagraphTabStopsOnline(request);
}

/// <summary>
/// Test for deleting all paragraph tab stops without node path.
/// </summary>
TEST_F(ParagraphTests, TestDeleteAllParagraphTabStopsWithoutNodePath) {
    std::wstring remoteFileName = L"TestDeleteAllParagraphTabStopsWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + tabStopFolder + L"/ParagraphTabStops.docx",
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteAllParagraphTabStopsRequest> request(new requests::DeleteAllParagraphTabStopsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteAllParagraphTabStops(request);
    ASSERT_TRUE(actual->getTabStops() != nullptr);
    ASSERT_EQ(0, actual->getTabStops()->size());
}

/// <summary>
/// Test for deleting a tab stops.
/// </summary>
TEST_F(ParagraphTests, TestDeleteParagraphTabStop) {
    std::wstring remoteFileName = L"TestDeleteParagraphTabStop.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + tabStopFolder + L"/ParagraphTabStops.docx",
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteParagraphTabStopRequest> request(new requests::DeleteParagraphTabStopRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< double >(72.0),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteParagraphTabStop(request);
    ASSERT_TRUE(actual->getTabStops() != nullptr);
    ASSERT_EQ(1, actual->getTabStops()->size());
}

/// <summary>
/// Test for deleting a tab stops online.
/// </summary>
TEST_F(ParagraphTests, TestDeleteParagraphTabStopOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(tabStopFolder + L"/ParagraphTabStops.docx")), std::istream::binary));
    std::shared_ptr<requests::DeleteParagraphTabStopOnlineRequest> request(new requests::DeleteParagraphTabStopOnlineRequest(
        requestDocument,
        std::make_shared< double >(72.0),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteParagraphTabStopOnline(request);
}

/// <summary>
/// Test for deleting a tab stops without node path.
/// </summary>
TEST_F(ParagraphTests, TestDeleteParagraphTabStopWithoutNodePath) {
    std::wstring remoteFileName = L"TestDeleteParagraphTabStopWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + tabStopFolder + L"/ParagraphTabStops.docx",
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteParagraphTabStopRequest> request(new requests::DeleteParagraphTabStopRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< double >(72.0),
        std::make_shared< int32_t >(0),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteParagraphTabStop(request);
    ASSERT_TRUE(actual->getTabStops() != nullptr);
    ASSERT_EQ(1, actual->getTabStops()->size());
}
