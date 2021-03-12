/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="model_base.cpp">
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

#include "model_base.h"

namespace aspose::words::cloud::api::models {
    web::json::value ModelBase::toJson( const std::wstring& value )
    {
        return web::json::value::string(value);
    }
    web::json::value ModelBase::toJson( const utility::datetime& value )
    {
        return web::json::value::string(value.to_string(utility::datetime::ISO_8601));
    }
    web::json::value ModelBase::toJson( int32_t value )
    {
        return web::json::value::number(value);
    }
    web::json::value ModelBase::toJson( int64_t value )
    {
        return web::json::value::number(value);
    }
    web::json::value ModelBase::toJson( double value )
    {
        return web::json::value::number(value);
    } 
    web::json::value ModelBase::toJson(bool value) {
        return web::json::value::boolean(value);
    }

    web::json::value ModelBase::toJson(const std::shared_ptr<HttpContent>& content )
    {
        web::json::value value;
        value[_XPLATSTR("ContentDisposition")] = ModelBase::toJson(content->getContentDisposition());
        value[_XPLATSTR("ContentType")] = ModelBase::toJson(content->getContentType());
        value[_XPLATSTR("FileName")] = ModelBase::toJson(content->getFileName());
        value[_XPLATSTR("InputStream")] = web::json::value::string( ModelBase::toBase64(content->getData()) );
        return value;
    }

    std::shared_ptr<HttpContent> ModelBase::fileFromJson(web::json::value& val)
    {
        std::shared_ptr<HttpContent> content = std::make_shared<HttpContent>();

        if(val.has_field(_XPLATSTR("ContentDisposition")))
        {
            content->setContentDisposition( ModelBase::stringFromJson(val[_XPLATSTR("ContentDisposition")]) );
        }
        if(val.has_field(_XPLATSTR("ContentType")))
        {
            content->setContentType( ModelBase::stringFromJson(val[_XPLATSTR("ContentType")]) );
        }
        if(val.has_field(_XPLATSTR("FileName")))
        {
            content->setFileName( ModelBase::stringFromJson(val[_XPLATSTR("FileName")]) );
        }
        if(val.has_field(_XPLATSTR("InputStream")))
        {
            content->setData( ModelBase::fromBase64( ModelBase::stringFromJson(val[_XPLATSTR("InputStream")]) ) );
        }

        return content;
    }

    web::json::value ModelBase::toJson(const std::shared_ptr<ModelBase>& content )
    {
        return content ? content->toJson() : web::json::value::null();
    }

    std::shared_ptr<HttpContent> ModelBase::toHttpContent( const std::wstring& name, const std::wstring& value, const std::wstring& contentType)
    {
        auto content = std::make_shared<HttpContent>();
        content->setName( name );
        content->setContentDisposition( _XPLATSTR("form-data") );
        content->setContentType( contentType );
        content->setData(std::make_shared<std::stringstream>(utility::conversions::to_utf8string(value)));
        return content;
    }
    std::shared_ptr<HttpContent> ModelBase::toHttpContent( const std::wstring& name, const utility::datetime& value, const std::wstring& contentType )
    {
        auto content = std::make_shared<HttpContent>();
        content->setName( name );
        content->setContentDisposition( _XPLATSTR("form-data") );
        content->setContentType( contentType );
        content->setData(std::make_shared<std::stringstream>(utility::conversions::to_utf8string(value.to_string(utility::datetime::ISO_8601) ) ) );
        return content;
    }
    std::shared_ptr<HttpContent> ModelBase::toHttpContent( const std::wstring& name, std::shared_ptr<HttpContent> value )
    {
        auto content = std::make_shared<HttpContent>();
        content->setName( name );
        content->setContentDisposition( value->getContentDisposition() );
        content->setContentType( value->getContentType() );
        content->setData( value->getData() );
        content->setFileName( value->getFileName() );
        return content;
    }
    std::shared_ptr<HttpContent> ModelBase::toHttpContent( const std::wstring& name, const web::json::value& value, const std::wstring& contentType )
    {
        auto content = std::make_shared<HttpContent>();
        content->setName( name );
        content->setContentDisposition( _XPLATSTR("form-data") );
        content->setContentType( contentType );
        content->setData(std::make_shared<std::stringstream>( utility::conversions::to_utf8string(value.serialize()) ) );
        return content;
    }
    std::shared_ptr<HttpContent> ModelBase::toHttpContent( const std::wstring& name, int32_t value, const std::wstring& contentType )
    {
        auto content = std::make_shared<HttpContent>();
        content->setName( name );
        content->setContentDisposition( _XPLATSTR("form-data") );
        content->setContentType( contentType );
	    auto valueAsStringStream = std::make_shared<std::stringstream>();
	    (*valueAsStringStream) << value;
        content->setData( valueAsStringStream );
        return content;
    }
    std::shared_ptr<HttpContent> ModelBase::toHttpContent( const std::wstring& name, int64_t value, const std::wstring& contentType )
    {
        auto content = std::make_shared<HttpContent>();
        content->setName( name );
        content->setContentDisposition( _XPLATSTR("form-data") );
        content->setContentType( contentType );
	    auto valueAsStringStream = std::make_shared<std::stringstream>();
	    (*valueAsStringStream) << value;
        content->setData(valueAsStringStream) ;
        return content;
    }
    std::shared_ptr<HttpContent> ModelBase::toHttpContent( const std::wstring& name, double value, const std::wstring& contentType )
    {
        auto content = std::make_shared<HttpContent>();
        content->setName( name );
        content->setContentDisposition( _XPLATSTR("form-data") );
        content->setContentType( contentType );
	    auto valueAsStringStream = std::make_shared<std::stringstream>();
	    (*valueAsStringStream) << value;
        content->setData(valueAsStringStream);
        return content;
    }

