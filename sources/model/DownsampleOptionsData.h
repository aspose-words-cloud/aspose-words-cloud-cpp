/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DownsampleOptionsData.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_DownsampleOptionsData_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_DownsampleOptionsData_H_


#include "../ModelBase.h"

#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Container class for Downsample options.
/// </summary>
class  DownsampleOptionsData
    : public ModelBase
{
public:
    DownsampleOptionsData();
    virtual ~DownsampleOptionsData();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// DownsampleOptionsData members

    /// <summary>
    /// Gets or sets specifies whether images should be downsampled.
    /// </summary>
    bool isDownsampleImages() const;
    bool downsampleImagesIsSet() const;
    void unsetDownsampleImages();
    void setDownsampleImages(bool value);
    /// <summary>
    /// Gets or sets specifies the resolution in pixels per inch which the images should be downsampled to.
    /// </summary>
    int32_t getResolution() const;
    bool resolutionIsSet() const;
    void unsetResolution();
    void setResolution(int32_t value);
    /// <summary>
    /// Gets or sets specifies the threshold resolution in pixels per inch. If resolution of an image in the document is less than threshold value, the downsampling algorithm will not be applied. A value of 0 means the threshold check is not used and all images that can be reduced in size are downsampled.
    /// </summary>
    int32_t getResolutionThreshold() const;
    bool resolutionThresholdIsSet() const;
    void unsetResolutionThreshold();
    void setResolutionThreshold(int32_t value);

protected:
    bool m_DownsampleImages;
    bool m_DownsampleImagesIsSet;
    int32_t m_Resolution;
    bool m_ResolutionIsSet;
    int32_t m_ResolutionThreshold;
    bool m_ResolutionThresholdIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_DownsampleOptionsData_H_ */
