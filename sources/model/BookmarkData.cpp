/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="BookmarkData.cpp">
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


#include "BookmarkData.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

BookmarkData::BookmarkData()
{
    m_Name = utility::conversions::to_string_t("");
    m_NameIsSet = false;
    m_Text = utility::conversions::to_string_t("");
    m_TextIsSet = false;
}

BookmarkData::~BookmarkData()
{
}

void BookmarkData::validate()
{
    // TODO: implement validation
}

web::json::value BookmarkData::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_NameIsSet)
    {
        val[utility::conversions::to_string_t("Name")] = ModelBase::toJson(m_Name);
    }
    if(m_TextIsSet)
    {
        val[utility::conversions::to_string_t("Text")] = ModelBase::toJson(m_Text);
    }

    return val;
}

void BookmarkData::fromJson(web::json::value& val)
{
    if(val.has_field(utility::conversions::to_string_t("Name")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Name")];
        if(!fieldValue.is_null())
        {
            setName(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("Text")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Text")];
        if(!fieldValue.is_null())
        {
            setText(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void BookmarkData::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_TextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Text"), m_Text));
        
    }
}

void BookmarkData::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t("Text")))
    {
        setText(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Text"))));
    }
}

utility::string_t BookmarkData::getName() const
{
    return m_Name;
}


void BookmarkData::setName(utility::string_t value)
{
    m_Name = value;
    m_NameIsSet = true;
}
bool BookmarkData::nameIsSet() const
{
    return m_NameIsSet;
}

void BookmarkData::unsetName()
{
    m_NameIsSet = false;
}

utility::string_t BookmarkData::getText() const
{
    return m_Text;
}


void BookmarkData::setText(utility::string_t value)
{
    m_Text = value;
    m_TextIsSet = true;
}
bool BookmarkData::textIsSet() const
{
    return m_TextIsSet;
}

void BookmarkData::unsetText()
{
    m_TextIsSet = false;
}

}
}
}
}

