/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TableInsert.cpp">
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

#include "TableInsert.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

TableInsert::TableInsert()
{
    m_ColumnsCount = 0;
    m_ColumnsCountIsSet = false;

    m_PositionIsSet = false;
    m_RowsCount = 0;
    m_RowsCountIsSet = false;

}

TableInsert::~TableInsert()
{
}

void TableInsert::validate()
{
    // TODO: implement validation
}

web::json::value TableInsert::toJson() const
{
    web::json::value val = web::json::value::object();
    if(m_ColumnsCountIsSet)
    {
        val[_XPLATSTR("ColumnsCount")] = ModelBase::toJson(m_ColumnsCount);
    }
    if(m_PositionIsSet)
    {
        val[_XPLATSTR("Position")] = ModelBase::toJson(m_Position);
    }
    if(m_RowsCountIsSet)
    {
        val[_XPLATSTR("RowsCount")] = ModelBase::toJson(m_RowsCount);
    }

    return val;
}

void TableInsert::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("ColumnsCount")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ColumnsCount")];
        if(!fieldValue.is_null())
        {
           setColumnsCount(ModelBase::integerFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("Position")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Position")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<DocumentPosition> newItem(new DocumentPosition());
            newItem->fromJson(fieldValue);
            setPosition( newItem );
        }
    }


    if(val.has_field(_XPLATSTR("RowsCount")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("RowsCount")];
        if(!fieldValue.is_null())
        {
           setRowsCount(ModelBase::integerFromJson(fieldValue));
        }
    }

}

void TableInsert::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_ColumnsCountIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ColumnsCount"), m_ColumnsCount));
    }


    if(m_PositionIsSet)
    {
        if (m_Position.get())
        {
            m_Position->toMultipart(multipart, _XPLATSTR("Position."));
        }
    }


    if(m_RowsCountIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RowsCount"), m_RowsCount));
    }

}

void TableInsert::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

int32_t TableInsert::getColumnsCount() const
{
    return m_ColumnsCount;
}


void TableInsert::setColumnsCount(int32_t value)
{
    m_ColumnsCount = value;
    m_ColumnsCountIsSet = true;
}

bool TableInsert::columnsCountIsSet() const
{
    return m_ColumnsCountIsSet;
}

void TableInsert::unsetColumnsCount()
{
    m_ColumnsCountIsSet = false;
}

std::shared_ptr<DocumentPosition> TableInsert::getPosition() const
{
    return m_Position;
}


void TableInsert::setPosition(std::shared_ptr<DocumentPosition> value)
{
    m_Position = value;
    m_PositionIsSet = true;
}

bool TableInsert::positionIsSet() const
{
    return m_PositionIsSet;
}

void TableInsert::unsetPosition()
{
    m_PositionIsSet = false;
}

int32_t TableInsert::getRowsCount() const
{
    return m_RowsCount;
}


void TableInsert::setRowsCount(int32_t value)
{
    m_RowsCount = value;
    m_RowsCountIsSet = true;
}

bool TableInsert::rowsCountIsSet() const
{
    return m_RowsCountIsSet;
}

void TableInsert::unsetRowsCount()
{
    m_RowsCountIsSet = false;
}

}
}
}
}
}
