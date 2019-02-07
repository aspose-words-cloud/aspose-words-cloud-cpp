/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FieldLink.cpp">
*   Copyright (c) 2018 Aspose.Words for Cloud
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


#include "FieldLink.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

FieldLink::FieldLink()
{
    m_FieldCode = utility::conversions::to_string_t("");
    m_FieldCodeIsSet = false;
}

FieldLink::~FieldLink()
{
}

void FieldLink::validate()
{
    // TODO: implement validation
}

web::json::value FieldLink::toJson() const
{
    web::json::value val = this->NodeLink::toJson();

    if(m_FieldCodeIsSet)
    {
        val[_XPLATSTR("FieldCode")] = ModelBase::toJson(m_FieldCode);
    }

    return val;
}

void FieldLink::fromJson(web::json::value& val)
{
    this->NodeLink::fromJson(val);

    if(val.has_field(_XPLATSTR("FieldCode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("FieldCode")];
        if(!fieldValue.is_null())
        {
            setFieldCode(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void FieldLink::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
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
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("NodeId"), m_NodeId));
        
    }
    if(m_FieldCodeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("FieldCode"), m_FieldCode));
        
    }
}

void FieldLink::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(_XPLATSTR("NodeId")))
    {
        setNodeId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("NodeId"))));
    }
    if(multipart->hasContent(_XPLATSTR("FieldCode")))
    {
        setFieldCode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("FieldCode"))));
    }
}

utility::string_t FieldLink::getFieldCode() const
{
    return m_FieldCode;
}


void FieldLink::setFieldCode(utility::string_t value)
{
    m_FieldCode = value;
    m_FieldCodeIsSet = true;
}
bool FieldLink::fieldCodeIsSet() const
{
    return m_FieldCodeIsSet;
}

void FieldLink::unsetFieldCode()
{
    m_FieldCodeIsSet = false;
}

}
}
}
}

