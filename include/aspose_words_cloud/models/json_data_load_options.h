/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="json_data_load_options.h">
*   Copyright (c) 2023 Aspose.Words for Cloud
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
#include "model_base.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Represents options for parsing JSON data.
    /// An instance of this class can be passed into constructors of Aspose.Words.Reporting.JsonDataSource.
    /// </summary>
    class JsonDataLoadOptions : public ModelBase
    {
    public:
        /// <summary>
        /// Gets or sets a mode for parsing JSON simple values (null, boolean, number, integer,
        /// and string) while loading JSON. Such a mode does not affect parsing of date-time
        /// values. The default is Aspose.Words.Reporting.JsonSimpleValueParseMode.Loose.
        /// </summary>
        enum class SimpleValueParseMode
        { 
            LOOSE,
            STRICT
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~JsonDataLoadOptions() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void getFileReferences(std::vector< FileReference* >& result) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void validate() override;


        /// <summary>
        /// Gets or sets a value indicating whether a generated data source will always contain
        /// an object for a JSON root element. If a JSON root element contains a single complex
        /// property, such an object is not created by default.
        /// The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getAlwaysGenerateRootObject() const;

        /// <summary>
        /// Gets or sets a value indicating whether a generated data source will always contain
        /// an object for a JSON root element. If a JSON root element contains a single complex
        /// property, such an object is not created by default.
        /// The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setAlwaysGenerateRootObject(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets exact formats for parsing JSON date-time values while loading JSON.
        /// The default is null.
        /// Strings encoded using Microsoft® JSON date-time format (for example, "/Date(1224043200000)/")
        /// are always recognized as date-time values regardless of a value of this property.
        /// The property defines additional formats to be used while parsing date-time values
        /// from strings in the following way:
        /// • When Aspose.Words.Reporting.JsonDataLoadOptions.ExactDateTimeParseFormats is
        /// null, the ISO-8601 format and all date-time formats supported for the current,
        /// English USA, and English New Zealand cultures are used additionally in the mentioned
        /// order.
        /// • When Aspose.Words.Reporting.JsonDataLoadOptions.ExactDateTimeParseFormats contains
        /// strings, they are used as additional date-time formats utilizing the current
        /// culture.
        /// • When Aspose.Words.Reporting.JsonDataLoadOptions.ExactDateTimeParseFormats is
        /// empty, no additional date-time formats are used.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::vector<std::shared_ptr<std::wstring>> > getExactDateTimeParseFormats() const;

        /// <summary>
        /// Gets or sets exact formats for parsing JSON date-time values while loading JSON.
        /// The default is null.
        /// Strings encoded using Microsoft® JSON date-time format (for example, "/Date(1224043200000)/")
        /// are always recognized as date-time values regardless of a value of this property.
        /// The property defines additional formats to be used while parsing date-time values
        /// from strings in the following way:
        /// • When Aspose.Words.Reporting.JsonDataLoadOptions.ExactDateTimeParseFormats is
        /// null, the ISO-8601 format and all date-time formats supported for the current,
        /// English USA, and English New Zealand cultures are used additionally in the mentioned
        /// order.
        /// • When Aspose.Words.Reporting.JsonDataLoadOptions.ExactDateTimeParseFormats contains
        /// strings, they are used as additional date-time formats utilizing the current
        /// culture.
        /// • When Aspose.Words.Reporting.JsonDataLoadOptions.ExactDateTimeParseFormats is
        /// empty, no additional date-time formats are used.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExactDateTimeParseFormats(std::shared_ptr< std::vector<std::shared_ptr<std::wstring>> > value);


        /// <summary>
        /// Gets or sets a mode for parsing JSON simple values (null, boolean, number, integer,
        /// and string) while loading JSON. Such a mode does not affect parsing of date-time
        /// values. The default is Aspose.Words.Reporting.JsonSimpleValueParseMode.Loose.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::JsonDataLoadOptions::SimpleValueParseMode > getSimpleValueParseMode() const;

        /// <summary>
        /// Gets or sets a mode for parsing JSON simple values (null, boolean, number, integer,
        /// and string) while loading JSON. Such a mode does not affect parsing of date-time
        /// values. The default is Aspose.Words.Reporting.JsonSimpleValueParseMode.Loose.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSimpleValueParseMode(std::shared_ptr< aspose::words::cloud::models::JsonDataLoadOptions::SimpleValueParseMode > value);


    protected:
        std::shared_ptr< bool > m_AlwaysGenerateRootObject;
        std::shared_ptr< std::vector<std::shared_ptr<std::wstring>> > m_ExactDateTimeParseFormats;
        std::shared_ptr< aspose::words::cloud::models::JsonDataLoadOptions::SimpleValueParseMode > m_SimpleValueParseMode;
    };
}

