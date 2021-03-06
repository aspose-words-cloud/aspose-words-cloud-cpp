/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="CompareOptions.cpp">
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

#include "CompareOptions.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

CompareOptions::CompareOptions()
{
    m_IgnoreCaseChanges = false;
    m_IgnoreCaseChangesIsSet = false;
    m_IgnoreComments = false;
    m_IgnoreCommentsIsSet = false;
    m_IgnoreFields = false;
    m_IgnoreFieldsIsSet = false;
    m_IgnoreFootnotes = false;
    m_IgnoreFootnotesIsSet = false;
    m_IgnoreFormatting = false;
    m_IgnoreFormattingIsSet = false;
    m_IgnoreHeadersAndFooters = false;
    m_IgnoreHeadersAndFootersIsSet = false;
    m_IgnoreTables = false;
    m_IgnoreTablesIsSet = false;
    m_IgnoreTextboxes = false;
    m_IgnoreTextboxesIsSet = false;

    m_TargetIsSet = false;

}

CompareOptions::~CompareOptions()
{
}

void CompareOptions::validate()
{
    // TODO: implement validation
}

web::json::value CompareOptions::toJson() const
{
    web::json::value val = web::json::value::object();
    if(m_IgnoreCaseChangesIsSet)
    {
        val[_XPLATSTR("IgnoreCaseChanges")] = ModelBase::toJson(m_IgnoreCaseChanges);
    }
    if(m_IgnoreCommentsIsSet)
    {
        val[_XPLATSTR("IgnoreComments")] = ModelBase::toJson(m_IgnoreComments);
    }
    if(m_IgnoreFieldsIsSet)
    {
        val[_XPLATSTR("IgnoreFields")] = ModelBase::toJson(m_IgnoreFields);
    }
    if(m_IgnoreFootnotesIsSet)
    {
        val[_XPLATSTR("IgnoreFootnotes")] = ModelBase::toJson(m_IgnoreFootnotes);
    }
    if(m_IgnoreFormattingIsSet)
    {
        val[_XPLATSTR("IgnoreFormatting")] = ModelBase::toJson(m_IgnoreFormatting);
    }
    if(m_IgnoreHeadersAndFootersIsSet)
    {
        val[_XPLATSTR("IgnoreHeadersAndFooters")] = ModelBase::toJson(m_IgnoreHeadersAndFooters);
    }
    if(m_IgnoreTablesIsSet)
    {
        val[_XPLATSTR("IgnoreTables")] = ModelBase::toJson(m_IgnoreTables);
    }
    if(m_IgnoreTextboxesIsSet)
    {
        val[_XPLATSTR("IgnoreTextboxes")] = ModelBase::toJson(m_IgnoreTextboxes);
    }
    if(m_TargetIsSet)
    {
        val[_XPLATSTR("Target")] = ModelBase::toJson(m_Target);
    }

    return val;
}

void CompareOptions::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("IgnoreCaseChanges")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("IgnoreCaseChanges")];
        if(!fieldValue.is_null())
        {
           setIgnoreCaseChanges(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("IgnoreComments")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("IgnoreComments")];
        if(!fieldValue.is_null())
        {
           setIgnoreComments(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("IgnoreFields")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("IgnoreFields")];
        if(!fieldValue.is_null())
        {
           setIgnoreFields(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("IgnoreFootnotes")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("IgnoreFootnotes")];
        if(!fieldValue.is_null())
        {
           setIgnoreFootnotes(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("IgnoreFormatting")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("IgnoreFormatting")];
        if(!fieldValue.is_null())
        {
           setIgnoreFormatting(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("IgnoreHeadersAndFooters")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("IgnoreHeadersAndFooters")];
        if(!fieldValue.is_null())
        {
           setIgnoreHeadersAndFooters(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("IgnoreTables")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("IgnoreTables")];
        if(!fieldValue.is_null())
        {
           setIgnoreTables(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("IgnoreTextboxes")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("IgnoreTextboxes")];
        if(!fieldValue.is_null())
        {
           setIgnoreTextboxes(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("Target")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Target")];
        if(!fieldValue.is_null())
        {
           setTarget(ModelBase::enumFromJson(fieldValue));
        }
    }

}

void CompareOptions::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_IgnoreCaseChangesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("IgnoreCaseChanges"), m_IgnoreCaseChanges));
    }


    if(m_IgnoreCommentsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("IgnoreComments"), m_IgnoreComments));
    }


    if(m_IgnoreFieldsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("IgnoreFields"), m_IgnoreFields));
    }


    if(m_IgnoreFootnotesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("IgnoreFootnotes"), m_IgnoreFootnotes));
    }


    if(m_IgnoreFormattingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("IgnoreFormatting"), m_IgnoreFormatting));
    }


    if(m_IgnoreHeadersAndFootersIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("IgnoreHeadersAndFooters"), m_IgnoreHeadersAndFooters));
    }


    if(m_IgnoreTablesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("IgnoreTables"), m_IgnoreTables));
    }


    if(m_IgnoreTextboxesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("IgnoreTextboxes"), m_IgnoreTextboxes));
    }


    if(m_TargetIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Target"), m_Target));
    }

}

