/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="StyleUpdate.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_StyleUpdate_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_StyleUpdate_H_


#include "../ModelBase.h"

#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Represents a single document style properties to update.
/// </summary>
class  StyleUpdate
    : public ModelBase
{
public:
    StyleUpdate();
    virtual ~StyleUpdate();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// StyleUpdate members

    /// <summary>
    /// Gets or sets /sets the name of the style to be applied automatically to a new paragraph inserted after a paragraph formatted with the specified style.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getNextParagraphStyleName() const;
    bool nextParagraphStyleNameIsSet() const;
    void unsetNextParagraphStyleName();
    void setNextParagraphStyleName(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets /sets the name of the style this style is based on.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getBaseStyleName() const;
    bool baseStyleNameIsSet() const;
    void unsetBaseStyleName();
    void setBaseStyleName(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets a value indicating whether specifies whether this style is shown in the Quick Style gallery inside MS Word UI.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isIsQuickStyle() const;
    bool isQuickStyleIsSet() const;
    void unsetIsQuickStyle();
    void setIsQuickStyle(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the name of the style.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getName() const;
    bool nameIsSet() const;
    void unsetName();
    void setName(<DATA_TYPE_START>string<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>string<DATA_TYPE_END> m_NextParagraphStyleName;
    bool m_NextParagraphStyleNameIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_BaseStyleName;
    bool m_BaseStyleNameIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_IsQuickStyle;
    bool m_IsQuickStyleIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_Name;
    bool m_NameIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_StyleUpdate_H_ */
