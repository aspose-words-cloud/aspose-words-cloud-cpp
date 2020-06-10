/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SectionPageSetupResponse.cpp">
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

#include "SectionPageSetupResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

SectionPageSetupResponse::SectionPageSetupResponse()
{
    m_PageSetupIsSet = false;

}

SectionPageSetupResponse::~SectionPageSetupResponse()
{
}

void SectionPageSetupResponse::validate()
{
    // TODO: implement validation
}

web::json::value SectionPageSetupResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();
    if(m_PageSetupIsSet)
    {
        val[_XPLATSTR("PageSetup")] = ModelBase::toJson(m_PageSetup);
    }

    return val;
}

void SectionPageSetupResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("PageSetup")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("PageSetup")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<PageSetup> newItem(new PageSetup());
            newItem->fromJson(fieldValue);
            setPageSetup( newItem );
        }
    }

}

void SectionPageSetupResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    WordsResponse::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_PageSetupIsSet)
    {
        if (m_PageSetup.get())
        {
            m_PageSetup->toMultipart(multipart, _XPLATSTR("PageSetup."));
        }
    }

}

void SectionPageSetupResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

std::shared_ptr<PageSetup> SectionPageSetupResponse::getPageSetup() const
{
    return m_PageSetup;
}


void SectionPageSetupResponse::setPageSetup(std::shared_ptr<PageSetup> value)
{
    m_PageSetup = value;
    m_PageSetupIsSet = true;
}

bool SectionPageSetupResponse::pageSetupIsSet() const
{
    return m_PageSetupIsSet;
}

void SectionPageSetupResponse::unsetPageSetup()
{
    m_PageSetupIsSet = false;
}

}
}
}
}
}
