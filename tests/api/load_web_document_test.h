/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="load_web_document_test.h">
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
/// Example of how to load web document.
/// </summary>
class LoadWebDocumentTests : public InfrastructureTest {
protected:
};

/// <summary>
/// Test for loading web document.
/// </summary>
TEST_F(LoadWebDocumentTests, TestLoadWebDocument) {
    auto requestDataSaveOptions = std::make_shared< aspose::words::cloud::models::DocSaveOptionsData >();
    requestDataSaveOptions->setFileName(std::make_shared< std::wstring >(L"google.doc"));
    requestDataSaveOptions->setDmlEffectsRenderingMode(std::make_shared< aspose::words::cloud::models::SaveOptionsData::DmlEffectsRenderingMode >(aspose::words::cloud::models::SaveOptionsData::DmlEffectsRenderingMode::NONE));
    requestDataSaveOptions->setDmlRenderingMode(std::make_shared< aspose::words::cloud::models::SaveOptionsData::DmlRenderingMode >(aspose::words::cloud::models::SaveOptionsData::DmlRenderingMode::DRAWING_ML));
    requestDataSaveOptions->setZipOutput(std::make_shared< bool >(false));
    auto requestData = std::make_shared< aspose::words::cloud::models::LoadWebDocumentData >();
    requestData->setLoadingDocumentUrl(std::make_shared< std::wstring >(L"http://google.com"));
    requestData->setSaveOptions(requestDataSaveOptions);
    std::shared_ptr<requests::LoadWebDocumentRequest> request(new requests::LoadWebDocumentRequest(
        requestData,
        nullptr
    ));

    auto actual = getApi()->loadWebDocument(request);
    ASSERT_TRUE(actual->getSaveResult() != nullptr);
    ASSERT_TRUE(actual->getSaveResult()->getDestDocument() != nullptr);
    ASSERT_TRUE(actual->getSaveResult()->getDestDocument()->getHref()->compare(L"google.doc") == 0);
}
