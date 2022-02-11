/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="field_options.h">
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
#include "user_information.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// DTO for field options.
    /// </summary>
    class FieldOptions : public ModelBase
    {
    public:
        /// <summary>
        /// Gets or sets Field Index Format.
        /// </summary>
        enum class FieldIndexFormat
        { 
            TEMPLATE,
            CLASSIC,
            FANCY,
            MODERN,
            BULLETED,
            FORMAL,
            SIMPLE
        };

        /// <summary>
        /// Gets or sets Field Update Culture Source.
        /// </summary>
        enum class FieldUpdateCultureSource
        { 
            CURRENT_THREAD,
            FIELD_CODE
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~FieldOptions() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets BuiltIn Templates Paths.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::vector<std::shared_ptr<std::wstring>> > getBuiltInTemplatesPaths() const;

        /// <summary>
        /// Gets or sets BuiltIn Templates Paths.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBuiltInTemplatesPaths(std::shared_ptr< std::vector<std::shared_ptr<std::wstring>> > value);


        /// <summary>
        /// Gets or sets Curren tUser.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::UserInformation > getCurrentUser() const;

        /// <summary>
        /// Gets or sets Curren tUser.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setCurrentUser(std::shared_ptr< aspose::words::cloud::models::UserInformation > value);


        /// <summary>
        /// Gets or sets Custom Toc Style Separator.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getCustomTocStyleSeparator() const;

        /// <summary>
        /// Gets or sets Custom Toc Style Separator.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setCustomTocStyleSeparator(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets Default Document Author.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getDefaultDocumentAuthor() const;

        /// <summary>
        /// Gets or sets Default Document Author.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDefaultDocumentAuthor(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets Field Index Format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::FieldOptions::FieldIndexFormat > getFieldIndexFormat() const;

        /// <summary>
        /// Gets or sets Field Index Format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFieldIndexFormat(std::shared_ptr< aspose::words::cloud::models::FieldOptions::FieldIndexFormat > value);


        /// <summary>
        /// Gets or sets Field Update Culture Name.
        /// It is used for all fields if FieldUpdateCultureSource is FieldCode.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getFieldUpdateCultureName() const;

        /// <summary>
        /// Gets or sets Field Update Culture Name.
        /// It is used for all fields if FieldUpdateCultureSource is FieldCode.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFieldUpdateCultureName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets Field Update Culture Source.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::FieldOptions::FieldUpdateCultureSource > getFieldUpdateCultureSource() const;

        /// <summary>
        /// Gets or sets Field Update Culture Source.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFieldUpdateCultureSource(std::shared_ptr< aspose::words::cloud::models::FieldOptions::FieldUpdateCultureSource > value);


        /// <summary>
        /// Gets or sets File Name.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getFileName() const;

        /// <summary>
        /// Gets or sets File Name.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFileName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets if Bidi Text Supported OnUpdate.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsBidiTextSupportedOnUpdate() const;

        /// <summary>
        /// Gets or sets if Bidi Text Supported OnUpdate.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsBidiTextSupportedOnUpdate(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets if Legacy Number Format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getLegacyNumberFormat() const;

        /// <summary>
        /// Gets or sets if Legacy Number Format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLegacyNumberFormat(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets PreProcess Culture Name.
        /// It is a culture code for DOC fields.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getPreProcessCultureName() const;

        /// <summary>
        /// Gets or sets PreProcess Culture Name.
        /// It is a culture code for DOC fields.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPreProcessCultureName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets Template Name.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getTemplateName() const;

        /// <summary>
        /// Gets or sets Template Name.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTemplateName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets if Use Invariant Culture Number Format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getUseInvariantCultureNumberFormat() const;

        /// <summary>
        /// Gets or sets if Use Invariant Culture Number Format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setUseInvariantCultureNumberFormat(std::shared_ptr< bool > value);


    protected:
        std::shared_ptr< std::vector<std::shared_ptr<std::wstring>> > m_BuiltInTemplatesPaths;
        std::shared_ptr< aspose::words::cloud::models::UserInformation > m_CurrentUser;
        std::shared_ptr< std::wstring > m_CustomTocStyleSeparator;
        std::shared_ptr< std::wstring > m_DefaultDocumentAuthor;
        std::shared_ptr< aspose::words::cloud::models::FieldOptions::FieldIndexFormat > m_FieldIndexFormat;
        std::shared_ptr< std::wstring > m_FieldUpdateCultureName;
        std::shared_ptr< aspose::words::cloud::models::FieldOptions::FieldUpdateCultureSource > m_FieldUpdateCultureSource;
        std::shared_ptr< std::wstring > m_FileName;
        std::shared_ptr< bool > m_IsBidiTextSupportedOnUpdate;
        std::shared_ptr< bool > m_LegacyNumberFormat;
        std::shared_ptr< std::wstring > m_PreProcessCultureName;
        std::shared_ptr< std::wstring > m_TemplateName;
        std::shared_ptr< bool > m_UseInvariantCultureNumberFormat;
    };
}

