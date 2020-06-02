/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DocumentPosition.cpp">
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

#include "DocumentPosition.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

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
        val[_XPLATSTR("Node")] = ModelBase::toJson(m_Node);
    }
    if(m_OffsetIsSet)
    {
        val[_XPLATSTR("Offset")] = ModelBase::toJson(m_Offset);
    }

    return val;
}

void DocumentPosition::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("Node")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Node")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<NodeLink> newItem(new NodeLink());
            newItem->fromJson(fieldValue);
        }
    }


    if(val.has_field(_XPLATSTR("Offset")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Offset")];
        if(!fieldValue.is_null())
        {
           setOffset(ModelBase::integerFromJson(fieldValue));
        }
    }

}

void DocumentPosition::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_NodeIsSet)
    {
        if (m_Node.get())
        {
            m_Node->toMultipart(multipart, _XPLATSTR("Node."));
        }
    }


    if(m_OffsetIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Offset"), m_Offset));
    }

}

void DocumentPosition::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
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
}
