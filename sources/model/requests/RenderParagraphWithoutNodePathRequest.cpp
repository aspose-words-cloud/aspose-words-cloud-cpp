/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="RenderParagraphWithoutNodePathRequest.cpp">
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
#include "RenderParagraphWithoutNodePathRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
RenderParagraphWithoutNodePathRequest::RenderParagraphWithoutNodePathRequest(
        utility::string_t name,
                utility::string_t format,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> fontsLocation
        ) : 
            m_name(std::move(name)),
            m_format(std::move(format)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_fontsLocation(std::move(fontsLocation))
        {
            
        }

        utility::string_t RenderParagraphWithoutNodePathRequest::getName() const
        {
            return m_name;
        }
        void RenderParagraphWithoutNodePathRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t RenderParagraphWithoutNodePathRequest::getFormat() const
        {
            return m_format;
        }
        void RenderParagraphWithoutNodePathRequest::setFormat(utility::string_t format){
            m_format = std::move(format);
        }
        int32_t RenderParagraphWithoutNodePathRequest::getIndex() const
        {
            return m_index;
        }
        void RenderParagraphWithoutNodePathRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> RenderParagraphWithoutNodePathRequest::getFolder() const
        {
            return m_folder;
        }
        void RenderParagraphWithoutNodePathRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> RenderParagraphWithoutNodePathRequest::getStorage() const
        {
            return m_storage;
        }
        void RenderParagraphWithoutNodePathRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> RenderParagraphWithoutNodePathRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void RenderParagraphWithoutNodePathRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> RenderParagraphWithoutNodePathRequest::getPassword() const
        {
            return m_password;
        }
        void RenderParagraphWithoutNodePathRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> RenderParagraphWithoutNodePathRequest::getFontsLocation() const
        {
            return m_fontsLocation;
        }
        void RenderParagraphWithoutNodePathRequest::setFontsLocation(boost::optional<utility::string_t> fontsLocation){
            m_fontsLocation = std::move(fontsLocation);
        }

}
}
}
}
}

