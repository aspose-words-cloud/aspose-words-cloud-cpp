/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="fieldTests.cpp">
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
/// Example of how to work with field.
/// </summary>
class FieldTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentElements/Fields");
    utility::string_t textFolder = STCONVERT("DocumentElements/Text");
    utility::string_t fieldFolder = STCONVERT("DocumentElements/Fields");

};

/// <summary>
/// Test for getting fields.
/// </summary>
TEST_F(FieldTests, TestGetFields) {
    utility::string_t localFileName = STCONVERT("GetField.docx");
    utility::string_t remoteFileName = STCONVERT("TestGetFields.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, fieldFolder + STCONVERT("/") + localFileName)
    );

    std::shared_ptr< GetFieldsRequest > request(new GetFieldsRequest(
        remoteFileName,
        STCONVERT("sections/0"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getFields(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting fields without node path.
/// </summary>
TEST_F(FieldTests, TestGetFieldsWithoutNodePath) {
    utility::string_t localFileName = STCONVERT("GetField.docx");
    utility::string_t remoteFileName = STCONVERT("TestGetFieldsWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, fieldFolder + STCONVERT("/") + localFileName)
    );

    std::shared_ptr< GetFieldsWithoutNodePathRequest > request(new GetFieldsWithoutNodePathRequest(
        remoteFileName,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getFieldsWithoutNodePath(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting field by index.
/// </summary>
TEST_F(FieldTests, TestGetField) {
    utility::string_t localFileName = STCONVERT("GetField.docx");
    utility::string_t remoteFileName = STCONVERT("TestGetField.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, fieldFolder + STCONVERT("/") + localFileName)
    );

    std::shared_ptr< GetFieldRequest > request(new GetFieldRequest(
        remoteFileName,
        STCONVERT("sections/0/paragraphs/0"),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getField(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting field by index without node path.
/// </summary>
TEST_F(FieldTests, TestGetFieldWithoutNodePath) {
    utility::string_t localFileName = STCONVERT("GetField.docx");
    utility::string_t remoteFileName = STCONVERT("TestGetFieldWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, fieldFolder + STCONVERT("/") + localFileName)
    );

    std::shared_ptr< GetFieldWithoutNodePathRequest > request(new GetFieldWithoutNodePathRequest(
        remoteFileName,
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getFieldWithoutNodePath(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for putting field.
/// </summary>
TEST_F(FieldTests, TestInsertField) {
    utility::string_t localFileName = STCONVERT("SampleWordDocument.docx");
    utility::string_t remoteFileName = STCONVERT("TestInsertField.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, textFolder + STCONVERT("/") + localFileName)
    );

    auto requestField = std::make_shared< FieldInsert >();
    requestField->setFieldCode(STCONVERT("{ NUMPAGES }"));

    std::shared_ptr< InsertFieldRequest > request(new InsertFieldRequest(
        remoteFileName,
        requestField,
        STCONVERT("sections/0/paragraphs/0"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->insertField(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for putting field without node path.
/// </summary>
TEST_F(FieldTests, TestInsertFieldWithoutNodePath) {
    utility::string_t localFileName = STCONVERT("SampleWordDocument.docx");
    utility::string_t remoteFileName = STCONVERT("TestInsertFieldWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, textFolder + STCONVERT("/") + localFileName)
    );

    auto requestField = std::make_shared< FieldInsert >();
    requestField->setFieldCode(STCONVERT("{ NUMPAGES }"));

    std::shared_ptr< InsertFieldWithoutNodePathRequest > request(new InsertFieldWithoutNodePathRequest(
        remoteFileName,
        requestField,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->insertFieldWithoutNodePath(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for posting field.
/// </summary>
TEST_F(FieldTests, TestUpdateField) {
    utility::string_t localFileName = STCONVERT("GetField.docx");
    utility::string_t remoteFileName = STCONVERT("TestUpdateField.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, fieldFolder + STCONVERT("/") + localFileName)
    );

    auto requestField = std::make_shared< FieldUpdate >();
    requestField->setFieldCode(STCONVERT("{ NUMPAGES }"));

    std::shared_ptr< UpdateFieldRequest > request(new UpdateFieldRequest(
        remoteFileName,
        requestField,
        STCONVERT("sections/0/paragraphs/0"),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->updateField(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for inserting page numbers field.
/// </summary>
TEST_F(FieldTests, TestInsertPageNumbers) {
    utility::string_t localFileName = STCONVERT("test_multi_pages.docx");
    utility::string_t remoteFileName = STCONVERT("TestInsertPageNumbers.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, STCONVERT("Common/") + localFileName)
    );

    auto requestPageNumber = std::make_shared< PageNumber >();
    requestPageNumber->setAlignment(STCONVERT("center"));
    requestPageNumber->setFormat(STCONVERT("{PAGE} of {NUMPAGES}"));

    std::shared_ptr< InsertPageNumbersRequest > request(new InsertPageNumbersRequest(
        remoteFileName,
        requestPageNumber,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        baseTestOutPath + STCONVERT("/") + remoteFileName,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->insertPageNumbers(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting field.
/// </summary>
TEST_F(FieldTests, TestDeleteField) {
    utility::string_t localFileName = STCONVERT("GetField.docx");
    utility::string_t remoteFileName = STCONVERT("TestDeleteField.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, fieldFolder + STCONVERT("/") + localFileName)
    );

    std::shared_ptr< DeleteFieldRequest > request(new DeleteFieldRequest(
        remoteFileName,
        STCONVERT("sections/0/paragraphs/0"),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->deleteField(request).get();
}

/// <summary>
/// Test for deleting field without node path.
/// </summary>
TEST_F(FieldTests, TestDeleteFieldWithoutNodePath) {
    utility::string_t localFileName = STCONVERT("GetField.docx");
    utility::string_t remoteFileName = STCONVERT("TestDeleteFieldWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, fieldFolder + STCONVERT("/") + localFileName)
    );

    std::shared_ptr< DeleteFieldWithoutNodePathRequest > request(new DeleteFieldWithoutNodePathRequest(
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

   get_api()->deleteFieldWithoutNodePath(request).get();
}

/// <summary>
/// Test for deleting paragraph fields.
/// </summary>
TEST_F(FieldTests, TestDeleteParagraphFields) {
    utility::string_t localFileName = STCONVERT("test_multi_pages.docx");
    utility::string_t remoteFileName = STCONVERT("TestDeleteParagraphFields.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, STCONVERT("Common/") + localFileName)
    );

    std::shared_ptr< DeleteFieldsRequest > request(new DeleteFieldsRequest(
        remoteFileName,
        STCONVERT("paragraphs/0"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->deleteFields(request).get();
}

/// <summary>
/// Test for deleting paragraph fields without node path.
/// </summary>
TEST_F(FieldTests, TestDeleteParagraphFieldsWithoutNodePath) {
    utility::string_t localFileName = STCONVERT("test_multi_pages.docx");
    utility::string_t remoteFileName = STCONVERT("TestDeleteParagraphFieldsWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, STCONVERT("Common/") + localFileName)
    );

    std::shared_ptr< DeleteFieldsWithoutNodePathRequest > request(new DeleteFieldsWithoutNodePathRequest(
        remoteFileName,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->deleteFieldsWithoutNodePath(request).get();
}

/// <summary>
/// Test for deleting section fields.
/// </summary>
TEST_F(FieldTests, TestDeleteSectionFields) {
    utility::string_t localFileName = STCONVERT("test_multi_pages.docx");
    utility::string_t remoteFileName = STCONVERT("TestDeleteSectionFields.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, STCONVERT("Common/") + localFileName)
    );

    std::shared_ptr< DeleteFieldsRequest > request(new DeleteFieldsRequest(
        remoteFileName,
        STCONVERT("sections/0"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->deleteFields(request).get();
}

/// <summary>
/// Test for deleting section fields without node path.
/// </summary>
TEST_F(FieldTests, TestDeleteSectionFieldsWithoutNodePath) {
    utility::string_t localFileName = STCONVERT("test_multi_pages.docx");
    utility::string_t remoteFileName = STCONVERT("TestDeleteSectionFieldsWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, STCONVERT("Common/") + localFileName)
    );

    std::shared_ptr< DeleteFieldsWithoutNodePathRequest > request(new DeleteFieldsWithoutNodePathRequest(
        remoteFileName,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->deleteFieldsWithoutNodePath(request).get();
}

/// <summary>
/// Test for deleting paragraph fields in section.
/// </summary>
TEST_F(FieldTests, TestDeleteSectionParagraphFields) {
    utility::string_t localFileName = STCONVERT("test_multi_pages.docx");
    utility::string_t remoteFileName = STCONVERT("TestDeleteSectionParagraphFields.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, STCONVERT("Common/") + localFileName)
    );

    std::shared_ptr< DeleteFieldsRequest > request(new DeleteFieldsRequest(
        remoteFileName,
        STCONVERT("sections/0/paragraphs/0"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->deleteFields(request).get();
}

/// <summary>
/// Test for deleting fields.
/// </summary>
TEST_F(FieldTests, TestDeleteDocumentFields) {
    utility::string_t localFileName = STCONVERT("test_multi_pages.docx");
    utility::string_t remoteFileName = STCONVERT("TestDeleteSectionParagraphFields.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, STCONVERT("Common/") + localFileName)
    );

    std::shared_ptr< DeleteFieldsRequest > request(new DeleteFieldsRequest(
        remoteFileName,
        STCONVERT(""),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->deleteFields(request).get();
}

/// <summary>
/// Test for posting updated fields.
/// </summary>
TEST_F(FieldTests, TestUpdateDocumentFields) {
    utility::string_t localFileName = STCONVERT("test_multi_pages.docx");
    utility::string_t remoteFileName = STCONVERT("TestUpdateDocumentFields.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, STCONVERT("Common/") + localFileName)
    );

    std::shared_ptr< UpdateFieldsRequest > request(new UpdateFieldsRequest(
        remoteFileName,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->updateFields(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}
