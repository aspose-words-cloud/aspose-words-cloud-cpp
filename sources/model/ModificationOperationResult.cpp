/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ModificationOperationResult.cpp">
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


#include "ModificationOperationResult.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

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
        val[_XPLATSTR("source")] = ModelBase::toJson(m_Source);
    }
    if(m_DestIsSet)
    {
        val[_XPLATSTR("dest")] = ModelBase::toJson(m_Dest);
    }

    return val;
}

void ModificationOperationResult::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("source")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("source")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<FileLink> newItem(new FileLink());
            newItem->fromJson(fieldValue);
            setSource( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("dest")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("dest")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<FileLink> newItem(new FileLink());
            newItem->fromJson(fieldValue);
            setDest( newItem );
        }
    }
}

void ModificationOperationResult::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_SourceIsSet)
    {
        if (m_Source.get())
        {
            m_Source->toMultipart(multipart, _XPLATSTR("source."));
        }
        
    }
    if(m_DestIsSet)
    {
        if (m_Dest.get())
        {
            m_Dest->toMultipart(multipart, _XPLATSTR("dest."));
        }
        
    }
}

void ModificationOperationResult::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("source")))
    {
        if(multipart->hasContent(_XPLATSTR("source")))
        {
            std::shared_ptr<FileLink> newItem(new FileLink());
            newItem->fromMultiPart(multipart, _XPLATSTR("source."));
            setSource( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("dest")))
    {
        if(multipart->hasContent(_XPLATSTR("dest")))
        {
            std::shared_ptr<FileLink> newItem(new FileLink());
            newItem->fromMultiPart(multipart, _XPLATSTR("dest."));
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
}

