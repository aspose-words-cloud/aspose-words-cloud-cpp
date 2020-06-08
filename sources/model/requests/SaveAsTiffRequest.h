/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SaveAsTiffRequest.h">
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
#pragma once
#ifndef saveAsTiff_H
#define saveAsTiff_H 

#include "cpprest/details/basic_types.h"
#include "TiffSaveOptionsData.h"
#include <boost/optional.hpp>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

class SaveAsTiffRequest{
    public: 
     SaveAsTiffRequest(
                utility::string_t name,
                std::shared_ptr<TiffSaveOptionsData> saveOptions,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<bool> useAntiAliasing,
                boost::optional<bool> useHighQualityRendering,
                boost::optional<double> imageBrightness,
                boost::optional<utility::string_t> imageColorMode,
                boost::optional<double> imageContrast,
                boost::optional<utility::string_t> numeralFormat,
                boost::optional<int32_t> pageCount,
                boost::optional<int32_t> pageIndex,
                boost::optional<utility::string_t> paperColor,
                boost::optional<utility::string_t> pixelFormat,
                boost::optional<double> resolution,
                boost::optional<double> scale,
                boost::optional<utility::string_t> tiffCompression,
                boost::optional<utility::string_t> dmlRenderingMode,
                boost::optional<utility::string_t> dmlEffectsRenderingMode,
                boost::optional<utility::string_t> tiffBinarizationMethod,
                boost::optional<bool> zipOutput,
                boost::optional<utility::string_t> fontsLocation
        );

        utility::string_t getName() const;
        void setName(utility::string_t name);

        std::shared_ptr<TiffSaveOptionsData> getSaveOptions() const;
        void setSaveOptions(std::shared_ptr<TiffSaveOptionsData> saveOptions);

        boost::optional<utility::string_t> getFolder() const;
        void setFolder(boost::optional<utility::string_t> folder);

        boost::optional<utility::string_t> getStorage() const;
        void setStorage(boost::optional<utility::string_t> storage);

        boost::optional<utility::string_t> getLoadEncoding() const;
        void setLoadEncoding(boost::optional<utility::string_t> loadEncoding);

        boost::optional<utility::string_t> getPassword() const;
        void setPassword(boost::optional<utility::string_t> password);

        boost::optional<bool> getUseAntiAliasing() const;
        void setUseAntiAliasing(boost::optional<bool> useAntiAliasing);

        boost::optional<bool> getUseHighQualityRendering() const;
        void setUseHighQualityRendering(boost::optional<bool> useHighQualityRendering);

        boost::optional<double> getImageBrightness() const;
        void setImageBrightness(boost::optional<double> imageBrightness);

        boost::optional<utility::string_t> getImageColorMode() const;
        void setImageColorMode(boost::optional<utility::string_t> imageColorMode);

        boost::optional<double> getImageContrast() const;
        void setImageContrast(boost::optional<double> imageContrast);

        boost::optional<utility::string_t> getNumeralFormat() const;
        void setNumeralFormat(boost::optional<utility::string_t> numeralFormat);

        boost::optional<int32_t> getPageCount() const;
        void setPageCount(boost::optional<int32_t> pageCount);

        boost::optional<int32_t> getPageIndex() const;
        void setPageIndex(boost::optional<int32_t> pageIndex);

        boost::optional<utility::string_t> getPaperColor() const;
        void setPaperColor(boost::optional<utility::string_t> paperColor);

        boost::optional<utility::string_t> getPixelFormat() const;
        void setPixelFormat(boost::optional<utility::string_t> pixelFormat);

        boost::optional<double> getResolution() const;
        void setResolution(boost::optional<double> resolution);

        boost::optional<double> getScale() const;
        void setScale(boost::optional<double> scale);

        boost::optional<utility::string_t> getTiffCompression() const;
        void setTiffCompression(boost::optional<utility::string_t> tiffCompression);

        boost::optional<utility::string_t> getDmlRenderingMode() const;
        void setDmlRenderingMode(boost::optional<utility::string_t> dmlRenderingMode);

        boost::optional<utility::string_t> getDmlEffectsRenderingMode() const;
        void setDmlEffectsRenderingMode(boost::optional<utility::string_t> dmlEffectsRenderingMode);

        boost::optional<utility::string_t> getTiffBinarizationMethod() const;
        void setTiffBinarizationMethod(boost::optional<utility::string_t> tiffBinarizationMethod);

        boost::optional<bool> getZipOutput() const;
        void setZipOutput(boost::optional<bool> zipOutput);

        boost::optional<utility::string_t> getFontsLocation() const;
        void setFontsLocation(boost::optional<utility::string_t> fontsLocation);
    private:
        utility::string_t m_name;
        std::shared_ptr<TiffSaveOptionsData> m_saveOptions;
        boost::optional<utility::string_t> m_folder;
        boost::optional<utility::string_t> m_storage;
        boost::optional<utility::string_t> m_loadEncoding;
        boost::optional<utility::string_t> m_password;
        boost::optional<bool> m_useAntiAliasing;
        boost::optional<bool> m_useHighQualityRendering;
        boost::optional<double> m_imageBrightness;
        boost::optional<utility::string_t> m_imageColorMode;
        boost::optional<double> m_imageContrast;
        boost::optional<utility::string_t> m_numeralFormat;
        boost::optional<int32_t> m_pageCount;
        boost::optional<int32_t> m_pageIndex;
        boost::optional<utility::string_t> m_paperColor;
        boost::optional<utility::string_t> m_pixelFormat;
        boost::optional<double> m_resolution;
        boost::optional<double> m_scale;
        boost::optional<utility::string_t> m_tiffCompression;
        boost::optional<utility::string_t> m_dmlRenderingMode;
        boost::optional<utility::string_t> m_dmlEffectsRenderingMode;
        boost::optional<utility::string_t> m_tiffBinarizationMethod;
        boost::optional<bool> m_zipOutput;
        boost::optional<utility::string_t> m_fontsLocation;
};

}
}
}
}
}

#endif
