
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="OdtSaveOptionsData.h">
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

#ifndef IO_SWAGGER_CLIENT_MODEL_OdtSaveOptionsData_H_
#define IO_SWAGGER_CLIENT_MODEL_OdtSaveOptionsData_H_


#include "SaveOptionsData.h"
#include <cpprest/details/basic_types.h>

namespace io {
namespace swagger {
namespace client {
namespace model {

/// <summary>
/// container class for odt/ott save options
/// </summary>
class  OdtSaveOptionsData
    : public SaveOptionsData
{
public:
    OdtSaveOptionsData();
    virtual ~OdtSaveOptionsData();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// OdtSaveOptionsData members

    /// <summary>
    /// Specifies whether export should correspond to ODT specification 1.1 strictly
    /// </summary>
    bool isIsStrictSchema11() const;
    bool isStrictSchema11IsSet() const;
    void unsetIsStrictSchema11();
    void setIsStrictSchema11(bool value);
    /// <summary>
    /// Allows to specify units of measure to apply to document content. The default value is Aspose.Words.Saving.OdtSaveMeasureUnit.Centimeters  Open Office uses centimeters when specifying lengths, widths and other measurable formatting and content properties in documents whereas MS Office uses inches.
    /// </summary>
    utility::string_t getMeasureUnit() const;
    bool measureUnitIsSet() const;
    void unsetMeasureUnit();
    void setMeasureUnit(utility::string_t value);
    /// <summary>
    /// Specifies whether or not use pretty formats output
    /// </summary>
    bool isPrettyFormat() const;
    bool prettyFormatIsSet() const;
    void unsetPrettyFormat();
    void setPrettyFormat(bool value);

protected:
    bool m_IsStrictSchema11;
    bool m_IsStrictSchema11IsSet;
    utility::string_t m_MeasureUnit;
    bool m_MeasureUnitIsSet;
    bool m_PrettyFormat;
    bool m_PrettyFormatIsSet;
};

}
}
}
}

#endif /* IO_SWAGGER_CLIENT_MODEL_OdtSaveOptionsData_H_ */
