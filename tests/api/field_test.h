/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="field_test.h">
*   Copyright (c) 2024 Aspose.Words for Cloud
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
/// Example of how to work with field.
/// </summary>
class FieldTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentElements/Fields";
    std::wstring textFolder = L"DocumentElements/Text";
    std::wstring fieldFolder = L"DocumentElements/Fields";

};

/// <summary>
/// Test for getting fields.
/// </summary>
TEST_F(FieldTests, TestGetFields) {
    std::wstring localFileName = L"GetField.docx";
    std::wstring remoteFileName = L"TestGetFields.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + fieldFolder + L"/" + localFileName,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetFieldsRequest> request(new requests::GetFieldsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"sections/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getFields(request);
    ASSERT_TRUE(actual->getFields() != nullptr);
    ASSERT_TRUE(actual->getFields()->getList() != nullptr);
    ASSERT_EQ(1, actual->getFields()->getList()->size());
    ASSERT_TRUE(actual->getFields()->getList()->at(0)->getResult()->compare(L"1") == 0);
}

/// <summary>
/// Test for getting fields online.
/// </summary>
TEST_F(FieldTests, TestGetFieldsOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(fieldFolder + L"/GetField.docx")), std::istream::binary));
    std::shared_ptr<requests::GetFieldsOnlineRequest> request(new requests::GetFieldsOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"sections/0"),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getFieldsOnline(request);
}

/// <summary>
/// Test for getting fields without node path.
/// </summary>
TEST_F(FieldTests, TestGetFieldsWithoutNodePath) {
    std::wstring localFileName = L"GetField.docx";
    std::wstring remoteFileName = L"TestGetFieldsWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + fieldFolder + L"/" + localFileName,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetFieldsRequest> request(new requests::GetFieldsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getFields(request);
    ASSERT_TRUE(actual->getFields() != nullptr);
    ASSERT_TRUE(actual->getFields()->getList() != nullptr);
    ASSERT_EQ(1, actual->getFields()->getList()->size());
    ASSERT_TRUE(actual->getFields()->getList()->at(0)->getResult()->compare(L"1") == 0);
}

/// <summary>
/// Test for getting field by index.
/// </summary>
TEST_F(FieldTests, TestGetField) {
    std::wstring localFileName = L"GetField.docx";
    std::wstring remoteFileName = L"TestGetField.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + fieldFolder + L"/" + localFileName,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetFieldRequest> request(new requests::GetFieldRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L"sections/0/paragraphs/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getField(request);
    ASSERT_TRUE(actual->getField() != nullptr);
    ASSERT_TRUE(actual->getField()->getResult()->compare(L"1") == 0);
}

/// <summary>
/// Test for getting field by index online.
/// </summary>
TEST_F(FieldTests, TestGetFieldOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(fieldFolder + L"/GetField.docx")), std::istream::binary));
    std::shared_ptr<requests::GetFieldOnlineRequest> request(new requests::GetFieldOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L"sections/0/paragraphs/0"),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getFieldOnline(request);
}

/// <summary>
/// Test for getting field by index without node path.
/// </summary>
TEST_F(FieldTests, TestGetFieldWithoutNodePath) {
    std::wstring localFileName = L"GetField.docx";
    std::wstring remoteFileName = L"TestGetFieldWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + fieldFolder + L"/" + localFileName,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetFieldRequest> request(new requests::GetFieldRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getField(request);
    ASSERT_TRUE(actual->getField() != nullptr);
    ASSERT_TRUE(actual->getField()->getResult()->compare(L"1") == 0);
}

