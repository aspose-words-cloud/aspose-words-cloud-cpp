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
    m_ListInfoIsSet = false;
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
    web::json::value val = this->LinkElement::toJson();

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_ListInfo.begin(), m_ListInfo.end(), std::back_inserter(jsonArray),
			[&](<DATA_TYPE_START>ListInfo<DATA_TYPE_END> item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("ListInfo")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void Lists::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    {
        m_ListInfo.clear();
        if(val.has_field(_XPLATSTR("ListInfo")) 
                            && !val[_XPLATSTR("ListInfo")].is_null())
        {
        auto arr = val[_XPLATSTR("ListInfo")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_ListInfo), [&](web::json::value& item){
            if(item.is_null())
            {
                return <DATA_TYPE_START>ListInfo<DATA_TYPE_END>(nullptr);
            }
            else
            {
                <DATA_TYPE_START>ListInfo<DATA_TYPE_END> newItem(new ListInfo());
                newItem->fromJson(item);
                return newItem;
            }
        });

        }
    }
}

void Lists::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    LinkElement::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_ListInfo.begin(), m_ListInfo.end(), std::back_inserter(jsonArray), [&](<DATA_TYPE_START>ListInfo<DATA_TYPE_END> item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ListInfo"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }
}

void Lists::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    LinkElement::fromMultiPart(multipart, prefix);

    {
        m_ListInfo.clear();
        if(multipart->hasContent(_XPLATSTR("ListInfo")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ListInfo")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_ListInfo), [&](web::json::value item) {
            if(item.is_null())
            {
                return <DATA_TYPE_START>ListInfo<DATA_TYPE_END>(nullptr) ;
            }
            else
            {
                <DATA_TYPE_START>ListInfo<DATA_TYPE_END> newItem(new ListInfo());
                newItem->fromJson(item);
                return newItem ;
            }
        });
        }
    }
}

<DATA_TYPE_START>List<ListInfo><DATA_TYPE_END>& Lists::getListInfo()
{
    return m_ListInfo;
}

void Lists::setListInfo(<DATA_TYPE_START>List<ListInfo><DATA_TYPE_END> const& value)
{
    m_ListInfo = value;
    m_ListInfoIsSet = true;
}
bool Lists::listInfoIsSet() const
{
    return m_ListInfoIsSet;
}

void Lists::unsetListInfo()
{
    m_ListInfoIsSet = false;
}

}
}
}
}
}

