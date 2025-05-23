﻿/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="font_test.h">
*   Copyright (c) 2025 Aspose.Words for Cloud
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
/// Example of how to work with font.
/// </summary>
class FontTests : public InfrastructureTest {
protected:
};

/// <summary>
/// Test for reseting cache.
/// </summary>
TEST_F(FontTests, TestResetCache) {
    std::shared_ptr<requests::ResetCacheRequest> request(new requests::ResetCacheRequest(
    ));

getApi()->resetCache(request);
}

/// <summary>
/// Test for GetAvailableFonts resource.
/// </summary>
TEST_F(FontTests, TestGetAvailableFonts) {
    std::shared_ptr<requests::GetAvailableFontsRequest> request(new requests::GetAvailableFontsRequest(
        nullptr
    ));

    auto actual = getApi()->getAvailableFonts(request);
    ASSERT_TRUE(actual->getSystemFonts() != nullptr);
}
