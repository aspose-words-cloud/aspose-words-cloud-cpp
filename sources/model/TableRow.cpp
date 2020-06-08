/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TableRow.cpp">
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


#include "TableRow.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

TableRow::TableRow()
{
    m_RowFormatIsSet = false;
    m_TableCellListIsSet = false;
}

TableRow::~TableRow()
{
}

void TableRow::validate()
{
    // TODO: implement validation
}

web::json::value TableRow::toJson() const
{
    web::json::value val = this->NodeLink::toJson();

    if(m_RowFormatIsSet)
    {
        val[_XPLATSTR("RowFormat")] = ModelBase::toJson(m_RowFormat);
    }
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_TableCellList.begin(), m_TableCellList.end(), std::back_inserter(jsonArray),
			[&](<DATA_TYPE_START>TableCell<DATA_TYPE_END> item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("TableCellList")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void TableRow::fromJson(web::json::value& val)
{
    this->NodeLink::fromJson(val);

    if(val.has_field(_XPLATSTR("RowFormat")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("RowFormat")];
        if(!fieldValue.is_null())
        {
            <DATA_TYPE_START>TableRowFormat<DATA_TYPE_END> newItem(new TableRowFormat());
            newItem->fromJson(fieldValue);
            setRowFormat( newItem );
        }
    }
    {
        m_TableCellList.clear();
        if(val.has_field(_XPLATSTR("TableCellList")) 
                            && !val[_XPLATSTR("TableCellList")].is_null())
        {
        auto arr = val[_XPLATSTR("TableCellList")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_TableCellList), [&](web::json::value& item){
            if(item.is_null())
            {
                return <DATA_TYPE_START>TableCell<DATA_TYPE_END>(nullptr);
            }
            else
            {
                <DATA_TYPE_START>TableCell<DATA_TYPE_END> newItem(new TableCell());
                newItem->fromJson(item);
                return newItem;
            }
        });

        }
    }
}

void TableRow::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    NodeLink::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_RowFormatIsSet)
    {
        if (m_RowFormat.get())
        {
            m_RowFormat->toMultipart(multipart, _XPLATSTR("RowFormat."));
        }
        
    }
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_TableCellList.begin(), m_TableCellList.end(), std::back_inserter(jsonArray), [&](<DATA_TYPE_START>TableCell<DATA_TYPE_END> item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TableCellList"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }
}

void TableRow::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    NodeLink::fromMultiPart(multipart, prefix);

    if(multipart->hasContent(_XPLATSTR("RowFormat")))
    {
        if(multipart->hasContent(_XPLATSTR("RowFormat")))
        {
            <DATA_TYPE_START>TableRowFormat<DATA_TYPE_END> newItem(new TableRowFormat());
            newItem->fromMultiPart(multipart, _XPLATSTR("RowFormat."));
            setRowFormat( newItem );
        }
    }
    {
        m_TableCellList.clear();
        if(multipart->hasContent(_XPLATSTR("TableCellList")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("TableCellList")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_TableCellList), [&](web::json::value item) {
            if(item.is_null())
            {
                return <DATA_TYPE_START>TableCell<DATA_TYPE_END>(nullptr) ;
            }
            else
            {
                <DATA_TYPE_START>TableCell<DATA_TYPE_END> newItem(new TableCell());
                newItem->fromJson(item);
                return newItem ;
            }
        });
        }
    }
}

<DATA_TYPE_START>TableRowFormat<DATA_TYPE_END> TableRow::getRowFormat() const
{
    return m_RowFormat;
}


void TableRow::setRowFormat(<DATA_TYPE_START>TableRowFormat<DATA_TYPE_END> value)
{
    m_RowFormat = value;
    m_RowFormatIsSet = true;
}
bool TableRow::rowFormatIsSet() const
{
    return m_RowFormatIsSet;
}

void TableRow::unsetRowFormat()
{
    m_RowFormatIsSet = false;
}

<DATA_TYPE_START>List<TableCell><DATA_TYPE_END>& TableRow::getTableCellList()
{
    return m_TableCellList;
}

void TableRow::setTableCellList(<DATA_TYPE_START>List<TableCell><DATA_TYPE_END> const& value)
{
    m_TableCellList = value;
    m_TableCellListIsSet = true;
}
bool TableRow::tableCellListIsSet() const
{
    return m_TableCellListIsSet;
}

void TableRow::unsetTableCellList()
{
    m_TableCellListIsSet = false;
}

}
}
}
}
}

