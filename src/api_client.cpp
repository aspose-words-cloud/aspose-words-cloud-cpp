/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="api_client.cpp">
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

#include <random>
#include "aspose_words_cloud/api_client.h"
#include "aspose_words_cloud/requests/get_public_key_request.h"
#include "aspose_words_cloud/responses/get_public_key_response.h"

// USE THIRD PARTY LIBS ONLY IN CPP FILES!!!
#include "../thirdparty/utf8.h"
#include "../thirdparty/json.hpp"
#pragma warning(push, 0) 
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "../thirdparty/httplib.h"
#pragma warning(pop)

// INCLUDE OPENSSL
#include <openssl/rsa.h>

namespace aspose::words::cloud {
    inline ::httplib::Result callInternal(
        std::shared_ptr<::httplib::Client> client,
        HttpRequestMethod method,
        const char* path,
        const ::httplib::Headers& headers,
        const std::string& body,
        const std::string& contentType)
    {
        if (method == HttpRequestMethod::HttpGET)
        {
            return client->Get(path, headers);
        }
        else if (method == HttpRequestMethod::HttpPOST)
        {
            return client->Post(path, headers, body, contentType.c_str());
        }
        else if (method == HttpRequestMethod::HttpPUT)
        {
            return client->Put(path, headers, body, contentType.c_str());
        }
        else if (method == HttpRequestMethod::HttpDELETE)
        {
            return client->Delete(path, headers, body, contentType.c_str());
        }

        throw ApiException(400, L"Invalid http method type.");
    }

    inline void HandleHttpError(::httplib::Result& httpResponse)
    {
        if (httpResponse.error() == ::httplib::Error::Success)
            return;

        if (httpResponse.error() == ::httplib::Error::Canceled)
            throw ApiException(400, L"Canceled");

        if (httpResponse.error() == ::httplib::Error::Connection)
            throw ApiException(400, L"Failed to establish a connection to the server");

        if (httpResponse.error() == ::httplib::Error::ExceedRedirectCount)
            throw ApiException(400, L"Exceed redirect count");

        if (httpResponse.error() == ::httplib::Error::Read)
            throw ApiException(400, L"Failed read from socket");

        if (httpResponse.error() == ::httplib::Error::Write)
            throw ApiException(400, L"Failed write to socket");

        if (httpResponse.error() == ::httplib::Error::SSLConnection)
            throw ApiException(400, L"Failed to establish SSL connection");

        if (httpResponse.error() == ::httplib::Error::SSLLoadingCerts)
            throw ApiException(400, L"Failed to loading SSL certificates");

        if (httpResponse.error() == ::httplib::Error::SSLServerVerification)
            throw ApiException(400, L"Failed to validate server SSL certificate or root certificate is not present in local storage.");

        throw ApiException(400, L"Unknown socket error: " + std::to_wstring(httpResponse.error()));
    }

    inline void PrintDebugData(const std::string& data)
    {
        std::string printBuffer;
        printBuffer.reserve(2048);
        char bufHex[10];
        for (int i = 0; i < data.size(); i++) {
            uint8_t c = data[i];
            if (isprint(c)) {
                printBuffer += c;
            }
            else if (c == '\r' || c == '\n' || c == '\t') {
                printBuffer += c;
            }
            else {
#ifdef WIN32
                sprintf_s(bufHex, "%X", c);
#else
                sprintf(bufHex, "%X", c);
#endif // WIN32
                if (c < 16) printBuffer += "x0";
                else printBuffer += "x";
                printBuffer.append(bufHex);
            }

            if (printBuffer.size() > 1024) {
                std::cout << printBuffer;
                printBuffer.clear();
            }
        }

        std::cout << printBuffer;
    }

    ApiClient::ApiClient(std::shared_ptr<ApiConfiguration> configuration )
        : m_Configuration(configuration),
        m_encryptionKey(nullptr)
    {
        std::string baseUrlUtf8;
        ::utf8::utf16to8(configuration->getBaseUrl().begin(), configuration->getBaseUrl().end(), back_inserter(baseUrlUtf8));
        m_HttpClient = std::make_shared<::httplib::Client>(baseUrlUtf8.c_str());
        m_HttpClient->set_read_timeout(configuration->getTimeout(), 0);
        m_HttpClient->set_write_timeout(configuration->getTimeout(), 0);
        m_HttpClient->set_keep_alive(true);
        m_HttpClient->set_tcp_nodelay(true);
    }

