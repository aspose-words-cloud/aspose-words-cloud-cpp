/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="MetafileRenderingOptionsData.cpp">
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


#include "MetafileRenderingOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

MetafileRenderingOptionsData::MetafileRenderingOptionsData()
{
    m_EmfPlusDualRenderingMode = utility::conversions::to_string_t("");
    m_EmfPlusDualRenderingModeIsSet = false;
    m_EmulateRasterOperations = false;
    m_EmulateRasterOperationsIsSet = false;
    m_RenderingMode = utility::conversions::to_string_t("");
    m_RenderingModeIsSet = false;
    m_UseEmfEmbeddedToWmf = false;
    m_UseEmfEmbeddedToWmfIsSet = false;
    m_ScaleWmfFontsToMetafileSize = false;
    m_ScaleWmfFontsToMetafileSizeIsSet = false;
}

MetafileRenderingOptionsData::~MetafileRenderingOptionsData()
{
}

void MetafileRenderingOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value MetafileRenderingOptionsData::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_EmfPlusDualRenderingModeIsSet)
    {
        val[_XPLATSTR("emfPlusDualRenderingMode")] = ModelBase::toJson(m_EmfPlusDualRenderingMode);
    }
    if(m_EmulateRasterOperationsIsSet)
    {
        val[_XPLATSTR("emulateRasterOperations")] = ModelBase::toJson(m_EmulateRasterOperations);
    }
    if(m_RenderingModeIsSet)
    {
        val[_XPLATSTR("renderingMode")] = ModelBase::toJson(m_RenderingMode);
    }
    if(m_UseEmfEmbeddedToWmfIsSet)
    {
        val[_XPLATSTR("useEmfEmbeddedToWmf")] = ModelBase::toJson(m_UseEmfEmbeddedToWmf);
    }
    if(m_ScaleWmfFontsToMetafileSizeIsSet)
    {
        val[_XPLATSTR("scaleWmfFontsToMetafileSize")] = ModelBase::toJson(m_ScaleWmfFontsToMetafileSize);
    }

    return val;
}

void MetafileRenderingOptionsData::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("emfPlusDualRenderingMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("emfPlusDualRenderingMode")];
        if(!fieldValue.is_null())
        {
            setEmfPlusDualRenderingMode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("emulateRasterOperations")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("emulateRasterOperations")];
        if(!fieldValue.is_null())
        {
            setEmulateRasterOperations(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("renderingMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("renderingMode")];
        if(!fieldValue.is_null())
        {
            setRenderingMode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("useEmfEmbeddedToWmf")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("useEmfEmbeddedToWmf")];
        if(!fieldValue.is_null())
        {
            setUseEmfEmbeddedToWmf(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("scaleWmfFontsToMetafileSize")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("scaleWmfFontsToMetafileSize")];
        if(!fieldValue.is_null())
        {
            setScaleWmfFontsToMetafileSize(ModelBase::boolFromJson(fieldValue));
        }
    }
}

void MetafileRenderingOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_EmfPlusDualRenderingModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("emfPlusDualRenderingMode"), m_EmfPlusDualRenderingMode));
        
    }
    if(m_EmulateRasterOperationsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("emulateRasterOperations"), m_EmulateRasterOperations));
    }
    if(m_RenderingModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("renderingMode"), m_RenderingMode));
        
    }
    if(m_UseEmfEmbeddedToWmfIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("useEmfEmbeddedToWmf"), m_UseEmfEmbeddedToWmf));
    }
    if(m_ScaleWmfFontsToMetafileSizeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("scaleWmfFontsToMetafileSize"), m_ScaleWmfFontsToMetafileSize));
    }
}

void MetafileRenderingOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("emfPlusDualRenderingMode")))
    {
        setEmfPlusDualRenderingMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("emfPlusDualRenderingMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("emulateRasterOperations")))
    {
        setEmulateRasterOperations(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("emulateRasterOperations"))));
    }
    if(multipart->hasContent(_XPLATSTR("renderingMode")))
    {
        setRenderingMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("renderingMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("useEmfEmbeddedToWmf")))
    {
        setUseEmfEmbeddedToWmf(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("useEmfEmbeddedToWmf"))));
    }
    if(multipart->hasContent(_XPLATSTR("scaleWmfFontsToMetafileSize")))
    {
        setScaleWmfFontsToMetafileSize(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("scaleWmfFontsToMetafileSize"))));
    }
}

utility::string_t MetafileRenderingOptionsData::getEmfPlusDualRenderingMode() const
{
    return m_EmfPlusDualRenderingMode;
}


void MetafileRenderingOptionsData::setEmfPlusDualRenderingMode(utility::string_t value)
{
    m_EmfPlusDualRenderingMode = value;
    m_EmfPlusDualRenderingModeIsSet = true;
}
bool MetafileRenderingOptionsData::emfPlusDualRenderingModeIsSet() const
{
    return m_EmfPlusDualRenderingModeIsSet;
}

void MetafileRenderingOptionsData::unsetEmfPlusDualRenderingMode()
{
    m_EmfPlusDualRenderingModeIsSet = false;
}

bool MetafileRenderingOptionsData::isEmulateRasterOperations() const
{
    return m_EmulateRasterOperations;
}


void MetafileRenderingOptionsData::setEmulateRasterOperations(bool value)
{
    m_EmulateRasterOperations = value;
    m_EmulateRasterOperationsIsSet = true;
}
bool MetafileRenderingOptionsData::emulateRasterOperationsIsSet() const
{
    return m_EmulateRasterOperationsIsSet;
}

void MetafileRenderingOptionsData::unsetEmulateRasterOperations()
{
    m_EmulateRasterOperationsIsSet = false;
}

utility::string_t MetafileRenderingOptionsData::getRenderingMode() const
{
    return m_RenderingMode;
}


void MetafileRenderingOptionsData::setRenderingMode(utility::string_t value)
{
    m_RenderingMode = value;
    m_RenderingModeIsSet = true;
}
bool MetafileRenderingOptionsData::renderingModeIsSet() const
{
    return m_RenderingModeIsSet;
}

void MetafileRenderingOptionsData::unsetRenderingMode()
{
    m_RenderingModeIsSet = false;
}

bool MetafileRenderingOptionsData::isUseEmfEmbeddedToWmf() const
{
    return m_UseEmfEmbeddedToWmf;
}


void MetafileRenderingOptionsData::setUseEmfEmbeddedToWmf(bool value)
{
    m_UseEmfEmbeddedToWmf = value;
    m_UseEmfEmbeddedToWmfIsSet = true;
}
bool MetafileRenderingOptionsData::useEmfEmbeddedToWmfIsSet() const
{
    return m_UseEmfEmbeddedToWmfIsSet;
}

void MetafileRenderingOptionsData::unsetUseEmfEmbeddedToWmf()
{
    m_UseEmfEmbeddedToWmfIsSet = false;
}

bool MetafileRenderingOptionsData::isScaleWmfFontsToMetafileSize() const
{
    return m_ScaleWmfFontsToMetafileSize;
}


void MetafileRenderingOptionsData::setScaleWmfFontsToMetafileSize(bool value)
{
    m_ScaleWmfFontsToMetafileSize = value;
    m_ScaleWmfFontsToMetafileSizeIsSet = true;
}
bool MetafileRenderingOptionsData::scaleWmfFontsToMetafileSizeIsSet() const
{
    return m_ScaleWmfFontsToMetafileSizeIsSet;
}

void MetafileRenderingOptionsData::unsetScaleWmfFontsToMetafileSize()
{
    m_ScaleWmfFontsToMetafileSizeIsSet = false;
}

}
}
}
}
}

