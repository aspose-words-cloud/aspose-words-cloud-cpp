/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FieldNamesResponse.cpp">
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


#include "FieldNamesResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

FieldNamesResponse::FieldNamesResponse()
{
    m_FieldNamesIsSet = false;
}

FieldNamesResponse::~FieldNamesResponse()
{
}

void FieldNamesResponse::validate()
{
    // TODO: implement validation
}

web::json::value FieldNamesResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();

    if(m_FieldNamesIsSet)
    {
        val[_XPLATSTR("FieldNames")] = ModelBase::toJson(m_FieldNames);
    }

    return val;
}

void FieldNamesResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("FieldNames")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("FieldNames")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<FieldNames> newItem(new FieldNames());
            newItem->fromJson(fieldValue);
            setFieldNames( newItem );
        }
    }
}

void FieldNamesResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    WordsResponse::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_FieldNamesIsSet)
    {
        if (m_FieldNames.get())
        {
            m_FieldNames->toMultipart(multipart, _XPLATSTR("FieldNames."));
        }
        
    }
}

void FieldNamesResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    WordsResponse::fromMultiPart(multipart, prefix);

    if(multipart->hasContent(_XPLATSTR("FieldNames")))
    {
        if(multipart->hasContent(_XPLATSTR("FieldNames")))
        {
            std::shared_ptr<FieldNames> newItem(new FieldNames());
            newItem->fromMultiPart(multipart, _XPLATSTR("FieldNames."));
            setFieldNames( newItem );
        }
    }
}

std::shared_ptr<FieldNames> FieldNamesResponse::getFieldNames() const
{
    return m_FieldNames;
}


void FieldNamesResponse::setFieldNames(std::shared_ptr<FieldNames> value)
{
    m_FieldNames = value;
    m_FieldNamesIsSet = true;
}
bool FieldNamesResponse::fieldNamesIsSet() const
{
    return m_FieldNamesIsSet;
}

void FieldNamesResponse::unsetFieldNames()
{
    m_FieldNamesIsSet = false;
}

}
}
}
}
}

