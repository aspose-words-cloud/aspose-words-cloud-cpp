/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Field.cpp">
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


#include "Field.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

Field::Field()
{
    m_LocaleId = utility::conversions::to_string_t("");
    m_LocaleIdIsSet = false;
    m_Result = utility::conversions::to_string_t("");
    m_ResultIsSet = false;
}

Field::~Field()
{
}

void Field::validate()
{
    // TODO: implement validation
}

web::json::value Field::toJson() const
{
    web::json::value val = this->FieldLink::toJson();

    if(m_LocaleIdIsSet)
    {
        val[utility::conversions::to_string_t("LocaleId")] = ModelBase::toJson(m_LocaleId);
    }
    if(m_ResultIsSet)
    {
        val[utility::conversions::to_string_t("Result")] = ModelBase::toJson(m_Result);
    }

    return val;
}

void Field::fromJson(web::json::value& val)
{
    this->FieldLink::fromJson(val);

    if(val.has_field(utility::conversions::to_string_t("LocaleId")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("LocaleId")];
        if(!fieldValue.is_null())
        {
            setLocaleId(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("Result")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Result")];
        if(!fieldValue.is_null())
        {
            setResult(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void Field::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_LocaleIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("LocaleId"), m_LocaleId));
        
    }
    if(m_ResultIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Result"), m_Result));
        
    }
}

void Field::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t("LocaleId")))
    {
        setLocaleId(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("LocaleId"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Result")))
    {
        setResult(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Result"))));
    }
}

utility::string_t Field::getLocaleId() const
{
    return m_LocaleId;
}


void Field::setLocaleId(utility::string_t value)
{
    m_LocaleId = value;
    m_LocaleIdIsSet = true;
}
bool Field::localeIdIsSet() const
{
    return m_LocaleIdIsSet;
}

void Field::unsetLocaleId()
{
    m_LocaleIdIsSet = false;
}

utility::string_t Field::getResult() const
{
    return m_Result;
}


void Field::setResult(utility::string_t value)
{
    m_Result = value;
    m_ResultIsSet = true;
}
bool Field::resultIsSet() const
{
    return m_ResultIsSet;
}

void Field::unsetResult()
{
    m_ResultIsSet = false;
}

}
}
}
}

