/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="runTests.cpp">
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
/// Example of how to work with runs.
/// </summary>
class RunTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentElements/Runs");
    utility::string_t localFile = STCONVERT("DocumentElements/Runs/Run.doc");

};

/// <summary>
/// Test for updating run.
/// </summary>
TEST_F(RunTests, TestUpdateRun) {
    utility::string_t remoteFileName = STCONVERT("TestUpdateRun.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestRun = std::make_shared< RunUpdate >();
    requestRun->setText(STCONVERT("run with text"));

    std::shared_ptr< UpdateRunRequest > request(new UpdateRunRequest(
        remoteFileName,
        requestRun,
        STCONVERT("paragraphs/1"),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->updateRun(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getRun()));
   ASSERT_EQ(STCONVERT("run with text"), actual.body->getRun()->getText());
}

/// <summary>
/// Test for adding run.
/// </summary>
TEST_F(RunTests, TestInsertRun) {
    utility::string_t remoteFileName = STCONVERT("TestInsertRun.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestRun = std::make_shared< RunInsert >();
    requestRun->setText(STCONVERT("run with text"));

    std::shared_ptr< InsertRunRequest > request(new InsertRunRequest(
        remoteFileName,
        STCONVERT("paragraphs/1"),
        requestRun,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->insertRun(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getRun()));
   ASSERT_EQ(STCONVERT("run with text"), actual.body->getRun()->getText());
   ASSERT_EQ(STCONVERT("0.0.1.3"), actual.body->getRun()->getNodeId());
}

/// <summary>
/// Test for deleting run.
/// </summary>
TEST_F(RunTests, TestDeleteRun) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteRun.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< DeleteRunRequest > request(new DeleteRunRequest(
        remoteFileName,
        STCONVERT("paragraphs/1"),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->deleteRun(request).get();
}
