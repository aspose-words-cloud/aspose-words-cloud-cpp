/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TabStop.cpp">
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

#include "TabStop.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

TabStop::TabStop()
{
    m_IsClear = false;
    m_IsClearIsSet = false;

}

TabStop::~TabStop()
{
}

void TabStop::validate()
{
    // TODO: implement validation
}

web::json::value TabStop::toJson() const
{
    web::json::value val = this->TabStopBase::toJson();
    if(m_IsClearIsSet)
    {
        val[_XPLATSTR("IsClear")] = ModelBase::toJson(m_IsClear);
    }

    return val;
}

void TabStop::fromJson(web::json::value& val)
{
    this->TabStopBase::fromJson(val);

    if(val.has_field(_XPLATSTR("IsClear")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("IsClear")];
        if(!fieldValue.is_null())
        {
           setIsClear(ModelBase::booleanFromJson(fieldValue));
        }
    }

}

void TabStop::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    TabStopBase::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_IsClearIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("IsClear"), m_IsClear));
    }

}

void TabStop::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

bool TabStop::isIsClear() const
{
    return m_IsClear;
}


void TabStop::setIsClear(bool value)
{
    m_IsClear = value;
    m_IsClearIsSet = true;
}

bool TabStop::isClearIsSet() const
{
    return m_IsClearIsSet;
}

void TabStop::unsetIsClear()
{
    m_IsClearIsSet = false;
}

}
}
}
}
}
