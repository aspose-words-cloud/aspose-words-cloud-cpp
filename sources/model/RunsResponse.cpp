/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="RunsResponse.cpp">
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


#include "RunsResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

RunsResponse::RunsResponse()
{
    m_RunsIsSet = false;
}

RunsResponse::~RunsResponse()
{
}

void RunsResponse::validate()
{
    // TODO: implement validation
}

web::json::value RunsResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();

    if(m_RunsIsSet)
    {
        val[_XPLATSTR("runs")] = ModelBase::toJson(m_Runs);
    }

    return val;
}

void RunsResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("runs")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("runs")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Runs> newItem(new Runs());
            newItem->fromJson(fieldValue);
            setRuns( newItem );
        }
    }
}

void RunsResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_RequestIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("requestId"), m_RequestId));
        
    }
    if(m_RunsIsSet)
    {
        if (m_Runs.get())
        {
            m_Runs->toMultipart(multipart, _XPLATSTR("runs."));
        }
        
    }
}

void RunsResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("requestId")))
    {
        setRequestId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("requestId"))));
    }
    if(multipart->hasContent(_XPLATSTR("runs")))
    {
        if(multipart->hasContent(_XPLATSTR("runs")))
        {
            std::shared_ptr<Runs> newItem(new Runs());
            newItem->fromMultiPart(multipart, _XPLATSTR("runs."));
            setRuns( newItem );
        }
    }
}

std::shared_ptr<Runs> RunsResponse::getRuns() const
{
    return m_Runs;
}


void RunsResponse::setRuns(std::shared_ptr<Runs> value)
{
    m_Runs = value;
    m_RunsIsSet = true;
}
bool RunsResponse::runsIsSet() const
{
    return m_RunsIsSet;
}

void RunsResponse::unsetRuns()
{
    m_RunsIsSet = false;
}

}
}
}
}
}

