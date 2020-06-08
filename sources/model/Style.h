/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Style.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_Style_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_Style_H_


#include "Font.h"
#include "LinkElement.h"
#include "WordsApiLink.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Represents a single document style.
/// </summary>
class  Style
    : public LinkElement
{
public:
    Style();
    virtual ~Style();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// Style members

    /// <summary>
    /// Gets or sets all aliases of this style. If style has no aliases then empty array of string is returned.
    /// </summary>
    <DATA_TYPE_START>List<string><DATA_TYPE_END>& getAliases();
    bool aliasesIsSet() const;
    void unsetAliases();
    void setAliases(<DATA_TYPE_START>List<string><DATA_TYPE_END> const& value);
    /// <summary>
    /// Gets or sets /sets the name of the style this style is based on.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getBaseStyleName() const;
    bool baseStyleNameIsSet() const;
    void unsetBaseStyleName();
    void setBaseStyleName(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets a value indicating whether true if this style is one of the built-in styles in MS Word.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isBuiltIn() const;
    bool builtInIsSet() const;
    void unsetBuiltIn();
    void setBuiltIn(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets Font.
    /// </summary>
    <DATA_TYPE_START>Font<DATA_TYPE_END> getFont() const;
    bool fontIsSet() const;
    void unsetFont();
    void setFont(<DATA_TYPE_START>Font<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets a value indicating whether true when the style is one of the built-in Heading styles.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isIsHeading() const;
    bool isHeadingIsSet() const;
    void unsetIsHeading();
    void setIsHeading(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets a value indicating whether specifies whether this style is shown in the Quick Style gallery inside MS Word UI.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isIsQuickStyle() const;
    bool isQuickStyleIsSet() const;
    void unsetIsQuickStyle();
    void setIsQuickStyle(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the name of the Style linked to this one. Returns Empty string if no styles are linked.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getLinkedStyleName() const;
    bool linkedStyleNameIsSet() const;
    void unsetLinkedStyleName();
    void setLinkedStyleName(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the name of the style.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getName() const;
    bool nameIsSet() const;
    void unsetName();
    void setName(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets /sets the name of the style to be applied automatically to a new paragraph inserted after a paragraph formatted with the specified style.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getNextParagraphStyleName() const;
    bool nextParagraphStyleNameIsSet() const;
    void unsetNextParagraphStyleName();
    void setNextParagraphStyleName(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the locale independent style identifier for a built-in style.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getStyleIdentifier() const;
    bool styleIdentifierIsSet() const;
    void unsetStyleIdentifier();
    void setStyleIdentifier(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the style type (paragraph or character).
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getType() const;
    bool typeIsSet() const;
    void unsetType();
    void setType(<DATA_TYPE_START>string<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>List<string><DATA_TYPE_END> m_Aliases;
    bool m_AliasesIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_BaseStyleName;
    bool m_BaseStyleNameIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_BuiltIn;
    bool m_BuiltInIsSet;
    <DATA_TYPE_START>Font<DATA_TYPE_END> m_Font;
    bool m_FontIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_IsHeading;
    bool m_IsHeadingIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_IsQuickStyle;
    bool m_IsQuickStyleIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_LinkedStyleName;
    bool m_LinkedStyleNameIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_Name;
    bool m_NameIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_NextParagraphStyleName;
    bool m_NextParagraphStyleNameIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_StyleIdentifier;
    bool m_StyleIdentifierIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_Type;
    bool m_TypeIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_Style_H_ */
