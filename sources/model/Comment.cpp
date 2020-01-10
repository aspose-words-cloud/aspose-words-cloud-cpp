/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Comment.cpp">
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


#include "Comment.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

Comment::Comment()
{
    m_Author = utility::conversions::to_string_t("");
    m_AuthorIsSet = false;
    m_ContentIsSet = false;
    m_DateTime = utility::datetime();
    m_DateTimeIsSet = false;
    m_Initial = utility::conversions::to_string_t("");
    m_InitialIsSet = false;
    m_RangeEndIsSet = false;
    m_RangeStartIsSet = false;
    m_Text = utility::conversions::to_string_t("");
    m_TextIsSet = false;
}

Comment::~Comment()
{
}

void Comment::validate()
{
    // TODO: implement validation
}

web::json::value Comment::toJson() const
{
    web::json::value val = this->CommentLink::toJson();

    if(m_AuthorIsSet)
    {
        val[_XPLATSTR("author")] = ModelBase::toJson(m_Author);
    }
    if(m_ContentIsSet)
    {
        val[_XPLATSTR("content")] = ModelBase::toJson(m_Content);
    }
    if(m_DateTimeIsSet)
    {
        val[_XPLATSTR("dateTime")] = ModelBase::toJson(m_DateTime);
    }
    if(m_InitialIsSet)
    {
        val[_XPLATSTR("initial")] = ModelBase::toJson(m_Initial);
    }
    if(m_RangeEndIsSet)
    {
        val[_XPLATSTR("rangeEnd")] = ModelBase::toJson(m_RangeEnd);
    }
    if(m_RangeStartIsSet)
    {
        val[_XPLATSTR("rangeStart")] = ModelBase::toJson(m_RangeStart);
    }
    if(m_TextIsSet)
    {
        val[_XPLATSTR("text")] = ModelBase::toJson(m_Text);
    }

    return val;
}

void Comment::fromJson(web::json::value& val)
{
    this->CommentLink::fromJson(val);

    if(val.has_field(_XPLATSTR("author")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("author")];
        if(!fieldValue.is_null())
        {
            setAuthor(ModelBase::stringFromJson(fieldValue));
        }
    }
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
    if(val.has_field(_XPLATSTR("dateTime")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("dateTime")];
        if(!fieldValue.is_null())
        {
            setDateTime(ModelBase::dateFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("initial")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("initial")];
        if(!fieldValue.is_null())
        {
            setInitial(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("rangeEnd")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("rangeEnd")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<DocumentPosition> newItem(new DocumentPosition());
            newItem->fromJson(fieldValue);
            setRangeEnd( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("rangeStart")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("rangeStart")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<DocumentPosition> newItem(new DocumentPosition());
            newItem->fromJson(fieldValue);
            setRangeStart( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("text")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("text")];
        if(!fieldValue.is_null())
        {
            setText(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void Comment::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_LinkIsSet)
    {
        if (m_Link.get())
        {
            m_Link->toMultipart(multipart, _XPLATSTR("link."));
        }
        
    }
    if(m_AuthorIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("author"), m_Author));
        
    }
    if(m_ContentIsSet)
    {
        if (m_Content.get())
        {
            m_Content->toMultipart(multipart, _XPLATSTR("content."));
        }
        
    }
    if(m_DateTimeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("dateTime"), m_DateTime));
        
    }
    if(m_InitialIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("initial"), m_Initial));
        
    }
    if(m_RangeEndIsSet)
    {
        if (m_RangeEnd.get())
        {
            m_RangeEnd->toMultipart(multipart, _XPLATSTR("rangeEnd."));
        }
        
    }
    if(m_RangeStartIsSet)
    {
        if (m_RangeStart.get())
        {
            m_RangeStart->toMultipart(multipart, _XPLATSTR("rangeStart."));
        }
        
    }
    if(m_TextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("text"), m_Text));
        
    }
}

