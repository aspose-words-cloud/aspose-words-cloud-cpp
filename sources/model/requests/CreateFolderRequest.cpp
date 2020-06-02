/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="CreateFolderRequest.cpp">
*   Copyright (c) 2020 Aspose.Words for Cloud
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

#include "CreateFolderRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
CreateFolderRequest::CreateFolderRequest(
    utility::string_t path,
    boost::optional< utility::string_t > storageName
) : m_Path(std::move(path)),
m_StorageName(std::move(storageName))
{
}

utility::string_t CreateFolderRequest::getPath() const
{
    return m_Path;
}

void CreateFolderRequest::setPath(utility::string_t path)
{
    m_Path = std::move(path);
}

boost::optional< utility::string_t > CreateFolderRequest::getStorageName() const
{
    return m_StorageName;
}

void CreateFolderRequest::setStorageName(boost::optional< utility::string_t > storageName)
{
    m_StorageName = std::move(storageName);
}

}
}
}
}
}