/// <summary>
/// Test for putting field.
/// </summary>
TEST_F(FieldTests, TestInsertField) {
    std::wstring localFileName = L"SampleWordDocument.docx";
    std::wstring remoteFileName = L"TestInsertField.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + textFolder + L"/" + localFileName,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestField = std::make_shared< aspose::words::cloud::models::FieldInsert >();
    requestField->setFieldCode(std::make_shared< std::wstring >(L"{ NUMPAGES }"));
    std::shared_ptr<requests::InsertFieldRequest> request(new requests::InsertFieldRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestField,
        std::make_shared< std::wstring >(L"sections/0/paragraphs/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertField(request);
    ASSERT_TRUE(actual->getField() != nullptr);
    ASSERT_TRUE(actual->getField()->getFieldCode()->compare(L"{ NUMPAGES }") == 0);
    ASSERT_TRUE(actual->getField()->getNodeId()->compare(L"0.0.0.1") == 0);
}

/// <summary>
/// Test for putting field online.
/// </summary>
TEST_F(FieldTests, TestInsertFieldOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(fieldFolder + L"/GetField.docx")), std::istream::binary));
    auto requestField = std::make_shared< aspose::words::cloud::models::FieldInsert >();
    requestField->setFieldCode(std::make_shared< std::wstring >(L"{ NUMPAGES }"));
    std::shared_ptr<requests::InsertFieldOnlineRequest> request(new requests::InsertFieldOnlineRequest(
        requestDocument,
        requestField,
        std::make_shared< std::wstring >(L"sections/0/paragraphs/0"),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertFieldOnline(request);
}

/// <summary>
/// Test for putting field without node path.
/// </summary>
TEST_F(FieldTests, TestInsertFieldWithoutNodePath) {
    std::wstring localFileName = L"SampleWordDocument.docx";
    std::wstring remoteFileName = L"TestInsertFieldWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + textFolder + L"/" + localFileName,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestField = std::make_shared< aspose::words::cloud::models::FieldInsert >();
    requestField->setFieldCode(std::make_shared< std::wstring >(L"{ NUMPAGES }"));
    std::shared_ptr<requests::InsertFieldRequest> request(new requests::InsertFieldRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestField,
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

    auto actual = getApi()->insertField(request);
    ASSERT_TRUE(actual->getField() != nullptr);
    ASSERT_TRUE(actual->getField()->getFieldCode()->compare(L"{ NUMPAGES }") == 0);
    ASSERT_TRUE(actual->getField()->getNodeId()->compare(L"5.0.22.0") == 0);
}

/// <summary>
/// Test for posting field.
/// </summary>
TEST_F(FieldTests, TestUpdateField) {
    std::wstring localFileName = L"GetField.docx";
    std::wstring remoteFileName = L"TestUpdateField.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + fieldFolder + L"/" + localFileName,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestField = std::make_shared< aspose::words::cloud::models::FieldUpdate >();
    requestField->setFieldCode(std::make_shared< std::wstring >(L"{ NUMPAGES }"));
    std::shared_ptr<requests::UpdateFieldRequest> request(new requests::UpdateFieldRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        requestField,
        std::make_shared< std::wstring >(L"sections/0/paragraphs/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateField(request);
    ASSERT_TRUE(actual->getField() != nullptr);
    ASSERT_TRUE(actual->getField()->getFieldCode()->compare(L"{ NUMPAGES }") == 0);
    ASSERT_TRUE(actual->getField()->getNodeId()->compare(L"0.0.0.0") == 0);
}

/// <summary>
/// Test for posting field online.
/// </summary>
TEST_F(FieldTests, TestUpdateFieldOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(fieldFolder + L"/GetField.docx")), std::istream::binary));
    auto requestField = std::make_shared< aspose::words::cloud::models::FieldUpdate >();
    requestField->setFieldCode(std::make_shared< std::wstring >(L"{ NUMPAGES }"));
    std::shared_ptr<requests::UpdateFieldOnlineRequest> request(new requests::UpdateFieldOnlineRequest(
        requestDocument,
        requestField,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L"sections/0/paragraphs/0"),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateFieldOnline(request);
}

/// <summary>
/// Test for inserting page numbers field.
/// </summary>
TEST_F(FieldTests, TestInsertPageNumbers) {
    std::wstring localFileName = L"test_multi_pages.docx";
    std::wstring remoteFileName = L"TestInsertPageNumbers.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + L"Common/" + localFileName,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestPageNumber = std::make_shared< aspose::words::cloud::models::PageNumber >();
    requestPageNumber->setAlignment(std::make_shared< std::wstring >(L"center"));
    requestPageNumber->setFormat(std::make_shared< std::wstring >(L"{PAGE} of {NUMPAGES}"));
    requestPageNumber->setIsTop(std::make_shared< bool >(true));
    requestPageNumber->setSetPageNumberOnFirstPage(std::make_shared< bool >(true));
    std::shared_ptr<requests::InsertPageNumbersRequest> request(new requests::InsertPageNumbersRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestPageNumber,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertPageNumbers(request);
    ASSERT_TRUE(actual->getDocument() != nullptr);
    ASSERT_TRUE(actual->getDocument()->getFileName()->compare(L"TestInsertPageNumbers.docx") == 0);
}

/// <summary>
/// Test for inserting page numbers field online.
/// </summary>
TEST_F(FieldTests, TestInsertPageNumbersOnline) {
    std::wstring localFileName = L"test_multi_pages.docx";

    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(L"Common/" + localFileName)), std::istream::binary));
    auto requestPageNumber = std::make_shared< aspose::words::cloud::models::PageNumber >();
    requestPageNumber->setAlignment(std::make_shared< std::wstring >(L"center"));
    requestPageNumber->setFormat(std::make_shared< std::wstring >(L"{PAGE} of {NUMPAGES}"));
    requestPageNumber->setIsTop(std::make_shared< bool >(true));
    requestPageNumber->setSetPageNumberOnFirstPage(std::make_shared< bool >(true));
    std::shared_ptr<requests::InsertPageNumbersOnlineRequest> request(new requests::InsertPageNumbersOnlineRequest(
        requestDocument,
        requestPageNumber,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertPageNumbersOnline(request);
}

/// <summary>
/// Test for deleting field.
/// </summary>
TEST_F(FieldTests, TestDeleteField) {
    std::wstring localFileName = L"GetField.docx";
    std::wstring remoteFileName = L"TestDeleteField.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + fieldFolder + L"/" + localFileName,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteFieldRequest> request(new requests::DeleteFieldRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L"sections/0/paragraphs/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

getApi()->deleteField(request);
}

/// <summary>
/// Test for deleting field online.
/// </summary>
TEST_F(FieldTests, TestDeleteFieldOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(fieldFolder + L"/GetField.docx")), std::istream::binary));
    std::shared_ptr<requests::DeleteFieldOnlineRequest> request(new requests::DeleteFieldOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L"sections/0/paragraphs/0"),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteFieldOnline(request);
}

