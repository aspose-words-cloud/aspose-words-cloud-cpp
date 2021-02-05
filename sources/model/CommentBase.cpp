/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="CommentBase.cpp">
*   Copyright (c) 2021 Aspose.Words for Cloud
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

#include "CommentBase.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

CommentBase::CommentBase()
{
    m_Author = utility::conversions::to_string_t("");
    m_AuthorIsSet = false;
    m_DateTime = utility::datetime();
    m_DateTimeIsSet = false;
    m_Initial = utility::conversions::to_string_t("");
    m_InitialIsSet = false;

    m_RangeEndIsSet = false;

    m_RangeStartIsSet = false;
    m_Text = utility::conversions::to_string_t("");
    m_TextIsSet = false;

}

CommentBase::~CommentBase()
{
}

void CommentBase::validate()
{
    // TODO: implement validation
}

web::json::value CommentBase::toJson() const
{
    web::json::value val = web::json::value::object();
    if(m_AuthorIsSet)
    {
        val[_XPLATSTR("Author")] = ModelBase::toJson(m_Author);
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

void CommentBase::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("Author")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Author")];
        if(!fieldValue.is_null())
        {
           setAuthor(ModelBase::stringFromJson(fieldValue));
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
            setRangeEnd( newItem );
        }
    }


    if(val.has_field(_XPLATSTR("RangeStart")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("RangeStart")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<DocumentPosition> newItem(new DocumentPosition());
            newItem->fromJson(fieldValue);
            setRangeStart( newItem );
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

void CommentBase::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_AuthorIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Author"), m_Author));
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

void CommentBase::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

utility::string_t CommentBase::getAuthor() const
{
    return m_Author;
}


void CommentBase::setAuthor(utility::string_t value)
{
    m_Author = value;
    m_AuthorIsSet = true;
}

bool CommentBase::authorIsSet() const
{
    return m_AuthorIsSet;
}

void CommentBase::unsetAuthor()
{
    m_AuthorIsSet = false;
}

utility::datetime CommentBase::getDateTime() const
{
    return m_DateTime;
}


void CommentBase::setDateTime(utility::datetime value)
{
    m_DateTime = value;
    m_DateTimeIsSet = true;
}

bool CommentBase::dateTimeIsSet() const
{
    return m_DateTimeIsSet;
}

void CommentBase::unsetDateTime()
{
    m_DateTimeIsSet = false;
}

utility::string_t CommentBase::getInitial() const
{
    return m_Initial;
}


void CommentBase::setInitial(utility::string_t value)
{
    m_Initial = value;
    m_InitialIsSet = true;
}

bool CommentBase::initialIsSet() const
{
    return m_InitialIsSet;
}

void CommentBase::unsetInitial()
{
    m_InitialIsSet = false;
}

std::shared_ptr<DocumentPosition> CommentBase::getRangeEnd() const
{
    return m_RangeEnd;
}


void CommentBase::setRangeEnd(std::shared_ptr<DocumentPosition> value)
{
    m_RangeEnd = value;
    m_RangeEndIsSet = true;
}

bool CommentBase::rangeEndIsSet() const
{
    return m_RangeEndIsSet;
}

void CommentBase::unsetRangeEnd()
{
    m_RangeEndIsSet = false;
}

std::shared_ptr<DocumentPosition> CommentBase::getRangeStart() const
{
    return m_RangeStart;
}


void CommentBase::setRangeStart(std::shared_ptr<DocumentPosition> value)
{
    m_RangeStart = value;
    m_RangeStartIsSet = true;
}

bool CommentBase::rangeStartIsSet() const
{
    return m_RangeStartIsSet;
}

void CommentBase::unsetRangeStart()
{
    m_RangeStartIsSet = false;
}

utility::string_t CommentBase::getText() const
{
    return m_Text;
}


void CommentBase::setText(utility::string_t value)
{
    m_Text = value;
    m_TextIsSet = true;
}

bool CommentBase::textIsSet() const
{
    return m_TextIsSet;
}

void CommentBase::unsetText()
{
    m_TextIsSet = false;
}

}
}
}
}
}
