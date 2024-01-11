/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="watermark_data_text.h">
*   Copyright (c) 2024 Aspose.Words for Cloud
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
#include "watermark_data_base.h"
#include "xml_color.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Class for insert watermark text request building.
    /// </summary>
    class WatermarkDataText : public WatermarkDataBase
    {
    public:
        /// <summary>
        /// Gets or sets layout of the watermark. The default value is Aspose.Words.WatermarkLayout.Diagonal.
        /// </summary>
        enum class Layout
        { 
            HORIZONTAL,
            DIAGONAL
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~WatermarkDataText() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void getFileReferences(std::vector< FileReference* >& result) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void validate() override;

        void abstractWatermarkDataBase() override {}

        /// <summary>
        /// Gets or sets font color. The default value is System.Drawing.Color.Silver.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::XmlColor > getColor() const;

        /// <summary>
        /// Gets or sets font color. The default value is System.Drawing.Color.Silver.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setColor(std::shared_ptr< aspose::words::cloud::models::XmlColor > value);


        /// <summary>
        /// Gets or sets font family name. The default value is "Calibri".
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getFontFamily() const;

        /// <summary>
        /// Gets or sets font family name. The default value is "Calibri".
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFontFamily(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets a font size. The default value is 0 - auto.
        /// Valid values range from 0 to 65.5 inclusive. Auto font size means that the watermark will be scaled to its max width and max height relative to the page margins.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getFontSize() const;

        /// <summary>
        /// Gets or sets a font size. The default value is 0 - auto.
        /// Valid values range from 0 to 65.5 inclusive. Auto font size means that the watermark will be scaled to its max width and max height relative to the page margins.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFontSize(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets a boolean value which is responsible for opacity of the watermark. The default value is true.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsSemitrasparent() const;

        /// <summary>
        /// Gets or sets a boolean value which is responsible for opacity of the watermark. The default value is true.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsSemitrasparent(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets layout of the watermark. The default value is Aspose.Words.WatermarkLayout.Diagonal.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::WatermarkDataText::Layout > getLayout() const;

        /// <summary>
        /// Gets or sets layout of the watermark. The default value is Aspose.Words.WatermarkLayout.Diagonal.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLayout(std::shared_ptr< aspose::words::cloud::models::WatermarkDataText::Layout > value);


        /// <summary>
        /// Gets or sets the watermark text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getText() const;

        /// <summary>
        /// Gets or sets the watermark text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setText(std::shared_ptr< std::wstring > value);


    protected:
        std::shared_ptr< aspose::words::cloud::models::XmlColor > m_Color;
        std::shared_ptr< std::wstring > m_FontFamily;
        std::shared_ptr< double > m_FontSize;
        std::shared_ptr< bool > m_IsSemitrasparent;
        std::shared_ptr< aspose::words::cloud::models::WatermarkDataText::Layout > m_Layout;
        std::shared_ptr< std::wstring > m_Text;
    };
}

