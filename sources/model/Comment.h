
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Comment.h">
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

#ifndef IO_SWAGGER_CLIENT_MODEL_Comment_H_
#define IO_SWAGGER_CLIENT_MODEL_Comment_H_


#include "DocumentPosition.h"
#include "CommentLink.h"
#include <cpprest/details/basic_types.h>
#include "StoryChildNodes.h"
#include "WordsApiLink.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

/// <summary>
/// Comment.
/// </summary>
class  Comment
    : public CommentLink
{
public:
    Comment();
    virtual ~Comment();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// Comment members

    /// <summary>
    /// Returns or sets the author name for a comment.
    /// </summary>
    utility::string_t getAuthor() const;
    bool authorIsSet() const;
    void unsetAuthor();
    void setAuthor(utility::string_t value);
    /// <summary>
    /// Content of comment
    /// </summary>
    std::shared_ptr<StoryChildNodes> getContent() const;
    bool contentIsSet() const;
    void unsetContent();
    void setContent(std::shared_ptr<StoryChildNodes> value);
    /// <summary>
    /// Gets the date and time that the comment was made.
    /// </summary>
    utility::datetime getDateTime() const;
    bool dateTimeIsSet() const;
    void unsetDateTime();
    void setDateTime(utility::datetime value);
    /// <summary>
    /// Returns or sets the initials of the user associated with a specific comment.
    /// </summary>
    utility::string_t getInitial() const;
    bool initialIsSet() const;
    void unsetInitial();
    void setInitial(utility::string_t value);
    /// <summary>
    /// Link to comment range end node.
    /// </summary>
    std::shared_ptr<DocumentPosition> getRangeEnd() const;
    bool rangeEndIsSet() const;
    void unsetRangeEnd();
    void setRangeEnd(std::shared_ptr<DocumentPosition> value);
    /// <summary>
    /// Link to comment range start node.
    /// </summary>
    std::shared_ptr<DocumentPosition> getRangeStart() const;
    bool rangeStartIsSet() const;
    void unsetRangeStart();
    void setRangeStart(std::shared_ptr<DocumentPosition> value);
    /// <summary>
    /// This is a convenience property that allows to easily get or set text of the comment.
    /// </summary>
    utility::string_t getText() const;
    bool textIsSet() const;
    void unsetText();
    void setText(utility::string_t value);

protected:
    utility::string_t m_Author;
    bool m_AuthorIsSet;
    std::shared_ptr<StoryChildNodes> m_Content;
    bool m_ContentIsSet;
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

#endif /* IO_SWAGGER_CLIENT_MODEL_Comment_H_ */
