/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TableRowInsert.cpp">
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


#include "TableRowInsert.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

TableRowInsert::TableRowInsert()
{
    m_InsertAfter = 0;
    m_InsertAfterIsSet = false;
    m_ColumnsCount = 0;
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

    if(m_InsertAfterIsSet)
    {
        val[_XPLATSTR("insertAfter")] = ModelBase::toJson(m_InsertAfter);
    }
    val[_XPLATSTR("columnsCount")] = ModelBase::toJson(m_ColumnsCount);

    return val;
}

void TableRowInsert::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("insertAfter")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("insertAfter")];
        if(!fieldValue.is_null())
        {
            setInsertAfter(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("columnsCount")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("columnsCount")];
        if(!fieldValue.is_null())
        {
            setColumnsCount(ModelBase::int32_tFromJson(fieldValue));
        }
    }
}

void TableRowInsert::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_InsertAfterIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("insertAfter"), m_InsertAfter));
    }
    multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("columnsCount"), m_ColumnsCount));
}

void TableRowInsert::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("insertAfter")))
    {
        setInsertAfter(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("insertAfter"))));
    }
    setColumnsCount(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("columnsCount"))));
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

int32_t TableRowInsert::getColumnsCount() const
{
    return m_ColumnsCount;
}


void TableRowInsert::setColumnsCount(int32_t value)
{
    m_ColumnsCount = value;
    
}
}
}
}
}
}

