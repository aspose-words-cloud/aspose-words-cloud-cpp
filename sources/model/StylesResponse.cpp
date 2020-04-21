/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="StylesResponse.cpp">
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


#include "StylesResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

StylesResponse::StylesResponse()
{
    m_StylesIsSet = false;
}

StylesResponse::~StylesResponse()
{
}

void StylesResponse::validate()
{
    // TODO: implement validation
}

web::json::value StylesResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();

    if(m_StylesIsSet)
    {
        val[_XPLATSTR("Styles")] = ModelBase::toJson(m_Styles);
    }

    return val;
}

void StylesResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("Styles")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Styles")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Styles> newItem(new Styles());
            newItem->fromJson(fieldValue);
            setStyles( newItem );
        }
    }
}

void StylesResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    WordsResponse::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_StylesIsSet)
    {
        if (m_Styles.get())
        {
            m_Styles->toMultipart(multipart, _XPLATSTR("Styles."));
        }
        
    }
}

void StylesResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    WordsResponse::fromMultiPart(multipart, prefix);

    if(multipart->hasContent(_XPLATSTR("Styles")))
    {
        if(multipart->hasContent(_XPLATSTR("Styles")))
        {
            std::shared_ptr<Styles> newItem(new Styles());
            newItem->fromMultiPart(multipart, _XPLATSTR("Styles."));
            setStyles( newItem );
        }
    }
}

std::shared_ptr<Styles> StylesResponse::getStyles() const
{
    return m_Styles;
}


void StylesResponse::setStyles(std::shared_ptr<Styles> value)
{
    m_Styles = value;
    m_StylesIsSet = true;
}
bool StylesResponse::stylesIsSet() const
{
    return m_StylesIsSet;
}

void StylesResponse::unsetStyles()
{
    m_StylesIsSet = false;
}

}
}
}
}
}

