/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="OfficeMathObject.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_OfficeMathObject_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_OfficeMathObject_H_


#include "OfficeMathLink.h"
#include "StoryChildNodes.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// OfficeMath object.
/// </summary>
class  OfficeMathObject
    : public OfficeMathLink
{
public:
    OfficeMathObject();
    virtual ~OfficeMathObject();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// OfficeMathObject members

    /// <summary>
    /// Gets or sets Content.
    /// </summary>
    <DATA_TYPE_START>StoryChildNodes<DATA_TYPE_END> getContent() const;
    bool contentIsSet() const;
    void unsetContent();
    void setContent(<DATA_TYPE_START>StoryChildNodes<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets /sets Office Math display format type which represents whether an equation is displayed inline with the text or displayed on its own line.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getDisplayType() const;
    bool displayTypeIsSet() const;
    void unsetDisplayType();
    void setDisplayType(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets /sets Office Math justification.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getJustification() const;
    bool justificationIsSet() const;
    void unsetJustification();
    void setJustification(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets type Aspose.Words.Math.OfficeMath.MathObjectType of this Office Math object.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getMathObjectType() const;
    bool mathObjectTypeIsSet() const;
    void unsetMathObjectType();
    void setMathObjectType(<DATA_TYPE_START>string<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>StoryChildNodes<DATA_TYPE_END> m_Content;
    bool m_ContentIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_DisplayType;
    bool m_DisplayTypeIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_Justification;
    bool m_JustificationIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_MathObjectType;
    bool m_MathObjectTypeIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_OfficeMathObject_H_ */
