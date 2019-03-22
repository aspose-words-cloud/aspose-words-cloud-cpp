/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DocumentPropertiesResponse.cpp">
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


#include "DocumentPropertiesResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

DocumentPropertiesResponse::DocumentPropertiesResponse()
{
    m_DocumentPropertiesIsSet = false;
}

DocumentPropertiesResponse::~DocumentPropertiesResponse()
{
}

void DocumentPropertiesResponse::validate()
{
    // TODO: implement validation
}

web::json::value DocumentPropertiesResponse::toJson() const
{
    web::json::value val = this->AsposeResponse::toJson();

    if(m_DocumentPropertiesIsSet)
    {
        val[_XPLATSTR("DocumentProperties")] = ModelBase::toJson(m_DocumentProperties);
    }

    return val;
}

void DocumentPropertiesResponse::fromJson(web::json::value& val)
{
    this->AsposeResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("DocumentProperties")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DocumentProperties")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<DocumentProperties> newItem(new DocumentProperties());
            newItem->fromJson(fieldValue);
            setDocumentProperties( newItem );
        }
    }
}

void DocumentPropertiesResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Code"), m_Code));
    if(m_StatusIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Status"), m_Status));
        
    }
    if(m_DocumentPropertiesIsSet)
    {
        if (m_DocumentProperties.get())
        {
            m_DocumentProperties->toMultipart(multipart, _XPLATSTR("DocumentProperties."));
        }
        
    }
}

void DocumentPropertiesResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    setCode(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("Code"))));
    if(multipart->hasContent(_XPLATSTR("Status")))
    {
        setStatus(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Status"))));
    }
    if(multipart->hasContent(_XPLATSTR("DocumentProperties")))
    {
        if(multipart->hasContent(_XPLATSTR("DocumentProperties")))
        {
            std::shared_ptr<DocumentProperties> newItem(new DocumentProperties());
            newItem->fromMultiPart(multipart, _XPLATSTR("DocumentProperties."));
            setDocumentProperties( newItem );
        }
    }
}

std::shared_ptr<DocumentProperties> DocumentPropertiesResponse::getDocumentProperties() const
{
    return m_DocumentProperties;
}


void DocumentPropertiesResponse::setDocumentProperties(std::shared_ptr<DocumentProperties> value)
{
    m_DocumentProperties = value;
    m_DocumentPropertiesIsSet = true;
}
bool DocumentPropertiesResponse::documentPropertiesIsSet() const
{
    return m_DocumentPropertiesIsSet;
}

void DocumentPropertiesResponse::unsetDocumentProperties()
{
    m_DocumentPropertiesIsSet = false;
}

}
}
}
}
}