    ApiClient::~ApiClient()
    {
        if (m_encryptionKey != nullptr)
        {
            RSA_free(m_encryptionKey);
            m_encryptionKey = nullptr;
        }
    }

    void ApiClient::call(
        std::shared_ptr<HttpRequestData> httpRequest,
        aspose::words::cloud::responses::ResponseModelBase& response)
    {
        httpRequest->encryptSecureData(this);

        std::lock_guard<std::mutex> lock(m_Mutex);
        if (m_AccessToken.empty()) requestToken();
        std::string path("/v4.0");
        path.append(httpRequest->getFullPath());

        ::httplib::Headers headers;
        headers.emplace("Authorization", m_AccessToken);
        headers.emplace("x-aspose-client-version", "21.12");
        headers.emplace("x-aspose-client", "C++ SDK");

        for (auto& pair : httpRequest->getHeaders()) {
            std::string keyUtf8, valueUtf8;
            ::utf8::utf16to8(pair.first.begin(), pair.first.end(), back_inserter(keyUtf8));
            ::utf8::utf16to8(pair.second.begin(), pair.second.end(), back_inserter(valueUtf8));
            headers.emplace(keyUtf8, valueUtf8);
        }

        if (m_Configuration->isDebugMode()) {
            std::cout << "==================== CALL START ====================" << std::endl;
            std::cout << "REQUEST:" << std::endl;
            std::cout << "\tURL: " << path << std::endl;
            if (headers.size() > 0) {
                std::cout << "\tHEADERS: " << std::endl;
            }
            for (auto& pair : headers) {
                std::cout << "\t\t" << pair.first << ": " << pair.second << std::endl;
            }
            if (httpRequest->getContentType().size() > 0) {
                std::cout << "\tCONTENT-TYPE: " << httpRequest->getContentType() << std::endl;
            }
            if (httpRequest->getBody().size() > 0) {
                std::cout << "\tBODY: ";
                PrintDebugData(httpRequest->getBody());
                std::cout << std::endl;
            }
        }

        ::httplib::Result httpResponse = callInternal(
            m_HttpClient, 
            httpRequest->getMethod(), 
            path.c_str(), headers, 
            httpRequest->getBody(), 
            httpRequest->getContentType());
        HandleHttpError(httpResponse);

        if (httpResponse->status == 401)
        {
            requestToken();
            httpResponse = callInternal(
                m_HttpClient,
                httpRequest->getMethod(),
                path.c_str(), headers,
                httpRequest->getBody(),
                httpRequest->getContentType());
            HandleHttpError(httpResponse);
        }

        if (m_Configuration->isDebugMode()) {
            std::cout << "RESPONSE:" << std::endl;
            std::cout << "\tSTATUS CODE: " << httpResponse->status << std::endl;
            std::cout << "\tRESULT: ";
            PrintDebugData(httpResponse->body);
            std::cout << std::endl;
            std::cout << "==================== CALL END ====================" << std::endl;
        }

        response.setStatusCode(httpResponse->status);
        if (httpResponse->status == 200)
        {
            response.deserialize(httpResponse->body);
        }
        else
        {
            response.setErrorData(httpResponse->body);
        }
    }

    void ApiClient::requestToken()
    {
        if (m_Configuration == nullptr)
            throw ApiException(400, L"Configuration must be set before calling an api methods");

        if(m_Configuration->getClientId().empty())
            throw ApiException(400, L"Configuration parameter ClientId must be set before calling an api methods");

        if (m_Configuration->getClientSecret().empty())
            throw ApiException(400, L"Configuration parameter ClientSecret must be set before calling an api methods");

        std::string bodyUtf8;
        std::wstring body = L"grant_type=client_credentials&client_id=" + m_Configuration->getClientId() + L"&client_secret=" + m_Configuration->getClientSecret();
        ::utf8::utf16to8(body.begin(), body.end(), back_inserter(bodyUtf8));

        ::httplib::Result result = m_HttpClient->Post("/connect/token", bodyUtf8, "application/x-www-form-urlencoded");
        HandleHttpError(result);
        if (result->status != 200)
        {
            std::wstring errorMessage;
            ::utf8::utf8to16(result->body.begin(), result->body.end(), back_inserter(errorMessage));
            throw ApiException(result->status, L"Failed to request authorization token:\r\n" + errorMessage);
        }

        auto json = ::nlohmann::json::parse(result->body);
        m_AccessToken = "Bearer " + json["access_token"].get<std::string>();
    }

