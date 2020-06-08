/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetParagraphsRequest.cpp">
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
#include "GetParagraphsRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetParagraphsRequest::GetParagraphsRequest(
        utility::string_t name,
                utility::string_t nodePath,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(std::move(name)),
            m_nodePath(std::move(nodePath)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password))
        {
            
        }

        utility::string_t GetParagraphsRequest::getName() const
        {
            return m_name;
        }
        void GetParagraphsRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t GetParagraphsRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void GetParagraphsRequest::setNodePath(utility::string_t nodePath){
            m_nodePath = std::move(nodePath);
        }
        boost::optional<utility::string_t> GetParagraphsRequest::getFolder() const
        {
            return m_folder;
        }
        void GetParagraphsRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetParagraphsRequest::getStorage() const
        {
            return m_storage;
        }
        void GetParagraphsRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetParagraphsRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetParagraphsRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetParagraphsRequest::getPassword() const
        {
            return m_password;
        }
        void GetParagraphsRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetParagraphsWithoutNodePathRequest.cpp">
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
#include "GetParagraphsWithoutNodePathRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetParagraphsWithoutNodePathRequest::GetParagraphsWithoutNodePathRequest(
        utility::string_t name,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(std::move(name)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password))
        {
            
        }

        utility::string_t GetParagraphsWithoutNodePathRequest::getName() const
        {
            return m_name;
        }
        void GetParagraphsWithoutNodePathRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        boost::optional<utility::string_t> GetParagraphsWithoutNodePathRequest::getFolder() const
        {
            return m_folder;
        }
        void GetParagraphsWithoutNodePathRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetParagraphsWithoutNodePathRequest::getStorage() const
        {
            return m_storage;
        }
        void GetParagraphsWithoutNodePathRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetParagraphsWithoutNodePathRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetParagraphsWithoutNodePathRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetParagraphsWithoutNodePathRequest::getPassword() const
        {
            return m_password;
        }
        void GetParagraphsWithoutNodePathRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetRangeTextRequest.cpp">
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
#include "GetRangeTextRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetRangeTextRequest::GetRangeTextRequest(
        utility::string_t name,
                utility::string_t rangeStartIdentifier,
                boost::optional<utility::string_t> rangeEndIdentifier,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(std::move(name)),
            m_rangeStartIdentifier(std::move(rangeStartIdentifier)),
            m_rangeEndIdentifier(std::move(rangeEndIdentifier)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password))
        {
            
        }

        utility::string_t GetRangeTextRequest::getName() const
        {
            return m_name;
        }
        void GetRangeTextRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t GetRangeTextRequest::getRangeStartIdentifier() const
        {
            return m_rangeStartIdentifier;
        }
        void GetRangeTextRequest::setRangeStartIdentifier(utility::string_t rangeStartIdentifier){
            m_rangeStartIdentifier = std::move(rangeStartIdentifier);
        }
        boost::optional<utility::string_t> GetRangeTextRequest::getRangeEndIdentifier() const
        {
            return m_rangeEndIdentifier;
        }
        void GetRangeTextRequest::setRangeEndIdentifier(boost::optional<utility::string_t> rangeEndIdentifier){
            m_rangeEndIdentifier = std::move(rangeEndIdentifier);
        }
        boost::optional<utility::string_t> GetRangeTextRequest::getFolder() const
        {
            return m_folder;
        }
        void GetRangeTextRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetRangeTextRequest::getStorage() const
        {
            return m_storage;
        }
        void GetRangeTextRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetRangeTextRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetRangeTextRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetRangeTextRequest::getPassword() const
        {
            return m_password;
        }
        void GetRangeTextRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetRunRequest.cpp">
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
#include "GetRunRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetRunRequest::GetRunRequest(
        utility::string_t name,
                utility::string_t paragraphPath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(std::move(name)),
            m_paragraphPath(std::move(paragraphPath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password))
        {
            
        }

        utility::string_t GetRunRequest::getName() const
        {
            return m_name;
        }
        void GetRunRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t GetRunRequest::getParagraphPath() const
        {
            return m_paragraphPath;
        }
        void GetRunRequest::setParagraphPath(utility::string_t paragraphPath){
            m_paragraphPath = std::move(paragraphPath);
        }
        int32_t GetRunRequest::getIndex() const
        {
            return m_index;
        }
        void GetRunRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> GetRunRequest::getFolder() const
        {
            return m_folder;
        }
        void GetRunRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetRunRequest::getStorage() const
        {
            return m_storage;
        }
        void GetRunRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetRunRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetRunRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetRunRequest::getPassword() const
        {
            return m_password;
        }
        void GetRunRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetRunFontRequest.cpp">
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
#include "GetRunFontRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetRunFontRequest::GetRunFontRequest(
        utility::string_t name,
                utility::string_t paragraphPath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(std::move(name)),
            m_paragraphPath(std::move(paragraphPath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password))
        {
            
        }

        utility::string_t GetRunFontRequest::getName() const
        {
            return m_name;
        }
        void GetRunFontRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t GetRunFontRequest::getParagraphPath() const
        {
            return m_paragraphPath;
        }
        void GetRunFontRequest::setParagraphPath(utility::string_t paragraphPath){
            m_paragraphPath = std::move(paragraphPath);
        }
        int32_t GetRunFontRequest::getIndex() const
        {
            return m_index;
        }
        void GetRunFontRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> GetRunFontRequest::getFolder() const
        {
            return m_folder;
        }
        void GetRunFontRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetRunFontRequest::getStorage() const
        {
            return m_storage;
        }
        void GetRunFontRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetRunFontRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetRunFontRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetRunFontRequest::getPassword() const
        {
            return m_password;
        }
        void GetRunFontRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetRunsRequest.cpp">
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
#include "GetRunsRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetRunsRequest::GetRunsRequest(
        utility::string_t name,
                utility::string_t paragraphPath,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(std::move(name)),
            m_paragraphPath(std::move(paragraphPath)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password))
        {
            
        }

        utility::string_t GetRunsRequest::getName() const
        {
            return m_name;
        }
        void GetRunsRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t GetRunsRequest::getParagraphPath() const
        {
            return m_paragraphPath;
        }
        void GetRunsRequest::setParagraphPath(utility::string_t paragraphPath){
            m_paragraphPath = std::move(paragraphPath);
        }
        boost::optional<utility::string_t> GetRunsRequest::getFolder() const
        {
            return m_folder;
        }
        void GetRunsRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetRunsRequest::getStorage() const
        {
            return m_storage;
        }
        void GetRunsRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetRunsRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetRunsRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetRunsRequest::getPassword() const
        {
            return m_password;
        }
        void GetRunsRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetSectionRequest.cpp">
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
#include "GetSectionRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetSectionRequest::GetSectionRequest(
        utility::string_t name,
                int32_t sectionIndex,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(std::move(name)),
            m_sectionIndex(std::move(sectionIndex)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password))
        {
            
        }

        utility::string_t GetSectionRequest::getName() const
        {
            return m_name;
        }
        void GetSectionRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        int32_t GetSectionRequest::getSectionIndex() const
        {
            return m_sectionIndex;
        }
        void GetSectionRequest::setSectionIndex(int32_t sectionIndex){
            m_sectionIndex = std::move(sectionIndex);
        }
        boost::optional<utility::string_t> GetSectionRequest::getFolder() const
        {
            return m_folder;
        }
        void GetSectionRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetSectionRequest::getStorage() const
        {
            return m_storage;
        }
        void GetSectionRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetSectionRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetSectionRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetSectionRequest::getPassword() const
        {
            return m_password;
        }
        void GetSectionRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetSectionPageSetupRequest.cpp">
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
#include "GetSectionPageSetupRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetSectionPageSetupRequest::GetSectionPageSetupRequest(
        utility::string_t name,
                int32_t sectionIndex,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(std::move(name)),
            m_sectionIndex(std::move(sectionIndex)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password))
        {
            
        }

        utility::string_t GetSectionPageSetupRequest::getName() const
        {
            return m_name;
        }
        void GetSectionPageSetupRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        int32_t GetSectionPageSetupRequest::getSectionIndex() const
        {
            return m_sectionIndex;
        }
        void GetSectionPageSetupRequest::setSectionIndex(int32_t sectionIndex){
            m_sectionIndex = std::move(sectionIndex);
        }
        boost::optional<utility::string_t> GetSectionPageSetupRequest::getFolder() const
        {
            return m_folder;
        }
        void GetSectionPageSetupRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetSectionPageSetupRequest::getStorage() const
        {
            return m_storage;
        }
        void GetSectionPageSetupRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetSectionPageSetupRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetSectionPageSetupRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetSectionPageSetupRequest::getPassword() const
        {
            return m_password;
        }
        void GetSectionPageSetupRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetSectionsRequest.cpp">
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
#include "GetSectionsRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetSectionsRequest::GetSectionsRequest(
        utility::string_t name,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(std::move(name)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password))
        {
            
        }

        utility::string_t GetSectionsRequest::getName() const
        {
            return m_name;
        }
        void GetSectionsRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        boost::optional<utility::string_t> GetSectionsRequest::getFolder() const
        {
            return m_folder;
        }
        void GetSectionsRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetSectionsRequest::getStorage() const
        {
            return m_storage;
        }
        void GetSectionsRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetSectionsRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetSectionsRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetSectionsRequest::getPassword() const
        {
            return m_password;
        }
        void GetSectionsRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetStyleRequest.cpp">
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
#include "GetStyleRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetStyleRequest::GetStyleRequest(
        utility::string_t name,
                utility::string_t styleName,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(std::move(name)),
            m_styleName(std::move(styleName)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password))
        {
            
        }

        utility::string_t GetStyleRequest::getName() const
        {
            return m_name;
        }
        void GetStyleRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t GetStyleRequest::getStyleName() const
        {
            return m_styleName;
        }
        void GetStyleRequest::setStyleName(utility::string_t styleName){
            m_styleName = std::move(styleName);
        }
        boost::optional<utility::string_t> GetStyleRequest::getFolder() const
        {
            return m_folder;
        }
        void GetStyleRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetStyleRequest::getStorage() const
        {
            return m_storage;
        }
        void GetStyleRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetStyleRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetStyleRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetStyleRequest::getPassword() const
        {
            return m_password;
        }
        void GetStyleRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetStyleFromDocumentElementRequest.cpp">
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
#include "GetStyleFromDocumentElementRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetStyleFromDocumentElementRequest::GetStyleFromDocumentElementRequest(
        utility::string_t name,
                utility::string_t styledNodePath,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(std::move(name)),
            m_styledNodePath(std::move(styledNodePath)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password))
        {
            
        }

        utility::string_t GetStyleFromDocumentElementRequest::getName() const
        {
            return m_name;
        }
        void GetStyleFromDocumentElementRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t GetStyleFromDocumentElementRequest::getStyledNodePath() const
        {
            return m_styledNodePath;
        }
        void GetStyleFromDocumentElementRequest::setStyledNodePath(utility::string_t styledNodePath){
            m_styledNodePath = std::move(styledNodePath);
        }
        boost::optional<utility::string_t> GetStyleFromDocumentElementRequest::getFolder() const
        {
            return m_folder;
        }
        void GetStyleFromDocumentElementRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetStyleFromDocumentElementRequest::getStorage() const
        {
            return m_storage;
        }
        void GetStyleFromDocumentElementRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetStyleFromDocumentElementRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetStyleFromDocumentElementRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetStyleFromDocumentElementRequest::getPassword() const
        {
            return m_password;
        }
        void GetStyleFromDocumentElementRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetStylesRequest.cpp">
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
#include "GetStylesRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetStylesRequest::GetStylesRequest(
        utility::string_t name,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(std::move(name)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password))
        {
            
        }

        utility::string_t GetStylesRequest::getName() const
        {
            return m_name;
        }
        void GetStylesRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        boost::optional<utility::string_t> GetStylesRequest::getFolder() const
        {
            return m_folder;
        }
        void GetStylesRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetStylesRequest::getStorage() const
        {
            return m_storage;
        }
        void GetStylesRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetStylesRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetStylesRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetStylesRequest::getPassword() const
        {
            return m_password;
        }
        void GetStylesRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetTableRequest.cpp">
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
#include "GetTableRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetTableRequest::GetTableRequest(
        utility::string_t name,
                utility::string_t nodePath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(std::move(name)),
            m_nodePath(std::move(nodePath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password))
        {
            
        }

        utility::string_t GetTableRequest::getName() const
        {
            return m_name;
        }
        void GetTableRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t GetTableRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void GetTableRequest::setNodePath(utility::string_t nodePath){
            m_nodePath = std::move(nodePath);
        }
        int32_t GetTableRequest::getIndex() const
        {
            return m_index;
        }
        void GetTableRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> GetTableRequest::getFolder() const
        {
            return m_folder;
        }
        void GetTableRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetTableRequest::getStorage() const
        {
            return m_storage;
        }
        void GetTableRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetTableRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetTableRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetTableRequest::getPassword() const
        {
            return m_password;
        }
        void GetTableRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetTableCellRequest.cpp">
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
#include "GetTableCellRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetTableCellRequest::GetTableCellRequest(
        utility::string_t name,
                utility::string_t tableRowPath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(std::move(name)),
            m_tableRowPath(std::move(tableRowPath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password))
        {
            
        }

        utility::string_t GetTableCellRequest::getName() const
        {
            return m_name;
        }
        void GetTableCellRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t GetTableCellRequest::getTableRowPath() const
        {
            return m_tableRowPath;
        }
        void GetTableCellRequest::setTableRowPath(utility::string_t tableRowPath){
            m_tableRowPath = std::move(tableRowPath);
        }
        int32_t GetTableCellRequest::getIndex() const
        {
            return m_index;
        }
        void GetTableCellRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> GetTableCellRequest::getFolder() const
        {
            return m_folder;
        }
        void GetTableCellRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetTableCellRequest::getStorage() const
        {
            return m_storage;
        }
        void GetTableCellRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetTableCellRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetTableCellRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetTableCellRequest::getPassword() const
        {
            return m_password;
        }
        void GetTableCellRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetTableCellFormatRequest.cpp">
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
#include "GetTableCellFormatRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetTableCellFormatRequest::GetTableCellFormatRequest(
        utility::string_t name,
                utility::string_t tableRowPath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(std::move(name)),
            m_tableRowPath(std::move(tableRowPath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password))
        {
            
        }

        utility::string_t GetTableCellFormatRequest::getName() const
        {
            return m_name;
        }
        void GetTableCellFormatRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t GetTableCellFormatRequest::getTableRowPath() const
        {
            return m_tableRowPath;
        }
        void GetTableCellFormatRequest::setTableRowPath(utility::string_t tableRowPath){
            m_tableRowPath = std::move(tableRowPath);
        }
        int32_t GetTableCellFormatRequest::getIndex() const
        {
            return m_index;
        }
        void GetTableCellFormatRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> GetTableCellFormatRequest::getFolder() const
        {
            return m_folder;
        }
        void GetTableCellFormatRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetTableCellFormatRequest::getStorage() const
        {
            return m_storage;
        }
        void GetTableCellFormatRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetTableCellFormatRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetTableCellFormatRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetTableCellFormatRequest::getPassword() const
        {
            return m_password;
        }
        void GetTableCellFormatRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetTablePropertiesRequest.cpp">
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
#include "GetTablePropertiesRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetTablePropertiesRequest::GetTablePropertiesRequest(
        utility::string_t name,
                utility::string_t nodePath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(std::move(name)),
            m_nodePath(std::move(nodePath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password))
        {
            
        }

        utility::string_t GetTablePropertiesRequest::getName() const
        {
            return m_name;
        }
        void GetTablePropertiesRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t GetTablePropertiesRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void GetTablePropertiesRequest::setNodePath(utility::string_t nodePath){
            m_nodePath = std::move(nodePath);
        }
        int32_t GetTablePropertiesRequest::getIndex() const
        {
            return m_index;
        }
        void GetTablePropertiesRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> GetTablePropertiesRequest::getFolder() const
        {
            return m_folder;
        }
        void GetTablePropertiesRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetTablePropertiesRequest::getStorage() const
        {
            return m_storage;
        }
        void GetTablePropertiesRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetTablePropertiesRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetTablePropertiesRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetTablePropertiesRequest::getPassword() const
        {
            return m_password;
        }
        void GetTablePropertiesRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetTablePropertiesWithoutNodePathRequest.cpp">
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
#include "GetTablePropertiesWithoutNodePathRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetTablePropertiesWithoutNodePathRequest::GetTablePropertiesWithoutNodePathRequest(
        utility::string_t name,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(std::move(name)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password))
        {
            
        }

        utility::string_t GetTablePropertiesWithoutNodePathRequest::getName() const
        {
            return m_name;
        }
        void GetTablePropertiesWithoutNodePathRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        int32_t GetTablePropertiesWithoutNodePathRequest::getIndex() const
        {
            return m_index;
        }
        void GetTablePropertiesWithoutNodePathRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> GetTablePropertiesWithoutNodePathRequest::getFolder() const
        {
            return m_folder;
        }
        void GetTablePropertiesWithoutNodePathRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetTablePropertiesWithoutNodePathRequest::getStorage() const
        {
            return m_storage;
        }
        void GetTablePropertiesWithoutNodePathRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetTablePropertiesWithoutNodePathRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetTablePropertiesWithoutNodePathRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetTablePropertiesWithoutNodePathRequest::getPassword() const
        {
            return m_password;
        }
        void GetTablePropertiesWithoutNodePathRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetTableRowRequest.cpp">
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
#include "GetTableRowRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetTableRowRequest::GetTableRowRequest(
        utility::string_t name,
                utility::string_t tablePath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(std::move(name)),
            m_tablePath(std::move(tablePath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password))
        {
            
        }

        utility::string_t GetTableRowRequest::getName() const
        {
            return m_name;
        }
        void GetTableRowRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t GetTableRowRequest::getTablePath() const
        {
            return m_tablePath;
        }
        void GetTableRowRequest::setTablePath(utility::string_t tablePath){
            m_tablePath = std::move(tablePath);
        }
        int32_t GetTableRowRequest::getIndex() const
        {
            return m_index;
        }
        void GetTableRowRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> GetTableRowRequest::getFolder() const
        {
            return m_folder;
        }
        void GetTableRowRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetTableRowRequest::getStorage() const
        {
            return m_storage;
        }
        void GetTableRowRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetTableRowRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetTableRowRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetTableRowRequest::getPassword() const
        {
            return m_password;
        }
        void GetTableRowRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetTableRowFormatRequest.cpp">
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
#include "GetTableRowFormatRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetTableRowFormatRequest::GetTableRowFormatRequest(
        utility::string_t name,
                utility::string_t tablePath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(std::move(name)),
            m_tablePath(std::move(tablePath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password))
        {
            
        }

        utility::string_t GetTableRowFormatRequest::getName() const
        {
            return m_name;
        }
        void GetTableRowFormatRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t GetTableRowFormatRequest::getTablePath() const
        {
            return m_tablePath;
        }
        void GetTableRowFormatRequest::setTablePath(utility::string_t tablePath){
            m_tablePath = std::move(tablePath);
        }
        int32_t GetTableRowFormatRequest::getIndex() const
        {
            return m_index;
        }
        void GetTableRowFormatRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> GetTableRowFormatRequest::getFolder() const
        {
            return m_folder;
        }
        void GetTableRowFormatRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetTableRowFormatRequest::getStorage() const
        {
            return m_storage;
        }
        void GetTableRowFormatRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetTableRowFormatRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetTableRowFormatRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetTableRowFormatRequest::getPassword() const
        {
            return m_password;
        }
        void GetTableRowFormatRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetTableWithoutNodePathRequest.cpp">
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
#include "GetTableWithoutNodePathRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetTableWithoutNodePathRequest::GetTableWithoutNodePathRequest(
        utility::string_t name,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(std::move(name)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password))
        {
            
        }

        utility::string_t GetTableWithoutNodePathRequest::getName() const
        {
            return m_name;
        }
        void GetTableWithoutNodePathRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        int32_t GetTableWithoutNodePathRequest::getIndex() const
        {
            return m_index;
        }
        void GetTableWithoutNodePathRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> GetTableWithoutNodePathRequest::getFolder() const
        {
            return m_folder;
        }
        void GetTableWithoutNodePathRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetTableWithoutNodePathRequest::getStorage() const
        {
            return m_storage;
        }
        void GetTableWithoutNodePathRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetTableWithoutNodePathRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetTableWithoutNodePathRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetTableWithoutNodePathRequest::getPassword() const
        {
            return m_password;
        }
        void GetTableWithoutNodePathRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetTablesRequest.cpp">
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
#include "GetTablesRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetTablesRequest::GetTablesRequest(
        utility::string_t name,
                utility::string_t nodePath,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(std::move(name)),
            m_nodePath(std::move(nodePath)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password))
        {
            
        }

        utility::string_t GetTablesRequest::getName() const
        {
            return m_name;
        }
        void GetTablesRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t GetTablesRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void GetTablesRequest::setNodePath(utility::string_t nodePath){
            m_nodePath = std::move(nodePath);
        }
        boost::optional<utility::string_t> GetTablesRequest::getFolder() const
        {
            return m_folder;
        }
        void GetTablesRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetTablesRequest::getStorage() const
        {
            return m_storage;
        }
        void GetTablesRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetTablesRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetTablesRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetTablesRequest::getPassword() const
        {
            return m_password;
        }
        void GetTablesRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetTablesWithoutNodePathRequest.cpp">
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
#include "GetTablesWithoutNodePathRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetTablesWithoutNodePathRequest::GetTablesWithoutNodePathRequest(
        utility::string_t name,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(std::move(name)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password))
        {
            
        }

        utility::string_t GetTablesWithoutNodePathRequest::getName() const
        {
            return m_name;
        }
        void GetTablesWithoutNodePathRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        boost::optional<utility::string_t> GetTablesWithoutNodePathRequest::getFolder() const
        {
            return m_folder;
        }
        void GetTablesWithoutNodePathRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetTablesWithoutNodePathRequest::getStorage() const
        {
            return m_storage;
        }
        void GetTablesWithoutNodePathRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetTablesWithoutNodePathRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetTablesWithoutNodePathRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetTablesWithoutNodePathRequest::getPassword() const
        {
            return m_password;
        }
        void GetTablesWithoutNodePathRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertCommentRequest.cpp">
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
#include "InsertCommentRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
InsertCommentRequest::InsertCommentRequest(
        utility::string_t name,
                std::shared_ptr<CommentInsert> comment,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_comment(std::move(comment)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t InsertCommentRequest::getName() const
        {
            return m_name;
        }
        void InsertCommentRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<CommentInsert> InsertCommentRequest::getComment() const
        {
            return m_comment;
        }
        void InsertCommentRequest::setComment(std::shared_ptr<CommentInsert> comment){
            m_comment = std::move(comment);
        }
        boost::optional<utility::string_t> InsertCommentRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertCommentRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> InsertCommentRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertCommentRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> InsertCommentRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertCommentRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> InsertCommentRequest::getPassword() const
        {
            return m_password;
        }
        void InsertCommentRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> InsertCommentRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertCommentRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> InsertCommentRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void InsertCommentRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> InsertCommentRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void InsertCommentRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertDrawingObjectRequest.cpp">
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
#include "InsertDrawingObjectRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
InsertDrawingObjectRequest::InsertDrawingObjectRequest(
        utility::string_t name,
                std::shared_ptr<DrawingObjectInsert> drawingObject,
                std::shared_ptr<HttpContent> imageFile,
                utility::string_t nodePath,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_drawingObject(std::move(drawingObject)),
            m_imageFile(std::move(imageFile)),
            m_nodePath(std::move(nodePath)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t InsertDrawingObjectRequest::getName() const
        {
            return m_name;
        }
        void InsertDrawingObjectRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<DrawingObjectInsert> InsertDrawingObjectRequest::getDrawingObject() const
        {
            return m_drawingObject;
        }
        void InsertDrawingObjectRequest::setDrawingObject(std::shared_ptr<DrawingObjectInsert> drawingObject){
            m_drawingObject = std::move(drawingObject);
        }
        std::shared_ptr<HttpContent> InsertDrawingObjectRequest::getImageFile() const
        {
            return m_imageFile;
        }
        void InsertDrawingObjectRequest::setImageFile(std::shared_ptr<HttpContent> imageFile){
            m_imageFile = std::move(imageFile);
        }
        utility::string_t InsertDrawingObjectRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void InsertDrawingObjectRequest::setNodePath(utility::string_t nodePath){
            m_nodePath = std::move(nodePath);
        }
        boost::optional<utility::string_t> InsertDrawingObjectRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertDrawingObjectRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> InsertDrawingObjectRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertDrawingObjectRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> InsertDrawingObjectRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertDrawingObjectRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> InsertDrawingObjectRequest::getPassword() const
        {
            return m_password;
        }
        void InsertDrawingObjectRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> InsertDrawingObjectRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertDrawingObjectRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> InsertDrawingObjectRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void InsertDrawingObjectRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> InsertDrawingObjectRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void InsertDrawingObjectRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertDrawingObjectWithoutNodePathRequest.cpp">
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
#include "InsertDrawingObjectWithoutNodePathRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
InsertDrawingObjectWithoutNodePathRequest::InsertDrawingObjectWithoutNodePathRequest(
        utility::string_t name,
                std::shared_ptr<DrawingObjectInsert> drawingObject,
                std::shared_ptr<HttpContent> imageFile,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_drawingObject(std::move(drawingObject)),
            m_imageFile(std::move(imageFile)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t InsertDrawingObjectWithoutNodePathRequest::getName() const
        {
            return m_name;
        }
        void InsertDrawingObjectWithoutNodePathRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<DrawingObjectInsert> InsertDrawingObjectWithoutNodePathRequest::getDrawingObject() const
        {
            return m_drawingObject;
        }
        void InsertDrawingObjectWithoutNodePathRequest::setDrawingObject(std::shared_ptr<DrawingObjectInsert> drawingObject){
            m_drawingObject = std::move(drawingObject);
        }
        std::shared_ptr<HttpContent> InsertDrawingObjectWithoutNodePathRequest::getImageFile() const
        {
            return m_imageFile;
        }
        void InsertDrawingObjectWithoutNodePathRequest::setImageFile(std::shared_ptr<HttpContent> imageFile){
            m_imageFile = std::move(imageFile);
        }
        boost::optional<utility::string_t> InsertDrawingObjectWithoutNodePathRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertDrawingObjectWithoutNodePathRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> InsertDrawingObjectWithoutNodePathRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertDrawingObjectWithoutNodePathRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> InsertDrawingObjectWithoutNodePathRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertDrawingObjectWithoutNodePathRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> InsertDrawingObjectWithoutNodePathRequest::getPassword() const
        {
            return m_password;
        }
        void InsertDrawingObjectWithoutNodePathRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> InsertDrawingObjectWithoutNodePathRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertDrawingObjectWithoutNodePathRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> InsertDrawingObjectWithoutNodePathRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void InsertDrawingObjectWithoutNodePathRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> InsertDrawingObjectWithoutNodePathRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void InsertDrawingObjectWithoutNodePathRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertFieldRequest.cpp">
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
#include "InsertFieldRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
InsertFieldRequest::InsertFieldRequest(
        utility::string_t name,
                std::shared_ptr<FieldInsert> field,
                utility::string_t nodePath,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime,
                boost::optional<utility::string_t> insertBeforeNode
        ) : 
            m_name(std::move(name)),
            m_field(std::move(field)),
            m_nodePath(std::move(nodePath)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime)),
            m_insertBeforeNode(std::move(insertBeforeNode))
        {
            
        }

        utility::string_t InsertFieldRequest::getName() const
        {
            return m_name;
        }
        void InsertFieldRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<FieldInsert> InsertFieldRequest::getField() const
        {
            return m_field;
        }
        void InsertFieldRequest::setField(std::shared_ptr<FieldInsert> field){
            m_field = std::move(field);
        }
        utility::string_t InsertFieldRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void InsertFieldRequest::setNodePath(utility::string_t nodePath){
            m_nodePath = std::move(nodePath);
        }
        boost::optional<utility::string_t> InsertFieldRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertFieldRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> InsertFieldRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertFieldRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> InsertFieldRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertFieldRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> InsertFieldRequest::getPassword() const
        {
            return m_password;
        }
        void InsertFieldRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> InsertFieldRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertFieldRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> InsertFieldRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void InsertFieldRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> InsertFieldRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void InsertFieldRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }
        boost::optional<utility::string_t> InsertFieldRequest::getInsertBeforeNode() const
        {
            return m_insertBeforeNode;
        }
        void InsertFieldRequest::setInsertBeforeNode(boost::optional<utility::string_t> insertBeforeNode){
            m_insertBeforeNode = std::move(insertBeforeNode);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertFieldWithoutNodePathRequest.cpp">
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
#include "InsertFieldWithoutNodePathRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
InsertFieldWithoutNodePathRequest::InsertFieldWithoutNodePathRequest(
        utility::string_t name,
                std::shared_ptr<FieldInsert> field,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime,
                boost::optional<utility::string_t> insertBeforeNode
        ) : 
            m_name(std::move(name)),
            m_field(std::move(field)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime)),
            m_insertBeforeNode(std::move(insertBeforeNode))
        {
            
        }

        utility::string_t InsertFieldWithoutNodePathRequest::getName() const
        {
            return m_name;
        }
        void InsertFieldWithoutNodePathRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<FieldInsert> InsertFieldWithoutNodePathRequest::getField() const
        {
            return m_field;
        }
        void InsertFieldWithoutNodePathRequest::setField(std::shared_ptr<FieldInsert> field){
            m_field = std::move(field);
        }
        boost::optional<utility::string_t> InsertFieldWithoutNodePathRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertFieldWithoutNodePathRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> InsertFieldWithoutNodePathRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertFieldWithoutNodePathRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> InsertFieldWithoutNodePathRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertFieldWithoutNodePathRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> InsertFieldWithoutNodePathRequest::getPassword() const
        {
            return m_password;
        }
        void InsertFieldWithoutNodePathRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> InsertFieldWithoutNodePathRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertFieldWithoutNodePathRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> InsertFieldWithoutNodePathRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void InsertFieldWithoutNodePathRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> InsertFieldWithoutNodePathRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void InsertFieldWithoutNodePathRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }
        boost::optional<utility::string_t> InsertFieldWithoutNodePathRequest::getInsertBeforeNode() const
        {
            return m_insertBeforeNode;
        }
        void InsertFieldWithoutNodePathRequest::setInsertBeforeNode(boost::optional<utility::string_t> insertBeforeNode){
            m_insertBeforeNode = std::move(insertBeforeNode);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertFootnoteRequest.cpp">
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
#include "InsertFootnoteRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
InsertFootnoteRequest::InsertFootnoteRequest(
        utility::string_t name,
                std::shared_ptr<FootnoteInsert> footnoteDto,
                utility::string_t nodePath,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_footnoteDto(std::move(footnoteDto)),
            m_nodePath(std::move(nodePath)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t InsertFootnoteRequest::getName() const
        {
            return m_name;
        }
        void InsertFootnoteRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<FootnoteInsert> InsertFootnoteRequest::getFootnoteDto() const
        {
            return m_footnoteDto;
        }
        void InsertFootnoteRequest::setFootnoteDto(std::shared_ptr<FootnoteInsert> footnoteDto){
            m_footnoteDto = std::move(footnoteDto);
        }
        utility::string_t InsertFootnoteRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void InsertFootnoteRequest::setNodePath(utility::string_t nodePath){
            m_nodePath = std::move(nodePath);
        }
        boost::optional<utility::string_t> InsertFootnoteRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertFootnoteRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> InsertFootnoteRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertFootnoteRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> InsertFootnoteRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertFootnoteRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> InsertFootnoteRequest::getPassword() const
        {
            return m_password;
        }
        void InsertFootnoteRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> InsertFootnoteRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertFootnoteRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> InsertFootnoteRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void InsertFootnoteRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> InsertFootnoteRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void InsertFootnoteRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertFootnoteWithoutNodePathRequest.cpp">
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
#include "InsertFootnoteWithoutNodePathRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
InsertFootnoteWithoutNodePathRequest::InsertFootnoteWithoutNodePathRequest(
        utility::string_t name,
                std::shared_ptr<FootnoteInsert> footnoteDto,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_footnoteDto(std::move(footnoteDto)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t InsertFootnoteWithoutNodePathRequest::getName() const
        {
            return m_name;
        }
        void InsertFootnoteWithoutNodePathRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<FootnoteInsert> InsertFootnoteWithoutNodePathRequest::getFootnoteDto() const
        {
            return m_footnoteDto;
        }
        void InsertFootnoteWithoutNodePathRequest::setFootnoteDto(std::shared_ptr<FootnoteInsert> footnoteDto){
            m_footnoteDto = std::move(footnoteDto);
        }
        boost::optional<utility::string_t> InsertFootnoteWithoutNodePathRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertFootnoteWithoutNodePathRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> InsertFootnoteWithoutNodePathRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertFootnoteWithoutNodePathRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> InsertFootnoteWithoutNodePathRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertFootnoteWithoutNodePathRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> InsertFootnoteWithoutNodePathRequest::getPassword() const
        {
            return m_password;
        }
        void InsertFootnoteWithoutNodePathRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> InsertFootnoteWithoutNodePathRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertFootnoteWithoutNodePathRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> InsertFootnoteWithoutNodePathRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void InsertFootnoteWithoutNodePathRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> InsertFootnoteWithoutNodePathRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void InsertFootnoteWithoutNodePathRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertFormFieldRequest.cpp">
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
#include "InsertFormFieldRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
InsertFormFieldRequest::InsertFormFieldRequest(
        utility::string_t name,
                std::shared_ptr<FormField> formField,
                utility::string_t nodePath,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime,
                boost::optional<utility::string_t> insertBeforeNode
        ) : 
            m_name(std::move(name)),
            m_formField(std::move(formField)),
            m_nodePath(std::move(nodePath)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime)),
            m_insertBeforeNode(std::move(insertBeforeNode))
        {
            
        }

        utility::string_t InsertFormFieldRequest::getName() const
        {
            return m_name;
        }
        void InsertFormFieldRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<FormField> InsertFormFieldRequest::getFormField() const
        {
            return m_formField;
        }
        void InsertFormFieldRequest::setFormField(std::shared_ptr<FormField> formField){
            m_formField = std::move(formField);
        }
        utility::string_t InsertFormFieldRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void InsertFormFieldRequest::setNodePath(utility::string_t nodePath){
            m_nodePath = std::move(nodePath);
        }
        boost::optional<utility::string_t> InsertFormFieldRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertFormFieldRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> InsertFormFieldRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertFormFieldRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> InsertFormFieldRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertFormFieldRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> InsertFormFieldRequest::getPassword() const
        {
            return m_password;
        }
        void InsertFormFieldRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> InsertFormFieldRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertFormFieldRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> InsertFormFieldRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void InsertFormFieldRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> InsertFormFieldRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void InsertFormFieldRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }
        boost::optional<utility::string_t> InsertFormFieldRequest::getInsertBeforeNode() const
        {
            return m_insertBeforeNode;
        }
        void InsertFormFieldRequest::setInsertBeforeNode(boost::optional<utility::string_t> insertBeforeNode){
            m_insertBeforeNode = std::move(insertBeforeNode);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertFormFieldWithoutNodePathRequest.cpp">
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
#include "InsertFormFieldWithoutNodePathRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
InsertFormFieldWithoutNodePathRequest::InsertFormFieldWithoutNodePathRequest(
        utility::string_t name,
                std::shared_ptr<FormField> formField,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime,
                boost::optional<utility::string_t> insertBeforeNode
        ) : 
            m_name(std::move(name)),
            m_formField(std::move(formField)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime)),
            m_insertBeforeNode(std::move(insertBeforeNode))
        {
            
        }

        utility::string_t InsertFormFieldWithoutNodePathRequest::getName() const
        {
            return m_name;
        }
        void InsertFormFieldWithoutNodePathRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<FormField> InsertFormFieldWithoutNodePathRequest::getFormField() const
        {
            return m_formField;
        }
        void InsertFormFieldWithoutNodePathRequest::setFormField(std::shared_ptr<FormField> formField){
            m_formField = std::move(formField);
        }
        boost::optional<utility::string_t> InsertFormFieldWithoutNodePathRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertFormFieldWithoutNodePathRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> InsertFormFieldWithoutNodePathRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertFormFieldWithoutNodePathRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> InsertFormFieldWithoutNodePathRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertFormFieldWithoutNodePathRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> InsertFormFieldWithoutNodePathRequest::getPassword() const
        {
            return m_password;
        }
        void InsertFormFieldWithoutNodePathRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> InsertFormFieldWithoutNodePathRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertFormFieldWithoutNodePathRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> InsertFormFieldWithoutNodePathRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void InsertFormFieldWithoutNodePathRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> InsertFormFieldWithoutNodePathRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void InsertFormFieldWithoutNodePathRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }
        boost::optional<utility::string_t> InsertFormFieldWithoutNodePathRequest::getInsertBeforeNode() const
        {
            return m_insertBeforeNode;
        }
        void InsertFormFieldWithoutNodePathRequest::setInsertBeforeNode(boost::optional<utility::string_t> insertBeforeNode){
            m_insertBeforeNode = std::move(insertBeforeNode);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertHeaderFooterRequest.cpp">
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
#include "InsertHeaderFooterRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
InsertHeaderFooterRequest::InsertHeaderFooterRequest(
        utility::string_t name,
                utility::string_t headerFooterType,
                utility::string_t sectionPath,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_headerFooterType(std::move(headerFooterType)),
            m_sectionPath(std::move(sectionPath)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t InsertHeaderFooterRequest::getName() const
        {
            return m_name;
        }
        void InsertHeaderFooterRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t InsertHeaderFooterRequest::getHeaderFooterType() const
        {
            return m_headerFooterType;
        }
        void InsertHeaderFooterRequest::setHeaderFooterType(utility::string_t headerFooterType){
            m_headerFooterType = std::move(headerFooterType);
        }
        utility::string_t InsertHeaderFooterRequest::getSectionPath() const
        {
            return m_sectionPath;
        }
        void InsertHeaderFooterRequest::setSectionPath(utility::string_t sectionPath){
            m_sectionPath = std::move(sectionPath);
        }
        boost::optional<utility::string_t> InsertHeaderFooterRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertHeaderFooterRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> InsertHeaderFooterRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertHeaderFooterRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> InsertHeaderFooterRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertHeaderFooterRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> InsertHeaderFooterRequest::getPassword() const
        {
            return m_password;
        }
        void InsertHeaderFooterRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> InsertHeaderFooterRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertHeaderFooterRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> InsertHeaderFooterRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void InsertHeaderFooterRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> InsertHeaderFooterRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void InsertHeaderFooterRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertListRequest.cpp">
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
#include "InsertListRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
InsertListRequest::InsertListRequest(
        utility::string_t name,
                std::shared_ptr<ListInsert> listInsert,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_listInsert(std::move(listInsert)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t InsertListRequest::getName() const
        {
            return m_name;
        }
        void InsertListRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<ListInsert> InsertListRequest::getListInsert() const
        {
            return m_listInsert;
        }
        void InsertListRequest::setListInsert(std::shared_ptr<ListInsert> listInsert){
            m_listInsert = std::move(listInsert);
        }
        boost::optional<utility::string_t> InsertListRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertListRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> InsertListRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertListRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> InsertListRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertListRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> InsertListRequest::getPassword() const
        {
            return m_password;
        }
        void InsertListRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> InsertListRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertListRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> InsertListRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void InsertListRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> InsertListRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void InsertListRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertOrUpdateParagraphTabStopRequest.cpp">
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
#include "InsertOrUpdateParagraphTabStopRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
InsertOrUpdateParagraphTabStopRequest::InsertOrUpdateParagraphTabStopRequest(
        utility::string_t name,
                std::shared_ptr<TabStopInsert> dto,
                utility::string_t nodePath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName
        ) : 
            m_name(std::move(name)),
            m_dto(std::move(dto)),
            m_nodePath(std::move(nodePath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName))
        {
            
        }

        utility::string_t InsertOrUpdateParagraphTabStopRequest::getName() const
        {
            return m_name;
        }
        void InsertOrUpdateParagraphTabStopRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<TabStopInsert> InsertOrUpdateParagraphTabStopRequest::getDto() const
        {
            return m_dto;
        }
        void InsertOrUpdateParagraphTabStopRequest::setDto(std::shared_ptr<TabStopInsert> dto){
            m_dto = std::move(dto);
        }
        utility::string_t InsertOrUpdateParagraphTabStopRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void InsertOrUpdateParagraphTabStopRequest::setNodePath(utility::string_t nodePath){
            m_nodePath = std::move(nodePath);
        }
        int32_t InsertOrUpdateParagraphTabStopRequest::getIndex() const
        {
            return m_index;
        }
        void InsertOrUpdateParagraphTabStopRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> InsertOrUpdateParagraphTabStopRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertOrUpdateParagraphTabStopRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> InsertOrUpdateParagraphTabStopRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertOrUpdateParagraphTabStopRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> InsertOrUpdateParagraphTabStopRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertOrUpdateParagraphTabStopRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> InsertOrUpdateParagraphTabStopRequest::getPassword() const
        {
            return m_password;
        }
        void InsertOrUpdateParagraphTabStopRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> InsertOrUpdateParagraphTabStopRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertOrUpdateParagraphTabStopRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertOrUpdateParagraphTabStopWithoutNodePathRequest.cpp">
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
#include "InsertOrUpdateParagraphTabStopWithoutNodePathRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
InsertOrUpdateParagraphTabStopWithoutNodePathRequest::InsertOrUpdateParagraphTabStopWithoutNodePathRequest(
        utility::string_t name,
                std::shared_ptr<TabStopInsert> dto,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName
        ) : 
            m_name(std::move(name)),
            m_dto(std::move(dto)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName))
        {
            
        }

        utility::string_t InsertOrUpdateParagraphTabStopWithoutNodePathRequest::getName() const
        {
            return m_name;
        }
        void InsertOrUpdateParagraphTabStopWithoutNodePathRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<TabStopInsert> InsertOrUpdateParagraphTabStopWithoutNodePathRequest::getDto() const
        {
            return m_dto;
        }
        void InsertOrUpdateParagraphTabStopWithoutNodePathRequest::setDto(std::shared_ptr<TabStopInsert> dto){
            m_dto = std::move(dto);
        }
        int32_t InsertOrUpdateParagraphTabStopWithoutNodePathRequest::getIndex() const
        {
            return m_index;
        }
        void InsertOrUpdateParagraphTabStopWithoutNodePathRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> InsertOrUpdateParagraphTabStopWithoutNodePathRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertOrUpdateParagraphTabStopWithoutNodePathRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> InsertOrUpdateParagraphTabStopWithoutNodePathRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertOrUpdateParagraphTabStopWithoutNodePathRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> InsertOrUpdateParagraphTabStopWithoutNodePathRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertOrUpdateParagraphTabStopWithoutNodePathRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> InsertOrUpdateParagraphTabStopWithoutNodePathRequest::getPassword() const
        {
            return m_password;
        }
        void InsertOrUpdateParagraphTabStopWithoutNodePathRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> InsertOrUpdateParagraphTabStopWithoutNodePathRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertOrUpdateParagraphTabStopWithoutNodePathRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertPageNumbersRequest.cpp">
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
#include "InsertPageNumbersRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
InsertPageNumbersRequest::InsertPageNumbersRequest(
        utility::string_t name,
                std::shared_ptr<PageNumber> pageNumber,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_pageNumber(std::move(pageNumber)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t InsertPageNumbersRequest::getName() const
        {
            return m_name;
        }
        void InsertPageNumbersRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<PageNumber> InsertPageNumbersRequest::getPageNumber() const
        {
            return m_pageNumber;
        }
        void InsertPageNumbersRequest::setPageNumber(std::shared_ptr<PageNumber> pageNumber){
            m_pageNumber = std::move(pageNumber);
        }
        boost::optional<utility::string_t> InsertPageNumbersRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertPageNumbersRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> InsertPageNumbersRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertPageNumbersRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> InsertPageNumbersRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertPageNumbersRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> InsertPageNumbersRequest::getPassword() const
        {
            return m_password;
        }
        void InsertPageNumbersRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> InsertPageNumbersRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertPageNumbersRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> InsertPageNumbersRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void InsertPageNumbersRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> InsertPageNumbersRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void InsertPageNumbersRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertParagraphRequest.cpp">
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
#include "InsertParagraphRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
InsertParagraphRequest::InsertParagraphRequest(
        utility::string_t name,
                std::shared_ptr<ParagraphInsert> paragraph,
                utility::string_t nodePath,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime,
                boost::optional<utility::string_t> insertBeforeNode
        ) : 
            m_name(std::move(name)),
            m_paragraph(std::move(paragraph)),
            m_nodePath(std::move(nodePath)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime)),
            m_insertBeforeNode(std::move(insertBeforeNode))
        {
            
        }

        utility::string_t InsertParagraphRequest::getName() const
        {
            return m_name;
        }
        void InsertParagraphRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<ParagraphInsert> InsertParagraphRequest::getParagraph() const
        {
            return m_paragraph;
        }
        void InsertParagraphRequest::setParagraph(std::shared_ptr<ParagraphInsert> paragraph){
            m_paragraph = std::move(paragraph);
        }
        utility::string_t InsertParagraphRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void InsertParagraphRequest::setNodePath(utility::string_t nodePath){
            m_nodePath = std::move(nodePath);
        }
        boost::optional<utility::string_t> InsertParagraphRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertParagraphRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> InsertParagraphRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertParagraphRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> InsertParagraphRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertParagraphRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> InsertParagraphRequest::getPassword() const
        {
            return m_password;
        }
        void InsertParagraphRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> InsertParagraphRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertParagraphRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> InsertParagraphRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void InsertParagraphRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> InsertParagraphRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void InsertParagraphRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }
        boost::optional<utility::string_t> InsertParagraphRequest::getInsertBeforeNode() const
        {
            return m_insertBeforeNode;
        }
        void InsertParagraphRequest::setInsertBeforeNode(boost::optional<utility::string_t> insertBeforeNode){
            m_insertBeforeNode = std::move(insertBeforeNode);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertParagraphWithoutNodePathRequest.cpp">
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
#include "InsertParagraphWithoutNodePathRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
InsertParagraphWithoutNodePathRequest::InsertParagraphWithoutNodePathRequest(
        utility::string_t name,
                std::shared_ptr<ParagraphInsert> paragraph,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime,
                boost::optional<utility::string_t> insertBeforeNode
        ) : 
            m_name(std::move(name)),
            m_paragraph(std::move(paragraph)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime)),
            m_insertBeforeNode(std::move(insertBeforeNode))
        {
            
        }

        utility::string_t InsertParagraphWithoutNodePathRequest::getName() const
        {
            return m_name;
        }
        void InsertParagraphWithoutNodePathRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<ParagraphInsert> InsertParagraphWithoutNodePathRequest::getParagraph() const
        {
            return m_paragraph;
        }
        void InsertParagraphWithoutNodePathRequest::setParagraph(std::shared_ptr<ParagraphInsert> paragraph){
            m_paragraph = std::move(paragraph);
        }
        boost::optional<utility::string_t> InsertParagraphWithoutNodePathRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertParagraphWithoutNodePathRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> InsertParagraphWithoutNodePathRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertParagraphWithoutNodePathRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> InsertParagraphWithoutNodePathRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertParagraphWithoutNodePathRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> InsertParagraphWithoutNodePathRequest::getPassword() const
        {
            return m_password;
        }
        void InsertParagraphWithoutNodePathRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> InsertParagraphWithoutNodePathRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertParagraphWithoutNodePathRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> InsertParagraphWithoutNodePathRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void InsertParagraphWithoutNodePathRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> InsertParagraphWithoutNodePathRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void InsertParagraphWithoutNodePathRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }
        boost::optional<utility::string_t> InsertParagraphWithoutNodePathRequest::getInsertBeforeNode() const
        {
            return m_insertBeforeNode;
        }
        void InsertParagraphWithoutNodePathRequest::setInsertBeforeNode(boost::optional<utility::string_t> insertBeforeNode){
            m_insertBeforeNode = std::move(insertBeforeNode);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertRunRequest.cpp">
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
#include "InsertRunRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
InsertRunRequest::InsertRunRequest(
        utility::string_t name,
                utility::string_t paragraphPath,
                std::shared_ptr<RunInsert> run,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime,
                boost::optional<utility::string_t> insertBeforeNode
        ) : 
            m_name(std::move(name)),
            m_paragraphPath(std::move(paragraphPath)),
            m_run(std::move(run)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime)),
            m_insertBeforeNode(std::move(insertBeforeNode))
        {
            
        }

        utility::string_t InsertRunRequest::getName() const
        {
            return m_name;
        }
        void InsertRunRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t InsertRunRequest::getParagraphPath() const
        {
            return m_paragraphPath;
        }
        void InsertRunRequest::setParagraphPath(utility::string_t paragraphPath){
            m_paragraphPath = std::move(paragraphPath);
        }
        std::shared_ptr<RunInsert> InsertRunRequest::getRun() const
        {
            return m_run;
        }
        void InsertRunRequest::setRun(std::shared_ptr<RunInsert> run){
            m_run = std::move(run);
        }
        boost::optional<utility::string_t> InsertRunRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertRunRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> InsertRunRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertRunRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> InsertRunRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertRunRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> InsertRunRequest::getPassword() const
        {
            return m_password;
        }
        void InsertRunRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> InsertRunRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertRunRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> InsertRunRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void InsertRunRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> InsertRunRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void InsertRunRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }
        boost::optional<utility::string_t> InsertRunRequest::getInsertBeforeNode() const
        {
            return m_insertBeforeNode;
        }
        void InsertRunRequest::setInsertBeforeNode(boost::optional<utility::string_t> insertBeforeNode){
            m_insertBeforeNode = std::move(insertBeforeNode);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertStyleRequest.cpp">
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
#include "InsertStyleRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
InsertStyleRequest::InsertStyleRequest(
        utility::string_t name,
                std::shared_ptr<StyleInsert> styleInsert,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_styleInsert(std::move(styleInsert)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t InsertStyleRequest::getName() const
        {
            return m_name;
        }
        void InsertStyleRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<StyleInsert> InsertStyleRequest::getStyleInsert() const
        {
            return m_styleInsert;
        }
        void InsertStyleRequest::setStyleInsert(std::shared_ptr<StyleInsert> styleInsert){
            m_styleInsert = std::move(styleInsert);
        }
        boost::optional<utility::string_t> InsertStyleRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertStyleRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> InsertStyleRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertStyleRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> InsertStyleRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertStyleRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> InsertStyleRequest::getPassword() const
        {
            return m_password;
        }
        void InsertStyleRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> InsertStyleRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertStyleRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> InsertStyleRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void InsertStyleRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> InsertStyleRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void InsertStyleRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertTableRequest.cpp">
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
#include "InsertTableRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
InsertTableRequest::InsertTableRequest(
        utility::string_t name,
        std::shared_ptr<TableInsert> table,
        utility::string_t nodePath,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_table(std::move(table)),
            m_nodePath(std::move(nodePath)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t InsertTableRequest::getName() const
        {
            return m_name;
        }
        void InsertTableRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<TableInsert> InsertTableRequest::getTable() const
        {
            return m_table;
        }
        void InsertTableRequest::setTable(std::shared_ptr<TableInsert> table){
            m_table = std::move(table);
        }
        utility::string_t InsertTableRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void InsertTableRequest::setNodePath(utility::string_t nodePath){
            m_nodePath = std::move(nodePath);
        }
        boost::optional<utility::string_t> InsertTableRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertTableRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> InsertTableRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertTableRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> InsertTableRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertTableRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> InsertTableRequest::getPassword() const
        {
            return m_password;
        }
        void InsertTableRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> InsertTableRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertTableRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> InsertTableRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void InsertTableRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> InsertTableRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void InsertTableRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertTableCellRequest.cpp">
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
#include "InsertTableCellRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
InsertTableCellRequest::InsertTableCellRequest(
        utility::string_t name,
        std::shared_ptr<TableCellInsert> cell,
        utility::string_t tableRowPath,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_cell(std::move(cell)),
            m_tableRowPath(std::move(tableRowPath)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t InsertTableCellRequest::getName() const
        {
            return m_name;
        }
        void InsertTableCellRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<TableCellInsert> InsertTableCellRequest::getCell() const
        {
            return m_cell;
        }
        void InsertTableCellRequest::setCell(std::shared_ptr<TableCellInsert> cell){
            m_cell = std::move(cell);
        }
        utility::string_t InsertTableCellRequest::getTableRowPath() const
        {
            return m_tableRowPath;
        }
        void InsertTableCellRequest::setTableRowPath(utility::string_t tableRowPath){
            m_tableRowPath = std::move(tableRowPath);
        }
        boost::optional<utility::string_t> InsertTableCellRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertTableCellRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> InsertTableCellRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertTableCellRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> InsertTableCellRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertTableCellRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> InsertTableCellRequest::getPassword() const
        {
            return m_password;
        }
        void InsertTableCellRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> InsertTableCellRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertTableCellRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> InsertTableCellRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void InsertTableCellRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> InsertTableCellRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void InsertTableCellRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertTableRowRequest.cpp">
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
#include "InsertTableRowRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
InsertTableRowRequest::InsertTableRowRequest(
        utility::string_t name,
        std::shared_ptr<TableRowInsert> row,
        utility::string_t tablePath,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_row(std::move(row)),
            m_tablePath(std::move(tablePath)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t InsertTableRowRequest::getName() const
        {
            return m_name;
        }
        void InsertTableRowRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<TableRowInsert> InsertTableRowRequest::getRow() const
        {
            return m_row;
        }
        void InsertTableRowRequest::setRow(std::shared_ptr<TableRowInsert> row){
            m_row = std::move(row);
        }
        utility::string_t InsertTableRowRequest::getTablePath() const
        {
            return m_tablePath;
        }
        void InsertTableRowRequest::setTablePath(utility::string_t tablePath){
            m_tablePath = std::move(tablePath);
        }
        boost::optional<utility::string_t> InsertTableRowRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertTableRowRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> InsertTableRowRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertTableRowRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> InsertTableRowRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertTableRowRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> InsertTableRowRequest::getPassword() const
        {
            return m_password;
        }
        void InsertTableRowRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> InsertTableRowRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertTableRowRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> InsertTableRowRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void InsertTableRowRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> InsertTableRowRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void InsertTableRowRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertTableWithoutNodePathRequest.cpp">
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
#include "InsertTableWithoutNodePathRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
InsertTableWithoutNodePathRequest::InsertTableWithoutNodePathRequest(
        utility::string_t name,
        std::shared_ptr<TableInsert> table,
        boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_table(std::move(table)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t InsertTableWithoutNodePathRequest::getName() const
        {
            return m_name;
        }
        void InsertTableWithoutNodePathRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<TableInsert> InsertTableWithoutNodePathRequest::getTable() const
        {
            return m_table;
        }
        void InsertTableWithoutNodePathRequest::setTable(std::shared_ptr<TableInsert> table){
            m_table = std::move(table);
        }
        boost::optional<utility::string_t> InsertTableWithoutNodePathRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertTableWithoutNodePathRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> InsertTableWithoutNodePathRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertTableWithoutNodePathRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> InsertTableWithoutNodePathRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertTableWithoutNodePathRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> InsertTableWithoutNodePathRequest::getPassword() const
        {
            return m_password;
        }
        void InsertTableWithoutNodePathRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> InsertTableWithoutNodePathRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertTableWithoutNodePathRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> InsertTableWithoutNodePathRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void InsertTableWithoutNodePathRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> InsertTableWithoutNodePathRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void InsertTableWithoutNodePathRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertWatermarkImageRequest.cpp">
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
#include "InsertWatermarkImageRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
InsertWatermarkImageRequest::InsertWatermarkImageRequest(
        utility::string_t name,
                boost::optional<std::shared_ptr<HttpContent>> imageFile,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime,
                boost::optional<double> rotationAngle,
                boost::optional<utility::string_t> image
        ) : 
            m_name(std::move(name)),
            m_imageFile(std::move(imageFile)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime)),
            m_rotationAngle(std::move(rotationAngle)),
            m_image(std::move(image))
        {
            
        }

        utility::string_t InsertWatermarkImageRequest::getName() const
        {
            return m_name;
        }
        void InsertWatermarkImageRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        boost::optional<std::shared_ptr<HttpContent>> InsertWatermarkImageRequest::getImageFile() const
        {
            return m_imageFile;
        }
        void InsertWatermarkImageRequest::setImageFile(boost::optional<std::shared_ptr<HttpContent>> imageFile){
            m_imageFile = std::move(imageFile);
        }
        boost::optional<utility::string_t> InsertWatermarkImageRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertWatermarkImageRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> InsertWatermarkImageRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertWatermarkImageRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> InsertWatermarkImageRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertWatermarkImageRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> InsertWatermarkImageRequest::getPassword() const
        {
            return m_password;
        }
        void InsertWatermarkImageRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> InsertWatermarkImageRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertWatermarkImageRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> InsertWatermarkImageRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void InsertWatermarkImageRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> InsertWatermarkImageRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void InsertWatermarkImageRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }
        boost::optional<double> InsertWatermarkImageRequest::getRotationAngle() const
        {
            return m_rotationAngle;
        }
        void InsertWatermarkImageRequest::setRotationAngle(boost::optional<double> rotationAngle){
            m_rotationAngle = std::move(rotationAngle);
        }
        boost::optional<utility::string_t> InsertWatermarkImageRequest::getImage() const
        {
            return m_image;
        }
        void InsertWatermarkImageRequest::setImage(boost::optional<utility::string_t> image){
            m_image = std::move(image);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertWatermarkTextRequest.cpp">
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
#include "InsertWatermarkTextRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
InsertWatermarkTextRequest::InsertWatermarkTextRequest(
        utility::string_t name,
                std::shared_ptr<WatermarkText> watermarkText,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_watermarkText(std::move(watermarkText)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t InsertWatermarkTextRequest::getName() const
        {
            return m_name;
        }
        void InsertWatermarkTextRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<WatermarkText> InsertWatermarkTextRequest::getWatermarkText() const
        {
            return m_watermarkText;
        }
        void InsertWatermarkTextRequest::setWatermarkText(std::shared_ptr<WatermarkText> watermarkText){
            m_watermarkText = std::move(watermarkText);
        }
        boost::optional<utility::string_t> InsertWatermarkTextRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertWatermarkTextRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> InsertWatermarkTextRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertWatermarkTextRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> InsertWatermarkTextRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertWatermarkTextRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> InsertWatermarkTextRequest::getPassword() const
        {
            return m_password;
        }
        void InsertWatermarkTextRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> InsertWatermarkTextRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertWatermarkTextRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> InsertWatermarkTextRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void InsertWatermarkTextRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> InsertWatermarkTextRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void InsertWatermarkTextRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="LoadWebDocumentRequest.cpp">
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
#include "LoadWebDocumentRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
LoadWebDocumentRequest::LoadWebDocumentRequest(
        std::shared_ptr<LoadWebDocumentData> data,
                boost::optional<utility::string_t> storage
        ) : 
            m_data(std::move(data)),
            m_storage(std::move(storage))
        {
            
        }

        std::shared_ptr<LoadWebDocumentData> LoadWebDocumentRequest::getData() const
        {
            return m_data;
        }
        void LoadWebDocumentRequest::setData(std::shared_ptr<LoadWebDocumentData> data){
            m_data = std::move(data);
        }
        boost::optional<utility::string_t> LoadWebDocumentRequest::getStorage() const
        {
            return m_storage;
        }
        void LoadWebDocumentRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="MoveFileRequest.cpp">
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
#include "MoveFileRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
MoveFileRequest::MoveFileRequest(
        utility::string_t destPath,
                utility::string_t srcPath,
                boost::optional<utility::string_t> srcStorageName,
                boost::optional<utility::string_t> destStorageName,
                boost::optional<utility::string_t> versionId
        ) : 
            m_destPath(std::move(destPath)),
            m_srcPath(std::move(srcPath)),
            m_srcStorageName(std::move(srcStorageName)),
            m_destStorageName(std::move(destStorageName)),
            m_versionId(std::move(versionId))
        {
            
        }

        utility::string_t MoveFileRequest::getDestPath() const
        {
            return m_destPath;
        }
        void MoveFileRequest::setDestPath(utility::string_t destPath){
            m_destPath = std::move(destPath);
        }
        utility::string_t MoveFileRequest::getSrcPath() const
        {
            return m_srcPath;
        }
        void MoveFileRequest::setSrcPath(utility::string_t srcPath){
            m_srcPath = std::move(srcPath);
        }
        boost::optional<utility::string_t> MoveFileRequest::getSrcStorageName() const
        {
            return m_srcStorageName;
        }
        void MoveFileRequest::setSrcStorageName(boost::optional<utility::string_t> srcStorageName){
            m_srcStorageName = std::move(srcStorageName);
        }
        boost::optional<utility::string_t> MoveFileRequest::getDestStorageName() const
        {
            return m_destStorageName;
        }
        void MoveFileRequest::setDestStorageName(boost::optional<utility::string_t> destStorageName){
            m_destStorageName = std::move(destStorageName);
        }
        boost::optional<utility::string_t> MoveFileRequest::getVersionId() const
        {
            return m_versionId;
        }
        void MoveFileRequest::setVersionId(boost::optional<utility::string_t> versionId){
            m_versionId = std::move(versionId);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="MoveFolderRequest.cpp">
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
#include "MoveFolderRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
MoveFolderRequest::MoveFolderRequest(
        utility::string_t destPath,
                utility::string_t srcPath,
                boost::optional<utility::string_t> srcStorageName,
                boost::optional<utility::string_t> destStorageName
        ) : 
            m_destPath(std::move(destPath)),
            m_srcPath(std::move(srcPath)),
            m_srcStorageName(std::move(srcStorageName)),
            m_destStorageName(std::move(destStorageName))
        {
            
        }

        utility::string_t MoveFolderRequest::getDestPath() const
        {
            return m_destPath;
        }
        void MoveFolderRequest::setDestPath(utility::string_t destPath){
            m_destPath = std::move(destPath);
        }
        utility::string_t MoveFolderRequest::getSrcPath() const
        {
            return m_srcPath;
        }
        void MoveFolderRequest::setSrcPath(utility::string_t srcPath){
            m_srcPath = std::move(srcPath);
        }
        boost::optional<utility::string_t> MoveFolderRequest::getSrcStorageName() const
        {
            return m_srcStorageName;
        }
        void MoveFolderRequest::setSrcStorageName(boost::optional<utility::string_t> srcStorageName){
            m_srcStorageName = std::move(srcStorageName);
        }
        boost::optional<utility::string_t> MoveFolderRequest::getDestStorageName() const
        {
            return m_destStorageName;
        }
        void MoveFolderRequest::setDestStorageName(boost::optional<utility::string_t> destStorageName){
            m_destStorageName = std::move(destStorageName);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ProtectDocumentRequest.cpp">
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
#include "ProtectDocumentRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
ProtectDocumentRequest::ProtectDocumentRequest(
        utility::string_t name,
                std::shared_ptr<ProtectionRequest> protectionRequest,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName
        ) : 
            m_name(std::move(name)),
            m_protectionRequest(std::move(protectionRequest)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName))
        {
            
        }

        utility::string_t ProtectDocumentRequest::getName() const
        {
            return m_name;
        }
        void ProtectDocumentRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<ProtectionRequest> ProtectDocumentRequest::getProtectionRequest() const
        {
            return m_protectionRequest;
        }
        void ProtectDocumentRequest::setProtectionRequest(std::shared_ptr<ProtectionRequest> protectionRequest){
            m_protectionRequest = std::move(protectionRequest);
        }
        boost::optional<utility::string_t> ProtectDocumentRequest::getFolder() const
        {
            return m_folder;
        }
        void ProtectDocumentRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> ProtectDocumentRequest::getStorage() const
        {
            return m_storage;
        }
        void ProtectDocumentRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> ProtectDocumentRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void ProtectDocumentRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> ProtectDocumentRequest::getPassword() const
        {
            return m_password;
        }
        void ProtectDocumentRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> ProtectDocumentRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void ProtectDocumentRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="RejectAllRevisionsRequest.cpp">
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
#include "RejectAllRevisionsRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
RejectAllRevisionsRequest::RejectAllRevisionsRequest(
        utility::string_t name,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName
        ) : 
            m_name(std::move(name)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName))
        {
            
        }

        utility::string_t RejectAllRevisionsRequest::getName() const
        {
            return m_name;
        }
        void RejectAllRevisionsRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        boost::optional<utility::string_t> RejectAllRevisionsRequest::getFolder() const
        {
            return m_folder;
        }
        void RejectAllRevisionsRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> RejectAllRevisionsRequest::getStorage() const
        {
            return m_storage;
        }
        void RejectAllRevisionsRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> RejectAllRevisionsRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void RejectAllRevisionsRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> RejectAllRevisionsRequest::getPassword() const
        {
            return m_password;
        }
        void RejectAllRevisionsRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> RejectAllRevisionsRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void RejectAllRevisionsRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="RemoveRangeRequest.cpp">
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
#include "RemoveRangeRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
RemoveRangeRequest::RemoveRangeRequest(
        utility::string_t name,
                utility::string_t rangeStartIdentifier,
                boost::optional<utility::string_t> rangeEndIdentifier,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName
        ) : 
            m_name(std::move(name)),
            m_rangeStartIdentifier(std::move(rangeStartIdentifier)),
            m_rangeEndIdentifier(std::move(rangeEndIdentifier)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName))
        {
            
        }

        utility::string_t RemoveRangeRequest::getName() const
        {
            return m_name;
        }
        void RemoveRangeRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t RemoveRangeRequest::getRangeStartIdentifier() const
        {
            return m_rangeStartIdentifier;
        }
        void RemoveRangeRequest::setRangeStartIdentifier(utility::string_t rangeStartIdentifier){
            m_rangeStartIdentifier = std::move(rangeStartIdentifier);
        }
        boost::optional<utility::string_t> RemoveRangeRequest::getRangeEndIdentifier() const
        {
            return m_rangeEndIdentifier;
        }
        void RemoveRangeRequest::setRangeEndIdentifier(boost::optional<utility::string_t> rangeEndIdentifier){
            m_rangeEndIdentifier = std::move(rangeEndIdentifier);
        }
        boost::optional<utility::string_t> RemoveRangeRequest::getFolder() const
        {
            return m_folder;
        }
        void RemoveRangeRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> RemoveRangeRequest::getStorage() const
        {
            return m_storage;
        }
        void RemoveRangeRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> RemoveRangeRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void RemoveRangeRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> RemoveRangeRequest::getPassword() const
        {
            return m_password;
        }
        void RemoveRangeRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> RemoveRangeRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void RemoveRangeRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="RenderDrawingObjectRequest.cpp">
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
#include "RenderDrawingObjectRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
RenderDrawingObjectRequest::RenderDrawingObjectRequest(
        utility::string_t name,
                utility::string_t format,
                utility::string_t nodePath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> fontsLocation
        ) : 
            m_name(std::move(name)),
            m_format(std::move(format)),
            m_nodePath(std::move(nodePath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_fontsLocation(std::move(fontsLocation))
        {
            
        }

        utility::string_t RenderDrawingObjectRequest::getName() const
        {
            return m_name;
        }
        void RenderDrawingObjectRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t RenderDrawingObjectRequest::getFormat() const
        {
            return m_format;
        }
        void RenderDrawingObjectRequest::setFormat(utility::string_t format){
            m_format = std::move(format);
        }
        utility::string_t RenderDrawingObjectRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void RenderDrawingObjectRequest::setNodePath(utility::string_t nodePath){
            m_nodePath = std::move(nodePath);
        }
        int32_t RenderDrawingObjectRequest::getIndex() const
        {
            return m_index;
        }
        void RenderDrawingObjectRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> RenderDrawingObjectRequest::getFolder() const
        {
            return m_folder;
        }
        void RenderDrawingObjectRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> RenderDrawingObjectRequest::getStorage() const
        {
            return m_storage;
        }
        void RenderDrawingObjectRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> RenderDrawingObjectRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void RenderDrawingObjectRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> RenderDrawingObjectRequest::getPassword() const
        {
            return m_password;
        }
        void RenderDrawingObjectRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> RenderDrawingObjectRequest::getFontsLocation() const
        {
            return m_fontsLocation;
        }
        void RenderDrawingObjectRequest::setFontsLocation(boost::optional<utility::string_t> fontsLocation){
            m_fontsLocation = std::move(fontsLocation);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="RenderDrawingObjectWithoutNodePathRequest.cpp">
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
#include "RenderDrawingObjectWithoutNodePathRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
RenderDrawingObjectWithoutNodePathRequest::RenderDrawingObjectWithoutNodePathRequest(
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

        utility::string_t RenderDrawingObjectWithoutNodePathRequest::getName() const
        {
            return m_name;
        }
        void RenderDrawingObjectWithoutNodePathRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t RenderDrawingObjectWithoutNodePathRequest::getFormat() const
        {
            return m_format;
        }
        void RenderDrawingObjectWithoutNodePathRequest::setFormat(utility::string_t format){
            m_format = std::move(format);
        }
        int32_t RenderDrawingObjectWithoutNodePathRequest::getIndex() const
        {
            return m_index;
        }
        void RenderDrawingObjectWithoutNodePathRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> RenderDrawingObjectWithoutNodePathRequest::getFolder() const
        {
            return m_folder;
        }
        void RenderDrawingObjectWithoutNodePathRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> RenderDrawingObjectWithoutNodePathRequest::getStorage() const
        {
            return m_storage;
        }
        void RenderDrawingObjectWithoutNodePathRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> RenderDrawingObjectWithoutNodePathRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void RenderDrawingObjectWithoutNodePathRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> RenderDrawingObjectWithoutNodePathRequest::getPassword() const
        {
            return m_password;
        }
        void RenderDrawingObjectWithoutNodePathRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> RenderDrawingObjectWithoutNodePathRequest::getFontsLocation() const
        {
            return m_fontsLocation;
        }
        void RenderDrawingObjectWithoutNodePathRequest::setFontsLocation(boost::optional<utility::string_t> fontsLocation){
            m_fontsLocation = std::move(fontsLocation);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="RenderMathObjectRequest.cpp">
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
#include "RenderMathObjectRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
RenderMathObjectRequest::RenderMathObjectRequest(
        utility::string_t name,
                utility::string_t format,
                utility::string_t nodePath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> fontsLocation
        ) : 
            m_name(std::move(name)),
            m_format(std::move(format)),
            m_nodePath(std::move(nodePath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_fontsLocation(std::move(fontsLocation))
        {
            
        }

        utility::string_t RenderMathObjectRequest::getName() const
        {
            return m_name;
        }
        void RenderMathObjectRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t RenderMathObjectRequest::getFormat() const
        {
            return m_format;
        }
        void RenderMathObjectRequest::setFormat(utility::string_t format){
            m_format = std::move(format);
        }
        utility::string_t RenderMathObjectRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void RenderMathObjectRequest::setNodePath(utility::string_t nodePath){
            m_nodePath = std::move(nodePath);
        }
        int32_t RenderMathObjectRequest::getIndex() const
        {
            return m_index;
        }
        void RenderMathObjectRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> RenderMathObjectRequest::getFolder() const
        {
            return m_folder;
        }
        void RenderMathObjectRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> RenderMathObjectRequest::getStorage() const
        {
            return m_storage;
        }
        void RenderMathObjectRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> RenderMathObjectRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void RenderMathObjectRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> RenderMathObjectRequest::getPassword() const
        {
            return m_password;
        }
        void RenderMathObjectRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> RenderMathObjectRequest::getFontsLocation() const
        {
            return m_fontsLocation;
        }
        void RenderMathObjectRequest::setFontsLocation(boost::optional<utility::string_t> fontsLocation){
            m_fontsLocation = std::move(fontsLocation);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="RenderMathObjectWithoutNodePathRequest.cpp">
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
#include "RenderMathObjectWithoutNodePathRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
RenderMathObjectWithoutNodePathRequest::RenderMathObjectWithoutNodePathRequest(
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

        utility::string_t RenderMathObjectWithoutNodePathRequest::getName() const
        {
            return m_name;
        }
        void RenderMathObjectWithoutNodePathRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t RenderMathObjectWithoutNodePathRequest::getFormat() const
        {
            return m_format;
        }
        void RenderMathObjectWithoutNodePathRequest::setFormat(utility::string_t format){
            m_format = std::move(format);
        }
        int32_t RenderMathObjectWithoutNodePathRequest::getIndex() const
        {
            return m_index;
        }
        void RenderMathObjectWithoutNodePathRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> RenderMathObjectWithoutNodePathRequest::getFolder() const
        {
            return m_folder;
        }
        void RenderMathObjectWithoutNodePathRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> RenderMathObjectWithoutNodePathRequest::getStorage() const
        {
            return m_storage;
        }
        void RenderMathObjectWithoutNodePathRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> RenderMathObjectWithoutNodePathRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void RenderMathObjectWithoutNodePathRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> RenderMathObjectWithoutNodePathRequest::getPassword() const
        {
            return m_password;
        }
        void RenderMathObjectWithoutNodePathRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> RenderMathObjectWithoutNodePathRequest::getFontsLocation() const
        {
            return m_fontsLocation;
        }
        void RenderMathObjectWithoutNodePathRequest::setFontsLocation(boost::optional<utility::string_t> fontsLocation){
            m_fontsLocation = std::move(fontsLocation);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="RenderPageRequest.cpp">
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
#include "RenderPageRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
RenderPageRequest::RenderPageRequest(
        utility::string_t name,
                int32_t pageIndex,
                utility::string_t format,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> fontsLocation
        ) : 
            m_name(std::move(name)),
            m_pageIndex(std::move(pageIndex)),
            m_format(std::move(format)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_fontsLocation(std::move(fontsLocation))
        {
            
        }

        utility::string_t RenderPageRequest::getName() const
        {
            return m_name;
        }
        void RenderPageRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        int32_t RenderPageRequest::getPageIndex() const
        {
            return m_pageIndex;
        }
        void RenderPageRequest::setPageIndex(int32_t pageIndex){
            m_pageIndex = std::move(pageIndex);
        }
        utility::string_t RenderPageRequest::getFormat() const
        {
            return m_format;
        }
        void RenderPageRequest::setFormat(utility::string_t format){
            m_format = std::move(format);
        }
        boost::optional<utility::string_t> RenderPageRequest::getFolder() const
        {
            return m_folder;
        }
        void RenderPageRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> RenderPageRequest::getStorage() const
        {
            return m_storage;
        }
        void RenderPageRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> RenderPageRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void RenderPageRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> RenderPageRequest::getPassword() const
        {
            return m_password;
        }
        void RenderPageRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> RenderPageRequest::getFontsLocation() const
        {
            return m_fontsLocation;
        }
        void RenderPageRequest::setFontsLocation(boost::optional<utility::string_t> fontsLocation){
            m_fontsLocation = std::move(fontsLocation);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="RenderParagraphRequest.cpp">
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
#include "RenderParagraphRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
RenderParagraphRequest::RenderParagraphRequest(
        utility::string_t name,
                utility::string_t format,
                utility::string_t nodePath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> fontsLocation
        ) : 
            m_name(std::move(name)),
            m_format(std::move(format)),
            m_nodePath(std::move(nodePath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_fontsLocation(std::move(fontsLocation))
        {
            
        }

        utility::string_t RenderParagraphRequest::getName() const
        {
            return m_name;
        }
        void RenderParagraphRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t RenderParagraphRequest::getFormat() const
        {
            return m_format;
        }
        void RenderParagraphRequest::setFormat(utility::string_t format){
            m_format = std::move(format);
        }
        utility::string_t RenderParagraphRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void RenderParagraphRequest::setNodePath(utility::string_t nodePath){
            m_nodePath = std::move(nodePath);
        }
        int32_t RenderParagraphRequest::getIndex() const
        {
            return m_index;
        }
        void RenderParagraphRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> RenderParagraphRequest::getFolder() const
        {
            return m_folder;
        }
        void RenderParagraphRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> RenderParagraphRequest::getStorage() const
        {
            return m_storage;
        }
        void RenderParagraphRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> RenderParagraphRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void RenderParagraphRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> RenderParagraphRequest::getPassword() const
        {
            return m_password;
        }
        void RenderParagraphRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> RenderParagraphRequest::getFontsLocation() const
        {
            return m_fontsLocation;
        }
        void RenderParagraphRequest::setFontsLocation(boost::optional<utility::string_t> fontsLocation){
            m_fontsLocation = std::move(fontsLocation);
        }

}
}
}
}
}

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

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="RenderTableRequest.cpp">
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
#include "RenderTableRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
RenderTableRequest::RenderTableRequest(
        utility::string_t name,
                utility::string_t format,
                utility::string_t nodePath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> fontsLocation
        ) : 
            m_name(std::move(name)),
            m_format(std::move(format)),
            m_nodePath(std::move(nodePath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_fontsLocation(std::move(fontsLocation))
        {
            
        }

        utility::string_t RenderTableRequest::getName() const
        {
            return m_name;
        }
        void RenderTableRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t RenderTableRequest::getFormat() const
        {
            return m_format;
        }
        void RenderTableRequest::setFormat(utility::string_t format){
            m_format = std::move(format);
        }
        utility::string_t RenderTableRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void RenderTableRequest::setNodePath(utility::string_t nodePath){
            m_nodePath = std::move(nodePath);
        }
        int32_t RenderTableRequest::getIndex() const
        {
            return m_index;
        }
        void RenderTableRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> RenderTableRequest::getFolder() const
        {
            return m_folder;
        }
        void RenderTableRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> RenderTableRequest::getStorage() const
        {
            return m_storage;
        }
        void RenderTableRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> RenderTableRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void RenderTableRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> RenderTableRequest::getPassword() const
        {
            return m_password;
        }
        void RenderTableRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> RenderTableRequest::getFontsLocation() const
        {
            return m_fontsLocation;
        }
        void RenderTableRequest::setFontsLocation(boost::optional<utility::string_t> fontsLocation){
            m_fontsLocation = std::move(fontsLocation);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="RenderTableWithoutNodePathRequest.cpp">
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
#include "RenderTableWithoutNodePathRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
RenderTableWithoutNodePathRequest::RenderTableWithoutNodePathRequest(
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

        utility::string_t RenderTableWithoutNodePathRequest::getName() const
        {
            return m_name;
        }
        void RenderTableWithoutNodePathRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t RenderTableWithoutNodePathRequest::getFormat() const
        {
            return m_format;
        }
        void RenderTableWithoutNodePathRequest::setFormat(utility::string_t format){
            m_format = std::move(format);
        }
        int32_t RenderTableWithoutNodePathRequest::getIndex() const
        {
            return m_index;
        }
        void RenderTableWithoutNodePathRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> RenderTableWithoutNodePathRequest::getFolder() const
        {
            return m_folder;
        }
        void RenderTableWithoutNodePathRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> RenderTableWithoutNodePathRequest::getStorage() const
        {
            return m_storage;
        }
        void RenderTableWithoutNodePathRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> RenderTableWithoutNodePathRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void RenderTableWithoutNodePathRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> RenderTableWithoutNodePathRequest::getPassword() const
        {
            return m_password;
        }
        void RenderTableWithoutNodePathRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> RenderTableWithoutNodePathRequest::getFontsLocation() const
        {
            return m_fontsLocation;
        }
        void RenderTableWithoutNodePathRequest::setFontsLocation(boost::optional<utility::string_t> fontsLocation){
            m_fontsLocation = std::move(fontsLocation);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ReplaceTextRequest.cpp">
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
#include "ReplaceTextRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
ReplaceTextRequest::ReplaceTextRequest(
        utility::string_t name,
                std::shared_ptr<ReplaceTextParameters> replaceText,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_replaceText(std::move(replaceText)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t ReplaceTextRequest::getName() const
        {
            return m_name;
        }
        void ReplaceTextRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<ReplaceTextParameters> ReplaceTextRequest::getReplaceText() const
        {
            return m_replaceText;
        }
        void ReplaceTextRequest::setReplaceText(std::shared_ptr<ReplaceTextParameters> replaceText){
            m_replaceText = std::move(replaceText);
        }
        boost::optional<utility::string_t> ReplaceTextRequest::getFolder() const
        {
            return m_folder;
        }
        void ReplaceTextRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> ReplaceTextRequest::getStorage() const
        {
            return m_storage;
        }
        void ReplaceTextRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> ReplaceTextRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void ReplaceTextRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> ReplaceTextRequest::getPassword() const
        {
            return m_password;
        }
        void ReplaceTextRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> ReplaceTextRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void ReplaceTextRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> ReplaceTextRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void ReplaceTextRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> ReplaceTextRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void ReplaceTextRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ReplaceWithTextRequest.cpp">
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
#include "ReplaceWithTextRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
ReplaceWithTextRequest::ReplaceWithTextRequest(
        utility::string_t name,
                utility::string_t rangeStartIdentifier,
                std::shared_ptr<ReplaceRange> rangeText,
                boost::optional<utility::string_t> rangeEndIdentifier,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName
        ) : 
            m_name(std::move(name)),
            m_rangeStartIdentifier(std::move(rangeStartIdentifier)),
            m_rangeText(std::move(rangeText)),
            m_rangeEndIdentifier(std::move(rangeEndIdentifier)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName))
        {
            
        }

        utility::string_t ReplaceWithTextRequest::getName() const
        {
            return m_name;
        }
        void ReplaceWithTextRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t ReplaceWithTextRequest::getRangeStartIdentifier() const
        {
            return m_rangeStartIdentifier;
        }
        void ReplaceWithTextRequest::setRangeStartIdentifier(utility::string_t rangeStartIdentifier){
            m_rangeStartIdentifier = std::move(rangeStartIdentifier);
        }
        std::shared_ptr<ReplaceRange> ReplaceWithTextRequest::getRangeText() const
        {
            return m_rangeText;
        }
        void ReplaceWithTextRequest::setRangeText(std::shared_ptr<ReplaceRange> rangeText){
            m_rangeText = std::move(rangeText);
        }
        boost::optional<utility::string_t> ReplaceWithTextRequest::getRangeEndIdentifier() const
        {
            return m_rangeEndIdentifier;
        }
        void ReplaceWithTextRequest::setRangeEndIdentifier(boost::optional<utility::string_t> rangeEndIdentifier){
            m_rangeEndIdentifier = std::move(rangeEndIdentifier);
        }
        boost::optional<utility::string_t> ReplaceWithTextRequest::getFolder() const
        {
            return m_folder;
        }
        void ReplaceWithTextRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> ReplaceWithTextRequest::getStorage() const
        {
            return m_storage;
        }
        void ReplaceWithTextRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> ReplaceWithTextRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void ReplaceWithTextRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> ReplaceWithTextRequest::getPassword() const
        {
            return m_password;
        }
        void ReplaceWithTextRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> ReplaceWithTextRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void ReplaceWithTextRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ResetCacheRequest.cpp">
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
#include "ResetCacheRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
ResetCacheRequest::ResetCacheRequest(
) 
        {
            
        }


}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SaveAsRequest.cpp">
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
#include "SaveAsRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
SaveAsRequest::SaveAsRequest(
        utility::string_t name,
                std::shared_ptr<SaveOptionsData> saveOptionsData,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> fontsLocation
        ) : 
            m_name(std::move(name)),
            m_saveOptionsData(std::move(saveOptionsData)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_fontsLocation(std::move(fontsLocation))
        {
            
        }

        utility::string_t SaveAsRequest::getName() const
        {
            return m_name;
        }
        void SaveAsRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<SaveOptionsData> SaveAsRequest::getSaveOptionsData() const
        {
            return m_saveOptionsData;
        }
        void SaveAsRequest::setSaveOptionsData(std::shared_ptr<SaveOptionsData> saveOptionsData){
            m_saveOptionsData = std::move(saveOptionsData);
        }
        boost::optional<utility::string_t> SaveAsRequest::getFolder() const
        {
            return m_folder;
        }
        void SaveAsRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> SaveAsRequest::getStorage() const
        {
            return m_storage;
        }
        void SaveAsRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> SaveAsRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void SaveAsRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> SaveAsRequest::getPassword() const
        {
            return m_password;
        }
        void SaveAsRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> SaveAsRequest::getFontsLocation() const
        {
            return m_fontsLocation;
        }
        void SaveAsRequest::setFontsLocation(boost::optional<utility::string_t> fontsLocation){
            m_fontsLocation = std::move(fontsLocation);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SaveAsRangeRequest.cpp">
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
#include "SaveAsRangeRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
SaveAsRangeRequest::SaveAsRangeRequest(
        utility::string_t name,
                utility::string_t rangeStartIdentifier,
                std::shared_ptr<RangeDocument> documentParameters,
                boost::optional<utility::string_t> rangeEndIdentifier,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(std::move(name)),
            m_rangeStartIdentifier(std::move(rangeStartIdentifier)),
            m_documentParameters(std::move(documentParameters)),
            m_rangeEndIdentifier(std::move(rangeEndIdentifier)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password))
        {
            
        }

        utility::string_t SaveAsRangeRequest::getName() const
        {
            return m_name;
        }
        void SaveAsRangeRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t SaveAsRangeRequest::getRangeStartIdentifier() const
        {
            return m_rangeStartIdentifier;
        }
        void SaveAsRangeRequest::setRangeStartIdentifier(utility::string_t rangeStartIdentifier){
            m_rangeStartIdentifier = std::move(rangeStartIdentifier);
        }
        std::shared_ptr<RangeDocument> SaveAsRangeRequest::getDocumentParameters() const
        {
            return m_documentParameters;
        }
        void SaveAsRangeRequest::setDocumentParameters(std::shared_ptr<RangeDocument> documentParameters){
            m_documentParameters = std::move(documentParameters);
        }
        boost::optional<utility::string_t> SaveAsRangeRequest::getRangeEndIdentifier() const
        {
            return m_rangeEndIdentifier;
        }
        void SaveAsRangeRequest::setRangeEndIdentifier(boost::optional<utility::string_t> rangeEndIdentifier){
            m_rangeEndIdentifier = std::move(rangeEndIdentifier);
        }
        boost::optional<utility::string_t> SaveAsRangeRequest::getFolder() const
        {
            return m_folder;
        }
        void SaveAsRangeRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> SaveAsRangeRequest::getStorage() const
        {
            return m_storage;
        }
        void SaveAsRangeRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> SaveAsRangeRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void SaveAsRangeRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> SaveAsRangeRequest::getPassword() const
        {
            return m_password;
        }
        void SaveAsRangeRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SaveAsTiffRequest.cpp">
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
#include "SaveAsTiffRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
SaveAsTiffRequest::SaveAsTiffRequest(
        utility::string_t name,
                std::shared_ptr<TiffSaveOptionsData> saveOptions,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<bool> useAntiAliasing,
                boost::optional<bool> useHighQualityRendering,
                boost::optional<double> imageBrightness,
                boost::optional<utility::string_t> imageColorMode,
                boost::optional<double> imageContrast,
                boost::optional<utility::string_t> numeralFormat,
                boost::optional<int32_t> pageCount,
                boost::optional<int32_t> pageIndex,
                boost::optional<utility::string_t> paperColor,
                boost::optional<utility::string_t> pixelFormat,
                boost::optional<double> resolution,
                boost::optional<double> scale,
                boost::optional<utility::string_t> tiffCompression,
                boost::optional<utility::string_t> dmlRenderingMode,
                boost::optional<utility::string_t> dmlEffectsRenderingMode,
                boost::optional<utility::string_t> tiffBinarizationMethod,
                boost::optional<bool> zipOutput,
                boost::optional<utility::string_t> fontsLocation
        ) : 
            m_name(std::move(name)),
            m_saveOptions(std::move(saveOptions)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_useAntiAliasing(std::move(useAntiAliasing)),
            m_useHighQualityRendering(std::move(useHighQualityRendering)),
            m_imageBrightness(std::move(imageBrightness)),
            m_imageColorMode(std::move(imageColorMode)),
            m_imageContrast(std::move(imageContrast)),
            m_numeralFormat(std::move(numeralFormat)),
            m_pageCount(std::move(pageCount)),
            m_pageIndex(std::move(pageIndex)),
            m_paperColor(std::move(paperColor)),
            m_pixelFormat(std::move(pixelFormat)),
            m_resolution(std::move(resolution)),
            m_scale(std::move(scale)),
            m_tiffCompression(std::move(tiffCompression)),
            m_dmlRenderingMode(std::move(dmlRenderingMode)),
            m_dmlEffectsRenderingMode(std::move(dmlEffectsRenderingMode)),
            m_tiffBinarizationMethod(std::move(tiffBinarizationMethod)),
            m_zipOutput(std::move(zipOutput)),
            m_fontsLocation(std::move(fontsLocation))
        {
            
        }

        utility::string_t SaveAsTiffRequest::getName() const
        {
            return m_name;
        }
        void SaveAsTiffRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<TiffSaveOptionsData> SaveAsTiffRequest::getSaveOptions() const
        {
            return m_saveOptions;
        }
        void SaveAsTiffRequest::setSaveOptions(std::shared_ptr<TiffSaveOptionsData> saveOptions){
            m_saveOptions = std::move(saveOptions);
        }
        boost::optional<utility::string_t> SaveAsTiffRequest::getFolder() const
        {
            return m_folder;
        }
        void SaveAsTiffRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> SaveAsTiffRequest::getStorage() const
        {
            return m_storage;
        }
        void SaveAsTiffRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> SaveAsTiffRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void SaveAsTiffRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> SaveAsTiffRequest::getPassword() const
        {
            return m_password;
        }
        void SaveAsTiffRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<bool> SaveAsTiffRequest::getUseAntiAliasing() const
        {
            return m_useAntiAliasing;
        }
        void SaveAsTiffRequest::setUseAntiAliasing(boost::optional<bool> useAntiAliasing){
            m_useAntiAliasing = std::move(useAntiAliasing);
        }
        boost::optional<bool> SaveAsTiffRequest::getUseHighQualityRendering() const
        {
            return m_useHighQualityRendering;
        }
        void SaveAsTiffRequest::setUseHighQualityRendering(boost::optional<bool> useHighQualityRendering){
            m_useHighQualityRendering = std::move(useHighQualityRendering);
        }
        boost::optional<double> SaveAsTiffRequest::getImageBrightness() const
        {
            return m_imageBrightness;
        }
        void SaveAsTiffRequest::setImageBrightness(boost::optional<double> imageBrightness){
            m_imageBrightness = std::move(imageBrightness);
        }
        boost::optional<utility::string_t> SaveAsTiffRequest::getImageColorMode() const
        {
            return m_imageColorMode;
        }
        void SaveAsTiffRequest::setImageColorMode(boost::optional<utility::string_t> imageColorMode){
            m_imageColorMode = std::move(imageColorMode);
        }
        boost::optional<double> SaveAsTiffRequest::getImageContrast() const
        {
            return m_imageContrast;
        }
        void SaveAsTiffRequest::setImageContrast(boost::optional<double> imageContrast){
            m_imageContrast = std::move(imageContrast);
        }
        boost::optional<utility::string_t> SaveAsTiffRequest::getNumeralFormat() const
        {
            return m_numeralFormat;
        }
        void SaveAsTiffRequest::setNumeralFormat(boost::optional<utility::string_t> numeralFormat){
            m_numeralFormat = std::move(numeralFormat);
        }
        boost::optional<int32_t> SaveAsTiffRequest::getPageCount() const
        {
            return m_pageCount;
        }
        void SaveAsTiffRequest::setPageCount(boost::optional<int32_t> pageCount){
            m_pageCount = std::move(pageCount);
        }
        boost::optional<int32_t> SaveAsTiffRequest::getPageIndex() const
        {
            return m_pageIndex;
        }
        void SaveAsTiffRequest::setPageIndex(boost::optional<int32_t> pageIndex){
            m_pageIndex = std::move(pageIndex);
        }
        boost::optional<utility::string_t> SaveAsTiffRequest::getPaperColor() const
        {
            return m_paperColor;
        }
        void SaveAsTiffRequest::setPaperColor(boost::optional<utility::string_t> paperColor){
            m_paperColor = std::move(paperColor);
        }
        boost::optional<utility::string_t> SaveAsTiffRequest::getPixelFormat() const
        {
            return m_pixelFormat;
        }
        void SaveAsTiffRequest::setPixelFormat(boost::optional<utility::string_t> pixelFormat){
            m_pixelFormat = std::move(pixelFormat);
        }
        boost::optional<double> SaveAsTiffRequest::getResolution() const
        {
            return m_resolution;
        }
        void SaveAsTiffRequest::setResolution(boost::optional<double> resolution){
            m_resolution = std::move(resolution);
        }
        boost::optional<double> SaveAsTiffRequest::getScale() const
        {
            return m_scale;
        }
        void SaveAsTiffRequest::setScale(boost::optional<double> scale){
            m_scale = std::move(scale);
        }
        boost::optional<utility::string_t> SaveAsTiffRequest::getTiffCompression() const
        {
            return m_tiffCompression;
        }
        void SaveAsTiffRequest::setTiffCompression(boost::optional<utility::string_t> tiffCompression){
            m_tiffCompression = std::move(tiffCompression);
        }
        boost::optional<utility::string_t> SaveAsTiffRequest::getDmlRenderingMode() const
        {
            return m_dmlRenderingMode;
        }
        void SaveAsTiffRequest::setDmlRenderingMode(boost::optional<utility::string_t> dmlRenderingMode){
            m_dmlRenderingMode = std::move(dmlRenderingMode);
        }
        boost::optional<utility::string_t> SaveAsTiffRequest::getDmlEffectsRenderingMode() const
        {
            return m_dmlEffectsRenderingMode;
        }
        void SaveAsTiffRequest::setDmlEffectsRenderingMode(boost::optional<utility::string_t> dmlEffectsRenderingMode){
            m_dmlEffectsRenderingMode = std::move(dmlEffectsRenderingMode);
        }
        boost::optional<utility::string_t> SaveAsTiffRequest::getTiffBinarizationMethod() const
        {
            return m_tiffBinarizationMethod;
        }
        void SaveAsTiffRequest::setTiffBinarizationMethod(boost::optional<utility::string_t> tiffBinarizationMethod){
            m_tiffBinarizationMethod = std::move(tiffBinarizationMethod);
        }
        boost::optional<bool> SaveAsTiffRequest::getZipOutput() const
        {
            return m_zipOutput;
        }
        void SaveAsTiffRequest::setZipOutput(boost::optional<bool> zipOutput){
            m_zipOutput = std::move(zipOutput);
        }
        boost::optional<utility::string_t> SaveAsTiffRequest::getFontsLocation() const
        {
            return m_fontsLocation;
        }
        void SaveAsTiffRequest::setFontsLocation(boost::optional<utility::string_t> fontsLocation){
            m_fontsLocation = std::move(fontsLocation);
        }

}
}
}
}
}

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
        utility::string_t name,
                utility::string_t pattern,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(std::move(name)),
            m_pattern(std::move(pattern)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password))
        {
            
        }

        utility::string_t SearchRequest::getName() const
        {
            return m_name;
        }
        void SearchRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t SearchRequest::getPattern() const
        {
            return m_pattern;
        }
        void SearchRequest::setPattern(utility::string_t pattern){
            m_pattern = std::move(pattern);
        }
        boost::optional<utility::string_t> SearchRequest::getFolder() const
        {
            return m_folder;
        }
        void SearchRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> SearchRequest::getStorage() const
        {
            return m_storage;
        }
        void SearchRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> SearchRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void SearchRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> SearchRequest::getPassword() const
        {
            return m_password;
        }
        void SearchRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SplitDocumentRequest.cpp">
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
#include "SplitDocumentRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
SplitDocumentRequest::SplitDocumentRequest(
        utility::string_t name,
                utility::string_t format,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<int32_t> from,
                boost::optional<int32_t> to,
                boost::optional<bool> zipOutput,
                boost::optional<utility::string_t> fontsLocation
        ) : 
            m_name(std::move(name)),
            m_format(std::move(format)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_from(std::move(from)),
            m_to(std::move(to)),
            m_zipOutput(std::move(zipOutput)),
            m_fontsLocation(std::move(fontsLocation))
        {
            
        }

        utility::string_t SplitDocumentRequest::getName() const
        {
            return m_name;
        }
        void SplitDocumentRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t SplitDocumentRequest::getFormat() const
        {
            return m_format;
        }
        void SplitDocumentRequest::setFormat(utility::string_t format){
            m_format = std::move(format);
        }
        boost::optional<utility::string_t> SplitDocumentRequest::getFolder() const
        {
            return m_folder;
        }
        void SplitDocumentRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> SplitDocumentRequest::getStorage() const
        {
            return m_storage;
        }
        void SplitDocumentRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> SplitDocumentRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void SplitDocumentRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> SplitDocumentRequest::getPassword() const
        {
            return m_password;
        }
        void SplitDocumentRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> SplitDocumentRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void SplitDocumentRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<int32_t> SplitDocumentRequest::getFrom() const
        {
            return m_from;
        }
        void SplitDocumentRequest::setFrom(boost::optional<int32_t> from){
            m_from = std::move(from);
        }
        boost::optional<int32_t> SplitDocumentRequest::getTo() const
        {
            return m_to;
        }
        void SplitDocumentRequest::setTo(boost::optional<int32_t> to){
            m_to = std::move(to);
        }
        boost::optional<bool> SplitDocumentRequest::getZipOutput() const
        {
            return m_zipOutput;
        }
        void SplitDocumentRequest::setZipOutput(boost::optional<bool> zipOutput){
            m_zipOutput = std::move(zipOutput);
        }
        boost::optional<utility::string_t> SplitDocumentRequest::getFontsLocation() const
        {
            return m_fontsLocation;
        }
        void SplitDocumentRequest::setFontsLocation(boost::optional<utility::string_t> fontsLocation){
            m_fontsLocation = std::move(fontsLocation);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UnprotectDocumentRequest.cpp">
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
#include "UnprotectDocumentRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UnprotectDocumentRequest::UnprotectDocumentRequest(
        utility::string_t name,
                std::shared_ptr<ProtectionRequest> protectionRequest,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName
        ) : 
            m_name(std::move(name)),
            m_protectionRequest(std::move(protectionRequest)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName))
        {
            
        }

        utility::string_t UnprotectDocumentRequest::getName() const
        {
            return m_name;
        }
        void UnprotectDocumentRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<ProtectionRequest> UnprotectDocumentRequest::getProtectionRequest() const
        {
            return m_protectionRequest;
        }
        void UnprotectDocumentRequest::setProtectionRequest(std::shared_ptr<ProtectionRequest> protectionRequest){
            m_protectionRequest = std::move(protectionRequest);
        }
        boost::optional<utility::string_t> UnprotectDocumentRequest::getFolder() const
        {
            return m_folder;
        }
        void UnprotectDocumentRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UnprotectDocumentRequest::getStorage() const
        {
            return m_storage;
        }
        void UnprotectDocumentRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UnprotectDocumentRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UnprotectDocumentRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UnprotectDocumentRequest::getPassword() const
        {
            return m_password;
        }
        void UnprotectDocumentRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UnprotectDocumentRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UnprotectDocumentRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateBookmarkRequest.cpp">
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
#include "UpdateBookmarkRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateBookmarkRequest::UpdateBookmarkRequest(
        utility::string_t name,
                std::shared_ptr<BookmarkData> bookmarkData,
                utility::string_t bookmarkName,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_bookmarkData(std::move(bookmarkData)),
            m_bookmarkName(std::move(bookmarkName)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateBookmarkRequest::getName() const
        {
            return m_name;
        }
        void UpdateBookmarkRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<BookmarkData> UpdateBookmarkRequest::getBookmarkData() const
        {
            return m_bookmarkData;
        }
        void UpdateBookmarkRequest::setBookmarkData(std::shared_ptr<BookmarkData> bookmarkData){
            m_bookmarkData = std::move(bookmarkData);
        }
        utility::string_t UpdateBookmarkRequest::getBookmarkName() const
        {
            return m_bookmarkName;
        }
        void UpdateBookmarkRequest::setBookmarkName(utility::string_t bookmarkName){
            m_bookmarkName = std::move(bookmarkName);
        }
        boost::optional<utility::string_t> UpdateBookmarkRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateBookmarkRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateBookmarkRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateBookmarkRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateBookmarkRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateBookmarkRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateBookmarkRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateBookmarkRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateBookmarkRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateBookmarkRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateBookmarkRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateBookmarkRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateBookmarkRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateBookmarkRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateBorderRequest.cpp">
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
#include "UpdateBorderRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateBorderRequest::UpdateBorderRequest(
        utility::string_t name,
                std::shared_ptr<Border> borderProperties,
                utility::string_t nodePath,
                utility::string_t borderType,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_borderProperties(std::move(borderProperties)),
            m_nodePath(std::move(nodePath)),
            m_borderType(std::move(borderType)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateBorderRequest::getName() const
        {
            return m_name;
        }
        void UpdateBorderRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<Border> UpdateBorderRequest::getBorderProperties() const
        {
            return m_borderProperties;
        }
        void UpdateBorderRequest::setBorderProperties(std::shared_ptr<Border> borderProperties){
            m_borderProperties = std::move(borderProperties);
        }
        utility::string_t UpdateBorderRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void UpdateBorderRequest::setNodePath(utility::string_t nodePath){
            m_nodePath = std::move(nodePath);
        }
        utility::string_t UpdateBorderRequest::getBorderType() const
        {
            return m_borderType;
        }
        void UpdateBorderRequest::setBorderType(utility::string_t borderType){
            m_borderType = std::move(borderType);
        }
        boost::optional<utility::string_t> UpdateBorderRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateBorderRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateBorderRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateBorderRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateBorderRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateBorderRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateBorderRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateBorderRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateBorderRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateBorderRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateBorderRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateBorderRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateBorderRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateBorderRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateCommentRequest.cpp">
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
#include "UpdateCommentRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateCommentRequest::UpdateCommentRequest(
        utility::string_t name,
                int32_t commentIndex,
                std::shared_ptr<CommentUpdate> comment,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_commentIndex(std::move(commentIndex)),
            m_comment(std::move(comment)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateCommentRequest::getName() const
        {
            return m_name;
        }
        void UpdateCommentRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        int32_t UpdateCommentRequest::getCommentIndex() const
        {
            return m_commentIndex;
        }
        void UpdateCommentRequest::setCommentIndex(int32_t commentIndex){
            m_commentIndex = std::move(commentIndex);
        }
        std::shared_ptr<CommentUpdate> UpdateCommentRequest::getComment() const
        {
            return m_comment;
        }
        void UpdateCommentRequest::setComment(std::shared_ptr<CommentUpdate> comment){
            m_comment = std::move(comment);
        }
        boost::optional<utility::string_t> UpdateCommentRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateCommentRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateCommentRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateCommentRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateCommentRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateCommentRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateCommentRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateCommentRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateCommentRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateCommentRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateCommentRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateCommentRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateCommentRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateCommentRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateDrawingObjectRequest.cpp">
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
#include "UpdateDrawingObjectRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateDrawingObjectRequest::UpdateDrawingObjectRequest(
        utility::string_t name,
                std::shared_ptr<DrawingObjectUpdate> drawingObject,
                std::shared_ptr<HttpContent> imageFile,
                utility::string_t nodePath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_drawingObject(std::move(drawingObject)),
            m_imageFile(std::move(imageFile)),
            m_nodePath(std::move(nodePath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateDrawingObjectRequest::getName() const
        {
            return m_name;
        }
        void UpdateDrawingObjectRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<DrawingObjectUpdate> UpdateDrawingObjectRequest::getDrawingObject() const
        {
            return m_drawingObject;
        }
        void UpdateDrawingObjectRequest::setDrawingObject(std::shared_ptr<DrawingObjectUpdate> drawingObject){
            m_drawingObject = std::move(drawingObject);
        }
        std::shared_ptr<HttpContent> UpdateDrawingObjectRequest::getImageFile() const
        {
            return m_imageFile;
        }
        void UpdateDrawingObjectRequest::setImageFile(std::shared_ptr<HttpContent> imageFile){
            m_imageFile = std::move(imageFile);
        }
        utility::string_t UpdateDrawingObjectRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void UpdateDrawingObjectRequest::setNodePath(utility::string_t nodePath){
            m_nodePath = std::move(nodePath);
        }
        int32_t UpdateDrawingObjectRequest::getIndex() const
        {
            return m_index;
        }
        void UpdateDrawingObjectRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> UpdateDrawingObjectRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateDrawingObjectRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateDrawingObjectRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateDrawingObjectRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateDrawingObjectRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateDrawingObjectRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateDrawingObjectRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateDrawingObjectRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateDrawingObjectRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateDrawingObjectRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateDrawingObjectRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateDrawingObjectRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateDrawingObjectRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateDrawingObjectRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateDrawingObjectWithoutNodePathRequest.cpp">
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
#include "UpdateDrawingObjectWithoutNodePathRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateDrawingObjectWithoutNodePathRequest::UpdateDrawingObjectWithoutNodePathRequest(
        utility::string_t name,
                std::shared_ptr<DrawingObjectUpdate> drawingObject,
                std::shared_ptr<HttpContent> imageFile,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_drawingObject(std::move(drawingObject)),
            m_imageFile(std::move(imageFile)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateDrawingObjectWithoutNodePathRequest::getName() const
        {
            return m_name;
        }
        void UpdateDrawingObjectWithoutNodePathRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<DrawingObjectUpdate> UpdateDrawingObjectWithoutNodePathRequest::getDrawingObject() const
        {
            return m_drawingObject;
        }
        void UpdateDrawingObjectWithoutNodePathRequest::setDrawingObject(std::shared_ptr<DrawingObjectUpdate> drawingObject){
            m_drawingObject = std::move(drawingObject);
        }
        std::shared_ptr<HttpContent> UpdateDrawingObjectWithoutNodePathRequest::getImageFile() const
        {
            return m_imageFile;
        }
        void UpdateDrawingObjectWithoutNodePathRequest::setImageFile(std::shared_ptr<HttpContent> imageFile){
            m_imageFile = std::move(imageFile);
        }
        int32_t UpdateDrawingObjectWithoutNodePathRequest::getIndex() const
        {
            return m_index;
        }
        void UpdateDrawingObjectWithoutNodePathRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> UpdateDrawingObjectWithoutNodePathRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateDrawingObjectWithoutNodePathRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateDrawingObjectWithoutNodePathRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateDrawingObjectWithoutNodePathRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateDrawingObjectWithoutNodePathRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateDrawingObjectWithoutNodePathRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateDrawingObjectWithoutNodePathRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateDrawingObjectWithoutNodePathRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateDrawingObjectWithoutNodePathRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateDrawingObjectWithoutNodePathRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateDrawingObjectWithoutNodePathRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateDrawingObjectWithoutNodePathRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateDrawingObjectWithoutNodePathRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateDrawingObjectWithoutNodePathRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateFieldRequest.cpp">
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
#include "UpdateFieldRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateFieldRequest::UpdateFieldRequest(
        utility::string_t name,
                std::shared_ptr<FieldUpdate> field,
                utility::string_t nodePath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_field(std::move(field)),
            m_nodePath(std::move(nodePath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateFieldRequest::getName() const
        {
            return m_name;
        }
        void UpdateFieldRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<FieldUpdate> UpdateFieldRequest::getField() const
        {
            return m_field;
        }
        void UpdateFieldRequest::setField(std::shared_ptr<FieldUpdate> field){
            m_field = std::move(field);
        }
        utility::string_t UpdateFieldRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void UpdateFieldRequest::setNodePath(utility::string_t nodePath){
            m_nodePath = std::move(nodePath);
        }
        int32_t UpdateFieldRequest::getIndex() const
        {
            return m_index;
        }
        void UpdateFieldRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> UpdateFieldRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateFieldRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateFieldRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateFieldRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateFieldRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateFieldRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateFieldRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateFieldRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateFieldRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateFieldRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateFieldRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateFieldRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateFieldRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateFieldRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateFieldsRequest.cpp">
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
#include "UpdateFieldsRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateFieldsRequest::UpdateFieldsRequest(
        utility::string_t name,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName
        ) : 
            m_name(std::move(name)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName))
        {
            
        }

        utility::string_t UpdateFieldsRequest::getName() const
        {
            return m_name;
        }
        void UpdateFieldsRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        boost::optional<utility::string_t> UpdateFieldsRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateFieldsRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateFieldsRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateFieldsRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateFieldsRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateFieldsRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateFieldsRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateFieldsRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateFieldsRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateFieldsRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateFootnoteRequest.cpp">
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
#include "UpdateFootnoteRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateFootnoteRequest::UpdateFootnoteRequest(
        utility::string_t name,
                std::shared_ptr<FootnoteUpdate> footnoteDto,
                utility::string_t nodePath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_footnoteDto(std::move(footnoteDto)),
            m_nodePath(std::move(nodePath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateFootnoteRequest::getName() const
        {
            return m_name;
        }
        void UpdateFootnoteRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<FootnoteUpdate> UpdateFootnoteRequest::getFootnoteDto() const
        {
            return m_footnoteDto;
        }
        void UpdateFootnoteRequest::setFootnoteDto(std::shared_ptr<FootnoteUpdate> footnoteDto){
            m_footnoteDto = std::move(footnoteDto);
        }
        utility::string_t UpdateFootnoteRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void UpdateFootnoteRequest::setNodePath(utility::string_t nodePath){
            m_nodePath = std::move(nodePath);
        }
        int32_t UpdateFootnoteRequest::getIndex() const
        {
            return m_index;
        }
        void UpdateFootnoteRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> UpdateFootnoteRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateFootnoteRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateFootnoteRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateFootnoteRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateFootnoteRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateFootnoteRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateFootnoteRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateFootnoteRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateFootnoteRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateFootnoteRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateFootnoteRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateFootnoteRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateFootnoteRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateFootnoteRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateFootnoteWithoutNodePathRequest.cpp">
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
#include "UpdateFootnoteWithoutNodePathRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateFootnoteWithoutNodePathRequest::UpdateFootnoteWithoutNodePathRequest(
        utility::string_t name,
                std::shared_ptr<FootnoteUpdate> footnoteDto,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_footnoteDto(std::move(footnoteDto)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateFootnoteWithoutNodePathRequest::getName() const
        {
            return m_name;
        }
        void UpdateFootnoteWithoutNodePathRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<FootnoteUpdate> UpdateFootnoteWithoutNodePathRequest::getFootnoteDto() const
        {
            return m_footnoteDto;
        }
        void UpdateFootnoteWithoutNodePathRequest::setFootnoteDto(std::shared_ptr<FootnoteUpdate> footnoteDto){
            m_footnoteDto = std::move(footnoteDto);
        }
        int32_t UpdateFootnoteWithoutNodePathRequest::getIndex() const
        {
            return m_index;
        }
        void UpdateFootnoteWithoutNodePathRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> UpdateFootnoteWithoutNodePathRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateFootnoteWithoutNodePathRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateFootnoteWithoutNodePathRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateFootnoteWithoutNodePathRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateFootnoteWithoutNodePathRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateFootnoteWithoutNodePathRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateFootnoteWithoutNodePathRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateFootnoteWithoutNodePathRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateFootnoteWithoutNodePathRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateFootnoteWithoutNodePathRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateFootnoteWithoutNodePathRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateFootnoteWithoutNodePathRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateFootnoteWithoutNodePathRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateFootnoteWithoutNodePathRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateFormFieldRequest.cpp">
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
#include "UpdateFormFieldRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateFormFieldRequest::UpdateFormFieldRequest(
        utility::string_t name,
                std::shared_ptr<FormField> formField,
                utility::string_t nodePath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_formField(std::move(formField)),
            m_nodePath(std::move(nodePath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateFormFieldRequest::getName() const
        {
            return m_name;
        }
        void UpdateFormFieldRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<FormField> UpdateFormFieldRequest::getFormField() const
        {
            return m_formField;
        }
        void UpdateFormFieldRequest::setFormField(std::shared_ptr<FormField> formField){
            m_formField = std::move(formField);
        }
        utility::string_t UpdateFormFieldRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void UpdateFormFieldRequest::setNodePath(utility::string_t nodePath){
            m_nodePath = std::move(nodePath);
        }
        int32_t UpdateFormFieldRequest::getIndex() const
        {
            return m_index;
        }
        void UpdateFormFieldRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> UpdateFormFieldRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateFormFieldRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateFormFieldRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateFormFieldRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateFormFieldRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateFormFieldRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateFormFieldRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateFormFieldRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateFormFieldRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateFormFieldRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateFormFieldRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateFormFieldRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateFormFieldRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateFormFieldRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateFormFieldWithoutNodePathRequest.cpp">
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
#include "UpdateFormFieldWithoutNodePathRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateFormFieldWithoutNodePathRequest::UpdateFormFieldWithoutNodePathRequest(
        utility::string_t name,
                std::shared_ptr<FormField> formField,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_formField(std::move(formField)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateFormFieldWithoutNodePathRequest::getName() const
        {
            return m_name;
        }
        void UpdateFormFieldWithoutNodePathRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<FormField> UpdateFormFieldWithoutNodePathRequest::getFormField() const
        {
            return m_formField;
        }
        void UpdateFormFieldWithoutNodePathRequest::setFormField(std::shared_ptr<FormField> formField){
            m_formField = std::move(formField);
        }
        int32_t UpdateFormFieldWithoutNodePathRequest::getIndex() const
        {
            return m_index;
        }
        void UpdateFormFieldWithoutNodePathRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> UpdateFormFieldWithoutNodePathRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateFormFieldWithoutNodePathRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateFormFieldWithoutNodePathRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateFormFieldWithoutNodePathRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateFormFieldWithoutNodePathRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateFormFieldWithoutNodePathRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateFormFieldWithoutNodePathRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateFormFieldWithoutNodePathRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateFormFieldWithoutNodePathRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateFormFieldWithoutNodePathRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateFormFieldWithoutNodePathRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateFormFieldWithoutNodePathRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateFormFieldWithoutNodePathRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateFormFieldWithoutNodePathRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateListRequest.cpp">
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
#include "UpdateListRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateListRequest::UpdateListRequest(
        utility::string_t name,
                std::shared_ptr<ListUpdate> listUpdate,
                int32_t listId,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_listUpdate(std::move(listUpdate)),
            m_listId(std::move(listId)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateListRequest::getName() const
        {
            return m_name;
        }
        void UpdateListRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<ListUpdate> UpdateListRequest::getListUpdate() const
        {
            return m_listUpdate;
        }
        void UpdateListRequest::setListUpdate(std::shared_ptr<ListUpdate> listUpdate){
            m_listUpdate = std::move(listUpdate);
        }
        int32_t UpdateListRequest::getListId() const
        {
            return m_listId;
        }
        void UpdateListRequest::setListId(int32_t listId){
            m_listId = std::move(listId);
        }
        boost::optional<utility::string_t> UpdateListRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateListRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateListRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateListRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateListRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateListRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateListRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateListRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateListRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateListRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateListRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateListRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateListRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateListRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateListLevelRequest.cpp">
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
#include "UpdateListLevelRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateListLevelRequest::UpdateListLevelRequest(
        utility::string_t name,
                std::shared_ptr<ListLevelUpdate> listUpdate,
                int32_t listId,
                int32_t listLevel,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_listUpdate(std::move(listUpdate)),
            m_listId(std::move(listId)),
            m_listLevel(std::move(listLevel)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateListLevelRequest::getName() const
        {
            return m_name;
        }
        void UpdateListLevelRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<ListLevelUpdate> UpdateListLevelRequest::getListUpdate() const
        {
            return m_listUpdate;
        }
        void UpdateListLevelRequest::setListUpdate(std::shared_ptr<ListLevelUpdate> listUpdate){
            m_listUpdate = std::move(listUpdate);
        }
        int32_t UpdateListLevelRequest::getListId() const
        {
            return m_listId;
        }
        void UpdateListLevelRequest::setListId(int32_t listId){
            m_listId = std::move(listId);
        }
        int32_t UpdateListLevelRequest::getListLevel() const
        {
            return m_listLevel;
        }
        void UpdateListLevelRequest::setListLevel(int32_t listLevel){
            m_listLevel = std::move(listLevel);
        }
        boost::optional<utility::string_t> UpdateListLevelRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateListLevelRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateListLevelRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateListLevelRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateListLevelRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateListLevelRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateListLevelRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateListLevelRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateListLevelRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateListLevelRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateListLevelRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateListLevelRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateListLevelRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateListLevelRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateParagraphFormatRequest.cpp">
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
#include "UpdateParagraphFormatRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateParagraphFormatRequest::UpdateParagraphFormatRequest(
        utility::string_t name,
                std::shared_ptr<ParagraphFormat> dto,
                utility::string_t nodePath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_dto(std::move(dto)),
            m_nodePath(std::move(nodePath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateParagraphFormatRequest::getName() const
        {
            return m_name;
        }
        void UpdateParagraphFormatRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<ParagraphFormat> UpdateParagraphFormatRequest::getDto() const
        {
            return m_dto;
        }
        void UpdateParagraphFormatRequest::setDto(std::shared_ptr<ParagraphFormat> dto){
            m_dto = std::move(dto);
        }
        utility::string_t UpdateParagraphFormatRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void UpdateParagraphFormatRequest::setNodePath(utility::string_t nodePath){
            m_nodePath = std::move(nodePath);
        }
        int32_t UpdateParagraphFormatRequest::getIndex() const
        {
            return m_index;
        }
        void UpdateParagraphFormatRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> UpdateParagraphFormatRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateParagraphFormatRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateParagraphFormatRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateParagraphFormatRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateParagraphFormatRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateParagraphFormatRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateParagraphFormatRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateParagraphFormatRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateParagraphFormatRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateParagraphFormatRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateParagraphFormatRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateParagraphFormatRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateParagraphFormatRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateParagraphFormatRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateParagraphFormatWithoutNodePathRequest.cpp">
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
#include "UpdateParagraphFormatWithoutNodePathRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateParagraphFormatWithoutNodePathRequest::UpdateParagraphFormatWithoutNodePathRequest(
        utility::string_t name,
                std::shared_ptr<ParagraphFormat> dto,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_dto(std::move(dto)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateParagraphFormatWithoutNodePathRequest::getName() const
        {
            return m_name;
        }
        void UpdateParagraphFormatWithoutNodePathRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<ParagraphFormat> UpdateParagraphFormatWithoutNodePathRequest::getDto() const
        {
            return m_dto;
        }
        void UpdateParagraphFormatWithoutNodePathRequest::setDto(std::shared_ptr<ParagraphFormat> dto){
            m_dto = std::move(dto);
        }
        int32_t UpdateParagraphFormatWithoutNodePathRequest::getIndex() const
        {
            return m_index;
        }
        void UpdateParagraphFormatWithoutNodePathRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> UpdateParagraphFormatWithoutNodePathRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateParagraphFormatWithoutNodePathRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateParagraphFormatWithoutNodePathRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateParagraphFormatWithoutNodePathRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateParagraphFormatWithoutNodePathRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateParagraphFormatWithoutNodePathRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateParagraphFormatWithoutNodePathRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateParagraphFormatWithoutNodePathRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateParagraphFormatWithoutNodePathRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateParagraphFormatWithoutNodePathRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateParagraphFormatWithoutNodePathRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateParagraphFormatWithoutNodePathRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateParagraphFormatWithoutNodePathRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateParagraphFormatWithoutNodePathRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateParagraphListFormatRequest.cpp">
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
#include "UpdateParagraphListFormatRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateParagraphListFormatRequest::UpdateParagraphListFormatRequest(
        utility::string_t name,
                std::shared_ptr<ListFormatUpdate> dto,
                utility::string_t nodePath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_dto(std::move(dto)),
            m_nodePath(std::move(nodePath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateParagraphListFormatRequest::getName() const
        {
            return m_name;
        }
        void UpdateParagraphListFormatRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<ListFormatUpdate> UpdateParagraphListFormatRequest::getDto() const
        {
            return m_dto;
        }
        void UpdateParagraphListFormatRequest::setDto(std::shared_ptr<ListFormatUpdate> dto){
            m_dto = std::move(dto);
        }
        utility::string_t UpdateParagraphListFormatRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void UpdateParagraphListFormatRequest::setNodePath(utility::string_t nodePath){
            m_nodePath = std::move(nodePath);
        }
        int32_t UpdateParagraphListFormatRequest::getIndex() const
        {
            return m_index;
        }
        void UpdateParagraphListFormatRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> UpdateParagraphListFormatRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateParagraphListFormatRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateParagraphListFormatRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateParagraphListFormatRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateParagraphListFormatRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateParagraphListFormatRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateParagraphListFormatRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateParagraphListFormatRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateParagraphListFormatRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateParagraphListFormatRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateParagraphListFormatRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateParagraphListFormatRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateParagraphListFormatRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateParagraphListFormatRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateParagraphListFormatWithoutNodePathRequest.cpp">
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
#include "UpdateParagraphListFormatWithoutNodePathRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateParagraphListFormatWithoutNodePathRequest::UpdateParagraphListFormatWithoutNodePathRequest(
        utility::string_t name,
                std::shared_ptr<ListFormatUpdate> dto,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_dto(std::move(dto)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateParagraphListFormatWithoutNodePathRequest::getName() const
        {
            return m_name;
        }
        void UpdateParagraphListFormatWithoutNodePathRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<ListFormatUpdate> UpdateParagraphListFormatWithoutNodePathRequest::getDto() const
        {
            return m_dto;
        }
        void UpdateParagraphListFormatWithoutNodePathRequest::setDto(std::shared_ptr<ListFormatUpdate> dto){
            m_dto = std::move(dto);
        }
        int32_t UpdateParagraphListFormatWithoutNodePathRequest::getIndex() const
        {
            return m_index;
        }
        void UpdateParagraphListFormatWithoutNodePathRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> UpdateParagraphListFormatWithoutNodePathRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateParagraphListFormatWithoutNodePathRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateParagraphListFormatWithoutNodePathRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateParagraphListFormatWithoutNodePathRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateParagraphListFormatWithoutNodePathRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateParagraphListFormatWithoutNodePathRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateParagraphListFormatWithoutNodePathRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateParagraphListFormatWithoutNodePathRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateParagraphListFormatWithoutNodePathRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateParagraphListFormatWithoutNodePathRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateParagraphListFormatWithoutNodePathRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateParagraphListFormatWithoutNodePathRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateParagraphListFormatWithoutNodePathRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateParagraphListFormatWithoutNodePathRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateRunRequest.cpp">
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
#include "UpdateRunRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateRunRequest::UpdateRunRequest(
        utility::string_t name,
                std::shared_ptr<RunUpdate> run,
                utility::string_t paragraphPath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_run(std::move(run)),
            m_paragraphPath(std::move(paragraphPath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateRunRequest::getName() const
        {
            return m_name;
        }
        void UpdateRunRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<RunUpdate> UpdateRunRequest::getRun() const
        {
            return m_run;
        }
        void UpdateRunRequest::setRun(std::shared_ptr<RunUpdate> run){
            m_run = std::move(run);
        }
        utility::string_t UpdateRunRequest::getParagraphPath() const
        {
            return m_paragraphPath;
        }
        void UpdateRunRequest::setParagraphPath(utility::string_t paragraphPath){
            m_paragraphPath = std::move(paragraphPath);
        }
        int32_t UpdateRunRequest::getIndex() const
        {
            return m_index;
        }
        void UpdateRunRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> UpdateRunRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateRunRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateRunRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateRunRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateRunRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateRunRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateRunRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateRunRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateRunRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateRunRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateRunRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateRunRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateRunRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateRunRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateRunFontRequest.cpp">
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
#include "UpdateRunFontRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateRunFontRequest::UpdateRunFontRequest(
        utility::string_t name,
                std::shared_ptr<Font> fontDto,
                utility::string_t paragraphPath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_fontDto(std::move(fontDto)),
            m_paragraphPath(std::move(paragraphPath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateRunFontRequest::getName() const
        {
            return m_name;
        }
        void UpdateRunFontRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<Font> UpdateRunFontRequest::getFontDto() const
        {
            return m_fontDto;
        }
        void UpdateRunFontRequest::setFontDto(std::shared_ptr<Font> fontDto){
            m_fontDto = std::move(fontDto);
        }
        utility::string_t UpdateRunFontRequest::getParagraphPath() const
        {
            return m_paragraphPath;
        }
        void UpdateRunFontRequest::setParagraphPath(utility::string_t paragraphPath){
            m_paragraphPath = std::move(paragraphPath);
        }
        int32_t UpdateRunFontRequest::getIndex() const
        {
            return m_index;
        }
        void UpdateRunFontRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> UpdateRunFontRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateRunFontRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateRunFontRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateRunFontRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateRunFontRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateRunFontRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateRunFontRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateRunFontRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateRunFontRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateRunFontRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateRunFontRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateRunFontRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateRunFontRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateRunFontRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateSectionPageSetupRequest.cpp">
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
#include "UpdateSectionPageSetupRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateSectionPageSetupRequest::UpdateSectionPageSetupRequest(
        utility::string_t name,
                int32_t sectionIndex,
                std::shared_ptr<PageSetup> pageSetup,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_sectionIndex(std::move(sectionIndex)),
            m_pageSetup(std::move(pageSetup)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateSectionPageSetupRequest::getName() const
        {
            return m_name;
        }
        void UpdateSectionPageSetupRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        int32_t UpdateSectionPageSetupRequest::getSectionIndex() const
        {
            return m_sectionIndex;
        }
        void UpdateSectionPageSetupRequest::setSectionIndex(int32_t sectionIndex){
            m_sectionIndex = std::move(sectionIndex);
        }
        std::shared_ptr<PageSetup> UpdateSectionPageSetupRequest::getPageSetup() const
        {
            return m_pageSetup;
        }
        void UpdateSectionPageSetupRequest::setPageSetup(std::shared_ptr<PageSetup> pageSetup){
            m_pageSetup = std::move(pageSetup);
        }
        boost::optional<utility::string_t> UpdateSectionPageSetupRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateSectionPageSetupRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateSectionPageSetupRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateSectionPageSetupRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateSectionPageSetupRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateSectionPageSetupRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateSectionPageSetupRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateSectionPageSetupRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateSectionPageSetupRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateSectionPageSetupRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateSectionPageSetupRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateSectionPageSetupRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateSectionPageSetupRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateSectionPageSetupRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateStyleRequest.cpp">
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
#include "UpdateStyleRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateStyleRequest::UpdateStyleRequest(
        utility::string_t name,
                std::shared_ptr<StyleUpdate> styleUpdate,
                utility::string_t styleName,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_styleUpdate(std::move(styleUpdate)),
            m_styleName(std::move(styleName)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateStyleRequest::getName() const
        {
            return m_name;
        }
        void UpdateStyleRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<StyleUpdate> UpdateStyleRequest::getStyleUpdate() const
        {
            return m_styleUpdate;
        }
        void UpdateStyleRequest::setStyleUpdate(std::shared_ptr<StyleUpdate> styleUpdate){
            m_styleUpdate = std::move(styleUpdate);
        }
        utility::string_t UpdateStyleRequest::getStyleName() const
        {
            return m_styleName;
        }
        void UpdateStyleRequest::setStyleName(utility::string_t styleName){
            m_styleName = std::move(styleName);
        }
        boost::optional<utility::string_t> UpdateStyleRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateStyleRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateStyleRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateStyleRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateStyleRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateStyleRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateStyleRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateStyleRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateStyleRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateStyleRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateStyleRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateStyleRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateStyleRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateStyleRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateTableCellFormatRequest.cpp">
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
#include "UpdateTableCellFormatRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateTableCellFormatRequest::UpdateTableCellFormatRequest(
        utility::string_t name,
        std::shared_ptr<TableCellFormat> format,
        utility::string_t tableRowPath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_format(std::move(format)),
            m_tableRowPath(std::move(tableRowPath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateTableCellFormatRequest::getName() const
        {
            return m_name;
        }
        void UpdateTableCellFormatRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<TableCellFormat> UpdateTableCellFormatRequest::getFormat() const
        {
            return m_format;
        }
        void UpdateTableCellFormatRequest::setFormat(std::shared_ptr<TableCellFormat> format){
            m_format = std::move(format);
        }
        utility::string_t UpdateTableCellFormatRequest::getTableRowPath() const
        {
            return m_tableRowPath;
        }
        void UpdateTableCellFormatRequest::setTableRowPath(utility::string_t tableRowPath){
            m_tableRowPath = std::move(tableRowPath);
        }
        int32_t UpdateTableCellFormatRequest::getIndex() const
        {
            return m_index;
        }
        void UpdateTableCellFormatRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> UpdateTableCellFormatRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateTableCellFormatRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateTableCellFormatRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateTableCellFormatRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateTableCellFormatRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateTableCellFormatRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateTableCellFormatRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateTableCellFormatRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateTableCellFormatRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateTableCellFormatRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateTableCellFormatRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateTableCellFormatRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateTableCellFormatRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateTableCellFormatRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateTablePropertiesRequest.cpp">
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
#include "UpdateTablePropertiesRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateTablePropertiesRequest::UpdateTablePropertiesRequest(
        utility::string_t name,
        std::shared_ptr<TableProperties> properties,
        utility::string_t nodePath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_properties(std::move(properties)),
            m_nodePath(std::move(nodePath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateTablePropertiesRequest::getName() const
        {
            return m_name;
        }
        void UpdateTablePropertiesRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<TableProperties> UpdateTablePropertiesRequest::getProperties() const
        {
            return m_properties;
        }
        void UpdateTablePropertiesRequest::setProperties(std::shared_ptr<TableProperties> properties){
            m_properties = std::move(properties);
        }
        utility::string_t UpdateTablePropertiesRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void UpdateTablePropertiesRequest::setNodePath(utility::string_t nodePath){
            m_nodePath = std::move(nodePath);
        }
        int32_t UpdateTablePropertiesRequest::getIndex() const
        {
            return m_index;
        }
        void UpdateTablePropertiesRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> UpdateTablePropertiesRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateTablePropertiesRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateTablePropertiesRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateTablePropertiesRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateTablePropertiesRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateTablePropertiesRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateTablePropertiesRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateTablePropertiesRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateTablePropertiesRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateTablePropertiesRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateTablePropertiesRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateTablePropertiesRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateTablePropertiesRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateTablePropertiesRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateTablePropertiesWithoutNodePathRequest.cpp">
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
#include "UpdateTablePropertiesWithoutNodePathRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateTablePropertiesWithoutNodePathRequest::UpdateTablePropertiesWithoutNodePathRequest(
        utility::string_t name,
        std::shared_ptr<TableProperties> properties,
        int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_properties(std::move(properties)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateTablePropertiesWithoutNodePathRequest::getName() const
        {
            return m_name;
        }
        void UpdateTablePropertiesWithoutNodePathRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<TableProperties> UpdateTablePropertiesWithoutNodePathRequest::getProperties() const
        {
            return m_properties;
        }
        void UpdateTablePropertiesWithoutNodePathRequest::setProperties(std::shared_ptr<TableProperties> properties){
            m_properties = std::move(properties);
        }
        int32_t UpdateTablePropertiesWithoutNodePathRequest::getIndex() const
        {
            return m_index;
        }
        void UpdateTablePropertiesWithoutNodePathRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> UpdateTablePropertiesWithoutNodePathRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateTablePropertiesWithoutNodePathRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateTablePropertiesWithoutNodePathRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateTablePropertiesWithoutNodePathRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateTablePropertiesWithoutNodePathRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateTablePropertiesWithoutNodePathRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateTablePropertiesWithoutNodePathRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateTablePropertiesWithoutNodePathRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateTablePropertiesWithoutNodePathRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateTablePropertiesWithoutNodePathRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateTablePropertiesWithoutNodePathRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateTablePropertiesWithoutNodePathRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateTablePropertiesWithoutNodePathRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateTablePropertiesWithoutNodePathRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateTableRowFormatRequest.cpp">
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
#include "UpdateTableRowFormatRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateTableRowFormatRequest::UpdateTableRowFormatRequest(
        utility::string_t name,
        std::shared_ptr<TableRowFormat> format,
        utility::string_t tablePath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_format(std::move(format)),
            m_tablePath(std::move(tablePath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateTableRowFormatRequest::getName() const
        {
            return m_name;
        }
        void UpdateTableRowFormatRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<TableRowFormat> UpdateTableRowFormatRequest::getFormat() const
        {
            return m_format;
        }
        void UpdateTableRowFormatRequest::setFormat(std::shared_ptr<TableRowFormat> format){
            m_format = std::move(format);
        }
        utility::string_t UpdateTableRowFormatRequest::getTablePath() const
        {
            return m_tablePath;
        }
        void UpdateTableRowFormatRequest::setTablePath(utility::string_t tablePath){
            m_tablePath = std::move(tablePath);
        }
        int32_t UpdateTableRowFormatRequest::getIndex() const
        {
            return m_index;
        }
        void UpdateTableRowFormatRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> UpdateTableRowFormatRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateTableRowFormatRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateTableRowFormatRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateTableRowFormatRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateTableRowFormatRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateTableRowFormatRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateTableRowFormatRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateTableRowFormatRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateTableRowFormatRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateTableRowFormatRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateTableRowFormatRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateTableRowFormatRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateTableRowFormatRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateTableRowFormatRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UploadFileRequest.cpp">
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
#include "UploadFileRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UploadFileRequest::UploadFileRequest(
        std::shared_ptr<HttpContent> fileContent,
                utility::string_t path,
                boost::optional<utility::string_t> storageName
        ) : 
            m_fileContent(std::move(fileContent)),
            m_path(std::move(path)),
            m_storageName(std::move(storageName))
        {
            
        }

        std::shared_ptr<HttpContent> UploadFileRequest::getFileContent() const
        {
            return m_fileContent;
        }
        void UploadFileRequest::setFileContent(std::shared_ptr<HttpContent> fileContent){
            m_fileContent = std::move(fileContent);
        }
        utility::string_t UploadFileRequest::getPath() const
        {
            return m_path;
        }
        void UploadFileRequest::setPath(utility::string_t path){
            m_path = std::move(path);
        }
        boost::optional<utility::string_t> UploadFileRequest::getStorageName() const
        {
            return m_storageName;
        }
        void UploadFileRequest::setStorageName(boost::optional<utility::string_t> storageName){
            m_storageName = std::move(storageName);
        }

}
}
}
}
}

