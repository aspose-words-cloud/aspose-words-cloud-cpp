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
        val[_XPLATSTR("CalculateOnExit")] = ModelBase::toJson(m_CalculateOnExit);
    }
    if(m_EnabledIsSet)
    {
        val[_XPLATSTR("Enabled")] = ModelBase::toJson(m_Enabled);
    }
    if(m_EntryMacroIsSet)
    {
        val[_XPLATSTR("EntryMacro")] = ModelBase::toJson(m_EntryMacro);
    }
    if(m_ExitMacroIsSet)
    {
        val[_XPLATSTR("ExitMacro")] = ModelBase::toJson(m_ExitMacro);
    }
    if(m_HelpTextIsSet)
    {
        val[_XPLATSTR("HelpText")] = ModelBase::toJson(m_HelpText);
    }
    if(m_NameIsSet)
    {
        val[_XPLATSTR("Name")] = ModelBase::toJson(m_Name);
    }
    if(m_OwnHelpIsSet)
    {
        val[_XPLATSTR("OwnHelp")] = ModelBase::toJson(m_OwnHelp);
    }
    if(m_OwnStatusIsSet)
    {
        val[_XPLATSTR("OwnStatus")] = ModelBase::toJson(m_OwnStatus);
    }
    if(m_StatusTextIsSet)
    {
        val[_XPLATSTR("StatusText")] = ModelBase::toJson(m_StatusText);
    }

    return val;
}

void FormField::fromJson(web::json::value& val)
{
    this->NodeLink::fromJson(val);

    if(val.has_field(_XPLATSTR("CalculateOnExit")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("CalculateOnExit")];
        if(!fieldValue.is_null())
        {
            setCalculateOnExit(ModelBase::bool?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Enabled")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Enabled")];
        if(!fieldValue.is_null())
        {
            setEnabled(ModelBase::bool?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("EntryMacro")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("EntryMacro")];
        if(!fieldValue.is_null())
        {
            setEntryMacro(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ExitMacro")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExitMacro")];
        if(!fieldValue.is_null())
        {
            setExitMacro(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("HelpText")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("HelpText")];
        if(!fieldValue.is_null())
        {
            setHelpText(ModelBase::stringFromJson(fieldValue));
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
    if(val.has_field(_XPLATSTR("OwnHelp")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("OwnHelp")];
        if(!fieldValue.is_null())
        {
            setOwnHelp(ModelBase::bool?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("OwnStatus")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("OwnStatus")];
        if(!fieldValue.is_null())
        {
            setOwnStatus(ModelBase::bool?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("StatusText")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("StatusText")];
        if(!fieldValue.is_null())
        {
            setStatusText(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void FormField::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    NodeLink::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

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
}

void FormField::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    NodeLink::fromMultiPart(multipart, prefix);

    if(multipart->hasContent(_XPLATSTR("CalculateOnExit")))
    {
        setCalculateOnExit(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("CalculateOnExit"))));
    }
    if(multipart->hasContent(_XPLATSTR("Enabled")))
    {
        setEnabled(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("Enabled"))));
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
        setOwnHelp(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("OwnHelp"))));
    }
    if(multipart->hasContent(_XPLATSTR("OwnStatus")))
    {
        setOwnStatus(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("OwnStatus"))));
    }
    if(multipart->hasContent(_XPLATSTR("StatusText")))
    {
        setStatusText(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("StatusText"))));
    }
}

<DATA_TYPE_START>bool?<DATA_TYPE_END> FormField::isCalculateOnExit() const
{
    return m_CalculateOnExit;
}


void FormField::setCalculateOnExit(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
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

<DATA_TYPE_START>bool?<DATA_TYPE_END> FormField::isEnabled() const
{
    return m_Enabled;
}


void FormField::setEnabled(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
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

<DATA_TYPE_START>string<DATA_TYPE_END> FormField::getEntryMacro() const
{
    return m_EntryMacro;
}


void FormField::setEntryMacro(<DATA_TYPE_START>string<DATA_TYPE_END> value)
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

<DATA_TYPE_START>string<DATA_TYPE_END> FormField::getExitMacro() const
{
    return m_ExitMacro;
}


void FormField::setExitMacro(<DATA_TYPE_START>string<DATA_TYPE_END> value)
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

<DATA_TYPE_START>string<DATA_TYPE_END> FormField::getHelpText() const
{
    return m_HelpText;
}


void FormField::setHelpText(<DATA_TYPE_START>string<DATA_TYPE_END> value)
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

<DATA_TYPE_START>string<DATA_TYPE_END> FormField::getName() const
{
    return m_Name;
}


void FormField::setName(<DATA_TYPE_START>string<DATA_TYPE_END> value)
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

<DATA_TYPE_START>bool?<DATA_TYPE_END> FormField::isOwnHelp() const
{
    return m_OwnHelp;
}


void FormField::setOwnHelp(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
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

<DATA_TYPE_START>bool?<DATA_TYPE_END> FormField::isOwnStatus() const
{
    return m_OwnStatus;
}


void FormField::setOwnStatus(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
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

<DATA_TYPE_START>string<DATA_TYPE_END> FormField::getStatusText() const
{
    return m_StatusText;
}


void FormField::setStatusText(<DATA_TYPE_START>string<DATA_TYPE_END> value)
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

