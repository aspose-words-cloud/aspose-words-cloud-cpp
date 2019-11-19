/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ApiException.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_ApiException_H_
#define ASPOSE_WORDS_CLOUD_API_ApiException_H_



#include <memory>
#include <map>

#include <cpprest/details/basic_types.h>
#include <cpprest/http_msg.h>

#include "model/WordsApiErrorResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {

class  ApiException
    : public web::http::http_exception
{
public:
    ApiException( int errorCode
        , const utility::string_t& message
        , std::shared_ptr<aspose::words::cloud::api::models::WordsApiErrorResponse> response = nullptr );
    ApiException( int errorCode
        , const utility::string_t& message
        , std::map<utility::string_t, utility::string_t>& headers
        , std::shared_ptr<aspose::words::cloud::api::models::WordsApiErrorResponse> response = nullptr );

    std::map<utility::string_t, utility::string_t>& getHeaders();
    std::shared_ptr<aspose::words::cloud::api::models::WordsApiErrorResponse> getResponse() const;

protected:
    std::shared_ptr<aspose::words::cloud::api::models::WordsApiErrorResponse> m_Response;
    std::map<utility::string_t, utility::string_t> m_Headers;
};

}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_ApiBase_H_ */
