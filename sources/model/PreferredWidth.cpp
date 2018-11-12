/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PreferredWidth.cpp">
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


#include "PreferredWidth.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

PreferredWidth::PreferredWidth()
{
    m_Type = utility::conversions::to_string_t("");
    m_Value = 0.0;
    m_ValueIsSet = false;
}

PreferredWidth::~PreferredWidth()
{
}

void PreferredWidth::validate()
{
    // TODO: implement validation
}

web::json::value PreferredWidth::toJson() const
{
    web::json::value val = web::json::value::object();

    val[utility::conversions::to_string_t("Type")] = ModelBase::toJson(m_Type);
    if(m_ValueIsSet)
    {
        val[utility::conversions::to_string_t("Value")] = ModelBase::toJson(m_Value);
    }

    return val;
}

void PreferredWidth::fromJson(web::json::value& val)
{
    setType(ModelBase::stringFromJson(val[utility::conversions::to_string_t("Type")]));
    if(val.has_field(utility::conversions::to_string_t("Value")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Value")];
        if(!fieldValue.is_null())
        {
            setValue(ModelBase::doubleFromJson(fieldValue));
        }
    }
}

void PreferredWidth::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Type"), m_Type));
    if(m_ValueIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Value"), m_Value));
    }
}

void PreferredWidth::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    setType(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Type"))));
    if(multipart->hasContent(utility::conversions::to_string_t("Value")))
    {
        setValue(ModelBase::doubleFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Value"))));
    }
}

utility::string_t PreferredWidth::getType() const
{
    return m_Type;
}


void PreferredWidth::setType(utility::string_t value)
{
    m_Type = value;
    
}
double PreferredWidth::getValue() const
{
    return m_Value;
}


void PreferredWidth::setValue(double value)
{
    m_Value = value;
    m_ValueIsSet = true;
}
bool PreferredWidth::valueIsSet() const
{
    return m_ValueIsSet;
}

void PreferredWidth::unsetValue()
{
    m_ValueIsSet = false;
}

}
}
}
}

