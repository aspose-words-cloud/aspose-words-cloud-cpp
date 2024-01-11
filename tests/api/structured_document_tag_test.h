/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="structured_document_tag_test.h">
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
/// Example of how to use structured document tags.
/// </summary>
class StructuredDocumentTagTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentElements/StructuredDocumentTag";
    std::wstring localFile = L"DocumentElements/StructuredDocumentTag/StructuredDocumentTag.docx";

};

/// <summary>
/// Test for getting SDT objects from document.
/// </summary>
TEST_F(StructuredDocumentTagTests, TestGetStructuredDocumentTags) {
    std::wstring remoteFileName = L"TestGetStructuredDocumentTags.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetStructuredDocumentTagsRequest> request(new requests::GetStructuredDocumentTagsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"sections/0/body/paragraphs/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getStructuredDocumentTags(request);
}

/// <summary>
/// Test for getting SDT objects from document online.
/// </summary>
TEST_F(StructuredDocumentTagTests, TestGetStructuredDocumentTagsOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetStructuredDocumentTagsOnlineRequest> request(new requests::GetStructuredDocumentTagsOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"sections/0/body/paragraphs/0"),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getStructuredDocumentTagsOnline(request);
}

/// <summary>
/// Test for getting SDT object from document.
/// </summary>
TEST_F(StructuredDocumentTagTests, TestGetStructuredDocumentTag) {
    std::wstring remoteFileName = L"TestGetStructuredDocumentTag.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetStructuredDocumentTagRequest> request(new requests::GetStructuredDocumentTagRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L"sections/0/body/paragraphs/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getStructuredDocumentTag(request);
}

/// <summary>
/// Test for getting SDT object from document online.
/// </summary>
TEST_F(StructuredDocumentTagTests, TestGetStructuredDocumentTagOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetStructuredDocumentTagOnlineRequest> request(new requests::GetStructuredDocumentTagOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L"sections/0/body/paragraphs/0"),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getStructuredDocumentTagOnline(request);
}

