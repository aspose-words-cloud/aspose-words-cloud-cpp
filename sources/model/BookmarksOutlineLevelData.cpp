/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="BookmarksOutlineLevelData.cpp">
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


#include "BookmarksOutlineLevelData.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

BookmarksOutlineLevelData::BookmarksOutlineLevelData()
{
    m_Name = utility::conversions::to_string_t("");
    m_NameIsSet = false;
    m_BookmarksOutlineLevel = 0;
}

BookmarksOutlineLevelData::~BookmarksOutlineLevelData()
{
}

void BookmarksOutlineLevelData::validate()
{
    // TODO: implement validation
}

web::json::value BookmarksOutlineLevelData::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_NameIsSet)
    {
        val[utility::conversions::to_string_t("Name")] = ModelBase::toJson(m_Name);
    }
    val[utility::conversions::to_string_t("BookmarksOutlineLevel")] = ModelBase::toJson(m_BookmarksOutlineLevel);

    return val;
}

void BookmarksOutlineLevelData::fromJson(web::json::value& val)
{
    if(val.has_field(utility::conversions::to_string_t("Name")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Name")];
        if(!fieldValue.is_null())
        {
            setName(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("BookmarksOutlineLevel")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("BookmarksOutlineLevel")];
        if(!fieldValue.is_null())
        {
            setBookmarksOutlineLevel(ModelBase::int32_tFromJson(fieldValue));
        }
    }
}

void BookmarksOutlineLevelData::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_NameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Name"), m_Name));
        
    }
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("BookmarksOutlineLevel"), m_BookmarksOutlineLevel));
}

void BookmarksOutlineLevelData::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("Name")))
    {
        setName(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Name"))));
    }
    setBookmarksOutlineLevel(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("BookmarksOutlineLevel"))));
}

utility::string_t BookmarksOutlineLevelData::getName() const
{
    return m_Name;
}


void BookmarksOutlineLevelData::setName(utility::string_t value)
{
    m_Name = value;
    m_NameIsSet = true;
}
bool BookmarksOutlineLevelData::nameIsSet() const
{
    return m_NameIsSet;
}

void BookmarksOutlineLevelData::unsetName()
{
    m_NameIsSet = false;
}

int32_t BookmarksOutlineLevelData::getBookmarksOutlineLevel() const
{
    return m_BookmarksOutlineLevel;
}


void BookmarksOutlineLevelData::setBookmarksOutlineLevel(int32_t value)
{
    m_BookmarksOutlineLevel = value;
    
}
}
}
}
}

