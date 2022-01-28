/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="modification_operation_result.h">
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
#include "file_link.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// result of the operation which modifies the original document and saves the result.
    /// </summary>
    class ModificationOperationResult : public ModelBase
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~ModificationOperationResult() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets the link to the dest document (result of the modification operation).
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::FileLink > getDest() const;

        /// <summary>
        /// Gets or sets the link to the dest document (result of the modification operation).
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDest(std::shared_ptr< aspose::words::cloud::models::FileLink > value);


        /// <summary>
        /// Gets or sets the link to the source document (source for the modification operation).
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::FileLink > getSource() const;

        /// <summary>
        /// Gets or sets the link to the source document (source for the modification operation).
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSource(std::shared_ptr< aspose::words::cloud::models::FileLink > value);


    protected:
        std::shared_ptr< aspose::words::cloud::models::FileLink > m_Dest;
        std::shared_ptr< aspose::words::cloud::models::FileLink > m_Source;
    };
}

