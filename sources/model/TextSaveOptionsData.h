
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TextSaveOptionsData.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_TextSaveOptionsData_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_TextSaveOptionsData_H_


#include "SaveOptionsData.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Container class for text save options.
/// </summary>
class  TextSaveOptionsData
    : public SaveOptionsData
{
public:
    TextSaveOptionsData();
    virtual ~TextSaveOptionsData();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// TextSaveOptionsData members

    /// <summary>
    /// Gets or sets specifies whether to add bi-directional marks before each BiDi run when exporting in plain text format. The default value is true.
    /// </summary>
    bool isAddBidiMarks() const;
    bool addBidiMarksIsSet() const;
    void unsetAddBidiMarks();
    void setAddBidiMarks(bool value);
    /// <summary>
    /// Gets or sets specifies the encoding to use when exporting in plain text format.
    /// </summary>
    utility::string_t getEncoding() const;
    bool encodingIsSet() const;
    void unsetEncoding();
    void setEncoding(utility::string_t value);
    /// <summary>
    /// Gets or sets specifies whether to output headers and footers when exporting in plain text format. default value is TxtExportHeadersFootersMode.PrimaryOnly.
    /// </summary>
    utility::string_t getExportHeadersFootersMode() const;
    bool exportHeadersFootersModeIsSet() const;
    void unsetExportHeadersFootersMode();
    void setExportHeadersFootersMode(utility::string_t value);
    /// <summary>
    /// Gets or sets allows to specify whether the page breaks should be preserved during export. The default value is false.
    /// </summary>
    bool isForcePageBreaks() const;
    bool forcePageBreaksIsSet() const;
    void unsetForcePageBreaks();
    void setForcePageBreaks(bool value);
    /// <summary>
    /// Gets or sets specifies the string to use as a paragraph break when exporting in plain text format.
    /// </summary>
    utility::string_t getParagraphBreak() const;
    bool paragraphBreakIsSet() const;
    void unsetParagraphBreak();
    void setParagraphBreak(utility::string_t value);
    /// <summary>
    /// Gets or sets specifies whether the program should attempt to preserve layout of tables when saving in the plain text format.
    /// </summary>
    bool isPreserveTableLayout() const;
    bool preserveTableLayoutIsSet() const;
    void unsetPreserveTableLayout();
    void setPreserveTableLayout(bool value);
    /// <summary>
    /// Gets or sets specifies whether the program should simplify list labels in case of complex label formatting not being adequately represented by plain text.
    /// </summary>
    bool isSimplifyListLabels() const;
    bool simplifyListLabelsIsSet() const;
    void unsetSimplifyListLabels();
    void setSimplifyListLabels(bool value);

protected:
    bool m_AddBidiMarks;
    bool m_AddBidiMarksIsSet;
    utility::string_t m_Encoding;
    bool m_EncodingIsSet;
    utility::string_t m_ExportHeadersFootersMode;
    bool m_ExportHeadersFootersModeIsSet;
    bool m_ForcePageBreaks;
    bool m_ForcePageBreaksIsSet;
    utility::string_t m_ParagraphBreak;
    bool m_ParagraphBreakIsSet;
    bool m_PreserveTableLayout;
    bool m_PreserveTableLayoutIsSet;
    bool m_SimplifyListLabels;
    bool m_SimplifyListLabelsIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_TextSaveOptionsData_H_ */
