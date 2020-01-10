/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Font.cpp">
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


#include "Font.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

Font::Font()
{
    m_AllCaps = false;
    m_AllCapsIsSet = false;
    m_Bidi = false;
    m_BidiIsSet = false;
    m_Bold = false;
    m_BoldIsSet = false;
    m_BoldBi = false;
    m_BoldBiIsSet = false;
    m_BorderIsSet = false;
    m_ColorIsSet = false;
    m_ComplexScript = false;
    m_ComplexScriptIsSet = false;
    m_DoubleStrikeThrough = false;
    m_DoubleStrikeThroughIsSet = false;
    m_Emboss = false;
    m_EmbossIsSet = false;
    m_Engrave = false;
    m_EngraveIsSet = false;
    m_Hidden = false;
    m_HiddenIsSet = false;
    m_HighlightColorIsSet = false;
    m_Italic = false;
    m_ItalicIsSet = false;
    m_ItalicBi = false;
    m_ItalicBiIsSet = false;
    m_Kerning = 0.0;
    m_KerningIsSet = false;
    m_LocaleId = 0;
    m_LocaleIdIsSet = false;
    m_LocaleIdBi = 0;
    m_LocaleIdBiIsSet = false;
    m_LocaleIdFarEast = 0;
    m_LocaleIdFarEastIsSet = false;
    m_Name = utility::conversions::to_string_t("");
    m_NameIsSet = false;
    m_NameAscii = utility::conversions::to_string_t("");
    m_NameAsciiIsSet = false;
    m_NameBi = utility::conversions::to_string_t("");
    m_NameBiIsSet = false;
    m_NameFarEast = utility::conversions::to_string_t("");
    m_NameFarEastIsSet = false;
    m_NameOther = utility::conversions::to_string_t("");
    m_NameOtherIsSet = false;
    m_NoProofing = false;
    m_NoProofingIsSet = false;
    m_Outline = false;
    m_OutlineIsSet = false;
    m_Position = 0.0;
    m_PositionIsSet = false;
    m_Scaling = 0;
    m_ScalingIsSet = false;
    m_Shadow = false;
    m_ShadowIsSet = false;
    m_Size = 0.0;
    m_SizeIsSet = false;
    m_SizeBi = 0.0;
    m_SizeBiIsSet = false;
    m_SmallCaps = false;
    m_SmallCapsIsSet = false;
    m_Spacing = 0.0;
    m_SpacingIsSet = false;
    m_StrikeThrough = false;
    m_StrikeThroughIsSet = false;
    m_StyleIdentifier = utility::conversions::to_string_t("");
    m_StyleIdentifierIsSet = false;
    m_StyleName = utility::conversions::to_string_t("");
    m_StyleNameIsSet = false;
    m_Subscript = false;
    m_SubscriptIsSet = false;
    m_Superscript = false;
    m_SuperscriptIsSet = false;
    m_TextEffect = utility::conversions::to_string_t("");
    m_TextEffectIsSet = false;
    m_Underline = utility::conversions::to_string_t("");
    m_UnderlineIsSet = false;
    m_UnderlineColorIsSet = false;
}

Font::~Font()
{
}

void Font::validate()
{
    // TODO: implement validation
}

