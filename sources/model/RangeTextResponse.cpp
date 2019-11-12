/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="RangeTextResponse.cpp">
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


#include "RangeTextResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

RangeTextResponse::RangeTextResponse()
{
    m_Text = utility::conversions::to_string_t("");
    m_TextIsSet = false;
}

RangeTextResponse::~RangeTextResponse()
{
}

void RangeTextResponse::validate()
{
    // TODO: implement validation
}

web::json::value RangeTextResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();

    if(m_TextIsSet)
    {
        val[_XPLATSTR("Text")] = ModelBase::toJson(m_Text);
    }

    return val;
}

void RangeTextResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("Text")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Text")];
        if(!fieldValue.is_null())
        {
            setText(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void RangeTextResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_RequestIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RequestId"), m_RequestId));
        
    }
    if(m_TextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Text"), m_Text));
        
    }
}

void RangeTextResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("RequestId")))
    {
        setRequestId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("RequestId"))));
    }
    if(multipart->hasContent(_XPLATSTR("Text")))
    {
        setText(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Text"))));
    }
}

utility::string_t RangeTextResponse::getText() const
{
    return m_Text;
}


void RangeTextResponse::setText(utility::string_t value)
{
    m_Text = value;
    m_TextIsSet = true;
}
bool RangeTextResponse::textIsSet() const
{
    return m_TextIsSet;
}

void RangeTextResponse::unsetText()
{
    m_TextIsSet = false;
}

}
}
}
}
}

