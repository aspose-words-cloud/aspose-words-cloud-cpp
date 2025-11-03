/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="structured_document_tag_base.h">
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
#include "node_link.h"
#include "structured_document_tag_list_item.h"
#include "xml_color.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// DTO container with a StructuredDocumentTagBaseDto.
    /// </summary>
    class StructuredDocumentTagBase : public NodeLink
    {
    public:
        /// <summary>
        /// Gets or sets the appearance of a structured document tag.
        /// </summary>
        enum class Appearance
        { 
            BOUNDING_BOX,
            DEFAULT,
            TAGS,
            HIDDEN
        };

        /// <summary>
        /// Gets or sets format in which the date for a date SDT is stored when the SDT is bound to an XML node in the document's data store.
        /// The default value is Aspose.Words.Markup.SdtDateStorageFormat.DateTime.
        /// Accessing this property will work only for Aspose.Words.Markup.SdtType.Date SDT type.
        /// For all other SDT types, an exception will occur.
        /// </summary>
        enum class DateStorageFormat
        { 
            DATE,
            DATE_TIME,
            DEFAULT,
            TEXT
        };

        /// <summary>
        /// Gets or sets the type of calendar for this SDT. Default is Aspose.Words.Markup.SdtCalendarType.Default.
        /// Accessing this property will work only for Aspose.Words.Markup.SdtType.Date SDT type.
        /// For all other SDT types, an exception will occur.
        /// </summary>
        enum class CalendarType
        { 
            DEFAULT,
            GREGORIAN,
            GREGORIAN_ARABIC,
            GREGORIAN_ME_FRENCH,
            GREGORIAN_US,
            GREGORIAN_XLIT_ENGLISH,
            GREGORIAN_XLIT_FRENCH,
            HEBREW,
            HIJRI,
            JAPAN,
            KOREA,
            NONE,
            SAKA,
            TAIWAN,
            THAI
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~StructuredDocumentTagBase() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void getFileReferences(std::vector< FileReference* >& result) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void validate() override;

        virtual void abstractStructuredDocumentTagBase() = 0;

        /// <summary>
        /// Gets or sets Aspose.Words.Markup.SdtListItemCollection associated with this SDT.
        /// Accessing this property will work only for Aspose.Words.Markup.SdtType.ComboBox or Aspose.Words.Markup.SdtType.DropDownList SDT types.
        /// For all other SDT types, an exception will occur.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::StructuredDocumentTagListItem>> > getListItems() const;

        /// <summary>
        /// Gets or sets Aspose.Words.Markup.SdtListItemCollection associated with this SDT.
        /// Accessing this property will work only for Aspose.Words.Markup.SdtType.ComboBox or Aspose.Words.Markup.SdtType.DropDownList SDT types.
        /// For all other SDT types, an exception will occur.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setListItems(std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::StructuredDocumentTagListItem>> > value);


        /// <summary>
        /// Gets or sets a value indicating whether current state of the Checkbox SDT. Default value for this property.
        /// Accessing this property will work only for Aspose.Words.Markup.SdtType.Checkbox SDT types.
        /// For all other SDT types, an exception will occur.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getChecked() const;

        /// <summary>
        /// Gets or sets a value indicating whether current state of the Checkbox SDT. Default value for this property.
        /// Accessing this property will work only for Aspose.Words.Markup.SdtType.Checkbox SDT types.
        /// For all other SDT types, an exception will occur.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setChecked(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the appearance of a structured document tag.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTagBase::Appearance > getAppearance() const;

        /// <summary>
        /// Gets or sets the appearance of a structured document tag.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setAppearance(std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTagBase::Appearance > value);


        /// <summary>
        /// Gets or sets the language format for the date displayed in this SDT.
        /// Accessing this property will work only for Aspose.Words.Markup.SdtType.Date SDT type.
        /// For all other SDT types, an exception will occur.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getDateDisplayLocale() const;

        /// <summary>
        /// Gets or sets the language format for the date displayed in this SDT.
        /// Accessing this property will work only for Aspose.Words.Markup.SdtType.Date SDT type.
        /// For all other SDT types, an exception will occur.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDateDisplayLocale(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets String that represents the format in which dates are displayed. Can not be null. The dates for English (U.S.) is "mm/dd/yyyy".
        /// Accessing this property will work only for Aspose.Words.Markup.SdtType.Date SDT type.
        /// For all other SDT types, an exception will occur.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getDateDisplayFormat() const;

        /// <summary>
        /// Gets or sets String that represents the format in which dates are displayed. Can not be null. The dates for English (U.S.) is "mm/dd/yyyy".
        /// Accessing this property will work only for Aspose.Words.Markup.SdtType.Date SDT type.
        /// For all other SDT types, an exception will occur.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDateDisplayFormat(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the full date and time last entered into this SDT.
        /// Accessing this property will work only for Aspose.Words.Markup.SdtType.Date SDT type.
        /// For all other SDT types, an exception will occur.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getFullDate() const;

        /// <summary>
        /// Gets or sets the full date and time last entered into this SDT.
        /// Accessing this property will work only for Aspose.Words.Markup.SdtType.Date SDT type.
        /// For all other SDT types, an exception will occur.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFullDate(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the friendly name associated with this SDT. Can not be null.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getTitle() const;

        /// <summary>
        /// Gets or sets the friendly name associated with this SDT. Can not be null.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTitle(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets format in which the date for a date SDT is stored when the SDT is bound to an XML node in the document's data store.
        /// The default value is Aspose.Words.Markup.SdtDateStorageFormat.DateTime.
        /// Accessing this property will work only for Aspose.Words.Markup.SdtType.Date SDT type.
        /// For all other SDT types, an exception will occur.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTagBase::DateStorageFormat > getDateStorageFormat() const;

        /// <summary>
        /// Gets or sets format in which the date for a date SDT is stored when the SDT is bound to an XML node in the document's data store.
        /// The default value is Aspose.Words.Markup.SdtDateStorageFormat.DateTime.
        /// Accessing this property will work only for Aspose.Words.Markup.SdtType.Date SDT type.
        /// For all other SDT types, an exception will occur.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDateStorageFormat(std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTagBase::DateStorageFormat > value);


        /// <summary>
        /// Gets or sets type of building block for this SDT. Can not be null.
        /// Accessing this property will work only for Aspose.Words.Markup.SdtType.BuildingBlockGallery and Aspose.Words.Markup.SdtType.DocPartObj SDT types.
        /// It is read-only for SDT of the document part type.
        /// For all other SDT types, an exception will occur.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getBuildingBlockGallery() const;

        /// <summary>
        /// Gets or sets type of building block for this SDT. Can not be null.
        /// Accessing this property will work only for Aspose.Words.Markup.SdtType.BuildingBlockGallery and Aspose.Words.Markup.SdtType.DocPartObj SDT types.
        /// It is read-only for SDT of the document part type.
        /// For all other SDT types, an exception will occur.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBuildingBlockGallery(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets category of building block for this SDT node. Can not be null.
        /// Accessing this property will work only for Aspose.Words.Markup.SdtType.BuildingBlockGallery and Aspose.Words.Markup.SdtType.DocPartObj SDT types.
        /// It is read-only for SDT of the document part type. For all other SDT types, an exception will occur.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getBuildingBlockCategory() const;

        /// <summary>
        /// Gets or sets category of building block for this SDT node. Can not be null.
        /// Accessing this property will work only for Aspose.Words.Markup.SdtType.BuildingBlockGallery and Aspose.Words.Markup.SdtType.DocPartObj SDT types.
        /// It is read-only for SDT of the document part type. For all other SDT types, an exception will occur.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBuildingBlockCategory(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets a value indicating whether this SDT allows multiple lines of text.
        /// Accessing this property will work only for Aspose.Words.Markup.SdtType.RichText and Aspose.Words.Markup.SdtType.PlainText SDT type.
        /// For all other SDT types, an exception will occur.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getMultiline() const;

        /// <summary>
        /// Gets or sets a value indicating whether this SDT allows multiple lines of text.
        /// Accessing this property will work only for Aspose.Words.Markup.SdtType.RichText and Aspose.Words.Markup.SdtType.PlainText SDT type.
        /// For all other SDT types, an exception will occur.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setMultiline(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the color of the structured document tag.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::XmlColor > getColor() const;

        /// <summary>
        /// Gets or sets the color of the structured document tag.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setColor(std::shared_ptr< aspose::words::cloud::models::XmlColor > value);


        /// <summary>
        /// Gets or sets the name of the style applied to the structured document tag.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getStyleName() const;

        /// <summary>
        /// Gets or sets the name of the style applied to the structured document tag.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setStyleName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the type of calendar for this SDT. Default is Aspose.Words.Markup.SdtCalendarType.Default.
        /// Accessing this property will work only for Aspose.Words.Markup.SdtType.Date SDT type.
        /// For all other SDT types, an exception will occur.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTagBase::CalendarType > getCalendarType() const;

        /// <summary>
        /// Gets or sets the type of calendar for this SDT. Default is Aspose.Words.Markup.SdtCalendarType.Default.
        /// Accessing this property will work only for Aspose.Words.Markup.SdtType.Date SDT type.
        /// For all other SDT types, an exception will occur.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setCalendarType(std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTagBase::CalendarType > value);


        /// <summary>
        /// Gets or sets a value indicating whether this SDT shall be removed from the WordProcessingML document when its contents are modified.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsTemporary() const;

        /// <summary>
        /// Gets or sets a value indicating whether this SDT shall be removed from the WordProcessingML document when its contents are modified.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsTemporary(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets Name of the Aspose.Words.BuildingBlocks.BuildingBlock containing placeholder text.
        /// Aspose.Words.BuildingBlocks.BuildingBlock with this name Aspose.Words.BuildingBlocks.BuildingBlock.Name has to be present in the Aspose.Words.Document.GlossaryDocument otherwise System.InvalidOperationException will occur.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getPlaceholderName() const;

        /// <summary>
        /// Gets or sets Name of the Aspose.Words.BuildingBlocks.BuildingBlock containing placeholder text.
        /// Aspose.Words.BuildingBlocks.BuildingBlock with this name Aspose.Words.BuildingBlocks.BuildingBlock.Name has to be present in the Aspose.Words.Document.GlossaryDocument otherwise System.InvalidOperationException will occur.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPlaceholderName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets a value indicating whether, this property will prohibit a user from deleting this SDT.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getLockContentControl() const;

        /// <summary>
        /// Gets or sets a value indicating whether, this property will prohibit a user from deleting this SDT.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLockContentControl(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether, this property will prohibit a user from editing the contents of this SDT.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getLockContents() const;

        /// <summary>
        /// Gets or sets a value indicating whether, this property will prohibit a user from editing the contents of this SDT.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLockContents(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether the content of this SDT shall be interpreted to contain placeholder text (as opposed to regular text contents within the SDT).
        /// If set to true, this state shall be resumed (showing placeholder text) upon opening his document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsShowingPlaceholderText() const;

        /// <summary>
        /// Gets or sets a value indicating whether the content of this SDT shall be interpreted to contain placeholder text (as opposed to regular text contents within the SDT).
        /// If set to true, this state shall be resumed (showing placeholder text) upon opening his document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsShowingPlaceholderText(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a tag associated with the current SDT node. Can not be null.
        /// A tag is an arbitrary string which applications can associate with SDT in order to identify it without providing a visible friendly name.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getTag() const;

        /// <summary>
        /// Gets or sets a tag associated with the current SDT node. Can not be null.
        /// A tag is an arbitrary string which applications can associate with SDT in order to identify it without providing a visible friendly name.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTag(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets a unique read-only persistent numerical Id for this SDT.
        /// Id attribute shall follow these rules:
        /// - The document shall retain SDT ids only if the whole document is cloned Aspose.Words.Document.Clone.
        /// - During Aspose.Words.DocumentBase.ImportNode(Aspose.Words.Node,System.Boolean)
        /// - Id shall be retained if import does not cause conflicts with other SDT Ids in the target document.
        /// - If multiple SDT nodes specify the same decimal number value for the Id attribute, then the first SDT in the document shall maintain this original Id, and all subsequent
        /// - SDT nodes shall have new identifiers assigned to them when the document is loaded.
        /// - During standalone SDT Aspose.Words.Markup.StructuredDocumentTag.Clone(System.Boolean,Aspose.Words.INodeCloningListener) operation new unique ID will be generated for the cloned SDT node.
        /// - If Id is not specified in the source document, then the SDT node shall have a new unique identifier assigned to it when the document is loaded.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getId() const;

        /// <summary>
        /// Gets or sets a unique read-only persistent numerical Id for this SDT.
        /// Id attribute shall follow these rules:
        /// - The document shall retain SDT ids only if the whole document is cloned Aspose.Words.Document.Clone.
        /// - During Aspose.Words.DocumentBase.ImportNode(Aspose.Words.Node,System.Boolean)
        /// - Id shall be retained if import does not cause conflicts with other SDT Ids in the target document.
        /// - If multiple SDT nodes specify the same decimal number value for the Id attribute, then the first SDT in the document shall maintain this original Id, and all subsequent
        /// - SDT nodes shall have new identifiers assigned to them when the document is loaded.
        /// - During standalone SDT Aspose.Words.Markup.StructuredDocumentTag.Clone(System.Boolean,Aspose.Words.INodeCloningListener) operation new unique ID will be generated for the cloned SDT node.
        /// - If Id is not specified in the source document, then the SDT node shall have a new unique identifier assigned to it when the document is loaded.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setId(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets a string that represents the XML contained within the node in the Aspose.Words.SaveFormat.FlatOpc format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getWordOpenXML() const;



    protected:
        std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::StructuredDocumentTagListItem>> > m_ListItems;
        std::shared_ptr< bool > m_Checked;
        std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTagBase::Appearance > m_Appearance;
        std::shared_ptr< int32_t > m_DateDisplayLocale;
        std::shared_ptr< std::wstring > m_DateDisplayFormat;
        std::shared_ptr< std::wstring > m_FullDate;
        std::shared_ptr< std::wstring > m_Title;
        std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTagBase::DateStorageFormat > m_DateStorageFormat;
        std::shared_ptr< std::wstring > m_BuildingBlockGallery;
        std::shared_ptr< std::wstring > m_BuildingBlockCategory;
        std::shared_ptr< bool > m_Multiline;
        std::shared_ptr< aspose::words::cloud::models::XmlColor > m_Color;
        std::shared_ptr< std::wstring > m_StyleName;
        std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTagBase::CalendarType > m_CalendarType;
        std::shared_ptr< bool > m_IsTemporary;
        std::shared_ptr< std::wstring > m_PlaceholderName;
        std::shared_ptr< bool > m_LockContentControl;
        std::shared_ptr< bool > m_LockContents;
        std::shared_ptr< bool > m_IsShowingPlaceholderText;
        std::shared_ptr< std::wstring > m_Tag;
        std::shared_ptr< int32_t > m_Id;
        std::shared_ptr< std::wstring > m_WordOpenXML;
    };
}

