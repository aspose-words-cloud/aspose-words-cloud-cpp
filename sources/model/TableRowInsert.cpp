/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TableRowInsert.cpp">
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

#include "TableRowInsert.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

TableRowInsert::TableRowInsert()
{
    m_ColumnsCount = 0;
    m_ColumnsCountIsSet = false;
    m_InsertAfter = 0;
    m_InsertAfterIsSet = false;

}

TableRowInsert::~TableRowInsert()
{
}

void TableRowInsert::validate()
{
    // TODO: implement validation
}

web::json::value TableRowInsert::toJson() const
{
    web::json::value val = web::json::value::object();
    if(m_ColumnsCountIsSet)
    {
        val[_XPLATSTR("ColumnsCount")] = ModelBase::toJson(m_ColumnsCount);
    }
    if(m_InsertAfterIsSet)
    {
        val[_XPLATSTR("InsertAfter")] = ModelBase::toJson(m_InsertAfter);
    }

    return val;
}

void TableRowInsert::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("ColumnsCount")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ColumnsCount")];
        if(!fieldValue.is_null())
        {
           setColumnsCount(ModelBase::integerFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("InsertAfter")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("InsertAfter")];
        if(!fieldValue.is_null())
        {
           setInsertAfter(ModelBase::integerFromJson(fieldValue));
        }
    }

}

void TableRowInsert::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_ColumnsCountIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ColumnsCount"), m_ColumnsCount));
    }


    if(m_InsertAfterIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("InsertAfter"), m_InsertAfter));
    }

}

void TableRowInsert::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

int32_t TableRowInsert::getColumnsCount() const
{
    return m_ColumnsCount;
}


void TableRowInsert::setColumnsCount(int32_t value)
{
    m_ColumnsCount = value;
    m_ColumnsCountIsSet = true;
}

bool TableRowInsert::columnsCountIsSet() const
{
    return m_ColumnsCountIsSet;
}

void TableRowInsert::unsetColumnsCount()
{
    m_ColumnsCountIsSet = false;
}

int32_t TableRowInsert::getInsertAfter() const
{
    return m_InsertAfter;
}


void TableRowInsert::setInsertAfter(int32_t value)
{
    m_InsertAfter = value;
    m_InsertAfterIsSet = true;
}

bool TableRowInsert::insertAfterIsSet() const
{
    return m_InsertAfterIsSet;
}

void TableRowInsert::unsetInsertAfter()
{
    m_InsertAfterIsSet = false;
}

}
}
}
}
}
