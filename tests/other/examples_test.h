/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="examples_test.h">
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

#pragma once
#include "aspose_words_cloud.h"
using namespace aspose::words::cloud;
#include "../test_base.h"

class ExamplesTest : public InfrastructureTest {
protected:
    std::wstring localTestExamplesFolder = getSdkRoot() + L"/examples_data";
};

TEST_F(ExamplesTest, TestExampleAcceptAllRevisions) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    std::wstring fileName  = L"test_doc.docx";

    // Upload original document to cloud storage.
    auto myVar1 = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + fileName), std::istream::binary));
    auto myVar2 = std::make_shared< std::wstring >(fileName);
    std::shared_ptr< requests::UploadFileRequest > uploadFileRequest(
        new requests::UploadFileRequest(
            myVar1, myVar2
        )
    );
    wordsApi->uploadFile(uploadFileRequest);

    // Calls AcceptAllRevisions method for document in cloud.
    auto myVar3 = std::make_shared< std::wstring >(fileName);
    std::shared_ptr< requests::AcceptAllRevisionsRequest > request(
        new requests::AcceptAllRevisionsRequest(
            myVar3
        )
    );
    wordsApi->acceptAllRevisions(request);
}

TEST_F(ExamplesTest, TestExampleAcceptAllRevisionsOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::AcceptAllRevisionsOnlineRequest > acceptRequest(
        new requests::AcceptAllRevisionsOnlineRequest(
            requestDocument
        )
    );
    wordsApi->acceptAllRevisionsOnline(acceptRequest);
}

TEST_F(ExamplesTest, TestExampleAppendDocument) {
    auto wordsApi = getApi();
    std::wstring remoteFileName = L"Sample.docx";

    auto requestDocumentListDocumentEntries0 = std::make_shared< aspose::words::cloud::models::DocumentEntry >();
    requestDocumentListDocumentEntries0->setHref(std::make_shared< std::wstring >(remoteFileName));
    requestDocumentListDocumentEntries0->setImportFormatMode(std::make_shared< std::wstring >(L"KeepSourceFormatting"));
    auto requestDocumentListDocumentEntries = std::make_shared< std::vector<std::shared_ptr<aspose::words::cloud::models::DocumentEntry>> >();
    requestDocumentListDocumentEntries->push_back(requestDocumentListDocumentEntries0);
    auto requestDocumentList = std::make_shared< aspose::words::cloud::models::DocumentEntryList >();
    requestDocumentList->setDocumentEntries(requestDocumentListDocumentEntries);
    std::shared_ptr< requests::AppendDocumentRequest > appendRequest(
        new requests::AppendDocumentRequest(
            std::make_shared< std::wstring >(remoteFileName), requestDocumentList
        )
    );
    wordsApi->appendDocument(appendRequest);
}

TEST_F(ExamplesTest, TestExampleAppendDocumentOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestDocumentListDocumentEntries0 = std::make_shared< aspose::words::cloud::models::DocumentEntry >();
    requestDocumentListDocumentEntries0->setHref(std::make_shared< std::wstring >(L"Sample.docx"));
    requestDocumentListDocumentEntries0->setImportFormatMode(std::make_shared< std::wstring >(L"KeepSourceFormatting"));
    auto requestDocumentListDocumentEntries = std::make_shared< std::vector<std::shared_ptr<aspose::words::cloud::models::DocumentEntry>> >();
    requestDocumentListDocumentEntries->push_back(requestDocumentListDocumentEntries0);
    auto requestDocumentList = std::make_shared< aspose::words::cloud::models::DocumentEntryList >();
    requestDocumentList->setDocumentEntries(requestDocumentListDocumentEntries);
    std::shared_ptr< requests::AppendDocumentOnlineRequest > appendRequest(
        new requests::AppendDocumentOnlineRequest(
            requestDocument, requestDocumentList
        )
    );
    wordsApi->appendDocumentOnline(appendRequest);
}

TEST_F(ExamplesTest, TestExampleApplyStyleToDocumentElement) {
    auto wordsApi = getApi();
    auto requestStyleApply = std::make_shared< aspose::words::cloud::models::StyleApply >();
    requestStyleApply->setStyleName(std::make_shared< std::wstring >(L"Heading 1"));
    std::shared_ptr< requests::ApplyStyleToDocumentElementRequest > applyStyleRequest(
        new requests::ApplyStyleToDocumentElementRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"paragraphs/1/paragraphFormat"), requestStyleApply
        )
    );
    wordsApi->applyStyleToDocumentElement(applyStyleRequest);
}

TEST_F(ExamplesTest, TestExampleApplyStyleToDocumentElementOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestStyleApply = std::make_shared< aspose::words::cloud::models::StyleApply >();
    requestStyleApply->setStyleName(std::make_shared< std::wstring >(L"Heading 1"));
    std::shared_ptr< requests::ApplyStyleToDocumentElementOnlineRequest > applyStyleRequest(
        new requests::ApplyStyleToDocumentElementOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"paragraphs/1/paragraphFormat"), requestStyleApply
        )
    );
    wordsApi->applyStyleToDocumentElementOnline(applyStyleRequest);
}

TEST_F(ExamplesTest, TestExampleBuildReport) {
    auto wordsApi = getApi();
    auto requestReportEngineSettingsReportBuildOptions = std::make_shared< std::vector<std::shared_ptr<aspose::words::cloud::models::ReportBuildOptions>> >();
    requestReportEngineSettingsReportBuildOptions->push_back(std::make_shared< aspose::words::cloud::models::ReportBuildOptions >(aspose::words::cloud::models::ReportBuildOptions::ALLOW_MISSING_MEMBERS));
    requestReportEngineSettingsReportBuildOptions->push_back(std::make_shared< aspose::words::cloud::models::ReportBuildOptions >(aspose::words::cloud::models::ReportBuildOptions::REMOVE_EMPTY_PARAGRAPHS));
    auto requestReportEngineSettings = std::make_shared< aspose::words::cloud::models::ReportEngineSettings >();
    requestReportEngineSettings->setDataSourceType(std::make_shared< aspose::words::cloud::models::ReportEngineSettings::DataSourceType >(aspose::words::cloud::models::ReportEngineSettings::DataSourceType::JSON));
    requestReportEngineSettings->setReportBuildOptions(requestReportEngineSettingsReportBuildOptions);
    std::shared_ptr< requests::BuildReportRequest > buildReportRequest(
        new requests::BuildReportRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"Data.json"), requestReportEngineSettings
        )
    );
    wordsApi->buildReport(buildReportRequest);
}

TEST_F(ExamplesTest, TestExampleBuildReportOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestTemplate = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestReportEngineSettings = std::make_shared< aspose::words::cloud::models::ReportEngineSettings >();
    requestReportEngineSettings->setDataSourceType(std::make_shared< aspose::words::cloud::models::ReportEngineSettings::DataSourceType >(aspose::words::cloud::models::ReportEngineSettings::DataSourceType::JSON));
    requestReportEngineSettings->setDataSourceName(std::make_shared< std::wstring >(L"persons"));
    std::shared_ptr< requests::BuildReportOnlineRequest > buildReportRequest(
        new requests::BuildReportOnlineRequest(
            requestTemplate, std::make_shared< std::wstring >(L"Data.json"), requestReportEngineSettings
        )
    );
    wordsApi->buildReportOnline(buildReportRequest);
}

TEST_F(ExamplesTest, TestExampleClassify) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::ClassifyRequest > classifyRequest(
        new requests::ClassifyRequest(
            std::make_shared< std::wstring >(L"Try text classification"), std::make_shared< std::wstring >(L"3")
        )
    );
    wordsApi->classify(classifyRequest);
}

TEST_F(ExamplesTest, TestExampleClassifyDocument) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::ClassifyDocumentRequest > classifyRequest(
        new requests::ClassifyDocumentRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"3")
        )
    );
    wordsApi->classifyDocument(classifyRequest);
}

TEST_F(ExamplesTest, TestExampleClassifyDocumentOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::ClassifyDocumentOnlineRequest > classifyRequest(
        new requests::ClassifyDocumentOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"3")
        )
    );
    wordsApi->classifyDocumentOnline(classifyRequest);
}

TEST_F(ExamplesTest, TestExampleCompareDocument) {
    auto wordsApi = getApi();
    auto requestCompareData = std::make_shared< aspose::words::cloud::models::CompareData >();
    requestCompareData->setAuthor(std::make_shared< std::wstring >(L"author"));
    requestCompareData->setComparingWithDocument(std::make_shared< std::wstring >(L"TestCompareDocument2.doc"));
    requestCompareData->setDateTime(std::make_shared< std::wstring >(L"2015-10-26T00:00:00.0000000Z"));
    std::shared_ptr< requests::CompareDocumentRequest > compareRequest(
        new requests::CompareDocumentRequest(
            std::make_shared< std::wstring >(L"TestCompareDocument1.doc"), requestCompareData, std::make_shared< std::wstring >(L"/TestCompareDocumentOut.doc")
        )
    );
    wordsApi->compareDocument(compareRequest);
}

TEST_F(ExamplesTest, TestExampleCompareDocumentOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"compareTestDoc1.doc"), std::istream::binary));
    auto requestCompareData = std::make_shared< aspose::words::cloud::models::CompareData >();
    requestCompareData->setAuthor(std::make_shared< std::wstring >(L"author"));
    requestCompareData->setComparingWithDocument(std::make_shared< std::wstring >(L"TestCompareDocument2.doc"));
    requestCompareData->setDateTime(std::make_shared< std::wstring >(L"2015-10-26T00:00:00.0000000Z"));
    auto requestComparingDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"compareTestDoc2.doc"), std::istream::binary));
    std::shared_ptr< requests::CompareDocumentOnlineRequest > compareRequest(
        new requests::CompareDocumentOnlineRequest(
            requestDocument, requestCompareData, requestComparingDocument, std::make_shared< std::wstring >(L"/TestCompareDocumentOut.doc")
        )
    );
    wordsApi->compareDocumentOnline(compareRequest);
}

TEST_F(ExamplesTest, TestExampleConvertDocument) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::ConvertDocumentRequest > convertRequest(
        new requests::ConvertDocumentRequest(
            requestDocument, std::make_shared< std::wstring >(L"pdf")
        )
    );
    wordsApi->convertDocument(convertRequest);
}

TEST_F(ExamplesTest, TestExampleCopyFile) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::CopyFileRequest > copyRequest(
        new requests::CopyFileRequest(
            std::make_shared< std::wstring >(L"/TestCopyFileDest.docx"), std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->copyFile(copyRequest);
}

TEST_F(ExamplesTest, TestExampleCopyFolder) {
    auto wordsApi = getApi();
    std::wstring folderToCopy = L"/TestCopyFolder";

    std::shared_ptr< requests::CopyFolderRequest > copyRequest(
        new requests::CopyFolderRequest(
            std::make_shared< std::wstring >(folderToCopy + L"Dest"), std::make_shared< std::wstring >(folderToCopy + L"Src")
        )
    );
    wordsApi->copyFolder(copyRequest);
}

TEST_F(ExamplesTest, TestExampleCopyStyle) {
    auto wordsApi = getApi();
    auto requestStyleCopy = std::make_shared< aspose::words::cloud::models::StyleCopy >();
    requestStyleCopy->setStyleName(std::make_shared< std::wstring >(L"Heading 1"));
    std::shared_ptr< requests::CopyStyleRequest > copyRequest(
        new requests::CopyStyleRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), requestStyleCopy
        )
    );
    wordsApi->copyStyle(copyRequest);
}

TEST_F(ExamplesTest, TestExampleCopyStyleOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestStyleCopy = std::make_shared< aspose::words::cloud::models::StyleCopy >();
    requestStyleCopy->setStyleName(std::make_shared< std::wstring >(L"Heading 1"));
    std::shared_ptr< requests::CopyStyleOnlineRequest > copyRequest(
        new requests::CopyStyleOnlineRequest(
            requestDocument, requestStyleCopy
        )
    );
    wordsApi->copyStyleOnline(copyRequest);
}

TEST_F(ExamplesTest, TestExampleCreateDocument) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::CreateDocumentRequest > createRequest(
        new requests::CreateDocumentRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->createDocument(createRequest);
}

TEST_F(ExamplesTest, TestExampleCreateFolder) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::CreateFolderRequest > createRequest(
        new requests::CreateFolderRequest(
            std::make_shared< std::wstring >(L"/TestCreateFolder")
        )
    );
    wordsApi->createFolder(createRequest);
}

TEST_F(ExamplesTest, TestExampleCreateOrUpdateDocumentProperty) {
    auto wordsApi = getApi();
    auto requestProperty = std::make_shared< aspose::words::cloud::models::DocumentPropertyCreateOrUpdate >();
    requestProperty->setValue(std::make_shared< std::wstring >(L"Imran Anwar"));
    std::shared_ptr< requests::CreateOrUpdateDocumentPropertyRequest > createRequest(
        new requests::CreateOrUpdateDocumentPropertyRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"AsposeAuthor"), requestProperty
        )
    );
    wordsApi->createOrUpdateDocumentProperty(createRequest);
}

