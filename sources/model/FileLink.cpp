/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FileLink.cpp">
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


#include "FileLink.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

FileLink::FileLink()
{
}

FileLink::~FileLink()
{
}

void FileLink::validate()
{
    // TODO: implement validation
}

web::json::value FileLink::toJson() const
{
    web::json::value val = this->Link::toJson();


    return val;
}

void FileLink::fromJson(web::json::value& val)
{
    this->Link::fromJson(val);

}

void FileLink::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_HrefIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Href"), m_Href));
        
    }
    if(m_RelIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Rel"), m_Rel));
        
    }
    if(m_TypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Type"), m_Type));
        
    }
    if(m_TitleIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Title"), m_Title));
        
    }
}

void FileLink::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("Href")))
    {
        setHref(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Href"))));
    }
    if(multipart->hasContent(_XPLATSTR("Rel")))
    {
        setRel(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Rel"))));
    }
    if(multipart->hasContent(_XPLATSTR("Type")))
    {
        setType(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Type"))));
    }
    if(multipart->hasContent(_XPLATSTR("Title")))
    {
        setTitle(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Title"))));
    }
}

}
}
}
}

