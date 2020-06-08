/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ImageSaveOptionsData.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_ImageSaveOptionsData_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_ImageSaveOptionsData_H_


#include "FixedPageSaveOptionsData.h"
#include "GraphicsQualityOptionsData.h"
#include "MetafileRenderingOptionsData.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Container abstract class for image save options.
/// </summary>
class  ImageSaveOptionsData
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
    /// Gets or sets GraphicsQualityOptions.
    /// </summary>
    <DATA_TYPE_START>GraphicsQualityOptionsData<DATA_TYPE_END> getGraphicsQualityOptions() const;
    bool graphicsQualityOptionsIsSet() const;
    void unsetGraphicsQualityOptions();
    void setGraphicsQualityOptions(<DATA_TYPE_START>GraphicsQualityOptionsData<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the horizontal resolution for the generated images, in dots per inch.  This property has effect only when saving to raster image formats. The default value is 96.
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getHorizontalResolution() const;
    bool horizontalResolutionIsSet() const;
    void unsetHorizontalResolution();
    void setHorizontalResolution(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets brightness of image.
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getImageBrightness() const;
    bool imageBrightnessIsSet() const;
    void unsetImageBrightness();
    void setImageBrightness(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets color mode of image.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getImageColorMode() const;
    bool imageColorModeIsSet() const;
    void unsetImageColorMode();
    void setImageColorMode(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets contrast of image.
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getImageContrast() const;
    bool imageContrastIsSet() const;
    void unsetImageContrast();
    void setImageContrast(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets background (paper) color of image.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getPaperColor() const;
    bool paperColorIsSet() const;
    void unsetPaperColor();
    void setPaperColor(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets pixel format of image.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getPixelFormat() const;
    bool pixelFormatIsSet() const;
    void unsetPixelFormat();
    void setPixelFormat(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets both horizontal and vertical resolution for the generated images, in dots per inch.  This property has effect only when saving to raster image formats. The default value is 96.
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getResolution() const;
    bool resolutionIsSet() const;
    void unsetResolution();
    void setResolution(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets zoom factor of image.
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getScale() const;
    bool scaleIsSet() const;
    void unsetScale();
    void setScale(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets determine whether or not to use anti-aliasing for rendering.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isUseAntiAliasing() const;
    bool useAntiAliasingIsSet() const;
    void unsetUseAntiAliasing();
    void setUseAntiAliasing(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets a value determining whether to use GDI+ or Aspose.Words metafile renderer when saving to EMF.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isUseGdiEmfRenderer() const;
    bool useGdiEmfRendererIsSet() const;
    void unsetUseGdiEmfRenderer();
    void setUseGdiEmfRenderer(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets determine whether or not to use high quality (i.e. slow) rendering algorithms.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isUseHighQualityRendering() const;
    bool useHighQualityRenderingIsSet() const;
    void unsetUseHighQualityRendering();
    void setUseHighQualityRendering(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the vertical resolution for the generated images, in dots per inch.  This property has effect only when saving to raster image formats. The default value is 96.
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getVerticalResolution() const;
    bool verticalResolutionIsSet() const;
    void unsetVerticalResolution();
    void setVerticalResolution(<DATA_TYPE_START>double?<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>GraphicsQualityOptionsData<DATA_TYPE_END> m_GraphicsQualityOptions;
    bool m_GraphicsQualityOptionsIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_HorizontalResolution;
    bool m_HorizontalResolutionIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_ImageBrightness;
    bool m_ImageBrightnessIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_ImageColorMode;
    bool m_ImageColorModeIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_ImageContrast;
    bool m_ImageContrastIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_PaperColor;
    bool m_PaperColorIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_PixelFormat;
    bool m_PixelFormatIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_Resolution;
    bool m_ResolutionIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_Scale;
    bool m_ScaleIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_UseAntiAliasing;
    bool m_UseAntiAliasingIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_UseGdiEmfRenderer;
    bool m_UseGdiEmfRendererIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_UseHighQualityRendering;
    bool m_UseHighQualityRenderingIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_VerticalResolution;
    bool m_VerticalResolutionIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_ImageSaveOptionsData_H_ */
