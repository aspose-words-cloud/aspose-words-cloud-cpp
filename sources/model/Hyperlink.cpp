/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Hyperlink.cpp">
*   Copyright (c) 2020 Aspose.Words for Cloud
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

#include "Hyperlink.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

Hyperlink::Hyperlink()
{
    m_DisplayText = utility::conversions::to_string_t("");
    m_DisplayTextIsSet = false;
    m_Value = utility::conversions::to_string_t("");
    m_ValueIsSet = false;

}

Hyperlink::~Hyperlink()
{
}

void Hyperlink::validate()
{
    // TODO: implement validation
}

web::json::value Hyperlink::toJson() const
{
    web::json::value val = this->LinkElement::toJson();
    if(m_DisplayTextIsSet)
    {
        val[_XPLATSTR("DisplayText")] = ModelBase::toJson(m_DisplayText);
    }
    if(m_ValueIsSet)
    {
        val[_XPLATSTR("Value")] = ModelBase::toJson(m_Value);
    }

    return val;
}

void Hyperlink::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    if(val.has_field(_XPLATSTR("DisplayText")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DisplayText")];
        if(!fieldValue.is_null())
        {
           setDisplayText(ModelBase::stringFromJson(fieldValue));
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

void Hyperlink::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    LinkElement::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_DisplayTextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("DisplayText"), m_DisplayText));
    }


    if(m_ValueIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Value"), m_Value));
    }

}

void Hyperlink::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

utility::string_t Hyperlink::getDisplayText() const
{
    return m_DisplayText;
}


void Hyperlink::setDisplayText(utility::string_t value)
{
    m_DisplayText = value;
    m_DisplayTextIsSet = true;
}

bool Hyperlink::displayTextIsSet() const
{
    return m_DisplayTextIsSet;
}

void Hyperlink::unsetDisplayText()
{
    m_DisplayTextIsSet = false;
}

utility::string_t Hyperlink::getValue() const
{
    return m_Value;
}


void Hyperlink::setValue(utility::string_t value)
{
    m_Value = value;
    m_ValueIsSet = true;
}

bool Hyperlink::valueIsSet() const
{
    return m_ValueIsSet;
}

void Hyperlink::unsetValue()
{
    m_ValueIsSet = false;
}

}
}
}
}
}
