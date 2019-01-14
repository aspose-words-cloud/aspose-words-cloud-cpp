#include "TestBase.h"
#include "../model/FormFieldTextInput.h"

/// <summary>
/// Example of how to work with form field
/// </summary>
class FormFieldTest : public InfrastructureTest {
protected:
	const utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements\\FormFields")),
		fieldFolder = STCONVERT("DocumentElements\\FormFields");
};

/// <summary>
/// Test for posting form field
/// </summary>
TEST_F(FormFieldTest, TestPostFormField)
{
	utility::string_t
		localName = STCONVERT("FormFilled.docx"),
		remoteName = STCONVERT("TestPostFormField.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(fieldFolder), localName),
		destFileName = path_combine_url(baseTestOutPath, remoteName);
	int32_t index = 0;

	std::shared_ptr<FormFieldTextInput> body(new FormFieldTextInput);
	body->setName(STCONVERT("FullName"));
	body->setEnabled(true);
	body->setCalculateOnExit(true);
	body->setStatusText(STCONVERT(""));
	body->setTextInputType(STCONVERT("Regular"));
	body->setTextInputDefault(STCONVERT(""));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PostFormFieldRequest> request(new PostFormFieldRequest(remoteName, body, index, dataFolder, boost::none,
		boost::none, boost::none, destFileName, boost::none, boost::none, STCONVERT("sections/0")));

	std::shared_ptr<FormFieldResponse> actual = get_api()->postFormField(request).get();
	std::shared_ptr<FormField> formField = actual->getFormField();

	ASSERT_EQ(200, actual->getCode());
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

	std::shared_ptr<GetFormFieldRequest> request(new GetFormFieldRequest(remoteName, index, dataFolder, boost::none,
		boost::none, boost::none, STCONVERT("sections/0")));

	std::shared_ptr<FormFieldResponse> actual = get_api()->getFormField(request).get();

	ASSERT_EQ(200, actual->getCode());
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

	std::shared_ptr<GetFormFieldsRequest> request(new GetFormFieldsRequest(remoteName, dataFolder, boost::none,
		boost::none, boost::none, STCONVERT("sections/0")));

	std::shared_ptr<FormFieldsResponse> actual = get_api()->getFormFields(request).get();

	auto formFields = actual->getFormFields()->getList();

	ASSERT_EQ(200, actual->getCode());


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
/// Test for putting form field
/// </summary>
TEST_F(FormFieldTest, TestPutFormField)
{
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPutFormField.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName),
		destFileName = path_combine_url(baseTestOutPath, remoteName);

	std::shared_ptr<FormFieldTextInput> body(new FormFieldTextInput);
	body->setName(STCONVERT("FullName"));
	body->setEnabled(true);
	body->setCalculateOnExit(true);
	body->setStatusText(STCONVERT(""));
	body->setTextInputType(STCONVERT("Regular"));
	body->setTextInputDefault(STCONVERT("123"));
	body->setTextInputFormat(STCONVERT("UPPERCASE"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PutFormFieldRequest> request(new PutFormFieldRequest(remoteName, body, dataFolder, boost::none,
		boost::none, boost::none, destFileName, boost::none, boost::none, STCONVERT("sections/0/paragraphs/0"), boost::none));

	std::shared_ptr<FormFieldResponse> actual = get_api()->putFormField(request).get();

	ASSERT_EQ(200, actual->getCode());
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

	std::shared_ptr<DeleteFormFieldRequest> request(new DeleteFormFieldRequest(remoteName, index, dataFolder, boost::none,
		boost::none, boost::none, destFileName, boost::none, boost::none, STCONVERT("sections/0")));

	std::shared_ptr<AsposeResponse> actual = get_api()->deleteFormField(request).get();
	ASSERT_EQ(200, actual->getCode());
}