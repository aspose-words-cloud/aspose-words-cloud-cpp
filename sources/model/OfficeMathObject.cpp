/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="OfficeMathObject.cpp">
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


#include "OfficeMathObject.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

OfficeMathObject::OfficeMathObject()
{
    m_ContentIsSet = false;
    m_DisplayType = utility::conversions::to_string_t("");
    m_DisplayTypeIsSet = false;
    m_Justification = utility::conversions::to_string_t("");
    m_JustificationIsSet = false;
    m_MathObjectType = utility::conversions::to_string_t("");
    m_MathObjectTypeIsSet = false;
}

OfficeMathObject::~OfficeMathObject()
{
}

void OfficeMathObject::validate()
{
    // TODO: implement validation
}

web::json::value OfficeMathObject::toJson() const
{
    web::json::value val = this->OfficeMathLink::toJson();

    if(m_ContentIsSet)
    {
        val[_XPLATSTR("content")] = ModelBase::toJson(m_Content);
    }
    if(m_DisplayTypeIsSet)
    {
        val[_XPLATSTR("displayType")] = ModelBase::toJson(m_DisplayType);
    }
    if(m_JustificationIsSet)
    {
        val[_XPLATSTR("justification")] = ModelBase::toJson(m_Justification);
    }
    if(m_MathObjectTypeIsSet)
    {
        val[_XPLATSTR("mathObjectType")] = ModelBase::toJson(m_MathObjectType);
    }

    return val;
}

void OfficeMathObject::fromJson(web::json::value& val)
{
    this->OfficeMathLink::fromJson(val);

    if(val.has_field(_XPLATSTR("content")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("content")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<StoryChildNodes> newItem(new StoryChildNodes());
            newItem->fromJson(fieldValue);
            setContent( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("displayType")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("displayType")];
        if(!fieldValue.is_null())
        {
            setDisplayType(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("justification")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("justification")];
        if(!fieldValue.is_null())
        {
            setJustification(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("mathObjectType")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("mathObjectType")];
        if(!fieldValue.is_null())
        {
            setMathObjectType(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void OfficeMathObject::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
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
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("nodeId"), m_NodeId));
        
    }
    if(m_ContentIsSet)
    {
        if (m_Content.get())
        {
            m_Content->toMultipart(multipart, _XPLATSTR("content."));
        }
        
    }
    if(m_DisplayTypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("displayType"), m_DisplayType));
        
    }
    if(m_JustificationIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("justification"), m_Justification));
        
    }
    if(m_MathObjectTypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("mathObjectType"), m_MathObjectType));
        
    }
}

void OfficeMathObject::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(_XPLATSTR("nodeId")))
    {
        setNodeId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("nodeId"))));
    }
    if(multipart->hasContent(_XPLATSTR("content")))
    {
        if(multipart->hasContent(_XPLATSTR("content")))
        {
            std::shared_ptr<StoryChildNodes> newItem(new StoryChildNodes());
            newItem->fromMultiPart(multipart, _XPLATSTR("content."));
            setContent( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("displayType")))
    {
        setDisplayType(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("displayType"))));
    }
    if(multipart->hasContent(_XPLATSTR("justification")))
    {
        setJustification(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("justification"))));
    }
    if(multipart->hasContent(_XPLATSTR("mathObjectType")))
    {
        setMathObjectType(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("mathObjectType"))));
    }
}

std::shared_ptr<StoryChildNodes> OfficeMathObject::getContent() const
{
    return m_Content;
}


void OfficeMathObject::setContent(std::shared_ptr<StoryChildNodes> value)
{
    m_Content = value;
    m_ContentIsSet = true;
}
bool OfficeMathObject::contentIsSet() const
{
    return m_ContentIsSet;
}

void OfficeMathObject::unsetContent()
{
    m_ContentIsSet = false;
}

utility::string_t OfficeMathObject::getDisplayType() const
{
    return m_DisplayType;
}


void OfficeMathObject::setDisplayType(utility::string_t value)
{
    m_DisplayType = value;
    m_DisplayTypeIsSet = true;
}
bool OfficeMathObject::displayTypeIsSet() const
{
    return m_DisplayTypeIsSet;
}

void OfficeMathObject::unsetDisplayType()
{
    m_DisplayTypeIsSet = false;
}

utility::string_t OfficeMathObject::getJustification() const
{
    return m_Justification;
}


void OfficeMathObject::setJustification(utility::string_t value)
{
    m_Justification = value;
    m_JustificationIsSet = true;
}
bool OfficeMathObject::justificationIsSet() const
{
    return m_JustificationIsSet;
}

void OfficeMathObject::unsetJustification()
{
    m_JustificationIsSet = false;
}

utility::string_t OfficeMathObject::getMathObjectType() const
{
    return m_MathObjectType;
}


void OfficeMathObject::setMathObjectType(utility::string_t value)
{
    m_MathObjectType = value;
    m_MathObjectTypeIsSet = true;
}
bool OfficeMathObject::mathObjectTypeIsSet() const
{
    return m_MathObjectTypeIsSet;
}

void OfficeMathObject::unsetMathObjectType()
{
    m_MathObjectTypeIsSet = false;
}

}
}
}
}
}

