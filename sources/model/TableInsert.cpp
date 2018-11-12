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
        val[utility::conversions::to_string_t("Postion")] = ModelBase::toJson(m_Postion);
    }
    val[utility::conversions::to_string_t("ColumnsCount")] = ModelBase::toJson(m_ColumnsCount);
    val[utility::conversions::to_string_t("RowsCount")] = ModelBase::toJson(m_RowsCount);

    return val;
}

void TableInsert::fromJson(web::json::value& val)
{
    if(val.has_field(utility::conversions::to_string_t("Postion")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Postion")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<DocumentPosition> newItem(new DocumentPosition());
            newItem->fromJson(fieldValue);
            setPostion( newItem );
        }
    }
    setColumnsCount(ModelBase::int32_tFromJson(val[utility::conversions::to_string_t("ColumnsCount")]));
    setRowsCount(ModelBase::int32_tFromJson(val[utility::conversions::to_string_t("RowsCount")]));
}

void TableInsert::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_PostionIsSet)
    {
        if (m_Postion.get())
        {
            m_Postion->toMultipart(multipart, utility::conversions::to_string_t("Postion."));
        }
        
    }
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("ColumnsCount"), m_ColumnsCount));
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("RowsCount"), m_RowsCount));
}

void TableInsert::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("Postion")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("Postion")))
        {
            std::shared_ptr<DocumentPosition> newItem(new DocumentPosition());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("Postion."));
            setPostion( newItem );
        }
    }
    setColumnsCount(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("ColumnsCount"))));
    setRowsCount(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("RowsCount"))));
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

