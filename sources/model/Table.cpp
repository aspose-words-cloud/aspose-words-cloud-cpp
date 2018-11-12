/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Table.cpp">
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


#include "Table.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

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
        val[utility::conversions::to_string_t("TableProperties")] = ModelBase::toJson(m_TableProperties);
    }
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_TableRowList )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        if(jsonArray.size() > 0)
        {
            val[utility::conversions::to_string_t("TableRowList")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void Table::fromJson(web::json::value& val)
{
    this->NodeLink::fromJson(val);

    if(val.has_field(utility::conversions::to_string_t("TableProperties")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("TableProperties")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<TableProperties> newItem(new TableProperties());
            newItem->fromJson(fieldValue);
            setTableProperties( newItem );
        }
    }
    {
        m_TableRowList.clear();
        std::vector<web::json::value> jsonArray;
        if(val.has_field(utility::conversions::to_string_t("TableRowList")))
        {
        for( auto& item : val[utility::conversions::to_string_t("TableRowList")].as_array() )
        {
            if(item.is_null())
            {
                m_TableRowList.push_back( std::shared_ptr<TableRow>(nullptr) );
            }
            else
            {
                std::shared_ptr<TableRow> newItem(new TableRow());
                newItem->fromJson(item);
                m_TableRowList.push_back( newItem );
            }
        }
        }
    }
}

void Table::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_LinkIsSet)
    {
        if (m_Link.get())
        {
            m_Link->toMultipart(multipart, utility::conversions::to_string_t("link."));
        }
        
    }
    if(m_NodeIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("NodeId"), m_NodeId));
        
    }
    if(m_TablePropertiesIsSet)
    {
        if (m_TableProperties.get())
        {
            m_TableProperties->toMultipart(multipart, utility::conversions::to_string_t("TableProperties."));
        }
        
    }
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_TableRowList )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("TableRowList"), web::json::value::array(jsonArray), utility::conversions::to_string_t("application/json")));
        }
    }
}

void Table::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("link")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("link")))
        {
            std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("link."));
            setLink( newItem );
        }
    }
    if(multipart->hasContent(utility::conversions::to_string_t("NodeId")))
    {
        setNodeId(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("NodeId"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("TableProperties")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("TableProperties")))
        {
            std::shared_ptr<TableProperties> newItem(new TableProperties());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("TableProperties."));
            setTableProperties( newItem );
        }
    }
    {
        m_TableRowList.clear();
        if(multipart->hasContent(utility::conversions::to_string_t("TableRowList")))
        {

        web::json::value jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("TableRowList"))));
        for( auto& item : jsonArray.as_array() )
        {
            if(item.is_null())
            {
                m_TableRowList.push_back( std::shared_ptr<TableRow>(nullptr) );
            }
            else
            {
                std::shared_ptr<TableRow> newItem(new TableRow());
                newItem->fromJson(item);
                m_TableRowList.push_back( newItem );
            }
        }
        }
    }
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

void Table::setTableRowList(std::vector<std::shared_ptr<TableRow>> value)
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

