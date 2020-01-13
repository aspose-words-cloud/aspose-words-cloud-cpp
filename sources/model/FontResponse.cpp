/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FontResponse.cpp">
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


#include "FontResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

FontResponse::FontResponse()
{
    m_FontIsSet = false;
}

FontResponse::~FontResponse()
{
}

void FontResponse::validate()
{
    // TODO: implement validation
}

web::json::value FontResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();

    if(m_FontIsSet)
    {
        val[_XPLATSTR("Font")] = ModelBase::toJson(m_Font);
    }

    return val;
}

void FontResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("Font")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Font")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Font> newItem(new Font());
            newItem->fromJson(fieldValue);
            setFont( newItem );
        }
    }
}

void FontResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_RequestIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RequestId"), m_RequestId));
        
    }
    if(m_FontIsSet)
    {
        if (m_Font.get())
        {
            m_Font->toMultipart(multipart, _XPLATSTR("Font."));
        }
        
    }
}

void FontResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("RequestId")))
    {
        setRequestId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("RequestId"))));
    }
    if(multipart->hasContent(_XPLATSTR("Font")))
    {
        if(multipart->hasContent(_XPLATSTR("Font")))
        {
            std::shared_ptr<Font> newItem(new Font());
            newItem->fromMultiPart(multipart, _XPLATSTR("Font."));
            setFont( newItem );
        }
    }
}

std::shared_ptr<Font> FontResponse::getFont() const
{
    return m_Font;
}


void FontResponse::setFont(std::shared_ptr<Font> value)
{
    m_Font = value;
    m_FontIsSet = true;
}
bool FontResponse::fontIsSet() const
{
    return m_FontIsSet;
}

void FontResponse::unsetFont()
{
    m_FontIsSet = false;
}

}
}
}
}
}

