/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="OfficeMathObjectResponse.cpp">
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


#include "OfficeMathObjectResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

OfficeMathObjectResponse::OfficeMathObjectResponse()
{
    m_OfficeMathObjectIsSet = false;
}

OfficeMathObjectResponse::~OfficeMathObjectResponse()
{
}

void OfficeMathObjectResponse::validate()
{
    // TODO: implement validation
}

web::json::value OfficeMathObjectResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();

    if(m_OfficeMathObjectIsSet)
    {
        val[_XPLATSTR("OfficeMathObject")] = ModelBase::toJson(m_OfficeMathObject);
    }

    return val;
}

void OfficeMathObjectResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("OfficeMathObject")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("OfficeMathObject")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<OfficeMathObject> newItem(new OfficeMathObject());
            newItem->fromJson(fieldValue);
            setOfficeMathObject( newItem );
        }
    }
}

void OfficeMathObjectResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    WordsResponse::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_OfficeMathObjectIsSet)
    {
        if (m_OfficeMathObject.get())
        {
            m_OfficeMathObject->toMultipart(multipart, _XPLATSTR("OfficeMathObject."));
        }
        
    }
}

void OfficeMathObjectResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    WordsResponse::fromMultiPart(multipart, prefix);

    if(multipart->hasContent(_XPLATSTR("OfficeMathObject")))
    {
        if(multipart->hasContent(_XPLATSTR("OfficeMathObject")))
        {
            std::shared_ptr<OfficeMathObject> newItem(new OfficeMathObject());
            newItem->fromMultiPart(multipart, _XPLATSTR("OfficeMathObject."));
            setOfficeMathObject( newItem );
        }
    }
}

std::shared_ptr<OfficeMathObject> OfficeMathObjectResponse::getOfficeMathObject() const
{
    return m_OfficeMathObject;
}


void OfficeMathObjectResponse::setOfficeMathObject(std::shared_ptr<OfficeMathObject> value)
{
    m_OfficeMathObject = value;
    m_OfficeMathObjectIsSet = true;
}
bool OfficeMathObjectResponse::officeMathObjectIsSet() const
{
    return m_OfficeMathObjectIsSet;
}

void OfficeMathObjectResponse::unsetOfficeMathObject()
{
    m_OfficeMathObjectIsSet = false;
}

}
}
}
}
}

