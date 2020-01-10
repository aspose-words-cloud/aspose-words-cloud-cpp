/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FormField.cpp">
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


#include "FormField.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

FormField::FormField()
{
    m_CalculateOnExit = false;
    m_CalculateOnExitIsSet = false;
    m_Enabled = false;
    m_EnabledIsSet = false;
    m_EntryMacro = utility::conversions::to_string_t("");
    m_EntryMacroIsSet = false;
    m_ExitMacro = utility::conversions::to_string_t("");
    m_ExitMacroIsSet = false;
    m_HelpText = utility::conversions::to_string_t("");
    m_HelpTextIsSet = false;
    m_Name = utility::conversions::to_string_t("");
    m_NameIsSet = false;
    m_OwnHelp = false;
    m_OwnHelpIsSet = false;
    m_OwnStatus = false;
    m_OwnStatusIsSet = false;
    m_StatusText = utility::conversions::to_string_t("");
    m_StatusTextIsSet = false;
}

FormField::~FormField()
{
}

void FormField::validate()
{
    // TODO: implement validation
}

web::json::value FormField::toJson() const
{
    web::json::value val = this->NodeLink::toJson();

    if(m_CalculateOnExitIsSet)
    {
        val[_XPLATSTR("calculateOnExit")] = ModelBase::toJson(m_CalculateOnExit);
    }
    if(m_EnabledIsSet)
    {
        val[_XPLATSTR("enabled")] = ModelBase::toJson(m_Enabled);
    }
    if(m_EntryMacroIsSet)
    {
        val[_XPLATSTR("entryMacro")] = ModelBase::toJson(m_EntryMacro);
    }
    if(m_ExitMacroIsSet)
    {
        val[_XPLATSTR("exitMacro")] = ModelBase::toJson(m_ExitMacro);
    }
    if(m_HelpTextIsSet)
    {
        val[_XPLATSTR("helpText")] = ModelBase::toJson(m_HelpText);
    }
    if(m_NameIsSet)
    {
        val[_XPLATSTR("name")] = ModelBase::toJson(m_Name);
    }
    if(m_OwnHelpIsSet)
    {
        val[_XPLATSTR("ownHelp")] = ModelBase::toJson(m_OwnHelp);
    }
    if(m_OwnStatusIsSet)
    {
        val[_XPLATSTR("ownStatus")] = ModelBase::toJson(m_OwnStatus);
    }
    if(m_StatusTextIsSet)
    {
        val[_XPLATSTR("statusText")] = ModelBase::toJson(m_StatusText);
    }

    return val;
}

void FormField::fromJson(web::json::value& val)
{
    this->NodeLink::fromJson(val);

    if(val.has_field(_XPLATSTR("calculateOnExit")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("calculateOnExit")];
        if(!fieldValue.is_null())
        {
            setCalculateOnExit(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("enabled")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("enabled")];
        if(!fieldValue.is_null())
        {
            setEnabled(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("entryMacro")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("entryMacro")];
        if(!fieldValue.is_null())
        {
            setEntryMacro(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("exitMacro")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exitMacro")];
        if(!fieldValue.is_null())
        {
            setExitMacro(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("helpText")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("helpText")];
        if(!fieldValue.is_null())
        {
            setHelpText(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("name")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("name")];
        if(!fieldValue.is_null())
        {
            setName(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ownHelp")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ownHelp")];
        if(!fieldValue.is_null())
        {
            setOwnHelp(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ownStatus")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ownStatus")];
        if(!fieldValue.is_null())
        {
            setOwnStatus(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("statusText")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("statusText")];
        if(!fieldValue.is_null())
        {
            setStatusText(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void FormField::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
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
}

void FormField::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
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
}

bool FormField::isCalculateOnExit() const
{
    return m_CalculateOnExit;
}


void FormField::setCalculateOnExit(bool value)
{
    m_CalculateOnExit = value;
    m_CalculateOnExitIsSet = true;
}
bool FormField::calculateOnExitIsSet() const
{
    return m_CalculateOnExitIsSet;
}

void FormField::unsetCalculateOnExit()
{
    m_CalculateOnExitIsSet = false;
}

bool FormField::isEnabled() const
{
    return m_Enabled;
}


void FormField::setEnabled(bool value)
{
    m_Enabled = value;
    m_EnabledIsSet = true;
}
bool FormField::enabledIsSet() const
{
    return m_EnabledIsSet;
}

void FormField::unsetEnabled()
{
    m_EnabledIsSet = false;
}

utility::string_t FormField::getEntryMacro() const
{
    return m_EntryMacro;
}


void FormField::setEntryMacro(utility::string_t value)
{
    m_EntryMacro = value;
    m_EntryMacroIsSet = true;
}
bool FormField::entryMacroIsSet() const
{
    return m_EntryMacroIsSet;
}

void FormField::unsetEntryMacro()
{
    m_EntryMacroIsSet = false;
}

utility::string_t FormField::getExitMacro() const
{
    return m_ExitMacro;
}


void FormField::setExitMacro(utility::string_t value)
{
    m_ExitMacro = value;
    m_ExitMacroIsSet = true;
}
bool FormField::exitMacroIsSet() const
{
    return m_ExitMacroIsSet;
}

void FormField::unsetExitMacro()
{
    m_ExitMacroIsSet = false;
}

utility::string_t FormField::getHelpText() const
{
    return m_HelpText;
}


void FormField::setHelpText(utility::string_t value)
{
    m_HelpText = value;
    m_HelpTextIsSet = true;
}
bool FormField::helpTextIsSet() const
{
    return m_HelpTextIsSet;
}

void FormField::unsetHelpText()
{
    m_HelpTextIsSet = false;
}

utility::string_t FormField::getName() const
{
    return m_Name;
}


void FormField::setName(utility::string_t value)
{
    m_Name = value;
    m_NameIsSet = true;
}
bool FormField::nameIsSet() const
{
    return m_NameIsSet;
}

void FormField::unsetName()
{
    m_NameIsSet = false;
}

bool FormField::isOwnHelp() const
{
    return m_OwnHelp;
}


void FormField::setOwnHelp(bool value)
{
    m_OwnHelp = value;
    m_OwnHelpIsSet = true;
}
bool FormField::ownHelpIsSet() const
{
    return m_OwnHelpIsSet;
}

void FormField::unsetOwnHelp()
{
    m_OwnHelpIsSet = false;
}

bool FormField::isOwnStatus() const
{
    return m_OwnStatus;
}


void FormField::setOwnStatus(bool value)
{
    m_OwnStatus = value;
    m_OwnStatusIsSet = true;
}
bool FormField::ownStatusIsSet() const
{
    return m_OwnStatusIsSet;
}

void FormField::unsetOwnStatus()
{
    m_OwnStatusIsSet = false;
}

utility::string_t FormField::getStatusText() const
{
    return m_StatusText;
}


void FormField::setStatusText(utility::string_t value)
{
    m_StatusText = value;
    m_StatusTextIsSet = true;
}
bool FormField::statusTextIsSet() const
{
    return m_StatusTextIsSet;
}

void FormField::unsetStatusText()
{
    m_StatusTextIsSet = false;
}

}
}
}
}
}

