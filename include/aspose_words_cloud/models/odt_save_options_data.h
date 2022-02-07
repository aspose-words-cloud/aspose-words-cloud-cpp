/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="odt_save_options_data.h">
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
    /// Container class for odt/ott save options.
    /// </summary>
    class OdtSaveOptionsData : public SaveOptionsData
    {
    public:
        /// <summary>
        /// Gets or sets the units of measure to apply to document content. The default value is Aspose.Words.Saving.OdtSaveMeasureUnit.Centimeters.
        /// Open Office uses centimeters when specifying lengths, widths and other measurable formatting and content properties in documents whereas MS Office uses inches.
        /// </summary>
        enum class MeasureUnit
        { 
            CENTIMETERS,
            INCHES
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~OdtSaveOptionsData() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;

        void abstractSaveOptionsData() override {}

        /// <summary>
        /// Gets or sets a value indicating whether export should correspond to ODT specification 1.1 strictly.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsStrictSchema11() const;

        /// <summary>
        /// Gets or sets a value indicating whether export should correspond to ODT specification 1.1 strictly.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsStrictSchema11(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the units of measure to apply to document content. The default value is Aspose.Words.Saving.OdtSaveMeasureUnit.Centimeters.
        /// Open Office uses centimeters when specifying lengths, widths and other measurable formatting and content properties in documents whereas MS Office uses inches.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::OdtSaveOptionsData::MeasureUnit > getMeasureUnit() const;

        /// <summary>
        /// Gets or sets the units of measure to apply to document content. The default value is Aspose.Words.Saving.OdtSaveMeasureUnit.Centimeters.
        /// Open Office uses centimeters when specifying lengths, widths and other measurable formatting and content properties in documents whereas MS Office uses inches.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setMeasureUnit(std::shared_ptr< aspose::words::cloud::models::OdtSaveOptionsData::MeasureUnit > value);


        /// <summary>
        /// Gets or sets the password to encrypt document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getPassword() const;

        /// <summary>
        /// Gets or sets the password to encrypt document.
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


        /// <summary>
        /// Gets the format of save.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getSaveFormat() const override;



    protected:
        std::shared_ptr< bool > m_IsStrictSchema11;
        std::shared_ptr< aspose::words::cloud::models::OdtSaveOptionsData::MeasureUnit > m_MeasureUnit;
        std::shared_ptr< std::wstring > m_Password;
        std::shared_ptr< bool > m_PrettyFormat;
        std::shared_ptr< std::wstring > m_SaveFormat = std::make_shared<std::wstring>(L"odt");
    };
}

