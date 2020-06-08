/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Style.cpp">
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


#include "Style.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

Style::Style()
{
    m_AliasesIsSet = false;
    m_BaseStyleName = utility::conversions::to_string_t("");
    m_BaseStyleNameIsSet = false;
    m_BuiltIn = false;
    m_BuiltInIsSet = false;
    m_FontIsSet = false;
    m_IsHeading = false;
    m_IsHeadingIsSet = false;
    m_IsQuickStyle = false;
    m_IsQuickStyleIsSet = false;
    m_LinkedStyleName = utility::conversions::to_string_t("");
    m_LinkedStyleNameIsSet = false;
    m_Name = utility::conversions::to_string_t("");
    m_NameIsSet = false;
    m_NextParagraphStyleName = utility::conversions::to_string_t("");
    m_NextParagraphStyleNameIsSet = false;
    m_StyleIdentifier = utility::conversions::to_string_t("");
    m_StyleIdentifierIsSet = false;
    m_Type = utility::conversions::to_string_t("");
    m_TypeIsSet = false;
}

Style::~Style()
{
}

void Style::validate()
{
    // TODO: implement validation
}

web::json::value Style::toJson() const
{
    web::json::value val = this->LinkElement::toJson();

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_Aliases.begin(), m_Aliases.end(), std::back_inserter(jsonArray),
			[&](<DATA_TYPE_START>string<DATA_TYPE_END> item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("Aliases")] = web::json::value::array(jsonArray);
        }
    }
    if(m_BaseStyleNameIsSet)
    {
        val[_XPLATSTR("BaseStyleName")] = ModelBase::toJson(m_BaseStyleName);
    }
    if(m_BuiltInIsSet)
    {
        val[_XPLATSTR("BuiltIn")] = ModelBase::toJson(m_BuiltIn);
    }
    if(m_FontIsSet)
    {
        val[_XPLATSTR("Font")] = ModelBase::toJson(m_Font);
    }
    if(m_IsHeadingIsSet)
    {
        val[_XPLATSTR("IsHeading")] = ModelBase::toJson(m_IsHeading);
    }
    if(m_IsQuickStyleIsSet)
    {
        val[_XPLATSTR("IsQuickStyle")] = ModelBase::toJson(m_IsQuickStyle);
    }
    if(m_LinkedStyleNameIsSet)
    {
        val[_XPLATSTR("LinkedStyleName")] = ModelBase::toJson(m_LinkedStyleName);
    }
    if(m_NameIsSet)
    {
        val[_XPLATSTR("Name")] = ModelBase::toJson(m_Name);
    }
    if(m_NextParagraphStyleNameIsSet)
    {
        val[_XPLATSTR("NextParagraphStyleName")] = ModelBase::toJson(m_NextParagraphStyleName);
    }
    if(m_StyleIdentifierIsSet)
    {
        val[_XPLATSTR("StyleIdentifier")] = ModelBase::toJson(m_StyleIdentifier);
    }
    if(m_TypeIsSet)
    {
        val[_XPLATSTR("Type")] = ModelBase::toJson(m_Type);
    }

    return val;
}

