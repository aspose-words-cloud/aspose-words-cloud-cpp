/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ReportEngineSettings.cpp">
*   Copyright (c) 2021 Aspose.Words for Cloud
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

#include "ReportEngineSettings.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

ReportEngineSettings::ReportEngineSettings()
{
    m_CsvDataLoadOptionsIsSet = false;
    m_DataSourceName = utility::conversions::to_string_t("");
    m_DataSourceNameIsSet = false;

    m_DataSourceTypeIsSet = false;

    m_ReportBuildOptionsIsSet = false;

}

ReportEngineSettings::~ReportEngineSettings()
{
}

void ReportEngineSettings::validate()
{
    // TODO: implement validation
}

web::json::value ReportEngineSettings::toJson() const
{
    web::json::value val = web::json::value::object();
    if(m_CsvDataLoadOptionsIsSet)
    {
        val[_XPLATSTR("CsvDataLoadOptions")] = ModelBase::toJson(m_CsvDataLoadOptions);
    }
    if(m_DataSourceNameIsSet)
    {
        val[_XPLATSTR("DataSourceName")] = ModelBase::toJson(m_DataSourceName);
    }
    if(m_DataSourceTypeIsSet)
    {
        val[_XPLATSTR("DataSourceType")] = ModelBase::toJson(m_DataSourceType);
    }
    if(m_ReportBuildOptionsIsSet)
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_ReportBuildOptions.begin(), m_ReportBuildOptions.end(), std::back_inserter(jsonArray),
            [&](utility::string_t item) {
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("ReportBuildOptions")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void ReportEngineSettings::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("CsvDataLoadOptions")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("CsvDataLoadOptions")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<CsvDataLoadOptions> newItem(new CsvDataLoadOptions());
            newItem->fromJson(fieldValue);
            setCsvDataLoadOptions( newItem );
        }
    }


    if(val.has_field(_XPLATSTR("DataSourceName")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DataSourceName")];
        if(!fieldValue.is_null())
        {
           setDataSourceName(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("DataSourceType")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DataSourceType")];
        if(!fieldValue.is_null())
        {
           setDataSourceType(ModelBase::enumFromJson(fieldValue));
        }
    }


    {
        m_ReportBuildOptions.clear();
        if(val.has_field(_XPLATSTR("ReportBuildOptions")) 
                            && !val[_XPLATSTR("ReportBuildOptions")].is_null())
        {
            auto arr = val[_XPLATSTR("ReportBuildOptions")].as_array();
            std::transform(arr.begin(), arr.end(), std::back_inserter(m_ReportBuildOptions), [&](web::json::value& item){
                return ModelBase::enumFromJson(item);
            });
        }
    }

}

void ReportEngineSettings::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_CsvDataLoadOptionsIsSet)
    {
        if (m_CsvDataLoadOptions.get())
        {
            m_CsvDataLoadOptions->toMultipart(multipart, _XPLATSTR("CsvDataLoadOptions."));
        }
    }


    if(m_DataSourceNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("DataSourceName"), m_DataSourceName));
    }


    if(m_DataSourceTypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("DataSourceType"), m_DataSourceType));
    }


    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_ReportBuildOptions.begin(), m_ReportBuildOptions.end(), std::back_inserter(jsonArray), [&](utility::string_t item){
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ReportBuildOptions"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }

}

void ReportEngineSettings::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

std::shared_ptr<CsvDataLoadOptions> ReportEngineSettings::getCsvDataLoadOptions() const
{
    return m_CsvDataLoadOptions;
}


void ReportEngineSettings::setCsvDataLoadOptions(std::shared_ptr<CsvDataLoadOptions> value)
{
    m_CsvDataLoadOptions = value;
    m_CsvDataLoadOptionsIsSet = true;
}

bool ReportEngineSettings::csvDataLoadOptionsIsSet() const
{
    return m_CsvDataLoadOptionsIsSet;
}

void ReportEngineSettings::unsetCsvDataLoadOptions()
{
    m_CsvDataLoadOptionsIsSet = false;
}

utility::string_t ReportEngineSettings::getDataSourceName() const
{
    return m_DataSourceName;
}


void ReportEngineSettings::setDataSourceName(utility::string_t value)
{
    m_DataSourceName = value;
    m_DataSourceNameIsSet = true;
}

bool ReportEngineSettings::dataSourceNameIsSet() const
{
    return m_DataSourceNameIsSet;
}

void ReportEngineSettings::unsetDataSourceName()
{
    m_DataSourceNameIsSet = false;
}

utility::string_t ReportEngineSettings::getDataSourceType() const
{
    return m_DataSourceType;
}


void ReportEngineSettings::setDataSourceType(utility::string_t value)
{
    m_DataSourceType = value;
    m_DataSourceTypeIsSet = true;
}

bool ReportEngineSettings::dataSourceTypeIsSet() const
{
    return m_DataSourceTypeIsSet;
}

void ReportEngineSettings::unsetDataSourceType()
{
    m_DataSourceTypeIsSet = false;
}

std::vector<utility::string_t>& ReportEngineSettings::getReportBuildOptions()
{
    return m_ReportBuildOptions;
}


void ReportEngineSettings::setReportBuildOptions(std::vector<utility::string_t> const& value)
{
    m_ReportBuildOptions = value;
    m_ReportBuildOptionsIsSet = true;
}

bool ReportEngineSettings::reportBuildOptionsIsSet() const
{
    return m_ReportBuildOptionsIsSet;
}

void ReportEngineSettings::unsetReportBuildOptions()
{
    m_ReportBuildOptionsIsSet = false;
}

}
}
}
}
}
