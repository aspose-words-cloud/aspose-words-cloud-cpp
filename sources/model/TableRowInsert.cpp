/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TableRowInsert.cpp">
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


#include "TableRowInsert.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

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
        val[utility::conversions::to_string_t("InsertAfter")] = ModelBase::toJson(m_InsertAfter);
    }
    val[utility::conversions::to_string_t("ColumnsCount")] = ModelBase::toJson(m_ColumnsCount);

    return val;
}

void TableRowInsert::fromJson(web::json::value& val)
{
    if(val.has_field(utility::conversions::to_string_t("InsertAfter")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("InsertAfter")];
        if(!fieldValue.is_null())
        {
            setInsertAfter(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("ColumnsCount")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("ColumnsCount")];
        if(!fieldValue.is_null())
        {
            setColumnsCount(ModelBase::int32_tFromJson(fieldValue));
        }
    }
}

void TableRowInsert::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_InsertAfterIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("InsertAfter"), m_InsertAfter));
    }
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("ColumnsCount"), m_ColumnsCount));
}

void TableRowInsert::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("InsertAfter")))
    {
        setInsertAfter(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("InsertAfter"))));
    }
    setColumnsCount(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("ColumnsCount"))));
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

