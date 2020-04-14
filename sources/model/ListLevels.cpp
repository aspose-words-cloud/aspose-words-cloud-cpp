/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ListLevels.cpp">
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


#include "ListLevels.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

ListLevels::ListLevels()
{
    m_ListLevelIsSet = false;
}

ListLevels::~ListLevels()
{
}

void ListLevels::validate()
{
    // TODO: implement validation
}

web::json::value ListLevels::toJson() const
{
    web::json::value val = web::json::value::object();

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_ListLevel.begin(), m_ListLevel.end(), std::back_inserter(jsonArray),
			[&](std::shared_ptr<ListLevel> item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("ListLevel")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void ListLevels::fromJson(web::json::value& val)
{
    {
        m_ListLevel.clear();
        if(val.has_field(_XPLATSTR("ListLevel")) 
                            && !val[_XPLATSTR("ListLevel")].is_null())
        {
        auto arr = val[_XPLATSTR("ListLevel")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_ListLevel), [&](web::json::value& item){
            if(item.is_null())
            {
                return std::shared_ptr<ListLevel>(nullptr);
            }
            else
            {
                std::shared_ptr<ListLevel> newItem(new ListLevel());
                newItem->fromJson(item);
                return newItem;
            }
        });

        }
    }
}

void ListLevels::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_ListLevel.begin(), m_ListLevel.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<ListLevel> item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ListLevel"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }
}

void ListLevels::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    

    {
        m_ListLevel.clear();
        if(multipart->hasContent(_XPLATSTR("ListLevel")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ListLevel")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_ListLevel), [&](web::json::value item) {
            if(item.is_null())
            {
                return std::shared_ptr<ListLevel>(nullptr) ;
            }
            else
            {
                std::shared_ptr<ListLevel> newItem(new ListLevel());
                newItem->fromJson(item);
                return newItem ;
            }
        });
        }
    }
}

std::vector<std::shared_ptr<ListLevel>>& ListLevels::getListLevel()
{
    return m_ListLevel;
}

void ListLevels::setListLevel(std::vector<std::shared_ptr<ListLevel>> const& value)
{
    m_ListLevel = value;
    m_ListLevelIsSet = true;
}
bool ListLevels::listLevelIsSet() const
{
    return m_ListLevelIsSet;
}

void ListLevels::unsetListLevel()
{
    m_ListLevelIsSet = false;
}

}
}
}
}
}
