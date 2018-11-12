/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="HeaderFooterLink.cpp">
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


#include "HeaderFooterLink.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

HeaderFooterLink::HeaderFooterLink()
{
    m_Type = utility::conversions::to_string_t("");
    m_TypeIsSet = false;
}

HeaderFooterLink::~HeaderFooterLink()
{
}

void HeaderFooterLink::validate()
{
    // TODO: implement validation
}

web::json::value HeaderFooterLink::toJson() const
{
    web::json::value val = this->LinkElement::toJson();

    if(m_TypeIsSet)
    {
        val[utility::conversions::to_string_t("Type")] = ModelBase::toJson(m_Type);
    }

    return val;
}

void HeaderFooterLink::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    if(val.has_field(utility::conversions::to_string_t("Type")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Type")];
        if(!fieldValue.is_null())
        {
            setType(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void HeaderFooterLink::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_LinkIsSet)
    {
        if (m_Link.get())
        {
            m_Link->toMultipart(multipart, utility::conversions::to_string_t("link."));
        }
        
    }
    if(m_TypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Type"), m_Type));
        
    }
}

void HeaderFooterLink::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("link")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("link")))
        {
            std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("link."));
            setLink( newItem );
        }
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Type")))
    {
        setType(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Type"))));
    }
}

utility::string_t HeaderFooterLink::getType() const
{
    return m_Type;
}


void HeaderFooterLink::setType(utility::string_t value)
{
    m_Type = value;
    m_TypeIsSet = true;
}
bool HeaderFooterLink::typeIsSet() const
{
    return m_TypeIsSet;
}

void HeaderFooterLink::unsetType()
{
    m_TypeIsSet = false;
}

}
}
}
}

