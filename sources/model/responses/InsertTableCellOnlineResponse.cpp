/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertTableCellOnlineResponse.cpp">
*   Copyright (c) 2020 Aspose.Words for Cloud
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

#include "InsertTableCellOnlineResponse.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
InsertTableCellOnlineResponse::InsertTableCellOnlineResponse(
    std::shared_ptr<TableCellResponse> model,
    std::shared_ptr<HttpContent> document
) : m_Model(model),
m_Document(document)
{
}

std::shared_ptr<TableCellResponse> InsertTableCellOnlineResponse::getModel() const
{
    return m_Model;
}

std::shared_ptr<HttpContent> InsertTableCellOnlineResponse::getDocument() const
{
    return m_Document;
}

}
}
}
}
}
