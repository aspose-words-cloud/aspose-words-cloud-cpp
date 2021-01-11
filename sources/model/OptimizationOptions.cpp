/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="OptimizationOptions.cpp">
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

#include "OptimizationOptions.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

OptimizationOptions::OptimizationOptions()
{
    m_MsWordVersionIsSet = false;

}

OptimizationOptions::~OptimizationOptions()
{
}

void OptimizationOptions::validate()
{
    // TODO: implement validation
}

web::json::value OptimizationOptions::toJson() const
{
    web::json::value val = web::json::value::object();
    if(m_MsWordVersionIsSet)
    {
        val[_XPLATSTR("MsWordVersion")] = ModelBase::toJson(m_MsWordVersion);
    }

    return val;
}

void OptimizationOptions::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("MsWordVersion")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("MsWordVersion")];
        if(!fieldValue.is_null())
        {
           setMsWordVersion(ModelBase::enumFromJson(fieldValue));
        }
    }

}

void OptimizationOptions::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_MsWordVersionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("MsWordVersion"), m_MsWordVersion));
    }

}

void OptimizationOptions::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

utility::string_t OptimizationOptions::getMsWordVersion() const
{
    return m_MsWordVersion;
}


void OptimizationOptions::setMsWordVersion(utility::string_t value)
{
    m_MsWordVersion = value;
    m_MsWordVersionIsSet = true;
}

bool OptimizationOptions::msWordVersionIsSet() const
{
    return m_MsWordVersionIsSet;
}

void OptimizationOptions::unsetMsWordVersion()
{
    m_MsWordVersionIsSet = false;
}

}
}
}
}
}
