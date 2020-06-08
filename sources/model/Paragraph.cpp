/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Paragraph.cpp">
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


#include "Paragraph.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

Paragraph::Paragraph()
{
    m_ChildNodesIsSet = false;
}

Paragraph::~Paragraph()
{
}

void Paragraph::validate()
{
    // TODO: implement validation
}

web::json::value Paragraph::toJson() const
{
    web::json::value val = this->NodeLink::toJson();

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_ChildNodes.begin(), m_ChildNodes.end(), std::back_inserter(jsonArray),
			[&](<DATA_TYPE_START>NodeLink<DATA_TYPE_END> item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("ChildNodes")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void Paragraph::fromJson(web::json::value& val)
{
    this->NodeLink::fromJson(val);

    {
        m_ChildNodes.clear();
        if(val.has_field(_XPLATSTR("ChildNodes")) 
                            && !val[_XPLATSTR("ChildNodes")].is_null())
        {
        auto arr = val[_XPLATSTR("ChildNodes")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_ChildNodes), [&](web::json::value& item){
            if(item.is_null())
            {
                return <DATA_TYPE_START>NodeLink<DATA_TYPE_END>(nullptr);
            }
            else
            {
                <DATA_TYPE_START>NodeLink<DATA_TYPE_END> newItem(new NodeLink());
                newItem->fromJson(item);
                return newItem;
            }
        });

        }
    }
}

void Paragraph::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    NodeLink::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_ChildNodes.begin(), m_ChildNodes.end(), std::back_inserter(jsonArray), [&](<DATA_TYPE_START>NodeLink<DATA_TYPE_END> item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ChildNodes"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }
}

void Paragraph::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    NodeLink::fromMultiPart(multipart, prefix);

    {
        m_ChildNodes.clear();
        if(multipart->hasContent(_XPLATSTR("ChildNodes")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ChildNodes")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_ChildNodes), [&](web::json::value item) {
            if(item.is_null())
            {
                return <DATA_TYPE_START>NodeLink<DATA_TYPE_END>(nullptr) ;
            }
            else
            {
                <DATA_TYPE_START>NodeLink<DATA_TYPE_END> newItem(new NodeLink());
                newItem->fromJson(item);
                return newItem ;
            }
        });
        }
    }
}

<DATA_TYPE_START>List<NodeLink><DATA_TYPE_END>& Paragraph::getChildNodes()
{
    return m_ChildNodes;
}

void Paragraph::setChildNodes(<DATA_TYPE_START>List<NodeLink><DATA_TYPE_END> const& value)
{
    m_ChildNodes = value;
    m_ChildNodesIsSet = true;
}
bool Paragraph::childNodesIsSet() const
{
    return m_ChildNodesIsSet;
}

void Paragraph::unsetChildNodes()
{
    m_ChildNodesIsSet = false;
}

}
}
}
}
}

