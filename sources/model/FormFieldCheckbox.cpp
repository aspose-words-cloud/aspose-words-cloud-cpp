/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FormFieldCheckbox.cpp">
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


#include "FormFieldCheckbox.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

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
        val[_XPLATSTR("checkBoxSize")] = ModelBase::toJson(m_CheckBoxSize);
    }
    if(m_CheckedIsSet)
    {
        val[_XPLATSTR("checked")] = ModelBase::toJson(m_Checked);
    }
    if(m_IsCheckBoxExactSizeIsSet)
    {
        val[_XPLATSTR("isCheckBoxExactSize")] = ModelBase::toJson(m_IsCheckBoxExactSize);
    }

    return val;
}

void FormFieldCheckbox::fromJson(web::json::value& val)
{
    this->FormField::fromJson(val);

    if(val.has_field(_XPLATSTR("checkBoxSize")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("checkBoxSize")];
        if(!fieldValue.is_null())
        {
            setCheckBoxSize(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("checked")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("checked")];
        if(!fieldValue.is_null())
        {
            setChecked(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("isCheckBoxExactSize")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("isCheckBoxExactSize")];
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
    if(m_CheckBoxSizeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("checkBoxSize"), m_CheckBoxSize));
    }
    if(m_CheckedIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("checked"), m_Checked));
    }
    if(m_IsCheckBoxExactSizeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("isCheckBoxExactSize"), m_IsCheckBoxExactSize));
    }
}

void FormFieldCheckbox::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(_XPLATSTR("checkBoxSize")))
    {
        setCheckBoxSize(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("checkBoxSize"))));
    }
    if(multipart->hasContent(_XPLATSTR("checked")))
    {
        setChecked(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("checked"))));
    }
    if(multipart->hasContent(_XPLATSTR("isCheckBoxExactSize")))
    {
        setIsCheckBoxExactSize(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("isCheckBoxExactSize"))));
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
}

