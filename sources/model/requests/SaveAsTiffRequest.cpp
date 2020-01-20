/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SaveAsTiffRequest.cpp">
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
#include "SaveAsTiffRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
SaveAsTiffRequest::SaveAsTiffRequest(
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
        ) : 
            m_name(std::move(name)),
            m_saveOptions(std::move(saveOptions)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
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

        utility::string_t SaveAsTiffRequest::getName() const
        {
            return m_name;
        }
        void SaveAsTiffRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<TiffSaveOptionsData> SaveAsTiffRequest::getSaveOptions() const
        {
            return m_saveOptions;
        }
        void SaveAsTiffRequest::setSaveOptions(std::shared_ptr<TiffSaveOptionsData> saveOptions){
            m_saveOptions = std::move(saveOptions);
        }
        boost::optional<utility::string_t> SaveAsTiffRequest::getFolder() const
        {
            return m_folder;
        }
        void SaveAsTiffRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> SaveAsTiffRequest::getStorage() const
        {
            return m_storage;
        }
        void SaveAsTiffRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> SaveAsTiffRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void SaveAsTiffRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> SaveAsTiffRequest::getPassword() const
        {
            return m_password;
        }
        void SaveAsTiffRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<bool> SaveAsTiffRequest::getUseAntiAliasing() const
        {
            return m_useAntiAliasing;
        }
        void SaveAsTiffRequest::setUseAntiAliasing(boost::optional<bool> useAntiAliasing){
            m_useAntiAliasing = std::move(useAntiAliasing);
        }
        boost::optional<bool> SaveAsTiffRequest::getUseHighQualityRendering() const
        {
            return m_useHighQualityRendering;
        }
        void SaveAsTiffRequest::setUseHighQualityRendering(boost::optional<bool> useHighQualityRendering){
            m_useHighQualityRendering = std::move(useHighQualityRendering);
        }
        boost::optional<double> SaveAsTiffRequest::getImageBrightness() const
        {
            return m_imageBrightness;
        }
        void SaveAsTiffRequest::setImageBrightness(boost::optional<double> imageBrightness){
            m_imageBrightness = std::move(imageBrightness);
        }
        boost::optional<utility::string_t> SaveAsTiffRequest::getImageColorMode() const
        {
            return m_imageColorMode;
        }
        void SaveAsTiffRequest::setImageColorMode(boost::optional<utility::string_t> imageColorMode){
            m_imageColorMode = std::move(imageColorMode);
        }
        boost::optional<double> SaveAsTiffRequest::getImageContrast() const
        {
            return m_imageContrast;
        }
        void SaveAsTiffRequest::setImageContrast(boost::optional<double> imageContrast){
            m_imageContrast = std::move(imageContrast);
        }
        boost::optional<utility::string_t> SaveAsTiffRequest::getNumeralFormat() const
        {
            return m_numeralFormat;
        }
        void SaveAsTiffRequest::setNumeralFormat(boost::optional<utility::string_t> numeralFormat){
            m_numeralFormat = std::move(numeralFormat);
        }
        boost::optional<int32_t> SaveAsTiffRequest::getPageCount() const
        {
            return m_pageCount;
        }
        void SaveAsTiffRequest::setPageCount(boost::optional<int32_t> pageCount){
            m_pageCount = std::move(pageCount);
        }
        boost::optional<int32_t> SaveAsTiffRequest::getPageIndex() const
        {
            return m_pageIndex;
        }
        void SaveAsTiffRequest::setPageIndex(boost::optional<int32_t> pageIndex){
            m_pageIndex = std::move(pageIndex);
        }
        boost::optional<utility::string_t> SaveAsTiffRequest::getPaperColor() const
        {
            return m_paperColor;
        }
        void SaveAsTiffRequest::setPaperColor(boost::optional<utility::string_t> paperColor){
            m_paperColor = std::move(paperColor);
        }
        boost::optional<utility::string_t> SaveAsTiffRequest::getPixelFormat() const
        {
            return m_pixelFormat;
        }
        void SaveAsTiffRequest::setPixelFormat(boost::optional<utility::string_t> pixelFormat){
            m_pixelFormat = std::move(pixelFormat);
        }
        boost::optional<double> SaveAsTiffRequest::getResolution() const
        {
            return m_resolution;
        }
        void SaveAsTiffRequest::setResolution(boost::optional<double> resolution){
            m_resolution = std::move(resolution);
        }
        boost::optional<double> SaveAsTiffRequest::getScale() const
        {
            return m_scale;
        }
        void SaveAsTiffRequest::setScale(boost::optional<double> scale){
            m_scale = std::move(scale);
        }
        boost::optional<utility::string_t> SaveAsTiffRequest::getTiffCompression() const
        {
            return m_tiffCompression;
        }
        void SaveAsTiffRequest::setTiffCompression(boost::optional<utility::string_t> tiffCompression){
            m_tiffCompression = std::move(tiffCompression);
        }
        boost::optional<utility::string_t> SaveAsTiffRequest::getDmlRenderingMode() const
        {
            return m_dmlRenderingMode;
        }
        void SaveAsTiffRequest::setDmlRenderingMode(boost::optional<utility::string_t> dmlRenderingMode){
            m_dmlRenderingMode = std::move(dmlRenderingMode);
        }
        boost::optional<utility::string_t> SaveAsTiffRequest::getDmlEffectsRenderingMode() const
        {
            return m_dmlEffectsRenderingMode;
        }
        void SaveAsTiffRequest::setDmlEffectsRenderingMode(boost::optional<utility::string_t> dmlEffectsRenderingMode){
            m_dmlEffectsRenderingMode = std::move(dmlEffectsRenderingMode);
        }
        boost::optional<utility::string_t> SaveAsTiffRequest::getTiffBinarizationMethod() const
        {
            return m_tiffBinarizationMethod;
        }
        void SaveAsTiffRequest::setTiffBinarizationMethod(boost::optional<utility::string_t> tiffBinarizationMethod){
            m_tiffBinarizationMethod = std::move(tiffBinarizationMethod);
        }
        boost::optional<bool> SaveAsTiffRequest::getZipOutput() const
        {
            return m_zipOutput;
        }
        void SaveAsTiffRequest::setZipOutput(boost::optional<bool> zipOutput){
            m_zipOutput = std::move(zipOutput);
        }
        boost::optional<utility::string_t> SaveAsTiffRequest::getFontsLocation() const
        {
            return m_fontsLocation;
        }
        void SaveAsTiffRequest::setFontsLocation(boost::optional<utility::string_t> fontsLocation){
            m_fontsLocation = std::move(fontsLocation);
        }

}
}
}
}
}

