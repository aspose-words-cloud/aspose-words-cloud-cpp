/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TableLinkCollection.cpp">
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

#include "TableLinkCollection.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

TableLinkCollection::TableLinkCollection()
{
    m_TableLinkListIsSet = false;

}

TableLinkCollection::~TableLinkCollection()
{
}

void TableLinkCollection::validate()
{
    // TODO: implement validation
}

web::json::value TableLinkCollection::toJson() const
{
    web::json::value val = this->LinkElement::toJson();
    if(m_TableLinkListIsSet)
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_TableLinkList.begin(), m_TableLinkList.end(), std::back_inserter(jsonArray),
            [&](std::shared_ptr<TableLink> item) {
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("TableLinkList")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void TableLinkCollection::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    {
        m_TableLinkList.clear();
        if(val.has_field(_XPLATSTR("TableLinkList")) 
                            && !val[_XPLATSTR("TableLinkList")].is_null())
        {
            auto arr = val[_XPLATSTR("TableLinkList")].as_array();
            std::transform(arr.begin(), arr.end(), std::back_inserter(m_TableLinkList), [&](web::json::value& item){
                if(!item.is_null())
                {
                    std::shared_ptr<TableLink> newItem(new TableLink());
                    newItem->fromJson(item);
                    return newItem;
                }

                return (std::shared_ptr<TableLink>)nullptr;
            });
        }
    }

}

void TableLinkCollection::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    LinkElement::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_TableLinkList.begin(), m_TableLinkList.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<TableLink> item){
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TableLinkList"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }

}

void TableLinkCollection::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

std::vector<std::shared_ptr<TableLink>>& TableLinkCollection::getTableLinkList()
{
    return m_TableLinkList;
}


void TableLinkCollection::setTableLinkList(std::vector<std::shared_ptr<TableLink>> const& value)
{
    m_TableLinkList = value;
    m_TableLinkListIsSet = true;
}

bool TableLinkCollection::tableLinkListIsSet() const
{
    return m_TableLinkListIsSet;
}

void TableLinkCollection::unsetTableLinkList()
{
    m_TableLinkListIsSet = false;
}

}
}
}
}
}
