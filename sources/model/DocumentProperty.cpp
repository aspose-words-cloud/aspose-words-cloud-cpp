/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DocumentProperty.cpp">
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


#include "DocumentProperty.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

DocumentProperty::DocumentProperty()
{
    m_BuiltIn = false;
    m_BuiltInIsSet = false;
    m_Name = _XPLATSTR("");
    m_NameIsSet = false;
    m_Value = _XPLATSTR("");
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
        val[_XPLATSTR("BuiltIn")] = ModelBase::toJson(m_BuiltIn);
    }
    if(m_NameIsSet)
    {
        val[_XPLATSTR("Name")] = ModelBase::toJson(m_Name);
    }
    if(m_ValueIsSet)
    {
        val[_XPLATSTR("Value")] = ModelBase::toJson(m_Value);
    }

    return val;
}

void DocumentProperty::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    if(val.has_field(_XPLATSTR("BuiltIn")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("BuiltIn")];
        if(!fieldValue.is_null())
        {
            setBuiltIn(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Name")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Name")];
        if(!fieldValue.is_null())
        {
            setName(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Value")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Value")];
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
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("BuiltIn"), m_BuiltIn));
    }
    if(m_NameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Name"), m_Name));
        
    }
    if(m_ValueIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Value"), m_Value));
        
    }
}

void DocumentProperty::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(multipart->hasContent(_XPLATSTR("link")))
    {
        if(multipart->hasContent(_XPLATSTR("link")))
        {
            std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
            newItem->fromMultiPart(multipart, _XPLATSTR("link."));
            setLink( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("BuiltIn")))
    {
        setBuiltIn(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("BuiltIn"))));
    }
    if(multipart->hasContent(_XPLATSTR("Name")))
    {
        setName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Name"))));
    }
    if(multipart->hasContent(_XPLATSTR("Value")))
    {
        setValue(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Value"))));
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

