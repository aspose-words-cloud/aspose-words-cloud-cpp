/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="OfficeMathObjectsResponse.cpp">
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


#include "OfficeMathObjectsResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

OfficeMathObjectsResponse::OfficeMathObjectsResponse()
{
    m_OfficeMathObjectsIsSet = false;
}

OfficeMathObjectsResponse::~OfficeMathObjectsResponse()
{
}

void OfficeMathObjectsResponse::validate()
{
    // TODO: implement validation
}

web::json::value OfficeMathObjectsResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();

    if(m_OfficeMathObjectsIsSet)
    {
        val[_XPLATSTR("OfficeMathObjects")] = ModelBase::toJson(m_OfficeMathObjects);
    }

    return val;
}

void OfficeMathObjectsResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("OfficeMathObjects")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("OfficeMathObjects")];
        if(!fieldValue.is_null())
        {
            <DATA_TYPE_START>OfficeMathObjectsCollection<DATA_TYPE_END> newItem(new OfficeMathObjectsCollection());
            newItem->fromJson(fieldValue);
            setOfficeMathObjects( newItem );
        }
    }
}

void OfficeMathObjectsResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    WordsResponse::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_OfficeMathObjectsIsSet)
    {
        if (m_OfficeMathObjects.get())
        {
            m_OfficeMathObjects->toMultipart(multipart, _XPLATSTR("OfficeMathObjects."));
        }
        
    }
}

void OfficeMathObjectsResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    WordsResponse::fromMultiPart(multipart, prefix);

    if(multipart->hasContent(_XPLATSTR("OfficeMathObjects")))
    {
        if(multipart->hasContent(_XPLATSTR("OfficeMathObjects")))
        {
            <DATA_TYPE_START>OfficeMathObjectsCollection<DATA_TYPE_END> newItem(new OfficeMathObjectsCollection());
            newItem->fromMultiPart(multipart, _XPLATSTR("OfficeMathObjects."));
            setOfficeMathObjects( newItem );
        }
    }
}

<DATA_TYPE_START>OfficeMathObjectsCollection<DATA_TYPE_END> OfficeMathObjectsResponse::getOfficeMathObjects() const
{
    return m_OfficeMathObjects;
}


void OfficeMathObjectsResponse::setOfficeMathObjects(<DATA_TYPE_START>OfficeMathObjectsCollection<DATA_TYPE_END> value)
{
    m_OfficeMathObjects = value;
    m_OfficeMathObjectsIsSet = true;
}
bool OfficeMathObjectsResponse::officeMathObjectsIsSet() const
{
    return m_OfficeMathObjectsIsSet;
}

void OfficeMathObjectsResponse::unsetOfficeMathObjects()
{
    m_OfficeMathObjectsIsSet = false;
}

}
}
}
}
}

