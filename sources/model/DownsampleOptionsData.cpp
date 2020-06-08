/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DownsampleOptionsData.cpp">
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


#include "DownsampleOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

DownsampleOptionsData::DownsampleOptionsData()
{
    m_DownsampleImages = false;
    m_DownsampleImagesIsSet = false;
    m_Resolution = 0;
    m_ResolutionIsSet = false;
    m_ResolutionThreshold = 0;
    m_ResolutionThresholdIsSet = false;
}

DownsampleOptionsData::~DownsampleOptionsData()
{
}

void DownsampleOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value DownsampleOptionsData::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_DownsampleImagesIsSet)
    {
        val[_XPLATSTR("DownsampleImages")] = ModelBase::toJson(m_DownsampleImages);
    }
    if(m_ResolutionIsSet)
    {
        val[_XPLATSTR("Resolution")] = ModelBase::toJson(m_Resolution);
    }
    if(m_ResolutionThresholdIsSet)
    {
        val[_XPLATSTR("ResolutionThreshold")] = ModelBase::toJson(m_ResolutionThreshold);
    }

    return val;
}

void DownsampleOptionsData::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("DownsampleImages")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DownsampleImages")];
        if(!fieldValue.is_null())
        {
            setDownsampleImages(ModelBase::bool?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Resolution")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Resolution")];
        if(!fieldValue.is_null())
        {
            setResolution(ModelBase::int?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ResolutionThreshold")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ResolutionThreshold")];
        if(!fieldValue.is_null())
        {
            setResolutionThreshold(ModelBase::int?FromJson(fieldValue));
        }
    }
}

void DownsampleOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_DownsampleImagesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("DownsampleImages"), m_DownsampleImages));
        
    }
    if(m_ResolutionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Resolution"), m_Resolution));
        
    }
    if(m_ResolutionThresholdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ResolutionThreshold"), m_ResolutionThreshold));
        
    }
}

void DownsampleOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    

    if(multipart->hasContent(_XPLATSTR("DownsampleImages")))
    {
        setDownsampleImages(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("DownsampleImages"))));
    }
    if(multipart->hasContent(_XPLATSTR("Resolution")))
    {
        setResolution(ModelBase::int?FromHttpContent(multipart->getContent(_XPLATSTR("Resolution"))));
    }
    if(multipart->hasContent(_XPLATSTR("ResolutionThreshold")))
    {
        setResolutionThreshold(ModelBase::int?FromHttpContent(multipart->getContent(_XPLATSTR("ResolutionThreshold"))));
    }
}

<DATA_TYPE_START>bool?<DATA_TYPE_END> DownsampleOptionsData::isDownsampleImages() const
{
    return m_DownsampleImages;
}


void DownsampleOptionsData::setDownsampleImages(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
{
    m_DownsampleImages = value;
    m_DownsampleImagesIsSet = true;
}
bool DownsampleOptionsData::downsampleImagesIsSet() const
{
    return m_DownsampleImagesIsSet;
}

void DownsampleOptionsData::unsetDownsampleImages()
{
    m_DownsampleImagesIsSet = false;
}

<DATA_TYPE_START>int?<DATA_TYPE_END> DownsampleOptionsData::getResolution() const
{
    return m_Resolution;
}


void DownsampleOptionsData::setResolution(<DATA_TYPE_START>int?<DATA_TYPE_END> value)
{
    m_Resolution = value;
    m_ResolutionIsSet = true;
}
bool DownsampleOptionsData::resolutionIsSet() const
{
    return m_ResolutionIsSet;
}

void DownsampleOptionsData::unsetResolution()
{
    m_ResolutionIsSet = false;
}

<DATA_TYPE_START>int?<DATA_TYPE_END> DownsampleOptionsData::getResolutionThreshold() const
{
    return m_ResolutionThreshold;
}


void DownsampleOptionsData::setResolutionThreshold(<DATA_TYPE_START>int?<DATA_TYPE_END> value)
{
    m_ResolutionThreshold = value;
    m_ResolutionThresholdIsSet = true;
}
bool DownsampleOptionsData::resolutionThresholdIsSet() const
{
    return m_ResolutionThresholdIsSet;
}

void DownsampleOptionsData::unsetResolutionThreshold()
{
    m_ResolutionThresholdIsSet = false;
}

}
}
}
}
}

