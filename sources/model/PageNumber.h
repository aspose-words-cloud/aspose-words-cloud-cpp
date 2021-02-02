/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PageNumber.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_PageNumber_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_PageNumber_H_

#include "../ModelBase.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Class is used for insert page number request building.
/// </summary>
class PageNumber
    : public ModelBase
{
public:
    PageNumber();
    virtual ~PageNumber();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// PageNumber members

    /// <summary>
    /// Gets or sets text alignment, possible values are left, right, center or justify.
    /// </summary>
    utility::string_t getAlignment() const;
    bool alignmentIsSet() const;
    void unsetAlignment();
    void setAlignment(utility::string_t value);

    /// <summary>
    /// Gets or sets the page number format, e.g. "{PAGE} of {NUMPAGES}".
    /// </summary>
    utility::string_t getFormat() const;
    bool formatIsSet() const;
    void unsetFormat();
    void setFormat(utility::string_t value);

    /// <summary>
    /// Gets or sets a value indicating whether if true the page number is added at the top of the page, else at the bottom.
    /// </summary>
    bool isIsTop() const;
    bool isTopIsSet() const;
    void unsetIsTop();
    void setIsTop(bool value);

    /// <summary>
    /// Gets or sets a value indicating whether if true the page number is added on first page too.
    /// </summary>
    bool isSetPageNumberOnFirstPage() const;
    bool setPageNumberOnFirstPageIsSet() const;
    void unsetSetPageNumberOnFirstPage();
    void setSetPageNumberOnFirstPage(bool value);

protected:
    utility::string_t m_Alignment;
    bool m_AlignmentIsSet;

    utility::string_t m_Format;
    bool m_FormatIsSet;

    bool m_IsTop;
    bool m_IsTopIsSet;

    bool m_SetPageNumberOnFirstPage;
    bool m_SetPageNumberOnFirstPageIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_PageNumber_H_ */
