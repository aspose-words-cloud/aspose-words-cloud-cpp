/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="form_field_test.h">
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
#include "../test_base.h"

/// <summary>
/// Example of how to work with form field.
/// </summary>
class FormFieldTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentElements/FormFields";
    std::wstring fieldFolder = L"DocumentElements/FormFields";

};

/// <summary>
/// Test for posting form field.
/// </summary>
TEST_F(FormFieldTests, TestUpdateFormField) {
    std::wstring remoteFileName = L"TestUpdateFormField.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + fieldFolder + L"/FormFilled.docx",
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestFormField = std::make_shared< aspose::words::cloud::models::FormFieldTextInput >();
    requestFormField->setName(std::make_shared< std::wstring >(L"FullName"));
    requestFormField->setEnabled(std::make_shared< bool >(true));
    requestFormField->setCalculateOnExit(std::make_shared< bool >(true));
    requestFormField->setStatusText(std::make_shared< std::wstring >(L""));
    requestFormField->setTextInputType(std::make_shared< aspose::words::cloud::models::FormFieldTextInput::TextInputType >(aspose::words::cloud::models::FormFieldTextInput::TextInputType::REGULAR));
    requestFormField->setTextInputDefault(std::make_shared< std::wstring >(L"No name"));
    std::shared_ptr<requests::UpdateFormFieldRequest> request(new requests::UpdateFormFieldRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        requestFormField,
        std::make_shared< std::wstring >(L"sections/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateFormField(request);
    ASSERT_TRUE(actual->getFormField() != nullptr);
    ASSERT_TRUE(actual->getFormField()->getName()->compare(L"FullName") == 0);
    ASSERT_TRUE(actual->getFormField()->getStatusText()->compare(L"") == 0);
}

/// <summary>
/// Test for posting form field online.
/// </summary>
TEST_F(FormFieldTests, TestUpdateFormFieldOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(fieldFolder + L"/FormFilled.docx")), std::istream::binary));
    auto requestFormField = std::make_shared< aspose::words::cloud::models::FormFieldTextInput >();
    requestFormField->setName(std::make_shared< std::wstring >(L"FullName"));
    requestFormField->setEnabled(std::make_shared< bool >(true));
    requestFormField->setCalculateOnExit(std::make_shared< bool >(true));
    requestFormField->setStatusText(std::make_shared< std::wstring >(L""));
    requestFormField->setTextInputType(std::make_shared< aspose::words::cloud::models::FormFieldTextInput::TextInputType >(aspose::words::cloud::models::FormFieldTextInput::TextInputType::REGULAR));
    requestFormField->setTextInputDefault(std::make_shared< std::wstring >(L"No name"));
    std::shared_ptr<requests::UpdateFormFieldOnlineRequest> request(new requests::UpdateFormFieldOnlineRequest(
        requestDocument,
        requestFormField,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L"sections/0"),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateFormFieldOnline(request);
}

/// <summary>
/// Test for posting form field without node path.
/// </summary>
TEST_F(FormFieldTests, TestUpdateFormFieldWithoutNodePath) {
    std::wstring remoteFileName = L"TestUpdateFormFieldWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + fieldFolder + L"/FormFilled.docx",
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestFormField = std::make_shared< aspose::words::cloud::models::FormFieldTextInput >();
    requestFormField->setName(std::make_shared< std::wstring >(L"FullName"));
    requestFormField->setEnabled(std::make_shared< bool >(true));
    requestFormField->setCalculateOnExit(std::make_shared< bool >(true));
    requestFormField->setStatusText(std::make_shared< std::wstring >(L""));
    requestFormField->setTextInputType(std::make_shared< aspose::words::cloud::models::FormFieldTextInput::TextInputType >(aspose::words::cloud::models::FormFieldTextInput::TextInputType::REGULAR));
    requestFormField->setTextInputDefault(std::make_shared< std::wstring >(L"No name"));
    std::shared_ptr<requests::UpdateFormFieldRequest> request(new requests::UpdateFormFieldRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        requestFormField,
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateFormField(request);
    ASSERT_TRUE(actual->getFormField() != nullptr);
    ASSERT_TRUE(actual->getFormField()->getName()->compare(L"FullName") == 0);
    ASSERT_TRUE(actual->getFormField()->getStatusText()->compare(L"") == 0);
}

/// <summary>
/// Test for getting form field.
/// </summary>
TEST_F(FormFieldTests, TestGetFormField) {
    std::wstring remoteFileName = L"TestGetFormField.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + fieldFolder + L"/FormFilled.docx",
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetFormFieldRequest> request(new requests::GetFormFieldRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L"sections/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getFormField(request);
    ASSERT_TRUE(actual->getFormField() != nullptr);
    ASSERT_TRUE(actual->getFormField()->getName()->compare(L"FullName") == 0);
}

/// <summary>
/// Test for getting form field online.
/// </summary>
TEST_F(FormFieldTests, TestGetFormFieldOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(fieldFolder + L"/FormFilled.docx")), std::istream::binary));
    std::shared_ptr<requests::GetFormFieldOnlineRequest> request(new requests::GetFormFieldOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L"sections/0"),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getFormFieldOnline(request);
}

