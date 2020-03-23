/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="RtfSaveOptionsData.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_RtfSaveOptionsData_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_RtfSaveOptionsData_H_


#include "SaveOptionsData.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// container class for rtf save options.
/// </summary>
class  RtfSaveOptionsData
    : public SaveOptionsData
{
public:
    RtfSaveOptionsData();
    virtual ~RtfSaveOptionsData();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// RtfSaveOptionsData members

    /// <summary>
    /// Gets or sets allows to make output RTF documents smaller in size, but if they contain RTL (right-to-left) text, it will not be displayed correctly.
    /// </summary>
    bool isExportCompactSize() const;
    bool exportCompactSizeIsSet() const;
    void unsetExportCompactSize();
    void setExportCompactSize(bool value);
    /// <summary>
    /// Gets or sets specifies whether the keywords for \&quot;old readers\&quot; are written to RTF or not.
    /// </summary>
    bool isExportImagesForOldReaders() const;
    bool exportImagesForOldReadersIsSet() const;
    void unsetExportImagesForOldReaders();
    void setExportImagesForOldReaders(bool value);
    /// <summary>
    /// Gets or sets specifies whether or not use pretty formats output.
    /// </summary>
    bool isPrettyFormat() const;
    bool prettyFormatIsSet() const;
    void unsetPrettyFormat();
    void setPrettyFormat(bool value);
    /// <summary>
    /// Gets or sets a value indicating whether when true all images will be saved as WMF. This option might help to avoid WordPad warning messages.
    /// </summary>
    bool isSaveImagesAsWmf() const;
    bool saveImagesAsWmfIsSet() const;
    void unsetSaveImagesAsWmf();
    void setSaveImagesAsWmf(bool value);

protected:
    bool m_ExportCompactSize;
    bool m_ExportCompactSizeIsSet;
    bool m_ExportImagesForOldReaders;
    bool m_ExportImagesForOldReadersIsSet;
    bool m_PrettyFormat;
    bool m_PrettyFormatIsSet;
    bool m_SaveImagesAsWmf;
    bool m_SaveImagesAsWmfIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_RtfSaveOptionsData_H_ */
