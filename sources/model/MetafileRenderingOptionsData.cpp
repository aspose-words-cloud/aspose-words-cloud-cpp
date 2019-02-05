/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="MetafileRenderingOptionsData.cpp">
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


#include "MetafileRenderingOptionsData.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

MetafileRenderingOptionsData::MetafileRenderingOptionsData()
{
    m_EmfPlusDualRenderingMode = _XPLATSTR("");
    m_EmfPlusDualRenderingModeIsSet = false;
    m_EmulateRasterOperations = false;
    m_EmulateRasterOperationsIsSet = false;
    m_RenderingMode = _XPLATSTR("");
    m_RenderingModeIsSet = false;
    m_UseEmfEmbeddedToWmf = false;
    m_UseEmfEmbeddedToWmfIsSet = false;
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
        val[_XPLATSTR("EmfPlusDualRenderingMode")] = ModelBase::toJson(m_EmfPlusDualRenderingMode);
    }
    if(m_EmulateRasterOperationsIsSet)
    {
        val[_XPLATSTR("EmulateRasterOperations")] = ModelBase::toJson(m_EmulateRasterOperations);
    }
    if(m_RenderingModeIsSet)
    {
        val[_XPLATSTR("RenderingMode")] = ModelBase::toJson(m_RenderingMode);
    }
    if(m_UseEmfEmbeddedToWmfIsSet)
    {
        val[_XPLATSTR("UseEmfEmbeddedToWmf")] = ModelBase::toJson(m_UseEmfEmbeddedToWmf);
    }

    return val;
}

void MetafileRenderingOptionsData::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("EmfPlusDualRenderingMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("EmfPlusDualRenderingMode")];
        if(!fieldValue.is_null())
        {
            setEmfPlusDualRenderingMode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("EmulateRasterOperations")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("EmulateRasterOperations")];
        if(!fieldValue.is_null())
        {
            setEmulateRasterOperations(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("RenderingMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("RenderingMode")];
        if(!fieldValue.is_null())
        {
            setRenderingMode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("UseEmfEmbeddedToWmf")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("UseEmfEmbeddedToWmf")];
        if(!fieldValue.is_null())
        {
            setUseEmfEmbeddedToWmf(ModelBase::boolFromJson(fieldValue));
        }
    }
}

void MetafileRenderingOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_EmfPlusDualRenderingModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("EmfPlusDualRenderingMode"), m_EmfPlusDualRenderingMode));
        
    }
    if(m_EmulateRasterOperationsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("EmulateRasterOperations"), m_EmulateRasterOperations));
    }
    if(m_RenderingModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RenderingMode"), m_RenderingMode));
        
    }
    if(m_UseEmfEmbeddedToWmfIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("UseEmfEmbeddedToWmf"), m_UseEmfEmbeddedToWmf));
    }
}

void MetafileRenderingOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(multipart->hasContent(_XPLATSTR("EmfPlusDualRenderingMode")))
    {
        setEmfPlusDualRenderingMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("EmfPlusDualRenderingMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("EmulateRasterOperations")))
    {
        setEmulateRasterOperations(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("EmulateRasterOperations"))));
    }
    if(multipart->hasContent(_XPLATSTR("RenderingMode")))
    {
        setRenderingMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("RenderingMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("UseEmfEmbeddedToWmf")))
    {
        setUseEmfEmbeddedToWmf(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("UseEmfEmbeddedToWmf"))));
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

}
}
}
}

