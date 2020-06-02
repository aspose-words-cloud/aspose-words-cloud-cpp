/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SvgSaveOptionsData.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_SvgSaveOptionsData_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_SvgSaveOptionsData_H_

#include "FixedPageSaveOptionsData.h"
#include "../ModelBase.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// container class for svg save options.
/// </summary>
class SvgSaveOptionsData
    : public FixedPageSaveOptionsData
{
public:
    SvgSaveOptionsData();
    virtual ~SvgSaveOptionsData();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// SvgSaveOptionsData members

    /// <summary>
    /// Gets or sets specified whether images should be embedded into SVG document as base64.
    /// </summary>
    bool isExportEmbeddedImages() const;
    bool exportEmbeddedImagesIsSet() const;
    void unsetExportEmbeddedImages();
    void setExportEmbeddedImages(bool value);

    /// <summary>
    /// Gets or sets specifies if the output SVG should fill the available viewport area (browser window or container). When set to true width and height of output SVG are set to 100%.
    /// </summary>
    bool isFitToViewPort() const;
    bool fitToViewPortIsSet() const;
    void unsetFitToViewPort();
    void setFitToViewPort(bool value);

    /// <summary>
    /// Gets or sets specifies the physical folder where resources (images) are saved when exporting.
    /// </summary>
    utility::string_t getResourcesFolder() const;
    bool resourcesFolderIsSet() const;
    void unsetResourcesFolder();
    void setResourcesFolder(utility::string_t value);

    /// <summary>
    /// Gets or sets specifies the name of the folder used to construct image URIs.
    /// </summary>
    utility::string_t getResourcesFolderAlias() const;
    bool resourcesFolderAliasIsSet() const;
    void unsetResourcesFolderAlias();
    void setResourcesFolderAlias(utility::string_t value);

    /// <summary>
    /// Gets or sets show/hide page stepper.
    /// </summary>
    bool isShowPageBorder() const;
    bool showPageBorderIsSet() const;
    void unsetShowPageBorder();
    void setShowPageBorder(bool value);

    /// <summary>
    /// Gets or sets determines how text should be rendered.
    /// </summary>
    utility::string_t getTextOutputMode() const;
    bool textOutputModeIsSet() const;
    void unsetTextOutputMode();
    void setTextOutputMode(utility::string_t value);

protected:
    bool m_ExportEmbeddedImages;
    bool m_ExportEmbeddedImagesIsSet;

    bool m_FitToViewPort;
    bool m_FitToViewPortIsSet;

    utility::string_t m_ResourcesFolder;
    bool m_ResourcesFolderIsSet;

    utility::string_t m_ResourcesFolderAlias;
    bool m_ResourcesFolderAliasIsSet;

    bool m_ShowPageBorder;
    bool m_ShowPageBorderIsSet;

    utility::string_t m_TextOutputMode;
    bool m_TextOutputModeIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_SvgSaveOptionsData_H_ */
