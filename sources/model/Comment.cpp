/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Comment.cpp">
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
        val[_XPLATSTR("Author")] = ModelBase::toJson(m_Author);
    }
    if(m_ContentIsSet)
    {
        val[_XPLATSTR("Content")] = ModelBase::toJson(m_Content);
    }
    if(m_DateTimeIsSet)
    {
        val[_XPLATSTR("DateTime")] = ModelBase::toJson(m_DateTime);
    }
    if(m_InitialIsSet)
    {
        val[_XPLATSTR("Initial")] = ModelBase::toJson(m_Initial);
    }
    if(m_RangeEndIsSet)
    {
        val[_XPLATSTR("RangeEnd")] = ModelBase::toJson(m_RangeEnd);
    }
    if(m_RangeStartIsSet)
    {
        val[_XPLATSTR("RangeStart")] = ModelBase::toJson(m_RangeStart);
    }
    if(m_TextIsSet)
    {
        val[_XPLATSTR("Text")] = ModelBase::toJson(m_Text);
    }

    return val;
}

void Comment::fromJson(web::json::value& val)
{
    this->CommentLink::fromJson(val);

    if(val.has_field(_XPLATSTR("Author")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Author")];
        if(!fieldValue.is_null())
        {
           setAuthor(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("Content")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Content")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<StoryChildNodes> newItem(new StoryChildNodes());
            newItem->fromJson(fieldValue);
        }
    }


    if(val.has_field(_XPLATSTR("DateTime")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DateTime")];
        if(!fieldValue.is_null())
        {
           setDateTime(ModelBase::dateTimeFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("Initial")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Initial")];
        if(!fieldValue.is_null())
        {
           setInitial(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("RangeEnd")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("RangeEnd")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<DocumentPosition> newItem(new DocumentPosition());
            newItem->fromJson(fieldValue);
        }
    }


    if(val.has_field(_XPLATSTR("RangeStart")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("RangeStart")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<DocumentPosition> newItem(new DocumentPosition());
            newItem->fromJson(fieldValue);
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

void Comment::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    CommentLink::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_AuthorIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Author"), m_Author));
    }


    if(m_ContentIsSet)
    {
        if (m_Content.get())
        {
            m_Content->toMultipart(multipart, _XPLATSTR("Content."));
        }
    }


    if(m_DateTimeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("DateTime"), m_DateTime));
    }


    if(m_InitialIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Initial"), m_Initial));
    }


    if(m_RangeEndIsSet)
    {
        if (m_RangeEnd.get())
        {
            m_RangeEnd->toMultipart(multipart, _XPLATSTR("RangeEnd."));
        }
    }


    if(m_RangeStartIsSet)
    {
        if (m_RangeStart.get())
        {
            m_RangeStart->toMultipart(multipart, _XPLATSTR("RangeStart."));
        }
    }


    if(m_TextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Text"), m_Text));
    }

}

void Comment::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
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