web::json::value Font::toJson() const
{
    web::json::value val = this->LinkElement::toJson();

    if(m_AllCapsIsSet)
    {
        val[_XPLATSTR("allCaps")] = ModelBase::toJson(m_AllCaps);
    }
    if(m_BidiIsSet)
    {
        val[_XPLATSTR("bidi")] = ModelBase::toJson(m_Bidi);
    }
    if(m_BoldIsSet)
    {
        val[_XPLATSTR("bold")] = ModelBase::toJson(m_Bold);
    }
    if(m_BoldBiIsSet)
    {
        val[_XPLATSTR("boldBi")] = ModelBase::toJson(m_BoldBi);
    }
    if(m_BorderIsSet)
    {
        val[_XPLATSTR("border")] = ModelBase::toJson(m_Border);
    }
    if(m_ColorIsSet)
    {
        val[_XPLATSTR("color")] = ModelBase::toJson(m_Color);
    }
    if(m_ComplexScriptIsSet)
    {
        val[_XPLATSTR("complexScript")] = ModelBase::toJson(m_ComplexScript);
    }
    if(m_DoubleStrikeThroughIsSet)
    {
        val[_XPLATSTR("doubleStrikeThrough")] = ModelBase::toJson(m_DoubleStrikeThrough);
    }
    if(m_EmbossIsSet)
    {
        val[_XPLATSTR("emboss")] = ModelBase::toJson(m_Emboss);
    }
    if(m_EngraveIsSet)
    {
        val[_XPLATSTR("engrave")] = ModelBase::toJson(m_Engrave);
    }
    if(m_HiddenIsSet)
    {
        val[_XPLATSTR("hidden")] = ModelBase::toJson(m_Hidden);
    }
    if(m_HighlightColorIsSet)
    {
        val[_XPLATSTR("highlightColor")] = ModelBase::toJson(m_HighlightColor);
    }
    if(m_ItalicIsSet)
    {
        val[_XPLATSTR("italic")] = ModelBase::toJson(m_Italic);
    }
    if(m_ItalicBiIsSet)
    {
        val[_XPLATSTR("italicBi")] = ModelBase::toJson(m_ItalicBi);
    }
    if(m_KerningIsSet)
    {
        val[_XPLATSTR("kerning")] = ModelBase::toJson(m_Kerning);
    }
    if(m_LocaleIdIsSet)
    {
        val[_XPLATSTR("localeId")] = ModelBase::toJson(m_LocaleId);
    }
    if(m_LocaleIdBiIsSet)
    {
        val[_XPLATSTR("localeIdBi")] = ModelBase::toJson(m_LocaleIdBi);
    }
    if(m_LocaleIdFarEastIsSet)
    {
        val[_XPLATSTR("localeIdFarEast")] = ModelBase::toJson(m_LocaleIdFarEast);
    }
    if(m_NameIsSet)
    {
        val[_XPLATSTR("name")] = ModelBase::toJson(m_Name);
    }
    if(m_NameAsciiIsSet)
    {
        val[_XPLATSTR("nameAscii")] = ModelBase::toJson(m_NameAscii);
    }
    if(m_NameBiIsSet)
    {
        val[_XPLATSTR("nameBi")] = ModelBase::toJson(m_NameBi);
    }
    if(m_NameFarEastIsSet)
    {
        val[_XPLATSTR("nameFarEast")] = ModelBase::toJson(m_NameFarEast);
    }
    if(m_NameOtherIsSet)
    {
        val[_XPLATSTR("nameOther")] = ModelBase::toJson(m_NameOther);
    }
    if(m_NoProofingIsSet)
    {
        val[_XPLATSTR("noProofing")] = ModelBase::toJson(m_NoProofing);
    }
    if(m_OutlineIsSet)
    {
        val[_XPLATSTR("outline")] = ModelBase::toJson(m_Outline);
    }
    if(m_PositionIsSet)
    {
        val[_XPLATSTR("position")] = ModelBase::toJson(m_Position);
    }
    if(m_ScalingIsSet)
    {
        val[_XPLATSTR("scaling")] = ModelBase::toJson(m_Scaling);
    }
    if(m_ShadowIsSet)
    {
        val[_XPLATSTR("shadow")] = ModelBase::toJson(m_Shadow);
    }
    if(m_SizeIsSet)
    {
        val[_XPLATSTR("size")] = ModelBase::toJson(m_Size);
    }
    if(m_SizeBiIsSet)
    {
        val[_XPLATSTR("sizeBi")] = ModelBase::toJson(m_SizeBi);
    }
    if(m_SmallCapsIsSet)
    {
        val[_XPLATSTR("smallCaps")] = ModelBase::toJson(m_SmallCaps);
    }
    if(m_SpacingIsSet)
    {
        val[_XPLATSTR("spacing")] = ModelBase::toJson(m_Spacing);
    }
    if(m_StrikeThroughIsSet)
    {
        val[_XPLATSTR("strikeThrough")] = ModelBase::toJson(m_StrikeThrough);
    }
    if(m_StyleIdentifierIsSet)
    {
        val[_XPLATSTR("styleIdentifier")] = ModelBase::toJson(m_StyleIdentifier);
    }
    if(m_StyleNameIsSet)
    {
        val[_XPLATSTR("styleName")] = ModelBase::toJson(m_StyleName);
    }
    if(m_SubscriptIsSet)
    {
        val[_XPLATSTR("subscript")] = ModelBase::toJson(m_Subscript);
    }
    if(m_SuperscriptIsSet)
    {
        val[_XPLATSTR("superscript")] = ModelBase::toJson(m_Superscript);
    }
    if(m_TextEffectIsSet)
    {
        val[_XPLATSTR("textEffect")] = ModelBase::toJson(m_TextEffect);
    }
    if(m_UnderlineIsSet)
    {
        val[_XPLATSTR("underline")] = ModelBase::toJson(m_Underline);
    }
    if(m_UnderlineColorIsSet)
    {
        val[_XPLATSTR("underlineColor")] = ModelBase::toJson(m_UnderlineColor);
    }

    return val;
}

