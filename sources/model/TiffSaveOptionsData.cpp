/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TiffSaveOptionsData.cpp">
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

#include "TiffSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

TiffSaveOptionsData::TiffSaveOptionsData()
{
    m_ThresholdForFloydSteinbergDithering = 0;
    m_ThresholdForFloydSteinbergDitheringIsSet = false;
    m_TiffBinarizationMethod = utility::conversions::to_string_t("");
    m_TiffBinarizationMethodIsSet = false;
    m_TiffCompression = utility::conversions::to_string_t("");
    m_TiffCompressionIsSet = false;

}

TiffSaveOptionsData::~TiffSaveOptionsData()
{
}

void TiffSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value TiffSaveOptionsData::toJson() const
{
    web::json::value val = this->ImageSaveOptionsData::toJson();
    if(m_ThresholdForFloydSteinbergDitheringIsSet)
    {
        val[_XPLATSTR("ThresholdForFloydSteinbergDithering")] = ModelBase::toJson(m_ThresholdForFloydSteinbergDithering);
    }
    if(m_TiffBinarizationMethodIsSet)
    {
        val[_XPLATSTR("TiffBinarizationMethod")] = ModelBase::toJson(m_TiffBinarizationMethod);
    }
    if(m_TiffCompressionIsSet)
    {
        val[_XPLATSTR("TiffCompression")] = ModelBase::toJson(m_TiffCompression);
    }

    return val;
}

void TiffSaveOptionsData::fromJson(web::json::value& val)
{
    this->ImageSaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("ThresholdForFloydSteinbergDithering")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ThresholdForFloydSteinbergDithering")];
        if(!fieldValue.is_null())
        {
           setThresholdForFloydSteinbergDithering(ModelBase::integerFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("TiffBinarizationMethod")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("TiffBinarizationMethod")];
        if(!fieldValue.is_null())
        {
           setTiffBinarizationMethod(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("TiffCompression")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("TiffCompression")];
        if(!fieldValue.is_null())
        {
           setTiffCompression(ModelBase::stringFromJson(fieldValue));
        }
    }

}

void TiffSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    ImageSaveOptionsData::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_ThresholdForFloydSteinbergDitheringIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ThresholdForFloydSteinbergDithering"), m_ThresholdForFloydSteinbergDithering));
    }


    if(m_TiffBinarizationMethodIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TiffBinarizationMethod"), m_TiffBinarizationMethod));
    }


    if(m_TiffCompressionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TiffCompression"), m_TiffCompression));
    }

}

void TiffSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

int32_t TiffSaveOptionsData::getThresholdForFloydSteinbergDithering() const
{
    return m_ThresholdForFloydSteinbergDithering;
}


void TiffSaveOptionsData::setThresholdForFloydSteinbergDithering(int32_t value)
{
    m_ThresholdForFloydSteinbergDithering = value;
    m_ThresholdForFloydSteinbergDitheringIsSet = true;
}

bool TiffSaveOptionsData::thresholdForFloydSteinbergDitheringIsSet() const
{
    return m_ThresholdForFloydSteinbergDitheringIsSet;
}

void TiffSaveOptionsData::unsetThresholdForFloydSteinbergDithering()
{
    m_ThresholdForFloydSteinbergDitheringIsSet = false;
}

utility::string_t TiffSaveOptionsData::getTiffBinarizationMethod() const
{
    return m_TiffBinarizationMethod;
}


void TiffSaveOptionsData::setTiffBinarizationMethod(utility::string_t value)
{
    m_TiffBinarizationMethod = value;
    m_TiffBinarizationMethodIsSet = true;
}

bool TiffSaveOptionsData::tiffBinarizationMethodIsSet() const
{
    return m_TiffBinarizationMethodIsSet;
}

void TiffSaveOptionsData::unsetTiffBinarizationMethod()
{
    m_TiffBinarizationMethodIsSet = false;
}

utility::string_t TiffSaveOptionsData::getTiffCompression() const
{
    return m_TiffCompression;
}


void TiffSaveOptionsData::setTiffCompression(utility::string_t value)
{
    m_TiffCompression = value;
    m_TiffCompressionIsSet = true;
}

bool TiffSaveOptionsData::tiffCompressionIsSet() const
{
    return m_TiffCompressionIsSet;
}

void TiffSaveOptionsData::unsetTiffCompression()
{
    m_TiffCompressionIsSet = false;
}

}
}
}
}
}
