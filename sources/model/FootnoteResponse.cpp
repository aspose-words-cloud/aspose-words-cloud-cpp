/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FootnoteResponse.cpp">
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


#include "FootnoteResponse.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

FootnoteResponse::FootnoteResponse()
{
    m_FootnoteIsSet = false;
}

FootnoteResponse::~FootnoteResponse()
{
}

void FootnoteResponse::validate()
{
    // TODO: implement validation
}

web::json::value FootnoteResponse::toJson() const
{
    web::json::value val = this->AsposeResponse::toJson();

    if(m_FootnoteIsSet)
    {
        val[_XPLATSTR("Footnote")] = ModelBase::toJson(m_Footnote);
    }

    return val;
}

void FootnoteResponse::fromJson(web::json::value& val)
{
    this->AsposeResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("Footnote")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Footnote")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Footnote> newItem(new Footnote());
            newItem->fromJson(fieldValue);
            setFootnote( newItem );
        }
    }
}

void FootnoteResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Code"), m_Code));
    if(m_StatusIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Status"), m_Status));
        
    }
    if(m_FootnoteIsSet)
    {
        if (m_Footnote.get())
        {
            m_Footnote->toMultipart(multipart, _XPLATSTR("Footnote."));
        }
        
    }
}

void FootnoteResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    setCode(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("Code"))));
    if(multipart->hasContent(_XPLATSTR("Status")))
    {
        setStatus(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Status"))));
    }
    if(multipart->hasContent(_XPLATSTR("Footnote")))
    {
        if(multipart->hasContent(_XPLATSTR("Footnote")))
        {
            std::shared_ptr<Footnote> newItem(new Footnote());
            newItem->fromMultiPart(multipart, _XPLATSTR("Footnote."));
            setFootnote( newItem );
        }
    }
}

std::shared_ptr<Footnote> FootnoteResponse::getFootnote() const
{
    return m_Footnote;
}


void FootnoteResponse::setFootnote(std::shared_ptr<Footnote> value)
{
    m_Footnote = value;
    m_FootnoteIsSet = true;
}
bool FootnoteResponse::footnoteIsSet() const
{
    return m_FootnoteIsSet;
}

void FootnoteResponse::unsetFootnote()
{
    m_FootnoteIsSet = false;
}

}
}
}
}

