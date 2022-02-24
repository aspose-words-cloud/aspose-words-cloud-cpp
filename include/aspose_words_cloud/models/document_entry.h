/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="document_entry.h">
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
    /// Represents a document which will be appended to the original resource document.
    /// </summary>
    class DocumentEntry : public ModelBase
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~DocumentEntry() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets document password encrypted on API public key. The default value is null (the document has no password).
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getEncryptedPassword() const;

        /// <summary>
        /// Gets or sets document password encrypted on API public key. The default value is null (the document has no password).
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setEncryptedPassword(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the path to document to append at the server.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getHref() const;

        /// <summary>
        /// Gets or sets the path to document to append at the server.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setHref(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the option that controls formatting will be used: appended or destination document. Can be KeepSourceFormatting or UseDestinationStyles.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getImportFormatMode() const;

        /// <summary>
        /// Gets or sets the option that controls formatting will be used: appended or destination document. Can be KeepSourceFormatting or UseDestinationStyles.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setImportFormatMode(std::shared_ptr< std::wstring > value);


    protected:
        std::shared_ptr< std::wstring > m_EncryptedPassword;
        std::shared_ptr< std::wstring > m_Href;
        std::shared_ptr< std::wstring > m_ImportFormatMode;
    };
}

