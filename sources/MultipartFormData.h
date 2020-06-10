/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="MultipartFormData.h">
*   Copyright (c) 2020 Aspose.Words for Cloud
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_MultipartFormData_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_MultipartFormData_H_

#include "IHttpBody.h"
#include "HttpContent.h"

#include <vector>
#include <unordered_map>
#include <memory>

#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

class  MultipartFormData
    : public IHttpBody
{
public:
    MultipartFormData();
    explicit MultipartFormData(utility::string_t boundary);

    virtual void add(const std::shared_ptr<HttpContent>& content);
    virtual utility::string_t getBoundary() const;
    virtual std::shared_ptr<HttpContent> getContent(const utility::string_t& name) const;
    virtual bool hasContent(const utility::string_t& name) const;
    void writeTo( std::ostream& target ) const override;

protected:
    std::vector<std::shared_ptr<HttpContent>> m_Contents;
    utility::string_t m_Boundary;
    std::unordered_map<utility::string_t, std::shared_ptr<HttpContent>> m_ContentLookup;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_MultipartFormData_H_ */
