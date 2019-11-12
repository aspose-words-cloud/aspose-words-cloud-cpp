
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TableCellInsert.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_TableCellInsert_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_TableCellInsert_H_


#include "../ModelBase.h"


namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Table cell element.
/// </summary>
class  TableCellInsert
    : public ModelBase
{
public:
    TableCellInsert();
    virtual ~TableCellInsert();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// TableCellInsert members

    /// <summary>
    /// Gets or sets table cell will be inserted after cell with specified 0-based index.
    /// </summary>
    int32_t getInsertAfter() const;
    bool insertAfterIsSet() const;
    void unsetInsertAfter();
    void setInsertAfter(int32_t value);

protected:
    int32_t m_InsertAfter;
    bool m_InsertAfterIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_TableCellInsert_H_ */
