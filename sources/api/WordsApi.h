/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="WordsApi.h">
*   Copyright (c) 2020 Aspose.Words for Cloud
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

#ifndef ASPOSE_WORDS_CLOUD_API_WordsApi_H_
#define ASPOSE_WORDS_CLOUD_API_WordsApi_H_

#include "../ApiClient.h"
#include "../model/WordsApiErrorResponse.h"

#include "FormFieldTextInput.h"
#include "FormFieldCheckbox.h"
#include "FormFieldDropDown.h"

#include "requests/AcceptAllRevisionsRequest.h"
#include "requests/AcceptAllRevisionsOnlineRequest.h"
#include "requests/AppendDocumentRequest.h"
#include "requests/AppendDocumentOnlineRequest.h"
#include "requests/ApplyStyleToDocumentElementRequest.h"
#include "requests/ApplyStyleToDocumentElementOnlineRequest.h"
#include "requests/BuildReportRequest.h"
#include "requests/BuildReportOnlineRequest.h"
#include "requests/ClassifyRequest.h"
#include "requests/ClassifyDocumentRequest.h"
#include "requests/ClassifyDocumentOnlineRequest.h"
#include "requests/CompareDocumentRequest.h"
#include "requests/CompareDocumentOnlineRequest.h"
#include "requests/ConvertDocumentRequest.h"
#include "requests/CopyFileRequest.h"
#include "requests/CopyFolderRequest.h"
#include "requests/CopyStyleRequest.h"
#include "requests/CopyStyleOnlineRequest.h"
#include "requests/CreateDocumentRequest.h"
#include "requests/CreateFolderRequest.h"
#include "requests/CreateOrUpdateDocumentPropertyRequest.h"
#include "requests/CreateOrUpdateDocumentPropertyOnlineRequest.h"
#include "requests/DeleteAllParagraphTabStopsRequest.h"
#include "requests/DeleteBorderRequest.h"
#include "requests/DeleteBorderOnlineRequest.h"
#include "requests/DeleteBordersRequest.h"
#include "requests/DeleteBordersOnlineRequest.h"
#include "requests/DeleteCommentRequest.h"
#include "requests/DeleteCommentOnlineRequest.h"
#include "requests/DeleteDocumentPropertyRequest.h"
#include "requests/DeleteDocumentPropertyOnlineRequest.h"
#include "requests/DeleteDrawingObjectRequest.h"
#include "requests/DeleteDrawingObjectOnlineRequest.h"
#include "requests/DeleteFieldRequest.h"
#include "requests/DeleteFieldOnlineRequest.h"
#include "requests/DeleteFieldsRequest.h"
#include "requests/DeleteFieldsOnlineRequest.h"
#include "requests/DeleteFileRequest.h"
#include "requests/DeleteFolderRequest.h"
#include "requests/DeleteFootnoteRequest.h"
#include "requests/DeleteFootnoteOnlineRequest.h"
#include "requests/DeleteFormFieldRequest.h"
#include "requests/DeleteFormFieldOnlineRequest.h"
#include "requests/DeleteHeaderFooterRequest.h"
#include "requests/DeleteHeaderFooterOnlineRequest.h"
#include "requests/DeleteHeadersFootersRequest.h"
#include "requests/DeleteHeadersFootersOnlineRequest.h"
#include "requests/DeleteMacrosRequest.h"
#include "requests/DeleteMacrosOnlineRequest.h"
#include "requests/DeleteOfficeMathObjectRequest.h"
#include "requests/DeleteOfficeMathObjectOnlineRequest.h"
#include "requests/DeleteParagraphRequest.h"
#include "requests/DeleteParagraphListFormatRequest.h"
#include "requests/DeleteParagraphListFormatOnlineRequest.h"
#include "requests/DeleteParagraphOnlineRequest.h"
#include "requests/DeleteParagraphTabStopRequest.h"
#include "requests/DeleteRunRequest.h"
#include "requests/DeleteRunOnlineRequest.h"
#include "requests/DeleteSectionRequest.h"
#include "requests/DeleteSectionOnlineRequest.h"
#include "requests/DeleteTableRequest.h"
#include "requests/DeleteTableCellRequest.h"
#include "requests/DeleteTableCellOnlineRequest.h"
#include "requests/DeleteTableOnlineRequest.h"
#include "requests/DeleteTableRowRequest.h"
#include "requests/DeleteTableRowOnlineRequest.h"
#include "requests/DeleteWatermarkRequest.h"
#include "requests/DeleteWatermarkOnlineRequest.h"
#include "requests/DownloadFileRequest.h"
#include "requests/ExecuteMailMergeRequest.h"
#include "requests/ExecuteMailMergeOnlineRequest.h"
#include "requests/GetAvailableFontsRequest.h"
#include "requests/GetBookmarkByNameRequest.h"
#include "requests/GetBookmarkByNameOnlineRequest.h"
#include "requests/GetBookmarksRequest.h"
#include "requests/GetBookmarksOnlineRequest.h"
#include "requests/GetBorderRequest.h"
#include "requests/GetBorderOnlineRequest.h"
#include "requests/GetBordersRequest.h"
#include "requests/GetBordersOnlineRequest.h"
#include "requests/GetCommentRequest.h"
#include "requests/GetCommentOnlineRequest.h"
#include "requests/GetCommentsRequest.h"
#include "requests/GetCommentsOnlineRequest.h"
#include "requests/GetDocumentRequest.h"
#include "requests/GetDocumentDrawingObjectByIndexRequest.h"
#include "requests/GetDocumentDrawingObjectByIndexOnlineRequest.h"
#include "requests/GetDocumentDrawingObjectImageDataRequest.h"
#include "requests/GetDocumentDrawingObjectImageDataOnlineRequest.h"
#include "requests/GetDocumentDrawingObjectOleDataRequest.h"
#include "requests/GetDocumentDrawingObjectOleDataOnlineRequest.h"
#include "requests/GetDocumentDrawingObjectsRequest.h"
#include "requests/GetDocumentDrawingObjectsOnlineRequest.h"
#include "requests/GetDocumentFieldNamesRequest.h"
#include "requests/GetDocumentFieldNamesOnlineRequest.h"
#include "requests/GetDocumentHyperlinkByIndexRequest.h"
#include "requests/GetDocumentHyperlinkByIndexOnlineRequest.h"
#include "requests/GetDocumentHyperlinksRequest.h"
#include "requests/GetDocumentHyperlinksOnlineRequest.h"
#include "requests/GetDocumentPropertiesRequest.h"
#include "requests/GetDocumentPropertiesOnlineRequest.h"
#include "requests/GetDocumentPropertyRequest.h"
#include "requests/GetDocumentPropertyOnlineRequest.h"
#include "requests/GetDocumentProtectionRequest.h"
#include "requests/GetDocumentProtectionOnlineRequest.h"
#include "requests/GetDocumentStatisticsRequest.h"
#include "requests/GetDocumentStatisticsOnlineRequest.h"
#include "requests/GetDocumentWithFormatRequest.h"
#include "requests/GetFieldRequest.h"
#include "requests/GetFieldOnlineRequest.h"
#include "requests/GetFieldsRequest.h"
#include "requests/GetFieldsOnlineRequest.h"
#include "requests/GetFilesListRequest.h"
#include "requests/GetFootnoteRequest.h"
#include "requests/GetFootnoteOnlineRequest.h"
#include "requests/GetFootnotesRequest.h"
#include "requests/GetFootnotesOnlineRequest.h"
#include "requests/GetFormFieldRequest.h"
#include "requests/GetFormFieldOnlineRequest.h"
#include "requests/GetFormFieldsRequest.h"
#include "requests/GetFormFieldsOnlineRequest.h"
#include "requests/GetHeaderFooterRequest.h"
#include "requests/GetHeaderFooterOfSectionRequest.h"
#include "requests/GetHeaderFooterOfSectionOnlineRequest.h"
#include "requests/GetHeaderFooterOnlineRequest.h"
#include "requests/GetHeaderFootersRequest.h"
#include "requests/GetHeaderFootersOnlineRequest.h"
#include "requests/GetListRequest.h"
#include "requests/GetListOnlineRequest.h"
#include "requests/GetListsRequest.h"
#include "requests/GetListsOnlineRequest.h"
#include "requests/GetOfficeMathObjectRequest.h"
#include "requests/GetOfficeMathObjectOnlineRequest.h"
#include "requests/GetOfficeMathObjectsRequest.h"
#include "requests/GetOfficeMathObjectsOnlineRequest.h"
#include "requests/GetParagraphRequest.h"
#include "requests/GetParagraphFormatRequest.h"
#include "requests/GetParagraphFormatOnlineRequest.h"
#include "requests/GetParagraphListFormatRequest.h"
#include "requests/GetParagraphListFormatOnlineRequest.h"
#include "requests/GetParagraphOnlineRequest.h"
#include "requests/GetParagraphsRequest.h"
#include "requests/GetParagraphsOnlineRequest.h"
#include "requests/GetParagraphTabStopsRequest.h"
#include "requests/GetParagraphTabStopsOnlineRequest.h"
#include "requests/GetRangeTextRequest.h"
#include "requests/GetRangeTextOnlineRequest.h"
#include "requests/GetRunRequest.h"
#include "requests/GetRunFontRequest.h"
#include "requests/GetRunFontOnlineRequest.h"
#include "requests/GetRunOnlineRequest.h"
#include "requests/GetRunsRequest.h"
#include "requests/GetRunsOnlineRequest.h"
#include "requests/GetSectionRequest.h"
#include "requests/GetSectionOnlineRequest.h"
#include "requests/GetSectionPageSetupRequest.h"
#include "requests/GetSectionPageSetupOnlineRequest.h"
#include "requests/GetSectionsRequest.h"
#include "requests/GetSectionsOnlineRequest.h"
#include "requests/GetStyleRequest.h"
#include "requests/GetStyleFromDocumentElementRequest.h"
#include "requests/GetStyleFromDocumentElementOnlineRequest.h"
#include "requests/GetStyleOnlineRequest.h"
#include "requests/GetStylesRequest.h"
#include "requests/GetStylesOnlineRequest.h"
#include "requests/GetTableRequest.h"
#include "requests/GetTableCellRequest.h"
#include "requests/GetTableCellFormatRequest.h"
#include "requests/GetTableCellFormatOnlineRequest.h"
#include "requests/GetTableCellOnlineRequest.h"
#include "requests/GetTableOnlineRequest.h"
#include "requests/GetTablePropertiesRequest.h"
#include "requests/GetTablePropertiesOnlineRequest.h"
#include "requests/GetTableRowRequest.h"
#include "requests/GetTableRowFormatRequest.h"
#include "requests/GetTableRowFormatOnlineRequest.h"
#include "requests/GetTableRowOnlineRequest.h"
#include "requests/GetTablesRequest.h"
#include "requests/GetTablesOnlineRequest.h"
#include "requests/InsertCommentRequest.h"
#include "requests/InsertCommentOnlineRequest.h"
#include "requests/InsertDrawingObjectRequest.h"
#include "requests/InsertDrawingObjectOnlineRequest.h"
#include "requests/InsertFieldRequest.h"
#include "requests/InsertFieldOnlineRequest.h"
#include "requests/InsertFootnoteRequest.h"
#include "requests/InsertFootnoteOnlineRequest.h"
#include "requests/InsertFormFieldRequest.h"
#include "requests/InsertFormFieldOnlineRequest.h"
#include "requests/InsertHeaderFooterRequest.h"
#include "requests/InsertHeaderFooterOnlineRequest.h"
#include "requests/InsertListRequest.h"
#include "requests/InsertListOnlineRequest.h"
#include "requests/InsertOrUpdateParagraphTabStopRequest.h"
#include "requests/InsertOrUpdateParagraphTabStopOnlineRequest.h"
#include "requests/InsertPageNumbersRequest.h"
#include "requests/InsertPageNumbersOnlineRequest.h"
#include "requests/InsertParagraphRequest.h"
#include "requests/InsertParagraphOnlineRequest.h"
#include "requests/InsertRunRequest.h"
#include "requests/InsertRunOnlineRequest.h"
#include "requests/InsertStyleRequest.h"
#include "requests/InsertStyleOnlineRequest.h"
#include "requests/InsertTableRequest.h"
#include "requests/InsertTableCellRequest.h"
#include "requests/InsertTableCellOnlineRequest.h"
#include "requests/InsertTableOnlineRequest.h"
#include "requests/InsertTableRowRequest.h"
#include "requests/InsertTableRowOnlineRequest.h"
#include "requests/InsertWatermarkImageRequest.h"
#include "requests/InsertWatermarkImageOnlineRequest.h"
#include "requests/InsertWatermarkTextRequest.h"
#include "requests/InsertWatermarkTextOnlineRequest.h"
#include "requests/LoadWebDocumentRequest.h"
#include "requests/MoveFileRequest.h"
#include "requests/MoveFolderRequest.h"
#include "requests/OptimizeDocumentRequest.h"
#include "requests/OptimizeDocumentOnlineRequest.h"
#include "requests/ProtectDocumentRequest.h"
#include "requests/ProtectDocumentOnlineRequest.h"
#include "requests/RejectAllRevisionsRequest.h"
#include "requests/RejectAllRevisionsOnlineRequest.h"
#include "requests/RemoveRangeRequest.h"
#include "requests/RemoveRangeOnlineRequest.h"
#include "requests/RenderDrawingObjectRequest.h"
#include "requests/RenderDrawingObjectOnlineRequest.h"
#include "requests/RenderMathObjectRequest.h"
#include "requests/RenderMathObjectOnlineRequest.h"
#include "requests/RenderPageRequest.h"
#include "requests/RenderPageOnlineRequest.h"
#include "requests/RenderParagraphRequest.h"
#include "requests/RenderParagraphOnlineRequest.h"
#include "requests/RenderTableRequest.h"
#include "requests/RenderTableOnlineRequest.h"
#include "requests/ReplaceTextRequest.h"
#include "requests/ReplaceTextOnlineRequest.h"
#include "requests/ReplaceWithTextRequest.h"
#include "requests/ReplaceWithTextOnlineRequest.h"
#include "requests/ResetCacheRequest.h"
#include "requests/SaveAsRequest.h"
#include "requests/SaveAsOnlineRequest.h"
#include "requests/SaveAsRangeRequest.h"
#include "requests/SaveAsRangeOnlineRequest.h"
#include "requests/SaveAsTiffRequest.h"
#include "requests/SaveAsTiffOnlineRequest.h"
#include "requests/SearchRequest.h"
#include "requests/SearchOnlineRequest.h"
#include "requests/SplitDocumentRequest.h"
#include "requests/SplitDocumentOnlineRequest.h"
#include "requests/UnprotectDocumentRequest.h"
#include "requests/UnprotectDocumentOnlineRequest.h"
#include "requests/UpdateBookmarkRequest.h"
#include "requests/UpdateBookmarkOnlineRequest.h"
#include "requests/UpdateBorderRequest.h"
#include "requests/UpdateBorderOnlineRequest.h"
#include "requests/UpdateCommentRequest.h"
#include "requests/UpdateCommentOnlineRequest.h"
#include "requests/UpdateDrawingObjectRequest.h"
#include "requests/UpdateDrawingObjectOnlineRequest.h"
#include "requests/UpdateFieldRequest.h"
#include "requests/UpdateFieldOnlineRequest.h"
#include "requests/UpdateFieldsRequest.h"
#include "requests/UpdateFieldsOnlineRequest.h"
#include "requests/UpdateFootnoteRequest.h"
#include "requests/UpdateFootnoteOnlineRequest.h"
#include "requests/UpdateFormFieldRequest.h"
#include "requests/UpdateFormFieldOnlineRequest.h"
#include "requests/UpdateListRequest.h"
#include "requests/UpdateListLevelRequest.h"
#include "requests/UpdateListLevelOnlineRequest.h"
#include "requests/UpdateListOnlineRequest.h"
#include "requests/UpdateParagraphFormatRequest.h"
#include "requests/UpdateParagraphFormatOnlineRequest.h"
#include "requests/UpdateParagraphListFormatRequest.h"
#include "requests/UpdateParagraphListFormatOnlineRequest.h"
#include "requests/UpdateRunRequest.h"
#include "requests/UpdateRunFontRequest.h"
#include "requests/UpdateRunFontOnlineRequest.h"
#include "requests/UpdateRunOnlineRequest.h"
#include "requests/UpdateSectionPageSetupRequest.h"
#include "requests/UpdateSectionPageSetupOnlineRequest.h"
#include "requests/UpdateStyleRequest.h"
#include "requests/UpdateStyleOnlineRequest.h"
#include "requests/UpdateTableCellFormatRequest.h"
#include "requests/UpdateTableCellFormatOnlineRequest.h"
#include "requests/UpdateTablePropertiesRequest.h"
#include "requests/UpdateTablePropertiesOnlineRequest.h"
#include "requests/UpdateTableRowFormatRequest.h"
#include "requests/UpdateTableRowFormatOnlineRequest.h"
#include "requests/UploadFileRequest.h"

