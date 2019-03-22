/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ReplaceTextResponse.cpp">
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


#include "ReplaceTextResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

ReplaceTextResponse::ReplaceTextResponse()
{
    m_DocumentLinkIsSet = false;
    m_Matches = 0;
    m_MatchesIsSet = false;
}

ReplaceTextResponse::~ReplaceTextResponse()
{
}

void ReplaceTextResponse::validate()
{
    // TODO: implement validation
}

web::json::value ReplaceTextResponse::toJson() const
{
    web::json::value val = this->AsposeResponse::toJson();

    if(m_DocumentLinkIsSet)
    {
        val[_XPLATSTR("DocumentLink")] = ModelBase::toJson(m_DocumentLink);
    }
    if(m_MatchesIsSet)
    {
        val[_XPLATSTR("Matches")] = ModelBase::toJson(m_Matches);
    }

    return val;
}

void ReplaceTextResponse::fromJson(web::json::value& val)
{
    this->AsposeResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("DocumentLink")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DocumentLink")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<FileLink> newItem(new FileLink());
            newItem->fromJson(fieldValue);
            setDocumentLink( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("Matches")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Matches")];
        if(!fieldValue.is_null())
        {
            setMatches(ModelBase::int32_tFromJson(fieldValue));
        }
    }
}

void ReplaceTextResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Code"), m_Code));
    if(m_StatusIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Status"), m_Status));
        
    }
    if(m_DocumentLinkIsSet)
    {
        if (m_DocumentLink.get())
        {
            m_DocumentLink->toMultipart(multipart, _XPLATSTR("DocumentLink."));
        }
        
    }
    if(m_MatchesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Matches"), m_Matches));
    }
}

void ReplaceTextResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    setCode(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("Code"))));
    if(multipart->hasContent(_XPLATSTR("Status")))
    {
        setStatus(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Status"))));
    }
    if(multipart->hasContent(_XPLATSTR("DocumentLink")))
    {
        if(multipart->hasContent(_XPLATSTR("DocumentLink")))
        {
            std::shared_ptr<FileLink> newItem(new FileLink());
            newItem->fromMultiPart(multipart, _XPLATSTR("DocumentLink."));
            setDocumentLink( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("Matches")))
    {
        setMatches(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("Matches"))));
    }
}

std::shared_ptr<FileLink> ReplaceTextResponse::getDocumentLink() const
{
    return m_DocumentLink;
}


void ReplaceTextResponse::setDocumentLink(std::shared_ptr<FileLink> value)
{
    m_DocumentLink = value;
    m_DocumentLinkIsSet = true;
}
bool ReplaceTextResponse::documentLinkIsSet() const
{
    return m_DocumentLinkIsSet;
}

void ReplaceTextResponse::unsetDocumentLink()
{
    m_DocumentLinkIsSet = false;
}

int32_t ReplaceTextResponse::getMatches() const
{
    return m_Matches;
}


void ReplaceTextResponse::setMatches(int32_t value)
{
    m_Matches = value;
    m_MatchesIsSet = true;
}
bool ReplaceTextResponse::matchesIsSet() const
{
    return m_MatchesIsSet;
}

void ReplaceTextResponse::unsetMatches()
{
    m_MatchesIsSet = false;
}

}
}
}
}
}

