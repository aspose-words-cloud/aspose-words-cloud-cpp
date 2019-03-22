/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="HttpContent.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_HttpContent_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_HttpContent_H_



#include <memory>

#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

class  HttpContent
{
public:
    virtual ~HttpContent() = default;

    virtual utility::string_t getContentDisposition() const;
    virtual void setContentDisposition( utility::string_t value );

    virtual utility::string_t getName() const;
    virtual void setName( utility::string_t value );

    virtual utility::string_t getFileName() const;
    virtual void setFileName( utility::string_t value );

    virtual utility::string_t getContentType() const;
    virtual void setContentType( utility::string_t value );

    virtual std::shared_ptr<std::istream> getData() const;
    virtual void setData( const std::shared_ptr<std::istream>& value );

    virtual void writeTo( std::ostream& stream );

protected:
    // NOTE: no utility::string_t here because those strings can only contain ascii
    utility::string_t m_ContentDisposition;
    utility::string_t m_Name;
    utility::string_t m_FileName;
    utility::string_t m_ContentType;
    std::shared_ptr<std::istream> m_Data;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_HttpContent_H_ */
