/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PageStatData.cpp">
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


#include "PageStatData.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

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

    val[_XPLATSTR("PageNumber")] = ModelBase::toJson(m_PageNumber);
    val[_XPLATSTR("WordCount")] = ModelBase::toJson(m_WordCount);
    val[_XPLATSTR("ParagraphCount")] = ModelBase::toJson(m_ParagraphCount);
    if(m_FootnotesStatDataIsSet)
    {
        val[_XPLATSTR("FootnotesStatData")] = ModelBase::toJson(m_FootnotesStatData);
    }

    return val;
}

void PageStatData::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("PageNumber")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("PageNumber")];
        if(!fieldValue.is_null())
        {
            setPageNumber(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("WordCount")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("WordCount")];
        if(!fieldValue.is_null())
        {
            setWordCount(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ParagraphCount")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ParagraphCount")];
        if(!fieldValue.is_null())
        {
            setParagraphCount(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("FootnotesStatData")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("FootnotesStatData")];
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

    multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("PageNumber"), m_PageNumber));
    multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("WordCount"), m_WordCount));
    multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ParagraphCount"), m_ParagraphCount));
    if(m_FootnotesStatDataIsSet)
    {
        if (m_FootnotesStatData.get())
        {
            m_FootnotesStatData->toMultipart(multipart, _XPLATSTR("FootnotesStatData."));
        }
        
    }
}

void PageStatData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    setPageNumber(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("PageNumber"))));
    setWordCount(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("WordCount"))));
    setParagraphCount(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("ParagraphCount"))));
    if(multipart->hasContent(_XPLATSTR("FootnotesStatData")))
    {
        if(multipart->hasContent(_XPLATSTR("FootnotesStatData")))
        {
            std::shared_ptr<FootnotesStatData> newItem(new FootnotesStatData());
            newItem->fromMultiPart(multipart, _XPLATSTR("FootnotesStatData."));
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

