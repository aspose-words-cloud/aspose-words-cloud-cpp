/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ListFormatUpdate.cpp">
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


#include "ListFormatUpdate.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

ListFormatUpdate::ListFormatUpdate()
{
    m_ListLevelNumber = 0;
    m_ListLevelNumberIsSet = false;
    m_ListId = 0;
    m_ListIdIsSet = false;
}

ListFormatUpdate::~ListFormatUpdate()
{
}

void ListFormatUpdate::validate()
{
    // TODO: implement validation
}

web::json::value ListFormatUpdate::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_ListLevelNumberIsSet)
    {
        val[_XPLATSTR("ListLevelNumber")] = ModelBase::toJson(m_ListLevelNumber);
    }
    if(m_ListIdIsSet)
    {
        val[_XPLATSTR("ListId")] = ModelBase::toJson(m_ListId);
    }

    return val;
}

void ListFormatUpdate::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("ListLevelNumber")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ListLevelNumber")];
        if(!fieldValue.is_null())
        {
            setListLevelNumber(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ListId")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ListId")];
        if(!fieldValue.is_null())
        {
            setListId(ModelBase::int32_tFromJson(fieldValue));
        }
    }
}

void ListFormatUpdate::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_ListLevelNumberIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ListLevelNumber"), m_ListLevelNumber));
        
    }
    if(m_ListIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ListId"), m_ListId));
        
    }
}

void ListFormatUpdate::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    

    if(multipart->hasContent(_XPLATSTR("ListLevelNumber")))
    {
        setListLevelNumber(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("ListLevelNumber"))));
    }
    if(multipart->hasContent(_XPLATSTR("ListId")))
    {
        setListId(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("ListId"))));
    }
}

int32_t ListFormatUpdate::getListLevelNumber() const
{
    return m_ListLevelNumber;
}


void ListFormatUpdate::setListLevelNumber(int32_t value)
{
    m_ListLevelNumber = value;
    m_ListLevelNumberIsSet = true;
}
bool ListFormatUpdate::listLevelNumberIsSet() const
{
    return m_ListLevelNumberIsSet;
}

void ListFormatUpdate::unsetListLevelNumber()
{
    m_ListLevelNumberIsSet = false;
}

int32_t ListFormatUpdate::getListId() const
{
    return m_ListId;
}


void ListFormatUpdate::setListId(int32_t value)
{
    m_ListId = value;
    m_ListIdIsSet = true;
}
bool ListFormatUpdate::listIdIsSet() const
{
    return m_ListIdIsSet;
}

void ListFormatUpdate::unsetListId()
{
    m_ListIdIsSet = false;
}

}
}
}
}
}

