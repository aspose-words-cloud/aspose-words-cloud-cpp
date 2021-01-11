/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="StyleResponse.cpp">
*   Copyright (c) 2021 Aspose.Words for Cloud
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

#include "StyleResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

StyleResponse::StyleResponse()
{
    m_StyleIsSet = false;

}

StyleResponse::~StyleResponse()
{
}

void StyleResponse::validate()
{
    // TODO: implement validation
}

web::json::value StyleResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();
    if(m_StyleIsSet)
    {
        val[_XPLATSTR("Style")] = ModelBase::toJson(m_Style);
    }

    return val;
}

void StyleResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("Style")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Style")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Style> newItem(new Style());
            newItem->fromJson(fieldValue);
            setStyle( newItem );
        }
    }

}

void StyleResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    WordsResponse::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_StyleIsSet)
    {
        if (m_Style.get())
        {
            m_Style->toMultipart(multipart, _XPLATSTR("Style."));
        }
    }

}

void StyleResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

std::shared_ptr<Style> StyleResponse::getStyle() const
{
    return m_Style;
}


void StyleResponse::setStyle(std::shared_ptr<Style> value)
{
    m_Style = value;
    m_StyleIsSet = true;
}

bool StyleResponse::styleIsSet() const
{
    return m_StyleIsSet;
}

void StyleResponse::unsetStyle()
{
    m_StyleIsSet = false;
}

}
}
}
}
}
