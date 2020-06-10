/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FormFieldTextInput.cpp">
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

#include "FormFieldTextInput.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

FormFieldTextInput::FormFieldTextInput()
{
    m_MaxLength = 0;
    m_MaxLengthIsSet = false;
    m_TextInputDefault = utility::conversions::to_string_t("");
    m_TextInputDefaultIsSet = false;
    m_TextInputFormat = utility::conversions::to_string_t("");
    m_TextInputFormatIsSet = false;

    m_TextInputTypeIsSet = false;

}

FormFieldTextInput::~FormFieldTextInput()
{
}

void FormFieldTextInput::validate()
{
    // TODO: implement validation
}

web::json::value FormFieldTextInput::toJson() const
{
    web::json::value val = this->FormField::toJson();
    if(m_MaxLengthIsSet)
    {
        val[_XPLATSTR("MaxLength")] = ModelBase::toJson(m_MaxLength);
    }
    if(m_TextInputDefaultIsSet)
    {
        val[_XPLATSTR("TextInputDefault")] = ModelBase::toJson(m_TextInputDefault);
    }
    if(m_TextInputFormatIsSet)
    {
        val[_XPLATSTR("TextInputFormat")] = ModelBase::toJson(m_TextInputFormat);
    }
    if(m_TextInputTypeIsSet)
    {
        val[_XPLATSTR("TextInputType")] = ModelBase::toJson(m_TextInputType);
    }

    return val;
}

void FormFieldTextInput::fromJson(web::json::value& val)
{
    this->FormField::fromJson(val);

    if(val.has_field(_XPLATSTR("MaxLength")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("MaxLength")];
        if(!fieldValue.is_null())
        {
           setMaxLength(ModelBase::integerFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("TextInputDefault")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("TextInputDefault")];
        if(!fieldValue.is_null())
        {
           setTextInputDefault(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("TextInputFormat")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("TextInputFormat")];
        if(!fieldValue.is_null())
        {
           setTextInputFormat(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("TextInputType")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("TextInputType")];
        if(!fieldValue.is_null())
        {
           setTextInputType(ModelBase::enumFromJson(fieldValue));
        }
    }

}

void FormFieldTextInput::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    FormField::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_MaxLengthIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("MaxLength"), m_MaxLength));
    }


    if(m_TextInputDefaultIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TextInputDefault"), m_TextInputDefault));
    }


    if(m_TextInputFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TextInputFormat"), m_TextInputFormat));
    }


    if(m_TextInputTypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TextInputType"), m_TextInputType));
    }

}

void FormFieldTextInput::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

int32_t FormFieldTextInput::getMaxLength() const
{
    return m_MaxLength;
}


void FormFieldTextInput::setMaxLength(int32_t value)
{
    m_MaxLength = value;
    m_MaxLengthIsSet = true;
}

bool FormFieldTextInput::maxLengthIsSet() const
{
    return m_MaxLengthIsSet;
}

void FormFieldTextInput::unsetMaxLength()
{
    m_MaxLengthIsSet = false;
}

utility::string_t FormFieldTextInput::getTextInputDefault() const
{
    return m_TextInputDefault;
}


void FormFieldTextInput::setTextInputDefault(utility::string_t value)
{
    m_TextInputDefault = value;
    m_TextInputDefaultIsSet = true;
}

bool FormFieldTextInput::textInputDefaultIsSet() const
{
    return m_TextInputDefaultIsSet;
}

void FormFieldTextInput::unsetTextInputDefault()
{
    m_TextInputDefaultIsSet = false;
}

utility::string_t FormFieldTextInput::getTextInputFormat() const
{
    return m_TextInputFormat;
}


void FormFieldTextInput::setTextInputFormat(utility::string_t value)
{
    m_TextInputFormat = value;
    m_TextInputFormatIsSet = true;
}

bool FormFieldTextInput::textInputFormatIsSet() const
{
    return m_TextInputFormatIsSet;
}

void FormFieldTextInput::unsetTextInputFormat()
{
    m_TextInputFormatIsSet = false;
}

utility::string_t FormFieldTextInput::getTextInputType() const
{
    return m_TextInputType;
}


void FormFieldTextInput::setTextInputType(utility::string_t value)
{
    m_TextInputType = value;
    m_TextInputTypeIsSet = true;
}

bool FormFieldTextInput::textInputTypeIsSet() const
{
    return m_TextInputTypeIsSet;
}

void FormFieldTextInput::unsetTextInputType()
{
    m_TextInputTypeIsSet = false;
}

}
}
}
}
}
