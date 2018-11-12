/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DocumentPosition.cpp">
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


#include "DocumentPosition.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

DocumentPosition::DocumentPosition()
{
    m_NodeIsSet = false;
    m_Offset = 0;
    m_OffsetIsSet = false;
}

DocumentPosition::~DocumentPosition()
{
}

void DocumentPosition::validate()
{
    // TODO: implement validation
}

web::json::value DocumentPosition::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_NodeIsSet)
    {
        val[utility::conversions::to_string_t("Node")] = ModelBase::toJson(m_Node);
    }
    if(m_OffsetIsSet)
    {
        val[utility::conversions::to_string_t("Offset")] = ModelBase::toJson(m_Offset);
    }

    return val;
}

void DocumentPosition::fromJson(web::json::value& val)
{
    if(val.has_field(utility::conversions::to_string_t("Node")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Node")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<NodeLink> newItem(new NodeLink());
            newItem->fromJson(fieldValue);
            setNode( newItem );
        }
    }
    if(val.has_field(utility::conversions::to_string_t("Offset")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Offset")];
        if(!fieldValue.is_null())
        {
            setOffset(ModelBase::int32_tFromJson(fieldValue));
        }
    }
}

void DocumentPosition::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_NodeIsSet)
    {
        if (m_Node.get())
        {
            m_Node->toMultipart(multipart, utility::conversions::to_string_t("Node."));
        }
        
    }
    if(m_OffsetIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Offset"), m_Offset));
    }
}

void DocumentPosition::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("Node")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("Node")))
        {
            std::shared_ptr<NodeLink> newItem(new NodeLink());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("Node."));
            setNode( newItem );
        }
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Offset")))
    {
        setOffset(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Offset"))));
    }
}

std::shared_ptr<NodeLink> DocumentPosition::getNode() const
{
    return m_Node;
}


void DocumentPosition::setNode(std::shared_ptr<NodeLink> value)
{
    m_Node = value;
    m_NodeIsSet = true;
}
bool DocumentPosition::nodeIsSet() const
{
    return m_NodeIsSet;
}

void DocumentPosition::unsetNode()
{
    m_NodeIsSet = false;
}

int32_t DocumentPosition::getOffset() const
{
    return m_Offset;
}


void DocumentPosition::setOffset(int32_t value)
{
    m_Offset = value;
    m_OffsetIsSet = true;
}
bool DocumentPosition::offsetIsSet() const
{
    return m_OffsetIsSet;
}

void DocumentPosition::unsetOffset()
{
    m_OffsetIsSet = false;
}

}
}
}
}

