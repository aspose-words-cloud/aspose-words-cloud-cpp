/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ClassifyRequest.cpp">
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
#include "ClassifyRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
ClassifyRequest::ClassifyRequest(
        utility::string_t text,
                boost::optional<utility::string_t> bestClassesCount
        ) : 
            m_text(std::move(text)),
            m_bestClassesCount(std::move(bestClassesCount))
        {
            
        }

        utility::string_t ClassifyRequest::getText() const
        {
            return m_text;
        }
        void ClassifyRequest::setText(utility::string_t text){
            m_text = std::move(text);
        }
        boost::optional<utility::string_t> ClassifyRequest::getBestClassesCount() const
        {
            return m_bestClassesCount;
        }
        void ClassifyRequest::setBestClassesCount(boost::optional<utility::string_t> bestClassesCount){
            m_bestClassesCount = std::move(bestClassesCount);
        }

}
}
}
}
}

