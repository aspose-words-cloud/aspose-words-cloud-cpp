/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="CommentBase.h">
*   Copyright (c) 2020 Aspose.Words for Cloud
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

#include "DocumentPosition.h"
#include "../ModelBase.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Comment.
/// </summary>
class CommentBase
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
    /// Gets or sets the author name for a comment.
    /// </summary>
    utility::string_t getAuthor() const;
    bool authorIsSet() const;
    void unsetAuthor();
    void setAuthor(utility::string_t value);

    /// <summary>
    /// Gets or sets the date and time that the comment was made.
    /// </summary>
    utility::datetime getDateTime() const;
    bool dateTimeIsSet() const;
    void unsetDateTime();
    void setDateTime(utility::datetime value);

    /// <summary>
    /// Gets or sets the initials of the user associated with a specific comment.
    /// </summary>
    utility::string_t getInitial() const;
    bool initialIsSet() const;
    void unsetInitial();
    void setInitial(utility::string_t value);

    /// <summary>
    /// Gets or sets the link to comment range end node.
    /// </summary>
    std::shared_ptr<DocumentPosition> getRangeEnd() const;
    bool rangeEndIsSet() const;
    void unsetRangeEnd();
    void setRangeEnd(std::shared_ptr<DocumentPosition> value);

    /// <summary>
    /// Gets or sets the link to comment range start node.
    /// </summary>
    std::shared_ptr<DocumentPosition> getRangeStart() const;
    bool rangeStartIsSet() const;
    void unsetRangeStart();
    void setRangeStart(std::shared_ptr<DocumentPosition> value);

    /// <summary>
    /// Gets or sets text of the comment.
    /// </summary>
    utility::string_t getText() const;
    bool textIsSet() const;
    void unsetText();
    void setText(utility::string_t value);

protected:
    utility::string_t m_Author;
    bool m_AuthorIsSet;

    utility::datetime m_DateTime;
    bool m_DateTimeIsSet;

    utility::string_t m_Initial;
    bool m_InitialIsSet;

    std::shared_ptr<DocumentPosition> m_RangeEnd;
    bool m_RangeEndIsSet;

    std::shared_ptr<DocumentPosition> m_RangeStart;
    bool m_RangeStartIsSet;

    utility::string_t m_Text;
    bool m_TextIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_CommentBase_H_ */
