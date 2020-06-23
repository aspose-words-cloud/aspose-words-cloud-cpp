/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="footnoteTests.cpp">
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
/// Example of how to work with footnotes.
/// </summary>
class FootnoteTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentElements/Footnotes");
    utility::string_t footnoteFolder = STCONVERT("DocumentElements/Footnotes");

};

/// <summary>
/// Test for adding footnote.
/// </summary>
TEST_F(FootnoteTests, TestInsertFootnote) {
    utility::string_t remoteFileName = STCONVERT("TestInsertFootnote.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, footnoteFolder + STCONVERT("/Footnote.doc"))
    );

    auto requestFootnoteDto = std::make_shared< FootnoteInsert >();
    requestFootnoteDto->setFootnoteType(STCONVERT("Endnote"));
    requestFootnoteDto->setText(STCONVERT("test endnote"));

    std::shared_ptr< InsertFootnoteRequest > request(new InsertFootnoteRequest(
        remoteFileName,
        requestFootnoteDto,
        STCONVERT(""),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->insertFootnote(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for adding footnote without node path.
/// </summary>
TEST_F(FootnoteTests, TestInsertFootnoteWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestInsertFootnoteWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, footnoteFolder + STCONVERT("/Footnote.doc"))
    );

    auto requestFootnoteDto = std::make_shared< FootnoteInsert >();
    requestFootnoteDto->setFootnoteType(STCONVERT("Endnote"));
    requestFootnoteDto->setText(STCONVERT("test endnote"));

    std::shared_ptr< InsertFootnoteWithoutNodePathRequest > request(new InsertFootnoteWithoutNodePathRequest(
        remoteFileName,
        requestFootnoteDto,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->insertFootnoteWithoutNodePath(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting footnote.
/// </summary>
TEST_F(FootnoteTests, TestDeleteFootnote) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteFootnote.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, footnoteFolder + STCONVERT("/Footnote.doc"))
    );

    std::shared_ptr< DeleteFootnoteRequest > request(new DeleteFootnoteRequest(
        remoteFileName,
        STCONVERT(""),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->deleteFootnote(request).get();
}

/// <summary>
/// Test for deleting footnote without node path.
/// </summary>
TEST_F(FootnoteTests, TestDeleteFootnoteWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteFootnoteWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, footnoteFolder + STCONVERT("/Footnote.doc"))
    );

    std::shared_ptr< DeleteFootnoteWithoutNodePathRequest > request(new DeleteFootnoteWithoutNodePathRequest(
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

   get_api()->deleteFootnoteWithoutNodePath(request).get();
}

/// <summary>
/// Test for getting footnotes.
/// </summary>
TEST_F(FootnoteTests, TestGetFootnotes) {
    utility::string_t remoteFileName = STCONVERT("TestGetFootnotes.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, footnoteFolder + STCONVERT("/Footnote.doc"))
    );

    std::shared_ptr< GetFootnotesRequest > request(new GetFootnotesRequest(
        remoteFileName,
        STCONVERT(""),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getFootnotes(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting footnotes without node path.
/// </summary>
TEST_F(FootnoteTests, TestGetFootnotesWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestGetFootnotesWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, footnoteFolder + STCONVERT("/Footnote.doc"))
    );

    std::shared_ptr< GetFootnotesWithoutNodePathRequest > request(new GetFootnotesWithoutNodePathRequest(
        remoteFileName,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getFootnotesWithoutNodePath(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting footnote.
/// </summary>
TEST_F(FootnoteTests, TestGetFootnote) {
    utility::string_t remoteFileName = STCONVERT("TestGetFootnote.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, footnoteFolder + STCONVERT("/Footnote.doc"))
    );

    std::shared_ptr< GetFootnoteRequest > request(new GetFootnoteRequest(
        remoteFileName,
        STCONVERT(""),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getFootnote(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting footnote without node path.
/// </summary>
TEST_F(FootnoteTests, TestGetFootnoteWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestGetFootnoteWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, footnoteFolder + STCONVERT("/Footnote.doc"))
    );

    std::shared_ptr< GetFootnoteWithoutNodePathRequest > request(new GetFootnoteWithoutNodePathRequest(
        remoteFileName,
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getFootnoteWithoutNodePath(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for updating footnote.
/// </summary>
TEST_F(FootnoteTests, TestUpdateFootnote) {
    utility::string_t remoteFileName = STCONVERT("TestUpdateFootnote.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, footnoteFolder + STCONVERT("/Footnote.doc"))
    );

    auto requestFootnoteDto = std::make_shared< FootnoteUpdate >();
    requestFootnoteDto->setText(STCONVERT("new text is here"));

    std::shared_ptr< UpdateFootnoteRequest > request(new UpdateFootnoteRequest(
        remoteFileName,
        requestFootnoteDto,
        STCONVERT(""),
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->updateFootnote(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for updating footnote without node path.
/// </summary>
TEST_F(FootnoteTests, TestUpdateFootnoteWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestUpdateFootnoteWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, footnoteFolder + STCONVERT("/Footnote.doc"))
    );

    auto requestFootnoteDto = std::make_shared< FootnoteUpdate >();
    requestFootnoteDto->setText(STCONVERT("new text is here"));

    std::shared_ptr< UpdateFootnoteWithoutNodePathRequest > request(new UpdateFootnoteWithoutNodePathRequest(
        remoteFileName,
        requestFootnoteDto,
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->updateFootnoteWithoutNodePath(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}
