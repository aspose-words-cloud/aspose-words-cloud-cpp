/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="StorageFile.cpp">
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

#include "StorageFile.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

StorageFile::StorageFile()
{
    m_IsFolder = false;
    m_IsFolderIsSet = false;
    m_ModifiedDate = utility::datetime();
    m_ModifiedDateIsSet = false;
    m_Name = utility::conversions::to_string_t("");
    m_NameIsSet = false;
    m_Path = utility::conversions::to_string_t("");
    m_PathIsSet = false;
    m_Size = 0;
    m_SizeIsSet = false;

}

StorageFile::~StorageFile()
{
}

void StorageFile::validate()
{
    // TODO: implement validation
}

web::json::value StorageFile::toJson() const
{
    web::json::value val = web::json::value::object();
    if(m_IsFolderIsSet)
    {
        val[_XPLATSTR("IsFolder")] = ModelBase::toJson(m_IsFolder);
    }
    if(m_ModifiedDateIsSet)
    {
        val[_XPLATSTR("ModifiedDate")] = ModelBase::toJson(m_ModifiedDate);
    }
    if(m_NameIsSet)
    {
        val[_XPLATSTR("Name")] = ModelBase::toJson(m_Name);
    }
    if(m_PathIsSet)
    {
        val[_XPLATSTR("Path")] = ModelBase::toJson(m_Path);
    }
    if(m_SizeIsSet)
    {
        val[_XPLATSTR("Size")] = ModelBase::toJson(m_Size);
    }

    return val;
}

void StorageFile::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("IsFolder")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("IsFolder")];
        if(!fieldValue.is_null())
        {
           setIsFolder(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("ModifiedDate")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ModifiedDate")];
        if(!fieldValue.is_null())
        {
           setModifiedDate(ModelBase::dateTimeFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("Name")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Name")];
        if(!fieldValue.is_null())
        {
           setName(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("Path")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Path")];
        if(!fieldValue.is_null())
        {
           setPath(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("Size")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Size")];
        if(!fieldValue.is_null())
        {
           setSize(ModelBase::integerFromJson(fieldValue));
        }
    }

}

void StorageFile::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_IsFolderIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("IsFolder"), m_IsFolder));
    }


    if(m_ModifiedDateIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ModifiedDate"), m_ModifiedDate));
    }


    if(m_NameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Name"), m_Name));
    }


    if(m_PathIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Path"), m_Path));
    }


    if(m_SizeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Size"), m_Size));
    }

}

void StorageFile::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

bool StorageFile::isIsFolder() const
{
    return m_IsFolder;
}


void StorageFile::setIsFolder(bool value)
{
    m_IsFolder = value;
    m_IsFolderIsSet = true;
}

bool StorageFile::isFolderIsSet() const
{
    return m_IsFolderIsSet;
}

void StorageFile::unsetIsFolder()
{
    m_IsFolderIsSet = false;
}

utility::datetime StorageFile::getModifiedDate() const
{
    return m_ModifiedDate;
}


void StorageFile::setModifiedDate(utility::datetime value)
{
    m_ModifiedDate = value;
    m_ModifiedDateIsSet = true;
}

bool StorageFile::modifiedDateIsSet() const
{
    return m_ModifiedDateIsSet;
}

void StorageFile::unsetModifiedDate()
{
    m_ModifiedDateIsSet = false;
}

utility::string_t StorageFile::getName() const
{
    return m_Name;
}


void StorageFile::setName(utility::string_t value)
{
    m_Name = value;
    m_NameIsSet = true;
}

bool StorageFile::nameIsSet() const
{
    return m_NameIsSet;
}

void StorageFile::unsetName()
{
    m_NameIsSet = false;
}

utility::string_t StorageFile::getPath() const
{
    return m_Path;
}


void StorageFile::setPath(utility::string_t value)
{
    m_Path = value;
    m_PathIsSet = true;
}

bool StorageFile::pathIsSet() const
{
    return m_PathIsSet;
}

void StorageFile::unsetPath()
{
    m_PathIsSet = false;
}

int32_t StorageFile::getSize() const
{
    return m_Size;
}


void StorageFile::setSize(int32_t value)
{
    m_Size = value;
    m_SizeIsSet = true;
}

bool StorageFile::sizeIsSet() const
{
    return m_SizeIsSet;
}

void StorageFile::unsetSize()
{
    m_SizeIsSet = false;
}

}
}
}
}
}
