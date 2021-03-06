/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FootnotesStatData.cpp">
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

#include "FootnotesStatData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

FootnotesStatData::FootnotesStatData()
{
    m_ParagraphCount = 0;
    m_ParagraphCountIsSet = false;
    m_WordCount = 0;
    m_WordCountIsSet = false;

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
    if(m_ParagraphCountIsSet)
    {
        val[_XPLATSTR("ParagraphCount")] = ModelBase::toJson(m_ParagraphCount);
    }
    if(m_WordCountIsSet)
    {
        val[_XPLATSTR("WordCount")] = ModelBase::toJson(m_WordCount);
    }

    return val;
}

void FootnotesStatData::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("ParagraphCount")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ParagraphCount")];
        if(!fieldValue.is_null())
        {
           setParagraphCount(ModelBase::integerFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("WordCount")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("WordCount")];
        if(!fieldValue.is_null())
        {
           setWordCount(ModelBase::integerFromJson(fieldValue));
        }
    }

}

void FootnotesStatData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_ParagraphCountIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ParagraphCount"), m_ParagraphCount));
    }


    if(m_WordCountIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("WordCount"), m_WordCount));
    }

}

void FootnotesStatData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

int32_t FootnotesStatData::getParagraphCount() const
{
    return m_ParagraphCount;
}


void FootnotesStatData::setParagraphCount(int32_t value)
{
    m_ParagraphCount = value;
    m_ParagraphCountIsSet = true;
}

bool FootnotesStatData::paragraphCountIsSet() const
{
    return m_ParagraphCountIsSet;
}

void FootnotesStatData::unsetParagraphCount()
{
    m_ParagraphCountIsSet = false;
}

int32_t FootnotesStatData::getWordCount() const
{
    return m_WordCount;
}


void FootnotesStatData::setWordCount(int32_t value)
{
    m_WordCount = value;
    m_WordCountIsSet = true;
}

bool FootnotesStatData::wordCountIsSet() const
{
    return m_WordCountIsSet;
}

void FootnotesStatData::unsetWordCount()
{
    m_WordCountIsSet = false;
}

}
}
}
}
}
