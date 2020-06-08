/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="MhtmlSaveOptionsData.cpp">
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


#include "MhtmlSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

MhtmlSaveOptionsData::MhtmlSaveOptionsData()
{
    m_ExportCidUrlsForMhtmlResources = false;
    m_ExportCidUrlsForMhtmlResourcesIsSet = false;
}

MhtmlSaveOptionsData::~MhtmlSaveOptionsData()
{
}

void MhtmlSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value MhtmlSaveOptionsData::toJson() const
{
    web::json::value val = this->HtmlSaveOptionsData::toJson();

    if(m_ExportCidUrlsForMhtmlResourcesIsSet)
    {
        val[_XPLATSTR("ExportCidUrlsForMhtmlResources")] = ModelBase::toJson(m_ExportCidUrlsForMhtmlResources);
    }

    return val;
}

void MhtmlSaveOptionsData::fromJson(web::json::value& val)
{
    this->HtmlSaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("ExportCidUrlsForMhtmlResources")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportCidUrlsForMhtmlResources")];
        if(!fieldValue.is_null())
        {
            setExportCidUrlsForMhtmlResources(ModelBase::bool?FromJson(fieldValue));
        }
    }
}

void MhtmlSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    HtmlSaveOptionsData::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_ExportCidUrlsForMhtmlResourcesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportCidUrlsForMhtmlResources"), m_ExportCidUrlsForMhtmlResources));
        
    }
}

void MhtmlSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    HtmlSaveOptionsData::fromMultiPart(multipart, prefix);

    if(multipart->hasContent(_XPLATSTR("ExportCidUrlsForMhtmlResources")))
    {
        setExportCidUrlsForMhtmlResources(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("ExportCidUrlsForMhtmlResources"))));
    }
}

<DATA_TYPE_START>bool?<DATA_TYPE_END> MhtmlSaveOptionsData::isExportCidUrlsForMhtmlResources() const
{
    return m_ExportCidUrlsForMhtmlResources;
}


void MhtmlSaveOptionsData::setExportCidUrlsForMhtmlResources(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
{
    m_ExportCidUrlsForMhtmlResources = value;
    m_ExportCidUrlsForMhtmlResourcesIsSet = true;
}
bool MhtmlSaveOptionsData::exportCidUrlsForMhtmlResourcesIsSet() const
{
    return m_ExportCidUrlsForMhtmlResourcesIsSet;
}

void MhtmlSaveOptionsData::unsetExportCidUrlsForMhtmlResources()
{
    m_ExportCidUrlsForMhtmlResourcesIsSet = false;
}

}
}
}
}
}

