/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="HyperlinkResponse.cpp">
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


#include "HyperlinkResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

HyperlinkResponse::HyperlinkResponse()
{
    m_HyperlinkIsSet = false;
}

HyperlinkResponse::~HyperlinkResponse()
{
}

void HyperlinkResponse::validate()
{
    // TODO: implement validation
}

web::json::value HyperlinkResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();

    if(m_HyperlinkIsSet)
    {
        val[_XPLATSTR("Hyperlink")] = ModelBase::toJson(m_Hyperlink);
    }

    return val;
}

void HyperlinkResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("Hyperlink")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Hyperlink")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Hyperlink> newItem(new Hyperlink());
            newItem->fromJson(fieldValue);
            setHyperlink( newItem );
        }
    }
}

void HyperlinkResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    WordsResponse::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_HyperlinkIsSet)
    {
        if (m_Hyperlink.get())
        {
            m_Hyperlink->toMultipart(multipart, _XPLATSTR("Hyperlink."));
        }
        
    }
}

void HyperlinkResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    WordsResponse::fromMultiPart(multipart, prefix);

    if(multipart->hasContent(_XPLATSTR("Hyperlink")))
    {
        if(multipart->hasContent(_XPLATSTR("Hyperlink")))
        {
            std::shared_ptr<Hyperlink> newItem(new Hyperlink());
            newItem->fromMultiPart(multipart, _XPLATSTR("Hyperlink."));
            setHyperlink( newItem );
        }
    }
}

std::shared_ptr<Hyperlink> HyperlinkResponse::getHyperlink() const
{
    return m_Hyperlink;
}


void HyperlinkResponse::setHyperlink(std::shared_ptr<Hyperlink> value)
{
    m_Hyperlink = value;
    m_HyperlinkIsSet = true;
}
bool HyperlinkResponse::hyperlinkIsSet() const
{
    return m_HyperlinkIsSet;
}

void HyperlinkResponse::unsetHyperlink()
{
    m_HyperlinkIsSet = false;
}

}
}
}
}
}

