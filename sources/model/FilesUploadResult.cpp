/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FilesUploadResult.cpp">
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


#include "FilesUploadResult.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

FilesUploadResult::FilesUploadResult()
{
    m_UploadedIsSet = false;
    m_ErrorsIsSet = false;
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

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_Uploaded.begin(), m_Uploaded.end(), std::back_inserter(jsonArray),
			[&](<DATA_TYPE_START>string<DATA_TYPE_END> item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("Uploaded")] = web::json::value::array(jsonArray);
        }
    }
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_Errors.begin(), m_Errors.end(), std::back_inserter(jsonArray),
			[&](<DATA_TYPE_START>Error<DATA_TYPE_END> item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("Errors")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void FilesUploadResult::fromJson(web::json::value& val)
{
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
    {
        m_Errors.clear();
        if(val.has_field(_XPLATSTR("Errors")) 
                            && !val[_XPLATSTR("Errors")].is_null())
        {
        auto arr = val[_XPLATSTR("Errors")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_Errors), [&](web::json::value& item){
            if(item.is_null())
            {
                return <DATA_TYPE_START>Error<DATA_TYPE_END>(nullptr);
            }
            else
            {
                <DATA_TYPE_START>Error<DATA_TYPE_END> newItem(new Error());
                newItem->fromJson(item);
                return newItem;
            }
        });

        }
    }
}

void FilesUploadResult::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_Uploaded.begin(), m_Uploaded.end(), std::back_inserter(jsonArray), [&](<DATA_TYPE_START>string<DATA_TYPE_END> item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Uploaded"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_Errors.begin(), m_Errors.end(), std::back_inserter(jsonArray), [&](<DATA_TYPE_START>Error<DATA_TYPE_END> item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Errors"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }
}

void FilesUploadResult::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    

    {
        m_Uploaded.clear();
        if(multipart->hasContent(_XPLATSTR("Uploaded")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Uploaded")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_Uploaded), [&](web::json::value item) {
            return ModelBase::stringFromJson(item);
        });
        }
    }
    {
        m_Errors.clear();
        if(multipart->hasContent(_XPLATSTR("Errors")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Errors")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_Errors), [&](web::json::value item) {
            if(item.is_null())
            {
                return <DATA_TYPE_START>Error<DATA_TYPE_END>(nullptr) ;
            }
            else
            {
                <DATA_TYPE_START>Error<DATA_TYPE_END> newItem(new Error());
                newItem->fromJson(item);
                return newItem ;
            }
        });
        }
    }
}

<DATA_TYPE_START>List<string><DATA_TYPE_END>& FilesUploadResult::getUploaded()
{
    return m_Uploaded;
}

void FilesUploadResult::setUploaded(<DATA_TYPE_START>List<string><DATA_TYPE_END> const& value)
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

<DATA_TYPE_START>List<Error><DATA_TYPE_END>& FilesUploadResult::getErrors()
{
    return m_Errors;
}

void FilesUploadResult::setErrors(<DATA_TYPE_START>List<Error><DATA_TYPE_END> const& value)
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

}
}
}
}
}

