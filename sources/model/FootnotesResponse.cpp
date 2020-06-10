/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FootnotesResponse.cpp">
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

#include "FootnotesResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

FootnotesResponse::FootnotesResponse()
{
    m_FootnotesIsSet = false;

}

FootnotesResponse::~FootnotesResponse()
{
}

void FootnotesResponse::validate()
{
    // TODO: implement validation
}

web::json::value FootnotesResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();
    if(m_FootnotesIsSet)
    {
        val[_XPLATSTR("Footnotes")] = ModelBase::toJson(m_Footnotes);
    }

    return val;
}

void FootnotesResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("Footnotes")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Footnotes")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<FootnoteCollection> newItem(new FootnoteCollection());
            newItem->fromJson(fieldValue);
            setFootnotes( newItem );
        }
    }

}

void FootnotesResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    WordsResponse::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_FootnotesIsSet)
    {
        if (m_Footnotes.get())
        {
            m_Footnotes->toMultipart(multipart, _XPLATSTR("Footnotes."));
        }
    }

}

void FootnotesResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

std::shared_ptr<FootnoteCollection> FootnotesResponse::getFootnotes() const
{
    return m_Footnotes;
}


void FootnotesResponse::setFootnotes(std::shared_ptr<FootnoteCollection> value)
{
    m_Footnotes = value;
    m_FootnotesIsSet = true;
}

bool FootnotesResponse::footnotesIsSet() const
{
    return m_FootnotesIsSet;
}

void FootnotesResponse::unsetFootnotes()
{
    m_FootnotesIsSet = false;
}

}
}
}
}
}
