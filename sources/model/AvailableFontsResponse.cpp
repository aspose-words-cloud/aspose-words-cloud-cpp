/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="AvailableFontsResponse.cpp">
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


#include "AvailableFontsResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

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
    web::json::value val = this->WordsResponse::toJson();

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_AdditionalFonts.begin(), m_AdditionalFonts.end(), std::back_inserter(jsonArray),
			[&](std::shared_ptr<FontInfo> item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("AdditionalFonts")] = web::json::value::array(jsonArray);
        }
    }
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_CustomFonts.begin(), m_CustomFonts.end(), std::back_inserter(jsonArray),
			[&](std::shared_ptr<FontInfo> item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("CustomFonts")] = web::json::value::array(jsonArray);
        }
    }
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_SystemFonts.begin(), m_SystemFonts.end(), std::back_inserter(jsonArray),
			[&](std::shared_ptr<FontInfo> item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("SystemFonts")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void AvailableFontsResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    {
        m_AdditionalFonts.clear();
        if(val.has_field(_XPLATSTR("AdditionalFonts")) 
                            && !val[_XPLATSTR("AdditionalFonts")].is_null())
        {
        auto arr = val[_XPLATSTR("AdditionalFonts")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_AdditionalFonts), [&](web::json::value& item){
            if(item.is_null())
            {
                return std::shared_ptr<FontInfo>(nullptr);
            }
            else
            {
                std::shared_ptr<FontInfo> newItem(new FontInfo());
                newItem->fromJson(item);
                return newItem;
            }
        });

        }
    }
    {
        m_CustomFonts.clear();
        if(val.has_field(_XPLATSTR("CustomFonts")) 
                            && !val[_XPLATSTR("CustomFonts")].is_null())
        {
        auto arr = val[_XPLATSTR("CustomFonts")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_CustomFonts), [&](web::json::value& item){
            if(item.is_null())
            {
                return std::shared_ptr<FontInfo>(nullptr);
            }
            else
            {
                std::shared_ptr<FontInfo> newItem(new FontInfo());
                newItem->fromJson(item);
                return newItem;
            }
        });

        }
    }
    {
        m_SystemFonts.clear();
        if(val.has_field(_XPLATSTR("SystemFonts")) 
                            && !val[_XPLATSTR("SystemFonts")].is_null())
        {
        auto arr = val[_XPLATSTR("SystemFonts")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_SystemFonts), [&](web::json::value& item){
            if(item.is_null())
            {
                return std::shared_ptr<FontInfo>(nullptr);
            }
            else
            {
                std::shared_ptr<FontInfo> newItem(new FontInfo());
                newItem->fromJson(item);
                return newItem;
            }
        });

        }
    }
}

void AvailableFontsResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    WordsResponse::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_AdditionalFonts.begin(), m_AdditionalFonts.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<FontInfo> item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("AdditionalFonts"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_CustomFonts.begin(), m_CustomFonts.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<FontInfo> item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("CustomFonts"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_SystemFonts.begin(), m_SystemFonts.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<FontInfo> item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("SystemFonts"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }
}

void AvailableFontsResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    WordsResponse::fromMultiPart(multipart, prefix);

    {
        m_AdditionalFonts.clear();
        if(multipart->hasContent(_XPLATSTR("AdditionalFonts")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("AdditionalFonts")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_AdditionalFonts), [&](web::json::value item) {
            if(item.is_null())
            {
                return std::shared_ptr<FontInfo>(nullptr) ;
            }
            else
            {
                std::shared_ptr<FontInfo> newItem(new FontInfo());
                newItem->fromJson(item);
                return newItem ;
            }
        });
        }
    }
    {
        m_CustomFonts.clear();
        if(multipart->hasContent(_XPLATSTR("CustomFonts")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("CustomFonts")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_CustomFonts), [&](web::json::value item) {
            if(item.is_null())
            {
                return std::shared_ptr<FontInfo>(nullptr) ;
            }
            else
            {
                std::shared_ptr<FontInfo> newItem(new FontInfo());
                newItem->fromJson(item);
                return newItem ;
            }
        });
        }
    }
    {
        m_SystemFonts.clear();
        if(multipart->hasContent(_XPLATSTR("SystemFonts")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("SystemFonts")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_SystemFonts), [&](web::json::value item) {
            if(item.is_null())
            {
                return std::shared_ptr<FontInfo>(nullptr) ;
            }
            else
            {
                std::shared_ptr<FontInfo> newItem(new FontInfo());
                newItem->fromJson(item);
                return newItem ;
            }
        });
        }
    }
}

std::vector<std::shared_ptr<FontInfo>>& AvailableFontsResponse::getAdditionalFonts()
{
    return m_AdditionalFonts;
}

void AvailableFontsResponse::setAdditionalFonts(std::vector<std::shared_ptr<FontInfo>> const& value)
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

void AvailableFontsResponse::setCustomFonts(std::vector<std::shared_ptr<FontInfo>> const& value)
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

void AvailableFontsResponse::setSystemFonts(std::vector<std::shared_ptr<FontInfo>> const& value)
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
}

