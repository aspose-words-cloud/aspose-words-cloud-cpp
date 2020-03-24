/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="EpubSaveOptionsData.cpp">
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


#include "EpubSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

EpubSaveOptionsData::EpubSaveOptionsData()
{
    m_EpubNavigationMapLevel = 0;
    m_EpubNavigationMapLevelIsSet = false;
}

EpubSaveOptionsData::~EpubSaveOptionsData()
{
}

void EpubSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value EpubSaveOptionsData::toJson() const
{
    web::json::value val = this->HtmlSaveOptionsData::toJson();

    if(m_EpubNavigationMapLevelIsSet)
    {
        val[_XPLATSTR("EpubNavigationMapLevel")] = ModelBase::toJson(m_EpubNavigationMapLevel);
    }

    return val;
}

void EpubSaveOptionsData::fromJson(web::json::value& val)
{
    this->HtmlSaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("EpubNavigationMapLevel")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("EpubNavigationMapLevel")];
        if(!fieldValue.is_null())
        {
            setEpubNavigationMapLevel(ModelBase::int32_tFromJson(fieldValue));
        }
    }
}

void EpubSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    HtmlSaveOptionsData::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_EpubNavigationMapLevelIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("EpubNavigationMapLevel"), m_EpubNavigationMapLevel));
        
    }
}

void EpubSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    HtmlSaveOptionsData::fromMultiPart(multipart, prefix);

    if(multipart->hasContent(_XPLATSTR("EpubNavigationMapLevel")))
    {
        setEpubNavigationMapLevel(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("EpubNavigationMapLevel"))));
    }
}

int32_t EpubSaveOptionsData::getEpubNavigationMapLevel() const
{
    return m_EpubNavigationMapLevel;
}


void EpubSaveOptionsData::setEpubNavigationMapLevel(int32_t value)
{
    m_EpubNavigationMapLevel = value;
    m_EpubNavigationMapLevelIsSet = true;
}
bool EpubSaveOptionsData::epubNavigationMapLevelIsSet() const
{
    return m_EpubNavigationMapLevelIsSet;
}

void EpubSaveOptionsData::unsetEpubNavigationMapLevel()
{
    m_EpubNavigationMapLevelIsSet = false;
}

}
}
}
}
}

