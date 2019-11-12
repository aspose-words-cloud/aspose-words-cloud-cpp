
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DrawingObjectCollection.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_DrawingObjectCollection_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_DrawingObjectCollection_H_


#include "LinkElement.h"
#include <vector>
#include "WordsApiLink.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Represents drawing objects collection DTO.
/// </summary>
class  DrawingObjectCollection
    : public LinkElement
{
public:
    DrawingObjectCollection();
    virtual ~DrawingObjectCollection();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// DrawingObjectCollection members

    /// <summary>
    /// Gets or sets collection of DrawingObjects links.
    /// </summary>
    std::vector<std::shared_ptr<LinkElement>>& getList();
    bool listIsSet() const;
    void unsetList();
    void setList(std::vector<std::shared_ptr<LinkElement>> const& value);

protected:
    std::vector<std::shared_ptr<LinkElement>> m_List;
    bool m_ListIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_DrawingObjectCollection_H_ */
