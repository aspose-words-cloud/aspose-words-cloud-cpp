/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SplitDocumentResult.cpp">
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

#include "SplitDocumentResult.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

SplitDocumentResult::SplitDocumentResult()
{
    m_PagesIsSet = false;

    m_SourceDocumentIsSet = false;

    m_ZippedPagesIsSet = false;

}

SplitDocumentResult::~SplitDocumentResult()
{
}

void SplitDocumentResult::validate()
{
    // TODO: implement validation
}

web::json::value SplitDocumentResult::toJson() const
{
    web::json::value val = web::json::value::object();
    if(m_PagesIsSet)
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_Pages.begin(), m_Pages.end(), std::back_inserter(jsonArray),
            [&](std::shared_ptr<FileLink> item) {
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("Pages")] = web::json::value::array(jsonArray);
        }
    }
    if(m_SourceDocumentIsSet)
    {
        val[_XPLATSTR("SourceDocument")] = ModelBase::toJson(m_SourceDocument);
    }
    if(m_ZippedPagesIsSet)
    {
        val[_XPLATSTR("ZippedPages")] = ModelBase::toJson(m_ZippedPages);
    }

    return val;
}

void SplitDocumentResult::fromJson(web::json::value& val)
{
    {
        m_Pages.clear();
        if(val.has_field(_XPLATSTR("Pages")) 
                            && !val[_XPLATSTR("Pages")].is_null())
        {
            auto arr = val[_XPLATSTR("Pages")].as_array();
            std::transform(arr.begin(), arr.end(), std::back_inserter(m_Pages), [&](web::json::value& item){
                if(!item.is_null())
                {
                    std::shared_ptr<FileLink> newItem(new FileLink());
                    newItem->fromJson(item);
                    return newItem;
                }

                return (std::shared_ptr<FileLink>)nullptr;
            });
        }
    }


    if(val.has_field(_XPLATSTR("SourceDocument")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SourceDocument")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<FileLink> newItem(new FileLink());
            newItem->fromJson(fieldValue);
            setSourceDocument( newItem );
        }
    }


    if(val.has_field(_XPLATSTR("ZippedPages")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ZippedPages")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<FileLink> newItem(new FileLink());
            newItem->fromJson(fieldValue);
            setZippedPages( newItem );
        }
    }

}

void SplitDocumentResult::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_Pages.begin(), m_Pages.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<FileLink> item){
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Pages"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }


    if(m_SourceDocumentIsSet)
    {
        if (m_SourceDocument.get())
        {
            m_SourceDocument->toMultipart(multipart, _XPLATSTR("SourceDocument."));
        }
    }


    if(m_ZippedPagesIsSet)
    {
        if (m_ZippedPages.get())
        {
            m_ZippedPages->toMultipart(multipart, _XPLATSTR("ZippedPages."));
        }
    }

}

void SplitDocumentResult::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

std::vector<std::shared_ptr<FileLink>>& SplitDocumentResult::getPages()
{
    return m_Pages;
}


void SplitDocumentResult::setPages(std::vector<std::shared_ptr<FileLink>> const& value)
{
    m_Pages = value;
    m_PagesIsSet = true;
}

bool SplitDocumentResult::pagesIsSet() const
{
    return m_PagesIsSet;
}

void SplitDocumentResult::unsetPages()
{
    m_PagesIsSet = false;
}

std::shared_ptr<FileLink> SplitDocumentResult::getSourceDocument() const
{
    return m_SourceDocument;
}


void SplitDocumentResult::setSourceDocument(std::shared_ptr<FileLink> value)
{
    m_SourceDocument = value;
    m_SourceDocumentIsSet = true;
}

bool SplitDocumentResult::sourceDocumentIsSet() const
{
    return m_SourceDocumentIsSet;
}

void SplitDocumentResult::unsetSourceDocument()
{
    m_SourceDocumentIsSet = false;
}

std::shared_ptr<FileLink> SplitDocumentResult::getZippedPages() const
{
    return m_ZippedPages;
}


void SplitDocumentResult::setZippedPages(std::shared_ptr<FileLink> value)
{
    m_ZippedPages = value;
    m_ZippedPagesIsSet = true;
}

bool SplitDocumentResult::zippedPagesIsSet() const
{
    return m_ZippedPagesIsSet;
}

void SplitDocumentResult::unsetZippedPages()
{
    m_ZippedPagesIsSet = false;
}

}
}
}
}
}
