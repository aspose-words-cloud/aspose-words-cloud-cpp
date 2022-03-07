/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="save_options_data.h">
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
#include "time_zone_info_data.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// base container class for save options data.
    /// </summary>
    class SaveOptionsData : public ModelBase
    {
    public:
        /// <summary>
        /// Gets or sets the value determining how 3D effects are rendered.
        /// </summary>
        enum class Dml3DEffectsRenderingMode
        { 
            BASIC,
            ADVANCED
        };

        /// <summary>
        /// Gets or sets the value determining how DrawingML effects are rendered.
        /// { Simplified | None | Fine }.
        /// </summary>
        enum class DmlEffectsRenderingMode
        { 
            SIMPLIFIED,
            NONE,
            FINE
        };

        /// <summary>
        /// Gets or sets the option that controls how DrawingML shapes are rendered.
        /// </summary>
        enum class DmlRenderingMode
        { 
            FALLBACK,
            DRAWING_ML
        };

        /// <summary>
        /// Gets or sets the value determining how ink (InkML) objects are rendered.
        /// </summary>
        enum class ImlRenderingMode
        { 
            FALLBACK,
            INK_ML
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~SaveOptionsData() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;

        virtual void abstractSaveOptionsData() = 0;

        /// <summary>
        /// Gets or sets a boolean value indicating whether to allow embedding fonts with PostScript outlines when embedding TrueType fonts in a document upon it is saved. The default value is false..
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getAllowEmbeddingPostScriptFonts() const;

        /// <summary>
        /// Gets or sets a boolean value indicating whether to allow embedding fonts with PostScript outlines when embedding TrueType fonts in a document upon it is saved. The default value is false..
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setAllowEmbeddingPostScriptFonts(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets CustomTimeZoneInfo.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::TimeZoneInfoData > getCustomTimeZoneInfoData() const;

        /// <summary>
        /// Gets or sets CustomTimeZoneInfo.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setCustomTimeZoneInfoData(std::shared_ptr< aspose::words::cloud::models::TimeZoneInfoData > value);


        /// <summary>
        /// Gets or sets the value determining how 3D effects are rendered.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::SaveOptionsData::Dml3DEffectsRenderingMode > getDml3DEffectsRenderingMode() const;

        /// <summary>
        /// Gets or sets the value determining how 3D effects are rendered.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDml3DEffectsRenderingMode(std::shared_ptr< aspose::words::cloud::models::SaveOptionsData::Dml3DEffectsRenderingMode > value);


        /// <summary>
        /// Gets or sets the value determining how DrawingML effects are rendered.
        /// { Simplified | None | Fine }.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::SaveOptionsData::DmlEffectsRenderingMode > getDmlEffectsRenderingMode() const;

        /// <summary>
        /// Gets or sets the value determining how DrawingML effects are rendered.
        /// { Simplified | None | Fine }.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDmlEffectsRenderingMode(std::shared_ptr< aspose::words::cloud::models::SaveOptionsData::DmlEffectsRenderingMode > value);


        /// <summary>
        /// Gets or sets the option that controls how DrawingML shapes are rendered.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::SaveOptionsData::DmlRenderingMode > getDmlRenderingMode() const;

        /// <summary>
        /// Gets or sets the option that controls how DrawingML shapes are rendered.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDmlRenderingMode(std::shared_ptr< aspose::words::cloud::models::SaveOptionsData::DmlRenderingMode > value);


        /// <summary>
        /// Gets or sets the name of destination file.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getFileName() const;

        /// <summary>
        /// Gets or sets the name of destination file.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFileName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets value determining which document formats are allowed to be mapped by Aspose.Words.Markup.StructuredDocumentTag.XmlMapping.
        /// By default only Aspose.Words.LoadFormat.FlatOpc document format is allowed to be mapped.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getFlatOpcXmlMappingOnly() const;

        /// <summary>
        /// Gets or sets value determining which document formats are allowed to be mapped by Aspose.Words.Markup.StructuredDocumentTag.XmlMapping.
        /// By default only Aspose.Words.LoadFormat.FlatOpc document format is allowed to be mapped.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFlatOpcXmlMappingOnly(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the value determining how ink (InkML) objects are rendered.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::SaveOptionsData::ImlRenderingMode > getImlRenderingMode() const;

        /// <summary>
        /// Gets or sets the value determining how ink (InkML) objects are rendered.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setImlRenderingMode(std::shared_ptr< aspose::words::cloud::models::SaveOptionsData::ImlRenderingMode > value);


        /// <summary>
        /// Gets the format of save.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getSaveFormat() const;



        /// <summary>
        /// Gets or sets a value determining whether the Aspose.Words.Properties.BuiltInDocumentProperties.CreatedTime property is updated before saving.
        /// Default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getUpdateCreatedTimeProperty() const;

        /// <summary>
        /// Gets or sets a value determining whether the Aspose.Words.Properties.BuiltInDocumentProperties.CreatedTime property is updated before saving.
        /// Default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setUpdateCreatedTimeProperty(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether fields should be updated before saving the document to a fixed page format. The default value is true.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getUpdateFields() const;

        /// <summary>
        /// Gets or sets a value indicating whether fields should be updated before saving the document to a fixed page format. The default value is true.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setUpdateFields(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether the Aspose.Words.Properties.BuiltInDocumentProperties.LastPrinted property is updated before saving.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getUpdateLastPrintedProperty() const;

        /// <summary>
        /// Gets or sets a value indicating whether the Aspose.Words.Properties.BuiltInDocumentProperties.LastPrinted property is updated before saving.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setUpdateLastPrintedProperty(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether the Aspose.Words.Properties.BuiltInDocumentProperties.LastSavedTime property is updated before saving.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getUpdateLastSavedTimeProperty() const;

        /// <summary>
        /// Gets or sets a value indicating whether the Aspose.Words.Properties.BuiltInDocumentProperties.LastSavedTime property is updated before saving.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setUpdateLastSavedTimeProperty(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether content of StructuredDocumentTag is updated before saving.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getUpdateSdtContent() const;

        /// <summary>
        /// Gets or sets a value indicating whether content of StructuredDocumentTag is updated before saving.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setUpdateSdtContent(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether to zip output or not.
        /// The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getZipOutput() const;

        /// <summary>
        /// Gets or sets a value indicating whether to zip output or not.
        /// The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setZipOutput(std::shared_ptr< bool > value);


    protected:
        std::shared_ptr< bool > m_AllowEmbeddingPostScriptFonts;
        std::shared_ptr< aspose::words::cloud::models::TimeZoneInfoData > m_CustomTimeZoneInfoData;
        std::shared_ptr< aspose::words::cloud::models::SaveOptionsData::Dml3DEffectsRenderingMode > m_Dml3DEffectsRenderingMode;
        std::shared_ptr< aspose::words::cloud::models::SaveOptionsData::DmlEffectsRenderingMode > m_DmlEffectsRenderingMode;
        std::shared_ptr< aspose::words::cloud::models::SaveOptionsData::DmlRenderingMode > m_DmlRenderingMode;
        std::shared_ptr< std::wstring > m_FileName;
        std::shared_ptr< bool > m_FlatOpcXmlMappingOnly;
        std::shared_ptr< aspose::words::cloud::models::SaveOptionsData::ImlRenderingMode > m_ImlRenderingMode;
        std::shared_ptr< std::wstring > m_SaveFormat;
        std::shared_ptr< bool > m_UpdateCreatedTimeProperty;
        std::shared_ptr< bool > m_UpdateFields;
        std::shared_ptr< bool > m_UpdateLastPrintedProperty;
        std::shared_ptr< bool > m_UpdateLastSavedTimeProperty;
        std::shared_ptr< bool > m_UpdateSdtContent;
        std::shared_ptr< bool > m_ZipOutput;
    };
}

