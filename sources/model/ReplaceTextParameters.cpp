/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ReplaceTextParameters.cpp">
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

#include "ReplaceTextParameters.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

ReplaceTextParameters::ReplaceTextParameters()
{
    m_IsMatchCase = false;
    m_IsMatchCaseIsSet = false;
    m_IsMatchWholeWord = false;
    m_IsMatchWholeWordIsSet = false;
    m_IsOldValueRegex = false;
    m_IsOldValueRegexIsSet = false;
    m_NewValue = utility::conversions::to_string_t("");
    m_NewValueIsSet = false;
    m_OldValue = utility::conversions::to_string_t("");
    m_OldValueIsSet = false;

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
    if(m_IsMatchCaseIsSet)
    {
        val[_XPLATSTR("IsMatchCase")] = ModelBase::toJson(m_IsMatchCase);
    }
    if(m_IsMatchWholeWordIsSet)
    {
        val[_XPLATSTR("IsMatchWholeWord")] = ModelBase::toJson(m_IsMatchWholeWord);
    }
    if(m_IsOldValueRegexIsSet)
    {
        val[_XPLATSTR("IsOldValueRegex")] = ModelBase::toJson(m_IsOldValueRegex);
    }
    if(m_NewValueIsSet)
    {
        val[_XPLATSTR("NewValue")] = ModelBase::toJson(m_NewValue);
    }
    if(m_OldValueIsSet)
    {
        val[_XPLATSTR("OldValue")] = ModelBase::toJson(m_OldValue);
    }

    return val;
}

void ReplaceTextParameters::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("IsMatchCase")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("IsMatchCase")];
        if(!fieldValue.is_null())
        {
           setIsMatchCase(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("IsMatchWholeWord")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("IsMatchWholeWord")];
        if(!fieldValue.is_null())
        {
           setIsMatchWholeWord(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("IsOldValueRegex")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("IsOldValueRegex")];
        if(!fieldValue.is_null())
        {
           setIsOldValueRegex(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("NewValue")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("NewValue")];
        if(!fieldValue.is_null())
        {
           setNewValue(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("OldValue")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("OldValue")];
        if(!fieldValue.is_null())
        {
           setOldValue(ModelBase::stringFromJson(fieldValue));
        }
    }

}

void ReplaceTextParameters::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_IsMatchCaseIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("IsMatchCase"), m_IsMatchCase));
    }


    if(m_IsMatchWholeWordIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("IsMatchWholeWord"), m_IsMatchWholeWord));
    }


    if(m_IsOldValueRegexIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("IsOldValueRegex"), m_IsOldValueRegex));
    }


    if(m_NewValueIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("NewValue"), m_NewValue));
    }


    if(m_OldValueIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("OldValue"), m_OldValue));
    }

}

void ReplaceTextParameters::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

bool ReplaceTextParameters::isIsMatchCase() const
{
    return m_IsMatchCase;
}


void ReplaceTextParameters::setIsMatchCase(bool value)
{
    m_IsMatchCase = value;
    m_IsMatchCaseIsSet = true;
}

bool ReplaceTextParameters::isMatchCaseIsSet() const
{
    return m_IsMatchCaseIsSet;
}

void ReplaceTextParameters::unsetIsMatchCase()
{
    m_IsMatchCaseIsSet = false;
}

bool ReplaceTextParameters::isIsMatchWholeWord() const
{
    return m_IsMatchWholeWord;
}


void ReplaceTextParameters::setIsMatchWholeWord(bool value)
{
    m_IsMatchWholeWord = value;
    m_IsMatchWholeWordIsSet = true;
}

bool ReplaceTextParameters::isMatchWholeWordIsSet() const
{
    return m_IsMatchWholeWordIsSet;
}

void ReplaceTextParameters::unsetIsMatchWholeWord()
{
    m_IsMatchWholeWordIsSet = false;
}

bool ReplaceTextParameters::isIsOldValueRegex() const
{
    return m_IsOldValueRegex;
}


void ReplaceTextParameters::setIsOldValueRegex(bool value)
{
    m_IsOldValueRegex = value;
    m_IsOldValueRegexIsSet = true;
}

bool ReplaceTextParameters::isOldValueRegexIsSet() const
{
    return m_IsOldValueRegexIsSet;
}

void ReplaceTextParameters::unsetIsOldValueRegex()
{
    m_IsOldValueRegexIsSet = false;
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

}
}
}
}
}
