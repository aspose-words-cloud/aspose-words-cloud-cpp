/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TableCellFormatResponse.cpp">
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


#include "TableCellFormatResponse.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

TableCellFormatResponse::TableCellFormatResponse()
{
    m_CellFormatIsSet = false;
}

TableCellFormatResponse::~TableCellFormatResponse()
{
}

void TableCellFormatResponse::validate()
{
    // TODO: implement validation
}

web::json::value TableCellFormatResponse::toJson() const
{
    web::json::value val = this->AsposeResponse::toJson();

    if(m_CellFormatIsSet)
    {
        val[utility::conversions::to_string_t("CellFormat")] = ModelBase::toJson(m_CellFormat);
    }

    return val;
}

void TableCellFormatResponse::fromJson(web::json::value& val)
{
    this->AsposeResponse::fromJson(val);

    if(val.has_field(utility::conversions::to_string_t("CellFormat")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("CellFormat")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<TableCellFormat> newItem(new TableCellFormat());
            newItem->fromJson(fieldValue);
            setCellFormat( newItem );
        }
    }
}

void TableCellFormatResponse::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Code"), m_Code));
    if(m_StatusIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Status"), m_Status));
        
    }
    if(m_CellFormatIsSet)
    {
        if (m_CellFormat.get())
        {
            m_CellFormat->toMultipart(multipart, utility::conversions::to_string_t("CellFormat."));
        }
        
    }
}

void TableCellFormatResponse::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    setCode(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Code"))));
    if(multipart->hasContent(utility::conversions::to_string_t("Status")))
    {
        setStatus(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Status"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("CellFormat")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("CellFormat")))
        {
            std::shared_ptr<TableCellFormat> newItem(new TableCellFormat());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("CellFormat."));
            setCellFormat( newItem );
        }
    }
}

std::shared_ptr<TableCellFormat> TableCellFormatResponse::getCellFormat() const
{
    return m_CellFormat;
}


void TableCellFormatResponse::setCellFormat(std::shared_ptr<TableCellFormat> value)
{
    m_CellFormat = value;
    m_CellFormatIsSet = true;
}
bool TableCellFormatResponse::cellFormatIsSet() const
{
    return m_CellFormatIsSet;
}

void TableCellFormatResponse::unsetCellFormat()
{
    m_CellFormatIsSet = false;
}

}
}
}
}

