/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ModelBase.h">
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

#ifndef IO_SWAGGER_CLIENT_MODEL_ModelBase_H_
#define IO_SWAGGER_CLIENT_MODEL_ModelBase_H_


#include "HttpContent.h"
#include "MultipartFormData.h"

#include <cpprest/details/basic_types.h>
#include <cpprest/json.h>

#include <vector>

namespace io {
namespace swagger {
namespace client {
namespace model {

class FormFieldCheckbox;
class FormFieldDropDown;
class FormFieldTextInput;


class  ModelBase
{
public:
    ModelBase();
    virtual ~ModelBase();

    virtual void validate() = 0;

    virtual web::json::value toJson() const = 0;
    virtual void fromJson(web::json::value& json) = 0;

    virtual void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const = 0;
    virtual void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) = 0;

    static web::json::value toJson( const utility::string_t& value );
    static web::json::value toJson( const utility::datetime& value );
    static web::json::value toJson( std::shared_ptr<HttpContent> value );
    static web::json::value toJson( std::shared_ptr<ModelBase> value );
    static web::json::value toJson( int32_t value );
    static web::json::value toJson( int64_t value );
    static web::json::value toJson( double value );
    static web::json::value toJson( bool value );
    template<class T>
    static web::json::value toJson(const std::vector<T>& value);

    static int64_t int64_tFromJson(web::json::value& val);
    static int32_t int32_tFromJson(web::json::value& val);
    static float floatFromJson(web::json::value& val);
    static utility::string_t stringFromJson(web::json::value& val);
    static utility::datetime dateFromJson(web::json::value& val);
    static double doubleFromJson(web::json::value& val);
    static bool boolFromJson(web::json::value& val);
    static std::shared_ptr<HttpContent> fileFromJson(web::json::value& val);

    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, const utility::string_t& value, const utility::string_t& contentType = utility::conversions::to_string_t(""));
    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, const utility::datetime& value, const utility::string_t& contentType = utility::conversions::to_string_t(""));
    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, std::shared_ptr<HttpContent> value );
    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, const web::json::value& value, const utility::string_t& contentType = utility::conversions::to_string_t("application/json") );
    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, int32_t value, const utility::string_t& contentType = utility::conversions::to_string_t("") );
    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, int64_t value, const utility::string_t& contentType = utility::conversions::to_string_t("") );
    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, double value, const utility::string_t& contentType = utility::conversions::to_string_t("") );
    template <class T>
    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, const std::vector<T>& value, const utility::string_t& contentType = utility::conversions::to_string_t("") );

    static int64_t int64_tFromHttpContent(std::shared_ptr<HttpContent> val);
    static int32_t int32_tFromHttpContent(std::shared_ptr<HttpContent> val);
    static float floatFromHttpContent(std::shared_ptr<HttpContent> val);
    static utility::string_t stringFromHttpContent(std::shared_ptr<HttpContent> val);
    static utility::datetime dateFromHttpContent(std::shared_ptr<HttpContent> val);
    static bool boolFromHttpContent(std::shared_ptr<HttpContent> val);
    static double doubleFromHttpContent(std::shared_ptr<HttpContent> val);
    static web::json::value valueFromHttpContent(std::shared_ptr<HttpContent> val);


    static utility::string_t toBase64( utility::string_t value );
    static utility::string_t toBase64( std::shared_ptr<std::istream> value );
    static std::shared_ptr<std::istream> fromBase64( const utility::string_t& encoded );
};

template<class T>
web::json::value ModelBase::toJson(const std::vector<T>& value) {
    std::vector<web::json::value> ret;
    for (auto& x : value) {
        ret.push_back(toJson(x));
    }

    return web::json::value::array(ret);
}

template <class T>
std::shared_ptr<HttpContent> ModelBase::toHttpContent( const utility::string_t& name, const std::vector<T>& value, const utility::string_t& contentType ) {
    web::json::value json_array = ModelBase::toJson(value);
    std::shared_ptr<HttpContent> content( new HttpContent );
    content->setName( name );
    content->setContentDisposition( utility::conversions::to_string_t("form-data") );
    content->setContentType( contentType );
    content->setData( std::shared_ptr<std::istream>( new std::stringstream( utility::conversions::to_utf8string(json_array.serialize()) ) ) );
    return content;
}

}
}
}
}

#endif /* IO_SWAGGER_CLIENT_MODEL_ModelBase_H_ */
