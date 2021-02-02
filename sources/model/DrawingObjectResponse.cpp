/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DrawingObjectResponse.cpp">
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

#include "DrawingObjectResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

DrawingObjectResponse::DrawingObjectResponse()
{
    m_DrawingObjectIsSet = false;

}

DrawingObjectResponse::~DrawingObjectResponse()
{
}

void DrawingObjectResponse::validate()
{
    // TODO: implement validation
}

web::json::value DrawingObjectResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();
    if(m_DrawingObjectIsSet)
    {
        val[_XPLATSTR("DrawingObject")] = ModelBase::toJson(m_DrawingObject);
    }

    return val;
}

void DrawingObjectResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("DrawingObject")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DrawingObject")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<DrawingObject> newItem(new DrawingObject());
            newItem->fromJson(fieldValue);
            setDrawingObject( newItem );
        }
    }

}

void DrawingObjectResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    WordsResponse::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_DrawingObjectIsSet)
    {
        if (m_DrawingObject.get())
        {
            m_DrawingObject->toMultipart(multipart, _XPLATSTR("DrawingObject."));
        }
    }

}

void DrawingObjectResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

std::shared_ptr<DrawingObject> DrawingObjectResponse::getDrawingObject() const
{
    return m_DrawingObject;
}


void DrawingObjectResponse::setDrawingObject(std::shared_ptr<DrawingObject> value)
{
    m_DrawingObject = value;
    m_DrawingObjectIsSet = true;
}

bool DrawingObjectResponse::drawingObjectIsSet() const
{
    return m_DrawingObjectIsSet;
}

void DrawingObjectResponse::unsetDrawingObject()
{
    m_DrawingObjectIsSet = false;
}

}
}
}
}
}
