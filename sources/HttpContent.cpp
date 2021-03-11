/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="HttpContent.cpp">
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

#include "HttpContent.h"

namespace aspose::words::cloud::api::models {
    std::wstring HttpContent::getContentDisposition() const
    {
        return m_ContentDisposition;
    }

    void HttpContent::setContentDisposition(std::wstring value )
    {
        m_ContentDisposition = std::move(value);
    }

    std::wstring HttpContent::getName() const
    {
        return m_Name;
    }

    void HttpContent::setName( std::wstring value )
    {
        m_Name = std::move(value);
    }

    std::wstring HttpContent::getFileName() const
    {
        return m_FileName;
    }

    void HttpContent::setFileName( std::wstring value )
    {
        m_FileName = std::move(value);
    }

    std::wstring HttpContent::getContentType() const
    {
        return m_ContentType;
    }

    void HttpContent::setContentType( std::wstring value )
    {
        m_ContentType = std::move(value);
    }

    std::shared_ptr<std::istream> HttpContent::getData() const
    {
        return m_Data;
    }

    void HttpContent::setData(const std::shared_ptr<std::istream>& value )
    {
        m_Data = value;
    }

    void HttpContent::writeTo( std::ostream& stream )
    {
        m_Data->seekg( 0, m_Data->beg );
        stream << m_Data->rdbuf();
    }
}