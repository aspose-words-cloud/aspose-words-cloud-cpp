/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ListUpdate.cpp">
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


#include "ListUpdate.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

ListUpdate::ListUpdate()
{
    m_IsRestartAtEachSection = false;
    m_IsRestartAtEachSectionIsSet = false;
}

ListUpdate::~ListUpdate()
{
}

void ListUpdate::validate()
{
    // TODO: implement validation
}

web::json::value ListUpdate::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_IsRestartAtEachSectionIsSet)
    {
        val[_XPLATSTR("IsRestartAtEachSection")] = ModelBase::toJson(m_IsRestartAtEachSection);
    }

    return val;
}

void ListUpdate::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("IsRestartAtEachSection")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("IsRestartAtEachSection")];
        if(!fieldValue.is_null())
        {
            setIsRestartAtEachSection(ModelBase::bool?FromJson(fieldValue));
        }
    }
}

void ListUpdate::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_IsRestartAtEachSectionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("IsRestartAtEachSection"), m_IsRestartAtEachSection));
        
    }
}

void ListUpdate::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    

    if(multipart->hasContent(_XPLATSTR("IsRestartAtEachSection")))
    {
        setIsRestartAtEachSection(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("IsRestartAtEachSection"))));
    }
}

<DATA_TYPE_START>bool?<DATA_TYPE_END> ListUpdate::isIsRestartAtEachSection() const
{
    return m_IsRestartAtEachSection;
}


void ListUpdate::setIsRestartAtEachSection(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
{
    m_IsRestartAtEachSection = value;
    m_IsRestartAtEachSectionIsSet = true;
}
bool ListUpdate::isRestartAtEachSectionIsSet() const
{
    return m_IsRestartAtEachSectionIsSet;
}

void ListUpdate::unsetIsRestartAtEachSection()
{
    m_IsRestartAtEachSectionIsSet = false;
}

}
}
}
}
}

