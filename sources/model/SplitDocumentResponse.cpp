/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SplitDocumentResponse.cpp">
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

#include "SplitDocumentResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

SplitDocumentResponse::SplitDocumentResponse()
{
    m_SplitResultIsSet = false;

}

SplitDocumentResponse::~SplitDocumentResponse()
{
}

void SplitDocumentResponse::validate()
{
    // TODO: implement validation
}

web::json::value SplitDocumentResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();
    if(m_SplitResultIsSet)
    {
        val[_XPLATSTR("SplitResult")] = ModelBase::toJson(m_SplitResult);
    }

    return val;
}

void SplitDocumentResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("SplitResult")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SplitResult")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<SplitDocumentResult> newItem(new SplitDocumentResult());
            newItem->fromJson(fieldValue);
            setSplitResult( newItem );
        }
    }

}

void SplitDocumentResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    WordsResponse::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_SplitResultIsSet)
    {
        if (m_SplitResult.get())
        {
            m_SplitResult->toMultipart(multipart, _XPLATSTR("SplitResult."));
        }
    }

}

void SplitDocumentResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

std::shared_ptr<SplitDocumentResult> SplitDocumentResponse::getSplitResult() const
{
    return m_SplitResult;
}


void SplitDocumentResponse::setSplitResult(std::shared_ptr<SplitDocumentResult> value)
{
    m_SplitResult = value;
    m_SplitResultIsSet = true;
}

bool SplitDocumentResponse::splitResultIsSet() const
{
    return m_SplitResultIsSet;
}

void SplitDocumentResponse::unsetSplitResult()
{
    m_SplitResultIsSet = false;
}

}
}
}
}
}
