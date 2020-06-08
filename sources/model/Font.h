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
    bool isAllCaps() const;
    bool allCapsIsSet() const;
    void unsetAllCaps();
    void setAllCaps(bool value);
    /// <summary>
    /// Gets or sets specifies whether the contents of this run shall have right-to-left characteristics.             
    /// </summary>
    bool isBidi() const;
    bool bidiIsSet() const;
    void unsetBidi();
    void setBidi(bool value);
    /// <summary>
    /// Gets or sets true if the font is formatted as bold.             
    /// </summary>
    bool isBold() const;
    bool boldIsSet() const;
    void unsetBold();
    void setBold(bool value);
    /// <summary>
    /// Gets or sets true if the right-to-left text is formatted as bold.             
    /// </summary>
    bool isBoldBi() const;
    bool boldBiIsSet() const;
    void unsetBoldBi();
    void setBoldBi(bool value);
    /// <summary>
    /// Gets or sets Border.
    /// </summary>
    std::shared_ptr<Border> getBorder() const;
    bool borderIsSet() const;
    void unsetBorder();
    void setBorder(std::shared_ptr<Border> value);
    /// <summary>
    /// Gets or sets Color.
    /// </summary>
    std::shared_ptr<XmlColor> getColor() const;
    bool colorIsSet() const;
    void unsetColor();
    void setColor(std::shared_ptr<XmlColor> value);
    /// <summary>
    /// Gets or sets specifies whether the contents of this run shall be treated as complex script text regardless of their Unicode character values when determining the formatting for this run.             
    /// </summary>
    bool isComplexScript() const;
    bool complexScriptIsSet() const;
    void unsetComplexScript();
    void setComplexScript(bool value);
    /// <summary>
    /// Gets or sets true if the font is formatted as double strikethrough text.             
    /// </summary>
    bool isDoubleStrikeThrough() const;
    bool doubleStrikeThroughIsSet() const;
    void unsetDoubleStrikeThrough();
    void setDoubleStrikeThrough(bool value);
    /// <summary>
    /// Gets or sets true if the font is formatted as embossed.             
    /// </summary>
    bool isEmboss() const;
    bool embossIsSet() const;
    void unsetEmboss();
    void setEmboss(bool value);
    /// <summary>
    /// Gets or sets true if the font is formatted as engraved.             
    /// </summary>
    bool isEngrave() const;
    bool engraveIsSet() const;
    void unsetEngrave();
    void setEngrave(bool value);
    /// <summary>
    /// Gets or sets true if the font is formatted as hidden text.             
    /// </summary>
    bool isHidden() const;
    bool hiddenIsSet() const;
    void unsetHidden();
    void setHidden(bool value);
    /// <summary>
    /// Gets or sets HighlightColor.
    /// </summary>
    std::shared_ptr<XmlColor> getHighlightColor() const;
    bool highlightColorIsSet() const;
    void unsetHighlightColor();
    void setHighlightColor(std::shared_ptr<XmlColor> value);
    /// <summary>
    /// Gets or sets true if the font is formatted as italic.             
    /// </summary>
    bool isItalic() const;
    bool italicIsSet() const;
    void unsetItalic();
    void setItalic(bool value);
    /// <summary>
    /// Gets or sets true if the right-to-left text is formatted as italic.             
    /// </summary>
    bool isItalicBi() const;
    bool italicBiIsSet() const;
    void unsetItalicBi();
    void setItalicBi(bool value);
    /// <summary>
    /// Gets or sets the font size at which kerning starts.             
    /// </summary>
    double getKerning() const;
    bool kerningIsSet() const;
    void unsetKerning();
    void setKerning(double value);
    /// <summary>
    /// Gets or sets the locale identifier (language) of the formatted characters.             
    /// </summary>
    int32_t getLocaleId() const;
    bool localeIdIsSet() const;
    void unsetLocaleId();
    void setLocaleId(int32_t value);
    /// <summary>
    /// Gets or sets the locale identifier (language) of the formatted right-to-left characters.             
    /// </summary>
    int32_t getLocaleIdBi() const;
    bool localeIdBiIsSet() const;
    void unsetLocaleIdBi();
    void setLocaleIdBi(int32_t value);
    /// <summary>
    /// Gets or sets the locale identifier (language) of the formatted Asian characters.             
    /// </summary>
    int32_t getLocaleIdFarEast() const;
    bool localeIdFarEastIsSet() const;
    void unsetLocaleIdFarEast();
    void setLocaleIdFarEast(int32_t value);
    /// <summary>
    /// Gets or sets the name of the font.             
    /// </summary>
    utility::string_t getName() const;
    bool nameIsSet() const;
    void unsetName();
    void setName(utility::string_t value);
    /// <summary>
    /// Gets or sets returns or sets the font used for Latin text (characters with character codes from 0 (zero) through 127).             
    /// </summary>
    utility::string_t getNameAscii() const;
    bool nameAsciiIsSet() const;
    void unsetNameAscii();
    void setNameAscii(utility::string_t value);
    /// <summary>
    /// Gets or sets returns or sets the name of the font in a right-to-left language document.             
    /// </summary>
    utility::string_t getNameBi() const;
    bool nameBiIsSet() const;
    void unsetNameBi();
    void setNameBi(utility::string_t value);
    /// <summary>
    /// Gets or sets returns or sets an East Asian font name.             
    /// </summary>
    utility::string_t getNameFarEast() const;
    bool nameFarEastIsSet() const;
    void unsetNameFarEast();
    void setNameFarEast(utility::string_t value);
    /// <summary>
    /// Gets or sets returns or sets the font used for characters with character codes from 128 through 255.             
    /// </summary>
    utility::string_t getNameOther() const;
    bool nameOtherIsSet() const;
    void unsetNameOther();
    void setNameOther(utility::string_t value);
    /// <summary>
    /// Gets or sets true when the formatted characters are not to be spell checked.
    /// </summary>
    bool isNoProofing() const;
    bool noProofingIsSet() const;
    void unsetNoProofing();
    void setNoProofing(bool value);
    /// <summary>
    /// Gets or sets true if the font is formatted as outline.             
    /// </summary>
    bool isOutline() const;
    bool outlineIsSet() const;
    void unsetOutline();
    void setOutline(bool value);
    /// <summary>
    /// Gets or sets the position of text (in points) relative to the base line. A positive number raises the text, and a negative number lowers it.             
    /// </summary>
    double getPosition() const;
    bool positionIsSet() const;
    void unsetPosition();
    void setPosition(double value);
    /// <summary>
    /// Gets or sets character width scaling in percent.             
    /// </summary>
    int32_t getScaling() const;
    bool scalingIsSet() const;
    void unsetScaling();
    void setScaling(int32_t value);
    /// <summary>
    /// Gets or sets true if the font is formatted as shadowed.             
    /// </summary>
    bool isShadow() const;
    bool shadowIsSet() const;
    void unsetShadow();
    void setShadow(bool value);
    /// <summary>
    /// Gets or sets the font size in points.             
    /// </summary>
    double getSize() const;
    bool sizeIsSet() const;
    void unsetSize();
    void setSize(double value);
    /// <summary>
    /// Gets or sets the font size in points used in a right-to-left document.             
    /// </summary>
    double getSizeBi() const;
    bool sizeBiIsSet() const;
    void unsetSizeBi();
    void setSizeBi(double value);
    /// <summary>
    /// Gets or sets true if the font is formatted as small capital letters.             
    /// </summary>
    bool isSmallCaps() const;
    bool smallCapsIsSet() const;
    void unsetSmallCaps();
    void setSmallCaps(bool value);
    /// <summary>
    /// Gets or sets returns or sets the spacing (in points) between characters.             
    /// </summary>
    double getSpacing() const;
    bool spacingIsSet() const;
    void unsetSpacing();
    void setSpacing(double value);
    /// <summary>
    /// Gets or sets true if the font is formatted as strikethrough text.             
    /// </summary>
    bool isStrikeThrough() const;
    bool strikeThroughIsSet() const;
    void unsetStrikeThrough();
    void setStrikeThrough(bool value);
    /// <summary>
    /// Gets or sets the locale independent style identifier of the character style applied to this formatting.
    /// </summary>
    utility::string_t getStyleIdentifier() const;
    bool styleIdentifierIsSet() const;
    void unsetStyleIdentifier();
    void setStyleIdentifier(utility::string_t value);
    /// <summary>
    /// Gets or sets the name of the character style applied to this formatting.             
    /// </summary>
    utility::string_t getStyleName() const;
    bool styleNameIsSet() const;
    void unsetStyleName();
    void setStyleName(utility::string_t value);
    /// <summary>
    /// Gets or sets true if the font is formatted as subscript.             
    /// </summary>
    bool isSubscript() const;
    bool subscriptIsSet() const;
    void unsetSubscript();
    void setSubscript(bool value);
    /// <summary>
    /// Gets or sets true if the font is formatted as superscript.             
    /// </summary>
    bool isSuperscript() const;
    bool superscriptIsSet() const;
    void unsetSuperscript();
    void setSuperscript(bool value);
    /// <summary>
    /// Gets or sets the font animation effect.
    /// </summary>
    utility::string_t getTextEffect() const;
    bool textEffectIsSet() const;
    void unsetTextEffect();
    void setTextEffect(utility::string_t value);
    /// <summary>
    /// Gets or sets the type of underline applied to the font.
    /// </summary>
    utility::string_t getUnderline() const;
    bool underlineIsSet() const;
    void unsetUnderline();
    void setUnderline(utility::string_t value);
    /// <summary>
    /// Gets or sets UnderlineColor.
    /// </summary>
    std::shared_ptr<XmlColor> getUnderlineColor() const;
    bool underlineColorIsSet() const;
    void unsetUnderlineColor();
    void setUnderlineColor(std::shared_ptr<XmlColor> value);

