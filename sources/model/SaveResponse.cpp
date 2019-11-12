/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SaveResponse.cpp">
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


#include "SaveResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

SaveResponse::SaveResponse()
{
    m_SaveResultIsSet = false;
}

SaveResponse::~SaveResponse()
{
}

void SaveResponse::validate()
{
    // TODO: implement validation
}

web::json::value SaveResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();

    if(m_SaveResultIsSet)
    {
        val[_XPLATSTR("SaveResult")] = ModelBase::toJson(m_SaveResult);
    }

    return val;
}

void SaveResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("SaveResult")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SaveResult")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<SaveResult> newItem(new SaveResult());
            newItem->fromJson(fieldValue);
            setSaveResult( newItem );
        }
    }
}

void SaveResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_RequestIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RequestId"), m_RequestId));
        
    }
    if(m_SaveResultIsSet)
    {
        if (m_SaveResult.get())
        {
            m_SaveResult->toMultipart(multipart, _XPLATSTR("SaveResult."));
        }
        
    }
}

void SaveResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("RequestId")))
    {
        setRequestId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("RequestId"))));
    }
    if(multipart->hasContent(_XPLATSTR("SaveResult")))
    {
        if(multipart->hasContent(_XPLATSTR("SaveResult")))
        {
            std::shared_ptr<SaveResult> newItem(new SaveResult());
            newItem->fromMultiPart(multipart, _XPLATSTR("SaveResult."));
            setSaveResult( newItem );
        }
    }
}

std::shared_ptr<SaveResult> SaveResponse::getSaveResult() const
{
    return m_SaveResult;
}


void SaveResponse::setSaveResult(std::shared_ptr<SaveResult> value)
{
    m_SaveResult = value;
    m_SaveResultIsSet = true;
}
bool SaveResponse::saveResultIsSet() const
{
    return m_SaveResultIsSet;
}

void SaveResponse::unsetSaveResult()
{
    m_SaveResultIsSet = false;
}

}
}
}
}
}

