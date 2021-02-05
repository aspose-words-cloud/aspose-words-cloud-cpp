/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TableRowResponse.cpp">
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

#include "TableRowResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

TableRowResponse::TableRowResponse()
{
    m_RowIsSet = false;

}

TableRowResponse::~TableRowResponse()
{
}

void TableRowResponse::validate()
{
    // TODO: implement validation
}

web::json::value TableRowResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();
    if(m_RowIsSet)
    {
        val[_XPLATSTR("Row")] = ModelBase::toJson(m_Row);
    }

    return val;
}

void TableRowResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("Row")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Row")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<TableRow> newItem(new TableRow());
            newItem->fromJson(fieldValue);
            setRow( newItem );
        }
    }

}

void TableRowResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    WordsResponse::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_RowIsSet)
    {
        if (m_Row.get())
        {
            m_Row->toMultipart(multipart, _XPLATSTR("Row."));
        }
    }

}

void TableRowResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

std::shared_ptr<TableRow> TableRowResponse::getRow() const
{
    return m_Row;
}


void TableRowResponse::setRow(std::shared_ptr<TableRow> value)
{
    m_Row = value;
    m_RowIsSet = true;
}

bool TableRowResponse::rowIsSet() const
{
    return m_RowIsSet;
}

void TableRowResponse::unsetRow()
{
    m_RowIsSet = false;
}

}
}
}
}
}
