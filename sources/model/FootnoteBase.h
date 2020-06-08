/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FootnoteBase.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_FootnoteBase_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_FootnoteBase_H_


#include "../ModelBase.h"

#include "DocumentPosition.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Footnote base class.
/// </summary>
class  FootnoteBase
    : public ModelBase
{
public:
    FootnoteBase();
    virtual ~FootnoteBase();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// FootnoteBase members

    /// <summary>
    /// Gets or sets Position.
    /// </summary>
    <DATA_TYPE_START>DocumentPosition<DATA_TYPE_END> getPosition() const;
    bool positionIsSet() const;
    void unsetPosition();
    void setPosition(<DATA_TYPE_START>DocumentPosition<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns a value that specifies whether this is a footnote or endnote.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getFootnoteType() const;
    bool footnoteTypeIsSet() const;
    void unsetFootnoteType();
    void setFootnoteType(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets /sets custom reference mark to be used for this footnote. Default value is Empty, meaning auto-numbered footnotes are used.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getReferenceMark() const;
    bool referenceMarkIsSet() const;
    void unsetReferenceMark();
    void setReferenceMark(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets this is a convenience property that allows to easily get or set text of the footnote.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getText() const;
    bool textIsSet() const;
    void unsetText();
    void setText(<DATA_TYPE_START>string<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>DocumentPosition<DATA_TYPE_END> m_Position;
    bool m_PositionIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_FootnoteType;
    bool m_FootnoteTypeIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_ReferenceMark;
    bool m_ReferenceMarkIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_Text;
    bool m_TextIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_FootnoteBase_H_ */
