﻿/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="custom_xml_part.h">
*   Copyright (c) 2021 Aspose.Words for Cloud
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
#include "custom_xml_part_link.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// DTO container with a CustomXmlPart.
    /// </summary>
    class CustomXmlPart : public CustomXmlPartLink
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~CustomXmlPart() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;

        /// <summary>
        /// Gets or sets the custom xml part data.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< std::wstring > getData() const;

        /// <summary>
        /// Gets or sets the custom xml part data.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setData(std::shared_ptr< std::wstring > value);

        /// <summary>
        /// Gets or sets the custom xml part id.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< std::wstring > getId() const;

        /// <summary>
        /// Gets or sets the custom xml part id.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setId(std::shared_ptr< std::wstring > value);

    protected:
        std::shared_ptr< std::wstring > m_Data;
        std::shared_ptr< std::wstring > m_Id;
    };
}
