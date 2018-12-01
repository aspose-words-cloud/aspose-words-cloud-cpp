/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="WatermarkText.cpp">
*   Copyright (c) 2018 Aspose.Words for Cloud
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

namespace io {
namespace swagger {
namespace client {
namespace model {

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
        val[utility::conversions::to_string_t("Text")] = ModelBase::toJson(m_Text);
    }
    val[utility::conversions::to_string_t("RotationAngle")] = ModelBase::toJson(m_RotationAngle);

    return val;
}

void WatermarkText::fromJson(web::json::value& val)
{
    if(val.has_field(utility::conversions::to_string_t("Text")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Text")];
        if(!fieldValue.is_null())
        {
            setText(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("RotationAngle")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("RotationAngle")];
        if(!fieldValue.is_null())
        {
            setRotationAngle(ModelBase::doubleFromJson(fieldValue));
        }
    }
}

void WatermarkText::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_TextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Text"), m_Text));
        
    }
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("RotationAngle"), m_RotationAngle));
}

void WatermarkText::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("Text")))
    {
        setText(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Text"))));
    }
    setRotationAngle(ModelBase::doubleFromHttpContent(multipart->getContent(utility::conversions::to_string_t("RotationAngle"))));
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
