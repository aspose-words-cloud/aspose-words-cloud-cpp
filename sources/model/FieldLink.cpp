/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FieldLink.cpp">
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


#include "FieldLink.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

FieldLink::FieldLink()
{
    m_FieldCode = utility::conversions::to_string_t("");
    m_FieldCodeIsSet = false;
}

FieldLink::~FieldLink()
{
}

void FieldLink::validate()
{
    // TODO: implement validation
}

web::json::value FieldLink::toJson() const
{
    web::json::value val = this->NodeLink::toJson();

    if(m_FieldCodeIsSet)
    {
        val[utility::conversions::to_string_t("FieldCode")] = ModelBase::toJson(m_FieldCode);
    }

    return val;
}

void FieldLink::fromJson(web::json::value& val)
{
    this->NodeLink::fromJson(val);

    if(val.has_field(utility::conversions::to_string_t("FieldCode")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("FieldCode")];
        if(!fieldValue.is_null())
        {
            setFieldCode(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void FieldLink::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_NodeIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("NodeId"), m_NodeId));
        
    }
    if(m_FieldCodeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("FieldCode"), m_FieldCode));
        
    }
}

void FieldLink::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t("NodeId")))
    {
        setNodeId(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("NodeId"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("FieldCode")))
    {
        setFieldCode(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("FieldCode"))));
    }
}

utility::string_t FieldLink::getFieldCode() const
{
    return m_FieldCode;
}


void FieldLink::setFieldCode(utility::string_t value)
{
    m_FieldCode = value;
    m_FieldCodeIsSet = true;
}
bool FieldLink::fieldCodeIsSet() const
{
    return m_FieldCodeIsSet;
}

void FieldLink::unsetFieldCode()
{
    m_FieldCodeIsSet = false;
}

}
}
}
}

