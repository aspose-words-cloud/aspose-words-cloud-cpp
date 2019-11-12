
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ModificationOperationResult.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_ModificationOperationResult_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_ModificationOperationResult_H_


#include "../ModelBase.h"

#include "FileLink.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// result of the operation which modifies the original document and saves the result.
/// </summary>
class  ModificationOperationResult
    : public ModelBase
{
public:
    ModificationOperationResult();
    virtual ~ModificationOperationResult();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// ModificationOperationResult members

    /// <summary>
    /// Gets or sets link to the source document (source for the modification operation).
    /// </summary>
    std::shared_ptr<FileLink> getSource() const;
    bool sourceIsSet() const;
    void unsetSource();
    void setSource(std::shared_ptr<FileLink> value);
    /// <summary>
    /// Gets or sets link to the dest document (result of the modification operation).
    /// </summary>
    std::shared_ptr<FileLink> getDest() const;
    bool destIsSet() const;
    void unsetDest();
    void setDest(std::shared_ptr<FileLink> value);

protected:
    std::shared_ptr<FileLink> m_Source;
    bool m_SourceIsSet;
    std::shared_ptr<FileLink> m_Dest;
    bool m_DestIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_ModificationOperationResult_H_ */