TEST_F(ExamplesTest, TestExampleCreateOrUpdateDocumentPropertyOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestProperty = std::make_shared< aspose::words::cloud::models::DocumentPropertyCreateOrUpdate >();
    requestProperty->setValue(std::make_shared< std::wstring >(L"Imran Anwar"));
    std::shared_ptr< requests::CreateOrUpdateDocumentPropertyOnlineRequest > createRequest(
        new requests::CreateOrUpdateDocumentPropertyOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"AsposeAuthor"), requestProperty
        )
    );
    wordsApi->createOrUpdateDocumentPropertyOnline(createRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteAllParagraphTabStops) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteAllParagraphTabStopsRequest > deleteRequest(
        new requests::DeleteAllParagraphTabStopsRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteAllParagraphTabStops(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteAllParagraphTabStopsOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::DeleteAllParagraphTabStopsOnlineRequest > deleteRequest(
        new requests::DeleteAllParagraphTabStopsOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteAllParagraphTabStopsOnline(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteBorder) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteBorderRequest > deleteRequest(
        new requests::DeleteBorderRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"left"), std::make_shared< std::wstring >(L"tables/1/rows/0/cells/0")
        )
    );
    wordsApi->deleteBorder(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteBorderOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::DeleteBorderOnlineRequest > deleteRequest(
        new requests::DeleteBorderOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"left"), std::make_shared< std::wstring >(L"tables/1/rows/0/cells/0")
        )
    );
    wordsApi->deleteBorderOnline(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteBorders) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteBordersRequest > deleteRequest(
        new requests::DeleteBordersRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"tables/1/rows/0/cells/0")
        )
    );
    wordsApi->deleteBorders(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteBordersOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::DeleteBordersOnlineRequest > deleteRequest(
        new requests::DeleteBordersOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"tables/1/rows/0/cells/0")
        )
    );
    wordsApi->deleteBordersOnline(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteComment) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteCommentRequest > deleteRequest(
        new requests::DeleteCommentRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteComment(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteCommentOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::DeleteCommentOnlineRequest > deleteRequest(
        new requests::DeleteCommentOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteCommentOnline(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteComments) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteCommentsRequest > deleteRequest(
        new requests::DeleteCommentsRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->deleteComments(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteCommentsOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::DeleteCommentsOnlineRequest > deleteRequest(
        new requests::DeleteCommentsOnlineRequest(
            requestDocument
        )
    );
    wordsApi->deleteCommentsOnline(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteCustomXmlPart) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteCustomXmlPartRequest > deleteRequest(
        new requests::DeleteCustomXmlPartRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteCustomXmlPart(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteCustomXmlPartOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::DeleteCustomXmlPartOnlineRequest > deleteRequest(
        new requests::DeleteCustomXmlPartOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteCustomXmlPartOnline(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteCustomXmlParts) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteCustomXmlPartsRequest > deleteRequest(
        new requests::DeleteCustomXmlPartsRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->deleteCustomXmlParts(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteCustomXmlPartsOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::DeleteCustomXmlPartsOnlineRequest > deleteRequest(
        new requests::DeleteCustomXmlPartsOnlineRequest(
            requestDocument
        )
    );
    wordsApi->deleteCustomXmlPartsOnline(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteDocumentProperty) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteDocumentPropertyRequest > deleteRequest(
        new requests::DeleteDocumentPropertyRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"testProp")
        )
    );
    wordsApi->deleteDocumentProperty(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteDocumentPropertyOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::DeleteDocumentPropertyOnlineRequest > deleteRequest(
        new requests::DeleteDocumentPropertyOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"testProp")
        )
    );
    wordsApi->deleteDocumentPropertyOnline(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteDrawingObject) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteDrawingObjectRequest > deleteRequest(
        new requests::DeleteDrawingObjectRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteDrawingObject(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteDrawingObjectOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::DeleteDrawingObjectOnlineRequest > deleteRequest(
        new requests::DeleteDrawingObjectOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteDrawingObjectOnline(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteField) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteFieldRequest > deleteRequest(
        new requests::DeleteFieldRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteField(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteFieldOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::DeleteFieldOnlineRequest > deleteRequest(
        new requests::DeleteFieldOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0), std::make_shared< std::wstring >(L"sections/0/paragraphs/0")
        )
    );
    wordsApi->deleteFieldOnline(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteFields) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteFieldsRequest > deleteRequest(
        new requests::DeleteFieldsRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->deleteFields(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteFieldsOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::DeleteFieldsOnlineRequest > deleteRequest(
        new requests::DeleteFieldsOnlineRequest(
            requestDocument
        )
    );
    wordsApi->deleteFieldsOnline(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteFile) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteFileRequest > deleteRequest(
        new requests::DeleteFileRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->deleteFile(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteFolder) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteFolderRequest > deleteRequest(
        new requests::DeleteFolderRequest(
            std::make_shared< std::wstring >(L"")
        )
    );
    wordsApi->deleteFolder(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteFootnote) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteFootnoteRequest > deleteRequest(
        new requests::DeleteFootnoteRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteFootnote(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteFootnoteOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
    std::shared_ptr< requests::DeleteFootnoteOnlineRequest > deleteRequest(
        new requests::DeleteFootnoteOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteFootnoteOnline(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteFormField) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteFormFieldRequest > deleteRequest(
        new requests::DeleteFormFieldRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteFormField(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteFormFieldOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::DeleteFormFieldOnlineRequest > deleteRequest(
        new requests::DeleteFormFieldOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0), std::make_shared< std::wstring >(L"sections/0")
        )
    );
    wordsApi->deleteFormFieldOnline(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteHeaderFooter) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteHeaderFooterRequest > deleteRequest(
        new requests::DeleteHeaderFooterRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L""), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteHeaderFooter(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteHeaderFooterOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
    std::shared_ptr< requests::DeleteHeaderFooterOnlineRequest > deleteRequest(
        new requests::DeleteHeaderFooterOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L""), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteHeaderFooterOnline(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteHeadersFooters) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteHeadersFootersRequest > deleteRequest(
        new requests::DeleteHeadersFootersRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"")
        )
    );
    wordsApi->deleteHeadersFooters(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteHeadersFootersOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
    std::shared_ptr< requests::DeleteHeadersFootersOnlineRequest > deleteRequest(
        new requests::DeleteHeadersFootersOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"")
        )
    );
    wordsApi->deleteHeadersFootersOnline(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteMacros) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteMacrosRequest > deleteRequest(
        new requests::DeleteMacrosRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->deleteMacros(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteMacrosOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::DeleteMacrosOnlineRequest > deleteRequest(
        new requests::DeleteMacrosOnlineRequest(
            requestDocument
        )
    );
    wordsApi->deleteMacrosOnline(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteOfficeMathObject) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteOfficeMathObjectRequest > deleteRequest(
        new requests::DeleteOfficeMathObjectRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteOfficeMathObject(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteOfficeMathObjectOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::DeleteOfficeMathObjectOnlineRequest > deleteRequest(
        new requests::DeleteOfficeMathObjectOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteOfficeMathObjectOnline(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteParagraph) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteParagraphRequest > deleteRequest(
        new requests::DeleteParagraphRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteParagraph(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteParagraphListFormat) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteParagraphListFormatRequest > deleteRequest(
        new requests::DeleteParagraphListFormatRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteParagraphListFormat(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteParagraphListFormatOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
    std::shared_ptr< requests::DeleteParagraphListFormatOnlineRequest > deleteRequest(
        new requests::DeleteParagraphListFormatOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteParagraphListFormatOnline(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteParagraphOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::DeleteParagraphOnlineRequest > deleteRequest(
        new requests::DeleteParagraphOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteParagraphOnline(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteParagraphTabStop) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteParagraphTabStopRequest > deleteRequest(
        new requests::DeleteParagraphTabStopRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< double >(72.0), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteParagraphTabStop(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteParagraphTabStopOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::DeleteParagraphTabStopOnlineRequest > deleteRequest(
        new requests::DeleteParagraphTabStopOnlineRequest(
            requestDocument, std::make_shared< double >(72.0), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteParagraphTabStopOnline(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteRun) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteRunRequest > deleteRequest(
        new requests::DeleteRunRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"paragraphs/1"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteRun(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteRunOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
    std::shared_ptr< requests::DeleteRunOnlineRequest > deleteRequest(
        new requests::DeleteRunOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"paragraphs/1"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteRunOnline(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteSection) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteSectionRequest > deleteRequest(
        new requests::DeleteSectionRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteSection(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteSectionOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::DeleteSectionOnlineRequest > deleteRequest(
        new requests::DeleteSectionOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteSectionOnline(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteTable) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteTableRequest > deleteRequest(
        new requests::DeleteTableRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(1)
        )
    );
    wordsApi->deleteTable(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteTableCell) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteTableCellRequest > deleteRequest(
        new requests::DeleteTableCellRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"sections/0/tables/2/rows/0"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteTableCell(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteTableCellOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::DeleteTableCellOnlineRequest > deleteRequest(
        new requests::DeleteTableCellOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"sections/0/tables/2/rows/0"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteTableCellOnline(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteTableOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::DeleteTableOnlineRequest > deleteRequest(
        new requests::DeleteTableOnlineRequest(
            requestDocument, std::make_shared< int32_t >(1)
        )
    );
    wordsApi->deleteTableOnline(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteTableRow) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteTableRowRequest > deleteRequest(
        new requests::DeleteTableRowRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"tables/1"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteTableRow(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteTableRowOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::DeleteTableRowOnlineRequest > deleteRequest(
        new requests::DeleteTableRowOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"tables/1"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->deleteTableRowOnline(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteWatermark) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DeleteWatermarkRequest > deleteRequest(
        new requests::DeleteWatermarkRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->deleteWatermark(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDeleteWatermarkOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::DeleteWatermarkOnlineRequest > deleteRequest(
        new requests::DeleteWatermarkOnlineRequest(
            requestDocument
        )
    );
    wordsApi->deleteWatermarkOnline(deleteRequest);
}

TEST_F(ExamplesTest, TestExampleDownloadFile) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::DownloadFileRequest > downloadRequest(
        new requests::DownloadFileRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->downloadFile(downloadRequest);
}

TEST_F(ExamplesTest, TestExampleExecuteMailMerge) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::ExecuteMailMergeRequest > mailMergeRequest(
        new requests::ExecuteMailMergeRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"TestExecuteTemplateData.txt")
        )
    );
    wordsApi->executeMailMerge(mailMergeRequest);
}

TEST_F(ExamplesTest, TestExampleExecuteMailMergeOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestTemplate = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"TestExecuteTemplate.doc"), std::istream::binary));
    auto requestData = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"TestExecuteTemplateData.txt"), std::istream::binary));
    std::shared_ptr< requests::ExecuteMailMergeOnlineRequest > mailMergeRequest(
        new requests::ExecuteMailMergeOnlineRequest(
            requestTemplate, requestData
        )
    );
    wordsApi->executeMailMergeOnline(mailMergeRequest);
}

TEST_F(ExamplesTest, TestExampleGetAvailableFonts) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetAvailableFontsRequest > request(
        new requests::GetAvailableFontsRequest(
        )
    );
    wordsApi->getAvailableFonts(request);
}

TEST_F(ExamplesTest, TestExampleGetBookmarkByName) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetBookmarkByNameRequest > request(
        new requests::GetBookmarkByNameRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"aspose")
        )
    );
    wordsApi->getBookmarkByName(request);
}

TEST_F(ExamplesTest, TestExampleGetBookmarkByNameOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetBookmarkByNameOnlineRequest > request(
        new requests::GetBookmarkByNameOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"aspose")
        )
    );
    wordsApi->getBookmarkByNameOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetBookmarks) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetBookmarksRequest > request(
        new requests::GetBookmarksRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->getBookmarks(request);
}

TEST_F(ExamplesTest, TestExampleGetBookmarksOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetBookmarksOnlineRequest > request(
        new requests::GetBookmarksOnlineRequest(
            requestDocument
        )
    );
    wordsApi->getBookmarksOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetBorder) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetBorderRequest > request(
        new requests::GetBorderRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"left"), std::make_shared< std::wstring >(L"tables/1/rows/0/cells/0")
        )
    );
    wordsApi->getBorder(request);
}

TEST_F(ExamplesTest, TestExampleGetBorderOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetBorderOnlineRequest > request(
        new requests::GetBorderOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"left"), std::make_shared< std::wstring >(L"tables/1/rows/0/cells/0")
        )
    );
    wordsApi->getBorderOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetBorders) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetBordersRequest > request(
        new requests::GetBordersRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"tables/1/rows/0/cells/0")
        )
    );
    wordsApi->getBorders(request);
}

TEST_F(ExamplesTest, TestExampleGetBordersOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetBordersOnlineRequest > request(
        new requests::GetBordersOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"tables/1/rows/0/cells/0")
        )
    );
    wordsApi->getBordersOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetComment) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetCommentRequest > request(
        new requests::GetCommentRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getComment(request);
}

TEST_F(ExamplesTest, TestExampleGetCommentOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetCommentOnlineRequest > request(
        new requests::GetCommentOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getCommentOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetComments) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetCommentsRequest > request(
        new requests::GetCommentsRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->getComments(request);
}

TEST_F(ExamplesTest, TestExampleGetCommentsOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetCommentsOnlineRequest > request(
        new requests::GetCommentsOnlineRequest(
            requestDocument
        )
    );
    wordsApi->getCommentsOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetCustomXmlPart) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetCustomXmlPartRequest > request(
        new requests::GetCustomXmlPartRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getCustomXmlPart(request);
}

TEST_F(ExamplesTest, TestExampleGetCustomXmlPartOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetCustomXmlPartOnlineRequest > request(
        new requests::GetCustomXmlPartOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getCustomXmlPartOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetCustomXmlParts) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetCustomXmlPartsRequest > request(
        new requests::GetCustomXmlPartsRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->getCustomXmlParts(request);
}

TEST_F(ExamplesTest, TestExampleGetCustomXmlPartsOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetCustomXmlPartsOnlineRequest > request(
        new requests::GetCustomXmlPartsOnlineRequest(
            requestDocument
        )
    );
    wordsApi->getCustomXmlPartsOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetDocument) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetDocumentRequest > request(
        new requests::GetDocumentRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->getDocument(request);
}

TEST_F(ExamplesTest, TestExampleGetDocumentDrawingObjectByIndex) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetDocumentDrawingObjectByIndexRequest > request(
        new requests::GetDocumentDrawingObjectByIndexRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getDocumentDrawingObjectByIndex(request);
}

TEST_F(ExamplesTest, TestExampleGetDocumentDrawingObjectByIndexOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetDocumentDrawingObjectByIndexOnlineRequest > request(
        new requests::GetDocumentDrawingObjectByIndexOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0), std::make_shared< std::wstring >(L"sections/0")
        )
    );
    wordsApi->getDocumentDrawingObjectByIndexOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetDocumentDrawingObjectImageData) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetDocumentDrawingObjectImageDataRequest > request(
        new requests::GetDocumentDrawingObjectImageDataRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getDocumentDrawingObjectImageData(request);
}

TEST_F(ExamplesTest, TestExampleGetDocumentDrawingObjectImageDataOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetDocumentDrawingObjectImageDataOnlineRequest > request(
        new requests::GetDocumentDrawingObjectImageDataOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0), std::make_shared< std::wstring >(L"sections/0")
        )
    );
    wordsApi->getDocumentDrawingObjectImageDataOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetDocumentDrawingObjectOleData) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetDocumentDrawingObjectOleDataRequest > request(
        new requests::GetDocumentDrawingObjectOleDataRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getDocumentDrawingObjectOleData(request);
}

TEST_F(ExamplesTest, TestExampleGetDocumentDrawingObjectOleDataOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetDocumentDrawingObjectOleDataOnlineRequest > request(
        new requests::GetDocumentDrawingObjectOleDataOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0), std::make_shared< std::wstring >(L"sections/0")
        )
    );
    wordsApi->getDocumentDrawingObjectOleDataOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetDocumentDrawingObjects) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetDocumentDrawingObjectsRequest > request(
        new requests::GetDocumentDrawingObjectsRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->getDocumentDrawingObjects(request);
}

TEST_F(ExamplesTest, TestExampleGetDocumentDrawingObjectsOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetDocumentDrawingObjectsOnlineRequest > request(
        new requests::GetDocumentDrawingObjectsOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"sections/0")
        )
    );
    wordsApi->getDocumentDrawingObjectsOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetDocumentFieldNames) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetDocumentFieldNamesRequest > request(
        new requests::GetDocumentFieldNamesRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->getDocumentFieldNames(request);
}

TEST_F(ExamplesTest, TestExampleGetDocumentFieldNamesOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestTemplate = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetDocumentFieldNamesOnlineRequest > request(
        new requests::GetDocumentFieldNamesOnlineRequest(
            requestTemplate, std::make_shared< bool >(true)
        )
    );
    wordsApi->getDocumentFieldNamesOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetDocumentHyperlinkByIndex) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetDocumentHyperlinkByIndexRequest > request(
        new requests::GetDocumentHyperlinkByIndexRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getDocumentHyperlinkByIndex(request);
}

TEST_F(ExamplesTest, TestExampleGetDocumentHyperlinkByIndexOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetDocumentHyperlinkByIndexOnlineRequest > request(
        new requests::GetDocumentHyperlinkByIndexOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getDocumentHyperlinkByIndexOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetDocumentHyperlinks) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetDocumentHyperlinksRequest > request(
        new requests::GetDocumentHyperlinksRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->getDocumentHyperlinks(request);
}

TEST_F(ExamplesTest, TestExampleGetDocumentHyperlinksOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetDocumentHyperlinksOnlineRequest > request(
        new requests::GetDocumentHyperlinksOnlineRequest(
            requestDocument
        )
    );
    wordsApi->getDocumentHyperlinksOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetDocumentProperties) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetDocumentPropertiesRequest > request(
        new requests::GetDocumentPropertiesRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->getDocumentProperties(request);
}

TEST_F(ExamplesTest, TestExampleGetDocumentPropertiesOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetDocumentPropertiesOnlineRequest > request(
        new requests::GetDocumentPropertiesOnlineRequest(
            requestDocument
        )
    );
    wordsApi->getDocumentPropertiesOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetDocumentProperty) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetDocumentPropertyRequest > request(
        new requests::GetDocumentPropertyRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"Author")
        )
    );
    wordsApi->getDocumentProperty(request);
}

TEST_F(ExamplesTest, TestExampleGetDocumentPropertyOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetDocumentPropertyOnlineRequest > request(
        new requests::GetDocumentPropertyOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"Author")
        )
    );
    wordsApi->getDocumentPropertyOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetDocumentProtection) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetDocumentProtectionRequest > request(
        new requests::GetDocumentProtectionRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->getDocumentProtection(request);
}

TEST_F(ExamplesTest, TestExampleGetDocumentProtectionOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetDocumentProtectionOnlineRequest > request(
        new requests::GetDocumentProtectionOnlineRequest(
            requestDocument
        )
    );
    wordsApi->getDocumentProtectionOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetDocumentStatistics) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetDocumentStatisticsRequest > request(
        new requests::GetDocumentStatisticsRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->getDocumentStatistics(request);
}

TEST_F(ExamplesTest, TestExampleGetDocumentStatisticsOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetDocumentStatisticsOnlineRequest > request(
        new requests::GetDocumentStatisticsOnlineRequest(
            requestDocument
        )
    );
    wordsApi->getDocumentStatisticsOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetDocumentWithFormat) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetDocumentWithFormatRequest > request(
        new requests::GetDocumentWithFormatRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"text"), std::make_shared< std::wstring >(L"/TestGetDocumentWithFormatAndOutPath.text")
        )
    );
    wordsApi->getDocumentWithFormat(request);
}

TEST_F(ExamplesTest, TestExampleGetField) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetFieldRequest > request(
        new requests::GetFieldRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getField(request);
}

TEST_F(ExamplesTest, TestExampleGetFieldOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetFieldOnlineRequest > request(
        new requests::GetFieldOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0), std::make_shared< std::wstring >(L"sections/0/paragraphs/0")
        )
    );
    wordsApi->getFieldOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetFields) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetFieldsRequest > request(
        new requests::GetFieldsRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->getFields(request);
}

TEST_F(ExamplesTest, TestExampleGetFieldsOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetFieldsOnlineRequest > request(
        new requests::GetFieldsOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"sections/0")
        )
    );
    wordsApi->getFieldsOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetFilesList) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetFilesListRequest > request(
        new requests::GetFilesListRequest(
            std::make_shared< std::wstring >(L"")
        )
    );
    wordsApi->getFilesList(request);
}

