/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="MultipartFormData.cpp">
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
#include "MultipartFormData.h"
#include "ModelBase.h"

#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

MultipartFormData::MultipartFormData() :
    m_Boundary(utility::conversions::details::to_string_t(boost::uuids::random_generator()()))
{
}

MultipartFormData::MultipartFormData(utility::string_t boundary)
    : m_Boundary(std::move(boundary))
{
}


utility::string_t MultipartFormData::getBoundary() const
{
    return m_Boundary;
}

void MultipartFormData::add(const std::shared_ptr<HttpContent>& content )
{
    m_Contents.push_back( content );
    m_ContentLookup[content->getName()] = content;
}

bool MultipartFormData::hasContent(const utility::string_t& name) const
{
    return m_ContentLookup.find(name) != m_ContentLookup.end();
}

std::shared_ptr<HttpContent> MultipartFormData::getContent(const utility::string_t& name) const
{
    const auto result = m_ContentLookup.find(name);
    if(result != m_ContentLookup.end())
    {
        return result->second;
    }
    return nullptr;
}

void MultipartFormData::writeTo( std::ostream& target ) const
{
    for (const auto & content : m_Contents)
    {
        if (m_Contents.size() > 1)
        {
            // boundary
            target << "\r\n" << "--" << utility::conversions::to_utf8string(m_Boundary) << "\r\n";

            // headers
            target << "Content-Disposition: " << utility::conversions::to_utf8string(content->getContentDisposition());
            if (!content->getName().empty())
            {
                target << "; name=\"" << utility::conversions::to_utf8string(content->getName()) << "\"";
            }
            if (!content->getFileName().empty())
            {
                target << "; filename=\"" << utility::conversions::to_utf8string(content->getFileName()) << "\"";
            }
            target << "\r\n";

            if (!content->getContentType().empty())
            {
                target << "Content-Type: " << utility::conversions::to_utf8string(content->getContentType()) << "\r\n";
            }

            target << "\r\n";
        }

        // body
        target << content->getData()->rdbuf();
    }

    if (m_Contents.size() > 1)
    {
        target << "\r\n--" << utility::conversions::to_utf8string( m_Boundary ) << "--\r\n";
    }
}

}
}
}
}
