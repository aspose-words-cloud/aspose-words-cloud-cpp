/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ReplaceWithTextRequest.cpp">
*   Copyright (c) 2021 Aspose.Words for Cloud
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
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
ReplaceWithTextRequest::ReplaceWithTextRequest(
    utility::string_t name,
    utility::string_t rangeStartIdentifier,
    std::shared_ptr<ReplaceRange> rangeText,
    boost::optional< utility::string_t > rangeEndIdentifier,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName
) : m_Name(std::move(name)),
m_RangeStartIdentifier(std::move(rangeStartIdentifier)),
m_RangeText(std::move(rangeText)),
m_RangeEndIdentifier(std::move(rangeEndIdentifier)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName))
{
}

utility::string_t ReplaceWithTextRequest::getName() const
{
    return m_Name;
}

void ReplaceWithTextRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

utility::string_t ReplaceWithTextRequest::getRangeStartIdentifier() const
{
    return m_RangeStartIdentifier;
}

void ReplaceWithTextRequest::setRangeStartIdentifier(utility::string_t rangeStartIdentifier)
{
    m_RangeStartIdentifier = std::move(rangeStartIdentifier);
}

std::shared_ptr<ReplaceRange> ReplaceWithTextRequest::getRangeText() const
{
    return m_RangeText;
}

void ReplaceWithTextRequest::setRangeText(std::shared_ptr<ReplaceRange> rangeText)
{
    m_RangeText = std::move(rangeText);
}

boost::optional< utility::string_t > ReplaceWithTextRequest::getRangeEndIdentifier() const
{
    return m_RangeEndIdentifier;
}

void ReplaceWithTextRequest::setRangeEndIdentifier(boost::optional< utility::string_t > rangeEndIdentifier)
{
    m_RangeEndIdentifier = std::move(rangeEndIdentifier);
}

boost::optional< utility::string_t > ReplaceWithTextRequest::getFolder() const
{
    return m_Folder;
}

void ReplaceWithTextRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > ReplaceWithTextRequest::getStorage() const
{
    return m_Storage;
}

void ReplaceWithTextRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > ReplaceWithTextRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void ReplaceWithTextRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > ReplaceWithTextRequest::getPassword() const
{
    return m_Password;
}

void ReplaceWithTextRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > ReplaceWithTextRequest::getDestFileName() const
{
    return m_DestFileName;
}

void ReplaceWithTextRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

}
}
}
}
}
