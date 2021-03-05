/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="formFieldTests.cpp">
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
/// Example of how to work with form field.
/// </summary>
class FormFieldTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentElements/FormFields");
    utility::string_t fieldFolder = STCONVERT("DocumentElements/FormFields");

};

/// <summary>
/// Test for posting form field.
/// </summary>
TEST_F(FormFieldTests, TestUpdateFormField) {
    utility::string_t remoteFileName = STCONVERT("TestUpdateFormField.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, fieldFolder + STCONVERT("/FormFilled.docx"))
    );

    auto requestFormField = std::make_shared< FormFieldTextInput >();
    requestFormField->setName(STCONVERT("FullName"));
    requestFormField->setEnabled(true);
    requestFormField->setCalculateOnExit(true);
    requestFormField->setStatusText(STCONVERT(""));
    requestFormField->setTextInputType(STCONVERT("Regular"));
    requestFormField->setTextInputDefault(STCONVERT("No name"));

    std::shared_ptr< UpdateFormFieldRequest > request(new UpdateFormFieldRequest(
        remoteFileName,
        0,
        requestFormField,
        STCONVERT("sections/0"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        baseTestOutPath + STCONVERT("/") + remoteFileName,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->updateFormField(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getFormField()));
   ASSERT_EQ(STCONVERT("FullName"), actual.body->getFormField()->getName());
   ASSERT_EQ(STCONVERT(""), actual.body->getFormField()->getStatusText());
}



/// <summary>
/// Test for posting form field without node path.
/// </summary>
TEST_F(FormFieldTests, TestUpdateFormFieldWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestUpdateFormFieldWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, fieldFolder + STCONVERT("/FormFilled.docx"))
    );

    auto requestFormField = std::make_shared< FormFieldTextInput >();
    requestFormField->setName(STCONVERT("FullName"));
    requestFormField->setEnabled(true);
    requestFormField->setCalculateOnExit(true);
    requestFormField->setStatusText(STCONVERT(""));
    requestFormField->setTextInputType(STCONVERT("Regular"));
    requestFormField->setTextInputDefault(STCONVERT("No name"));

    std::shared_ptr< UpdateFormFieldRequest > request(new UpdateFormFieldRequest(
        remoteFileName,
        0,
        requestFormField,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        baseTestOutPath + STCONVERT("/") + remoteFileName,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->updateFormField(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getFormField()));
   ASSERT_EQ(STCONVERT("FullName"), actual.body->getFormField()->getName());
   ASSERT_EQ(STCONVERT(""), actual.body->getFormField()->getStatusText());
}

/// <summary>
/// Test for getting form field.
/// </summary>
TEST_F(FormFieldTests, TestGetFormField) {
    utility::string_t remoteFileName = STCONVERT("TestGetFormField.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, fieldFolder + STCONVERT("/FormFilled.docx"))
    );

    std::shared_ptr< GetFormFieldRequest > request(new GetFormFieldRequest(
        remoteFileName,
        0,
        STCONVERT("sections/0"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getFormField(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getFormField()));
   ASSERT_EQ(STCONVERT("FullName"), actual.body->getFormField()->getName());
}



/// <summary>
/// Test for getting form field without node path.
/// </summary>
TEST_F(FormFieldTests, TestGetFormFieldWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestGetFormFieldWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, fieldFolder + STCONVERT("/FormFilled.docx"))
    );

    std::shared_ptr< GetFormFieldRequest > request(new GetFormFieldRequest(
        remoteFileName,
        0,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getFormField(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getFormField()));
   ASSERT_EQ(STCONVERT("FullName"), actual.body->getFormField()->getName());
}

/// <summary>
/// Test for getting form fields.
/// </summary>
TEST_F(FormFieldTests, TestGetFormFields) {
    utility::string_t remoteFileName = STCONVERT("TestGetFormFields.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, fieldFolder + STCONVERT("/FormFilled.docx"))
    );

    std::shared_ptr< GetFormFieldsRequest > request(new GetFormFieldsRequest(
        remoteFileName,
        STCONVERT("sections/0"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getFormFields(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getFormFields()));
   ASSERT_TRUE(IsNotNull(actual.body->getFormFields()->getList()));
   ASSERT_EQ(5, actual.body->getFormFields()->getList().size());
   ASSERT_EQ(STCONVERT("FullName"), actual.body->getFormFields()->getList()[0]->getName());
}



/// <summary>
/// Test for getting form fields without node path.
/// </summary>
TEST_F(FormFieldTests, TestGetFormFieldsWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestGetFormFieldsWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, fieldFolder + STCONVERT("/FormFilled.docx"))
    );

    std::shared_ptr< GetFormFieldsRequest > request(new GetFormFieldsRequest(
        remoteFileName,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getFormFields(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getFormFields()));
   ASSERT_TRUE(IsNotNull(actual.body->getFormFields()->getList()));
   ASSERT_EQ(5, actual.body->getFormFields()->getList().size());
   ASSERT_EQ(STCONVERT("FullName"), actual.body->getFormFields()->getList()[0]->getName());
}

/// <summary>
/// Test for insert form field without node path.
/// </summary>
TEST_F(FormFieldTests, TestInsertFormField) {
    utility::string_t remoteFileName = STCONVERT("TestInsertFormField.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, STCONVERT("Common/test_multi_pages.docx"))
    );

    auto requestFormField = std::make_shared< FormFieldTextInput >();
    requestFormField->setName(STCONVERT("FullName"));
    requestFormField->setEnabled(true);
    requestFormField->setCalculateOnExit(true);
    requestFormField->setStatusText(STCONVERT(""));
    requestFormField->setTextInputType(STCONVERT("Regular"));
    requestFormField->setTextInputDefault(STCONVERT("123"));
    requestFormField->setTextInputFormat(STCONVERT("UPPERCASE"));

    std::shared_ptr< InsertFormFieldRequest > request(new InsertFormFieldRequest(
        remoteFileName,
        requestFormField,
        STCONVERT("sections/0/paragraphs/0"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        baseTestOutPath + STCONVERT("/") + remoteFileName,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->insertFormField(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getFormField()));
   ASSERT_EQ(STCONVERT("FullName"), actual.body->getFormField()->getName());
   ASSERT_EQ(STCONVERT(""), actual.body->getFormField()->getStatusText());
}



/// <summary>
/// Test for insert form field without node path.
/// </summary>
TEST_F(FormFieldTests, TestInsertFormFieldWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestInsertFormFieldWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, STCONVERT("Common/test_multi_pages.docx"))
    );

    auto requestFormField = std::make_shared< FormFieldTextInput >();
    requestFormField->setName(STCONVERT("FullName"));
    requestFormField->setEnabled(true);
    requestFormField->setCalculateOnExit(true);
    requestFormField->setStatusText(STCONVERT(""));
    requestFormField->setTextInputType(STCONVERT("Regular"));
    requestFormField->setTextInputDefault(STCONVERT("123"));
    requestFormField->setTextInputFormat(STCONVERT("UPPERCASE"));

    std::shared_ptr< InsertFormFieldRequest > request(new InsertFormFieldRequest(
        remoteFileName,
        requestFormField,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        baseTestOutPath + STCONVERT("/") + remoteFileName,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->insertFormField(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getFormField()));
   ASSERT_EQ(STCONVERT("FullName"), actual.body->getFormField()->getName());
   ASSERT_EQ(STCONVERT(""), actual.body->getFormField()->getStatusText());
}

/// <summary>
/// Test for deleting form field.
/// </summary>
TEST_F(FormFieldTests, TestDeleteFormField) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteFormField.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, fieldFolder + STCONVERT("/FormFilled.docx"))
    );

    std::shared_ptr< DeleteFormFieldRequest > request(new DeleteFormFieldRequest(
        remoteFileName,
        0,
        STCONVERT("sections/0"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        baseTestOutPath + STCONVERT("/") + remoteFileName,
        boost::none,
        boost::none
    ));

   get_api()->deleteFormField(request).get();
}



/// <summary>
/// Test for deleting form field without node path.
/// </summary>
TEST_F(FormFieldTests, TestDeleteFormFieldWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteFormFieldWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, fieldFolder + STCONVERT("/FormFilled.docx"))
    );

    std::shared_ptr< DeleteFormFieldRequest > request(new DeleteFormFieldRequest(
        remoteFileName,
        0,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        baseTestOutPath + STCONVERT("/") + remoteFileName,
        boost::none,
        boost::none
    ));

   get_api()->deleteFormField(request).get();
}
