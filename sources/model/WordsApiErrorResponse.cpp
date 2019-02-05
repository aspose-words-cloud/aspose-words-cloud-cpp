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
    m_Message = _XPLATSTR("");
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
        val[_XPLATSTR("Message")] = ModelBase::toJson(m_Message);
    }

    return val;
}

void WordsApiErrorResponse::fromJson(web::json::value& val)
{
    this->AsposeResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("Message")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Message")];
        if(!fieldValue.is_null())
        {
            setMessage(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void WordsApiErrorResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Code"), m_Code));
    if(m_StatusIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Status"), m_Status));
        
    }
    if(m_MessageIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Message"), m_Message));
        
    }
}

void WordsApiErrorResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    setCode(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("Code"))));
    if(multipart->hasContent(_XPLATSTR("Status")))
    {
        setStatus(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Status"))));
    }
    if(multipart->hasContent(_XPLATSTR("Message")))
    {
        setMessage(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Message"))));
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

