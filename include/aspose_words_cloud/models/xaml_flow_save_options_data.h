﻿/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="xaml_flow_save_options_data.h">
*   Copyright (c) 2025 Aspose.Words for Cloud
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
#include "save_options_data.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Container class for xaml flow save options.
    /// </summary>
    class XamlFlowSaveOptionsData : public SaveOptionsData
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~XamlFlowSaveOptionsData() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void getFileReferences(std::vector< FileReference* >& result) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void validate() override;

        void abstractSaveOptionsData() override {}

        /// <summary>
        /// Gets or sets the physical folder where images are saved when exporting.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getImagesFolder() const;

        /// <summary>
        /// Gets or sets the physical folder where images are saved when exporting.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setImagesFolder(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the name of the folder used to construct image URIs.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getImagesFolderAlias() const;

        /// <summary>
        /// Gets or sets the name of the folder used to construct image URIs.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setImagesFolderAlias(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the flag that indicates whether backslash characters should be replaced with yen signs.
        /// Default value is false.
        /// By default, Aspose.Words mimics MS Word's behavior and doesn't replace backslash characters with yen signs in
        /// generated HTML documents. However, previous versions of Aspose.Words performed such replacements in certain
        /// scenarios. This flag enables backward compatibility with previous versions of Aspose.Words.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getReplaceBackslashWithYenSign() const;

        /// <summary>
        /// Gets or sets the flag that indicates whether backslash characters should be replaced with yen signs.
        /// Default value is false.
        /// By default, Aspose.Words mimics MS Word's behavior and doesn't replace backslash characters with yen signs in
        /// generated HTML documents. However, previous versions of Aspose.Words performed such replacements in certain
        /// scenarios. This flag enables backward compatibility with previous versions of Aspose.Words.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setReplaceBackslashWithYenSign(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets the format of save.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getSaveFormat() const override;



    protected:
        std::shared_ptr< std::wstring > m_ImagesFolder;
        std::shared_ptr< std::wstring > m_ImagesFolderAlias;
        std::shared_ptr< bool > m_ReplaceBackslashWithYenSign;
        std::shared_ptr< std::wstring > m_SaveFormat = std::make_shared<std::wstring>(L"xamlflow");
    };
}

