/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SaveResult.cpp">
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

#include "SaveResult.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

SaveResult::SaveResult()
{
    m_AdditionalItemsIsSet = false;

    m_DestDocumentIsSet = false;

    m_SourceDocumentIsSet = false;

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
    if(m_AdditionalItemsIsSet)
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_AdditionalItems.begin(), m_AdditionalItems.end(), std::back_inserter(jsonArray),
            [&](std::shared_ptr<FileLink> item) {
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("AdditionalItems")] = web::json::value::array(jsonArray);
        }
    }
    if(m_DestDocumentIsSet)
    {
        val[_XPLATSTR("DestDocument")] = ModelBase::toJson(m_DestDocument);
    }
    if(m_SourceDocumentIsSet)
    {
        val[_XPLATSTR("SourceDocument")] = ModelBase::toJson(m_SourceDocument);
    }

    return val;
}

void SaveResult::fromJson(web::json::value& val)
{
    {
        m_AdditionalItems.clear();
        if(val.has_field(_XPLATSTR("AdditionalItems")) 
                            && !val[_XPLATSTR("AdditionalItems")].is_null())
        {
            auto arr = val[_XPLATSTR("AdditionalItems")].as_array();
            std::transform(arr.begin(), arr.end(), std::back_inserter(m_AdditionalItems), [&](web::json::value& item){
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


    if(val.has_field(_XPLATSTR("DestDocument")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DestDocument")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<FileLink> newItem(new FileLink());
            newItem->fromJson(fieldValue);
        }
    }


    if(val.has_field(_XPLATSTR("SourceDocument")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SourceDocument")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<FileLink> newItem(new FileLink());
            newItem->fromJson(fieldValue);
        }
    }

}

void SaveResult::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_AdditionalItems.begin(), m_AdditionalItems.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<FileLink> item){
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("AdditionalItems"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }


    if(m_DestDocumentIsSet)
    {
        if (m_DestDocument.get())
        {
            m_DestDocument->toMultipart(multipart, _XPLATSTR("DestDocument."));
        }
    }


    if(m_SourceDocumentIsSet)
    {
        if (m_SourceDocument.get())
        {
            m_SourceDocument->toMultipart(multipart, _XPLATSTR("SourceDocument."));
        }
    }

}

void SaveResult::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

std::vector<std::shared_ptr<FileLink>>& SaveResult::getAdditionalItems()
{
    return m_AdditionalItems;
}


void SaveResult::setAdditionalItems(std::vector<std::shared_ptr<FileLink>> const& value)
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

}
}
}
}
}