void Font::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    if(val.has_field(_XPLATSTR("allCaps")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("allCaps")];
        if(!fieldValue.is_null())
        {
            setAllCaps(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("bidi")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("bidi")];
        if(!fieldValue.is_null())
        {
            setBidi(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("bold")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("bold")];
        if(!fieldValue.is_null())
        {
            setBold(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("boldBi")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("boldBi")];
        if(!fieldValue.is_null())
        {
            setBoldBi(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("border")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("border")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Border> newItem(new Border());
            newItem->fromJson(fieldValue);
            setBorder( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("color")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("color")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<XmlColor> newItem(new XmlColor());
            newItem->fromJson(fieldValue);
            setColor( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("complexScript")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("complexScript")];
        if(!fieldValue.is_null())
        {
            setComplexScript(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("doubleStrikeThrough")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("doubleStrikeThrough")];
        if(!fieldValue.is_null())
        {
            setDoubleStrikeThrough(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("emboss")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("emboss")];
        if(!fieldValue.is_null())
        {
            setEmboss(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("engrave")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("engrave")];
        if(!fieldValue.is_null())
        {
            setEngrave(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("hidden")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("hidden")];
        if(!fieldValue.is_null())
        {
            setHidden(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("highlightColor")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("highlightColor")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<XmlColor> newItem(new XmlColor());
            newItem->fromJson(fieldValue);
            setHighlightColor( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("italic")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("italic")];
        if(!fieldValue.is_null())
        {
            setItalic(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("italicBi")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("italicBi")];
        if(!fieldValue.is_null())
        {
            setItalicBi(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("kerning")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("kerning")];
        if(!fieldValue.is_null())
        {
            setKerning(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("localeId")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("localeId")];
        if(!fieldValue.is_null())
        {
            setLocaleId(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("localeIdBi")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("localeIdBi")];
        if(!fieldValue.is_null())
        {
            setLocaleIdBi(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("localeIdFarEast")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("localeIdFarEast")];
        if(!fieldValue.is_null())
        {
            setLocaleIdFarEast(ModelBase::int32_tFromJson(fieldValue));
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
    if(val.has_field(_XPLATSTR("nameAscii")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("nameAscii")];
        if(!fieldValue.is_null())
        {
            setNameAscii(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("nameBi")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("nameBi")];
        if(!fieldValue.is_null())
        {
            setNameBi(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("nameFarEast")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("nameFarEast")];
        if(!fieldValue.is_null())
        {
            setNameFarEast(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("nameOther")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("nameOther")];
        if(!fieldValue.is_null())
        {
            setNameOther(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("noProofing")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("noProofing")];
        if(!fieldValue.is_null())
        {
            setNoProofing(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("outline")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("outline")];
        if(!fieldValue.is_null())
        {
            setOutline(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("position")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("position")];
        if(!fieldValue.is_null())
        {
            setPosition(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("scaling")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("scaling")];
        if(!fieldValue.is_null())
        {
            setScaling(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("shadow")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("shadow")];
        if(!fieldValue.is_null())
        {
            setShadow(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("size")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("size")];
        if(!fieldValue.is_null())
        {
            setSize(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("sizeBi")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("sizeBi")];
        if(!fieldValue.is_null())
        {
            setSizeBi(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("smallCaps")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("smallCaps")];
        if(!fieldValue.is_null())
        {
            setSmallCaps(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("spacing")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("spacing")];
        if(!fieldValue.is_null())
        {
            setSpacing(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("strikeThrough")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("strikeThrough")];
        if(!fieldValue.is_null())
        {
            setStrikeThrough(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("styleIdentifier")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("styleIdentifier")];
        if(!fieldValue.is_null())
        {
            setStyleIdentifier(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("styleName")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("styleName")];
        if(!fieldValue.is_null())
        {
            setStyleName(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("subscript")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("subscript")];
        if(!fieldValue.is_null())
        {
            setSubscript(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("superscript")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("superscript")];
        if(!fieldValue.is_null())
        {
            setSuperscript(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("textEffect")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("textEffect")];
        if(!fieldValue.is_null())
        {
            setTextEffect(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("underline")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("underline")];
        if(!fieldValue.is_null())
        {
            setUnderline(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("underlineColor")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("underlineColor")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<XmlColor> newItem(new XmlColor());
            newItem->fromJson(fieldValue);
            setUnderlineColor( newItem );
        }
    }
}

void Font::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_LinkIsSet)
    {
        if (m_Link.get())
        {
            m_Link->toMultipart(multipart, _XPLATSTR("link."));
        }
        
    }
    if(m_AllCapsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("allCaps"), m_AllCaps));
    }
    if(m_BidiIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("bidi"), m_Bidi));
    }
    if(m_BoldIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("bold"), m_Bold));
    }
    if(m_BoldBiIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("boldBi"), m_BoldBi));
    }
    if(m_BorderIsSet)
    {
        if (m_Border.get())
        {
            m_Border->toMultipart(multipart, _XPLATSTR("border."));
        }
        
    }
    if(m_ColorIsSet)
    {
        if (m_Color.get())
        {
            m_Color->toMultipart(multipart, _XPLATSTR("color."));
        }
        
    }
    if(m_ComplexScriptIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("complexScript"), m_ComplexScript));
    }
    if(m_DoubleStrikeThroughIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("doubleStrikeThrough"), m_DoubleStrikeThrough));
    }
    if(m_EmbossIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("emboss"), m_Emboss));
    }
    if(m_EngraveIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("engrave"), m_Engrave));
    }
    if(m_HiddenIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("hidden"), m_Hidden));
    }
    if(m_HighlightColorIsSet)
    {
        if (m_HighlightColor.get())
        {
            m_HighlightColor->toMultipart(multipart, _XPLATSTR("highlightColor."));
        }
        
    }
    if(m_ItalicIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("italic"), m_Italic));
    }
    if(m_ItalicBiIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("italicBi"), m_ItalicBi));
    }
    if(m_KerningIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("kerning"), m_Kerning));
    }
    if(m_LocaleIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("localeId"), m_LocaleId));
    }
    if(m_LocaleIdBiIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("localeIdBi"), m_LocaleIdBi));
    }
    if(m_LocaleIdFarEastIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("localeIdFarEast"), m_LocaleIdFarEast));
    }
    if(m_NameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("name"), m_Name));
        
    }
    if(m_NameAsciiIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("nameAscii"), m_NameAscii));
        
    }
    if(m_NameBiIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("nameBi"), m_NameBi));
        
    }
    if(m_NameFarEastIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("nameFarEast"), m_NameFarEast));
        
    }
    if(m_NameOtherIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("nameOther"), m_NameOther));
        
    }
    if(m_NoProofingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("noProofing"), m_NoProofing));
    }
    if(m_OutlineIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("outline"), m_Outline));
    }
    if(m_PositionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("position"), m_Position));
    }
    if(m_ScalingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("scaling"), m_Scaling));
    }
    if(m_ShadowIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("shadow"), m_Shadow));
    }
    if(m_SizeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("size"), m_Size));
    }
    if(m_SizeBiIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("sizeBi"), m_SizeBi));
    }
    if(m_SmallCapsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("smallCaps"), m_SmallCaps));
    }
    if(m_SpacingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("spacing"), m_Spacing));
    }
    if(m_StrikeThroughIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("strikeThrough"), m_StrikeThrough));
    }
    if(m_StyleIdentifierIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("styleIdentifier"), m_StyleIdentifier));
        
    }
    if(m_StyleNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("styleName"), m_StyleName));
        
    }
    if(m_SubscriptIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("subscript"), m_Subscript));
    }
    if(m_SuperscriptIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("superscript"), m_Superscript));
    }
    if(m_TextEffectIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("textEffect"), m_TextEffect));
        
    }
    if(m_UnderlineIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("underline"), m_Underline));
        
    }
    if(m_UnderlineColorIsSet)
    {
        if (m_UnderlineColor.get())
        {
            m_UnderlineColor->toMultipart(multipart, _XPLATSTR("underlineColor."));
        }
        
    }
}

