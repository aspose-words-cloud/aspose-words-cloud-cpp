/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TablePropertiesResponse.cpp">
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


#include "TablePropertiesResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

TablePropertiesResponse::TablePropertiesResponse()
{
    m_PropertiesIsSet = false;
}

TablePropertiesResponse::~TablePropertiesResponse()
{
}

void TablePropertiesResponse::validate()
{
    // TODO: implement validation
}

web::json::value TablePropertiesResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();

    if(m_PropertiesIsSet)
    {
        val[_XPLATSTR("properties")] = ModelBase::toJson(m_Properties);
    }

    return val;
}

void TablePropertiesResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("properties")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("properties")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<TableProperties> newItem(new TableProperties());
            newItem->fromJson(fieldValue);
            setProperties( newItem );
        }
    }
}

void TablePropertiesResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_RequestIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("requestId"), m_RequestId));
        
    }
    if(m_PropertiesIsSet)
    {
        if (m_Properties.get())
        {
            m_Properties->toMultipart(multipart, _XPLATSTR("properties."));
        }
        
    }
}

void TablePropertiesResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("requestId")))
    {
        setRequestId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("requestId"))));
    }
    if(multipart->hasContent(_XPLATSTR("properties")))
    {
        if(multipart->hasContent(_XPLATSTR("properties")))
        {
            std::shared_ptr<TableProperties> newItem(new TableProperties());
            newItem->fromMultiPart(multipart, _XPLATSTR("properties."));
            setProperties( newItem );
        }
    }
}

std::shared_ptr<TableProperties> TablePropertiesResponse::getProperties() const
{
    return m_Properties;
}


void TablePropertiesResponse::setProperties(std::shared_ptr<TableProperties> value)
{
    m_Properties = value;
    m_PropertiesIsSet = true;
}
bool TablePropertiesResponse::propertiesIsSet() const
{
    return m_PropertiesIsSet;
}

void TablePropertiesResponse::unsetProperties()
{
    m_PropertiesIsSet = false;
}

}
}
}
}
}

