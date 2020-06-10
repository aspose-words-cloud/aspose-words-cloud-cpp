/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="BorderResponse.cpp">
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

#include "BorderResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

BorderResponse::BorderResponse()
{
    m_BorderIsSet = false;

}

BorderResponse::~BorderResponse()
{
}

void BorderResponse::validate()
{
    // TODO: implement validation
}

web::json::value BorderResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();
    if(m_BorderIsSet)
    {
        val[_XPLATSTR("Border")] = ModelBase::toJson(m_Border);
    }

    return val;
}

void BorderResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("Border")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Border")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Border> newItem(new Border());
            newItem->fromJson(fieldValue);
            setBorder( newItem );
        }
    }

}

void BorderResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    WordsResponse::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_BorderIsSet)
    {
        if (m_Border.get())
        {
            m_Border->toMultipart(multipart, _XPLATSTR("Border."));
        }
    }

}

void BorderResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

std::shared_ptr<Border> BorderResponse::getBorder() const
{
    return m_Border;
}


void BorderResponse::setBorder(std::shared_ptr<Border> value)
{
    m_Border = value;
    m_BorderIsSet = true;
}

bool BorderResponse::borderIsSet() const
{
    return m_BorderIsSet;
}

void BorderResponse::unsetBorder()
{
    m_BorderIsSet = false;
}

}
}
}
}
}
