/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="list_info.h">
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


        /// <summary>
        /// Gets or sets a value indicating whether this list is a definition of a list style.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsListStyleDefinition() const;

        /// <summary>
        /// Gets or sets a value indicating whether this list is a definition of a list style.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsListStyleDefinition(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether this list is a reference to a list style.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsListStyleReference() const;

        /// <summary>
        /// Gets or sets a value indicating whether this list is a reference to a list style.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsListStyleReference(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether the list contains 9 levels; false when 1 level.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsMultiLevel() const;

        /// <summary>
        /// Gets or sets a value indicating whether the list contains 9 levels; false when 1 level.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsMultiLevel(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether list should be restarted at each section. The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsRestartAtEachSection() const;

        /// <summary>
        /// Gets or sets a value indicating whether list should be restarted at each section. The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsRestartAtEachSection(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the unique identifier of the list.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getListId() const;

        /// <summary>
        /// Gets or sets the unique identifier of the list.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setListId(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the collection of list levels for this list.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::ListLevels > getListLevels() const;

        /// <summary>
        /// Gets or sets the collection of list levels for this list.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setListLevels(std::shared_ptr< aspose::words::cloud::models::ListLevels > value);


        /// <summary>
        /// Gets or sets the list style that this list references or defines.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::Style > getStyle() const;

        /// <summary>
        /// Gets or sets the list style that this list references or defines.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setStyle(std::shared_ptr< aspose::words::cloud::models::Style > value);


    protected:
        std::shared_ptr< bool > m_IsListStyleDefinition;
        std::shared_ptr< bool > m_IsListStyleReference;
        std::shared_ptr< bool > m_IsMultiLevel;
        std::shared_ptr< bool > m_IsRestartAtEachSection;
        std::shared_ptr< int32_t > m_ListId;
        std::shared_ptr< aspose::words::cloud::models::ListLevels > m_ListLevels;
        std::shared_ptr< aspose::words::cloud::models::Style > m_Style;
    };
}

