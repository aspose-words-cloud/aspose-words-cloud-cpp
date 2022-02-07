/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="txt_save_options_base_data.h">
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
    /// Base class for save options of text formats.
    /// </summary>
    class TxtSaveOptionsBaseData : public SaveOptionsData
    {
    public:
        /// <summary>
        /// Gets or sets the option that controls whether to output headers and footers when exporting in plain text format.
        /// default value is TxtExportHeadersFootersMode.PrimaryOnly.
        /// </summary>
        enum class ExportHeadersFootersMode
        { 
            NONE,
            PRIMARY_ONLY,
            ALL_AT_END
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~TxtSaveOptionsBaseData() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;

        virtual void abstractTxtSaveOptionsBaseData() = 0;
        void abstractSaveOptionsData() override {}

        /// <summary>
        /// Gets or sets the character encoding to use when exporting in plain text format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getEncoding() const;

        /// <summary>
        /// Gets or sets the character encoding to use when exporting in plain text format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setEncoding(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the option that controls whether to output headers and footers when exporting in plain text format.
        /// default value is TxtExportHeadersFootersMode.PrimaryOnly.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::TxtSaveOptionsBaseData::ExportHeadersFootersMode > getExportHeadersFootersMode() const;

        /// <summary>
        /// Gets or sets the option that controls whether to output headers and footers when exporting in plain text format.
        /// default value is TxtExportHeadersFootersMode.PrimaryOnly.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportHeadersFootersMode(std::shared_ptr< aspose::words::cloud::models::TxtSaveOptionsBaseData::ExportHeadersFootersMode > value);


        /// <summary>
        /// Gets or sets a value indicating whether the page breaks should be preserved during export.
        /// The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getForcePageBreaks() const;

        /// <summary>
        /// Gets or sets a value indicating whether the page breaks should be preserved during export.
        /// The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setForcePageBreaks(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the string to use as a paragraph break when exporting in plain text format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getParagraphBreak() const;

        /// <summary>
        /// Gets or sets the string to use as a paragraph break when exporting in plain text format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setParagraphBreak(std::shared_ptr< std::wstring > value);


    protected:
        std::shared_ptr< std::wstring > m_Encoding;
        std::shared_ptr< aspose::words::cloud::models::TxtSaveOptionsBaseData::ExportHeadersFootersMode > m_ExportHeadersFootersMode;
        std::shared_ptr< bool > m_ForcePageBreaks;
        std::shared_ptr< std::wstring > m_ParagraphBreak;
    };
}