TEST_F(ExamplesTest, TestExampleGetFootnote) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetFootnoteRequest > request(
        new requests::GetFootnoteRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getFootnote(request);
}

TEST_F(ExamplesTest, TestExampleGetFootnoteOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
    std::shared_ptr< requests::GetFootnoteOnlineRequest > request(
        new requests::GetFootnoteOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getFootnoteOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetFootnotes) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetFootnotesRequest > request(
        new requests::GetFootnotesRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->getFootnotes(request);
}

TEST_F(ExamplesTest, TestExampleGetFootnotesOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
    std::shared_ptr< requests::GetFootnotesOnlineRequest > request(
        new requests::GetFootnotesOnlineRequest(
            requestDocument
        )
    );
    wordsApi->getFootnotesOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetFormField) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetFormFieldRequest > request(
        new requests::GetFormFieldRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getFormField(request);
}

TEST_F(ExamplesTest, TestExampleGetFormFieldOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetFormFieldOnlineRequest > request(
        new requests::GetFormFieldOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0), std::make_shared< std::wstring >(L"sections/0")
        )
    );
    wordsApi->getFormFieldOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetFormFields) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetFormFieldsRequest > request(
        new requests::GetFormFieldsRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->getFormFields(request);
}

TEST_F(ExamplesTest, TestExampleGetFormFieldsOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetFormFieldsOnlineRequest > request(
        new requests::GetFormFieldsOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"sections/0")
        )
    );
    wordsApi->getFormFieldsOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetHeaderFooter) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetHeaderFooterRequest > request(
        new requests::GetHeaderFooterRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getHeaderFooter(request);
}

TEST_F(ExamplesTest, TestExampleGetHeaderFooterOfSection) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetHeaderFooterOfSectionRequest > request(
        new requests::GetHeaderFooterOfSectionRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getHeaderFooterOfSection(request);
}

TEST_F(ExamplesTest, TestExampleGetHeaderFooterOfSectionOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
    std::shared_ptr< requests::GetHeaderFooterOfSectionOnlineRequest > request(
        new requests::GetHeaderFooterOfSectionOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getHeaderFooterOfSectionOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetHeaderFooterOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
    std::shared_ptr< requests::GetHeaderFooterOnlineRequest > request(
        new requests::GetHeaderFooterOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getHeaderFooterOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetHeaderFooters) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetHeaderFootersRequest > request(
        new requests::GetHeaderFootersRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"")
        )
    );
    wordsApi->getHeaderFooters(request);
}

TEST_F(ExamplesTest, TestExampleGetHeaderFootersOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
    std::shared_ptr< requests::GetHeaderFootersOnlineRequest > request(
        new requests::GetHeaderFootersOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"")
        )
    );
    wordsApi->getHeaderFootersOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetList) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetListRequest > request(
        new requests::GetListRequest(
            std::make_shared< std::wstring >(L"TestGetLists.doc"), std::make_shared< int32_t >(1)
        )
    );
    wordsApi->getList(request);
}

TEST_F(ExamplesTest, TestExampleGetListOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
    std::shared_ptr< requests::GetListOnlineRequest > request(
        new requests::GetListOnlineRequest(
            requestDocument, std::make_shared< int32_t >(1)
        )
    );
    wordsApi->getListOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetLists) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetListsRequest > request(
        new requests::GetListsRequest(
            std::make_shared< std::wstring >(L"TestGetLists.doc")
        )
    );
    wordsApi->getLists(request);
}

TEST_F(ExamplesTest, TestExampleGetListsOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
    std::shared_ptr< requests::GetListsOnlineRequest > request(
        new requests::GetListsOnlineRequest(
            requestDocument
        )
    );
    wordsApi->getListsOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetOfficeMathObject) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetOfficeMathObjectRequest > request(
        new requests::GetOfficeMathObjectRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getOfficeMathObject(request);
}

TEST_F(ExamplesTest, TestExampleGetOfficeMathObjectOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetOfficeMathObjectOnlineRequest > request(
        new requests::GetOfficeMathObjectOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getOfficeMathObjectOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetOfficeMathObjects) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetOfficeMathObjectsRequest > request(
        new requests::GetOfficeMathObjectsRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->getOfficeMathObjects(request);
}

TEST_F(ExamplesTest, TestExampleGetOfficeMathObjectsOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetOfficeMathObjectsOnlineRequest > request(
        new requests::GetOfficeMathObjectsOnlineRequest(
            requestDocument
        )
    );
    wordsApi->getOfficeMathObjectsOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetParagraph) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetParagraphRequest > request(
        new requests::GetParagraphRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getParagraph(request);
}

TEST_F(ExamplesTest, TestExampleGetParagraphFormat) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetParagraphFormatRequest > request(
        new requests::GetParagraphFormatRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getParagraphFormat(request);
}

TEST_F(ExamplesTest, TestExampleGetParagraphFormatOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetParagraphFormatOnlineRequest > request(
        new requests::GetParagraphFormatOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getParagraphFormatOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetParagraphListFormat) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetParagraphListFormatRequest > request(
        new requests::GetParagraphListFormatRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getParagraphListFormat(request);
}

TEST_F(ExamplesTest, TestExampleGetParagraphListFormatOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
    std::shared_ptr< requests::GetParagraphListFormatOnlineRequest > request(
        new requests::GetParagraphListFormatOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getParagraphListFormatOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetParagraphOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetParagraphOnlineRequest > request(
        new requests::GetParagraphOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0), std::make_shared< std::wstring >(L"sections/0")
        )
    );
    wordsApi->getParagraphOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetParagraphs) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetParagraphsRequest > request(
        new requests::GetParagraphsRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->getParagraphs(request);
}

TEST_F(ExamplesTest, TestExampleGetParagraphsOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetParagraphsOnlineRequest > request(
        new requests::GetParagraphsOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"sections/0")
        )
    );
    wordsApi->getParagraphsOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetParagraphTabStops) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetParagraphTabStopsRequest > request(
        new requests::GetParagraphTabStopsRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getParagraphTabStops(request);
}

TEST_F(ExamplesTest, TestExampleGetParagraphTabStopsOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetParagraphTabStopsOnlineRequest > request(
        new requests::GetParagraphTabStopsOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getParagraphTabStopsOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetPublicKey) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetPublicKeyRequest > request(
        new requests::GetPublicKeyRequest(
        )
    );
    wordsApi->getPublicKey(request);
}

TEST_F(ExamplesTest, TestExampleGetRangeText) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetRangeTextRequest > request(
        new requests::GetRangeTextRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"id0.0.0"), std::make_shared< std::wstring >(L"id0.0.1")
        )
    );
    wordsApi->getRangeText(request);
}

TEST_F(ExamplesTest, TestExampleGetRangeTextOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
    std::shared_ptr< requests::GetRangeTextOnlineRequest > request(
        new requests::GetRangeTextOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"id0.0.0"), std::make_shared< std::wstring >(L"id0.0.1")
        )
    );
    wordsApi->getRangeTextOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetRun) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetRunRequest > request(
        new requests::GetRunRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"paragraphs/0"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getRun(request);
}

TEST_F(ExamplesTest, TestExampleGetRunFont) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetRunFontRequest > request(
        new requests::GetRunFontRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"paragraphs/0"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getRunFont(request);
}

TEST_F(ExamplesTest, TestExampleGetRunFontOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetRunFontOnlineRequest > request(
        new requests::GetRunFontOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"paragraphs/0"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getRunFontOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetRunOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetRunOnlineRequest > request(
        new requests::GetRunOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"paragraphs/0"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getRunOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetRuns) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetRunsRequest > request(
        new requests::GetRunsRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"sections/0/paragraphs/0")
        )
    );
    wordsApi->getRuns(request);
}

TEST_F(ExamplesTest, TestExampleGetRunsOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetRunsOnlineRequest > request(
        new requests::GetRunsOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"sections/0/paragraphs/0")
        )
    );
    wordsApi->getRunsOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetSection) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetSectionRequest > request(
        new requests::GetSectionRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getSection(request);
}

TEST_F(ExamplesTest, TestExampleGetSectionOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetSectionOnlineRequest > request(
        new requests::GetSectionOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getSectionOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetSectionPageSetup) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetSectionPageSetupRequest > request(
        new requests::GetSectionPageSetupRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getSectionPageSetup(request);
}

TEST_F(ExamplesTest, TestExampleGetSectionPageSetupOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetSectionPageSetupOnlineRequest > request(
        new requests::GetSectionPageSetupOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getSectionPageSetupOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetSections) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetSectionsRequest > request(
        new requests::GetSectionsRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->getSections(request);
}

TEST_F(ExamplesTest, TestExampleGetSectionsOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetSectionsOnlineRequest > request(
        new requests::GetSectionsOnlineRequest(
            requestDocument
        )
    );
    wordsApi->getSectionsOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetStyle) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetStyleRequest > request(
        new requests::GetStyleRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"Heading 1")
        )
    );
    wordsApi->getStyle(request);
}

TEST_F(ExamplesTest, TestExampleGetStyleFromDocumentElement) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetStyleFromDocumentElementRequest > request(
        new requests::GetStyleFromDocumentElementRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"paragraphs/1/paragraphFormat")
        )
    );
    wordsApi->getStyleFromDocumentElement(request);
}

