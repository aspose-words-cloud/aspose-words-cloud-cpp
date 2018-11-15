
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PageStatData.h">
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

#ifndef IO_SWAGGER_CLIENT_MODEL_PageStatData_H_
#define IO_SWAGGER_CLIENT_MODEL_PageStatData_H_


#include "../ModelBase.h"

#include "FootnotesStatData.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

/// <summary>
/// Container for the page&#39;s statistical data
/// </summary>
class  PageStatData
    : public ModelBase
{
public:
    PageStatData();
    virtual ~PageStatData();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// PageStatData members

    /// <summary>
    /// Page number
    /// </summary>
    int32_t getPageNumber() const;
        void setPageNumber(int32_t value);
    /// <summary>
    /// Total count of words in the page
    /// </summary>
    int32_t getWordCount() const;
        void setWordCount(int32_t value);
    /// <summary>
    /// Total count of paragraphs in the page
    /// </summary>
    int32_t getParagraphCount() const;
        void setParagraphCount(int32_t value);
    /// <summary>
    /// Detailed statistics of footnotes
    /// </summary>
    std::shared_ptr<FootnotesStatData> getFootnotesStatData() const;
    bool footnotesStatDataIsSet() const;
    void unsetFootnotesStatData();
    void setFootnotesStatData(std::shared_ptr<FootnotesStatData> value);

protected:
    int32_t m_PageNumber;
        int32_t m_WordCount;
        int32_t m_ParagraphCount;
        std::shared_ptr<FootnotesStatData> m_FootnotesStatData;
    bool m_FootnotesStatDataIsSet;
};

}
}
}
}

#endif /* IO_SWAGGER_CLIENT_MODEL_PageStatData_H_ */
