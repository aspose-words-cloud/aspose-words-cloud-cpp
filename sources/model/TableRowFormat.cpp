/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TableRowFormat.cpp">
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


#include "TableRowFormat.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

TableRowFormat::TableRowFormat()
{
    m_AllowBreakAcrossPages = false;
    m_AllowBreakAcrossPagesIsSet = false;
    m_HeadingFormat = false;
    m_HeadingFormatIsSet = false;
    m_Height = 0.0;
    m_HeightIsSet = false;
    m_HeightRule = utility::conversions::to_string_t("");
    m_HeightRuleIsSet = false;
}

TableRowFormat::~TableRowFormat()
{
}

void TableRowFormat::validate()
{
    // TODO: implement validation
}

web::json::value TableRowFormat::toJson() const
{
    web::json::value val = this->LinkElement::toJson();

    if(m_AllowBreakAcrossPagesIsSet)
    {
        val[_XPLATSTR("allowBreakAcrossPages")] = ModelBase::toJson(m_AllowBreakAcrossPages);
    }
    if(m_HeadingFormatIsSet)
    {
        val[_XPLATSTR("headingFormat")] = ModelBase::toJson(m_HeadingFormat);
    }
    if(m_HeightIsSet)
    {
        val[_XPLATSTR("height")] = ModelBase::toJson(m_Height);
    }
    if(m_HeightRuleIsSet)
    {
        val[_XPLATSTR("heightRule")] = ModelBase::toJson(m_HeightRule);
    }

    return val;
}

void TableRowFormat::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    if(val.has_field(_XPLATSTR("allowBreakAcrossPages")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("allowBreakAcrossPages")];
        if(!fieldValue.is_null())
        {
            setAllowBreakAcrossPages(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("headingFormat")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("headingFormat")];
        if(!fieldValue.is_null())
        {
            setHeadingFormat(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("height")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("height")];
        if(!fieldValue.is_null())
        {
            setHeight(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("heightRule")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("heightRule")];
        if(!fieldValue.is_null())
        {
            setHeightRule(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void TableRowFormat::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_LinkIsSet)
    {
        if (m_Link.get())
        {
            m_Link->toMultipart(multipart, _XPLATSTR("link."));
        }
        
    }
    if(m_AllowBreakAcrossPagesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("allowBreakAcrossPages"), m_AllowBreakAcrossPages));
    }
    if(m_HeadingFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("headingFormat"), m_HeadingFormat));
    }
    if(m_HeightIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("height"), m_Height));
    }
    if(m_HeightRuleIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("heightRule"), m_HeightRule));
        
    }
}

void TableRowFormat::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("link")))
    {
        if(multipart->hasContent(_XPLATSTR("link")))
        {
            std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
            newItem->fromMultiPart(multipart, _XPLATSTR("link."));
            setLink( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("allowBreakAcrossPages")))
    {
        setAllowBreakAcrossPages(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("allowBreakAcrossPages"))));
    }
    if(multipart->hasContent(_XPLATSTR("headingFormat")))
    {
        setHeadingFormat(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("headingFormat"))));
    }
    if(multipart->hasContent(_XPLATSTR("height")))
    {
        setHeight(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("height"))));
    }
    if(multipart->hasContent(_XPLATSTR("heightRule")))
    {
        setHeightRule(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("heightRule"))));
    }
}

bool TableRowFormat::isAllowBreakAcrossPages() const
{
    return m_AllowBreakAcrossPages;
}


void TableRowFormat::setAllowBreakAcrossPages(bool value)
{
    m_AllowBreakAcrossPages = value;
    m_AllowBreakAcrossPagesIsSet = true;
}
bool TableRowFormat::allowBreakAcrossPagesIsSet() const
{
    return m_AllowBreakAcrossPagesIsSet;
}

void TableRowFormat::unsetAllowBreakAcrossPages()
{
    m_AllowBreakAcrossPagesIsSet = false;
}

bool TableRowFormat::isHeadingFormat() const
{
    return m_HeadingFormat;
}


void TableRowFormat::setHeadingFormat(bool value)
{
    m_HeadingFormat = value;
    m_HeadingFormatIsSet = true;
}
bool TableRowFormat::headingFormatIsSet() const
{
    return m_HeadingFormatIsSet;
}

void TableRowFormat::unsetHeadingFormat()
{
    m_HeadingFormatIsSet = false;
}

double TableRowFormat::getHeight() const
{
    return m_Height;
}


void TableRowFormat::setHeight(double value)
{
    m_Height = value;
    m_HeightIsSet = true;
}
bool TableRowFormat::heightIsSet() const
{
    return m_HeightIsSet;
}

void TableRowFormat::unsetHeight()
{
    m_HeightIsSet = false;
}

utility::string_t TableRowFormat::getHeightRule() const
{
    return m_HeightRule;
}


void TableRowFormat::setHeightRule(utility::string_t value)
{
    m_HeightRule = value;
    m_HeightRuleIsSet = true;
}
bool TableRowFormat::heightRuleIsSet() const
{
    return m_HeightRuleIsSet;
}

void TableRowFormat::unsetHeightRule()
{
    m_HeightRuleIsSet = false;
}

}
}
}
}
}

