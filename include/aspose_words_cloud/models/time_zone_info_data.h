/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="time_zone_info_data.h">
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

namespace aspose::words::cloud::models {
    /// <summary>
    /// Class to specify TimeZoneInfo parameters.
    /// </summary>
    class TimeZoneInfoData : public ModelBase
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~TimeZoneInfoData() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets base utc offset in hh:mm:ss format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getBaseUtcOffset() const;

        /// <summary>
        /// Gets or sets base utc offset in hh:mm:ss format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBaseUtcOffset(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets display name.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getDisplayName() const;

        /// <summary>
        /// Gets or sets display name.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDisplayName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets an Id string for CustomTimeZoneInfo.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getId() const;

        /// <summary>
        /// Gets or sets an Id string for CustomTimeZoneInfo.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setId(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets standard display name.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getStandardDisplayName() const;

        /// <summary>
        /// Gets or sets standard display name.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setStandardDisplayName(std::shared_ptr< std::wstring > value);


    protected:
        std::shared_ptr< std::wstring > m_BaseUtcOffset;
        std::shared_ptr< std::wstring > m_DisplayName;
        std::shared_ptr< std::wstring > m_Id;
        std::shared_ptr< std::wstring > m_StandardDisplayName;
    };
}

