/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="LoadWebDocumentData.cpp">
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


#include "LoadWebDocumentData.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

LoadWebDocumentData::LoadWebDocumentData()
{
    m_LoadingDocumentUrl = utility::conversions::to_string_t("");
    m_LoadingDocumentUrlIsSet = false;
    m_SaveOptionsIsSet = false;
}

LoadWebDocumentData::~LoadWebDocumentData()
{
}

void LoadWebDocumentData::validate()
{
    // TODO: implement validation
}

web::json::value LoadWebDocumentData::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_LoadingDocumentUrlIsSet)
    {
        val[utility::conversions::to_string_t("LoadingDocumentUrl")] = ModelBase::toJson(m_LoadingDocumentUrl);
    }
    if(m_SaveOptionsIsSet)
    {
        val[utility::conversions::to_string_t("SaveOptions")] = ModelBase::toJson(m_SaveOptions);
    }

    return val;
}

void LoadWebDocumentData::fromJson(web::json::value& val)
{
    if(val.has_field(utility::conversions::to_string_t("LoadingDocumentUrl")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("LoadingDocumentUrl")];
        if(!fieldValue.is_null())
        {
            setLoadingDocumentUrl(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("SaveOptions")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("SaveOptions")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<SaveOptionsData> newItem(new SaveOptionsData());
            newItem->fromJson(fieldValue);
            setSaveOptions( newItem );
        }
    }
}

void LoadWebDocumentData::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_LoadingDocumentUrlIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("LoadingDocumentUrl"), m_LoadingDocumentUrl));
        
    }
    if(m_SaveOptionsIsSet)
    {
        if (m_SaveOptions.get())
        {
            m_SaveOptions->toMultipart(multipart, utility::conversions::to_string_t("SaveOptions."));
        }
        
    }
}

void LoadWebDocumentData::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("LoadingDocumentUrl")))
    {
        setLoadingDocumentUrl(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("LoadingDocumentUrl"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("SaveOptions")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("SaveOptions")))
        {
            std::shared_ptr<SaveOptionsData> newItem(new SaveOptionsData());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("SaveOptions."));
            setSaveOptions( newItem );
        }
    }
}

utility::string_t LoadWebDocumentData::getLoadingDocumentUrl() const
{
    return m_LoadingDocumentUrl;
}


void LoadWebDocumentData::setLoadingDocumentUrl(utility::string_t value)
{
    m_LoadingDocumentUrl = value;
    m_LoadingDocumentUrlIsSet = true;
}
bool LoadWebDocumentData::loadingDocumentUrlIsSet() const
{
    return m_LoadingDocumentUrlIsSet;
}

void LoadWebDocumentData::unsetLoadingDocumentUrl()
{
    m_LoadingDocumentUrlIsSet = false;
}

std::shared_ptr<SaveOptionsData> LoadWebDocumentData::getSaveOptions() const
{
    return m_SaveOptions;
}


void LoadWebDocumentData::setSaveOptions(std::shared_ptr<SaveOptionsData> value)
{
    m_SaveOptions = value;
    m_SaveOptionsIsSet = true;
}
bool LoadWebDocumentData::saveOptionsIsSet() const
{
    return m_SaveOptionsIsSet;
}

void LoadWebDocumentData::unsetSaveOptions()
{
    m_SaveOptionsIsSet = false;
}

}
}
}
}

