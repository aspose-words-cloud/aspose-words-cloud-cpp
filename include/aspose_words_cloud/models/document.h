/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="document.h">
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
#include "document_properties.h"
#include "link.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Represents Words document DTO.
    /// </summary>
    class Document : public ModelBase
    {
    public:
        /// <summary>
        /// Gets or sets the original format of the document.
        /// </summary>
        enum class SourceFormat
        { 
            UNKNOWN,
            DOC,
            DOT,
            DOC_PRE_WORD60,
            DOCX,
            DOCM,
            DOTX,
            DOTM,
            FLAT_OPC,
            RTF,
            WORD_ML,
            HTML,
            MHTML,
            EPUB,
            TEXT,
            ODT,
            OTT,
            PDF,
            XPS,
            TIFF,
            SVG
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~Document() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets the document properties.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::DocumentProperties > getDocumentProperties() const;

        /// <summary>
        /// Gets or sets the document properties.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDocumentProperties(std::shared_ptr< aspose::words::cloud::models::DocumentProperties > value);


        /// <summary>
        /// Gets or sets the name of the file.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getFileName() const;

        /// <summary>
        /// Gets or sets the name of the file.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFileName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets a value indicating whether the document is encrypted and requires a password to open.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsEncrypted() const;

        /// <summary>
        /// Gets or sets a value indicating whether the document is encrypted and requires a password to open.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsEncrypted(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether the document contains a digital signature. This property merely informs that a digital signature is present on a document, but it does not specify whether the signature is valid or not.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsSigned() const;

        /// <summary>
        /// Gets or sets a value indicating whether the document contains a digital signature. This property merely informs that a digital signature is present on a document, but it does not specify whether the signature is valid or not.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsSigned(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the list of links that originate from this document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::Link>> > getLinks() const;

        /// <summary>
        /// Gets or sets the list of links that originate from this document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLinks(std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::Link>> > value);


        /// <summary>
        /// Gets or sets the original format of the document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::Document::SourceFormat > getSourceFormat() const;

        /// <summary>
        /// Gets or sets the original format of the document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSourceFormat(std::shared_ptr< aspose::words::cloud::models::Document::SourceFormat > value);


    protected:
        std::shared_ptr< aspose::words::cloud::models::DocumentProperties > m_DocumentProperties;
        std::shared_ptr< std::wstring > m_FileName;
        std::shared_ptr< bool > m_IsEncrypted;
        std::shared_ptr< bool > m_IsSigned;
        std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::Link>> > m_Links;
        std::shared_ptr< aspose::words::cloud::models::Document::SourceFormat > m_SourceFormat;
    };
}

