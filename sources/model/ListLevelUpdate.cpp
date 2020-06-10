/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ListLevelUpdate.cpp">
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

#include "ListLevelUpdate.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

ListLevelUpdate::ListLevelUpdate()
{
    m_AlignmentIsSet = false;
    m_IsLegal = false;
    m_IsLegalIsSet = false;
    m_NumberFormat = utility::conversions::to_string_t("");
    m_NumberFormatIsSet = false;
    m_NumberPosition = 0.0;
    m_NumberPositionIsSet = false;

    m_NumberStyleIsSet = false;
    m_RestartAfterLevel = 0;
    m_RestartAfterLevelIsSet = false;
    m_StartAt = 0;
    m_StartAtIsSet = false;
    m_TabPosition = 0.0;
    m_TabPositionIsSet = false;
    m_TextPosition = 0.0;
    m_TextPositionIsSet = false;

    m_TrailingCharacterIsSet = false;

}

ListLevelUpdate::~ListLevelUpdate()
{
}

void ListLevelUpdate::validate()
{
    // TODO: implement validation
}

web::json::value ListLevelUpdate::toJson() const
{
    web::json::value val = web::json::value::object();
    if(m_AlignmentIsSet)
    {
        val[_XPLATSTR("Alignment")] = ModelBase::toJson(m_Alignment);
    }
    if(m_IsLegalIsSet)
    {
        val[_XPLATSTR("IsLegal")] = ModelBase::toJson(m_IsLegal);
    }
    if(m_NumberFormatIsSet)
    {
        val[_XPLATSTR("NumberFormat")] = ModelBase::toJson(m_NumberFormat);
    }
    if(m_NumberPositionIsSet)
    {
        val[_XPLATSTR("NumberPosition")] = ModelBase::toJson(m_NumberPosition);
    }
    if(m_NumberStyleIsSet)
    {
        val[_XPLATSTR("NumberStyle")] = ModelBase::toJson(m_NumberStyle);
    }
    if(m_RestartAfterLevelIsSet)
    {
        val[_XPLATSTR("RestartAfterLevel")] = ModelBase::toJson(m_RestartAfterLevel);
    }
    if(m_StartAtIsSet)
    {
        val[_XPLATSTR("StartAt")] = ModelBase::toJson(m_StartAt);
    }
    if(m_TabPositionIsSet)
    {
        val[_XPLATSTR("TabPosition")] = ModelBase::toJson(m_TabPosition);
    }
    if(m_TextPositionIsSet)
    {
        val[_XPLATSTR("TextPosition")] = ModelBase::toJson(m_TextPosition);
    }
    if(m_TrailingCharacterIsSet)
    {
        val[_XPLATSTR("TrailingCharacter")] = ModelBase::toJson(m_TrailingCharacter);
    }

    return val;
}

void ListLevelUpdate::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("Alignment")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Alignment")];
        if(!fieldValue.is_null())
        {
           setAlignment(ModelBase::enumFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("IsLegal")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("IsLegal")];
        if(!fieldValue.is_null())
        {
           setIsLegal(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("NumberFormat")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("NumberFormat")];
        if(!fieldValue.is_null())
        {
           setNumberFormat(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("NumberPosition")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("NumberPosition")];
        if(!fieldValue.is_null())
        {
           setNumberPosition(ModelBase::floatingFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("NumberStyle")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("NumberStyle")];
        if(!fieldValue.is_null())
        {
           setNumberStyle(ModelBase::enumFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("RestartAfterLevel")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("RestartAfterLevel")];
        if(!fieldValue.is_null())
        {
           setRestartAfterLevel(ModelBase::integerFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("StartAt")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("StartAt")];
        if(!fieldValue.is_null())
        {
           setStartAt(ModelBase::integerFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("TabPosition")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("TabPosition")];
        if(!fieldValue.is_null())
        {
           setTabPosition(ModelBase::floatingFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("TextPosition")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("TextPosition")];
        if(!fieldValue.is_null())
        {
           setTextPosition(ModelBase::floatingFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("TrailingCharacter")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("TrailingCharacter")];
        if(!fieldValue.is_null())
        {
           setTrailingCharacter(ModelBase::enumFromJson(fieldValue));
        }
    }

}

void ListLevelUpdate::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_AlignmentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Alignment"), m_Alignment));
    }


    if(m_IsLegalIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("IsLegal"), m_IsLegal));
    }


    if(m_NumberFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("NumberFormat"), m_NumberFormat));
    }


    if(m_NumberPositionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("NumberPosition"), m_NumberPosition));
    }


    if(m_NumberStyleIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("NumberStyle"), m_NumberStyle));
    }


    if(m_RestartAfterLevelIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RestartAfterLevel"), m_RestartAfterLevel));
    }


    if(m_StartAtIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("StartAt"), m_StartAt));
    }


    if(m_TabPositionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TabPosition"), m_TabPosition));
    }


    if(m_TextPositionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TextPosition"), m_TextPosition));
    }


    if(m_TrailingCharacterIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TrailingCharacter"), m_TrailingCharacter));
    }

}

