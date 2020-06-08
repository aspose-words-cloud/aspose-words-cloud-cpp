/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="CompareData.cpp">
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


#include "CompareData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

CompareData::CompareData()
{
    m_ComparingWithDocument = utility::conversions::to_string_t("");
    m_ComparingWithDocumentIsSet = false;
    m_Author = utility::conversions::to_string_t("");
    m_AuthorIsSet = false;
    m_DateTime = utility::datetime();
    m_DateTimeIsSet = false;
    m_CompareOptionsIsSet = false;
}

CompareData::~CompareData()
{
}

void CompareData::validate()
{
    // TODO: implement validation
}

web::json::value CompareData::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_ComparingWithDocumentIsSet)
    {
        val[_XPLATSTR("ComparingWithDocument")] = ModelBase::toJson(m_ComparingWithDocument);
    }
    if(m_AuthorIsSet)
    {
        val[_XPLATSTR("Author")] = ModelBase::toJson(m_Author);
    }
    if(m_DateTimeIsSet)
    {
        val[_XPLATSTR("DateTime")] = ModelBase::toJson(m_DateTime);
    }
    if(m_CompareOptionsIsSet)
    {
        val[_XPLATSTR("CompareOptions")] = ModelBase::toJson(m_CompareOptions);
    }

    return val;
}

void CompareData::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("ComparingWithDocument")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ComparingWithDocument")];
        if(!fieldValue.is_null())
        {
            setComparingWithDocument(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Author")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Author")];
        if(!fieldValue.is_null())
        {
            setAuthor(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("DateTime")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DateTime")];
        if(!fieldValue.is_null())
        {
            setDateTime(ModelBase::DateTime?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("CompareOptions")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("CompareOptions")];
        if(!fieldValue.is_null())
        {
            <DATA_TYPE_START>CompareOptions<DATA_TYPE_END> newItem(new CompareOptions());
            newItem->fromJson(fieldValue);
            setCompareOptions( newItem );
        }
    }
}

void CompareData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_ComparingWithDocumentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ComparingWithDocument"), m_ComparingWithDocument));
        
    }
    if(m_AuthorIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Author"), m_Author));
        
    }
    if(m_DateTimeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("DateTime"), m_DateTime));
        
    }
    if(m_CompareOptionsIsSet)
    {
        if (m_CompareOptions.get())
        {
            m_CompareOptions->toMultipart(multipart, _XPLATSTR("CompareOptions."));
        }
        
    }
}

void CompareData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    

    if(multipart->hasContent(_XPLATSTR("ComparingWithDocument")))
    {
        setComparingWithDocument(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ComparingWithDocument"))));
    }
    if(multipart->hasContent(_XPLATSTR("Author")))
    {
        setAuthor(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Author"))));
    }
    if(multipart->hasContent(_XPLATSTR("DateTime")))
    {
        setDateTime(ModelBase::DateTime?FromHttpContent(multipart->getContent(_XPLATSTR("DateTime"))));
    }
    if(multipart->hasContent(_XPLATSTR("CompareOptions")))
    {
        if(multipart->hasContent(_XPLATSTR("CompareOptions")))
        {
            <DATA_TYPE_START>CompareOptions<DATA_TYPE_END> newItem(new CompareOptions());
            newItem->fromMultiPart(multipart, _XPLATSTR("CompareOptions."));
            setCompareOptions( newItem );
        }
    }
}

<DATA_TYPE_START>string<DATA_TYPE_END> CompareData::getComparingWithDocument() const
{
    return m_ComparingWithDocument;
}


void CompareData::setComparingWithDocument(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_ComparingWithDocument = value;
    m_ComparingWithDocumentIsSet = true;
}
bool CompareData::comparingWithDocumentIsSet() const
{
    return m_ComparingWithDocumentIsSet;
}

void CompareData::unsetComparingWithDocument()
{
    m_ComparingWithDocumentIsSet = false;
}

<DATA_TYPE_START>string<DATA_TYPE_END> CompareData::getAuthor() const
{
    return m_Author;
}


void CompareData::setAuthor(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_Author = value;
    m_AuthorIsSet = true;
}
bool CompareData::authorIsSet() const
{
    return m_AuthorIsSet;
}

void CompareData::unsetAuthor()
{
    m_AuthorIsSet = false;
}

<DATA_TYPE_START>DateTime?<DATA_TYPE_END> CompareData::getDateTime() const
{
    return m_DateTime;
}


void CompareData::setDateTime(<DATA_TYPE_START>DateTime?<DATA_TYPE_END> value)
{
    m_DateTime = value;
    m_DateTimeIsSet = true;
}
bool CompareData::dateTimeIsSet() const
{
    return m_DateTimeIsSet;
}

void CompareData::unsetDateTime()
{
    m_DateTimeIsSet = false;
}

<DATA_TYPE_START>CompareOptions<DATA_TYPE_END> CompareData::getCompareOptions() const
{
    return m_CompareOptions;
}


void CompareData::setCompareOptions(<DATA_TYPE_START>CompareOptions<DATA_TYPE_END> value)
{
    m_CompareOptions = value;
    m_CompareOptionsIsSet = true;
}
bool CompareData::compareOptionsIsSet() const
{
    return m_CompareOptionsIsSet;
}

void CompareData::unsetCompareOptions()
{
    m_CompareOptionsIsSet = false;
}

}
}
}
}
}

