﻿/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="form_fields_response.h">
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
#include "form_field_collection.h"
#include "words_response.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// The REST response with a collection of form fields.
    /// This response is returned by the Service when handling "GET https://api.aspose.cloud/v4.0/words/Test.doc/{nodePath}/form fields" REST API requests.
    /// </summary>
    class FormFieldsResponse : public WordsResponse
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~FormFieldsResponse() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void getFileReferences(std::vector< FileReference* >& result) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void validate() override;


        /// <summary>
        /// Gets or sets the collection of form fields.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::FormFieldCollection > getFormFields() const;

        /// <summary>
        /// Gets or sets the collection of form fields.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFormFields(std::shared_ptr< aspose::words::cloud::models::FormFieldCollection > value);


    protected:
        std::shared_ptr< aspose::words::cloud::models::FormFieldCollection > m_FormFields;
    };
}

