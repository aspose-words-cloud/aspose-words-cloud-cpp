/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="NodeLink.cpp">
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


#include "NodeLink.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

NodeLink::NodeLink()
{
    m_NodeId = utility::conversions::to_string_t("");
    m_NodeIdIsSet = false;
}

NodeLink::~NodeLink()
{
}

void NodeLink::validate()
{
    // TODO: implement validation
}

web::json::value NodeLink::toJson() const
{
    web::json::value val = this->LinkElement::toJson();

    if(m_NodeIdIsSet)
    {
        val[_XPLATSTR("NodeId")] = ModelBase::toJson(m_NodeId);
    }

    return val;
}

void NodeLink::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    if(val.has_field(_XPLATSTR("NodeId")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("NodeId")];
        if(!fieldValue.is_null())
        {
            setNodeId(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void NodeLink::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_LinkIsSet)
    {
        if (m_Link.get())
        {
            m_Link->toMultipart(multipart, _XPLATSTR("link."));
        }
        
    }
    if(m_NodeIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("NodeId"), m_NodeId));
        
    }
}

void NodeLink::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("link")))
    {
        if(multipart->hasContent(_XPLATSTR("link")))
        {
            std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
            newItem->fromMultiPart(multipart, _XPLATSTR("link."));
            setLink( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("NodeId")))
    {
        setNodeId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("NodeId"))));
    }
}

utility::string_t NodeLink::getNodeId() const
{
    return m_NodeId;
}


void NodeLink::setNodeId(utility::string_t value)
{
    m_NodeId = value;
    m_NodeIdIsSet = true;
}
bool NodeLink::nodeIdIsSet() const
{
    return m_NodeIdIsSet;
}

void NodeLink::unsetNodeId()
{
    m_NodeIdIsSet = false;
}

}
}
}
}
}

