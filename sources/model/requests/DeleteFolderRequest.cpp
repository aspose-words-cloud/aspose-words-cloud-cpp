/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DeleteFolderRequest.cpp">
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

#include "DeleteFolderRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
DeleteFolderRequest::DeleteFolderRequest(
    utility::string_t path,
    boost::optional< utility::string_t > storageName,
    boost::optional< bool > recursive
) : m_Path(std::move(path)),
m_StorageName(std::move(storageName)),
m_Recursive(std::move(recursive))
{
}

utility::string_t DeleteFolderRequest::getPath() const
{
    return m_Path;
}

void DeleteFolderRequest::setPath(utility::string_t path)
{
    m_Path = std::move(path);
}

boost::optional< utility::string_t > DeleteFolderRequest::getStorageName() const
{
    return m_StorageName;
}

void DeleteFolderRequest::setStorageName(boost::optional< utility::string_t > storageName)
{
    m_StorageName = std::move(storageName);
}

boost::optional< bool > DeleteFolderRequest::getRecursive() const
{
    return m_Recursive;
}

void DeleteFolderRequest::setRecursive(boost::optional< bool > recursive)
{
    m_Recursive = std::move(recursive);
}

}
}
}
}
}
