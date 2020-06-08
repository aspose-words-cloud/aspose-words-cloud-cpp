/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="WordMLSaveOptionsData.cpp">
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


#include "WordMLSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

WordMLSaveOptionsData::WordMLSaveOptionsData()
{
    m_PrettyFormat = false;
    m_PrettyFormatIsSet = false;
}

WordMLSaveOptionsData::~WordMLSaveOptionsData()
{
}

void WordMLSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value WordMLSaveOptionsData::toJson() const
{
    web::json::value val = this->SaveOptionsData::toJson();

    if(m_PrettyFormatIsSet)
    {
        val[_XPLATSTR("PrettyFormat")] = ModelBase::toJson(m_PrettyFormat);
    }

    return val;
}

void WordMLSaveOptionsData::fromJson(web::json::value& val)
{
    this->SaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("PrettyFormat")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("PrettyFormat")];
        if(!fieldValue.is_null())
        {
            setPrettyFormat(ModelBase::bool?FromJson(fieldValue));
        }
    }
}

void WordMLSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    SaveOptionsData::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_PrettyFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("PrettyFormat"), m_PrettyFormat));
        
    }
}

void WordMLSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    SaveOptionsData::fromMultiPart(multipart, prefix);

    if(multipart->hasContent(_XPLATSTR("PrettyFormat")))
    {
        setPrettyFormat(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("PrettyFormat"))));
    }
}

<DATA_TYPE_START>bool?<DATA_TYPE_END> WordMLSaveOptionsData::isPrettyFormat() const
{
    return m_PrettyFormat;
}


void WordMLSaveOptionsData::setPrettyFormat(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
{
    m_PrettyFormat = value;
    m_PrettyFormatIsSet = true;
}
bool WordMLSaveOptionsData::prettyFormatIsSet() const
{
    return m_PrettyFormatIsSet;
}

void WordMLSaveOptionsData::unsetPrettyFormat()
{
    m_PrettyFormatIsSet = false;
}

}
}
}
}
}

