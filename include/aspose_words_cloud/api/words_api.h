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
#include "aspose_words_cloud/api_client.h"
#include "aspose_words_cloud/requests/accept_all_revisions_request.h"
#include "aspose_words_cloud/responses/accept_all_revisions_response.h"

namespace aspose::words::cloud::api {
    class WordsApi
    {
    public:
        /// <summary>
        /// Accepts all revisions in the document.
        /// </summary>
        /// <param name="name">The filename of the input document.</param>
        /// <param name="folder">Original document folder.</param>
        /// <param name="storage">Original document storage.</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML.</param>
        /// <param name="password">Password for opening an encrypted document.</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document.</param>
        std::shared_ptr<aspose::words::cloud::responses::AcceptAllRevisionsResponse> acceptAllRevisions(std::shared_ptr<aspose::words::cloud::requests::AcceptAllRevisionsRequest> request);

    public:
        WordsApi(std::shared_ptr<ApiConfiguration> configuration);
        virtual ~WordsApi() = default;

    protected:
        std::shared_ptr<ApiClient> m_ApiClient;
    };
}
