/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Document.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_Document_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_Document_H_


#include "../ModelBase.h"

#include "DocumentProperties.h"
#include "Link.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Represents Words document DTO.
/// </summary>
class  Document
    : public ModelBase
{
public:
    Document();
    virtual ~Document();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// Document members

    /// <summary>
    /// Gets or sets a list of links that originate from this document.
    /// </summary>
    std::vector<std::shared_ptr<Link>>& getLinks();
    bool linksIsSet() const;
    void unsetLinks();
    void setLinks(std::vector<std::shared_ptr<Link>> const& value);
    /// <summary>
    /// Gets or sets the name of the file.
    /// </summary>
    utility::string_t getFileName() const;
    bool fileNameIsSet() const;
    void unsetFileName();
    void setFileName(utility::string_t value);
    /// <summary>
    /// Gets or sets the original format of the document.
    /// </summary>
    utility::string_t getSourceFormat() const;
    bool sourceFormatIsSet() const;
    void unsetSourceFormat();
    void setSourceFormat(utility::string_t value);
    /// <summary>
    /// Gets or sets a value indicating whether returns true if the document is encrypted and requires a password to open.
    /// </summary>
    bool isIsEncrypted() const;
    bool isEncryptedIsSet() const;
    void unsetIsEncrypted();
    void setIsEncrypted(bool value);
    /// <summary>
    /// Gets or sets a value indicating whether returns true if the document contains a digital signature. This property merely informs that a digital signature is present on a document, but it does not specify whether the signature is valid or not.
    /// </summary>
    bool isIsSigned() const;
    bool isSignedIsSet() const;
    void unsetIsSigned();
    void setIsSigned(bool value);
    /// <summary>
    /// Gets or sets DocumentProperties.
    /// </summary>
    std::shared_ptr<DocumentProperties> getDocumentProperties() const;
    bool documentPropertiesIsSet() const;
    void unsetDocumentProperties();
    void setDocumentProperties(std::shared_ptr<DocumentProperties> value);

protected:
    std::vector<std::shared_ptr<Link>> m_Links;
    bool m_LinksIsSet;
    utility::string_t m_FileName;
    bool m_FileNameIsSet;
    utility::string_t m_SourceFormat;
    bool m_SourceFormatIsSet;
    bool m_IsEncrypted;
    bool m_IsEncryptedIsSet;
    bool m_IsSigned;
    bool m_IsSignedIsSet;
    std::shared_ptr<DocumentProperties> m_DocumentProperties;
    bool m_DocumentPropertiesIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_Document_H_ */
