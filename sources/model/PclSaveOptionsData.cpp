/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PclSaveOptionsData.cpp">
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

#include "PclSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

PclSaveOptionsData::PclSaveOptionsData()
{
    m_FalllbackFontName = utility::conversions::to_string_t("");
    m_FalllbackFontNameIsSet = false;
    m_RasterizeTransformedElements = false;
    m_RasterizeTransformedElementsIsSet = false;

}

PclSaveOptionsData::~PclSaveOptionsData()
{
}

void PclSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value PclSaveOptionsData::toJson() const
{
    web::json::value val = this->FixedPageSaveOptionsData::toJson();
    if(m_FalllbackFontNameIsSet)
    {
        val[_XPLATSTR("FalllbackFontName")] = ModelBase::toJson(m_FalllbackFontName);
    }
    if(m_RasterizeTransformedElementsIsSet)
    {
        val[_XPLATSTR("RasterizeTransformedElements")] = ModelBase::toJson(m_RasterizeTransformedElements);
    }

    return val;
}

void PclSaveOptionsData::fromJson(web::json::value& val)
{
    this->FixedPageSaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("FalllbackFontName")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("FalllbackFontName")];
        if(!fieldValue.is_null())
        {
           setFalllbackFontName(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("RasterizeTransformedElements")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("RasterizeTransformedElements")];
        if(!fieldValue.is_null())
        {
           setRasterizeTransformedElements(ModelBase::booleanFromJson(fieldValue));
        }
    }

}

void PclSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    FixedPageSaveOptionsData::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_FalllbackFontNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("FalllbackFontName"), m_FalllbackFontName));
    }


    if(m_RasterizeTransformedElementsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RasterizeTransformedElements"), m_RasterizeTransformedElements));
    }

}

void PclSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

utility::string_t PclSaveOptionsData::getFalllbackFontName() const
{
    return m_FalllbackFontName;
}


void PclSaveOptionsData::setFalllbackFontName(utility::string_t value)
{
    m_FalllbackFontName = value;
    m_FalllbackFontNameIsSet = true;
}

bool PclSaveOptionsData::falllbackFontNameIsSet() const
{
    return m_FalllbackFontNameIsSet;
}

void PclSaveOptionsData::unsetFalllbackFontName()
{
    m_FalllbackFontNameIsSet = false;
}

bool PclSaveOptionsData::isRasterizeTransformedElements() const
{
    return m_RasterizeTransformedElements;
}


void PclSaveOptionsData::setRasterizeTransformedElements(bool value)
{
    m_RasterizeTransformedElements = value;
    m_RasterizeTransformedElementsIsSet = true;
}

bool PclSaveOptionsData::rasterizeTransformedElementsIsSet() const
{
    return m_RasterizeTransformedElementsIsSet;
}

void PclSaveOptionsData::unsetRasterizeTransformedElements()
{
    m_RasterizeTransformedElementsIsSet = false;
}

}
}
}
}
}
