
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Section.h">
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

#ifndef IO_SWAGGER_CLIENT_MODEL_Section_H_
#define IO_SWAGGER_CLIENT_MODEL_Section_H_


#include "NodeLink.h"
#include "LinkElement.h"
#include <vector>
#include "WordsApiLink.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

/// <summary>
/// Section element
/// </summary>
class  Section
    : public LinkElement
{
public:
    Section();
    virtual ~Section();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// Section members

    /// <summary>
    /// Child nodes.
    /// </summary>
    std::vector<std::shared_ptr<NodeLink>>& getChildNodes();
    bool childNodesIsSet() const;
    void unsetChildNodes();
    void setChildNodes(std::vector<std::shared_ptr<NodeLink>> const& value);
    /// <summary>
    /// Link to HeaderFooters resource
    /// </summary>
    std::shared_ptr<LinkElement> getHeaderFooters() const;
    bool headerFootersIsSet() const;
    void unsetHeaderFooters();
    void setHeaderFooters(std::shared_ptr<LinkElement> value);
    /// <summary>
    /// Link to PageSetup resource
    /// </summary>
    std::shared_ptr<LinkElement> getPageSetup() const;
    bool pageSetupIsSet() const;
    void unsetPageSetup();
    void setPageSetup(std::shared_ptr<LinkElement> value);
    /// <summary>
    /// Link to Paragraphs resource
    /// </summary>
    std::shared_ptr<LinkElement> getParagraphs() const;
    bool paragraphsIsSet() const;
    void unsetParagraphs();
    void setParagraphs(std::shared_ptr<LinkElement> value);
    /// <summary>
    /// Link to Tables resource
    /// </summary>
    std::shared_ptr<LinkElement> getTables() const;
    bool tablesIsSet() const;
    void unsetTables();
    void setTables(std::shared_ptr<LinkElement> value);

protected:
    std::vector<std::shared_ptr<NodeLink>> m_ChildNodes;
    bool m_ChildNodesIsSet;
    std::shared_ptr<LinkElement> m_HeaderFooters;
    bool m_HeaderFootersIsSet;
    std::shared_ptr<LinkElement> m_PageSetup;
    bool m_PageSetupIsSet;
    std::shared_ptr<LinkElement> m_Paragraphs;
    bool m_ParagraphsIsSet;
    std::shared_ptr<LinkElement> m_Tables;
    bool m_TablesIsSet;
};

}
}
}
}

#endif /* IO_SWAGGER_CLIENT_MODEL_Section_H_ */
