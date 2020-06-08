/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SplitDocumentResult.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_SplitDocumentResult_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_SplitDocumentResult_H_


#include "../ModelBase.h"

#include "FileLink.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Result of splitting document.
/// </summary>
class  SplitDocumentResult
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
    /// Gets or sets SourceDocument.
    /// </summary>
    <DATA_TYPE_START>FileLink<DATA_TYPE_END> getSourceDocument() const;
    bool sourceDocumentIsSet() const;
    void unsetSourceDocument();
    void setSourceDocument(<DATA_TYPE_START>FileLink<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets array of pages.
    /// </summary>
    <DATA_TYPE_START>List<FileLink><DATA_TYPE_END>& getPages();
    bool pagesIsSet() const;
    void unsetPages();
    void setPages(<DATA_TYPE_START>List<FileLink><DATA_TYPE_END> const& value);
    /// <summary>
    /// Gets or sets ZippedPages.
    /// </summary>
    <DATA_TYPE_START>FileLink<DATA_TYPE_END> getZippedPages() const;
    bool zippedPagesIsSet() const;
    void unsetZippedPages();
    void setZippedPages(<DATA_TYPE_START>FileLink<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>FileLink<DATA_TYPE_END> m_SourceDocument;
    bool m_SourceDocumentIsSet;
    <DATA_TYPE_START>List<FileLink><DATA_TYPE_END> m_Pages;
    bool m_PagesIsSet;
    <DATA_TYPE_START>FileLink<DATA_TYPE_END> m_ZippedPages;
    bool m_ZippedPagesIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_SplitDocumentResult_H_ */
