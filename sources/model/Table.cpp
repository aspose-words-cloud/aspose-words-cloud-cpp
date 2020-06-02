/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Table.cpp">
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

#include "Table.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

Table::Table()
{
    m_TablePropertiesIsSet = false;

    m_TableRowListIsSet = false;

}

Table::~Table()
{
}

void Table::validate()
{
    // TODO: implement validation
}

web::json::value Table::toJson() const
{
    web::json::value val = this->NodeLink::toJson();
    if(m_TablePropertiesIsSet)
    {
        val[_XPLATSTR("TableProperties")] = ModelBase::toJson(m_TableProperties);
    }
    if(m_TableRowListIsSet)
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_TableRowList.begin(), m_TableRowList.end(), std::back_inserter(jsonArray),
            [&](std::shared_ptr<TableRow> item) {
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("TableRowList")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void Table::fromJson(web::json::value& val)
{
    this->NodeLink::fromJson(val);

    if(val.has_field(_XPLATSTR("TableProperties")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("TableProperties")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<TableProperties> newItem(new TableProperties());
            newItem->fromJson(fieldValue);
        }
    }


    {
        m_TableRowList.clear();
        if(val.has_field(_XPLATSTR("TableRowList")) 
                            && !val[_XPLATSTR("TableRowList")].is_null())
        {
            auto arr = val[_XPLATSTR("TableRowList")].as_array();
            std::transform(arr.begin(), arr.end(), std::back_inserter(m_TableRowList), [&](web::json::value& item){
                if(!item.is_null())
                {
                    std::shared_ptr<TableRow> newItem(new TableRow());
                    newItem->fromJson(item);
                    return newItem;
                }

                return (std::shared_ptr<TableRow>)nullptr;
            });
        }
    }

}

void Table::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    NodeLink::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_TablePropertiesIsSet)
    {
        if (m_TableProperties.get())
        {
            m_TableProperties->toMultipart(multipart, _XPLATSTR("TableProperties."));
        }
    }


    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_TableRowList.begin(), m_TableRowList.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<TableRow> item){
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TableRowList"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }

}

void Table::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

std::shared_ptr<TableProperties> Table::getTableProperties() const
{
    return m_TableProperties;
}


void Table::setTableProperties(std::shared_ptr<TableProperties> value)
{
    m_TableProperties = value;
    m_TablePropertiesIsSet = true;
}

bool Table::tablePropertiesIsSet() const
{
    return m_TablePropertiesIsSet;
}

void Table::unsetTableProperties()
{
    m_TablePropertiesIsSet = false;
}

std::vector<std::shared_ptr<TableRow>>& Table::getTableRowList()
{
    return m_TableRowList;
}


void Table::setTableRowList(std::vector<std::shared_ptr<TableRow>> const& value)
{
    m_TableRowList = value;
    m_TableRowListIsSet = true;
}

bool Table::tableRowListIsSet() const
{
    return m_TableRowListIsSet;
}

void Table::unsetTableRowList()
{
    m_TableRowListIsSet = false;
}

}
}
}
}
}
