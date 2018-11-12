/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Footnote.cpp">
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


#include "Footnote.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

Footnote::Footnote()
{
    m_ContentIsSet = false;
    m_FootnoteType = utility::conversions::to_string_t("");
    m_FootnoteTypeIsSet = false;
    m_PositionIsSet = false;
    m_ReferenceMark = utility::conversions::to_string_t("");
    m_ReferenceMarkIsSet = false;
    m_Text = utility::conversions::to_string_t("");
    m_TextIsSet = false;
}

Footnote::~Footnote()
{
}

void Footnote::validate()
{
    // TODO: implement validation
}

web::json::value Footnote::toJson() const
{
    web::json::value val = this->FootnoteLink::toJson();

    if(m_ContentIsSet)
    {
        val[utility::conversions::to_string_t("Content")] = ModelBase::toJson(m_Content);
    }
    if(m_FootnoteTypeIsSet)
    {
        val[utility::conversions::to_string_t("FootnoteType")] = ModelBase::toJson(m_FootnoteType);
    }
    if(m_PositionIsSet)
    {
        val[utility::conversions::to_string_t("Position")] = ModelBase::toJson(m_Position);
    }
    if(m_ReferenceMarkIsSet)
    {
        val[utility::conversions::to_string_t("ReferenceMark")] = ModelBase::toJson(m_ReferenceMark);
    }
    if(m_TextIsSet)
    {
        val[utility::conversions::to_string_t("Text")] = ModelBase::toJson(m_Text);
    }

    return val;
}

void Footnote::fromJson(web::json::value& val)
{
    this->FootnoteLink::fromJson(val);

    if(val.has_field(utility::conversions::to_string_t("Content")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Content")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<StoryChildNodes> newItem(new StoryChildNodes());
            newItem->fromJson(fieldValue);
            setContent( newItem );
        }
    }
    if(val.has_field(utility::conversions::to_string_t("FootnoteType")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("FootnoteType")];
        if(!fieldValue.is_null())
        {
            setFootnoteType(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("Position")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Position")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<DocumentPosition> newItem(new DocumentPosition());
            newItem->fromJson(fieldValue);
            setPosition( newItem );
        }
    }
    if(val.has_field(utility::conversions::to_string_t("ReferenceMark")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("ReferenceMark")];
        if(!fieldValue.is_null())
        {
            setReferenceMark(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("Text")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Text")];
        if(!fieldValue.is_null())
        {
            setText(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void Footnote::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_ContentIsSet)
    {
        if (m_Content.get())
        {
            m_Content->toMultipart(multipart, utility::conversions::to_string_t("Content."));
        }
        
    }
    if(m_FootnoteTypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("FootnoteType"), m_FootnoteType));
        
    }
    if(m_PositionIsSet)
    {
        if (m_Position.get())
        {
            m_Position->toMultipart(multipart, utility::conversions::to_string_t("Position."));
        }
        
    }
    if(m_ReferenceMarkIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("ReferenceMark"), m_ReferenceMark));
        
    }
    if(m_TextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Text"), m_Text));
        
    }
}

void Footnote::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t("Content")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("Content")))
        {
            std::shared_ptr<StoryChildNodes> newItem(new StoryChildNodes());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("Content."));
            setContent( newItem );
        }
    }
    if(multipart->hasContent(utility::conversions::to_string_t("FootnoteType")))
    {
        setFootnoteType(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("FootnoteType"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Position")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("Position")))
        {
            std::shared_ptr<DocumentPosition> newItem(new DocumentPosition());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("Position."));
            setPosition( newItem );
        }
    }
    if(multipart->hasContent(utility::conversions::to_string_t("ReferenceMark")))
    {
        setReferenceMark(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("ReferenceMark"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Text")))
    {
        setText(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Text"))));
    }
}

std::shared_ptr<StoryChildNodes> Footnote::getContent() const
{
    return m_Content;
}


void Footnote::setContent(std::shared_ptr<StoryChildNodes> value)
{
    m_Content = value;
    m_ContentIsSet = true;
}
bool Footnote::contentIsSet() const
{
    return m_ContentIsSet;
}

void Footnote::unsetContent()
{
    m_ContentIsSet = false;
}

utility::string_t Footnote::getFootnoteType() const
{
    return m_FootnoteType;
}


void Footnote::setFootnoteType(utility::string_t value)
{
    m_FootnoteType = value;
    m_FootnoteTypeIsSet = true;
}
bool Footnote::footnoteTypeIsSet() const
{
    return m_FootnoteTypeIsSet;
}

void Footnote::unsetFootnoteType()
{
    m_FootnoteTypeIsSet = false;
}

std::shared_ptr<DocumentPosition> Footnote::getPosition() const
{
    return m_Position;
}


void Footnote::setPosition(std::shared_ptr<DocumentPosition> value)
{
    m_Position = value;
    m_PositionIsSet = true;
}
bool Footnote::positionIsSet() const
{
    return m_PositionIsSet;
}

void Footnote::unsetPosition()
{
    m_PositionIsSet = false;
}

utility::string_t Footnote::getReferenceMark() const
{
    return m_ReferenceMark;
}


void Footnote::setReferenceMark(utility::string_t value)
{
    m_ReferenceMark = value;
    m_ReferenceMarkIsSet = true;
}
bool Footnote::referenceMarkIsSet() const
{
    return m_ReferenceMarkIsSet;
}

void Footnote::unsetReferenceMark()
{
    m_ReferenceMarkIsSet = false;
}

utility::string_t Footnote::getText() const
{
    return m_Text;
}


void Footnote::setText(utility::string_t value)
{
    m_Text = value;
    m_TextIsSet = true;
}
bool Footnote::textIsSet() const
{
    return m_TextIsSet;
}

void Footnote::unsetText()
{
    m_TextIsSet = false;
}

}
}
}
}

