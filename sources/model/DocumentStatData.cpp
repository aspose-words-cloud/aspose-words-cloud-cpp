/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DocumentStatData.cpp">
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


#include "DocumentStatData.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

DocumentStatData::DocumentStatData()
{
    m_WordCount = 0;
    m_ParagraphCount = 0;
    m_PageCount = 0;
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

    val[utility::conversions::to_string_t("WordCount")] = ModelBase::toJson(m_WordCount);
    val[utility::conversions::to_string_t("ParagraphCount")] = ModelBase::toJson(m_ParagraphCount);
    val[utility::conversions::to_string_t("PageCount")] = ModelBase::toJson(m_PageCount);
    if(m_FootnotesStatDataIsSet)
    {
        val[utility::conversions::to_string_t("FootnotesStatData")] = ModelBase::toJson(m_FootnotesStatData);
    }
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_PageStatData.begin(), m_PageStatData.end(), std::back_inserter(jsonArray),
			[&](std::shared_ptr<PageStatData> item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[utility::conversions::to_string_t("PageStatData")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void DocumentStatData::fromJson(web::json::value& val)
{
    if(val.has_field(utility::conversions::to_string_t("WordCount")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("WordCount")];
        if(!fieldValue.is_null())
        {
            setWordCount(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("ParagraphCount")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("ParagraphCount")];
        if(!fieldValue.is_null())
        {
            setParagraphCount(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("PageCount")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("PageCount")];
        if(!fieldValue.is_null())
        {
            setPageCount(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("FootnotesStatData")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("FootnotesStatData")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<FootnotesStatData> newItem(new FootnotesStatData());
            newItem->fromJson(fieldValue);
            setFootnotesStatData( newItem );
        }
    }
    {
        m_PageStatData.clear();
        if(val.has_field(utility::conversions::to_string_t("PageStatData")) 
                            && !val[utility::conversions::to_string_t("PageStatData")].is_null())
        {
        auto arr = val[utility::conversions::to_string_t("PageStatData")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_PageStatData), [&](std::shared_ptr<PageStatData> item){
            if(item.is_null())
            {
                return std::shared_ptr<PageStatData>(nullptr);
            }
            else
            {
                std::shared_ptr<PageStatData> newItem(new PageStatData());
                newItem->fromJson(item);
                return newItem;
            }
        });

        }
    }
}

void DocumentStatData::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("WordCount"), m_WordCount));
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("ParagraphCount"), m_ParagraphCount));
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("PageCount"), m_PageCount));
    if(m_FootnotesStatDataIsSet)
    {
        if (m_FootnotesStatData.get())
        {
            m_FootnotesStatData->toMultipart(multipart, utility::conversions::to_string_t("FootnotesStatData."));
        }
        
    }
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_PageStatData.begin(), m_PageStatData.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<PageStatData> item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("PageStatData"), web::json::value::array(jsonArray), utility::conversions::to_string_t("application/json")));
        }
    }
}

void DocumentStatData::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    setWordCount(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("WordCount"))));
    setParagraphCount(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("ParagraphCount"))));
    setPageCount(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("PageCount"))));
    if(multipart->hasContent(utility::conversions::to_string_t("FootnotesStatData")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("FootnotesStatData")))
        {
            std::shared_ptr<FootnotesStatData> newItem(new FootnotesStatData());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("FootnotesStatData."));
            setFootnotesStatData( newItem );
        }
    }
    {
        m_PageStatData.clear();
        if(multipart->hasContent(utility::conversions::to_string_t("PageStatData")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("PageStatData")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_PageStatData), [&](std::shared_ptr<PageStatData> item) {
            if(item.is_null())
            {
                return std::shared_ptr<PageStatData>(nullptr) ;
            }
            else
            {
                std::shared_ptr<PageStatData> newItem(new PageStatData());
                newItem->fromJson(item);
                return newItem ;
            }
        });
        }
    }
}

int32_t DocumentStatData::getWordCount() const
{
    return m_WordCount;
}


void DocumentStatData::setWordCount(int32_t value)
{
    m_WordCount = value;
    
}
int32_t DocumentStatData::getParagraphCount() const
{
    return m_ParagraphCount;
}


void DocumentStatData::setParagraphCount(int32_t value)
{
    m_ParagraphCount = value;
    
}
int32_t DocumentStatData::getPageCount() const
{
    return m_PageCount;
}


void DocumentStatData::setPageCount(int32_t value)
{
    m_PageCount = value;
    
}
std::shared_ptr<FootnotesStatData> DocumentStatData::getFootnotesStatData() const
{
    return m_FootnotesStatData;
}


void DocumentStatData::setFootnotesStatData(std::shared_ptr<FootnotesStatData> value)
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

std::vector<std::shared_ptr<PageStatData>>& DocumentStatData::getPageStatData()
{
    return m_PageStatData;
}

void DocumentStatData::setPageStatData(std::vector<std::shared_ptr<PageStatData>> const& value)
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