TEST_F(ExamplesTest, TestExampleGetStyleFromDocumentElementOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetStyleFromDocumentElementOnlineRequest > request(
        new requests::GetStyleFromDocumentElementOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"paragraphs/1/paragraphFormat")
        )
    );
    wordsApi->getStyleFromDocumentElementOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetStyleOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetStyleOnlineRequest > request(
        new requests::GetStyleOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"Heading 1")
        )
    );
    wordsApi->getStyleOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetStyles) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetStylesRequest > request(
        new requests::GetStylesRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->getStyles(request);
}

TEST_F(ExamplesTest, TestExampleGetStylesOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetStylesOnlineRequest > request(
        new requests::GetStylesOnlineRequest(
            requestDocument
        )
    );
    wordsApi->getStylesOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetTable) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetTableRequest > request(
        new requests::GetTableRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(1)
        )
    );
    wordsApi->getTable(request);
}

TEST_F(ExamplesTest, TestExampleGetTableCell) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetTableCellRequest > request(
        new requests::GetTableCellRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"sections/0/tables/2/rows/0"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getTableCell(request);
}

TEST_F(ExamplesTest, TestExampleGetTableCellFormat) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetTableCellFormatRequest > request(
        new requests::GetTableCellFormatRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"sections/0/tables/2/rows/0"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getTableCellFormat(request);
}

TEST_F(ExamplesTest, TestExampleGetTableCellFormatOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetTableCellFormatOnlineRequest > request(
        new requests::GetTableCellFormatOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"sections/0/tables/2/rows/0"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getTableCellFormatOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetTableCellOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetTableCellOnlineRequest > request(
        new requests::GetTableCellOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"sections/0/tables/2/rows/0"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getTableCellOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetTableOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetTableOnlineRequest > request(
        new requests::GetTableOnlineRequest(
            requestDocument, std::make_shared< int32_t >(1)
        )
    );
    wordsApi->getTableOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetTableProperties) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetTablePropertiesRequest > request(
        new requests::GetTablePropertiesRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(1)
        )
    );
    wordsApi->getTableProperties(request);
}

TEST_F(ExamplesTest, TestExampleGetTablePropertiesOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetTablePropertiesOnlineRequest > request(
        new requests::GetTablePropertiesOnlineRequest(
            requestDocument, std::make_shared< int32_t >(1)
        )
    );
    wordsApi->getTablePropertiesOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetTableRow) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetTableRowRequest > request(
        new requests::GetTableRowRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"tables/1"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getTableRow(request);
}

TEST_F(ExamplesTest, TestExampleGetTableRowFormat) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetTableRowFormatRequest > request(
        new requests::GetTableRowFormatRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"sections/0/tables/2"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getTableRowFormat(request);
}

