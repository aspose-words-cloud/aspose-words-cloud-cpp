/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="XmlColor.cpp">
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


#include "XmlColor.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

XmlColor::XmlColor()
{
    m_Web = utility::conversions::to_string_t("");
    m_WebIsSet = false;
    m_Alpha = 0;
    m_AlphaIsSet = false;
}

XmlColor::~XmlColor()
{
}

void XmlColor::validate()
{
    // TODO: implement validation
}

web::json::value XmlColor::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_WebIsSet)
    {
        val[_XPLATSTR("Web")] = ModelBase::toJson(m_Web);
    }
    if(m_AlphaIsSet)
    {
        val[_XPLATSTR("Alpha")] = ModelBase::toJson(m_Alpha);
    }

    return val;
}

void XmlColor::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("Web")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Web")];
        if(!fieldValue.is_null())
        {
            setWeb(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Alpha")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Alpha")];
        if(!fieldValue.is_null())
        {
            setAlpha(ModelBase::int32_tFromJson(fieldValue));
        }
    }
}

void XmlColor::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_WebIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Web"), m_Web));
        
    }
    if(m_AlphaIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Alpha"), m_Alpha));
        
    }
}

void XmlColor::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    

    if(multipart->hasContent(_XPLATSTR("Web")))
    {
        setWeb(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Web"))));
    }
    if(multipart->hasContent(_XPLATSTR("Alpha")))
    {
        setAlpha(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("Alpha"))));
    }
}

utility::string_t XmlColor::getWeb() const
{
    return m_Web;
}


void XmlColor::setWeb(utility::string_t value)
{
    m_Web = value;
    m_WebIsSet = true;
}
bool XmlColor::webIsSet() const
{
    return m_WebIsSet;
}

void XmlColor::unsetWeb()
{
    m_WebIsSet = false;
}

int32_t XmlColor::getAlpha() const
{
    return m_Alpha;
}


void XmlColor::setAlpha(int32_t value)
{
    m_Alpha = value;
    m_AlphaIsSet = true;
}
bool XmlColor::alphaIsSet() const
{
    return m_AlphaIsSet;
}

void XmlColor::unsetAlpha()
{
    m_AlphaIsSet = false;
}

}
}
}
}
}