/// <summary>
/// Test for adding SDT object.
/// </summary>
TEST_F(StructuredDocumentTagTests, TestInsertStructuredDocumentTag) {
    std::wstring remoteFileName = L"TestInsetStructuredDocumentTag.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestStructuredDocumentTag = std::make_shared< aspose::words::cloud::models::StructuredDocumentTagInsert >();
    requestStructuredDocumentTag->setSdtType(std::make_shared< aspose::words::cloud::models::StructuredDocumentTagInsert::SdtType >(aspose::words::cloud::models::StructuredDocumentTagInsert::SdtType::COMBO_BOX));
    requestStructuredDocumentTag->setLevel(std::make_shared< aspose::words::cloud::models::StructuredDocumentTagInsert::Level >(aspose::words::cloud::models::StructuredDocumentTagInsert::Level::INLINE));
    std::shared_ptr<requests::InsertStructuredDocumentTagRequest> request(new requests::InsertStructuredDocumentTagRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestStructuredDocumentTag,
        std::make_shared< std::wstring >(L"sections/0/body/paragraphs/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertStructuredDocumentTag(request);
}

/// <summary>
/// Test for adding SDT object online.
/// </summary>
TEST_F(StructuredDocumentTagTests, TestInsertStructuredDocumentTagOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestStructuredDocumentTag = std::make_shared< aspose::words::cloud::models::StructuredDocumentTagInsert >();
    requestStructuredDocumentTag->setSdtType(std::make_shared< aspose::words::cloud::models::StructuredDocumentTagInsert::SdtType >(aspose::words::cloud::models::StructuredDocumentTagInsert::SdtType::COMBO_BOX));
    requestStructuredDocumentTag->setLevel(std::make_shared< aspose::words::cloud::models::StructuredDocumentTagInsert::Level >(aspose::words::cloud::models::StructuredDocumentTagInsert::Level::INLINE));
    std::shared_ptr<requests::InsertStructuredDocumentTagOnlineRequest> request(new requests::InsertStructuredDocumentTagOnlineRequest(
        requestDocument,
        requestStructuredDocumentTag,
        std::make_shared< std::wstring >(L"sections/0/body/paragraphs/0"),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertStructuredDocumentTagOnline(request);
}

/// <summary>
/// Test for deleting SDT object.
/// </summary>
TEST_F(StructuredDocumentTagTests, TestDeleteStructuredDocumentTag) {
    std::wstring remoteFileName = L"TestDeleteStructuredDocumentTag.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteStructuredDocumentTagRequest> request(new requests::DeleteStructuredDocumentTagRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L"sections/0/body/paragraphs/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

getApi()->deleteStructuredDocumentTag(request);
}

/// <summary>
/// Test for deleting SDT object online.
/// </summary>
TEST_F(StructuredDocumentTagTests, TestDeleteStructuredDocumentTagOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::DeleteStructuredDocumentTagOnlineRequest> request(new requests::DeleteStructuredDocumentTagOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L"sections/0/body/paragraphs/0"),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteStructuredDocumentTagOnline(request);
}

/// <summary>
/// Test for updating SDT object.
/// </summary>
TEST_F(StructuredDocumentTagTests, TestUpdateStructuredDocumentTag) {
    std::wstring remoteFileName = L"TestUpdateStructuredDocumentTag.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestStructuredDocumentTagListItems0 = std::make_shared< aspose::words::cloud::models::StructuredDocumentTagListItem >();
    requestStructuredDocumentTagListItems0->setDisplayText(std::make_shared< std::wstring >(L"Aspose Words"));
    requestStructuredDocumentTagListItems0->setValue(std::make_shared< std::wstring >(L"1"));
    auto requestStructuredDocumentTagListItems1 = std::make_shared< aspose::words::cloud::models::StructuredDocumentTagListItem >();
    requestStructuredDocumentTagListItems1->setDisplayText(std::make_shared< std::wstring >(L"Hello world"));
    requestStructuredDocumentTagListItems1->setValue(std::make_shared< std::wstring >(L"2"));
    auto requestStructuredDocumentTagListItems = std::make_shared< std::vector<std::shared_ptr<aspose::words::cloud::models::StructuredDocumentTagListItem>> >();
    requestStructuredDocumentTagListItems->push_back(requestStructuredDocumentTagListItems0);
    requestStructuredDocumentTagListItems->push_back(requestStructuredDocumentTagListItems1);
    auto requestStructuredDocumentTag = std::make_shared< aspose::words::cloud::models::StructuredDocumentTagUpdate >();
    requestStructuredDocumentTag->setListItems(requestStructuredDocumentTagListItems);
    std::shared_ptr<requests::UpdateStructuredDocumentTagRequest> request(new requests::UpdateStructuredDocumentTagRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        requestStructuredDocumentTag,
        std::make_shared< std::wstring >(L"sections/0/body/paragraphs/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateStructuredDocumentTag(request);
}

/// <summary>
/// Test for updating SDT object online.
/// </summary>
TEST_F(StructuredDocumentTagTests, TestUpdateStructuredDocumentTagOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestStructuredDocumentTagListItems0 = std::make_shared< aspose::words::cloud::models::StructuredDocumentTagListItem >();
    requestStructuredDocumentTagListItems0->setDisplayText(std::make_shared< std::wstring >(L"Aspose Words"));
    requestStructuredDocumentTagListItems0->setValue(std::make_shared< std::wstring >(L"1"));
    auto requestStructuredDocumentTagListItems1 = std::make_shared< aspose::words::cloud::models::StructuredDocumentTagListItem >();
    requestStructuredDocumentTagListItems1->setDisplayText(std::make_shared< std::wstring >(L"Hello world"));
    requestStructuredDocumentTagListItems1->setValue(std::make_shared< std::wstring >(L"2"));
    auto requestStructuredDocumentTagListItems = std::make_shared< std::vector<std::shared_ptr<aspose::words::cloud::models::StructuredDocumentTagListItem>> >();
    requestStructuredDocumentTagListItems->push_back(requestStructuredDocumentTagListItems0);
    requestStructuredDocumentTagListItems->push_back(requestStructuredDocumentTagListItems1);
    auto requestStructuredDocumentTag = std::make_shared< aspose::words::cloud::models::StructuredDocumentTagUpdate >();
    requestStructuredDocumentTag->setListItems(requestStructuredDocumentTagListItems);
    std::shared_ptr<requests::UpdateStructuredDocumentTagOnlineRequest> request(new requests::UpdateStructuredDocumentTagOnlineRequest(
        requestDocument,
        requestStructuredDocumentTag,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L"sections/0/body/paragraphs/0"),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateStructuredDocumentTagOnline(request);
}
