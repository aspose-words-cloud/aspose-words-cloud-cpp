/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="CommentsCollection.cpp">
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

#include "CommentsCollection.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

CommentsCollection::CommentsCollection()
{
    m_CommentListIsSet = false;

}

CommentsCollection::~CommentsCollection()
{
}

void CommentsCollection::validate()
{
    // TODO: implement validation
}

web::json::value CommentsCollection::toJson() const
{
    web::json::value val = this->LinkElement::toJson();
    if(m_CommentListIsSet)
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_CommentList.begin(), m_CommentList.end(), std::back_inserter(jsonArray),
            [&](std::shared_ptr<Comment> item) {
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("CommentList")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void CommentsCollection::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    {
        m_CommentList.clear();
        if(val.has_field(_XPLATSTR("CommentList")) 
                            && !val[_XPLATSTR("CommentList")].is_null())
        {
            auto arr = val[_XPLATSTR("CommentList")].as_array();
            std::transform(arr.begin(), arr.end(), std::back_inserter(m_CommentList), [&](web::json::value& item){
                if(!item.is_null())
                {
                    std::shared_ptr<Comment> newItem(new Comment());
                    newItem->fromJson(item);
                    return newItem;
                }

                return (std::shared_ptr<Comment>)nullptr;
            });
        }
    }

}

void CommentsCollection::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    LinkElement::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_CommentList.begin(), m_CommentList.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<Comment> item){
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("CommentList"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }

}

void CommentsCollection::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

std::vector<std::shared_ptr<Comment>>& CommentsCollection::getCommentList()
{
    return m_CommentList;
}


void CommentsCollection::setCommentList(std::vector<std::shared_ptr<Comment>> const& value)
{
    m_CommentList = value;
    m_CommentListIsSet = true;
}

bool CommentsCollection::commentListIsSet() const
{
    return m_CommentListIsSet;
}

void CommentsCollection::unsetCommentList()
{
    m_CommentListIsSet = false;
}

}
}
}
}
}
