/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="rtf_save_options_data.h">
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
#include "./model_base.h"
#include "save_options_data.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Container class for rtf save options.
    /// </summary>
    class RtfSaveOptionsData : public SaveOptionsData
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~RtfSaveOptionsData() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;

        void abstractSaveOptionsData() override {}

        /// <summary>
        /// Gets or sets a value indicating whether to make output RTF documents smaller in size, but if they contain RTL (right-to-left) text, it will not be displayed correctly.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getExportCompactSize() const;

        /// <summary>
        /// Gets or sets a value indicating whether to make output RTF documents smaller in size, but if they contain RTL (right-to-left) text, it will not be displayed correctly.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportCompactSize(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether the keywords for "old readers" are written to RTF or not.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getExportImagesForOldReaders() const;

        /// <summary>
        /// Gets or sets a value indicating whether the keywords for "old readers" are written to RTF or not.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportImagesForOldReaders(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether to use pretty formats output.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getPrettyFormat() const;

        /// <summary>
        /// Gets or sets a value indicating whether to use pretty formats output.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPrettyFormat(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets the format of save.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getSaveFormat() const override;



        /// <summary>
        /// Gets or sets a value indicating whether when true all images will be saved as WMF. This option might help to avoid WordPad warning messages.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getSaveImagesAsWmf() const;

        /// <summary>
        /// Gets or sets a value indicating whether when true all images will be saved as WMF. This option might help to avoid WordPad warning messages.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSaveImagesAsWmf(std::shared_ptr< bool > value);


    protected:
        std::shared_ptr< bool > m_ExportCompactSize;
        std::shared_ptr< bool > m_ExportImagesForOldReaders;
        std::shared_ptr< bool > m_PrettyFormat;
        std::shared_ptr< std::wstring > m_SaveFormat = std::make_shared<std::wstring>(L"rtf");
        std::shared_ptr< bool > m_SaveImagesAsWmf;
    };
}

