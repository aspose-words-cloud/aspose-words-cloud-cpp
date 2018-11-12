/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ReplaceTextRequest.cpp">
*   Copyright (c) 2018 Aspose.Words for Cloud
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


#include "ReplaceTextRequest.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

ReplaceTextRequest::ReplaceTextRequest()
{
    m_OldValue = utility::conversions::to_string_t("");
    m_OldValueIsSet = false;
    m_NewValue = utility::conversions::to_string_t("");
    m_NewValueIsSet = false;
    m_IsMatchCase = false;
    m_IsMatchWholeWord = false;
    m_IsOldValueRegex = false;
}

ReplaceTextRequest::~ReplaceTextRequest()
{
}

void ReplaceTextRequest::validate()
{
    // TODO: implement validation
}

web::json::value ReplaceTextRequest::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_OldValueIsSet)
    {
        val[utility::conversions::to_string_t("OldValue")] = ModelBase::toJson(m_OldValue);
    }
    if(m_NewValueIsSet)
    {
        val[utility::conversions::to_string_t("NewValue")] = ModelBase::toJson(m_NewValue);
    }
    val[utility::conversions::to_string_t("IsMatchCase")] = ModelBase::toJson(m_IsMatchCase);
    val[utility::conversions::to_string_t("IsMatchWholeWord")] = ModelBase::toJson(m_IsMatchWholeWord);
    val[utility::conversions::to_string_t("IsOldValueRegex")] = ModelBase::toJson(m_IsOldValueRegex);

    return val;
}

void ReplaceTextRequest::fromJson(web::json::value& val)
{
    if(val.has_field(utility::conversions::to_string_t("OldValue")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("OldValue")];
        if(!fieldValue.is_null())
        {
            setOldValue(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("NewValue")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("NewValue")];
        if(!fieldValue.is_null())
        {
            setNewValue(ModelBase::stringFromJson(fieldValue));
        }
    }
    setIsMatchCase(ModelBase::boolFromJson(val[utility::conversions::to_string_t("IsMatchCase")]));
    setIsMatchWholeWord(ModelBase::boolFromJson(val[utility::conversions::to_string_t("IsMatchWholeWord")]));
    setIsOldValueRegex(ModelBase::boolFromJson(val[utility::conversions::to_string_t("IsOldValueRegex")]));
}

void ReplaceTextRequest::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_OldValueIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("OldValue"), m_OldValue));
        
    }
    if(m_NewValueIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("NewValue"), m_NewValue));
        
    }
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("IsMatchCase"), m_IsMatchCase));
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("IsMatchWholeWord"), m_IsMatchWholeWord));
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("IsOldValueRegex"), m_IsOldValueRegex));
}

void ReplaceTextRequest::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("OldValue")))
    {
        setOldValue(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("OldValue"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("NewValue")))
    {
        setNewValue(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("NewValue"))));
    }
    setIsMatchCase(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("IsMatchCase"))));
    setIsMatchWholeWord(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("IsMatchWholeWord"))));
    setIsOldValueRegex(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("IsOldValueRegex"))));
}

utility::string_t ReplaceTextRequest::getOldValue() const
{
    return m_OldValue;
}


void ReplaceTextRequest::setOldValue(utility::string_t value)
{
    m_OldValue = value;
    m_OldValueIsSet = true;
}
bool ReplaceTextRequest::oldValueIsSet() const
{
    return m_OldValueIsSet;
}

void ReplaceTextRequest::unsetOldValue()
{
    m_OldValueIsSet = false;
}

utility::string_t ReplaceTextRequest::getNewValue() const
{
    return m_NewValue;
}


void ReplaceTextRequest::setNewValue(utility::string_t value)
{
    m_NewValue = value;
    m_NewValueIsSet = true;
}
bool ReplaceTextRequest::newValueIsSet() const
{
    return m_NewValueIsSet;
}

void ReplaceTextRequest::unsetNewValue()
{
    m_NewValueIsSet = false;
}

bool ReplaceTextRequest::isIsMatchCase() const
{
    return m_IsMatchCase;
}


void ReplaceTextRequest::setIsMatchCase(bool value)
{
    m_IsMatchCase = value;
    
}
bool ReplaceTextRequest::isIsMatchWholeWord() const
{
    return m_IsMatchWholeWord;
}


void ReplaceTextRequest::setIsMatchWholeWord(bool value)
{
    m_IsMatchWholeWord = value;
    
}
bool ReplaceTextRequest::isIsOldValueRegex() const
{
    return m_IsOldValueRegex;
}


void ReplaceTextRequest::setIsOldValueRegex(bool value)
{
    m_IsOldValueRegex = value;
    
}
}
}
}
}

