/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Object.cpp">
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
#include "Object.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

void Object::validate()
{
    // TODO: implement validation
}

web::json::value Object::toJson() const
{
    return m_object;
}

void Object::fromJson(web::json::value& val)
{
    if (val.is_object())
    {
        m_object = val;
    }
}

void Object::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("object"), m_object));
}

void Object::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    m_object = ModelBase::valueFromHttpContent(multipart->getContent(namePrefix + _XPLATSTR("object")));
}

web::json::value Object::getValue(const utility::string_t& key) const
{
    return m_object.at(key);
}


void Object::setValue(const utility::string_t& key, const web::json::value& value)
{
    m_object[key] = value;
}

}
}
}
}
