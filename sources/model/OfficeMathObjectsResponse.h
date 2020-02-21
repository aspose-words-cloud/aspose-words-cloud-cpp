
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="OfficeMathObjectsResponse.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_OfficeMathObjectsResponse_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_OfficeMathObjectsResponse_H_


#include "WordsResponse.h"
#include <cpprest/details/basic_types.h>
#include "OfficeMathObjectsCollection.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// This response should be returned by the service when handling: GET http://api.aspose.com/v4.0/words/Test.doc/OfficeMathObjects.
/// </summary>
class  OfficeMathObjectsResponse
    : public WordsResponse
{
public:
    OfficeMathObjectsResponse();
    virtual ~OfficeMathObjectsResponse();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// OfficeMathObjectsResponse members

    /// <summary>
    /// Gets or sets collection of OfficeMath objects.
    /// </summary>
    std::shared_ptr<OfficeMathObjectsCollection> getOfficeMathObjects() const;
    bool officeMathObjectsIsSet() const;
    void unsetOfficeMathObjects();
    void setOfficeMathObjects(std::shared_ptr<OfficeMathObjectsCollection> value);

protected:
    std::shared_ptr<OfficeMathObjectsCollection> m_OfficeMathObjects;
    bool m_OfficeMathObjectsIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_OfficeMathObjectsResponse_H_ */
