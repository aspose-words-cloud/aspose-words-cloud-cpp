/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TabStopsResponse.cpp">
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
    if(m_TabStopsIsSet)
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_TabStops.begin(), m_TabStops.end(), std::back_inserter(jsonArray),
            [&](std::shared_ptr<TabStop> item) {
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
                if(!item.is_null())
                {
                    std::shared_ptr<TabStop> newItem(new TabStop());
                    newItem->fromJson(item);
                    return newItem;
                }

                return (std::shared_ptr<TabStop>)nullptr;
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
        std::transform(m_TabStops.begin(), m_TabStops.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<TabStop> item){
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
    // TODO: implement fromMultiPart
}

std::vector<std::shared_ptr<TabStop>>& TabStopsResponse::getTabStops()
{
    return m_TabStops;
}


void TabStopsResponse::setTabStops(std::vector<std::shared_ptr<TabStop>> const& value)
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
