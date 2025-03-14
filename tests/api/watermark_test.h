﻿/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="watermark_test.h">
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
/// Example of how to work with watermarks.
/// </summary>
class WatermarkTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentActions/Watermark";
    std::wstring localFile = L"Common/test_multi_pages.docx";

};

/// <summary>
/// Test for adding watermark text.
/// </summary>
TEST_F(WatermarkTests, TestInsertWatermarkText) {
    std::wstring remoteFileName = L"TestInsertWatermarkText.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestWatermarkData = std::make_shared< aspose::words::cloud::models::WatermarkDataText >();
    requestWatermarkData->setText(std::make_shared< std::wstring >(L"watermark text"));
    std::shared_ptr<requests::InsertWatermarkRequest> request(new requests::InsertWatermarkRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestWatermarkData,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertWatermark(request);
    ASSERT_TRUE(actual->getDocument() != nullptr);
}

/// <summary>
/// Test for adding watermark text online.
/// </summary>
TEST_F(WatermarkTests, TestInsertWatermarkTextOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestWatermarkData = std::make_shared< aspose::words::cloud::models::WatermarkDataText >();
    requestWatermarkData->setText(std::make_shared< std::wstring >(L"watermark text"));
    std::shared_ptr<requests::InsertWatermarkOnlineRequest> request(new requests::InsertWatermarkOnlineRequest(
        requestDocument,
        requestWatermarkData,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertWatermarkOnline(request);
}

/// <summary>
/// Test for adding watermark text.
/// </summary>
TEST_F(WatermarkTests, TestInsertWatermarkImage) {
    std::wstring remoteFileName = L"TestInsertWatermarkImage.docx";
    std::wstring remoteImagePath = remoteDataFolder + L"/TestInsertWatermarkImage.png";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );
    uploadFileToStorage(
        localTestDataFolder + L"/" + L"Common/aspose-cloud.png",
        remoteImagePath
    );

    auto requestWatermarkDataImage = std::make_shared< aspose::words::cloud::models::FileReference >(std::make_shared< std::wstring >(remoteImagePath));
    auto requestWatermarkData = std::make_shared< aspose::words::cloud::models::WatermarkDataImage >();
    requestWatermarkData->setImage(requestWatermarkDataImage);
    std::shared_ptr<requests::InsertWatermarkRequest> request(new requests::InsertWatermarkRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestWatermarkData,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertWatermark(request);
    ASSERT_TRUE(actual->getDocument() != nullptr);
}

/// <summary>
/// Test for adding watermark text online.
/// </summary>
TEST_F(WatermarkTests, TestInsertWatermarkImageOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestWatermarkDataImageStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(L"Common/aspose-cloud.png")), std::istream::binary));
    auto requestWatermarkDataImage = std::make_shared< aspose::words::cloud::models::FileReference >(requestWatermarkDataImageStream);
    auto requestWatermarkData = std::make_shared< aspose::words::cloud::models::WatermarkDataImage >();
    requestWatermarkData->setImage(requestWatermarkDataImage);
    std::shared_ptr<requests::InsertWatermarkOnlineRequest> request(new requests::InsertWatermarkOnlineRequest(
        requestDocument,
        requestWatermarkData,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertWatermarkOnline(request);
}

/// <summary>
/// Test for adding watermark image.
/// </summary>
TEST_F(WatermarkTests, TestInsertWatermarkImageDeprecated) {
    std::wstring remoteFileName = L"TestInsertWatermarkImage.docx";
    std::wstring remoteImagePath = remoteDataFolder + L"/TestInsertWatermarkImage.png";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );
    uploadFileToStorage(
        localTestDataFolder + L"/" + L"Common/aspose-cloud.png",
        remoteImagePath
    );

    std::shared_ptr<requests::InsertWatermarkImageRequest> request(new requests::InsertWatermarkImageRequest(
        std::make_shared< std::wstring >(remoteFileName),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName),
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(remoteImagePath)
    ));

    auto actual = getApi()->insertWatermarkImage(request);
    ASSERT_TRUE(actual->getDocument() != nullptr);
    ASSERT_TRUE(actual->getDocument()->getFileName()->compare(L"TestInsertWatermarkImage.docx") == 0);
}

/// <summary>
/// Test for adding watermark image online.
/// </summary>
TEST_F(WatermarkTests, TestInsertWatermarkImageDeprecatedOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestImageFile = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(L"Common/aspose-cloud.png")), std::istream::binary));
    std::shared_ptr<requests::InsertWatermarkImageOnlineRequest> request(new requests::InsertWatermarkImageOnlineRequest(
        requestDocument,
        requestImageFile,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertWatermarkImageOnline(request);
}

/// <summary>
/// Test for adding watermark text.
/// </summary>
TEST_F(WatermarkTests, TestInsertWatermarkTextDeprecated) {
    std::wstring remoteFileName = L"TestInsertWatermarkText.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestWatermarkText = std::make_shared< aspose::words::cloud::models::WatermarkText >();
    requestWatermarkText->setText(std::make_shared< std::wstring >(L"This is the text"));
    requestWatermarkText->setRotationAngle(std::make_shared< double >(90.0));
    std::shared_ptr<requests::InsertWatermarkTextRequest> request(new requests::InsertWatermarkTextRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestWatermarkText,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertWatermarkText(request);
    ASSERT_TRUE(actual->getDocument() != nullptr);
    ASSERT_TRUE(actual->getDocument()->getFileName()->compare(L"TestInsertWatermarkText.docx") == 0);
}

/// <summary>
/// Test for adding watermark text online.
/// </summary>
TEST_F(WatermarkTests, TestInsertWatermarkTextDeprecatedOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestWatermarkText = std::make_shared< aspose::words::cloud::models::WatermarkText >();
    requestWatermarkText->setText(std::make_shared< std::wstring >(L"This is the text"));
    requestWatermarkText->setRotationAngle(std::make_shared< double >(90));
    std::shared_ptr<requests::InsertWatermarkTextOnlineRequest> request(new requests::InsertWatermarkTextOnlineRequest(
        requestDocument,
        requestWatermarkText,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertWatermarkTextOnline(request);
}

/// <summary>
/// Test for deleting watermark.
/// </summary>
TEST_F(WatermarkTests, TestDeleteWatermark) {
    std::wstring remoteFileName = L"TestDeleteWatermark.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteWatermarkRequest> request(new requests::DeleteWatermarkRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteWatermark(request);
    ASSERT_TRUE(actual->getDocument() != nullptr);
    ASSERT_TRUE(actual->getDocument()->getFileName()->compare(L"TestDeleteWatermark.docx") == 0);
}

/// <summary>
/// Test for deleting watermark online.
/// </summary>
TEST_F(WatermarkTests, TestDeleteWatermarkOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::DeleteWatermarkOnlineRequest> request(new requests::DeleteWatermarkOnlineRequest(
        requestDocument,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteWatermarkOnline(request);
}
