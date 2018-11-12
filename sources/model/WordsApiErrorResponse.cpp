/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="WordsApiErrorResponse.cpp">
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


#include "WordsApiErrorResponse.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

WordsApiErrorResponse::WordsApiErrorResponse()
{
    m_Message = utility::conversions::to_string_t("");
    m_MessageIsSet = false;
}

WordsApiErrorResponse::~WordsApiErrorResponse()
{
}

void WordsApiErrorResponse::validate()
{
    // TODO: implement validation
}

web::json::value WordsApiErrorResponse::toJson() const
{
    web::json::value val = this->AsposeResponse::toJson();

    if(m_MessageIsSet)
    {
        val[utility::conversions::to_string_t("Message")] = ModelBase::toJson(m_Message);
    }

    return val;
}

void WordsApiErrorResponse::fromJson(web::json::value& val)
{
    this->AsposeResponse::fromJson(val);

    if(val.has_field(utility::conversions::to_string_t("Message")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Message")];
        if(!fieldValue.is_null())
        {
            setMessage(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void WordsApiErrorResponse::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_MessageIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Message"), m_Message));
        
    }
}

void WordsApiErrorResponse::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t("Message")))
    {
        setMessage(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Message"))));
    }
}

utility::string_t WordsApiErrorResponse::getMessage() const
{
    return m_Message;
}


void WordsApiErrorResponse::setMessage(utility::string_t value)
{
    m_Message = value;
    m_MessageIsSet = true;
}
bool WordsApiErrorResponse::messageIsSet() const
{
    return m_MessageIsSet;
}

void WordsApiErrorResponse::unsetMessage()
{
    m_MessageIsSet = false;
}

}
}
}
}

