/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ReplaceRange.cpp">
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


#include "ReplaceRange.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

ReplaceRange::ReplaceRange()
{
    m_Text = utility::conversions::to_string_t("");
    m_TextIsSet = false;
    m_TextType = utility::conversions::to_string_t("");
    m_TextTypeIsSet = false;
}

ReplaceRange::~ReplaceRange()
{
}

void ReplaceRange::validate()
{
    // TODO: implement validation
}

web::json::value ReplaceRange::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_TextIsSet)
    {
        val[_XPLATSTR("Text")] = ModelBase::toJson(m_Text);
    }
    if(m_TextTypeIsSet)
    {
        val[_XPLATSTR("TextType")] = ModelBase::toJson(m_TextType);
    }

    return val;
}

void ReplaceRange::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("Text")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Text")];
        if(!fieldValue.is_null())
        {
            setText(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("TextType")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("TextType")];
        if(!fieldValue.is_null())
        {
            setTextType(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void ReplaceRange::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_TextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Text"), m_Text));
        
    }
    if(m_TextTypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TextType"), m_TextType));
        
    }
}

void ReplaceRange::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("Text")))
    {
        setText(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Text"))));
    }
    if(multipart->hasContent(_XPLATSTR("TextType")))
    {
        setTextType(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("TextType"))));
    }
}

utility::string_t ReplaceRange::getText() const
{
    return m_Text;
}


void ReplaceRange::setText(utility::string_t value)
{
    m_Text = value;
    m_TextIsSet = true;
}
bool ReplaceRange::textIsSet() const
{
    return m_TextIsSet;
}

void ReplaceRange::unsetText()
{
    m_TextIsSet = false;
}

utility::string_t ReplaceRange::getTextType() const
{
    return m_TextType;
}


void ReplaceRange::setTextType(utility::string_t value)
{
    m_TextType = value;
    m_TextTypeIsSet = true;
}
bool ReplaceRange::textTypeIsSet() const
{
    return m_TextTypeIsSet;
}

void ReplaceRange::unsetTextType()
{
    m_TextTypeIsSet = false;
}

}
}
}
}
}

