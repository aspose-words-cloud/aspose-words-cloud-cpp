/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SaveOptionsData.h">
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
class  SaveOptionsData
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
    /// Gets or sets format of save.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getSaveFormat() const;
    bool saveFormatIsSet() const;
    void unsetSaveFormat();
    void setSaveFormat(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets name of destination file.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getFileName() const;
    bool fileNameIsSet() const;
    void unsetFileName();
    void setFileName(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets a value determining how DrawingML shapes are rendered. { Fallback | DrawingML }.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getDmlRenderingMode() const;
    bool dmlRenderingModeIsSet() const;
    void unsetDmlRenderingMode();
    void setDmlRenderingMode(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets a value determining how DrawingML effects are rendered. { Simplified | None | Fine }.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getDmlEffectsRenderingMode() const;
    bool dmlEffectsRenderingModeIsSet() const;
    void unsetDmlEffectsRenderingMode();
    void setDmlEffectsRenderingMode(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets controls zip output or not. Default value is false.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isZipOutput() const;
    bool zipOutputIsSet() const;
    void unsetZipOutput();
    void setZipOutput(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets a value determining whether the Aspose.Words.Properties.BuiltInDocumentProperties.LastSavedTime property is updated before saving.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isUpdateLastSavedTimeProperty() const;
    bool updateLastSavedTimePropertyIsSet() const;
    void unsetUpdateLastSavedTimeProperty();
    void setUpdateLastSavedTimeProperty(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets value determining whether content of StructuredDocumentTag is updated before saving.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isUpdateSdtContent() const;
    bool updateSdtContentIsSet() const;
    void unsetUpdateSdtContent();
    void setUpdateSdtContent(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets a value determining if fields should be updated before saving the document to a fixed page format. Default value for this property is. true
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isUpdateFields() const;
    bool updateFieldsIsSet() const;
    void unsetUpdateFields();
    void setUpdateFields(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets a value determining how 3D effects are rendered.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getDml3DEffectsRenderingMode() const;
    bool dml3DEffectsRenderingModeIsSet() const;
    void unsetDml3DEffectsRenderingMode();
    void setDml3DEffectsRenderingMode(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets a value determining whether the Aspose.Words.Properties.BuiltInDocumentProperties.LastPrinted property is updated before saving.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isUpdateLastPrintedProperty() const;
    bool updateLastPrintedPropertyIsSet() const;
    void unsetUpdateLastPrintedProperty();
    void setUpdateLastPrintedProperty(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>string<DATA_TYPE_END> m_SaveFormat;
    bool m_SaveFormatIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_FileName;
    bool m_FileNameIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_DmlRenderingMode;
    bool m_DmlRenderingModeIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_DmlEffectsRenderingMode;
    bool m_DmlEffectsRenderingModeIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_ZipOutput;
    bool m_ZipOutputIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_UpdateLastSavedTimeProperty;
    bool m_UpdateLastSavedTimePropertyIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_UpdateSdtContent;
    bool m_UpdateSdtContentIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_UpdateFields;
    bool m_UpdateFieldsIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_Dml3DEffectsRenderingMode;
    bool m_Dml3DEffectsRenderingModeIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_UpdateLastPrintedProperty;
    bool m_UpdateLastPrintedPropertyIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_SaveOptionsData_H_ */
