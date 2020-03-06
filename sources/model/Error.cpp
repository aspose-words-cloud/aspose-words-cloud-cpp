/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Error.cpp">
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


#include "Error.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

Error::Error()
{
    m_Code = utility::conversions::to_string_t("");
    m_CodeIsSet = false;
    m_Message = utility::conversions::to_string_t("");
    m_MessageIsSet = false;
    m_Description = utility::conversions::to_string_t("");
    m_DescriptionIsSet = false;
    m_InnerErrorIsSet = false;
}

Error::~Error()
{
}

void Error::validate()
{
    // TODO: implement validation
}

web::json::value Error::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_CodeIsSet)
    {
        val[_XPLATSTR("Code")] = ModelBase::toJson(m_Code);
    }
    if(m_MessageIsSet)
    {
        val[_XPLATSTR("Message")] = ModelBase::toJson(m_Message);
    }
    if(m_DescriptionIsSet)
    {
        val[_XPLATSTR("Description")] = ModelBase::toJson(m_Description);
    }
    if(m_InnerErrorIsSet)
    {
        val[_XPLATSTR("InnerError")] = ModelBase::toJson(m_InnerError);
    }

    return val;
}

void Error::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("Code")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Code")];
        if(!fieldValue.is_null())
        {
            setCode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Message")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Message")];
        if(!fieldValue.is_null())
        {
            setMessage(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Description")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Description")];
        if(!fieldValue.is_null())
        {
            setDescription(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("InnerError")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("InnerError")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<ErrorDetails> newItem(new ErrorDetails());
            newItem->fromJson(fieldValue);
            setInnerError( newItem );
        }
    }
}

void Error::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_CodeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Code"), m_Code));
        
    }
    if(m_MessageIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Message"), m_Message));
        
    }
    if(m_DescriptionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Description"), m_Description));
        
    }
    if(m_InnerErrorIsSet)
    {
        if (m_InnerError.get())
        {
            m_InnerError->toMultipart(multipart, _XPLATSTR("InnerError."));
        }
        
    }
}

void Error::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    

    if(multipart->hasContent(_XPLATSTR("Code")))
    {
        setCode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Code"))));
    }
    if(multipart->hasContent(_XPLATSTR("Message")))
    {
        setMessage(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Message"))));
    }
    if(multipart->hasContent(_XPLATSTR("Description")))
    {
        setDescription(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Description"))));
    }
    if(multipart->hasContent(_XPLATSTR("InnerError")))
    {
        if(multipart->hasContent(_XPLATSTR("InnerError")))
        {
            std::shared_ptr<ErrorDetails> newItem(new ErrorDetails());
            newItem->fromMultiPart(multipart, _XPLATSTR("InnerError."));
            setInnerError( newItem );
        }
    }
}

utility::string_t Error::getCode() const
{
    return m_Code;
}


void Error::setCode(utility::string_t value)
{
    m_Code = value;
    m_CodeIsSet = true;
}
bool Error::codeIsSet() const
{
    return m_CodeIsSet;
}

void Error::unsetCode()
{
    m_CodeIsSet = false;
}

utility::string_t Error::getMessage() const
{
    return m_Message;
}


void Error::setMessage(utility::string_t value)
{
    m_Message = value;
    m_MessageIsSet = true;
}
bool Error::messageIsSet() const
{
    return m_MessageIsSet;
}

void Error::unsetMessage()
{
    m_MessageIsSet = false;
}

utility::string_t Error::getDescription() const
{
    return m_Description;
}


void Error::setDescription(utility::string_t value)
{
    m_Description = value;
    m_DescriptionIsSet = true;
}
bool Error::descriptionIsSet() const
{
    return m_DescriptionIsSet;
}

void Error::unsetDescription()
{
    m_DescriptionIsSet = false;
}

std::shared_ptr<ErrorDetails> Error::getInnerError() const
{
    return m_InnerError;
}


void Error::setInnerError(std::shared_ptr<ErrorDetails> value)
{
    m_InnerError = value;
    m_InnerErrorIsSet = true;
}
bool Error::innerErrorIsSet() const
{
    return m_InnerErrorIsSet;
}

void Error::unsetInnerError()
{
    m_InnerErrorIsSet = false;
}

}
}
}
}
}

