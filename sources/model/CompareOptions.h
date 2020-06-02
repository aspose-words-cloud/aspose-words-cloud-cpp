/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="CompareOptions.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_CompareOptions_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_CompareOptions_H_

#include "../ModelBase.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Container class for compare documents options.
/// </summary>
class CompareOptions
    : public ModelBase
{
public:
    CompareOptions();
    virtual ~CompareOptions();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// CompareOptions members

    /// <summary>
    /// Gets or sets a value indicating whether true indicates that documents comparison is case insensitive. By default comparison is case sensitive.
    /// </summary>
    bool isIgnoreCaseChanges() const;
    bool ignoreCaseChangesIsSet() const;
    void unsetIgnoreCaseChanges();
    void setIgnoreCaseChanges(bool value);

    /// <summary>
    /// Gets or sets a value indicating whether specifies whether to compare differences in comments. By default comments are
    /// not ignored.
    /// </summary>
    bool isIgnoreComments() const;
    bool ignoreCommentsIsSet() const;
    void unsetIgnoreComments();
    void setIgnoreComments(bool value);

    /// <summary>
    /// Gets or sets a value indicating whether specifies whether to compare differences in fields. By default fields are not
    /// ignored.
    /// </summary>
    bool isIgnoreFields() const;
    bool ignoreFieldsIsSet() const;
    void unsetIgnoreFields();
    void setIgnoreFields(bool value);

    /// <summary>
    /// Gets or sets a value indicating whether specifies whether to compare differences in footnotes and endnotes. By default
    /// footnotes are not ignored.
    /// </summary>
    bool isIgnoreFootnotes() const;
    bool ignoreFootnotesIsSet() const;
    void unsetIgnoreFootnotes();
    void setIgnoreFootnotes(bool value);

    /// <summary>
    /// Gets or sets a value indicating whether true indicates that formatting is ignored. By default document formatting is
    /// not ignored.
    /// </summary>
    bool isIgnoreFormatting() const;
    bool ignoreFormattingIsSet() const;
    void unsetIgnoreFormatting();
    void setIgnoreFormatting(bool value);

    /// <summary>
    /// Gets or sets a value indicating whether true indicates that headers and footers content is ignored. By default headers
    /// and footers are not ignored.
    /// </summary>
    bool isIgnoreHeadersAndFooters() const;
    bool ignoreHeadersAndFootersIsSet() const;
    void unsetIgnoreHeadersAndFooters();
    void setIgnoreHeadersAndFooters(bool value);

    /// <summary>
    /// Gets or sets a value indicating whether specifies whether to compare the differences in data contained in tables. By
    /// default tables are not ignored.
    /// </summary>
    bool isIgnoreTables() const;
    bool ignoreTablesIsSet() const;
    void unsetIgnoreTables();
    void setIgnoreTables(bool value);

    /// <summary>
    /// Gets or sets a value indicating whether specifies whether to compare differences in the data contained within text boxes.
    /// By default textboxes are not ignored.
    /// </summary>
    bool isIgnoreTextboxes() const;
    bool ignoreTextboxesIsSet() const;
    void unsetIgnoreTextboxes();
    void setIgnoreTextboxes(bool value);

    /// <summary>
    /// Gets or sets specifies which document shall be used as a target during comparison.
    /// </summary>
    utility::string_t getTarget() const;
    bool targetIsSet() const;
    void unsetTarget();
    void setTarget(utility::string_t value);

protected:
    bool m_IgnoreCaseChanges;
    bool m_IgnoreCaseChangesIsSet;

    bool m_IgnoreComments;
    bool m_IgnoreCommentsIsSet;

    bool m_IgnoreFields;
    bool m_IgnoreFieldsIsSet;

    bool m_IgnoreFootnotes;
    bool m_IgnoreFootnotesIsSet;

    bool m_IgnoreFormatting;
    bool m_IgnoreFormattingIsSet;

    bool m_IgnoreHeadersAndFooters;
    bool m_IgnoreHeadersAndFootersIsSet;

    bool m_IgnoreTables;
    bool m_IgnoreTablesIsSet;

    bool m_IgnoreTextboxes;
    bool m_IgnoreTextboxesIsSet;

    utility::string_t m_Target;
    bool m_TargetIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_CompareOptions_H_ */
