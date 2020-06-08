/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="MetafileRenderingOptionsData.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_MetafileRenderingOptionsData_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_MetafileRenderingOptionsData_H_


#include "../ModelBase.h"

#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// container class for options of metafile rendering.
/// </summary>
class  MetafileRenderingOptionsData
    : public ModelBase
{
public:
    MetafileRenderingOptionsData();
    virtual ~MetafileRenderingOptionsData();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// MetafileRenderingOptionsData members

    /// <summary>
    /// Gets or sets determines how EMF+ Dual metafiles should be rendered.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getEmfPlusDualRenderingMode() const;
    bool emfPlusDualRenderingModeIsSet() const;
    void unsetEmfPlusDualRenderingMode();
    void setEmfPlusDualRenderingMode(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets a value determining whether or not the raster operations should be emulated.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isEmulateRasterOperations() const;
    bool emulateRasterOperationsIsSet() const;
    void unsetEmulateRasterOperations();
    void setEmulateRasterOperations(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets determines how metafile images should be rendered.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getRenderingMode() const;
    bool renderingModeIsSet() const;
    void unsetRenderingMode();
    void setRenderingMode(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets determines how WMF metafiles with embedded EMF metafiles should be rendered.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isUseEmfEmbeddedToWmf() const;
    bool useEmfEmbeddedToWmfIsSet() const;
    void unsetUseEmfEmbeddedToWmf();
    void setUseEmfEmbeddedToWmf(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets a value determining whether or not to scale fonts in WMF metafile according to metafile size on the page. The default value is true.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isScaleWmfFontsToMetafileSize() const;
    bool scaleWmfFontsToMetafileSizeIsSet() const;
    void unsetScaleWmfFontsToMetafileSize();
    void setScaleWmfFontsToMetafileSize(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>string<DATA_TYPE_END> m_EmfPlusDualRenderingMode;
    bool m_EmfPlusDualRenderingModeIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_EmulateRasterOperations;
    bool m_EmulateRasterOperationsIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_RenderingMode;
    bool m_RenderingModeIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_UseEmfEmbeddedToWmf;
    bool m_UseEmfEmbeddedToWmfIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_ScaleWmfFontsToMetafileSize;
    bool m_ScaleWmfFontsToMetafileSizeIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_MetafileRenderingOptionsData_H_ */
