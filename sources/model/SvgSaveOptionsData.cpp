/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SvgSaveOptionsData.cpp">
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

#include "SvgSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

SvgSaveOptionsData::SvgSaveOptionsData()
{
    m_ExportEmbeddedImages = false;
    m_ExportEmbeddedImagesIsSet = false;
    m_FitToViewPort = false;
    m_FitToViewPortIsSet = false;
    m_ResourcesFolder = utility::conversions::to_string_t("");
    m_ResourcesFolderIsSet = false;
    m_ResourcesFolderAlias = utility::conversions::to_string_t("");
    m_ResourcesFolderAliasIsSet = false;
    m_ShowPageBorder = false;
    m_ShowPageBorderIsSet = false;
    m_TextOutputMode = utility::conversions::to_string_t("");
    m_TextOutputModeIsSet = false;

}

SvgSaveOptionsData::~SvgSaveOptionsData()
{
}

void SvgSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value SvgSaveOptionsData::toJson() const
{
    web::json::value val = this->FixedPageSaveOptionsData::toJson();
    if(m_ExportEmbeddedImagesIsSet)
    {
        val[_XPLATSTR("ExportEmbeddedImages")] = ModelBase::toJson(m_ExportEmbeddedImages);
    }
    if(m_FitToViewPortIsSet)
    {
        val[_XPLATSTR("FitToViewPort")] = ModelBase::toJson(m_FitToViewPort);
    }
    if(m_ResourcesFolderIsSet)
    {
        val[_XPLATSTR("ResourcesFolder")] = ModelBase::toJson(m_ResourcesFolder);
    }
    if(m_ResourcesFolderAliasIsSet)
    {
        val[_XPLATSTR("ResourcesFolderAlias")] = ModelBase::toJson(m_ResourcesFolderAlias);
    }
    if(m_ShowPageBorderIsSet)
    {
        val[_XPLATSTR("ShowPageBorder")] = ModelBase::toJson(m_ShowPageBorder);
    }
    if(m_TextOutputModeIsSet)
    {
        val[_XPLATSTR("TextOutputMode")] = ModelBase::toJson(m_TextOutputMode);
    }

    return val;
}

void SvgSaveOptionsData::fromJson(web::json::value& val)
{
    this->FixedPageSaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("ExportEmbeddedImages")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportEmbeddedImages")];
        if(!fieldValue.is_null())
        {
           setExportEmbeddedImages(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("FitToViewPort")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("FitToViewPort")];
        if(!fieldValue.is_null())
        {
           setFitToViewPort(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("ResourcesFolder")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ResourcesFolder")];
        if(!fieldValue.is_null())
        {
           setResourcesFolder(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("ResourcesFolderAlias")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ResourcesFolderAlias")];
        if(!fieldValue.is_null())
        {
           setResourcesFolderAlias(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("ShowPageBorder")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ShowPageBorder")];
        if(!fieldValue.is_null())
        {
           setShowPageBorder(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("TextOutputMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("TextOutputMode")];
        if(!fieldValue.is_null())
        {
           setTextOutputMode(ModelBase::stringFromJson(fieldValue));
        }
    }

}

void SvgSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    FixedPageSaveOptionsData::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_ExportEmbeddedImagesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportEmbeddedImages"), m_ExportEmbeddedImages));
    }


    if(m_FitToViewPortIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("FitToViewPort"), m_FitToViewPort));
    }


    if(m_ResourcesFolderIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ResourcesFolder"), m_ResourcesFolder));
    }


    if(m_ResourcesFolderAliasIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ResourcesFolderAlias"), m_ResourcesFolderAlias));
    }


    if(m_ShowPageBorderIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ShowPageBorder"), m_ShowPageBorder));
    }


    if(m_TextOutputModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TextOutputMode"), m_TextOutputMode));
    }

}

void SvgSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

bool SvgSaveOptionsData::isExportEmbeddedImages() const
{
    return m_ExportEmbeddedImages;
}


void SvgSaveOptionsData::setExportEmbeddedImages(bool value)
{
    m_ExportEmbeddedImages = value;
    m_ExportEmbeddedImagesIsSet = true;
}

bool SvgSaveOptionsData::exportEmbeddedImagesIsSet() const
{
    return m_ExportEmbeddedImagesIsSet;
}

void SvgSaveOptionsData::unsetExportEmbeddedImages()
{
    m_ExportEmbeddedImagesIsSet = false;
}

bool SvgSaveOptionsData::isFitToViewPort() const
{
    return m_FitToViewPort;
}


void SvgSaveOptionsData::setFitToViewPort(bool value)
{
    m_FitToViewPort = value;
    m_FitToViewPortIsSet = true;
}

bool SvgSaveOptionsData::fitToViewPortIsSet() const
{
    return m_FitToViewPortIsSet;
}

void SvgSaveOptionsData::unsetFitToViewPort()
{
    m_FitToViewPortIsSet = false;
}

utility::string_t SvgSaveOptionsData::getResourcesFolder() const
{
    return m_ResourcesFolder;
}


void SvgSaveOptionsData::setResourcesFolder(utility::string_t value)
{
    m_ResourcesFolder = value;
    m_ResourcesFolderIsSet = true;
}

bool SvgSaveOptionsData::resourcesFolderIsSet() const
{
    return m_ResourcesFolderIsSet;
}

void SvgSaveOptionsData::unsetResourcesFolder()
{
    m_ResourcesFolderIsSet = false;
}

utility::string_t SvgSaveOptionsData::getResourcesFolderAlias() const
{
    return m_ResourcesFolderAlias;
}


void SvgSaveOptionsData::setResourcesFolderAlias(utility::string_t value)
{
    m_ResourcesFolderAlias = value;
    m_ResourcesFolderAliasIsSet = true;
}

bool SvgSaveOptionsData::resourcesFolderAliasIsSet() const
{
    return m_ResourcesFolderAliasIsSet;
}

void SvgSaveOptionsData::unsetResourcesFolderAlias()
{
    m_ResourcesFolderAliasIsSet = false;
}

bool SvgSaveOptionsData::isShowPageBorder() const
{
    return m_ShowPageBorder;
}


void SvgSaveOptionsData::setShowPageBorder(bool value)
{
    m_ShowPageBorder = value;
    m_ShowPageBorderIsSet = true;
}

bool SvgSaveOptionsData::showPageBorderIsSet() const
{
    return m_ShowPageBorderIsSet;
}

void SvgSaveOptionsData::unsetShowPageBorder()
{
    m_ShowPageBorderIsSet = false;
}

utility::string_t SvgSaveOptionsData::getTextOutputMode() const
{
    return m_TextOutputMode;
}


void SvgSaveOptionsData::setTextOutputMode(utility::string_t value)
{
    m_TextOutputMode = value;
    m_TextOutputModeIsSet = true;
}

bool SvgSaveOptionsData::textOutputModeIsSet() const
{
    return m_TextOutputModeIsSet;
}

void SvgSaveOptionsData::unsetTextOutputMode()
{
    m_TextOutputModeIsSet = false;
}

}
}
}
}
}
