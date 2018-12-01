/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PostSplitDocumentRequest.cpp">
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
#include "PostSplitDocumentRequest.h"
namespace io{
namespace swagger{
namespace client{
namespace model{
PostSplitDocumentRequest::PostSplitDocumentRequest(
        utility::string_t name,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> format,
                boost::optional<int32_t> from,
                boost::optional<int32_t> to,
                boost::optional<bool> zipOutput,
                boost::optional<utility::string_t> fontsLocation
        )
        {
            this->name = name;
            this->folder = folder;
            this->storage = storage;
            this->loadEncoding = loadEncoding;
            this->password = password;
            this->destFileName = destFileName;
            this->format = format;
            this->from = from;
            this->to = to;
            this->zipOutput = zipOutput;
            this->fontsLocation = fontsLocation;
        }

}
}
}
}
