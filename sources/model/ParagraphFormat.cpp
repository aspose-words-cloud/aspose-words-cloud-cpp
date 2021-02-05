/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ParagraphFormat.cpp">
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

#include "ParagraphFormat.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

ParagraphFormat::ParagraphFormat()
{
    m_IsHeading = false;
    m_IsHeadingIsSet = false;
    m_IsListItem = false;
    m_IsListItemIsSet = false;

}

ParagraphFormat::~ParagraphFormat()
{
}

void ParagraphFormat::validate()
{
    // TODO: implement validation
}

web::json::value ParagraphFormat::toJson() const
{
    web::json::value val = this->ParagraphFormatBase::toJson();
    if(m_IsHeadingIsSet)
    {
        val[_XPLATSTR("IsHeading")] = ModelBase::toJson(m_IsHeading);
    }
    if(m_IsListItemIsSet)
    {
        val[_XPLATSTR("IsListItem")] = ModelBase::toJson(m_IsListItem);
    }

    return val;
}

void ParagraphFormat::fromJson(web::json::value& val)
{
    this->ParagraphFormatBase::fromJson(val);

    if(val.has_field(_XPLATSTR("IsHeading")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("IsHeading")];
        if(!fieldValue.is_null())
        {
           setIsHeading(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("IsListItem")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("IsListItem")];
        if(!fieldValue.is_null())
        {
           setIsListItem(ModelBase::booleanFromJson(fieldValue));
        }
    }

}

void ParagraphFormat::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    ParagraphFormatBase::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_IsHeadingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("IsHeading"), m_IsHeading));
    }


    if(m_IsListItemIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("IsListItem"), m_IsListItem));
    }

}

void ParagraphFormat::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

bool ParagraphFormat::isIsHeading() const
{
    return m_IsHeading;
}


void ParagraphFormat::setIsHeading(bool value)
{
    m_IsHeading = value;
    m_IsHeadingIsSet = true;
}

bool ParagraphFormat::isHeadingIsSet() const
{
    return m_IsHeadingIsSet;
}

void ParagraphFormat::unsetIsHeading()
{
    m_IsHeadingIsSet = false;
}

bool ParagraphFormat::isIsListItem() const
{
    return m_IsListItem;
}


void ParagraphFormat::setIsListItem(bool value)
{
    m_IsListItem = value;
    m_IsListItemIsSet = true;
}

bool ParagraphFormat::isListItemIsSet() const
{
    return m_IsListItemIsSet;
}

void ParagraphFormat::unsetIsListItem()
{
    m_IsListItemIsSet = false;
}

}
}
}
}
}
