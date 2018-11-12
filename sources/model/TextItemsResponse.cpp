/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TextItemsResponse.cpp">
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


#include "TextItemsResponse.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

TextItemsResponse::TextItemsResponse()
{
    m_TextItemsIsSet = false;
}

TextItemsResponse::~TextItemsResponse()
{
}

void TextItemsResponse::validate()
{
    // TODO: implement validation
}

web::json::value TextItemsResponse::toJson() const
{
    web::json::value val = this->AsposeResponse::toJson();

    if(m_TextItemsIsSet)
    {
        val[utility::conversions::to_string_t("TextItems")] = ModelBase::toJson(m_TextItems);
    }

    return val;
}

void TextItemsResponse::fromJson(web::json::value& val)
{
    this->AsposeResponse::fromJson(val);

    if(val.has_field(utility::conversions::to_string_t("TextItems")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("TextItems")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<TextItems> newItem(new TextItems());
            newItem->fromJson(fieldValue);
            setTextItems( newItem );
        }
    }
}

void TextItemsResponse::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_TextItemsIsSet)
    {
        if (m_TextItems.get())
        {
            m_TextItems->toMultipart(multipart, utility::conversions::to_string_t("TextItems."));
        }
        
    }
}

void TextItemsResponse::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t("TextItems")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("TextItems")))
        {
            std::shared_ptr<TextItems> newItem(new TextItems());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("TextItems."));
            setTextItems( newItem );
        }
    }
}

std::shared_ptr<TextItems> TextItemsResponse::getTextItems() const
{
    return m_TextItems;
}


void TextItemsResponse::setTextItems(std::shared_ptr<TextItems> value)
{
    m_TextItems = value;
    m_TextItemsIsSet = true;
}
bool TextItemsResponse::textItemsIsSet() const
{
    return m_TextItemsIsSet;
}

void TextItemsResponse::unsetTextItems()
{
    m_TextItemsIsSet = false;
}

}
}
}
}

