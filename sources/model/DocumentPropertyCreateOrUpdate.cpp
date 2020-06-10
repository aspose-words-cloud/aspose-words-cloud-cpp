/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DocumentPropertyCreateOrUpdate.cpp">
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

#include "DocumentPropertyCreateOrUpdate.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

DocumentPropertyCreateOrUpdate::DocumentPropertyCreateOrUpdate()
{
}

DocumentPropertyCreateOrUpdate::~DocumentPropertyCreateOrUpdate()
{
}

void DocumentPropertyCreateOrUpdate::validate()
{
    // TODO: implement validation
}

web::json::value DocumentPropertyCreateOrUpdate::toJson() const
{
    web::json::value val = this->DocumentPropertyBase::toJson();

    return val;
}

void DocumentPropertyCreateOrUpdate::fromJson(web::json::value& val)
{
    this->DocumentPropertyBase::fromJson(val);

}

void DocumentPropertyCreateOrUpdate::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    DocumentPropertyBase::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
}

void DocumentPropertyCreateOrUpdate::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}



}
}
}
}
}
