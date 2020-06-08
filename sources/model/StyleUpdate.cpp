/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="StyleUpdate.cpp">
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


#include "StyleUpdate.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

StyleUpdate::StyleUpdate()
{
    m_NextParagraphStyleName = utility::conversions::to_string_t("");
    m_NextParagraphStyleNameIsSet = false;
    m_BaseStyleName = utility::conversions::to_string_t("");
    m_BaseStyleNameIsSet = false;
    m_IsQuickStyle = false;
    m_IsQuickStyleIsSet = false;
    m_Name = utility::conversions::to_string_t("");
    m_NameIsSet = false;
}

StyleUpdate::~StyleUpdate()
{
}

void StyleUpdate::validate()
{
    // TODO: implement validation
}

web::json::value StyleUpdate::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_NextParagraphStyleNameIsSet)
    {
        val[_XPLATSTR("NextParagraphStyleName")] = ModelBase::toJson(m_NextParagraphStyleName);
    }
    if(m_BaseStyleNameIsSet)
    {
        val[_XPLATSTR("BaseStyleName")] = ModelBase::toJson(m_BaseStyleName);
    }
    if(m_IsQuickStyleIsSet)
    {
        val[_XPLATSTR("IsQuickStyle")] = ModelBase::toJson(m_IsQuickStyle);
    }
    if(m_NameIsSet)
    {
        val[_XPLATSTR("Name")] = ModelBase::toJson(m_Name);
    }

    return val;
}

void StyleUpdate::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("NextParagraphStyleName")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("NextParagraphStyleName")];
        if(!fieldValue.is_null())
        {
            setNextParagraphStyleName(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("BaseStyleName")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("BaseStyleName")];
        if(!fieldValue.is_null())
        {
            setBaseStyleName(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("IsQuickStyle")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("IsQuickStyle")];
        if(!fieldValue.is_null())
        {
            setIsQuickStyle(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Name")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Name")];
        if(!fieldValue.is_null())
        {
            setName(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void StyleUpdate::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_NextParagraphStyleNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("NextParagraphStyleName"), m_NextParagraphStyleName));
        
    }
    if(m_BaseStyleNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("BaseStyleName"), m_BaseStyleName));
        
    }
    if(m_IsQuickStyleIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("IsQuickStyle"), m_IsQuickStyle));
        
    }
    if(m_NameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Name"), m_Name));
        
    }
}

void StyleUpdate::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    

    if(multipart->hasContent(_XPLATSTR("NextParagraphStyleName")))
    {
        setNextParagraphStyleName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("NextParagraphStyleName"))));
    }
    if(multipart->hasContent(_XPLATSTR("BaseStyleName")))
    {
        setBaseStyleName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("BaseStyleName"))));
    }
    if(multipart->hasContent(_XPLATSTR("IsQuickStyle")))
    {
        setIsQuickStyle(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("IsQuickStyle"))));
    }
    if(multipart->hasContent(_XPLATSTR("Name")))
    {
        setName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Name"))));
    }
}

utility::string_t StyleUpdate::getNextParagraphStyleName() const
{
    return m_NextParagraphStyleName;
}


void StyleUpdate::setNextParagraphStyleName(utility::string_t value)
{
    m_NextParagraphStyleName = value;
    m_NextParagraphStyleNameIsSet = true;
}
bool StyleUpdate::nextParagraphStyleNameIsSet() const
{
    return m_NextParagraphStyleNameIsSet;
}

void StyleUpdate::unsetNextParagraphStyleName()
{
    m_NextParagraphStyleNameIsSet = false;
}

utility::string_t StyleUpdate::getBaseStyleName() const
{
    return m_BaseStyleName;
}


void StyleUpdate::setBaseStyleName(utility::string_t value)
{
    m_BaseStyleName = value;
    m_BaseStyleNameIsSet = true;
}
bool StyleUpdate::baseStyleNameIsSet() const
{
    return m_BaseStyleNameIsSet;
}

void StyleUpdate::unsetBaseStyleName()
{
    m_BaseStyleNameIsSet = false;
}

bool StyleUpdate::isIsQuickStyle() const
{
    return m_IsQuickStyle;
}


void StyleUpdate::setIsQuickStyle(bool value)
{
    m_IsQuickStyle = value;
    m_IsQuickStyleIsSet = true;
}
bool StyleUpdate::isQuickStyleIsSet() const
{
    return m_IsQuickStyleIsSet;
}

void StyleUpdate::unsetIsQuickStyle()
{
    m_IsQuickStyleIsSet = false;
}

utility::string_t StyleUpdate::getName() const
{
    return m_Name;
}


void StyleUpdate::setName(utility::string_t value)
{
    m_Name = value;
    m_NameIsSet = true;
}
bool StyleUpdate::nameIsSet() const
{
    return m_NameIsSet;
}

void StyleUpdate::unsetName()
{
    m_NameIsSet = false;
}

}
}
}
}
}

