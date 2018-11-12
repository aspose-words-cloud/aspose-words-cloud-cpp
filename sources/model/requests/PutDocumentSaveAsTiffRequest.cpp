/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PutDocumentSaveAsTiffRequest.cpp">
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
#include "PutDocumentSaveAsTiffRequest.h"
namespace io{
namespace swagger{
namespace client{
namespace model{
PutDocumentSaveAsTiffRequest::PutDocumentSaveAsTiffRequest(
        utility::string_t name,
                std::shared_ptr<TiffSaveOptionsData> saveOptions,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> resultFile,
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
        )
        {
            this->name = name;
            this->saveOptions = saveOptions;
            this->folder = folder;
            this->storage = storage;
            this->loadEncoding = loadEncoding;
            this->password = password;
            this->destFileName = destFileName;
            this->resultFile = resultFile;
            this->useAntiAliasing = useAntiAliasing;
            this->useHighQualityRendering = useHighQualityRendering;
            this->imageBrightness = imageBrightness;
            this->imageColorMode = imageColorMode;
            this->imageContrast = imageContrast;
            this->numeralFormat = numeralFormat;
            this->pageCount = pageCount;
            this->pageIndex = pageIndex;
            this->paperColor = paperColor;
            this->pixelFormat = pixelFormat;
            this->resolution = resolution;
            this->scale = scale;
            this->tiffCompression = tiffCompression;
            this->dmlRenderingMode = dmlRenderingMode;
            this->dmlEffectsRenderingMode = dmlEffectsRenderingMode;
            this->tiffBinarizationMethod = tiffBinarizationMethod;
            this->zipOutput = zipOutput;
            this->fontsLocation = fontsLocation;
        }

}
}
}
}

