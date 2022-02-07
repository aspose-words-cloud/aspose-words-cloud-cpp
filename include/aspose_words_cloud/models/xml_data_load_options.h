/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="xml_data_load_options.h">
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

namespace aspose::words::cloud::models {
    /// <summary>
    /// Represents options for XML data loading.
    /// </summary>
    class XmlDataLoadOptions : public ModelBase
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~XmlDataLoadOptions() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets a flag indicating whether a generated data source will always contain an object for an XML root
        /// element. If an XML root element has no attributes and all its child elements have same names, such an object
        /// is not created by default.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getAlwaysGenerateRootObject() const;

        /// <summary>
        /// Gets or sets a flag indicating whether a generated data source will always contain an object for an XML root
        /// element. If an XML root element has no attributes and all its child elements have same names, such an object
        /// is not created by default.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setAlwaysGenerateRootObject(std::shared_ptr< bool > value);


    protected:
        std::shared_ptr< bool > m_AlwaysGenerateRootObject;
    };
}

