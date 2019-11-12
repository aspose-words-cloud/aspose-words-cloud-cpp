/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SectionResponse.cpp">
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


#include "SectionResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

SectionResponse::SectionResponse()
{
    m_SectionIsSet = false;
}

SectionResponse::~SectionResponse()
{
}

void SectionResponse::validate()
{
    // TODO: implement validation
}

web::json::value SectionResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();

    if(m_SectionIsSet)
    {
        val[_XPLATSTR("Section")] = ModelBase::toJson(m_Section);
    }

    return val;
}

void SectionResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("Section")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Section")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Section> newItem(new Section());
            newItem->fromJson(fieldValue);
            setSection( newItem );
        }
    }
}

void SectionResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_RequestIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RequestId"), m_RequestId));
        
    }
    if(m_SectionIsSet)
    {
        if (m_Section.get())
        {
            m_Section->toMultipart(multipart, _XPLATSTR("Section."));
        }
        
    }
}

void SectionResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("RequestId")))
    {
        setRequestId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("RequestId"))));
    }
    if(multipart->hasContent(_XPLATSTR("Section")))
    {
        if(multipart->hasContent(_XPLATSTR("Section")))
        {
            std::shared_ptr<Section> newItem(new Section());
            newItem->fromMultiPart(multipart, _XPLATSTR("Section."));
            setSection( newItem );
        }
    }
}

std::shared_ptr<Section> SectionResponse::getSection() const
{
    return m_Section;
}


void SectionResponse::setSection(std::shared_ptr<Section> value)
{
    m_Section = value;
    m_SectionIsSet = true;
}
bool SectionResponse::sectionIsSet() const
{
    return m_SectionIsSet;
}

void SectionResponse::unsetSection()
{
    m_SectionIsSet = false;
}

}
}
}
}
}

