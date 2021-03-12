/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="words_api.h">
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

#pragma once
#include "../api_client.h"
#include "../model/words_api_error_response.h"

#include "requests/accept_all_revisions_request.h"

#include "api_error.h"
#include "http_content.h"

namespace aspose::words::cloud::api {
    template<class T>
    struct AsposeResponse
    {
	    std::shared_ptr<web::http::http_response> httpResponse;
        std::shared_ptr<T> body;
    };

    class WordsApi
    {
    public:
        /// <summary>
        /// Accepts all revisions in the document.
        /// </summary>
        /// <param name="name">The filename of the input document.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
        pplx::task<HttpContent> acceptAllRevisions(
        	std::shared_ptr<AcceptAllRevisionsRequest> request
        );


    public:
        explicit WordsApi(std::shared_ptr<ApiConfiguration> configuration);
        virtual ~WordsApi() = default;

    protected:
        std::shared_ptr<ApiClient> m_ApiClient;
    };
}
