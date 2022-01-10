/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="api_client.h">
*   Copyright (c) 2022 Aspose.Words for Cloud
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

#pragma once
#include <mutex>
#include <memory>
#include "./api_configuration.h"
#include "./api_exception.h"
#include "./http_request_data.h"
#include "./responses/response_model_base.h"
#include "./common.h"

struct rsa_st;
namespace httplib {
    class Client;
}

namespace aspose::words::cloud {
    class ApiClient
    {
    public:
        ASPOSE_WORDS_CLOUD_EXPORT ApiClient(std::shared_ptr<ApiConfiguration> configuration);
        ASPOSE_WORDS_CLOUD_EXPORT virtual ~ApiClient();

        ASPOSE_WORDS_CLOUD_EXPORT void call(
            std::shared_ptr< HttpRequestData > httpRequest,
            aspose::words::cloud::responses::ResponseModelBase& response);

        ASPOSE_WORDS_CLOUD_EXPORT ::std::wstring encryptString(const ::std::wstring& text);

        static ASPOSE_WORDS_CLOUD_EXPORT std::string createRandomGuid();

    private:
        void requestToken();
        void requestEncryptionKey();
        std::shared_ptr<::httplib::Client> m_HttpClient;
        std::shared_ptr<ApiConfiguration> m_Configuration;
        std::string m_AccessToken;
        std::mutex m_Mutex;
        rsa_st* m_encryptionKey;
    };
}
