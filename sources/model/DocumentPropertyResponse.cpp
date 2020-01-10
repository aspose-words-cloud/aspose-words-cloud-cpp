/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DocumentPropertyResponse.cpp">
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


#include "DocumentPropertyResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

DocumentPropertyResponse::DocumentPropertyResponse()
{
    m_DocumentPropertyIsSet = false;
}

DocumentPropertyResponse::~DocumentPropertyResponse()
{
}

void DocumentPropertyResponse::validate()
{
    // TODO: implement validation
}

web::json::value DocumentPropertyResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();

    if(m_DocumentPropertyIsSet)
    {
        val[_XPLATSTR("documentProperty")] = ModelBase::toJson(m_DocumentProperty);
    }

    return val;
}

void DocumentPropertyResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("documentProperty")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("documentProperty")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<DocumentProperty> newItem(new DocumentProperty());
            newItem->fromJson(fieldValue);
            setDocumentProperty( newItem );
        }
    }
}

void DocumentPropertyResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_RequestIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("requestId"), m_RequestId));
        
    }
    if(m_DocumentPropertyIsSet)
    {
        if (m_DocumentProperty.get())
        {
            m_DocumentProperty->toMultipart(multipart, _XPLATSTR("documentProperty."));
        }
        
    }
}

void DocumentPropertyResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("requestId")))
    {
        setRequestId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("requestId"))));
    }
    if(multipart->hasContent(_XPLATSTR("documentProperty")))
    {
        if(multipart->hasContent(_XPLATSTR("documentProperty")))
        {
            std::shared_ptr<DocumentProperty> newItem(new DocumentProperty());
            newItem->fromMultiPart(multipart, _XPLATSTR("documentProperty."));
            setDocumentProperty( newItem );
        }
    }
}

std::shared_ptr<DocumentProperty> DocumentPropertyResponse::getDocumentProperty() const
{
    return m_DocumentProperty;
}


void DocumentPropertyResponse::setDocumentProperty(std::shared_ptr<DocumentProperty> value)
{
    m_DocumentProperty = value;
    m_DocumentPropertyIsSet = true;
}
bool DocumentPropertyResponse::documentPropertyIsSet() const
{
    return m_DocumentPropertyIsSet;
}

void DocumentPropertyResponse::unsetDocumentProperty()
{
    m_DocumentPropertyIsSet = false;
}

}
}
}
}
}

