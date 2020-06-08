/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FontInfo.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_FontInfo_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_FontInfo_H_


#include "../ModelBase.h"

#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Font info.
/// </summary>
class  FontInfo
    : public ModelBase
{
public:
    FontInfo();
    virtual ~FontInfo();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// FontInfo members

    /// <summary>
    /// Gets or sets family name of the font.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getFontFamilyName() const;
    bool fontFamilyNameIsSet() const;
    void unsetFontFamilyName();
    void setFontFamilyName(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets full name of the font.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getFullFontName() const;
    bool fullFontNameIsSet() const;
    void unsetFullFontName();
    void setFullFontName(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets version string of the font.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getVersion() const;
    bool versionIsSet() const;
    void unsetVersion();
    void setVersion(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets path to the font file if any.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getFilePath() const;
    bool filePathIsSet() const;
    void unsetFilePath();
    void setFilePath(<DATA_TYPE_START>string<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>string<DATA_TYPE_END> m_FontFamilyName;
    bool m_FontFamilyNameIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_FullFontName;
    bool m_FullFontNameIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_Version;
    bool m_VersionIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_FilePath;
    bool m_FilePathIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_FontInfo_H_ */
