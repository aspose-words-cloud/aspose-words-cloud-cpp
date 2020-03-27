/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="RunUpdate.cpp">
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


#include "RunUpdate.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

RunUpdate::RunUpdate()
{
}

RunUpdate::~RunUpdate()
{
}

void RunUpdate::validate()
{
    // TODO: implement validation
}

web::json::value RunUpdate::toJson() const
{
    web::json::value val = this->RunBase::toJson();


    return val;
}

void RunUpdate::fromJson(web::json::value& val)
{
    this->RunBase::fromJson(val);

}

void RunUpdate::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    RunBase::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

}

void RunUpdate::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    RunBase::fromMultiPart(multipart, prefix);

}

}
}
}
}
}

