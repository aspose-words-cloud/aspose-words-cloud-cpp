/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ApiError.cpp">
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


#include "ApiError.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

ApiError::ApiError()
{
    m_Code = utility::conversions::to_string_t("");
    m_CodeIsSet = false;
    m_Message = utility::conversions::to_string_t("");
    m_MessageIsSet = false;
    m_Description = utility::conversions::to_string_t("");
    m_DescriptionIsSet = false;
    m_DateTime = utility::datetime();
    m_DateTimeIsSet = false;
    m_InnerErrorIsSet = false;
}

ApiError::~ApiError()
{
}

void ApiError::validate()
{
    // TODO: implement validation
}

web::json::value ApiError::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_CodeIsSet)
    {
        val[_XPLATSTR("code")] = ModelBase::toJson(m_Code);
    }
    if(m_MessageIsSet)
    {
        val[_XPLATSTR("message")] = ModelBase::toJson(m_Message);
    }
    if(m_DescriptionIsSet)
    {
        val[_XPLATSTR("description")] = ModelBase::toJson(m_Description);
    }
    if(m_DateTimeIsSet)
    {
        val[_XPLATSTR("dateTime")] = ModelBase::toJson(m_DateTime);
    }
    if(m_InnerErrorIsSet)
    {
        val[_XPLATSTR("innerError")] = ModelBase::toJson(m_InnerError);
    }

    return val;
}

void ApiError::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("code")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("code")];
        if(!fieldValue.is_null())
        {
            setCode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("message")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("message")];
        if(!fieldValue.is_null())
        {
            setMessage(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("description")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("description")];
        if(!fieldValue.is_null())
        {
            setDescription(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("dateTime")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("dateTime")];
        if(!fieldValue.is_null())
        {
            setDateTime(ModelBase::dateFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("innerError")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("innerError")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<ApiError> newItem(new ApiError());
            newItem->fromJson(fieldValue);
            setInnerError( newItem );
        }
    }
}

void ApiError::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_CodeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("code"), m_Code));
        
    }
    if(m_MessageIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("message"), m_Message));
        
    }
    if(m_DescriptionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("description"), m_Description));
        
    }
    if(m_DateTimeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("dateTime"), m_DateTime));
        
    }
    if(m_InnerErrorIsSet)
    {
        if (m_InnerError.get())
        {
            m_InnerError->toMultipart(multipart, _XPLATSTR("innerError."));
        }
        
    }
}

void ApiError::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("code")))
    {
        setCode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("code"))));
    }
    if(multipart->hasContent(_XPLATSTR("message")))
    {
        setMessage(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("message"))));
    }
    if(multipart->hasContent(_XPLATSTR("description")))
    {
        setDescription(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("description"))));
    }
    if(multipart->hasContent(_XPLATSTR("dateTime")))
    {
        setDateTime(ModelBase::dateFromHttpContent(multipart->getContent(_XPLATSTR("dateTime"))));
    }
    if(multipart->hasContent(_XPLATSTR("innerError")))
    {
        if(multipart->hasContent(_XPLATSTR("innerError")))
        {
            std::shared_ptr<ApiError> newItem(new ApiError());
            newItem->fromMultiPart(multipart, _XPLATSTR("innerError."));
            setInnerError( newItem );
        }
    }
}

utility::string_t ApiError::getCode() const
{
    return m_Code;
}


void ApiError::setCode(utility::string_t value)
{
    m_Code = value;
    m_CodeIsSet = true;
}
bool ApiError::codeIsSet() const
{
    return m_CodeIsSet;
}

void ApiError::unsetCode()
{
    m_CodeIsSet = false;
}

utility::string_t ApiError::getMessage() const
{
    return m_Message;
}


void ApiError::setMessage(utility::string_t value)
{
    m_Message = value;
    m_MessageIsSet = true;
}
bool ApiError::messageIsSet() const
{
    return m_MessageIsSet;
}

void ApiError::unsetMessage()
{
    m_MessageIsSet = false;
}

utility::string_t ApiError::getDescription() const
{
    return m_Description;
}


void ApiError::setDescription(utility::string_t value)
{
    m_Description = value;
    m_DescriptionIsSet = true;
}
bool ApiError::descriptionIsSet() const
{
    return m_DescriptionIsSet;
}

void ApiError::unsetDescription()
{
    m_DescriptionIsSet = false;
}

utility::datetime ApiError::getDateTime() const
{
    return m_DateTime;
}


void ApiError::setDateTime(utility::datetime value)
{
    m_DateTime = value;
    m_DateTimeIsSet = true;
}
bool ApiError::dateTimeIsSet() const
{
    return m_DateTimeIsSet;
}

void ApiError::unsetDateTime()
{
    m_DateTimeIsSet = false;
}

std::shared_ptr<ApiError> ApiError::getInnerError() const
{
    return m_InnerError;
}


void ApiError::setInnerError(std::shared_ptr<ApiError> value)
{
    m_InnerError = value;
    m_InnerErrorIsSet = true;
}
bool ApiError::innerErrorIsSet() const
{
    return m_InnerErrorIsSet;
}

void ApiError::unsetInnerError()
{
    m_InnerErrorIsSet = false;
}

}
}
}
}
}

