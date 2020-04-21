/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Styles.cpp">
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


#include "Styles.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

Styles::Styles()
{
    m_StyleIsSet = false;
}

Styles::~Styles()
{
}

void Styles::validate()
{
    // TODO: implement validation
}

web::json::value Styles::toJson() const
{
    web::json::value val = this->LinkElement::toJson();

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_Style.begin(), m_Style.end(), std::back_inserter(jsonArray),
			[&](std::shared_ptr<Style> item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("Style")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void Styles::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    {
        m_Style.clear();
        if(val.has_field(_XPLATSTR("Style")) 
                            && !val[_XPLATSTR("Style")].is_null())
        {
        auto arr = val[_XPLATSTR("Style")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_Style), [&](web::json::value& item){
            if(item.is_null())
            {
                return std::shared_ptr<Style>(nullptr);
            }
            else
            {
                std::shared_ptr<Style> newItem(new Style());
                newItem->fromJson(item);
                return newItem;
            }
        });

        }
    }
}

void Styles::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    LinkElement::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_Style.begin(), m_Style.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<Style> item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Style"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }
}

void Styles::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    LinkElement::fromMultiPart(multipart, prefix);

    {
        m_Style.clear();
        if(multipart->hasContent(_XPLATSTR("Style")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Style")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_Style), [&](web::json::value item) {
            if(item.is_null())
            {
                return std::shared_ptr<Style>(nullptr) ;
            }
            else
            {
                std::shared_ptr<Style> newItem(new Style());
                newItem->fromJson(item);
                return newItem ;
            }
        });
        }
    }
}

std::vector<std::shared_ptr<Style>>& Styles::getStyle()
{
    return m_Style;
}

void Styles::setStyle(std::vector<std::shared_ptr<Style>> const& value)
{
    m_Style = value;
    m_StyleIsSet = true;
}
bool Styles::styleIsSet() const
{
    return m_StyleIsSet;
}

void Styles::unsetStyle()
{
    m_StyleIsSet = false;
}

}
}
}
}
}

