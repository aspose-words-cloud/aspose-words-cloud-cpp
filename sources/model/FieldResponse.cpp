/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FieldResponse.cpp">
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


#include "FieldResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

FieldResponse::FieldResponse()
{
    m_FieldIsSet = false;
}

FieldResponse::~FieldResponse()
{
}

void FieldResponse::validate()
{
    // TODO: implement validation
}

web::json::value FieldResponse::toJson() const
{
    web::json::value val = this->AsposeResponse::toJson();

    if(m_FieldIsSet)
    {
        val[_XPLATSTR("Field")] = ModelBase::toJson(m_Field);
    }

    return val;
}

void FieldResponse::fromJson(web::json::value& val)
{
    this->AsposeResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("Field")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Field")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Field> newItem(new Field());
            newItem->fromJson(fieldValue);
            setField( newItem );
        }
    }
}

void FieldResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Code"), m_Code));
    if(m_StatusIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Status"), m_Status));
        
    }
    if(m_FieldIsSet)
    {
        if (m_Field.get())
        {
            m_Field->toMultipart(multipart, _XPLATSTR("Field."));
        }
        
    }
}

void FieldResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    setCode(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("Code"))));
    if(multipart->hasContent(_XPLATSTR("Status")))
    {
        setStatus(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Status"))));
    }
    if(multipart->hasContent(_XPLATSTR("Field")))
    {
        if(multipart->hasContent(_XPLATSTR("Field")))
        {
            std::shared_ptr<Field> newItem(new Field());
            newItem->fromMultiPart(multipart, _XPLATSTR("Field."));
            setField( newItem );
        }
    }
}

std::shared_ptr<Field> FieldResponse::getField() const
{
    return m_Field;
}


void FieldResponse::setField(std::shared_ptr<Field> value)
{
    m_Field = value;
    m_FieldIsSet = true;
}
bool FieldResponse::fieldIsSet() const
{
    return m_FieldIsSet;
}

void FieldResponse::unsetField()
{
    m_FieldIsSet = false;
}

}
}
}
}
}

