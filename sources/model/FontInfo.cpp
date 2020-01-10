/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FontInfo.cpp">
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


#include "FontInfo.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

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
        val[_XPLATSTR("fontFamilyName")] = ModelBase::toJson(m_FontFamilyName);
    }
    if(m_FullFontNameIsSet)
    {
        val[_XPLATSTR("fullFontName")] = ModelBase::toJson(m_FullFontName);
    }
    if(m_VersionIsSet)
    {
        val[_XPLATSTR("version")] = ModelBase::toJson(m_Version);
    }
    if(m_FilePathIsSet)
    {
        val[_XPLATSTR("filePath")] = ModelBase::toJson(m_FilePath);
    }

    return val;
}

void FontInfo::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("fontFamilyName")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("fontFamilyName")];
        if(!fieldValue.is_null())
        {
            setFontFamilyName(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("fullFontName")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("fullFontName")];
        if(!fieldValue.is_null())
        {
            setFullFontName(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("version")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("version")];
        if(!fieldValue.is_null())
        {
            setVersion(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("filePath")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("filePath")];
        if(!fieldValue.is_null())
        {
            setFilePath(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void FontInfo::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_FontFamilyNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("fontFamilyName"), m_FontFamilyName));
        
    }
    if(m_FullFontNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("fullFontName"), m_FullFontName));
        
    }
    if(m_VersionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("version"), m_Version));
        
    }
    if(m_FilePathIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("filePath"), m_FilePath));
        
    }
}

void FontInfo::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("fontFamilyName")))
    {
        setFontFamilyName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("fontFamilyName"))));
    }
    if(multipart->hasContent(_XPLATSTR("fullFontName")))
    {
        setFullFontName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("fullFontName"))));
    }
    if(multipart->hasContent(_XPLATSTR("version")))
    {
        setVersion(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("version"))));
    }
    if(multipart->hasContent(_XPLATSTR("filePath")))
    {
        setFilePath(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("filePath"))));
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
}

