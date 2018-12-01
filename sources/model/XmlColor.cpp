/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="XmlColor.cpp">
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


#include "XmlColor.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

XmlColor::XmlColor()
{
    m_Web = utility::conversions::to_string_t("");
    m_WebIsSet = false;
    m_Alpha = 0;
}

XmlColor::~XmlColor()
{
}

void XmlColor::validate()
{
    // TODO: implement validation
}

web::json::value XmlColor::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_WebIsSet)
    {
        val[utility::conversions::to_string_t("Web")] = ModelBase::toJson(m_Web);
    }
    val[utility::conversions::to_string_t("Alpha")] = ModelBase::toJson(m_Alpha);

    return val;
}

void XmlColor::fromJson(web::json::value& val)
{
    if(val.has_field(utility::conversions::to_string_t("Web")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Web")];
        if(!fieldValue.is_null())
        {
            setWeb(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("Alpha")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Alpha")];
        if(!fieldValue.is_null())
        {
            setAlpha(ModelBase::int32_tFromJson(fieldValue));
        }
    }
}

void XmlColor::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_WebIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Web"), m_Web));
        
    }
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Alpha"), m_Alpha));
}

void XmlColor::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("Web")))
    {
        setWeb(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Web"))));
    }
    setAlpha(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Alpha"))));
}

utility::string_t XmlColor::getWeb() const
{
    return m_Web;
}


void XmlColor::setWeb(utility::string_t value)
{
    m_Web = value;
    m_WebIsSet = true;
}
bool XmlColor::webIsSet() const
{
    return m_WebIsSet;
}

void XmlColor::unsetWeb()
{
    m_WebIsSet = false;
}

int32_t XmlColor::getAlpha() const
{
    return m_Alpha;
}


void XmlColor::setAlpha(int32_t value)
{
    m_Alpha = value;
    
}
}
}
}
}

