/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DocumentResponse.cpp">
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


#include "DocumentResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

DocumentResponse::DocumentResponse()
{
    m_DocumentIsSet = false;
}

DocumentResponse::~DocumentResponse()
{
}

void DocumentResponse::validate()
{
    // TODO: implement validation
}

web::json::value DocumentResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();

    if(m_DocumentIsSet)
    {
        val[_XPLATSTR("Document")] = ModelBase::toJson(m_Document);
    }

    return val;
}

void DocumentResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("Document")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Document")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Document> newItem(new Document());
            newItem->fromJson(fieldValue);
            setDocument( newItem );
        }
    }
}

void DocumentResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_RequestIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RequestId"), m_RequestId));
        
    }
    if(m_DocumentIsSet)
    {
        if (m_Document.get())
        {
            m_Document->toMultipart(multipart, _XPLATSTR("Document."));
        }
        
    }
}

void DocumentResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("RequestId")))
    {
        setRequestId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("RequestId"))));
    }
    if(multipart->hasContent(_XPLATSTR("Document")))
    {
        if(multipart->hasContent(_XPLATSTR("Document")))
        {
            std::shared_ptr<Document> newItem(new Document());
            newItem->fromMultiPart(multipart, _XPLATSTR("Document."));
            setDocument( newItem );
        }
    }
}

std::shared_ptr<Document> DocumentResponse::getDocument() const
{
    return m_Document;
}


void DocumentResponse::setDocument(std::shared_ptr<Document> value)
{
    m_Document = value;
    m_DocumentIsSet = true;
}
bool DocumentResponse::documentIsSet() const
{
    return m_DocumentIsSet;
}

void DocumentResponse::unsetDocument()
{
    m_DocumentIsSet = false;
}

}
}
}
}
}

