
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="MetafileRenderingOptionsData.h">
*   Copyright (c) 2018 Aspose.Words for Cloud
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

#ifndef IO_SWAGGER_CLIENT_MODEL_MetafileRenderingOptionsData_H_
#define IO_SWAGGER_CLIENT_MODEL_MetafileRenderingOptionsData_H_


#include "../ModelBase.h"

#include <cpprest/details/basic_types.h>

namespace io {
namespace swagger {
namespace client {
namespace model {

/// <summary>
/// container class for options of metafile rendering
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

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// MetafileRenderingOptionsData members

    /// <summary>
    /// Determines how EMF+ Dual metafiles should be rendered
    /// </summary>
    utility::string_t getEmfPlusDualRenderingMode() const;
    bool emfPlusDualRenderingModeIsSet() const;
    void unsetEmfPlusDualRenderingMode();
    void setEmfPlusDualRenderingMode(utility::string_t value);
    /// <summary>
    /// Gets or sets a value determining whether or not the raster operations should be emulated.             
    /// </summary>
    bool isEmulateRasterOperations() const;
    bool emulateRasterOperationsIsSet() const;
    void unsetEmulateRasterOperations();
    void setEmulateRasterOperations(bool value);
    /// <summary>
    /// Determines how metafile images should be rendered
    /// </summary>
    utility::string_t getRenderingMode() const;
    bool renderingModeIsSet() const;
    void unsetRenderingMode();
    void setRenderingMode(utility::string_t value);
    /// <summary>
    /// Determines how WMF metafiles with embedded EMF metafiles should be rendered
    /// </summary>
    bool isUseEmfEmbeddedToWmf() const;
    bool useEmfEmbeddedToWmfIsSet() const;
    void unsetUseEmfEmbeddedToWmf();
    void setUseEmfEmbeddedToWmf(bool value);

protected:
    utility::string_t m_EmfPlusDualRenderingMode;
    bool m_EmfPlusDualRenderingModeIsSet;
    bool m_EmulateRasterOperations;
    bool m_EmulateRasterOperationsIsSet;
    utility::string_t m_RenderingMode;
    bool m_RenderingModeIsSet;
    bool m_UseEmfEmbeddedToWmf;
    bool m_UseEmfEmbeddedToWmfIsSet;
};

}
}
}
}

#endif /* IO_SWAGGER_CLIENT_MODEL_MetafileRenderingOptionsData_H_ */