void Font::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(_XPLATSTR("allCaps")))
    {
        setAllCaps(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("allCaps"))));
    }
    if(multipart->hasContent(_XPLATSTR("bidi")))
    {
        setBidi(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("bidi"))));
    }
    if(multipart->hasContent(_XPLATSTR("bold")))
    {
        setBold(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("bold"))));
    }
    if(multipart->hasContent(_XPLATSTR("boldBi")))
    {
        setBoldBi(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("boldBi"))));
    }
    if(multipart->hasContent(_XPLATSTR("border")))
    {
        if(multipart->hasContent(_XPLATSTR("border")))
        {
            std::shared_ptr<Border> newItem(new Border());
            newItem->fromMultiPart(multipart, _XPLATSTR("border."));
            setBorder( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("color")))
    {
        if(multipart->hasContent(_XPLATSTR("color")))
        {
            std::shared_ptr<XmlColor> newItem(new XmlColor());
            newItem->fromMultiPart(multipart, _XPLATSTR("color."));
            setColor( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("complexScript")))
    {
        setComplexScript(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("complexScript"))));
    }
    if(multipart->hasContent(_XPLATSTR("doubleStrikeThrough")))
    {
        setDoubleStrikeThrough(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("doubleStrikeThrough"))));
    }
    if(multipart->hasContent(_XPLATSTR("emboss")))
    {
        setEmboss(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("emboss"))));
    }
    if(multipart->hasContent(_XPLATSTR("engrave")))
    {
        setEngrave(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("engrave"))));
    }
    if(multipart->hasContent(_XPLATSTR("hidden")))
    {
        setHidden(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("hidden"))));
    }
    if(multipart->hasContent(_XPLATSTR("highlightColor")))
    {
        if(multipart->hasContent(_XPLATSTR("highlightColor")))
        {
            std::shared_ptr<XmlColor> newItem(new XmlColor());
            newItem->fromMultiPart(multipart, _XPLATSTR("highlightColor."));
            setHighlightColor( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("italic")))
    {
        setItalic(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("italic"))));
    }
    if(multipart->hasContent(_XPLATSTR("italicBi")))
    {
        setItalicBi(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("italicBi"))));
    }
    if(multipart->hasContent(_XPLATSTR("kerning")))
    {
        setKerning(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("kerning"))));
    }
    if(multipart->hasContent(_XPLATSTR("localeId")))
    {
        setLocaleId(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("localeId"))));
    }
    if(multipart->hasContent(_XPLATSTR("localeIdBi")))
    {
        setLocaleIdBi(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("localeIdBi"))));
    }
    if(multipart->hasContent(_XPLATSTR("localeIdFarEast")))
    {
        setLocaleIdFarEast(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("localeIdFarEast"))));
    }
    if(multipart->hasContent(_XPLATSTR("name")))
    {
        setName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("name"))));
    }
    if(multipart->hasContent(_XPLATSTR("nameAscii")))
    {
        setNameAscii(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("nameAscii"))));
    }
    if(multipart->hasContent(_XPLATSTR("nameBi")))
    {
        setNameBi(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("nameBi"))));
    }
    if(multipart->hasContent(_XPLATSTR("nameFarEast")))
    {
        setNameFarEast(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("nameFarEast"))));
    }
    if(multipart->hasContent(_XPLATSTR("nameOther")))
    {
        setNameOther(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("nameOther"))));
    }
    if(multipart->hasContent(_XPLATSTR("noProofing")))
    {
        setNoProofing(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("noProofing"))));
    }
    if(multipart->hasContent(_XPLATSTR("outline")))
    {
        setOutline(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("outline"))));
    }
    if(multipart->hasContent(_XPLATSTR("position")))
    {
        setPosition(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("position"))));
    }
    if(multipart->hasContent(_XPLATSTR("scaling")))
    {
        setScaling(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("scaling"))));
    }
    if(multipart->hasContent(_XPLATSTR("shadow")))
    {
        setShadow(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("shadow"))));
    }
    if(multipart->hasContent(_XPLATSTR("size")))
    {
        setSize(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("size"))));
    }
    if(multipart->hasContent(_XPLATSTR("sizeBi")))
    {
        setSizeBi(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("sizeBi"))));
    }
    if(multipart->hasContent(_XPLATSTR("smallCaps")))
    {
        setSmallCaps(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("smallCaps"))));
    }
    if(multipart->hasContent(_XPLATSTR("spacing")))
    {
        setSpacing(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("spacing"))));
    }
    if(multipart->hasContent(_XPLATSTR("strikeThrough")))
    {
        setStrikeThrough(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("strikeThrough"))));
    }
    if(multipart->hasContent(_XPLATSTR("styleIdentifier")))
    {
        setStyleIdentifier(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("styleIdentifier"))));
    }
    if(multipart->hasContent(_XPLATSTR("styleName")))
    {
        setStyleName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("styleName"))));
    }
    if(multipart->hasContent(_XPLATSTR("subscript")))
    {
        setSubscript(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("subscript"))));
    }
    if(multipart->hasContent(_XPLATSTR("superscript")))
    {
        setSuperscript(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("superscript"))));
    }
    if(multipart->hasContent(_XPLATSTR("textEffect")))
    {
        setTextEffect(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("textEffect"))));
    }
    if(multipart->hasContent(_XPLATSTR("underline")))
    {
        setUnderline(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("underline"))));
    }
    if(multipart->hasContent(_XPLATSTR("underlineColor")))
    {
        if(multipart->hasContent(_XPLATSTR("underlineColor")))
        {
            std::shared_ptr<XmlColor> newItem(new XmlColor());
            newItem->fromMultiPart(multipart, _XPLATSTR("underlineColor."));
            setUnderlineColor( newItem );
        }
    }
}

