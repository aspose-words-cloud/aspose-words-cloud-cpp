/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="HyperlinksResponse.cpp">
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

#include "HyperlinksResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

HyperlinksResponse::HyperlinksResponse()
{
    m_HyperlinksIsSet = false;

}

HyperlinksResponse::~HyperlinksResponse()
{
}

void HyperlinksResponse::validate()
{
    // TODO: implement validation
}

web::json::value HyperlinksResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();
    if(m_HyperlinksIsSet)
    {
        val[_XPLATSTR("Hyperlinks")] = ModelBase::toJson(m_Hyperlinks);
    }

    return val;
}

void HyperlinksResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("Hyperlinks")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Hyperlinks")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Hyperlinks> newItem(new Hyperlinks());
            newItem->fromJson(fieldValue);
        }
    }

}

void HyperlinksResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    WordsResponse::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_HyperlinksIsSet)
    {
        if (m_Hyperlinks.get())
        {
            m_Hyperlinks->toMultipart(multipart, _XPLATSTR("Hyperlinks."));
        }
    }

}

void HyperlinksResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

std::shared_ptr<Hyperlinks> HyperlinksResponse::getHyperlinks() const
{
    return m_Hyperlinks;
}


void HyperlinksResponse::setHyperlinks(std::shared_ptr<Hyperlinks> value)
{
    m_Hyperlinks = value;
    m_HyperlinksIsSet = true;
}

bool HyperlinksResponse::hyperlinksIsSet() const
{
    return m_HyperlinksIsSet;
}

void HyperlinksResponse::unsetHyperlinks()
{
    m_HyperlinksIsSet = false;
}

}
}
}
}
}
