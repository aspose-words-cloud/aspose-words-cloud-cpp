/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="storage_file.h">
*   Copyright (c) 2022 Aspose.Words for Cloud
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

#pragma once
#include "./model_base.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// File or folder information.
    /// </summary>
    class StorageFile : public ModelBase
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~StorageFile() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// True if it is a folder.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsFolder() const;

        /// <summary>
        /// True if it is a folder.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsFolder(std::shared_ptr< bool > value);


        /// <summary>
        /// File or folder last modified DateTime.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getModifiedDate() const;

        /// <summary>
        /// File or folder last modified DateTime.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setModifiedDate(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// File or folder name.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getName() const;

        /// <summary>
        /// File or folder name.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// File or folder path.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getPath() const;

        /// <summary>
        /// File or folder path.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPath(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// File or folder size.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getSize() const;

        /// <summary>
        /// File or folder size.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSize(std::shared_ptr< int32_t > value);


    protected:
        std::shared_ptr< bool > m_IsFolder;
        std::shared_ptr< std::wstring > m_ModifiedDate;
        std::shared_ptr< std::wstring > m_Name;
        std::shared_ptr< std::wstring > m_Path;
        std::shared_ptr< int32_t > m_Size;
    };
}

