/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="structured_document_tag.h">
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
#include "node_link.h"
#include "structured_document_tag_list_item.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// DTO container with a StructuredDocumentTag.
    /// </summary>
    class StructuredDocumentTag : public NodeLink
    {
    public:
        /// <summary>
        /// Gets or sets the appearance of a structured document tag.
        /// </summary>
        enum class Appearance
        { 
            DEFAULT,
            BOUNDING_BOX,
            TAGS,
            HIDDEN
        };

        /// <summary>
        /// Gets or sets the type of calendar for this SDT. Default is Aspose.Words.Markup.SdtCalendarType.Default.
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

        /// <summary>
        /// Gets or sets format in which the date for a date SDT is stored when the SDT is bound to an XML node in the document's data store.
        /// Default value is Aspose.Words.Markup.SdtDateStorageFormat.DateTime.
        /// </summary>
        enum class DateStorageFormat
        { 
            DATE,
            DATE_TIME,
            DEFAULT,
            TEXT
        };

        /// <summary>
        /// Gets or sets the level at which this SDT occurs in the document tree.
        /// </summary>
        enum class Level
        { 
            UNKNOWN,
            INLINE,
            BLOCK,
            ROW,
            CELL
        };

        /// <summary>
        /// Gets or sets type of this Structured document tag.
        /// </summary>
        enum class SdtType
        { 
            NONE,
            BIBLIOGRAPHY,
            CITATION,
            EQUATION,
            DROP_DOWN_LIST,
            COMBO_BOX,
            DATE,
            BUILDING_BLOCK_GALLERY,
            DOC_PART_OBJ,
            GROUP,
            PICTURE,
            RICH_TEXT,
            PLAIN_TEXT,
            CHECKBOX,
            REPEATING_SECTION,
            REPEATING_SECTION_ITEM,
            ENTITY_PICKER
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~StructuredDocumentTag() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void getFileReferences(std::vector< FileReference* >& result) override;


        /// <summary>
        /// Gets or sets the appearance of a structured document tag.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTag::Appearance > getAppearance() const;

        /// <summary>
        /// Gets or sets the appearance of a structured document tag.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setAppearance(std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTag::Appearance > value);


        /// <summary>
        /// Gets or sets category of building block for this SDT node. Can not be null.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getBuildingBlockCategory() const;

        /// <summary>
        /// Gets or sets category of building block for this SDT node. Can not be null.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBuildingBlockCategory(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets type of building block for this SDT. Can not be null.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getBuildingBlockGallery() const;

        /// <summary>
        /// Gets or sets type of building block for this SDT. Can not be null.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBuildingBlockGallery(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the type of calendar for this SDT. Default is Aspose.Words.Markup.SdtCalendarType.Default.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTag::CalendarType > getCalendarType() const;

        /// <summary>
        /// Gets or sets the type of calendar for this SDT. Default is Aspose.Words.Markup.SdtCalendarType.Default.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setCalendarType(std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTag::CalendarType > value);


        /// <summary>
        /// Gets or sets a value indicating whether current state of the Checkbox SDT. Default value for this property.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getChecked() const;

        /// <summary>
        /// Gets or sets a value indicating whether current state of the Checkbox SDT. Default value for this property.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setChecked(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the color of the structured document tag.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getColor() const;

        /// <summary>
        /// Gets or sets the color of the structured document tag.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setColor(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets String that represents the format in which dates are displayed. Can not be null. The dates for English (U.S.) is "mm/dd/yyyy".
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getDateDisplayFormat() const;

        /// <summary>
        /// Gets or sets String that represents the format in which dates are displayed. Can not be null. The dates for English (U.S.) is "mm/dd/yyyy".
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDateDisplayFormat(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the language format for the date displayed in this SDT.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getDateDisplayLocale() const;

        /// <summary>
        /// Gets or sets the language format for the date displayed in this SDT.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDateDisplayLocale(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets format in which the date for a date SDT is stored when the SDT is bound to an XML node in the document's data store.
        /// Default value is Aspose.Words.Markup.SdtDateStorageFormat.DateTime.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTag::DateStorageFormat > getDateStorageFormat() const;

        /// <summary>
        /// Gets or sets format in which the date for a date SDT is stored when the SDT is bound to an XML node in the document's data store.
        /// Default value is Aspose.Words.Markup.SdtDateStorageFormat.DateTime.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDateStorageFormat(std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTag::DateStorageFormat > value);


        /// <summary>
        /// Gets or sets the full date and time last entered into this SDT.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getFullDate() const;

        /// <summary>
        /// Gets or sets the full date and time last entered into this SDT.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFullDate(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets a unique read-only persistent numerical Id for this SDT.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getId() const;

        /// <summary>
        /// Gets or sets a unique read-only persistent numerical Id for this SDT.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setId(std::shared_ptr< int32_t > value);


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
        /// Gets or sets a value indicating whether this SDT shall be removed from the WordProcessingML document when its contents are modified.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsTemporary() const;

        /// <summary>
        /// Gets or sets a value indicating whether this SDT shall be removed from the WordProcessingML document when its contents are modified.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsTemporary(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the level at which this SDT occurs in the document tree.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTag::Level > getLevel() const;

        /// <summary>
        /// Gets or sets the level at which this SDT occurs in the document tree.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLevel(std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTag::Level > value);


        /// <summary>
        /// Gets or sets Aspose.Words.Markup.SdtListItemCollection associated with this SDT.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::StructuredDocumentTagListItem>> > getListItems() const;

        /// <summary>
        /// Gets or sets Aspose.Words.Markup.SdtListItemCollection associated with this SDT.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setListItems(std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::StructuredDocumentTagListItem>> > value);


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
        /// Gets or sets a value indicating whether this SDT allows multiple lines of text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getMultiline() const;

        /// <summary>
        /// Gets or sets a value indicating whether this SDT allows multiple lines of text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setMultiline(std::shared_ptr< bool > value);


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
        /// Gets or sets type of this Structured document tag.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTag::SdtType > getSdtType() const;

        /// <summary>
        /// Gets or sets type of this Structured document tag.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSdtType(std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTag::SdtType > value);


        /// <summary>
        /// Gets or sets the name of the style applied to the structured document tag.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getStyleName() const;

        /// <summary>
        /// Gets or sets the name of the style applied to the structured document tag.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setStyleName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets a tag associated with the current SDT node. Can not be null.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getTag() const;

        /// <summary>
        /// Gets or sets a tag associated with the current SDT node. Can not be null.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTag(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the friendly name associated with this SDT. Can not be null.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getTitle() const;

        /// <summary>
        /// Gets or sets the friendly name associated with this SDT. Can not be null.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTitle(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets a string that represents the XML contained within the node in the Aspose.Words.SaveFormat.FlatOpc format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getWordOpenXML() const;

        /// <summary>
        /// Gets a string that represents the XML contained within the node in the Aspose.Words.SaveFormat.FlatOpc format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setWordOpenXML(std::shared_ptr< std::wstring > value);


    protected:
        std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTag::Appearance > m_Appearance;
        std::shared_ptr< std::wstring > m_BuildingBlockCategory;
        std::shared_ptr< std::wstring > m_BuildingBlockGallery;
        std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTag::CalendarType > m_CalendarType;
        std::shared_ptr< bool > m_Checked;
        std::shared_ptr< std::wstring > m_Color;
        std::shared_ptr< std::wstring > m_DateDisplayFormat;
        std::shared_ptr< int32_t > m_DateDisplayLocale;
        std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTag::DateStorageFormat > m_DateStorageFormat;
        std::shared_ptr< std::wstring > m_FullDate;
        std::shared_ptr< int32_t > m_Id;
        std::shared_ptr< bool > m_IsShowingPlaceholderText;
        std::shared_ptr< bool > m_IsTemporary;
        std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTag::Level > m_Level;
        std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::StructuredDocumentTagListItem>> > m_ListItems;
        std::shared_ptr< bool > m_LockContentControl;
        std::shared_ptr< bool > m_LockContents;
        std::shared_ptr< bool > m_Multiline;
        std::shared_ptr< std::wstring > m_PlaceholderName;
        std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTag::SdtType > m_SdtType;
        std::shared_ptr< std::wstring > m_StyleName;
        std::shared_ptr< std::wstring > m_Tag;
        std::shared_ptr< std::wstring > m_Title;
        std::shared_ptr< std::wstring > m_WordOpenXML;
    };
}

