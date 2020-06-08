/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ReplaceTextResponse.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_ReplaceTextResponse_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_ReplaceTextResponse_H_


#include "FileLink.h"
#include "WordsResponse.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Response for \&quot;Replace text\&quot; action.
/// </summary>
class  ReplaceTextResponse
    : public WordsResponse
{
public:
    ReplaceTextResponse();
    virtual ~ReplaceTextResponse();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// ReplaceTextResponse members

    /// <summary>
    /// Gets or sets DocumentLink.
    /// </summary>
    <DATA_TYPE_START>FileLink<DATA_TYPE_END> getDocumentLink() const;
    bool documentLinkIsSet() const;
    void unsetDocumentLink();
    void setDocumentLink(<DATA_TYPE_START>FileLink<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets number of occurrences of the captured text in the document.
    /// </summary>
    <DATA_TYPE_START>int?<DATA_TYPE_END> getMatches() const;
    bool matchesIsSet() const;
    void unsetMatches();
    void setMatches(<DATA_TYPE_START>int?<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>FileLink<DATA_TYPE_END> m_DocumentLink;
    bool m_DocumentLinkIsSet;
    <DATA_TYPE_START>int?<DATA_TYPE_END> m_Matches;
    bool m_MatchesIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_ReplaceTextResponse_H_ */
