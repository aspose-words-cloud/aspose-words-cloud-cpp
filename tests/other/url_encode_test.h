/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="url_encode_test.h">
*   Copyright (c) 2023 Aspose.Words for Cloud
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
/// URL encode test
/// </summary>
class UrlEncodeTest : public InfrastructureTest { };

/// <summary>
/// Test for URL encoding of document name
/// </summary>
TEST_F(UrlEncodeTest, TestUrlEncode) {
    std::wstring remoteName = L"[“Test_Two,_Inc.”]-_83(b)Election 你好([“Bill_Gates”]).docx";
    std::wstring remoteDir = remoteBaseTestDataFolder + L"/UrlEncodeTest";

    uploadFileToStorage(localTestDataFolder + L"/Common/test_multi_pages.docx", remoteDir + L"/" + remoteName);
    auto request = std::shared_ptr<requests::GetBookmarksRequest>(
        new requests::GetBookmarksRequest(
            std::make_shared<std::wstring>(remoteName),
            std::make_shared<std::wstring>(remoteDir)
        )
    );

    getApi()->getBookmarks(request);
}
