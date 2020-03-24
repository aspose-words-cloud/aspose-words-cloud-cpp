/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DownloadFileRequest.h">
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
#pragma once
#ifndef downloadFile_H
#define downloadFile_H 

#include "cpprest/details/basic_types.h"
#include <boost/optional.hpp>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

class DownloadFileRequest{
    public: 
     DownloadFileRequest(
                utility::string_t path,
                boost::optional<utility::string_t> storageName,
                boost::optional<utility::string_t> versionId
        );

        utility::string_t getPath() const;
        void setPath(utility::string_t path);

        boost::optional<utility::string_t> getStorageName() const;
        void setStorageName(boost::optional<utility::string_t> storageName);

        boost::optional<utility::string_t> getVersionId() const;
        void setVersionId(boost::optional<utility::string_t> versionId);
    private:
        utility::string_t m_path;
        boost::optional<utility::string_t> m_storageName;
        boost::optional<utility::string_t> m_versionId;
};

}
}
}
}
}

#endif
