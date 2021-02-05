/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="CsvDataLoadOptions.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_CsvDataLoadOptions_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_CsvDataLoadOptions_H_

#include "../ModelBase.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Represents options for parsing CSV data.
/// </summary>
class CsvDataLoadOptions
    : public ModelBase
{
public:
    CsvDataLoadOptions();
    virtual ~CsvDataLoadOptions();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// CsvDataLoadOptions members

    /// <summary>
    /// Gets or sets the character that is used to comment lines of CSV data.
    /// </summary>
    utility::string_t getCommentChar() const;
    bool commentCharIsSet() const;
    void unsetCommentChar();
    void setCommentChar(utility::string_t value);

    /// <summary>
    /// Gets or sets the character to be used as a column delimiter.
    /// </summary>
    utility::string_t getDelimiter() const;
    bool delimiterIsSet() const;
    void unsetDelimiter();
    void setDelimiter(utility::string_t value);

    /// <summary>
    /// Gets or sets a value indicating whether the first record of CSV data contains column names.
    /// </summary>
    bool isHasHeaders() const;
    bool hasHeadersIsSet() const;
    void unsetHasHeaders();
    void setHasHeaders(bool value);

    /// <summary>
    /// Gets or sets the character that is used to quote field values.
    /// </summary>
    utility::string_t getQuoteChar() const;
    bool quoteCharIsSet() const;
    void unsetQuoteChar();
    void setQuoteChar(utility::string_t value);

protected:
    utility::string_t m_CommentChar;
    bool m_CommentCharIsSet;

    utility::string_t m_Delimiter;
    bool m_DelimiterIsSet;

    bool m_HasHeaders;
    bool m_HasHeadersIsSet;

    utility::string_t m_QuoteChar;
    bool m_QuoteCharIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_CsvDataLoadOptions_H_ */
