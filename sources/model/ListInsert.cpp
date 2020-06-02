/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ListInsert.cpp">
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

#include "ListInsert.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

ListInsert::ListInsert()
{
    m_TemplateIsSet = false;

}

ListInsert::~ListInsert()
{
}

void ListInsert::validate()
{
    // TODO: implement validation
}

web::json::value ListInsert::toJson() const
{
    web::json::value val = web::json::value::object();
    if(m_TemplateIsSet)
    {
        val[_XPLATSTR("Template")] = ModelBase::toJson(m_Template);
    }

    return val;
}

void ListInsert::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("Template")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Template")];
        if(!fieldValue.is_null())
        {
           setTemplate(ModelBase::enumFromJson(fieldValue));
        }
    }

}

void ListInsert::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_TemplateIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Template"), m_Template));
    }

}

void ListInsert::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

utility::string_t ListInsert::getTemplate() const
{
    return m_Template;
}


void ListInsert::setTemplate(utility::string_t value)
{
    m_Template = value;
    m_TemplateIsSet = true;
}

bool ListInsert::_templateIsSet() const
{
    return m_TemplateIsSet;
}

void ListInsert::unsetTemplate()
{
    m_TemplateIsSet = false;
}

}
}
}
}
}
