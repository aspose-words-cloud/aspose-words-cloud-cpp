/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="BordersResponse.cpp">
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


#include "BordersResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

BordersResponse::BordersResponse()
{
    m_BordersIsSet = false;
}

BordersResponse::~BordersResponse()
{
}

void BordersResponse::validate()
{
    // TODO: implement validation
}

web::json::value BordersResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();

    if(m_BordersIsSet)
    {
        val[_XPLATSTR("borders")] = ModelBase::toJson(m_Borders);
    }

    return val;
}

void BordersResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("borders")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("borders")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<BordersCollection> newItem(new BordersCollection());
            newItem->fromJson(fieldValue);
            setBorders( newItem );
        }
    }
}

void BordersResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_RequestIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("requestId"), m_RequestId));
        
    }
    if(m_BordersIsSet)
    {
        if (m_Borders.get())
        {
            m_Borders->toMultipart(multipart, _XPLATSTR("borders."));
        }
        
    }
}

void BordersResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("requestId")))
    {
        setRequestId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("requestId"))));
    }
    if(multipart->hasContent(_XPLATSTR("borders")))
    {
        if(multipart->hasContent(_XPLATSTR("borders")))
        {
            std::shared_ptr<BordersCollection> newItem(new BordersCollection());
            newItem->fromMultiPart(multipart, _XPLATSTR("borders."));
            setBorders( newItem );
        }
    }
}

std::shared_ptr<BordersCollection> BordersResponse::getBorders() const
{
    return m_Borders;
}


void BordersResponse::setBorders(std::shared_ptr<BordersCollection> value)
{
    m_Borders = value;
    m_BordersIsSet = true;
}
bool BordersResponse::bordersIsSet() const
{
    return m_BordersIsSet;
}

void BordersResponse::unsetBorders()
{
    m_BordersIsSet = false;
}

}
}
}
}
}

