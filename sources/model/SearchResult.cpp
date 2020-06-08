/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SearchResult.cpp">
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


#include "SearchResult.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

SearchResult::SearchResult()
{
    m_RangeStartIsSet = false;
    m_RangeEndIsSet = false;
}

SearchResult::~SearchResult()
{
}

void SearchResult::validate()
{
    // TODO: implement validation
}

web::json::value SearchResult::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_RangeStartIsSet)
    {
        val[_XPLATSTR("RangeStart")] = ModelBase::toJson(m_RangeStart);
    }
    if(m_RangeEndIsSet)
    {
        val[_XPLATSTR("RangeEnd")] = ModelBase::toJson(m_RangeEnd);
    }

    return val;
}

void SearchResult::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("RangeStart")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("RangeStart")];
        if(!fieldValue.is_null())
        {
            <DATA_TYPE_START>DocumentPosition<DATA_TYPE_END> newItem(new DocumentPosition());
            newItem->fromJson(fieldValue);
            setRangeStart( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("RangeEnd")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("RangeEnd")];
        if(!fieldValue.is_null())
        {
            <DATA_TYPE_START>DocumentPosition<DATA_TYPE_END> newItem(new DocumentPosition());
            newItem->fromJson(fieldValue);
            setRangeEnd( newItem );
        }
    }
}

void SearchResult::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_RangeStartIsSet)
    {
        if (m_RangeStart.get())
        {
            m_RangeStart->toMultipart(multipart, _XPLATSTR("RangeStart."));
        }
        
    }
    if(m_RangeEndIsSet)
    {
        if (m_RangeEnd.get())
        {
            m_RangeEnd->toMultipart(multipart, _XPLATSTR("RangeEnd."));
        }
        
    }
}

void SearchResult::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    

    if(multipart->hasContent(_XPLATSTR("RangeStart")))
    {
        if(multipart->hasContent(_XPLATSTR("RangeStart")))
        {
            <DATA_TYPE_START>DocumentPosition<DATA_TYPE_END> newItem(new DocumentPosition());
            newItem->fromMultiPart(multipart, _XPLATSTR("RangeStart."));
            setRangeStart( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("RangeEnd")))
    {
        if(multipart->hasContent(_XPLATSTR("RangeEnd")))
        {
            <DATA_TYPE_START>DocumentPosition<DATA_TYPE_END> newItem(new DocumentPosition());
            newItem->fromMultiPart(multipart, _XPLATSTR("RangeEnd."));
            setRangeEnd( newItem );
        }
    }
}

<DATA_TYPE_START>DocumentPosition<DATA_TYPE_END> SearchResult::getRangeStart() const
{
    return m_RangeStart;
}


void SearchResult::setRangeStart(<DATA_TYPE_START>DocumentPosition<DATA_TYPE_END> value)
{
    m_RangeStart = value;
    m_RangeStartIsSet = true;
}
bool SearchResult::rangeStartIsSet() const
{
    return m_RangeStartIsSet;
}

void SearchResult::unsetRangeStart()
{
    m_RangeStartIsSet = false;
}

<DATA_TYPE_START>DocumentPosition<DATA_TYPE_END> SearchResult::getRangeEnd() const
{
    return m_RangeEnd;
}


void SearchResult::setRangeEnd(<DATA_TYPE_START>DocumentPosition<DATA_TYPE_END> value)
{
    m_RangeEnd = value;
    m_RangeEndIsSet = true;
}
bool SearchResult::rangeEndIsSet() const
{
    return m_RangeEndIsSet;
}

void SearchResult::unsetRangeEnd()
{
    m_RangeEndIsSet = false;
}

}
}
}
}
}

