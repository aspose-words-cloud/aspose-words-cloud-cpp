/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ImageSaveOptionsData.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_ImageSaveOptionsData_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_ImageSaveOptionsData_H_

#include "FixedPageSaveOptionsData.h"
#include "GraphicsQualityOptionsData.h"
#include "../ModelBase.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Container abstract class for image save options.
/// </summary>
class ImageSaveOptionsData
    : public FixedPageSaveOptionsData
{
public:
    ImageSaveOptionsData();
    virtual ~ImageSaveOptionsData();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// ImageSaveOptionsData members

    /// <summary>
    /// Gets or sets the additional System.Drawing.Graphics quality options.
    /// </summary>
    std::shared_ptr<GraphicsQualityOptionsData> getGraphicsQualityOptions() const;
    bool graphicsQualityOptionsIsSet() const;
    void unsetGraphicsQualityOptions();
    void setGraphicsQualityOptions(std::shared_ptr<GraphicsQualityOptionsData> value);

    /// <summary>
    /// Gets or sets the horizontal resolution in dots per inch for the generated images.
    /// This property has effect only when saving to raster image formats.
    /// The default value is 96.
    /// </summary>
    double getHorizontalResolution() const;
    bool horizontalResolutionIsSet() const;
    void unsetHorizontalResolution();
    void setHorizontalResolution(double value);

    /// <summary>
    /// Gets or sets the brightness level of the image.
    /// </summary>
    double getImageBrightness() const;
    bool imageBrightnessIsSet() const;
    void unsetImageBrightness();
    void setImageBrightness(double value);

    /// <summary>
    /// Gets or sets the color mode of the image.
    /// </summary>
    utility::string_t getImageColorMode() const;
    bool imageColorModeIsSet() const;
    void unsetImageColorMode();
    void setImageColorMode(utility::string_t value);

    /// <summary>
    /// Gets or sets the contrast level of the image.
    /// </summary>
    double getImageContrast() const;
    bool imageContrastIsSet() const;
    void unsetImageContrast();
    void setImageContrast(double value);

    /// <summary>
    /// Gets or sets the background (paper) color of the image.
    /// </summary>
    utility::string_t getPaperColor() const;
    bool paperColorIsSet() const;
    void unsetPaperColor();
    void setPaperColor(utility::string_t value);

    /// <summary>
    /// Gets or sets the pixel format of the image.
    /// </summary>
    utility::string_t getPixelFormat() const;
    bool pixelFormatIsSet() const;
    void unsetPixelFormat();
    void setPixelFormat(utility::string_t value);

    /// <summary>
    /// Gets or sets both horizontal and vertical resolution in dots per inch for the generated images.
    /// This property has effect only when saving to raster image formats.
    /// The default value is 96.
    /// </summary>
    double getResolution() const;
    bool resolutionIsSet() const;
    void unsetResolution();
    void setResolution(double value);

    /// <summary>
    /// Gets or sets the zoom factor of the image.
    /// </summary>
    double getScale() const;
    bool scaleIsSet() const;
    void unsetScale();
    void setScale(double value);

    /// <summary>
    /// Gets or sets a value indicating whether to use anti-aliasing for rendering.
    /// </summary>
    bool isUseAntiAliasing() const;
    bool useAntiAliasingIsSet() const;
    void unsetUseAntiAliasing();
    void setUseAntiAliasing(bool value);

    /// <summary>
    /// Gets or sets a value indicating whether to use GDI+ or Aspose.Words metafile renderer when saving to EMF.
    /// </summary>
    bool isUseGdiEmfRenderer() const;
    bool useGdiEmfRendererIsSet() const;
    void unsetUseGdiEmfRenderer();
    void setUseGdiEmfRenderer(bool value);

    /// <summary>
    /// Gets or sets a value indicating whether to use high quality (i.e. slow) rendering algorithms.
    /// </summary>
    bool isUseHighQualityRendering() const;
    bool useHighQualityRenderingIsSet() const;
    void unsetUseHighQualityRendering();
    void setUseHighQualityRendering(bool value);

    /// <summary>
    /// Gets or sets the vertical resolution in dots per inch for the generated images.
    /// This property has effect only when saving to raster image formats.
    /// The default value is 96.
    /// </summary>
    double getVerticalResolution() const;
    bool verticalResolutionIsSet() const;
    void unsetVerticalResolution();
    void setVerticalResolution(double value);

protected:
    std::shared_ptr<GraphicsQualityOptionsData> m_GraphicsQualityOptions;
    bool m_GraphicsQualityOptionsIsSet;

    double m_HorizontalResolution;
    bool m_HorizontalResolutionIsSet;

    double m_ImageBrightness;
    bool m_ImageBrightnessIsSet;

    utility::string_t m_ImageColorMode;
    bool m_ImageColorModeIsSet;

    double m_ImageContrast;
    bool m_ImageContrastIsSet;

    utility::string_t m_PaperColor;
    bool m_PaperColorIsSet;

    utility::string_t m_PixelFormat;
    bool m_PixelFormatIsSet;

    double m_Resolution;
    bool m_ResolutionIsSet;

    double m_Scale;
    bool m_ScaleIsSet;

    bool m_UseAntiAliasing;
    bool m_UseAntiAliasingIsSet;

    bool m_UseGdiEmfRenderer;
    bool m_UseGdiEmfRendererIsSet;

    bool m_UseHighQualityRendering;
    bool m_UseHighQualityRenderingIsSet;

    double m_VerticalResolution;
    bool m_VerticalResolutionIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_ImageSaveOptionsData_H_ */
