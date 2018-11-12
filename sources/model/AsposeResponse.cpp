/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="AsposeResponse.cpp">
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


#include "AsposeResponse.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

AsposeResponse::AsposeResponse()
{
    m_Code = 0;
    m_Status = utility::conversions::to_string_t("");
    m_StatusIsSet = false;
}

AsposeResponse::~AsposeResponse()
{
}

void AsposeResponse::validate()
{
    // TODO: implement validation
}

web::json::value AsposeResponse::toJson() const
{
    web::json::value val = web::json::value::object();

    val[utility::conversions::to_string_t("Code")] = ModelBase::toJson(m_Code);
    if(m_StatusIsSet)
    {
        val[utility::conversions::to_string_t("Status")] = ModelBase::toJson(m_Status);
    }

    return val;
}

void AsposeResponse::fromJson(web::json::value& val)
{
    setCode(ModelBase::int32_tFromJson(val[utility::conversions::to_string_t("Code")]));
    if(val.has_field(utility::conversions::to_string_t("Status")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Status")];
        if(!fieldValue.is_null())
        {
            setStatus(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void AsposeResponse::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
}

void AsposeResponse::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
}

int32_t AsposeResponse::getCode() const
{
    return m_Code;
}


void AsposeResponse::setCode(int32_t value)
{
    m_Code = value;
    
}
utility::string_t AsposeResponse::getStatus() const
{
    return m_Status;
}


void AsposeResponse::setStatus(utility::string_t value)
{
    m_Status = value;
    m_StatusIsSet = true;
}
bool AsposeResponse::statusIsSet() const
{
    return m_StatusIsSet;
}

void AsposeResponse::unsetStatus()
{
    m_StatusIsSet = false;
}

}
}
}
}

