/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Runs.cpp">
*   Copyright (c) 2018 Aspose.Words for Cloud
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


#include "Runs.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

Runs::Runs()
{
    m_ListIsSet = false;
}

Runs::~Runs()
{
}

void Runs::validate()
{
    // TODO: implement validation
}

web::json::value Runs::toJson() const
{
    web::json::value val = this->LinkElement::toJson();

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_List.begin(), m_List.end(), std::back_inserter(jsonArray),
			[&](std::shared_ptr<Run> item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[utility::conversions::to_string_t("List")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void Runs::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    {
        m_List.clear();
        if(val.has_field(utility::conversions::to_string_t("List")) 
                            && !val[utility::conversions::to_string_t("List")].is_null())
        {
        auto arr = val[utility::conversions::to_string_t("List")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_List), [&](std::shared_ptr<Run> item){
            if(item.is_null())
            {
                return std::shared_ptr<Run>(nullptr);
            }
            else
            {
                std::shared_ptr<Run> newItem(new Run());
                newItem->fromJson(item);
                return newItem;
            }
        });

        }
    }
}

void Runs::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_LinkIsSet)
    {
        if (m_Link.get())
        {
            m_Link->toMultipart(multipart, utility::conversions::to_string_t("link."));
        }
        
    }
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_List.begin(), m_List.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<Run> item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("List"), web::json::value::array(jsonArray), utility::conversions::to_string_t("application/json")));
        }
    }
}

void Runs::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("link")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("link")))
        {
            std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("link."));
            setLink( newItem );
        }
    }
    {
        m_List.clear();
        if(multipart->hasContent(utility::conversions::to_string_t("List")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("List")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_List), [&](std::shared_ptr<Run> item) {
            if(item.is_null())
            {
                return std::shared_ptr<Run>(nullptr) ;
            }
            else
            {
                std::shared_ptr<Run> newItem(new Run());
                newItem->fromJson(item);
                return newItem ;
            }
        });
        }
    }
}

std::vector<std::shared_ptr<Run>>& Runs::getList()
{
    return m_List;
}

void Runs::setList(std::vector<std::shared_ptr<Run>> const& value)
{
    m_List = value;
    m_ListIsSet = true;
}
bool Runs::listIsSet() const
{
    return m_ListIsSet;
}

void Runs::unsetList()
{
    m_ListIsSet = false;
}

}
}
}
}

