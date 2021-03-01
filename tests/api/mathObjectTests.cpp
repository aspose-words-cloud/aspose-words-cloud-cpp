/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="mathObjectTests.cpp">
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
/// Example of how to work with MathObjects.
/// </summary>
class MathObjectTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentElements/MathObjects");
    utility::string_t localFile = STCONVERT("DocumentElements/MathObjects/MathObjects.docx");

};

/// <summary>
/// Test for getting mathObjects.
/// </summary>
TEST_F(MathObjectTests, TestGetOfficeMathObjects) {
    utility::string_t remoteFileName = STCONVERT("TestGetOfficeMathObjects.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetOfficeMathObjectsRequest > request(new GetOfficeMathObjectsRequest(
        remoteFileName,
        STCONVERT(""),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getOfficeMathObjects(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getOfficeMathObjects()));
   ASSERT_TRUE(IsNotNull(actual.body->getOfficeMathObjects()->getList()));
   ASSERT_EQ(16, actual.body->getOfficeMathObjects()->getList().size());
   ASSERT_EQ(STCONVERT("0.0.0.0"), actual.body->getOfficeMathObjects()->getList()[0]->getNodeId());
}



/// <summary>
/// Test for getting mathObjects without node path.
/// </summary>
TEST_F(MathObjectTests, TestGetOfficeMathObjectsWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestGetOfficeMathObjectsWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetOfficeMathObjectsRequest > request(new GetOfficeMathObjectsRequest(
        remoteFileName,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getOfficeMathObjects(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getOfficeMathObjects()));
   ASSERT_TRUE(IsNotNull(actual.body->getOfficeMathObjects()->getList()));
   ASSERT_EQ(16, actual.body->getOfficeMathObjects()->getList().size());
   ASSERT_EQ(STCONVERT("0.0.0.0"), actual.body->getOfficeMathObjects()->getList()[0]->getNodeId());
}

/// <summary>
/// Test for getting mathObject.
/// </summary>
TEST_F(MathObjectTests, TestGetOfficeMathObject) {
    utility::string_t remoteFileName = STCONVERT("TestGetOfficeMathObject.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetOfficeMathObjectRequest > request(new GetOfficeMathObjectRequest(
        remoteFileName,
        0,
        STCONVERT(""),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getOfficeMathObject(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getOfficeMathObject()));
   ASSERT_EQ(STCONVERT("0.0.0.0"), actual.body->getOfficeMathObject()->getNodeId());
}



/// <summary>
/// Test for getting mathObject without node path.
/// </summary>
TEST_F(MathObjectTests, TestGetOfficeMathObjectWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestGetOfficeMathObjectWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetOfficeMathObjectRequest > request(new GetOfficeMathObjectRequest(
        remoteFileName,
        0,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getOfficeMathObject(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getOfficeMathObject()));
   ASSERT_EQ(STCONVERT("0.0.0.0"), actual.body->getOfficeMathObject()->getNodeId());
}

/// <summary>
/// Test for rendering mathObject.
/// </summary>
TEST_F(MathObjectTests, TestRenderMathObject) {
    utility::string_t remoteFileName = STCONVERT("TestRenderMathObject.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< RenderMathObjectRequest > request(new RenderMathObjectRequest(
        remoteFileName,
        STCONVERT("png"),
        0,
        STCONVERT(""),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->renderMathObject(request).get();
}



/// <summary>
/// Test for rendering mathObject without node path.
/// </summary>
TEST_F(MathObjectTests, TestRenderMathObjectWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestRenderMathObjectWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< RenderMathObjectRequest > request(new RenderMathObjectRequest(
        remoteFileName,
        STCONVERT("png"),
        0,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->renderMathObject(request).get();
}

/// <summary>
/// Test for deleting mathObject.
/// </summary>
TEST_F(MathObjectTests, TestDeleteOfficeMathObject) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteOfficeMathObject.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< DeleteOfficeMathObjectRequest > request(new DeleteOfficeMathObjectRequest(
        remoteFileName,
        0,
        STCONVERT(""),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->deleteOfficeMathObject(request).get();
}



/// <summary>
/// Test for deleting mathObject without node path.
/// </summary>
TEST_F(MathObjectTests, TestDeleteOfficeMathObjectWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteOfficeMathObjectWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< DeleteOfficeMathObjectRequest > request(new DeleteOfficeMathObjectRequest(
        remoteFileName,
        0,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->deleteOfficeMathObject(request).get();
}
