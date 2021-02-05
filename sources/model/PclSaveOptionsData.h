/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PclSaveOptionsData.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_PclSaveOptionsData_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_PclSaveOptionsData_H_

#include "FixedPageSaveOptionsData.h"
#include "../ModelBase.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Container class for pcl save options.
/// </summary>
class PclSaveOptionsData
    : public FixedPageSaveOptionsData
{
public:
    PclSaveOptionsData();
    virtual ~PclSaveOptionsData();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// PclSaveOptionsData members

    /// <summary>
    /// Gets or sets the font name, that will be used if no expected font is found in printer and built-in fonts collections.
    /// </summary>
    utility::string_t getFalllbackFontName() const;
    bool falllbackFontNameIsSet() const;
    void unsetFalllbackFontName();
    void setFalllbackFontName(utility::string_t value);

    /// <summary>
    /// Gets or sets a value indicating whether complex transformed elements should be rasterized before saving to PCL document.. The default value is true.
    /// </summary>
    bool isRasterizeTransformedElements() const;
    bool rasterizeTransformedElementsIsSet() const;
    void unsetRasterizeTransformedElements();
    void setRasterizeTransformedElements(bool value);

protected:
    utility::string_t m_FalllbackFontName;
    bool m_FalllbackFontNameIsSet;

    bool m_RasterizeTransformedElements;
    bool m_RasterizeTransformedElementsIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_PclSaveOptionsData_H_ */