TEST_F(ExamplesTest, TestExampleGetTableRowFormatOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetTableRowFormatOnlineRequest > request(
        new requests::GetTableRowFormatOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"sections/0/tables/2"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getTableRowFormatOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetTableRowOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetTableRowOnlineRequest > request(
        new requests::GetTableRowOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"tables/1"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->getTableRowOnline(request);
}

TEST_F(ExamplesTest, TestExampleGetTables) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::GetTablesRequest > request(
        new requests::GetTablesRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->getTables(request);
}

TEST_F(ExamplesTest, TestExampleGetTablesOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::GetTablesOnlineRequest > request(
        new requests::GetTablesOnlineRequest(
            requestDocument
        )
    );
    wordsApi->getTablesOnline(request);
}

TEST_F(ExamplesTest, TestExampleInsertComment) {
    auto wordsApi = getApi();
    auto requestCommentRangeStartNode = std::make_shared< aspose::words::cloud::models::NodeLink >();
    requestCommentRangeStartNode->setNodeId(std::make_shared< std::wstring >(L"0.3.0.3"));
    auto requestCommentRangeStart = std::make_shared< aspose::words::cloud::models::DocumentPosition >();
    requestCommentRangeStart->setNode(requestCommentRangeStartNode);
    requestCommentRangeStart->setOffset(std::make_shared< int32_t >(0));
    auto requestCommentRangeEndNode = std::make_shared< aspose::words::cloud::models::NodeLink >();
    requestCommentRangeEndNode->setNodeId(std::make_shared< std::wstring >(L"0.3.0.3"));
    auto requestCommentRangeEnd = std::make_shared< aspose::words::cloud::models::DocumentPosition >();
    requestCommentRangeEnd->setNode(requestCommentRangeEndNode);
    requestCommentRangeEnd->setOffset(std::make_shared< int32_t >(0));
    auto requestComment = std::make_shared< aspose::words::cloud::models::CommentInsert >();
    requestComment->setRangeStart(requestCommentRangeStart);
    requestComment->setRangeEnd(requestCommentRangeEnd);
    requestComment->setInitial(std::make_shared< std::wstring >(L"IA"));
    requestComment->setAuthor(std::make_shared< std::wstring >(L"Imran Anwar"));
    requestComment->setText(std::make_shared< std::wstring >(L"A new Comment"));
    std::shared_ptr< requests::InsertCommentRequest > insertRequest(
        new requests::InsertCommentRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), requestComment
        )
    );
    wordsApi->insertComment(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertCommentOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestCommentRangeStartNode = std::make_shared< aspose::words::cloud::models::NodeLink >();
    requestCommentRangeStartNode->setNodeId(std::make_shared< std::wstring >(L"0.3.0.3"));
    auto requestCommentRangeStart = std::make_shared< aspose::words::cloud::models::DocumentPosition >();
    requestCommentRangeStart->setNode(requestCommentRangeStartNode);
    requestCommentRangeStart->setOffset(std::make_shared< int32_t >(0));
    auto requestCommentRangeEndNode = std::make_shared< aspose::words::cloud::models::NodeLink >();
    requestCommentRangeEndNode->setNodeId(std::make_shared< std::wstring >(L"0.3.0.3"));
    auto requestCommentRangeEnd = std::make_shared< aspose::words::cloud::models::DocumentPosition >();
    requestCommentRangeEnd->setNode(requestCommentRangeEndNode);
    requestCommentRangeEnd->setOffset(std::make_shared< int32_t >(0));
    auto requestComment = std::make_shared< aspose::words::cloud::models::CommentInsert >();
    requestComment->setRangeStart(requestCommentRangeStart);
    requestComment->setRangeEnd(requestCommentRangeEnd);
    requestComment->setInitial(std::make_shared< std::wstring >(L"IA"));
    requestComment->setAuthor(std::make_shared< std::wstring >(L"Imran Anwar"));
    requestComment->setText(std::make_shared< std::wstring >(L"A new Comment"));
    std::shared_ptr< requests::InsertCommentOnlineRequest > insertRequest(
        new requests::InsertCommentOnlineRequest(
            requestDocument, requestComment
        )
    );
    wordsApi->insertCommentOnline(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertCustomXmlPart) {
    auto wordsApi = getApi();
    auto requestCustomXmlPart = std::make_shared< aspose::words::cloud::models::CustomXmlPartInsert >();
    requestCustomXmlPart->setId(std::make_shared< std::wstring >(L"hello"));
    requestCustomXmlPart->setData(std::make_shared< std::wstring >(L"<data>Hello world</data>"));
    std::shared_ptr< requests::InsertCustomXmlPartRequest > insertRequest(
        new requests::InsertCustomXmlPartRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), requestCustomXmlPart
        )
    );
    wordsApi->insertCustomXmlPart(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertCustomXmlPartOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestCustomXmlPart = std::make_shared< aspose::words::cloud::models::CustomXmlPartInsert >();
    requestCustomXmlPart->setId(std::make_shared< std::wstring >(L"hello"));
    requestCustomXmlPart->setData(std::make_shared< std::wstring >(L"<data>Hello world</data>"));
    std::shared_ptr< requests::InsertCustomXmlPartOnlineRequest > insertRequest(
        new requests::InsertCustomXmlPartOnlineRequest(
            requestDocument, requestCustomXmlPart
        )
    );
    wordsApi->insertCustomXmlPartOnline(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertDrawingObject) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDrawingObject = std::make_shared< aspose::words::cloud::models::DrawingObjectInsert >();
    requestDrawingObject->setHeight(std::make_shared< double >(0));
    requestDrawingObject->setLeft(std::make_shared< double >(0));
    requestDrawingObject->setTop(std::make_shared< double >(0));
    requestDrawingObject->setWidth(std::make_shared< double >(0));
    requestDrawingObject->setRelativeHorizontalPosition(std::make_shared< aspose::words::cloud::models::DrawingObjectInsert::RelativeHorizontalPosition >(aspose::words::cloud::models::DrawingObjectInsert::RelativeHorizontalPosition::MARGIN));
    requestDrawingObject->setRelativeVerticalPosition(std::make_shared< aspose::words::cloud::models::DrawingObjectInsert::RelativeVerticalPosition >(aspose::words::cloud::models::DrawingObjectInsert::RelativeVerticalPosition::MARGIN));
    requestDrawingObject->setWrapType(std::make_shared< aspose::words::cloud::models::DrawingObjectInsert::WrapType >(aspose::words::cloud::models::DrawingObjectInsert::WrapType::INLINE));
    auto requestImageFile = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Common/aspose-cloud.png"), std::istream::binary));
    std::shared_ptr< requests::InsertDrawingObjectRequest > insertRequest(
        new requests::InsertDrawingObjectRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), requestDrawingObject, requestImageFile
        )
    );
    wordsApi->insertDrawingObject(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertDrawingObjectOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestDrawingObject = std::make_shared< aspose::words::cloud::models::DrawingObjectInsert >();
    requestDrawingObject->setHeight(std::make_shared< double >(0));
    requestDrawingObject->setLeft(std::make_shared< double >(0));
    requestDrawingObject->setTop(std::make_shared< double >(0));
    requestDrawingObject->setWidth(std::make_shared< double >(0));
    requestDrawingObject->setRelativeHorizontalPosition(std::make_shared< aspose::words::cloud::models::DrawingObjectInsert::RelativeHorizontalPosition >(aspose::words::cloud::models::DrawingObjectInsert::RelativeHorizontalPosition::MARGIN));
    requestDrawingObject->setRelativeVerticalPosition(std::make_shared< aspose::words::cloud::models::DrawingObjectInsert::RelativeVerticalPosition >(aspose::words::cloud::models::DrawingObjectInsert::RelativeVerticalPosition::MARGIN));
    requestDrawingObject->setWrapType(std::make_shared< aspose::words::cloud::models::DrawingObjectInsert::WrapType >(aspose::words::cloud::models::DrawingObjectInsert::WrapType::INLINE));
    auto requestImageFile = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Common/aspose-cloud.png"), std::istream::binary));
    std::shared_ptr< requests::InsertDrawingObjectOnlineRequest > insertRequest(
        new requests::InsertDrawingObjectOnlineRequest(
            requestDocument, requestDrawingObject, requestImageFile
        )
    );
    wordsApi->insertDrawingObjectOnline(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertField) {
    auto wordsApi = getApi();
    auto requestField = std::make_shared< aspose::words::cloud::models::FieldInsert >();
    requestField->setFieldCode(std::make_shared< std::wstring >(L"{ NUMPAGES }"));
    std::shared_ptr< requests::InsertFieldRequest > insertRequest(
        new requests::InsertFieldRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), requestField
        )
    );
    wordsApi->insertField(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertFieldOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestField = std::make_shared< aspose::words::cloud::models::FieldInsert >();
    requestField->setFieldCode(std::make_shared< std::wstring >(L"{ NUMPAGES }"));
    std::shared_ptr< requests::InsertFieldOnlineRequest > insertRequest(
        new requests::InsertFieldOnlineRequest(
            requestDocument, requestField, std::make_shared< std::wstring >(L"sections/0/paragraphs/0")
        )
    );
    wordsApi->insertFieldOnline(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertFootnote) {
    auto wordsApi = getApi();
    auto requestFootnoteDto = std::make_shared< aspose::words::cloud::models::FootnoteInsert >();
    requestFootnoteDto->setFootnoteType(std::make_shared< aspose::words::cloud::models::FootnoteBase::FootnoteType >(aspose::words::cloud::models::FootnoteBase::FootnoteType::ENDNOTE));
    requestFootnoteDto->setText(std::make_shared< std::wstring >(L"test endnote"));
    std::shared_ptr< requests::InsertFootnoteRequest > insertRequest(
        new requests::InsertFootnoteRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), requestFootnoteDto
        )
    );
    wordsApi->insertFootnote(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertFootnoteOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
    auto requestFootnoteDto = std::make_shared< aspose::words::cloud::models::FootnoteInsert >();
    requestFootnoteDto->setFootnoteType(std::make_shared< aspose::words::cloud::models::FootnoteBase::FootnoteType >(aspose::words::cloud::models::FootnoteBase::FootnoteType::ENDNOTE));
    requestFootnoteDto->setText(std::make_shared< std::wstring >(L"test endnote"));
    std::shared_ptr< requests::InsertFootnoteOnlineRequest > insertRequest(
        new requests::InsertFootnoteOnlineRequest(
            requestDocument, requestFootnoteDto
        )
    );
    wordsApi->insertFootnoteOnline(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertFormField) {
    auto wordsApi = getApi();
    auto requestFormField = std::make_shared< aspose::words::cloud::models::FormFieldTextInput >();
    requestFormField->setName(std::make_shared< std::wstring >(L"FullName"));
    requestFormField->setEnabled(std::make_shared< bool >(true));
    requestFormField->setCalculateOnExit(std::make_shared< bool >(true));
    requestFormField->setStatusText(std::make_shared< std::wstring >(L""));
    requestFormField->setTextInputType(std::make_shared< aspose::words::cloud::models::FormFieldTextInput::TextInputType >(aspose::words::cloud::models::FormFieldTextInput::TextInputType::REGULAR));
    requestFormField->setTextInputDefault(std::make_shared< std::wstring >(L"123"));
    requestFormField->setTextInputFormat(std::make_shared< std::wstring >(L"UPPERCASE"));
    std::shared_ptr< requests::InsertFormFieldRequest > insertRequest(
        new requests::InsertFormFieldRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), requestFormField
        )
    );
    wordsApi->insertFormField(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertFormFieldOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestFormField = std::make_shared< aspose::words::cloud::models::FormFieldTextInput >();
    requestFormField->setName(std::make_shared< std::wstring >(L"FullName"));
    requestFormField->setEnabled(std::make_shared< bool >(true));
    requestFormField->setCalculateOnExit(std::make_shared< bool >(true));
    requestFormField->setStatusText(std::make_shared< std::wstring >(L""));
    requestFormField->setTextInputType(std::make_shared< aspose::words::cloud::models::FormFieldTextInput::TextInputType >(aspose::words::cloud::models::FormFieldTextInput::TextInputType::REGULAR));
    requestFormField->setTextInputDefault(std::make_shared< std::wstring >(L"123"));
    requestFormField->setTextInputFormat(std::make_shared< std::wstring >(L"UPPERCASE"));
    std::shared_ptr< requests::InsertFormFieldOnlineRequest > insertRequest(
        new requests::InsertFormFieldOnlineRequest(
            requestDocument, requestFormField, std::make_shared< std::wstring >(L"sections/0/paragraphs/0")
        )
    );
    wordsApi->insertFormFieldOnline(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertHeaderFooter) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::InsertHeaderFooterRequest > insertRequest(
        new requests::InsertHeaderFooterRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L""), std::make_shared< std::wstring >(L"FooterEven")
        )
    );
    wordsApi->insertHeaderFooter(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertHeaderFooterOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
    std::shared_ptr< requests::InsertHeaderFooterOnlineRequest > insertRequest(
        new requests::InsertHeaderFooterOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L""), std::make_shared< std::wstring >(L"FooterEven")
        )
    );
    wordsApi->insertHeaderFooterOnline(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertList) {
    auto wordsApi = getApi();
    auto requestListInsert = std::make_shared< aspose::words::cloud::models::ListInsert >();
    requestListInsert->setTemplate(std::make_shared< aspose::words::cloud::models::ListInsert::Template >(aspose::words::cloud::models::ListInsert::Template::OUTLINE_LEGAL));
    std::shared_ptr< requests::InsertListRequest > insertRequest(
        new requests::InsertListRequest(
            std::make_shared< std::wstring >(L"TestGetLists.doc"), requestListInsert
        )
    );
    wordsApi->insertList(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertListOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
    auto requestListInsert = std::make_shared< aspose::words::cloud::models::ListInsert >();
    requestListInsert->setTemplate(std::make_shared< aspose::words::cloud::models::ListInsert::Template >(aspose::words::cloud::models::ListInsert::Template::OUTLINE_LEGAL));
    std::shared_ptr< requests::InsertListOnlineRequest > insertRequest(
        new requests::InsertListOnlineRequest(
            requestDocument, requestListInsert
        )
    );
    wordsApi->insertListOnline(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertOrUpdateParagraphTabStop) {
    auto wordsApi = getApi();
    auto requestTabStopInsertDto = std::make_shared< aspose::words::cloud::models::TabStopInsert >();
    requestTabStopInsertDto->setAlignment(std::make_shared< aspose::words::cloud::models::TabStopBase::Alignment >(aspose::words::cloud::models::TabStopBase::Alignment::LEFT));
    requestTabStopInsertDto->setLeader(std::make_shared< aspose::words::cloud::models::TabStopBase::Leader >(aspose::words::cloud::models::TabStopBase::Leader::NONE));
    requestTabStopInsertDto->setPosition(std::make_shared< double >(100.0));
    std::shared_ptr< requests::InsertOrUpdateParagraphTabStopRequest > insertRequest(
        new requests::InsertOrUpdateParagraphTabStopRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0), requestTabStopInsertDto
        )
    );
    wordsApi->insertOrUpdateParagraphTabStop(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertOrUpdateParagraphTabStopOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestTabStopInsertDto = std::make_shared< aspose::words::cloud::models::TabStopInsert >();
    requestTabStopInsertDto->setAlignment(std::make_shared< aspose::words::cloud::models::TabStopBase::Alignment >(aspose::words::cloud::models::TabStopBase::Alignment::LEFT));
    requestTabStopInsertDto->setLeader(std::make_shared< aspose::words::cloud::models::TabStopBase::Leader >(aspose::words::cloud::models::TabStopBase::Leader::NONE));
    requestTabStopInsertDto->setPosition(std::make_shared< double >(72));
    std::shared_ptr< requests::InsertOrUpdateParagraphTabStopOnlineRequest > insertRequest(
        new requests::InsertOrUpdateParagraphTabStopOnlineRequest(
            requestDocument, requestTabStopInsertDto, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->insertOrUpdateParagraphTabStopOnline(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertPageNumbers) {
    auto wordsApi = getApi();
    auto requestPageNumber = std::make_shared< aspose::words::cloud::models::PageNumber >();
    requestPageNumber->setAlignment(std::make_shared< std::wstring >(L"center"));
    requestPageNumber->setFormat(std::make_shared< std::wstring >(L"{PAGE} of {NUMPAGES}"));
    std::shared_ptr< requests::InsertPageNumbersRequest > insertRequest(
        new requests::InsertPageNumbersRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), requestPageNumber
        )
    );
    wordsApi->insertPageNumbers(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertPageNumbersOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Common/Sample.docx"), std::istream::binary));
    auto requestPageNumber = std::make_shared< aspose::words::cloud::models::PageNumber >();
    requestPageNumber->setAlignment(std::make_shared< std::wstring >(L"center"));
    requestPageNumber->setFormat(std::make_shared< std::wstring >(L"{PAGE} of {NUMPAGES}"));
    std::shared_ptr< requests::InsertPageNumbersOnlineRequest > insertRequest(
        new requests::InsertPageNumbersOnlineRequest(
            requestDocument, requestPageNumber
        )
    );
    wordsApi->insertPageNumbersOnline(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertParagraph) {
    auto wordsApi = getApi();
    auto requestParagraph = std::make_shared< aspose::words::cloud::models::ParagraphInsert >();
    requestParagraph->setText(std::make_shared< std::wstring >(L"This is a new paragraph for your document"));
    std::shared_ptr< requests::InsertParagraphRequest > insertRequest(
        new requests::InsertParagraphRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), requestParagraph
        )
    );
    wordsApi->insertParagraph(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertParagraphOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestParagraph = std::make_shared< aspose::words::cloud::models::ParagraphInsert >();
    requestParagraph->setText(std::make_shared< std::wstring >(L"This is a new paragraph for your document"));
    std::shared_ptr< requests::InsertParagraphOnlineRequest > insertRequest(
        new requests::InsertParagraphOnlineRequest(
            requestDocument, requestParagraph, std::make_shared< std::wstring >(L"sections/0")
        )
    );
    wordsApi->insertParagraphOnline(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertRun) {
    auto wordsApi = getApi();
    auto requestRun = std::make_shared< aspose::words::cloud::models::RunInsert >();
    requestRun->setText(std::make_shared< std::wstring >(L"run with text"));
    std::shared_ptr< requests::InsertRunRequest > insertRequest(
        new requests::InsertRunRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"paragraphs/1"), requestRun
        )
    );
    wordsApi->insertRun(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertRunOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
    auto requestRun = std::make_shared< aspose::words::cloud::models::RunInsert >();
    requestRun->setText(std::make_shared< std::wstring >(L"run with text"));
    std::shared_ptr< requests::InsertRunOnlineRequest > insertRequest(
        new requests::InsertRunOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"paragraphs/1"), requestRun
        )
    );
    wordsApi->insertRunOnline(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertStyle) {
    auto wordsApi = getApi();
    auto requestStyleInsert = std::make_shared< aspose::words::cloud::models::StyleInsert >();
    requestStyleInsert->setStyleName(std::make_shared< std::wstring >(L"My Style"));
    requestStyleInsert->setStyleType(std::make_shared< aspose::words::cloud::models::StyleInsert::StyleType >(aspose::words::cloud::models::StyleInsert::StyleType::PARAGRAPH));
    std::shared_ptr< requests::InsertStyleRequest > insertRequest(
        new requests::InsertStyleRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), requestStyleInsert
        )
    );
    wordsApi->insertStyle(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertStyleOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestStyleInsert = std::make_shared< aspose::words::cloud::models::StyleInsert >();
    requestStyleInsert->setStyleName(std::make_shared< std::wstring >(L"My Style"));
    requestStyleInsert->setStyleType(std::make_shared< aspose::words::cloud::models::StyleInsert::StyleType >(aspose::words::cloud::models::StyleInsert::StyleType::PARAGRAPH));
    std::shared_ptr< requests::InsertStyleOnlineRequest > insertRequest(
        new requests::InsertStyleOnlineRequest(
            requestDocument, requestStyleInsert
        )
    );
    wordsApi->insertStyleOnline(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertTable) {
    auto wordsApi = getApi();
    auto requestTable = std::make_shared< aspose::words::cloud::models::TableInsert >();
    requestTable->setColumnsCount(std::make_shared< int32_t >(5));
    requestTable->setRowsCount(std::make_shared< int32_t >(4));
    std::shared_ptr< requests::InsertTableRequest > insertRequest(
        new requests::InsertTableRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), requestTable
        )
    );
    wordsApi->insertTable(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertTableCell) {
    auto wordsApi = getApi();
    auto requestCell = std::make_shared< aspose::words::cloud::models::TableCellInsert >();

    std::shared_ptr< requests::InsertTableCellRequest > insertRequest(
        new requests::InsertTableCellRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"sections/0/tables/2/rows/0"), requestCell
        )
    );
    wordsApi->insertTableCell(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertTableCellOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestCell = std::make_shared< aspose::words::cloud::models::TableCellInsert >();

    std::shared_ptr< requests::InsertTableCellOnlineRequest > insertRequest(
        new requests::InsertTableCellOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"sections/0/tables/2/rows/0"), requestCell
        )
    );
    wordsApi->insertTableCellOnline(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertTableOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestTable = std::make_shared< aspose::words::cloud::models::TableInsert >();
    requestTable->setColumnsCount(std::make_shared< int32_t >(5));
    requestTable->setRowsCount(std::make_shared< int32_t >(4));
    std::shared_ptr< requests::InsertTableOnlineRequest > insertRequest(
        new requests::InsertTableOnlineRequest(
            requestDocument, requestTable
        )
    );
    wordsApi->insertTableOnline(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertTableRow) {
    auto wordsApi = getApi();
    auto requestRow = std::make_shared< aspose::words::cloud::models::TableRowInsert >();
    requestRow->setColumnsCount(std::make_shared< int32_t >(5));
    std::shared_ptr< requests::InsertTableRowRequest > insertRequest(
        new requests::InsertTableRowRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"sections/0/tables/2"), requestRow
        )
    );
    wordsApi->insertTableRow(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertTableRowOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestRow = std::make_shared< aspose::words::cloud::models::TableRowInsert >();
    requestRow->setColumnsCount(std::make_shared< int32_t >(5));
    std::shared_ptr< requests::InsertTableRowOnlineRequest > insertRequest(
        new requests::InsertTableRowOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"sections/0/tables/2"), requestRow
        )
    );
    wordsApi->insertTableRowOnline(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertWatermarkImage) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    std::shared_ptr< requests::InsertWatermarkImageRequest > insertRequest(
        new requests::InsertWatermarkImageRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), nullptr, std::make_shared< std::wstring >(L"Sample.png")
        )
    );
    wordsApi->insertWatermarkImage(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertWatermarkImageOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestImageFile = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Common/aspose-cloud.png"), std::istream::binary));
    std::shared_ptr< requests::InsertWatermarkImageOnlineRequest > insertRequest(
        new requests::InsertWatermarkImageOnlineRequest(
            requestDocument, requestImageFile
        )
    );
    wordsApi->insertWatermarkImageOnline(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertWatermarkText) {
    auto wordsApi = getApi();
    auto requestWatermarkText = std::make_shared< aspose::words::cloud::models::WatermarkText >();
    requestWatermarkText->setText(std::make_shared< std::wstring >(L"This is the text"));
    requestWatermarkText->setRotationAngle(std::make_shared< double >(90.0));
    std::shared_ptr< requests::InsertWatermarkTextRequest > insertRequest(
        new requests::InsertWatermarkTextRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), requestWatermarkText
        )
    );
    wordsApi->insertWatermarkText(insertRequest);
}

TEST_F(ExamplesTest, TestExampleInsertWatermarkTextOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestWatermarkText = std::make_shared< aspose::words::cloud::models::WatermarkText >();
    requestWatermarkText->setText(std::make_shared< std::wstring >(L"This is the text"));
    requestWatermarkText->setRotationAngle(std::make_shared< double >(90));
    std::shared_ptr< requests::InsertWatermarkTextOnlineRequest > insertRequest(
        new requests::InsertWatermarkTextOnlineRequest(
            requestDocument, requestWatermarkText
        )
    );
    wordsApi->insertWatermarkTextOnline(insertRequest);
}

TEST_F(ExamplesTest, TestExampleLoadWebDocument) {
    auto wordsApi = getApi();
    auto requestDataSaveOptions = std::make_shared< aspose::words::cloud::models::SaveOptionsData >();
    requestDataSaveOptions->setFileName(std::make_shared< std::wstring >(L"google.doc"));
    requestDataSaveOptions->setSaveFormat(std::make_shared< std::wstring >(L"doc"));
    requestDataSaveOptions->setDmlEffectsRenderingMode(std::make_shared< std::wstring >(L"1"));
    requestDataSaveOptions->setDmlRenderingMode(std::make_shared< std::wstring >(L"1"));
    requestDataSaveOptions->setUpdateSdtContent(std::make_shared< bool >(false));
    requestDataSaveOptions->setZipOutput(std::make_shared< bool >(false));
    auto requestData = std::make_shared< aspose::words::cloud::models::LoadWebDocumentData >();
    requestData->setLoadingDocumentUrl(std::make_shared< std::wstring >(L"http://google.com"));
    requestData->setSaveOptions(requestDataSaveOptions);
    std::shared_ptr< requests::LoadWebDocumentRequest > loadRequest(
        new requests::LoadWebDocumentRequest(
            requestData
        )
    );
    wordsApi->loadWebDocument(loadRequest);
}

TEST_F(ExamplesTest, TestExampleMoveFile) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::MoveFileRequest > moveRequest(
        new requests::MoveFileRequest(
            std::make_shared< std::wstring >(L"/TestMoveFileDest_Sample.docx"), std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->moveFile(moveRequest);
}

TEST_F(ExamplesTest, TestExampleMoveFolder) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::MoveFolderRequest > moveRequest(
        new requests::MoveFolderRequest(
            std::make_shared< std::wstring >(L"/TestMoveFolderDest_Sample"), std::make_shared< std::wstring >(L"/TestMoveFolderSrc")
        )
    );
    wordsApi->moveFolder(moveRequest);
}

