/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Document.cpp">
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

#include "Document.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

Document::Document()
{
    m_DocumentPropertiesIsSet = false;
    m_FileName = utility::conversions::to_string_t("");
    m_FileNameIsSet = false;
    m_IsEncrypted = false;
    m_IsEncryptedIsSet = false;
    m_IsSigned = false;
    m_IsSignedIsSet = false;

    m_LinksIsSet = false;

    m_SourceFormatIsSet = false;

}

Document::~Document()
{
}

void Document::validate()
{
    // TODO: implement validation
}

web::json::value Document::toJson() const
{
    web::json::value val = web::json::value::object();
    if(m_DocumentPropertiesIsSet)
    {
        val[_XPLATSTR("DocumentProperties")] = ModelBase::toJson(m_DocumentProperties);
    }
    if(m_FileNameIsSet)
    {
        val[_XPLATSTR("FileName")] = ModelBase::toJson(m_FileName);
    }
    if(m_IsEncryptedIsSet)
    {
        val[_XPLATSTR("IsEncrypted")] = ModelBase::toJson(m_IsEncrypted);
    }
    if(m_IsSignedIsSet)
    {
        val[_XPLATSTR("IsSigned")] = ModelBase::toJson(m_IsSigned);
    }
    if(m_LinksIsSet)
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_Links.begin(), m_Links.end(), std::back_inserter(jsonArray),
            [&](std::shared_ptr<Link> item) {
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("Links")] = web::json::value::array(jsonArray);
        }
    }
    if(m_SourceFormatIsSet)
    {
        val[_XPLATSTR("SourceFormat")] = ModelBase::toJson(m_SourceFormat);
    }

    return val;
}

void Document::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("DocumentProperties")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DocumentProperties")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<DocumentProperties> newItem(new DocumentProperties());
            newItem->fromJson(fieldValue);
            setDocumentProperties( newItem );
        }
    }


    if(val.has_field(_XPLATSTR("FileName")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("FileName")];
        if(!fieldValue.is_null())
        {
           setFileName(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("IsEncrypted")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("IsEncrypted")];
        if(!fieldValue.is_null())
        {
           setIsEncrypted(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("IsSigned")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("IsSigned")];
        if(!fieldValue.is_null())
        {
           setIsSigned(ModelBase::booleanFromJson(fieldValue));
        }
    }


    {
        m_Links.clear();
        if(val.has_field(_XPLATSTR("Links")) 
                            && !val[_XPLATSTR("Links")].is_null())
        {
            auto arr = val[_XPLATSTR("Links")].as_array();
            std::transform(arr.begin(), arr.end(), std::back_inserter(m_Links), [&](web::json::value& item){
                if(!item.is_null())
                {
                    std::shared_ptr<Link> newItem(new Link());
                    newItem->fromJson(item);
                    return newItem;
                }

                return (std::shared_ptr<Link>)nullptr;
            });
        }
    }


    if(val.has_field(_XPLATSTR("SourceFormat")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SourceFormat")];
        if(!fieldValue.is_null())
        {
           setSourceFormat(ModelBase::enumFromJson(fieldValue));
        }
    }

}

void Document::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_DocumentPropertiesIsSet)
    {
        if (m_DocumentProperties.get())
        {
            m_DocumentProperties->toMultipart(multipart, _XPLATSTR("DocumentProperties."));
        }
    }


    if(m_FileNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("FileName"), m_FileName));
    }


    if(m_IsEncryptedIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("IsEncrypted"), m_IsEncrypted));
    }


    if(m_IsSignedIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("IsSigned"), m_IsSigned));
    }


    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_Links.begin(), m_Links.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<Link> item){
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Links"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }


    if(m_SourceFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("SourceFormat"), m_SourceFormat));
    }

}

void Document::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

std::shared_ptr<DocumentProperties> Document::getDocumentProperties() const
{
    return m_DocumentProperties;
}


void Document::setDocumentProperties(std::shared_ptr<DocumentProperties> value)
{
    m_DocumentProperties = value;
    m_DocumentPropertiesIsSet = true;
}

bool Document::documentPropertiesIsSet() const
{
    return m_DocumentPropertiesIsSet;
}

void Document::unsetDocumentProperties()
{
    m_DocumentPropertiesIsSet = false;
}

utility::string_t Document::getFileName() const
{
    return m_FileName;
}


void Document::setFileName(utility::string_t value)
{
    m_FileName = value;
    m_FileNameIsSet = true;
}

bool Document::fileNameIsSet() const
{
    return m_FileNameIsSet;
}

void Document::unsetFileName()
{
    m_FileNameIsSet = false;
}

bool Document::isIsEncrypted() const
{
    return m_IsEncrypted;
}


void Document::setIsEncrypted(bool value)
{
    m_IsEncrypted = value;
    m_IsEncryptedIsSet = true;
}

bool Document::isEncryptedIsSet() const
{
    return m_IsEncryptedIsSet;
}

void Document::unsetIsEncrypted()
{
    m_IsEncryptedIsSet = false;
}

bool Document::isIsSigned() const
{
    return m_IsSigned;
}


void Document::setIsSigned(bool value)
{
    m_IsSigned = value;
    m_IsSignedIsSet = true;
}

bool Document::isSignedIsSet() const
{
    return m_IsSignedIsSet;
}

void Document::unsetIsSigned()
{
    m_IsSignedIsSet = false;
}

std::vector<std::shared_ptr<Link>>& Document::getLinks()
{
    return m_Links;
}


void Document::setLinks(std::vector<std::shared_ptr<Link>> const& value)
{
    m_Links = value;
    m_LinksIsSet = true;
}

bool Document::linksIsSet() const
{
    return m_LinksIsSet;
}

void Document::unsetLinks()
{
    m_LinksIsSet = false;
}

utility::string_t Document::getSourceFormat() const
{
    return m_SourceFormat;
}


void Document::setSourceFormat(utility::string_t value)
{
    m_SourceFormat = value;
    m_SourceFormatIsSet = true;
}

bool Document::sourceFormatIsSet() const
{
    return m_SourceFormatIsSet;
}

void Document::unsetSourceFormat()
{
    m_SourceFormatIsSet = false;
}

}
}
}
}
}
