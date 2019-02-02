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

MultipartFormData::MultipartFormData()
{
    utility::stringstream_t uuidString;
    uuidString << boost::uuids::random_generator()();
    m_Boundary = uuidString.str();
}

MultipartFormData::MultipartFormData(const utility::string_t& boundary)
    : m_Boundary(boundary)
{

}

MultipartFormData::~MultipartFormData()
{
}

utility::string_t MultipartFormData::getBoundary()
{
    return m_Boundary;
}

void MultipartFormData::add( std::shared_ptr<HttpContent> content )
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
    auto result = m_ContentLookup.find(name);
    if(result == m_ContentLookup.end())
    {
        return std::shared_ptr<HttpContent>(nullptr);
    }
    return result->second;
}

void MultipartFormData::writeTo( std::ostream& target )
{
    size_t contentSize = m_Contents.size();

    for ( size_t i = 0; i < contentSize; i++ )
    {
        std::shared_ptr<HttpContent> content = m_Contents[i];
        if (contentSize > 1) {
        // boundary
        target << "\r\n" << "--" << utility::conversions::to_utf8string( m_Boundary ) << "\r\n";

        // headers
        target << "Content-Disposition: " << utility::conversions::to_utf8string( content->getContentDisposition() );
        if ( content->getName().size() > 0 )
        {
            target << "; name=\"" << utility::conversions::to_utf8string( content->getName() ) << "\"";
        }
        if ( content->getFileName().size() > 0 )
        {
            target << "; filename=\"" << utility::conversions::to_utf8string( content->getFileName() ) << "\"";
        }
        target << "\r\n";

        if ( content->getContentType().size() > 0 )
        {
            target << "Content-Type: " << utility::conversions::to_utf8string( content->getContentType() ) << "\r\n";
        }

        target << "\r\n";
        }

        // body
        std::shared_ptr<std::istream> data = content->getData();
		data->seekg( 0, data->end );
		std::vector<char> dataBytes( data->tellg() );
		data->seekg( 0, data->beg );
		data->read( &dataBytes[0], dataBytes.size() );

		std::copy( dataBytes.begin(), dataBytes.end(), std::ostreambuf_iterator<char>( target ) );
    }
    if (contentSize > 1)
    target << "\r\n--" << utility::conversions::to_utf8string( m_Boundary ) << "--\r\n";
}

}
}
}
}
