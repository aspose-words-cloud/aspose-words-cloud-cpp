/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="api_error.cpp">
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

#include "aspose_words_cloud/models/api_error.h"
#include "../thirdparty/json.hpp"
#include "../thirdparty/utf8.h"

namespace aspose::words::cloud::models {
    inline std::wstring convertUtf8(const std::string& value)
    {
        std::wstring result;
        ::utf8::utf8to16(value.begin(), value.end(), back_inserter(result));
        return result;
    }

    inline std::string convertUtf16(const std::wstring& value)
    {
        std::string result;
        ::utf8::utf16to8(value.begin(), value.end(), back_inserter(result));
        return result;
    }

    void ApiError::toJson(void* jsonIfc) const
    {
        ::nlohmann::json& json = *((::nlohmann::json*)jsonIfc);
        if (m_Code) json["Code"] = convertUtf16(*m_Code);
        if (m_DateTime) json["DateTime"] = *m_DateTime;
        if (m_Description) json["Description"] = convertUtf16(*m_Description);
        if (m_InnerError) m_InnerError->toJson(&json["InnerError"]);
        if (m_Message) json["Message"] = convertUtf16(*m_Message);
    }

    void ApiError::fromJson(const void* jsonIfc)
    {
        ::nlohmann::json& json = *((::nlohmann::json*)jsonIfc);
        if (json.contains("Code") && !json["Code"].is_null()) m_Code = std::make_shared< std::wstring >(convertUtf8( json["Code"].get< std::string >() ));
        if (json.contains("DateTime") && !json["DateTime"].is_null()) m_DateTime = std::make_shared< std::time_t >(json["DateTime"].get< std::time_t >());
        if (json.contains("Description") && !json["Description"].is_null()) m_Description = std::make_shared< std::wstring >(convertUtf8( json["Description"].get< std::string >() ));
        if (json.contains("InnerError") && !json["InnerError"].is_null()) m_InnerError->fromJson(&json["InnerError"]);
        if (json.contains("Message") && !json["Message"].is_null()) m_Message = std::make_shared< std::wstring >(convertUtf8( json["Message"].get< std::string >() ));
    }

    std::shared_ptr< std::wstring >& ApiError::getCode()
    {
        return m_Code;
    }

    void ApiError::setCode(std::shared_ptr< std::wstring >& value)
    {
        m_Code = value;
    }

    std::shared_ptr< std::time_t >& ApiError::getDateTime()
    {
        return m_DateTime;
    }

    void ApiError::setDateTime(std::shared_ptr< std::time_t >& value)
    {
        m_DateTime = value;
    }

    std::shared_ptr< std::wstring >& ApiError::getDescription()
    {
        return m_Description;
    }

    void ApiError::setDescription(std::shared_ptr< std::wstring >& value)
    {
        m_Description = value;
    }

    std::shared_ptr< ApiError >& ApiError::getInnerError()
    {
        return m_InnerError;
    }

    void ApiError::setInnerError(std::shared_ptr< ApiError >& value)
    {
        m_InnerError = value;
    }

    std::shared_ptr< std::wstring >& ApiError::getMessage()
    {
        return m_Message;
    }

    void ApiError::setMessage(std::shared_ptr< std::wstring >& value)
    {
        m_Message = value;
    }
}
