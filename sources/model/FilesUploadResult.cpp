/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FilesUploadResult.cpp">
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

#include "FilesUploadResult.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

FilesUploadResult::FilesUploadResult()
{
    m_ErrorsIsSet = false;

    m_UploadedIsSet = false;

}

FilesUploadResult::~FilesUploadResult()
{
}

void FilesUploadResult::validate()
{
    // TODO: implement validation
}

web::json::value FilesUploadResult::toJson() const
{
    web::json::value val = web::json::value::object();
    if(m_ErrorsIsSet)
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_Errors.begin(), m_Errors.end(), std::back_inserter(jsonArray),
            [&](std::shared_ptr<Error> item) {
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("Errors")] = web::json::value::array(jsonArray);
        }
    }
    if(m_UploadedIsSet)
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_Uploaded.begin(), m_Uploaded.end(), std::back_inserter(jsonArray),
            [&](utility::string_t item) {
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("Uploaded")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void FilesUploadResult::fromJson(web::json::value& val)
{
    {
        m_Errors.clear();
        if(val.has_field(_XPLATSTR("Errors")) 
                            && !val[_XPLATSTR("Errors")].is_null())
        {
            auto arr = val[_XPLATSTR("Errors")].as_array();
            std::transform(arr.begin(), arr.end(), std::back_inserter(m_Errors), [&](web::json::value& item){
                if(!item.is_null())
                {
                    std::shared_ptr<Error> newItem(new Error());
                    newItem->fromJson(item);
                    return newItem;
                }

                return (std::shared_ptr<Error>)nullptr;
            });
        }
    }


    {
        m_Uploaded.clear();
        if(val.has_field(_XPLATSTR("Uploaded")) 
                            && !val[_XPLATSTR("Uploaded")].is_null())
        {
            auto arr = val[_XPLATSTR("Uploaded")].as_array();
            std::transform(arr.begin(), arr.end(), std::back_inserter(m_Uploaded), [&](web::json::value& item){
                return ModelBase::stringFromJson(item);
            });
        }
    }

}

void FilesUploadResult::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_Errors.begin(), m_Errors.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<Error> item){
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Errors"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }


    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_Uploaded.begin(), m_Uploaded.end(), std::back_inserter(jsonArray), [&](utility::string_t item){
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Uploaded"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }

}

void FilesUploadResult::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

std::vector<std::shared_ptr<Error>>& FilesUploadResult::getErrors()
{
    return m_Errors;
}


void FilesUploadResult::setErrors(std::vector<std::shared_ptr<Error>> const& value)
{
    m_Errors = value;
    m_ErrorsIsSet = true;
}

bool FilesUploadResult::errorsIsSet() const
{
    return m_ErrorsIsSet;
}

void FilesUploadResult::unsetErrors()
{
    m_ErrorsIsSet = false;
}

std::vector<utility::string_t>& FilesUploadResult::getUploaded()
{
    return m_Uploaded;
}


void FilesUploadResult::setUploaded(std::vector<utility::string_t> const& value)
{
    m_Uploaded = value;
    m_UploadedIsSet = true;
}

bool FilesUploadResult::uploadedIsSet() const
{
    return m_UploadedIsSet;
}

void FilesUploadResult::unsetUploaded()
{
    m_UploadedIsSet = false;
}

}
}
}
}
}
