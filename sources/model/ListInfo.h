/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ListInfo.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_ListInfo_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_ListInfo_H_


#include "LinkElement.h"
#include "ListLevels.h"
#include "Style.h"
#include "WordsApiLink.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Represents a single document list.
/// </summary>
class  ListInfo
    : public LinkElement
{
public:
    ListInfo();
    virtual ~ListInfo();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// ListInfo members

    /// <summary>
    /// Gets or sets a value indicating whether returns true if this list is a definition of a list style.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isIsListStyleDefinition() const;
    bool isListStyleDefinitionIsSet() const;
    void unsetIsListStyleDefinition();
    void setIsListStyleDefinition(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets a value indicating whether returns true if this list is a reference to a list style.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isIsListStyleReference() const;
    bool isListStyleReferenceIsSet() const;
    void unsetIsListStyleReference();
    void setIsListStyleReference(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets a value indicating whether returns true when the list contains 9 levels; false when 1 level.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isIsMultiLevel() const;
    bool isMultiLevelIsSet() const;
    void unsetIsMultiLevel();
    void setIsMultiLevel(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets a value indicating whether specifies whether list should be restarted at each section. Default value is false.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isIsRestartAtEachSection() const;
    bool isRestartAtEachSectionIsSet() const;
    void unsetIsRestartAtEachSection();
    void setIsRestartAtEachSection(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the unique identifier of the list.
    /// </summary>
    <DATA_TYPE_START>int?<DATA_TYPE_END> getListId() const;
    bool listIdIsSet() const;
    void unsetListId();
    void setListId(<DATA_TYPE_START>int?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets ListLevels.
    /// </summary>
    <DATA_TYPE_START>ListLevels<DATA_TYPE_END> getListLevels() const;
    bool listLevelsIsSet() const;
    void unsetListLevels();
    void setListLevels(<DATA_TYPE_START>ListLevels<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets Style.
    /// </summary>
    <DATA_TYPE_START>Style<DATA_TYPE_END> getStyle() const;
    bool styleIsSet() const;
    void unsetStyle();
    void setStyle(<DATA_TYPE_START>Style<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_IsListStyleDefinition;
    bool m_IsListStyleDefinitionIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_IsListStyleReference;
    bool m_IsListStyleReferenceIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_IsMultiLevel;
    bool m_IsMultiLevelIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_IsRestartAtEachSection;
    bool m_IsRestartAtEachSectionIsSet;
    <DATA_TYPE_START>int?<DATA_TYPE_END> m_ListId;
    bool m_ListIdIsSet;
    <DATA_TYPE_START>ListLevels<DATA_TYPE_END> m_ListLevels;
    bool m_ListLevelsIsSet;
    <DATA_TYPE_START>Style<DATA_TYPE_END> m_Style;
    bool m_StyleIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_ListInfo_H_ */
