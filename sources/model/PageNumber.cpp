/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PageNumber.cpp">
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


#include "PageNumber.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

PageNumber::PageNumber()
{
    m_Format = utility::conversions::to_string_t("");
    m_FormatIsSet = false;
    m_Alignment = utility::conversions::to_string_t("");
    m_AlignmentIsSet = false;
    m_IsTop = false;
    m_SetPageNumberOnFirstPage = false;
}

PageNumber::~PageNumber()
{
}

void PageNumber::validate()
{
    // TODO: implement validation
}

web::json::value PageNumber::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_FormatIsSet)
    {
        val[_XPLATSTR("format")] = ModelBase::toJson(m_Format);
    }
    if(m_AlignmentIsSet)
    {
        val[_XPLATSTR("alignment")] = ModelBase::toJson(m_Alignment);
    }
    val[_XPLATSTR("isTop")] = ModelBase::toJson(m_IsTop);
    val[_XPLATSTR("setPageNumberOnFirstPage")] = ModelBase::toJson(m_SetPageNumberOnFirstPage);

    return val;
}

void PageNumber::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("format")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("format")];
        if(!fieldValue.is_null())
        {
            setFormat(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("alignment")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("alignment")];
        if(!fieldValue.is_null())
        {
            setAlignment(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("isTop")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("isTop")];
        if(!fieldValue.is_null())
        {
            setIsTop(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("setPageNumberOnFirstPage")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("setPageNumberOnFirstPage")];
        if(!fieldValue.is_null())
        {
            setSetPageNumberOnFirstPage(ModelBase::boolFromJson(fieldValue));
        }
    }
}

void PageNumber::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_FormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("format"), m_Format));
        
    }
    if(m_AlignmentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("alignment"), m_Alignment));
        
    }
    multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("isTop"), m_IsTop));
    multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("setPageNumberOnFirstPage"), m_SetPageNumberOnFirstPage));
}

void PageNumber::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("format")))
    {
        setFormat(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("format"))));
    }
    if(multipart->hasContent(_XPLATSTR("alignment")))
    {
        setAlignment(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("alignment"))));
    }
    setIsTop(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("isTop"))));
    setSetPageNumberOnFirstPage(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("setPageNumberOnFirstPage"))));
}

utility::string_t PageNumber::getFormat() const
{
    return m_Format;
}


void PageNumber::setFormat(utility::string_t value)
{
    m_Format = value;
    m_FormatIsSet = true;
}
bool PageNumber::formatIsSet() const
{
    return m_FormatIsSet;
}

void PageNumber::unsetFormat()
{
    m_FormatIsSet = false;
}

utility::string_t PageNumber::getAlignment() const
{
    return m_Alignment;
}


void PageNumber::setAlignment(utility::string_t value)
{
    m_Alignment = value;
    m_AlignmentIsSet = true;
}
bool PageNumber::alignmentIsSet() const
{
    return m_AlignmentIsSet;
}

void PageNumber::unsetAlignment()
{
    m_AlignmentIsSet = false;
}

bool PageNumber::isIsTop() const
{
    return m_IsTop;
}


void PageNumber::setIsTop(bool value)
{
    m_IsTop = value;
    
}
bool PageNumber::isSetPageNumberOnFirstPage() const
{
    return m_SetPageNumberOnFirstPage;
}


void PageNumber::setSetPageNumberOnFirstPage(bool value)
{
    m_SetPageNumberOnFirstPage = value;
    
}
}
}
}
}
}

