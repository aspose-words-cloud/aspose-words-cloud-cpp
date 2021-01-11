/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DocumentEntryList.cpp">
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

#include "DocumentEntryList.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

DocumentEntryList::DocumentEntryList()
{
    m_ApplyBaseDocumentHeadersAndFootersToAppendingDocuments = false;
    m_ApplyBaseDocumentHeadersAndFootersToAppendingDocumentsIsSet = false;

    m_DocumentEntriesIsSet = false;

}

DocumentEntryList::~DocumentEntryList()
{
}

void DocumentEntryList::validate()
{
    // TODO: implement validation
}

web::json::value DocumentEntryList::toJson() const
{
    web::json::value val = web::json::value::object();
    if(m_ApplyBaseDocumentHeadersAndFootersToAppendingDocumentsIsSet)
    {
        val[_XPLATSTR("ApplyBaseDocumentHeadersAndFootersToAppendingDocuments")] = ModelBase::toJson(m_ApplyBaseDocumentHeadersAndFootersToAppendingDocuments);
    }
    if(m_DocumentEntriesIsSet)
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_DocumentEntries.begin(), m_DocumentEntries.end(), std::back_inserter(jsonArray),
            [&](std::shared_ptr<DocumentEntry> item) {
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("DocumentEntries")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void DocumentEntryList::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("ApplyBaseDocumentHeadersAndFootersToAppendingDocuments")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ApplyBaseDocumentHeadersAndFootersToAppendingDocuments")];
        if(!fieldValue.is_null())
        {
           setApplyBaseDocumentHeadersAndFootersToAppendingDocuments(ModelBase::booleanFromJson(fieldValue));
        }
    }


    {
        m_DocumentEntries.clear();
        if(val.has_field(_XPLATSTR("DocumentEntries")) 
                            && !val[_XPLATSTR("DocumentEntries")].is_null())
        {
            auto arr = val[_XPLATSTR("DocumentEntries")].as_array();
            std::transform(arr.begin(), arr.end(), std::back_inserter(m_DocumentEntries), [&](web::json::value& item){
                if(!item.is_null())
                {
                    std::shared_ptr<DocumentEntry> newItem(new DocumentEntry());
                    newItem->fromJson(item);
                    return newItem;
                }

                return (std::shared_ptr<DocumentEntry>)nullptr;
            });
        }
    }

}

void DocumentEntryList::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_ApplyBaseDocumentHeadersAndFootersToAppendingDocumentsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ApplyBaseDocumentHeadersAndFootersToAppendingDocuments"), m_ApplyBaseDocumentHeadersAndFootersToAppendingDocuments));
    }


    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_DocumentEntries.begin(), m_DocumentEntries.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<DocumentEntry> item){
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("DocumentEntries"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }

}

void DocumentEntryList::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

bool DocumentEntryList::isApplyBaseDocumentHeadersAndFootersToAppendingDocuments() const
{
    return m_ApplyBaseDocumentHeadersAndFootersToAppendingDocuments;
}


void DocumentEntryList::setApplyBaseDocumentHeadersAndFootersToAppendingDocuments(bool value)
{
    m_ApplyBaseDocumentHeadersAndFootersToAppendingDocuments = value;
    m_ApplyBaseDocumentHeadersAndFootersToAppendingDocumentsIsSet = true;
}

bool DocumentEntryList::applyBaseDocumentHeadersAndFootersToAppendingDocumentsIsSet() const
{
    return m_ApplyBaseDocumentHeadersAndFootersToAppendingDocumentsIsSet;
}

void DocumentEntryList::unsetApplyBaseDocumentHeadersAndFootersToAppendingDocuments()
{
    m_ApplyBaseDocumentHeadersAndFootersToAppendingDocumentsIsSet = false;
}

std::vector<std::shared_ptr<DocumentEntry>>& DocumentEntryList::getDocumentEntries()
{
    return m_DocumentEntries;
}


void DocumentEntryList::setDocumentEntries(std::vector<std::shared_ptr<DocumentEntry>> const& value)
{
    m_DocumentEntries = value;
    m_DocumentEntriesIsSet = true;
}

bool DocumentEntryList::documentEntriesIsSet() const
{
    return m_DocumentEntriesIsSet;
}

void DocumentEntryList::unsetDocumentEntries()
{
    m_DocumentEntriesIsSet = false;
}

}
}
}
}
}
