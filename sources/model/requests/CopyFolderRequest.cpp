/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="CopyFolderRequest.cpp">
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

#include "CopyFolderRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
CopyFolderRequest::CopyFolderRequest(
    utility::string_t destPath,
    utility::string_t srcPath,
    boost::optional< utility::string_t > srcStorageName,
    boost::optional< utility::string_t > destStorageName
) : m_DestPath(std::move(destPath)),
m_SrcPath(std::move(srcPath)),
m_SrcStorageName(std::move(srcStorageName)),
m_DestStorageName(std::move(destStorageName))
{
}

utility::string_t CopyFolderRequest::getDestPath() const
{
    return m_DestPath;
}

void CopyFolderRequest::setDestPath(utility::string_t destPath)
{
    m_DestPath = std::move(destPath);
}

utility::string_t CopyFolderRequest::getSrcPath() const
{
    return m_SrcPath;
}

void CopyFolderRequest::setSrcPath(utility::string_t srcPath)
{
    m_SrcPath = std::move(srcPath);
}

boost::optional< utility::string_t > CopyFolderRequest::getSrcStorageName() const
{
    return m_SrcStorageName;
}

void CopyFolderRequest::setSrcStorageName(boost::optional< utility::string_t > srcStorageName)
{
    m_SrcStorageName = std::move(srcStorageName);
}

boost::optional< utility::string_t > CopyFolderRequest::getDestStorageName() const
{
    return m_DestStorageName;
}

void CopyFolderRequest::setDestStorageName(boost::optional< utility::string_t > destStorageName)
{
    m_DestStorageName = std::move(destStorageName);
}

}
}
}
}
}
