/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FormFieldTextInput.cpp">
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


#include "FormFieldTextInput.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

FormFieldTextInput::FormFieldTextInput()
{
    m_MaxLength = 0;
    m_MaxLengthIsSet = false;
    m_TextInputDefault = utility::conversions::to_string_t("");
    m_TextInputDefaultIsSet = false;
    m_TextInputFormat = utility::conversions::to_string_t("");
    m_TextInputFormatIsSet = false;
    m_TextInputType = utility::conversions::to_string_t("");
    m_TextInputTypeIsSet = false;
}

FormFieldTextInput::~FormFieldTextInput()
{
}

void FormFieldTextInput::validate()
{
    // TODO: implement validation
}

web::json::value FormFieldTextInput::toJson() const
{
    web::json::value val = this->FormField::toJson();

    if(m_MaxLengthIsSet)
    {
        val[_XPLATSTR("maxLength")] = ModelBase::toJson(m_MaxLength);
    }
    if(m_TextInputDefaultIsSet)
    {
        val[_XPLATSTR("textInputDefault")] = ModelBase::toJson(m_TextInputDefault);
    }
    if(m_TextInputFormatIsSet)
    {
        val[_XPLATSTR("textInputFormat")] = ModelBase::toJson(m_TextInputFormat);
    }
    if(m_TextInputTypeIsSet)
    {
        val[_XPLATSTR("textInputType")] = ModelBase::toJson(m_TextInputType);
    }

    return val;
}

void FormFieldTextInput::fromJson(web::json::value& val)
{
    this->FormField::fromJson(val);

    if(val.has_field(_XPLATSTR("maxLength")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("maxLength")];
        if(!fieldValue.is_null())
        {
            setMaxLength(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("textInputDefault")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("textInputDefault")];
        if(!fieldValue.is_null())
        {
            setTextInputDefault(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("textInputFormat")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("textInputFormat")];
        if(!fieldValue.is_null())
        {
            setTextInputFormat(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("textInputType")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("textInputType")];
        if(!fieldValue.is_null())
        {
            setTextInputType(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void FormFieldTextInput::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_LinkIsSet)
    {
        if (m_Link.get())
        {
            m_Link->toMultipart(multipart, _XPLATSTR("link."));
        }
        
    }
    if(m_NodeIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("nodeId"), m_NodeId));
        
    }
    if(m_CalculateOnExitIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("calculateOnExit"), m_CalculateOnExit));
    }
    if(m_EnabledIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("enabled"), m_Enabled));
    }
    if(m_EntryMacroIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("entryMacro"), m_EntryMacro));
        
    }
    if(m_ExitMacroIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exitMacro"), m_ExitMacro));
        
    }
    if(m_HelpTextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("helpText"), m_HelpText));
        
    }
    if(m_NameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("name"), m_Name));
        
    }
    if(m_OwnHelpIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ownHelp"), m_OwnHelp));
    }
    if(m_OwnStatusIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ownStatus"), m_OwnStatus));
    }
    if(m_StatusTextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("statusText"), m_StatusText));
        
    }
    if(m_MaxLengthIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("maxLength"), m_MaxLength));
    }
    if(m_TextInputDefaultIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("textInputDefault"), m_TextInputDefault));
        
    }
    if(m_TextInputFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("textInputFormat"), m_TextInputFormat));
        
    }
    if(m_TextInputTypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("textInputType"), m_TextInputType));
        
    }
}

void FormFieldTextInput::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("link")))
    {
        if(multipart->hasContent(_XPLATSTR("link")))
        {
            std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
            newItem->fromMultiPart(multipart, _XPLATSTR("link."));
            setLink( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("nodeId")))
    {
        setNodeId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("nodeId"))));
    }
    if(multipart->hasContent(_XPLATSTR("calculateOnExit")))
    {
        setCalculateOnExit(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("calculateOnExit"))));
    }
    if(multipart->hasContent(_XPLATSTR("enabled")))
    {
        setEnabled(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("enabled"))));
    }
    if(multipart->hasContent(_XPLATSTR("entryMacro")))
    {
        setEntryMacro(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("entryMacro"))));
    }
    if(multipart->hasContent(_XPLATSTR("exitMacro")))
    {
        setExitMacro(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("exitMacro"))));
    }
    if(multipart->hasContent(_XPLATSTR("helpText")))
    {
        setHelpText(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("helpText"))));
    }
    if(multipart->hasContent(_XPLATSTR("name")))
    {
        setName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("name"))));
    }
    if(multipart->hasContent(_XPLATSTR("ownHelp")))
    {
        setOwnHelp(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ownHelp"))));
    }
    if(multipart->hasContent(_XPLATSTR("ownStatus")))
    {
        setOwnStatus(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ownStatus"))));
    }
    if(multipart->hasContent(_XPLATSTR("statusText")))
    {
        setStatusText(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("statusText"))));
    }
    if(multipart->hasContent(_XPLATSTR("maxLength")))
    {
        setMaxLength(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("maxLength"))));
    }
    if(multipart->hasContent(_XPLATSTR("textInputDefault")))
    {
        setTextInputDefault(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("textInputDefault"))));
    }
    if(multipart->hasContent(_XPLATSTR("textInputFormat")))
    {
        setTextInputFormat(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("textInputFormat"))));
    }
    if(multipart->hasContent(_XPLATSTR("textInputType")))
    {
        setTextInputType(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("textInputType"))));
    }
}

int32_t FormFieldTextInput::getMaxLength() const
{
    return m_MaxLength;
}


void FormFieldTextInput::setMaxLength(int32_t value)
{
    m_MaxLength = value;
    m_MaxLengthIsSet = true;
}
bool FormFieldTextInput::maxLengthIsSet() const
{
    return m_MaxLengthIsSet;
}

void FormFieldTextInput::unsetMaxLength()
{
    m_MaxLengthIsSet = false;
}

utility::string_t FormFieldTextInput::getTextInputDefault() const
{
    return m_TextInputDefault;
}


void FormFieldTextInput::setTextInputDefault(utility::string_t value)
{
    m_TextInputDefault = value;
    m_TextInputDefaultIsSet = true;
}
bool FormFieldTextInput::textInputDefaultIsSet() const
{
    return m_TextInputDefaultIsSet;
}

void FormFieldTextInput::unsetTextInputDefault()
{
    m_TextInputDefaultIsSet = false;
}

utility::string_t FormFieldTextInput::getTextInputFormat() const
{
    return m_TextInputFormat;
}


void FormFieldTextInput::setTextInputFormat(utility::string_t value)
{
    m_TextInputFormat = value;
    m_TextInputFormatIsSet = true;
}
bool FormFieldTextInput::textInputFormatIsSet() const
{
    return m_TextInputFormatIsSet;
}

void FormFieldTextInput::unsetTextInputFormat()
{
    m_TextInputFormatIsSet = false;
}

utility::string_t FormFieldTextInput::getTextInputType() const
{
    return m_TextInputType;
}


void FormFieldTextInput::setTextInputType(utility::string_t value)
{
    m_TextInputType = value;
    m_TextInputTypeIsSet = true;
}
bool FormFieldTextInput::textInputTypeIsSet() const
{
    return m_TextInputTypeIsSet;
}

void FormFieldTextInput::unsetTextInputType()
{
    m_TextInputTypeIsSet = false;
}

}
}
}
}
}