void Comment::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(_XPLATSTR("author")))
    {
        setAuthor(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("author"))));
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
    if(multipart->hasContent(_XPLATSTR("dateTime")))
    {
        setDateTime(ModelBase::dateFromHttpContent(multipart->getContent(_XPLATSTR("dateTime"))));
    }
    if(multipart->hasContent(_XPLATSTR("initial")))
    {
        setInitial(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("initial"))));
    }
    if(multipart->hasContent(_XPLATSTR("rangeEnd")))
    {
        if(multipart->hasContent(_XPLATSTR("rangeEnd")))
        {
            std::shared_ptr<DocumentPosition> newItem(new DocumentPosition());
            newItem->fromMultiPart(multipart, _XPLATSTR("rangeEnd."));
            setRangeEnd( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("rangeStart")))
    {
        if(multipart->hasContent(_XPLATSTR("rangeStart")))
        {
            std::shared_ptr<DocumentPosition> newItem(new DocumentPosition());
            newItem->fromMultiPart(multipart, _XPLATSTR("rangeStart."));
            setRangeStart( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("text")))
    {
        setText(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("text"))));
    }
}

utility::string_t Comment::getAuthor() const
{
    return m_Author;
}


void Comment::setAuthor(utility::string_t value)
{
    m_Author = value;
    m_AuthorIsSet = true;
}
bool Comment::authorIsSet() const
{
    return m_AuthorIsSet;
}

void Comment::unsetAuthor()
{
    m_AuthorIsSet = false;
}

std::shared_ptr<StoryChildNodes> Comment::getContent() const
{
    return m_Content;
}


void Comment::setContent(std::shared_ptr<StoryChildNodes> value)
{
    m_Content = value;
    m_ContentIsSet = true;
}
bool Comment::contentIsSet() const
{
    return m_ContentIsSet;
}

void Comment::unsetContent()
{
    m_ContentIsSet = false;
}

utility::datetime Comment::getDateTime() const
{
    return m_DateTime;
}


void Comment::setDateTime(utility::datetime value)
{
    m_DateTime = value;
    m_DateTimeIsSet = true;
}
bool Comment::dateTimeIsSet() const
{
    return m_DateTimeIsSet;
}

void Comment::unsetDateTime()
{
    m_DateTimeIsSet = false;
}

utility::string_t Comment::getInitial() const
{
    return m_Initial;
}


void Comment::setInitial(utility::string_t value)
{
    m_Initial = value;
    m_InitialIsSet = true;
}
bool Comment::initialIsSet() const
{
    return m_InitialIsSet;
}

void Comment::unsetInitial()
{
    m_InitialIsSet = false;
}

std::shared_ptr<DocumentPosition> Comment::getRangeEnd() const
{
    return m_RangeEnd;
}


void Comment::setRangeEnd(std::shared_ptr<DocumentPosition> value)
{
    m_RangeEnd = value;
    m_RangeEndIsSet = true;
}
bool Comment::rangeEndIsSet() const
{
    return m_RangeEndIsSet;
}

void Comment::unsetRangeEnd()
{
    m_RangeEndIsSet = false;
}

std::shared_ptr<DocumentPosition> Comment::getRangeStart() const
{
    return m_RangeStart;
}


void Comment::setRangeStart(std::shared_ptr<DocumentPosition> value)
{
    m_RangeStart = value;
    m_RangeStartIsSet = true;
}
bool Comment::rangeStartIsSet() const
{
    return m_RangeStartIsSet;
}

void Comment::unsetRangeStart()
{
    m_RangeStartIsSet = false;
}

utility::string_t Comment::getText() const
{
    return m_Text;
}


void Comment::setText(utility::string_t value)
{
    m_Text = value;
    m_TextIsSet = true;
}
bool Comment::textIsSet() const
{
    return m_TextIsSet;
}

void Comment::unsetText()
{
    m_TextIsSet = false;
}

}
}
}
}
}

