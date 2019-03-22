/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="StoryChildNodes.cpp">
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


#include "StoryChildNodes.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

StoryChildNodes::StoryChildNodes()
{
    m_ChildNodesIsSet = false;
}

StoryChildNodes::~StoryChildNodes()
{
}

void StoryChildNodes::validate()
{
    // TODO: implement validation
}

web::json::value StoryChildNodes::toJson() const
{
    web::json::value val = web::json::value::object();

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_ChildNodes.begin(), m_ChildNodes.end(), std::back_inserter(jsonArray),
			[&](std::shared_ptr<NodeLink> item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("ChildNodes")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void StoryChildNodes::fromJson(web::json::value& val)
{
    {
        m_ChildNodes.clear();
        if(val.has_field(_XPLATSTR("ChildNodes")) 
                            && !val[_XPLATSTR("ChildNodes")].is_null())
        {
        auto arr = val[_XPLATSTR("ChildNodes")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_ChildNodes), [&](web::json::value& item){
            if(item.is_null())
            {
                return std::shared_ptr<NodeLink>(nullptr);
            }
            else
            {
                std::shared_ptr<NodeLink> newItem(new NodeLink());
                newItem->fromJson(item);
                return newItem;
            }
        });

        }
    }
}

void StoryChildNodes::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_ChildNodes.begin(), m_ChildNodes.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<NodeLink> item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ChildNodes"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }
}

void StoryChildNodes::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    {
        m_ChildNodes.clear();
        if(multipart->hasContent(_XPLATSTR("ChildNodes")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ChildNodes")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_ChildNodes), [&](web::json::value item) {
            if(item.is_null())
            {
                return std::shared_ptr<NodeLink>(nullptr) ;
            }
            else
            {
                std::shared_ptr<NodeLink> newItem(new NodeLink());
                newItem->fromJson(item);
                return newItem ;
            }
        });
        }
    }
}

std::vector<std::shared_ptr<NodeLink>>& StoryChildNodes::getChildNodes()
{
    return m_ChildNodes;
}

void StoryChildNodes::setChildNodes(std::vector<std::shared_ptr<NodeLink>> const& value)
{
    m_ChildNodes = value;
    m_ChildNodesIsSet = true;
}
bool StoryChildNodes::childNodesIsSet() const
{
    return m_ChildNodesIsSet;
}

void StoryChildNodes::unsetChildNodes()
{
    m_ChildNodesIsSet = false;
}

}
}
}
}
}

