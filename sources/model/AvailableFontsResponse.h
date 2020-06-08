/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="AvailableFontsResponse.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_AvailableFontsResponse_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_AvailableFontsResponse_H_


#include "FontInfo.h"
#include "WordsResponse.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// The list of fonts, available for document processing.
/// </summary>
class  AvailableFontsResponse
    : public WordsResponse
{
public:
    AvailableFontsResponse();
    virtual ~AvailableFontsResponse();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// AvailableFontsResponse members

    /// <summary>
    /// Gets or sets the list of addititional fonts, provided by aspose team.
    /// </summary>
    <DATA_TYPE_START>List<FontInfo><DATA_TYPE_END>& getAdditionalFonts();
    bool additionalFontsIsSet() const;
    void unsetAdditionalFonts();
    void setAdditionalFonts(<DATA_TYPE_START>List<FontInfo><DATA_TYPE_END> const& value);
    /// <summary>
    /// Gets or sets custom user fonts (from user file storage). To use them, you should specify \&quot;fontsLocation\&quot; parameter in any request.
    /// </summary>
    <DATA_TYPE_START>List<FontInfo><DATA_TYPE_END>& getCustomFonts();
    bool customFontsIsSet() const;
    void unsetCustomFonts();
    void setCustomFonts(<DATA_TYPE_START>List<FontInfo><DATA_TYPE_END> const& value);
    /// <summary>
    /// Gets or sets the list of system fonts, availiable on the server.
    /// </summary>
    <DATA_TYPE_START>List<FontInfo><DATA_TYPE_END>& getSystemFonts();
    bool systemFontsIsSet() const;
    void unsetSystemFonts();
    void setSystemFonts(<DATA_TYPE_START>List<FontInfo><DATA_TYPE_END> const& value);

protected:
    <DATA_TYPE_START>List<FontInfo><DATA_TYPE_END> m_AdditionalFonts;
    bool m_AdditionalFontsIsSet;
    <DATA_TYPE_START>List<FontInfo><DATA_TYPE_END> m_CustomFonts;
    bool m_CustomFontsIsSet;
    <DATA_TYPE_START>List<FontInfo><DATA_TYPE_END> m_SystemFonts;
    bool m_SystemFontsIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_AvailableFontsResponse_H_ */
