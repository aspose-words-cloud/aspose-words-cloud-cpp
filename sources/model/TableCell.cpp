/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TableCell.cpp">
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


#include "TableCell.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

TableCell::TableCell()
{
    m_ChildNodesIsSet = false;
}

TableCell::~TableCell()
{
}

void TableCell::validate()
{
    // TODO: implement validation
}

web::json::value TableCell::toJson() const
{
    web::json::value val = this->NodeLink::toJson();

    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_ChildNodes )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        if(jsonArray.size() > 0)
        {
            val[utility::conversions::to_string_t("ChildNodes")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void TableCell::fromJson(web::json::value& val)
{
    this->NodeLink::fromJson(val);

    {
        m_ChildNodes.clear();
        std::vector<web::json::value> jsonArray;
        if(val.has_field(utility::conversions::to_string_t("ChildNodes")))
        {
        for( auto& item : val[utility::conversions::to_string_t("ChildNodes")].as_array() )
        {
            if(item.is_null())
            {
                m_ChildNodes.push_back( std::shared_ptr<NodeLink>(nullptr) );
            }
            else
            {
                std::shared_ptr<NodeLink> newItem(new NodeLink());
                newItem->fromJson(item);
                m_ChildNodes.push_back( newItem );
            }
        }
        }
    }
}

void TableCell::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_ChildNodes )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("ChildNodes"), web::json::value::array(jsonArray), utility::conversions::to_string_t("application/json")));
        }
    }
}

void TableCell::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    {
        m_ChildNodes.clear();
        if(multipart->hasContent(utility::conversions::to_string_t("ChildNodes")))
        {

        web::json::value jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("ChildNodes"))));
        for( auto& item : jsonArray.as_array() )
        {
            if(item.is_null())
            {
                m_ChildNodes.push_back( std::shared_ptr<NodeLink>(nullptr) );
            }
            else
            {
                std::shared_ptr<NodeLink> newItem(new NodeLink());
                newItem->fromJson(item);
                m_ChildNodes.push_back( newItem );
            }
        }
        }
    }
}

std::vector<std::shared_ptr<NodeLink>>& TableCell::getChildNodes()
{
    return m_ChildNodes;
}

void TableCell::setChildNodes(std::vector<std::shared_ptr<NodeLink>> value)
{
    m_ChildNodes = value;
    m_ChildNodesIsSet = true;
}
bool TableCell::childNodesIsSet() const
{
    return m_ChildNodesIsSet;
}

void TableCell::unsetChildNodes()
{
    m_ChildNodesIsSet = false;
}

}
}
}
}

