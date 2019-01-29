#include "TestBase.h"
class ClassificationTests : public InfrastructureTest
{
protected:
	utility::string_t get_data_folder() override {
		return path_combine_url(STCONVERT("Temp\\SdkTests\\TestData"), commonFolder);
	}
};

/// <summary>
/// Test for raw text classification
/// </summary>
TEST_F(ClassificationTests, TestClassify) {
	std::shared_ptr<ClassifyRequest> request=
			std::make_shared<ClassifyRequest>(STCONVERT("Try text classification"), STCONVERT("3"));
	auto requestTask = get_api()->classify(request);
	std::shared_ptr<ClassificationResponse> actual = requestTask.get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for document classification.
/// </summary>
TEST_F(ClassificationTests, TestClassifyDocument) {
	utility::string_t localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("Source.docx"),
		fullName = path_combine(get_data_folder(), remoteName);
	utility::string_t filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<ClassifyDocumentRequest> request=
			std::make_shared<ClassifyDocumentRequest>(remoteName, get_data_folder(),
		boost::none, boost::none, boost::none, STCONVERT("3"), boost::none);
	auto requestTask = get_api()->classifyDocument(request);
	std::shared_ptr<ClassificationResponse> actual = requestTask.get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for document classification with taxonomy "documents".
/// </summary>
TEST_F(ClassificationTests, TestClassifyTaxonomyDocuments) {
	utility::string_t localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("Source.docx"),
		taxonomy = STCONVERT("documents"),
		fullName = path_combine(get_data_folder(), remoteName);
	utility::string_t filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<ClassifyDocumentRequest> request= std::make_shared<ClassifyDocumentRequest>(remoteName, get_data_folder(),
		boost::none, boost::none, boost::none, STCONVERT("3"), taxonomy);
	auto requestTask = get_api()->classifyDocument(request);
	std::shared_ptr<ClassificationResponse> actual = requestTask.get();

	ASSERT_EQ(200, actual->getCode());
}
