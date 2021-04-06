/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="section_test.h">
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

#pragma once
#include "../test_base.h"

/// <summary>
/// Example of how to work with sections.
/// </summary>
class SectionTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentElements/Section";
    std::wstring localFile = L"Common/test_multi_pages.docx";

};

/// <summary>
/// Test for getting section by index.
/// </summary>
TEST_F(SectionTests, TestGetSection) {
    std::wstring remoteFileName = L"TestGetSection.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetSectionRequest> request(new requests::GetSectionRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getSection(request);
    ASSERT_TRUE(actual->getSection() != nullptr);
    ASSERT_TRUE(actual->getSection()->getChildNodes() != nullptr);
    ASSERT_EQ(13, actual->getSection()->getChildNodes()->size());
    ASSERT_TRUE(actual->getSection()->getChildNodes()->at(0)->getNodeId()->compare(L"0.3.0") == 0);
}

/// <summary>
/// Test for getting section by index online.
/// </summary>
TEST_F(SectionTests, TestGetSectionOnline) {
    auto documentStream = std::shared_ptr<std::istream>(new std::ifstream(getDataDir(localFile).c_str(), std::istream::binary));
    std::shared_ptr<requests::GetSectionOnlineRequest> request(new requests::GetSectionOnlineRequest(
        documentStream,
        std::make_shared< int32_t >(0),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getSectionOnline(request);
}

/// <summary>
/// Test for getting sections.
/// </summary>
TEST_F(SectionTests, TestGetSections) {
    std::wstring remoteFileName = L"TestGetSections.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetSectionsRequest> request(new requests::GetSectionsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getSections(request);
    ASSERT_TRUE(actual->getSections() != nullptr);
    ASSERT_TRUE(actual->getSections()->getSectionLinkList() != nullptr);
    ASSERT_EQ(1, actual->getSections()->getSectionLinkList()->size());
    ASSERT_TRUE(actual->getSections()->getSectionLinkList()->at(0)->getNodeId()->compare(L"0") == 0);
}

/// <summary>
/// Test for getting sections online.
/// </summary>
TEST_F(SectionTests, TestGetSectionsOnline) {
    auto documentStream = std::shared_ptr<std::istream>(new std::ifstream(getDataDir(localFile).c_str(), std::istream::binary));
    std::shared_ptr<requests::GetSectionsOnlineRequest> request(new requests::GetSectionsOnlineRequest(
        documentStream,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getSectionsOnline(request);
}

/// <summary>
/// Test for delete a section.
/// </summary>
TEST_F(SectionTests, TestDeleteSection) {
    std::wstring remoteFileName = L"TestDeleteSection.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteSectionRequest> request(new requests::DeleteSectionRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

getApi()->deleteSection(request);
}

/// <summary>
/// Test for delete a section online.
/// </summary>
TEST_F(SectionTests, TestDeleteSectionOnline) {
    auto documentStream = std::shared_ptr<std::istream>(new std::ifstream(getDataDir(localFile).c_str(), std::istream::binary));
    std::shared_ptr<requests::DeleteSectionOnlineRequest> request(new requests::DeleteSectionOnlineRequest(
        documentStream,
        std::make_shared< int32_t >(0),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteSectionOnline(request);
}