bool Font::isAllCaps() const
{
    return m_AllCaps;
}


void Font::setAllCaps(bool value)
{
    m_AllCaps = value;
    m_AllCapsIsSet = true;
}
bool Font::allCapsIsSet() const
{
    return m_AllCapsIsSet;
}

void Font::unsetAllCaps()
{
    m_AllCapsIsSet = false;
}

bool Font::isBidi() const
{
    return m_Bidi;
}


void Font::setBidi(bool value)
{
    m_Bidi = value;
    m_BidiIsSet = true;
}
bool Font::bidiIsSet() const
{
    return m_BidiIsSet;
}

void Font::unsetBidi()
{
    m_BidiIsSet = false;
}

bool Font::isBold() const
{
    return m_Bold;
}


void Font::setBold(bool value)
{
    m_Bold = value;
    m_BoldIsSet = true;
}
bool Font::boldIsSet() const
{
    return m_BoldIsSet;
}

void Font::unsetBold()
{
    m_BoldIsSet = false;
}

bool Font::isBoldBi() const
{
    return m_BoldBi;
}


void Font::setBoldBi(bool value)
{
    m_BoldBi = value;
    m_BoldBiIsSet = true;
}
bool Font::boldBiIsSet() const
{
    return m_BoldBiIsSet;
}

