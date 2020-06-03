/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DrawingObjectsResponse.cpp">
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

#include "DrawingObjectsResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

DrawingObjectsResponse::DrawingObjectsResponse()
{
    m_DrawingObjectsIsSet = false;

}

DrawingObjectsResponse::~DrawingObjectsResponse()
{
}

void DrawingObjectsResponse::validate()
{
    // TODO: implement validation
}

web::json::value DrawingObjectsResponse::toJson() const
{
    web::json::value val = this->WordsResponse::toJson();
    if(m_DrawingObjectsIsSet)
    {
        val[_XPLATSTR("DrawingObjects")] = ModelBase::toJson(m_DrawingObjects);
    }

    return val;
}

void DrawingObjectsResponse::fromJson(web::json::value& val)
{
    this->WordsResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("DrawingObjects")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DrawingObjects")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<DrawingObjectCollection> newItem(new DrawingObjectCollection());
            newItem->fromJson(fieldValue);
            setDrawingObjects( newItem );
        }
    }

}

void DrawingObjectsResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    WordsResponse::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_DrawingObjectsIsSet)
    {
        if (m_DrawingObjects.get())
        {
            m_DrawingObjects->toMultipart(multipart, _XPLATSTR("DrawingObjects."));
        }
    }

}

void DrawingObjectsResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

std::shared_ptr<DrawingObjectCollection> DrawingObjectsResponse::getDrawingObjects() const
{
    return m_DrawingObjects;
}


void DrawingObjectsResponse::setDrawingObjects(std::shared_ptr<DrawingObjectCollection> value)
{
    m_DrawingObjects = value;
    m_DrawingObjectsIsSet = true;
}

bool DrawingObjectsResponse::drawingObjectsIsSet() const
{
    return m_DrawingObjectsIsSet;
}

void DrawingObjectsResponse::unsetDrawingObjects()
{
    m_DrawingObjectsIsSet = false;
}

}
}
}
}
}
