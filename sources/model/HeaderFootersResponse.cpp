/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="HeaderFootersResponse.cpp">
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


#include "HeaderFootersResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

HeaderFootersResponse::HeaderFootersResponse()
{
    m_HeaderFootersIsSet = false;
}

HeaderFootersResponse::~HeaderFootersResponse()
{
}

void HeaderFootersResponse::validate()
{
    // TODO: implement validation
}

web::json::value HeaderFootersResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();

    if(m_HeaderFootersIsSet)
    {
        val[_XPLATSTR("headerFooters")] = ModelBase::toJson(m_HeaderFooters);
    }

    return val;
}

void HeaderFootersResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("headerFooters")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("headerFooters")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<HeaderFooterLinkCollection> newItem(new HeaderFooterLinkCollection());
            newItem->fromJson(fieldValue);
            setHeaderFooters( newItem );
        }
    }
}

void HeaderFootersResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_RequestIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("requestId"), m_RequestId));
        
    }
    if(m_HeaderFootersIsSet)
    {
        if (m_HeaderFooters.get())
        {
            m_HeaderFooters->toMultipart(multipart, _XPLATSTR("headerFooters."));
        }
        
    }
}

void HeaderFootersResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("requestId")))
    {
        setRequestId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("requestId"))));
    }
    if(multipart->hasContent(_XPLATSTR("headerFooters")))
    {
        if(multipart->hasContent(_XPLATSTR("headerFooters")))
        {
            std::shared_ptr<HeaderFooterLinkCollection> newItem(new HeaderFooterLinkCollection());
            newItem->fromMultiPart(multipart, _XPLATSTR("headerFooters."));
            setHeaderFooters( newItem );
        }
    }
}

std::shared_ptr<HeaderFooterLinkCollection> HeaderFootersResponse::getHeaderFooters() const
{
    return m_HeaderFooters;
}


void HeaderFootersResponse::setHeaderFooters(std::shared_ptr<HeaderFooterLinkCollection> value)
{
    m_HeaderFooters = value;
    m_HeaderFootersIsSet = true;
}
bool HeaderFootersResponse::headerFootersIsSet() const
{
    return m_HeaderFootersIsSet;
}

void HeaderFootersResponse::unsetHeaderFooters()
{
    m_HeaderFootersIsSet = false;
}

}
}
}
}
}

