/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SaveOptionsData.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_SaveOptionsData_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_SaveOptionsData_H_

#include "../ModelBase.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// base container class for save options data.
/// </summary>
class SaveOptionsData
    : public ModelBase
{
public:
    SaveOptionsData();
    virtual ~SaveOptionsData();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// SaveOptionsData members

    /// <summary>
    /// Gets or sets a value determining how 3D effects are rendered.
    /// </summary>
    utility::string_t getDml3DEffectsRenderingMode() const;
    bool dml3DEffectsRenderingModeIsSet() const;
    void unsetDml3DEffectsRenderingMode();
    void setDml3DEffectsRenderingMode(utility::string_t value);

    /// <summary>
    /// Gets or sets a value determining how DrawingML effects are rendered.
    /// { Simplified | None | Fine }.
    /// </summary>
    utility::string_t getDmlEffectsRenderingMode() const;
    bool dmlEffectsRenderingModeIsSet() const;
    void unsetDmlEffectsRenderingMode();
    void setDmlEffectsRenderingMode(utility::string_t value);

    /// <summary>
    /// Gets or sets a value determining how DrawingML shapes are rendered.
    /// { Fallback | DrawingML }.
    /// </summary>
    utility::string_t getDmlRenderingMode() const;
    bool dmlRenderingModeIsSet() const;
    void unsetDmlRenderingMode();
    void setDmlRenderingMode(utility::string_t value);

    /// <summary>
    /// Gets or sets name of destination file.
    /// </summary>
    utility::string_t getFileName() const;
    bool fileNameIsSet() const;
    void unsetFileName();
    void setFileName(utility::string_t value);

    /// <summary>
    /// Gets or sets format of save.
    /// </summary>
    utility::string_t getSaveFormat() const;
    bool saveFormatIsSet() const;
    void unsetSaveFormat();
    void setSaveFormat(utility::string_t value);

    /// <summary>
    /// Gets or sets a value determining if fields should be updated before saving the document to a fixed page format.
    /// Default value for this property is. true.
    /// </summary>
    bool isUpdateFields() const;
    bool updateFieldsIsSet() const;
    void unsetUpdateFields();
    void setUpdateFields(bool value);

    /// <summary>
    /// Gets or sets a value determining whether the Aspose.Words.Properties.BuiltInDocumentProperties.LastPrinted
    /// property is updated before saving.
    /// </summary>
    bool isUpdateLastPrintedProperty() const;
    bool updateLastPrintedPropertyIsSet() const;
    void unsetUpdateLastPrintedProperty();
    void setUpdateLastPrintedProperty(bool value);

    /// <summary>
    /// Gets or sets a value determining whether the Aspose.Words.Properties.BuiltInDocumentProperties.LastSavedTime property is updated before saving.
    /// </summary>
    bool isUpdateLastSavedTimeProperty() const;
    bool updateLastSavedTimePropertyIsSet() const;
    void unsetUpdateLastSavedTimeProperty();
    void setUpdateLastSavedTimeProperty(bool value);

    /// <summary>
    /// Gets or sets value determining whether content of StructuredDocumentTag is updated before saving.
    /// </summary>
    bool isUpdateSdtContent() const;
    bool updateSdtContentIsSet() const;
    void unsetUpdateSdtContent();
    void setUpdateSdtContent(bool value);

    /// <summary>
    /// Gets or sets controls zip output or not.
    /// Default value is false.
    /// </summary>
    bool isZipOutput() const;
    bool zipOutputIsSet() const;
    void unsetZipOutput();
    void setZipOutput(bool value);

protected:
    utility::string_t m_Dml3DEffectsRenderingMode;
    bool m_Dml3DEffectsRenderingModeIsSet;

    utility::string_t m_DmlEffectsRenderingMode;
    bool m_DmlEffectsRenderingModeIsSet;

    utility::string_t m_DmlRenderingMode;
    bool m_DmlRenderingModeIsSet;

    utility::string_t m_FileName;
    bool m_FileNameIsSet;

    utility::string_t m_SaveFormat;
    bool m_SaveFormatIsSet;

    bool m_UpdateFields;
    bool m_UpdateFieldsIsSet;

    bool m_UpdateLastPrintedProperty;
    bool m_UpdateLastPrintedPropertyIsSet;

    bool m_UpdateLastSavedTimeProperty;
    bool m_UpdateLastSavedTimePropertyIsSet;

    bool m_UpdateSdtContent;
    bool m_UpdateSdtContentIsSet;

    bool m_ZipOutput;
    bool m_ZipOutputIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_SaveOptionsData_H_ */
