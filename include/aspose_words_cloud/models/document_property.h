/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="document_property.h">
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

namespace aspose::words::cloud::models {
    /// <summary>
    /// Words document property DTO.
    /// </summary>
    class DocumentProperty : public LinkElement
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~DocumentProperty() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets a value indicating whether the property is built-in or not.
        /// If true the property is built-in, if false the property is custom.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getBuiltIn() const;

        /// <summary>
        /// Gets or sets a value indicating whether the property is built-in or not.
        /// If true the property is built-in, if false the property is custom.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBuiltIn(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the name of the document property.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getName() const;

        /// <summary>
        /// Gets or sets the name of the document property.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the value of the document property.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getValue() const;

        /// <summary>
        /// Gets or sets the value of the document property.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setValue(std::shared_ptr< std::wstring > value);


    protected:
        std::shared_ptr< bool > m_BuiltIn;
        std::shared_ptr< std::wstring > m_Name;
        std::shared_ptr< std::wstring > m_Value;
    };
}

