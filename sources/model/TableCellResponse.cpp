/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TableCellResponse.cpp">
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


#include "TableCellResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

TableCellResponse::TableCellResponse()
{
    m_CellIsSet = false;
}

TableCellResponse::~TableCellResponse()
{
}

void TableCellResponse::validate()
{
    // TODO: implement validation
}

web::json::value TableCellResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();

    if(m_CellIsSet)
    {
        val[_XPLATSTR("Cell")] = ModelBase::toJson(m_Cell);
    }

    return val;
}

void TableCellResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("Cell")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Cell")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<TableCell> newItem(new TableCell());
            newItem->fromJson(fieldValue);
            setCell( newItem );
        }
    }
}

void TableCellResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_RequestIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RequestId"), m_RequestId));
        
    }
    if(m_CellIsSet)
    {
        if (m_Cell.get())
        {
            m_Cell->toMultipart(multipart, _XPLATSTR("Cell."));
        }
        
    }
}

void TableCellResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("RequestId")))
    {
        setRequestId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("RequestId"))));
    }
    if(multipart->hasContent(_XPLATSTR("Cell")))
    {
        if(multipart->hasContent(_XPLATSTR("Cell")))
        {
            std::shared_ptr<TableCell> newItem(new TableCell());
            newItem->fromMultiPart(multipart, _XPLATSTR("Cell."));
            setCell( newItem );
        }
    }
}

std::shared_ptr<TableCell> TableCellResponse::getCell() const
{
    return m_Cell;
}


void TableCellResponse::setCell(std::shared_ptr<TableCell> value)
{
    m_Cell = value;
    m_CellIsSet = true;
}
bool TableCellResponse::cellIsSet() const
{
    return m_CellIsSet;
}

void TableCellResponse::unsetCell()
{
    m_CellIsSet = false;
}

}
}
}
}
}

