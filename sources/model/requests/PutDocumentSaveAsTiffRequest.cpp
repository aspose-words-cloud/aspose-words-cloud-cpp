/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PutDocumentSaveAsTiffRequest.cpp">
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
#include "PutDocumentSaveAsTiffRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
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
        ) : 
            m_name(std::move(name)),
            m_saveOptions(std::move(saveOptions)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_resultFile(std::move(resultFile)),
            m_useAntiAliasing(std::move(useAntiAliasing)),
            m_useHighQualityRendering(std::move(useHighQualityRendering)),
            m_imageBrightness(std::move(imageBrightness)),
            m_imageColorMode(std::move(imageColorMode)),
            m_imageContrast(std::move(imageContrast)),
            m_numeralFormat(std::move(numeralFormat)),
            m_pageCount(std::move(pageCount)),
            m_pageIndex(std::move(pageIndex)),
            m_paperColor(std::move(paperColor)),
            m_pixelFormat(std::move(pixelFormat)),
            m_resolution(std::move(resolution)),
            m_scale(std::move(scale)),
            m_tiffCompression(std::move(tiffCompression)),
            m_dmlRenderingMode(std::move(dmlRenderingMode)),
            m_dmlEffectsRenderingMode(std::move(dmlEffectsRenderingMode)),
            m_tiffBinarizationMethod(std::move(tiffBinarizationMethod)),
            m_zipOutput(std::move(zipOutput)),
            m_fontsLocation(std::move(fontsLocation))
        {
            
        }

        utility::string_t PutDocumentSaveAsTiffRequest::getName() const
        {
            return m_name;
        }
        void PutDocumentSaveAsTiffRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<TiffSaveOptionsData> PutDocumentSaveAsTiffRequest::getSaveOptions() const
        {
            return m_saveOptions;
        }
        void PutDocumentSaveAsTiffRequest::setSaveOptions(std::shared_ptr<TiffSaveOptionsData> saveOptions){
            m_saveOptions = std::move(saveOptions);
        }
        boost::optional<utility::string_t> PutDocumentSaveAsTiffRequest::getFolder() const
        {
            return m_folder;
        }
        void PutDocumentSaveAsTiffRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> PutDocumentSaveAsTiffRequest::getStorage() const
        {
            return m_storage;
        }
        void PutDocumentSaveAsTiffRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> PutDocumentSaveAsTiffRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void PutDocumentSaveAsTiffRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> PutDocumentSaveAsTiffRequest::getPassword() const
        {
            return m_password;
        }
        void PutDocumentSaveAsTiffRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> PutDocumentSaveAsTiffRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void PutDocumentSaveAsTiffRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> PutDocumentSaveAsTiffRequest::getResultFile() const
        {
            return m_resultFile;
        }
        void PutDocumentSaveAsTiffRequest::setResultFile(boost::optional<utility::string_t> resultFile){
            m_resultFile = std::move(resultFile);
        }
        boost::optional<bool> PutDocumentSaveAsTiffRequest::getUseAntiAliasing() const
        {
            return m_useAntiAliasing;
        }
        void PutDocumentSaveAsTiffRequest::setUseAntiAliasing(boost::optional<bool> useAntiAliasing){
            m_useAntiAliasing = std::move(useAntiAliasing);
        }
        boost::optional<bool> PutDocumentSaveAsTiffRequest::getUseHighQualityRendering() const
        {
            return m_useHighQualityRendering;
        }
        void PutDocumentSaveAsTiffRequest::setUseHighQualityRendering(boost::optional<bool> useHighQualityRendering){
            m_useHighQualityRendering = std::move(useHighQualityRendering);
        }
        boost::optional<double> PutDocumentSaveAsTiffRequest::getImageBrightness() const
        {
            return m_imageBrightness;
        }
        void PutDocumentSaveAsTiffRequest::setImageBrightness(boost::optional<double> imageBrightness){
            m_imageBrightness = std::move(imageBrightness);
        }
        boost::optional<utility::string_t> PutDocumentSaveAsTiffRequest::getImageColorMode() const
        {
            return m_imageColorMode;
        }
        void PutDocumentSaveAsTiffRequest::setImageColorMode(boost::optional<utility::string_t> imageColorMode){
            m_imageColorMode = std::move(imageColorMode);
        }
        boost::optional<double> PutDocumentSaveAsTiffRequest::getImageContrast() const
        {
            return m_imageContrast;
        }
        void PutDocumentSaveAsTiffRequest::setImageContrast(boost::optional<double> imageContrast){
            m_imageContrast = std::move(imageContrast);
        }
        boost::optional<utility::string_t> PutDocumentSaveAsTiffRequest::getNumeralFormat() const
        {
            return m_numeralFormat;
        }
        void PutDocumentSaveAsTiffRequest::setNumeralFormat(boost::optional<utility::string_t> numeralFormat){
            m_numeralFormat = std::move(numeralFormat);
        }
        boost::optional<int32_t> PutDocumentSaveAsTiffRequest::getPageCount() const
        {
            return m_pageCount;
        }
        void PutDocumentSaveAsTiffRequest::setPageCount(boost::optional<int32_t> pageCount){
            m_pageCount = std::move(pageCount);
        }
        boost::optional<int32_t> PutDocumentSaveAsTiffRequest::getPageIndex() const
        {
            return m_pageIndex;
        }
        void PutDocumentSaveAsTiffRequest::setPageIndex(boost::optional<int32_t> pageIndex){
            m_pageIndex = std::move(pageIndex);
        }
        boost::optional<utility::string_t> PutDocumentSaveAsTiffRequest::getPaperColor() const
        {
            return m_paperColor;
        }
        void PutDocumentSaveAsTiffRequest::setPaperColor(boost::optional<utility::string_t> paperColor){
            m_paperColor = std::move(paperColor);
        }
        boost::optional<utility::string_t> PutDocumentSaveAsTiffRequest::getPixelFormat() const
        {
            return m_pixelFormat;
        }
        void PutDocumentSaveAsTiffRequest::setPixelFormat(boost::optional<utility::string_t> pixelFormat){
            m_pixelFormat = std::move(pixelFormat);
        }
        boost::optional<double> PutDocumentSaveAsTiffRequest::getResolution() const
        {
            return m_resolution;
        }
        void PutDocumentSaveAsTiffRequest::setResolution(boost::optional<double> resolution){
            m_resolution = std::move(resolution);
        }
        boost::optional<double> PutDocumentSaveAsTiffRequest::getScale() const
        {
            return m_scale;
        }
        void PutDocumentSaveAsTiffRequest::setScale(boost::optional<double> scale){
            m_scale = std::move(scale);
        }
        boost::optional<utility::string_t> PutDocumentSaveAsTiffRequest::getTiffCompression() const
        {
            return m_tiffCompression;
        }
        void PutDocumentSaveAsTiffRequest::setTiffCompression(boost::optional<utility::string_t> tiffCompression){
            m_tiffCompression = std::move(tiffCompression);
        }
        boost::optional<utility::string_t> PutDocumentSaveAsTiffRequest::getDmlRenderingMode() const
        {
            return m_dmlRenderingMode;
        }
        void PutDocumentSaveAsTiffRequest::setDmlRenderingMode(boost::optional<utility::string_t> dmlRenderingMode){
            m_dmlRenderingMode = std::move(dmlRenderingMode);
        }
        boost::optional<utility::string_t> PutDocumentSaveAsTiffRequest::getDmlEffectsRenderingMode() const
        {
            return m_dmlEffectsRenderingMode;
        }
        void PutDocumentSaveAsTiffRequest::setDmlEffectsRenderingMode(boost::optional<utility::string_t> dmlEffectsRenderingMode){
            m_dmlEffectsRenderingMode = std::move(dmlEffectsRenderingMode);
        }
        boost::optional<utility::string_t> PutDocumentSaveAsTiffRequest::getTiffBinarizationMethod() const
        {
            return m_tiffBinarizationMethod;
        }
        void PutDocumentSaveAsTiffRequest::setTiffBinarizationMethod(boost::optional<utility::string_t> tiffBinarizationMethod){
            m_tiffBinarizationMethod = std::move(tiffBinarizationMethod);
        }
        boost::optional<bool> PutDocumentSaveAsTiffRequest::getZipOutput() const
        {
            return m_zipOutput;
        }
        void PutDocumentSaveAsTiffRequest::setZipOutput(boost::optional<bool> zipOutput){
            m_zipOutput = std::move(zipOutput);
        }
        boost::optional<utility::string_t> PutDocumentSaveAsTiffRequest::getFontsLocation() const
        {
            return m_fontsLocation;
        }
        void PutDocumentSaveAsTiffRequest::setFontsLocation(boost::optional<utility::string_t> fontsLocation){
            m_fontsLocation = std::move(fontsLocation);
        }

}
}
}
}
}

