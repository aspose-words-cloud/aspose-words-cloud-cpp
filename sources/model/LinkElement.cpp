/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="LinkElement.cpp">
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
        val[_XPLATSTR("link")] = ModelBase::toJson(m_Link);
    }

    return val;
}

void LinkElement::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("link")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("link")];
        if(!fieldValue.is_null())
        {
            <DATA_TYPE_START>WordsApiLink<DATA_TYPE_END> newItem(new WordsApiLink());
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
            m_Link->toMultipart(multipart, _XPLATSTR("link."));
        }
        
    }
}

void LinkElement::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    

    if(multipart->hasContent(_XPLATSTR("link")))
    {
        if(multipart->hasContent(_XPLATSTR("link")))
        {
            <DATA_TYPE_START>WordsApiLink<DATA_TYPE_END> newItem(new WordsApiLink());
            newItem->fromMultiPart(multipart, _XPLATSTR("link."));
            setLink( newItem );
        }
    }
}

<DATA_TYPE_START>WordsApiLink<DATA_TYPE_END> LinkElement::getLink() const
{
    return m_Link;
}


void LinkElement::setLink(<DATA_TYPE_START>WordsApiLink<DATA_TYPE_END> value)
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

