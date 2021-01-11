/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="BookmarkResponse.cpp">
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

#include "BookmarkResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

BookmarkResponse::BookmarkResponse()
{
    m_BookmarkIsSet = false;

}

BookmarkResponse::~BookmarkResponse()
{
}

void BookmarkResponse::validate()
{
    // TODO: implement validation
}

web::json::value BookmarkResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();
    if(m_BookmarkIsSet)
    {
        val[_XPLATSTR("Bookmark")] = ModelBase::toJson(m_Bookmark);
    }

    return val;
}

void BookmarkResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("Bookmark")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Bookmark")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Bookmark> newItem(new Bookmark());
            newItem->fromJson(fieldValue);
            setBookmark( newItem );
        }
    }

}

void BookmarkResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    WordsResponse::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_BookmarkIsSet)
    {
        if (m_Bookmark.get())
        {
            m_Bookmark->toMultipart(multipart, _XPLATSTR("Bookmark."));
        }
    }

}

void BookmarkResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

std::shared_ptr<Bookmark> BookmarkResponse::getBookmark() const
{
    return m_Bookmark;
}


void BookmarkResponse::setBookmark(std::shared_ptr<Bookmark> value)
{
    m_Bookmark = value;
    m_BookmarkIsSet = true;
}

bool BookmarkResponse::bookmarkIsSet() const
{
    return m_BookmarkIsSet;
}

void BookmarkResponse::unsetBookmark()
{
    m_BookmarkIsSet = false;
}

}
}
}
}
}
