/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="WordsApiLink.cpp">
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


#include "WordsApiLink.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

WordsApiLink::WordsApiLink()
{
}

WordsApiLink::~WordsApiLink()
{
}

void WordsApiLink::validate()
{
    // TODO: implement validation
}

web::json::value WordsApiLink::toJson() const
{
    web::json::value val = this->Link::toJson();


    return val;
}

void WordsApiLink::fromJson(web::json::value& val)
{
    this->Link::fromJson(val);

}

void WordsApiLink::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_HrefIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Href"), m_Href));
        
    }
    if(m_RelIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Rel"), m_Rel));
        
    }
    if(m_TypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Type"), m_Type));
        
    }
    if(m_TitleIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Title"), m_Title));
        
    }
}

void WordsApiLink::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("Href")))
    {
        setHref(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Href"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Rel")))
    {
        setRel(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Rel"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Type")))
    {
        setType(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Type"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Title")))
    {
        setTitle(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Title"))));
    }
}

}
}
}
}

