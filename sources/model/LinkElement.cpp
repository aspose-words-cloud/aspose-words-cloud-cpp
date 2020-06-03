/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="LinkElement.cpp">
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

#include "LinkElement.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

LinkElement::LinkElement()
{
    m_LinkIsSet = false;

}

LinkElement::~LinkElement()
{
}

void LinkElement::validate()
{
    // TODO: implement validation
}

web::json::value LinkElement::toJson() const
{
    web::json::value val = web::json::value::object();
    if(m_LinkIsSet)
    {
        val[_XPLATSTR("Link")] = ModelBase::toJson(m_Link);
    }

    return val;
}

void LinkElement::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("Link")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Link")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
            newItem->fromJson(fieldValue);
            setLink( newItem );
        }
    }

}

void LinkElement::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_LinkIsSet)
    {
        if (m_Link.get())
        {
            m_Link->toMultipart(multipart, _XPLATSTR("Link."));
        }
    }

}

void LinkElement::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

std::shared_ptr<WordsApiLink> LinkElement::getLink() const
{
    return m_Link;
}


void LinkElement::setLink(std::shared_ptr<WordsApiLink> value)
{
    m_Link = value;
    m_LinkIsSet = true;
}

bool LinkElement::linkIsSet() const
{
    return m_LinkIsSet;
}

void LinkElement::unsetLink()
{
    m_LinkIsSet = false;
}

}
}
}
}
}
