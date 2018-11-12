/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="WordsApi.cpp">
*   Copyright (c) 2018 Aspose.Words for Cloud
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

#include "WordsApi.h"
#include "IHttpBody.h"
#include "JsonBody.h"
#include "MultipartFormData.h"

#include <unordered_set>

#include <boost/algorithm/string/replace.hpp>

namespace io {
namespace swagger {
namespace client {
namespace api {

using namespace io::swagger::client::model;

WordsApi::WordsApi( std::shared_ptr<ApiClient> apiClient )
    : m_ApiClient(apiClient)
{
}

WordsApi::~WordsApi()
{
}

pplx::task<std::shared_ptr<RevisionsModificationResponse>> WordsApi::acceptAllRevisions(std::shared_ptr<AcceptAllRevisionsRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/revisions/acceptAll");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->acceptAllRevisions does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->acceptAllRevisions does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling acceptAllRevisions: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling acceptAllRevisions: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<RevisionsModificationResponse> result(new RevisionsModificationResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling acceptAllRevisions: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<ClassificationResponse>> WordsApi::classify(std::shared_ptr<ClassifyRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/classify");
    
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->classify does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->bestClassesCount)
    {
        queryParams[utility::conversions::to_string_t("BestClassesCount")] = ApiClient::parameterToString(*(request->bestClassesCount));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->text);

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);
        multipart->add(ModelBase::toHttpContent(L"text", request->text));

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->classify does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling classify: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling classify: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<ClassificationResponse> result(new ClassificationResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling classify: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<ClassificationResponse>> WordsApi::classifyDocument(std::shared_ptr<ClassifyDocumentRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{documentName}/classify");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("DocumentName") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->documentName));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->classifyDocument does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->bestClassesCount)
    {
        queryParams[utility::conversions::to_string_t("BestClassesCount")] = ApiClient::parameterToString(*(request->bestClassesCount));
    }
    if (request->taxonomy)
    {
        queryParams[utility::conversions::to_string_t("Taxonomy")] = ApiClient::parameterToString(*(request->taxonomy));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->classifyDocument does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling classifyDocument: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling classifyDocument: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<ClassificationResponse> result(new ClassificationResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling classifyDocument: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<DocumentPropertyResponse>> WordsApi::createOrUpdateDocumentProperty(std::shared_ptr<CreateOrUpdateDocumentPropertyRequest> request)
{

    // verify the required parameter 'property' is set
    if (request->property == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'property' when calling WordsApi->createOrUpdateDocumentProperty"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/documentProperties/{propertyName}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("PropertyName") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->propertyName));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->createOrUpdateDocumentProperty does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->property);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->property.get())
        {
            (request->property)->toMultipart(multipart, utility::conversions::to_string_t("property"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->createOrUpdateDocumentProperty does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling createOrUpdateDocumentProperty: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling createOrUpdateDocumentProperty: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<DocumentPropertyResponse> result(new DocumentPropertyResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling createOrUpdateDocumentProperty: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<BorderResponse>> WordsApi::deleteBorder(std::shared_ptr<DeleteBorderRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/borders/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("NodePath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->nodePath));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->deleteBorder does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->deleteBorder does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling deleteBorder: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling deleteBorder: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<BorderResponse> result(new BorderResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling deleteBorder: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<BordersResponse>> WordsApi::deleteBorders(std::shared_ptr<DeleteBordersRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/borders");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("NodePath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->nodePath));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->deleteBorders does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->deleteBorders does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling deleteBorders: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling deleteBorders: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<BordersResponse> result(new BordersResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling deleteBorders: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteComment(std::shared_ptr<DeleteCommentRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/comments/{commentIndex}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("CommentIndex") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->commentIndex));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->deleteComment does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->deleteComment does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling deleteComment: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling deleteComment: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<AsposeResponse> result(new AsposeResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling deleteComment: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteDocumentMacros(std::shared_ptr<DeleteDocumentMacrosRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/macros");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->deleteDocumentMacros does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->deleteDocumentMacros does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling deleteDocumentMacros: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling deleteDocumentMacros: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<AsposeResponse> result(new AsposeResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling deleteDocumentMacros: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteDocumentProperty(std::shared_ptr<DeleteDocumentPropertyRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/documentProperties/{propertyName}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("PropertyName") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->propertyName));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->deleteDocumentProperty does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->deleteDocumentProperty does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling deleteDocumentProperty: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling deleteDocumentProperty: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<AsposeResponse> result(new AsposeResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling deleteDocumentProperty: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<DocumentResponse>> WordsApi::deleteDocumentWatermark(std::shared_ptr<DeleteDocumentWatermarkRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/watermark");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->deleteDocumentWatermark does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->deleteDocumentWatermark does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling deleteDocumentWatermark: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling deleteDocumentWatermark: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<DocumentResponse> result(new DocumentResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling deleteDocumentWatermark: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteDrawingObject(std::shared_ptr<DeleteDrawingObjectRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/drawingObjects/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->deleteDrawingObject does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->deleteDrawingObject does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling deleteDrawingObject: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling deleteDrawingObject: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<AsposeResponse> result(new AsposeResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling deleteDrawingObject: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteField(std::shared_ptr<DeleteFieldRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/fields/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->deleteField does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->deleteField does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling deleteField: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling deleteField: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<AsposeResponse> result(new AsposeResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling deleteField: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteFields(std::shared_ptr<DeleteFieldsRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/fields");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->deleteFields does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->deleteFields does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling deleteFields: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling deleteFields: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<AsposeResponse> result(new AsposeResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling deleteFields: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteFootnote(std::shared_ptr<DeleteFootnoteRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/footnotes/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->deleteFootnote does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->deleteFootnote does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling deleteFootnote: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling deleteFootnote: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<AsposeResponse> result(new AsposeResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling deleteFootnote: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteFormField(std::shared_ptr<DeleteFormFieldRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/formfields/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->deleteFormField does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->deleteFormField does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling deleteFormField: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling deleteFormField: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<AsposeResponse> result(new AsposeResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling deleteFormField: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteHeaderFooter(std::shared_ptr<DeleteHeaderFooterRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{sectionPath}/headersfooters/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->deleteHeaderFooter does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }
    if (request->sectionPath)
    {
        queryParams[utility::conversions::to_string_t("SectionPath")] = ApiClient::parameterToString(*(request->sectionPath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->deleteHeaderFooter does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling deleteHeaderFooter: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling deleteHeaderFooter: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<AsposeResponse> result(new AsposeResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling deleteHeaderFooter: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteHeadersFooters(std::shared_ptr<DeleteHeadersFootersRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{sectionPath}/headersfooters");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->deleteHeadersFooters does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }
    if (request->sectionPath)
    {
        queryParams[utility::conversions::to_string_t("SectionPath")] = ApiClient::parameterToString(*(request->sectionPath));
    }
    if (request->headersFootersTypes)
    {
        queryParams[utility::conversions::to_string_t("HeadersFootersTypes")] = ApiClient::parameterToString(*(request->headersFootersTypes));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->deleteHeadersFooters does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling deleteHeadersFooters: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling deleteHeadersFooters: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<AsposeResponse> result(new AsposeResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling deleteHeadersFooters: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteOfficeMathObject(std::shared_ptr<DeleteOfficeMathObjectRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/OfficeMathObjects/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->deleteOfficeMathObject does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->deleteOfficeMathObject does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling deleteOfficeMathObject: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling deleteOfficeMathObject: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<AsposeResponse> result(new AsposeResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling deleteOfficeMathObject: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteParagraph(std::shared_ptr<DeleteParagraphRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/paragraphs/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->deleteParagraph does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->deleteParagraph does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling deleteParagraph: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling deleteParagraph: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<AsposeResponse> result(new AsposeResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling deleteParagraph: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteRun(std::shared_ptr<DeleteRunRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{paragraphPath}/runs/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("ParagraphPath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->paragraphPath));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->deleteRun does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->deleteRun does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling deleteRun: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling deleteRun: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<AsposeResponse> result(new AsposeResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling deleteRun: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteTable(std::shared_ptr<DeleteTableRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/tables/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->deleteTable does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->deleteTable does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling deleteTable: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling deleteTable: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<AsposeResponse> result(new AsposeResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling deleteTable: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteTableCell(std::shared_ptr<DeleteTableCellRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{tableRowPath}/cells/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("TableRowPath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->tableRowPath));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->deleteTableCell does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->deleteTableCell does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling deleteTableCell: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling deleteTableCell: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<AsposeResponse> result(new AsposeResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling deleteTableCell: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteTableRow(std::shared_ptr<DeleteTableRowRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{tablePath}/rows/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("TablePath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->tablePath));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->deleteTableRow does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->deleteTableRow does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling deleteTableRow: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling deleteTableRow: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<AsposeResponse> result(new AsposeResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling deleteTableRow: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<ProtectionDataResponse>> WordsApi::deleteUnprotectDocument(std::shared_ptr<DeleteUnprotectDocumentRequest> request)
{

    // verify the required parameter 'protectionRequest' is set
    if (request->protectionRequest == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'protectionRequest' when calling WordsApi->deleteUnprotectDocument"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/protection");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->deleteUnprotectDocument does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->protectionRequest);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->protectionRequest.get())
        {
            (request->protectionRequest)->toMultipart(multipart, utility::conversions::to_string_t("protectionRequest"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->deleteUnprotectDocument does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling deleteUnprotectDocument: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling deleteUnprotectDocument: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<ProtectionDataResponse> result(new ProtectionDataResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling deleteUnprotectDocument: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<AvailableFontsResponse>> WordsApi::getAvailableFonts(std::shared_ptr<GetAvailableFontsRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/fonts/available");
    
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getAvailableFonts does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->fontsLocation)
    {
        queryParams[utility::conversions::to_string_t("FontsLocation")] = ApiClient::parameterToString(*(request->fontsLocation));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getAvailableFonts does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getAvailableFonts: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getAvailableFonts: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<AvailableFontsResponse> result(new AvailableFontsResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getAvailableFonts: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<BorderResponse>> WordsApi::getBorder(std::shared_ptr<GetBorderRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/borders/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("NodePath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->nodePath));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getBorder does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getBorder does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getBorder: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getBorder: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<BorderResponse> result(new BorderResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getBorder: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<BordersResponse>> WordsApi::getBorders(std::shared_ptr<GetBordersRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/borders");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("NodePath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->nodePath));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getBorders does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getBorders does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getBorders: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getBorders: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<BordersResponse> result(new BordersResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getBorders: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<CommentResponse>> WordsApi::getComment(std::shared_ptr<GetCommentRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/comments/{commentIndex}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("CommentIndex") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->commentIndex));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getComment does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getComment does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getComment: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getComment: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<CommentResponse> result(new CommentResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getComment: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<CommentsResponse>> WordsApi::getComments(std::shared_ptr<GetCommentsRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/comments");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getComments does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getComments does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getComments: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getComments: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<CommentsResponse> result(new CommentsResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getComments: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<DocumentResponse>> WordsApi::getDocument(std::shared_ptr<GetDocumentRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{documentName}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("DocumentName") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->documentName));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getDocument does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getDocument does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getDocument: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getDocument: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<DocumentResponse> result(new DocumentResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getDocument: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<BookmarkResponse>> WordsApi::getDocumentBookmarkByName(std::shared_ptr<GetDocumentBookmarkByNameRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/bookmarks/{bookmarkName}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("BookmarkName") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->bookmarkName));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getDocumentBookmarkByName does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getDocumentBookmarkByName does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getDocumentBookmarkByName: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getDocumentBookmarkByName: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<BookmarkResponse> result(new BookmarkResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getDocumentBookmarkByName: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<BookmarksResponse>> WordsApi::getDocumentBookmarks(std::shared_ptr<GetDocumentBookmarksRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/bookmarks");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getDocumentBookmarks does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getDocumentBookmarks does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getDocumentBookmarks: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getDocumentBookmarks: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<BookmarksResponse> result(new BookmarksResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getDocumentBookmarks: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<DrawingObjectResponse>> WordsApi::getDocumentDrawingObjectByIndex(std::shared_ptr<GetDocumentDrawingObjectByIndexRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/drawingObjects/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getDocumentDrawingObjectByIndex does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getDocumentDrawingObjectByIndex does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getDocumentDrawingObjectByIndex: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getDocumentDrawingObjectByIndex: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<DrawingObjectResponse> result(new DrawingObjectResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getDocumentDrawingObjectByIndex: unsupported response type"));
        }

        return result;
    });
}
pplx::task<HttpContent> WordsApi::getDocumentDrawingObjectImageData(std::shared_ptr<GetDocumentDrawingObjectImageDataRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/drawingObjects/{index}/imageData");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getDocumentDrawingObjectImageData does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getDocumentDrawingObjectImageData: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getDocumentDrawingObjectImageData: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<HttpContent> WordsApi::getDocumentDrawingObjectOleData(std::shared_ptr<GetDocumentDrawingObjectOleDataRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/drawingObjects/{index}/oleData");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getDocumentDrawingObjectOleData does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getDocumentDrawingObjectOleData: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getDocumentDrawingObjectOleData: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<std::shared_ptr<DrawingObjectsResponse>> WordsApi::getDocumentDrawingObjects(std::shared_ptr<GetDocumentDrawingObjectsRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/drawingObjects");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getDocumentDrawingObjects does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getDocumentDrawingObjects does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getDocumentDrawingObjects: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getDocumentDrawingObjects: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<DrawingObjectsResponse> result(new DrawingObjectsResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getDocumentDrawingObjects: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<FieldNamesResponse>> WordsApi::getDocumentFieldNames(std::shared_ptr<GetDocumentFieldNamesRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/mailMergeFieldNames");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getDocumentFieldNames does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->useNonMergeFields)
    {
        queryParams[utility::conversions::to_string_t("UseNonMergeFields")] = ApiClient::parameterToString(*(request->useNonMergeFields));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getDocumentFieldNames does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getDocumentFieldNames: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getDocumentFieldNames: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<FieldNamesResponse> result(new FieldNamesResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getDocumentFieldNames: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<HyperlinkResponse>> WordsApi::getDocumentHyperlinkByIndex(std::shared_ptr<GetDocumentHyperlinkByIndexRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/hyperlinks/{hyperlinkIndex}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("HyperlinkIndex") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->hyperlinkIndex));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getDocumentHyperlinkByIndex does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getDocumentHyperlinkByIndex does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getDocumentHyperlinkByIndex: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getDocumentHyperlinkByIndex: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<HyperlinkResponse> result(new HyperlinkResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getDocumentHyperlinkByIndex: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<HyperlinksResponse>> WordsApi::getDocumentHyperlinks(std::shared_ptr<GetDocumentHyperlinksRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/hyperlinks");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getDocumentHyperlinks does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getDocumentHyperlinks does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getDocumentHyperlinks: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getDocumentHyperlinks: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<HyperlinksResponse> result(new HyperlinksResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getDocumentHyperlinks: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<ParagraphResponse>> WordsApi::getDocumentParagraph(std::shared_ptr<GetDocumentParagraphRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/paragraphs/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getDocumentParagraph does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getDocumentParagraph does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getDocumentParagraph: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getDocumentParagraph: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<ParagraphResponse> result(new ParagraphResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getDocumentParagraph: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<ParagraphFormatResponse>> WordsApi::getDocumentParagraphFormat(std::shared_ptr<GetDocumentParagraphFormatRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/paragraphs/{index}/format");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getDocumentParagraphFormat does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getDocumentParagraphFormat does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getDocumentParagraphFormat: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getDocumentParagraphFormat: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<ParagraphFormatResponse> result(new ParagraphFormatResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getDocumentParagraphFormat: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<RunResponse>> WordsApi::getDocumentParagraphRun(std::shared_ptr<GetDocumentParagraphRunRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{paragraphPath}/runs/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("ParagraphPath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->paragraphPath));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getDocumentParagraphRun does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getDocumentParagraphRun does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getDocumentParagraphRun: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getDocumentParagraphRun: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<RunResponse> result(new RunResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getDocumentParagraphRun: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<FontResponse>> WordsApi::getDocumentParagraphRunFont(std::shared_ptr<GetDocumentParagraphRunFontRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{paragraphPath}/runs/{index}/font");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("ParagraphPath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->paragraphPath));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getDocumentParagraphRunFont does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getDocumentParagraphRunFont does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getDocumentParagraphRunFont: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getDocumentParagraphRunFont: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<FontResponse> result(new FontResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getDocumentParagraphRunFont: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<RunsResponse>> WordsApi::getDocumentParagraphRuns(std::shared_ptr<GetDocumentParagraphRunsRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{paragraphPath}/runs");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("ParagraphPath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->paragraphPath));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getDocumentParagraphRuns does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getDocumentParagraphRuns does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getDocumentParagraphRuns: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getDocumentParagraphRuns: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<RunsResponse> result(new RunsResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getDocumentParagraphRuns: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<ParagraphLinkCollectionResponse>> WordsApi::getDocumentParagraphs(std::shared_ptr<GetDocumentParagraphsRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/paragraphs");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getDocumentParagraphs does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getDocumentParagraphs does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getDocumentParagraphs: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getDocumentParagraphs: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<ParagraphLinkCollectionResponse> result(new ParagraphLinkCollectionResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getDocumentParagraphs: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<DocumentPropertiesResponse>> WordsApi::getDocumentProperties(std::shared_ptr<GetDocumentPropertiesRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/documentProperties");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getDocumentProperties does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getDocumentProperties does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getDocumentProperties: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getDocumentProperties: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<DocumentPropertiesResponse> result(new DocumentPropertiesResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getDocumentProperties: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<DocumentPropertyResponse>> WordsApi::getDocumentProperty(std::shared_ptr<GetDocumentPropertyRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/documentProperties/{propertyName}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("PropertyName") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->propertyName));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getDocumentProperty does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getDocumentProperty does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getDocumentProperty: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getDocumentProperty: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<DocumentPropertyResponse> result(new DocumentPropertyResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getDocumentProperty: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<ProtectionDataResponse>> WordsApi::getDocumentProtection(std::shared_ptr<GetDocumentProtectionRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/protection");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getDocumentProtection does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getDocumentProtection does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getDocumentProtection: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getDocumentProtection: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<ProtectionDataResponse> result(new ProtectionDataResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getDocumentProtection: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<StatDataResponse>> WordsApi::getDocumentStatistics(std::shared_ptr<GetDocumentStatisticsRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/statistics");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getDocumentStatistics does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->includeComments)
    {
        queryParams[utility::conversions::to_string_t("IncludeComments")] = ApiClient::parameterToString(*(request->includeComments));
    }
    if (request->includeFootnotes)
    {
        queryParams[utility::conversions::to_string_t("IncludeFootnotes")] = ApiClient::parameterToString(*(request->includeFootnotes));
    }
    if (request->includeTextInShapes)
    {
        queryParams[utility::conversions::to_string_t("IncludeTextInShapes")] = ApiClient::parameterToString(*(request->includeTextInShapes));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getDocumentStatistics does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getDocumentStatistics: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getDocumentStatistics: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<StatDataResponse> result(new StatDataResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getDocumentStatistics: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<TextItemsResponse>> WordsApi::getDocumentTextItems(std::shared_ptr<GetDocumentTextItemsRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/textItems");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getDocumentTextItems does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getDocumentTextItems does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getDocumentTextItems: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getDocumentTextItems: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<TextItemsResponse> result(new TextItemsResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getDocumentTextItems: unsupported response type"));
        }

        return result;
    });
}
pplx::task<HttpContent> WordsApi::getDocumentWithFormat(std::shared_ptr<GetDocumentWithFormatRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    {
        queryParams[utility::conversions::to_string_t("Format")] = ApiClient::parameterToString((request->format));
    }
    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->outPath)
    {
        queryParams[utility::conversions::to_string_t("OutPath")] = ApiClient::parameterToString(*(request->outPath));
    }
    if (request->fontsLocation)
    {
        queryParams[utility::conversions::to_string_t("FontsLocation")] = ApiClient::parameterToString(*(request->fontsLocation));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getDocumentWithFormat does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getDocumentWithFormat: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getDocumentWithFormat: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<std::shared_ptr<FieldResponse>> WordsApi::getField(std::shared_ptr<GetFieldRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/fields/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getField does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getField does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getField: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getField: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<FieldResponse> result(new FieldResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getField: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<FieldsResponse>> WordsApi::getFields(std::shared_ptr<GetFieldsRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/fields");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getFields does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getFields does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getFields: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getFields: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<FieldsResponse> result(new FieldsResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getFields: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<FootnoteResponse>> WordsApi::getFootnote(std::shared_ptr<GetFootnoteRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/footnotes/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getFootnote does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getFootnote does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getFootnote: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getFootnote: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<FootnoteResponse> result(new FootnoteResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getFootnote: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<FootnotesResponse>> WordsApi::getFootnotes(std::shared_ptr<GetFootnotesRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/footnotes");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getFootnotes does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getFootnotes does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getFootnotes: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getFootnotes: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<FootnotesResponse> result(new FootnotesResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getFootnotes: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<FormFieldResponse>> WordsApi::getFormField(std::shared_ptr<GetFormFieldRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/formfields/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getFormField does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getFormField does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getFormField: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getFormField: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<FormFieldResponse> result(new FormFieldResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getFormField: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<FormFieldsResponse>> WordsApi::getFormFields(std::shared_ptr<GetFormFieldsRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/formfields");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getFormFields does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getFormFields does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getFormFields: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getFormFields: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<FormFieldsResponse> result(new FormFieldsResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getFormFields: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<HeaderFooterResponse>> WordsApi::getHeaderFooter(std::shared_ptr<GetHeaderFooterRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/headersfooters/{headerFooterIndex}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("HeaderFooterIndex") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->headerFooterIndex));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getHeaderFooter does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->filterByType)
    {
        queryParams[utility::conversions::to_string_t("FilterByType")] = ApiClient::parameterToString(*(request->filterByType));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getHeaderFooter does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getHeaderFooter: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getHeaderFooter: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<HeaderFooterResponse> result(new HeaderFooterResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getHeaderFooter: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<HeaderFooterResponse>> WordsApi::getHeaderFooterOfSection(std::shared_ptr<GetHeaderFooterOfSectionRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/sections/{sectionIndex}/headersfooters/{headerFooterIndex}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("HeaderFooterIndex") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->headerFooterIndex));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("SectionIndex") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->sectionIndex));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getHeaderFooterOfSection does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->filterByType)
    {
        queryParams[utility::conversions::to_string_t("FilterByType")] = ApiClient::parameterToString(*(request->filterByType));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getHeaderFooterOfSection does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getHeaderFooterOfSection: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getHeaderFooterOfSection: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<HeaderFooterResponse> result(new HeaderFooterResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getHeaderFooterOfSection: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<HeaderFootersResponse>> WordsApi::getHeaderFooters(std::shared_ptr<GetHeaderFootersRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{sectionPath}/headersfooters");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getHeaderFooters does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->sectionPath)
    {
        queryParams[utility::conversions::to_string_t("SectionPath")] = ApiClient::parameterToString(*(request->sectionPath));
    }
    if (request->filterByType)
    {
        queryParams[utility::conversions::to_string_t("FilterByType")] = ApiClient::parameterToString(*(request->filterByType));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getHeaderFooters does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getHeaderFooters: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getHeaderFooters: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<HeaderFootersResponse> result(new HeaderFootersResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getHeaderFooters: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<OfficeMathObjectResponse>> WordsApi::getOfficeMathObject(std::shared_ptr<GetOfficeMathObjectRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/OfficeMathObjects/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getOfficeMathObject does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getOfficeMathObject does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getOfficeMathObject: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getOfficeMathObject: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<OfficeMathObjectResponse> result(new OfficeMathObjectResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getOfficeMathObject: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<OfficeMathObjectsResponse>> WordsApi::getOfficeMathObjects(std::shared_ptr<GetOfficeMathObjectsRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/OfficeMathObjects");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getOfficeMathObjects does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getOfficeMathObjects does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getOfficeMathObjects: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getOfficeMathObjects: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<OfficeMathObjectsResponse> result(new OfficeMathObjectsResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getOfficeMathObjects: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<SectionResponse>> WordsApi::getSection(std::shared_ptr<GetSectionRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/sections/{sectionIndex}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("SectionIndex") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->sectionIndex));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getSection does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getSection does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getSection: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getSection: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<SectionResponse> result(new SectionResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getSection: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<SectionPageSetupResponse>> WordsApi::getSectionPageSetup(std::shared_ptr<GetSectionPageSetupRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/sections/{sectionIndex}/pageSetup");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("SectionIndex") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->sectionIndex));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getSectionPageSetup does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getSectionPageSetup does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getSectionPageSetup: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getSectionPageSetup: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<SectionPageSetupResponse> result(new SectionPageSetupResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getSectionPageSetup: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<SectionLinkCollectionResponse>> WordsApi::getSections(std::shared_ptr<GetSectionsRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/sections");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getSections does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getSections does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getSections: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getSections: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<SectionLinkCollectionResponse> result(new SectionLinkCollectionResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getSections: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<TableResponse>> WordsApi::getTable(std::shared_ptr<GetTableRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/tables/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getTable does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getTable does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getTable: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getTable: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<TableResponse> result(new TableResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getTable: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<TableCellResponse>> WordsApi::getTableCell(std::shared_ptr<GetTableCellRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{tableRowPath}/cells/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("TableRowPath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->tableRowPath));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getTableCell does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getTableCell does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getTableCell: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getTableCell: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<TableCellResponse> result(new TableCellResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getTableCell: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<TableCellFormatResponse>> WordsApi::getTableCellFormat(std::shared_ptr<GetTableCellFormatRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{tableRowPath}/cells/{index}/cellformat");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("TableRowPath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->tableRowPath));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getTableCellFormat does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getTableCellFormat does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getTableCellFormat: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getTableCellFormat: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<TableCellFormatResponse> result(new TableCellFormatResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getTableCellFormat: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<TablePropertiesResponse>> WordsApi::getTableProperties(std::shared_ptr<GetTablePropertiesRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/tables/{index}/properties");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getTableProperties does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getTableProperties does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getTableProperties: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getTableProperties: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<TablePropertiesResponse> result(new TablePropertiesResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getTableProperties: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<TableRowResponse>> WordsApi::getTableRow(std::shared_ptr<GetTableRowRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{tablePath}/rows/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("TablePath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->tablePath));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getTableRow does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getTableRow does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getTableRow: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getTableRow: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<TableRowResponse> result(new TableRowResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getTableRow: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<TableRowFormatResponse>> WordsApi::getTableRowFormat(std::shared_ptr<GetTableRowFormatRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{tablePath}/rows/{index}/rowformat");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("TablePath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->tablePath));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getTableRowFormat does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getTableRowFormat does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getTableRowFormat: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getTableRowFormat: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<TableRowFormatResponse> result(new TableRowFormatResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getTableRowFormat: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<TableLinkCollectionResponse>> WordsApi::getTables(std::shared_ptr<GetTablesRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/tables");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->getTables does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->getTables does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getTables: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getTables: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<TableLinkCollectionResponse> result(new TableLinkCollectionResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getTables: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<TableResponse>> WordsApi::insertTable(std::shared_ptr<InsertTableRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/tables");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->insertTable does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        if (request->table)
            json = ModelBase::toJson(*(request->table));

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->table && (*(request->table)).get())
        {
            (*(request->table))->toMultipart(multipart, utility::conversions::to_string_t("table"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->insertTable does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling insertTable: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling insertTable: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<TableResponse> result(new TableResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling insertTable: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<TableCellResponse>> WordsApi::insertTableCell(std::shared_ptr<InsertTableCellRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{tableRowPath}/cells");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("TableRowPath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->tableRowPath));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->insertTableCell does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        if (request->cell)
            json = ModelBase::toJson(*(request->cell));

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->cell && (*(request->cell)).get())
        {
            (*(request->cell))->toMultipart(multipart, utility::conversions::to_string_t("cell"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->insertTableCell does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling insertTableCell: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling insertTableCell: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<TableCellResponse> result(new TableCellResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling insertTableCell: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<TableRowResponse>> WordsApi::insertTableRow(std::shared_ptr<InsertTableRowRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{tablePath}/rows");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("TablePath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->tablePath));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->insertTableRow does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        if (request->row)
            json = ModelBase::toJson(*(request->row));

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->row && (*(request->row)).get())
        {
            (*(request->row))->toMultipart(multipart, utility::conversions::to_string_t("row"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->insertTableRow does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling insertTableRow: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling insertTableRow: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<TableRowResponse> result(new TableRowResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling insertTableRow: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<DocumentResponse>> WordsApi::postAppendDocument(std::shared_ptr<PostAppendDocumentRequest> request)
{

    // verify the required parameter 'documentList' is set
    if (request->documentList == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'documentList' when calling WordsApi->postAppendDocument"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/appendDocument");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->postAppendDocument does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->documentList);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->documentList.get())
        {
            (request->documentList)->toMultipart(multipart, utility::conversions::to_string_t("documentList"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->postAppendDocument does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling postAppendDocument: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling postAppendDocument: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<DocumentResponse> result(new DocumentResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling postAppendDocument: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<ProtectionDataResponse>> WordsApi::postChangeDocumentProtection(std::shared_ptr<PostChangeDocumentProtectionRequest> request)
{

    // verify the required parameter 'protectionRequest' is set
    if (request->protectionRequest == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'protectionRequest' when calling WordsApi->postChangeDocumentProtection"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/protection");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->postChangeDocumentProtection does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->protectionRequest);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->protectionRequest.get())
        {
            (request->protectionRequest)->toMultipart(multipart, utility::conversions::to_string_t("protectionRequest"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->postChangeDocumentProtection does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling postChangeDocumentProtection: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling postChangeDocumentProtection: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<ProtectionDataResponse> result(new ProtectionDataResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling postChangeDocumentProtection: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<CommentResponse>> WordsApi::postComment(std::shared_ptr<PostCommentRequest> request)
{

    // verify the required parameter 'comment' is set
    if (request->comment == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'comment' when calling WordsApi->postComment"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/comments/{commentIndex}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("CommentIndex") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->commentIndex));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->postComment does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->comment);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->comment.get())
        {
            (request->comment)->toMultipart(multipart, utility::conversions::to_string_t("comment"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->postComment does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling postComment: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling postComment: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<CommentResponse> result(new CommentResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling postComment: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<DocumentResponse>> WordsApi::postCompareDocument(std::shared_ptr<PostCompareDocumentRequest> request)
{

    // verify the required parameter 'compareData' is set
    if (request->compareData == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'compareData' when calling WordsApi->postCompareDocument"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/compareDocument");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->postCompareDocument does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->compareData);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->compareData.get())
        {
            (request->compareData)->toMultipart(multipart, utility::conversions::to_string_t("compareData"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->postCompareDocument does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling postCompareDocument: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling postCompareDocument: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<DocumentResponse> result(new DocumentResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling postCompareDocument: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<DocumentResponse>> WordsApi::postDocumentExecuteMailMerge(std::shared_ptr<PostDocumentExecuteMailMergeRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/executeMailMerge");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->postDocumentExecuteMailMerge does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("multipart/form-data") );

    if (request->data)
    {
        formParams[ utility::conversions::to_string_t("Data") ] = ApiClient::parameterToString(*(request->data));
    }
    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->withRegions)
    {
        queryParams[utility::conversions::to_string_t("WithRegions")] = ApiClient::parameterToString(*(request->withRegions));
    }
    if (request->mailMergeDataFile)
    {
        queryParams[utility::conversions::to_string_t("MailMergeDataFile")] = ApiClient::parameterToString(*(request->mailMergeDataFile));
    }
    if (request->cleanup)
    {
        queryParams[utility::conversions::to_string_t("Cleanup")] = ApiClient::parameterToString(*(request->cleanup));
    }
    if (request->useWholeParagraphAsRegion)
    {
        queryParams[utility::conversions::to_string_t("UseWholeParagraphAsRegion")] = ApiClient::parameterToString(*(request->useWholeParagraphAsRegion));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->postDocumentExecuteMailMerge does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling postDocumentExecuteMailMerge: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling postDocumentExecuteMailMerge: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<DocumentResponse> result(new DocumentResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling postDocumentExecuteMailMerge: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<ParagraphFormatResponse>> WordsApi::postDocumentParagraphFormat(std::shared_ptr<PostDocumentParagraphFormatRequest> request)
{

    // verify the required parameter 'dto' is set
    if (request->dto == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'dto' when calling WordsApi->postDocumentParagraphFormat"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/paragraphs/{index}/format");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("NodePath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->nodePath));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->postDocumentParagraphFormat does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->dto);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->dto.get())
        {
            (request->dto)->toMultipart(multipart, utility::conversions::to_string_t("dto"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->postDocumentParagraphFormat does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling postDocumentParagraphFormat: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling postDocumentParagraphFormat: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<ParagraphFormatResponse> result(new ParagraphFormatResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling postDocumentParagraphFormat: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<FontResponse>> WordsApi::postDocumentParagraphRunFont(std::shared_ptr<PostDocumentParagraphRunFontRequest> request)
{

    // verify the required parameter 'fontDto' is set
    if (request->fontDto == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'fontDto' when calling WordsApi->postDocumentParagraphRunFont"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{paragraphPath}/runs/{index}/font");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("ParagraphPath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->paragraphPath));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->postDocumentParagraphRunFont does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->fontDto);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->fontDto.get())
        {
            (request->fontDto)->toMultipart(multipart, utility::conversions::to_string_t("fontDto"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->postDocumentParagraphRunFont does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling postDocumentParagraphRunFont: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling postDocumentParagraphRunFont: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<FontResponse> result(new FontResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling postDocumentParagraphRunFont: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<SaveResponse>> WordsApi::postDocumentSaveAs(std::shared_ptr<PostDocumentSaveAsRequest> request)
{

    // verify the required parameter 'saveOptionsData' is set
    if (request->saveOptionsData == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'saveOptionsData' when calling WordsApi->postDocumentSaveAs"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/saveAs");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->postDocumentSaveAs does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->fontsLocation)
    {
        queryParams[utility::conversions::to_string_t("FontsLocation")] = ApiClient::parameterToString(*(request->fontsLocation));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->saveOptionsData);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->saveOptionsData.get())
        {
            (request->saveOptionsData)->toMultipart(multipart, utility::conversions::to_string_t("saveOptionsData"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->postDocumentSaveAs does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling postDocumentSaveAs: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling postDocumentSaveAs: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<SaveResponse> result(new SaveResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling postDocumentSaveAs: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<DrawingObjectResponse>> WordsApi::postDrawingObject(std::shared_ptr<PostDrawingObjectRequest> request)
{

    // verify the required parameter 'imageFile' is set
    if (request->imageFile == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'imageFile' when calling WordsApi->postDrawingObject"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/drawingObjects/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->postDrawingObject does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("multipart/form-data") );

    {
        formParams[ utility::conversions::to_string_t("DrawingObject") ] = ApiClient::parameterToString((request->drawingObject));
    }
    if (request->imageFile != nullptr)
    {
        fileParams[ utility::conversions::to_string_t("ImageFile") ] = (request->imageFile);
    }
    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->postDrawingObject does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling postDrawingObject: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling postDrawingObject: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<DrawingObjectResponse> result(new DrawingObjectResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling postDrawingObject: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<DocumentResponse>> WordsApi::postExecuteTemplate(std::shared_ptr<PostExecuteTemplateRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/executeTemplate");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->postExecuteTemplate does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("multipart/form-data") );

    {
        formParams[ utility::conversions::to_string_t("Data") ] = ApiClient::parameterToString((request->data));
    }
    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->cleanup)
    {
        queryParams[utility::conversions::to_string_t("Cleanup")] = ApiClient::parameterToString(*(request->cleanup));
    }
    if (request->useWholeParagraphAsRegion)
    {
        queryParams[utility::conversions::to_string_t("UseWholeParagraphAsRegion")] = ApiClient::parameterToString(*(request->useWholeParagraphAsRegion));
    }
    if (request->withRegions)
    {
        queryParams[utility::conversions::to_string_t("WithRegions")] = ApiClient::parameterToString(*(request->withRegions));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->postExecuteTemplate does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling postExecuteTemplate: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling postExecuteTemplate: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<DocumentResponse> result(new DocumentResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling postExecuteTemplate: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<FieldResponse>> WordsApi::postField(std::shared_ptr<PostFieldRequest> request)
{

    // verify the required parameter 'field' is set
    if (request->field == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'field' when calling WordsApi->postField"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/fields/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->postField does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->field);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->field.get())
        {
            (request->field)->toMultipart(multipart, utility::conversions::to_string_t("field"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->postField does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling postField: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling postField: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<FieldResponse> result(new FieldResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling postField: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<FootnoteResponse>> WordsApi::postFootnote(std::shared_ptr<PostFootnoteRequest> request)
{

    // verify the required parameter 'footnoteDto' is set
    if (request->footnoteDto == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'footnoteDto' when calling WordsApi->postFootnote"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/footnotes/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->postFootnote does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->footnoteDto);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->footnoteDto.get())
        {
            (request->footnoteDto)->toMultipart(multipart, utility::conversions::to_string_t("footnoteDto"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->postFootnote does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling postFootnote: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling postFootnote: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<FootnoteResponse> result(new FootnoteResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling postFootnote: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<FormFieldResponse>> WordsApi::postFormField(std::shared_ptr<PostFormFieldRequest> request)
{

    // verify the required parameter 'formField' is set
    if (request->formField == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'formField' when calling WordsApi->postFormField"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/formfields/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->postFormField does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->formField);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->formField.get())
        {
            (request->formField)->toMultipart(multipart, utility::conversions::to_string_t("formField"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->postFormField does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling postFormField: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling postFormField: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<FormFieldResponse> result(new FormFieldResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling postFormField: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<DocumentResponse>> WordsApi::postInsertDocumentWatermarkImage(std::shared_ptr<PostInsertDocumentWatermarkImageRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/watermark/insertImage");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->postInsertDocumentWatermarkImage does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("multipart/form-data") );

    if (request->imageFile && *(request->imageFile) != nullptr)
    {
        fileParams[ utility::conversions::to_string_t("ImageFile") ] = *(request->imageFile);
    }
    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }
    if (request->rotationAngle)
    {
        queryParams[utility::conversions::to_string_t("RotationAngle")] = ApiClient::parameterToString(*(request->rotationAngle));
    }
    if (request->image)
    {
        queryParams[utility::conversions::to_string_t("Image")] = ApiClient::parameterToString(*(request->image));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->postInsertDocumentWatermarkImage does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling postInsertDocumentWatermarkImage: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling postInsertDocumentWatermarkImage: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<DocumentResponse> result(new DocumentResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling postInsertDocumentWatermarkImage: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<DocumentResponse>> WordsApi::postInsertDocumentWatermarkText(std::shared_ptr<PostInsertDocumentWatermarkTextRequest> request)
{

    // verify the required parameter 'watermarkText' is set
    if (request->watermarkText == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'watermarkText' when calling WordsApi->postInsertDocumentWatermarkText"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/watermark/insertText");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->postInsertDocumentWatermarkText does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->watermarkText);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->watermarkText.get())
        {
            (request->watermarkText)->toMultipart(multipart, utility::conversions::to_string_t("watermarkText"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->postInsertDocumentWatermarkText does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling postInsertDocumentWatermarkText: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling postInsertDocumentWatermarkText: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<DocumentResponse> result(new DocumentResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling postInsertDocumentWatermarkText: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<DocumentResponse>> WordsApi::postInsertPageNumbers(std::shared_ptr<PostInsertPageNumbersRequest> request)
{

    // verify the required parameter 'pageNumber' is set
    if (request->pageNumber == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'pageNumber' when calling WordsApi->postInsertPageNumbers"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/insertPageNumbers");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->postInsertPageNumbers does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->pageNumber);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->pageNumber.get())
        {
            (request->pageNumber)->toMultipart(multipart, utility::conversions::to_string_t("pageNumber"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->postInsertPageNumbers does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling postInsertPageNumbers: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling postInsertPageNumbers: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<DocumentResponse> result(new DocumentResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling postInsertPageNumbers: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<SaveResponse>> WordsApi::postLoadWebDocument(std::shared_ptr<PostLoadWebDocumentRequest> request)
{

    // verify the required parameter 'data' is set
    if (request->data == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'data' when calling WordsApi->postLoadWebDocument"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/loadWebDocument");
    
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->postLoadWebDocument does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->data);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->data.get())
        {
            (request->data)->toMultipart(multipart, utility::conversions::to_string_t("data"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->postLoadWebDocument does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling postLoadWebDocument: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling postLoadWebDocument: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<SaveResponse> result(new SaveResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling postLoadWebDocument: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<ReplaceTextResponse>> WordsApi::postReplaceText(std::shared_ptr<PostReplaceTextRequest> request)
{

    // verify the required parameter 'replaceText' is set
    if (request->replaceText == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'replaceText' when calling WordsApi->postReplaceText"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/replaceText");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->postReplaceText does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->replaceText);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->replaceText.get())
        {
            (request->replaceText)->toMultipart(multipart, utility::conversions::to_string_t("replaceText"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->postReplaceText does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling postReplaceText: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling postReplaceText: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<ReplaceTextResponse> result(new ReplaceTextResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling postReplaceText: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<RunResponse>> WordsApi::postRun(std::shared_ptr<PostRunRequest> request)
{

    // verify the required parameter 'run' is set
    if (request->run == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'run' when calling WordsApi->postRun"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{paragraphPath}/runs/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("ParagraphPath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->paragraphPath));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->postRun does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->run);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->run.get())
        {
            (request->run)->toMultipart(multipart, utility::conversions::to_string_t("run"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->postRun does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling postRun: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling postRun: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<RunResponse> result(new RunResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling postRun: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<SplitDocumentResponse>> WordsApi::postSplitDocument(std::shared_ptr<PostSplitDocumentRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/split");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->postSplitDocument does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->format)
    {
        queryParams[utility::conversions::to_string_t("Format")] = ApiClient::parameterToString(*(request->format));
    }
    if (request->from)
    {
        queryParams[utility::conversions::to_string_t("From")] = ApiClient::parameterToString(*(request->from));
    }
    if (request->to)
    {
        queryParams[utility::conversions::to_string_t("To")] = ApiClient::parameterToString(*(request->to));
    }
    if (request->zipOutput)
    {
        queryParams[utility::conversions::to_string_t("ZipOutput")] = ApiClient::parameterToString(*(request->zipOutput));
    }
    if (request->fontsLocation)
    {
        queryParams[utility::conversions::to_string_t("FontsLocation")] = ApiClient::parameterToString(*(request->fontsLocation));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->postSplitDocument does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling postSplitDocument: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling postSplitDocument: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<SplitDocumentResponse> result(new SplitDocumentResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling postSplitDocument: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<BookmarkResponse>> WordsApi::postUpdateDocumentBookmark(std::shared_ptr<PostUpdateDocumentBookmarkRequest> request)
{

    // verify the required parameter 'bookmarkData' is set
    if (request->bookmarkData == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'bookmarkData' when calling WordsApi->postUpdateDocumentBookmark"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/bookmarks/{bookmarkName}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("BookmarkName") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->bookmarkName));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->postUpdateDocumentBookmark does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->bookmarkData);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->bookmarkData.get())
        {
            (request->bookmarkData)->toMultipart(multipart, utility::conversions::to_string_t("bookmarkData"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->postUpdateDocumentBookmark does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling postUpdateDocumentBookmark: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling postUpdateDocumentBookmark: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<BookmarkResponse> result(new BookmarkResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling postUpdateDocumentBookmark: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<DocumentResponse>> WordsApi::postUpdateDocumentFields(std::shared_ptr<PostUpdateDocumentFieldsRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/updateFields");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->postUpdateDocumentFields does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->postUpdateDocumentFields does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling postUpdateDocumentFields: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling postUpdateDocumentFields: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<DocumentResponse> result(new DocumentResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling postUpdateDocumentFields: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<CommentResponse>> WordsApi::putComment(std::shared_ptr<PutCommentRequest> request)
{

    // verify the required parameter 'comment' is set
    if (request->comment == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'comment' when calling WordsApi->putComment"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/comments");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->putComment does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->comment);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->comment.get())
        {
            (request->comment)->toMultipart(multipart, utility::conversions::to_string_t("comment"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->putComment does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling putComment: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling putComment: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<CommentResponse> result(new CommentResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling putComment: unsupported response type"));
        }

        return result;
    });
}
pplx::task<HttpContent> WordsApi::putConvertDocument(std::shared_ptr<PutConvertDocumentRequest> request)
{

    // verify the required parameter 'document' is set
    if (request->document == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'document' when calling WordsApi->putConvertDocument"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/convert");
    
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("multipart/form-data") );

    if (request->document != nullptr)
    {
        fileParams[ utility::conversions::to_string_t("Document") ] = (request->document);
    }
    {
        queryParams[utility::conversions::to_string_t("Format")] = ApiClient::parameterToString((request->format));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->outPath)
    {
        queryParams[utility::conversions::to_string_t("OutPath")] = ApiClient::parameterToString(*(request->outPath));
    }
    if (request->documentFileName)
    {
        queryParams[utility::conversions::to_string_t("DocumentFileName")] = ApiClient::parameterToString(*(request->documentFileName));
    }
    if (request->fontsLocation)
    {
        queryParams[utility::conversions::to_string_t("FontsLocation")] = ApiClient::parameterToString(*(request->fontsLocation));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->putConvertDocument does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling putConvertDocument: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling putConvertDocument: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<std::shared_ptr<DocumentResponse>> WordsApi::putCreateDocument(std::shared_ptr<PutCreateDocumentRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/create");
    
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->putCreateDocument does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->fileName)
    {
        queryParams[utility::conversions::to_string_t("FileName")] = ApiClient::parameterToString(*(request->fileName));
    }
    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->putCreateDocument does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling putCreateDocument: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling putCreateDocument: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<DocumentResponse> result(new DocumentResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling putCreateDocument: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<FieldNamesResponse>> WordsApi::putDocumentFieldNames(std::shared_ptr<PutDocumentFieldNamesRequest> request)
{

    // verify the required parameter '_template' is set
    if (request->_template == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter '_template' when calling WordsApi->putDocumentFieldNames"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/mailMergeFieldNames");
    
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->putDocumentFieldNames does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("multipart/form-data") );

    if (request->_template != nullptr)
    {
        fileParams[ utility::conversions::to_string_t("Template") ] = (request->_template);
    }
    if (request->useNonMergeFields)
    {
        queryParams[utility::conversions::to_string_t("UseNonMergeFields")] = ApiClient::parameterToString(*(request->useNonMergeFields));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->putDocumentFieldNames does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling putDocumentFieldNames: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling putDocumentFieldNames: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<FieldNamesResponse> result(new FieldNamesResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling putDocumentFieldNames: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<SaveResponse>> WordsApi::putDocumentSaveAsTiff(std::shared_ptr<PutDocumentSaveAsTiffRequest> request)
{

    // verify the required parameter 'saveOptions' is set
    if (request->saveOptions == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'saveOptions' when calling WordsApi->putDocumentSaveAsTiff"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/saveAs/tiff");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->putDocumentSaveAsTiff does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->resultFile)
    {
        queryParams[utility::conversions::to_string_t("ResultFile")] = ApiClient::parameterToString(*(request->resultFile));
    }
    if (request->useAntiAliasing)
    {
        queryParams[utility::conversions::to_string_t("UseAntiAliasing")] = ApiClient::parameterToString(*(request->useAntiAliasing));
    }
    if (request->useHighQualityRendering)
    {
        queryParams[utility::conversions::to_string_t("UseHighQualityRendering")] = ApiClient::parameterToString(*(request->useHighQualityRendering));
    }
    if (request->imageBrightness)
    {
        queryParams[utility::conversions::to_string_t("ImageBrightness")] = ApiClient::parameterToString(*(request->imageBrightness));
    }
    if (request->imageColorMode)
    {
        queryParams[utility::conversions::to_string_t("ImageColorMode")] = ApiClient::parameterToString(*(request->imageColorMode));
    }
    if (request->imageContrast)
    {
        queryParams[utility::conversions::to_string_t("ImageContrast")] = ApiClient::parameterToString(*(request->imageContrast));
    }
    if (request->numeralFormat)
    {
        queryParams[utility::conversions::to_string_t("NumeralFormat")] = ApiClient::parameterToString(*(request->numeralFormat));
    }
    if (request->pageCount)
    {
        queryParams[utility::conversions::to_string_t("PageCount")] = ApiClient::parameterToString(*(request->pageCount));
    }
    if (request->pageIndex)
    {
        queryParams[utility::conversions::to_string_t("PageIndex")] = ApiClient::parameterToString(*(request->pageIndex));
    }
    if (request->paperColor)
    {
        queryParams[utility::conversions::to_string_t("PaperColor")] = ApiClient::parameterToString(*(request->paperColor));
    }
    if (request->pixelFormat)
    {
        queryParams[utility::conversions::to_string_t("PixelFormat")] = ApiClient::parameterToString(*(request->pixelFormat));
    }
    if (request->resolution)
    {
        queryParams[utility::conversions::to_string_t("Resolution")] = ApiClient::parameterToString(*(request->resolution));
    }
    if (request->scale)
    {
        queryParams[utility::conversions::to_string_t("Scale")] = ApiClient::parameterToString(*(request->scale));
    }
    if (request->tiffCompression)
    {
        queryParams[utility::conversions::to_string_t("TiffCompression")] = ApiClient::parameterToString(*(request->tiffCompression));
    }
    if (request->dmlRenderingMode)
    {
        queryParams[utility::conversions::to_string_t("DmlRenderingMode")] = ApiClient::parameterToString(*(request->dmlRenderingMode));
    }
    if (request->dmlEffectsRenderingMode)
    {
        queryParams[utility::conversions::to_string_t("DmlEffectsRenderingMode")] = ApiClient::parameterToString(*(request->dmlEffectsRenderingMode));
    }
    if (request->tiffBinarizationMethod)
    {
        queryParams[utility::conversions::to_string_t("TiffBinarizationMethod")] = ApiClient::parameterToString(*(request->tiffBinarizationMethod));
    }
    if (request->zipOutput)
    {
        queryParams[utility::conversions::to_string_t("ZipOutput")] = ApiClient::parameterToString(*(request->zipOutput));
    }
    if (request->fontsLocation)
    {
        queryParams[utility::conversions::to_string_t("FontsLocation")] = ApiClient::parameterToString(*(request->fontsLocation));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->saveOptions);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->saveOptions.get())
        {
            (request->saveOptions)->toMultipart(multipart, utility::conversions::to_string_t("saveOptions"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->putDocumentSaveAsTiff does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling putDocumentSaveAsTiff: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling putDocumentSaveAsTiff: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<SaveResponse> result(new SaveResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling putDocumentSaveAsTiff: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<DrawingObjectResponse>> WordsApi::putDrawingObject(std::shared_ptr<PutDrawingObjectRequest> request)
{

    // verify the required parameter 'imageFile' is set
    if (request->imageFile == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'imageFile' when calling WordsApi->putDrawingObject"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/drawingObjects");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->putDrawingObject does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("multipart/form-data") );

    {
        formParams[ utility::conversions::to_string_t("DrawingObject") ] = ApiClient::parameterToString((request->drawingObject));
    }
    if (request->imageFile != nullptr)
    {
        fileParams[ utility::conversions::to_string_t("ImageFile") ] = (request->imageFile);
    }
    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->putDrawingObject does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling putDrawingObject: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling putDrawingObject: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<DrawingObjectResponse> result(new DrawingObjectResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling putDrawingObject: unsupported response type"));
        }

        return result;
    });
}
pplx::task<HttpContent> WordsApi::putExecuteMailMergeOnline(std::shared_ptr<PutExecuteMailMergeOnlineRequest> request)
{

    // verify the required parameter '_template' is set
    if (request->_template == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter '_template' when calling WordsApi->putExecuteMailMergeOnline"));
    }

    // verify the required parameter 'data' is set
    if (request->data == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'data' when calling WordsApi->putExecuteMailMergeOnline"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/executeMailMerge");
    
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("multipart/form-data") );

    if (request->_template != nullptr)
    {
        fileParams[ utility::conversions::to_string_t("Template") ] = (request->_template);
    }
    if (request->data != nullptr)
    {
        fileParams[ utility::conversions::to_string_t("Data") ] = (request->data);
    }
    if (request->withRegions)
    {
        queryParams[utility::conversions::to_string_t("WithRegions")] = ApiClient::parameterToString(*(request->withRegions));
    }
    if (request->cleanup)
    {
        queryParams[utility::conversions::to_string_t("Cleanup")] = ApiClient::parameterToString(*(request->cleanup));
    }
    if (request->documentFileName)
    {
        queryParams[utility::conversions::to_string_t("DocumentFileName")] = ApiClient::parameterToString(*(request->documentFileName));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->putExecuteMailMergeOnline does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling putExecuteMailMergeOnline: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling putExecuteMailMergeOnline: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<HttpContent> WordsApi::putExecuteTemplateOnline(std::shared_ptr<PutExecuteTemplateOnlineRequest> request)
{

    // verify the required parameter '_template' is set
    if (request->_template == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter '_template' when calling WordsApi->putExecuteTemplateOnline"));
    }

    // verify the required parameter 'data' is set
    if (request->data == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'data' when calling WordsApi->putExecuteTemplateOnline"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/executeTemplate");
    
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("multipart/form-data") );

    if (request->_template != nullptr)
    {
        fileParams[ utility::conversions::to_string_t("Template") ] = (request->_template);
    }
    if (request->data != nullptr)
    {
        fileParams[ utility::conversions::to_string_t("Data") ] = (request->data);
    }
    if (request->cleanup)
    {
        queryParams[utility::conversions::to_string_t("Cleanup")] = ApiClient::parameterToString(*(request->cleanup));
    }
    if (request->useWholeParagraphAsRegion)
    {
        queryParams[utility::conversions::to_string_t("UseWholeParagraphAsRegion")] = ApiClient::parameterToString(*(request->useWholeParagraphAsRegion));
    }
    if (request->withRegions)
    {
        queryParams[utility::conversions::to_string_t("WithRegions")] = ApiClient::parameterToString(*(request->withRegions));
    }
    if (request->documentFileName)
    {
        queryParams[utility::conversions::to_string_t("DocumentFileName")] = ApiClient::parameterToString(*(request->documentFileName));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->putExecuteTemplateOnline does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling putExecuteTemplateOnline: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling putExecuteTemplateOnline: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<std::shared_ptr<FieldResponse>> WordsApi::putField(std::shared_ptr<PutFieldRequest> request)
{

    // verify the required parameter 'field' is set
    if (request->field == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'field' when calling WordsApi->putField"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/fields");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->putField does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }
    if (request->insertBeforeNode)
    {
        queryParams[utility::conversions::to_string_t("InsertBeforeNode")] = ApiClient::parameterToString(*(request->insertBeforeNode));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->field);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->field.get())
        {
            (request->field)->toMultipart(multipart, utility::conversions::to_string_t("field"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->putField does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling putField: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling putField: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<FieldResponse> result(new FieldResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling putField: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<FootnoteResponse>> WordsApi::putFootnote(std::shared_ptr<PutFootnoteRequest> request)
{

    // verify the required parameter 'footnoteDto' is set
    if (request->footnoteDto == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'footnoteDto' when calling WordsApi->putFootnote"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/footnotes");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->putFootnote does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->footnoteDto);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->footnoteDto.get())
        {
            (request->footnoteDto)->toMultipart(multipart, utility::conversions::to_string_t("footnoteDto"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->putFootnote does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling putFootnote: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling putFootnote: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<FootnoteResponse> result(new FootnoteResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling putFootnote: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<FormFieldResponse>> WordsApi::putFormField(std::shared_ptr<PutFormFieldRequest> request)
{

    // verify the required parameter 'formField' is set
    if (request->formField == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'formField' when calling WordsApi->putFormField"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/formfields");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->putFormField does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }
    if (request->insertBeforeNode)
    {
        queryParams[utility::conversions::to_string_t("InsertBeforeNode")] = ApiClient::parameterToString(*(request->insertBeforeNode));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->formField);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->formField.get())
        {
            (request->formField)->toMultipart(multipart, utility::conversions::to_string_t("formField"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->putFormField does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling putFormField: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling putFormField: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<FormFieldResponse> result(new FormFieldResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling putFormField: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<HeaderFooterResponse>> WordsApi::putHeaderFooter(std::shared_ptr<PutHeaderFooterRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{sectionPath}/headersfooters");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->putHeaderFooter does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }
    if (request->sectionPath)
    {
        queryParams[utility::conversions::to_string_t("SectionPath")] = ApiClient::parameterToString(*(request->sectionPath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->headerFooterType);

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);
        multipart->add(ModelBase::toHttpContent(L"headerFooterType", request->headerFooterType));

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->putHeaderFooter does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling putHeaderFooter: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling putHeaderFooter: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<HeaderFooterResponse> result(new HeaderFooterResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling putHeaderFooter: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<ParagraphResponse>> WordsApi::putParagraph(std::shared_ptr<PutParagraphRequest> request)
{

    // verify the required parameter 'paragraph' is set
    if (request->paragraph == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'paragraph' when calling WordsApi->putParagraph"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/paragraphs");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->putParagraph does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }
    if (request->insertBeforeNode)
    {
        queryParams[utility::conversions::to_string_t("InsertBeforeNode")] = ApiClient::parameterToString(*(request->insertBeforeNode));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->paragraph);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->paragraph.get())
        {
            (request->paragraph)->toMultipart(multipart, utility::conversions::to_string_t("paragraph"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->putParagraph does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling putParagraph: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling putParagraph: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<ParagraphResponse> result(new ParagraphResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling putParagraph: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<ProtectionDataResponse>> WordsApi::putProtectDocument(std::shared_ptr<PutProtectDocumentRequest> request)
{

    // verify the required parameter 'protectionRequest' is set
    if (request->protectionRequest == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'protectionRequest' when calling WordsApi->putProtectDocument"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/protection");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->putProtectDocument does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->protectionRequest);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->protectionRequest.get())
        {
            (request->protectionRequest)->toMultipart(multipart, utility::conversions::to_string_t("protectionRequest"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->putProtectDocument does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling putProtectDocument: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling putProtectDocument: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<ProtectionDataResponse> result(new ProtectionDataResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling putProtectDocument: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<RunResponse>> WordsApi::putRun(std::shared_ptr<PutRunRequest> request)
{

    // verify the required parameter 'run' is set
    if (request->run == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'run' when calling WordsApi->putRun"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{paragraphPath}/runs");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("ParagraphPath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->paragraphPath));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->putRun does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }
    if (request->insertBeforeNode)
    {
        queryParams[utility::conversions::to_string_t("InsertBeforeNode")] = ApiClient::parameterToString(*(request->insertBeforeNode));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->run);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->run.get())
        {
            (request->run)->toMultipart(multipart, utility::conversions::to_string_t("run"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->putRun does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling putRun: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling putRun: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<RunResponse> result(new RunResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling putRun: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<RevisionsModificationResponse>> WordsApi::rejectAllRevisions(std::shared_ptr<RejectAllRevisionsRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/revisions/rejectAll");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->rejectAllRevisions does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->rejectAllRevisions does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling rejectAllRevisions: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling rejectAllRevisions: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<RevisionsModificationResponse> result(new RevisionsModificationResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling rejectAllRevisions: unsupported response type"));
        }

        return result;
    });
}
pplx::task<HttpContent> WordsApi::renderDrawingObject(std::shared_ptr<RenderDrawingObjectRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/drawingObjects/{index}/render");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    {
        queryParams[utility::conversions::to_string_t("Format")] = ApiClient::parameterToString((request->format));
    }
    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }
    if (request->fontsLocation)
    {
        queryParams[utility::conversions::to_string_t("FontsLocation")] = ApiClient::parameterToString(*(request->fontsLocation));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->renderDrawingObject does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling renderDrawingObject: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling renderDrawingObject: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<HttpContent> WordsApi::renderMathObject(std::shared_ptr<RenderMathObjectRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/OfficeMathObjects/{index}/render");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    {
        queryParams[utility::conversions::to_string_t("Format")] = ApiClient::parameterToString((request->format));
    }
    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }
    if (request->fontsLocation)
    {
        queryParams[utility::conversions::to_string_t("FontsLocation")] = ApiClient::parameterToString(*(request->fontsLocation));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->renderMathObject does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling renderMathObject: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling renderMathObject: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<HttpContent> WordsApi::renderPage(std::shared_ptr<RenderPageRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/pages/{pageIndex}/render");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("PageIndex") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->pageIndex));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    {
        queryParams[utility::conversions::to_string_t("Format")] = ApiClient::parameterToString((request->format));
    }
    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->fontsLocation)
    {
        queryParams[utility::conversions::to_string_t("FontsLocation")] = ApiClient::parameterToString(*(request->fontsLocation));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->renderPage does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling renderPage: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling renderPage: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<HttpContent> WordsApi::renderParagraph(std::shared_ptr<RenderParagraphRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/paragraphs/{index}/render");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    {
        queryParams[utility::conversions::to_string_t("Format")] = ApiClient::parameterToString((request->format));
    }
    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }
    if (request->fontsLocation)
    {
        queryParams[utility::conversions::to_string_t("FontsLocation")] = ApiClient::parameterToString(*(request->fontsLocation));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->renderParagraph does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling renderParagraph: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling renderParagraph: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<HttpContent> WordsApi::renderTable(std::shared_ptr<RenderTableRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/tables/{index}/render");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    {
        queryParams[utility::conversions::to_string_t("Format")] = ApiClient::parameterToString((request->format));
    }
    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }
    if (request->fontsLocation)
    {
        queryParams[utility::conversions::to_string_t("FontsLocation")] = ApiClient::parameterToString(*(request->fontsLocation));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->renderTable does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling renderTable: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling renderTable: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::resetCache(std::shared_ptr<ResetCacheRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/fonts/cache");
    
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->resetCache does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );


    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->resetCache does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling resetCache: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling resetCache: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<AsposeResponse> result(new AsposeResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling resetCache: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<SearchResponse>> WordsApi::search(std::shared_ptr<SearchRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/search");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->search does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    {
        queryParams[utility::conversions::to_string_t("Pattern")] = ApiClient::parameterToString((request->pattern));
    }
    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->search does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling search: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling search: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<SearchResponse> result(new SearchResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling search: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<BorderResponse>> WordsApi::updateBorder(std::shared_ptr<UpdateBorderRequest> request)
{

    // verify the required parameter 'borderProperties' is set
    if (request->borderProperties == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'borderProperties' when calling WordsApi->updateBorder"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/borders/{index}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("NodePath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->nodePath));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->updateBorder does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->borderProperties);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->borderProperties.get())
        {
            (request->borderProperties)->toMultipart(multipart, utility::conversions::to_string_t("borderProperties"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->updateBorder does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling updateBorder: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling updateBorder: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<BorderResponse> result(new BorderResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling updateBorder: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<SectionPageSetupResponse>> WordsApi::updateSectionPageSetup(std::shared_ptr<UpdateSectionPageSetupRequest> request)
{

    // verify the required parameter 'pageSetup' is set
    if (request->pageSetup == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'pageSetup' when calling WordsApi->updateSectionPageSetup"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/sections/{sectionIndex}/pageSetup");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("SectionIndex") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->sectionIndex));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->updateSectionPageSetup does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->pageSetup);
        

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->pageSetup.get())
        {
            (request->pageSetup)->toMultipart(multipart, utility::conversions::to_string_t("pageSetup"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->updateSectionPageSetup does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling updateSectionPageSetup: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling updateSectionPageSetup: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<SectionPageSetupResponse> result(new SectionPageSetupResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling updateSectionPageSetup: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<TableCellFormatResponse>> WordsApi::updateTableCellFormat(std::shared_ptr<UpdateTableCellFormatRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{tableRowPath}/cells/{index}/cellformat");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("TableRowPath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->tableRowPath));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->updateTableCellFormat does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        if (request->format)
            json = ModelBase::toJson(*(request->format));

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->format && (*(request->format)).get())
        {
            (*(request->format))->toMultipart(multipart, utility::conversions::to_string_t("format"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->updateTableCellFormat does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling updateTableCellFormat: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling updateTableCellFormat: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<TableCellFormatResponse> result(new TableCellFormatResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling updateTableCellFormat: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<TablePropertiesResponse>> WordsApi::updateTableProperties(std::shared_ptr<UpdateTablePropertiesRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{nodePath}/tables/{index}/properties");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->updateTableProperties does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }
    if (request->nodePath)
    {
        queryParams[utility::conversions::to_string_t("NodePath")] = ApiClient::parameterToString(*(request->nodePath));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        if (request->properties)
            json = ModelBase::toJson(*(request->properties));

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->properties && (*(request->properties)).get())
        {
            (*(request->properties))->toMultipart(multipart, utility::conversions::to_string_t("properties"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->updateTableProperties does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling updateTableProperties: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling updateTableProperties: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<TablePropertiesResponse> result(new TablePropertiesResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling updateTableProperties: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<TableRowFormatResponse>> WordsApi::updateTableRowFormat(std::shared_ptr<UpdateTableRowFormatRequest> request)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/words/{name}/{tablePath}/rows/{index}/rowformat");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->name));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("TablePath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->tablePath));
boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("Index") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(request->index));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("WordsApi->updateTableRowFormat does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/xml") );
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (request->folder)
    {
        queryParams[utility::conversions::to_string_t("Folder")] = ApiClient::parameterToString(*(request->folder));
    }
    if (request->storage)
    {
        queryParams[utility::conversions::to_string_t("Storage")] = ApiClient::parameterToString(*(request->storage));
    }
    if (request->loadEncoding)
    {
        queryParams[utility::conversions::to_string_t("LoadEncoding")] = ApiClient::parameterToString(*(request->loadEncoding));
    }
    if (request->password)
    {
        queryParams[utility::conversions::to_string_t("Password")] = ApiClient::parameterToString(*(request->password));
    }
    if (request->destFileName)
    {
        queryParams[utility::conversions::to_string_t("DestFileName")] = ApiClient::parameterToString(*(request->destFileName));
    }
    if (request->revisionAuthor)
    {
        queryParams[utility::conversions::to_string_t("RevisionAuthor")] = ApiClient::parameterToString(*(request->revisionAuthor));
    }
    if (request->revisionDateTime)
    {
        queryParams[utility::conversions::to_string_t("RevisionDateTime")] = ApiClient::parameterToString(*(request->revisionDateTime));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value json;

        if (request->format)
            json = ModelBase::toJson(*(request->format));

        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if(request->format && (*(request->format)).get())
        {
            (*(request->format))->toMultipart(multipart, utility::conversions::to_string_t("format"));
        }

        httpBody = multipart;
        requestHttpContentType += utility::conversions::to_string_t("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("WordsApi->updateTableRowFormat does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling updateTableRowFormat: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling updateTableRowFormat: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<TableRowFormatResponse> result(new TableRowFormatResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling updateTableRowFormat: unsupported response type"));
        }

        return result;
    });
}

}
}
}
}


