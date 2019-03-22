
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="CompareData.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_CompareData_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_CompareData_H_


#include "../ModelBase.h"

#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Container class for compare documents
/// </summary>
class  CompareData
    : public ModelBase
{
public:
    CompareData();
    virtual ~CompareData();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// CompareData members

    /// <summary>
    /// Path to document to compare at the server.
    /// </summary>
    utility::string_t getComparingWithDocument() const;
    bool comparingWithDocumentIsSet() const;
    void unsetComparingWithDocument();
    void setComparingWithDocument(utility::string_t value);
    /// <summary>
    /// Initials of the author to use for revisions.
    /// </summary>
    utility::string_t getAuthor() const;
    bool authorIsSet() const;
    void unsetAuthor();
    void setAuthor(utility::string_t value);
    /// <summary>
    /// The date and time to use for revisions.             
    /// </summary>
    utility::datetime getDateTime() const;
    bool dateTimeIsSet() const;
    void unsetDateTime();
    void setDateTime(utility::datetime value);

protected:
    utility::string_t m_ComparingWithDocument;
    bool m_ComparingWithDocumentIsSet;
    utility::string_t m_Author;
    bool m_AuthorIsSet;
    utility::datetime m_DateTime;
    bool m_DateTimeIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_CompareData_H_ */
