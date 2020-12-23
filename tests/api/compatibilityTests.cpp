/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="compatibilityTests.cpp">
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
/// Example of how to work with compatibility options.
/// </summary>
class CompatibilityTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/Compatibility");
    utility::string_t localFile = STCONVERT("Common/test_multi_pages.docx");

};

/// <summary>
/// Test for optimize document to specific MS Word version.
/// </summary>
TEST_F(CompatibilityTests, TestOptimizeDocument) {
    utility::string_t remoteFileName = STCONVERT("TestOptimizeDocument.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestOptions = std::make_shared< OptimizationOptions >();
    requestOptions->setMsWordVersion(STCONVERT("Word2002"));

    std::shared_ptr< OptimizeDocumentRequest > request(new OptimizeDocumentRequest(
        remoteFileName,
        requestOptions,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->optimizeDocument(request).get();
}

/// <summary>
/// Test for optimize document to specific MS Word version.
/// </summary>
TEST_F(CompatibilityTests, TestOptimizeDocumentOnline) {
    auto requestOptions = std::make_shared< OptimizationOptions >();
    requestOptions->setMsWordVersion(STCONVERT("Word2002"));

    std::shared_ptr< OptimizeDocumentOnlineRequest > request(new OptimizeDocumentOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        requestOptions,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->optimizeDocumentOnline(request).get();
}
