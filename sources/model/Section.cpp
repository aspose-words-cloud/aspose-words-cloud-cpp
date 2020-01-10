/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Section.cpp">
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


#include "Section.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

Section::Section()
{
    m_ChildNodesIsSet = false;
    m_HeaderFootersIsSet = false;
    m_PageSetupIsSet = false;
    m_ParagraphsIsSet = false;
    m_TablesIsSet = false;
}

Section::~Section()
{
}

void Section::validate()
{
    // TODO: implement validation
}

web::json::value Section::toJson() const
{
    web::json::value val = this->LinkElement::toJson();

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_ChildNodes.begin(), m_ChildNodes.end(), std::back_inserter(jsonArray),
			[&](std::shared_ptr<NodeLink> item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("childNodes")] = web::json::value::array(jsonArray);
        }
    }
    if(m_HeaderFootersIsSet)
    {
        val[_XPLATSTR("headerFooters")] = ModelBase::toJson(m_HeaderFooters);
    }
    if(m_PageSetupIsSet)
    {
        val[_XPLATSTR("pageSetup")] = ModelBase::toJson(m_PageSetup);
    }
    if(m_ParagraphsIsSet)
    {
        val[_XPLATSTR("paragraphs")] = ModelBase::toJson(m_Paragraphs);
    }
    if(m_TablesIsSet)
    {
        val[_XPLATSTR("tables")] = ModelBase::toJson(m_Tables);
    }

    return val;
}

void Section::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    {
        m_ChildNodes.clear();
        if(val.has_field(_XPLATSTR("childNodes")) 
                            && !val[_XPLATSTR("childNodes")].is_null())
        {
        auto arr = val[_XPLATSTR("childNodes")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_ChildNodes), [&](web::json::value& item){
            if(item.is_null())
            {
                return std::shared_ptr<NodeLink>(nullptr);
            }
            else
            {
                std::shared_ptr<NodeLink> newItem(new NodeLink());
                newItem->fromJson(item);
                return newItem;
            }
        });

        }
    }
    if(val.has_field(_XPLATSTR("headerFooters")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("headerFooters")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<LinkElement> newItem(new LinkElement());
            newItem->fromJson(fieldValue);
            setHeaderFooters( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("pageSetup")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("pageSetup")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<LinkElement> newItem(new LinkElement());
            newItem->fromJson(fieldValue);
            setPageSetup( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("paragraphs")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("paragraphs")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<LinkElement> newItem(new LinkElement());
            newItem->fromJson(fieldValue);
            setParagraphs( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("tables")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("tables")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<LinkElement> newItem(new LinkElement());
            newItem->fromJson(fieldValue);
            setTables( newItem );
        }
    }
}

void Section::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_LinkIsSet)
    {
        if (m_Link.get())
        {
            m_Link->toMultipart(multipart, _XPLATSTR("link."));
        }
        
    }
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_ChildNodes.begin(), m_ChildNodes.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<NodeLink> item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("childNodes"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }
    if(m_HeaderFootersIsSet)
    {
        if (m_HeaderFooters.get())
        {
            m_HeaderFooters->toMultipart(multipart, _XPLATSTR("headerFooters."));
        }
        
    }
    if(m_PageSetupIsSet)
    {
        if (m_PageSetup.get())
        {
            m_PageSetup->toMultipart(multipart, _XPLATSTR("pageSetup."));
        }
        
    }
    if(m_ParagraphsIsSet)
    {
        if (m_Paragraphs.get())
        {
            m_Paragraphs->toMultipart(multipart, _XPLATSTR("paragraphs."));
        }
        
    }
    if(m_TablesIsSet)
    {
        if (m_Tables.get())
        {
            m_Tables->toMultipart(multipart, _XPLATSTR("tables."));
        }
        
    }
}

