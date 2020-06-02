/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="HeaderFooter.cpp">
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

#include "HeaderFooter.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

HeaderFooter::HeaderFooter()
{
    m_ChildNodesIsSet = false;

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
    if(m_ChildNodesIsSet)
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_ChildNodes.begin(), m_ChildNodes.end(), std::back_inserter(jsonArray),
            [&](std::shared_ptr<NodeLink> item) {
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("ChildNodes")] = web::json::value::array(jsonArray);
        }
    }
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

    {
        m_ChildNodes.clear();
        if(val.has_field(_XPLATSTR("ChildNodes")) 
                            && !val[_XPLATSTR("ChildNodes")].is_null())
        {
            auto arr = val[_XPLATSTR("ChildNodes")].as_array();
            std::transform(arr.begin(), arr.end(), std::back_inserter(m_ChildNodes), [&](web::json::value& item){
                if(!item.is_null())
                {
                    std::shared_ptr<NodeLink> newItem(new NodeLink());
                    newItem->fromJson(item);
                    return newItem;
                }

                return (std::shared_ptr<NodeLink>)nullptr;
            });
        }
    }


    if(val.has_field(_XPLATSTR("DrawingObjects")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DrawingObjects")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<LinkElement> newItem(new LinkElement());
            newItem->fromJson(fieldValue);
        }
    }


    if(val.has_field(_XPLATSTR("Paragraphs")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Paragraphs")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<LinkElement> newItem(new LinkElement());
            newItem->fromJson(fieldValue);
        }
    }

}

void HeaderFooter::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    HeaderFooterLink::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_ChildNodes.begin(), m_ChildNodes.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<NodeLink> item){
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ChildNodes"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
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
    // TODO: implement fromMultiPart
}

std::vector<std::shared_ptr<NodeLink>>& HeaderFooter::getChildNodes()
{
    return m_ChildNodes;
}


void HeaderFooter::setChildNodes(std::vector<std::shared_ptr<NodeLink>> const& value)
{
    m_ChildNodes = value;
    m_ChildNodesIsSet = true;
}

bool HeaderFooter::childNodesIsSet() const
{
    return m_ChildNodesIsSet;
}

void HeaderFooter::unsetChildNodes()
{
    m_ChildNodesIsSet = false;
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
}
