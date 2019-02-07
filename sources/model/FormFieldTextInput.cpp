/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FormFieldTextInput.cpp">
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


#include "FormFieldTextInput.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

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
        val[_XPLATSTR("MaxLength")] = ModelBase::toJson(m_MaxLength);
    }
    if(m_TextInputDefaultIsSet)
    {
        val[_XPLATSTR("TextInputDefault")] = ModelBase::toJson(m_TextInputDefault);
    }
    if(m_TextInputFormatIsSet)
    {
        val[_XPLATSTR("TextInputFormat")] = ModelBase::toJson(m_TextInputFormat);
    }
    if(m_TextInputTypeIsSet)
    {
        val[_XPLATSTR("TextInputType")] = ModelBase::toJson(m_TextInputType);
    }

    return val;
}

void FormFieldTextInput::fromJson(web::json::value& val)
{
    this->FormField::fromJson(val);

    if(val.has_field(_XPLATSTR("MaxLength")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("MaxLength")];
        if(!fieldValue.is_null())
        {
            setMaxLength(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("TextInputDefault")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("TextInputDefault")];
        if(!fieldValue.is_null())
        {
            setTextInputDefault(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("TextInputFormat")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("TextInputFormat")];
        if(!fieldValue.is_null())
        {
            setTextInputFormat(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("TextInputType")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("TextInputType")];
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
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("NodeId"), m_NodeId));
        
    }
    if(m_CalculateOnExitIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("CalculateOnExit"), m_CalculateOnExit));
    }
    if(m_EnabledIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Enabled"), m_Enabled));
    }
    if(m_EntryMacroIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("EntryMacro"), m_EntryMacro));
        
    }
    if(m_ExitMacroIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExitMacro"), m_ExitMacro));
        
    }
    if(m_HelpTextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("HelpText"), m_HelpText));
        
    }
    if(m_NameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Name"), m_Name));
        
    }
    if(m_OwnHelpIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("OwnHelp"), m_OwnHelp));
    }
    if(m_OwnStatusIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("OwnStatus"), m_OwnStatus));
    }
    if(m_StatusTextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("StatusText"), m_StatusText));
        
    }
    if(m_MaxLengthIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("MaxLength"), m_MaxLength));
    }
    if(m_TextInputDefaultIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TextInputDefault"), m_TextInputDefault));
        
    }
    if(m_TextInputFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TextInputFormat"), m_TextInputFormat));
        
    }
    if(m_TextInputTypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TextInputType"), m_TextInputType));
        
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
    if(multipart->hasContent(_XPLATSTR("NodeId")))
    {
        setNodeId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("NodeId"))));
    }
    if(multipart->hasContent(_XPLATSTR("CalculateOnExit")))
    {
        setCalculateOnExit(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("CalculateOnExit"))));
    }
    if(multipart->hasContent(_XPLATSTR("Enabled")))
    {
        setEnabled(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("Enabled"))));
    }
    if(multipart->hasContent(_XPLATSTR("EntryMacro")))
    {
        setEntryMacro(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("EntryMacro"))));
    }
    if(multipart->hasContent(_XPLATSTR("ExitMacro")))
    {
        setExitMacro(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ExitMacro"))));
    }
    if(multipart->hasContent(_XPLATSTR("HelpText")))
    {
        setHelpText(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("HelpText"))));
    }
    if(multipart->hasContent(_XPLATSTR("Name")))
    {
        setName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Name"))));
    }
    if(multipart->hasContent(_XPLATSTR("OwnHelp")))
    {
        setOwnHelp(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("OwnHelp"))));
    }
    if(multipart->hasContent(_XPLATSTR("OwnStatus")))
    {
        setOwnStatus(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("OwnStatus"))));
    }
    if(multipart->hasContent(_XPLATSTR("StatusText")))
    {
        setStatusText(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("StatusText"))));
    }
    if(multipart->hasContent(_XPLATSTR("MaxLength")))
    {
        setMaxLength(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("MaxLength"))));
    }
    if(multipart->hasContent(_XPLATSTR("TextInputDefault")))
    {
        setTextInputDefault(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("TextInputDefault"))));
    }
    if(multipart->hasContent(_XPLATSTR("TextInputFormat")))
    {
        setTextInputFormat(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("TextInputFormat"))));
    }
    if(multipart->hasContent(_XPLATSTR("TextInputType")))
    {
        setTextInputType(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("TextInputType"))));
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