#include "ApiError.h"
#include "AvailableFontsResponse.h"
#include "BmpSaveOptionsData.h"
#include "Bookmark.h"
#include "BookmarkData.h"
#include "BookmarkResponse.h"
#include "Bookmarks.h"
#include "BookmarksOutlineLevelData.h"
#include "BookmarksResponse.h"
#include "Border.h"
#include "BorderResponse.h"
#include "BordersCollection.h"
#include "BordersResponse.h"
#include "ClassificationResponse.h"
#include "ClassificationResult.h"
#include "Comment.h"
#include "CommentBase.h"
#include "CommentInsert.h"
#include "CommentLink.h"
#include "CommentResponse.h"
#include "CommentsCollection.h"
#include "CommentsResponse.h"
#include "CommentUpdate.h"
#include "CompareData.h"
#include "CompareOptions.h"
#include "CsvDataLoadOptions.h"
#include "DocSaveOptionsData.h"
#include "Document.h"
#include "DocumentEntry.h"
#include "DocumentEntryList.h"
#include "DocumentPosition.h"
#include "DocumentProperties.h"
#include "DocumentPropertiesResponse.h"
#include "DocumentProperty.h"
#include "DocumentPropertyBase.h"
#include "DocumentPropertyCreateOrUpdate.h"
#include "DocumentPropertyResponse.h"
#include "DocumentResponse.h"
#include "DocumentStatData.h"
#include "DownsampleOptionsData.h"
#include "DrawingObject.h"
#include "DrawingObjectCollection.h"
#include "DrawingObjectInsert.h"
#include "DrawingObjectLink.h"
#include "DrawingObjectResponse.h"
#include "DrawingObjectsResponse.h"
#include "DrawingObjectUpdate.h"
#include "EmfSaveOptionsData.h"
#include "EpubSaveOptionsData.h"
#include "Error.h"
#include "ErrorDetails.h"
#include "Field.h"
#include "FieldBase.h"
#include "FieldCollection.h"
#include "FieldInsert.h"
#include "FieldLink.h"
#include "FieldNames.h"
#include "FieldNamesResponse.h"
#include "FieldResponse.h"
#include "FieldsResponse.h"
#include "FieldUpdate.h"
#include "FileLink.h"
#include "FilesList.h"
#include "FilesUploadResult.h"
#include "FixedPageSaveOptionsData.h"
#include "Font.h"
#include "FontDto.h"
#include "FontInfo.h"
#include "FontResponse.h"
#include "Footnote.h"
#include "FootnoteBase.h"
#include "FootnoteCollection.h"
#include "FootnoteInsert.h"
#include "FootnoteLink.h"
#include "FootnoteResponse.h"
#include "FootnotesResponse.h"
#include "FootnotesStatData.h"
#include "FootnoteUpdate.h"
#include "FormField.h"
#include "FormFieldCheckbox.h"
#include "FormFieldCollection.h"
#include "FormFieldDropDown.h"
#include "FormFieldResponse.h"
#include "FormFieldsResponse.h"
#include "FormFieldTextInput.h"
#include "GifSaveOptionsData.h"
#include "GraphicsQualityOptionsData.h"
#include "HeaderFooter.h"
#include "HeaderFooterLink.h"
#include "HeaderFooterLinkCollection.h"
#include "HeaderFooterResponse.h"
#include "HeaderFootersResponse.h"
#include "HtmlFixedSaveOptionsData.h"
#include "HtmlSaveOptionsData.h"
#include "Hyperlink.h"
#include "HyperlinkResponse.h"
#include "Hyperlinks.h"
#include "HyperlinksResponse.h"
#include "ImageSaveOptionsData.h"
#include "JpegSaveOptionsData.h"
#include "Link.h"
#include "LinkElement.h"
#include "ListFormat.h"
#include "ListFormatUpdate.h"
#include "ListInfo.h"
#include "ListInsert.h"
#include "ListLevel.h"
#include "ListLevels.h"
#include "ListLevelUpdate.h"
#include "ListResponse.h"
#include "Lists.h"
#include "ListsResponse.h"
#include "ListUpdate.h"
#include "LoadWebDocumentData.h"
#include "MarkdownSaveOptionsData.h"
#include "MetafileRenderingOptionsData.h"
#include "MhtmlSaveOptionsData.h"
#include "ModificationOperationResult.h"
#include "NodeLink.h"
#include "OdtSaveOptionsData.h"
#include "OfficeMathLink.h"
#include "OfficeMathObject.h"
#include "OfficeMathObjectResponse.h"
#include "OfficeMathObjectsCollection.h"
#include "OfficeMathObjectsResponse.h"
#include "OoxmlSaveOptionsData.h"
#include "OptimizationOptions.h"
#include "OutlineOptionsData.h"
#include "PageNumber.h"
#include "PageSetup.h"
#include "PageStatData.h"
#include "Paragraph.h"
#include "ParagraphFormat.h"
#include "ParagraphFormatBase.h"
#include "ParagraphFormatResponse.h"
#include "ParagraphFormatUpdate.h"
#include "ParagraphInsert.h"
#include "ParagraphLink.h"
#include "ParagraphLinkCollection.h"
#include "ParagraphLinkCollectionResponse.h"
#include "ParagraphListFormatResponse.h"
#include "ParagraphResponse.h"
#include "PclSaveOptionsData.h"
#include "PdfDigitalSignatureDetailsData.h"
#include "PdfEncryptionDetailsData.h"
#include "PdfSaveOptionsData.h"
#include "PngSaveOptionsData.h"
#include "PreferredWidth.h"
#include "ProtectionData.h"
#include "ProtectionDataResponse.h"
#include "ProtectionRequest.h"
#include "PsSaveOptionsData.h"
#include "RangeDocument.h"
#include "RangeDocumentDto.h"
#include "RangeTextResponse.h"
#include "ReplaceRange.h"
#include "ReplaceRangeDto.h"
#include "ReplaceTextParameters.h"
#include "ReplaceTextResponse.h"
#include "ReportBuildOptions.h"
#include "ReportEngineSettings.h"
#include "RevisionsModificationResponse.h"
#include "RtfSaveOptionsData.h"
#include "Run.h"
#include "RunBase.h"
#include "RunInsert.h"
#include "RunLink.h"
#include "RunResponse.h"
#include "Runs.h"
#include "RunsResponse.h"
#include "RunUpdate.h"
#include "SaveOptionsData.h"
#include "SaveResponse.h"
#include "SaveResult.h"
#include "SearchResponse.h"
#include "SearchResult.h"
#include "SearchResultsCollection.h"
#include "Section.h"
#include "SectionLink.h"
#include "SectionLinkCollection.h"
#include "SectionLinkCollectionResponse.h"
#include "SectionPageSetupResponse.h"
#include "SectionResponse.h"
#include "Shading.h"
#include "SplitDocumentResponse.h"
#include "SplitDocumentResult.h"
#include "StatDataResponse.h"
#include "StorageFile.h"
#include "StoryChildNodes.h"
#include "StringFormatData.h"
#include "Style.h"
#include "StyleApply.h"
#include "StyleCopy.h"
#include "StyleInsert.h"
#include "StyleResponse.h"
#include "StylesResponse.h"
#include "StyleUpdate.h"
#include "SvgSaveOptionsData.h"
#include "Table.h"
#include "TableCell.h"
#include "TableCellFormat.h"
#include "TableCellFormatDto.h"
#include "TableCellFormatResponse.h"
#include "TableCellInsert.h"
#include "TableCellInsertDto.h"
#include "TableCellResponse.h"
#include "TableInsert.h"
#include "TableInsertDto.h"
#include "TableLink.h"
#include "TableLinkCollection.h"
#include "TableLinkCollectionResponse.h"
#include "TableProperties.h"
#include "TablePropertiesDto.h"
#include "TablePropertiesResponse.h"
#include "TableResponse.h"
#include "TableRow.h"
#include "TableRowFormat.h"
#include "TableRowFormatDto.h"
#include "TableRowFormatResponse.h"
#include "TableRowInsert.h"
#include "TableRowInsertDto.h"
#include "TableRowResponse.h"
#include "TabStop.h"
#include "TabStopBase.h"
#include "TabStopInsert.h"
#include "TabStopsResponse.h"
#include "TextSaveOptionsData.h"
#include "TiffSaveOptionsData.h"
#include "TxtSaveOptionsBaseData.h"
#include "WatermarkText.h"
#include "WordMLSaveOptionsData.h"
#include "WordsApiErrorResponse.h"
#include "WordsApiLink.h"
#include "WordsResponse.h"
#include "XamlFixedSaveOptionsData.h"
#include "XamlFlowSaveOptionsData.h"
#include "XmlColor.h"
#include "XpsSaveOptionsData.h"
#include "HttpContent.h"
#include <cpprest/details/basic_types.h>
#include <boost/optional.hpp>

