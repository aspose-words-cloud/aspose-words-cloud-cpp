/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FieldBase.cpp">
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


#include "FieldBase.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

FieldBase::FieldBase()
{
    m_FieldCode = utility::conversions::to_string_t("");
    m_FieldCodeIsSet = false;
    m_LocaleId = utility::conversions::to_string_t("");
    m_LocaleIdIsSet = false;
}

FieldBase::~FieldBase()
{
}

void FieldBase::validate()
{
    // TODO: implement validation
}

web::json::value FieldBase::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_FieldCodeIsSet)
    {
        val[_XPLATSTR("FieldCode")] = ModelBase::toJson(m_FieldCode);
    }
    if(m_LocaleIdIsSet)
    {
        val[_XPLATSTR("LocaleId")] = ModelBase::toJson(m_LocaleId);
    }

    return val;
}

void FieldBase::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("FieldCode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("FieldCode")];
        if(!fieldValue.is_null())
        {
            setFieldCode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("LocaleId")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("LocaleId")];
        if(!fieldValue.is_null())
        {
            setLocaleId(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void FieldBase::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_FieldCodeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("FieldCode"), m_FieldCode));
        
    }
    if(m_LocaleIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("LocaleId"), m_LocaleId));
        
    }
}

void FieldBase::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    

    if(multipart->hasContent(_XPLATSTR("FieldCode")))
    {
        setFieldCode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("FieldCode"))));
    }
    if(multipart->hasContent(_XPLATSTR("LocaleId")))
    {
        setLocaleId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("LocaleId"))));
    }
}

<DATA_TYPE_START>string<DATA_TYPE_END> FieldBase::getFieldCode() const
{
    return m_FieldCode;
}


void FieldBase::setFieldCode(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_FieldCode = value;
    m_FieldCodeIsSet = true;
}
bool FieldBase::fieldCodeIsSet() const
{
    return m_FieldCodeIsSet;
}

void FieldBase::unsetFieldCode()
{
    m_FieldCodeIsSet = false;
}

<DATA_TYPE_START>string<DATA_TYPE_END> FieldBase::getLocaleId() const
{
    return m_LocaleId;
}


void FieldBase::setLocaleId(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_LocaleId = value;
    m_LocaleIdIsSet = true;
}
bool FieldBase::localeIdIsSet() const
{
    return m_LocaleIdIsSet;
}

void FieldBase::unsetLocaleId()
{
    m_LocaleIdIsSet = false;
}

}
}
}
}
}

