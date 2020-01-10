/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DocumentProperty.cpp">
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


#include "DocumentProperty.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

DocumentProperty::DocumentProperty()
{
    m_BuiltIn = false;
    m_BuiltInIsSet = false;
    m_Name = utility::conversions::to_string_t("");
    m_NameIsSet = false;
    m_Value = utility::conversions::to_string_t("");
    m_ValueIsSet = false;
}

DocumentProperty::~DocumentProperty()
{
}

void DocumentProperty::validate()
{
    // TODO: implement validation
}

web::json::value DocumentProperty::toJson() const
{
    web::json::value val = this->LinkElement::toJson();

    if(m_BuiltInIsSet)
    {
        val[_XPLATSTR("builtIn")] = ModelBase::toJson(m_BuiltIn);
    }
    if(m_NameIsSet)
    {
        val[_XPLATSTR("name")] = ModelBase::toJson(m_Name);
    }
    if(m_ValueIsSet)
    {
        val[_XPLATSTR("value")] = ModelBase::toJson(m_Value);
    }

    return val;
}

void DocumentProperty::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    if(val.has_field(_XPLATSTR("builtIn")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("builtIn")];
        if(!fieldValue.is_null())
        {
            setBuiltIn(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("name")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("name")];
        if(!fieldValue.is_null())
        {
            setName(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("value")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("value")];
        if(!fieldValue.is_null())
        {
            setValue(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void DocumentProperty::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_LinkIsSet)
    {
        if (m_Link.get())
        {
            m_Link->toMultipart(multipart, _XPLATSTR("link."));
        }
        
    }
    if(m_BuiltInIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("builtIn"), m_BuiltIn));
    }
    if(m_NameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("name"), m_Name));
        
    }
    if(m_ValueIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("value"), m_Value));
        
    }
}

void DocumentProperty::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("link")))
    {
        if(multipart->hasContent(_XPLATSTR("link")))
        {
            std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
            newItem->fromMultiPart(multipart, _XPLATSTR("link."));
            setLink( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("builtIn")))
    {
        setBuiltIn(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("builtIn"))));
    }
    if(multipart->hasContent(_XPLATSTR("name")))
    {
        setName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("name"))));
    }
    if(multipart->hasContent(_XPLATSTR("value")))
    {
        setValue(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("value"))));
    }
}

bool DocumentProperty::isBuiltIn() const
{
    return m_BuiltIn;
}


void DocumentProperty::setBuiltIn(bool value)
{
    m_BuiltIn = value;
    m_BuiltInIsSet = true;
}
bool DocumentProperty::builtInIsSet() const
{
    return m_BuiltInIsSet;
}

void DocumentProperty::unsetBuiltIn()
{
    m_BuiltInIsSet = false;
}

utility::string_t DocumentProperty::getName() const
{
    return m_Name;
}


void DocumentProperty::setName(utility::string_t value)
{
    m_Name = value;
    m_NameIsSet = true;
}
bool DocumentProperty::nameIsSet() const
{
    return m_NameIsSet;
}

void DocumentProperty::unsetName()
{
    m_NameIsSet = false;
}

utility::string_t DocumentProperty::getValue() const
{
    return m_Value;
}


void DocumentProperty::setValue(utility::string_t value)
{
    m_Value = value;
    m_ValueIsSet = true;
}
bool DocumentProperty::valueIsSet() const
{
    return m_ValueIsSet;
}

void DocumentProperty::unsetValue()
{
    m_ValueIsSet = false;
}

}
}
}
}
}

