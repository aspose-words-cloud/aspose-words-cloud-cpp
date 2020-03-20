/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SearchRequest.cpp">
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
#include "SearchRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
SearchRequest::SearchRequest(
         
                 
                boost::optional<> 
                boost::optional<> 
                boost::optional<> 
                boost::optional<> 
        ) : 
            m_(std::move())
            m_(std::move())
            m_(std::move())
            m_(std::move())
            m_(std::move())
            m_(std::move())
        {
            
        }

         SearchRequest::getName() const
        {
            return m_;
        }
        void SearchRequest::setName( ){
            m_ = std::move();
        }
         SearchRequest::getPattern() const
        {
            return m_;
        }
        void SearchRequest::setPattern( ){
            m_ = std::move();
        }
        boost::optional<> SearchRequest::getFolder() const
        {
            return m_;
        }
        void SearchRequest::setFolder(boost::optional<> ){
            m_ = std::move();
        }
        boost::optional<> SearchRequest::getStorage() const
        {
            return m_;
        }
        void SearchRequest::setStorage(boost::optional<> ){
            m_ = std::move();
        }
        boost::optional<> SearchRequest::getLoadEncoding() const
        {
            return m_;
        }
        void SearchRequest::setLoadEncoding(boost::optional<> ){
            m_ = std::move();
        }
        boost::optional<> SearchRequest::getPassword() const
        {
            return m_;
        }
        void SearchRequest::setPassword(boost::optional<> ){
            m_ = std::move();
        }

}
}
}
}
}

