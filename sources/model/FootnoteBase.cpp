/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FootnoteBase.cpp">
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

#include "FootnoteBase.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

FootnoteBase::FootnoteBase()
{
    m_FootnoteTypeIsSet = false;

    m_PositionIsSet = false;
    m_ReferenceMark = utility::conversions::to_string_t("");
    m_ReferenceMarkIsSet = false;
    m_Text = utility::conversions::to_string_t("");
    m_TextIsSet = false;

}

FootnoteBase::~FootnoteBase()
{
}

void FootnoteBase::validate()
{
    // TODO: implement validation
}

web::json::value FootnoteBase::toJson() const
{
    web::json::value val = web::json::value::object();
    if(m_FootnoteTypeIsSet)
    {
        val[_XPLATSTR("FootnoteType")] = ModelBase::toJson(m_FootnoteType);
    }
    if(m_PositionIsSet)
    {
        val[_XPLATSTR("Position")] = ModelBase::toJson(m_Position);
    }
    if(m_ReferenceMarkIsSet)
    {
        val[_XPLATSTR("ReferenceMark")] = ModelBase::toJson(m_ReferenceMark);
    }
    if(m_TextIsSet)
    {
        val[_XPLATSTR("Text")] = ModelBase::toJson(m_Text);
    }

    return val;
}

void FootnoteBase::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("FootnoteType")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("FootnoteType")];
        if(!fieldValue.is_null())
        {
           setFootnoteType(ModelBase::enumFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("Position")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Position")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<DocumentPosition> newItem(new DocumentPosition());
            newItem->fromJson(fieldValue);
        }
    }


    if(val.has_field(_XPLATSTR("ReferenceMark")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ReferenceMark")];
        if(!fieldValue.is_null())
        {
           setReferenceMark(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("Text")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Text")];
        if(!fieldValue.is_null())
        {
           setText(ModelBase::stringFromJson(fieldValue));
        }
    }

}

void FootnoteBase::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_FootnoteTypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("FootnoteType"), m_FootnoteType));
    }


    if(m_PositionIsSet)
    {
        if (m_Position.get())
        {
            m_Position->toMultipart(multipart, _XPLATSTR("Position."));
        }
    }


    if(m_ReferenceMarkIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ReferenceMark"), m_ReferenceMark));
    }


    if(m_TextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Text"), m_Text));
    }

}

void FootnoteBase::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

utility::string_t FootnoteBase::getFootnoteType() const
{
    return m_FootnoteType;
}


void FootnoteBase::setFootnoteType(utility::string_t value)
{
    m_FootnoteType = value;
    m_FootnoteTypeIsSet = true;
}

bool FootnoteBase::footnoteTypeIsSet() const
{
    return m_FootnoteTypeIsSet;
}

void FootnoteBase::unsetFootnoteType()
{
    m_FootnoteTypeIsSet = false;
}

std::shared_ptr<DocumentPosition> FootnoteBase::getPosition() const
{
    return m_Position;
}


void FootnoteBase::setPosition(std::shared_ptr<DocumentPosition> value)
{
    m_Position = value;
    m_PositionIsSet = true;
}

bool FootnoteBase::positionIsSet() const
{
    return m_PositionIsSet;
}

void FootnoteBase::unsetPosition()
{
    m_PositionIsSet = false;
}

utility::string_t FootnoteBase::getReferenceMark() const
{
    return m_ReferenceMark;
}


void FootnoteBase::setReferenceMark(utility::string_t value)
{
    m_ReferenceMark = value;
    m_ReferenceMarkIsSet = true;
}

bool FootnoteBase::referenceMarkIsSet() const
{
    return m_ReferenceMarkIsSet;
}

void FootnoteBase::unsetReferenceMark()
{
    m_ReferenceMarkIsSet = false;
}

utility::string_t FootnoteBase::getText() const
{
    return m_Text;
}


void FootnoteBase::setText(utility::string_t value)
{
    m_Text = value;
    m_TextIsSet = true;
}

bool FootnoteBase::textIsSet() const
{
    return m_TextIsSet;
}

void FootnoteBase::unsetText()
{
    m_TextIsSet = false;
}

}
}
}
}
}
