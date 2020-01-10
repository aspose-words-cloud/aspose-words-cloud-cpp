/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="RunResponse.cpp">
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


#include "RunResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

RunResponse::RunResponse()
{
    m_RunIsSet = false;
}

RunResponse::~RunResponse()
{
}

void RunResponse::validate()
{
    // TODO: implement validation
}

web::json::value RunResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();

    if(m_RunIsSet)
    {
        val[_XPLATSTR("run")] = ModelBase::toJson(m_Run);
    }

    return val;
}

void RunResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("run")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("run")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Run> newItem(new Run());
            newItem->fromJson(fieldValue);
            setRun( newItem );
        }
    }
}

void RunResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_RequestIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("requestId"), m_RequestId));
        
    }
    if(m_RunIsSet)
    {
        if (m_Run.get())
        {
            m_Run->toMultipart(multipart, _XPLATSTR("run."));
        }
        
    }
}

void RunResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("requestId")))
    {
        setRequestId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("requestId"))));
    }
    if(multipart->hasContent(_XPLATSTR("run")))
    {
        if(multipart->hasContent(_XPLATSTR("run")))
        {
            std::shared_ptr<Run> newItem(new Run());
            newItem->fromMultiPart(multipart, _XPLATSTR("run."));
            setRun( newItem );
        }
    }
}

std::shared_ptr<Run> RunResponse::getRun() const
{
    return m_Run;
}


void RunResponse::setRun(std::shared_ptr<Run> value)
{
    m_Run = value;
    m_RunIsSet = true;
}
bool RunResponse::runIsSet() const
{
    return m_RunIsSet;
}

void RunResponse::unsetRun()
{
    m_RunIsSet = false;
}

}
}
}
}
}

