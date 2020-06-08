/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Font.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_Font_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_Font_H_


#include "Border.h"
#include "LinkElement.h"
#include "WordsApiLink.h"
#include "XmlColor.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Font element.             
/// </summary>
class  Font
    : public LinkElement
{
public:
    Font();
    virtual ~Font();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// Font members

    /// <summary>
    /// Gets or sets true if the font is formatted as all capital letters.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isAllCaps() const;
    bool allCapsIsSet() const;
    void unsetAllCaps();
    void setAllCaps(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies whether the contents of this run shall have right-to-left characteristics.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isBidi() const;
    bool bidiIsSet() const;
    void unsetBidi();
    void setBidi(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets true if the font is formatted as bold.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isBold() const;
    bool boldIsSet() const;
    void unsetBold();
    void setBold(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets true if the right-to-left text is formatted as bold.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isBoldBi() const;
    bool boldBiIsSet() const;
    void unsetBoldBi();
    void setBoldBi(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets Border.
    /// </summary>
    <DATA_TYPE_START>Border<DATA_TYPE_END> getBorder() const;
    bool borderIsSet() const;
    void unsetBorder();
    void setBorder(<DATA_TYPE_START>Border<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets Color.
    /// </summary>
    <DATA_TYPE_START>XmlColor<DATA_TYPE_END> getColor() const;
    bool colorIsSet() const;
    void unsetColor();
    void setColor(<DATA_TYPE_START>XmlColor<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies whether the contents of this run shall be treated as complex script text regardless of their Unicode character values when determining the formatting for this run.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isComplexScript() const;
    bool complexScriptIsSet() const;
    void unsetComplexScript();
    void setComplexScript(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets true if the font is formatted as double strikethrough text.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isDoubleStrikeThrough() const;
    bool doubleStrikeThroughIsSet() const;
    void unsetDoubleStrikeThrough();
    void setDoubleStrikeThrough(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets true if the font is formatted as embossed.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isEmboss() const;
    bool embossIsSet() const;
    void unsetEmboss();
    void setEmboss(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets true if the font is formatted as engraved.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isEngrave() const;
    bool engraveIsSet() const;
    void unsetEngrave();
    void setEngrave(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets true if the font is formatted as hidden text.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isHidden() const;
    bool hiddenIsSet() const;
    void unsetHidden();
    void setHidden(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets HighlightColor.
    /// </summary>
    <DATA_TYPE_START>XmlColor<DATA_TYPE_END> getHighlightColor() const;
    bool highlightColorIsSet() const;
    void unsetHighlightColor();
    void setHighlightColor(<DATA_TYPE_START>XmlColor<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets true if the font is formatted as italic.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isItalic() const;
    bool italicIsSet() const;
    void unsetItalic();
    void setItalic(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets true if the right-to-left text is formatted as italic.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isItalicBi() const;
    bool italicBiIsSet() const;
    void unsetItalicBi();
    void setItalicBi(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the font size at which kerning starts.             
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getKerning() const;
    bool kerningIsSet() const;
    void unsetKerning();
    void setKerning(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the locale identifier (language) of the formatted characters.             
    /// </summary>
    <DATA_TYPE_START>int?<DATA_TYPE_END> getLocaleId() const;
    bool localeIdIsSet() const;
    void unsetLocaleId();
    void setLocaleId(<DATA_TYPE_START>int?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the locale identifier (language) of the formatted right-to-left characters.             
    /// </summary>
    <DATA_TYPE_START>int?<DATA_TYPE_END> getLocaleIdBi() const;
    bool localeIdBiIsSet() const;
    void unsetLocaleIdBi();
    void setLocaleIdBi(<DATA_TYPE_START>int?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the locale identifier (language) of the formatted Asian characters.             
    /// </summary>
    <DATA_TYPE_START>int?<DATA_TYPE_END> getLocaleIdFarEast() const;
    bool localeIdFarEastIsSet() const;
    void unsetLocaleIdFarEast();
    void setLocaleIdFarEast(<DATA_TYPE_START>int?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the name of the font.             
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getName() const;
    bool nameIsSet() const;
    void unsetName();
    void setName(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns or sets the font used for Latin text (characters with character codes from 0 (zero) through 127).             
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getNameAscii() const;
    bool nameAsciiIsSet() const;
    void unsetNameAscii();
    void setNameAscii(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns or sets the name of the font in a right-to-left language document.             
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getNameBi() const;
    bool nameBiIsSet() const;
    void unsetNameBi();
    void setNameBi(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns or sets an East Asian font name.             
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getNameFarEast() const;
    bool nameFarEastIsSet() const;
    void unsetNameFarEast();
    void setNameFarEast(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns or sets the font used for characters with character codes from 128 through 255.             
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getNameOther() const;
    bool nameOtherIsSet() const;
    void unsetNameOther();
    void setNameOther(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets true when the formatted characters are not to be spell checked.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isNoProofing() const;
    bool noProofingIsSet() const;
    void unsetNoProofing();
    void setNoProofing(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets true if the font is formatted as outline.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isOutline() const;
    bool outlineIsSet() const;
    void unsetOutline();
    void setOutline(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the position of text (in points) relative to the base line. A positive number raises the text, and a negative number lowers it.             
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getPosition() const;
    bool positionIsSet() const;
    void unsetPosition();
    void setPosition(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets character width scaling in percent.             
    /// </summary>
    <DATA_TYPE_START>int?<DATA_TYPE_END> getScaling() const;
    bool scalingIsSet() const;
    void unsetScaling();
    void setScaling(<DATA_TYPE_START>int?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets true if the font is formatted as shadowed.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isShadow() const;
    bool shadowIsSet() const;
    void unsetShadow();
    void setShadow(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the font size in points.             
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getSize() const;
    bool sizeIsSet() const;
    void unsetSize();
    void setSize(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the font size in points used in a right-to-left document.             
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getSizeBi() const;
    bool sizeBiIsSet() const;
    void unsetSizeBi();
    void setSizeBi(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets true if the font is formatted as small capital letters.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isSmallCaps() const;
    bool smallCapsIsSet() const;
    void unsetSmallCaps();
    void setSmallCaps(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns or sets the spacing (in points) between characters.             
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getSpacing() const;
    bool spacingIsSet() const;
    void unsetSpacing();
    void setSpacing(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets true if the font is formatted as strikethrough text.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isStrikeThrough() const;
    bool strikeThroughIsSet() const;
    void unsetStrikeThrough();
    void setStrikeThrough(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the locale independent style identifier of the character style applied to this formatting.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getStyleIdentifier() const;
    bool styleIdentifierIsSet() const;
    void unsetStyleIdentifier();
    void setStyleIdentifier(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the name of the character style applied to this formatting.             
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getStyleName() const;
    bool styleNameIsSet() const;
    void unsetStyleName();
    void setStyleName(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets true if the font is formatted as subscript.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isSubscript() const;
    bool subscriptIsSet() const;
    void unsetSubscript();
    void setSubscript(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets true if the font is formatted as superscript.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isSuperscript() const;
    bool superscriptIsSet() const;
    void unsetSuperscript();
    void setSuperscript(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the font animation effect.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getTextEffect() const;
    bool textEffectIsSet() const;
    void unsetTextEffect();
    void setTextEffect(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the type of underline applied to the font.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getUnderline() const;
    bool underlineIsSet() const;
    void unsetUnderline();
    void setUnderline(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets UnderlineColor.
    /// </summary>
    <DATA_TYPE_START>XmlColor<DATA_TYPE_END> getUnderlineColor() const;
    bool underlineColorIsSet() const;
    void unsetUnderlineColor();
    void setUnderlineColor(<DATA_TYPE_START>XmlColor<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_AllCaps;
    bool m_AllCapsIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_Bidi;
    bool m_BidiIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_Bold;
    bool m_BoldIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_BoldBi;
    bool m_BoldBiIsSet;
    <DATA_TYPE_START>Border<DATA_TYPE_END> m_Border;
    bool m_BorderIsSet;
    <DATA_TYPE_START>XmlColor<DATA_TYPE_END> m_Color;
    bool m_ColorIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_ComplexScript;
    bool m_ComplexScriptIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_DoubleStrikeThrough;
    bool m_DoubleStrikeThroughIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_Emboss;
    bool m_EmbossIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_Engrave;
    bool m_EngraveIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_Hidden;
    bool m_HiddenIsSet;
    <DATA_TYPE_START>XmlColor<DATA_TYPE_END> m_HighlightColor;
    bool m_HighlightColorIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_Italic;
    bool m_ItalicIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_ItalicBi;
    bool m_ItalicBiIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_Kerning;
    bool m_KerningIsSet;
    <DATA_TYPE_START>int?<DATA_TYPE_END> m_LocaleId;
    bool m_LocaleIdIsSet;
    <DATA_TYPE_START>int?<DATA_TYPE_END> m_LocaleIdBi;
    bool m_LocaleIdBiIsSet;
    <DATA_TYPE_START>int?<DATA_TYPE_END> m_LocaleIdFarEast;
    bool m_LocaleIdFarEastIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_Name;
    bool m_NameIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_NameAscii;
    bool m_NameAsciiIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_NameBi;
    bool m_NameBiIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_NameFarEast;
    bool m_NameFarEastIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_NameOther;
    bool m_NameOtherIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_NoProofing;
    bool m_NoProofingIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_Outline;
    bool m_OutlineIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_Position;
    bool m_PositionIsSet;
    <DATA_TYPE_START>int?<DATA_TYPE_END> m_Scaling;
    bool m_ScalingIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_Shadow;
    bool m_ShadowIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_Size;
    bool m_SizeIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_SizeBi;
    bool m_SizeBiIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_SmallCaps;
    bool m_SmallCapsIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_Spacing;
    bool m_SpacingIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_StrikeThrough;
    bool m_StrikeThroughIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_StyleIdentifier;
    bool m_StyleIdentifierIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_StyleName;
    bool m_StyleNameIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_Subscript;
    bool m_SubscriptIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_Superscript;
    bool m_SuperscriptIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_TextEffect;
    bool m_TextEffectIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_Underline;
    bool m_UnderlineIsSet;
    <DATA_TYPE_START>XmlColor<DATA_TYPE_END> m_UnderlineColor;
    bool m_UnderlineColorIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_Font_H_ */