/// <summary>
/// Test for getting form field without node path.
/// </summary>
TEST_F(FormFieldTests, TestGetFormFieldWithoutNodePath) {
    std::wstring remoteFileName = L"TestGetFormFieldWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + fieldFolder + L"/FormFilled.docx",
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetFormFieldRequest> request(new requests::GetFormFieldRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getFormField(request);
    ASSERT_TRUE(actual->getFormField() != nullptr);
    ASSERT_TRUE(actual->getFormField()->getName()->compare(L"FullName") == 0);
}

/// <summary>
/// Test for getting form fields.
/// </summary>
TEST_F(FormFieldTests, TestGetFormFields) {
    std::wstring remoteFileName = L"TestGetFormFields.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + fieldFolder + L"/FormFilled.docx",
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetFormFieldsRequest> request(new requests::GetFormFieldsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"sections/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getFormFields(request);
    ASSERT_TRUE(actual->getFormFields() != nullptr);
    ASSERT_TRUE(actual->getFormFields()->getList() != nullptr);
    ASSERT_EQ(5, actual->getFormFields()->getList()->size());
    ASSERT_TRUE(actual->getFormFields()->getList()->at(0)->getName()->compare(L"FullName") == 0);
}

/// <summary>
/// Test for getting form fields online.
/// </summary>
TEST_F(FormFieldTests, TestGetFormFieldsOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(fieldFolder + L"/FormFilled.docx")), std::istream::binary));
    std::shared_ptr<requests::GetFormFieldsOnlineRequest> request(new requests::GetFormFieldsOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"sections/0"),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getFormFieldsOnline(request);
}

