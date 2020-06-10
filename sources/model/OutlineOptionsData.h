/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="OutlineOptionsData.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_OutlineOptionsData_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_OutlineOptionsData_H_

#include "BookmarksOutlineLevelData.h"
#include "../ModelBase.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// container class for outline options.
/// </summary>
class OutlineOptionsData
    : public ModelBase
{
public:
    OutlineOptionsData();
    virtual ~OutlineOptionsData();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// OutlineOptionsData members

    /// <summary>
    /// Gets or sets allows to specify individual bookmarks outline level.
    /// </summary>
    std::vector<std::shared_ptr<BookmarksOutlineLevelData>>& getBookmarksOutlineLevels();
    bool bookmarksOutlineLevelsIsSet() const;
    void unsetBookmarksOutlineLevels();
    void setBookmarksOutlineLevels(std::vector<std::shared_ptr<BookmarksOutlineLevelData>> const& value);

    /// <summary>
    /// Gets or sets a value determining whether or not to create missing outline levels
    /// when the document is exported.
    /// Default value for this property is false.
    /// </summary>
    bool isCreateMissingOutlineLevels() const;
    bool createMissingOutlineLevelsIsSet() const;
    void unsetCreateMissingOutlineLevels();
    void setCreateMissingOutlineLevels(bool value);

    /// <summary>
    /// Gets or sets specifies whether or not to create outlines for headings (paragraphs formatted
    /// with the Heading styles) inside tables.
    /// </summary>
    bool isCreateOutlinesForHeadingsInTables() const;
    bool createOutlinesForHeadingsInTablesIsSet() const;
    void unsetCreateOutlinesForHeadingsInTables();
    void setCreateOutlinesForHeadingsInTables(bool value);

    /// <summary>
    /// Gets or sets specifies the default level in the document outline at which to display Word bookmarks.
    /// </summary>
    int32_t getDefaultBookmarksOutlineLevel() const;
    bool defaultBookmarksOutlineLevelIsSet() const;
    void unsetDefaultBookmarksOutlineLevel();
    void setDefaultBookmarksOutlineLevel(int32_t value);

    /// <summary>
    /// Gets or sets specifies how many levels in the document outline to show expanded when the file is viewed.
    /// </summary>
    int32_t getExpandedOutlineLevels() const;
    bool expandedOutlineLevelsIsSet() const;
    void unsetExpandedOutlineLevels();
    void setExpandedOutlineLevels(int32_t value);

    /// <summary>
    /// Gets or sets specifies how many levels of headings (paragraphs formatted with the Heading styles) to include in the document outline.
    /// </summary>
    int32_t getHeadingsOutlineLevels() const;
    bool headingsOutlineLevelsIsSet() const;
    void unsetHeadingsOutlineLevels();
    void setHeadingsOutlineLevels(int32_t value);

protected:
    std::vector<std::shared_ptr<BookmarksOutlineLevelData>> m_BookmarksOutlineLevels;
    bool m_BookmarksOutlineLevelsIsSet;

    bool m_CreateMissingOutlineLevels;
    bool m_CreateMissingOutlineLevelsIsSet;

    bool m_CreateOutlinesForHeadingsInTables;
    bool m_CreateOutlinesForHeadingsInTablesIsSet;

    int32_t m_DefaultBookmarksOutlineLevel;
    bool m_DefaultBookmarksOutlineLevelIsSet;

    int32_t m_ExpandedOutlineLevels;
    bool m_ExpandedOutlineLevelsIsSet;

    int32_t m_HeadingsOutlineLevels;
    bool m_HeadingsOutlineLevelsIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_OutlineOptionsData_H_ */
