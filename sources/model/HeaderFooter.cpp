/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="HeaderFooter.cpp">
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


#include "HeaderFooter.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

HeaderFooter::HeaderFooter()
{
    m_DrawingObjectsIsSet = false;
    m_ParagraphsIsSet = false;
}

HeaderFooter::~HeaderFooter()
{
}

void HeaderFooter::validate()
{
    // TODO: implement validation
}

web::json::value HeaderFooter::toJson() const
{
    web::json::value val = this->HeaderFooterLink::toJson();

    if(m_DrawingObjectsIsSet)
    {
        val[_XPLATSTR("DrawingObjects")] = ModelBase::toJson(m_DrawingObjects);
    }
    if(m_ParagraphsIsSet)
    {
        val[_XPLATSTR("Paragraphs")] = ModelBase::toJson(m_Paragraphs);
    }

    return val;
}

void HeaderFooter::fromJson(web::json::value& val)
{
    this->HeaderFooterLink::fromJson(val);

    if(val.has_field(_XPLATSTR("DrawingObjects")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DrawingObjects")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<LinkElement> newItem(new LinkElement());
            newItem->fromJson(fieldValue);
            setDrawingObjects( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("Paragraphs")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Paragraphs")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<LinkElement> newItem(new LinkElement());
            newItem->fromJson(fieldValue);
            setParagraphs( newItem );
        }
    }
}

void HeaderFooter::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_LinkIsSet)
    {
        if (m_Link.get())
        {
            m_Link->toMultipart(multipart, _XPLATSTR("link."));
        }
        
    }
    if(m_TypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Type"), m_Type));
        
    }
    if(m_DrawingObjectsIsSet)
    {
        if (m_DrawingObjects.get())
        {
            m_DrawingObjects->toMultipart(multipart, _XPLATSTR("DrawingObjects."));
        }
        
    }
    if(m_ParagraphsIsSet)
    {
        if (m_Paragraphs.get())
        {
            m_Paragraphs->toMultipart(multipart, _XPLATSTR("Paragraphs."));
        }
        
    }
}

void HeaderFooter::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(multipart->hasContent(_XPLATSTR("link")))
    {
        if(multipart->hasContent(_XPLATSTR("link")))
        {
            std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
            newItem->fromMultiPart(multipart, _XPLATSTR("link."));
            setLink( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("Type")))
    {
        setType(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Type"))));
    }
    if(multipart->hasContent(_XPLATSTR("DrawingObjects")))
    {
        if(multipart->hasContent(_XPLATSTR("DrawingObjects")))
        {
            std::shared_ptr<LinkElement> newItem(new LinkElement());
            newItem->fromMultiPart(multipart, _XPLATSTR("DrawingObjects."));
            setDrawingObjects( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("Paragraphs")))
    {
        if(multipart->hasContent(_XPLATSTR("Paragraphs")))
        {
            std::shared_ptr<LinkElement> newItem(new LinkElement());
            newItem->fromMultiPart(multipart, _XPLATSTR("Paragraphs."));
            setParagraphs( newItem );
        }
    }
}

std::shared_ptr<LinkElement> HeaderFooter::getDrawingObjects() const
{
    return m_DrawingObjects;
}


void HeaderFooter::setDrawingObjects(std::shared_ptr<LinkElement> value)
{
    m_DrawingObjects = value;
    m_DrawingObjectsIsSet = true;
}
bool HeaderFooter::drawingObjectsIsSet() const
{
    return m_DrawingObjectsIsSet;
}

void HeaderFooter::unsetDrawingObjects()
{
    m_DrawingObjectsIsSet = false;
}

std::shared_ptr<LinkElement> HeaderFooter::getParagraphs() const
{
    return m_Paragraphs;
}


void HeaderFooter::setParagraphs(std::shared_ptr<LinkElement> value)
{
    m_Paragraphs = value;
    m_ParagraphsIsSet = true;
}
bool HeaderFooter::paragraphsIsSet() const
{
    return m_ParagraphsIsSet;
}

void HeaderFooter::unsetParagraphs()
{
    m_ParagraphsIsSet = false;
}

}
}
}
}

