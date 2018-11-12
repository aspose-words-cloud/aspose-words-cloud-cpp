/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TableCellInsert.cpp">
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


#include "TableCellInsert.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

TableCellInsert::TableCellInsert()
{
    m_InsertAfter = 0;
    m_InsertAfterIsSet = false;
}

TableCellInsert::~TableCellInsert()
{
}

void TableCellInsert::validate()
{
    // TODO: implement validation
}

web::json::value TableCellInsert::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_InsertAfterIsSet)
    {
        val[utility::conversions::to_string_t("InsertAfter")] = ModelBase::toJson(m_InsertAfter);
    }

    return val;
}

void TableCellInsert::fromJson(web::json::value& val)
{
    if(val.has_field(utility::conversions::to_string_t("InsertAfter")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("InsertAfter")];
        if(!fieldValue.is_null())
        {
            setInsertAfter(ModelBase::int32_tFromJson(fieldValue));
        }
    }
}

void TableCellInsert::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
}

void TableCellInsert::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
}

int32_t TableCellInsert::getInsertAfter() const
{
    return m_InsertAfter;
}


void TableCellInsert::setInsertAfter(int32_t value)
{
    m_InsertAfter = value;
    m_InsertAfterIsSet = true;
}
bool TableCellInsert::insertAfterIsSet() const
{
    return m_InsertAfterIsSet;
}

void TableCellInsert::unsetInsertAfter()
{
    m_InsertAfterIsSet = false;
}

}
}
}
}

