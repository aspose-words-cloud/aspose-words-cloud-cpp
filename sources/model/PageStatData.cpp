/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PageStatData.cpp">
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


#include "PageStatData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

PageStatData::PageStatData()
{
    m_PageNumber = 0;
    m_WordCount = 0;
    m_ParagraphCount = 0;
    m_FootnotesStatDataIsSet = false;
}

PageStatData::~PageStatData()
{
}

void PageStatData::validate()
{
    // TODO: implement validation
}

web::json::value PageStatData::toJson() const
{
    web::json::value val = web::json::value::object();

    val[_XPLATSTR("pageNumber")] = ModelBase::toJson(m_PageNumber);
    val[_XPLATSTR("wordCount")] = ModelBase::toJson(m_WordCount);
    val[_XPLATSTR("paragraphCount")] = ModelBase::toJson(m_ParagraphCount);
    if(m_FootnotesStatDataIsSet)
    {
        val[_XPLATSTR("footnotesStatData")] = ModelBase::toJson(m_FootnotesStatData);
    }

    return val;
}

void PageStatData::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("pageNumber")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("pageNumber")];
        if(!fieldValue.is_null())
        {
            setPageNumber(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("wordCount")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("wordCount")];
        if(!fieldValue.is_null())
        {
            setWordCount(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("paragraphCount")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("paragraphCount")];
        if(!fieldValue.is_null())
        {
            setParagraphCount(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("footnotesStatData")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("footnotesStatData")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<FootnotesStatData> newItem(new FootnotesStatData());
            newItem->fromJson(fieldValue);
            setFootnotesStatData( newItem );
        }
    }
}

void PageStatData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("pageNumber"), m_PageNumber));
    multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("wordCount"), m_WordCount));
    multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("paragraphCount"), m_ParagraphCount));
    if(m_FootnotesStatDataIsSet)
    {
        if (m_FootnotesStatData.get())
        {
            m_FootnotesStatData->toMultipart(multipart, _XPLATSTR("footnotesStatData."));
        }
        
    }
}

void PageStatData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    setPageNumber(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("pageNumber"))));
    setWordCount(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("wordCount"))));
    setParagraphCount(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("paragraphCount"))));
    if(multipart->hasContent(_XPLATSTR("footnotesStatData")))
    {
        if(multipart->hasContent(_XPLATSTR("footnotesStatData")))
        {
            std::shared_ptr<FootnotesStatData> newItem(new FootnotesStatData());
            newItem->fromMultiPart(multipart, _XPLATSTR("footnotesStatData."));
            setFootnotesStatData( newItem );
        }
    }
}

int32_t PageStatData::getPageNumber() const
{
    return m_PageNumber;
}


void PageStatData::setPageNumber(int32_t value)
{
    m_PageNumber = value;
    
}
int32_t PageStatData::getWordCount() const
{
    return m_WordCount;
}


void PageStatData::setWordCount(int32_t value)
{
    m_WordCount = value;
    
}
int32_t PageStatData::getParagraphCount() const
{
    return m_ParagraphCount;
}


void PageStatData::setParagraphCount(int32_t value)
{
    m_ParagraphCount = value;
    
}
std::shared_ptr<FootnotesStatData> PageStatData::getFootnotesStatData() const
{
    return m_FootnotesStatData;
}


void PageStatData::setFootnotesStatData(std::shared_ptr<FootnotesStatData> value)
{
    m_FootnotesStatData = value;
    m_FootnotesStatDataIsSet = true;
}
bool PageStatData::footnotesStatDataIsSet() const
{
    return m_FootnotesStatDataIsSet;
}

void PageStatData::unsetFootnotesStatData()
{
    m_FootnotesStatDataIsSet = false;
}

}
}
}
}
}

