/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TableInsertDto.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_TableInsertDto_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_TableInsertDto_H_

#include "DocumentPosition.h"
#include "../ModelBase.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// DTO container with a table element.
/// </summary>
class TableInsertDto
    : public ModelBase
{
public:
    TableInsertDto();
    virtual ~TableInsertDto();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// TableInsertDto members

    /// <summary>
    /// Gets or sets the number of columns. The default value is 2.
    /// </summary>
    int32_t getColumnsCount() const;
    bool columnsCountIsSet() const;
    void unsetColumnsCount();
    void setColumnsCount(int32_t value);

    /// <summary>
    /// Gets or sets the position to insert the table. The table will be inserted before the specified position.
    /// </summary>
    std::shared_ptr<DocumentPosition> getPosition() const;
    bool positionIsSet() const;
    void unsetPosition();
    void setPosition(std::shared_ptr<DocumentPosition> value);

    /// <summary>
    /// Gets or sets the number of rows. The default value is 2.
    /// </summary>
    int32_t getRowsCount() const;
    bool rowsCountIsSet() const;
    void unsetRowsCount();
    void setRowsCount(int32_t value);

protected:
    int32_t m_ColumnsCount;
    bool m_ColumnsCountIsSet;

    std::shared_ptr<DocumentPosition> m_Position;
    bool m_PositionIsSet;

    int32_t m_RowsCount;
    bool m_RowsCountIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_TableInsertDto_H_ */
