/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Bookmark.cpp">
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


#include "Bookmark.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

Bookmark::Bookmark()
{
    m_Name = utility::conversions::to_string_t("");
    m_NameIsSet = false;
    m_Text = utility::conversions::to_string_t("");
    m_TextIsSet = false;
}

Bookmark::~Bookmark()
{
}

void Bookmark::validate()
{
    // TODO: implement validation
}

web::json::value Bookmark::toJson() const
{
    web::json::value val = this->LinkElement::toJson();

    if(m_NameIsSet)
    {
        val[_XPLATSTR("name")] = ModelBase::toJson(m_Name);
    }
    if(m_TextIsSet)
    {
        val[_XPLATSTR("text")] = ModelBase::toJson(m_Text);
    }

    return val;
}

void Bookmark::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    if(val.has_field(_XPLATSTR("name")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("name")];
        if(!fieldValue.is_null())
        {
            setName(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("text")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("text")];
        if(!fieldValue.is_null())
        {
            setText(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void Bookmark::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_LinkIsSet)
    {
        if (m_Link.get())
        {
            m_Link->toMultipart(multipart, _XPLATSTR("link."));
        }
        
    }
    if(m_NameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("name"), m_Name));
        
    }
    if(m_TextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("text"), m_Text));
        
    }
}

void Bookmark::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(_XPLATSTR("name")))
    {
        setName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("name"))));
    }
    if(multipart->hasContent(_XPLATSTR("text")))
    {
        setText(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("text"))));
    }
}

utility::string_t Bookmark::getName() const
{
    return m_Name;
}


void Bookmark::setName(utility::string_t value)
{
    m_Name = value;
    m_NameIsSet = true;
}
bool Bookmark::nameIsSet() const
{
    return m_NameIsSet;
}

void Bookmark::unsetName()
{
    m_NameIsSet = false;
}

utility::string_t Bookmark::getText() const
{
    return m_Text;
}


void Bookmark::setText(utility::string_t value)
{
    m_Text = value;
    m_TextIsSet = true;
}
bool Bookmark::textIsSet() const
{
    return m_TextIsSet;
}

void Bookmark::unsetText()
{
    m_TextIsSet = false;
}

}
}
}
}
}

