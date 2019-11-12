/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="WordsResponse.cpp">
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


#include "WordsResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

WordsResponse::WordsResponse()
{
    m_RequestId = utility::conversions::to_string_t("");
    m_RequestIdIsSet = false;
}

WordsResponse::~WordsResponse()
{
}

void WordsResponse::validate()
{
    // TODO: implement validation
}

web::json::value WordsResponse::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_RequestIdIsSet)
    {
        val[_XPLATSTR("RequestId")] = ModelBase::toJson(m_RequestId);
    }

    return val;
}

void WordsResponse::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("RequestId")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("RequestId")];
        if(!fieldValue.is_null())
        {
            setRequestId(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void WordsResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_RequestIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RequestId"), m_RequestId));
        
    }
}

void WordsResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("RequestId")))
    {
        setRequestId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("RequestId"))));
    }
}

utility::string_t WordsResponse::getRequestId() const
{
    return m_RequestId;
}


void WordsResponse::setRequestId(utility::string_t value)
{
    m_RequestId = value;
    m_RequestIdIsSet = true;
}
bool WordsResponse::requestIdIsSet() const
{
    return m_RequestIdIsSet;
}

void WordsResponse::unsetRequestId()
{
    m_RequestIdIsSet = false;
}

}
}
}
}
}

