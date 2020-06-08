/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TableRowFormat.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_TableRowFormat_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_TableRowFormat_H_


#include "LinkElement.h"
#include "WordsApiLink.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Represents all formatting for a table row.
/// </summary>
class  TableRowFormat
    : public LinkElement
{
public:
    TableRowFormat();
    virtual ~TableRowFormat();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// TableRowFormat members

    /// <summary>
    /// Gets or sets true if the text in a table row is allowed to split across a page break.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isAllowBreakAcrossPages() const;
    bool allowBreakAcrossPagesIsSet() const;
    void unsetAllowBreakAcrossPages();
    void setAllowBreakAcrossPages(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets true if the row is repeated as a table heading on every page when the table spans more than one page.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isHeadingFormat() const;
    bool headingFormatIsSet() const;
    void unsetHeadingFormat();
    void setHeadingFormat(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the height of the table row in points.
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getHeight() const;
    bool heightIsSet() const;
    void unsetHeight();
    void setHeight(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the rule for determining the height of the table row.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getHeightRule() const;
    bool heightRuleIsSet() const;
    void unsetHeightRule();
    void setHeightRule(<DATA_TYPE_START>string<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_AllowBreakAcrossPages;
    bool m_AllowBreakAcrossPagesIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_HeadingFormat;
    bool m_HeadingFormatIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_Height;
    bool m_HeightIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_HeightRule;
    bool m_HeightRuleIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_TableRowFormat_H_ */
