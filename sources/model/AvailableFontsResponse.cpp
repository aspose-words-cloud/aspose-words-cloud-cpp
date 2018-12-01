/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="AvailableFontsResponse.cpp">
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


#include "AvailableFontsResponse.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

AvailableFontsResponse::AvailableFontsResponse()
{
    m_AdditionalFontsIsSet = false;
    m_CustomFontsIsSet = false;
    m_SystemFontsIsSet = false;
}

AvailableFontsResponse::~AvailableFontsResponse()
{
}

void AvailableFontsResponse::validate()
{
    // TODO: implement validation
}

web::json::value AvailableFontsResponse::toJson() const
{
    web::json::value val = this->AsposeResponse::toJson();

    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_AdditionalFonts )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        if(jsonArray.size() > 0)
        {
            val[utility::conversions::to_string_t("AdditionalFonts")] = web::json::value::array(jsonArray);
        }
    }
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_CustomFonts )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        if(jsonArray.size() > 0)
        {
            val[utility::conversions::to_string_t("CustomFonts")] = web::json::value::array(jsonArray);
        }
    }
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_SystemFonts )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        if(jsonArray.size() > 0)
        {
            val[utility::conversions::to_string_t("SystemFonts")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void AvailableFontsResponse::fromJson(web::json::value& val)
{
    this->AsposeResponse::fromJson(val);

    {
        m_AdditionalFonts.clear();
        std::vector<web::json::value> jsonArray;
        if(val.has_field(utility::conversions::to_string_t("AdditionalFonts")) 
                            && !val[utility::conversions::to_string_t("AdditionalFonts")].is_null())
        {
        for( auto& item : val[utility::conversions::to_string_t("AdditionalFonts")].as_array() )
        {
            if(item.is_null())
            {
                m_AdditionalFonts.push_back( std::shared_ptr<FontInfo>(nullptr) );
            }
            else
            {
                std::shared_ptr<FontInfo> newItem(new FontInfo());
                newItem->fromJson(item);
                m_AdditionalFonts.push_back( newItem );
            }
        }
        }
    }
    {
        m_CustomFonts.clear();
        std::vector<web::json::value> jsonArray;
        if(val.has_field(utility::conversions::to_string_t("CustomFonts")) 
                            && !val[utility::conversions::to_string_t("CustomFonts")].is_null())
        {
        for( auto& item : val[utility::conversions::to_string_t("CustomFonts")].as_array() )
        {
            if(item.is_null())
            {
                m_CustomFonts.push_back( std::shared_ptr<FontInfo>(nullptr) );
            }
            else
            {
                std::shared_ptr<FontInfo> newItem(new FontInfo());
                newItem->fromJson(item);
                m_CustomFonts.push_back( newItem );
            }
        }
        }
    }
    {
        m_SystemFonts.clear();
        std::vector<web::json::value> jsonArray;
        if(val.has_field(utility::conversions::to_string_t("SystemFonts")) 
                            && !val[utility::conversions::to_string_t("SystemFonts")].is_null())
        {
        for( auto& item : val[utility::conversions::to_string_t("SystemFonts")].as_array() )
        {
            if(item.is_null())
            {
                m_SystemFonts.push_back( std::shared_ptr<FontInfo>(nullptr) );
            }
            else
            {
                std::shared_ptr<FontInfo> newItem(new FontInfo());
                newItem->fromJson(item);
                m_SystemFonts.push_back( newItem );
            }
        }
        }
    }
}

void AvailableFontsResponse::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Code"), m_Code));
    if(m_StatusIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Status"), m_Status));
        
    }
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_AdditionalFonts )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("AdditionalFonts"), web::json::value::array(jsonArray), utility::conversions::to_string_t("application/json")));
        }
    }
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_CustomFonts )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("CustomFonts"), web::json::value::array(jsonArray), utility::conversions::to_string_t("application/json")));
        }
    }
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_SystemFonts )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("SystemFonts"), web::json::value::array(jsonArray), utility::conversions::to_string_t("application/json")));
        }
    }
}

void AvailableFontsResponse::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    setCode(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Code"))));
    if(multipart->hasContent(utility::conversions::to_string_t("Status")))
    {
        setStatus(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Status"))));
    }
    {
        m_AdditionalFonts.clear();
        if(multipart->hasContent(utility::conversions::to_string_t("AdditionalFonts")))
        {

        web::json::value jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("AdditionalFonts"))));
        for( auto& item : jsonArray.as_array() )
        {
            if(item.is_null())
            {
                m_AdditionalFonts.push_back( std::shared_ptr<FontInfo>(nullptr) );
            }
            else
            {
                std::shared_ptr<FontInfo> newItem(new FontInfo());
                newItem->fromJson(item);
                m_AdditionalFonts.push_back( newItem );
            }
        }
        }
    }
    {
        m_CustomFonts.clear();
        if(multipart->hasContent(utility::conversions::to_string_t("CustomFonts")))
        {

        web::json::value jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("CustomFonts"))));
        for( auto& item : jsonArray.as_array() )
        {
            if(item.is_null())
            {
                m_CustomFonts.push_back( std::shared_ptr<FontInfo>(nullptr) );
            }
            else
            {
                std::shared_ptr<FontInfo> newItem(new FontInfo());
                newItem->fromJson(item);
                m_CustomFonts.push_back( newItem );
            }
        }
        }
    }
    {
        m_SystemFonts.clear();
        if(multipart->hasContent(utility::conversions::to_string_t("SystemFonts")))
        {

        web::json::value jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("SystemFonts"))));
        for( auto& item : jsonArray.as_array() )
        {
            if(item.is_null())
            {
                m_SystemFonts.push_back( std::shared_ptr<FontInfo>(nullptr) );
            }
            else
            {
                std::shared_ptr<FontInfo> newItem(new FontInfo());
                newItem->fromJson(item);
                m_SystemFonts.push_back( newItem );
            }
        }
        }
    }
}

std::vector<std::shared_ptr<FontInfo>>& AvailableFontsResponse::getAdditionalFonts()
{
    return m_AdditionalFonts;
}

void AvailableFontsResponse::setAdditionalFonts(std::vector<std::shared_ptr<FontInfo>> value)
{
    m_AdditionalFonts = value;
    m_AdditionalFontsIsSet = true;
}
bool AvailableFontsResponse::additionalFontsIsSet() const
{
    return m_AdditionalFontsIsSet;
}

void AvailableFontsResponse::unsetAdditionalFonts()
{
    m_AdditionalFontsIsSet = false;
}

std::vector<std::shared_ptr<FontInfo>>& AvailableFontsResponse::getCustomFonts()
{
    return m_CustomFonts;
}

void AvailableFontsResponse::setCustomFonts(std::vector<std::shared_ptr<FontInfo>> value)
{
    m_CustomFonts = value;
    m_CustomFontsIsSet = true;
}
bool AvailableFontsResponse::customFontsIsSet() const
{
    return m_CustomFontsIsSet;
}

void AvailableFontsResponse::unsetCustomFonts()
{
    m_CustomFontsIsSet = false;
}

std::vector<std::shared_ptr<FontInfo>>& AvailableFontsResponse::getSystemFonts()
{
    return m_SystemFonts;
}

void AvailableFontsResponse::setSystemFonts(std::vector<std::shared_ptr<FontInfo>> value)
{
    m_SystemFonts = value;
    m_SystemFontsIsSet = true;
}
bool AvailableFontsResponse::systemFontsIsSet() const
{
    return m_SystemFontsIsSet;
}

void AvailableFontsResponse::unsetSystemFonts()
{
    m_SystemFontsIsSet = false;
}

}
}
}
}

