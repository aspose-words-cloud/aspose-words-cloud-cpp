/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="StyleCopy.cpp">
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

#include "StyleCopy.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

StyleCopy::StyleCopy()
{
    m_StyleName = utility::conversions::to_string_t("");
    m_StyleNameIsSet = false;

}

StyleCopy::~StyleCopy()
{
}

void StyleCopy::validate()
{
    // TODO: implement validation
}

web::json::value StyleCopy::toJson() const
{
    web::json::value val = web::json::value::object();
    if(m_StyleNameIsSet)
    {
        val[_XPLATSTR("StyleName")] = ModelBase::toJson(m_StyleName);
    }

    return val;
}

void StyleCopy::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("StyleName")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("StyleName")];
        if(!fieldValue.is_null())
        {
           setStyleName(ModelBase::stringFromJson(fieldValue));
        }
    }

}

void StyleCopy::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_StyleNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("StyleName"), m_StyleName));
    }

}

void StyleCopy::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

utility::string_t StyleCopy::getStyleName() const
{
    return m_StyleName;
}


void StyleCopy::setStyleName(utility::string_t value)
{
    m_StyleName = value;
    m_StyleNameIsSet = true;
}

bool StyleCopy::styleNameIsSet() const
{
    return m_StyleNameIsSet;
}

void StyleCopy::unsetStyleName()
{
    m_StyleNameIsSet = false;
}

}
}
}
}
}
