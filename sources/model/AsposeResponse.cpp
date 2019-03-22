/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="AsposeResponse.cpp">
*   Copyright (c) 2019 Aspose.Words for Cloud
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

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

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

    val[_XPLATSTR("Code")] = ModelBase::toJson(m_Code);
    if(m_StatusIsSet)
    {
        val[_XPLATSTR("Status")] = ModelBase::toJson(m_Status);
    }

    return val;
}

void AsposeResponse::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("Code")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Code")];
        if(!fieldValue.is_null())
        {
            setCode(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Status")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Status")];
        if(!fieldValue.is_null())
        {
            setStatus(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void AsposeResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Code"), m_Code));
    if(m_StatusIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Status"), m_Status));
        
    }
}

void AsposeResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    setCode(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("Code"))));
    if(multipart->hasContent(_XPLATSTR("Status")))
    {
        setStatus(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Status"))));
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
}

