/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FontInfo.h">
*   Copyright (c) 2021 Aspose.Words for Cloud
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
/// DTO container with font info.
/// </summary>
class FontInfo
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
    /// Gets or sets the path to the font file if any.
    /// </summary>
    utility::string_t getFilePath() const;
    bool filePathIsSet() const;
    void unsetFilePath();
    void setFilePath(utility::string_t value);

    /// <summary>
    /// Gets or sets the family name of the font.
    /// </summary>
    utility::string_t getFontFamilyName() const;
    bool fontFamilyNameIsSet() const;
    void unsetFontFamilyName();
    void setFontFamilyName(utility::string_t value);

    /// <summary>
    /// Gets or sets the full name of the font.
    /// </summary>
    utility::string_t getFullFontName() const;
    bool fullFontNameIsSet() const;
    void unsetFullFontName();
    void setFullFontName(utility::string_t value);

    /// <summary>
    /// Gets or sets the version string of the font.
    /// </summary>
    utility::string_t getVersion() const;
    bool versionIsSet() const;
    void unsetVersion();
    void setVersion(utility::string_t value);

protected:
    utility::string_t m_FilePath;
    bool m_FilePathIsSet;

    utility::string_t m_FontFamilyName;
    bool m_FontFamilyNameIsSet;

    utility::string_t m_FullFontName;
    bool m_FullFontNameIsSet;

    utility::string_t m_Version;
    bool m_VersionIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_FontInfo_H_ */
