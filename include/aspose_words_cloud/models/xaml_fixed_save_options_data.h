﻿/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="xaml_fixed_save_options_data.h">
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
#include "fixed_page_save_options_data.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Container class for xaml fixed save options.
    /// </summary>
    class XamlFixedSaveOptionsData : public FixedPageSaveOptionsData
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~XamlFixedSaveOptionsData() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void getFileReferences(std::vector< FileReference* >& result) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void validate() override;

        void abstractFixedPageSaveOptionsData() override {}
        void abstractSaveOptionsData() override {}

        /// <summary>
        /// Gets or sets the physical folder where resources (images and fonts) are saved when exporting a document to fixed page Xaml format.
        /// The default value is null.
        /// When you save a Document in fixed page Xaml format, Aspose.Words needs to save all images embedded in the document as standalone files. ResourcesFolder allows you to specify where the images will be saved and ResourcesFolderAlias allows to specify how the image URIs will be constructed.If you save a document into a file and provide a file name, Aspose.Words, by default, saves the images in the same folder where the document file is saved. Use ResourcesFolder to override this behavior.If you save a document into a stream, Aspose.Words does not have a folder where to save the images, but still needs to save the images somewhere. In this case, you need to specify an accessible folder by using the ResourcesFolder property.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getResourcesFolder() const;

        /// <summary>
        /// Gets or sets the physical folder where resources (images and fonts) are saved when exporting a document to fixed page Xaml format.
        /// The default value is null.
        /// When you save a Document in fixed page Xaml format, Aspose.Words needs to save all images embedded in the document as standalone files. ResourcesFolder allows you to specify where the images will be saved and ResourcesFolderAlias allows to specify how the image URIs will be constructed.If you save a document into a file and provide a file name, Aspose.Words, by default, saves the images in the same folder where the document file is saved. Use ResourcesFolder to override this behavior.If you save a document into a stream, Aspose.Words does not have a folder where to save the images, but still needs to save the images somewhere. In this case, you need to specify an accessible folder by using the ResourcesFolder property.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setResourcesFolder(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the name of the folder used to construct image URIs written into an fixed page Xaml document. The default value is null.
        /// When you save a Document in fixed page Xaml format, Aspose.Words needs to save all images embedded in the document as standalone files. ResourcesFolder allows you to specify where the images will be saved and ResourcesFolderAlias allows to specify how the image URIs will be constructed.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getResourcesFolderAlias() const;

        /// <summary>
        /// Gets or sets the name of the folder used to construct image URIs written into an fixed page Xaml document. The default value is null.
        /// When you save a Document in fixed page Xaml format, Aspose.Words needs to save all images embedded in the document as standalone files. ResourcesFolder allows you to specify where the images will be saved and ResourcesFolderAlias allows to specify how the image URIs will be constructed.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setResourcesFolderAlias(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets the format of save.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getSaveFormat() const override;



    protected:
        std::shared_ptr< std::wstring > m_ResourcesFolder;
        std::shared_ptr< std::wstring > m_ResourcesFolderAlias;
        std::shared_ptr< std::wstring > m_SaveFormat = std::make_shared<std::wstring>(L"xamlfixed");
    };
}

