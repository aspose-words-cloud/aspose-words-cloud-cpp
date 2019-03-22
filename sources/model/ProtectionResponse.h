
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ProtectionResponse.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_ProtectionResponse_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_ProtectionResponse_H_


#include "AsposeResponse.h"
#include <cpprest/details/basic_types.h>
#include "FileLink.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Response for the request on changing protection of the document
/// </summary>
class  ProtectionResponse
    : public AsposeResponse
{
public:
    ProtectionResponse();
    virtual ~ProtectionResponse();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// ProtectionResponse members

    /// <summary>
    /// Link to the document
    /// </summary>
    std::shared_ptr<FileLink> getDocumentLink() const;
    bool documentLinkIsSet() const;
    void unsetDocumentLink();
    void setDocumentLink(std::shared_ptr<FileLink> value);
    /// <summary>
    /// Result of the changing of protection
    /// </summary>
    bool isProtectionResult() const;
    bool protectionResultIsSet() const;
    void unsetProtectionResult();
    void setProtectionResult(bool value);

protected:
    std::shared_ptr<FileLink> m_DocumentLink;
    bool m_DocumentLinkIsSet;
    bool m_ProtectionResult;
    bool m_ProtectionResultIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_ProtectionResponse_H_ */
