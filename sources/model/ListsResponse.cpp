/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ListsResponse.cpp">
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


#include "ListsResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

ListsResponse::ListsResponse()
{
    m_ListsIsSet = false;
}

ListsResponse::~ListsResponse()
{
}

void ListsResponse::validate()
{
    // TODO: implement validation
}

web::json::value ListsResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();

    if(m_ListsIsSet)
    {
        val[_XPLATSTR("Lists")] = ModelBase::toJson(m_Lists);
    }

    return val;
}

void ListsResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("Lists")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Lists")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Lists> newItem(new Lists());
            newItem->fromJson(fieldValue);
            setLists( newItem );
        }
    }
}

void ListsResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    WordsResponse::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_ListsIsSet)
    {
        if (m_Lists.get())
        {
            m_Lists->toMultipart(multipart, _XPLATSTR("Lists."));
        }
        
    }
}

void ListsResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    WordsResponse::fromMultiPart(multipart, prefix);

    if(multipart->hasContent(_XPLATSTR("Lists")))
    {
        if(multipart->hasContent(_XPLATSTR("Lists")))
        {
            std::shared_ptr<Lists> newItem(new Lists());
            newItem->fromMultiPart(multipart, _XPLATSTR("Lists."));
            setLists( newItem );
        }
    }
}

std::shared_ptr<Lists> ListsResponse::getLists() const
{
    return m_Lists;
}


void ListsResponse::setLists(std::shared_ptr<Lists> value)
{
    m_Lists = value;
    m_ListsIsSet = true;
}
bool ListsResponse::listsIsSet() const
{
    return m_ListsIsSet;
}

void ListsResponse::unsetLists()
{
    m_ListsIsSet = false;
}

}
}
}
}
}

