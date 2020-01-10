/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ClassificationResponse.cpp">
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


#include "ClassificationResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

ClassificationResponse::ClassificationResponse()
{
    m_BestClassName = utility::conversions::to_string_t("");
    m_BestClassNameIsSet = false;
    m_BestClassProbability = 0.0;
    m_BestClassProbabilityIsSet = false;
    m_BestResultsIsSet = false;
}

ClassificationResponse::~ClassificationResponse()
{
}

void ClassificationResponse::validate()
{
    // TODO: implement validation
}

web::json::value ClassificationResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();

    if(m_BestClassNameIsSet)
    {
        val[_XPLATSTR("bestClassName")] = ModelBase::toJson(m_BestClassName);
    }
    if(m_BestClassProbabilityIsSet)
    {
        val[_XPLATSTR("bestClassProbability")] = ModelBase::toJson(m_BestClassProbability);
    }
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_BestResults.begin(), m_BestResults.end(), std::back_inserter(jsonArray),
			[&](std::shared_ptr<ClassificationResult> item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("bestResults")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void ClassificationResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("bestClassName")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("bestClassName")];
        if(!fieldValue.is_null())
        {
            setBestClassName(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("bestClassProbability")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("bestClassProbability")];
        if(!fieldValue.is_null())
        {
            setBestClassProbability(ModelBase::doubleFromJson(fieldValue));
        }
    }
    {
        m_BestResults.clear();
        if(val.has_field(_XPLATSTR("bestResults")) 
                            && !val[_XPLATSTR("bestResults")].is_null())
        {
        auto arr = val[_XPLATSTR("bestResults")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_BestResults), [&](web::json::value& item){
            if(item.is_null())
            {
                return std::shared_ptr<ClassificationResult>(nullptr);
            }
            else
            {
                std::shared_ptr<ClassificationResult> newItem(new ClassificationResult());
                newItem->fromJson(item);
                return newItem;
            }
        });

        }
    }
}

void ClassificationResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_RequestIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("requestId"), m_RequestId));
        
    }
    if(m_BestClassNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("bestClassName"), m_BestClassName));
        
    }
    if(m_BestClassProbabilityIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("bestClassProbability"), m_BestClassProbability));
    }
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_BestResults.begin(), m_BestResults.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<ClassificationResult> item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("bestResults"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }
}

void ClassificationResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("requestId")))
    {
        setRequestId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("requestId"))));
    }
    if(multipart->hasContent(_XPLATSTR("bestClassName")))
    {
        setBestClassName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("bestClassName"))));
    }
    if(multipart->hasContent(_XPLATSTR("bestClassProbability")))
    {
        setBestClassProbability(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("bestClassProbability"))));
    }
    {
        m_BestResults.clear();
        if(multipart->hasContent(_XPLATSTR("bestResults")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("bestResults")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_BestResults), [&](web::json::value item) {
            if(item.is_null())
            {
                return std::shared_ptr<ClassificationResult>(nullptr) ;
            }
            else
            {
                std::shared_ptr<ClassificationResult> newItem(new ClassificationResult());
                newItem->fromJson(item);
                return newItem ;
            }
        });
        }
    }
}

utility::string_t ClassificationResponse::getBestClassName() const
{
    return m_BestClassName;
}


void ClassificationResponse::setBestClassName(utility::string_t value)
{
    m_BestClassName = value;
    m_BestClassNameIsSet = true;
}
bool ClassificationResponse::bestClassNameIsSet() const
{
    return m_BestClassNameIsSet;
}

void ClassificationResponse::unsetBestClassName()
{
    m_BestClassNameIsSet = false;
}

double ClassificationResponse::getBestClassProbability() const
{
    return m_BestClassProbability;
}


void ClassificationResponse::setBestClassProbability(double value)
{
    m_BestClassProbability = value;
    m_BestClassProbabilityIsSet = true;
}
bool ClassificationResponse::bestClassProbabilityIsSet() const
{
    return m_BestClassProbabilityIsSet;
}

void ClassificationResponse::unsetBestClassProbability()
{
    m_BestClassProbabilityIsSet = false;
}

std::vector<std::shared_ptr<ClassificationResult>>& ClassificationResponse::getBestResults()
{
    return m_BestResults;
}

void ClassificationResponse::setBestResults(std::vector<std::shared_ptr<ClassificationResult>> const& value)
{
    m_BestResults = value;
    m_BestResultsIsSet = true;
}
bool ClassificationResponse::bestResultsIsSet() const
{
    return m_BestResultsIsSet;
}

void ClassificationResponse::unsetBestResults()
{
    m_BestResultsIsSet = false;
}

}
}
}
}
}

