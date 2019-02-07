/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="StringFormatData.cpp">
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


#include "StringFormatData.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

StringFormatData::StringFormatData()
{
    m_Alignment = utility::conversions::to_string_t("");
    m_AlignmentIsSet = false;
    m_FormatFlags = utility::conversions::to_string_t("");
    m_FormatFlagsIsSet = false;
    m_HotkeyPrefix = utility::conversions::to_string_t("");
    m_HotkeyPrefixIsSet = false;
    m_LineAlignment = utility::conversions::to_string_t("");
    m_LineAlignmentIsSet = false;
    m_Trimming = utility::conversions::to_string_t("");
    m_TrimmingIsSet = false;
}

StringFormatData::~StringFormatData()
{
}

void StringFormatData::validate()
{
    // TODO: implement validation
}

web::json::value StringFormatData::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_AlignmentIsSet)
    {
        val[_XPLATSTR("Alignment")] = ModelBase::toJson(m_Alignment);
    }
    if(m_FormatFlagsIsSet)
    {
        val[_XPLATSTR("FormatFlags")] = ModelBase::toJson(m_FormatFlags);
    }
    if(m_HotkeyPrefixIsSet)
    {
        val[_XPLATSTR("HotkeyPrefix")] = ModelBase::toJson(m_HotkeyPrefix);
    }
    if(m_LineAlignmentIsSet)
    {
        val[_XPLATSTR("LineAlignment")] = ModelBase::toJson(m_LineAlignment);
    }
    if(m_TrimmingIsSet)
    {
        val[_XPLATSTR("Trimming")] = ModelBase::toJson(m_Trimming);
    }

    return val;
}

void StringFormatData::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("Alignment")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Alignment")];
        if(!fieldValue.is_null())
        {
            setAlignment(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("FormatFlags")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("FormatFlags")];
        if(!fieldValue.is_null())
        {
            setFormatFlags(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("HotkeyPrefix")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("HotkeyPrefix")];
        if(!fieldValue.is_null())
        {
            setHotkeyPrefix(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("LineAlignment")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("LineAlignment")];
        if(!fieldValue.is_null())
        {
            setLineAlignment(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Trimming")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Trimming")];
        if(!fieldValue.is_null())
        {
            setTrimming(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void StringFormatData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_AlignmentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Alignment"), m_Alignment));
        
    }
    if(m_FormatFlagsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("FormatFlags"), m_FormatFlags));
        
    }
    if(m_HotkeyPrefixIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("HotkeyPrefix"), m_HotkeyPrefix));
        
    }
    if(m_LineAlignmentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("LineAlignment"), m_LineAlignment));
        
    }
    if(m_TrimmingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Trimming"), m_Trimming));
        
    }
}

void StringFormatData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("Alignment")))
    {
        setAlignment(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Alignment"))));
    }
    if(multipart->hasContent(_XPLATSTR("FormatFlags")))
    {
        setFormatFlags(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("FormatFlags"))));
    }
    if(multipart->hasContent(_XPLATSTR("HotkeyPrefix")))
    {
        setHotkeyPrefix(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("HotkeyPrefix"))));
    }
    if(multipart->hasContent(_XPLATSTR("LineAlignment")))
    {
        setLineAlignment(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("LineAlignment"))));
    }
    if(multipart->hasContent(_XPLATSTR("Trimming")))
    {
        setTrimming(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Trimming"))));
    }
}

utility::string_t StringFormatData::getAlignment() const
{
    return m_Alignment;
}


void StringFormatData::setAlignment(utility::string_t value)
{
    m_Alignment = value;
    m_AlignmentIsSet = true;
}
bool StringFormatData::alignmentIsSet() const
{
    return m_AlignmentIsSet;
}

void StringFormatData::unsetAlignment()
{
    m_AlignmentIsSet = false;
}

utility::string_t StringFormatData::getFormatFlags() const
{
    return m_FormatFlags;
}


void StringFormatData::setFormatFlags(utility::string_t value)
{
    m_FormatFlags = value;
    m_FormatFlagsIsSet = true;
}
bool StringFormatData::formatFlagsIsSet() const
{
    return m_FormatFlagsIsSet;
}

void StringFormatData::unsetFormatFlags()
{
    m_FormatFlagsIsSet = false;
}

utility::string_t StringFormatData::getHotkeyPrefix() const
{
    return m_HotkeyPrefix;
}


void StringFormatData::setHotkeyPrefix(utility::string_t value)
{
    m_HotkeyPrefix = value;
    m_HotkeyPrefixIsSet = true;
}
bool StringFormatData::hotkeyPrefixIsSet() const
{
    return m_HotkeyPrefixIsSet;
}

void StringFormatData::unsetHotkeyPrefix()
{
    m_HotkeyPrefixIsSet = false;
}

utility::string_t StringFormatData::getLineAlignment() const
{
    return m_LineAlignment;
}


void StringFormatData::setLineAlignment(utility::string_t value)
{
    m_LineAlignment = value;
    m_LineAlignmentIsSet = true;
}
bool StringFormatData::lineAlignmentIsSet() const
{
    return m_LineAlignmentIsSet;
}

void StringFormatData::unsetLineAlignment()
{
    m_LineAlignmentIsSet = false;
}

utility::string_t StringFormatData::getTrimming() const
{
    return m_Trimming;
}


void StringFormatData::setTrimming(utility::string_t value)
{
    m_Trimming = value;
    m_TrimmingIsSet = true;
}
bool StringFormatData::trimmingIsSet() const
{
    return m_TrimmingIsSet;
}

void StringFormatData::unsetTrimming()
{
    m_TrimmingIsSet = false;
}

}
}
}
}