    std::wstring ModelBase::toBase64(const std::wstring& value )
    {
        auto str = utility::conversions::to_utf8string(value);
        const std::vector<uint8_t> buffer(str.begin(), str.end());

        return utility::conversions::to_base64(buffer);
    }

    std::wstring ModelBase::toBase64(const std::shared_ptr<std::istream>& value )
    {
        value->seekg( 0, value->beg );
        const std::vector<uint8_t> buffer(std::istreambuf_iterator<char>{*value}, std::istreambuf_iterator<char>{});
        return utility::conversions::to_base64(buffer);
    }


    std::shared_ptr<std::istream> ModelBase::fromBase64( const std::wstring& encoded )
    {
        auto result = std::make_shared<std::stringstream>();
        auto buffer = utility::conversions::from_base64(encoded);
        std::copy(buffer.begin(), buffer.end(), std::ostreambuf_iterator<char>{*result});

        return result;
    }

    std::wstring ModelBase::fixNamePrefix(std::wstring prefix)
    {
        if(!prefix.empty() && prefix.back() != _XPLATSTR('.'))
        {
            prefix.push_back(_XPLATSTR('.'));
        }

        return prefix;
    }

    int64_t ModelBase::longFromJson(web::json::value& val)
    {
        return val.as_number().to_int64();
    }
    int32_t ModelBase::integerFromJson(web::json::value& val)
    {
        return val.as_integer();
    }
    float ModelBase::floatingFromJson(web::json::value& val)
    {
        return static_cast<float>(val.as_double());
    }
    std::wstring ModelBase::stringFromJson(web::json::value& val)
    {
        return val.is_string() ? val.as_string() : std::wstring{};
    }
    std::wstring ModelBase::enumFromJson(web::json::value& val)
    {
	    return val.is_string() ? val.as_string() : std::wstring{};
    }
    utility::datetime ModelBase::dateTimeFromJson(web::json::value& val)
    {
        return utility::datetime::from_string(val.as_string(), utility::datetime::ISO_8601);
    }
    bool ModelBase::booleanFromJson(web::json::value& val)
    {
        return val.as_bool();
    }
    double ModelBase::doubleFromJson(web::json::value& val)
    {
        return val.as_double();
    }

    int64_t ModelBase::int64_tFromHttpContent(const std::shared_ptr<HttpContent>& val)
    {
        std::wstring str = ModelBase::stringFromHttpContent(val);

        utility::stringstream_t ss(str);
        int64_t result = 0;
        ss >> result;
        return result;
    }
    int32_t ModelBase::int32_tFromHttpContent(const std::shared_ptr<HttpContent>& val)
    {
        std::wstring str = ModelBase::stringFromHttpContent(val);

        utility::stringstream_t ss(str);
        int32_t result = 0;
        ss >> result;
        return result;
    }
    float ModelBase::floatFromHttpContent(const std::shared_ptr<HttpContent>& val)
    {
        std::wstring str = ModelBase::stringFromHttpContent(val);

        utility::stringstream_t ss(str);
        float result = 0;
        ss >> result;
        return result;
    }
    std::wstring ModelBase::stringFromHttpContent(const std::shared_ptr<HttpContent>& val)
    {
        std::shared_ptr<std::istream> data = val->getData();
        data->seekg( 0, data->beg );

        std::string str((std::istreambuf_iterator<char>(*data)),
                     std::istreambuf_iterator<char>());

        return utility::conversions::to_string_t(str);
    }
    utility::datetime ModelBase::dateFromHttpContent(const std::shared_ptr<HttpContent>& val)
    {
        std::wstring str = ModelBase::stringFromHttpContent(val);
        return utility::datetime::from_string(str, utility::datetime::ISO_8601);
    }

    bool ModelBase::boolFromHttpContent(const std::shared_ptr<HttpContent>& val)
    {
        std::wstring str = ModelBase::stringFromHttpContent(val);

        utility::stringstream_t ss(str);
        bool result = false;
        ss >> result;
        return result;
    }
    double ModelBase::doubleFromHttpContent(const std::shared_ptr<HttpContent>& val)
    {
        std::wstring str = ModelBase::stringFromHttpContent(val);

        utility::stringstream_t ss(str);
        double result = 0.0;
        ss >> result;
        return result;
    }

    web::json::value ModelBase::valueFromHttpContent(const std::shared_ptr<HttpContent>& val)
    {
        std::wstring str = ModelBase::stringFromHttpContent(val);
        return web::json::value::parse(str);
    }
}