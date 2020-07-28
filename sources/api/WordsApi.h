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
#include "requests/AppendDocumentRequest.h"
#include "requests/AppendDocumentOnlineRequest.h"
#include "requests/ApplyStyleToDocumentElementRequest.h"
#include "requests/BuildReportRequest.h"
#include "requests/BuildReportOnlineRequest.h"
#include "requests/ClassifyRequest.h"
#include "requests/ClassifyDocumentRequest.h"
#include "requests/CompareDocumentRequest.h"
#include "requests/ConvertDocumentRequest.h"
#include "requests/CopyFileRequest.h"
#include "requests/CopyFolderRequest.h"
#include "requests/CopyStyleRequest.h"
#include "requests/CreateDocumentRequest.h"
#include "requests/CreateFolderRequest.h"
#include "requests/CreateOrUpdateDocumentPropertyRequest.h"
#include "requests/DeleteAllParagraphTabStopsRequest.h"
#include "requests/DeleteBorderRequest.h"
#include "requests/DeleteBordersRequest.h"
#include "requests/DeleteCommentRequest.h"
#include "requests/DeleteDocumentPropertyRequest.h"
#include "requests/DeleteDrawingObjectRequest.h"
#include "requests/DeleteFieldRequest.h"
#include "requests/DeleteFieldsRequest.h"
#include "requests/DeleteFileRequest.h"
#include "requests/DeleteFolderRequest.h"
#include "requests/DeleteFootnoteRequest.h"
#include "requests/DeleteFormFieldRequest.h"
#include "requests/DeleteHeaderFooterRequest.h"
#include "requests/DeleteHeadersFootersRequest.h"
#include "requests/DeleteMacrosRequest.h"
#include "requests/DeleteOfficeMathObjectRequest.h"
#include "requests/DeleteParagraphRequest.h"
#include "requests/DeleteParagraphListFormatRequest.h"
#include "requests/DeleteParagraphTabStopRequest.h"
#include "requests/DeleteRunRequest.h"
#include "requests/DeleteSectionRequest.h"
#include "requests/DeleteTableRequest.h"
#include "requests/DeleteTableCellRequest.h"
#include "requests/DeleteTableRowRequest.h"
#include "requests/DeleteWatermarkRequest.h"
#include "requests/DownloadFileRequest.h"
#include "requests/ExecuteMailMergeRequest.h"
#include "requests/ExecuteMailMergeOnlineRequest.h"
#include "requests/GetAvailableFontsRequest.h"
#include "requests/GetBookmarkByNameRequest.h"
#include "requests/GetBookmarksRequest.h"
#include "requests/GetBorderRequest.h"
#include "requests/GetBordersRequest.h"
#include "requests/GetCommentRequest.h"
#include "requests/GetCommentsRequest.h"
#include "requests/GetDocumentRequest.h"
#include "requests/GetDocumentDrawingObjectByIndexRequest.h"
#include "requests/GetDocumentDrawingObjectImageDataRequest.h"
#include "requests/GetDocumentDrawingObjectOleDataRequest.h"
#include "requests/GetDocumentDrawingObjectsRequest.h"
#include "requests/GetDocumentFieldNamesRequest.h"
#include "requests/GetDocumentFieldNamesOnlineRequest.h"
#include "requests/GetDocumentHyperlinkByIndexRequest.h"
#include "requests/GetDocumentHyperlinksRequest.h"
#include "requests/GetDocumentPropertiesRequest.h"
#include "requests/GetDocumentPropertyRequest.h"
#include "requests/GetDocumentProtectionRequest.h"
#include "requests/GetDocumentStatisticsRequest.h"
#include "requests/GetDocumentStatisticsOnlineRequest.h"
#include "requests/GetDocumentWithFormatRequest.h"
#include "requests/GetFieldRequest.h"
#include "requests/GetFieldsRequest.h"
#include "requests/GetFilesListRequest.h"
#include "requests/GetFootnoteRequest.h"
#include "requests/GetFootnotesRequest.h"
#include "requests/GetFormFieldRequest.h"
#include "requests/GetFormFieldsRequest.h"
#include "requests/GetHeaderFooterRequest.h"
#include "requests/GetHeaderFooterOfSectionRequest.h"
#include "requests/GetHeaderFootersRequest.h"
#include "requests/GetListRequest.h"
#include "requests/GetListsRequest.h"
#include "requests/GetOfficeMathObjectRequest.h"
#include "requests/GetOfficeMathObjectsRequest.h"
#include "requests/GetParagraphRequest.h"
#include "requests/GetParagraphFormatRequest.h"
#include "requests/GetParagraphListFormatRequest.h"
#include "requests/GetParagraphsRequest.h"
#include "requests/GetParagraphTabStopsRequest.h"
#include "requests/GetRangeTextRequest.h"
#include "requests/GetRunRequest.h"
#include "requests/GetRunFontRequest.h"
#include "requests/GetRunsRequest.h"
#include "requests/GetSectionRequest.h"
#include "requests/GetSectionPageSetupRequest.h"
#include "requests/GetSectionsRequest.h"
#include "requests/GetStyleRequest.h"
#include "requests/GetStyleFromDocumentElementRequest.h"
#include "requests/GetStylesRequest.h"
#include "requests/GetTableRequest.h"
#include "requests/GetTableCellRequest.h"
#include "requests/GetTableCellFormatRequest.h"
#include "requests/GetTablePropertiesRequest.h"
#include "requests/GetTableRowRequest.h"
#include "requests/GetTableRowFormatRequest.h"
#include "requests/GetTablesRequest.h"
#include "requests/InsertCommentRequest.h"
#include "requests/InsertDrawingObjectRequest.h"
#include "requests/InsertFieldRequest.h"
#include "requests/InsertFootnoteRequest.h"
#include "requests/InsertFormFieldRequest.h"
#include "requests/InsertHeaderFooterRequest.h"
#include "requests/InsertListRequest.h"
#include "requests/InsertOrUpdateParagraphTabStopRequest.h"
#include "requests/InsertPageNumbersRequest.h"
#include "requests/InsertParagraphRequest.h"
#include "requests/InsertRunRequest.h"
#include "requests/InsertStyleRequest.h"
#include "requests/InsertTableRequest.h"
#include "requests/InsertTableCellRequest.h"
#include "requests/InsertTableRowRequest.h"
#include "requests/InsertWatermarkImageRequest.h"
#include "requests/InsertWatermarkTextRequest.h"
#include "requests/LoadWebDocumentRequest.h"
#include "requests/MoveFileRequest.h"
#include "requests/MoveFolderRequest.h"
#include "requests/OptimizeDocumentRequest.h"
#include "requests/ProtectDocumentRequest.h"
#include "requests/RejectAllRevisionsRequest.h"
#include "requests/RemoveRangeRequest.h"
#include "requests/RenderDrawingObjectRequest.h"
#include "requests/RenderMathObjectRequest.h"
#include "requests/RenderPageRequest.h"
#include "requests/RenderParagraphRequest.h"
#include "requests/RenderTableRequest.h"
#include "requests/ReplaceTextRequest.h"
#include "requests/ReplaceWithTextRequest.h"
#include "requests/ResetCacheRequest.h"
#include "requests/SaveAsRequest.h"
#include "requests/SaveAsOnlineRequest.h"
#include "requests/SaveAsRangeRequest.h"
#include "requests/SaveAsTiffRequest.h"
#include "requests/SearchRequest.h"
#include "requests/SplitDocumentRequest.h"
#include "requests/UnprotectDocumentRequest.h"
#include "requests/UpdateBookmarkRequest.h"
#include "requests/UpdateBorderRequest.h"
#include "requests/UpdateCommentRequest.h"
#include "requests/UpdateDrawingObjectRequest.h"
#include "requests/UpdateFieldRequest.h"
#include "requests/UpdateFieldsRequest.h"
#include "requests/UpdateFootnoteRequest.h"
#include "requests/UpdateFormFieldRequest.h"
#include "requests/UpdateListRequest.h"
#include "requests/UpdateListLevelRequest.h"
#include "requests/UpdateParagraphFormatRequest.h"
#include "requests/UpdateParagraphListFormatRequest.h"
#include "requests/UpdateRunRequest.h"
#include "requests/UpdateRunFontRequest.h"
#include "requests/UpdateSectionPageSetupRequest.h"
#include "requests/UpdateStyleRequest.h"
#include "requests/UpdateTableCellFormatRequest.h"
#include "requests/UpdateTablePropertiesRequest.h"
#include "requests/UpdateTableRowFormatRequest.h"
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
#include "RangeTextResponse.h"
#include "ReplaceRange.h"
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
#include "TableCellFormatResponse.h"
#include "TableCellInsert.h"
#include "TableCellResponse.h"
#include "TableInsert.h"
#include "TableLink.h"
#include "TableLinkCollection.h"
#include "TableLinkCollectionResponse.h"
#include "TableProperties.h"
#include "TablePropertiesResponse.h"
#include "TableResponse.h"
#include "TableRow.h"
#include "TableRowFormat.h"
#include "TableRowFormatResponse.h"
#include "TableRowInsert.h"
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
    /// Accepts all revisions in document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    pplx::task<AsposeResponse<RevisionsModificationResponse>> acceptAllRevisions(
    	std::shared_ptr<AcceptAllRevisionsRequest> request
    );

    /// <summary>
    /// Appends documents to original document.
    /// </summary>
    /// <param name="name">Original document name.</param>
    /// <param name="documentList"><see cref="DocumentEntryList"/> with a list of documents to append.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<DocumentResponse>> appendDocument(
    	std::shared_ptr<AppendDocumentRequest> request
    );

    /// <summary>
    /// Appends documents to original document.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="documentList"><see cref="DocumentEntryList"/> with a list of documents to append.</param>
    pplx::task<HttpContent> appendDocumentOnline(
    	std::shared_ptr<AppendDocumentOnlineRequest> request
    );

    /// <summary>
    /// Apply a style to the document node.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="styleApply">Style to apply.</param>
    /// <param name="styledNodePath">The path to the node that supports a style. Supported node types: ParagraphFormat, List, ListLevel, Table.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<WordsResponse>> applyStyleToDocumentElement(
    	std::shared_ptr<ApplyStyleToDocumentElementRequest> request
    );

    /// <summary>
    /// Executes document "build report" operation.
    /// </summary>
    /// <param name="name">The template name.</param>
    /// <param name="data">A string providing a data to populate the specified template. The string must be of one of the following types: xml, json, csv.</param>
    /// <param name="reportEngineSettings">An object providing a settings of report engine.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved with autogenerated name. (optional)</param>
    pplx::task<AsposeResponse<DocumentResponse>> buildReport(
    	std::shared_ptr<BuildReportRequest> request
    );

    /// <summary>
    /// Executes document "build report" online operation.
    /// </summary>
    /// <param name="template">File with template.</param>
    /// <param name="data">A string providing a data to populate the specified template. The string must be of one of the following types: xml, json, csv.</param>
    /// <param name="reportEngineSettings">An object providing a settings of report engine.</param>
    /// <param name="documentFileName">This file name will be used when resulting document has dynamic field for document file name {filename}. If it is not set, "template" will be used instead. (optional)</param>
    pplx::task<HttpContent> buildReportOnline(
    	std::shared_ptr<BuildReportOnlineRequest> request
    );

    /// <summary>
    /// Classifies raw text.
    /// </summary>
    /// <param name="text">Text to classify.</param>
    /// <param name="bestClassesCount">Number of the best classes to return. (optional)</param>
    pplx::task<AsposeResponse<ClassificationResponse>> classify(
    	std::shared_ptr<ClassifyRequest> request
    );

    /// <summary>
    /// Classifies document.
    /// </summary>
    /// <param name="documentName">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="bestClassesCount">Count of the best classes to return. (optional)</param>
    /// <param name="taxonomy">Taxonomy to use for classification return. (optional)</param>
    pplx::task<AsposeResponse<ClassificationResponse>> classifyDocument(
    	std::shared_ptr<ClassifyDocumentRequest> request
    );

    /// <summary>
    /// Compares document with original document.
    /// </summary>
    /// <param name="name">Original document name.</param>
    /// <param name="compareData">CompareData with a document to compare.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    pplx::task<AsposeResponse<DocumentResponse>> compareDocument(
    	std::shared_ptr<CompareDocumentRequest> request
    );

    /// <summary>
    /// Converts document from the request's content to the specified format.
    /// </summary>
    /// <param name="document">Converting document.</param>
    /// <param name="format">Format to convert.</param>
    /// <param name="outPath">Path for saving operation result to the local storage. (optional)</param>
    /// <param name="fileNameFieldValue">This file name will be used when resulting document has dynamic field for document file name {filename}. If it is not set, "sourceFilename" will be used instead. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    pplx::task<HttpContent> convertDocument(
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
    pplx::task<std::shared_ptr<web::http::http_response>> copyFile(
    	std::shared_ptr<CopyFileRequest> request
    );

    /// <summary>
    /// Copy folder.
    /// </summary>
    /// <param name="destPath">Destination folder path e.g. '/dst'.</param>
    /// <param name="srcPath">Source folder path e.g. /Folder1.</param>
    /// <param name="srcStorageName">Source storage name. (optional)</param>
    /// <param name="destStorageName">Destination storage name. (optional)</param>
    pplx::task<std::shared_ptr<web::http::http_response>> copyFolder(
    	std::shared_ptr<CopyFolderRequest> request
    );

    /// <summary>
    /// Copy and insert a new style to the document, returns a copied style.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="styleCopy">Style to copy.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<StyleResponse>> copyStyle(
    	std::shared_ptr<CopyStyleRequest> request
    );

    /// <summary>
    /// Creates new document.
    /// Document is created with format which is recognized from file extensions.
    /// Supported extensions: ".doc", ".docx", ".docm", ".dot", ".dotm", ".dotx", ".flatopc", ".fopc", ".flatopc_macro", ".fopc_macro", ".flatopc_template", ".fopc_template", ".flatopc_template_macro", ".fopc_template_macro", ".wordml", ".wml", ".rtf".
    /// </summary>
    /// <param name="fileName">The document name. (optional)</param>
    /// <param name="folder">The document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    pplx::task<AsposeResponse<DocumentResponse>> createDocument(
    	std::shared_ptr<CreateDocumentRequest> request
    );

    /// <summary>
    /// Create the folder.
    /// </summary>
    /// <param name="path">Target folder's path e.g. Folder1/Folder2/. The folders will be created recursively.</param>
    /// <param name="storageName">Storage name. (optional)</param>
    pplx::task<std::shared_ptr<web::http::http_response>> createFolder(
    	std::shared_ptr<CreateFolderRequest> request
    );

    /// <summary>
    /// Adds new or update existing document property.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="propertyName">The property name.</param>
    /// <param name="property">The property with new value.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<DocumentPropertyResponse>> createOrUpdateDocumentProperty(
    	std::shared_ptr<CreateOrUpdateDocumentPropertyRequest> request
    );

    /// <summary>
    /// Remove all tab stops.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node which contains paragraph. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    pplx::task<AsposeResponse<TabStopsResponse>> deleteAllParagraphTabStops(
    	std::shared_ptr<DeleteAllParagraphTabStopsRequest> request
    );

    /// <summary>
    /// 'nodePath' should refer to paragraph, cell or row.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="borderType">Border type.</param>
    /// <param name="nodePath">Path to the node with border(node should be paragraph, cell or row). (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<BorderResponse>> deleteBorder(
    	std::shared_ptr<DeleteBorderRequest> request
    );

    /// <summary>
    /// 'nodePath' should refer to paragraph, cell or row.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="nodePath">Path to the node with borders(node should be paragraph, cell or row). (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<BordersResponse>> deleteBorders(
    	std::shared_ptr<DeleteBordersRequest> request
    );

    /// <summary>
    /// Removes comment from document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="commentIndex">The comment index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<web::http::http_response>> deleteComment(
    	std::shared_ptr<DeleteCommentRequest> request
    );

    /// <summary>
    /// Deletes document property.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="propertyName">The property name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<web::http::http_response>> deleteDocumentProperty(
    	std::shared_ptr<DeleteDocumentPropertyRequest> request
    );

    /// <summary>
    /// Removes drawing object from document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node, which contains collection of drawing objects. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<web::http::http_response>> deleteDrawingObject(
    	std::shared_ptr<DeleteDrawingObjectRequest> request
    );

    /// <summary>
    /// Deletes field from document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node, which contains collection of fields. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<web::http::http_response>> deleteField(
    	std::shared_ptr<DeleteFieldRequest> request
    );

    /// <summary>
    /// Removes fields from section paragraph.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="nodePath">Path to the node, which contains collection of fields. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<web::http::http_response>> deleteFields(
    	std::shared_ptr<DeleteFieldsRequest> request
    );

    /// <summary>
    /// Delete file.
    /// </summary>
    /// <param name="path">Path of the file including file name and extension e.g. /Folder1/file.ext.</param>
    /// <param name="storageName">Storage name. (optional)</param>
    /// <param name="versionId">File version ID to delete. (optional)</param>
    pplx::task<std::shared_ptr<web::http::http_response>> deleteFile(
    	std::shared_ptr<DeleteFileRequest> request
    );

    /// <summary>
    /// Delete folder.
    /// </summary>
    /// <param name="path">Folder path e.g. /Folder1s.</param>
    /// <param name="storageName">Storage name. (optional)</param>
    /// <param name="recursive">Enable to delete folders, subfolders and files. (optional)</param>
    pplx::task<std::shared_ptr<web::http::http_response>> deleteFolder(
    	std::shared_ptr<DeleteFolderRequest> request
    );

    /// <summary>
    /// Removes footnote from document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node, which contains collection of footnotes. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<web::http::http_response>> deleteFootnote(
    	std::shared_ptr<DeleteFootnoteRequest> request
    );

    /// <summary>
    /// Removes form field from document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node that contains collection of formfields. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<web::http::http_response>> deleteFormField(
    	std::shared_ptr<DeleteFormFieldRequest> request
    );

    /// <summary>
    /// Deletes header/footer from document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="sectionPath">Path to parent section.</param>
    /// <param name="index">Object index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<web::http::http_response>> deleteHeaderFooter(
    	std::shared_ptr<DeleteHeaderFooterRequest> request
    );

    /// <summary>
    /// Deletes document headers and footers.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="sectionPath">Path to parent section.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="headersFootersTypes">List of types of headers and footers. (optional)</param>
    pplx::task<std::shared_ptr<web::http::http_response>> deleteHeadersFooters(
    	std::shared_ptr<DeleteHeadersFootersRequest> request
    );

    /// <summary>
    /// Removes macros from document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<web::http::http_response>> deleteMacros(
    	std::shared_ptr<DeleteMacrosRequest> request
    );

    /// <summary>
    /// Removes OfficeMath object from document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node, which contains collection of OfficeMath objects. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<web::http::http_response>> deleteOfficeMathObject(
    	std::shared_ptr<DeleteOfficeMathObjectRequest> request
    );

    /// <summary>
    /// Removes paragraph from section.
    /// </summary>
    /// <param name="name">The file name.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node which contains paragraphs. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<web::http::http_response>> deleteParagraph(
    	std::shared_ptr<DeleteParagraphRequest> request
    );

    /// <summary>
    /// Delete paragraph list format, returns updated list format properties.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node which contains paragraphs. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<ParagraphListFormatResponse>> deleteParagraphListFormat(
    	std::shared_ptr<DeleteParagraphListFormatRequest> request
    );

    /// <summary>
    /// Remove the i-th tab stop.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="position">a tab stop position to remove.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node which contains paragraph. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    pplx::task<AsposeResponse<TabStopsResponse>> deleteParagraphTabStop(
    	std::shared_ptr<DeleteParagraphTabStopRequest> request
    );

    /// <summary>
    /// Removes run from document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="paragraphPath">Path to parent paragraph.</param>
    /// <param name="index">Object index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<web::http::http_response>> deleteRun(
    	std::shared_ptr<DeleteRunRequest> request
    );

    /// <summary>
    /// Removes section from document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="sectionIndex">Section index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<web::http::http_response>> deleteSection(
    	std::shared_ptr<DeleteSectionRequest> request
    );

    /// <summary>
    /// Deletes a table.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node, which contains tables. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<web::http::http_response>> deleteTable(
    	std::shared_ptr<DeleteTableRequest> request
    );

    /// <summary>
    /// Deletes a table cell.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="tableRowPath">Path to table row.</param>
    /// <param name="index">Object index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<web::http::http_response>> deleteTableCell(
    	std::shared_ptr<DeleteTableCellRequest> request
    );

    /// <summary>
    /// Deletes a table row.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="tablePath">Path to table.</param>
    /// <param name="index">Object index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<web::http::http_response>> deleteTableRow(
    	std::shared_ptr<DeleteTableRowRequest> request
    );

    /// <summary>
    /// Deletes watermark (for deleting last watermark from the document).
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<DocumentResponse>> deleteWatermark(
    	std::shared_ptr<DeleteWatermarkRequest> request
    );

    /// <summary>
    /// Download file.
    /// </summary>
    /// <param name="path">Path of the file including the file name and extension e.g. /folder1/file.ext.</param>
    /// <param name="storageName">Storage name. (optional)</param>
    /// <param name="versionId">File version ID to download. (optional)</param>
    pplx::task<HttpContent> downloadFile(
    	std::shared_ptr<DownloadFileRequest> request
    );

    /// <summary>
    /// Executes document mail merge operation.
    /// </summary>
    /// <param name="name">The template name.</param>
    /// <param name="data">Mail merge data. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="withRegions">With regions flag. (optional)</param>
    /// <param name="mailMergeDataFile">Mail merge data file. (optional)</param>
    /// <param name="cleanup">Clean up options. (optional)</param>
    /// <param name="useWholeParagraphAsRegion">Gets or sets a value indicating whether paragraph with TableStart or. TableEnd field should be fully included into mail merge region or particular range between TableStart and TableEnd fields. The default value is true. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved with autogenerated name. (optional)</param>
    pplx::task<AsposeResponse<DocumentResponse>> executeMailMerge(
    	std::shared_ptr<ExecuteMailMergeRequest> request
    );

    /// <summary>
    /// Executes document mail merge online.
    /// </summary>
    /// <param name="template">File with template.</param>
    /// <param name="data">File with mailmerge data.</param>
    /// <param name="withRegions">With regions flag. (optional)</param>
    /// <param name="cleanup">Clean up options. (optional)</param>
    /// <param name="documentFileName">This file name will be used when resulting document has dynamic field for document file name {filename}. If it is not set, "template" will be used instead. (optional)</param>
    pplx::task<HttpContent> executeMailMergeOnline(
    	std::shared_ptr<ExecuteMailMergeOnlineRequest> request
    );

    /// <summary>
    /// Gets the list of fonts, available for document processing.
    /// </summary>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    pplx::task<AsposeResponse<AvailableFontsResponse>> getAvailableFonts(
    	std::shared_ptr<GetAvailableFontsRequest> request
    );

    /// <summary>
    /// Reads document bookmark data by its name.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="bookmarkName">The bookmark name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<BookmarkResponse>> getBookmarkByName(
    	std::shared_ptr<GetBookmarkByNameRequest> request
    );

    /// <summary>
    /// Reads document bookmarks common info.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<BookmarksResponse>> getBookmarks(
    	std::shared_ptr<GetBookmarksRequest> request
    );

    /// <summary>
    /// 'nodePath' should refer to paragraph, cell or row.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="borderType">Border type.</param>
    /// <param name="nodePath">Path to the node with border(node should be paragraph, cell or row). (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<BorderResponse>> getBorder(
    	std::shared_ptr<GetBorderRequest> request
    );

    /// <summary>
    /// 'nodePath' should refer to paragraph, cell or row.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="nodePath">Path to the node with borders (node should be paragraph, cell or row). (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<BordersResponse>> getBorders(
    	std::shared_ptr<GetBordersRequest> request
    );

    /// <summary>
    /// Gets comment from document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="commentIndex">The comment index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<CommentResponse>> getComment(
    	std::shared_ptr<GetCommentRequest> request
    );

    /// <summary>
    /// Gets comments from document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<CommentsResponse>> getComments(
    	std::shared_ptr<GetCommentsRequest> request
    );

    /// <summary>
    /// Reads document common info.
    /// </summary>
    /// <param name="documentName">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<DocumentResponse>> getDocument(
    	std::shared_ptr<GetDocumentRequest> request
    );

    /// <summary>
    /// Reads document drawing object common info by its index or convert to format specified.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node, which contains collection of drawing objects. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<DrawingObjectResponse>> getDocumentDrawingObjectByIndex(
    	std::shared_ptr<GetDocumentDrawingObjectByIndexRequest> request
    );

    /// <summary>
    /// Reads drawing object image data.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node, which contains collection of drawing objects. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<HttpContent> getDocumentDrawingObjectImageData(
    	std::shared_ptr<GetDocumentDrawingObjectImageDataRequest> request
    );

    /// <summary>
    /// Gets drawing object OLE data.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node, which contains collection of drawing objects. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<HttpContent> getDocumentDrawingObjectOleData(
    	std::shared_ptr<GetDocumentDrawingObjectOleDataRequest> request
    );

    /// <summary>
    /// Reads document drawing objects common info.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="nodePath">Path to the node, which contains collection of drawing objects. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<DrawingObjectsResponse>> getDocumentDrawingObjects(
    	std::shared_ptr<GetDocumentDrawingObjectsRequest> request
    );

    /// <summary>
    /// Reads document field names.
    /// </summary>
    /// <param name="name">The template name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="useNonMergeFields">If true, result includes "mustache" field names. (optional)</param>
    pplx::task<AsposeResponse<FieldNamesResponse>> getDocumentFieldNames(
    	std::shared_ptr<GetDocumentFieldNamesRequest> request
    );

    /// <summary>
    /// Reads document field names.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="useNonMergeFields">If true, result includes "mustache" field names. (optional)</param>
    pplx::task<HttpContent> getDocumentFieldNamesOnline(
    	std::shared_ptr<GetDocumentFieldNamesOnlineRequest> request
    );

    /// <summary>
    /// Reads document hyperlink by its index.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="hyperlinkIndex">The hyperlink index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<HyperlinkResponse>> getDocumentHyperlinkByIndex(
    	std::shared_ptr<GetDocumentHyperlinkByIndexRequest> request
    );

    /// <summary>
    /// Reads document hyperlinks common info.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<HyperlinksResponse>> getDocumentHyperlinks(
    	std::shared_ptr<GetDocumentHyperlinksRequest> request
    );

    /// <summary>
    /// Reads document properties info.
    /// </summary>
    /// <param name="name">The document's name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<DocumentPropertiesResponse>> getDocumentProperties(
    	std::shared_ptr<GetDocumentPropertiesRequest> request
    );

    /// <summary>
    /// Reads document property info by the property name.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="propertyName">The property name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<DocumentPropertyResponse>> getDocumentProperty(
    	std::shared_ptr<GetDocumentPropertyRequest> request
    );

    /// <summary>
    /// Reads document protection common info.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<ProtectionDataResponse>> getDocumentProtection(
    	std::shared_ptr<GetDocumentProtectionRequest> request
    );

    /// <summary>
    /// Reads document statistics.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="includeComments">Support including/excluding comments from the WordCount. Default value is "false". (optional)</param>
    /// <param name="includeFootnotes">Support including/excluding footnotes from the WordCount. Default value is "false". (optional)</param>
    /// <param name="includeTextInShapes">Support including/excluding shape's text from the WordCount. Default value is "false". (optional)</param>
    pplx::task<AsposeResponse<StatDataResponse>> getDocumentStatistics(
    	std::shared_ptr<GetDocumentStatisticsRequest> request
    );

    /// <summary>
    /// Reads document statistics.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="includeComments">Support including/excluding comments from the WordCount. Default value is "false". (optional)</param>
    /// <param name="includeFootnotes">Support including/excluding footnotes from the WordCount. Default value is "false". (optional)</param>
    /// <param name="includeTextInShapes">Support including/excluding shape's text from the WordCount. Default value is "false". (optional)</param>
    pplx::task<HttpContent> getDocumentStatisticsOnline(
    	std::shared_ptr<GetDocumentStatisticsOnlineRequest> request
    );

    /// <summary>
    /// Exports the document into the specified format.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="format">The destination format.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="outPath">Path to save the result. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    pplx::task<HttpContent> getDocumentWithFormat(
    	std::shared_ptr<GetDocumentWithFormatRequest> request
    );

    /// <summary>
    /// Gets field from document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node, which contains collection of fields. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<FieldResponse>> getField(
    	std::shared_ptr<GetFieldRequest> request
    );

    /// <summary>
    /// Get fields from document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="nodePath">Path to the node, which contains collection of fields. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<FieldsResponse>> getFields(
    	std::shared_ptr<GetFieldsRequest> request
    );

    /// <summary>
    /// Get all files and folders within a folder.
    /// </summary>
    /// <param name="path">Folder path e.g. /Folder1.</param>
    /// <param name="storageName">Storage name. (optional)</param>
    pplx::task<AsposeResponse<FilesList>> getFilesList(
    	std::shared_ptr<GetFilesListRequest> request
    );

    /// <summary>
    /// Reads footnote by index.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node, which contains collection of footnotes. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<FootnoteResponse>> getFootnote(
    	std::shared_ptr<GetFootnoteRequest> request
    );

    /// <summary>
    /// Gets footnotes from document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="nodePath">Path to the node, which contains collection of footnotes. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<FootnotesResponse>> getFootnotes(
    	std::shared_ptr<GetFootnotesRequest> request
    );

    /// <summary>
    /// Returns representation of an one of the form field.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node that contains collection of formfields. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<FormFieldResponse>> getFormField(
    	std::shared_ptr<GetFormFieldRequest> request
    );

    /// <summary>
    /// Gets form fields from document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="nodePath">Path to the node containing collection of form fields. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<FormFieldsResponse>> getFormFields(
    	std::shared_ptr<GetFormFieldsRequest> request
    );

    /// <summary>
    /// Returns a header/footer from the document by index.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="headerFooterIndex">Header/footer index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="filterByType">List of types of headers and footers. (optional)</param>
    pplx::task<AsposeResponse<HeaderFooterResponse>> getHeaderFooter(
    	std::shared_ptr<GetHeaderFooterRequest> request
    );

    /// <summary>
    /// Returns a header/footer from the document section.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="headerFooterIndex">Header/footer index.</param>
    /// <param name="sectionIndex">Section index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="filterByType">List of types of headers and footers. (optional)</param>
    pplx::task<AsposeResponse<HeaderFooterResponse>> getHeaderFooterOfSection(
    	std::shared_ptr<GetHeaderFooterOfSectionRequest> request
    );

    /// <summary>
    /// Returns a list of header/footers from the document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="sectionPath">Path to parent section.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="filterByType">List of types of headers and footers. (optional)</param>
    pplx::task<AsposeResponse<HeaderFootersResponse>> getHeaderFooters(
    	std::shared_ptr<GetHeaderFootersRequest> request
    );

    /// <summary>
    /// This resource represents one of the lists contained in the document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="listId">List unique identifier.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<ListResponse>> getList(
    	std::shared_ptr<GetListRequest> request
    );

    /// <summary>
    /// Returns a list of lists that are contained in the document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<ListsResponse>> getLists(
    	std::shared_ptr<GetListsRequest> request
    );

    /// <summary>
    /// Reads OfficeMath object by index.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node, which contains collection of OfficeMath objects. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<OfficeMathObjectResponse>> getOfficeMathObject(
    	std::shared_ptr<GetOfficeMathObjectRequest> request
    );

    /// <summary>
    /// Gets OfficeMath objects from document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="nodePath">Path to the node, which contains collection of OfficeMath objects. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<OfficeMathObjectsResponse>> getOfficeMathObjects(
    	std::shared_ptr<GetOfficeMathObjectsRequest> request
    );

    /// <summary>
    /// This resource represents one of the paragraphs contained in the document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node which contains paragraphs. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<HttpContent> getParagraph(
    	std::shared_ptr<GetParagraphRequest> request
    );

    /// <summary>
    /// Represents all the formatting for a paragraph.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node which contains paragraphs. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<ParagraphFormatResponse>> getParagraphFormat(
    	std::shared_ptr<GetParagraphFormatRequest> request
    );

    /// <summary>
    /// Represents list format for a paragraph.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node which contains paragraphs. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<ParagraphListFormatResponse>> getParagraphListFormat(
    	std::shared_ptr<GetParagraphListFormatRequest> request
    );

    /// <summary>
    /// Returns a list of paragraphs that are contained in the document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="nodePath">Path to the node which contains paragraphs. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<HttpContent> getParagraphs(
    	std::shared_ptr<GetParagraphsRequest> request
    );

    /// <summary>
    /// Get all tab stops for the paragraph.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node which contains paragraph. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<TabStopsResponse>> getParagraphTabStops(
    	std::shared_ptr<GetParagraphTabStopsRequest> request
    );

    /// <summary>
    /// Gets the text from the range.
    /// </summary>
    /// <param name="name">The document.</param>
    /// <param name="rangeStartIdentifier">The range start identifier. Identifier is the value of the "nodeId" field, which every document node has, extended with the prefix "id". It looks like "id0.0.7". Also values like "image5" and "table3" can be used as an identifier for images and tables, where the number is an index of the image/table.</param>
    /// <param name="rangeEndIdentifier">The range end identifier. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<RangeTextResponse>> getRangeText(
    	std::shared_ptr<GetRangeTextRequest> request
    );

    /// <summary>
    /// This resource represents run of text contained in the document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="paragraphPath">Path to parent paragraph.</param>
    /// <param name="index">Object index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<RunResponse>> getRun(
    	std::shared_ptr<GetRunRequest> request
    );

    /// <summary>
    /// This resource represents font of run.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="paragraphPath">Path to parent paragraph.</param>
    /// <param name="index">Object index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<FontResponse>> getRunFont(
    	std::shared_ptr<GetRunFontRequest> request
    );

    /// <summary>
    /// This resource represents collection of runs in the paragraph.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="paragraphPath">Path to parent paragraph.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<RunsResponse>> getRuns(
    	std::shared_ptr<GetRunsRequest> request
    );

    /// <summary>
    /// Gets document section by index.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="sectionIndex">Section index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<SectionResponse>> getSection(
    	std::shared_ptr<GetSectionRequest> request
    );

    /// <summary>
    /// Gets page setup of section.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="sectionIndex">Section index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<SectionPageSetupResponse>> getSectionPageSetup(
    	std::shared_ptr<GetSectionPageSetupRequest> request
    );

    /// <summary>
    /// Returns a list of sections that are contained in the document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<SectionLinkCollectionResponse>> getSections(
    	std::shared_ptr<GetSectionsRequest> request
    );

    /// <summary>
    /// This resource represents one of the styles contained in the document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="styleName">Style name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<StyleResponse>> getStyle(
    	std::shared_ptr<GetStyleRequest> request
    );

    /// <summary>
    /// Gets a style from the document node.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="styledNodePath">The path to the node that supports a style. Supported node types: ParagraphFormat, List, ListLevel, Table.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<StyleResponse>> getStyleFromDocumentElement(
    	std::shared_ptr<GetStyleFromDocumentElementRequest> request
    );

    /// <summary>
    /// Returns a list of styles contained in the document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<StylesResponse>> getStyles(
    	std::shared_ptr<GetStylesRequest> request
    );

    /// <summary>
    /// Returns a table.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node, which contains tables. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<TableResponse>> getTable(
    	std::shared_ptr<GetTableRequest> request
    );

    /// <summary>
    /// Returns a table cell.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="tableRowPath">Path to table row.</param>
    /// <param name="index">Object index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<TableCellResponse>> getTableCell(
    	std::shared_ptr<GetTableCellRequest> request
    );

    /// <summary>
    /// Returns a table cell format.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="tableRowPath">Path to table row.</param>
    /// <param name="index">Object index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<TableCellFormatResponse>> getTableCellFormat(
    	std::shared_ptr<GetTableCellFormatRequest> request
    );

    /// <summary>
    /// Returns a table properties.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node, which contains tables. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<TablePropertiesResponse>> getTableProperties(
    	std::shared_ptr<GetTablePropertiesRequest> request
    );

    /// <summary>
    /// Returns a table row.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="tablePath">Path to table.</param>
    /// <param name="index">Object index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<TableRowResponse>> getTableRow(
    	std::shared_ptr<GetTableRowRequest> request
    );

    /// <summary>
    /// Returns a table row format.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="tablePath">Path to table.</param>
    /// <param name="index">Object index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<TableRowFormatResponse>> getTableRowFormat(
    	std::shared_ptr<GetTableRowFormatRequest> request
    );

    /// <summary>
    /// Returns a list of tables that are contained in the document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="nodePath">Path to the node, which contains tables. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<TableLinkCollectionResponse>> getTables(
    	std::shared_ptr<GetTablesRequest> request
    );

    /// <summary>
    /// Adds comment to document, returns inserted comment data.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="comment">The comment data.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<CommentResponse>> insertComment(
    	std::shared_ptr<InsertCommentRequest> request
    );

    /// <summary>
    /// Adds drawing object to document, returns added  drawing object's data.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="drawingObject">Drawing object parameters.</param>
    /// <param name="imageFile">File with image.</param>
    /// <param name="nodePath">Path to the node, which contains collection of drawing objects. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<DrawingObjectResponse>> insertDrawingObject(
    	std::shared_ptr<InsertDrawingObjectRequest> request
    );

    /// <summary>
    /// Adds field to document, returns inserted field's data.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="field">Field data.</param>
    /// <param name="nodePath">Path to the node, which contains collection of fields. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="insertBeforeNode">Field will be inserted before node with id="nodeId". (optional)</param>
    pplx::task<AsposeResponse<FieldResponse>> insertField(
    	std::shared_ptr<InsertFieldRequest> request
    );

    /// <summary>
    /// Adds footnote to document, returns added footnote's data.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="footnoteDto">Footnote data.</param>
    /// <param name="nodePath">Path to the node, which contains collection of footnotes. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<FootnoteResponse>> insertFootnote(
    	std::shared_ptr<InsertFootnoteRequest> request
    );

    /// <summary>
    /// Adds form field to paragraph, returns added form field's data.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="formField">From field data.</param>
    /// <param name="nodePath">Path to the node that contains collection of formfields. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="insertBeforeNode">Form field will be inserted before node with index. (optional)</param>
    pplx::task<AsposeResponse<FormFieldResponse>> insertFormField(
    	std::shared_ptr<InsertFormFieldRequest> request
    );

    /// <summary>
    /// Inserts to document header or footer.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="headerFooterType">Type of header/footer.</param>
    /// <param name="sectionPath">Path to parent section.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<HeaderFooterResponse>> insertHeaderFooter(
    	std::shared_ptr<InsertHeaderFooterRequest> request
    );

    /// <summary>
    /// Adds list to document, returns added list's data.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="listInsert">List to insert.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<ListResponse>> insertList(
    	std::shared_ptr<InsertListRequest> request
    );

    /// <summary>
    /// Insert or resplace tab stop if a tab stop with the position exists.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="dto">Paragraph tab stop.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node which contains paragraph. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    pplx::task<AsposeResponse<TabStopsResponse>> insertOrUpdateParagraphTabStop(
    	std::shared_ptr<InsertOrUpdateParagraphTabStopRequest> request
    );

    /// <summary>
    /// Inserts document page numbers.
    /// </summary>
    /// <param name="name">A document name.</param>
    /// <param name="pageNumber">PageNumber with the page numbers settings.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<DocumentResponse>> insertPageNumbers(
    	std::shared_ptr<InsertPageNumbersRequest> request
    );

    /// <summary>
    /// Adds paragraph to document, returns added paragraph's data.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="paragraph">Paragraph data.</param>
    /// <param name="nodePath">Path to the node which contains paragraphs. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="insertBeforeNode">Paragraph will be inserted before node with index. (optional)</param>
    pplx::task<HttpContent> insertParagraph(
    	std::shared_ptr<InsertParagraphRequest> request
    );

    /// <summary>
    /// Adds run to document, returns added paragraph's data.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="paragraphPath">Path to parent paragraph.</param>
    /// <param name="run">Run data.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="insertBeforeNode">Paragraph will be inserted before node with index. (optional)</param>
    pplx::task<AsposeResponse<RunResponse>> insertRun(
    	std::shared_ptr<InsertRunRequest> request
    );

    /// <summary>
    /// Adds a style to the document, returns an added style.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="styleInsert">Style to insert.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<StyleResponse>> insertStyle(
    	std::shared_ptr<InsertStyleRequest> request
    );

    /// <summary>
    /// Adds table to document, returns added table's data.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="table">Table parameters/.</param>
    /// <param name="nodePath">Path to the node, which contains tables. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<TableResponse>> insertTable(
    	std::shared_ptr<InsertTableRequest> request
    );

    /// <summary>
    /// Adds table cell to table, returns added cell's data.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="cell">Table cell parameters/.</param>
    /// <param name="tableRowPath">Path to table row.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<TableCellResponse>> insertTableCell(
    	std::shared_ptr<InsertTableCellRequest> request
    );

    /// <summary>
    /// Adds table row to table, returns added row's data.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="row">Table row parameters/.</param>
    /// <param name="tablePath">Path to table.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<TableRowResponse>> insertTableRow(
    	std::shared_ptr<InsertTableRowRequest> request
    );

    /// <summary>
    /// Inserts document watermark image.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="imageFile">File with image. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="rotationAngle">The watermark rotation angle. (optional)</param>
    /// <param name="image">The image file server full name. If the name is empty the image is expected in request content. (optional)</param>
    pplx::task<AsposeResponse<DocumentResponse>> insertWatermarkImage(
    	std::shared_ptr<InsertWatermarkImageRequest> request
    );

    /// <summary>
    /// Inserts document watermark text.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="watermarkText">WatermarkText with the watermark data.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<DocumentResponse>> insertWatermarkText(
    	std::shared_ptr<InsertWatermarkTextRequest> request
    );

    /// <summary>
    /// Loads new document from web into the file with any supported format of data.
    /// </summary>
    /// <param name="data">Parameters of loading.</param>
    /// <param name="storage">Original document storage. (optional)</param>
    pplx::task<AsposeResponse<SaveResponse>> loadWebDocument(
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
    pplx::task<std::shared_ptr<web::http::http_response>> moveFile(
    	std::shared_ptr<MoveFileRequest> request
    );

    /// <summary>
    /// Move folder.
    /// </summary>
    /// <param name="destPath">Destination folder path to move to e.g '/dst'.</param>
    /// <param name="srcPath">Source folder path e.g. /Folder1.</param>
    /// <param name="srcStorageName">Source storage name. (optional)</param>
    /// <param name="destStorageName">Destination storage name. (optional)</param>
    pplx::task<std::shared_ptr<web::http::http_response>> moveFolder(
    	std::shared_ptr<MoveFolderRequest> request
    );

    /// <summary>
    /// Allows to optimize the document contents as well as default Aspose.Words behavior to a particular versions of MS Word.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="options">The document optimization options.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<web::http::http_response>> optimizeDocument(
    	std::shared_ptr<OptimizeDocumentRequest> request
    );

    /// <summary>
    /// Protects document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="protectionRequest">ProtectionRequest with protection settings.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    pplx::task<AsposeResponse<ProtectionDataResponse>> protectDocument(
    	std::shared_ptr<ProtectDocumentRequest> request
    );

    /// <summary>
    /// Rejects all revisions in document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    pplx::task<AsposeResponse<RevisionsModificationResponse>> rejectAllRevisions(
    	std::shared_ptr<RejectAllRevisionsRequest> request
    );

    /// <summary>
    /// Removes the range from the document.
    /// </summary>
    /// <param name="name">The document.</param>
    /// <param name="rangeStartIdentifier">The range start identifier. Identifier is the value of the "nodeId" field, which every document node has, extended with the prefix "id". It looks like "id0.0.7". Also values like "image5" and "table3" can be used as an identifier for images and tables, where the number is an index of the image/table.</param>
    /// <param name="rangeEndIdentifier">The range end identifier. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    pplx::task<AsposeResponse<DocumentResponse>> removeRange(
    	std::shared_ptr<RemoveRangeRequest> request
    );

    /// <summary>
    /// Renders drawing object to specified format.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="format">The destination format.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node, which contains drawing objects. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    pplx::task<HttpContent> renderDrawingObject(
    	std::shared_ptr<RenderDrawingObjectRequest> request
    );

    /// <summary>
    /// Renders math object to specified format.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="format">The destination format.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node, which contains office math objects. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    pplx::task<HttpContent> renderMathObject(
    	std::shared_ptr<RenderMathObjectRequest> request
    );

    /// <summary>
    /// Renders page to specified format.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="pageIndex">Comment index.</param>
    /// <param name="format">The destination format.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    pplx::task<HttpContent> renderPage(
    	std::shared_ptr<RenderPageRequest> request
    );

    /// <summary>
    /// Renders paragraph to specified format.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="format">The destination format.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node, which contains paragraphs. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    pplx::task<HttpContent> renderParagraph(
    	std::shared_ptr<RenderParagraphRequest> request
    );

    /// <summary>
    /// Renders table to specified format.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="format">The destination format.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node, which contains tables. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    pplx::task<HttpContent> renderTable(
    	std::shared_ptr<RenderTableRequest> request
    );

    /// <summary>
    /// Replaces document text.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="replaceText">ReplaceTextResponse with the replace operation settings.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<ReplaceTextResponse>> replaceText(
    	std::shared_ptr<ReplaceTextRequest> request
    );

    /// <summary>
    /// Replaces the content in the range.
    /// </summary>
    /// <param name="name">The document.</param>
    /// <param name="rangeStartIdentifier">The range start identifier. Identifier is the value of the "nodeId" field, which every document node has, extended with the prefix "id". It looks like "id0.0.7". Also values like "image5" and "table3" can be used as an identifier for images and tables, where the number is an index of the image/table.</param>
    /// <param name="rangeText">Model with text for replacement.</param>
    /// <param name="rangeEndIdentifier">The range end identifier. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    pplx::task<AsposeResponse<DocumentResponse>> replaceWithText(
    	std::shared_ptr<ReplaceWithTextRequest> request
    );

    /// <summary>
    /// Resets font's cache.
    /// </summary>
    pplx::task<std::shared_ptr<web::http::http_response>> resetCache(
    	std::shared_ptr<ResetCacheRequest> request
    );

    /// <summary>
    /// Converts document to destination format with detailed settings and saves result to storage.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="saveOptionsData">Save options.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    pplx::task<AsposeResponse<SaveResponse>> saveAs(
    	std::shared_ptr<SaveAsRequest> request
    );

    /// <summary>
    /// Converts document to destination format with detailed settings and saves result to storage.
    /// </summary>
    /// <param name="document">The document.</param>
    /// <param name="saveOptionsData">Save options.</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    pplx::task<HttpContent> saveAsOnline(
    	std::shared_ptr<SaveAsOnlineRequest> request
    );

    /// <summary>
    /// Saves the selected range as a new document.
    /// </summary>
    /// <param name="name">The document.</param>
    /// <param name="rangeStartIdentifier">The range start identifier. Identifier is the value of the "nodeId" field, which every document node has, extended with the prefix "id". It looks like "id0.0.7". Also values like "image5" and "table3" can be used as an identifier for images and tables, where the number is an index of the image/table.</param>
    /// <param name="documentParameters">Parameters of a new document.</param>
    /// <param name="rangeEndIdentifier">The range end identifier. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<DocumentResponse>> saveAsRange(
    	std::shared_ptr<SaveAsRangeRequest> request
    );

    /// <summary>
    /// Converts document to tiff with detailed settings and saves result to storage.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="saveOptions">Tiff save options.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="useAntiAliasing">Use antialiasing flag. (optional)</param>
    /// <param name="useHighQualityRendering">Use high quality flag. (optional)</param>
    /// <param name="imageBrightness">Brightness for the generated images. (optional)</param>
    /// <param name="imageColorMode">Color mode for the generated images. (optional)</param>
    /// <param name="imageContrast">The contrast for the generated images. (optional)</param>
    /// <param name="numeralFormat">The images numeral format. (optional)</param>
    /// <param name="pageCount">Number of pages to render. (optional)</param>
    /// <param name="pageIndex">Page index to start rendering. (optional)</param>
    /// <param name="paperColor">Background image color. (optional)</param>
    /// <param name="pixelFormat">The pixel format of generated images. (optional)</param>
    /// <param name="resolution">The resolution of generated images. (optional)</param>
    /// <param name="scale">Zoom factor for generated images. (optional)</param>
    /// <param name="tiffCompression">The compression tipe. (optional)</param>
    /// <param name="dmlRenderingMode">Optional, default is Fallback. (optional)</param>
    /// <param name="dmlEffectsRenderingMode">Optional, default is Simplified. (optional)</param>
    /// <param name="tiffBinarizationMethod">Optional, Tiff binarization method, possible values are: FloydSteinbergDithering, Threshold. (optional)</param>
    /// <param name="zipOutput">Optional. A value determining zip output or not. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    pplx::task<AsposeResponse<SaveResponse>> saveAsTiff(
    	std::shared_ptr<SaveAsTiffRequest> request
    );

    /// <summary>
    /// Searches text in document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="pattern">The regular expression used to find matches.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<SearchResponse>> search(
    	std::shared_ptr<SearchRequest> request
    );

    /// <summary>
    /// Splits document.
    /// </summary>
    /// <param name="name">Original document name.</param>
    /// <param name="format">Format to split.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="from">Start page. (optional)</param>
    /// <param name="to">End page. (optional)</param>
    /// <param name="zipOutput">ZipOutput or not. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    pplx::task<AsposeResponse<SplitDocumentResponse>> splitDocument(
    	std::shared_ptr<SplitDocumentRequest> request
    );

    /// <summary>
    /// Unprotects document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="protectionRequest">ProtectionRequest with protection settings.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    pplx::task<AsposeResponse<ProtectionDataResponse>> unprotectDocument(
    	std::shared_ptr<UnprotectDocumentRequest> request
    );

    /// <summary>
    /// Updates document bookmark.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="bookmarkData">BookmarkData with new bookmark data.</param>
    /// <param name="bookmarkName">The bookmark name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<BookmarkResponse>> updateBookmark(
    	std::shared_ptr<UpdateBookmarkRequest> request
    );

    /// <summary>
    /// 'nodePath' should refer to paragraph, cell or row.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="borderProperties">Border properties.</param>
    /// <param name="borderType">Border type.</param>
    /// <param name="nodePath">Path to the node with border(node should be paragraph, cell or row). (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<BorderResponse>> updateBorder(
    	std::shared_ptr<UpdateBorderRequest> request
    );

    /// <summary>
    /// Updates the comment, returns updated comment data.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="commentIndex">The comment index.</param>
    /// <param name="comment">The comment data.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<CommentResponse>> updateComment(
    	std::shared_ptr<UpdateCommentRequest> request
    );

    /// <summary>
    /// Updates drawing object, returns updated  drawing object's data.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="drawingObject">Drawing object parameters.</param>
    /// <param name="imageFile">File with image.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node, which contains collection of drawing objects. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<DrawingObjectResponse>> updateDrawingObject(
    	std::shared_ptr<UpdateDrawingObjectRequest> request
    );

    /// <summary>
    /// Updates field's properties, returns updated field's data.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="field">Field data.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node, which contains collection of fields. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<FieldResponse>> updateField(
    	std::shared_ptr<UpdateFieldRequest> request
    );

    /// <summary>
    /// Updates (reevaluate) fields in document.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    pplx::task<AsposeResponse<DocumentResponse>> updateFields(
    	std::shared_ptr<UpdateFieldsRequest> request
    );

    /// <summary>
    /// Updates footnote's properties, returns updated run's data.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="footnoteDto">Footnote data.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node, which contains collection of footnotes. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<FootnoteResponse>> updateFootnote(
    	std::shared_ptr<UpdateFootnoteRequest> request
    );

    /// <summary>
    /// Updates properties of form field, returns updated form field.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="formField">From field data.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node that contains collection of formfields. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<FormFieldResponse>> updateFormField(
    	std::shared_ptr<UpdateFormFieldRequest> request
    );

    /// <summary>
    /// Updates list properties, returns updated list.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="listUpdate">List object.</param>
    /// <param name="listId">List unique identifier.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<ListResponse>> updateList(
    	std::shared_ptr<UpdateListRequest> request
    );

    /// <summary>
    /// Updates list level in document list, returns updated list.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="listUpdate">List object.</param>
    /// <param name="listId">List unique identifier.</param>
    /// <param name="listLevel">List level identifier.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<ListResponse>> updateListLevel(
    	std::shared_ptr<UpdateListLevelRequest> request
    );

    /// <summary>
    /// Updates paragraph format properties, returns updated format properties.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="dto">Paragraph format object.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node which contains paragraphs. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<ParagraphFormatResponse>> updateParagraphFormat(
    	std::shared_ptr<UpdateParagraphFormatRequest> request
    );

    /// <summary>
    /// Updates paragraph list format properties, returns updated list format properties.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="dto">Paragraph format object.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node which contains paragraphs. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<ParagraphListFormatResponse>> updateParagraphListFormat(
    	std::shared_ptr<UpdateParagraphListFormatRequest> request
    );

    /// <summary>
    /// Updates run's properties, returns updated run's data.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="run">Run data.</param>
    /// <param name="paragraphPath">Path to parent paragraph.</param>
    /// <param name="index">Object index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<RunResponse>> updateRun(
    	std::shared_ptr<UpdateRunRequest> request
    );

    /// <summary>
    /// Updates font properties, returns updated font data.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="fontDto">Font dto object.</param>
    /// <param name="paragraphPath">Path to parent paragraph.</param>
    /// <param name="index">Object index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<FontResponse>> updateRunFont(
    	std::shared_ptr<UpdateRunFontRequest> request
    );

    /// <summary>
    /// Updates page setup of section.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="sectionIndex">Section index.</param>
    /// <param name="pageSetup">Page setup properties dto.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<SectionPageSetupResponse>> updateSectionPageSetup(
    	std::shared_ptr<UpdateSectionPageSetupRequest> request
    );

    /// <summary>
    /// Updates style properties, returns an updated style.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="styleUpdate">Style properties to update.</param>
    /// <param name="styleName">Style name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<StyleResponse>> updateStyle(
    	std::shared_ptr<UpdateStyleRequest> request
    );

    /// <summary>
    /// Updates a table cell format.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="format">The properties.</param>
    /// <param name="tableRowPath">Path to table row.</param>
    /// <param name="index">Object index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<TableCellFormatResponse>> updateTableCellFormat(
    	std::shared_ptr<UpdateTableCellFormatRequest> request
    );

    /// <summary>
    /// Updates a table properties.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="properties">The properties.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">Path to the node, which contains tables. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<TablePropertiesResponse>> updateTableProperties(
    	std::shared_ptr<UpdateTablePropertiesRequest> request
    );

    /// <summary>
    /// Updates a table row format.
    /// </summary>
    /// <param name="name">The document name.</param>
    /// <param name="format">Table row format.</param>
    /// <param name="tablePath">Path to table.</param>
    /// <param name="index">Object index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<AsposeResponse<TableRowFormatResponse>> updateTableRowFormat(
    	std::shared_ptr<UpdateTableRowFormatRequest> request
    );

    /// <summary>
    /// Upload file.
    /// </summary>
    /// <param name="fileContent">File to upload.</param>
    /// <param name="path">Path where to upload including filename and extension e.g. /file.ext or /Folder 1/file.ext If the content is multipart and path does not contains the file name it tries to get them from filename parameter from Content-Disposition header.</param>
    /// <param name="storageName">Storage name. (optional)</param>
    pplx::task<AsposeResponse<FilesUploadResult>> uploadFile(
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
