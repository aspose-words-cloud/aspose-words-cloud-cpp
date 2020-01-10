/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FieldNames.cpp">
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


#include "FieldNames.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

FieldNames::FieldNames()
{
    m_NamesIsSet = false;
}

FieldNames::~FieldNames()
{
}

void FieldNames::validate()
{
    // TODO: implement validation
}

web::json::value FieldNames::toJson() const
{
    web::json::value val = this->LinkElement::toJson();

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_Names.begin(), m_Names.end(), std::back_inserter(jsonArray),
			[&](utility::string_t item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("names")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void FieldNames::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    {
        m_Names.clear();
        if(val.has_field(_XPLATSTR("names")) 
                            && !val[_XPLATSTR("names")].is_null())
        {
        auto arr = val[_XPLATSTR("names")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_Names), [&](web::json::value& item){
            return ModelBase::stringFromJson(item);
        });

        }
    }
}

void FieldNames::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_LinkIsSet)
    {
        if (m_Link.get())
        {
            m_Link->toMultipart(multipart, _XPLATSTR("link."));
        }
        
    }
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_Names.begin(), m_Names.end(), std::back_inserter(jsonArray), [&](utility::string_t item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("names"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }
}

void FieldNames::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("link")))
    {
        if(multipart->hasContent(_XPLATSTR("link")))
        {
            std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
            newItem->fromMultiPart(multipart, _XPLATSTR("link."));
            setLink( newItem );
        }
    }
    {
        m_Names.clear();
        if(multipart->hasContent(_XPLATSTR("names")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("names")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_Names), [&](web::json::value item) {
            return ModelBase::stringFromJson(item);
        });
        }
    }
}

std::vector<utility::string_t>& FieldNames::getNames()
{
    return m_Names;
}

void FieldNames::setNames(std::vector<utility::string_t> const& value)
{
    m_Names = value;
    m_NamesIsSet = true;
}
bool FieldNames::namesIsSet() const
{
    return m_NamesIsSet;
}

void FieldNames::unsetNames()
{
    m_NamesIsSet = false;
}

}
}
}
}
}

