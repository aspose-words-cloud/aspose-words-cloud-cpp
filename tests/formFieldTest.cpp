/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="formFieldTest.cpp">
*   Copyright (c) 2019 Aspose.Words for Cloud
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
#include "TestBase.h"
#include "../model/FormFieldTextInput.h"

/// <summary>
/// Example of how to work with form field
/// </summary>
class FormFieldTest : public InfrastructureTest {
protected:
	const utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements/FormFields")),
		fieldFolder = STCONVERT("DocumentElements/FormFields");
};

/// <summary>
/// Test for updating form field
/// </summary>
TEST_F(FormFieldTest, TestPutFormField)
{
	utility::string_t
		localName = STCONVERT("FormFilled.docx"),
		remoteName = STCONVERT("TestPostFormField.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(fieldFolder), localName),
		destFileName = path_combine_url(baseTestOutPath, remoteName);
	int32_t index = 0;

	std::shared_ptr<FormFieldTextInput> body= std::make_shared<FormFieldTextInput>();
	body->setName(STCONVERT("FullName"));
	body->setEnabled(true);
	body->setCalculateOnExit(true);
	body->setStatusText(STCONVERT(""));
	body->setTextInputType(STCONVERT("Regular"));
	body->setTextInputDefault(STCONVERT(""));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<UpdateFormFieldRequest> request= std::make_shared<UpdateFormFieldRequest>(remoteName, body, STCONVERT("sections/0"), index, dataFolder, boost::none,
		boost::none, boost::none, destFileName, boost::none, boost::none);

	AsposeResponse<FormFieldResponse> actual = get_api()->updateFormField(request).get();
	std::shared_ptr<FormField> formField = actual.body->getFormField();

	ASSERT_EQ(200, actual.httpResponse->status_code());
	ASSERT_EQ(STCONVERT("FullName"), formField->getName());
	ASSERT_TRUE(formField->isEnabled());
	body = std::static_pointer_cast<FormFieldTextInput>(formField);
	ASSERT_TRUE(body != nullptr);
	ASSERT_EQ(STCONVERT("Regular"), body->getTextInputType());
}

/// <summary>
/// Test for getting form field
/// </summary>
TEST_F(FormFieldTest, TestGetFormField)
{
	utility::string_t
		localName = STCONVERT("FormFilled.docx"),
		remoteName = STCONVERT("TestGetFormField.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(fieldFolder), localName);

	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetFormFieldRequest> request= std::make_shared<GetFormFieldRequest>(remoteName, STCONVERT("sections/0"), index, dataFolder, boost::none,
		boost::none, boost::none);

	AsposeResponse<FormFieldResponse> actual = get_api()->getFormField(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
///  Test for getting form fields
/// </summary>        
TEST_F(FormFieldTest, TestGetFormFields)
{
	utility::string_t
		localName = STCONVERT("FormFilled.docx"),
		remoteName = STCONVERT("TestGetFormFields.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(fieldFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetFormFieldsRequest> request= std::make_shared<GetFormFieldsRequest>(remoteName, STCONVERT("sections/0"), dataFolder, boost::none,
		boost::none, boost::none);

	AsposeResponse<FormFieldsResponse> actual = get_api()->getFormFields(request).get();

	auto formFields = actual.body->getFormFields()->getList();

	ASSERT_EQ(200, actual.httpResponse->status_code());


	std::shared_ptr<FormFieldTextInput> input1 = std::static_pointer_cast<FormFieldTextInput>(formFields.at(0)),
		input2 = std::static_pointer_cast<FormFieldTextInput>(formFields.at(1)),
		input3 = std::static_pointer_cast<FormFieldTextInput>(formFields.at(2));

	ASSERT_EQ(STCONVERT("Regular"), input1->getTextInputType());
	ASSERT_EQ(STCONVERT("Date"), input2->getTextInputType());
	ASSERT_EQ(STCONVERT("Number"), input3->getTextInputType());

	std::shared_ptr<FormFieldCheckbox> checkbox = std::static_pointer_cast<FormFieldCheckbox>(formFields.at(3));
	ASSERT_EQ(10, checkbox->getCheckBoxSize());

	std::shared_ptr<FormFieldDropDown> dropDown = std::static_pointer_cast<FormFieldDropDown>(formFields.at(4));
	ASSERT_TRUE(dropDown->getDropDownItems().size() > 0);
}

/// <summary>
/// Test for inserting form field
/// </summary>
TEST_F(FormFieldTest, TestPostFormField)
{
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPutFormField.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName),
		destFileName = path_combine_url(baseTestOutPath, remoteName);

	std::shared_ptr<FormFieldTextInput> body= std::make_shared<FormFieldTextInput>();
	body->setName(STCONVERT("FullName"));
	body->setEnabled(true);
	body->setCalculateOnExit(true);
	body->setStatusText(STCONVERT(""));
	body->setTextInputType(STCONVERT("Regular"));
	body->setTextInputDefault(STCONVERT("123"));
	body->setTextInputFormat(STCONVERT("UPPERCASE"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<InsertFormFieldRequest> request=
			std::make_shared<InsertFormFieldRequest>(remoteName, body, STCONVERT("sections/0/paragraphs/0"), dataFolder, boost::none,
		boost::none, boost::none, destFileName, boost::none, boost::none, boost::none);

	AsposeResponse<FormFieldResponse> actual = get_api()->insertFormField(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting form field
/// </summary>
TEST_F(FormFieldTest, TestDeleteFormField)
{
	utility::string_t
		localName = STCONVERT("FormFilled.docx"),
		remoteName = STCONVERT("TestDeleteFormField.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(fieldFolder), localName),
		destFileName = path_combine_url(baseTestOutPath, remoteName);
	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteFormFieldRequest> request= std::make_shared<DeleteFormFieldRequest>(remoteName, STCONVERT("sections/0"), index, dataFolder, boost::none,
		boost::none, boost::none, destFileName, boost::none, boost::none);

	std::shared_ptr<web::http::http_response> actual = get_api()->deleteFormField(request).get();
	ASSERT_EQ(200, actual->status_code());
}

/// <summary>
/// Test for updating form field
/// </summary>
TEST_F(FormFieldTest, TestPutFormFieldWithoutNodePath)
{
	utility::string_t
		localName = STCONVERT("FormFilled.docx"),
		remoteName = STCONVERT("TestPostFormFieldWithoutNodePath.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(fieldFolder), localName),
		destFileName = path_combine_url(baseTestOutPath, remoteName);
	int32_t index = 0;

	std::shared_ptr<FormFieldTextInput> body = std::make_shared<FormFieldTextInput>();
	body->setName(STCONVERT("FullName"));
	body->setEnabled(true);
	body->setCalculateOnExit(true);
	body->setStatusText(STCONVERT(""));
	body->setTextInputType(STCONVERT("Regular"));
	body->setTextInputDefault(STCONVERT(""));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<UpdateFormFieldWithoutNodePathRequest> request = std::make_shared<UpdateFormFieldWithoutNodePathRequest>(remoteName, body, index, dataFolder, boost::none,
		boost::none, boost::none, destFileName, boost::none, boost::none);

	AsposeResponse<FormFieldResponse> actual = get_api()->updateFormFieldWithoutNodePath(request).get();
	std::shared_ptr<FormField> formField = actual.body->getFormField();

	ASSERT_EQ(200, actual.httpResponse->status_code());
	ASSERT_EQ(STCONVERT("FullName"), formField->getName());
	ASSERT_TRUE(formField->isEnabled());
	body = std::static_pointer_cast<FormFieldTextInput>(formField);
	ASSERT_TRUE(body != nullptr);
	ASSERT_EQ(STCONVERT("Regular"), body->getTextInputType());
}

/// <summary>
/// Test for getting form field
/// </summary>
TEST_F(FormFieldTest, TestGetFormFieldWithoutNodePath)
{
	utility::string_t
		localName = STCONVERT("FormFilled.docx"),
		remoteName = STCONVERT("TestGetFormFieldWithoutNodePath.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(fieldFolder), localName);

	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetFormFieldWithoutNodePathRequest> request = std::make_shared<GetFormFieldWithoutNodePathRequest>(remoteName, index, dataFolder, boost::none,
		boost::none, boost::none);

	AsposeResponse<FormFieldResponse> actual = get_api()->getFormFieldWithoutNodePath(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
///  Test for getting form fields
/// </summary>        
TEST_F(FormFieldTest, TestGetFormFieldsWithoutNodePath)
{
	utility::string_t
		localName = STCONVERT("FormFilled.docx"),
		remoteName = STCONVERT("TestGetFormFieldsWithoutNodePath.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(fieldFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetFormFieldsWithoutNodePathRequest> request = std::make_shared<GetFormFieldsWithoutNodePathRequest>(remoteName, dataFolder, boost::none,
		boost::none, boost::none);

	AsposeResponse<FormFieldsResponse> actual = get_api()->getFormFieldsWithoutNodePath(request).get();

	auto formFields = actual.body->getFormFields()->getList();

	ASSERT_EQ(200, actual.httpResponse->status_code());


	std::shared_ptr<FormFieldTextInput> input1 = std::static_pointer_cast<FormFieldTextInput>(formFields.at(0)),
		input2 = std::static_pointer_cast<FormFieldTextInput>(formFields.at(1)),
		input3 = std::static_pointer_cast<FormFieldTextInput>(formFields.at(2));

	ASSERT_EQ(STCONVERT("Regular"), input1->getTextInputType());
	ASSERT_EQ(STCONVERT("Date"), input2->getTextInputType());
	ASSERT_EQ(STCONVERT("Number"), input3->getTextInputType());

	std::shared_ptr<FormFieldCheckbox> checkbox = std::static_pointer_cast<FormFieldCheckbox>(formFields.at(3));
	ASSERT_EQ(10, checkbox->getCheckBoxSize());

	std::shared_ptr<FormFieldDropDown> dropDown = std::static_pointer_cast<FormFieldDropDown>(formFields.at(4));
	ASSERT_TRUE(dropDown->getDropDownItems().size() > 0);
}

/// <summary>
/// Test for inserting form field
/// </summary>
TEST_F(FormFieldTest, TestPostFormFieldWithoutNodePath)
{
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPutFormFieldWithoutNodePath.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName),
		destFileName = path_combine_url(baseTestOutPath, remoteName);

	std::shared_ptr<FormFieldTextInput> body = std::make_shared<FormFieldTextInput>();
	body->setName(STCONVERT("FullName"));
	body->setEnabled(true);
	body->setCalculateOnExit(true);
	body->setStatusText(STCONVERT(""));
	body->setTextInputType(STCONVERT("Regular"));
	body->setTextInputDefault(STCONVERT("123"));
	body->setTextInputFormat(STCONVERT("UPPERCASE"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<InsertFormFieldWithoutNodePathRequest> request =
		std::make_shared<InsertFormFieldWithoutNodePathRequest>(remoteName, body, dataFolder, boost::none,
			boost::none, boost::none, destFileName, boost::none, boost::none, boost::none);

	AsposeResponse<FormFieldResponse> actual = get_api()->insertFormFieldWithoutNodePath(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting form field
/// </summary>
TEST_F(FormFieldTest, TestDeleteFormFieldWithoutNodePath)
{
	utility::string_t
		localName = STCONVERT("FormFilled.docx"),
		remoteName = STCONVERT("TestDeleteFormFieldWithoutNodePath.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(fieldFolder), localName),
		destFileName = path_combine_url(baseTestOutPath, remoteName);
	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteFormFieldWithoutNodePathRequest> request = std::make_shared<DeleteFormFieldWithoutNodePathRequest>(remoteName, index, dataFolder, boost::none,
		boost::none, boost::none, destFileName, boost::none, boost::none);

	std::shared_ptr<web::http::http_response> actual = get_api()->deleteFormFieldWithoutNodePath(request).get();
	ASSERT_EQ(200, actual->status_code());
}