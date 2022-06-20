/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="image_entry_list.h">
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
#include "base_entry_list.h"
#include "image_entry.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Represents a list of images which will be appended to the original resource document or image.
    /// </summary>
    class ImageEntryList : public BaseEntryList
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~ImageEntryList() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;

        void abstractBaseEntryList() override {}

        /// <summary>
        /// Gets or sets a value indicating whether each image should be added to a new page in the document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getAppendEachImageOnNewPage() const;

        /// <summary>
        /// Gets or sets a value indicating whether each image should be added to a new page in the document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setAppendEachImageOnNewPage(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the list of images.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::ImageEntry>> > getImageEntries() const;

        /// <summary>
        /// Gets or sets the list of images.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setImageEntries(std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::ImageEntry>> > value);


    protected:
        std::shared_ptr< bool > m_AppendEachImageOnNewPage;
        std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::ImageEntry>> > m_ImageEntries;
    };
}

