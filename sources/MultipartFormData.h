/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="MultipartFormData.h">
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

#include "IHttpBody.h"
#include "HttpContent.h"

#include <vector>
#include <unordered_map>
#include <memory>

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
    explicit MultipartFormData(std::wstring boundary);

    virtual void add(const std::shared_ptr<HttpContent>& content);
    virtual std::wstring getBoundary() const;
    virtual std::shared_ptr<HttpContent> getContent(const std::wstring& name) const;
    virtual bool hasContent(const std::wstring& name) const;
    void writeTo( std::ostream& target ) const override;

protected:
    std::vector<std::shared_ptr<HttpContent>> m_Contents;
    std::wstring m_Boundary;
    std::unordered_map<std::wstring, std::shared_ptr<HttpContent>> m_ContentLookup;
};

}
}
}
}
}
