/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Link.cpp">
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


#include "Link.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

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
        val[utility::conversions::to_string_t("Href")] = ModelBase::toJson(m_Href);
    }
    if(m_RelIsSet)
    {
        val[utility::conversions::to_string_t("Rel")] = ModelBase::toJson(m_Rel);
    }
    if(m_TypeIsSet)
    {
        val[utility::conversions::to_string_t("Type")] = ModelBase::toJson(m_Type);
    }
    if(m_TitleIsSet)
    {
        val[utility::conversions::to_string_t("Title")] = ModelBase::toJson(m_Title);
    }

    return val;
}

void Link::fromJson(web::json::value& val)
{
    if(val.has_field(utility::conversions::to_string_t("Href")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Href")];
        if(!fieldValue.is_null())
        {
            setHref(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("Rel")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Rel")];
        if(!fieldValue.is_null())
        {
            setRel(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("Type")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Type")];
        if(!fieldValue.is_null())
        {
            setType(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("Title")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Title")];
        if(!fieldValue.is_null())
        {
            setTitle(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void Link::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_HrefIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Href"), m_Href));
        
    }
    if(m_RelIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Rel"), m_Rel));
        
    }
    if(m_TypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Type"), m_Type));
        
    }
    if(m_TitleIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Title"), m_Title));
        
    }
}

void Link::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("Href")))
    {
        setHref(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Href"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Rel")))
    {
        setRel(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Rel"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Type")))
    {
        setType(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Type"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Title")))
    {
        setTitle(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Title"))));
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

