
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ClassificationResponse.h">
*   Copyright (c) 2018 Aspose.Words for Cloud
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

#ifndef IO_SWAGGER_CLIENT_MODEL_ClassificationResponse_H_
#define IO_SWAGGER_CLIENT_MODEL_ClassificationResponse_H_


#include "AsposeResponse.h"
#include "ClassificationResult.h"
#include <cpprest/details/basic_types.h>
#include <vector>

namespace io {
namespace swagger {
namespace client {
namespace model {

/// <summary>
/// This response should be returned by the service when handling: PUT http://api.aspose.com/v1.1/words/classify
/// </summary>
class  ClassificationResponse
    : public AsposeResponse
{
public:
    ClassificationResponse();
    virtual ~ClassificationResponse();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// ClassificationResponse members

    /// <summary>
    /// Best class name.        
    /// </summary>
    utility::string_t getBestClassName() const;
    bool bestClassNameIsSet() const;
    void unsetBestClassName();
    void setBestClassName(utility::string_t value);
    /// <summary>
    /// Best class probability.
    /// </summary>
    double getBestClassProbability() const;
    bool bestClassProbabilityIsSet() const;
    void unsetBestClassProbability();
    void setBestClassProbability(double value);
    /// <summary>
    /// Array of best classes results.
    /// </summary>
    std::vector<std::shared_ptr<ClassificationResult>>& getBestResults();
    bool bestResultsIsSet() const;
    void unsetBestResults();
    void setBestResults(std::vector<std::shared_ptr<ClassificationResult>> const& value);

protected:
    utility::string_t m_BestClassName;
    bool m_BestClassNameIsSet;
    double m_BestClassProbability;
    bool m_BestClassProbabilityIsSet;
    std::vector<std::shared_ptr<ClassificationResult>> m_BestResults;
    bool m_BestResultsIsSet;
};

}
}
}
}

#endif /* IO_SWAGGER_CLIENT_MODEL_ClassificationResponse_H_ */
