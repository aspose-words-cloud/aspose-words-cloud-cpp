/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="OdtSaveOptionsData.cpp">
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

#include "OdtSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

OdtSaveOptionsData::OdtSaveOptionsData()
{
    m_IsStrictSchema11 = false;
    m_IsStrictSchema11IsSet = false;

    m_MeasureUnitIsSet = false;
    m_Password = utility::conversions::to_string_t("");
    m_PasswordIsSet = false;
    m_PrettyFormat = false;
    m_PrettyFormatIsSet = false;

}

OdtSaveOptionsData::~OdtSaveOptionsData()
{
}

void OdtSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value OdtSaveOptionsData::toJson() const
{
    web::json::value val = this->SaveOptionsData::toJson();
    if(m_IsStrictSchema11IsSet)
    {
        val[_XPLATSTR("IsStrictSchema11")] = ModelBase::toJson(m_IsStrictSchema11);
    }
    if(m_MeasureUnitIsSet)
    {
        val[_XPLATSTR("MeasureUnit")] = ModelBase::toJson(m_MeasureUnit);
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

void OdtSaveOptionsData::fromJson(web::json::value& val)
{
    this->SaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("IsStrictSchema11")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("IsStrictSchema11")];
        if(!fieldValue.is_null())
        {
           setIsStrictSchema11(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("MeasureUnit")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("MeasureUnit")];
        if(!fieldValue.is_null())
        {
           setMeasureUnit(ModelBase::enumFromJson(fieldValue));
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

void OdtSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    SaveOptionsData::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_IsStrictSchema11IsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("IsStrictSchema11"), m_IsStrictSchema11));
    }


    if(m_MeasureUnitIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("MeasureUnit"), m_MeasureUnit));
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

void OdtSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

bool OdtSaveOptionsData::isIsStrictSchema11() const
{
    return m_IsStrictSchema11;
}


void OdtSaveOptionsData::setIsStrictSchema11(bool value)
{
    m_IsStrictSchema11 = value;
    m_IsStrictSchema11IsSet = true;
}

bool OdtSaveOptionsData::isStrictSchema11IsSet() const
{
    return m_IsStrictSchema11IsSet;
}

void OdtSaveOptionsData::unsetIsStrictSchema11()
{
    m_IsStrictSchema11IsSet = false;
}

utility::string_t OdtSaveOptionsData::getMeasureUnit() const
{
    return m_MeasureUnit;
}


void OdtSaveOptionsData::setMeasureUnit(utility::string_t value)
{
    m_MeasureUnit = value;
    m_MeasureUnitIsSet = true;
}

bool OdtSaveOptionsData::measureUnitIsSet() const
{
    return m_MeasureUnitIsSet;
}

void OdtSaveOptionsData::unsetMeasureUnit()
{
    m_MeasureUnitIsSet = false;
}

utility::string_t OdtSaveOptionsData::getPassword() const
{
    return m_Password;
}


void OdtSaveOptionsData::setPassword(utility::string_t value)
{
    m_Password = value;
    m_PasswordIsSet = true;
}

bool OdtSaveOptionsData::passwordIsSet() const
{
    return m_PasswordIsSet;
}

void OdtSaveOptionsData::unsetPassword()
{
    m_PasswordIsSet = false;
}

bool OdtSaveOptionsData::isPrettyFormat() const
{
    return m_PrettyFormat;
}


void OdtSaveOptionsData::setPrettyFormat(bool value)
{
    m_PrettyFormat = value;
    m_PrettyFormatIsSet = true;
}

bool OdtSaveOptionsData::prettyFormatIsSet() const
{
    return m_PrettyFormatIsSet;
}

void OdtSaveOptionsData::unsetPrettyFormat()
{
    m_PrettyFormatIsSet = false;
}

}
}
}
}
}