namespace aspose {
namespace words {
namespace cloud {
namespace api {

using namespace aspose::words::cloud::api::models;

template<class T>
struct AsposeResponse
{
	std::shared_ptr<web::http::http_response> httpResponse;
    std::shared_ptr<T> body;
};

class WordsApi
{
public:
    /// <summary>
    /// Accepts all revisions in the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    RevisionsModificationResponse acceptAllRevisions(
    	std::shared_ptr<AcceptAllRevisionsRequest> request
    );

    /// <summary>
    /// Accepts all revisions in the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    AcceptAllRevisionsOnlineResponse acceptAllRevisionsOnline(
    	std::shared_ptr<AcceptAllRevisionsOnlineRequest> request
    );

    /// <summary>
    /// Appends documents to the original document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="documentList"><see cref="DocumentEntryList"/> with a list of documents to append.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    DocumentResponse appendDocument(
    	std::shared_ptr<AppendDocumentRequest> request
    );

    /// <summary>
    /// Appends documents to the original document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="documentList"><see cref="DocumentEntryList"/> with a list of documents to append.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    AppendDocumentOnlineResponse appendDocumentOnline(
    	std::shared_ptr<AppendDocumentOnlineRequest> request
    );

    /// <summary>
    /// Applies a style to the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="styledNodePath">The path to the node in the document tree, that supports styles: ParagraphFormat, List, ListLevel, Table.</param>
    /// <param name="styleApply">Style to apply.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    WordsResponse applyStyleToDocumentElement(
    	std::shared_ptr<ApplyStyleToDocumentElementRequest> request
    );

    /// <summary>
    /// Applies a style to the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="styledNodePath">The path to the node in the document tree, that supports styles: ParagraphFormat, List, ListLevel, Table.</param>
    /// <param name="styleApply">Style to apply.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    ApplyStyleToDocumentElementOnlineResponse applyStyleToDocumentElementOnline(
    	std::shared_ptr<ApplyStyleToDocumentElementOnlineRequest> request
    );

    /// <summary>
    /// Executes the report generation process using the specified document template and the external data source in XML, JSON or CSV format.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="data">A string providing a data to populate the specified template. The string must be of one of the following types: xml, json, csv.</param>
    /// <param name="reportEngineSettings">An object providing a settings of report engine.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">The filename of the output document. If this parameter is omitted, the result will be saved with autogenerated name. (optional)</param>
    DocumentResponse buildReport(
    	std::shared_ptr<BuildReportRequest> request
    );

    /// <summary>
    /// Executes the report generation process online using the specified document template and the external data source in XML, JSON or CSV format.
    /// </summary>
    /// <param name="template">File with template.</param>
    /// <param name="data">A string providing a data to populate the specified template. The string must be of one of the following types: xml, json, csv.</param>
    /// <param name="reportEngineSettings">An object providing a settings of report engine.</param>
    /// <param name="documentFileName">The filename of the output document, that will be used when the resulting document has a dynamic field {filename}. If it is not set, the "template" will be used instead. (optional)</param>
    HttpContent buildReportOnline(
    	std::shared_ptr<BuildReportOnlineRequest> request
    );

    /// <summary>
    /// Runs a multi-class text classification for the specified raw text.
    /// </summary>
    /// <param name="text">The text to classify.</param>
    /// <param name="bestClassesCount">The number of the best classes to return. (optional)</param>
    ClassificationResponse classify(
    	std::shared_ptr<ClassifyRequest> request
    );

    /// <summary>
    /// Runs a multi-class text classification for the document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="bestClassesCount">The number of the best classes to return. (optional)</param>
    /// <param name="taxonomy">The taxonomy to use. (optional)</param>
    ClassificationResponse classifyDocument(
    	std::shared_ptr<ClassifyDocumentRequest> request
    );

    /// <summary>
    /// Runs a multi-class text classification for the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="bestClassesCount">The number of the best classes to return. (optional)</param>
    /// <param name="taxonomy">The taxonomy to use. (optional)</param>
    ClassificationResponse classifyDocumentOnline(
    	std::shared_ptr<ClassifyDocumentOnlineRequest> request
    );

    /// <summary>
    /// Compares two documents.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="compareData">Compare data.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    DocumentResponse compareDocument(
    	std::shared_ptr<CompareDocumentRequest> request
    );

    /// <summary>
    /// Compares two documents.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="compareData">Compare data.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    CompareDocumentOnlineResponse compareDocumentOnline(
    	std::shared_ptr<CompareDocumentOnlineRequest> request
    );

    /// <summary>
    /// Converts a document on a local drive to the specified format.
    /// </summary>
    /// <param name="document">Converting document.</param>
    /// <param name="format">The format to convert.</param>
    /// <param name="outPath">The path to the output document on a local storage. (optional)</param>
    /// <param name="fileNameFieldValue">The filename of the output document, that will be used when the resulting document has a dynamic field {filename}. If it is not set, the "sourceFilename" will be used instead. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    HttpContent convertDocument(
    	std::shared_ptr<ConvertDocumentRequest> request
    );

    /// <summary>
    /// Copy file.
    /// </summary>
    /// <param name="destPath">Destination file path.</param>
    /// <param name="srcPath">Source file's path e.g. '/Folder 1/file.ext' or '/Bucket/Folder 1/file.ext'.</param>
    /// <param name="srcStorageName">Source storage name. (optional)</param>
    /// <param name="destStorageName">Destination storage name. (optional)</param>
    /// <param name="versionId">File version ID to copy. (optional)</param>
    void copyFile(
    	std::shared_ptr<CopyFileRequest> request
    );

    /// <summary>
    /// Copy folder.
    /// </summary>
    /// <param name="destPath">Destination folder path e.g. '/dst'.</param>
    /// <param name="srcPath">Source folder path e.g. /Folder1.</param>
    /// <param name="srcStorageName">Source storage name. (optional)</param>
    /// <param name="destStorageName">Destination storage name. (optional)</param>
    void copyFolder(
    	std::shared_ptr<CopyFolderRequest> request
    );

    /// <summary>
    /// Makes a copy of the style in the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="styleCopy">Style to copy.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    StyleResponse copyStyle(
    	std::shared_ptr<CopyStyleRequest> request
    );

    /// <summary>
    /// Makes a copy of the style in the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="styleCopy">Style to copy.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    CopyStyleOnlineResponse copyStyleOnline(
    	std::shared_ptr<CopyStyleOnlineRequest> request
    );

    /// <summary>
    /// Supported extensions: ".doc", ".docx", ".docm", ".dot", ".dotm", ".dotx", ".flatopc", ".fopc", ".flatopc_macro", ".fopc_macro", ".flatopc_template", ".fopc_template", ".flatopc_template_macro", ".fopc_template_macro", ".wordml", ".wml", ".rtf".
    /// </summary>
    /// <param name="fileName">The filename of the document. (optional)</param>
    /// <param name="folder">The path to the document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    DocumentResponse createDocument(
    	std::shared_ptr<CreateDocumentRequest> request
    );

    /// <summary>
    /// Create the folder.
    /// </summary>
    /// <param name="path">Target folder's path e.g. Folder1/Folder2/. The folders will be created recursively.</param>
    /// <param name="storageName">Storage name. (optional)</param>
    void createFolder(
    	std::shared_ptr<CreateFolderRequest> request
    );

    /// <summary>
    /// Adds a new or updates an existing document property.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="propertyName">The name of the property.</param>
    /// <param name="property">The property with new value.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    DocumentPropertyResponse createOrUpdateDocumentProperty(
    	std::shared_ptr<CreateOrUpdateDocumentPropertyRequest> request
    );

    /// <summary>
    /// Adds a new or updates an existing document property.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="propertyName">The name of the property.</param>
    /// <param name="property">The property with new value.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    CreateOrUpdateDocumentPropertyOnlineResponse createOrUpdateDocumentPropertyOnline(
    	std::shared_ptr<CreateOrUpdateDocumentPropertyOnlineRequest> request
    );

    /// <summary>
    /// Removes paragraph tab stops from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    TabStopsResponse deleteAllParagraphTabStops(
    	std::shared_ptr<DeleteAllParagraphTabStopsRequest> request
    );

    /// <summary>
    /// The 'nodePath' parameter should refer to a paragraph, a cell or a row.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="borderType">Border type.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    BorderResponse deleteBorder(
    	std::shared_ptr<DeleteBorderRequest> request
    );

    /// <summary>
    /// Removes a border from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="borderType">Border type.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    DeleteBorderOnlineResponse deleteBorderOnline(
    	std::shared_ptr<DeleteBorderOnlineRequest> request
    );

    /// <summary>
    /// The 'nodePath' parameter should refer to a paragraph, a cell or a row.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    BordersResponse deleteBorders(
    	std::shared_ptr<DeleteBordersRequest> request
    );

    /// <summary>
    /// Removes borders from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    DeleteBordersOnlineResponse deleteBordersOnline(
    	std::shared_ptr<DeleteBordersOnlineRequest> request
    );

    /// <summary>
    /// Removes a comment from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="commentIndex">The index of the comment.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    void deleteComment(
    	std::shared_ptr<DeleteCommentRequest> request
    );

    /// <summary>
    /// Removes a comment from the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="commentIndex">The index of the comment.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    HttpContent deleteCommentOnline(
    	std::shared_ptr<DeleteCommentOnlineRequest> request
    );

    /// <summary>
    /// Removes a document property.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="propertyName">The name of the property.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    void deleteDocumentProperty(
    	std::shared_ptr<DeleteDocumentPropertyRequest> request
    );

    /// <summary>
    /// Removes a document property.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="propertyName">The name of the property.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    HttpContent deleteDocumentPropertyOnline(
    	std::shared_ptr<DeleteDocumentPropertyOnlineRequest> request
    );

    /// <summary>
    /// Removes a DrawingObject from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    void deleteDrawingObject(
    	std::shared_ptr<DeleteDrawingObjectRequest> request
    );

    /// <summary>
    /// Removes a DrawingObject from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    HttpContent deleteDrawingObjectOnline(
    	std::shared_ptr<DeleteDrawingObjectOnlineRequest> request
    );

    /// <summary>
    /// Removes a field from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    void deleteField(
    	std::shared_ptr<DeleteFieldRequest> request
    );

    /// <summary>
    /// Removes a field from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    HttpContent deleteFieldOnline(
    	std::shared_ptr<DeleteFieldOnlineRequest> request
    );

    /// <summary>
    /// Removes fields from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    void deleteFields(
    	std::shared_ptr<DeleteFieldsRequest> request
    );

    /// <summary>
    /// Removes fields from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    HttpContent deleteFieldsOnline(
    	std::shared_ptr<DeleteFieldsOnlineRequest> request
    );

    /// <summary>
    /// Delete file.
    /// </summary>
    /// <param name="path">Path of the file including file name and extension e.g. /Folder1/file.ext.</param>
    /// <param name="storageName">Storage name. (optional)</param>
    /// <param name="versionId">File version ID to delete. (optional)</param>
    void deleteFile(
    	std::shared_ptr<DeleteFileRequest> request
    );

    /// <summary>
    /// Delete folder.
    /// </summary>
    /// <param name="path">Folder path e.g. /Folder1s.</param>
    /// <param name="storageName">Storage name. (optional)</param>
    /// <param name="recursive">Enable to delete folders, subfolders and files. (optional)</param>
    void deleteFolder(
    	std::shared_ptr<DeleteFolderRequest> request
    );

    /// <summary>
    /// Removes a footnote from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    void deleteFootnote(
    	std::shared_ptr<DeleteFootnoteRequest> request
    );

    /// <summary>
    /// Removes a footnote from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    HttpContent deleteFootnoteOnline(
    	std::shared_ptr<DeleteFootnoteOnlineRequest> request
    );

    /// <summary>
    /// Removes a form field from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    void deleteFormField(
    	std::shared_ptr<DeleteFormFieldRequest> request
    );

    /// <summary>
    /// Removes a form field from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    HttpContent deleteFormFieldOnline(
    	std::shared_ptr<DeleteFormFieldOnlineRequest> request
    );

    /// <summary>
    /// Removes a HeaderFooter object from the document section.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="sectionPath">The path to the section in the document tree.</param>
    /// <param name="index">Object index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    void deleteHeaderFooter(
    	std::shared_ptr<DeleteHeaderFooterRequest> request
    );

    /// <summary>
    /// Removes a HeaderFooter object from the document section.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="sectionPath">The path to the section in the document tree.</param>
    /// <param name="index">Object index.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    HttpContent deleteHeaderFooterOnline(
    	std::shared_ptr<DeleteHeaderFooterOnlineRequest> request
    );

    /// <summary>
    /// Removes HeaderFooter objects from the document section.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="sectionPath">The path to the section in the document tree.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="headersFootersTypes">The list of HeaderFooter types. (optional)</param>
    void deleteHeadersFooters(
    	std::shared_ptr<DeleteHeadersFootersRequest> request
    );

    /// <summary>
    /// Removes HeaderFooter objects from the document section.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="sectionPath">The path to the section in the document tree.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="headersFootersTypes">The list of HeaderFooter types. (optional)</param>
    HttpContent deleteHeadersFootersOnline(
    	std::shared_ptr<DeleteHeadersFootersOnlineRequest> request
    );

    /// <summary>
    /// Removes macros from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    void deleteMacros(
    	std::shared_ptr<DeleteMacrosRequest> request
    );

    /// <summary>
    /// Removes macros from the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    HttpContent deleteMacrosOnline(
    	std::shared_ptr<DeleteMacrosOnlineRequest> request
    );

    /// <summary>
    /// Removes an OfficeMath object from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    void deleteOfficeMathObject(
    	std::shared_ptr<DeleteOfficeMathObjectRequest> request
    );

    /// <summary>
    /// Removes an OfficeMath object from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    HttpContent deleteOfficeMathObjectOnline(
    	std::shared_ptr<DeleteOfficeMathObjectOnlineRequest> request
    );

    /// <summary>
    /// Removes a paragraph from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    void deleteParagraph(
    	std::shared_ptr<DeleteParagraphRequest> request
    );

    /// <summary>
    /// Removes the formatting properties of a paragraph list from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    ParagraphListFormatResponse deleteParagraphListFormat(
    	std::shared_ptr<DeleteParagraphListFormatRequest> request
    );

    /// <summary>
    /// Removes the formatting properties of a paragraph list from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    DeleteParagraphListFormatOnlineResponse deleteParagraphListFormatOnline(
    	std::shared_ptr<DeleteParagraphListFormatOnlineRequest> request
    );

    /// <summary>
    /// Removes a paragraph from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    HttpContent deleteParagraphOnline(
    	std::shared_ptr<DeleteParagraphOnlineRequest> request
    );

    /// <summary>
    /// Removes a paragraph tab stop from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="position">The position of a tab stop to remove.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    TabStopsResponse deleteParagraphTabStop(
    	std::shared_ptr<DeleteParagraphTabStopRequest> request
    );

    /// <summary>
    /// Removes a Run object from the paragraph.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="paragraphPath">The path to the paragraph in the document tree.</param>
    /// <param name="index">Object index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    void deleteRun(
    	std::shared_ptr<DeleteRunRequest> request
    );

    /// <summary>
    /// Removes a Run object from the paragraph.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="paragraphPath">The path to the paragraph in the document tree.</param>
    /// <param name="index">Object index.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    HttpContent deleteRunOnline(
    	std::shared_ptr<DeleteRunOnlineRequest> request
    );

    /// <summary>
    /// Removes a section from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="sectionIndex">The index of the section.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    void deleteSection(
    	std::shared_ptr<DeleteSectionRequest> request
    );

    /// <summary>
    /// Removes a section from the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="sectionIndex">The index of the section.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    HttpContent deleteSectionOnline(
    	std::shared_ptr<DeleteSectionOnlineRequest> request
    );

    /// <summary>
    /// Removes a table from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    void deleteTable(
    	std::shared_ptr<DeleteTableRequest> request
    );

    /// <summary>
    /// Removes a cell from the table row.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="tableRowPath">The path to the table row in the document tree.</param>
    /// <param name="index">Object index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    void deleteTableCell(
    	std::shared_ptr<DeleteTableCellRequest> request
    );

    /// <summary>
    /// Removes a cell from the table row.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="tableRowPath">The path to the table row in the document tree.</param>
    /// <param name="index">Object index.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    HttpContent deleteTableCellOnline(
    	std::shared_ptr<DeleteTableCellOnlineRequest> request
    );

    /// <summary>
    /// Removes a table from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    HttpContent deleteTableOnline(
    	std::shared_ptr<DeleteTableOnlineRequest> request
    );

    /// <summary>
    /// Removes a row from the table.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="tablePath">The path to the table in the document tree.</param>
    /// <param name="index">Object index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    void deleteTableRow(
    	std::shared_ptr<DeleteTableRowRequest> request
    );

    /// <summary>
    /// Removes a row from the table.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="tablePath">The path to the table in the document tree.</param>
    /// <param name="index">Object index.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    HttpContent deleteTableRowOnline(
    	std::shared_ptr<DeleteTableRowOnlineRequest> request
    );

    /// <summary>
    /// Removes a watermark from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    DocumentResponse deleteWatermark(
    	std::shared_ptr<DeleteWatermarkRequest> request
    );

    /// <summary>
    /// Removes a watermark from the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    DeleteWatermarkOnlineResponse deleteWatermarkOnline(
    	std::shared_ptr<DeleteWatermarkOnlineRequest> request
    );

    /// <summary>
    /// Download file.
    /// </summary>
    /// <param name="path">Path of the file including the file name and extension e.g. /folder1/file.ext.</param>
    /// <param name="storageName">Storage name. (optional)</param>
    /// <param name="versionId">File version ID to download. (optional)</param>
    HttpContent downloadFile(
    	std::shared_ptr<DownloadFileRequest> request
    );

    /// <summary>
    /// Executes a Mail Merge operation.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="data">Mail merge data. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="withRegions">The flag indicating whether to execute Mail Merge operation with regions. (optional)</param>
    /// <param name="mailMergeDataFile">The data file. (optional)</param>
    /// <param name="cleanup">The cleanup options. (optional)</param>
    /// <param name="useWholeParagraphAsRegion">The flag indicating whether paragraph with TableStart or TableEnd field should be fully included into mail merge region or particular range between TableStart and TableEnd fields. The default value is true. (optional)</param>
    /// <param name="destFileName">The filename of the output document. If this parameter is omitted, the result will be saved with autogenerated name. (optional)</param>
    DocumentResponse executeMailMerge(
    	std::shared_ptr<ExecuteMailMergeRequest> request
    );

    /// <summary>
    /// Executes a Mail Merge operation online.
    /// </summary>
    /// <param name="template">File with template.</param>
    /// <param name="data">File with mailmerge data.</param>
    /// <param name="withRegions">The flag indicating whether to execute Mail Merge operation with regions. (optional)</param>
    /// <param name="cleanup">The cleanup options. (optional)</param>
    /// <param name="documentFileName">The filename of the output document, that will be used when the resulting document has a dynamic field {filename}. If it is not set, the "template" will be used instead. (optional)</param>
    HttpContent executeMailMergeOnline(
    	std::shared_ptr<ExecuteMailMergeOnlineRequest> request
    );

    /// <summary>
    /// Reads available fonts from the document.
    /// </summary>
    /// <param name="fontsLocation">The folder in cloud storage with custom fonts. (optional)</param>
    AvailableFontsResponse getAvailableFonts(
    	std::shared_ptr<GetAvailableFontsRequest> request
    );

    /// <summary>
    /// Reads a bookmark, specified by name, from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="bookmarkName">The name of the bookmark.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    BookmarkResponse getBookmarkByName(
    	std::shared_ptr<GetBookmarkByNameRequest> request
    );

    /// <summary>
    /// Reads a bookmark, specified by name, from the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="bookmarkName">The name of the bookmark.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    BookmarkResponse getBookmarkByNameOnline(
    	std::shared_ptr<GetBookmarkByNameOnlineRequest> request
    );

    /// <summary>
    /// Reads bookmarks from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    BookmarksResponse getBookmarks(
    	std::shared_ptr<GetBookmarksRequest> request
    );

    /// <summary>
    /// Reads bookmarks from the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    BookmarksResponse getBookmarksOnline(
    	std::shared_ptr<GetBookmarksOnlineRequest> request
    );

    /// <summary>
    /// The 'nodePath' parameter should refer to a paragraph, a cell or a row.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="borderType">Border type.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    BorderResponse getBorder(
    	std::shared_ptr<GetBorderRequest> request
    );

    /// <summary>
    /// Reads a border from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="borderType">Border type.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    BorderResponse getBorderOnline(
    	std::shared_ptr<GetBorderOnlineRequest> request
    );

    /// <summary>
    /// Reads borders from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    BordersResponse getBorders(
    	std::shared_ptr<GetBordersRequest> request
    );

    /// <summary>
    /// Reads borders from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    BordersResponse getBordersOnline(
    	std::shared_ptr<GetBordersOnlineRequest> request
    );

    /// <summary>
    /// Reads a comment from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="commentIndex">The index of the comment.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    CommentResponse getComment(
    	std::shared_ptr<GetCommentRequest> request
    );

    /// <summary>
    /// Reads a comment from the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="commentIndex">The index of the comment.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    CommentResponse getCommentOnline(
    	std::shared_ptr<GetCommentOnlineRequest> request
    );

    /// <summary>
    /// Reads comments from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    CommentsResponse getComments(
    	std::shared_ptr<GetCommentsRequest> request
    );

    /// <summary>
    /// Reads comments from the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    CommentsResponse getCommentsOnline(
    	std::shared_ptr<GetCommentsOnlineRequest> request
    );

    /// <summary>
    /// Reads common information from the document.
    /// </summary>
    /// <param name="documentName">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    DocumentResponse getDocument(
    	std::shared_ptr<GetDocumentRequest> request
    );

    /// <summary>
    /// Reads a DrawingObject from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    DrawingObjectResponse getDocumentDrawingObjectByIndex(
    	std::shared_ptr<GetDocumentDrawingObjectByIndexRequest> request
    );

    /// <summary>
    /// Reads a DrawingObject from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    DrawingObjectResponse getDocumentDrawingObjectByIndexOnline(
    	std::shared_ptr<GetDocumentDrawingObjectByIndexOnlineRequest> request
    );

    /// <summary>
    /// Reads image data of a DrawingObject from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    HttpContent getDocumentDrawingObjectImageData(
    	std::shared_ptr<GetDocumentDrawingObjectImageDataRequest> request
    );

    /// <summary>
    /// Reads image data of a DrawingObject from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    HttpContent getDocumentDrawingObjectImageDataOnline(
    	std::shared_ptr<GetDocumentDrawingObjectImageDataOnlineRequest> request
    );

    /// <summary>
    /// Reads OLE data of a DrawingObject from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    HttpContent getDocumentDrawingObjectOleData(
    	std::shared_ptr<GetDocumentDrawingObjectOleDataRequest> request
    );

    /// <summary>
    /// Reads OLE data of a DrawingObject from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    HttpContent getDocumentDrawingObjectOleDataOnline(
    	std::shared_ptr<GetDocumentDrawingObjectOleDataOnlineRequest> request
    );

    /// <summary>
    /// Reads DrawingObjects from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    DrawingObjectsResponse getDocumentDrawingObjects(
    	std::shared_ptr<GetDocumentDrawingObjectsRequest> request
    );

    /// <summary>
    /// Reads DrawingObjects from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    DrawingObjectsResponse getDocumentDrawingObjectsOnline(
    	std::shared_ptr<GetDocumentDrawingObjectsOnlineRequest> request
    );

    /// <summary>
    /// Reads merge field names from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="useNonMergeFields">The flag indicating whether to use non merge fields. If true, result includes "mustache" field names. (optional)</param>
    FieldNamesResponse getDocumentFieldNames(
    	std::shared_ptr<GetDocumentFieldNamesRequest> request
    );

    /// <summary>
    /// Reads merge field names from the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="useNonMergeFields">The flag indicating whether to use non merge fields. If true, result includes "mustache" field names. (optional)</param>
    FieldNamesResponse getDocumentFieldNamesOnline(
    	std::shared_ptr<GetDocumentFieldNamesOnlineRequest> request
    );

    /// <summary>
    /// Reads a hyperlink from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="hyperlinkIndex">The index of the hyperlink.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    HyperlinkResponse getDocumentHyperlinkByIndex(
    	std::shared_ptr<GetDocumentHyperlinkByIndexRequest> request
    );

    /// <summary>
    /// Reads a hyperlink from the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="hyperlinkIndex">The index of the hyperlink.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    HyperlinkResponse getDocumentHyperlinkByIndexOnline(
    	std::shared_ptr<GetDocumentHyperlinkByIndexOnlineRequest> request
    );

    /// <summary>
    /// Reads hyperlinks from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    HyperlinksResponse getDocumentHyperlinks(
    	std::shared_ptr<GetDocumentHyperlinksRequest> request
    );

    /// <summary>
    /// Reads hyperlinks from the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    HyperlinksResponse getDocumentHyperlinksOnline(
    	std::shared_ptr<GetDocumentHyperlinksOnlineRequest> request
    );

    /// <summary>
    /// Reads document properties.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    DocumentPropertiesResponse getDocumentProperties(
    	std::shared_ptr<GetDocumentPropertiesRequest> request
    );

    /// <summary>
    /// Reads document properties.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    DocumentPropertiesResponse getDocumentPropertiesOnline(
    	std::shared_ptr<GetDocumentPropertiesOnlineRequest> request
    );

    /// <summary>
    /// Reads a document property.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="propertyName">The name of the property.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    DocumentPropertyResponse getDocumentProperty(
    	std::shared_ptr<GetDocumentPropertyRequest> request
    );

    /// <summary>
    /// Reads a document property.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="propertyName">The name of the property.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    DocumentPropertyResponse getDocumentPropertyOnline(
    	std::shared_ptr<GetDocumentPropertyOnlineRequest> request
    );

    /// <summary>
    /// Reads protection properties from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    ProtectionDataResponse getDocumentProtection(
    	std::shared_ptr<GetDocumentProtectionRequest> request
    );

    /// <summary>
    /// Reads protection properties from the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    ProtectionDataResponse getDocumentProtectionOnline(
    	std::shared_ptr<GetDocumentProtectionOnlineRequest> request
    );

    /// <summary>
    /// Reads document statistics.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="includeComments">The flag indicating whether to include comments from the WordCount. The default value is "false". (optional)</param>
    /// <param name="includeFootnotes">The flag indicating whether to include footnotes from the WordCount. The default value is "false". (optional)</param>
    /// <param name="includeTextInShapes">The flag indicating whether to include shape's text from the WordCount. The default value is "false". (optional)</param>
    StatDataResponse getDocumentStatistics(
    	std::shared_ptr<GetDocumentStatisticsRequest> request
    );

    /// <summary>
    /// Reads document statistics.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="includeComments">The flag indicating whether to include comments from the WordCount. The default value is "false". (optional)</param>
    /// <param name="includeFootnotes">The flag indicating whether to include footnotes from the WordCount. The default value is "false". (optional)</param>
    /// <param name="includeTextInShapes">The flag indicating whether to include shape's text from the WordCount. The default value is "false". (optional)</param>
    StatDataResponse getDocumentStatisticsOnline(
    	std::shared_ptr<GetDocumentStatisticsOnlineRequest> request
    );

    /// <summary>
    /// Converts a document in cloud storage to the specified format.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="format">The destination format.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="outPath">The path to the output document. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    HttpContent getDocumentWithFormat(
    	std::shared_ptr<GetDocumentWithFormatRequest> request
    );

    /// <summary>
    /// Reads a field from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    FieldResponse getField(
    	std::shared_ptr<GetFieldRequest> request
    );

    /// <summary>
    /// Reads a field from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    FieldResponse getFieldOnline(
    	std::shared_ptr<GetFieldOnlineRequest> request
    );

    /// <summary>
    /// Reads fields from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    FieldsResponse getFields(
    	std::shared_ptr<GetFieldsRequest> request
    );

    /// <summary>
    /// Reads fields from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    FieldsResponse getFieldsOnline(
    	std::shared_ptr<GetFieldsOnlineRequest> request
    );

    /// <summary>
    /// Get all files and folders within a folder.
    /// </summary>
    /// <param name="path">Folder path e.g. /Folder1.</param>
    /// <param name="storageName">Storage name. (optional)</param>
    FilesList getFilesList(
    	std::shared_ptr<GetFilesListRequest> request
    );

    /// <summary>
    /// Reads a footnote from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    FootnoteResponse getFootnote(
    	std::shared_ptr<GetFootnoteRequest> request
    );

    /// <summary>
    /// Reads a footnote from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    FootnoteResponse getFootnoteOnline(
    	std::shared_ptr<GetFootnoteOnlineRequest> request
    );

    /// <summary>
    /// Reads footnotes from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    FootnotesResponse getFootnotes(
    	std::shared_ptr<GetFootnotesRequest> request
    );

    /// <summary>
    /// Reads footnotes from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    FootnotesResponse getFootnotesOnline(
    	std::shared_ptr<GetFootnotesOnlineRequest> request
    );

    /// <summary>
    /// Reads a form field from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    FormFieldResponse getFormField(
    	std::shared_ptr<GetFormFieldRequest> request
    );

    /// <summary>
    /// Reads a form field from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    FormFieldResponse getFormFieldOnline(
    	std::shared_ptr<GetFormFieldOnlineRequest> request
    );

    /// <summary>
    /// Reads form fields from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    FormFieldsResponse getFormFields(
    	std::shared_ptr<GetFormFieldsRequest> request
    );

    /// <summary>
    /// Reads form fields from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    FormFieldsResponse getFormFieldsOnline(
    	std::shared_ptr<GetFormFieldsOnlineRequest> request
    );

    /// <summary>
    /// Reads a HeaderFooter object from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="headerFooterIndex">The index of the HeaderFooter object.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="filterByType">The list of HeaderFooter types. (optional)</param>
    HeaderFooterResponse getHeaderFooter(
    	std::shared_ptr<GetHeaderFooterRequest> request
    );

    /// <summary>
    /// Reads a HeaderFooter object from the document section.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="headerFooterIndex">The index of the HeaderFooter object.</param>
    /// <param name="sectionIndex">The index of the section.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="filterByType">The list of HeaderFooter types. (optional)</param>
    HeaderFooterResponse getHeaderFooterOfSection(
    	std::shared_ptr<GetHeaderFooterOfSectionRequest> request
    );

    /// <summary>
    /// Reads a HeaderFooter object from the document section.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="headerFooterIndex">The index of the HeaderFooter object.</param>
    /// <param name="sectionIndex">The index of the section.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="filterByType">The list of HeaderFooter types. (optional)</param>
    HeaderFooterResponse getHeaderFooterOfSectionOnline(
    	std::shared_ptr<GetHeaderFooterOfSectionOnlineRequest> request
    );

    /// <summary>
    /// Reads a HeaderFooter object from the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="headerFooterIndex">The index of the HeaderFooter object.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="filterByType">The list of HeaderFooter types. (optional)</param>
    HeaderFooterResponse getHeaderFooterOnline(
    	std::shared_ptr<GetHeaderFooterOnlineRequest> request
    );

    /// <summary>
    /// Reads HeaderFooter objects from the document section.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="sectionPath">The path to the section in the document tree.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="filterByType">The list of HeaderFooter types. (optional)</param>
    HeaderFootersResponse getHeaderFooters(
    	std::shared_ptr<GetHeaderFootersRequest> request
    );

    /// <summary>
    /// Reads HeaderFooter objects from the document section.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="sectionPath">The path to the section in the document tree.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="filterByType">The list of HeaderFooter types. (optional)</param>
    HeaderFootersResponse getHeaderFootersOnline(
    	std::shared_ptr<GetHeaderFootersOnlineRequest> request
    );

    /// <summary>
    /// Reads a list from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="listId">The list Id.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    ListResponse getList(
    	std::shared_ptr<GetListRequest> request
    );

    /// <summary>
    /// Reads a list from the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="listId">The list Id.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    ListResponse getListOnline(
    	std::shared_ptr<GetListOnlineRequest> request
    );

    /// <summary>
    /// Reads lists from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    ListsResponse getLists(
    	std::shared_ptr<GetListsRequest> request
    );

    /// <summary>
    /// Reads lists from the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    ListsResponse getListsOnline(
    	std::shared_ptr<GetListsOnlineRequest> request
    );

    /// <summary>
    /// Reads an OfficeMath object from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    OfficeMathObjectResponse getOfficeMathObject(
    	std::shared_ptr<GetOfficeMathObjectRequest> request
    );

    /// <summary>
    /// Reads an OfficeMath object from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    OfficeMathObjectResponse getOfficeMathObjectOnline(
    	std::shared_ptr<GetOfficeMathObjectOnlineRequest> request
    );

    /// <summary>
    /// Reads OfficeMath objects from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    OfficeMathObjectsResponse getOfficeMathObjects(
    	std::shared_ptr<GetOfficeMathObjectsRequest> request
    );

    /// <summary>
    /// Reads OfficeMath objects from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    OfficeMathObjectsResponse getOfficeMathObjectsOnline(
    	std::shared_ptr<GetOfficeMathObjectsOnlineRequest> request
    );

    /// <summary>
    /// Reads a paragraph from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    ParagraphResponse getParagraph(
    	std::shared_ptr<GetParagraphRequest> request
    );

    /// <summary>
    /// Reads the formatting properties of a paragraph from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    ParagraphFormatResponse getParagraphFormat(
    	std::shared_ptr<GetParagraphFormatRequest> request
    );

    /// <summary>
    /// Reads the formatting properties of a paragraph from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    ParagraphFormatResponse getParagraphFormatOnline(
    	std::shared_ptr<GetParagraphFormatOnlineRequest> request
    );

    /// <summary>
    /// Reads the formatting properties of a paragraph list from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    ParagraphListFormatResponse getParagraphListFormat(
    	std::shared_ptr<GetParagraphListFormatRequest> request
    );

    /// <summary>
    /// Reads the formatting properties of a paragraph list from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    ParagraphListFormatResponse getParagraphListFormatOnline(
    	std::shared_ptr<GetParagraphListFormatOnlineRequest> request
    );

    /// <summary>
    /// Reads a paragraph from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    ParagraphResponse getParagraphOnline(
    	std::shared_ptr<GetParagraphOnlineRequest> request
    );

    /// <summary>
    /// Reads paragraphs from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    ParagraphLinkCollectionResponse getParagraphs(
    	std::shared_ptr<GetParagraphsRequest> request
    );

    /// <summary>
    /// Reads paragraphs from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    ParagraphLinkCollectionResponse getParagraphsOnline(
    	std::shared_ptr<GetParagraphsOnlineRequest> request
    );

    /// <summary>
    /// Reads paragraph tab stops from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    TabStopsResponse getParagraphTabStops(
    	std::shared_ptr<GetParagraphTabStopsRequest> request
    );

    /// <summary>
    /// Reads paragraph tab stops from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    TabStopsResponse getParagraphTabStopsOnline(
    	std::shared_ptr<GetParagraphTabStopsOnlineRequest> request
    );

    /// <summary>
    /// Reads range text from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="rangeStartIdentifier">The range start identifier.</param>
    /// <param name="rangeEndIdentifier">The range end identifier. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    RangeTextResponse getRangeText(
    	std::shared_ptr<GetRangeTextRequest> request
    );

    /// <summary>
    /// Reads range text from the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="rangeStartIdentifier">The range start identifier.</param>
    /// <param name="rangeEndIdentifier">The range end identifier. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    RangeTextResponse getRangeTextOnline(
    	std::shared_ptr<GetRangeTextOnlineRequest> request
    );

    /// <summary>
    /// Reads a Run object from the paragraph.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="paragraphPath">The path to the paragraph in the document tree.</param>
    /// <param name="index">Object index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    RunResponse getRun(
    	std::shared_ptr<GetRunRequest> request
    );

    /// <summary>
    /// Reads the font properties of a Run object from the paragraph.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="paragraphPath">The path to the paragraph in the document tree.</param>
    /// <param name="index">Object index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    FontResponse getRunFont(
    	std::shared_ptr<GetRunFontRequest> request
    );

    /// <summary>
    /// Reads the font properties of a Run object from the paragraph.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="paragraphPath">The path to the paragraph in the document tree.</param>
    /// <param name="index">Object index.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    FontResponse getRunFontOnline(
    	std::shared_ptr<GetRunFontOnlineRequest> request
    );

    /// <summary>
    /// Reads a Run object from the paragraph.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="paragraphPath">The path to the paragraph in the document tree.</param>
    /// <param name="index">Object index.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    RunResponse getRunOnline(
    	std::shared_ptr<GetRunOnlineRequest> request
    );

    /// <summary>
    /// Reads Run objects from the paragraph.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="paragraphPath">The path to the paragraph in the document tree.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    RunsResponse getRuns(
    	std::shared_ptr<GetRunsRequest> request
    );

    /// <summary>
    /// Reads Run objects from the paragraph.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="paragraphPath">The path to the paragraph in the document tree.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    RunsResponse getRunsOnline(
    	std::shared_ptr<GetRunsOnlineRequest> request
    );

    /// <summary>
    /// Reads a section from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="sectionIndex">The index of the section.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    SectionResponse getSection(
    	std::shared_ptr<GetSectionRequest> request
    );

    /// <summary>
    /// Reads a section from the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="sectionIndex">The index of the section.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    SectionResponse getSectionOnline(
    	std::shared_ptr<GetSectionOnlineRequest> request
    );

    /// <summary>
    /// Reads the page setup of a section from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="sectionIndex">The index of the section.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    SectionPageSetupResponse getSectionPageSetup(
    	std::shared_ptr<GetSectionPageSetupRequest> request
    );

    /// <summary>
    /// Reads the page setup of a section from the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="sectionIndex">The index of the section.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    SectionPageSetupResponse getSectionPageSetupOnline(
    	std::shared_ptr<GetSectionPageSetupOnlineRequest> request
    );

    /// <summary>
    /// Reads sections from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    SectionLinkCollectionResponse getSections(
    	std::shared_ptr<GetSectionsRequest> request
    );

    /// <summary>
    /// Reads sections from the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    SectionLinkCollectionResponse getSectionsOnline(
    	std::shared_ptr<GetSectionsOnlineRequest> request
    );

    /// <summary>
    /// Reads a style from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="styleName">The name of the style.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    StyleResponse getStyle(
    	std::shared_ptr<GetStyleRequest> request
    );

    /// <summary>
    /// Reads a style from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="styledNodePath">The path to the node in the document tree, that supports styles: ParagraphFormat, List, ListLevel, Table.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    StyleResponse getStyleFromDocumentElement(
    	std::shared_ptr<GetStyleFromDocumentElementRequest> request
    );

    /// <summary>
    /// Reads a style from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="styledNodePath">The path to the node in the document tree, that supports styles: ParagraphFormat, List, ListLevel, Table.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    StyleResponse getStyleFromDocumentElementOnline(
    	std::shared_ptr<GetStyleFromDocumentElementOnlineRequest> request
    );

    /// <summary>
    /// Reads a style from the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="styleName">The name of the style.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    StyleResponse getStyleOnline(
    	std::shared_ptr<GetStyleOnlineRequest> request
    );

    /// <summary>
    /// Reads styles from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    StylesResponse getStyles(
    	std::shared_ptr<GetStylesRequest> request
    );

    /// <summary>
    /// Reads styles from the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    StylesResponse getStylesOnline(
    	std::shared_ptr<GetStylesOnlineRequest> request
    );

    /// <summary>
    /// Reads a table from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    TableResponse getTable(
    	std::shared_ptr<GetTableRequest> request
    );

    /// <summary>
    /// Reads a cell from the table row.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="tableRowPath">The path to the table row in the document tree.</param>
    /// <param name="index">Object index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    TableCellResponse getTableCell(
    	std::shared_ptr<GetTableCellRequest> request
    );

    /// <summary>
    /// Reads the formatting properties of a table cell.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="tableRowPath">The path to the table row in the document tree.</param>
    /// <param name="index">Object index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    TableCellFormatResponse getTableCellFormat(
    	std::shared_ptr<GetTableCellFormatRequest> request
    );

    /// <summary>
    /// Reads the formatting properties of a table cell.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="tableRowPath">The path to the table row in the document tree.</param>
    /// <param name="index">Object index.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    TableCellFormatResponse getTableCellFormatOnline(
    	std::shared_ptr<GetTableCellFormatOnlineRequest> request
    );

    /// <summary>
    /// Reads a cell from the table row.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="tableRowPath">The path to the table row in the document tree.</param>
    /// <param name="index">Object index.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    TableCellResponse getTableCellOnline(
    	std::shared_ptr<GetTableCellOnlineRequest> request
    );

    /// <summary>
    /// Reads a table from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    TableResponse getTableOnline(
    	std::shared_ptr<GetTableOnlineRequest> request
    );

    /// <summary>
    /// Reads properties of a table from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    TablePropertiesResponse getTableProperties(
    	std::shared_ptr<GetTablePropertiesRequest> request
    );

    /// <summary>
    /// Reads properties of a table from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    TablePropertiesResponse getTablePropertiesOnline(
    	std::shared_ptr<GetTablePropertiesOnlineRequest> request
    );

    /// <summary>
    /// Reads a row from the table.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="tablePath">The path to the table in the document tree.</param>
    /// <param name="index">Object index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    TableRowResponse getTableRow(
    	std::shared_ptr<GetTableRowRequest> request
    );

    /// <summary>
    /// Reads the formatting properties of a table row.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="tablePath">The path to the table in the document tree.</param>
    /// <param name="index">Object index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    TableRowFormatResponse getTableRowFormat(
    	std::shared_ptr<GetTableRowFormatRequest> request
    );

    /// <summary>
    /// Reads the formatting properties of a table row.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="tablePath">The path to the table in the document tree.</param>
    /// <param name="index">Object index.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    TableRowFormatResponse getTableRowFormatOnline(
    	std::shared_ptr<GetTableRowFormatOnlineRequest> request
    );

    /// <summary>
    /// Reads a row from the table.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="tablePath">The path to the table in the document tree.</param>
    /// <param name="index">Object index.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    TableRowResponse getTableRowOnline(
    	std::shared_ptr<GetTableRowOnlineRequest> request
    );

    /// <summary>
    /// Reads tables from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    TableLinkCollectionResponse getTables(
    	std::shared_ptr<GetTablesRequest> request
    );

    /// <summary>
    /// Reads tables from the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    TableLinkCollectionResponse getTablesOnline(
    	std::shared_ptr<GetTablesOnlineRequest> request
    );

    /// <summary>
    /// Inserts a new comment to the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="comment">Comment data.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    CommentResponse insertComment(
    	std::shared_ptr<InsertCommentRequest> request
    );

    /// <summary>
    /// Inserts a new comment to the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="comment">Comment data.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    InsertCommentOnlineResponse insertCommentOnline(
    	std::shared_ptr<InsertCommentOnlineRequest> request
    );

    /// <summary>
    /// Inserts a new DrawingObject to the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="drawingObject">Drawing object parameters.</param>
    /// <param name="imageFile">File with image.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    DrawingObjectResponse insertDrawingObject(
    	std::shared_ptr<InsertDrawingObjectRequest> request
    );

    /// <summary>
    /// Inserts a new DrawingObject to the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="drawingObject">Drawing object parameters.</param>
    /// <param name="imageFile">File with image.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    InsertDrawingObjectOnlineResponse insertDrawingObjectOnline(
    	std::shared_ptr<InsertDrawingObjectOnlineRequest> request
    );

    /// <summary>
    /// Inserts a new field to the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="field">Field data.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="insertBeforeNode">The index of the node. A new field will be inserted before the node with the specified node Id. (optional)</param>
    FieldResponse insertField(
    	std::shared_ptr<InsertFieldRequest> request
    );

    /// <summary>
    /// Inserts a new field to the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="field">Field data.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="insertBeforeNode">The index of the node. A new field will be inserted before the node with the specified node Id. (optional)</param>
    InsertFieldOnlineResponse insertFieldOnline(
    	std::shared_ptr<InsertFieldOnlineRequest> request
    );

    /// <summary>
    /// Inserts a new footnote to the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="footnoteDto">Footnote data.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    FootnoteResponse insertFootnote(
    	std::shared_ptr<InsertFootnoteRequest> request
    );

    /// <summary>
    /// Inserts a new footnote to the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="footnoteDto">Footnote data.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    InsertFootnoteOnlineResponse insertFootnoteOnline(
    	std::shared_ptr<InsertFootnoteOnlineRequest> request
    );

    /// <summary>
    /// Inserts a new form field to the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="formField">From field data.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="insertBeforeNode">The index of the node. A new form field will be inserted before the node with the specified node Id. (optional)</param>
    FormFieldResponse insertFormField(
    	std::shared_ptr<InsertFormFieldRequest> request
    );

    /// <summary>
    /// Inserts a new form field to the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="formField">From field data.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="insertBeforeNode">The index of the node. A new form field will be inserted before the node with the specified node Id. (optional)</param>
    InsertFormFieldOnlineResponse insertFormFieldOnline(
    	std::shared_ptr<InsertFormFieldOnlineRequest> request
    );

    /// <summary>
    /// Inserts a new HeaderFooter object to the document section.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="sectionPath">The path to the section in the document tree.</param>
    /// <param name="headerFooterType">Type of header/footer.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    HeaderFooterResponse insertHeaderFooter(
    	std::shared_ptr<InsertHeaderFooterRequest> request
    );

    /// <summary>
    /// Inserts a new HeaderFooter object to the document section.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="sectionPath">The path to the section in the document tree.</param>
    /// <param name="headerFooterType">Type of header/footer.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    InsertHeaderFooterOnlineResponse insertHeaderFooterOnline(
    	std::shared_ptr<InsertHeaderFooterOnlineRequest> request
    );

    /// <summary>
    /// Inserts a new list to the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="listInsert">List object.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    ListResponse insertList(
    	std::shared_ptr<InsertListRequest> request
    );

    /// <summary>
    /// Inserts a new list to the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="listInsert">List object.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    InsertListOnlineResponse insertListOnline(
    	std::shared_ptr<InsertListOnlineRequest> request
    );

    /// <summary>
    /// Inserts a new or updates an existing paragraph tab stop in the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="tabStopInsertDto">TabStopInsert dto.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    TabStopsResponse insertOrUpdateParagraphTabStop(
    	std::shared_ptr<InsertOrUpdateParagraphTabStopRequest> request
    );

    /// <summary>
    /// Inserts a new or updates an existing paragraph tab stop in the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="tabStopInsertDto">TabStopInsert dto.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    InsertOrUpdateParagraphTabStopOnlineResponse insertOrUpdateParagraphTabStopOnline(
    	std::shared_ptr<InsertOrUpdateParagraphTabStopOnlineRequest> request
    );

    /// <summary>
    /// Inserts page numbers to the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="pageNumber">Page number dto.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    DocumentResponse insertPageNumbers(
    	std::shared_ptr<InsertPageNumbersRequest> request
    );

    /// <summary>
    /// Inserts page numbers to the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="pageNumber">Page number dto.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    InsertPageNumbersOnlineResponse insertPageNumbersOnline(
    	std::shared_ptr<InsertPageNumbersOnlineRequest> request
    );

    /// <summary>
    /// Inserts a new paragraph to the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="paragraph">Paragraph data.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="insertBeforeNode">The index of the node. A new paragraph will be inserted before the node with the specified index. (optional)</param>
    ParagraphResponse insertParagraph(
    	std::shared_ptr<InsertParagraphRequest> request
    );

    /// <summary>
    /// Inserts a new paragraph to the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="paragraph">Paragraph data.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="insertBeforeNode">The index of the node. A new paragraph will be inserted before the node with the specified index. (optional)</param>
    InsertParagraphOnlineResponse insertParagraphOnline(
    	std::shared_ptr<InsertParagraphOnlineRequest> request
    );

    /// <summary>
    /// Inserts a new Run object to the paragraph.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="paragraphPath">The path to the paragraph in the document tree.</param>
    /// <param name="run">Run data.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="insertBeforeNode">The index of the node. A new Run object will be inserted before the node with the specified node Id. (optional)</param>
    RunResponse insertRun(
    	std::shared_ptr<InsertRunRequest> request
    );

    /// <summary>
    /// Inserts a new Run object to the paragraph.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="paragraphPath">The path to the paragraph in the document tree.</param>
    /// <param name="run">Run data.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="insertBeforeNode">The index of the node. A new Run object will be inserted before the node with the specified node Id. (optional)</param>
    InsertRunOnlineResponse insertRunOnline(
    	std::shared_ptr<InsertRunOnlineRequest> request
    );

    /// <summary>
    /// Inserts a new style to the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="styleInsert">Style to insert.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    StyleResponse insertStyle(
    	std::shared_ptr<InsertStyleRequest> request
    );

    /// <summary>
    /// Inserts a new style to the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="styleInsert">Style to insert.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    InsertStyleOnlineResponse insertStyleOnline(
    	std::shared_ptr<InsertStyleOnlineRequest> request
    );

    /// <summary>
    /// Inserts a new table to the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="table">Table parameters.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    TableResponse insertTable(
    	std::shared_ptr<InsertTableRequest> request
    );

    /// <summary>
    /// Inserts a new cell to the table row.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="tableRowPath">The path to the table row in the document tree.</param>
    /// <param name="cell">Table cell parameters.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    TableCellResponse insertTableCell(
    	std::shared_ptr<InsertTableCellRequest> request
    );

    /// <summary>
    /// Inserts a new cell to the table row.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="tableRowPath">The path to the table row in the document tree.</param>
    /// <param name="cell">Table cell parameters.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    InsertTableCellOnlineResponse insertTableCellOnline(
    	std::shared_ptr<InsertTableCellOnlineRequest> request
    );

    /// <summary>
    /// Inserts a new table to the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="table">Table parameters.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    InsertTableOnlineResponse insertTableOnline(
    	std::shared_ptr<InsertTableOnlineRequest> request
    );

    /// <summary>
    /// Inserts a new row to the table.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="tablePath">The path to the table in the document tree.</param>
    /// <param name="row">Table row parameters.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    TableRowResponse insertTableRow(
    	std::shared_ptr<InsertTableRowRequest> request
    );

    /// <summary>
    /// Inserts a new row to the table.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="tablePath">The path to the table in the document tree.</param>
    /// <param name="row">Table row parameters.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    InsertTableRowOnlineResponse insertTableRowOnline(
    	std::shared_ptr<InsertTableRowOnlineRequest> request
    );

    /// <summary>
    /// Inserts a new watermark image to the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="imageFile">File with image. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="rotationAngle">The rotation angle of the watermark. (optional)</param>
    /// <param name="image">The filename of the image. If the parameter value is missing — the image data is expected in the request content. (optional)</param>
    DocumentResponse insertWatermarkImage(
    	std::shared_ptr<InsertWatermarkImageRequest> request
    );

    /// <summary>
    /// Inserts a new watermark image to the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="imageFile">File with image.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="rotationAngle">The rotation angle of the watermark. (optional)</param>
    /// <param name="image">The filename of the image. If the parameter value is missing — the image data is expected in the request content. (optional)</param>
    InsertWatermarkImageOnlineResponse insertWatermarkImageOnline(
    	std::shared_ptr<InsertWatermarkImageOnlineRequest> request
    );

    /// <summary>
    /// Inserts a new watermark text to the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="watermarkText">The watermark data.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    DocumentResponse insertWatermarkText(
    	std::shared_ptr<InsertWatermarkTextRequest> request
    );

    /// <summary>
    /// Inserts a new watermark text to the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="watermarkText">The watermark data.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    InsertWatermarkTextOnlineResponse insertWatermarkTextOnline(
    	std::shared_ptr<InsertWatermarkTextOnlineRequest> request
    );

    /// <summary>
    /// Downloads a document from the Web using URL and saves it to cloud storage in the specified format.
    /// </summary>
    /// <param name="data">The properties of data downloading.</param>
    /// <param name="storage">Original document storage. (optional)</param>
    SaveResponse loadWebDocument(
    	std::shared_ptr<LoadWebDocumentRequest> request
    );

    /// <summary>
    /// Move file.
    /// </summary>
    /// <param name="destPath">Destination file path e.g. '/dest.ext'.</param>
    /// <param name="srcPath">Source file's path e.g. '/Folder 1/file.ext' or '/Bucket/Folder 1/file.ext'.</param>
    /// <param name="srcStorageName">Source storage name. (optional)</param>
    /// <param name="destStorageName">Destination storage name. (optional)</param>
    /// <param name="versionId">File version ID to move. (optional)</param>
    void moveFile(
    	std::shared_ptr<MoveFileRequest> request
    );

    /// <summary>
    /// Move folder.
    /// </summary>
    /// <param name="destPath">Destination folder path to move to e.g '/dst'.</param>
    /// <param name="srcPath">Source folder path e.g. /Folder1.</param>
    /// <param name="srcStorageName">Source storage name. (optional)</param>
    /// <param name="destStorageName">Destination storage name. (optional)</param>
    void moveFolder(
    	std::shared_ptr<MoveFolderRequest> request
    );

    /// <summary>
    /// Applies document content optimization options, specific to a particular versions of Microsoft Word.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="options">The document optimization options.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    void optimizeDocument(
    	std::shared_ptr<OptimizeDocumentRequest> request
    );

    /// <summary>
    /// Applies document content optimization options, specific to a particular versions of Microsoft Word.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="options">The document optimization options.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    HttpContent optimizeDocumentOnline(
    	std::shared_ptr<OptimizeDocumentOnlineRequest> request
    );

    /// <summary>
    /// Adds protection to the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="protectionRequest">Protection request.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    ProtectionDataResponse protectDocument(
    	std::shared_ptr<ProtectDocumentRequest> request
    );

    /// <summary>
    /// Adds protection to the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="protectionRequest">Protection request.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    ProtectDocumentOnlineResponse protectDocumentOnline(
    	std::shared_ptr<ProtectDocumentOnlineRequest> request
    );

    /// <summary>
    /// Rejects all revisions in the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    RevisionsModificationResponse rejectAllRevisions(
    	std::shared_ptr<RejectAllRevisionsRequest> request
    );

    /// <summary>
    /// Rejects all revisions in the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    RejectAllRevisionsOnlineResponse rejectAllRevisionsOnline(
    	std::shared_ptr<RejectAllRevisionsOnlineRequest> request
    );

    /// <summary>
    /// Removes a range from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="rangeStartIdentifier">The range start identifier.</param>
    /// <param name="rangeEndIdentifier">The range end identifier. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    DocumentResponse removeRange(
    	std::shared_ptr<RemoveRangeRequest> request
    );

    /// <summary>
    /// Removes a range from the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="rangeStartIdentifier">The range start identifier.</param>
    /// <param name="rangeEndIdentifier">The range end identifier. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    RemoveRangeOnlineResponse removeRangeOnline(
    	std::shared_ptr<RemoveRangeOnlineRequest> request
    );

    /// <summary>
    /// Renders a DrawingObject to the specified format.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="format">The destination format.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    HttpContent renderDrawingObject(
    	std::shared_ptr<RenderDrawingObjectRequest> request
    );

    /// <summary>
    /// Renders a DrawingObject to the specified format.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="format">The destination format.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    HttpContent renderDrawingObjectOnline(
    	std::shared_ptr<RenderDrawingObjectOnlineRequest> request
    );

    /// <summary>
    /// Renders an OfficeMath object to the specified format.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="format">The destination format.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    HttpContent renderMathObject(
    	std::shared_ptr<RenderMathObjectRequest> request
    );

    /// <summary>
    /// Renders an OfficeMath object to the specified format.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="format">The destination format.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    HttpContent renderMathObjectOnline(
    	std::shared_ptr<RenderMathObjectOnlineRequest> request
    );

    /// <summary>
    /// Renders a page to the specified format.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="pageIndex">The index of the page.</param>
    /// <param name="format">The destination format.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    HttpContent renderPage(
    	std::shared_ptr<RenderPageRequest> request
    );

    /// <summary>
    /// Renders a page to the specified format.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="pageIndex">The index of the page.</param>
    /// <param name="format">The destination format.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    HttpContent renderPageOnline(
    	std::shared_ptr<RenderPageOnlineRequest> request
    );

    /// <summary>
    /// Renders a paragraph to the specified format.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="format">The destination format.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    HttpContent renderParagraph(
    	std::shared_ptr<RenderParagraphRequest> request
    );

    /// <summary>
    /// Renders a paragraph to the specified format.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="format">The destination format.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    HttpContent renderParagraphOnline(
    	std::shared_ptr<RenderParagraphOnlineRequest> request
    );

    /// <summary>
    /// Renders a table to the specified format.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="format">The destination format.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    HttpContent renderTable(
    	std::shared_ptr<RenderTableRequest> request
    );

    /// <summary>
    /// Renders a table to the specified format.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="format">The destination format.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    HttpContent renderTableOnline(
    	std::shared_ptr<RenderTableOnlineRequest> request
    );

    /// <summary>
    /// Replaces text in the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="replaceText">The replace operation settings.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    ReplaceTextResponse replaceText(
    	std::shared_ptr<ReplaceTextRequest> request
    );

    /// <summary>
    /// Replaces text in the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="replaceText">The replace operation settings.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    ReplaceTextOnlineResponse replaceTextOnline(
    	std::shared_ptr<ReplaceTextOnlineRequest> request
    );

    /// <summary>
    /// Replaces a range with text in the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="rangeStartIdentifier">The range start identifier.</param>
    /// <param name="rangeText">Model with text for replacement.</param>
    /// <param name="rangeEndIdentifier">The range end identifier. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    DocumentResponse replaceWithText(
    	std::shared_ptr<ReplaceWithTextRequest> request
    );

    /// <summary>
    /// Replaces a range with text in the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="rangeStartIdentifier">The range start identifier.</param>
    /// <param name="rangeText">Model with text for replacement.</param>
    /// <param name="rangeEndIdentifier">The range end identifier. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    ReplaceWithTextOnlineResponse replaceWithTextOnline(
    	std::shared_ptr<ReplaceWithTextOnlineRequest> request
    );

    /// <summary>
    /// Clears the font cache.
    /// </summary>
    void resetCache(
    	std::shared_ptr<ResetCacheRequest> request
    );

    /// <summary>
    /// Converts a document in cloud storage to the specified format.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="saveOptionsData">Save options.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    SaveResponse saveAs(
    	std::shared_ptr<SaveAsRequest> request
    );

    /// <summary>
    /// Converts a document in cloud storage to the specified format.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="saveOptionsData">Save options.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    SaveAsOnlineResponse saveAsOnline(
    	std::shared_ptr<SaveAsOnlineRequest> request
    );

    /// <summary>
    /// Saves a range as a new document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="rangeStartIdentifier">The range start identifier.</param>
    /// <param name="documentParameters">Parameters of a new document.</param>
    /// <param name="rangeEndIdentifier">The range end identifier. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    DocumentResponse saveAsRange(
    	std::shared_ptr<SaveAsRangeRequest> request
    );

    /// <summary>
    /// Saves a range as a new document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="rangeStartIdentifier">The range start identifier.</param>
    /// <param name="documentParameters">Parameters of a new document.</param>
    /// <param name="rangeEndIdentifier">The range end identifier. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    SaveAsRangeOnlineResponse saveAsRangeOnline(
    	std::shared_ptr<SaveAsRangeOnlineRequest> request
    );

    /// <summary>
    /// Converts a document in cloud storage to TIFF format using detailed conversion settings.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="saveOptions">Tiff save options.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="useAntiAliasing">The flag indicating whether to use antialiasing. (optional)</param>
    /// <param name="useHighQualityRendering">The flag indicating whether to use high quality. (optional)</param>
    /// <param name="imageBrightness">The level of brightness for the generated images. (optional)</param>
    /// <param name="imageColorMode">The color mode for the generated images. (optional)</param>
    /// <param name="imageContrast">The contrast for the generated images. (optional)</param>
    /// <param name="numeralFormat">The images numeral format. (optional)</param>
    /// <param name="pageCount">The number of pages to render. (optional)</param>
    /// <param name="pageIndex">The index of the page to start rendering. (optional)</param>
    /// <param name="paperColor">The background image color. (optional)</param>
    /// <param name="pixelFormat">The pixel format of the generated images. (optional)</param>
    /// <param name="resolution">The resolution of the generated images. (optional)</param>
    /// <param name="scale">The zoom factor for the generated images. (optional)</param>
    /// <param name="tiffCompression">The compression tipe. (optional)</param>
    /// <param name="dmlRenderingMode">The optional dml rendering mode. The default value is Fallback. (optional)</param>
    /// <param name="dmlEffectsRenderingMode">The optional dml effects rendering mode. The default value is Simplified. (optional)</param>
    /// <param name="tiffBinarizationMethod">The optional TIFF binarization method. Possible values are: FloydSteinbergDithering, Threshold. (optional)</param>
    /// <param name="zipOutput">The flag indicating whether to ZIP the output. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    SaveResponse saveAsTiff(
    	std::shared_ptr<SaveAsTiffRequest> request
    );

    /// <summary>
    /// Converts a document in cloud storage to TIFF format using detailed conversion settings.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="saveOptions">Tiff save options.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="useAntiAliasing">The flag indicating whether to use antialiasing. (optional)</param>
    /// <param name="useHighQualityRendering">The flag indicating whether to use high quality. (optional)</param>
    /// <param name="imageBrightness">The level of brightness for the generated images. (optional)</param>
    /// <param name="imageColorMode">The color mode for the generated images. (optional)</param>
    /// <param name="imageContrast">The contrast for the generated images. (optional)</param>
    /// <param name="numeralFormat">The images numeral format. (optional)</param>
    /// <param name="pageCount">The number of pages to render. (optional)</param>
    /// <param name="pageIndex">The index of the page to start rendering. (optional)</param>
    /// <param name="paperColor">The background image color. (optional)</param>
    /// <param name="pixelFormat">The pixel format of the generated images. (optional)</param>
    /// <param name="resolution">The resolution of the generated images. (optional)</param>
    /// <param name="scale">The zoom factor for the generated images. (optional)</param>
    /// <param name="tiffCompression">The compression tipe. (optional)</param>
    /// <param name="dmlRenderingMode">The optional dml rendering mode. The default value is Fallback. (optional)</param>
    /// <param name="dmlEffectsRenderingMode">The optional dml effects rendering mode. The default value is Simplified. (optional)</param>
    /// <param name="tiffBinarizationMethod">The optional TIFF binarization method. Possible values are: FloydSteinbergDithering, Threshold. (optional)</param>
    /// <param name="zipOutput">The flag indicating whether to ZIP the output. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    SaveAsTiffOnlineResponse saveAsTiffOnline(
    	std::shared_ptr<SaveAsTiffOnlineRequest> request
    );

    /// <summary>
    /// Searches text, specified by the regular expression, in the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="pattern">The regular expression used to find matches.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    SearchResponse search(
    	std::shared_ptr<SearchRequest> request
    );

    /// <summary>
    /// Searches text, specified by the regular expression, in the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="pattern">The regular expression used to find matches.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    SearchResponse searchOnline(
    	std::shared_ptr<SearchOnlineRequest> request
    );

    /// <summary>
    /// Splits a document into parts and saves them in the specified format.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="format">The format to split.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="from">The start page. (optional)</param>
    /// <param name="to">The end page. (optional)</param>
    /// <param name="zipOutput">The flag indicating whether to ZIP the output. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    SplitDocumentResponse splitDocument(
    	std::shared_ptr<SplitDocumentRequest> request
    );

    /// <summary>
    /// Splits a document into parts and saves them in the specified format.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="format">The format to split.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="from">The start page. (optional)</param>
    /// <param name="to">The end page. (optional)</param>
    /// <param name="zipOutput">The flag indicating whether to ZIP the output. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    SplitDocumentOnlineResponse splitDocumentOnline(
    	std::shared_ptr<SplitDocumentOnlineRequest> request
    );

    /// <summary>
    /// Removes protection from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="protectionRequest">Protection request.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    ProtectionDataResponse unprotectDocument(
    	std::shared_ptr<UnprotectDocumentRequest> request
    );

    /// <summary>
    /// Removes protection from the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="protectionRequest">Protection request.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    UnprotectDocumentOnlineResponse unprotectDocumentOnline(
    	std::shared_ptr<UnprotectDocumentOnlineRequest> request
    );

    /// <summary>
    /// Updates a bookmark in the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="bookmarkName">The name of the bookmark.</param>
    /// <param name="bookmarkData">Bookmark data.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    BookmarkResponse updateBookmark(
    	std::shared_ptr<UpdateBookmarkRequest> request
    );

    /// <summary>
    /// Updates a bookmark in the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="bookmarkName">The name of the bookmark.</param>
    /// <param name="bookmarkData">Bookmark data.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    UpdateBookmarkOnlineResponse updateBookmarkOnline(
    	std::shared_ptr<UpdateBookmarkOnlineRequest> request
    );

    /// <summary>
    /// The 'nodePath' parameter should refer to a paragraph, a cell or a row.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="borderType">Border type.</param>
    /// <param name="borderProperties">Border properties.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    BorderResponse updateBorder(
    	std::shared_ptr<UpdateBorderRequest> request
    );

    /// <summary>
    /// Updates a border in the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="borderProperties">Border properties.</param>
    /// <param name="borderType">Border type.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    UpdateBorderOnlineResponse updateBorderOnline(
    	std::shared_ptr<UpdateBorderOnlineRequest> request
    );

    /// <summary>
    /// Updates a comment in the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="commentIndex">The index of the comment.</param>
    /// <param name="comment">Comment data.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    CommentResponse updateComment(
    	std::shared_ptr<UpdateCommentRequest> request
    );

    /// <summary>
    /// Updates a comment in the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="commentIndex">The index of the comment.</param>
    /// <param name="comment">Comment data.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    UpdateCommentOnlineResponse updateCommentOnline(
    	std::shared_ptr<UpdateCommentOnlineRequest> request
    );

    /// <summary>
    /// Updates a DrawingObject in the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="drawingObject">Drawing object parameters.</param>
    /// <param name="imageFile">File with image.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    DrawingObjectResponse updateDrawingObject(
    	std::shared_ptr<UpdateDrawingObjectRequest> request
    );

    /// <summary>
    /// Updates a DrawingObject in the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="drawingObject">Drawing object parameters.</param>
    /// <param name="imageFile">File with image.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    UpdateDrawingObjectOnlineResponse updateDrawingObjectOnline(
    	std::shared_ptr<UpdateDrawingObjectOnlineRequest> request
    );

    /// <summary>
    /// Updates a field in the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="field">Field data.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    FieldResponse updateField(
    	std::shared_ptr<UpdateFieldRequest> request
    );

    /// <summary>
    /// Updates a field in the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="field">Field data.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    UpdateFieldOnlineResponse updateFieldOnline(
    	std::shared_ptr<UpdateFieldOnlineRequest> request
    );

    /// <summary>
    /// Reevaluates field values in the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    DocumentResponse updateFields(
    	std::shared_ptr<UpdateFieldsRequest> request
    );

    /// <summary>
    /// Reevaluates field values in the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    UpdateFieldsOnlineResponse updateFieldsOnline(
    	std::shared_ptr<UpdateFieldsOnlineRequest> request
    );

    /// <summary>
    /// Updates a footnote in the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="footnoteDto">Footnote data.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    FootnoteResponse updateFootnote(
    	std::shared_ptr<UpdateFootnoteRequest> request
    );

    /// <summary>
    /// Updates a footnote in the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="footnoteDto">Footnote data.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    UpdateFootnoteOnlineResponse updateFootnoteOnline(
    	std::shared_ptr<UpdateFootnoteOnlineRequest> request
    );

    /// <summary>
    /// Updates a form field in the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="formField">From field data.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    FormFieldResponse updateFormField(
    	std::shared_ptr<UpdateFormFieldRequest> request
    );

    /// <summary>
    /// Updates a form field in the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="formField">From field data.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    UpdateFormFieldOnlineResponse updateFormFieldOnline(
    	std::shared_ptr<UpdateFormFieldOnlineRequest> request
    );

    /// <summary>
    /// Updates a list in the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="listId">The list Id.</param>
    /// <param name="listUpdate">List object.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    ListResponse updateList(
    	std::shared_ptr<UpdateListRequest> request
    );

    /// <summary>
    /// Updates the level of a List element in the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="listId">The list Id.</param>
    /// <param name="listLevel">The list level.</param>
    /// <param name="listUpdate">List object.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    ListResponse updateListLevel(
    	std::shared_ptr<UpdateListLevelRequest> request
    );

    /// <summary>
    /// Updates the level of a List element in the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="listId">The list Id.</param>
    /// <param name="listUpdate">List object.</param>
    /// <param name="listLevel">The list level.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    UpdateListLevelOnlineResponse updateListLevelOnline(
    	std::shared_ptr<UpdateListLevelOnlineRequest> request
    );

    /// <summary>
    /// Updates a list in the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="listId">The list Id.</param>
    /// <param name="listUpdate">List object.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    UpdateListOnlineResponse updateListOnline(
    	std::shared_ptr<UpdateListOnlineRequest> request
    );

    /// <summary>
    /// Updates the formatting properties of a paragraph in the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="paragraphFormatDto">Dto for paragraph format update.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    ParagraphFormatResponse updateParagraphFormat(
    	std::shared_ptr<UpdateParagraphFormatRequest> request
    );

    /// <summary>
    /// Updates the formatting properties of a paragraph in the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="paragraphFormatDto">Dto for paragraph format update.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    UpdateParagraphFormatOnlineResponse updateParagraphFormatOnline(
    	std::shared_ptr<UpdateParagraphFormatOnlineRequest> request
    );

    /// <summary>
    /// Updates the formatting properties of a paragraph list in the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="listFormatDto">ListFormatUpdate dto.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    ParagraphListFormatResponse updateParagraphListFormat(
    	std::shared_ptr<UpdateParagraphListFormatRequest> request
    );

    /// <summary>
    /// Updates the formatting properties of a paragraph list in the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="listFormatDto">ListFormatUpdate dto.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    UpdateParagraphListFormatOnlineResponse updateParagraphListFormatOnline(
    	std::shared_ptr<UpdateParagraphListFormatOnlineRequest> request
    );

    /// <summary>
    /// Updates a Run object in the paragraph.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="paragraphPath">The path to the paragraph in the document tree.</param>
    /// <param name="index">Object index.</param>
    /// <param name="run">Run data.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    RunResponse updateRun(
    	std::shared_ptr<UpdateRunRequest> request
    );

    /// <summary>
    /// Updates the font properties of a Run object in the paragraph.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="paragraphPath">The path to the paragraph in the document tree.</param>
    /// <param name="index">Object index.</param>
    /// <param name="fontDto">Font dto object.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    FontResponse updateRunFont(
    	std::shared_ptr<UpdateRunFontRequest> request
    );

    /// <summary>
    /// Updates the font properties of a Run object in the paragraph.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="paragraphPath">The path to the paragraph in the document tree.</param>
    /// <param name="fontDto">Font dto object.</param>
    /// <param name="index">Object index.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    UpdateRunFontOnlineResponse updateRunFontOnline(
    	std::shared_ptr<UpdateRunFontOnlineRequest> request
    );

    /// <summary>
    /// Updates a Run object in the paragraph.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="paragraphPath">The path to the paragraph in the document tree.</param>
    /// <param name="run">Run data.</param>
    /// <param name="index">Object index.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    UpdateRunOnlineResponse updateRunOnline(
    	std::shared_ptr<UpdateRunOnlineRequest> request
    );

    /// <summary>
    /// Updates the page setup of a section in the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="sectionIndex">The index of the section.</param>
    /// <param name="pageSetup">Page setup properties dto.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    SectionPageSetupResponse updateSectionPageSetup(
    	std::shared_ptr<UpdateSectionPageSetupRequest> request
    );

    /// <summary>
    /// Updates the page setup of a section in the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="sectionIndex">The index of the section.</param>
    /// <param name="pageSetup">Page setup properties dto.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    UpdateSectionPageSetupOnlineResponse updateSectionPageSetupOnline(
    	std::shared_ptr<UpdateSectionPageSetupOnlineRequest> request
    );

    /// <summary>
    /// Updates a style in the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="styleName">The name of the style.</param>
    /// <param name="styleUpdate">Style properties to update.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    StyleResponse updateStyle(
    	std::shared_ptr<UpdateStyleRequest> request
    );

    /// <summary>
    /// Updates a style in the document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="styleName">The name of the style.</param>
    /// <param name="styleUpdate">Style properties to update.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    UpdateStyleOnlineResponse updateStyleOnline(
    	std::shared_ptr<UpdateStyleOnlineRequest> request
    );

    /// <summary>
    /// Updates the formatting properties of a cell in the table row.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="tableRowPath">The path to the table row in the document tree.</param>
    /// <param name="index">Object index.</param>
    /// <param name="format">The properties.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    TableCellFormatResponse updateTableCellFormat(
    	std::shared_ptr<UpdateTableCellFormatRequest> request
    );

    /// <summary>
    /// Updates the formatting properties of a cell in the table row.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="tableRowPath">The path to the table row in the document tree.</param>
    /// <param name="format">The properties.</param>
    /// <param name="index">Object index.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    UpdateTableCellFormatOnlineResponse updateTableCellFormatOnline(
    	std::shared_ptr<UpdateTableCellFormatOnlineRequest> request
    );

    /// <summary>
    /// Updates properties of a table in the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="properties">The properties.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    TablePropertiesResponse updateTableProperties(
    	std::shared_ptr<UpdateTablePropertiesRequest> request
    );

    /// <summary>
    /// Updates properties of a table in the document node.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="properties">The properties.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    UpdateTablePropertiesOnlineResponse updateTablePropertiesOnline(
    	std::shared_ptr<UpdateTablePropertiesOnlineRequest> request
    );

    /// <summary>
    /// Updates the formatting properties of a table row.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="tablePath">The path to the table in the document tree.</param>
    /// <param name="index">Object index.</param>
    /// <param name="format">Table row format.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    TableRowFormatResponse updateTableRowFormat(
    	std::shared_ptr<UpdateTableRowFormatRequest> request
    );

    /// <summary>
    /// Updates the formatting properties of a table row.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="tablePath">The path to the table in the document tree.</param>
    /// <param name="format">Table row format.</param>
    /// <param name="index">Object index.</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    UpdateTableRowFormatOnlineResponse updateTableRowFormatOnline(
    	std::shared_ptr<UpdateTableRowFormatOnlineRequest> request
    );

    /// <summary>
    /// Upload file.
    /// </summary>
    /// <param name="fileContent">File to upload.</param>
    /// <param name="path">Path where to upload including filename and extension e.g. /file.ext or /Folder 1/file.ext If the content is multipart and path does not contains the file name it tries to get them from filename parameter from Content-Disposition header.</param>
    /// <param name="storageName">Storage name. (optional)</param>
    FilesUploadResult uploadFile(
    	std::shared_ptr<UploadFileRequest> request
    );

public:
    explicit WordsApi(std::shared_ptr<ApiConfiguration> configuration);
    virtual ~WordsApi() = default;

protected:
    std::shared_ptr<ApiClient> m_ApiClient;
};

}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_WordsApi_H_ */
