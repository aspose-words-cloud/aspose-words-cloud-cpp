/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TabStopsResponse.cpp">
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


#include "TabStopsResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

TabStopsResponse::TabStopsResponse()
{
    m_TabStopsIsSet = false;
}

TabStopsResponse::~TabStopsResponse()
{
}

void TabStopsResponse::validate()
{
    // TODO: implement validation
}

web::json::value TabStopsResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_TabStops.begin(), m_TabStops.end(), std::back_inserter(jsonArray),
			[&](<DATA_TYPE_START>TabStop<DATA_TYPE_END> item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("TabStops")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void TabStopsResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    {
        m_TabStops.clear();
        if(val.has_field(_XPLATSTR("TabStops")) 
                            && !val[_XPLATSTR("TabStops")].is_null())
        {
        auto arr = val[_XPLATSTR("TabStops")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_TabStops), [&](web::json::value& item){
            if(item.is_null())
            {
                return <DATA_TYPE_START>TabStop<DATA_TYPE_END>(nullptr);
            }
            else
            {
                <DATA_TYPE_START>TabStop<DATA_TYPE_END> newItem(new TabStop());
                newItem->fromJson(item);
                return newItem;
            }
        });

        }
    }
}

void TabStopsResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    WordsResponse::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_TabStops.begin(), m_TabStops.end(), std::back_inserter(jsonArray), [&](<DATA_TYPE_START>TabStop<DATA_TYPE_END> item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TabStops"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }
}

void TabStopsResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    WordsResponse::fromMultiPart(multipart, prefix);

    {
        m_TabStops.clear();
        if(multipart->hasContent(_XPLATSTR("TabStops")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("TabStops")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_TabStops), [&](web::json::value item) {
            if(item.is_null())
            {
                return <DATA_TYPE_START>TabStop<DATA_TYPE_END>(nullptr) ;
            }
            else
            {
                <DATA_TYPE_START>TabStop<DATA_TYPE_END> newItem(new TabStop());
                newItem->fromJson(item);
                return newItem ;
            }
        });
        }
    }
}

<DATA_TYPE_START>List<TabStop><DATA_TYPE_END>& TabStopsResponse::getTabStops()
{
    return m_TabStops;
}

void TabStopsResponse::setTabStops(<DATA_TYPE_START>List<TabStop><DATA_TYPE_END> const& value)
{
    m_TabStops = value;
    m_TabStopsIsSet = true;
}
bool TabStopsResponse::tabStopsIsSet() const
{
    return m_TabStopsIsSet;
}

void TabStopsResponse::unsetTabStops()
{
    m_TabStopsIsSet = false;
}

}
}
}
}
}

