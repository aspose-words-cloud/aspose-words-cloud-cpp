/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FilesList.cpp">
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


#include "FilesList.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

FilesList::FilesList()
{
    m_ValueIsSet = false;
}

FilesList::~FilesList()
{
}

void FilesList::validate()
{
    // TODO: implement validation
}

web::json::value FilesList::toJson() const
{
    web::json::value val = web::json::value::object();

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_Value.begin(), m_Value.end(), std::back_inserter(jsonArray),
			[&](<DATA_TYPE_START>StorageFile<DATA_TYPE_END> item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("Value")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void FilesList::fromJson(web::json::value& val)
{
    {
        m_Value.clear();
        if(val.has_field(_XPLATSTR("Value")) 
                            && !val[_XPLATSTR("Value")].is_null())
        {
        auto arr = val[_XPLATSTR("Value")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_Value), [&](web::json::value& item){
            if(item.is_null())
            {
                return <DATA_TYPE_START>StorageFile<DATA_TYPE_END>(nullptr);
            }
            else
            {
                <DATA_TYPE_START>StorageFile<DATA_TYPE_END> newItem(new StorageFile());
                newItem->fromJson(item);
                return newItem;
            }
        });

        }
    }
}

void FilesList::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_Value.begin(), m_Value.end(), std::back_inserter(jsonArray), [&](<DATA_TYPE_START>StorageFile<DATA_TYPE_END> item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Value"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }
}

void FilesList::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    

    {
        m_Value.clear();
        if(multipart->hasContent(_XPLATSTR("Value")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Value")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_Value), [&](web::json::value item) {
            if(item.is_null())
            {
                return <DATA_TYPE_START>StorageFile<DATA_TYPE_END>(nullptr) ;
            }
            else
            {
                <DATA_TYPE_START>StorageFile<DATA_TYPE_END> newItem(new StorageFile());
                newItem->fromJson(item);
                return newItem ;
            }
        });
        }
    }
}

<DATA_TYPE_START>List<StorageFile><DATA_TYPE_END>& FilesList::getValue()
{
    return m_Value;
}

void FilesList::setValue(<DATA_TYPE_START>List<StorageFile><DATA_TYPE_END> const& value)
{
    m_Value = value;
    m_ValueIsSet = true;
}
bool FilesList::valueIsSet() const
{
    return m_ValueIsSet;
}

void FilesList::unsetValue()
{
    m_ValueIsSet = false;
}

}
}
}
}
}