void Style::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    {
        m_Aliases.clear();
        if(val.has_field(_XPLATSTR("Aliases")) 
                            && !val[_XPLATSTR("Aliases")].is_null())
        {
        auto arr = val[_XPLATSTR("Aliases")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_Aliases), [&](web::json::value& item){
            return ModelBase::stringFromJson(item);
        });

        }
    }
    if(val.has_field(_XPLATSTR("BaseStyleName")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("BaseStyleName")];
        if(!fieldValue.is_null())
        {
            setBaseStyleName(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("BuiltIn")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("BuiltIn")];
        if(!fieldValue.is_null())
        {
            setBuiltIn(ModelBase::bool?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Font")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Font")];
        if(!fieldValue.is_null())
        {
            <DATA_TYPE_START>Font<DATA_TYPE_END> newItem(new Font());
            newItem->fromJson(fieldValue);
            setFont( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("IsHeading")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("IsHeading")];
        if(!fieldValue.is_null())
        {
            setIsHeading(ModelBase::bool?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("IsQuickStyle")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("IsQuickStyle")];
        if(!fieldValue.is_null())
        {
            setIsQuickStyle(ModelBase::bool?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("LinkedStyleName")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("LinkedStyleName")];
        if(!fieldValue.is_null())
        {
            setLinkedStyleName(ModelBase::stringFromJson(fieldValue));
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
    if(val.has_field(_XPLATSTR("NextParagraphStyleName")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("NextParagraphStyleName")];
        if(!fieldValue.is_null())
        {
            setNextParagraphStyleName(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("StyleIdentifier")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("StyleIdentifier")];
        if(!fieldValue.is_null())
        {
            setStyleIdentifier(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Type")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Type")];
        if(!fieldValue.is_null())
        {
            setType(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void Style::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    LinkElement::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_Aliases.begin(), m_Aliases.end(), std::back_inserter(jsonArray), [&](<DATA_TYPE_START>string<DATA_TYPE_END> item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Aliases"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }
    if(m_BaseStyleNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("BaseStyleName"), m_BaseStyleName));
        
    }
    if(m_BuiltInIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("BuiltIn"), m_BuiltIn));
        
    }
    if(m_FontIsSet)
    {
        if (m_Font.get())
        {
            m_Font->toMultipart(multipart, _XPLATSTR("Font."));
        }
        
    }
    if(m_IsHeadingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("IsHeading"), m_IsHeading));
        
    }
    if(m_IsQuickStyleIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("IsQuickStyle"), m_IsQuickStyle));
        
    }
    if(m_LinkedStyleNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("LinkedStyleName"), m_LinkedStyleName));
        
    }
    if(m_NameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Name"), m_Name));
        
    }
    if(m_NextParagraphStyleNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("NextParagraphStyleName"), m_NextParagraphStyleName));
        
    }
    if(m_StyleIdentifierIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("StyleIdentifier"), m_StyleIdentifier));
        
    }
    if(m_TypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Type"), m_Type));
        
    }
}

void Style::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    LinkElement::fromMultiPart(multipart, prefix);

    {
        m_Aliases.clear();
        if(multipart->hasContent(_XPLATSTR("Aliases")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Aliases")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_Aliases), [&](web::json::value item) {
            return ModelBase::stringFromJson(item);
        });
        }
    }
    if(multipart->hasContent(_XPLATSTR("BaseStyleName")))
    {
        setBaseStyleName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("BaseStyleName"))));
    }
    if(multipart->hasContent(_XPLATSTR("BuiltIn")))
    {
        setBuiltIn(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("BuiltIn"))));
    }
    if(multipart->hasContent(_XPLATSTR("Font")))
    {
        if(multipart->hasContent(_XPLATSTR("Font")))
        {
            <DATA_TYPE_START>Font<DATA_TYPE_END> newItem(new Font());
            newItem->fromMultiPart(multipart, _XPLATSTR("Font."));
            setFont( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("IsHeading")))
    {
        setIsHeading(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("IsHeading"))));
    }
    if(multipart->hasContent(_XPLATSTR("IsQuickStyle")))
    {
        setIsQuickStyle(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("IsQuickStyle"))));
    }
    if(multipart->hasContent(_XPLATSTR("LinkedStyleName")))
    {
        setLinkedStyleName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("LinkedStyleName"))));
    }
    if(multipart->hasContent(_XPLATSTR("Name")))
    {
        setName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Name"))));
    }
    if(multipart->hasContent(_XPLATSTR("NextParagraphStyleName")))
    {
        setNextParagraphStyleName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("NextParagraphStyleName"))));
    }
    if(multipart->hasContent(_XPLATSTR("StyleIdentifier")))
    {
        setStyleIdentifier(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("StyleIdentifier"))));
    }
    if(multipart->hasContent(_XPLATSTR("Type")))
    {
        setType(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Type"))));
    }
}

<DATA_TYPE_START>List<string><DATA_TYPE_END>& Style::getAliases()
{
    return m_Aliases;
}

void Style::setAliases(<DATA_TYPE_START>List<string><DATA_TYPE_END> const& value)
{
    m_Aliases = value;
    m_AliasesIsSet = true;
}
bool Style::aliasesIsSet() const
{
    return m_AliasesIsSet;
}

void Style::unsetAliases()
{
    m_AliasesIsSet = false;
}

<DATA_TYPE_START>string<DATA_TYPE_END> Style::getBaseStyleName() const
{
    return m_BaseStyleName;
}


