/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FootnotesStatData.cpp">
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


#include "FootnotesStatData.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

FootnotesStatData::FootnotesStatData()
{
    m_WordCount = 0;
    m_ParagraphCount = 0;
}

FootnotesStatData::~FootnotesStatData()
{
}

void FootnotesStatData::validate()
{
    // TODO: implement validation
}

web::json::value FootnotesStatData::toJson() const
{
    web::json::value val = web::json::value::object();

    val[utility::conversions::to_string_t("WordCount")] = ModelBase::toJson(m_WordCount);
    val[utility::conversions::to_string_t("ParagraphCount")] = ModelBase::toJson(m_ParagraphCount);

    return val;
}

void FootnotesStatData::fromJson(web::json::value& val)
{
    setWordCount(ModelBase::int32_tFromJson(val[utility::conversions::to_string_t("WordCount")]));
    setParagraphCount(ModelBase::int32_tFromJson(val[utility::conversions::to_string_t("ParagraphCount")]));
}

void FootnotesStatData::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("WordCount"), m_WordCount));
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("ParagraphCount"), m_ParagraphCount));
}

void FootnotesStatData::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    setWordCount(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("WordCount"))));
    setParagraphCount(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("ParagraphCount"))));
}

int32_t FootnotesStatData::getWordCount() const
{
    return m_WordCount;
}


void FootnotesStatData::setWordCount(int32_t value)
{
    m_WordCount = value;
    
}
int32_t FootnotesStatData::getParagraphCount() const
{
    return m_ParagraphCount;
}


void FootnotesStatData::setParagraphCount(int32_t value)
{
    m_ParagraphCount = value;
    
}
}
}
}
}

