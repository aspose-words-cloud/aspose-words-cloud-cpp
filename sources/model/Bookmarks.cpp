/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Bookmarks.cpp">
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


#include "Bookmarks.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

Bookmarks::Bookmarks()
{
    m_BookmarkListIsSet = false;
}

Bookmarks::~Bookmarks()
{
}

void Bookmarks::validate()
{
    // TODO: implement validation
}

web::json::value Bookmarks::toJson() const
{
    web::json::value val = this->LinkElement::toJson();

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_BookmarkList.begin(), m_BookmarkList.end(), std::back_inserter(jsonArray),
			[&](std::shared_ptr<Bookmark> item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("BookmarkList")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void Bookmarks::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    {
        m_BookmarkList.clear();
        if(val.has_field(_XPLATSTR("BookmarkList")) 
                            && !val[_XPLATSTR("BookmarkList")].is_null())
        {
        auto arr = val[_XPLATSTR("BookmarkList")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_BookmarkList), [&](web::json::value& item){
            if(item.is_null())
            {
                return std::shared_ptr<Bookmark>(nullptr);
            }
            else
            {
                std::shared_ptr<Bookmark> newItem(new Bookmark());
                newItem->fromJson(item);
                return newItem;
            }
        });

        }
    }
}

void Bookmarks::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_LinkIsSet)
    {
        if (m_Link.get())
        {
            m_Link->toMultipart(multipart, _XPLATSTR("link."));
        }
        
    }
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_BookmarkList.begin(), m_BookmarkList.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<Bookmark> item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("BookmarkList"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }
}

void Bookmarks::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("link")))
    {
        if(multipart->hasContent(_XPLATSTR("link")))
        {
            std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
            newItem->fromMultiPart(multipart, _XPLATSTR("link."));
            setLink( newItem );
        }
    }
    {
        m_BookmarkList.clear();
        if(multipart->hasContent(_XPLATSTR("BookmarkList")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("BookmarkList")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_BookmarkList), [&](web::json::value item) {
            if(item.is_null())
            {
                return std::shared_ptr<Bookmark>(nullptr) ;
            }
            else
            {
                std::shared_ptr<Bookmark> newItem(new Bookmark());
                newItem->fromJson(item);
                return newItem ;
            }
        });
        }
    }
}

std::vector<std::shared_ptr<Bookmark>>& Bookmarks::getBookmarkList()
{
    return m_BookmarkList;
}

void Bookmarks::setBookmarkList(std::vector<std::shared_ptr<Bookmark>> const& value)
{
    m_BookmarkList = value;
    m_BookmarkListIsSet = true;
}
bool Bookmarks::bookmarkListIsSet() const
{
    return m_BookmarkListIsSet;
}

void Bookmarks::unsetBookmarkList()
{
    m_BookmarkListIsSet = false;
}

}
}
}
}
}

