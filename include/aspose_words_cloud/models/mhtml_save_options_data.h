/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="mhtml_save_options_data.h">
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
#include "html_save_options_data.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Container class for mhtml save options.
    /// </summary>
    class MhtmlSaveOptionsData : public HtmlSaveOptionsData
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~MhtmlSaveOptionsData() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;

        void abstractSaveOptionsData() override {}

        /// <summary>
        /// Gets or sets a value indicating whether to use CID (Content-ID) URLs to reference resources (images, fonts, CSS) included in MHTML documents. The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getExportCidUrlsForMhtmlResources() const;

        /// <summary>
        /// Gets or sets a value indicating whether to use CID (Content-ID) URLs to reference resources (images, fonts, CSS) included in MHTML documents. The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportCidUrlsForMhtmlResources(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets the format of save.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getSaveFormat() const override;



    protected:
        std::shared_ptr< bool > m_ExportCidUrlsForMhtmlResources;
        std::shared_ptr< std::wstring > m_SaveFormat = std::make_shared<std::wstring>(L"mht");
    };
}

