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
        std::transform(m_DropDownItems.begin(), m_DropDownItems.end(), std::back_inserter(jsonArray),
			[&](utility::string_t item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("DropDownItems")] = web::json::value::array(jsonArray);
        }
    }
    if(m_DropDownSelectedIndexIsSet)
    {
        val[_XPLATSTR("DropDownSelectedIndex")] = ModelBase::toJson(m_DropDownSelectedIndex);
    }

    return val;
}

void FormFieldDropDown::fromJson(web::json::value& val)
{
    this->FormField::fromJson(val);

    {
        m_DropDownItems.clear();
        if(val.has_field(_XPLATSTR("DropDownItems")) 
                            && !val[_XPLATSTR("DropDownItems")].is_null())
        {
        auto arr = val[_XPLATSTR("DropDownItems")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_DropDownItems), [&](web::json::value& item){
            return ModelBase::stringFromJson(item);
        });

        }
    }
    if(val.has_field(_XPLATSTR("DropDownSelectedIndex")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DropDownSelectedIndex")];
        if(!fieldValue.is_null())
        {
            setDropDownSelectedIndex(ModelBase::int32_tFromJson(fieldValue));
        }
    }
}

void FormFieldDropDown::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
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
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_DropDownItems.begin(), m_DropDownItems.end(), std::back_inserter(jsonArray), [&](utility::string_t item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("DropDownItems"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }
    if(m_DropDownSelectedIndexIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("DropDownSelectedIndex"), m_DropDownSelectedIndex));
    }
}

void FormFieldDropDown::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
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
    {
        m_DropDownItems.clear();
        if(multipart->hasContent(_XPLATSTR("DropDownItems")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("DropDownItems")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_DropDownItems), [&](web::json::value item) {
            return ModelBase::stringFromJson(item);
        });
        }
    }
    if(multipart->hasContent(_XPLATSTR("DropDownSelectedIndex")))
    {
        setDropDownSelectedIndex(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("DropDownSelectedIndex"))));
    }
}

std::vector<utility::string_t>& FormFieldDropDown::getDropDownItems()
{
    return m_DropDownItems;
}

void FormFieldDropDown::setDropDownItems(std::vector<utility::string_t> const& value)
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

