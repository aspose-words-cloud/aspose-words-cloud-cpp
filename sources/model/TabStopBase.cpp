/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TabStopBase.cpp">
*   Copyright (c) 2021 Aspose.Words for Cloud
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

#include "TabStopBase.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

TabStopBase::TabStopBase()
{
    m_AlignmentIsSet = false;

    m_LeaderIsSet = false;
    m_Position = 0.0;
    m_PositionIsSet = false;

}

TabStopBase::~TabStopBase()
{
}

void TabStopBase::validate()
{
    // TODO: implement validation
}

web::json::value TabStopBase::toJson() const
{
    web::json::value val = web::json::value::object();
    if(m_AlignmentIsSet)
    {
        val[_XPLATSTR("Alignment")] = ModelBase::toJson(m_Alignment);
    }
    if(m_LeaderIsSet)
    {
        val[_XPLATSTR("Leader")] = ModelBase::toJson(m_Leader);
    }
    if(m_PositionIsSet)
    {
        val[_XPLATSTR("Position")] = ModelBase::toJson(m_Position);
    }

    return val;
}

void TabStopBase::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("Alignment")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Alignment")];
        if(!fieldValue.is_null())
        {
           setAlignment(ModelBase::enumFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("Leader")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Leader")];
        if(!fieldValue.is_null())
        {
           setLeader(ModelBase::enumFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("Position")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Position")];
        if(!fieldValue.is_null())
        {
           setPosition(ModelBase::floatingFromJson(fieldValue));
        }
    }

}

void TabStopBase::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_AlignmentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Alignment"), m_Alignment));
    }


    if(m_LeaderIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Leader"), m_Leader));
    }


    if(m_PositionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Position"), m_Position));
    }

}

void TabStopBase::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

utility::string_t TabStopBase::getAlignment() const
{
    return m_Alignment;
}


void TabStopBase::setAlignment(utility::string_t value)
{
    m_Alignment = value;
    m_AlignmentIsSet = true;
}

bool TabStopBase::alignmentIsSet() const
{
    return m_AlignmentIsSet;
}

void TabStopBase::unsetAlignment()
{
    m_AlignmentIsSet = false;
}

utility::string_t TabStopBase::getLeader() const
{
    return m_Leader;
}


void TabStopBase::setLeader(utility::string_t value)
{
    m_Leader = value;
    m_LeaderIsSet = true;
}

bool TabStopBase::leaderIsSet() const
{
    return m_LeaderIsSet;
}

void TabStopBase::unsetLeader()
{
    m_LeaderIsSet = false;
}

double TabStopBase::getPosition() const
{
    return m_Position;
}


void TabStopBase::setPosition(double value)
{
    m_Position = value;
    m_PositionIsSet = true;
}

bool TabStopBase::positionIsSet() const
{
    return m_PositionIsSet;
}

void TabStopBase::unsetPosition()
{
    m_PositionIsSet = false;
}

}
}
}
}
}
