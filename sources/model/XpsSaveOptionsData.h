/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="XpsSaveOptionsData.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_XpsSaveOptionsData_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_XpsSaveOptionsData_H_


#include "FixedPageSaveOptionsData.h"
#include "MetafileRenderingOptionsData.h"
#include "OutlineOptionsData.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Container class for xps save options.
/// </summary>
class  XpsSaveOptionsData
    : public FixedPageSaveOptionsData
{
public:
    XpsSaveOptionsData();
    virtual ~XpsSaveOptionsData();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// XpsSaveOptionsData members

    /// <summary>
    /// Gets or sets specifies the level in the XPS document outline at which to display Word bookmarks.
    /// </summary>
    <DATA_TYPE_START>int?<DATA_TYPE_END> getBookmarksOutlineLevel() const;
    bool bookmarksOutlineLevelIsSet() const;
    void unsetBookmarksOutlineLevel();
    void setBookmarksOutlineLevel(<DATA_TYPE_START>int?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies how many levels of headings (paragraphs formatted with the Heading styles) to include in the XPS document outline.
    /// </summary>
    <DATA_TYPE_START>int?<DATA_TYPE_END> getHeadingsOutlineLevels() const;
    bool headingsOutlineLevelsIsSet() const;
    void unsetHeadingsOutlineLevels();
    void setHeadingsOutlineLevels(<DATA_TYPE_START>int?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets OutlineOptions.
    /// </summary>
    <DATA_TYPE_START>OutlineOptionsData<DATA_TYPE_END> getOutlineOptions() const;
    bool outlineOptionsIsSet() const;
    void unsetOutlineOptions();
    void setOutlineOptions(<DATA_TYPE_START>OutlineOptionsData<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets determines whether the document should be saved using a booklet printing layout.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isUseBookFoldPrintingSettings() const;
    bool useBookFoldPrintingSettingsIsSet() const;
    void unsetUseBookFoldPrintingSettings();
    void setUseBookFoldPrintingSettings(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>int?<DATA_TYPE_END> m_BookmarksOutlineLevel;
    bool m_BookmarksOutlineLevelIsSet;
    <DATA_TYPE_START>int?<DATA_TYPE_END> m_HeadingsOutlineLevels;
    bool m_HeadingsOutlineLevelsIsSet;
    <DATA_TYPE_START>OutlineOptionsData<DATA_TYPE_END> m_OutlineOptions;
    bool m_OutlineOptionsIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_UseBookFoldPrintingSettings;
    bool m_UseBookFoldPrintingSettingsIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_XpsSaveOptionsData_H_ */
