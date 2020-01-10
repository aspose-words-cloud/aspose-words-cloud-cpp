/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Field.cpp">
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


#include "Field.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

Field::Field()
{
    m_LocaleId = utility::conversions::to_string_t("");
    m_LocaleIdIsSet = false;
    m_Result = utility::conversions::to_string_t("");
    m_ResultIsSet = false;
}

Field::~Field()
{
}

void Field::validate()
{
    // TODO: implement validation
}

web::json::value Field::toJson() const
{
    web::json::value val = this->FieldLink::toJson();

    if(m_LocaleIdIsSet)
    {
        val[_XPLATSTR("localeId")] = ModelBase::toJson(m_LocaleId);
    }
    if(m_ResultIsSet)
    {
        val[_XPLATSTR("result")] = ModelBase::toJson(m_Result);
    }

    return val;
}

void Field::fromJson(web::json::value& val)
{
    this->FieldLink::fromJson(val);

    if(val.has_field(_XPLATSTR("localeId")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("localeId")];
        if(!fieldValue.is_null())
        {
            setLocaleId(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("result")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("result")];
        if(!fieldValue.is_null())
        {
            setResult(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void Field::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_LinkIsSet)
    {
        if (m_Link.get())
        {
            m_Link->toMultipart(multipart, _XPLATSTR("link."));
        }
        
    }
    if(m_NodeIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("nodeId"), m_NodeId));
        
    }
    if(m_FieldCodeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("fieldCode"), m_FieldCode));
        
    }
    if(m_LocaleIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("localeId"), m_LocaleId));
        
    }
    if(m_ResultIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("result"), m_Result));
        
    }
}

void Field::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("link")))
    {
        if(multipart->hasContent(_XPLATSTR("link")))
        {
            std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
            newItem->fromMultiPart(multipart, _XPLATSTR("link."));
            setLink( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("nodeId")))
    {
        setNodeId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("nodeId"))));
    }
    if(multipart->hasContent(_XPLATSTR("fieldCode")))
    {
        setFieldCode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("fieldCode"))));
    }
    if(multipart->hasContent(_XPLATSTR("localeId")))
    {
        setLocaleId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("localeId"))));
    }
    if(multipart->hasContent(_XPLATSTR("result")))
    {
        setResult(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("result"))));
    }
}

utility::string_t Field::getLocaleId() const
{
    return m_LocaleId;
}


void Field::setLocaleId(utility::string_t value)
{
    m_LocaleId = value;
    m_LocaleIdIsSet = true;
}
bool Field::localeIdIsSet() const
{
    return m_LocaleIdIsSet;
}

void Field::unsetLocaleId()
{
    m_LocaleIdIsSet = false;
}

utility::string_t Field::getResult() const
{
    return m_Result;
}


void Field::setResult(utility::string_t value)
{
    m_Result = value;
    m_ResultIsSet = true;
}
bool Field::resultIsSet() const
{
    return m_ResultIsSet;
}

void Field::unsetResult()
{
    m_ResultIsSet = false;
}

}
}
}
}
}

