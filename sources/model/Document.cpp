/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Document.cpp">
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


#include "Document.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

Document::Document()
{
    m_LinksIsSet = false;
    m_FileName = utility::conversions::to_string_t("");
    m_FileNameIsSet = false;
    m_SourceFormat = utility::conversions::to_string_t("");
    m_IsEncrypted = false;
    m_IsSigned = false;
    m_DocumentPropertiesIsSet = false;
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

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_Links.begin(), m_Links.end(), std::back_inserter(jsonArray),
			[&](std::shared_ptr<Link> item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[utility::conversions::to_string_t("Links")] = web::json::value::array(jsonArray);
        }
    }
    if(m_FileNameIsSet)
    {
        val[utility::conversions::to_string_t("FileName")] = ModelBase::toJson(m_FileName);
    }
    val[utility::conversions::to_string_t("SourceFormat")] = ModelBase::toJson(m_SourceFormat);
    val[utility::conversions::to_string_t("IsEncrypted")] = ModelBase::toJson(m_IsEncrypted);
    val[utility::conversions::to_string_t("IsSigned")] = ModelBase::toJson(m_IsSigned);
    if(m_DocumentPropertiesIsSet)
    {
        val[utility::conversions::to_string_t("DocumentProperties")] = ModelBase::toJson(m_DocumentProperties);
    }

    return val;
}

void Document::fromJson(web::json::value& val)
{
    {
        m_Links.clear();
        if(val.has_field(utility::conversions::to_string_t("Links")) 
                            && !val[utility::conversions::to_string_t("Links")].is_null())
        {
        auto arr = val[utility::conversions::to_string_t("Links")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_Links), [&](std::shared_ptr<Link> item){
            if(item.is_null())
            {
                return std::shared_ptr<Link>(nullptr);
            }
            else
            {
                std::shared_ptr<Link> newItem(new Link());
                newItem->fromJson(item);
                return newItem;
            }
        });

        }
    }
    if(val.has_field(utility::conversions::to_string_t("FileName")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("FileName")];
        if(!fieldValue.is_null())
        {
            setFileName(ModelBase::stringFromJson(fieldValue));
        }
    }
    setSourceFormat(ModelBase::stringFromJson(val[utility::conversions::to_string_t("SourceFormat")]));
    if(val.has_field(utility::conversions::to_string_t("IsEncrypted")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("IsEncrypted")];
        if(!fieldValue.is_null())
        {
            setIsEncrypted(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("IsSigned")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("IsSigned")];
        if(!fieldValue.is_null())
        {
            setIsSigned(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("DocumentProperties")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("DocumentProperties")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<DocumentProperties> newItem(new DocumentProperties());
            newItem->fromJson(fieldValue);
            setDocumentProperties( newItem );
        }
    }
}

void Document::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_Links.begin(), m_Links.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<Link> item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Links"), web::json::value::array(jsonArray), utility::conversions::to_string_t("application/json")));
        }
    }
    if(m_FileNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("FileName"), m_FileName));
        
    }
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("SourceFormat"), m_SourceFormat));
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("IsEncrypted"), m_IsEncrypted));
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("IsSigned"), m_IsSigned));
    if(m_DocumentPropertiesIsSet)
    {
        if (m_DocumentProperties.get())
        {
            m_DocumentProperties->toMultipart(multipart, utility::conversions::to_string_t("DocumentProperties."));
        }
        
    }
}

void Document::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    {
        m_Links.clear();
        if(multipart->hasContent(utility::conversions::to_string_t("Links")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Links")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_Links), [&](std::shared_ptr<Link> item) {
            if(item.is_null())
            {
                return std::shared_ptr<Link>(nullptr) ;
            }
            else
            {
                std::shared_ptr<Link> newItem(new Link());
                newItem->fromJson(item);
                return newItem ;
            }
        });
        }
    }
    if(multipart->hasContent(utility::conversions::to_string_t("FileName")))
    {
        setFileName(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("FileName"))));
    }
    setSourceFormat(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("SourceFormat"))));
    setIsEncrypted(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("IsEncrypted"))));
    setIsSigned(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("IsSigned"))));
    if(multipart->hasContent(utility::conversions::to_string_t("DocumentProperties")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("DocumentProperties")))
        {
            std::shared_ptr<DocumentProperties> newItem(new DocumentProperties());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("DocumentProperties."));
            setDocumentProperties( newItem );
        }
    }
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

utility::string_t Document::getSourceFormat() const
{
    return m_SourceFormat;
}


void Document::setSourceFormat(utility::string_t value)
{
    m_SourceFormat = value;
    
}
bool Document::isIsEncrypted() const
{
    return m_IsEncrypted;
}


void Document::setIsEncrypted(bool value)
{
    m_IsEncrypted = value;
    
}
bool Document::isIsSigned() const
{
    return m_IsSigned;
}


void Document::setIsSigned(bool value)
{
    m_IsSigned = value;
    
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

}
}
}
}

