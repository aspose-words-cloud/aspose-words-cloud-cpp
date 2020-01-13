/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TableLinkCollectionResponse.cpp">
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


#include "TableLinkCollectionResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

TableLinkCollectionResponse::TableLinkCollectionResponse()
{
    m_TablesIsSet = false;
}

TableLinkCollectionResponse::~TableLinkCollectionResponse()
{
}

void TableLinkCollectionResponse::validate()
{
    // TODO: implement validation
}

web::json::value TableLinkCollectionResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();

    if(m_TablesIsSet)
    {
        val[_XPLATSTR("Tables")] = ModelBase::toJson(m_Tables);
    }

    return val;
}

void TableLinkCollectionResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("Tables")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Tables")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<TableLinkCollection> newItem(new TableLinkCollection());
            newItem->fromJson(fieldValue);
            setTables( newItem );
        }
    }
}

void TableLinkCollectionResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_RequestIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RequestId"), m_RequestId));
        
    }
    if(m_TablesIsSet)
    {
        if (m_Tables.get())
        {
            m_Tables->toMultipart(multipart, _XPLATSTR("Tables."));
        }
        
    }
}

void TableLinkCollectionResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("RequestId")))
    {
        setRequestId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("RequestId"))));
    }
    if(multipart->hasContent(_XPLATSTR("Tables")))
    {
        if(multipart->hasContent(_XPLATSTR("Tables")))
        {
            std::shared_ptr<TableLinkCollection> newItem(new TableLinkCollection());
            newItem->fromMultiPart(multipart, _XPLATSTR("Tables."));
            setTables( newItem );
        }
    }
}

std::shared_ptr<TableLinkCollection> TableLinkCollectionResponse::getTables() const
{
    return m_Tables;
}


void TableLinkCollectionResponse::setTables(std::shared_ptr<TableLinkCollection> value)
{
    m_Tables = value;
    m_TablesIsSet = true;
}
bool TableLinkCollectionResponse::tablesIsSet() const
{
    return m_TablesIsSet;
}

void TableLinkCollectionResponse::unsetTables()
{
    m_TablesIsSet = false;
}

}
}
}
}
}

