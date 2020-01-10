/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ReplaceTextParameters.cpp">
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


#include "ReplaceTextParameters.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

ReplaceTextParameters::ReplaceTextParameters()
{
    m_OldValue = utility::conversions::to_string_t("");
    m_OldValueIsSet = false;
    m_NewValue = utility::conversions::to_string_t("");
    m_NewValueIsSet = false;
    m_IsMatchCase = false;
    m_IsMatchWholeWord = false;
    m_IsOldValueRegex = false;
}

ReplaceTextParameters::~ReplaceTextParameters()
{
}

void ReplaceTextParameters::validate()
{
    // TODO: implement validation
}

web::json::value ReplaceTextParameters::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_OldValueIsSet)
    {
        val[_XPLATSTR("oldValue")] = ModelBase::toJson(m_OldValue);
    }
    if(m_NewValueIsSet)
    {
        val[_XPLATSTR("newValue")] = ModelBase::toJson(m_NewValue);
    }
    val[_XPLATSTR("isMatchCase")] = ModelBase::toJson(m_IsMatchCase);
    val[_XPLATSTR("isMatchWholeWord")] = ModelBase::toJson(m_IsMatchWholeWord);
    val[_XPLATSTR("isOldValueRegex")] = ModelBase::toJson(m_IsOldValueRegex);

    return val;
}

void ReplaceTextParameters::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("oldValue")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("oldValue")];
        if(!fieldValue.is_null())
        {
            setOldValue(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("newValue")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("newValue")];
        if(!fieldValue.is_null())
        {
            setNewValue(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("isMatchCase")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("isMatchCase")];
        if(!fieldValue.is_null())
        {
            setIsMatchCase(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("isMatchWholeWord")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("isMatchWholeWord")];
        if(!fieldValue.is_null())
        {
            setIsMatchWholeWord(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("isOldValueRegex")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("isOldValueRegex")];
        if(!fieldValue.is_null())
        {
            setIsOldValueRegex(ModelBase::boolFromJson(fieldValue));
        }
    }
}

void ReplaceTextParameters::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_OldValueIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("oldValue"), m_OldValue));
        
    }
    if(m_NewValueIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("newValue"), m_NewValue));
        
    }
    multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("isMatchCase"), m_IsMatchCase));
    multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("isMatchWholeWord"), m_IsMatchWholeWord));
    multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("isOldValueRegex"), m_IsOldValueRegex));
}

void ReplaceTextParameters::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("oldValue")))
    {
        setOldValue(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("oldValue"))));
    }
    if(multipart->hasContent(_XPLATSTR("newValue")))
    {
        setNewValue(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("newValue"))));
    }
    setIsMatchCase(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("isMatchCase"))));
    setIsMatchWholeWord(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("isMatchWholeWord"))));
    setIsOldValueRegex(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("isOldValueRegex"))));
}

utility::string_t ReplaceTextParameters::getOldValue() const
{
    return m_OldValue;
}


void ReplaceTextParameters::setOldValue(utility::string_t value)
{
    m_OldValue = value;
    m_OldValueIsSet = true;
}
bool ReplaceTextParameters::oldValueIsSet() const
{
    return m_OldValueIsSet;
}

void ReplaceTextParameters::unsetOldValue()
{
    m_OldValueIsSet = false;
}

utility::string_t ReplaceTextParameters::getNewValue() const
{
    return m_NewValue;
}


void ReplaceTextParameters::setNewValue(utility::string_t value)
{
    m_NewValue = value;
    m_NewValueIsSet = true;
}
bool ReplaceTextParameters::newValueIsSet() const
{
    return m_NewValueIsSet;
}

void ReplaceTextParameters::unsetNewValue()
{
    m_NewValueIsSet = false;
}

bool ReplaceTextParameters::isIsMatchCase() const
{
    return m_IsMatchCase;
}


void ReplaceTextParameters::setIsMatchCase(bool value)
{
    m_IsMatchCase = value;
    
}
bool ReplaceTextParameters::isIsMatchWholeWord() const
{
    return m_IsMatchWholeWord;
}


void ReplaceTextParameters::setIsMatchWholeWord(bool value)
{
    m_IsMatchWholeWord = value;
    
}
bool ReplaceTextParameters::isIsOldValueRegex() const
{
    return m_IsOldValueRegex;
}


void ReplaceTextParameters::setIsOldValueRegex(bool value)
{
    m_IsOldValueRegex = value;
    
}
}
}
}
}
}