void Style::setBaseStyleName(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_BaseStyleName = value;
    m_BaseStyleNameIsSet = true;
}
bool Style::baseStyleNameIsSet() const
{
    return m_BaseStyleNameIsSet;
}

void Style::unsetBaseStyleName()
{
    m_BaseStyleNameIsSet = false;
}

<DATA_TYPE_START>bool?<DATA_TYPE_END> Style::isBuiltIn() const
{
    return m_BuiltIn;
}


void Style::setBuiltIn(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
{
    m_BuiltIn = value;
    m_BuiltInIsSet = true;
}
bool Style::builtInIsSet() const
{
    return m_BuiltInIsSet;
}

void Style::unsetBuiltIn()
{
    m_BuiltInIsSet = false;
}

<DATA_TYPE_START>Font<DATA_TYPE_END> Style::getFont() const
{
    return m_Font;
}


void Style::setFont(<DATA_TYPE_START>Font<DATA_TYPE_END> value)
{
    m_Font = value;
    m_FontIsSet = true;
}
bool Style::fontIsSet() const
{
    return m_FontIsSet;
}

void Style::unsetFont()
{
    m_FontIsSet = false;
}

<DATA_TYPE_START>bool?<DATA_TYPE_END> Style::isIsHeading() const
{
    return m_IsHeading;
}


void Style::setIsHeading(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
{
    m_IsHeading = value;
    m_IsHeadingIsSet = true;
}
bool Style::isHeadingIsSet() const
{
    return m_IsHeadingIsSet;
}

void Style::unsetIsHeading()
{
    m_IsHeadingIsSet = false;
}

<DATA_TYPE_START>bool?<DATA_TYPE_END> Style::isIsQuickStyle() const
{
    return m_IsQuickStyle;
}


void Style::setIsQuickStyle(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
{
    m_IsQuickStyle = value;
    m_IsQuickStyleIsSet = true;
}
bool Style::isQuickStyleIsSet() const
{
    return m_IsQuickStyleIsSet;
}

void Style::unsetIsQuickStyle()
{
    m_IsQuickStyleIsSet = false;
}

<DATA_TYPE_START>string<DATA_TYPE_END> Style::getLinkedStyleName() const
{
    return m_LinkedStyleName;
}


void Style::setLinkedStyleName(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_LinkedStyleName = value;
    m_LinkedStyleNameIsSet = true;
}
bool Style::linkedStyleNameIsSet() const
{
    return m_LinkedStyleNameIsSet;
}

void Style::unsetLinkedStyleName()
{
    m_LinkedStyleNameIsSet = false;
}

<DATA_TYPE_START>string<DATA_TYPE_END> Style::getName() const
{
    return m_Name;
}


void Style::setName(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_Name = value;
    m_NameIsSet = true;
}
bool Style::nameIsSet() const
{
    return m_NameIsSet;
}

void Style::unsetName()
{
    m_NameIsSet = false;
}

<DATA_TYPE_START>string<DATA_TYPE_END> Style::getNextParagraphStyleName() const
{
    return m_NextParagraphStyleName;
}


void Style::setNextParagraphStyleName(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_NextParagraphStyleName = value;
    m_NextParagraphStyleNameIsSet = true;
}
bool Style::nextParagraphStyleNameIsSet() const
{
    return m_NextParagraphStyleNameIsSet;
}

void Style::unsetNextParagraphStyleName()
{
    m_NextParagraphStyleNameIsSet = false;
}

<DATA_TYPE_START>string<DATA_TYPE_END> Style::getStyleIdentifier() const
{
    return m_StyleIdentifier;
}


void Style::setStyleIdentifier(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_StyleIdentifier = value;
    m_StyleIdentifierIsSet = true;
}
bool Style::styleIdentifierIsSet() const
{
    return m_StyleIdentifierIsSet;
}

void Style::unsetStyleIdentifier()
{
    m_StyleIdentifierIsSet = false;
}

<DATA_TYPE_START>string<DATA_TYPE_END> Style::getType() const
{
    return m_Type;
}


void Style::setType(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_Type = value;
    m_TypeIsSet = true;
}
bool Style::typeIsSet() const
{
    return m_TypeIsSet;
}

void Style::unsetType()
{
    m_TypeIsSet = false;
}

}
}
}
}
}

