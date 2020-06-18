/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TextSaveOptionsData.cpp">
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

#include "TextSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

TextSaveOptionsData::TextSaveOptionsData()
{
    m_AddBidiMarks = false;
    m_AddBidiMarksIsSet = false;
    m_PreserveTableLayout = false;
    m_PreserveTableLayoutIsSet = false;
    m_SimplifyListLabels = false;
    m_SimplifyListLabelsIsSet = false;

}

TextSaveOptionsData::~TextSaveOptionsData()
{
}

void TextSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value TextSaveOptionsData::toJson() const
{
    web::json::value val = this->TxtSaveOptionsBaseData::toJson();
    if(m_AddBidiMarksIsSet)
    {
        val[_XPLATSTR("AddBidiMarks")] = ModelBase::toJson(m_AddBidiMarks);
    }
    if(m_PreserveTableLayoutIsSet)
    {
        val[_XPLATSTR("PreserveTableLayout")] = ModelBase::toJson(m_PreserveTableLayout);
    }
    if(m_SimplifyListLabelsIsSet)
    {
        val[_XPLATSTR("SimplifyListLabels")] = ModelBase::toJson(m_SimplifyListLabels);
    }

    return val;
}

void TextSaveOptionsData::fromJson(web::json::value& val)
{
    this->TxtSaveOptionsBaseData::fromJson(val);

    if(val.has_field(_XPLATSTR("AddBidiMarks")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("AddBidiMarks")];
        if(!fieldValue.is_null())
        {
           setAddBidiMarks(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("PreserveTableLayout")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("PreserveTableLayout")];
        if(!fieldValue.is_null())
        {
           setPreserveTableLayout(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("SimplifyListLabels")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SimplifyListLabels")];
        if(!fieldValue.is_null())
        {
           setSimplifyListLabels(ModelBase::booleanFromJson(fieldValue));
        }
    }

}

void TextSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    TxtSaveOptionsBaseData::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_AddBidiMarksIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("AddBidiMarks"), m_AddBidiMarks));
    }


    if(m_PreserveTableLayoutIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("PreserveTableLayout"), m_PreserveTableLayout));
    }


    if(m_SimplifyListLabelsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("SimplifyListLabels"), m_SimplifyListLabels));
    }

}

void TextSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

bool TextSaveOptionsData::isAddBidiMarks() const
{
    return m_AddBidiMarks;
}


void TextSaveOptionsData::setAddBidiMarks(bool value)
{
    m_AddBidiMarks = value;
    m_AddBidiMarksIsSet = true;
}

bool TextSaveOptionsData::addBidiMarksIsSet() const
{
    return m_AddBidiMarksIsSet;
}

void TextSaveOptionsData::unsetAddBidiMarks()
{
    m_AddBidiMarksIsSet = false;
}

bool TextSaveOptionsData::isPreserveTableLayout() const
{
    return m_PreserveTableLayout;
}


void TextSaveOptionsData::setPreserveTableLayout(bool value)
{
    m_PreserveTableLayout = value;
    m_PreserveTableLayoutIsSet = true;
}

bool TextSaveOptionsData::preserveTableLayoutIsSet() const
{
    return m_PreserveTableLayoutIsSet;
}

void TextSaveOptionsData::unsetPreserveTableLayout()
{
    m_PreserveTableLayoutIsSet = false;
}

bool TextSaveOptionsData::isSimplifyListLabels() const
{
    return m_SimplifyListLabels;
}


void TextSaveOptionsData::setSimplifyListLabels(bool value)
{
    m_SimplifyListLabels = value;
    m_SimplifyListLabelsIsSet = true;
}

bool TextSaveOptionsData::simplifyListLabelsIsSet() const
{
    return m_SimplifyListLabelsIsSet;
}

void TextSaveOptionsData::unsetSimplifyListLabels()
{
    m_SimplifyListLabelsIsSet = false;
}

}
}
}
}
}
