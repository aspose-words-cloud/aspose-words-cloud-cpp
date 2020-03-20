/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="CopyFileRequest.cpp">
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
#include "CopyFileRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
CopyFileRequest::CopyFileRequest(
         
                 
                boost::optional<> 
                boost::optional<> 
                boost::optional<> 
        ) : 
            m_(std::move())
            m_(std::move())
            m_(std::move())
            m_(std::move())
            m_(std::move())
        {
            
        }

         CopyFileRequest::getDestPath() const
        {
            return m_;
        }
        void CopyFileRequest::setDestPath( ){
            m_ = std::move();
        }
         CopyFileRequest::getSrcPath() const
        {
            return m_;
        }
        void CopyFileRequest::setSrcPath( ){
            m_ = std::move();
        }
        boost::optional<> CopyFileRequest::getSrcStorageName() const
        {
            return m_;
        }
        void CopyFileRequest::setSrcStorageName(boost::optional<> ){
            m_ = std::move();
        }
        boost::optional<> CopyFileRequest::getDestStorageName() const
        {
            return m_;
        }
        void CopyFileRequest::setDestStorageName(boost::optional<> ){
            m_ = std::move();
        }
        boost::optional<> CopyFileRequest::getVersionId() const
        {
            return m_;
        }
        void CopyFileRequest::setVersionId(boost::optional<> ){
            m_ = std::move();
        }

}
}
}
}
}