protected:
    bool m_AllCaps;
    bool m_AllCapsIsSet;
    bool m_Bidi;
    bool m_BidiIsSet;
    bool m_Bold;
    bool m_BoldIsSet;
    bool m_BoldBi;
    bool m_BoldBiIsSet;
    std::shared_ptr<Border> m_Border;
    bool m_BorderIsSet;
    std::shared_ptr<XmlColor> m_Color;
    bool m_ColorIsSet;
    bool m_ComplexScript;
    bool m_ComplexScriptIsSet;
    bool m_DoubleStrikeThrough;
    bool m_DoubleStrikeThroughIsSet;
    bool m_Emboss;
    bool m_EmbossIsSet;
    bool m_Engrave;
    bool m_EngraveIsSet;
    bool m_Hidden;
    bool m_HiddenIsSet;
    std::shared_ptr<XmlColor> m_HighlightColor;
    bool m_HighlightColorIsSet;
    bool m_Italic;
    bool m_ItalicIsSet;
    bool m_ItalicBi;
    bool m_ItalicBiIsSet;
    double m_Kerning;
    bool m_KerningIsSet;
    int32_t m_LocaleId;
    bool m_LocaleIdIsSet;
    int32_t m_LocaleIdBi;
    bool m_LocaleIdBiIsSet;
    int32_t m_LocaleIdFarEast;
    bool m_LocaleIdFarEastIsSet;
    utility::string_t m_Name;
    bool m_NameIsSet;
    utility::string_t m_NameAscii;
    bool m_NameAsciiIsSet;
    utility::string_t m_NameBi;
    bool m_NameBiIsSet;
    utility::string_t m_NameFarEast;
    bool m_NameFarEastIsSet;
    utility::string_t m_NameOther;
    bool m_NameOtherIsSet;
    bool m_NoProofing;
    bool m_NoProofingIsSet;
    bool m_Outline;
    bool m_OutlineIsSet;
    double m_Position;
    bool m_PositionIsSet;
    int32_t m_Scaling;
    bool m_ScalingIsSet;
    bool m_Shadow;
    bool m_ShadowIsSet;
    double m_Size;
    bool m_SizeIsSet;
    double m_SizeBi;
    bool m_SizeBiIsSet;
    bool m_SmallCaps;
    bool m_SmallCapsIsSet;
    double m_Spacing;
    bool m_SpacingIsSet;
    bool m_StrikeThrough;
    bool m_StrikeThroughIsSet;
    utility::string_t m_StyleIdentifier;
    bool m_StyleIdentifierIsSet;
    utility::string_t m_StyleName;
    bool m_StyleNameIsSet;
    bool m_Subscript;
    bool m_SubscriptIsSet;
    bool m_Superscript;
    bool m_SuperscriptIsSet;
    utility::string_t m_TextEffect;
    bool m_TextEffectIsSet;
    utility::string_t m_Underline;
    bool m_UnderlineIsSet;
    std::shared_ptr<XmlColor> m_UnderlineColor;
    bool m_UnderlineColorIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_Font_H_ */
