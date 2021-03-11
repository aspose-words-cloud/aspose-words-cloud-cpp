/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="HttpContent.h">
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

#include <memory>
#include <string>
#include <optional>

namespace aspose::words::cloud::api::models {
    class  HttpContent
    {
    public:
        virtual ~HttpContent() = default;

        virtual std::wstring getContentDisposition() const;
        virtual void setContentDisposition( std::wstring value );

        virtual std::wstring getName() const;
        virtual void setName( std::wstring value );

        virtual std::wstring getFileName() const;
        virtual void setFileName( std::wstring value );

        virtual std::wstring getContentType() const;
        virtual void setContentType( std::wstring value );

        virtual std::shared_ptr<std::istream> getData() const;
        virtual void setData( const std::shared_ptr<std::istream>& value );

        virtual void writeTo( std::ostream& stream );

    protected:
        std::wstring m_ContentDisposition;
        std::wstring m_Name;
        std::wstring m_FileName;
        std::wstring m_ContentType;
        std::shared_ptr<std::istream> m_Data;
    };
}