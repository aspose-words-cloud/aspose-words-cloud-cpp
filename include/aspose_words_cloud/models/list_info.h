/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="list_info.h">
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
#include "model_base.h"
#include "link_element.h"
#include "list_levels.h"
#include "style.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// DTO container with a single document list.
    /// </summary>
    class ListInfo : public LinkElement
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~ListInfo() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void getFileReferences(std::vector< FileReference* >& result) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void validate() override;


        /// <summary>
        /// Gets or sets the unique identifier of the list.
        /// You do not normally need to use this property. But if you use it, you normally do so in conjunction with the Aspose.Words.Lists.ListCollection.GetListByListId(System.Int32) method to find a list by its identifier.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getListId() const;

        /// <summary>
        /// Gets or sets the unique identifier of the list.
        /// You do not normally need to use this property. But if you use it, you normally do so in conjunction with the Aspose.Words.Lists.ListCollection.GetListByListId(System.Int32) method to find a list by its identifier.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setListId(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets a value indicating whether the list contains 9 levels; false when 1 level.
        /// The lists that you create with Aspose.Words are always multi-level lists and contain 9 levels. Microsoft Word 2003 and later always create multi-level lists with 9 levels. But in some documents, created with earlier versions of Microsoft Word you might encounter lists that have 1 level only.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsMultiLevel() const;

        /// <summary>
        /// Gets or sets a value indicating whether the list contains 9 levels; false when 1 level.
        /// The lists that you create with Aspose.Words are always multi-level lists and contain 9 levels. Microsoft Word 2003 and later always create multi-level lists with 9 levels. But in some documents, created with earlier versions of Microsoft Word you might encounter lists that have 1 level only.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsMultiLevel(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether list should be restarted at each section. The default value is false.
        /// This option is supported only in RTF, DOC and DOCX document formats. This option will be written to DOCX only if Aspose.Words.Saving.OoxmlCompliance is higher then Aspose.Words.Saving.OoxmlCompliance.Ecma376_2006.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsRestartAtEachSection() const;

        /// <summary>
        /// Gets or sets a value indicating whether list should be restarted at each section. The default value is false.
        /// This option is supported only in RTF, DOC and DOCX document formats. This option will be written to DOCX only if Aspose.Words.Saving.OoxmlCompliance is higher then Aspose.Words.Saving.OoxmlCompliance.Ecma376_2006.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsRestartAtEachSection(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether this list is a definition of a list style.
        /// When this property is true, the Aspose.Words.Lists.List.Style property returns the list style that this list defines. By modifying properties of a list that defines a list style, you modify The properties of the list style. A list that is a definition of a list style cannot be applied directly to paragraphs to make them numbered. Aspose.Words.Lists.List.Style Aspose.Words.Lists.List.IsListStyleReference.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsListStyleDefinition() const;

        /// <summary>
        /// Gets or sets a value indicating whether this list is a definition of a list style.
        /// When this property is true, the Aspose.Words.Lists.List.Style property returns the list style that this list defines. By modifying properties of a list that defines a list style, you modify The properties of the list style. A list that is a definition of a list style cannot be applied directly to paragraphs to make them numbered. Aspose.Words.Lists.List.Style Aspose.Words.Lists.List.IsListStyleReference.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsListStyleDefinition(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether this list is a reference to a list style.
        /// Note, modifying properties of a list that is a reference to list style has no effect. The list formatting specified in the list style itself always takes precedence. Aspose.Words.Lists.List.Style Aspose.Words.Lists.List.IsListStyleDefinition.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsListStyleReference() const;

        /// <summary>
        /// Gets or sets a value indicating whether this list is a reference to a list style.
        /// Note, modifying properties of a list that is a reference to list style has no effect. The list formatting specified in the list style itself always takes precedence. Aspose.Words.Lists.List.Style Aspose.Words.Lists.List.IsListStyleDefinition.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsListStyleReference(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the list style that this list references or defines.
        /// If this list is not associated with a list style, the property will return null. A list could be a reference to a list style, in this case Aspose.Words.Lists.List.IsListStyleReference will be true. A list could be a definition of a list style, in this case Aspose.Words.Lists.List.IsListStyleDefinition will be true. Such a list cannot be applied to paragraphs in the document directly.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::Style > getStyle() const;

        /// <summary>
        /// Gets or sets the list style that this list references or defines.
        /// If this list is not associated with a list style, the property will return null. A list could be a reference to a list style, in this case Aspose.Words.Lists.List.IsListStyleReference will be true. A list could be a definition of a list style, in this case Aspose.Words.Lists.List.IsListStyleDefinition will be true. Such a list cannot be applied to paragraphs in the document directly.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setStyle(std::shared_ptr< aspose::words::cloud::models::Style > value);


        /// <summary>
        /// Gets or sets the collection of list levels for this list.
        /// Use this property to access and modify formatting individual to each level of the list.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::ListLevels > getListLevels() const;

        /// <summary>
        /// Gets or sets the collection of list levels for this list.
        /// Use this property to access and modify formatting individual to each level of the list.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setListLevels(std::shared_ptr< aspose::words::cloud::models::ListLevels > value);


    protected:
        std::shared_ptr< int32_t > m_ListId;
        std::shared_ptr< bool > m_IsMultiLevel;
        std::shared_ptr< bool > m_IsRestartAtEachSection;
        std::shared_ptr< bool > m_IsListStyleDefinition;
        std::shared_ptr< bool > m_IsListStyleReference;
        std::shared_ptr< aspose::words::cloud::models::Style > m_Style;
        std::shared_ptr< aspose::words::cloud::models::ListLevels > m_ListLevels;
    };
}

