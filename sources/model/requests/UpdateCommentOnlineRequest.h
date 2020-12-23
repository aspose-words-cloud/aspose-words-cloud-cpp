/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateCommentOnlineRequest.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_UpdateCommentOnlineRequest_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_UpdateCommentOnlineRequest_H_

#include "CommentUpdate.h"
#include "HttpContent.h"
#include "cpprest/details/basic_types.h"
#include <boost/optional.hpp>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

class UpdateCommentOnlineRequest {
    public: 
 UpdateCommentOnlineRequest(
            std::shared_ptr<HttpContent> document,
            int32_t commentIndex,
            std::shared_ptr<CommentUpdate> comment,
            boost::optional< utility::string_t > loadEncoding,
            boost::optional< utility::string_t > password,
            boost::optional< utility::string_t > destFileName,
            boost::optional< utility::string_t > revisionAuthor,
            boost::optional< utility::string_t > revisionDateTime
        );

        std::shared_ptr<HttpContent> getDocument() const;
        void setDocument(std::shared_ptr<HttpContent> document);

        int32_t getCommentIndex() const;
        void setCommentIndex(int32_t commentIndex);

        std::shared_ptr<CommentUpdate> getComment() const;
        void setComment(std::shared_ptr<CommentUpdate> comment);

        boost::optional< utility::string_t > getLoadEncoding() const;
        void setLoadEncoding(boost::optional< utility::string_t > loadEncoding);

        boost::optional< utility::string_t > getPassword() const;
        void setPassword(boost::optional< utility::string_t > password);

        boost::optional< utility::string_t > getDestFileName() const;
        void setDestFileName(boost::optional< utility::string_t > destFileName);

        boost::optional< utility::string_t > getRevisionAuthor() const;
        void setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor);

        boost::optional< utility::string_t > getRevisionDateTime() const;
        void setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime);

    private:
        std::shared_ptr<HttpContent> m_Document;
        int32_t m_CommentIndex;
        std::shared_ptr<CommentUpdate> m_Comment;
        boost::optional< utility::string_t > m_LoadEncoding;
        boost::optional< utility::string_t > m_Password;
        boost::optional< utility::string_t > m_DestFileName;
        boost::optional< utility::string_t > m_RevisionAuthor;
        boost::optional< utility::string_t > m_RevisionDateTime;
};

}
}
}
}
}

#endif  /* ASPOSE_WORDS_CLOUD_API_MODELS_UpdateCommentOnlineRequest_H_ */
