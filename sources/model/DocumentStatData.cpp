/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DocumentStatData.cpp">
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


#include "DocumentStatData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

DocumentStatData::DocumentStatData()
{
    m_WordCount = 0;
    m_WordCountIsSet = false;
    m_ParagraphCount = 0;
    m_ParagraphCountIsSet = false;
    m_PageCount = 0;
    m_PageCountIsSet = false;
    m_FootnotesStatDataIsSet = false;
    m_PageStatDataIsSet = false;
}

DocumentStatData::~DocumentStatData()
{
}

void DocumentStatData::validate()
{
    // TODO: implement validation
}

web::json::value DocumentStatData::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_WordCountIsSet)
    {
        val[_XPLATSTR("WordCount")] = ModelBase::toJson(m_WordCount);
    }
    if(m_ParagraphCountIsSet)
    {
        val[_XPLATSTR("ParagraphCount")] = ModelBase::toJson(m_ParagraphCount);
    }
    if(m_PageCountIsSet)
    {
        val[_XPLATSTR("PageCount")] = ModelBase::toJson(m_PageCount);
    }
    if(m_FootnotesStatDataIsSet)
    {
        val[_XPLATSTR("FootnotesStatData")] = ModelBase::toJson(m_FootnotesStatData);
    }
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_PageStatData.begin(), m_PageStatData.end(), std::back_inserter(jsonArray),
			[&](<DATA_TYPE_START>PageStatData<DATA_TYPE_END> item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("PageStatData")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void DocumentStatData::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("WordCount")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("WordCount")];
        if(!fieldValue.is_null())
        {
            setWordCount(ModelBase::int?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ParagraphCount")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ParagraphCount")];
        if(!fieldValue.is_null())
        {
            setParagraphCount(ModelBase::int?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("PageCount")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("PageCount")];
        if(!fieldValue.is_null())
        {
            setPageCount(ModelBase::int?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("FootnotesStatData")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("FootnotesStatData")];
        if(!fieldValue.is_null())
        {
            <DATA_TYPE_START>FootnotesStatData<DATA_TYPE_END> newItem(new FootnotesStatData());
            newItem->fromJson(fieldValue);
            setFootnotesStatData( newItem );
        }
    }
    {
        m_PageStatData.clear();
        if(val.has_field(_XPLATSTR("PageStatData")) 
                            && !val[_XPLATSTR("PageStatData")].is_null())
        {
        auto arr = val[_XPLATSTR("PageStatData")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_PageStatData), [&](web::json::value& item){
            if(item.is_null())
            {
                return <DATA_TYPE_START>PageStatData<DATA_TYPE_END>(nullptr);
            }
            else
            {
                <DATA_TYPE_START>PageStatData<DATA_TYPE_END> newItem(new PageStatData());
                newItem->fromJson(item);
                return newItem;
            }
        });

        }
    }
}

void DocumentStatData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_WordCountIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("WordCount"), m_WordCount));
        
    }
    if(m_ParagraphCountIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ParagraphCount"), m_ParagraphCount));
        
    }
    if(m_PageCountIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("PageCount"), m_PageCount));
        
    }
    if(m_FootnotesStatDataIsSet)
    {
        if (m_FootnotesStatData.get())
        {
            m_FootnotesStatData->toMultipart(multipart, _XPLATSTR("FootnotesStatData."));
        }
        
    }
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_PageStatData.begin(), m_PageStatData.end(), std::back_inserter(jsonArray), [&](<DATA_TYPE_START>PageStatData<DATA_TYPE_END> item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("PageStatData"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }
}