void Font::unsetBoldBi()
{
    m_BoldBiIsSet = false;
}

std::shared_ptr<Border> Font::getBorder() const
{
    return m_Border;
}


void Font::setBorder(std::shared_ptr<Border> value)
{
    m_Border = value;
    m_BorderIsSet = true;
}
bool Font::borderIsSet() const
{
    return m_BorderIsSet;
}

void Font::unsetBorder()
{
    m_BorderIsSet = false;
}

std::shared_ptr<XmlColor> Font::getColor() const
{
    return m_Color;
}


void Font::setColor(std::shared_ptr<XmlColor> value)
{
    m_Color = value;
    m_ColorIsSet = true;
}
bool Font::colorIsSet() const
{
    return m_ColorIsSet;
}

void Font::unsetColor()
{
    m_ColorIsSet = false;
}

bool Font::isComplexScript() const
{
    return m_ComplexScript;
}


void Font::setComplexScript(bool value)
{
    m_ComplexScript = value;
    m_ComplexScriptIsSet = true;
}
bool Font::complexScriptIsSet() const
{
    return m_ComplexScriptIsSet;
}

void Font::unsetComplexScript()
{
    m_ComplexScriptIsSet = false;
}

bool Font::isDoubleStrikeThrough() const
{
    return m_DoubleStrikeThrough;
}


void Font::setDoubleStrikeThrough(bool value)
{
    m_DoubleStrikeThrough = value;
    m_DoubleStrikeThroughIsSet = true;
}
bool Font::doubleStrikeThroughIsSet() const
{
    return m_DoubleStrikeThroughIsSet;
}

void Font::unsetDoubleStrikeThrough()
{
    m_DoubleStrikeThroughIsSet = false;
}

bool Font::isEmboss() const
{
    return m_Emboss;
}


void Font::setEmboss(bool value)
{
    m_Emboss = value;
    m_EmbossIsSet = true;
}
bool Font::embossIsSet() const
{
    return m_EmbossIsSet;
}

void Font::unsetEmboss()
{
    m_EmbossIsSet = false;
}

bool Font::isEngrave() const
{
    return m_Engrave;
}


void Font::setEngrave(bool value)
{
    m_Engrave = value;
    m_EngraveIsSet = true;
}
bool Font::engraveIsSet() const
{
    return m_EngraveIsSet;
}

void Font::unsetEngrave()
{
    m_EngraveIsSet = false;
}

bool Font::isHidden() const
{
    return m_Hidden;
}


void Font::setHidden(bool value)
{
    m_Hidden = value;
    m_HiddenIsSet = true;
}
bool Font::hiddenIsSet() const
{
    return m_HiddenIsSet;
}

void Font::unsetHidden()
{
    m_HiddenIsSet = false;
}

std::shared_ptr<XmlColor> Font::getHighlightColor() const
{
    return m_HighlightColor;
}


void Font::setHighlightColor(std::shared_ptr<XmlColor> value)
{
    m_HighlightColor = value;
    m_HighlightColorIsSet = true;
}
bool Font::highlightColorIsSet() const
{
    return m_HighlightColorIsSet;
}

void Font::unsetHighlightColor()
{
    m_HighlightColorIsSet = false;
}

bool Font::isItalic() const
{
    return m_Italic;
}


void Font::setItalic(bool value)
{
    m_Italic = value;
    m_ItalicIsSet = true;
}
bool Font::italicIsSet() const
{
    return m_ItalicIsSet;
}

void Font::unsetItalic()
{
    m_ItalicIsSet = false;
}

bool Font::isItalicBi() const
{
    return m_ItalicBi;
}


void Font::setItalicBi(bool value)
{
    m_ItalicBi = value;
    m_ItalicBiIsSet = true;
}
bool Font::italicBiIsSet() const
{
    return m_ItalicBiIsSet;
}

void Font::unsetItalicBi()
{
    m_ItalicBiIsSet = false;
}

double Font::getKerning() const
{
    return m_Kerning;
}


void Font::setKerning(double value)
{
    m_Kerning = value;
    m_KerningIsSet = true;
}
bool Font::kerningIsSet() const
{
    return m_KerningIsSet;
}

