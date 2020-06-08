/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TableCellInsert.cpp">
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


#include "TableCellInsert.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

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
        val[_XPLATSTR("InsertAfter")] = ModelBase::toJson(m_InsertAfter);
    }

    return val;
}

void TableCellInsert::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("InsertAfter")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("InsertAfter")];
        if(!fieldValue.is_null())
        {
            setInsertAfter(ModelBase::int?FromJson(fieldValue));
        }
    }
}

void TableCellInsert::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_InsertAfterIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("InsertAfter"), m_InsertAfter));
        
    }
}

void TableCellInsert::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    

    if(multipart->hasContent(_XPLATSTR("InsertAfter")))
    {
        setInsertAfter(ModelBase::int?FromHttpContent(multipart->getContent(_XPLATSTR("InsertAfter"))));
    }
}

<DATA_TYPE_START>int?<DATA_TYPE_END> TableCellInsert::getInsertAfter() const
{
    return m_InsertAfter;
}


void TableCellInsert::setInsertAfter(<DATA_TYPE_START>int?<DATA_TYPE_END> value)
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
}

