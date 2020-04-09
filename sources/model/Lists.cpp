/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Lists.cpp">
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


#include "Lists.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

Lists::Lists()
{
    m_ListCollectionIsSet = false;
}

Lists::~Lists()
{
}

void Lists::validate()
{
    // TODO: implement validation
}

web::json::value Lists::toJson() const
{
    web::json::value val = web::json::value::object();

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_ListCollection.begin(), m_ListCollection.end(), std::back_inserter(jsonArray),
			[&](std::shared_ptr<ListInfo> item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("ListCollection")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void Lists::fromJson(web::json::value& val)
{
    {
        m_ListCollection.clear();
        if(val.has_field(_XPLATSTR("ListCollection")) 
                            && !val[_XPLATSTR("ListCollection")].is_null())
        {
        auto arr = val[_XPLATSTR("ListCollection")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_ListCollection), [&](web::json::value& item){
            if(item.is_null())
            {
                return std::shared_ptr<ListInfo>(nullptr);
            }
            else
            {
                std::shared_ptr<ListInfo> newItem(new ListInfo());
                newItem->fromJson(item);
                return newItem;
            }
        });

        }
    }
}

void Lists::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_ListCollection.begin(), m_ListCollection.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<ListInfo> item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ListCollection"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }
}

void Lists::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    

    {
        m_ListCollection.clear();
        if(multipart->hasContent(_XPLATSTR("ListCollection")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ListCollection")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_ListCollection), [&](web::json::value item) {
            if(item.is_null())
            {
                return std::shared_ptr<ListInfo>(nullptr) ;
            }
            else
            {
                std::shared_ptr<ListInfo> newItem(new ListInfo());
                newItem->fromJson(item);
                return newItem ;
            }
        });
        }
    }
}

std::vector<std::shared_ptr<ListInfo>>& Lists::getListCollection()
{
    return m_ListCollection;
}

void Lists::setListCollection(std::vector<std::shared_ptr<ListInfo>> const& value)
{
    m_ListCollection = value;
    m_ListCollectionIsSet = true;
}
bool Lists::listCollectionIsSet() const
{
    return m_ListCollectionIsSet;
}

void Lists::unsetListCollection()
{
    m_ListCollectionIsSet = false;
}

}
}
}
}
}

