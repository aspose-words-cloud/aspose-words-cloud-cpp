/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ReportEngineSettings.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_ReportEngineSettings_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_ReportEngineSettings_H_

#include "CsvDataLoadOptions.h"
#include "ReportBuildOptions.h"
#include "../ModelBase.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Report engine settings.
/// </summary>
class ReportEngineSettings
    : public ModelBase
{
public:
    ReportEngineSettings();
    virtual ~ReportEngineSettings();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// ReportEngineSettings members

    /// <summary>
    /// Gets or sets the options for parsing CSV data.
    /// </summary>
    std::shared_ptr<CsvDataLoadOptions> getCsvDataLoadOptions() const;
    bool csvDataLoadOptionsIsSet() const;
    void unsetCsvDataLoadOptions();
    void setCsvDataLoadOptions(std::shared_ptr<CsvDataLoadOptions> value);

    /// <summary>
    /// Gets or sets the name to reference the data source object in the template.
    /// </summary>
    utility::string_t getDataSourceName() const;
    bool dataSourceNameIsSet() const;
    void unsetDataSourceName();
    void setDataSourceName(utility::string_t value);

    /// <summary>
    /// Gets or sets type of datasource.
    /// </summary>
    utility::string_t getDataSourceType() const;
    bool dataSourceTypeIsSet() const;
    void unsetDataSourceType();
    void setDataSourceType(utility::string_t value);

    /// <summary>
    /// Gets or sets type of options to build report.
    /// </summary>
    std::vector<utility::string_t>& getReportBuildOptions();
    bool reportBuildOptionsIsSet() const;
    void unsetReportBuildOptions();
    void setReportBuildOptions(std::vector<utility::string_t> const& value);

protected:
    std::shared_ptr<CsvDataLoadOptions> m_CsvDataLoadOptions;
    bool m_CsvDataLoadOptionsIsSet;

    utility::string_t m_DataSourceName;
    bool m_DataSourceNameIsSet;

    utility::string_t m_DataSourceType;
    bool m_DataSourceTypeIsSet;

    std::vector<utility::string_t> m_ReportBuildOptions;
    bool m_ReportBuildOptionsIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_ReportEngineSettings_H_ */
