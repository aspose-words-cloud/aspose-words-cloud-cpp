/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="LoadWebDocumentData.cpp">
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


#include "LoadWebDocumentData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

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
        val[_XPLATSTR("LoadingDocumentUrl")] = ModelBase::toJson(m_LoadingDocumentUrl);
    }
    if(m_SaveOptionsIsSet)
    {
        val[_XPLATSTR("SaveOptions")] = ModelBase::toJson(m_SaveOptions);
    }

    return val;
}

void LoadWebDocumentData::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("LoadingDocumentUrl")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("LoadingDocumentUrl")];
        if(!fieldValue.is_null())
        {
            setLoadingDocumentUrl(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("SaveOptions")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SaveOptions")];
        if(!fieldValue.is_null())
        {
            <DATA_TYPE_START>SaveOptionsData<DATA_TYPE_END> newItem(new SaveOptionsData());
            newItem->fromJson(fieldValue);
            setSaveOptions( newItem );
        }
    }
}

void LoadWebDocumentData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_LoadingDocumentUrlIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("LoadingDocumentUrl"), m_LoadingDocumentUrl));
        
    }
    if(m_SaveOptionsIsSet)
    {
        if (m_SaveOptions.get())
        {
            m_SaveOptions->toMultipart(multipart, _XPLATSTR("SaveOptions."));
        }
        
    }
}

void LoadWebDocumentData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    

    if(multipart->hasContent(_XPLATSTR("LoadingDocumentUrl")))
    {
        setLoadingDocumentUrl(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("LoadingDocumentUrl"))));
    }
    if(multipart->hasContent(_XPLATSTR("SaveOptions")))
    {
        if(multipart->hasContent(_XPLATSTR("SaveOptions")))
        {
            <DATA_TYPE_START>SaveOptionsData<DATA_TYPE_END> newItem(new SaveOptionsData());
            newItem->fromMultiPart(multipart, _XPLATSTR("SaveOptions."));
            setSaveOptions( newItem );
        }
    }
}

<DATA_TYPE_START>string<DATA_TYPE_END> LoadWebDocumentData::getLoadingDocumentUrl() const
{
    return m_LoadingDocumentUrl;
}


void LoadWebDocumentData::setLoadingDocumentUrl(<DATA_TYPE_START>string<DATA_TYPE_END> value)
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

<DATA_TYPE_START>SaveOptionsData<DATA_TYPE_END> LoadWebDocumentData::getSaveOptions() const
{
    return m_SaveOptions;
}


void LoadWebDocumentData::setSaveOptions(<DATA_TYPE_START>SaveOptionsData<DATA_TYPE_END> value)
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
}

