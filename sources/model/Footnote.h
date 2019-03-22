
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Footnote.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_Footnote_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_Footnote_H_


#include "DocumentPosition.h"
#include "FootnoteLink.h"
#include <cpprest/details/basic_types.h>
#include "StoryChildNodes.h"
#include "WordsApiLink.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Footnote.
/// </summary>
class  Footnote
    : public FootnoteLink
{
public:
    Footnote();
    virtual ~Footnote();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// Footnote members

    /// <summary>
    /// Content of footnote.
    /// </summary>
    std::shared_ptr<StoryChildNodes> getContent() const;
    bool contentIsSet() const;
    void unsetContent();
    void setContent(std::shared_ptr<StoryChildNodes> value);
    /// <summary>
    /// Returns a value that specifies whether this is a footnote or endnote.
    /// </summary>
    utility::string_t getFootnoteType() const;
    bool footnoteTypeIsSet() const;
    void unsetFootnoteType();
    void setFootnoteType(utility::string_t value);
    /// <summary>
    /// Link to comment range start node.
    /// </summary>
    std::shared_ptr<DocumentPosition> getPosition() const;
    bool positionIsSet() const;
    void unsetPosition();
    void setPosition(std::shared_ptr<DocumentPosition> value);
    /// <summary>
    /// Gets/sets custom reference mark to be used for this footnote. Default value is , meaning auto-numbered footnotes are used.
    /// </summary>
    utility::string_t getReferenceMark() const;
    bool referenceMarkIsSet() const;
    void unsetReferenceMark();
    void setReferenceMark(utility::string_t value);
    /// <summary>
    /// This is a convenience property that allows to easily get or set text of the footnote.
    /// </summary>
    utility::string_t getText() const;
    bool textIsSet() const;
    void unsetText();
    void setText(utility::string_t value);

protected:
    std::shared_ptr<StoryChildNodes> m_Content;
    bool m_ContentIsSet;
    utility::string_t m_FootnoteType;
    bool m_FootnoteTypeIsSet;
    std::shared_ptr<DocumentPosition> m_Position;
    bool m_PositionIsSet;
    utility::string_t m_ReferenceMark;
    bool m_ReferenceMarkIsSet;
    utility::string_t m_Text;
    bool m_TextIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_Footnote_H_ */
