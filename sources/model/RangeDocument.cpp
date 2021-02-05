/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="RangeDocument.cpp">
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

#include "RangeDocument.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

RangeDocument::RangeDocument()
{
    m_DocumentName = utility::conversions::to_string_t("");
    m_DocumentNameIsSet = false;

}

RangeDocument::~RangeDocument()
{
}

void RangeDocument::validate()
{
    // TODO: implement validation
}

web::json::value RangeDocument::toJson() const
{
    web::json::value val = web::json::value::object();
    if(m_DocumentNameIsSet)
    {
        val[_XPLATSTR("DocumentName")] = ModelBase::toJson(m_DocumentName);
    }

    return val;
}

void RangeDocument::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("DocumentName")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DocumentName")];
        if(!fieldValue.is_null())
        {
           setDocumentName(ModelBase::stringFromJson(fieldValue));
        }
    }

}

void RangeDocument::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_DocumentNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("DocumentName"), m_DocumentName));
    }

}

void RangeDocument::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

utility::string_t RangeDocument::getDocumentName() const
{
    return m_DocumentName;
}


void RangeDocument::setDocumentName(utility::string_t value)
{
    m_DocumentName = value;
    m_DocumentNameIsSet = true;
}

bool RangeDocument::documentNameIsSet() const
{
    return m_DocumentNameIsSet;
}

void RangeDocument::unsetDocumentName()
{
    m_DocumentNameIsSet = false;
}

}
}
}
}
}
