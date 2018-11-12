/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PostDocumentExecuteMailMergeRequest.cpp">
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
#include "PostDocumentExecuteMailMergeRequest.h"
namespace io{
namespace swagger{
namespace client{
namespace model{
PostDocumentExecuteMailMergeRequest::PostDocumentExecuteMailMergeRequest(
        utility::string_t name,
                boost::optional<utility::string_t> data,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<bool> withRegions,
                boost::optional<utility::string_t> mailMergeDataFile,
                boost::optional<utility::string_t> cleanup,
                boost::optional<bool> useWholeParagraphAsRegion,
                boost::optional<utility::string_t> destFileName
        )
        {
            this->name = name;
            this->data = data;
            this->folder = folder;
            this->storage = storage;
            this->loadEncoding = loadEncoding;
            this->password = password;
            this->withRegions = withRegions;
            this->mailMergeDataFile = mailMergeDataFile;
            this->cleanup = cleanup;
            this->useWholeParagraphAsRegion = useWholeParagraphAsRegion;
            this->destFileName = destFileName;
        }

}
}
}
}

