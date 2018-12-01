/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SearchResultsCollection.cpp">
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


#include "SearchResultsCollection.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

SearchResultsCollection::SearchResultsCollection()
{
    m_ResultsListIsSet = false;
}

SearchResultsCollection::~SearchResultsCollection()
{
}

void SearchResultsCollection::validate()
{
    // TODO: implement validation
}

web::json::value SearchResultsCollection::toJson() const
{
    web::json::value val = this->LinkElement::toJson();

    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_ResultsList )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        if(jsonArray.size() > 0)
        {
            val[utility::conversions::to_string_t("ResultsList")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void SearchResultsCollection::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    {
        m_ResultsList.clear();
        std::vector<web::json::value> jsonArray;
        if(val.has_field(utility::conversions::to_string_t("ResultsList")) 
                            && !val[utility::conversions::to_string_t("ResultsList")].is_null())
        {
        for( auto& item : val[utility::conversions::to_string_t("ResultsList")].as_array() )
        {
            if(item.is_null())
            {
                m_ResultsList.push_back( std::shared_ptr<SearchResult>(nullptr) );
            }
            else
            {
                std::shared_ptr<SearchResult> newItem(new SearchResult());
                newItem->fromJson(item);
                m_ResultsList.push_back( newItem );
            }
        }
        }
    }
}

void SearchResultsCollection::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
        for( auto& item : m_ResultsList )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("ResultsList"), web::json::value::array(jsonArray), utility::conversions::to_string_t("application/json")));
        }
    }
}

void SearchResultsCollection::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
        m_ResultsList.clear();
        if(multipart->hasContent(utility::conversions::to_string_t("ResultsList")))
        {

        web::json::value jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("ResultsList"))));
        for( auto& item : jsonArray.as_array() )
        {
            if(item.is_null())
            {
                m_ResultsList.push_back( std::shared_ptr<SearchResult>(nullptr) );
            }
            else
            {
                std::shared_ptr<SearchResult> newItem(new SearchResult());
                newItem->fromJson(item);
                m_ResultsList.push_back( newItem );
            }
        }
        }
    }
}

std::vector<std::shared_ptr<SearchResult>>& SearchResultsCollection::getResultsList()
{
    return m_ResultsList;
}

void SearchResultsCollection::setResultsList(std::vector<std::shared_ptr<SearchResult>> value)
{
    m_ResultsList = value;
    m_ResultsListIsSet = true;
}
bool SearchResultsCollection::resultsListIsSet() const
{
    return m_ResultsListIsSet;
}

void SearchResultsCollection::unsetResultsList()
{
    m_ResultsListIsSet = false;
}

}
}
}
}
