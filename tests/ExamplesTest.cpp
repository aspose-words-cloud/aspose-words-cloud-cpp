/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ExamplesTest.cpp">
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
#include <boost/filesystem.hpp>
#include "WordsApi.h"
using namespace aspose::words::cloud::api;
#include "TestBase.h"

class ExamplesTest : public InfrastructureTest {
protected:
    boost::filesystem::path LocalTestExamplesFolder{get_sdk_root()/"ExamplesData"};
};

TEST_F(ExamplesTest, TestExampleAcceptAllRevisions) {
    utility::string_t documentsDir = utility::conversions::to_string_t(LocalTestExamplesFolder.generic_string());
    auto wordsApi = get_api();
    utility::string_t fileName  = STCONVERT("test_doc.docx");

    // Upload original document to cloud storage.
    auto fileContentContent = std::make_shared<HttpContent>();
    auto fileContentStream = std::make_shared<boost::filesystem::ifstream>(documentsDir + STCONVERT("/") + fileName, std::ifstream::binary);
    fileContentContent->setData(fileContentStream);
    fileContentContent->setContentDisposition(_XPLATSTR("form-data"));
    auto uploadFileRequest = std::make_shared< UploadFileRequest >(fileContentContent, fileName, boost::none);
    wordsApi->uploadFile(uploadFileRequest).get();

    // Calls AcceptAllRevisions method for document in cloud.
    auto request = std::make_shared< AcceptAllRevisionsRequest >(fileName, boost::none, boost::none, boost::none, boost::none, boost::none);
    wordsApi->acceptAllRevisions(request).get();
}



// AcceptAllRevisionsOnline => ONLINE METHODS NOT SUPPORTED AT THIS MOMENT
