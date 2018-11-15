
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ClassificationResult.h">
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

#ifndef IO_SWAGGER_CLIENT_MODEL_ClassificationResult_H_
#define IO_SWAGGER_CLIENT_MODEL_ClassificationResult_H_


#include "../ModelBase.h"

#include <cpprest/details/basic_types.h>

namespace io {
namespace swagger {
namespace client {
namespace model {

/// <summary>
/// Represents a single classification result.
/// </summary>
class  ClassificationResult
    : public ModelBase
{
public:
    ClassificationResult();
    virtual ~ClassificationResult();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// ClassificationResult members

    /// <summary>
    /// Gets or sets the name of the class.
    /// </summary>
    utility::string_t getClassName() const;
    bool classNameIsSet() const;
    void unsetClassName();
    void setClassName(utility::string_t value);
    /// <summary>
    /// Gets or sets the probability of class.
    /// </summary>
    double getClassProbability() const;
        void setClassProbability(double value);

protected:
    utility::string_t m_ClassName;
    bool m_ClassNameIsSet;
    double m_ClassProbability;
    };

}
}
}
}

#endif /* IO_SWAGGER_CLIENT_MODEL_ClassificationResult_H_ */
