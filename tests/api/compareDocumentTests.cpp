/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="compareDocumentTests.cpp">
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
/// Example of document comparison.
/// </summary>
class CompareDocumentTests : public InfrastructureTest {
protected:
    utility::string_t remoteFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentActions/CompareDocument");
    utility::string_t localFolder = STCONVERT("DocumentActions/CompareDocument");

};

/// <summary>
/// Test for document comparison.
/// </summary>
TEST_F(CompareDocumentTests, TestCompareDocument) {
    utility::string_t localName1 = STCONVERT("compareTestDoc1.doc");
    utility::string_t localName2 = STCONVERT("compareTestDoc2.doc");
    utility::string_t remoteName1 = STCONVERT("TestCompareDocument1.doc");
    utility::string_t remoteName2 = STCONVERT("TestCompareDocument2.doc");

    UploadFileToStorage(
        remoteFolder + STCONVERT("/") + remoteName1,
        path_combine(LocalTestDataFolder, localFolder + STCONVERT("/") + localName1)
    );
    UploadFileToStorage(
        remoteFolder + STCONVERT("/") + remoteName2,
        path_combine(LocalTestDataFolder, localFolder + STCONVERT("/") + localName2)
    );

    auto requestCompareData = std::make_shared< CompareData >();
    requestCompareData->setAuthor(STCONVERT("author"));
    requestCompareData->setComparingWithDocument(remoteFolder + STCONVERT("/") + remoteName2);
    requestCompareData->setDateTime(utility::datetime::from_string(STCONVERT("2015-10-26T00:00:00.0000000Z"), utility::datetime::ISO_8601));

    std::shared_ptr< CompareDocumentRequest > request(new CompareDocumentRequest(
        remoteName1,
        requestCompareData,
        remoteFolder,
        boost::none,
        boost::none,
        boost::none,
        baseTestOutPath + STCONVERT("/TestCompareDocumentOut.doc")
    ));

   auto actual = get_api()->compareDocument(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_EQ(true, actual.body->getDocument() != nullptr);
   ASSERT_EQ(0, actual.body->getDocument()->getFileName().rfind(STCONVERT("TestCompareDocumentOut.doc"), 0));
}
