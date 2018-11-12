/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ModificationOperationResult.cpp">
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


#include "ModificationOperationResult.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

ModificationOperationResult::ModificationOperationResult()
{
    m_SourceIsSet = false;
    m_DestIsSet = false;
}

ModificationOperationResult::~ModificationOperationResult()
{
}

void ModificationOperationResult::validate()
{
    // TODO: implement validation
}

web::json::value ModificationOperationResult::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_SourceIsSet)
    {
        val[utility::conversions::to_string_t("Source")] = ModelBase::toJson(m_Source);
    }
    if(m_DestIsSet)
    {
        val[utility::conversions::to_string_t("Dest")] = ModelBase::toJson(m_Dest);
    }

    return val;
}

void ModificationOperationResult::fromJson(web::json::value& val)
{
    if(val.has_field(utility::conversions::to_string_t("Source")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Source")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<FileLink> newItem(new FileLink());
            newItem->fromJson(fieldValue);
            setSource( newItem );
        }
    }
    if(val.has_field(utility::conversions::to_string_t("Dest")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Dest")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<FileLink> newItem(new FileLink());
            newItem->fromJson(fieldValue);
            setDest( newItem );
        }
    }
}

void ModificationOperationResult::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_SourceIsSet)
    {
        if (m_Source.get())
        {
            m_Source->toMultipart(multipart, utility::conversions::to_string_t("Source."));
        }
        
    }
    if(m_DestIsSet)
    {
        if (m_Dest.get())
        {
            m_Dest->toMultipart(multipart, utility::conversions::to_string_t("Dest."));
        }
        
    }
}

void ModificationOperationResult::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("Source")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("Source")))
        {
            std::shared_ptr<FileLink> newItem(new FileLink());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("Source."));
            setSource( newItem );
        }
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Dest")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("Dest")))
        {
            std::shared_ptr<FileLink> newItem(new FileLink());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("Dest."));
            setDest( newItem );
        }
    }
}

std::shared_ptr<FileLink> ModificationOperationResult::getSource() const
{
    return m_Source;
}


void ModificationOperationResult::setSource(std::shared_ptr<FileLink> value)
{
    m_Source = value;
    m_SourceIsSet = true;
}
bool ModificationOperationResult::sourceIsSet() const
{
    return m_SourceIsSet;
}

void ModificationOperationResult::unsetSource()
{
    m_SourceIsSet = false;
}

std::shared_ptr<FileLink> ModificationOperationResult::getDest() const
{
    return m_Dest;
}


void ModificationOperationResult::setDest(std::shared_ptr<FileLink> value)
{
    m_Dest = value;
    m_DestIsSet = true;
}
bool ModificationOperationResult::destIsSet() const
{
    return m_DestIsSet;
}

void ModificationOperationResult::unsetDest()
{
    m_DestIsSet = false;
}

}
}
}
}

