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
        val[_XPLATSTR("comparingWithDocument")] = ModelBase::toJson(m_ComparingWithDocument);
    }
    if(m_AuthorIsSet)
    {
        val[_XPLATSTR("author")] = ModelBase::toJson(m_Author);
    }
    if(m_DateTimeIsSet)
    {
        val[_XPLATSTR("dateTime")] = ModelBase::toJson(m_DateTime);
    }

    return val;
}

void CompareData::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("comparingWithDocument")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("comparingWithDocument")];
        if(!fieldValue.is_null())
        {
            setComparingWithDocument(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("author")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("author")];
        if(!fieldValue.is_null())
        {
            setAuthor(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("dateTime")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("dateTime")];
        if(!fieldValue.is_null())
        {
            setDateTime(ModelBase::dateFromJson(fieldValue));
        }
    }
}

void CompareData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_ComparingWithDocumentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("comparingWithDocument"), m_ComparingWithDocument));
        
    }
    if(m_AuthorIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("author"), m_Author));
        
    }
    if(m_DateTimeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("dateTime"), m_DateTime));
        
    }
}

void CompareData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("comparingWithDocument")))
    {
        setComparingWithDocument(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("comparingWithDocument"))));
    }
    if(multipart->hasContent(_XPLATSTR("author")))
    {
        setAuthor(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("author"))));
    }
    if(multipart->hasContent(_XPLATSTR("dateTime")))
    {
        setDateTime(ModelBase::dateFromHttpContent(multipart->getContent(_XPLATSTR("dateTime"))));
    }
}

utility::string_t CompareData::getComparingWithDocument() const
{
    return m_ComparingWithDocument;
}


void CompareData::setComparingWithDocument(utility::string_t value)
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

utility::string_t CompareData::getAuthor() const
{
    return m_Author;
}


void CompareData::setAuthor(utility::string_t value)
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

utility::datetime CompareData::getDateTime() const
{
    return m_DateTime;
}


void CompareData::setDateTime(utility::datetime value)
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

}
}
}
}
}

