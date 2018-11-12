/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FormFieldDropDown.cpp">
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


#include "FormFieldDropDown.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

FormFieldDropDown::FormFieldDropDown()
{
    m_DropDownItemsIsSet = false;
    m_DropDownSelectedIndex = 0;
    m_DropDownSelectedIndexIsSet = false;
}

FormFieldDropDown::~FormFieldDropDown()
{
}

void FormFieldDropDown::validate()
{
    // TODO: implement validation
}

web::json::value FormFieldDropDown::toJson() const
{
    web::json::value val = this->FormField::toJson();

    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_DropDownItems )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        if(jsonArray.size() > 0)
        {
            val[utility::conversions::to_string_t("DropDownItems")] = web::json::value::array(jsonArray);
        }
    }
    if(m_DropDownSelectedIndexIsSet)
    {
        val[utility::conversions::to_string_t("DropDownSelectedIndex")] = ModelBase::toJson(m_DropDownSelectedIndex);
    }

    return val;
}

void FormFieldDropDown::fromJson(web::json::value& val)
{
    this->FormField::fromJson(val);

    {
        m_DropDownItems.clear();
        std::vector<web::json::value> jsonArray;
        if(val.has_field(utility::conversions::to_string_t("DropDownItems")))
        {
        for( auto& item : val[utility::conversions::to_string_t("DropDownItems")].as_array() )
        {
            m_DropDownItems.push_back(ModelBase::stringFromJson(item));
        }
        }
    }
    if(val.has_field(utility::conversions::to_string_t("DropDownSelectedIndex")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("DropDownSelectedIndex")];
        if(!fieldValue.is_null())
        {
            setDropDownSelectedIndex(ModelBase::int32_tFromJson(fieldValue));
        }
    }
}

void FormFieldDropDown::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_LinkIsSet)
    {
        if (m_Link.get())
        {
            m_Link->toMultipart(multipart, utility::conversions::to_string_t("link."));
        }
        
    }
    if(m_NodeIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("NodeId"), m_NodeId));
        
    }
    if(m_CalculateOnExitIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("CalculateOnExit"), m_CalculateOnExit));
    }
    if(m_EnabledIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Enabled"), m_Enabled));
    }
    if(m_EntryMacroIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("EntryMacro"), m_EntryMacro));
        
    }
    if(m_ExitMacroIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("ExitMacro"), m_ExitMacro));
        
    }
    if(m_HelpTextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("HelpText"), m_HelpText));
        
    }
    if(m_NameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Name"), m_Name));
        
    }
    if(m_OwnHelpIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("OwnHelp"), m_OwnHelp));
    }
    if(m_OwnStatusIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("OwnStatus"), m_OwnStatus));
    }
    if(m_StatusTextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("StatusText"), m_StatusText));
        
    }
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_DropDownItems )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("DropDownItems"), web::json::value::array(jsonArray), utility::conversions::to_string_t("application/json")));
        }
    }
    if(m_DropDownSelectedIndexIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("DropDownSelectedIndex"), m_DropDownSelectedIndex));
    }
}

void FormFieldDropDown::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("link")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("link")))
        {
            std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("link."));
            setLink( newItem );
        }
    }
    if(multipart->hasContent(utility::conversions::to_string_t("NodeId")))
    {
        setNodeId(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("NodeId"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("CalculateOnExit")))
    {
        setCalculateOnExit(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("CalculateOnExit"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Enabled")))
    {
        setEnabled(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Enabled"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("EntryMacro")))
    {
        setEntryMacro(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("EntryMacro"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("ExitMacro")))
    {
        setExitMacro(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("ExitMacro"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("HelpText")))
    {
        setHelpText(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("HelpText"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Name")))
    {
        setName(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Name"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("OwnHelp")))
    {
        setOwnHelp(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("OwnHelp"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("OwnStatus")))
    {
        setOwnStatus(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("OwnStatus"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("StatusText")))
    {
        setStatusText(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("StatusText"))));
    }
    {
        m_DropDownItems.clear();
        if(multipart->hasContent(utility::conversions::to_string_t("DropDownItems")))
        {

        web::json::value jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("DropDownItems"))));
        for( auto& item : jsonArray.as_array() )
        {
            m_DropDownItems.push_back(ModelBase::stringFromJson(item));
        }
        }
    }
    if(multipart->hasContent(utility::conversions::to_string_t("DropDownSelectedIndex")))
    {
        setDropDownSelectedIndex(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("DropDownSelectedIndex"))));
    }
}

std::vector<utility::string_t>& FormFieldDropDown::getDropDownItems()
{
    return m_DropDownItems;
}

void FormFieldDropDown::setDropDownItems(std::vector<utility::string_t> value)
{
    m_DropDownItems = value;
    m_DropDownItemsIsSet = true;
}
bool FormFieldDropDown::dropDownItemsIsSet() const
{
    return m_DropDownItemsIsSet;
}

void FormFieldDropDown::unsetDropDownItems()
{
    m_DropDownItemsIsSet = false;
}

int32_t FormFieldDropDown::getDropDownSelectedIndex() const
{
    return m_DropDownSelectedIndex;
}


void FormFieldDropDown::setDropDownSelectedIndex(int32_t value)
{
    m_DropDownSelectedIndex = value;
    m_DropDownSelectedIndexIsSet = true;
}
bool FormFieldDropDown::dropDownSelectedIndexIsSet() const
{
    return m_DropDownSelectedIndexIsSet;
}

void FormFieldDropDown::unsetDropDownSelectedIndex()
{
    m_DropDownSelectedIndexIsSet = false;
}

}
}
}
}

