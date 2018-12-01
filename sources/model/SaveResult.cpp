/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SaveResult.cpp">
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


#include "SaveResult.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

SaveResult::SaveResult()
{
    m_SourceDocumentIsSet = false;
    m_DestDocumentIsSet = false;
    m_AdditionalItemsIsSet = false;
}

SaveResult::~SaveResult()
{
}

void SaveResult::validate()
{
    // TODO: implement validation
}

web::json::value SaveResult::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_SourceDocumentIsSet)
    {
        val[utility::conversions::to_string_t("SourceDocument")] = ModelBase::toJson(m_SourceDocument);
    }
    if(m_DestDocumentIsSet)
    {
        val[utility::conversions::to_string_t("DestDocument")] = ModelBase::toJson(m_DestDocument);
    }
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_AdditionalItems )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        if(jsonArray.size() > 0)
        {
            val[utility::conversions::to_string_t("AdditionalItems")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void SaveResult::fromJson(web::json::value& val)
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
    if(val.has_field(utility::conversions::to_string_t("DestDocument")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("DestDocument")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<FileLink> newItem(new FileLink());
            newItem->fromJson(fieldValue);
            setDestDocument( newItem );
        }
    }
    {
        m_AdditionalItems.clear();
        std::vector<web::json::value> jsonArray;
        if(val.has_field(utility::conversions::to_string_t("AdditionalItems")) 
                            && !val[utility::conversions::to_string_t("AdditionalItems")].is_null())
        {
        for( auto& item : val[utility::conversions::to_string_t("AdditionalItems")].as_array() )
        {
            if(item.is_null())
            {
                m_AdditionalItems.push_back( std::shared_ptr<FileLink>(nullptr) );
            }
            else
            {
                std::shared_ptr<FileLink> newItem(new FileLink());
                newItem->fromJson(item);
                m_AdditionalItems.push_back( newItem );
            }
        }
        }
    }
}

void SaveResult::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_DestDocumentIsSet)
    {
        if (m_DestDocument.get())
        {
            m_DestDocument->toMultipart(multipart, utility::conversions::to_string_t("DestDocument."));
        }
        
    }
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_AdditionalItems )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("AdditionalItems"), web::json::value::array(jsonArray), utility::conversions::to_string_t("application/json")));
        }
    }
}

void SaveResult::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t("DestDocument")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("DestDocument")))
        {
            std::shared_ptr<FileLink> newItem(new FileLink());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("DestDocument."));
            setDestDocument( newItem );
        }
    }
    {
        m_AdditionalItems.clear();
        if(multipart->hasContent(utility::conversions::to_string_t("AdditionalItems")))
        {

        web::json::value jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("AdditionalItems"))));
        for( auto& item : jsonArray.as_array() )
        {
            if(item.is_null())
            {
                m_AdditionalItems.push_back( std::shared_ptr<FileLink>(nullptr) );
            }
            else
            {
                std::shared_ptr<FileLink> newItem(new FileLink());
                newItem->fromJson(item);
                m_AdditionalItems.push_back( newItem );
            }
        }
        }
    }
}

std::shared_ptr<FileLink> SaveResult::getSourceDocument() const
{
    return m_SourceDocument;
}


void SaveResult::setSourceDocument(std::shared_ptr<FileLink> value)
{
    m_SourceDocument = value;
    m_SourceDocumentIsSet = true;
}
bool SaveResult::sourceDocumentIsSet() const
{
    return m_SourceDocumentIsSet;
}

void SaveResult::unsetSourceDocument()
{
    m_SourceDocumentIsSet = false;
}

std::shared_ptr<FileLink> SaveResult::getDestDocument() const
{
    return m_DestDocument;
}


void SaveResult::setDestDocument(std::shared_ptr<FileLink> value)
{
    m_DestDocument = value;
    m_DestDocumentIsSet = true;
}
bool SaveResult::destDocumentIsSet() const
{
    return m_DestDocumentIsSet;
}

void SaveResult::unsetDestDocument()
{
    m_DestDocumentIsSet = false;
}

std::vector<std::shared_ptr<FileLink>>& SaveResult::getAdditionalItems()
{
    return m_AdditionalItems;
}

void SaveResult::setAdditionalItems(std::vector<std::shared_ptr<FileLink>> value)
{
    m_AdditionalItems = value;
    m_AdditionalItemsIsSet = true;
}
bool SaveResult::additionalItemsIsSet() const
{
    return m_AdditionalItemsIsSet;
}

void SaveResult::unsetAdditionalItems()
{
    m_AdditionalItemsIsSet = false;
}

}
}
}
}

