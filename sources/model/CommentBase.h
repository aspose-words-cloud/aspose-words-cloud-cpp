/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="CommentBase.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_CommentBase_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_CommentBase_H_


#include "../ModelBase.h"

#include "DocumentPosition.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Comment.
/// </summary>
class  CommentBase
    : public ModelBase
{
public:
    CommentBase();
    virtual ~CommentBase();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// CommentBase members

    /// <summary>
    /// Gets or sets RangeStart.
    /// </summary>
    <DATA_TYPE_START>DocumentPosition<DATA_TYPE_END> getRangeStart() const;
    bool rangeStartIsSet() const;
    void unsetRangeStart();
    void setRangeStart(<DATA_TYPE_START>DocumentPosition<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets RangeEnd.
    /// </summary>
    <DATA_TYPE_START>DocumentPosition<DATA_TYPE_END> getRangeEnd() const;
    bool rangeEndIsSet() const;
    void unsetRangeEnd();
    void setRangeEnd(<DATA_TYPE_START>DocumentPosition<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns or sets the author name for a comment.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getAuthor() const;
    bool authorIsSet() const;
    void unsetAuthor();
    void setAuthor(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns or sets the initials of the user associated with a specific comment.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getInitial() const;
    bool initialIsSet() const;
    void unsetInitial();
    void setInitial(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the date and time that the comment was made.
    /// </summary>
    <DATA_TYPE_START>DateTime?<DATA_TYPE_END> getDateTime() const;
    bool dateTimeIsSet() const;
    void unsetDateTime();
    void setDateTime(<DATA_TYPE_START>DateTime?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets this is a convenience property that allows to easily get or set text of the comment.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getText() const;
    bool textIsSet() const;
    void unsetText();
    void setText(<DATA_TYPE_START>string<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>DocumentPosition<DATA_TYPE_END> m_RangeStart;
    bool m_RangeStartIsSet;
    <DATA_TYPE_START>DocumentPosition<DATA_TYPE_END> m_RangeEnd;
    bool m_RangeEndIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_Author;
    bool m_AuthorIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_Initial;
    bool m_InitialIsSet;
    <DATA_TYPE_START>DateTime?<DATA_TYPE_END> m_DateTime;
    bool m_DateTimeIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_Text;
    bool m_TextIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_CommentBase_H_ */