void Section::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("link")))
    {
        if(multipart->hasContent(_XPLATSTR("link")))
        {
            std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
            newItem->fromMultiPart(multipart, _XPLATSTR("link."));
            setLink( newItem );
        }
    }
    {
        m_ChildNodes.clear();
        if(multipart->hasContent(_XPLATSTR("childNodes")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("childNodes")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_ChildNodes), [&](web::json::value item) {
            if(item.is_null())
            {
                return std::shared_ptr<NodeLink>(nullptr) ;
            }
            else
            {
                std::shared_ptr<NodeLink> newItem(new NodeLink());
                newItem->fromJson(item);
                return newItem ;
            }
        });
        }
    }
    if(multipart->hasContent(_XPLATSTR("headerFooters")))
    {
        if(multipart->hasContent(_XPLATSTR("headerFooters")))
        {
            std::shared_ptr<LinkElement> newItem(new LinkElement());
            newItem->fromMultiPart(multipart, _XPLATSTR("headerFooters."));
            setHeaderFooters( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("pageSetup")))
    {
        if(multipart->hasContent(_XPLATSTR("pageSetup")))
        {
            std::shared_ptr<LinkElement> newItem(new LinkElement());
            newItem->fromMultiPart(multipart, _XPLATSTR("pageSetup."));
            setPageSetup( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("paragraphs")))
    {
        if(multipart->hasContent(_XPLATSTR("paragraphs")))
        {
            std::shared_ptr<LinkElement> newItem(new LinkElement());
            newItem->fromMultiPart(multipart, _XPLATSTR("paragraphs."));
            setParagraphs( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("tables")))
    {
        if(multipart->hasContent(_XPLATSTR("tables")))
        {
            std::shared_ptr<LinkElement> newItem(new LinkElement());
            newItem->fromMultiPart(multipart, _XPLATSTR("tables."));
            setTables( newItem );
        }
    }
}

std::vector<std::shared_ptr<NodeLink>>& Section::getChildNodes()
{
    return m_ChildNodes;
}

void Section::setChildNodes(std::vector<std::shared_ptr<NodeLink>> const& value)
{
    m_ChildNodes = value;
    m_ChildNodesIsSet = true;
}
bool Section::childNodesIsSet() const
{
    return m_ChildNodesIsSet;
}

void Section::unsetChildNodes()
{
    m_ChildNodesIsSet = false;
}

std::shared_ptr<LinkElement> Section::getHeaderFooters() const
{
    return m_HeaderFooters;
}


void Section::setHeaderFooters(std::shared_ptr<LinkElement> value)
{
    m_HeaderFooters = value;
    m_HeaderFootersIsSet = true;
}
bool Section::headerFootersIsSet() const
{
    return m_HeaderFootersIsSet;
}

void Section::unsetHeaderFooters()
{
    m_HeaderFootersIsSet = false;
}

std::shared_ptr<LinkElement> Section::getPageSetup() const
{
    return m_PageSetup;
}


void Section::setPageSetup(std::shared_ptr<LinkElement> value)
{
    m_PageSetup = value;
    m_PageSetupIsSet = true;
}
bool Section::pageSetupIsSet() const
{
    return m_PageSetupIsSet;
}

void Section::unsetPageSetup()
{
    m_PageSetupIsSet = false;
}

std::shared_ptr<LinkElement> Section::getParagraphs() const
{
    return m_Paragraphs;
}


void Section::setParagraphs(std::shared_ptr<LinkElement> value)
{
    m_Paragraphs = value;
    m_ParagraphsIsSet = true;
}
bool Section::paragraphsIsSet() const
{
    return m_ParagraphsIsSet;
}

void Section::unsetParagraphs()
{
    m_ParagraphsIsSet = false;
}

std::shared_ptr<LinkElement> Section::getTables() const
{
    return m_Tables;
}


void Section::setTables(std::shared_ptr<LinkElement> value)
{
    m_Tables = value;
    m_TablesIsSet = true;
}
bool Section::tablesIsSet() const
{
    return m_TablesIsSet;
}

void Section::unsetTables()
{
    m_TablesIsSet = false;
}

}
}
}
}
}

