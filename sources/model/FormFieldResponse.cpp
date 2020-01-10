/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FormFieldResponse.cpp">
*   Copyright (c) 2019 Aspose.Words for Cloud
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


#include "FormFieldResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

FormFieldResponse::FormFieldResponse()
{
    m_FormFieldIsSet = false;
}

FormFieldResponse::~FormFieldResponse()
{
}

void FormFieldResponse::validate()
{
    // TODO: implement validation
}

web::json::value FormFieldResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();

    if(m_FormFieldIsSet)
    {
        val[_XPLATSTR("formField")] = ModelBase::toJson(m_FormField);
    }

    return val;
}

void FormFieldResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("formField")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("formField")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<FormField> newItem(new FormField());
            newItem->fromJson(fieldValue);
            setFormField( newItem );
        }
    }
}

void FormFieldResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_RequestIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("requestId"), m_RequestId));
        
    }
    if(m_FormFieldIsSet)
    {
        if (m_FormField.get())
        {
            m_FormField->toMultipart(multipart, _XPLATSTR("formField."));
        }
        
    }
}

void FormFieldResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("requestId")))
    {
        setRequestId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("requestId"))));
    }
    if(multipart->hasContent(_XPLATSTR("formField")))
    {
        if(multipart->hasContent(_XPLATSTR("formField")))
        {
            std::shared_ptr<FormField> newItem(new FormField());
            newItem->fromMultiPart(multipart, _XPLATSTR("formField."));
            setFormField( newItem );
        }
    }
}

std::shared_ptr<FormField> FormFieldResponse::getFormField() const
{
    return m_FormField;
}


void FormFieldResponse::setFormField(std::shared_ptr<FormField> value)
{
    m_FormField = value;
    m_FormFieldIsSet = true;
}
bool FormFieldResponse::formFieldIsSet() const
{
    return m_FormFieldIsSet;
}

void FormFieldResponse::unsetFormField()
{
    m_FormFieldIsSet = false;
}

}
}
}
}
}

