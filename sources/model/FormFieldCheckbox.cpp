/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FormFieldCheckbox.cpp">
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


#include "FormFieldCheckbox.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

FormFieldCheckbox::FormFieldCheckbox()
{
    m_CheckBoxSize = 0.0;
    m_CheckBoxSizeIsSet = false;
    m_Checked = false;
    m_CheckedIsSet = false;
    m_IsCheckBoxExactSize = false;
    m_IsCheckBoxExactSizeIsSet = false;
}

FormFieldCheckbox::~FormFieldCheckbox()
{
}

void FormFieldCheckbox::validate()
{
    // TODO: implement validation
}

web::json::value FormFieldCheckbox::toJson() const
{
    web::json::value val = this->FormField::toJson();

    if(m_CheckBoxSizeIsSet)
    {
        val[_XPLATSTR("CheckBoxSize")] = ModelBase::toJson(m_CheckBoxSize);
    }
    if(m_CheckedIsSet)
    {
        val[_XPLATSTR("Checked")] = ModelBase::toJson(m_Checked);
    }
    if(m_IsCheckBoxExactSizeIsSet)
    {
        val[_XPLATSTR("IsCheckBoxExactSize")] = ModelBase::toJson(m_IsCheckBoxExactSize);
    }

    return val;
}

void FormFieldCheckbox::fromJson(web::json::value& val)
{
    this->FormField::fromJson(val);

    if(val.has_field(_XPLATSTR("CheckBoxSize")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("CheckBoxSize")];
        if(!fieldValue.is_null())
        {
            setCheckBoxSize(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Checked")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Checked")];
        if(!fieldValue.is_null())
        {
            setChecked(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("IsCheckBoxExactSize")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("IsCheckBoxExactSize")];
        if(!fieldValue.is_null())
        {
            setIsCheckBoxExactSize(ModelBase::boolFromJson(fieldValue));
        }
    }
}

void FormFieldCheckbox::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
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
    if(m_CheckBoxSizeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("CheckBoxSize"), m_CheckBoxSize));
    }
    if(m_CheckedIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Checked"), m_Checked));
    }
    if(m_IsCheckBoxExactSizeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("IsCheckBoxExactSize"), m_IsCheckBoxExactSize));
    }
}

void FormFieldCheckbox::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

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
    if(multipart->hasContent(_XPLATSTR("CheckBoxSize")))
    {
        setCheckBoxSize(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("CheckBoxSize"))));
    }
    if(multipart->hasContent(_XPLATSTR("Checked")))
    {
        setChecked(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("Checked"))));
    }
    if(multipart->hasContent(_XPLATSTR("IsCheckBoxExactSize")))
    {
        setIsCheckBoxExactSize(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("IsCheckBoxExactSize"))));
    }
}

double FormFieldCheckbox::getCheckBoxSize() const
{
    return m_CheckBoxSize;
}


void FormFieldCheckbox::setCheckBoxSize(double value)
{
    m_CheckBoxSize = value;
    m_CheckBoxSizeIsSet = true;
}
bool FormFieldCheckbox::checkBoxSizeIsSet() const
{
    return m_CheckBoxSizeIsSet;
}

void FormFieldCheckbox::unsetCheckBoxSize()
{
    m_CheckBoxSizeIsSet = false;
}

bool FormFieldCheckbox::isChecked() const
{
    return m_Checked;
}


void FormFieldCheckbox::setChecked(bool value)
{
    m_Checked = value;
    m_CheckedIsSet = true;
}
bool FormFieldCheckbox::checkedIsSet() const
{
    return m_CheckedIsSet;
}

void FormFieldCheckbox::unsetChecked()
{
    m_CheckedIsSet = false;
}

bool FormFieldCheckbox::isIsCheckBoxExactSize() const
{
    return m_IsCheckBoxExactSize;
}


void FormFieldCheckbox::setIsCheckBoxExactSize(bool value)
{
    m_IsCheckBoxExactSize = value;
    m_IsCheckBoxExactSizeIsSet = true;
}
bool FormFieldCheckbox::isCheckBoxExactSizeIsSet() const
{
    return m_IsCheckBoxExactSizeIsSet;
}

void FormFieldCheckbox::unsetIsCheckBoxExactSize()
{
    m_IsCheckBoxExactSizeIsSet = false;
}

}
}
}
}

