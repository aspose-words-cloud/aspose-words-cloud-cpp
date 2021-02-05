/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="OutlineOptionsData.cpp">
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

#include "OutlineOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

OutlineOptionsData::OutlineOptionsData()
{
    m_BookmarksOutlineLevelsIsSet = false;
    m_CreateMissingOutlineLevels = false;
    m_CreateMissingOutlineLevelsIsSet = false;
    m_CreateOutlinesForHeadingsInTables = false;
    m_CreateOutlinesForHeadingsInTablesIsSet = false;
    m_DefaultBookmarksOutlineLevel = 0;
    m_DefaultBookmarksOutlineLevelIsSet = false;
    m_ExpandedOutlineLevels = 0;
    m_ExpandedOutlineLevelsIsSet = false;
    m_HeadingsOutlineLevels = 0;
    m_HeadingsOutlineLevelsIsSet = false;

}

OutlineOptionsData::~OutlineOptionsData()
{
}

void OutlineOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value OutlineOptionsData::toJson() const
{
    web::json::value val = web::json::value::object();
    if(m_BookmarksOutlineLevelsIsSet)
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_BookmarksOutlineLevels.begin(), m_BookmarksOutlineLevels.end(), std::back_inserter(jsonArray),
            [&](std::shared_ptr<BookmarksOutlineLevelData> item) {
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("BookmarksOutlineLevels")] = web::json::value::array(jsonArray);
        }
    }
    if(m_CreateMissingOutlineLevelsIsSet)
    {
        val[_XPLATSTR("CreateMissingOutlineLevels")] = ModelBase::toJson(m_CreateMissingOutlineLevels);
    }
    if(m_CreateOutlinesForHeadingsInTablesIsSet)
    {
        val[_XPLATSTR("CreateOutlinesForHeadingsInTables")] = ModelBase::toJson(m_CreateOutlinesForHeadingsInTables);
    }
    if(m_DefaultBookmarksOutlineLevelIsSet)
    {
        val[_XPLATSTR("DefaultBookmarksOutlineLevel")] = ModelBase::toJson(m_DefaultBookmarksOutlineLevel);
    }
    if(m_ExpandedOutlineLevelsIsSet)
    {
        val[_XPLATSTR("ExpandedOutlineLevels")] = ModelBase::toJson(m_ExpandedOutlineLevels);
    }
    if(m_HeadingsOutlineLevelsIsSet)
    {
        val[_XPLATSTR("HeadingsOutlineLevels")] = ModelBase::toJson(m_HeadingsOutlineLevels);
    }

    return val;
}

void OutlineOptionsData::fromJson(web::json::value& val)
{
    {
        m_BookmarksOutlineLevels.clear();
        if(val.has_field(_XPLATSTR("BookmarksOutlineLevels")) 
                            && !val[_XPLATSTR("BookmarksOutlineLevels")].is_null())
        {
            auto arr = val[_XPLATSTR("BookmarksOutlineLevels")].as_array();
            std::transform(arr.begin(), arr.end(), std::back_inserter(m_BookmarksOutlineLevels), [&](web::json::value& item){
                if(!item.is_null())
                {
                    std::shared_ptr<BookmarksOutlineLevelData> newItem(new BookmarksOutlineLevelData());
                    newItem->fromJson(item);
                    return newItem;
                }

                return (std::shared_ptr<BookmarksOutlineLevelData>)nullptr;
            });
        }
    }


    if(val.has_field(_XPLATSTR("CreateMissingOutlineLevels")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("CreateMissingOutlineLevels")];
        if(!fieldValue.is_null())
        {
           setCreateMissingOutlineLevels(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("CreateOutlinesForHeadingsInTables")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("CreateOutlinesForHeadingsInTables")];
        if(!fieldValue.is_null())
        {
           setCreateOutlinesForHeadingsInTables(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("DefaultBookmarksOutlineLevel")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DefaultBookmarksOutlineLevel")];
        if(!fieldValue.is_null())
        {
           setDefaultBookmarksOutlineLevel(ModelBase::integerFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("ExpandedOutlineLevels")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExpandedOutlineLevels")];
        if(!fieldValue.is_null())
        {
           setExpandedOutlineLevels(ModelBase::integerFromJson(fieldValue));
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

}

void OutlineOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_BookmarksOutlineLevels.begin(), m_BookmarksOutlineLevels.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<BookmarksOutlineLevelData> item){
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("BookmarksOutlineLevels"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }


    if(m_CreateMissingOutlineLevelsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("CreateMissingOutlineLevels"), m_CreateMissingOutlineLevels));
    }


    if(m_CreateOutlinesForHeadingsInTablesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("CreateOutlinesForHeadingsInTables"), m_CreateOutlinesForHeadingsInTables));
    }


    if(m_DefaultBookmarksOutlineLevelIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("DefaultBookmarksOutlineLevel"), m_DefaultBookmarksOutlineLevel));
    }


    if(m_ExpandedOutlineLevelsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExpandedOutlineLevels"), m_ExpandedOutlineLevels));
    }


    if(m_HeadingsOutlineLevelsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("HeadingsOutlineLevels"), m_HeadingsOutlineLevels));
    }

}

void OutlineOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

std::vector<std::shared_ptr<BookmarksOutlineLevelData>>& OutlineOptionsData::getBookmarksOutlineLevels()
{
    return m_BookmarksOutlineLevels;
}


void OutlineOptionsData::setBookmarksOutlineLevels(std::vector<std::shared_ptr<BookmarksOutlineLevelData>> const& value)
{
    m_BookmarksOutlineLevels = value;
    m_BookmarksOutlineLevelsIsSet = true;
}

bool OutlineOptionsData::bookmarksOutlineLevelsIsSet() const
{
    return m_BookmarksOutlineLevelsIsSet;
}

void OutlineOptionsData::unsetBookmarksOutlineLevels()
{
    m_BookmarksOutlineLevelsIsSet = false;
}

bool OutlineOptionsData::isCreateMissingOutlineLevels() const
{
    return m_CreateMissingOutlineLevels;
}


void OutlineOptionsData::setCreateMissingOutlineLevels(bool value)
{
    m_CreateMissingOutlineLevels = value;
    m_CreateMissingOutlineLevelsIsSet = true;
}

bool OutlineOptionsData::createMissingOutlineLevelsIsSet() const
{
    return m_CreateMissingOutlineLevelsIsSet;
}

void OutlineOptionsData::unsetCreateMissingOutlineLevels()
{
    m_CreateMissingOutlineLevelsIsSet = false;
}

bool OutlineOptionsData::isCreateOutlinesForHeadingsInTables() const
{
    return m_CreateOutlinesForHeadingsInTables;
}


void OutlineOptionsData::setCreateOutlinesForHeadingsInTables(bool value)
{
    m_CreateOutlinesForHeadingsInTables = value;
    m_CreateOutlinesForHeadingsInTablesIsSet = true;
}

bool OutlineOptionsData::createOutlinesForHeadingsInTablesIsSet() const
{
    return m_CreateOutlinesForHeadingsInTablesIsSet;
}

void OutlineOptionsData::unsetCreateOutlinesForHeadingsInTables()
{
    m_CreateOutlinesForHeadingsInTablesIsSet = false;
}

int32_t OutlineOptionsData::getDefaultBookmarksOutlineLevel() const
{
    return m_DefaultBookmarksOutlineLevel;
}


void OutlineOptionsData::setDefaultBookmarksOutlineLevel(int32_t value)
{
    m_DefaultBookmarksOutlineLevel = value;
    m_DefaultBookmarksOutlineLevelIsSet = true;
}

bool OutlineOptionsData::defaultBookmarksOutlineLevelIsSet() const
{
    return m_DefaultBookmarksOutlineLevelIsSet;
}

void OutlineOptionsData::unsetDefaultBookmarksOutlineLevel()
{
    m_DefaultBookmarksOutlineLevelIsSet = false;
}

int32_t OutlineOptionsData::getExpandedOutlineLevels() const
{
    return m_ExpandedOutlineLevels;
}


void OutlineOptionsData::setExpandedOutlineLevels(int32_t value)
{
    m_ExpandedOutlineLevels = value;
    m_ExpandedOutlineLevelsIsSet = true;
}

bool OutlineOptionsData::expandedOutlineLevelsIsSet() const
{
    return m_ExpandedOutlineLevelsIsSet;
}

void OutlineOptionsData::unsetExpandedOutlineLevels()
{
    m_ExpandedOutlineLevelsIsSet = false;
}

int32_t OutlineOptionsData::getHeadingsOutlineLevels() const
{
    return m_HeadingsOutlineLevels;
}


void OutlineOptionsData::setHeadingsOutlineLevels(int32_t value)
{
    m_HeadingsOutlineLevels = value;
    m_HeadingsOutlineLevelsIsSet = true;
}

bool OutlineOptionsData::headingsOutlineLevelsIsSet() const
{
    return m_HeadingsOutlineLevelsIsSet;
}

void OutlineOptionsData::unsetHeadingsOutlineLevels()
{
    m_HeadingsOutlineLevelsIsSet = false;
}

}
}
}
}
}
