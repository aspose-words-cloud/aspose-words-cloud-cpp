/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="XamlFixedSaveOptionsData.cpp">
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

#include "XamlFixedSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

XamlFixedSaveOptionsData::XamlFixedSaveOptionsData()
{
    m_ResourcesFolder = utility::conversions::to_string_t("");
    m_ResourcesFolderIsSet = false;
    m_ResourcesFolderAlias = utility::conversions::to_string_t("");
    m_ResourcesFolderAliasIsSet = false;

}

XamlFixedSaveOptionsData::~XamlFixedSaveOptionsData()
{
}

void XamlFixedSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value XamlFixedSaveOptionsData::toJson() const
{
    web::json::value val = this->FixedPageSaveOptionsData::toJson();
    if(m_ResourcesFolderIsSet)
    {
        val[_XPLATSTR("ResourcesFolder")] = ModelBase::toJson(m_ResourcesFolder);
    }
    if(m_ResourcesFolderAliasIsSet)
    {
        val[_XPLATSTR("ResourcesFolderAlias")] = ModelBase::toJson(m_ResourcesFolderAlias);
    }

    return val;
}

void XamlFixedSaveOptionsData::fromJson(web::json::value& val)
{
    this->FixedPageSaveOptionsData::fromJson(val);

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

}

void XamlFixedSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    FixedPageSaveOptionsData::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_ResourcesFolderIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ResourcesFolder"), m_ResourcesFolder));
    }


    if(m_ResourcesFolderAliasIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ResourcesFolderAlias"), m_ResourcesFolderAlias));
    }

}

void XamlFixedSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

utility::string_t XamlFixedSaveOptionsData::getResourcesFolder() const
{
    return m_ResourcesFolder;
}


void XamlFixedSaveOptionsData::setResourcesFolder(utility::string_t value)
{
    m_ResourcesFolder = value;
    m_ResourcesFolderIsSet = true;
}

bool XamlFixedSaveOptionsData::resourcesFolderIsSet() const
{
    return m_ResourcesFolderIsSet;
}

void XamlFixedSaveOptionsData::unsetResourcesFolder()
{
    m_ResourcesFolderIsSet = false;
}

utility::string_t XamlFixedSaveOptionsData::getResourcesFolderAlias() const
{
    return m_ResourcesFolderAlias;
}


void XamlFixedSaveOptionsData::setResourcesFolderAlias(utility::string_t value)
{
    m_ResourcesFolderAlias = value;
    m_ResourcesFolderAliasIsSet = true;
}

bool XamlFixedSaveOptionsData::resourcesFolderAliasIsSet() const
{
    return m_ResourcesFolderAliasIsSet;
}

void XamlFixedSaveOptionsData::unsetResourcesFolderAlias()
{
    m_ResourcesFolderAliasIsSet = false;
}

}
}
}
}
}