/// <summary>
/// Test for getting form fields without node path.
/// </summary>
TEST_F(FormFieldTests, TestGetFormFieldsWithoutNodePath) {
    std::wstring remoteFileName = L"TestGetFormFieldsWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + fieldFolder + L"/FormFilled.docx",
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetFormFieldsRequest> request(new requests::GetFormFieldsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getFormFields(request);
    ASSERT_TRUE(actual->getFormFields() != nullptr);
    ASSERT_TRUE(actual->getFormFields()->getList() != nullptr);
    ASSERT_EQ(5, actual->getFormFields()->getList()->size());
    ASSERT_TRUE(actual->getFormFields()->getList()->at(0)->getName()->compare(L"FullName") == 0);
}

/// <summary>
/// Test for insert form field without node path.
/// </summary>
TEST_F(FormFieldTests, TestInsertFormField) {
    std::wstring remoteFileName = L"TestInsertFormField.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + L"Common/test_multi_pages.docx",
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestFormField = std::make_shared< aspose::words::cloud::models::FormFieldTextInput >();
    requestFormField->setName(std::make_shared< std::wstring >(L"FullName"));
    requestFormField->setEnabled(std::make_shared< bool >(true));
    requestFormField->setCalculateOnExit(std::make_shared< bool >(true));
    requestFormField->setStatusText(std::make_shared< std::wstring >(L""));
    requestFormField->setTextInputType(std::make_shared< aspose::words::cloud::models::FormFieldTextInput::TextInputType >(aspose::words::cloud::models::FormFieldTextInput::TextInputType::REGULAR));
    requestFormField->setTextInputDefault(std::make_shared< std::wstring >(L"123"));
    requestFormField->setTextInputFormat(std::make_shared< std::wstring >(L"UPPERCASE"));
    std::shared_ptr<requests::InsertFormFieldRequest> request(new requests::InsertFormFieldRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestFormField,
        std::make_shared< std::wstring >(L"sections/0/paragraphs/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertFormField(request);
    ASSERT_TRUE(actual->getFormField() != nullptr);
    ASSERT_TRUE(actual->getFormField()->getName()->compare(L"FullName") == 0);
    ASSERT_TRUE(actual->getFormField()->getStatusText()->compare(L"") == 0);
}

/// <summary>
/// Test for insert form field without node path online.
/// </summary>
TEST_F(FormFieldTests, TestInsertFormFieldOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(fieldFolder + L"/FormFilled.docx")), std::istream::binary));
    auto requestFormField = std::make_shared< aspose::words::cloud::models::FormFieldTextInput >();
    requestFormField->setName(std::make_shared< std::wstring >(L"FullName"));
    requestFormField->setEnabled(std::make_shared< bool >(true));
    requestFormField->setCalculateOnExit(std::make_shared< bool >(true));
    requestFormField->setStatusText(std::make_shared< std::wstring >(L""));
    requestFormField->setTextInputType(std::make_shared< aspose::words::cloud::models::FormFieldTextInput::TextInputType >(aspose::words::cloud::models::FormFieldTextInput::TextInputType::REGULAR));
    requestFormField->setTextInputDefault(std::make_shared< std::wstring >(L"123"));
    requestFormField->setTextInputFormat(std::make_shared< std::wstring >(L"UPPERCASE"));
    std::shared_ptr<requests::InsertFormFieldOnlineRequest> request(new requests::InsertFormFieldOnlineRequest(
        requestDocument,
        requestFormField,
        std::make_shared< std::wstring >(L"sections/0/paragraphs/0"),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertFormFieldOnline(request);
}

/// <summary>
/// Test for insert form field without node path.
/// </summary>
TEST_F(FormFieldTests, TestInsertFormFieldWithoutNodePath) {
    std::wstring remoteFileName = L"TestInsertFormFieldWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + L"Common/test_multi_pages.docx",
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestFormField = std::make_shared< aspose::words::cloud::models::FormFieldTextInput >();
    requestFormField->setName(std::make_shared< std::wstring >(L"FullName"));
    requestFormField->setEnabled(std::make_shared< bool >(true));
    requestFormField->setCalculateOnExit(std::make_shared< bool >(true));
    requestFormField->setStatusText(std::make_shared< std::wstring >(L""));
    requestFormField->setTextInputType(std::make_shared< aspose::words::cloud::models::FormFieldTextInput::TextInputType >(aspose::words::cloud::models::FormFieldTextInput::TextInputType::REGULAR));
    requestFormField->setTextInputDefault(std::make_shared< std::wstring >(L"123"));
    requestFormField->setTextInputFormat(std::make_shared< std::wstring >(L"UPPERCASE"));
    std::shared_ptr<requests::InsertFormFieldRequest> request(new requests::InsertFormFieldRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestFormField,
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertFormField(request);
    ASSERT_TRUE(actual->getFormField() != nullptr);
    ASSERT_TRUE(actual->getFormField()->getName()->compare(L"FullName") == 0);
    ASSERT_TRUE(actual->getFormField()->getStatusText()->compare(L"") == 0);
}

/// <summary>
/// Test for deleting form field.
/// </summary>
TEST_F(FormFieldTests, TestDeleteFormField) {
    std::wstring remoteFileName = L"TestDeleteFormField.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + fieldFolder + L"/FormFilled.docx",
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteFormFieldRequest> request(new requests::DeleteFormFieldRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L"sections/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName),
        nullptr,
        nullptr
    ));

getApi()->deleteFormField(request);
}

/// <summary>
/// Test for deleting form field online.
/// </summary>
TEST_F(FormFieldTests, TestDeleteFormFieldOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(fieldFolder + L"/FormFilled.docx")), std::istream::binary));
    std::shared_ptr<requests::DeleteFormFieldOnlineRequest> request(new requests::DeleteFormFieldOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L"sections/0"),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteFormFieldOnline(request);
}

/// <summary>
/// Test for deleting form field without node path.
/// </summary>
TEST_F(FormFieldTests, TestDeleteFormFieldWithoutNodePath) {
    std::wstring remoteFileName = L"TestDeleteFormFieldWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + fieldFolder + L"/FormFilled.docx",
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteFormFieldRequest> request(new requests::DeleteFormFieldRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName),
        nullptr,
        nullptr
    ));

getApi()->deleteFormField(request);
}
