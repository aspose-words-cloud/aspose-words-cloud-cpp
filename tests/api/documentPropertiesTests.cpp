/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="documentPropertiesTests.cpp">
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
/// Example of how to get document properties.
/// </summary>
class DocumentPropertiesTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentElements/DocumentProperties");
    utility::string_t localFile = STCONVERT("Common/test_multi_pages.docx");

};

/// <summary>
/// Test for getting document properties.
/// </summary>
TEST_F(DocumentPropertiesTests, TestGetDocumentProperties) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentProperties.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetDocumentPropertiesRequest > request(new GetDocumentPropertiesRequest(
        remoteFileName,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getDocumentProperties(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getDocumentProperties()));
   ASSERT_TRUE(IsNotNull(actual.body->getDocumentProperties()->getList()));
   ASSERT_EQ(24, actual.body->getDocumentProperties()->getList().size());
   ASSERT_TRUE(IsNotNull(actual.body->getDocumentProperties()->getList()[0]));
   ASSERT_EQ(STCONVERT("Author"), actual.body->getDocumentProperties()->getList()[0]->getName());
   ASSERT_EQ(STCONVERT(""), actual.body->getDocumentProperties()->getList()[0]->getValue());
}



/// <summary>
/// A test for GetDocumentProperty.
/// </summary>
TEST_F(DocumentPropertiesTests, TestGetDocumentProperty) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentProperty.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetDocumentPropertyRequest > request(new GetDocumentPropertyRequest(
        remoteFileName,
        STCONVERT("Author"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getDocumentProperty(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getDocumentProperty()));
   ASSERT_EQ(STCONVERT("Author"), actual.body->getDocumentProperty()->getName());
   ASSERT_EQ(STCONVERT(""), actual.body->getDocumentProperty()->getValue());
}



/// <summary>
/// Test for deleting document property.
/// </summary>
TEST_F(DocumentPropertiesTests, TestDeleteDocumentProperty) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteDocumentProperty.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< DeleteDocumentPropertyRequest > request(new DeleteDocumentPropertyRequest(
        remoteFileName,
        STCONVERT("testProp"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        baseTestOutPath + STCONVERT("/") + remoteFileName,
        boost::none,
        boost::none
    ));

   get_api()->deleteDocumentProperty(request).get();
}



/// <summary>
/// Test for updating document property.
/// </summary>
TEST_F(DocumentPropertiesTests, TestUpdateDocumentProperty) {
    utility::string_t remoteFileName = STCONVERT("TestUpdateDocumentProperty.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestProperty = std::make_shared< DocumentPropertyCreateOrUpdate >();
    requestProperty->setValue(STCONVERT("Imran Anwar"));

    std::shared_ptr< CreateOrUpdateDocumentPropertyRequest > request(new CreateOrUpdateDocumentPropertyRequest(
        remoteFileName,
        STCONVERT("AsposeAuthor"),
        requestProperty,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        baseTestOutPath + STCONVERT("/") + remoteFileName,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->createOrUpdateDocumentProperty(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getDocumentProperty()));
   ASSERT_EQ(STCONVERT("AsposeAuthor"), actual.body->getDocumentProperty()->getName());
   ASSERT_EQ(STCONVERT("Imran Anwar"), actual.body->getDocumentProperty()->getValue());
}


