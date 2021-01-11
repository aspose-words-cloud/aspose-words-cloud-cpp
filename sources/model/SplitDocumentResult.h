/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SplitDocumentResult.h">
*   Copyright (c) 2021 Aspose.Words for Cloud
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_SplitDocumentResult_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_SplitDocumentResult_H_

#include "FileLink.h"
#include "../ModelBase.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Result of splitting document.
/// </summary>
class SplitDocumentResult
    : public ModelBase
{
public:
    SplitDocumentResult();
    virtual ~SplitDocumentResult();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// SplitDocumentResult members

    /// <summary>
    /// Gets or sets the list of pages.
    /// </summary>
    std::vector<std::shared_ptr<FileLink>>& getPages();
    bool pagesIsSet() const;
    void unsetPages();
    void setPages(std::vector<std::shared_ptr<FileLink>> const& value);

    /// <summary>
    /// Gets or sets the link to the source document.
    /// </summary>
    std::shared_ptr<FileLink> getSourceDocument() const;
    bool sourceDocumentIsSet() const;
    void unsetSourceDocument();
    void setSourceDocument(std::shared_ptr<FileLink> value);

    /// <summary>
    /// Gets or sets the link to the file archive with pages.
    /// </summary>
    std::shared_ptr<FileLink> getZippedPages() const;
    bool zippedPagesIsSet() const;
    void unsetZippedPages();
    void setZippedPages(std::shared_ptr<FileLink> value);

protected:
    std::vector<std::shared_ptr<FileLink>> m_Pages;
    bool m_PagesIsSet;

    std::shared_ptr<FileLink> m_SourceDocument;
    bool m_SourceDocumentIsSet;

    std::shared_ptr<FileLink> m_ZippedPages;
    bool m_ZippedPagesIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_SplitDocumentResult_H_ */
