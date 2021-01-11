/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="loadWebDocumentTests.cpp">
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
/// Example of how to load web document.
/// </summary>
class LoadWebDocumentTests : public InfrastructureTest {
protected:
};

/// <summary>
/// Test for loading web document.
/// </summary>
TEST_F(LoadWebDocumentTests, TestLoadWebDocument) {
    auto requestDataSaveOptions = std::make_shared< SaveOptionsData >();
    requestDataSaveOptions->setFileName(STCONVERT("google.doc"));
    requestDataSaveOptions->setSaveFormat(STCONVERT("doc"));
    requestDataSaveOptions->setDmlEffectsRenderingMode(STCONVERT("1"));
    requestDataSaveOptions->setDmlRenderingMode(STCONVERT("1"));
    requestDataSaveOptions->setUpdateSdtContent(false);
    requestDataSaveOptions->setZipOutput(false);

    auto requestData = std::make_shared< LoadWebDocumentData >();
    requestData->setLoadingDocumentUrl(STCONVERT("http://google.com"));
    requestData->setSaveOptions(requestDataSaveOptions);

    std::shared_ptr< LoadWebDocumentRequest > request(new LoadWebDocumentRequest(
        requestData,
        boost::none
    ));

   auto actual = get_api()->loadWebDocument(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getSaveResult()));
   ASSERT_TRUE(IsNotNull(actual.body->getSaveResult()->getDestDocument()));
   ASSERT_EQ(STCONVERT("google.doc"), actual.body->getSaveResult()->getDestDocument()->getHref());
}
