/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FontInfo.cpp">
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


#include "FontInfo.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

FontInfo::FontInfo()
{
    m_FontFamilyName = utility::conversions::to_string_t("");
    m_FontFamilyNameIsSet = false;
    m_FullFontName = utility::conversions::to_string_t("");
    m_FullFontNameIsSet = false;
    m_Version = utility::conversions::to_string_t("");
    m_VersionIsSet = false;
    m_FilePath = utility::conversions::to_string_t("");
    m_FilePathIsSet = false;
}

FontInfo::~FontInfo()
{
}

void FontInfo::validate()
{
    // TODO: implement validation
}

web::json::value FontInfo::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_FontFamilyNameIsSet)
    {
        val[utility::conversions::to_string_t("FontFamilyName")] = ModelBase::toJson(m_FontFamilyName);
    }
    if(m_FullFontNameIsSet)
    {
        val[utility::conversions::to_string_t("FullFontName")] = ModelBase::toJson(m_FullFontName);
    }
    if(m_VersionIsSet)
    {
        val[utility::conversions::to_string_t("Version")] = ModelBase::toJson(m_Version);
    }
    if(m_FilePathIsSet)
    {
        val[utility::conversions::to_string_t("FilePath")] = ModelBase::toJson(m_FilePath);
    }

    return val;
}

void FontInfo::fromJson(web::json::value& val)
{
    if(val.has_field(utility::conversions::to_string_t("FontFamilyName")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("FontFamilyName")];
        if(!fieldValue.is_null())
        {
            setFontFamilyName(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("FullFontName")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("FullFontName")];
        if(!fieldValue.is_null())
        {
            setFullFontName(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("Version")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Version")];
        if(!fieldValue.is_null())
        {
            setVersion(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("FilePath")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("FilePath")];
        if(!fieldValue.is_null())
        {
            setFilePath(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void FontInfo::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_FontFamilyNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("FontFamilyName"), m_FontFamilyName));
        
    }
    if(m_FullFontNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("FullFontName"), m_FullFontName));
        
    }
    if(m_VersionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Version"), m_Version));
        
    }
    if(m_FilePathIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("FilePath"), m_FilePath));
        
    }
}

void FontInfo::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("FontFamilyName")))
    {
        setFontFamilyName(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("FontFamilyName"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("FullFontName")))
    {
        setFullFontName(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("FullFontName"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Version")))
    {
        setVersion(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Version"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("FilePath")))
    {
        setFilePath(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("FilePath"))));
    }
}

utility::string_t FontInfo::getFontFamilyName() const
{
    return m_FontFamilyName;
}


void FontInfo::setFontFamilyName(utility::string_t value)
{
    m_FontFamilyName = value;
    m_FontFamilyNameIsSet = true;
}
bool FontInfo::fontFamilyNameIsSet() const
{
    return m_FontFamilyNameIsSet;
}

void FontInfo::unsetFontFamilyName()
{
    m_FontFamilyNameIsSet = false;
}

utility::string_t FontInfo::getFullFontName() const
{
    return m_FullFontName;
}


void FontInfo::setFullFontName(utility::string_t value)
{
    m_FullFontName = value;
    m_FullFontNameIsSet = true;
}
bool FontInfo::fullFontNameIsSet() const
{
    return m_FullFontNameIsSet;
}

void FontInfo::unsetFullFontName()
{
    m_FullFontNameIsSet = false;
}

utility::string_t FontInfo::getVersion() const
{
    return m_Version;
}


void FontInfo::setVersion(utility::string_t value)
{
    m_Version = value;
    m_VersionIsSet = true;
}
bool FontInfo::versionIsSet() const
{
    return m_VersionIsSet;
}

void FontInfo::unsetVersion()
{
    m_VersionIsSet = false;
}

utility::string_t FontInfo::getFilePath() const
{
    return m_FilePath;
}


void FontInfo::setFilePath(utility::string_t value)
{
    m_FilePath = value;
    m_FilePathIsSet = true;
}
bool FontInfo::filePathIsSet() const
{
    return m_FilePathIsSet;
}

void FontInfo::unsetFilePath()
{
    m_FilePathIsSet = false;
}

}
}
}
}

