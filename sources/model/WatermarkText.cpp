/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="WatermarkText.cpp">
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


#include "WatermarkText.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

WatermarkText::WatermarkText()
{
    m_Text = utility::conversions::to_string_t("");
    m_TextIsSet = false;
    m_RotationAngle = 0.0;
}

WatermarkText::~WatermarkText()
{
}

void WatermarkText::validate()
{
    // TODO: implement validation
}

web::json::value WatermarkText::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_TextIsSet)
    {
        val[_XPLATSTR("text")] = ModelBase::toJson(m_Text);
    }
    val[_XPLATSTR("rotationAngle")] = ModelBase::toJson(m_RotationAngle);

    return val;
}

void WatermarkText::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("text")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("text")];
        if(!fieldValue.is_null())
        {
            setText(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("rotationAngle")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("rotationAngle")];
        if(!fieldValue.is_null())
        {
            setRotationAngle(ModelBase::doubleFromJson(fieldValue));
        }
    }
}

void WatermarkText::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_TextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("text"), m_Text));
        
    }
    multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("rotationAngle"), m_RotationAngle));
}

void WatermarkText::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("text")))
    {
        setText(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("text"))));
    }
    setRotationAngle(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("rotationAngle"))));
}

utility::string_t WatermarkText::getText() const
{
    return m_Text;
}


void WatermarkText::setText(utility::string_t value)
{
    m_Text = value;
    m_TextIsSet = true;
}
bool WatermarkText::textIsSet() const
{
    return m_TextIsSet;
}

void WatermarkText::unsetText()
{
    m_TextIsSet = false;
}

double WatermarkText::getRotationAngle() const
{
    return m_RotationAngle;
}


void WatermarkText::setRotationAngle(double value)
{
    m_RotationAngle = value;
    
}
}
}
}
}
}

