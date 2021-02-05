/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="CopyFileRequest.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_CopyFileRequest_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_CopyFileRequest_H_

#include "HttpContent.h"
#include "cpprest/details/basic_types.h"
#include <boost/optional.hpp>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

class CopyFileRequest {
    public: 
 CopyFileRequest(
            utility::string_t destPath,
            utility::string_t srcPath,
            boost::optional< utility::string_t > srcStorageName,
            boost::optional< utility::string_t > destStorageName,
            boost::optional< utility::string_t > versionId
        );

        utility::string_t getDestPath() const;
        void setDestPath(utility::string_t destPath);

        utility::string_t getSrcPath() const;
        void setSrcPath(utility::string_t srcPath);

        boost::optional< utility::string_t > getSrcStorageName() const;
        void setSrcStorageName(boost::optional< utility::string_t > srcStorageName);

        boost::optional< utility::string_t > getDestStorageName() const;
        void setDestStorageName(boost::optional< utility::string_t > destStorageName);

        boost::optional< utility::string_t > getVersionId() const;
        void setVersionId(boost::optional< utility::string_t > versionId);

    private:
        utility::string_t m_DestPath;
        utility::string_t m_SrcPath;
        boost::optional< utility::string_t > m_SrcStorageName;
        boost::optional< utility::string_t > m_DestStorageName;
        boost::optional< utility::string_t > m_VersionId;
};

}
}
}
}
}

#endif  /* ASPOSE_WORDS_CLOUD_API_MODELS_CopyFileRequest_H_ */
