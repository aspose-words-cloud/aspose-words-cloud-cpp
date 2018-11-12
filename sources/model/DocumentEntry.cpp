/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DocumentEntry.cpp">
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


#include "DocumentEntry.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

DocumentEntry::DocumentEntry()
{
    m_Href = utility::conversions::to_string_t("");
    m_HrefIsSet = false;
    m_ImportFormatMode = utility::conversions::to_string_t("");
    m_ImportFormatModeIsSet = false;
}

DocumentEntry::~DocumentEntry()
{
}

void DocumentEntry::validate()
{
    // TODO: implement validation
}

web::json::value DocumentEntry::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_HrefIsSet)
    {
        val[utility::conversions::to_string_t("Href")] = ModelBase::toJson(m_Href);
    }
    if(m_ImportFormatModeIsSet)
    {
        val[utility::conversions::to_string_t("ImportFormatMode")] = ModelBase::toJson(m_ImportFormatMode);
    }

    return val;
}

void DocumentEntry::fromJson(web::json::value& val)
{
    if(val.has_field(utility::conversions::to_string_t("Href")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Href")];
        if(!fieldValue.is_null())
        {
            setHref(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("ImportFormatMode")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("ImportFormatMode")];
        if(!fieldValue.is_null())
        {
            setImportFormatMode(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void DocumentEntry::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_ImportFormatModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("ImportFormatMode"), m_ImportFormatMode));
        
    }
}

void DocumentEntry::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t("ImportFormatMode")))
    {
        setImportFormatMode(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("ImportFormatMode"))));
    }
}

utility::string_t DocumentEntry::getHref() const
{
    return m_Href;
}


void DocumentEntry::setHref(utility::string_t value)
{
    m_Href = value;
    m_HrefIsSet = true;
}
bool DocumentEntry::hrefIsSet() const
{
    return m_HrefIsSet;
}

void DocumentEntry::unsetHref()
{
    m_HrefIsSet = false;
}

utility::string_t DocumentEntry::getImportFormatMode() const
{
    return m_ImportFormatMode;
}


void DocumentEntry::setImportFormatMode(utility::string_t value)
{
    m_ImportFormatMode = value;
    m_ImportFormatModeIsSet = true;
}
bool DocumentEntry::importFormatModeIsSet() const
{
    return m_ImportFormatModeIsSet;
}

void DocumentEntry::unsetImportFormatMode()
{
    m_ImportFormatModeIsSet = false;
}

}
}
}
}

