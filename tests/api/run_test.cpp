/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="run_test.cpp">
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

#include "../test_base.h"

/// <summary>
/// Example of how to work with runs.
/// </summary>
class RunTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentElements/Runs";
    std::wstring localFile = L"DocumentElements/Runs/Run.doc";

};

/// <summary>
/// Test for updating run.
/// </summary>
TEST_F(RunTests, TestUpdateRun) {
    std::wstring remoteFileName = L"TestUpdateRun.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestRun = std::make_shared< aspose::words::cloud::models::RunUpdate >();
    requestRun->setText(std::make_shared< std::wstring >(L"run with text"));

    std::shared_ptr<requests::UpdateRunRequest> request(new requests::UpdateRunRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"paragraphs/1"),
        std::make_shared< int32_t >(0),
        requestRun,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateRun(request);
    ASSERT_TRUE(actual->getRun() != nullptr);
    ASSERT_TRUE(actual->getRun()->getText()->compare(L"run with text") == 0);
}



/// <summary>
/// Test for adding run.
/// </summary>
TEST_F(RunTests, TestInsertRun) {
    std::wstring remoteFileName = L"TestInsertRun.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestRun = std::make_shared< aspose::words::cloud::models::RunInsert >();
    requestRun->setText(std::make_shared< std::wstring >(L"run with text"));

    std::shared_ptr<requests::InsertRunRequest> request(new requests::InsertRunRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"paragraphs/1"),
        requestRun,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertRun(request);
    ASSERT_TRUE(actual->getRun() != nullptr);
    ASSERT_TRUE(actual->getRun()->getText()->compare(L"run with text") == 0);
    ASSERT_TRUE(actual->getRun()->getNodeId()->compare(L"0.0.1.3") == 0);
}



/// <summary>
/// Test for deleting run.
/// </summary>
TEST_F(RunTests, TestDeleteRun) {
    std::wstring remoteFileName = L"TestDeleteRun.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteRunRequest> request(new requests::DeleteRunRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"paragraphs/1"),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

getApi()->deleteRun(request);
}


