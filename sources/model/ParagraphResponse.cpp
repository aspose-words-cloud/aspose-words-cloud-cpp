/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ParagraphResponse.cpp">
*   Copyright (c) 2020 Aspose.Words for Cloud
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

#include "ParagraphResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

ParagraphResponse::ParagraphResponse()
{
    m_ParagraphIsSet = false;

}

ParagraphResponse::~ParagraphResponse()
{
}

void ParagraphResponse::validate()
{
    // TODO: implement validation
}

web::json::value ParagraphResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();
    if(m_ParagraphIsSet)
    {
        val[_XPLATSTR("Paragraph")] = ModelBase::toJson(m_Paragraph);
    }

    return val;
}

void ParagraphResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("Paragraph")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Paragraph")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Paragraph> newItem(new Paragraph());
            newItem->fromJson(fieldValue);
        }
    }

}

void ParagraphResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    WordsResponse::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_ParagraphIsSet)
    {
        if (m_Paragraph.get())
        {
            m_Paragraph->toMultipart(multipart, _XPLATSTR("Paragraph."));
        }
    }

}

void ParagraphResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

std::shared_ptr<Paragraph> ParagraphResponse::getParagraph() const
{
    return m_Paragraph;
}


void ParagraphResponse::setParagraph(std::shared_ptr<Paragraph> value)
{
    m_Paragraph = value;
    m_ParagraphIsSet = true;
}

bool ParagraphResponse::paragraphIsSet() const
{
    return m_ParagraphIsSet;
}

void ParagraphResponse::unsetParagraph()
{
    m_ParagraphIsSet = false;
}

}
}
}
}
}