void CompareOptions::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

bool CompareOptions::isIgnoreCaseChanges() const
{
    return m_IgnoreCaseChanges;
}


void CompareOptions::setIgnoreCaseChanges(bool value)
{
    m_IgnoreCaseChanges = value;
    m_IgnoreCaseChangesIsSet = true;
}

bool CompareOptions::ignoreCaseChangesIsSet() const
{
    return m_IgnoreCaseChangesIsSet;
}

void CompareOptions::unsetIgnoreCaseChanges()
{
    m_IgnoreCaseChangesIsSet = false;
}

bool CompareOptions::isIgnoreComments() const
{
    return m_IgnoreComments;
}


void CompareOptions::setIgnoreComments(bool value)
{
    m_IgnoreComments = value;
    m_IgnoreCommentsIsSet = true;
}

bool CompareOptions::ignoreCommentsIsSet() const
{
    return m_IgnoreCommentsIsSet;
}

void CompareOptions::unsetIgnoreComments()
{
    m_IgnoreCommentsIsSet = false;
}

bool CompareOptions::isIgnoreFields() const
{
    return m_IgnoreFields;
}


void CompareOptions::setIgnoreFields(bool value)
{
    m_IgnoreFields = value;
    m_IgnoreFieldsIsSet = true;
}

bool CompareOptions::ignoreFieldsIsSet() const
{
    return m_IgnoreFieldsIsSet;
}

void CompareOptions::unsetIgnoreFields()
{
    m_IgnoreFieldsIsSet = false;
}

bool CompareOptions::isIgnoreFootnotes() const
{
    return m_IgnoreFootnotes;
}


void CompareOptions::setIgnoreFootnotes(bool value)
{
    m_IgnoreFootnotes = value;
    m_IgnoreFootnotesIsSet = true;
}

bool CompareOptions::ignoreFootnotesIsSet() const
{
    return m_IgnoreFootnotesIsSet;
}

void CompareOptions::unsetIgnoreFootnotes()
{
    m_IgnoreFootnotesIsSet = false;
}

bool CompareOptions::isIgnoreFormatting() const
{
    return m_IgnoreFormatting;
}


void CompareOptions::setIgnoreFormatting(bool value)
{
    m_IgnoreFormatting = value;
    m_IgnoreFormattingIsSet = true;
}

bool CompareOptions::ignoreFormattingIsSet() const
{
    return m_IgnoreFormattingIsSet;
}

void CompareOptions::unsetIgnoreFormatting()
{
    m_IgnoreFormattingIsSet = false;
}

bool CompareOptions::isIgnoreHeadersAndFooters() const
{
    return m_IgnoreHeadersAndFooters;
}


void CompareOptions::setIgnoreHeadersAndFooters(bool value)
{
    m_IgnoreHeadersAndFooters = value;
    m_IgnoreHeadersAndFootersIsSet = true;
}

bool CompareOptions::ignoreHeadersAndFootersIsSet() const
{
    return m_IgnoreHeadersAndFootersIsSet;
}

void CompareOptions::unsetIgnoreHeadersAndFooters()
{
    m_IgnoreHeadersAndFootersIsSet = false;
}

bool CompareOptions::isIgnoreTables() const
{
    return m_IgnoreTables;
}


void CompareOptions::setIgnoreTables(bool value)
{
    m_IgnoreTables = value;
    m_IgnoreTablesIsSet = true;
}

bool CompareOptions::ignoreTablesIsSet() const
{
    return m_IgnoreTablesIsSet;
}

void CompareOptions::unsetIgnoreTables()
{
    m_IgnoreTablesIsSet = false;
}

bool CompareOptions::isIgnoreTextboxes() const
{
    return m_IgnoreTextboxes;
}


void CompareOptions::setIgnoreTextboxes(bool value)
{
    m_IgnoreTextboxes = value;
    m_IgnoreTextboxesIsSet = true;
}

bool CompareOptions::ignoreTextboxesIsSet() const
{
    return m_IgnoreTextboxesIsSet;
}

void CompareOptions::unsetIgnoreTextboxes()
{
    m_IgnoreTextboxesIsSet = false;
}

utility::string_t CompareOptions::getTarget() const
{
    return m_Target;
}


void CompareOptions::setTarget(utility::string_t value)
{
    m_Target = value;
    m_TargetIsSet = true;
}

bool CompareOptions::targetIsSet() const
{
    return m_TargetIsSet;
}

void CompareOptions::unsetTarget()
{
    m_TargetIsSet = false;
}

}
}
}
}
}
