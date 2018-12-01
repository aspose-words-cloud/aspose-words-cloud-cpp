#include "TestBase.h"
class CompareDocumentTest : public InfrastructureTest {
protected:
	utility::string_t get_data_folder() override {
		return path_combine_url(STCONVERT("Temp\\SdkTests\\TestData"), STCONVERT("DocumentActions\\CompareDocument"));
	}
	const utility::string_t compareFolder = STCONVERT("DocumentActions\\CompareDocument");
};

/// <summary>
/// Test for document comparison
/// </summary>
TEST_F(CompareDocumentTest, TestCompareDocument) {
	utility::string_t
		localName1 = STCONVERT("compareTestDoc1.doc"),
		localName2 = STCONVERT("compareTestDoc2.doc"),
		remoteName1 = STCONVERT("TestCompareDocument1.doc"),
		remoteName2 = STCONVERT("TestCompareDocument2.doc"),
		fullName1 = path_combine_url(get_data_folder(), remoteName1),
		fullName2 = path_combine_url(get_data_folder(), remoteName2),
		destFileName = path_combine_url(baseTestOutPath, STCONVERT("TestCompareDocumentOut.doc")),
		filePath1 = path_combine(get_data_dir(compareFolder), localName1),
		filePath2 = path_combine(get_data_dir(compareFolder), localName2);

	std::shared_ptr<CompareData> compareData(new CompareData);
	compareData->setAuthor(STCONVERT("author"));
	compareData->setComparingWithDocument(fullName2);
	compareData->setDateTime(utility::datetime::from_string(STCONVERT("Mon, 26 OCT 2015")));

	UploadFileToStorage(fullName1, filePath1);
	UploadFileToStorage(fullName2, filePath2);

	std::shared_ptr<PostCompareDocumentRequest> request(new PostCompareDocumentRequest(remoteName1, compareData, get_data_folder(), boost::none, boost::none,
		boost::none, destFileName));
	auto requestTask = get_api()->postCompareDocument(request);

	std::shared_ptr<DocumentResponse> actual = requestTask.get();
	ASSERT_EQ(200, actual->getCode());
}
