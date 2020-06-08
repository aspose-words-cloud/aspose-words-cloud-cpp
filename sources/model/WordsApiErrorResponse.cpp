/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="WordsApiErrorResponse.cpp">
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


#include "WordsApiErrorResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

WordsApiErrorResponse::WordsApiErrorResponse()
{
    m_ErrorIsSet = false;
}

WordsApiErrorResponse::~WordsApiErrorResponse()
{
}

void WordsApiErrorResponse::validate()
{
    // TODO: implement validation
}

web::json::value WordsApiErrorResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();

    if(m_ErrorIsSet)
    {
        val[_XPLATSTR("Error")] = ModelBase::toJson(m_Error);
    }

    return val;
}

void WordsApiErrorResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("Error")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Error")];
        if(!fieldValue.is_null())
        {
            <DATA_TYPE_START>ApiError<DATA_TYPE_END> newItem(new ApiError());
            newItem->fromJson(fieldValue);
            setError( newItem );
        }
    }
}

void WordsApiErrorResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    WordsResponse::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_ErrorIsSet)
    {
        if (m_Error.get())
        {
            m_Error->toMultipart(multipart, _XPLATSTR("Error."));
        }
        
    }
}

void WordsApiErrorResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    WordsResponse::fromMultiPart(multipart, prefix);

    if(multipart->hasContent(_XPLATSTR("Error")))
    {
        if(multipart->hasContent(_XPLATSTR("Error")))
        {
            <DATA_TYPE_START>ApiError<DATA_TYPE_END> newItem(new ApiError());
            newItem->fromMultiPart(multipart, _XPLATSTR("Error."));
            setError( newItem );
        }
    }
}

<DATA_TYPE_START>ApiError<DATA_TYPE_END> WordsApiErrorResponse::getError() const
{
    return m_Error;
}


void WordsApiErrorResponse::setError(<DATA_TYPE_START>ApiError<DATA_TYPE_END> value)
{
    m_Error = value;
    m_ErrorIsSet = true;
}
bool WordsApiErrorResponse::errorIsSet() const
{
    return m_ErrorIsSet;
}

void WordsApiErrorResponse::unsetError()
{
    m_ErrorIsSet = false;
}

}
}
}
}
}