void DocumentStatData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    

    if(multipart->hasContent(_XPLATSTR("WordCount")))
    {
        setWordCount(ModelBase::int?FromHttpContent(multipart->getContent(_XPLATSTR("WordCount"))));
    }
    if(multipart->hasContent(_XPLATSTR("ParagraphCount")))
    {
        setParagraphCount(ModelBase::int?FromHttpContent(multipart->getContent(_XPLATSTR("ParagraphCount"))));
    }
    if(multipart->hasContent(_XPLATSTR("PageCount")))
    {
        setPageCount(ModelBase::int?FromHttpContent(multipart->getContent(_XPLATSTR("PageCount"))));
    }
    if(multipart->hasContent(_XPLATSTR("FootnotesStatData")))
    {
        if(multipart->hasContent(_XPLATSTR("FootnotesStatData")))
        {
            <DATA_TYPE_START>FootnotesStatData<DATA_TYPE_END> newItem(new FootnotesStatData());
            newItem->fromMultiPart(multipart, _XPLATSTR("FootnotesStatData."));
            setFootnotesStatData( newItem );
        }
    }
    {
        m_PageStatData.clear();
        if(multipart->hasContent(_XPLATSTR("PageStatData")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("PageStatData")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_PageStatData), [&](web::json::value item) {
            if(item.is_null())
            {
                return <DATA_TYPE_START>PageStatData<DATA_TYPE_END>(nullptr) ;
            }
            else
            {
                <DATA_TYPE_START>PageStatData<DATA_TYPE_END> newItem(new PageStatData());
                newItem->fromJson(item);
                return newItem ;
            }
        });
        }
    }
}

<DATA_TYPE_START>int?<DATA_TYPE_END> DocumentStatData::getWordCount() const
{
    return m_WordCount;
}


void DocumentStatData::setWordCount(<DATA_TYPE_START>int?<DATA_TYPE_END> value)
{
    m_WordCount = value;
    m_WordCountIsSet = true;
}
bool DocumentStatData::wordCountIsSet() const
{
    return m_WordCountIsSet;
}

void DocumentStatData::unsetWordCount()
{
    m_WordCountIsSet = false;
}

<DATA_TYPE_START>int?<DATA_TYPE_END> DocumentStatData::getParagraphCount() const
{
    return m_ParagraphCount;
}


void DocumentStatData::setParagraphCount(<DATA_TYPE_START>int?<DATA_TYPE_END> value)
{
    m_ParagraphCount = value;
    m_ParagraphCountIsSet = true;
}
bool DocumentStatData::paragraphCountIsSet() const
{
    return m_ParagraphCountIsSet;
}

void DocumentStatData::unsetParagraphCount()
{
    m_ParagraphCountIsSet = false;
}

<DATA_TYPE_START>int?<DATA_TYPE_END> DocumentStatData::getPageCount() const
{
    return m_PageCount;
}


void DocumentStatData::setPageCount(<DATA_TYPE_START>int?<DATA_TYPE_END> value)
{
    m_PageCount = value;
    m_PageCountIsSet = true;
}
bool DocumentStatData::pageCountIsSet() const
{
    return m_PageCountIsSet;
}

void DocumentStatData::unsetPageCount()
{
    m_PageCountIsSet = false;
}

<DATA_TYPE_START>FootnotesStatData<DATA_TYPE_END> DocumentStatData::getFootnotesStatData() const
{
    return m_FootnotesStatData;
}


void DocumentStatData::setFootnotesStatData(<DATA_TYPE_START>FootnotesStatData<DATA_TYPE_END> value)
{
    m_FootnotesStatData = value;
    m_FootnotesStatDataIsSet = true;
}
bool DocumentStatData::footnotesStatDataIsSet() const
{
    return m_FootnotesStatDataIsSet;
}

void DocumentStatData::unsetFootnotesStatData()
{
    m_FootnotesStatDataIsSet = false;
}

<DATA_TYPE_START>List<PageStatData><DATA_TYPE_END>& DocumentStatData::getPageStatData()
{
    return m_PageStatData;
}

void DocumentStatData::setPageStatData(<DATA_TYPE_START>List<PageStatData><DATA_TYPE_END> const& value)
{
    m_PageStatData = value;
    m_PageStatDataIsSet = true;
}
bool DocumentStatData::pageStatDataIsSet() const
{
    return m_PageStatDataIsSet;
}

void DocumentStatData::unsetPageStatData()
{
    m_PageStatDataIsSet = false;
}

}
}
}
}
}

