/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SplitDocumentResult.cpp">
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


#include "SplitDocumentResult.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

SplitDocumentResult::SplitDocumentResult()
{
    m_SourceDocumentIsSet = false;
    m_PagesIsSet = false;
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

    if(m_SourceDocumentIsSet)
    {
        val[utility::conversions::to_string_t("SourceDocument")] = ModelBase::toJson(m_SourceDocument);
    }
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_Pages.begin(), m_Pages.end(), std::back_inserter(jsonArray),
			[&](auto item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[utility::conversions::to_string_t("Pages")] = web::json::value::array(jsonArray);
        }
    }
    if(m_ZippedPagesIsSet)
    {
        val[utility::conversions::to_string_t("ZippedPages")] = ModelBase::toJson(m_ZippedPages);
    }

    return val;
}

void SplitDocumentResult::fromJson(web::json::value& val)
{
    if(val.has_field(utility::conversions::to_string_t("SourceDocument")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("SourceDocument")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<FileLink> newItem(new FileLink());
            newItem->fromJson(fieldValue);
            setSourceDocument( newItem );
        }
    }
    {
        m_Pages.clear();
        if(val.has_field(utility::conversions::to_string_t("Pages")) 
                            && !val[utility::conversions::to_string_t("Pages")].is_null())
        {
        auto arr = val[utility::conversions::to_string_t("Pages")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_Pages), [&](auto item){
            if(item.is_null())
            {
                return std::shared_ptr<FileLink>(nullptr);
            }
            else
            {
                std::shared_ptr<FileLink> newItem(new FileLink());
                newItem->fromJson(item);
                return newItem;
            }
        });

        }
    }
    if(val.has_field(utility::conversions::to_string_t("ZippedPages")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("ZippedPages")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<FileLink> newItem(new FileLink());
            newItem->fromJson(fieldValue);
            setZippedPages( newItem );
        }
    }
}

void SplitDocumentResult::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_SourceDocumentIsSet)
    {
        if (m_SourceDocument.get())
        {
            m_SourceDocument->toMultipart(multipart, utility::conversions::to_string_t("SourceDocument."));
        }
        
    }
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_Pages.begin(), m_Pages.end(), std::back_inserter(jsonArray), [&](auto& item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Pages"), web::json::value::array(jsonArray), utility::conversions::to_string_t("application/json")));
        }
    }
    if(m_ZippedPagesIsSet)
    {
        if (m_ZippedPages.get())
        {
            m_ZippedPages->toMultipart(multipart, utility::conversions::to_string_t("ZippedPages."));
        }
        
    }
}

void SplitDocumentResult::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("SourceDocument")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("SourceDocument")))
        {
            std::shared_ptr<FileLink> newItem(new FileLink());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("SourceDocument."));
            setSourceDocument( newItem );
        }
    }
    {
        m_Pages.clear();
        if(multipart->hasContent(utility::conversions::to_string_t("Pages")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Pages")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_Pages), [&](auto& item) {
            if(item.is_null())
            {
                return std::shared_ptr<FileLink>(nullptr) ;
            }
            else
            {
                std::shared_ptr<FileLink> newItem(new FileLink());
                newItem->fromJson(item);
                return newItem ;
            }
        });
        }
    }
    if(multipart->hasContent(utility::conversions::to_string_t("ZippedPages")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("ZippedPages")))
        {
            std::shared_ptr<FileLink> newItem(new FileLink());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("ZippedPages."));
            setZippedPages( newItem );
        }
    }
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

