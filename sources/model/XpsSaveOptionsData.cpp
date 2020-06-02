/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="XpsSaveOptionsData.cpp">
*   Copyright (c) 2020 Aspose.Words for Cloud
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

#include "XpsSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

XpsSaveOptionsData::XpsSaveOptionsData()
{
    m_BookmarksOutlineLevel = 0;
    m_BookmarksOutlineLevelIsSet = false;
    m_HeadingsOutlineLevels = 0;
    m_HeadingsOutlineLevelsIsSet = false;

    m_OutlineOptionsIsSet = false;
    m_UseBookFoldPrintingSettings = false;
    m_UseBookFoldPrintingSettingsIsSet = false;

}

XpsSaveOptionsData::~XpsSaveOptionsData()
{
}

void XpsSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value XpsSaveOptionsData::toJson() const
{
    web::json::value val = this->FixedPageSaveOptionsData::toJson();
    if(m_BookmarksOutlineLevelIsSet)
    {
        val[_XPLATSTR("BookmarksOutlineLevel")] = ModelBase::toJson(m_BookmarksOutlineLevel);
    }
    if(m_HeadingsOutlineLevelsIsSet)
    {
        val[_XPLATSTR("HeadingsOutlineLevels")] = ModelBase::toJson(m_HeadingsOutlineLevels);
    }
    if(m_OutlineOptionsIsSet)
    {
        val[_XPLATSTR("OutlineOptions")] = ModelBase::toJson(m_OutlineOptions);
    }
    if(m_UseBookFoldPrintingSettingsIsSet)
    {
        val[_XPLATSTR("UseBookFoldPrintingSettings")] = ModelBase::toJson(m_UseBookFoldPrintingSettings);
    }

    return val;
}

void XpsSaveOptionsData::fromJson(web::json::value& val)
{
    this->FixedPageSaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("BookmarksOutlineLevel")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("BookmarksOutlineLevel")];
        if(!fieldValue.is_null())
        {
           setBookmarksOutlineLevel(ModelBase::integerFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("HeadingsOutlineLevels")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("HeadingsOutlineLevels")];
        if(!fieldValue.is_null())
        {
           setHeadingsOutlineLevels(ModelBase::integerFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("OutlineOptions")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("OutlineOptions")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<OutlineOptionsData> newItem(new OutlineOptionsData());
            newItem->fromJson(fieldValue);
        }
    }


    if(val.has_field(_XPLATSTR("UseBookFoldPrintingSettings")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("UseBookFoldPrintingSettings")];
        if(!fieldValue.is_null())
        {
           setUseBookFoldPrintingSettings(ModelBase::booleanFromJson(fieldValue));
        }
    }

}

void XpsSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    FixedPageSaveOptionsData::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_BookmarksOutlineLevelIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("BookmarksOutlineLevel"), m_BookmarksOutlineLevel));
    }


    if(m_HeadingsOutlineLevelsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("HeadingsOutlineLevels"), m_HeadingsOutlineLevels));
    }


    if(m_OutlineOptionsIsSet)
    {
        if (m_OutlineOptions.get())
        {
            m_OutlineOptions->toMultipart(multipart, _XPLATSTR("OutlineOptions."));
        }
    }


    if(m_UseBookFoldPrintingSettingsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("UseBookFoldPrintingSettings"), m_UseBookFoldPrintingSettings));
    }

}

void XpsSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

int32_t XpsSaveOptionsData::getBookmarksOutlineLevel() const
{
    return m_BookmarksOutlineLevel;
}


void XpsSaveOptionsData::setBookmarksOutlineLevel(int32_t value)
{
    m_BookmarksOutlineLevel = value;
    m_BookmarksOutlineLevelIsSet = true;
}

bool XpsSaveOptionsData::bookmarksOutlineLevelIsSet() const
{
    return m_BookmarksOutlineLevelIsSet;
}

void XpsSaveOptionsData::unsetBookmarksOutlineLevel()
{
    m_BookmarksOutlineLevelIsSet = false;
}

int32_t XpsSaveOptionsData::getHeadingsOutlineLevels() const
{
    return m_HeadingsOutlineLevels;
}


void XpsSaveOptionsData::setHeadingsOutlineLevels(int32_t value)
{
    m_HeadingsOutlineLevels = value;
    m_HeadingsOutlineLevelsIsSet = true;
}

bool XpsSaveOptionsData::headingsOutlineLevelsIsSet() const
{
    return m_HeadingsOutlineLevelsIsSet;
}

void XpsSaveOptionsData::unsetHeadingsOutlineLevels()
{
    m_HeadingsOutlineLevelsIsSet = false;
}

std::shared_ptr<OutlineOptionsData> XpsSaveOptionsData::getOutlineOptions() const
{
    return m_OutlineOptions;
}


void XpsSaveOptionsData::setOutlineOptions(std::shared_ptr<OutlineOptionsData> value)
{
    m_OutlineOptions = value;
    m_OutlineOptionsIsSet = true;
}

bool XpsSaveOptionsData::outlineOptionsIsSet() const
{
    return m_OutlineOptionsIsSet;
}

void XpsSaveOptionsData::unsetOutlineOptions()
{
    m_OutlineOptionsIsSet = false;
}

bool XpsSaveOptionsData::isUseBookFoldPrintingSettings() const
{
    return m_UseBookFoldPrintingSettings;
}


void XpsSaveOptionsData::setUseBookFoldPrintingSettings(bool value)
{
    m_UseBookFoldPrintingSettings = value;
    m_UseBookFoldPrintingSettingsIsSet = true;
}

bool XpsSaveOptionsData::useBookFoldPrintingSettingsIsSet() const
{
    return m_UseBookFoldPrintingSettingsIsSet;
}

void XpsSaveOptionsData::unsetUseBookFoldPrintingSettings()
{
    m_UseBookFoldPrintingSettingsIsSet = false;
}

}
}
}
}
}
