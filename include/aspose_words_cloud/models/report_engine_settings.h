/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="report_engine_settings.h">
*   Copyright (c) 2022 Aspose.Words for Cloud
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

#pragma once
#include "./model_base.h"
#include "csv_data_load_options.h"
#include "json_data_load_options.h"
#include "report_build_options.h"
#include "xml_data_load_options.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Report engine settings.
    /// </summary>
    class ReportEngineSettings : public ModelBase
    {
    public:
        /// <summary>
        /// Gets or sets type of datasource.
        /// </summary>
        enum class DataSourceType
        { 
            XML,
            JSON,
            CSV
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~ReportEngineSettings() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets the options for parsing CSV data.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::CsvDataLoadOptions > getCsvDataLoadOptions() const;

        /// <summary>
        /// Gets or sets the options for parsing CSV data.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setCsvDataLoadOptions(std::shared_ptr< aspose::words::cloud::models::CsvDataLoadOptions > value);


        /// <summary>
        /// Gets or sets the name to reference the data source object in the template.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getDataSourceName() const;

        /// <summary>
        /// Gets or sets the name to reference the data source object in the template.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDataSourceName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets type of datasource.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::ReportEngineSettings::DataSourceType > getDataSourceType() const;

        /// <summary>
        /// Gets or sets type of datasource.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDataSourceType(std::shared_ptr< aspose::words::cloud::models::ReportEngineSettings::DataSourceType > value);


        /// <summary>
        /// Gets or sets the options for parsing JSON data.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::JsonDataLoadOptions > getJsonDataLoadOptions() const;

        /// <summary>
        /// Gets or sets the options for parsing JSON data.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setJsonDataLoadOptions(std::shared_ptr< aspose::words::cloud::models::JsonDataLoadOptions > value);


        /// <summary>
        /// Gets or sets type of options to build report.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::ReportBuildOptions>> > getReportBuildOptions() const;

        /// <summary>
        /// Gets or sets type of options to build report.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setReportBuildOptions(std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::ReportBuildOptions>> > value);


        /// <summary>
        /// Gets or sets the options for parsing XML data.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::XmlDataLoadOptions > getXmlDataLoadOptions() const;

        /// <summary>
        /// Gets or sets the options for parsing XML data.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setXmlDataLoadOptions(std::shared_ptr< aspose::words::cloud::models::XmlDataLoadOptions > value);


    protected:
        std::shared_ptr< aspose::words::cloud::models::CsvDataLoadOptions > m_CsvDataLoadOptions;
        std::shared_ptr< std::wstring > m_DataSourceName;
        std::shared_ptr< aspose::words::cloud::models::ReportEngineSettings::DataSourceType > m_DataSourceType;
        std::shared_ptr< aspose::words::cloud::models::JsonDataLoadOptions > m_JsonDataLoadOptions;
        std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::ReportBuildOptions>> > m_ReportBuildOptions;
        std::shared_ptr< aspose::words::cloud::models::XmlDataLoadOptions > m_XmlDataLoadOptions;
    };
}

