/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="CsvDataLoadOptions.cpp">
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

#include "CsvDataLoadOptions.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

CsvDataLoadOptions::CsvDataLoadOptions()
{
    m_CommentChar = utility::conversions::to_string_t("");
    m_CommentCharIsSet = false;
    m_Delimiter = utility::conversions::to_string_t("");
    m_DelimiterIsSet = false;
    m_HasHeaders = false;
    m_HasHeadersIsSet = false;
    m_QuoteChar = utility::conversions::to_string_t("");
    m_QuoteCharIsSet = false;

}

CsvDataLoadOptions::~CsvDataLoadOptions()
{
}

void CsvDataLoadOptions::validate()
{
    // TODO: implement validation
}

web::json::value CsvDataLoadOptions::toJson() const
{
    web::json::value val = web::json::value::object();
    if(m_CommentCharIsSet)
    {
        val[_XPLATSTR("CommentChar")] = ModelBase::toJson(m_CommentChar);
    }
    if(m_DelimiterIsSet)
    {
        val[_XPLATSTR("Delimiter")] = ModelBase::toJson(m_Delimiter);
    }
    if(m_HasHeadersIsSet)
    {
        val[_XPLATSTR("HasHeaders")] = ModelBase::toJson(m_HasHeaders);
    }
    if(m_QuoteCharIsSet)
    {
        val[_XPLATSTR("QuoteChar")] = ModelBase::toJson(m_QuoteChar);
    }

    return val;
}

void CsvDataLoadOptions::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("CommentChar")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("CommentChar")];
        if(!fieldValue.is_null())
        {
           setCommentChar(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("Delimiter")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Delimiter")];
        if(!fieldValue.is_null())
        {
           setDelimiter(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("HasHeaders")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("HasHeaders")];
        if(!fieldValue.is_null())
        {
           setHasHeaders(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("QuoteChar")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("QuoteChar")];
        if(!fieldValue.is_null())
        {
           setQuoteChar(ModelBase::stringFromJson(fieldValue));
        }
    }

}

void CsvDataLoadOptions::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_CommentCharIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("CommentChar"), m_CommentChar));
    }


    if(m_DelimiterIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Delimiter"), m_Delimiter));
    }


    if(m_HasHeadersIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("HasHeaders"), m_HasHeaders));
    }


    if(m_QuoteCharIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("QuoteChar"), m_QuoteChar));
    }

}

void CsvDataLoadOptions::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

utility::string_t CsvDataLoadOptions::getCommentChar() const
{
    return m_CommentChar;
}


void CsvDataLoadOptions::setCommentChar(utility::string_t value)
{
    m_CommentChar = value;
    m_CommentCharIsSet = true;
}

bool CsvDataLoadOptions::commentCharIsSet() const
{
    return m_CommentCharIsSet;
}

void CsvDataLoadOptions::unsetCommentChar()
{
    m_CommentCharIsSet = false;
}

utility::string_t CsvDataLoadOptions::getDelimiter() const
{
    return m_Delimiter;
}


void CsvDataLoadOptions::setDelimiter(utility::string_t value)
{
    m_Delimiter = value;
    m_DelimiterIsSet = true;
}

bool CsvDataLoadOptions::delimiterIsSet() const
{
    return m_DelimiterIsSet;
}

void CsvDataLoadOptions::unsetDelimiter()
{
    m_DelimiterIsSet = false;
}

bool CsvDataLoadOptions::isHasHeaders() const
{
    return m_HasHeaders;
}


void CsvDataLoadOptions::setHasHeaders(bool value)
{
    m_HasHeaders = value;
    m_HasHeadersIsSet = true;
}

bool CsvDataLoadOptions::hasHeadersIsSet() const
{
    return m_HasHeadersIsSet;
}

void CsvDataLoadOptions::unsetHasHeaders()
{
    m_HasHeadersIsSet = false;
}

utility::string_t CsvDataLoadOptions::getQuoteChar() const
{
    return m_QuoteChar;
}


void CsvDataLoadOptions::setQuoteChar(utility::string_t value)
{
    m_QuoteChar = value;
    m_QuoteCharIsSet = true;
}

bool CsvDataLoadOptions::quoteCharIsSet() const
{
    return m_QuoteCharIsSet;
}

void CsvDataLoadOptions::unsetQuoteChar()
{
    m_QuoteCharIsSet = false;
}

}
}
}
}
}
