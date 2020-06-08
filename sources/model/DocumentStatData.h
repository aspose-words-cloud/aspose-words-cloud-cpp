/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DocumentStatData.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_DocumentStatData_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_DocumentStatData_H_


#include "../ModelBase.h"

#include "FootnotesStatData.h"
#include "PageStatData.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Container for the document&#x27;s statistical data.
/// </summary>
class  DocumentStatData
    : public ModelBase
{
public:
    DocumentStatData();
    virtual ~DocumentStatData();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// DocumentStatData members

    /// <summary>
    /// Gets or sets total count of words in the document.
    /// </summary>
    <DATA_TYPE_START>int?<DATA_TYPE_END> getWordCount() const;
    bool wordCountIsSet() const;
    void unsetWordCount();
    void setWordCount(<DATA_TYPE_START>int?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets total count of paragraphs in the document.
    /// </summary>
    <DATA_TYPE_START>int?<DATA_TYPE_END> getParagraphCount() const;
    bool paragraphCountIsSet() const;
    void unsetParagraphCount();
    void setParagraphCount(<DATA_TYPE_START>int?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets total count of pages in the document.
    /// </summary>
    <DATA_TYPE_START>int?<DATA_TYPE_END> getPageCount() const;
    bool pageCountIsSet() const;
    void unsetPageCount();
    void setPageCount(<DATA_TYPE_START>int?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets FootnotesStatData.
    /// </summary>
    <DATA_TYPE_START>FootnotesStatData<DATA_TYPE_END> getFootnotesStatData() const;
    bool footnotesStatDataIsSet() const;
    void unsetFootnotesStatData();
    void setFootnotesStatData(<DATA_TYPE_START>FootnotesStatData<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets detailed statistics of all pages.
    /// </summary>
    <DATA_TYPE_START>List<PageStatData><DATA_TYPE_END>& getPageStatData();
    bool pageStatDataIsSet() const;
    void unsetPageStatData();
    void setPageStatData(<DATA_TYPE_START>List<PageStatData><DATA_TYPE_END> const& value);

protected:
    <DATA_TYPE_START>int?<DATA_TYPE_END> m_WordCount;
    bool m_WordCountIsSet;
    <DATA_TYPE_START>int?<DATA_TYPE_END> m_ParagraphCount;
    bool m_ParagraphCountIsSet;
    <DATA_TYPE_START>int?<DATA_TYPE_END> m_PageCount;
    bool m_PageCountIsSet;
    <DATA_TYPE_START>FootnotesStatData<DATA_TYPE_END> m_FootnotesStatData;
    bool m_FootnotesStatDataIsSet;
    <DATA_TYPE_START>List<PageStatData><DATA_TYPE_END> m_PageStatData;
    bool m_PageStatDataIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_DocumentStatData_H_ */
