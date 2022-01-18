/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="save_as_tiff_request.h">
*   Copyright (c) 2022 Aspose.Words for Cloud
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
#include "./request_model_base.h"
#include "aspose_words_cloud/models/tiff_save_options_data.h"

namespace aspose::words::cloud::requests {
    class SaveAsTiffRequest : public RequestModelBase {
    public:
        ASPOSE_WORDS_CLOUD_EXPORT SaveAsTiffRequest(
            const std::shared_ptr< std::wstring > name,
            const std::shared_ptr< aspose::words::cloud::models::TiffSaveOptionsData > saveOptions,
            const std::shared_ptr< std::wstring > folder = nullptr,
            const std::shared_ptr< std::wstring > storage = nullptr,
            const std::shared_ptr< std::wstring > loadEncoding = nullptr,
            const std::shared_ptr< std::wstring > password = nullptr,
            const std::shared_ptr< std::wstring > encryptedPassword = nullptr,
            const std::shared_ptr< bool > useAntiAliasing = nullptr,
            const std::shared_ptr< bool > useHighQualityRendering = nullptr,
            const std::shared_ptr< double > imageBrightness = nullptr,
            const std::shared_ptr< std::wstring > imageColorMode = nullptr,
            const std::shared_ptr< double > imageContrast = nullptr,
            const std::shared_ptr< std::wstring > numeralFormat = nullptr,
            const std::shared_ptr< int32_t > pageCount = nullptr,
            const std::shared_ptr< int32_t > pageIndex = nullptr,
            const std::shared_ptr< std::wstring > paperColor = nullptr,
            const std::shared_ptr< std::wstring > pixelFormat = nullptr,
            const std::shared_ptr< double > resolution = nullptr,
            const std::shared_ptr< double > scale = nullptr,
            const std::shared_ptr< std::wstring > tiffCompression = nullptr,
            const std::shared_ptr< std::wstring > dmlRenderingMode = nullptr,
            const std::shared_ptr< std::wstring > dmlEffectsRenderingMode = nullptr,
            const std::shared_ptr< std::wstring > tiffBinarizationMethod = nullptr,
            const std::shared_ptr< bool > zipOutput = nullptr,
            const std::shared_ptr< std::wstring > fontsLocation = nullptr
        );

        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getName() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< aspose::words::cloud::models::TiffSaveOptionsData > getSaveOptions() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getFolder() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getStorage() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getLoadEncoding() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getPassword() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getEncryptedPassword() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< bool > getUseAntiAliasing() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< bool > getUseHighQualityRendering() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< double > getImageBrightness() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getImageColorMode() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< double > getImageContrast() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getNumeralFormat() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< int32_t > getPageCount() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< int32_t > getPageIndex() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getPaperColor() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getPixelFormat() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< double > getResolution() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< double > getScale() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getTiffCompression() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getDmlRenderingMode() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getDmlEffectsRenderingMode() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getTiffBinarizationMethod() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< bool > getZipOutput() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getFontsLocation() const;

        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::HttpRequestData > createHttpRequest() const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > createResponse() const override;

    private:
        const std::shared_ptr< std::wstring > m_Name;
        const std::shared_ptr< aspose::words::cloud::models::TiffSaveOptionsData > m_SaveOptions;
        const std::shared_ptr< std::wstring > m_Folder;
        const std::shared_ptr< std::wstring > m_Storage;
        const std::shared_ptr< std::wstring > m_LoadEncoding;
        const std::shared_ptr< std::wstring > m_Password;
        const std::shared_ptr< std::wstring > m_EncryptedPassword;
        const std::shared_ptr< bool > m_UseAntiAliasing;
        const std::shared_ptr< bool > m_UseHighQualityRendering;
        const std::shared_ptr< double > m_ImageBrightness;
        const std::shared_ptr< std::wstring > m_ImageColorMode;
        const std::shared_ptr< double > m_ImageContrast;
        const std::shared_ptr< std::wstring > m_NumeralFormat;
        const std::shared_ptr< int32_t > m_PageCount;
        const std::shared_ptr< int32_t > m_PageIndex;
        const std::shared_ptr< std::wstring > m_PaperColor;
        const std::shared_ptr< std::wstring > m_PixelFormat;
        const std::shared_ptr< double > m_Resolution;
        const std::shared_ptr< double > m_Scale;
        const std::shared_ptr< std::wstring > m_TiffCompression;
        const std::shared_ptr< std::wstring > m_DmlRenderingMode;
        const std::shared_ptr< std::wstring > m_DmlEffectsRenderingMode;
        const std::shared_ptr< std::wstring > m_TiffBinarizationMethod;
        const std::shared_ptr< bool > m_ZipOutput;
        const std::shared_ptr< std::wstring > m_FontsLocation;
    };
}
