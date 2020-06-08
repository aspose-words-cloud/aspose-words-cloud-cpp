/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ParagraphListFormatResponse.cpp">
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


#include "ParagraphListFormatResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

ParagraphListFormatResponse::ParagraphListFormatResponse()
{
    m_ListFormatIsSet = false;
}

ParagraphListFormatResponse::~ParagraphListFormatResponse()
{
}

void ParagraphListFormatResponse::validate()
{
    // TODO: implement validation
}

web::json::value ParagraphListFormatResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();

    if(m_ListFormatIsSet)
    {
        val[_XPLATSTR("ListFormat")] = ModelBase::toJson(m_ListFormat);
    }

    return val;
}

void ParagraphListFormatResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("ListFormat")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ListFormat")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<ListFormat> newItem(new ListFormat());
            newItem->fromJson(fieldValue);
            setListFormat( newItem );
        }
    }
}

void ParagraphListFormatResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    WordsResponse::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_ListFormatIsSet)
    {
        if (m_ListFormat.get())
        {
            m_ListFormat->toMultipart(multipart, _XPLATSTR("ListFormat."));
        }
        
    }
}

void ParagraphListFormatResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    WordsResponse::fromMultiPart(multipart, prefix);

    if(multipart->hasContent(_XPLATSTR("ListFormat")))
    {
        if(multipart->hasContent(_XPLATSTR("ListFormat")))
        {
            std::shared_ptr<ListFormat> newItem(new ListFormat());
            newItem->fromMultiPart(multipart, _XPLATSTR("ListFormat."));
            setListFormat( newItem );
        }
    }
}

std::shared_ptr<ListFormat> ParagraphListFormatResponse::getListFormat() const
{
    return m_ListFormat;
}


void ParagraphListFormatResponse::setListFormat(std::shared_ptr<ListFormat> value)
{
    m_ListFormat = value;
    m_ListFormatIsSet = true;
}
bool ParagraphListFormatResponse::listFormatIsSet() const
{
    return m_ListFormatIsSet;
}

void ParagraphListFormatResponse::unsetListFormat()
{
    m_ListFormatIsSet = false;
}

}
}
}
}
}