/// <summary>
/// Test for deleting field without node path.
/// </summary>
TEST_F(FieldTests, TestDeleteFieldWithoutNodePath) {
    std::wstring localFileName = L"GetField.docx";
    std::wstring remoteFileName = L"TestDeleteFieldWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + fieldFolder + L"/" + localFileName,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteFieldRequest> request(new requests::DeleteFieldRequest(
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

getApi()->deleteField(request);
}

/// <summary>
/// Test for deleting paragraph fields.
/// </summary>
TEST_F(FieldTests, TestDeleteParagraphFields) {
    std::wstring localFileName = L"test_multi_pages.docx";
    std::wstring remoteFileName = L"TestDeleteParagraphFields.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + L"Common/" + localFileName,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteFieldsRequest> request(new requests::DeleteFieldsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"paragraphs/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

getApi()->deleteFields(request);
}

/// <summary>
/// Test for deleting paragraph fields without node path.
/// </summary>
TEST_F(FieldTests, TestDeleteParagraphFieldsWithoutNodePath) {
    std::wstring localFileName = L"test_multi_pages.docx";
    std::wstring remoteFileName = L"TestDeleteParagraphFieldsWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + L"Common/" + localFileName,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteFieldsRequest> request(new requests::DeleteFieldsRequest(
        std::make_shared< std::wstring >(remoteFileName),
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

getApi()->deleteFields(request);
}

/// <summary>
/// Test for deleting section fields.
/// </summary>
TEST_F(FieldTests, TestDeleteSectionFields) {
    std::wstring localFileName = L"test_multi_pages.docx";
    std::wstring remoteFileName = L"TestDeleteSectionFields.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + L"Common/" + localFileName,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteFieldsRequest> request(new requests::DeleteFieldsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"sections/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

getApi()->deleteFields(request);
}

/// <summary>
/// Test for deleting section fields without node path.
/// </summary>
TEST_F(FieldTests, TestDeleteSectionFieldsWithoutNodePath) {
    std::wstring localFileName = L"test_multi_pages.docx";
    std::wstring remoteFileName = L"TestDeleteSectionFieldsWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + L"Common/" + localFileName,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteFieldsRequest> request(new requests::DeleteFieldsRequest(
        std::make_shared< std::wstring >(remoteFileName),
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

getApi()->deleteFields(request);
}

/// <summary>
/// Test for deleting paragraph fields in section.
/// </summary>
TEST_F(FieldTests, TestDeleteSectionParagraphFields) {
    std::wstring localFileName = L"test_multi_pages.docx";
    std::wstring remoteFileName = L"TestDeleteSectionParagraphFields.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + L"Common/" + localFileName,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteFieldsRequest> request(new requests::DeleteFieldsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"sections/0/paragraphs/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

getApi()->deleteFields(request);
}

/// <summary>
/// Test for deleting fields.
/// </summary>
TEST_F(FieldTests, TestDeleteDocumentFields) {
    std::wstring localFileName = L"test_multi_pages.docx";
    std::wstring remoteFileName = L"TestDeleteSectionParagraphFields.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + L"Common/" + localFileName,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteFieldsRequest> request(new requests::DeleteFieldsRequest(
        std::make_shared< std::wstring >(remoteFileName),
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

getApi()->deleteFields(request);
}

/// <summary>
/// Test for deleting fields online.
/// </summary>
TEST_F(FieldTests, TestDeleteDocumentFieldsOnline) {
    std::wstring localFileName = L"Common/test_multi_pages.docx";

    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFileName)), std::istream::binary));
    std::shared_ptr<requests::DeleteFieldsOnlineRequest> request(new requests::DeleteFieldsOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteFieldsOnline(request);
}

/// <summary>
/// Test for posting updated fields.
/// </summary>
TEST_F(FieldTests, TestUpdateDocumentFields) {
    std::wstring localFileName = L"test_multi_pages.docx";
    std::wstring remoteFileName = L"TestUpdateDocumentFields.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + L"Common/" + localFileName,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::UpdateFieldsRequest> request(new requests::UpdateFieldsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateFields(request);
    ASSERT_TRUE(actual->getDocument() != nullptr);
    ASSERT_TRUE(actual->getDocument()->getFileName()->compare(L"TestUpdateDocumentFields.docx") == 0);
}

/// <summary>
/// Test for posting updated fields online.
/// </summary>
TEST_F(FieldTests, TestUpdateDocumentFieldsOnline) {
    std::wstring localFile = L"Common/test_multi_pages.docx";

    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::UpdateFieldsOnlineRequest> request(new requests::UpdateFieldsOnlineRequest(
        requestDocument,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateFieldsOnline(request);
}
