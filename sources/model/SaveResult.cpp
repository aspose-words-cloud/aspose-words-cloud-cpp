/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SaveResult.cpp">
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


#include "SaveResult.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

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
        val[_XPLATSTR("SourceDocument")] = ModelBase::toJson(m_SourceDocument);
    }
    if(m_DestDocumentIsSet)
    {
        val[_XPLATSTR("DestDocument")] = ModelBase::toJson(m_DestDocument);
    }
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_AdditionalItems.begin(), m_AdditionalItems.end(), std::back_inserter(jsonArray),
			[&](<DATA_TYPE_START>FileLink<DATA_TYPE_END> item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("AdditionalItems")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void SaveResult::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("SourceDocument")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SourceDocument")];
        if(!fieldValue.is_null())
        {
            <DATA_TYPE_START>FileLink<DATA_TYPE_END> newItem(new FileLink());
            newItem->fromJson(fieldValue);
            setSourceDocument( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("DestDocument")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DestDocument")];
        if(!fieldValue.is_null())
        {
            <DATA_TYPE_START>FileLink<DATA_TYPE_END> newItem(new FileLink());
            newItem->fromJson(fieldValue);
            setDestDocument( newItem );
        }
    }
    {
        m_AdditionalItems.clear();
        if(val.has_field(_XPLATSTR("AdditionalItems")) 
                            && !val[_XPLATSTR("AdditionalItems")].is_null())
        {
        auto arr = val[_XPLATSTR("AdditionalItems")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_AdditionalItems), [&](web::json::value& item){
            if(item.is_null())
            {
                return <DATA_TYPE_START>FileLink<DATA_TYPE_END>(nullptr);
            }
            else
            {
                <DATA_TYPE_START>FileLink<DATA_TYPE_END> newItem(new FileLink());
                newItem->fromJson(item);
                return newItem;
            }
        });

        }
    }
}

void SaveResult::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_SourceDocumentIsSet)
    {
        if (m_SourceDocument.get())
        {
            m_SourceDocument->toMultipart(multipart, _XPLATSTR("SourceDocument."));
        }
        
    }
    if(m_DestDocumentIsSet)
    {
        if (m_DestDocument.get())
        {
            m_DestDocument->toMultipart(multipart, _XPLATSTR("DestDocument."));
        }
        
    }
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_AdditionalItems.begin(), m_AdditionalItems.end(), std::back_inserter(jsonArray), [&](<DATA_TYPE_START>FileLink<DATA_TYPE_END> item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("AdditionalItems"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }
}

void SaveResult::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    

    if(multipart->hasContent(_XPLATSTR("SourceDocument")))
    {
        if(multipart->hasContent(_XPLATSTR("SourceDocument")))
        {
            <DATA_TYPE_START>FileLink<DATA_TYPE_END> newItem(new FileLink());
            newItem->fromMultiPart(multipart, _XPLATSTR("SourceDocument."));
            setSourceDocument( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("DestDocument")))
    {
        if(multipart->hasContent(_XPLATSTR("DestDocument")))
        {
            <DATA_TYPE_START>FileLink<DATA_TYPE_END> newItem(new FileLink());
            newItem->fromMultiPart(multipart, _XPLATSTR("DestDocument."));
            setDestDocument( newItem );
        }
    }
    {
        m_AdditionalItems.clear();
        if(multipart->hasContent(_XPLATSTR("AdditionalItems")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("AdditionalItems")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_AdditionalItems), [&](web::json::value item) {
            if(item.is_null())
            {
                return <DATA_TYPE_START>FileLink<DATA_TYPE_END>(nullptr) ;
            }
            else
            {
                <DATA_TYPE_START>FileLink<DATA_TYPE_END> newItem(new FileLink());
                newItem->fromJson(item);
                return newItem ;
            }
        });
        }
    }
}

<DATA_TYPE_START>FileLink<DATA_TYPE_END> SaveResult::getSourceDocument() const
{
    return m_SourceDocument;
}


void SaveResult::setSourceDocument(<DATA_TYPE_START>FileLink<DATA_TYPE_END> value)
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

<DATA_TYPE_START>FileLink<DATA_TYPE_END> SaveResult::getDestDocument() const
{
    return m_DestDocument;
}


void SaveResult::setDestDocument(<DATA_TYPE_START>FileLink<DATA_TYPE_END> value)
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

<DATA_TYPE_START>List<FileLink><DATA_TYPE_END>& SaveResult::getAdditionalItems()
{
    return m_AdditionalItems;
}

void SaveResult::setAdditionalItems(<DATA_TYPE_START>List<FileLink><DATA_TYPE_END> const& value)
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
}

