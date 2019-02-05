/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FieldsResponse.cpp">
*   Copyright (c) 2018 Aspose.Words for Cloud
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


#include "FieldsResponse.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

FieldsResponse::FieldsResponse()
{
    m_FieldsIsSet = false;
}

FieldsResponse::~FieldsResponse()
{
}

void FieldsResponse::validate()
{
    // TODO: implement validation
}

web::json::value FieldsResponse::toJson() const
{
    web::json::value val = this->AsposeResponse::toJson();

    if(m_FieldsIsSet)
    {
        val[_XPLATSTR("Fields")] = ModelBase::toJson(m_Fields);
    }

    return val;
}

void FieldsResponse::fromJson(web::json::value& val)
{
    this->AsposeResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("Fields")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Fields")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<FieldCollection> newItem(new FieldCollection());
            newItem->fromJson(fieldValue);
            setFields( newItem );
        }
    }
}

void FieldsResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Code"), m_Code));
    if(m_StatusIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Status"), m_Status));
        
    }
    if(m_FieldsIsSet)
    {
        if (m_Fields.get())
        {
            m_Fields->toMultipart(multipart, _XPLATSTR("Fields."));
        }
        
    }
}

void FieldsResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    setCode(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("Code"))));
    if(multipart->hasContent(_XPLATSTR("Status")))
    {
        setStatus(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Status"))));
    }
    if(multipart->hasContent(_XPLATSTR("Fields")))
    {
        if(multipart->hasContent(_XPLATSTR("Fields")))
        {
            std::shared_ptr<FieldCollection> newItem(new FieldCollection());
            newItem->fromMultiPart(multipart, _XPLATSTR("Fields."));
            setFields( newItem );
        }
    }
}

std::shared_ptr<FieldCollection> FieldsResponse::getFields() const
{
    return m_Fields;
}


void FieldsResponse::setFields(std::shared_ptr<FieldCollection> value)
{
    m_Fields = value;
    m_FieldsIsSet = true;
}
bool FieldsResponse::fieldsIsSet() const
{
    return m_FieldsIsSet;
}

void FieldsResponse::unsetFields()
{
    m_FieldsIsSet = false;
}

}
}
}
}

