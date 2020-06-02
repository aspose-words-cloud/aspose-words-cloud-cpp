/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="RevisionsModificationResponse.cpp">
*   Copyright (c) 2020 Aspose.Words for Cloud
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

#include "RevisionsModificationResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

RevisionsModificationResponse::RevisionsModificationResponse()
{
    m_ResultIsSet = false;

}

RevisionsModificationResponse::~RevisionsModificationResponse()
{
}

void RevisionsModificationResponse::validate()
{
    // TODO: implement validation
}

web::json::value RevisionsModificationResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();
    if(m_ResultIsSet)
    {
        val[_XPLATSTR("Result")] = ModelBase::toJson(m_Result);
    }

    return val;
}

void RevisionsModificationResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("Result")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Result")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<ModificationOperationResult> newItem(new ModificationOperationResult());
            newItem->fromJson(fieldValue);
        }
    }

}

void RevisionsModificationResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    WordsResponse::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_ResultIsSet)
    {
        if (m_Result.get())
        {
            m_Result->toMultipart(multipart, _XPLATSTR("Result."));
        }
    }

}

void RevisionsModificationResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

std::shared_ptr<ModificationOperationResult> RevisionsModificationResponse::getResult() const
{
    return m_Result;
}


void RevisionsModificationResponse::setResult(std::shared_ptr<ModificationOperationResult> value)
{
    m_Result = value;
    m_ResultIsSet = true;
}

bool RevisionsModificationResponse::resultIsSet() const
{
    return m_ResultIsSet;
}

void RevisionsModificationResponse::unsetResult()
{
    m_ResultIsSet = false;
}

}
}
}
}
}
