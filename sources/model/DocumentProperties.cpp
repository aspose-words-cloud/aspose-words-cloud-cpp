/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DocumentProperties.cpp">
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

#include "DocumentProperties.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

DocumentProperties::DocumentProperties()
{
    m_ListIsSet = false;

}

DocumentProperties::~DocumentProperties()
{
}

void DocumentProperties::validate()
{
    // TODO: implement validation
}

web::json::value DocumentProperties::toJson() const
{
    web::json::value val = this->LinkElement::toJson();
    if(m_ListIsSet)
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_List.begin(), m_List.end(), std::back_inserter(jsonArray),
            [&](std::shared_ptr<DocumentProperty> item) {
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("List")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void DocumentProperties::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    {
        m_List.clear();
        if(val.has_field(_XPLATSTR("List")) 
                            && !val[_XPLATSTR("List")].is_null())
        {
            auto arr = val[_XPLATSTR("List")].as_array();
            std::transform(arr.begin(), arr.end(), std::back_inserter(m_List), [&](web::json::value& item){
                if(!item.is_null())
                {
                    std::shared_ptr<DocumentProperty> newItem(new DocumentProperty());
                    newItem->fromJson(item);
                    return newItem;
                }

                return (std::shared_ptr<DocumentProperty>)nullptr;
            });
        }
    }

}

void DocumentProperties::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    LinkElement::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_List.begin(), m_List.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<DocumentProperty> item){
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("List"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }

}

void DocumentProperties::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

std::vector<std::shared_ptr<DocumentProperty>>& DocumentProperties::getList()
{
    return m_List;
}


void DocumentProperties::setList(std::vector<std::shared_ptr<DocumentProperty>> const& value)
{
    m_List = value;
    m_ListIsSet = true;
}

bool DocumentProperties::listIsSet() const
{
    return m_ListIsSet;
}

void DocumentProperties::unsetList()
{
    m_ListIsSet = false;
}

}
}
}
}
}
