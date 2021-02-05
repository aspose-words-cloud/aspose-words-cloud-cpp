/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SaveAsTiffOnlineRequest.cpp">
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

#include "SaveAsTiffOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
SaveAsTiffOnlineRequest::SaveAsTiffOnlineRequest(
    std::shared_ptr<HttpContent> document,
    std::shared_ptr<TiffSaveOptionsData> saveOptions,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< bool > useAntiAliasing,
    boost::optional< bool > useHighQualityRendering,
    boost::optional< double > imageBrightness,
    boost::optional< utility::string_t > imageColorMode,
    boost::optional< double > imageContrast,
    boost::optional< utility::string_t > numeralFormat,
    boost::optional< int32_t > pageCount,
    boost::optional< int32_t > pageIndex,
    boost::optional< utility::string_t > paperColor,
    boost::optional< utility::string_t > pixelFormat,
    boost::optional< double > resolution,
    boost::optional< double > scale,
    boost::optional< utility::string_t > tiffCompression,
    boost::optional< utility::string_t > dmlRenderingMode,
    boost::optional< utility::string_t > dmlEffectsRenderingMode,
    boost::optional< utility::string_t > tiffBinarizationMethod,
    boost::optional< bool > zipOutput,
    boost::optional< utility::string_t > fontsLocation
) : m_Document(std::move(document)),
m_SaveOptions(std::move(saveOptions)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_UseAntiAliasing(std::move(useAntiAliasing)),
m_UseHighQualityRendering(std::move(useHighQualityRendering)),
m_ImageBrightness(std::move(imageBrightness)),
m_ImageColorMode(std::move(imageColorMode)),
m_ImageContrast(std::move(imageContrast)),
m_NumeralFormat(std::move(numeralFormat)),
m_PageCount(std::move(pageCount)),
m_PageIndex(std::move(pageIndex)),
m_PaperColor(std::move(paperColor)),
m_PixelFormat(std::move(pixelFormat)),
m_Resolution(std::move(resolution)),
m_Scale(std::move(scale)),
m_TiffCompression(std::move(tiffCompression)),
m_DmlRenderingMode(std::move(dmlRenderingMode)),
m_DmlEffectsRenderingMode(std::move(dmlEffectsRenderingMode)),
m_TiffBinarizationMethod(std::move(tiffBinarizationMethod)),
m_ZipOutput(std::move(zipOutput)),
m_FontsLocation(std::move(fontsLocation))
{
}

std::shared_ptr<HttpContent> SaveAsTiffOnlineRequest::getDocument() const
{
    return m_Document;
}

void SaveAsTiffOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

std::shared_ptr<TiffSaveOptionsData> SaveAsTiffOnlineRequest::getSaveOptions() const
{
    return m_SaveOptions;
}

void SaveAsTiffOnlineRequest::setSaveOptions(std::shared_ptr<TiffSaveOptionsData> saveOptions)
{
    m_SaveOptions = std::move(saveOptions);
}

boost::optional< utility::string_t > SaveAsTiffOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void SaveAsTiffOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > SaveAsTiffOnlineRequest::getPassword() const
{
    return m_Password;
}

void SaveAsTiffOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< bool > SaveAsTiffOnlineRequest::getUseAntiAliasing() const
{
    return m_UseAntiAliasing;
}

void SaveAsTiffOnlineRequest::setUseAntiAliasing(boost::optional< bool > useAntiAliasing)
{
    m_UseAntiAliasing = std::move(useAntiAliasing);
}

boost::optional< bool > SaveAsTiffOnlineRequest::getUseHighQualityRendering() const
{
    return m_UseHighQualityRendering;
}

void SaveAsTiffOnlineRequest::setUseHighQualityRendering(boost::optional< bool > useHighQualityRendering)
{
    m_UseHighQualityRendering = std::move(useHighQualityRendering);
}

boost::optional< double > SaveAsTiffOnlineRequest::getImageBrightness() const
{
    return m_ImageBrightness;
}

void SaveAsTiffOnlineRequest::setImageBrightness(boost::optional< double > imageBrightness)
{
    m_ImageBrightness = std::move(imageBrightness);
}

boost::optional< utility::string_t > SaveAsTiffOnlineRequest::getImageColorMode() const
{
    return m_ImageColorMode;
}

void SaveAsTiffOnlineRequest::setImageColorMode(boost::optional< utility::string_t > imageColorMode)
{
    m_ImageColorMode = std::move(imageColorMode);
}

boost::optional< double > SaveAsTiffOnlineRequest::getImageContrast() const
{
    return m_ImageContrast;
}

void SaveAsTiffOnlineRequest::setImageContrast(boost::optional< double > imageContrast)
{
    m_ImageContrast = std::move(imageContrast);
}

boost::optional< utility::string_t > SaveAsTiffOnlineRequest::getNumeralFormat() const
{
    return m_NumeralFormat;
}

void SaveAsTiffOnlineRequest::setNumeralFormat(boost::optional< utility::string_t > numeralFormat)
{
    m_NumeralFormat = std::move(numeralFormat);
}

boost::optional< int32_t > SaveAsTiffOnlineRequest::getPageCount() const
{
    return m_PageCount;
}

void SaveAsTiffOnlineRequest::setPageCount(boost::optional< int32_t > pageCount)
{
    m_PageCount = std::move(pageCount);
}

boost::optional< int32_t > SaveAsTiffOnlineRequest::getPageIndex() const
{
    return m_PageIndex;
}

void SaveAsTiffOnlineRequest::setPageIndex(boost::optional< int32_t > pageIndex)
{
    m_PageIndex = std::move(pageIndex);
}

boost::optional< utility::string_t > SaveAsTiffOnlineRequest::getPaperColor() const
{
    return m_PaperColor;
}

void SaveAsTiffOnlineRequest::setPaperColor(boost::optional< utility::string_t > paperColor)
{
    m_PaperColor = std::move(paperColor);
}

boost::optional< utility::string_t > SaveAsTiffOnlineRequest::getPixelFormat() const
{
    return m_PixelFormat;
}

void SaveAsTiffOnlineRequest::setPixelFormat(boost::optional< utility::string_t > pixelFormat)
{
    m_PixelFormat = std::move(pixelFormat);
}

boost::optional< double > SaveAsTiffOnlineRequest::getResolution() const
{
    return m_Resolution;
}

void SaveAsTiffOnlineRequest::setResolution(boost::optional< double > resolution)
{
    m_Resolution = std::move(resolution);
}

boost::optional< double > SaveAsTiffOnlineRequest::getScale() const
{
    return m_Scale;
}

void SaveAsTiffOnlineRequest::setScale(boost::optional< double > scale)
{
    m_Scale = std::move(scale);
}

boost::optional< utility::string_t > SaveAsTiffOnlineRequest::getTiffCompression() const
{
    return m_TiffCompression;
}

void SaveAsTiffOnlineRequest::setTiffCompression(boost::optional< utility::string_t > tiffCompression)
{
    m_TiffCompression = std::move(tiffCompression);
}

boost::optional< utility::string_t > SaveAsTiffOnlineRequest::getDmlRenderingMode() const
{
    return m_DmlRenderingMode;
}

void SaveAsTiffOnlineRequest::setDmlRenderingMode(boost::optional< utility::string_t > dmlRenderingMode)
{
    m_DmlRenderingMode = std::move(dmlRenderingMode);
}

boost::optional< utility::string_t > SaveAsTiffOnlineRequest::getDmlEffectsRenderingMode() const
{
    return m_DmlEffectsRenderingMode;
}

void SaveAsTiffOnlineRequest::setDmlEffectsRenderingMode(boost::optional< utility::string_t > dmlEffectsRenderingMode)
{
    m_DmlEffectsRenderingMode = std::move(dmlEffectsRenderingMode);
}

boost::optional< utility::string_t > SaveAsTiffOnlineRequest::getTiffBinarizationMethod() const
{
    return m_TiffBinarizationMethod;
}

void SaveAsTiffOnlineRequest::setTiffBinarizationMethod(boost::optional< utility::string_t > tiffBinarizationMethod)
{
    m_TiffBinarizationMethod = std::move(tiffBinarizationMethod);
}

boost::optional< bool > SaveAsTiffOnlineRequest::getZipOutput() const
{
    return m_ZipOutput;
}

void SaveAsTiffOnlineRequest::setZipOutput(boost::optional< bool > zipOutput)
{
    m_ZipOutput = std::move(zipOutput);
}

boost::optional< utility::string_t > SaveAsTiffOnlineRequest::getFontsLocation() const
{
    return m_FontsLocation;
}

void SaveAsTiffOnlineRequest::setFontsLocation(boost::optional< utility::string_t > fontsLocation)
{
    m_FontsLocation = std::move(fontsLocation);
}

}
}
}
}
}
