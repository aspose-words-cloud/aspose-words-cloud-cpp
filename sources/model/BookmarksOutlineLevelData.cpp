/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="BookmarksOutlineLevelData.cpp">
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


#include "BookmarksOutlineLevelData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

BookmarksOutlineLevelData::BookmarksOutlineLevelData()
{
    m_Name = utility::conversions::to_string_t("");
    m_NameIsSet = false;
    m_BookmarksOutlineLevel = 0;
    m_BookmarksOutlineLevelIsSet = false;
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
        val[_XPLATSTR("Name")] = ModelBase::toJson(m_Name);
    }
    if(m_BookmarksOutlineLevelIsSet)
    {
        val[_XPLATSTR("BookmarksOutlineLevel")] = ModelBase::toJson(m_BookmarksOutlineLevel);
    }

    return val;
}

void BookmarksOutlineLevelData::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("Name")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Name")];
        if(!fieldValue.is_null())
        {
            setName(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("BookmarksOutlineLevel")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("BookmarksOutlineLevel")];
        if(!fieldValue.is_null())
        {
            setBookmarksOutlineLevel(ModelBase::int32_tFromJson(fieldValue));
        }
    }
}

void BookmarksOutlineLevelData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_NameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Name"), m_Name));
        
    }
    if(m_BookmarksOutlineLevelIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("BookmarksOutlineLevel"), m_BookmarksOutlineLevel));
        
    }
}

void BookmarksOutlineLevelData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    

    if(multipart->hasContent(_XPLATSTR("Name")))
    {
        setName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Name"))));
    }
    if(multipart->hasContent(_XPLATSTR("BookmarksOutlineLevel")))
    {
        setBookmarksOutlineLevel(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("BookmarksOutlineLevel"))));
    }
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
    m_BookmarksOutlineLevelIsSet = true;
}
bool BookmarksOutlineLevelData::bookmarksOutlineLevelIsSet() const
{
    return m_BookmarksOutlineLevelIsSet;
}

void BookmarksOutlineLevelData::unsetBookmarksOutlineLevel()
{
    m_BookmarksOutlineLevelIsSet = false;
}

}
}
}
}
}