TEST_F(ExamplesTest, TestExampleOptimizeDocument) {
    auto wordsApi = getApi();
    auto requestOptions = std::make_shared< aspose::words::cloud::models::OptimizationOptions >();
    requestOptions->setMsWordVersion(std::make_shared< aspose::words::cloud::models::OptimizationOptions::MsWordVersion >(aspose::words::cloud::models::OptimizationOptions::MsWordVersion::WORD2002));
    std::shared_ptr< requests::OptimizeDocumentRequest > optimizeRequest(
        new requests::OptimizeDocumentRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), requestOptions
        )
    );
    wordsApi->optimizeDocument(optimizeRequest);
}

TEST_F(ExamplesTest, TestExampleOptimizeDocumentOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestOptions = std::make_shared< aspose::words::cloud::models::OptimizationOptions >();
    requestOptions->setMsWordVersion(std::make_shared< aspose::words::cloud::models::OptimizationOptions::MsWordVersion >(aspose::words::cloud::models::OptimizationOptions::MsWordVersion::WORD2002));
    std::shared_ptr< requests::OptimizeDocumentOnlineRequest > optimizeRequest(
        new requests::OptimizeDocumentOnlineRequest(
            requestDocument, requestOptions
        )
    );
    wordsApi->optimizeDocumentOnline(optimizeRequest);
}

TEST_F(ExamplesTest, TestExampleProtectDocument) {
    auto wordsApi = getApi();
    auto requestProtectionRequest = std::make_shared< aspose::words::cloud::models::ProtectionRequest >();
    requestProtectionRequest->setPassword(std::make_shared< std::wstring >(L"123"));
    requestProtectionRequest->setProtectionType(std::make_shared< std::wstring >(L"ReadOnly"));
    std::shared_ptr< requests::ProtectDocumentRequest > protectRequest(
        new requests::ProtectDocumentRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), requestProtectionRequest
        )
    );
    wordsApi->protectDocument(protectRequest);
}

TEST_F(ExamplesTest, TestExampleProtectDocumentOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestProtectionRequest = std::make_shared< aspose::words::cloud::models::ProtectionRequest >();
    requestProtectionRequest->setNewPassword(std::make_shared< std::wstring >(L"123"));
    std::shared_ptr< requests::ProtectDocumentOnlineRequest > protectRequest(
        new requests::ProtectDocumentOnlineRequest(
            requestDocument, requestProtectionRequest
        )
    );
    wordsApi->protectDocumentOnline(protectRequest);
}

TEST_F(ExamplesTest, TestExampleRejectAllRevisions) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::RejectAllRevisionsRequest > rejectRequest(
        new requests::RejectAllRevisionsRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->rejectAllRevisions(rejectRequest);
}

TEST_F(ExamplesTest, TestExampleRejectAllRevisionsOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::RejectAllRevisionsOnlineRequest > rejectRequest(
        new requests::RejectAllRevisionsOnlineRequest(
            requestDocument
        )
    );
    wordsApi->rejectAllRevisionsOnline(rejectRequest);
}

TEST_F(ExamplesTest, TestExampleRemoveRange) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::RemoveRangeRequest > removeRequest(
        new requests::RemoveRangeRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"id0.0.0"), std::make_shared< std::wstring >(L"id0.0.1")
        )
    );
    wordsApi->removeRange(removeRequest);
}

TEST_F(ExamplesTest, TestExampleRemoveRangeOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
    std::shared_ptr< requests::RemoveRangeOnlineRequest > removeRequest(
        new requests::RemoveRangeOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"id0.0.0"), std::make_shared< std::wstring >(L"id0.0.1")
        )
    );
    wordsApi->removeRangeOnline(removeRequest);
}

TEST_F(ExamplesTest, TestExampleRenderDrawingObject) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::RenderDrawingObjectRequest > renderRequest(
        new requests::RenderDrawingObjectRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"png"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->renderDrawingObject(renderRequest);
}

TEST_F(ExamplesTest, TestExampleRenderDrawingObjectOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::RenderDrawingObjectOnlineRequest > renderRequest(
        new requests::RenderDrawingObjectOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"png"), std::make_shared< int32_t >(0), std::make_shared< std::wstring >(L"sections/0")
        )
    );
    wordsApi->renderDrawingObjectOnline(renderRequest);
}

TEST_F(ExamplesTest, TestExampleRenderMathObject) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::RenderMathObjectRequest > renderRequest(
        new requests::RenderMathObjectRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"png"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->renderMathObject(renderRequest);
}

TEST_F(ExamplesTest, TestExampleRenderMathObjectOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::RenderMathObjectOnlineRequest > renderRequest(
        new requests::RenderMathObjectOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"png"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->renderMathObjectOnline(renderRequest);
}

TEST_F(ExamplesTest, TestExampleRenderPage) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::RenderPageRequest > renderRequest(
        new requests::RenderPageRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(1), std::make_shared< std::wstring >(L"bmp")
        )
    );
    wordsApi->renderPage(renderRequest);
}

TEST_F(ExamplesTest, TestExampleRenderPageOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::RenderPageOnlineRequest > renderRequest(
        new requests::RenderPageOnlineRequest(
            requestDocument, std::make_shared< int32_t >(1), std::make_shared< std::wstring >(L"bmp")
        )
    );
    wordsApi->renderPageOnline(renderRequest);
}

TEST_F(ExamplesTest, TestExampleRenderParagraph) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::RenderParagraphRequest > renderRequest(
        new requests::RenderParagraphRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"png"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->renderParagraph(renderRequest);
}

TEST_F(ExamplesTest, TestExampleRenderParagraphOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::RenderParagraphOnlineRequest > renderRequest(
        new requests::RenderParagraphOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"png"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->renderParagraphOnline(renderRequest);
}

TEST_F(ExamplesTest, TestExampleRenderTable) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::RenderTableRequest > renderRequest(
        new requests::RenderTableRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"png"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->renderTable(renderRequest);
}

TEST_F(ExamplesTest, TestExampleRenderTableOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::RenderTableOnlineRequest > renderRequest(
        new requests::RenderTableOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"png"), std::make_shared< int32_t >(0)
        )
    );
    wordsApi->renderTableOnline(renderRequest);
}

TEST_F(ExamplesTest, TestExampleReplaceText) {
    auto wordsApi = getApi();
    auto requestReplaceText = std::make_shared< aspose::words::cloud::models::ReplaceTextParameters >();
    requestReplaceText->setOldValue(std::make_shared< std::wstring >(L"Testing"));
    requestReplaceText->setNewValue(std::make_shared< std::wstring >(L"Aspose testing"));
    std::shared_ptr< requests::ReplaceTextRequest > replaceRequest(
        new requests::ReplaceTextRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), requestReplaceText
        )
    );
    wordsApi->replaceText(replaceRequest);
}

TEST_F(ExamplesTest, TestExampleReplaceTextOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestReplaceText = std::make_shared< aspose::words::cloud::models::ReplaceTextParameters >();
    requestReplaceText->setOldValue(std::make_shared< std::wstring >(L"aspose"));
    requestReplaceText->setNewValue(std::make_shared< std::wstring >(L"aspose new"));
    std::shared_ptr< requests::ReplaceTextOnlineRequest > replaceRequest(
        new requests::ReplaceTextOnlineRequest(
            requestDocument, requestReplaceText
        )
    );
    wordsApi->replaceTextOnline(replaceRequest);
}

TEST_F(ExamplesTest, TestExampleReplaceWithText) {
    auto wordsApi = getApi();
    auto requestRangeText = std::make_shared< aspose::words::cloud::models::ReplaceRange >();
    requestRangeText->setText(std::make_shared< std::wstring >(L"Replaced header"));
    std::shared_ptr< requests::ReplaceWithTextRequest > replaceRequest(
        new requests::ReplaceWithTextRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"id0.0.0"), requestRangeText, std::make_shared< std::wstring >(L"id0.0.1")
        )
    );
    wordsApi->replaceWithText(replaceRequest);
}

TEST_F(ExamplesTest, TestExampleReplaceWithTextOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
    auto requestRangeText = std::make_shared< aspose::words::cloud::models::ReplaceRange >();
    requestRangeText->setText(std::make_shared< std::wstring >(L"Replaced header"));
    std::shared_ptr< requests::ReplaceWithTextOnlineRequest > replaceRequest(
        new requests::ReplaceWithTextOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"id0.0.0"), requestRangeText, std::make_shared< std::wstring >(L"id0.0.1")
        )
    );
    wordsApi->replaceWithTextOnline(replaceRequest);
}

TEST_F(ExamplesTest, TestExampleResetCache) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::ResetCacheRequest > resetRequest(
        new requests::ResetCacheRequest(
        )
    );
    wordsApi->resetCache(resetRequest);
}

TEST_F(ExamplesTest, TestExampleSaveAs) {
    auto wordsApi = getApi();
    auto requestSaveOptionsData = std::make_shared< aspose::words::cloud::models::SaveOptionsData >();
    requestSaveOptionsData->setSaveFormat(std::make_shared< std::wstring >(L"docx"));
    requestSaveOptionsData->setFileName(std::make_shared< std::wstring >(L"/TestSaveAsFromPdfToDoc.docx"));
    std::shared_ptr< requests::SaveAsRequest > saveRequest(
        new requests::SaveAsRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), requestSaveOptionsData
        )
    );
    wordsApi->saveAs(saveRequest);
}

TEST_F(ExamplesTest, TestExampleSaveAsOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Common/test_multi_pages.docx"), std::istream::binary));
    auto requestSaveOptionsData = std::make_shared< aspose::words::cloud::models::SaveOptionsData >();
    requestSaveOptionsData->setSaveFormat(std::make_shared< std::wstring >(L"pdf"));
    requestSaveOptionsData->setFileName(std::make_shared< std::wstring >(L"/TestSaveAs.pdf"));
    std::shared_ptr< requests::SaveAsOnlineRequest > saveRequest(
        new requests::SaveAsOnlineRequest(
            requestDocument, requestSaveOptionsData
        )
    );
    wordsApi->saveAsOnline(saveRequest);
}

TEST_F(ExamplesTest, TestExampleSaveAsRange) {
    auto wordsApi = getApi();
    auto requestDocumentParameters = std::make_shared< aspose::words::cloud::models::RangeDocument >();
    requestDocumentParameters->setDocumentName(std::make_shared< std::wstring >(L"/NewDoc.docx"));
    std::shared_ptr< requests::SaveAsRangeRequest > saveRequest(
        new requests::SaveAsRangeRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"id0.0.0"), requestDocumentParameters, std::make_shared< std::wstring >(L"id0.0.1")
        )
    );
    wordsApi->saveAsRange(saveRequest);
}

TEST_F(ExamplesTest, TestExampleSaveAsRangeOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
    auto requestDocumentParameters = std::make_shared< aspose::words::cloud::models::RangeDocument >();
    requestDocumentParameters->setDocumentName(std::make_shared< std::wstring >(L"/NewDoc.docx"));
    std::shared_ptr< requests::SaveAsRangeOnlineRequest > saveRequest(
        new requests::SaveAsRangeOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"id0.0.0"), requestDocumentParameters, std::make_shared< std::wstring >(L"id0.0.1")
        )
    );
    wordsApi->saveAsRangeOnline(saveRequest);
}

TEST_F(ExamplesTest, TestExampleSaveAsTiff) {
    auto wordsApi = getApi();
    auto requestSaveOptions = std::make_shared< aspose::words::cloud::models::TiffSaveOptionsData >();
    requestSaveOptions->setSaveFormat(std::make_shared< std::wstring >(L"tiff"));
    requestSaveOptions->setFileName(std::make_shared< std::wstring >(L"/abc.tiff"));
    std::shared_ptr< requests::SaveAsTiffRequest > saveRequest(
        new requests::SaveAsTiffRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), requestSaveOptions
        )
    );
    wordsApi->saveAsTiff(saveRequest);
}

TEST_F(ExamplesTest, TestExampleSaveAsTiffOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Common/test_multi_pages.docx"), std::istream::binary));
    auto requestSaveOptions = std::make_shared< aspose::words::cloud::models::TiffSaveOptionsData >();
    requestSaveOptions->setSaveFormat(std::make_shared< std::wstring >(L"tiff"));
    requestSaveOptions->setFileName(std::make_shared< std::wstring >(L"/abc.tiff"));
    std::shared_ptr< requests::SaveAsTiffOnlineRequest > saveRequest(
        new requests::SaveAsTiffOnlineRequest(
            requestDocument, requestSaveOptions
        )
    );
    wordsApi->saveAsTiffOnline(saveRequest);
}

TEST_F(ExamplesTest, TestExampleSearch) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::SearchRequest > searchRequest(
        new requests::SearchRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"aspose")
        )
    );
    wordsApi->search(searchRequest);
}

TEST_F(ExamplesTest, TestExampleSearchOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::SearchOnlineRequest > searchRequest(
        new requests::SearchOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"aspose")
        )
    );
    wordsApi->searchOnline(searchRequest);
}

TEST_F(ExamplesTest, TestExampleSplitDocument) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::SplitDocumentRequest > splitRequest(
        new requests::SplitDocumentRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"text"), std::make_shared< std::wstring >(L"/TestSplitDocument.text"), std::make_shared< int32_t >(1), std::make_shared< int32_t >(2)
        )
    );
    wordsApi->splitDocument(splitRequest);
}

TEST_F(ExamplesTest, TestExampleSplitDocumentOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::SplitDocumentOnlineRequest > splitRequest(
        new requests::SplitDocumentOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"text"), std::make_shared< std::wstring >(L"/TestSplitDocument.text"), std::make_shared< int32_t >(1), std::make_shared< int32_t >(2)
        )
    );
    wordsApi->splitDocumentOnline(splitRequest);
}

TEST_F(ExamplesTest, TestExampleUnprotectDocument) {
    auto wordsApi = getApi();
    auto requestProtectionRequest = std::make_shared< aspose::words::cloud::models::ProtectionRequest >();
    requestProtectionRequest->setPassword(std::make_shared< std::wstring >(L"aspose"));
    std::shared_ptr< requests::UnprotectDocumentRequest > unprotectRequest(
        new requests::UnprotectDocumentRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), requestProtectionRequest
        )
    );
    wordsApi->unprotectDocument(unprotectRequest);
}

