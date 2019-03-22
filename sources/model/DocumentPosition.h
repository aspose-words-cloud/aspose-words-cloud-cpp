
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DocumentPosition.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_DocumentPosition_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_DocumentPosition_H_


#include "../ModelBase.h"

#include "NodeLink.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Represents a position in the document tree.
/// </summary>
class  DocumentPosition
    : public ModelBase
{
public:
    DocumentPosition();
    virtual ~DocumentPosition();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// DocumentPosition members

    /// <summary>
    /// Link to  node.
    /// </summary>
    std::shared_ptr<NodeLink> getNode() const;
    bool nodeIsSet() const;
    void unsetNode();
    void setNode(std::shared_ptr<NodeLink> value);
    /// <summary>
    /// Offset into the node.
    /// </summary>
    int32_t getOffset() const;
    bool offsetIsSet() const;
    void unsetOffset();
    void setOffset(int32_t value);

protected:
    std::shared_ptr<NodeLink> m_Node;
    bool m_NodeIsSet;
    int32_t m_Offset;
    bool m_OffsetIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_DocumentPosition_H_ */
