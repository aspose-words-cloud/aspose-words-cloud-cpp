/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ReportEngineSettings.cpp">
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


#include "ReportEngineSettings.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

ReportEngineSettings::ReportEngineSettings()
{
    m_DataSourceType = utility::conversions::to_string_t("");
    m_DataSourceTypeIsSet = false;
    m_ReportBuildOptionsIsSet = false;
    m_DataSourceName = utility::conversions::to_string_t("");
    m_DataSourceNameIsSet = false;
    m_CsvDataLoadOptionsIsSet = false;
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

    if(m_DataSourceTypeIsSet)
    {
        val[_XPLATSTR("DataSourceType")] = ModelBase::toJson(m_DataSourceType);
    }
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_ReportBuildOptions.begin(), m_ReportBuildOptions.end(), std::back_inserter(jsonArray),
			[&](std::shared_ptr<ReportBuildOptions> item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("ReportBuildOptions")] = web::json::value::array(jsonArray);
        }
    }
    if(m_DataSourceNameIsSet)
    {
        val[_XPLATSTR("DataSourceName")] = ModelBase::toJson(m_DataSourceName);
    }
    if(m_CsvDataLoadOptionsIsSet)
    {
        val[_XPLATSTR("CsvDataLoadOptions")] = ModelBase::toJson(m_CsvDataLoadOptions);
    }

    return val;
}

void ReportEngineSettings::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("DataSourceType")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DataSourceType")];
        if(!fieldValue.is_null())
        {
            setDataSourceType(ModelBase::stringFromJson(fieldValue));
        }
    }
    {
        m_ReportBuildOptions.clear();
        if(val.has_field(_XPLATSTR("ReportBuildOptions")) 
                            && !val[_XPLATSTR("ReportBuildOptions")].is_null())
        {
        auto arr = val[_XPLATSTR("ReportBuildOptions")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_ReportBuildOptions), [&](web::json::value& item){
            if(item.is_null())
            {
                return std::shared_ptr<ReportBuildOptions>(nullptr);
            }
            else
            {
                std::shared_ptr<ReportBuildOptions> newItem(new ReportBuildOptions());
                newItem->fromJson(item);
                return newItem;
            }
        });

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
}

void ReportEngineSettings::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_DataSourceTypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("DataSourceType"), m_DataSourceType));
        
    }
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_ReportBuildOptions.begin(), m_ReportBuildOptions.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<ReportBuildOptions> item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ReportBuildOptions"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }
    if(m_DataSourceNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("DataSourceName"), m_DataSourceName));
        
    }
    if(m_CsvDataLoadOptionsIsSet)
    {
        if (m_CsvDataLoadOptions.get())
        {
            m_CsvDataLoadOptions->toMultipart(multipart, _XPLATSTR("CsvDataLoadOptions."));
        }
        
    }
}

void ReportEngineSettings::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    

    if(multipart->hasContent(_XPLATSTR("DataSourceType")))
    {
        setDataSourceType(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("DataSourceType"))));
    }
    {
        m_ReportBuildOptions.clear();
        if(multipart->hasContent(_XPLATSTR("ReportBuildOptions")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ReportBuildOptions")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_ReportBuildOptions), [&](web::json::value item) {
            if(item.is_null())
            {
                return std::shared_ptr<ReportBuildOptions>(nullptr) ;
            }
            else
            {
                std::shared_ptr<ReportBuildOptions> newItem(new ReportBuildOptions());
                newItem->fromJson(item);
                return newItem ;
            }
        });
        }
    }
    if(multipart->hasContent(_XPLATSTR("DataSourceName")))
    {
        setDataSourceName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("DataSourceName"))));
    }
    if(multipart->hasContent(_XPLATSTR("CsvDataLoadOptions")))
    {
        if(multipart->hasContent(_XPLATSTR("CsvDataLoadOptions")))
        {
            std::shared_ptr<CsvDataLoadOptions> newItem(new CsvDataLoadOptions());
            newItem->fromMultiPart(multipart, _XPLATSTR("CsvDataLoadOptions."));
            setCsvDataLoadOptions( newItem );
        }
    }
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

std::vector<std::shared_ptr<ReportBuildOptions>>& ReportEngineSettings::getReportBuildOptions()
{
    return m_ReportBuildOptions;
}

void ReportEngineSettings::setReportBuildOptions(std::vector<std::shared_ptr<ReportBuildOptions>> const& value)
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

}
}
}
}
}