void Font::unsetKerning()
{
    m_KerningIsSet = false;
}

int32_t Font::getLocaleId() const
{
    return m_LocaleId;
}


void Font::setLocaleId(int32_t value)
{
    m_LocaleId = value;
    m_LocaleIdIsSet = true;
}
bool Font::localeIdIsSet() const
{
    return m_LocaleIdIsSet;
}

void Font::unsetLocaleId()
{
    m_LocaleIdIsSet = false;
}

int32_t Font::getLocaleIdBi() const
{
    return m_LocaleIdBi;
}


void Font::setLocaleIdBi(int32_t value)
{
    m_LocaleIdBi = value;
    m_LocaleIdBiIsSet = true;
}
bool Font::localeIdBiIsSet() const
{
    return m_LocaleIdBiIsSet;
}

void Font::unsetLocaleIdBi()
{
    m_LocaleIdBiIsSet = false;
}

int32_t Font::getLocaleIdFarEast() const
{
    return m_LocaleIdFarEast;
}


void Font::setLocaleIdFarEast(int32_t value)
{
    m_LocaleIdFarEast = value;
    m_LocaleIdFarEastIsSet = true;
}
bool Font::localeIdFarEastIsSet() const
{
    return m_LocaleIdFarEastIsSet;
}

void Font::unsetLocaleIdFarEast()
{
    m_LocaleIdFarEastIsSet = false;
}

utility::string_t Font::getName() const
{
    return m_Name;
}


void Font::setName(utility::string_t value)
{
    m_Name = value;
    m_NameIsSet = true;
}
bool Font::nameIsSet() const
{
    return m_NameIsSet;
}

void Font::unsetName()
{
    m_NameIsSet = false;
}

utility::string_t Font::getNameAscii() const
{
    return m_NameAscii;
}


void Font::setNameAscii(utility::string_t value)
{
    m_NameAscii = value;
    m_NameAsciiIsSet = true;
}
bool Font::nameAsciiIsSet() const
{
    return m_NameAsciiIsSet;
}

void Font::unsetNameAscii()
{
    m_NameAsciiIsSet = false;
}

utility::string_t Font::getNameBi() const
{
    return m_NameBi;
}


void Font::setNameBi(utility::string_t value)
{
    m_NameBi = value;
    m_NameBiIsSet = true;
}
bool Font::nameBiIsSet() const
{
    return m_NameBiIsSet;
}

void Font::unsetNameBi()
{
    m_NameBiIsSet = false;
}

utility::string_t Font::getNameFarEast() const
{
    return m_NameFarEast;
}


void Font::setNameFarEast(utility::string_t value)
{
    m_NameFarEast = value;
    m_NameFarEastIsSet = true;
}
bool Font::nameFarEastIsSet() const
{
    return m_NameFarEastIsSet;
}

void Font::unsetNameFarEast()
{
    m_NameFarEastIsSet = false;
}

utility::string_t Font::getNameOther() const
{
    return m_NameOther;
}


void Font::setNameOther(utility::string_t value)
{
    m_NameOther = value;
    m_NameOtherIsSet = true;
}
bool Font::nameOtherIsSet() const
{
    return m_NameOtherIsSet;
}

void Font::unsetNameOther()
{
    m_NameOtherIsSet = false;
}

bool Font::isNoProofing() const
{
    return m_NoProofing;
}


void Font::setNoProofing(bool value)
{
    m_NoProofing = value;
    m_NoProofingIsSet = true;
}
bool Font::noProofingIsSet() const
{
    return m_NoProofingIsSet;
}

void Font::unsetNoProofing()
{
    m_NoProofingIsSet = false;
}

bool Font::isOutline() const
{
    return m_Outline;
}


void Font::setOutline(bool value)
{
    m_Outline = value;
    m_OutlineIsSet = true;
}
bool Font::outlineIsSet() const
{
    return m_OutlineIsSet;
}

void Font::unsetOutline()
{
    m_OutlineIsSet = false;
}

double Font::getPosition() const
{
    return m_Position;
}


void Font::setPosition(double value)
{
    m_Position = value;
    m_PositionIsSet = true;
}
bool Font::positionIsSet() const
{
    return m_PositionIsSet;
}

void Font::unsetPosition()
{
    m_PositionIsSet = false;
}

int32_t Font::getScaling() const
{
    return m_Scaling;
}


void Font::setScaling(int32_t value)
{
    m_Scaling = value;
    m_ScalingIsSet = true;
}
bool Font::scalingIsSet() const
{
    return m_ScalingIsSet;
}

void Font::unsetScaling()
{
    m_ScalingIsSet = false;
}

bool Font::isShadow() const
{
    return m_Shadow;
}


void Font::setShadow(bool value)
{
    m_Shadow = value;
    m_ShadowIsSet = true;
}
bool Font::shadowIsSet() const
{
    return m_ShadowIsSet;
}

