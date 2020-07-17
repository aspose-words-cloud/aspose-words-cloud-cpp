/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DocumentEntryList.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_DocumentEntryList_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_DocumentEntryList_H_

#include "DocumentEntry.h"
#include "../ModelBase.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Represents a list of documents which will be appended to the original resource document.
/// </summary>
class DocumentEntryList
    : public ModelBase
{
public:
    DocumentEntryList();
    virtual ~DocumentEntryList();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// DocumentEntryList members

    /// <summary>
    /// Gets or sets parameter that indicates to apply headers and footers from base document to appending documents. Default is true.
    /// </summary>
    bool isApplyBaseDocumentHeadersAndFootersToAppendingDocuments() const;
    bool applyBaseDocumentHeadersAndFootersToAppendingDocumentsIsSet() const;
    void unsetApplyBaseDocumentHeadersAndFootersToAppendingDocuments();
    void setApplyBaseDocumentHeadersAndFootersToAppendingDocuments(bool value);

    /// <summary>
    /// Gets or sets list of documents.
    /// </summary>
    std::vector<std::shared_ptr<DocumentEntry>>& getDocumentEntries();
    bool documentEntriesIsSet() const;
    void unsetDocumentEntries();
    void setDocumentEntries(std::vector<std::shared_ptr<DocumentEntry>> const& value);

protected:
    bool m_ApplyBaseDocumentHeadersAndFootersToAppendingDocuments;
    bool m_ApplyBaseDocumentHeadersAndFootersToAppendingDocumentsIsSet;

    std::vector<std::shared_ptr<DocumentEntry>> m_DocumentEntries;
    bool m_DocumentEntriesIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_DocumentEntryList_H_ */
