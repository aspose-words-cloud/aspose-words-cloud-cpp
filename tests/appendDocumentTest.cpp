#include "TestBase.h"

class AppendDocumentTest : public InfrastructureTest
{
protected:
	utility::string_t get_data_folder() override {
		return path_combine_url(STCONVERT("Temp\\SdkTests\\TestData"), STCONVERT("DocumentActions\\AppendDocument"));
	}
};

/// <summary>
/// Test for appending document
/// </summary>
TEST_F(AppendDocumentTest, TestPostAppendDocument) {
	utility::string_t localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPostAppendDocument.docx"),
		fullName = path_combine(get_data_folder(), remoteName),
		destFileName = path_combine_url(baseTestOutPath, remoteName);
	utility::string_t filePath = path_combine(get_data_dir(commonFolder), localName);
	std::shared_ptr<DocumentEntryList> body= std::make_shared<DocumentEntryList>();
	std::shared_ptr<DocumentEntry> entry= std::make_shared<DocumentEntry>();
	entry->setHref(fullName);
	entry->setImportFormatMode(STCONVERT("KeepSourceFormatting"));

	std::vector<std::shared_ptr<DocumentEntry>> entries;
	entries.push_back(entry);
	body->setDocumentEntries(entries);

	UploadFileToStorage(fullName, filePath);

    std::shared_ptr<PostAppendDocumentRequest> request= std::make_shared<PostAppendDocumentRequest>(remoteName, body, get_data_folder(), boost::none,
		boost::none, boost::none, destFileName, boost::none, boost::none);
	auto requestTask = get_api()->postAppendDocument(request);
	std::shared_ptr<DocumentResponse> actual = requestTask.get();

	ASSERT_EQ(200, actual->getCode());
}
