/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="CompareData.cpp">
*   Copyright (c) 2020 Aspose.Words for Cloud
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
    m_Author = utility::conversions::to_string_t("");
    m_AuthorIsSet = false;

    m_CompareOptionsIsSet = false;
    m_ComparingWithDocument = utility::conversions::to_string_t("");
    m_ComparingWithDocumentIsSet = false;
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
    if(m_AuthorIsSet)
    {
        val[_XPLATSTR("Author")] = ModelBase::toJson(m_Author);
    }
    if(m_CompareOptionsIsSet)
    {
        val[_XPLATSTR("CompareOptions")] = ModelBase::toJson(m_CompareOptions);
    }
    if(m_ComparingWithDocumentIsSet)
    {
        val[_XPLATSTR("ComparingWithDocument")] = ModelBase::toJson(m_ComparingWithDocument);
    }
    if(m_DateTimeIsSet)
    {
        val[_XPLATSTR("DateTime")] = ModelBase::toJson(m_DateTime);
    }

    return val;
}

void CompareData::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("Author")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Author")];
        if(!fieldValue.is_null())
        {
           setAuthor(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("CompareOptions")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("CompareOptions")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<CompareOptions> newItem(new CompareOptions());
            newItem->fromJson(fieldValue);
            setCompareOptions( newItem );
        }
    }


    if(val.has_field(_XPLATSTR("ComparingWithDocument")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ComparingWithDocument")];
        if(!fieldValue.is_null())
        {
           setComparingWithDocument(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("DateTime")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DateTime")];
        if(!fieldValue.is_null())
        {
           setDateTime(ModelBase::dateTimeFromJson(fieldValue));
        }
    }

}

void CompareData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_AuthorIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Author"), m_Author));
    }


    if(m_CompareOptionsIsSet)
    {
        if (m_CompareOptions.get())
        {
            m_CompareOptions->toMultipart(multipart, _XPLATSTR("CompareOptions."));
        }
    }


    if(m_ComparingWithDocumentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ComparingWithDocument"), m_ComparingWithDocument));
    }


    if(m_DateTimeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("DateTime"), m_DateTime));
    }

}

void CompareData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
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

std::shared_ptr<CompareOptions> CompareData::getCompareOptions() const
{
    return m_CompareOptions;
}


void CompareData::setCompareOptions(std::shared_ptr<CompareOptions> value)
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
