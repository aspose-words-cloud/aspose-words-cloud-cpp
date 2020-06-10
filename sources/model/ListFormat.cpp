/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ListFormat.cpp">
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

#include "ListFormat.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

ListFormat::ListFormat()
{
    m_IsListItem = false;
    m_IsListItemIsSet = false;
    m_ListId = 0;
    m_ListIdIsSet = false;
    m_ListLevelNumber = 0;
    m_ListLevelNumberIsSet = false;

}

ListFormat::~ListFormat()
{
}

void ListFormat::validate()
{
    // TODO: implement validation
}

web::json::value ListFormat::toJson() const
{
    web::json::value val = this->LinkElement::toJson();
    if(m_IsListItemIsSet)
    {
        val[_XPLATSTR("IsListItem")] = ModelBase::toJson(m_IsListItem);
    }
    if(m_ListIdIsSet)
    {
        val[_XPLATSTR("ListId")] = ModelBase::toJson(m_ListId);
    }
    if(m_ListLevelNumberIsSet)
    {
        val[_XPLATSTR("ListLevelNumber")] = ModelBase::toJson(m_ListLevelNumber);
    }

    return val;
}

void ListFormat::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    if(val.has_field(_XPLATSTR("IsListItem")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("IsListItem")];
        if(!fieldValue.is_null())
        {
           setIsListItem(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("ListId")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ListId")];
        if(!fieldValue.is_null())
        {
           setListId(ModelBase::integerFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("ListLevelNumber")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ListLevelNumber")];
        if(!fieldValue.is_null())
        {
           setListLevelNumber(ModelBase::integerFromJson(fieldValue));
        }
    }

}

void ListFormat::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    LinkElement::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_IsListItemIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("IsListItem"), m_IsListItem));
    }


    if(m_ListIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ListId"), m_ListId));
    }


    if(m_ListLevelNumberIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ListLevelNumber"), m_ListLevelNumber));
    }

}

void ListFormat::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

bool ListFormat::isIsListItem() const
{
    return m_IsListItem;
}


void ListFormat::setIsListItem(bool value)
{
    m_IsListItem = value;
    m_IsListItemIsSet = true;
}

bool ListFormat::isListItemIsSet() const
{
    return m_IsListItemIsSet;
}

void ListFormat::unsetIsListItem()
{
    m_IsListItemIsSet = false;
}

int32_t ListFormat::getListId() const
{
    return m_ListId;
}


void ListFormat::setListId(int32_t value)
{
    m_ListId = value;
    m_ListIdIsSet = true;
}

bool ListFormat::listIdIsSet() const
{
    return m_ListIdIsSet;
}

void ListFormat::unsetListId()
{
    m_ListIdIsSet = false;
}

int32_t ListFormat::getListLevelNumber() const
{
    return m_ListLevelNumber;
}


void ListFormat::setListLevelNumber(int32_t value)
{
    m_ListLevelNumber = value;
    m_ListLevelNumberIsSet = true;
}

bool ListFormat::listLevelNumberIsSet() const
{
    return m_ListLevelNumberIsSet;
}

void ListFormat::unsetListLevelNumber()
{
    m_ListLevelNumberIsSet = false;
}

}
}
}
}
}
