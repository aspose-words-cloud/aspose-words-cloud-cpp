﻿/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="section.h">
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
#include "model_base.h"
#include "link_element.h"
#include "node_link.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// DTO container with a section element.
    /// </summary>
    class Section : public LinkElement
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~Section() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void getFileReferences(std::vector< FileReference* >& result) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void validate() override;


        /// <summary>
        /// Gets or sets the list of child nodes.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::NodeLink>> > getChildNodes() const;

        /// <summary>
        /// Gets or sets the list of child nodes.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setChildNodes(std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::NodeLink>> > value);


        /// <summary>
        /// Gets or sets the link to Paragraphs resource.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::LinkElement > getParagraphs() const;

        /// <summary>
        /// Gets or sets the link to Paragraphs resource.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setParagraphs(std::shared_ptr< aspose::words::cloud::models::LinkElement > value);


        /// <summary>
        /// Gets or sets the link to PageSetup resource.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::LinkElement > getPageSetup() const;

        /// <summary>
        /// Gets or sets the link to PageSetup resource.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPageSetup(std::shared_ptr< aspose::words::cloud::models::LinkElement > value);


        /// <summary>
        /// Gets or sets the link to HeaderFooters resource.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::LinkElement > getHeaderFooters() const;

        /// <summary>
        /// Gets or sets the link to HeaderFooters resource.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setHeaderFooters(std::shared_ptr< aspose::words::cloud::models::LinkElement > value);


        /// <summary>
        /// Gets or sets the link to Tables resource.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::LinkElement > getTables() const;

        /// <summary>
        /// Gets or sets the link to Tables resource.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTables(std::shared_ptr< aspose::words::cloud::models::LinkElement > value);


    protected:
        std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::NodeLink>> > m_ChildNodes;
        std::shared_ptr< aspose::words::cloud::models::LinkElement > m_Paragraphs;
        std::shared_ptr< aspose::words::cloud::models::LinkElement > m_PageSetup;
        std::shared_ptr< aspose::words::cloud::models::LinkElement > m_HeaderFooters;
        std::shared_ptr< aspose::words::cloud::models::LinkElement > m_Tables;
    };
}

