/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="AcceptAllRevisionsRequest.h">
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

#include "HttpContent.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

class AcceptAllRevisionsRequest {
    public: 
 AcceptAllRevisionsRequest(
            std::wstring name,
            std::optional< std::wstring > folder,
            std::optional< std::wstring > storage,
            std::optional< std::wstring > loadEncoding,
            std::optional< std::wstring > password,
            std::optional< std::wstring > destFileName
        );

        std::wstring getName() const;
        void setName(std::wstring name);

        std::optional< std::wstring > getFolder() const;
        void setFolder(std::optional< std::wstring > folder);

        std::optional< std::wstring > getStorage() const;
        void setStorage(std::optional< std::wstring > storage);

        std::optional< std::wstring > getLoadEncoding() const;
        void setLoadEncoding(std::optional< std::wstring > loadEncoding);

        std::optional< std::wstring > getPassword() const;
        void setPassword(std::optional< std::wstring > password);

        std::optional< std::wstring > getDestFileName() const;
        void setDestFileName(std::optional< std::wstring > destFileName);

    private:
        std::wstring m_Name;
        std::optional< std::wstring > m_Folder;
        std::optional< std::wstring > m_Storage;
        std::optional< std::wstring > m_LoadEncoding;
        std::optional< std::wstring > m_Password;
        std::optional< std::wstring > m_DestFileName;
};

}
}
}
}
}

#endif  /* ASPOSE_WORDS_CLOUD_API_MODELS_AcceptAllRevisionsRequest_H_ */
