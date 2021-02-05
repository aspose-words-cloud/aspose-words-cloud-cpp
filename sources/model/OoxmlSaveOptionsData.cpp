/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="OoxmlSaveOptionsData.cpp">
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

#include "OoxmlSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

OoxmlSaveOptionsData::OoxmlSaveOptionsData()
{
    m_Compliance = utility::conversions::to_string_t("");
    m_ComplianceIsSet = false;

    m_CompressionLevelIsSet = false;
    m_Password = utility::conversions::to_string_t("");
    m_PasswordIsSet = false;
    m_PrettyFormat = false;
    m_PrettyFormatIsSet = false;

}

OoxmlSaveOptionsData::~OoxmlSaveOptionsData()
{
}

void OoxmlSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value OoxmlSaveOptionsData::toJson() const
{
    web::json::value val = this->SaveOptionsData::toJson();
    if(m_ComplianceIsSet)
    {
        val[_XPLATSTR("Compliance")] = ModelBase::toJson(m_Compliance);
    }
    if(m_CompressionLevelIsSet)
    {
        val[_XPLATSTR("CompressionLevel")] = ModelBase::toJson(m_CompressionLevel);
    }
    if(m_PasswordIsSet)
    {
        val[_XPLATSTR("Password")] = ModelBase::toJson(m_Password);
    }
    if(m_PrettyFormatIsSet)
    {
        val[_XPLATSTR("PrettyFormat")] = ModelBase::toJson(m_PrettyFormat);
    }

    return val;
}

void OoxmlSaveOptionsData::fromJson(web::json::value& val)
{
    this->SaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("Compliance")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Compliance")];
        if(!fieldValue.is_null())
        {
           setCompliance(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("CompressionLevel")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("CompressionLevel")];
        if(!fieldValue.is_null())
        {
           setCompressionLevel(ModelBase::enumFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("Password")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Password")];
        if(!fieldValue.is_null())
        {
           setPassword(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("PrettyFormat")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("PrettyFormat")];
        if(!fieldValue.is_null())
        {
           setPrettyFormat(ModelBase::booleanFromJson(fieldValue));
        }
    }

}

void OoxmlSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    SaveOptionsData::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_ComplianceIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Compliance"), m_Compliance));
    }


    if(m_CompressionLevelIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("CompressionLevel"), m_CompressionLevel));
    }


    if(m_PasswordIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Password"), m_Password));
    }


    if(m_PrettyFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("PrettyFormat"), m_PrettyFormat));
    }

}

void OoxmlSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

utility::string_t OoxmlSaveOptionsData::getCompliance() const
{
    return m_Compliance;
}


void OoxmlSaveOptionsData::setCompliance(utility::string_t value)
{
    m_Compliance = value;
    m_ComplianceIsSet = true;
}

bool OoxmlSaveOptionsData::complianceIsSet() const
{
    return m_ComplianceIsSet;
}

void OoxmlSaveOptionsData::unsetCompliance()
{
    m_ComplianceIsSet = false;
}

utility::string_t OoxmlSaveOptionsData::getCompressionLevel() const
{
    return m_CompressionLevel;
}


void OoxmlSaveOptionsData::setCompressionLevel(utility::string_t value)
{
    m_CompressionLevel = value;
    m_CompressionLevelIsSet = true;
}

bool OoxmlSaveOptionsData::compressionLevelIsSet() const
{
    return m_CompressionLevelIsSet;
}

void OoxmlSaveOptionsData::unsetCompressionLevel()
{
    m_CompressionLevelIsSet = false;
}

utility::string_t OoxmlSaveOptionsData::getPassword() const
{
    return m_Password;
}


void OoxmlSaveOptionsData::setPassword(utility::string_t value)
{
    m_Password = value;
    m_PasswordIsSet = true;
}

bool OoxmlSaveOptionsData::passwordIsSet() const
{
    return m_PasswordIsSet;
}

void OoxmlSaveOptionsData::unsetPassword()
{
    m_PasswordIsSet = false;
}

bool OoxmlSaveOptionsData::isPrettyFormat() const
{
    return m_PrettyFormat;
}


void OoxmlSaveOptionsData::setPrettyFormat(bool value)
{
    m_PrettyFormat = value;
    m_PrettyFormatIsSet = true;
}

bool OoxmlSaveOptionsData::prettyFormatIsSet() const
{
    return m_PrettyFormatIsSet;
}

void OoxmlSaveOptionsData::unsetPrettyFormat()
{
    m_PrettyFormatIsSet = false;
}

}
}
}
}
}
