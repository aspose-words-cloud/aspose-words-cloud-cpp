
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DocumentProperty.h">
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

#ifndef IO_SWAGGER_CLIENT_MODEL_DocumentProperty_H_
#define IO_SWAGGER_CLIENT_MODEL_DocumentProperty_H_


#include <cpprest/details/basic_types.h>
#include "LinkElement.h"
#include "WordsApiLink.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

/// <summary>
/// Words document property DTO.
/// </summary>
class  DocumentProperty
    : public LinkElement
{
public:
    DocumentProperty();
    virtual ~DocumentProperty();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// DocumentProperty members

    /// <summary>
    /// Flag indicates whether the property is built-in or not. If true the property is built-in, if false the property is custom.
    /// </summary>
    bool isBuiltIn() const;
    bool builtInIsSet() const;
    void unsetBuiltIn();
    void setBuiltIn(bool value);
    /// <summary>
    /// Name of the document property.
    /// </summary>
    utility::string_t getName() const;
    bool nameIsSet() const;
    void unsetName();
    void setName(utility::string_t value);
    /// <summary>
    /// string value of the document property. 
    /// </summary>
    utility::string_t getValue() const;
    bool valueIsSet() const;
    void unsetValue();
    void setValue(utility::string_t value);

protected:
    bool m_BuiltIn;
    bool m_BuiltInIsSet;
    utility::string_t m_Name;
    bool m_NameIsSet;
    utility::string_t m_Value;
    bool m_ValueIsSet;
};

}
}
}
}

#endif /* IO_SWAGGER_CLIENT_MODEL_DocumentProperty_H_ */
