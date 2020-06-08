/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DocumentPropertyBase.cpp">
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


#include "DocumentPropertyBase.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

DocumentPropertyBase::DocumentPropertyBase()
{
    m_Value = utility::conversions::to_string_t("");
    m_ValueIsSet = false;
}

DocumentPropertyBase::~DocumentPropertyBase()
{
}

void DocumentPropertyBase::validate()
{
    // TODO: implement validation
}

web::json::value DocumentPropertyBase::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_ValueIsSet)
    {
        val[_XPLATSTR("Value")] = ModelBase::toJson(m_Value);
    }

    return val;
}

void DocumentPropertyBase::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("Value")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Value")];
        if(!fieldValue.is_null())
        {
            setValue(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void DocumentPropertyBase::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_ValueIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Value"), m_Value));
        
    }
}

void DocumentPropertyBase::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    

    if(multipart->hasContent(_XPLATSTR("Value")))
    {
        setValue(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Value"))));
    }
}

<DATA_TYPE_START>string<DATA_TYPE_END> DocumentPropertyBase::getValue() const
{
    return m_Value;
}


void DocumentPropertyBase::setValue(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_Value = value;
    m_ValueIsSet = true;
}
bool DocumentPropertyBase::valueIsSet() const
{
    return m_ValueIsSet;
}

void DocumentPropertyBase::unsetValue()
{
    m_ValueIsSet = false;
}

}
}
}
}
}

