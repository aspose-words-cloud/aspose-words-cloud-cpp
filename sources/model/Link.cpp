/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Link.cpp">
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


#include "Link.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

Link::Link()
{
    m_Href = utility::conversions::to_string_t("");
    m_HrefIsSet = false;
    m_Rel = utility::conversions::to_string_t("");
    m_RelIsSet = false;
    m_Type = utility::conversions::to_string_t("");
    m_TypeIsSet = false;
    m_Title = utility::conversions::to_string_t("");
    m_TitleIsSet = false;
}

Link::~Link()
{
}

void Link::validate()
{
    // TODO: implement validation
}

web::json::value Link::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_HrefIsSet)
    {
        val[_XPLATSTR("href")] = ModelBase::toJson(m_Href);
    }
    if(m_RelIsSet)
    {
        val[_XPLATSTR("rel")] = ModelBase::toJson(m_Rel);
    }
    if(m_TypeIsSet)
    {
        val[_XPLATSTR("type")] = ModelBase::toJson(m_Type);
    }
    if(m_TitleIsSet)
    {
        val[_XPLATSTR("title")] = ModelBase::toJson(m_Title);
    }

    return val;
}

void Link::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("href")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("href")];
        if(!fieldValue.is_null())
        {
            setHref(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("rel")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("rel")];
        if(!fieldValue.is_null())
        {
            setRel(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("type")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("type")];
        if(!fieldValue.is_null())
        {
            setType(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("title")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("title")];
        if(!fieldValue.is_null())
        {
            setTitle(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void Link::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_HrefIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("href"), m_Href));
        
    }
    if(m_RelIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("rel"), m_Rel));
        
    }
    if(m_TypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("type"), m_Type));
        
    }
    if(m_TitleIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("title"), m_Title));
        
    }
}

void Link::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("href")))
    {
        setHref(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("href"))));
    }
    if(multipart->hasContent(_XPLATSTR("rel")))
    {
        setRel(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("rel"))));
    }
    if(multipart->hasContent(_XPLATSTR("type")))
    {
        setType(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("type"))));
    }
    if(multipart->hasContent(_XPLATSTR("title")))
    {
        setTitle(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("title"))));
    }
}

utility::string_t Link::getHref() const
{
    return m_Href;
}


void Link::setHref(utility::string_t value)
{
    m_Href = value;
    m_HrefIsSet = true;
}
bool Link::hrefIsSet() const
{
    return m_HrefIsSet;
}

void Link::unsetHref()
{
    m_HrefIsSet = false;
}

utility::string_t Link::getRel() const
{
    return m_Rel;
}


void Link::setRel(utility::string_t value)
{
    m_Rel = value;
    m_RelIsSet = true;
}
bool Link::relIsSet() const
{
    return m_RelIsSet;
}

void Link::unsetRel()
{
    m_RelIsSet = false;
}

utility::string_t Link::getType() const
{
    return m_Type;
}


void Link::setType(utility::string_t value)
{
    m_Type = value;
    m_TypeIsSet = true;
}
bool Link::typeIsSet() const
{
    return m_TypeIsSet;
}

void Link::unsetType()
{
    m_TypeIsSet = false;
}

utility::string_t Link::getTitle() const
{
    return m_Title;
}


void Link::setTitle(utility::string_t value)
{
    m_Title = value;
    m_TitleIsSet = true;
}
bool Link::titleIsSet() const
{
    return m_TitleIsSet;
}

void Link::unsetTitle()
{
    m_TitleIsSet = false;
}

}
}
}
}
}

