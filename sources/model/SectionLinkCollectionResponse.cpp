/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SectionLinkCollectionResponse.cpp">
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


#include "SectionLinkCollectionResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

SectionLinkCollectionResponse::SectionLinkCollectionResponse()
{
    m_SectionsIsSet = false;
}

SectionLinkCollectionResponse::~SectionLinkCollectionResponse()
{
}

void SectionLinkCollectionResponse::validate()
{
    // TODO: implement validation
}

web::json::value SectionLinkCollectionResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();

    if(m_SectionsIsSet)
    {
        val[_XPLATSTR("Sections")] = ModelBase::toJson(m_Sections);
    }

    return val;
}

void SectionLinkCollectionResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("Sections")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Sections")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<SectionLinkCollection> newItem(new SectionLinkCollection());
            newItem->fromJson(fieldValue);
            setSections( newItem );
        }
    }
}

void SectionLinkCollectionResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_RequestIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RequestId"), m_RequestId));
        
    }
    if(m_SectionsIsSet)
    {
        if (m_Sections.get())
        {
            m_Sections->toMultipart(multipart, _XPLATSTR("Sections."));
        }
        
    }
}

void SectionLinkCollectionResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("RequestId")))
    {
        setRequestId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("RequestId"))));
    }
    if(multipart->hasContent(_XPLATSTR("Sections")))
    {
        if(multipart->hasContent(_XPLATSTR("Sections")))
        {
            std::shared_ptr<SectionLinkCollection> newItem(new SectionLinkCollection());
            newItem->fromMultiPart(multipart, _XPLATSTR("Sections."));
            setSections( newItem );
        }
    }
}

std::shared_ptr<SectionLinkCollection> SectionLinkCollectionResponse::getSections() const
{
    return m_Sections;
}


void SectionLinkCollectionResponse::setSections(std::shared_ptr<SectionLinkCollection> value)
{
    m_Sections = value;
    m_SectionsIsSet = true;
}
bool SectionLinkCollectionResponse::sectionsIsSet() const
{
    return m_SectionsIsSet;
}

void SectionLinkCollectionResponse::unsetSections()
{
    m_SectionsIsSet = false;
}

}
}
}
}
}

