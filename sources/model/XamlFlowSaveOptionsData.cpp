/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="XamlFlowSaveOptionsData.cpp">
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

#include "XamlFlowSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

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
        val[_XPLATSTR("ImagesFolder")] = ModelBase::toJson(m_ImagesFolder);
    }
    if(m_ImagesFolderAliasIsSet)
    {
        val[_XPLATSTR("ImagesFolderAlias")] = ModelBase::toJson(m_ImagesFolderAlias);
    }

    return val;
}

void XamlFlowSaveOptionsData::fromJson(web::json::value& val)
{
    this->SaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("ImagesFolder")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ImagesFolder")];
        if(!fieldValue.is_null())
        {
           setImagesFolder(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("ImagesFolderAlias")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ImagesFolderAlias")];
        if(!fieldValue.is_null())
        {
           setImagesFolderAlias(ModelBase::stringFromJson(fieldValue));
        }
    }

}

void XamlFlowSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    SaveOptionsData::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_ImagesFolderIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ImagesFolder"), m_ImagesFolder));
    }


    if(m_ImagesFolderAliasIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ImagesFolderAlias"), m_ImagesFolderAlias));
    }

}

void XamlFlowSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
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
}
