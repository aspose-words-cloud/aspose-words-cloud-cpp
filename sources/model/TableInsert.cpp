/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TableInsert.cpp">
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


#include "TableInsert.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

TableInsert::TableInsert()
{
    m_PostionIsSet = false;
    m_ColumnsCount = 0;
    m_RowsCount = 0;
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

    if(m_PostionIsSet)
    {
        val[_XPLATSTR("Postion")] = ModelBase::toJson(m_Postion);
    }
    val[_XPLATSTR("ColumnsCount")] = ModelBase::toJson(m_ColumnsCount);
    val[_XPLATSTR("RowsCount")] = ModelBase::toJson(m_RowsCount);

    return val;
}

void TableInsert::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("Postion")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Postion")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<DocumentPosition> newItem(new DocumentPosition());
            newItem->fromJson(fieldValue);
            setPostion( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("ColumnsCount")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ColumnsCount")];
        if(!fieldValue.is_null())
        {
            setColumnsCount(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("RowsCount")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("RowsCount")];
        if(!fieldValue.is_null())
        {
            setRowsCount(ModelBase::int32_tFromJson(fieldValue));
        }
    }
}

void TableInsert::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_PostionIsSet)
    {
        if (m_Postion.get())
        {
            m_Postion->toMultipart(multipart, _XPLATSTR("Postion."));
        }
        
    }
    multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ColumnsCount"), m_ColumnsCount));
    multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RowsCount"), m_RowsCount));
}

void TableInsert::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("Postion")))
    {
        if(multipart->hasContent(_XPLATSTR("Postion")))
        {
            std::shared_ptr<DocumentPosition> newItem(new DocumentPosition());
            newItem->fromMultiPart(multipart, _XPLATSTR("Postion."));
            setPostion( newItem );
        }
    }
    setColumnsCount(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("ColumnsCount"))));
    setRowsCount(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("RowsCount"))));
}

std::shared_ptr<DocumentPosition> TableInsert::getPostion() const
{
    return m_Postion;
}


void TableInsert::setPostion(std::shared_ptr<DocumentPosition> value)
{
    m_Postion = value;
    m_PostionIsSet = true;
}
bool TableInsert::postionIsSet() const
{
    return m_PostionIsSet;
}

void TableInsert::unsetPostion()
{
    m_PostionIsSet = false;
}

int32_t TableInsert::getColumnsCount() const
{
    return m_ColumnsCount;
}


void TableInsert::setColumnsCount(int32_t value)
{
    m_ColumnsCount = value;
    
}
int32_t TableInsert::getRowsCount() const
{
    return m_RowsCount;
}


void TableInsert::setRowsCount(int32_t value)
{
    m_RowsCount = value;
    
}
}
}
}
}

