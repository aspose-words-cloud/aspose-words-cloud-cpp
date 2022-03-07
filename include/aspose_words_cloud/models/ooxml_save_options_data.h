/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ooxml_save_options_data.h">
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
    /// Container class for docx/docm/dotx/dotm/flatopc save options.
    /// </summary>
    class OoxmlSaveOptionsData : public SaveOptionsData
    {
    public:
        /// <summary>
        /// Gets or sets the oOXML version for the output document.
        /// </summary>
        enum class Compliance
        { 
            ECMA376_2006,
            ISO29500_2008__TRANSITIONAL,
            ISO29500_2008__STRICT
        };

        /// <summary>
        /// Gets or sets the compression level.
        /// </summary>
        enum class CompressionLevel
        { 
            NORMAL,
            MAXIMUM,
            FAST,
            SUPER_FAST
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~OoxmlSaveOptionsData() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;

        virtual void abstractOoxmlSaveOptionsData() = 0;
        void abstractSaveOptionsData() override {}

        /// <summary>
        /// Gets or sets the oOXML version for the output document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::OoxmlSaveOptionsData::Compliance > getCompliance() const;

        /// <summary>
        /// Gets or sets the oOXML version for the output document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setCompliance(std::shared_ptr< aspose::words::cloud::models::OoxmlSaveOptionsData::Compliance > value);


        /// <summary>
        /// Gets or sets the compression level.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::OoxmlSaveOptionsData::CompressionLevel > getCompressionLevel() const;

        /// <summary>
        /// Gets or sets the compression level.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setCompressionLevel(std::shared_ptr< aspose::words::cloud::models::OoxmlSaveOptionsData::CompressionLevel > value);


        /// <summary>
        /// Gets or sets the password to encrypt document using ECMA376 Standard encryption algorithm.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getPassword() const;

        /// <summary>
        /// Gets or sets the password to encrypt document using ECMA376 Standard encryption algorithm.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPassword(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets a value indicating whether to use pretty formats output.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getPrettyFormat() const;

        /// <summary>
        /// Gets or sets a value indicating whether to use pretty formats output.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPrettyFormat(std::shared_ptr< bool > value);


    protected:
        std::shared_ptr< aspose::words::cloud::models::OoxmlSaveOptionsData::Compliance > m_Compliance;
        std::shared_ptr< aspose::words::cloud::models::OoxmlSaveOptionsData::CompressionLevel > m_CompressionLevel;
        std::shared_ptr< std::wstring > m_Password;
        std::shared_ptr< bool > m_PrettyFormat;
    };
}