void Font::unsetShadow()
{
    m_ShadowIsSet = false;
}

double Font::getSize() const
{
    return m_Size;
}


void Font::setSize(double value)
{
    m_Size = value;
    m_SizeIsSet = true;
}
bool Font::sizeIsSet() const
{
    return m_SizeIsSet;
}

void Font::unsetSize()
{
    m_SizeIsSet = false;
}

double Font::getSizeBi() const
{
    return m_SizeBi;
}


void Font::setSizeBi(double value)
{
    m_SizeBi = value;
    m_SizeBiIsSet = true;
}
bool Font::sizeBiIsSet() const
{
    return m_SizeBiIsSet;
}

void Font::unsetSizeBi()
{
    m_SizeBiIsSet = false;
}

bool Font::isSmallCaps() const
{
    return m_SmallCaps;
}


void Font::setSmallCaps(bool value)
{
    m_SmallCaps = value;
    m_SmallCapsIsSet = true;
}
bool Font::smallCapsIsSet() const
{
    return m_SmallCapsIsSet;
}

void Font::unsetSmallCaps()
{
    m_SmallCapsIsSet = false;
}

double Font::getSpacing() const
{
    return m_Spacing;
}


void Font::setSpacing(double value)
{
    m_Spacing = value;
    m_SpacingIsSet = true;
}
bool Font::spacingIsSet() const
{
    return m_SpacingIsSet;
}

void Font::unsetSpacing()
{
    m_SpacingIsSet = false;
}

bool Font::isStrikeThrough() const
{
    return m_StrikeThrough;
}


void Font::setStrikeThrough(bool value)
{
    m_StrikeThrough = value;
    m_StrikeThroughIsSet = true;
}
bool Font::strikeThroughIsSet() const
{
    return m_StrikeThroughIsSet;
}

void Font::unsetStrikeThrough()
{
    m_StrikeThroughIsSet = false;
}

utility::string_t Font::getStyleIdentifier() const
{
    return m_StyleIdentifier;
}


void Font::setStyleIdentifier(utility::string_t value)
{
    m_StyleIdentifier = value;
    m_StyleIdentifierIsSet = true;
}
bool Font::styleIdentifierIsSet() const
{
    return m_StyleIdentifierIsSet;
}

void Font::unsetStyleIdentifier()
{
    m_StyleIdentifierIsSet = false;
}

utility::string_t Font::getStyleName() const
{
    return m_StyleName;
}


void Font::setStyleName(utility::string_t value)
{
    m_StyleName = value;
    m_StyleNameIsSet = true;
}
bool Font::styleNameIsSet() const
{
    return m_StyleNameIsSet;
}

void Font::unsetStyleName()
{
    m_StyleNameIsSet = false;
}

bool Font::isSubscript() const
{
    return m_Subscript;
}


void Font::setSubscript(bool value)
{
    m_Subscript = value;
    m_SubscriptIsSet = true;
}
bool Font::subscriptIsSet() const
{
    return m_SubscriptIsSet;
}

void Font::unsetSubscript()
{
    m_SubscriptIsSet = false;
}

bool Font::isSuperscript() const
{
    return m_Superscript;
}


void Font::setSuperscript(bool value)
{
    m_Superscript = value;
    m_SuperscriptIsSet = true;
}
bool Font::superscriptIsSet() const
{
    return m_SuperscriptIsSet;
}

void Font::unsetSuperscript()
{
    m_SuperscriptIsSet = false;
}

utility::string_t Font::getTextEffect() const
{
    return m_TextEffect;
}


void Font::setTextEffect(utility::string_t value)
{
    m_TextEffect = value;
    m_TextEffectIsSet = true;
}
bool Font::textEffectIsSet() const
{
    return m_TextEffectIsSet;
}

void Font::unsetTextEffect()
{
    m_TextEffectIsSet = false;
}

utility::string_t Font::getUnderline() const
{
    return m_Underline;
}


void Font::setUnderline(utility::string_t value)
{
    m_Underline = value;
    m_UnderlineIsSet = true;
}
bool Font::underlineIsSet() const
{
    return m_UnderlineIsSet;
}

void Font::unsetUnderline()
{
    m_UnderlineIsSet = false;
}

std::shared_ptr<XmlColor> Font::getUnderlineColor() const
{
    return m_UnderlineColor;
}


void Font::setUnderlineColor(std::shared_ptr<XmlColor> value)
{
    m_UnderlineColor = value;
    m_UnderlineColorIsSet = true;
}
bool Font::underlineColorIsSet() const
{
    return m_UnderlineColorIsSet;
}

void Font::unsetUnderlineColor()
{
    m_UnderlineColorIsSet = false;
}

}
}
}
}
}

