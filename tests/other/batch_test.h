/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="batch_test.h">
*   Copyright (c) 2024 Aspose.Words for Cloud
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

#pragma once
#include "../test_base.h"

/// <summary>
/// Batch test
/// </summary>
class BatchTest : public InfrastructureTest {
protected:
    std::wstring localFile = L"Common/test_multi_pages.docx";
};

/// <summary>
/// Test for batch parallel requests
/// </summary>
TEST_F(BatchTest, TestBatchParallel) {
    requests::BatchRequest request1(
        std::shared_ptr<requests::GetBookmarksOnlineRequest>(
            new requests::GetBookmarksOnlineRequest(
                std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(localTestDataFolder + L"/" + localFile), std::ios_base::binary))
            )
        )
    );

    requests::BatchRequest request2(
        std::shared_ptr<requests::GetCommentsOnlineRequest>(
            new requests::GetCommentsOnlineRequest(
                std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(localTestDataFolder + L"/" + localFile), std::ios_base::binary))
            )
        )
    );

    auto response = getApi()->batch({ request1, request2 });

    ASSERT_TRUE(response->getCount() == 2);

    ASSERT_TRUE(response->getResult<responses::GetBookmarksOnlineResponse>(0) != nullptr);
    ASSERT_TRUE(response->getResult<responses::GetBookmarksOnlineResponse>(0)->getStatusCode() == 200);
    ASSERT_TRUE(response->getResult<responses::GetBookmarksOnlineResponse>(0)->getModel()->getBookmarks()->getBookmarkList()->size() > 0);

    ASSERT_TRUE(response->getResult<responses::GetCommentsOnlineResponse>(1) != nullptr);
    ASSERT_TRUE(response->getResult<responses::GetCommentsOnlineResponse>(1)->getStatusCode() == 200);
    ASSERT_TRUE(response->getResult<responses::GetCommentsOnlineResponse>(1)->getModel()->getComments()->getCommentList()->size() > 0);
}

/// <summary>
/// Test for batch depends requests
/// </summary>
TEST_F(BatchTest, TestBatchDepends) {
    std::wstring remoteFileName = L"TestBatchDepends.docx";

    requests::BatchRequest request0(
        std::shared_ptr<requests::UploadFileRequest>(
            new requests::UploadFileRequest(
                std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(localTestDataFolder + L"/" + localFile), std::ios_base::binary)),
                std::make_shared< std::wstring >(remoteBaseTestDataFolder + L"/" + remoteFileName)
            )
        )
    );

    requests::BatchRequest request1(
        std::shared_ptr<requests::GetBookmarksRequest>(
            new requests::GetBookmarksRequest(
                std::make_shared< std::wstring >(remoteFileName),
                std::make_shared< std::wstring >(remoteBaseTestDataFolder)
            )
        )
    );

    requests::BatchRequest request2(
        std::shared_ptr<requests::GetCommentsRequest>(
            new requests::GetCommentsRequest(
                std::make_shared< std::wstring >(remoteFileName),
                std::make_shared< std::wstring >(remoteBaseTestDataFolder)
            )
        )
    );

    request1.dependsOn(request0);
    request2.dependsOn(request0);

    auto response = getApi()->batch({ request0, request1, request2 });

    ASSERT_TRUE(response->getCount() == 3);

    ASSERT_TRUE(response->getResult<responses::GetBookmarksResponse>(1) != nullptr);
    ASSERT_TRUE(response->getResult<responses::GetBookmarksResponse>(1)->getStatusCode() == 200);
    ASSERT_TRUE(response->getResult<responses::GetBookmarksResponse>(1)->getModel()->getBookmarks()->getBookmarkList()->size() > 0);

    ASSERT_TRUE(response->getResult<responses::GetCommentsResponse>(2) != nullptr);
    ASSERT_TRUE(response->getResult<responses::GetCommentsResponse>(2)->getStatusCode() == 200);
    ASSERT_TRUE(response->getResult<responses::GetCommentsResponse>(2)->getModel()->getComments()->getCommentList()->size() > 0);
}

/// <summary>
/// Test for batch resultOf requests
/// </summary>
TEST_F(BatchTest, TestBatchResultOf) {
    requests::BatchRequest request1(
        std::shared_ptr<requests::GetBookmarksOnlineRequest>(
            new requests::GetBookmarksOnlineRequest(
                std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(localTestDataFolder + L"/" + localFile), std::ios_base::binary))
            )
        )
    );

    requests::BatchRequest request2(
        std::shared_ptr<requests::GetCommentsOnlineRequest>(
            new requests::GetCommentsOnlineRequest(
                request1.asResult()
            )
        )
    );

    auto response = getApi()->batch({ request1, request2 });

    ASSERT_TRUE(response->getCount() == 2);

    ASSERT_TRUE(response->getResult<responses::GetBookmarksOnlineResponse>(0) != nullptr);
    ASSERT_TRUE(response->getResult<responses::GetBookmarksOnlineResponse>(0)->getStatusCode() == 200);

    ASSERT_TRUE(response->getResult<responses::GetCommentsOnlineResponse>(1) != nullptr);
    ASSERT_TRUE(response->getResult<responses::GetCommentsOnlineResponse>(1)->getStatusCode() == 200);
}

/// <summary>
/// Test for batch depends requests
/// </summary>
TEST_F(BatchTest, TestBatchWithoutIntermediateResults) {
    std::wstring remoteFileName = L"TestBatchWithoutIntermediateResults.docx";

    requests::BatchRequest request0(
        std::shared_ptr<requests::UploadFileRequest>(
            new requests::UploadFileRequest(
                std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(localTestDataFolder + L"/" + localFile), std::ios_base::binary)),
                std::make_shared< std::wstring >(remoteBaseTestDataFolder + L"/" + remoteFileName)
            )
        )
    );

    requests::BatchRequest request1(
        std::shared_ptr<requests::GetBookmarksRequest>(
            new requests::GetBookmarksRequest(
                std::make_shared< std::wstring >(remoteFileName),
                std::make_shared< std::wstring >(remoteBaseTestDataFolder)
            )
        )
    );

    requests::BatchRequest request2(
        std::shared_ptr<requests::GetCommentsRequest>(
            new requests::GetCommentsRequest(
                std::make_shared< std::wstring >(remoteFileName),
                std::make_shared< std::wstring >(remoteBaseTestDataFolder)
            )
        )
    );

    request2.dependsOn(request1);
    request1.dependsOn(request0);

    auto response = getApi()->batch({ request0, request1, request2 }, false);
    ASSERT_TRUE(response->getCount() == 1);
    ASSERT_TRUE(response->getResult<responses::GetCommentsResponse>(0) != nullptr);
    ASSERT_TRUE(response->getResult<responses::GetCommentsResponse>(0)->getStatusCode() == 200);
    ASSERT_TRUE(response->getResult<responses::GetCommentsResponse>(0)->getModel()->getComments()->getCommentList()->size() > 0);
}
