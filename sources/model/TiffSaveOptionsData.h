/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TiffSaveOptionsData.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_TiffSaveOptionsData_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_TiffSaveOptionsData_H_

#include "ImageSaveOptionsData.h"
#include "../ModelBase.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Container class for tiff save options.
/// </summary>
class TiffSaveOptionsData
    : public ImageSaveOptionsData
{
public:
    TiffSaveOptionsData();
    virtual ~TiffSaveOptionsData();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// TiffSaveOptionsData members

    /// <summary>
    /// Gets or sets the threshold that determines the value of the binarization error in the Floyd-Steinberg method. when ImageBinarizationMethod is ImageBinarizationMethod.FloydSteinbergDithering.
    /// Default value is 128.
    /// </summary>
    int32_t getThresholdForFloydSteinbergDithering() const;
    bool thresholdForFloydSteinbergDitheringIsSet() const;
    void unsetThresholdForFloydSteinbergDithering();
    void setThresholdForFloydSteinbergDithering(int32_t value);

    /// <summary>
    /// Gets or sets specifies method used while converting images to 1 bpp format.
    /// </summary>
    utility::string_t getTiffBinarizationMethod() const;
    bool tiffBinarizationMethodIsSet() const;
    void unsetTiffBinarizationMethod();
    void setTiffBinarizationMethod(utility::string_t value);

    /// <summary>
    /// Gets or sets type of compression.
    /// </summary>
    utility::string_t getTiffCompression() const;
    bool tiffCompressionIsSet() const;
    void unsetTiffCompression();
    void setTiffCompression(utility::string_t value);

protected:
    int32_t m_ThresholdForFloydSteinbergDithering;
    bool m_ThresholdForFloydSteinbergDitheringIsSet;

    utility::string_t m_TiffBinarizationMethod;
    bool m_TiffBinarizationMethodIsSet;

    utility::string_t m_TiffCompression;
    bool m_TiffCompressionIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_TiffSaveOptionsData_H_ */
