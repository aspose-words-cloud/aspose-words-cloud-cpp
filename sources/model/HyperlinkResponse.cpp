/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="HyperlinkResponse.cpp">
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


#include "HyperlinkResponse.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

HyperlinkResponse::HyperlinkResponse()
{
    m_HyperlinkIsSet = false;
}

HyperlinkResponse::~HyperlinkResponse()
{
}

void HyperlinkResponse::validate()
{
    // TODO: implement validation
}

web::json::value HyperlinkResponse::toJson() const
{
    web::json::value val = this->AsposeResponse::toJson();

    if(m_HyperlinkIsSet)
    {
        val[utility::conversions::to_string_t("Hyperlink")] = ModelBase::toJson(m_Hyperlink);
    }

    return val;
}

void HyperlinkResponse::fromJson(web::json::value& val)
{
    this->AsposeResponse::fromJson(val);

    if(val.has_field(utility::conversions::to_string_t("Hyperlink")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Hyperlink")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Hyperlink> newItem(new Hyperlink());
            newItem->fromJson(fieldValue);
            setHyperlink( newItem );
        }
    }
}

void HyperlinkResponse::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Code"), m_Code));
    if(m_StatusIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Status"), m_Status));
        
    }
    if(m_HyperlinkIsSet)
    {
        if (m_Hyperlink.get())
        {
            m_Hyperlink->toMultipart(multipart, utility::conversions::to_string_t("Hyperlink."));
        }
        
    }
}

void HyperlinkResponse::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    setCode(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Code"))));
    if(multipart->hasContent(utility::conversions::to_string_t("Status")))
    {
        setStatus(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Status"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Hyperlink")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("Hyperlink")))
        {
            std::shared_ptr<Hyperlink> newItem(new Hyperlink());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("Hyperlink."));
            setHyperlink( newItem );
        }
    }
}

std::shared_ptr<Hyperlink> HyperlinkResponse::getHyperlink() const
{
    return m_Hyperlink;
}


void HyperlinkResponse::setHyperlink(std::shared_ptr<Hyperlink> value)
{
    m_Hyperlink = value;
    m_HyperlinkIsSet = true;
}
bool HyperlinkResponse::hyperlinkIsSet() const
{
    return m_HyperlinkIsSet;
}

void HyperlinkResponse::unsetHyperlink()
{
    m_HyperlinkIsSet = false;
}

}
}
}
}

