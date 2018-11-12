/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FieldNamesResponse.cpp">
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


#include "FieldNamesResponse.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

FieldNamesResponse::FieldNamesResponse()
{
    m_FieldNamesIsSet = false;
}

FieldNamesResponse::~FieldNamesResponse()
{
}

void FieldNamesResponse::validate()
{
    // TODO: implement validation
}

web::json::value FieldNamesResponse::toJson() const
{
    web::json::value val = this->AsposeResponse::toJson();

    if(m_FieldNamesIsSet)
    {
        val[utility::conversions::to_string_t("FieldNames")] = ModelBase::toJson(m_FieldNames);
    }

    return val;
}

void FieldNamesResponse::fromJson(web::json::value& val)
{
    this->AsposeResponse::fromJson(val);

    if(val.has_field(utility::conversions::to_string_t("FieldNames")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("FieldNames")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<FieldNames> newItem(new FieldNames());
            newItem->fromJson(fieldValue);
            setFieldNames( newItem );
        }
    }
}

void FieldNamesResponse::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_FieldNamesIsSet)
    {
        if (m_FieldNames.get())
        {
            m_FieldNames->toMultipart(multipart, utility::conversions::to_string_t("FieldNames."));
        }
        
    }
}

void FieldNamesResponse::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t("FieldNames")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("FieldNames")))
        {
            std::shared_ptr<FieldNames> newItem(new FieldNames());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("FieldNames."));
            setFieldNames( newItem );
        }
    }
}

std::shared_ptr<FieldNames> FieldNamesResponse::getFieldNames() const
{
    return m_FieldNames;
}


void FieldNamesResponse::setFieldNames(std::shared_ptr<FieldNames> value)
{
    m_FieldNames = value;
    m_FieldNamesIsSet = true;
}
bool FieldNamesResponse::fieldNamesIsSet() const
{
    return m_FieldNamesIsSet;
}

void FieldNamesResponse::unsetFieldNames()
{
    m_FieldNamesIsSet = false;
}

}
}
}
}

