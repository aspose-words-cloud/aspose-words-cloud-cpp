/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ListResponse.cpp">
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

#include "ListResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

ListResponse::ListResponse()
{
    m_ListIsSet = false;

}

ListResponse::~ListResponse()
{
}

void ListResponse::validate()
{
    // TODO: implement validation
}

web::json::value ListResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();
    if(m_ListIsSet)
    {
        val[_XPLATSTR("List")] = ModelBase::toJson(m_List);
    }

    return val;
}

void ListResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("List")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("List")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<ListInfo> newItem(new ListInfo());
            newItem->fromJson(fieldValue);
            setList( newItem );
        }
    }

}

void ListResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    WordsResponse::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_ListIsSet)
    {
        if (m_List.get())
        {
            m_List->toMultipart(multipart, _XPLATSTR("List."));
        }
    }

}

void ListResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

std::shared_ptr<ListInfo> ListResponse::getList() const
{
    return m_List;
}


void ListResponse::setList(std::shared_ptr<ListInfo> value)
{
    m_List = value;
    m_ListIsSet = true;
}

bool ListResponse::listIsSet() const
{
    return m_ListIsSet;
}

void ListResponse::unsetList()
{
    m_ListIsSet = false;
}

}
}
}
}
}