void ListLevelUpdate::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

utility::string_t ListLevelUpdate::getAlignment() const
{
    return m_Alignment;
}


void ListLevelUpdate::setAlignment(utility::string_t value)
{
    m_Alignment = value;
    m_AlignmentIsSet = true;
}

bool ListLevelUpdate::alignmentIsSet() const
{
    return m_AlignmentIsSet;
}

void ListLevelUpdate::unsetAlignment()
{
    m_AlignmentIsSet = false;
}

bool ListLevelUpdate::isIsLegal() const
{
    return m_IsLegal;
}


void ListLevelUpdate::setIsLegal(bool value)
{
    m_IsLegal = value;
    m_IsLegalIsSet = true;
}

bool ListLevelUpdate::isLegalIsSet() const
{
    return m_IsLegalIsSet;
}

void ListLevelUpdate::unsetIsLegal()
{
    m_IsLegalIsSet = false;
}

utility::string_t ListLevelUpdate::getNumberFormat() const
{
    return m_NumberFormat;
}


void ListLevelUpdate::setNumberFormat(utility::string_t value)
{
    m_NumberFormat = value;
    m_NumberFormatIsSet = true;
}

bool ListLevelUpdate::numberFormatIsSet() const
{
    return m_NumberFormatIsSet;
}

void ListLevelUpdate::unsetNumberFormat()
{
    m_NumberFormatIsSet = false;
}

double ListLevelUpdate::getNumberPosition() const
{
    return m_NumberPosition;
}


void ListLevelUpdate::setNumberPosition(double value)
{
    m_NumberPosition = value;
    m_NumberPositionIsSet = true;
}

bool ListLevelUpdate::numberPositionIsSet() const
{
    return m_NumberPositionIsSet;
}

void ListLevelUpdate::unsetNumberPosition()
{
    m_NumberPositionIsSet = false;
}

utility::string_t ListLevelUpdate::getNumberStyle() const
{
    return m_NumberStyle;
}


void ListLevelUpdate::setNumberStyle(utility::string_t value)
{
    m_NumberStyle = value;
    m_NumberStyleIsSet = true;
}

bool ListLevelUpdate::numberStyleIsSet() const
{
    return m_NumberStyleIsSet;
}

void ListLevelUpdate::unsetNumberStyle()
{
    m_NumberStyleIsSet = false;
}

int32_t ListLevelUpdate::getRestartAfterLevel() const
{
    return m_RestartAfterLevel;
}


void ListLevelUpdate::setRestartAfterLevel(int32_t value)
{
    m_RestartAfterLevel = value;
    m_RestartAfterLevelIsSet = true;
}

bool ListLevelUpdate::restartAfterLevelIsSet() const
{
    return m_RestartAfterLevelIsSet;
}

void ListLevelUpdate::unsetRestartAfterLevel()
{
    m_RestartAfterLevelIsSet = false;
}

int32_t ListLevelUpdate::getStartAt() const
{
    return m_StartAt;
}


void ListLevelUpdate::setStartAt(int32_t value)
{
    m_StartAt = value;
    m_StartAtIsSet = true;
}

bool ListLevelUpdate::startAtIsSet() const
{
    return m_StartAtIsSet;
}

void ListLevelUpdate::unsetStartAt()
{
    m_StartAtIsSet = false;
}

double ListLevelUpdate::getTabPosition() const
{
    return m_TabPosition;
}


void ListLevelUpdate::setTabPosition(double value)
{
    m_TabPosition = value;
    m_TabPositionIsSet = true;
}

bool ListLevelUpdate::tabPositionIsSet() const
{
    return m_TabPositionIsSet;
}

void ListLevelUpdate::unsetTabPosition()
{
    m_TabPositionIsSet = false;
}

double ListLevelUpdate::getTextPosition() const
{
    return m_TextPosition;
}


void ListLevelUpdate::setTextPosition(double value)
{
    m_TextPosition = value;
    m_TextPositionIsSet = true;
}

bool ListLevelUpdate::textPositionIsSet() const
{
    return m_TextPositionIsSet;
}

void ListLevelUpdate::unsetTextPosition()
{
    m_TextPositionIsSet = false;
}

utility::string_t ListLevelUpdate::getTrailingCharacter() const
{
    return m_TrailingCharacter;
}


void ListLevelUpdate::setTrailingCharacter(utility::string_t value)
{
    m_TrailingCharacter = value;
    m_TrailingCharacterIsSet = true;
}

bool ListLevelUpdate::trailingCharacterIsSet() const
{
    return m_TrailingCharacterIsSet;
}

void ListLevelUpdate::unsetTrailingCharacter()
{
    m_TrailingCharacterIsSet = false;
}

}
}
}
}
}
