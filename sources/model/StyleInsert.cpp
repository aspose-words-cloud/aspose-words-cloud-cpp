/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="StyleInsert.cpp">
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

#include "StyleInsert.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

StyleInsert::StyleInsert()
{
    m_StyleName = utility::conversions::to_string_t("");
    m_StyleNameIsSet = false;

    m_StyleTypeIsSet = false;

}

StyleInsert::~StyleInsert()
{
}

void StyleInsert::validate()
{
    // TODO: implement validation
}

web::json::value StyleInsert::toJson() const
{
    web::json::value val = web::json::value::object();
    if(m_StyleNameIsSet)
    {
        val[_XPLATSTR("StyleName")] = ModelBase::toJson(m_StyleName);
    }
    if(m_StyleTypeIsSet)
    {
        val[_XPLATSTR("StyleType")] = ModelBase::toJson(m_StyleType);
    }

    return val;
}

void StyleInsert::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("StyleName")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("StyleName")];
        if(!fieldValue.is_null())
        {
           setStyleName(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("StyleType")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("StyleType")];
        if(!fieldValue.is_null())
        {
           setStyleType(ModelBase::enumFromJson(fieldValue));
        }
    }

}

void StyleInsert::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_StyleNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("StyleName"), m_StyleName));
    }


    if(m_StyleTypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("StyleType"), m_StyleType));
    }

}

void StyleInsert::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

utility::string_t StyleInsert::getStyleName() const
{
    return m_StyleName;
}


void StyleInsert::setStyleName(utility::string_t value)
{
    m_StyleName = value;
    m_StyleNameIsSet = true;
}

bool StyleInsert::styleNameIsSet() const
{
    return m_StyleNameIsSet;
}

void StyleInsert::unsetStyleName()
{
    m_StyleNameIsSet = false;
}

utility::string_t StyleInsert::getStyleType() const
{
    return m_StyleType;
}


void StyleInsert::setStyleType(utility::string_t value)
{
    m_StyleType = value;
    m_StyleTypeIsSet = true;
}

bool StyleInsert::styleTypeIsSet() const
{
    return m_StyleTypeIsSet;
}

void StyleInsert::unsetStyleType()
{
    m_StyleTypeIsSet = false;
}

}
}
}
}
}
