/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="XamlFlowSaveOptionsData.cpp">
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


#include "XamlFlowSaveOptionsData.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

XamlFlowSaveOptionsData::XamlFlowSaveOptionsData()
{
    m_ImagesFolder = utility::conversions::to_string_t("");
    m_ImagesFolderIsSet = false;
    m_ImagesFolderAlias = utility::conversions::to_string_t("");
    m_ImagesFolderAliasIsSet = false;
}

XamlFlowSaveOptionsData::~XamlFlowSaveOptionsData()
{
}

void XamlFlowSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value XamlFlowSaveOptionsData::toJson() const
{
    web::json::value val = this->SaveOptionsData::toJson();

    if(m_ImagesFolderIsSet)
    {
        val[utility::conversions::to_string_t("ImagesFolder")] = ModelBase::toJson(m_ImagesFolder);
    }
    if(m_ImagesFolderAliasIsSet)
    {
        val[utility::conversions::to_string_t("ImagesFolderAlias")] = ModelBase::toJson(m_ImagesFolderAlias);
    }

    return val;
}

void XamlFlowSaveOptionsData::fromJson(web::json::value& val)
{
    this->SaveOptionsData::fromJson(val);

    if(val.has_field(utility::conversions::to_string_t("ImagesFolder")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("ImagesFolder")];
        if(!fieldValue.is_null())
        {
            setImagesFolder(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("ImagesFolderAlias")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("ImagesFolderAlias")];
        if(!fieldValue.is_null())
        {
            setImagesFolderAlias(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void XamlFlowSaveOptionsData::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_ColorModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("ColorMode"), m_ColorMode));
        
    }
    if(m_SaveFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("SaveFormat"), m_SaveFormat));
        
    }
    if(m_FileNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("FileName"), m_FileName));
        
    }
    if(m_DmlRenderingModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("DmlRenderingMode"), m_DmlRenderingMode));
        
    }
    if(m_DmlEffectsRenderingModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("DmlEffectsRenderingMode"), m_DmlEffectsRenderingMode));
        
    }
    if(m_ZipOutputIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("ZipOutput"), m_ZipOutput));
    }
    if(m_UpdateLastSavedTimePropertyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("UpdateLastSavedTimeProperty"), m_UpdateLastSavedTimeProperty));
    }
    if(m_UpdateSdtContentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("UpdateSdtContent"), m_UpdateSdtContent));
    }
    if(m_UpdateFieldsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("UpdateFields"), m_UpdateFields));
    }
    if(m_ImagesFolderIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("ImagesFolder"), m_ImagesFolder));
        
    }
    if(m_ImagesFolderAliasIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("ImagesFolderAlias"), m_ImagesFolderAlias));
        
    }
}

void XamlFlowSaveOptionsData::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("ColorMode")))
    {
        setColorMode(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("ColorMode"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("SaveFormat")))
    {
        setSaveFormat(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("SaveFormat"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("FileName")))
    {
        setFileName(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("FileName"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("DmlRenderingMode")))
    {
        setDmlRenderingMode(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("DmlRenderingMode"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("DmlEffectsRenderingMode")))
    {
        setDmlEffectsRenderingMode(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("DmlEffectsRenderingMode"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("ZipOutput")))
    {
        setZipOutput(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("ZipOutput"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("UpdateLastSavedTimeProperty")))
    {
        setUpdateLastSavedTimeProperty(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("UpdateLastSavedTimeProperty"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("UpdateSdtContent")))
    {
        setUpdateSdtContent(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("UpdateSdtContent"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("UpdateFields")))
    {
        setUpdateFields(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("UpdateFields"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("ImagesFolder")))
    {
        setImagesFolder(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("ImagesFolder"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("ImagesFolderAlias")))
    {
        setImagesFolderAlias(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("ImagesFolderAlias"))));
    }
}

utility::string_t XamlFlowSaveOptionsData::getImagesFolder() const
{
    return m_ImagesFolder;
}


void XamlFlowSaveOptionsData::setImagesFolder(utility::string_t value)
{
    m_ImagesFolder = value;
    m_ImagesFolderIsSet = true;
}
bool XamlFlowSaveOptionsData::imagesFolderIsSet() const
{
    return m_ImagesFolderIsSet;
}

void XamlFlowSaveOptionsData::unsetImagesFolder()
{
    m_ImagesFolderIsSet = false;
}

utility::string_t XamlFlowSaveOptionsData::getImagesFolderAlias() const
{
    return m_ImagesFolderAlias;
}


void XamlFlowSaveOptionsData::setImagesFolderAlias(utility::string_t value)
{
    m_ImagesFolderAlias = value;
    m_ImagesFolderAliasIsSet = true;
}
bool XamlFlowSaveOptionsData::imagesFolderAliasIsSet() const
{
    return m_ImagesFolderAliasIsSet;
}

void XamlFlowSaveOptionsData::unsetImagesFolderAlias()
{
    m_ImagesFolderAliasIsSet = false;
}

}
}
}
}