TEST_F(ExamplesTest, TestExampleUnprotectDocumentOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestProtectionRequest = std::make_shared< aspose::words::cloud::models::ProtectionRequest >();
    requestProtectionRequest->setPassword(std::make_shared< std::wstring >(L"aspose"));
    std::shared_ptr< requests::UnprotectDocumentOnlineRequest > unprotectRequest(
        new requests::UnprotectDocumentOnlineRequest(
            requestDocument, requestProtectionRequest
        )
    );
    wordsApi->unprotectDocumentOnline(unprotectRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateBookmark) {
    auto wordsApi = getApi();
    std::wstring bookmarkName = L"aspose";

    auto requestBookmarkData = std::make_shared< aspose::words::cloud::models::BookmarkData >();
    requestBookmarkData->setName(std::make_shared< std::wstring >(bookmarkName));
    requestBookmarkData->setText(std::make_shared< std::wstring >(L"This will be the text for Aspose"));
    std::shared_ptr< requests::UpdateBookmarkRequest > updateRequest(
        new requests::UpdateBookmarkRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(bookmarkName), requestBookmarkData
        )
    );
    wordsApi->updateBookmark(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateBookmarkOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    std::wstring bookmarkName = L"aspose";

    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestBookmarkData = std::make_shared< aspose::words::cloud::models::BookmarkData >();
    requestBookmarkData->setName(std::make_shared< std::wstring >(bookmarkName));
    requestBookmarkData->setText(std::make_shared< std::wstring >(L"This will be the text for Aspose"));
    std::shared_ptr< requests::UpdateBookmarkOnlineRequest > updateRequest(
        new requests::UpdateBookmarkOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(bookmarkName), requestBookmarkData, std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->updateBookmarkOnline(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateBorder) {
    auto wordsApi = getApi();
    auto requestBorderPropertiesColor = std::make_shared< aspose::words::cloud::models::XmlColor >();
    requestBorderPropertiesColor->setWeb(std::make_shared< std::wstring >(L"#AABBCC"));
    auto requestBorderProperties = std::make_shared< aspose::words::cloud::models::Border >();
    requestBorderProperties->setBorderType(std::make_shared< aspose::words::cloud::models::Border::BorderType >(aspose::words::cloud::models::Border::BorderType::LEFT));
    requestBorderProperties->setColor(requestBorderPropertiesColor);
    requestBorderProperties->setDistanceFromText(std::make_shared< double >(6.0));
    requestBorderProperties->setLineStyle(std::make_shared< aspose::words::cloud::models::Border::LineStyle >(aspose::words::cloud::models::Border::LineStyle::DASH_DOT_STROKER));
    requestBorderProperties->setLineWidth(std::make_shared< double >(2.0));
    requestBorderProperties->setShadow(std::make_shared< bool >(true));
    std::shared_ptr< requests::UpdateBorderRequest > updateRequest(
        new requests::UpdateBorderRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"left"), requestBorderProperties, std::make_shared< std::wstring >(L"tables/1/rows/0/cells/0")
        )
    );
    wordsApi->updateBorder(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateBorderOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestBorderPropertiesColor = std::make_shared< aspose::words::cloud::models::XmlColor >();
    requestBorderPropertiesColor->setWeb(std::make_shared< std::wstring >(L"#AABBCC"));
    auto requestBorderProperties = std::make_shared< aspose::words::cloud::models::Border >();
    requestBorderProperties->setBorderType(std::make_shared< aspose::words::cloud::models::Border::BorderType >(aspose::words::cloud::models::Border::BorderType::LEFT));
    requestBorderProperties->setColor(requestBorderPropertiesColor);
    requestBorderProperties->setDistanceFromText(std::make_shared< double >(6));
    requestBorderProperties->setLineStyle(std::make_shared< aspose::words::cloud::models::Border::LineStyle >(aspose::words::cloud::models::Border::LineStyle::DASH_DOT_STROKER));
    requestBorderProperties->setLineWidth(std::make_shared< double >(2));
    requestBorderProperties->setShadow(std::make_shared< bool >(true));
    std::shared_ptr< requests::UpdateBorderOnlineRequest > updateRequest(
        new requests::UpdateBorderOnlineRequest(
            requestDocument, requestBorderProperties, std::make_shared< std::wstring >(L"left"), std::make_shared< std::wstring >(L"tables/1/rows/0/cells/0")
        )
    );
    wordsApi->updateBorderOnline(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateComment) {
    auto wordsApi = getApi();
    auto requestCommentRangeStartNode = std::make_shared< aspose::words::cloud::models::NodeLink >();
    requestCommentRangeStartNode->setNodeId(std::make_shared< std::wstring >(L"0.3.0"));
    auto requestCommentRangeStart = std::make_shared< aspose::words::cloud::models::DocumentPosition >();
    requestCommentRangeStart->setNode(requestCommentRangeStartNode);
    requestCommentRangeStart->setOffset(std::make_shared< int32_t >(0));
    auto requestCommentRangeEndNode = std::make_shared< aspose::words::cloud::models::NodeLink >();
    requestCommentRangeEndNode->setNodeId(std::make_shared< std::wstring >(L"0.3.0"));
    auto requestCommentRangeEnd = std::make_shared< aspose::words::cloud::models::DocumentPosition >();
    requestCommentRangeEnd->setNode(requestCommentRangeEndNode);
    requestCommentRangeEnd->setOffset(std::make_shared< int32_t >(0));
    auto requestComment = std::make_shared< aspose::words::cloud::models::CommentUpdate >();
    requestComment->setRangeStart(requestCommentRangeStart);
    requestComment->setRangeEnd(requestCommentRangeEnd);
    requestComment->setInitial(std::make_shared< std::wstring >(L"IA"));
    requestComment->setAuthor(std::make_shared< std::wstring >(L"Imran Anwar"));
    requestComment->setText(std::make_shared< std::wstring >(L"A new Comment"));
    std::shared_ptr< requests::UpdateCommentRequest > updateRequest(
        new requests::UpdateCommentRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0), requestComment
        )
    );
    wordsApi->updateComment(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateCommentOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestCommentRangeStartNode = std::make_shared< aspose::words::cloud::models::NodeLink >();
    requestCommentRangeStartNode->setNodeId(std::make_shared< std::wstring >(L"0.3.0"));
    auto requestCommentRangeStart = std::make_shared< aspose::words::cloud::models::DocumentPosition >();
    requestCommentRangeStart->setNode(requestCommentRangeStartNode);
    requestCommentRangeStart->setOffset(std::make_shared< int32_t >(0));
    auto requestCommentRangeEndNode = std::make_shared< aspose::words::cloud::models::NodeLink >();
    requestCommentRangeEndNode->setNodeId(std::make_shared< std::wstring >(L"0.3.0"));
    auto requestCommentRangeEnd = std::make_shared< aspose::words::cloud::models::DocumentPosition >();
    requestCommentRangeEnd->setNode(requestCommentRangeEndNode);
    requestCommentRangeEnd->setOffset(std::make_shared< int32_t >(0));
    auto requestComment = std::make_shared< aspose::words::cloud::models::CommentUpdate >();
    requestComment->setRangeStart(requestCommentRangeStart);
    requestComment->setRangeEnd(requestCommentRangeEnd);
    requestComment->setInitial(std::make_shared< std::wstring >(L"IA"));
    requestComment->setAuthor(std::make_shared< std::wstring >(L"Imran Anwar"));
    requestComment->setText(std::make_shared< std::wstring >(L"A new Comment"));
    std::shared_ptr< requests::UpdateCommentOnlineRequest > updateRequest(
        new requests::UpdateCommentOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0), requestComment
        )
    );
    wordsApi->updateCommentOnline(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateCustomXmlPart) {
    auto wordsApi = getApi();
    auto requestCustomXmlPart = std::make_shared< aspose::words::cloud::models::CustomXmlPartUpdate >();
    requestCustomXmlPart->setData(std::make_shared< std::wstring >(L"<data>Hello world</data>"));
    std::shared_ptr< requests::UpdateCustomXmlPartRequest > updateRequest(
        new requests::UpdateCustomXmlPartRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0), requestCustomXmlPart
        )
    );
    wordsApi->updateCustomXmlPart(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateCustomXmlPartOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestCustomXmlPart = std::make_shared< aspose::words::cloud::models::CustomXmlPartUpdate >();
    requestCustomXmlPart->setData(std::make_shared< std::wstring >(L"<data>Hello world</data>"));
    std::shared_ptr< requests::UpdateCustomXmlPartOnlineRequest > updateRequest(
        new requests::UpdateCustomXmlPartOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0), requestCustomXmlPart
        )
    );
    wordsApi->updateCustomXmlPartOnline(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateDrawingObject) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDrawingObject = std::make_shared< aspose::words::cloud::models::DrawingObjectUpdate >();
    requestDrawingObject->setLeft(std::make_shared< double >(0));
    auto requestImageFile = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Common/aspose-cloud.png"), std::istream::binary));
    std::shared_ptr< requests::UpdateDrawingObjectRequest > updateRequest(
        new requests::UpdateDrawingObjectRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), requestDrawingObject, requestImageFile, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->updateDrawingObject(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateDrawingObjectOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestDrawingObject = std::make_shared< aspose::words::cloud::models::DrawingObjectUpdate >();
    requestDrawingObject->setLeft(std::make_shared< double >(0));
    auto requestImageFile = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Common/aspose-cloud.png"), std::istream::binary));
    std::shared_ptr< requests::UpdateDrawingObjectOnlineRequest > updateRequest(
        new requests::UpdateDrawingObjectOnlineRequest(
            requestDocument, requestDrawingObject, requestImageFile, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->updateDrawingObjectOnline(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateField) {
    auto wordsApi = getApi();
    auto requestField = std::make_shared< aspose::words::cloud::models::FieldUpdate >();
    requestField->setFieldCode(std::make_shared< std::wstring >(L"{ NUMPAGES }"));
    std::shared_ptr< requests::UpdateFieldRequest > updateRequest(
        new requests::UpdateFieldRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0), requestField, std::make_shared< std::wstring >(L"sections/0/paragraphs/0")
        )
    );
    wordsApi->updateField(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateFieldOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestField = std::make_shared< aspose::words::cloud::models::FieldUpdate >();
    requestField->setFieldCode(std::make_shared< std::wstring >(L"{ NUMPAGES }"));
    std::shared_ptr< requests::UpdateFieldOnlineRequest > updateRequest(
        new requests::UpdateFieldOnlineRequest(
            requestDocument, requestField, std::make_shared< int32_t >(0), std::make_shared< std::wstring >(L"sections/0/paragraphs/0")
        )
    );
    wordsApi->updateFieldOnline(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateFields) {
    auto wordsApi = getApi();
    std::shared_ptr< requests::UpdateFieldsRequest > updateRequest(
        new requests::UpdateFieldsRequest(
            std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->updateFields(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateFieldsOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::UpdateFieldsOnlineRequest > updateRequest(
        new requests::UpdateFieldsOnlineRequest(
            requestDocument
        )
    );
    wordsApi->updateFieldsOnline(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateFootnote) {
    auto wordsApi = getApi();
    auto requestFootnoteDto = std::make_shared< aspose::words::cloud::models::FootnoteUpdate >();
    requestFootnoteDto->setText(std::make_shared< std::wstring >(L"new text is here"));
    std::shared_ptr< requests::UpdateFootnoteRequest > updateRequest(
        new requests::UpdateFootnoteRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0), requestFootnoteDto
        )
    );
    wordsApi->updateFootnote(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateFootnoteOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
    auto requestFootnoteDto = std::make_shared< aspose::words::cloud::models::FootnoteUpdate >();
    requestFootnoteDto->setText(std::make_shared< std::wstring >(L"new text is here"));
    std::shared_ptr< requests::UpdateFootnoteOnlineRequest > updateRequest(
        new requests::UpdateFootnoteOnlineRequest(
            requestDocument, requestFootnoteDto, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->updateFootnoteOnline(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateFormField) {
    auto wordsApi = getApi();
    auto requestFormField = std::make_shared< aspose::words::cloud::models::FormFieldTextInput >();
    requestFormField->setName(std::make_shared< std::wstring >(L"FullName"));
    requestFormField->setEnabled(std::make_shared< bool >(true));
    requestFormField->setCalculateOnExit(std::make_shared< bool >(true));
    requestFormField->setStatusText(std::make_shared< std::wstring >(L""));
    requestFormField->setTextInputType(std::make_shared< aspose::words::cloud::models::FormFieldTextInput::TextInputType >(aspose::words::cloud::models::FormFieldTextInput::TextInputType::REGULAR));
    requestFormField->setTextInputDefault(std::make_shared< std::wstring >(L"No name"));
    std::shared_ptr< requests::UpdateFormFieldRequest > updateRequest(
        new requests::UpdateFormFieldRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0), requestFormField
        )
    );
    wordsApi->updateFormField(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateFormFieldOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestFormField = std::make_shared< aspose::words::cloud::models::FormFieldTextInput >();
    requestFormField->setName(std::make_shared< std::wstring >(L"FullName"));
    requestFormField->setEnabled(std::make_shared< bool >(true));
    requestFormField->setCalculateOnExit(std::make_shared< bool >(true));
    requestFormField->setStatusText(std::make_shared< std::wstring >(L""));
    requestFormField->setTextInputType(std::make_shared< aspose::words::cloud::models::FormFieldTextInput::TextInputType >(aspose::words::cloud::models::FormFieldTextInput::TextInputType::REGULAR));
    requestFormField->setTextInputDefault(std::make_shared< std::wstring >(L"No name"));
    std::shared_ptr< requests::UpdateFormFieldOnlineRequest > updateRequest(
        new requests::UpdateFormFieldOnlineRequest(
            requestDocument, requestFormField, std::make_shared< int32_t >(0), std::make_shared< std::wstring >(L"sections/0")
        )
    );
    wordsApi->updateFormFieldOnline(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateList) {
    auto wordsApi = getApi();
    auto requestListUpdate = std::make_shared< aspose::words::cloud::models::ListUpdate >();
    requestListUpdate->setIsRestartAtEachSection(std::make_shared< bool >(true));
    std::shared_ptr< requests::UpdateListRequest > updateRequest(
        new requests::UpdateListRequest(
            std::make_shared< std::wstring >(L"TestGetLists.doc"), std::make_shared< int32_t >(1), requestListUpdate
        )
    );
    wordsApi->updateList(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateListLevel) {
    auto wordsApi = getApi();
    auto requestListUpdate = std::make_shared< aspose::words::cloud::models::ListLevelUpdate >();
    requestListUpdate->setAlignment(std::make_shared< aspose::words::cloud::models::ListLevelUpdate::Alignment >(aspose::words::cloud::models::ListLevelUpdate::Alignment::RIGHT));
    std::shared_ptr< requests::UpdateListLevelRequest > updateRequest(
        new requests::UpdateListLevelRequest(
            std::make_shared< std::wstring >(L"TestGetLists.doc"), std::make_shared< int32_t >(1), std::make_shared< int32_t >(1), requestListUpdate
        )
    );
    wordsApi->updateListLevel(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateListLevelOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
    auto requestListUpdate = std::make_shared< aspose::words::cloud::models::ListLevelUpdate >();
    requestListUpdate->setAlignment(std::make_shared< aspose::words::cloud::models::ListLevelUpdate::Alignment >(aspose::words::cloud::models::ListLevelUpdate::Alignment::RIGHT));
    std::shared_ptr< requests::UpdateListLevelOnlineRequest > updateRequest(
        new requests::UpdateListLevelOnlineRequest(
            requestDocument, std::make_shared< int32_t >(1), requestListUpdate, std::make_shared< int32_t >(1)
        )
    );
    wordsApi->updateListLevelOnline(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateListOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
    auto requestListUpdate = std::make_shared< aspose::words::cloud::models::ListUpdate >();
    requestListUpdate->setIsRestartAtEachSection(std::make_shared< bool >(true));
    std::shared_ptr< requests::UpdateListOnlineRequest > updateRequest(
        new requests::UpdateListOnlineRequest(
            requestDocument, std::make_shared< int32_t >(1), requestListUpdate
        )
    );
    wordsApi->updateListOnline(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateParagraphFormat) {
    auto wordsApi = getApi();
    auto requestParagraphFormatDto = std::make_shared< aspose::words::cloud::models::ParagraphFormatUpdate >();
    requestParagraphFormatDto->setAlignment(std::make_shared< aspose::words::cloud::models::ParagraphFormatBase::Alignment >(aspose::words::cloud::models::ParagraphFormatBase::Alignment::RIGHT));
    std::shared_ptr< requests::UpdateParagraphFormatRequest > updateRequest(
        new requests::UpdateParagraphFormatRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0), requestParagraphFormatDto
        )
    );
    wordsApi->updateParagraphFormat(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateParagraphFormatOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestParagraphFormatDto = std::make_shared< aspose::words::cloud::models::ParagraphFormatUpdate >();
    requestParagraphFormatDto->setAlignment(std::make_shared< aspose::words::cloud::models::ParagraphFormatBase::Alignment >(aspose::words::cloud::models::ParagraphFormatBase::Alignment::RIGHT));
    std::shared_ptr< requests::UpdateParagraphFormatOnlineRequest > updateRequest(
        new requests::UpdateParagraphFormatOnlineRequest(
            requestDocument, requestParagraphFormatDto, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->updateParagraphFormatOnline(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateParagraphListFormat) {
    auto wordsApi = getApi();
    auto requestListFormatDto = std::make_shared< aspose::words::cloud::models::ListFormatUpdate >();
    requestListFormatDto->setListId(std::make_shared< int32_t >(2));
    std::shared_ptr< requests::UpdateParagraphListFormatRequest > updateRequest(
        new requests::UpdateParagraphListFormatRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0), requestListFormatDto
        )
    );
    wordsApi->updateParagraphListFormat(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateParagraphListFormatOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
    auto requestListFormatDto = std::make_shared< aspose::words::cloud::models::ListFormatUpdate >();
    requestListFormatDto->setListId(std::make_shared< int32_t >(2));
    std::shared_ptr< requests::UpdateParagraphListFormatOnlineRequest > updateRequest(
        new requests::UpdateParagraphListFormatOnlineRequest(
            requestDocument, requestListFormatDto, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->updateParagraphListFormatOnline(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateRun) {
    auto wordsApi = getApi();
    auto requestRun = std::make_shared< aspose::words::cloud::models::RunUpdate >();
    requestRun->setText(std::make_shared< std::wstring >(L"run with text"));
    std::shared_ptr< requests::UpdateRunRequest > updateRequest(
        new requests::UpdateRunRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"paragraphs/1"), std::make_shared< int32_t >(0), requestRun
        )
    );
    wordsApi->updateRun(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateRunFont) {
    auto wordsApi = getApi();
    auto requestFontDto = std::make_shared< aspose::words::cloud::models::Font >();
    requestFontDto->setBold(std::make_shared< bool >(true));
    std::shared_ptr< requests::UpdateRunFontRequest > updateRequest(
        new requests::UpdateRunFontRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"paragraphs/0"), std::make_shared< int32_t >(0), requestFontDto
        )
    );
    wordsApi->updateRunFont(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateRunFontOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestFontDto = std::make_shared< aspose::words::cloud::models::Font >();
    requestFontDto->setBold(std::make_shared< bool >(true));
    std::shared_ptr< requests::UpdateRunFontOnlineRequest > updateRequest(
        new requests::UpdateRunFontOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"paragraphs/0"), requestFontDto, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->updateRunFontOnline(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateRunOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
    auto requestRun = std::make_shared< aspose::words::cloud::models::RunUpdate >();
    requestRun->setText(std::make_shared< std::wstring >(L"run with text"));
    std::shared_ptr< requests::UpdateRunOnlineRequest > updateRequest(
        new requests::UpdateRunOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"paragraphs/1"), requestRun, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->updateRunOnline(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateSectionPageSetup) {
    auto wordsApi = getApi();
    auto requestPageSetup = std::make_shared< aspose::words::cloud::models::PageSetup >();
    requestPageSetup->setRtlGutter(std::make_shared< bool >(true));
    requestPageSetup->setLeftMargin(std::make_shared< double >(10.0));
    requestPageSetup->setOrientation(std::make_shared< aspose::words::cloud::models::PageSetup::Orientation >(aspose::words::cloud::models::PageSetup::Orientation::LANDSCAPE));
    requestPageSetup->setPaperSize(std::make_shared< aspose::words::cloud::models::PageSetup::PaperSize >(aspose::words::cloud::models::PageSetup::PaperSize::A5));
    std::shared_ptr< requests::UpdateSectionPageSetupRequest > updateRequest(
        new requests::UpdateSectionPageSetupRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0), requestPageSetup
        )
    );
    wordsApi->updateSectionPageSetup(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateSectionPageSetupOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestPageSetup = std::make_shared< aspose::words::cloud::models::PageSetup >();
    requestPageSetup->setRtlGutter(std::make_shared< bool >(true));
    requestPageSetup->setLeftMargin(std::make_shared< double >(10));
    requestPageSetup->setOrientation(std::make_shared< aspose::words::cloud::models::PageSetup::Orientation >(aspose::words::cloud::models::PageSetup::Orientation::LANDSCAPE));
    requestPageSetup->setPaperSize(std::make_shared< aspose::words::cloud::models::PageSetup::PaperSize >(aspose::words::cloud::models::PageSetup::PaperSize::A5));
    std::shared_ptr< requests::UpdateSectionPageSetupOnlineRequest > updateRequest(
        new requests::UpdateSectionPageSetupOnlineRequest(
            requestDocument, std::make_shared< int32_t >(0), requestPageSetup
        )
    );
    wordsApi->updateSectionPageSetupOnline(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateStyle) {
    auto wordsApi = getApi();
    auto requestStyleUpdate = std::make_shared< aspose::words::cloud::models::StyleUpdate >();
    requestStyleUpdate->setName(std::make_shared< std::wstring >(L"My Style"));
    std::shared_ptr< requests::UpdateStyleRequest > updateRequest(
        new requests::UpdateStyleRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"Heading 1"), requestStyleUpdate
        )
    );
    wordsApi->updateStyle(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateStyleOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestStyleUpdate = std::make_shared< aspose::words::cloud::models::StyleUpdate >();
    requestStyleUpdate->setName(std::make_shared< std::wstring >(L"My Style"));
    std::shared_ptr< requests::UpdateStyleOnlineRequest > updateRequest(
        new requests::UpdateStyleOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"Heading 1"), requestStyleUpdate
        )
    );
    wordsApi->updateStyleOnline(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateTableCellFormat) {
    auto wordsApi = getApi();
    auto requestFormat = std::make_shared< aspose::words::cloud::models::TableCellFormat >();
    requestFormat->setBottomPadding(std::make_shared< double >(5.0));
    requestFormat->setFitText(std::make_shared< bool >(true));
    requestFormat->setHorizontalMerge(std::make_shared< aspose::words::cloud::models::TableCellFormat::HorizontalMerge >(aspose::words::cloud::models::TableCellFormat::HorizontalMerge::FIRST));
    requestFormat->setWrapText(std::make_shared< bool >(true));
    std::shared_ptr< requests::UpdateTableCellFormatRequest > updateRequest(
        new requests::UpdateTableCellFormatRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"sections/0/tables/2/rows/0"), std::make_shared< int32_t >(0), requestFormat
        )
    );
    wordsApi->updateTableCellFormat(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateTableCellFormatOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestFormat = std::make_shared< aspose::words::cloud::models::TableCellFormat >();
    requestFormat->setBottomPadding(std::make_shared< double >(5));
    requestFormat->setFitText(std::make_shared< bool >(true));
    requestFormat->setHorizontalMerge(std::make_shared< aspose::words::cloud::models::TableCellFormat::HorizontalMerge >(aspose::words::cloud::models::TableCellFormat::HorizontalMerge::FIRST));
    requestFormat->setWrapText(std::make_shared< bool >(true));
    std::shared_ptr< requests::UpdateTableCellFormatOnlineRequest > updateRequest(
        new requests::UpdateTableCellFormatOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"sections/0/tables/2/rows/0"), requestFormat, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->updateTableCellFormatOnline(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateTableProperties) {
    auto wordsApi = getApi();
    auto requestProperties = std::make_shared< aspose::words::cloud::models::TableProperties >();
    requestProperties->setAlignment(std::make_shared< aspose::words::cloud::models::TableProperties::Alignment >(aspose::words::cloud::models::TableProperties::Alignment::RIGHT));
    requestProperties->setAllowAutoFit(std::make_shared< bool >(false));
    requestProperties->setBidi(std::make_shared< bool >(true));
    requestProperties->setBottomPadding(std::make_shared< double >(1.0));
    requestProperties->setCellSpacing(std::make_shared< double >(2.0));
    requestProperties->setStyleOptions(std::make_shared< aspose::words::cloud::models::TableProperties::StyleOptions >(aspose::words::cloud::models::TableProperties::StyleOptions::COLUMN_BANDS));
    std::shared_ptr< requests::UpdateTablePropertiesRequest > updateRequest(
        new requests::UpdateTablePropertiesRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(1), requestProperties
        )
    );
    wordsApi->updateTableProperties(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateTablePropertiesOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestProperties = std::make_shared< aspose::words::cloud::models::TableProperties >();
    requestProperties->setAlignment(std::make_shared< aspose::words::cloud::models::TableProperties::Alignment >(aspose::words::cloud::models::TableProperties::Alignment::RIGHT));
    requestProperties->setAllowAutoFit(std::make_shared< bool >(false));
    requestProperties->setBidi(std::make_shared< bool >(true));
    requestProperties->setBottomPadding(std::make_shared< double >(1));
    requestProperties->setCellSpacing(std::make_shared< double >(2));
    requestProperties->setStyleOptions(std::make_shared< aspose::words::cloud::models::TableProperties::StyleOptions >(aspose::words::cloud::models::TableProperties::StyleOptions::COLUMN_BANDS));
    std::shared_ptr< requests::UpdateTablePropertiesOnlineRequest > updateRequest(
        new requests::UpdateTablePropertiesOnlineRequest(
            requestDocument, requestProperties, std::make_shared< int32_t >(1)
        )
    );
    wordsApi->updateTablePropertiesOnline(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateTableRowFormat) {
    auto wordsApi = getApi();
    auto requestFormat = std::make_shared< aspose::words::cloud::models::TableRowFormat >();
    requestFormat->setAllowBreakAcrossPages(std::make_shared< bool >(true));
    requestFormat->setHeadingFormat(std::make_shared< bool >(true));
    requestFormat->setHeight(std::make_shared< double >(10.0));
    requestFormat->setHeightRule(std::make_shared< aspose::words::cloud::models::TableRowFormat::HeightRule >(aspose::words::cloud::models::TableRowFormat::HeightRule::EXACTLY));
    std::shared_ptr< requests::UpdateTableRowFormatRequest > updateRequest(
        new requests::UpdateTableRowFormatRequest(
            std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"sections/0/tables/2"), std::make_shared< int32_t >(0), requestFormat
        )
    );
    wordsApi->updateTableRowFormat(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUpdateTableRowFormatOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    auto requestFormat = std::make_shared< aspose::words::cloud::models::TableRowFormat >();
    requestFormat->setAllowBreakAcrossPages(std::make_shared< bool >(true));
    requestFormat->setHeadingFormat(std::make_shared< bool >(true));
    requestFormat->setHeight(std::make_shared< double >(10));
    requestFormat->setHeightRule(std::make_shared< aspose::words::cloud::models::TableRowFormat::HeightRule >(aspose::words::cloud::models::TableRowFormat::HeightRule::AUTO));
    std::shared_ptr< requests::UpdateTableRowFormatOnlineRequest > updateRequest(
        new requests::UpdateTableRowFormatOnlineRequest(
            requestDocument, std::make_shared< std::wstring >(L"sections/0/tables/2"), requestFormat, std::make_shared< int32_t >(0)
        )
    );
    wordsApi->updateTableRowFormatOnline(updateRequest);
}

TEST_F(ExamplesTest, TestExampleUploadFile) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    auto requestFileContent = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
    std::shared_ptr< requests::UploadFileRequest > uploadRequest(
        new requests::UploadFileRequest(
            requestFileContent, std::make_shared< std::wstring >(L"Sample.docx")
        )
    );
    wordsApi->uploadFile(uploadRequest);
}