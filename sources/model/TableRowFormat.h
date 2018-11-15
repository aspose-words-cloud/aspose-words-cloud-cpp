
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TableRowFormat.h">
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

#ifndef IO_SWAGGER_CLIENT_MODEL_TableRowFormat_H_
#define IO_SWAGGER_CLIENT_MODEL_TableRowFormat_H_


#include <cpprest/details/basic_types.h>
#include "LinkElement.h"
#include "WordsApiLink.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

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

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// TableRowFormat members

    /// <summary>
    /// True if the text in a table row is allowed to split across a page break.
    /// </summary>
    bool isAllowBreakAcrossPages() const;
    bool allowBreakAcrossPagesIsSet() const;
    void unsetAllowBreakAcrossPages();
    void setAllowBreakAcrossPages(bool value);
    /// <summary>
    /// True if the row is repeated as a table heading on every page when the table spans more than one page.
    /// </summary>
    bool isHeadingFormat() const;
    bool headingFormatIsSet() const;
    void unsetHeadingFormat();
    void setHeadingFormat(bool value);
    /// <summary>
    /// Gets or sets the height of the table row in points.
    /// </summary>
    double getHeight() const;
    bool heightIsSet() const;
    void unsetHeight();
    void setHeight(double value);
    /// <summary>
    /// Gets or sets the rule for determining the height of the table row.
    /// </summary>
    utility::string_t getHeightRule() const;
    bool heightRuleIsSet() const;
    void unsetHeightRule();
    void setHeightRule(utility::string_t value);

protected:
    bool m_AllowBreakAcrossPages;
    bool m_AllowBreakAcrossPagesIsSet;
    bool m_HeadingFormat;
    bool m_HeadingFormatIsSet;
    double m_Height;
    bool m_HeightIsSet;
    utility::string_t m_HeightRule;
    bool m_HeightRuleIsSet;
};

}
}
}
}

#endif /* IO_SWAGGER_CLIENT_MODEL_TableRowFormat_H_ */