    unsigned char* base64_decode(const char* base64data, int* len) {
        BIO* b64, * bmem;
        size_t length = strlen(base64data);
        unsigned char* buffer = (unsigned char*)malloc(length);
        b64 = BIO_new(BIO_f_base64());
        BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
        bmem = BIO_new_mem_buf((void*)base64data, (int)length);
        bmem = BIO_push(b64, bmem);
        *len = BIO_read(bmem, buffer, (int)length);
        BIO_free_all(bmem);
        return buffer;
    }

    BIGNUM* bignum_base64_decode(const char* base64bignum) {
        BIGNUM* bn = NULL;
        int len;
        unsigned char* data = base64_decode(base64bignum, &len);
        if (len) {
            bn = BN_bin2bn(data, len, NULL);
        }
        free(data);
        return bn;
    }

    RSA* RSA_fromBase64(const char* modulus_b64, const char* exp_b64) {
        BIGNUM* n = bignum_base64_decode(modulus_b64);
        BIGNUM* e = bignum_base64_decode(exp_b64);
        if (e && n) {
            RSA* rsa = RSA_new();
            RSA_set0_key(rsa, n, e, nullptr);
            return rsa;
        }
        else {
            if (n) BN_free(n);
            if (e) BN_free(e);
            return NULL;
        }
    }

    void ApiClient::requestEncryptionKey()
    {
        if (m_encryptionKey == nullptr)
        {
            auto request = std::make_shared<aspose::words::cloud::requests::GetPublicKeyRequest>();
            auto response = std::make_shared<aspose::words::cloud::responses::GetPublicKeyResponse>();
            this->call(request->createHttpRequest(), *response);
            if (response->getStatusCode() != 200) {
                throw aspose::words::cloud::ApiException(response->getStatusCode(), response->getErrorMessage());
            }

            auto result = response->getResult();

            std::string modulus, exponent;
            ::utf8::utf16to8(result->getModulus()->begin(), result->getModulus()->end(), back_inserter(modulus));
            ::utf8::utf16to8(result->getExponent()->begin(), result->getExponent()->end(), back_inserter(exponent));
            m_encryptionKey = RSA_fromBase64(modulus.c_str(), exponent.c_str());

            if (m_encryptionKey == nullptr)
            {
                throw ApiException(400, L"Failed to create encryption key.");
            }
        }
    }

    ::std::wstring ApiClient::encryptString(const ::std::wstring& text)
    {
        requestEncryptionKey();

        std::string plainText;
        ::utf8::utf16to8(text.begin(), text.end(), back_inserter(plainText));

        unsigned char* crypttext = new unsigned char[RSA_size(m_encryptionKey)];
        int cryptLength = RSA_public_encrypt(
            (int)plainText.length(),
            (const unsigned char*)plainText.data(),
            crypttext,
            m_encryptionKey,
            RSA_PKCS1_PADDING
        );

        BIO* base64 = BIO_new(BIO_s_mem());
        base64 = BIO_push(BIO_new(BIO_f_base64()), base64);
        BIO_write(base64, crypttext, cryptLength);
        BIO_flush(base64);
        char* base64Data;
        const long base64Length = BIO_get_mem_data(base64, &base64Data);
        auto base64Str = std::string(base64Data, base64Length);
        BIO_free(base64);
        delete[] crypttext;

        ::std::wstring result;
        ::utf8::utf8to16(base64Str.begin(), base64Str.end(), back_inserter(result));
        return result;
    }

    std::string ApiClient::createRandomGuid()
    {
        static std::random_device dev;
        static std::mt19937 rng(dev());

        std::uniform_int_distribution<int> dist(0, 15);

        const char* v = "0123456789abcdef";
        const bool dash[] = { 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0 };

        std::string res;
        for (int i = 0; i < 16; i++) {
            if (dash[i]) res += '-';
            res += v[dist(rng)];
            res += v[dist(rng)];
        }
        return res;
    }
}
