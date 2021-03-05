/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="sectionTests.cpp">
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
/// Example of how to work with sections.
/// </summary>
class SectionTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentElements/Section");
    utility::string_t localFile = STCONVERT("Common/test_multi_pages.docx");

};

/// <summary>
/// Test for getting section by index.
/// </summary>
TEST_F(SectionTests, TestGetSection) {
    utility::string_t remoteFileName = STCONVERT("TestGetSection.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetSectionRequest > request(new GetSectionRequest(
        remoteFileName,
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getSection(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getSection()));
   ASSERT_TRUE(IsNotNull(actual.body->getSection()->getChildNodes()));
   ASSERT_EQ(13, actual.body->getSection()->getChildNodes().size());
   ASSERT_EQ(STCONVERT("0.3.0"), actual.body->getSection()->getChildNodes()[0]->getNodeId());
}



/// <summary>
/// Test for getting sections.
/// </summary>
TEST_F(SectionTests, TestGetSections) {
    utility::string_t remoteFileName = STCONVERT("TestGetSections.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetSectionsRequest > request(new GetSectionsRequest(
        remoteFileName,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getSections(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getSections()));
   ASSERT_TRUE(IsNotNull(actual.body->getSections()->getSectionLinkList()));
   ASSERT_EQ(1, actual.body->getSections()->getSectionLinkList().size());
   ASSERT_EQ(STCONVERT("0"), actual.body->getSections()->getSectionLinkList()[0]->getNodeId());
}



/// <summary>
/// Test for delete a section.
/// </summary>
TEST_F(SectionTests, TestDeleteSection) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteSection.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< DeleteSectionRequest > request(new DeleteSectionRequest(
        remoteFileName,
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->deleteSection(request).get();
}


