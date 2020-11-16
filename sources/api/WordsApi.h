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
    /// Accepts all revisions in the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    pplx::task<AsposeResponse<RevisionsModificationResponse>> acceptAllRevisions(
    	std::shared_ptr<AcceptAllRevisionsRequest> request
    );

    /// <summary>
    /// Appends documents to the original document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="documentList">The collection of documents to append.</param>
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
    /// Applies a style to the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="styleApply">The style to apply.</param>
    /// <param name="styledNodePath">The path to the node in the document tree, that supports styles: ParagraphFormat, List, ListLevel, Table.</param>
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
    pplx::task<AsposeResponse<DocumentResponse>> buildReport(
    	std::shared_ptr<BuildReportRequest> request
    );

    /// <summary>
    /// Executes the report generation process online using the specified document template and the external data source in XML, JSON or CSV format.
    /// </summary>
    /// <param name="template">File with template.</param>
    /// <param name="data">A string providing a data to populate the specified template. The string must be of one of the following types: xml, json, csv.</param>
    /// <param name="reportEngineSettings">An object providing a settings of report engine.</param>
    /// <param name="documentFileName">The filename of the output document, that will be used when the resulting document has a dynamic field {filename}. If it is not set, the "template" will be used instead. (optional)</param>
    pplx::task<HttpContent> buildReportOnline(
    	std::shared_ptr<BuildReportOnlineRequest> request
    );

    /// <summary>
    /// Runs a multi-class text classification for the specified raw text.
    /// </summary>
    /// <param name="text">The text to classify.</param>
    /// <param name="bestClassesCount">The number of the best classes to return. (optional)</param>
    pplx::task<AsposeResponse<ClassificationResponse>> classify(
    	std::shared_ptr<ClassifyRequest> request
    );

    /// <summary>
    /// Runs a multi-class text classification for the document.
    /// </summary>
    /// <param name="documentName">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="bestClassesCount">The number of the best classes to return. (optional)</param>
    /// <param name="taxonomy">The taxonomy to use. (optional)</param>
    pplx::task<AsposeResponse<ClassificationResponse>> classifyDocument(
    	std::shared_ptr<ClassifyDocumentRequest> request
    );

    /// <summary>
    /// Compares two documents.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="compareData">The properties of the document to compare with.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    pplx::task<AsposeResponse<DocumentResponse>> compareDocument(
    	std::shared_ptr<CompareDocumentRequest> request
    );

    /// <summary>
    /// Converts a document on a local drive to the specified format.
    /// </summary>
    /// <param name="document">Converting document.</param>
    /// <param name="format">The format to convert.</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="outPath">The path to the output document on a local storage. (optional)</param>
    /// <param name="fileNameFieldValue">The filename of the output document, that will be used when the resulting document has a dynamic field {filename}. If it is not set, the "sourceFilename" will be used instead. (optional)</param>
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
    /// Makes a copy of the style in the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="styleCopy">The properties of the style.</param>
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
    /// Supported extensions: ".doc", ".docx", ".docm", ".dot", ".dotm", ".dotx", ".flatopc", ".fopc", ".flatopc_macro", ".fopc_macro", ".flatopc_template", ".fopc_template", ".flatopc_template_macro", ".fopc_template_macro", ".wordml", ".wml", ".rtf".
    /// </summary>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="fileName">The filename of the document. (optional)</param>
    /// <param name="folder">The path to the document folder. (optional)</param>
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
    /// Adds a new or updates an existing document property.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="propertyName">The name of the property.</param>
    /// <param name="property">The property with a new value.</param>
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
    pplx::task<AsposeResponse<TabStopsResponse>> deleteAllParagraphTabStops(
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
    pplx::task<AsposeResponse<BorderResponse>> deleteBorder(
    	std::shared_ptr<DeleteBorderRequest> request
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
    pplx::task<AsposeResponse<BordersResponse>> deleteBorders(
    	std::shared_ptr<DeleteBordersRequest> request
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
    pplx::task<std::shared_ptr<web::http::http_response>> deleteComment(
    	std::shared_ptr<DeleteCommentRequest> request
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
    pplx::task<std::shared_ptr<web::http::http_response>> deleteDocumentProperty(
    	std::shared_ptr<DeleteDocumentPropertyRequest> request
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
    pplx::task<std::shared_ptr<web::http::http_response>> deleteDrawingObject(
    	std::shared_ptr<DeleteDrawingObjectRequest> request
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
    pplx::task<std::shared_ptr<web::http::http_response>> deleteField(
    	std::shared_ptr<DeleteFieldRequest> request
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
    pplx::task<std::shared_ptr<web::http::http_response>> deleteFootnote(
    	std::shared_ptr<DeleteFootnoteRequest> request
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
    pplx::task<std::shared_ptr<web::http::http_response>> deleteFormField(
    	std::shared_ptr<DeleteFormFieldRequest> request
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
    pplx::task<std::shared_ptr<web::http::http_response>> deleteHeaderFooter(
    	std::shared_ptr<DeleteHeaderFooterRequest> request
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
    pplx::task<std::shared_ptr<web::http::http_response>> deleteHeadersFooters(
    	std::shared_ptr<DeleteHeadersFootersRequest> request
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
    pplx::task<std::shared_ptr<web::http::http_response>> deleteMacros(
    	std::shared_ptr<DeleteMacrosRequest> request
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
    pplx::task<std::shared_ptr<web::http::http_response>> deleteOfficeMathObject(
    	std::shared_ptr<DeleteOfficeMathObjectRequest> request
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
    pplx::task<std::shared_ptr<web::http::http_response>> deleteParagraph(
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
    pplx::task<AsposeResponse<ParagraphListFormatResponse>> deleteParagraphListFormat(
    	std::shared_ptr<DeleteParagraphListFormatRequest> request
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
    pplx::task<AsposeResponse<TabStopsResponse>> deleteParagraphTabStop(
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
    pplx::task<std::shared_ptr<web::http::http_response>> deleteRun(
    	std::shared_ptr<DeleteRunRequest> request
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
    pplx::task<std::shared_ptr<web::http::http_response>> deleteSection(
    	std::shared_ptr<DeleteSectionRequest> request
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
    pplx::task<std::shared_ptr<web::http::http_response>> deleteTable(
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
    pplx::task<std::shared_ptr<web::http::http_response>> deleteTableCell(
    	std::shared_ptr<DeleteTableCellRequest> request
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
    pplx::task<std::shared_ptr<web::http::http_response>> deleteTableRow(
    	std::shared_ptr<DeleteTableRowRequest> request
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
    pplx::task<AsposeResponse<DocumentResponse>> executeMailMerge(
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
    pplx::task<HttpContent> executeMailMergeOnline(
    	std::shared_ptr<ExecuteMailMergeOnlineRequest> request
    );

    /// <summary>
    /// Reads available fonts from the document.
    /// </summary>
    /// <param name="fontsLocation">The folder in cloud storage with custom fonts. (optional)</param>
    pplx::task<AsposeResponse<AvailableFontsResponse>> getAvailableFonts(
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
    pplx::task<AsposeResponse<BookmarkResponse>> getBookmarkByName(
    	std::shared_ptr<GetBookmarkByNameRequest> request
    );

    /// <summary>
    /// Reads bookmarks from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<BookmarksResponse>> getBookmarks(
    	std::shared_ptr<GetBookmarksRequest> request
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
    pplx::task<AsposeResponse<BorderResponse>> getBorder(
    	std::shared_ptr<GetBorderRequest> request
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
    pplx::task<AsposeResponse<BordersResponse>> getBorders(
    	std::shared_ptr<GetBordersRequest> request
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
    pplx::task<AsposeResponse<CommentResponse>> getComment(
    	std::shared_ptr<GetCommentRequest> request
    );

    /// <summary>
    /// Reads comments from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<CommentsResponse>> getComments(
    	std::shared_ptr<GetCommentsRequest> request
    );

    /// <summary>
    /// Reads common information from the document.
    /// </summary>
    /// <param name="documentName">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<DocumentResponse>> getDocument(
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
    pplx::task<AsposeResponse<DrawingObjectResponse>> getDocumentDrawingObjectByIndex(
    	std::shared_ptr<GetDocumentDrawingObjectByIndexRequest> request
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
    pplx::task<HttpContent> getDocumentDrawingObjectImageData(
    	std::shared_ptr<GetDocumentDrawingObjectImageDataRequest> request
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
    pplx::task<HttpContent> getDocumentDrawingObjectOleData(
    	std::shared_ptr<GetDocumentDrawingObjectOleDataRequest> request
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
    pplx::task<AsposeResponse<DrawingObjectsResponse>> getDocumentDrawingObjects(
    	std::shared_ptr<GetDocumentDrawingObjectsRequest> request
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
    pplx::task<AsposeResponse<FieldNamesResponse>> getDocumentFieldNames(
    	std::shared_ptr<GetDocumentFieldNamesRequest> request
    );

    /// <summary>
    /// Reads merge field names from the document.
    /// </summary>
    /// <param name="template">File with template.</param>
    /// <param name="useNonMergeFields">The flag indicating whether to use non merge fields. If true, result includes "mustache" field names. (optional)</param>
    pplx::task<AsposeResponse<FieldNamesResponse>> getDocumentFieldNamesOnline(
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
    pplx::task<AsposeResponse<HyperlinkResponse>> getDocumentHyperlinkByIndex(
    	std::shared_ptr<GetDocumentHyperlinkByIndexRequest> request
    );

    /// <summary>
    /// Reads hyperlinks from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<HyperlinksResponse>> getDocumentHyperlinks(
    	std::shared_ptr<GetDocumentHyperlinksRequest> request
    );

    /// <summary>
    /// Reads document properties.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<DocumentPropertiesResponse>> getDocumentProperties(
    	std::shared_ptr<GetDocumentPropertiesRequest> request
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
    pplx::task<AsposeResponse<DocumentPropertyResponse>> getDocumentProperty(
    	std::shared_ptr<GetDocumentPropertyRequest> request
    );

    /// <summary>
    /// Reads protection properties from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
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
    /// <param name="name">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="includeComments">The flag indicating whether to include comments from the WordCount. The default value is "false". (optional)</param>
    /// <param name="includeFootnotes">The flag indicating whether to include footnotes from the WordCount. The default value is "false". (optional)</param>
    /// <param name="includeTextInShapes">The flag indicating whether to include shape's text from the WordCount. The default value is "false". (optional)</param>
    pplx::task<AsposeResponse<StatDataResponse>> getDocumentStatistics(
    	std::shared_ptr<GetDocumentStatisticsRequest> request
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
    pplx::task<HttpContent> getDocumentWithFormat(
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
    pplx::task<AsposeResponse<FieldResponse>> getField(
    	std::shared_ptr<GetFieldRequest> request
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
    /// Reads a footnote from the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<FootnoteResponse>> getFootnote(
    	std::shared_ptr<GetFootnoteRequest> request
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
    pplx::task<AsposeResponse<FootnotesResponse>> getFootnotes(
    	std::shared_ptr<GetFootnotesRequest> request
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
    pplx::task<AsposeResponse<FormFieldResponse>> getFormField(
    	std::shared_ptr<GetFormFieldRequest> request
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
    pplx::task<AsposeResponse<FormFieldsResponse>> getFormFields(
    	std::shared_ptr<GetFormFieldsRequest> request
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
    pplx::task<AsposeResponse<HeaderFooterResponse>> getHeaderFooter(
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
    pplx::task<AsposeResponse<HeaderFooterResponse>> getHeaderFooterOfSection(
    	std::shared_ptr<GetHeaderFooterOfSectionRequest> request
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
    pplx::task<AsposeResponse<HeaderFootersResponse>> getHeaderFooters(
    	std::shared_ptr<GetHeaderFootersRequest> request
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
    pplx::task<AsposeResponse<ListResponse>> getList(
    	std::shared_ptr<GetListRequest> request
    );

    /// <summary>
    /// Reads lists from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<ListsResponse>> getLists(
    	std::shared_ptr<GetListsRequest> request
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
    pplx::task<AsposeResponse<OfficeMathObjectResponse>> getOfficeMathObject(
    	std::shared_ptr<GetOfficeMathObjectRequest> request
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
    pplx::task<AsposeResponse<OfficeMathObjectsResponse>> getOfficeMathObjects(
    	std::shared_ptr<GetOfficeMathObjectsRequest> request
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
    pplx::task<AsposeResponse<ParagraphResponse>> getParagraph(
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
    pplx::task<AsposeResponse<ParagraphFormatResponse>> getParagraphFormat(
    	std::shared_ptr<GetParagraphFormatRequest> request
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
    pplx::task<AsposeResponse<ParagraphListFormatResponse>> getParagraphListFormat(
    	std::shared_ptr<GetParagraphListFormatRequest> request
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
    pplx::task<AsposeResponse<ParagraphLinkCollectionResponse>> getParagraphs(
    	std::shared_ptr<GetParagraphsRequest> request
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
    pplx::task<AsposeResponse<TabStopsResponse>> getParagraphTabStops(
    	std::shared_ptr<GetParagraphTabStopsRequest> request
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
    pplx::task<AsposeResponse<RangeTextResponse>> getRangeText(
    	std::shared_ptr<GetRangeTextRequest> request
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
    pplx::task<AsposeResponse<RunResponse>> getRun(
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
    pplx::task<AsposeResponse<FontResponse>> getRunFont(
    	std::shared_ptr<GetRunFontRequest> request
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
    pplx::task<AsposeResponse<RunsResponse>> getRuns(
    	std::shared_ptr<GetRunsRequest> request
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
    pplx::task<AsposeResponse<SectionResponse>> getSection(
    	std::shared_ptr<GetSectionRequest> request
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
    pplx::task<AsposeResponse<SectionPageSetupResponse>> getSectionPageSetup(
    	std::shared_ptr<GetSectionPageSetupRequest> request
    );

    /// <summary>
    /// Reads sections from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<SectionLinkCollectionResponse>> getSections(
    	std::shared_ptr<GetSectionsRequest> request
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
    pplx::task<AsposeResponse<StyleResponse>> getStyle(
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
    pplx::task<AsposeResponse<StyleResponse>> getStyleFromDocumentElement(
    	std::shared_ptr<GetStyleFromDocumentElementRequest> request
    );

    /// <summary>
    /// Reads styles from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<StylesResponse>> getStyles(
    	std::shared_ptr<GetStylesRequest> request
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
    pplx::task<AsposeResponse<TableResponse>> getTable(
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
    pplx::task<AsposeResponse<TableCellResponse>> getTableCell(
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
    pplx::task<AsposeResponse<TableCellFormatResponse>> getTableCellFormat(
    	std::shared_ptr<GetTableCellFormatRequest> request
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
    pplx::task<AsposeResponse<TablePropertiesResponse>> getTableProperties(
    	std::shared_ptr<GetTablePropertiesRequest> request
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
    pplx::task<AsposeResponse<TableRowResponse>> getTableRow(
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
    pplx::task<AsposeResponse<TableRowFormatResponse>> getTableRowFormat(
    	std::shared_ptr<GetTableRowFormatRequest> request
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
    pplx::task<AsposeResponse<TableLinkCollectionResponse>> getTables(
    	std::shared_ptr<GetTablesRequest> request
    );

    /// <summary>
    /// Inserts a new comment to the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="comment">The properties of the comment.</param>
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
    pplx::task<AsposeResponse<DrawingObjectResponse>> insertDrawingObject(
    	std::shared_ptr<InsertDrawingObjectRequest> request
    );

    /// <summary>
    /// Inserts a new field to the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="field">The properties of the field.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="insertBeforeNode">The index of the node. A new field will be inserted before the node with the specified node Id. (optional)</param>
    pplx::task<AsposeResponse<FieldResponse>> insertField(
    	std::shared_ptr<InsertFieldRequest> request
    );

    /// <summary>
    /// Inserts a new footnote to the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="footnoteDto">The properties of the footnote.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
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
    /// Inserts a new form field to the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="formField">The properties of the form field.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="insertBeforeNode">The index of the node. A new form field will be inserted before the node with the specified node Id. (optional)</param>
    pplx::task<AsposeResponse<FormFieldResponse>> insertFormField(
    	std::shared_ptr<InsertFormFieldRequest> request
    );

    /// <summary>
    /// Inserts a new HeaderFooter object to the document section.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="headerFooterType">The type of a HeaderFooter object.</param>
    /// <param name="sectionPath">The path to the section in the document tree.</param>
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
    /// Inserts a new list to the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="listInsert">The properties of the list.</param>
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
    /// Inserts a new or updates an existing paragraph tab stop in the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="dto">The properties of the paragraph tab stop.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    pplx::task<AsposeResponse<TabStopsResponse>> insertOrUpdateParagraphTabStop(
    	std::shared_ptr<InsertOrUpdateParagraphTabStopRequest> request
    );

    /// <summary>
    /// Inserts page numbers to the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="pageNumber">The page numbers settings.</param>
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
    /// Inserts a new paragraph to the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="paragraph">The properties of the paragraph.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="insertBeforeNode">The index of the node. A new paragraph will be inserted before the node with the specified index. (optional)</param>
    pplx::task<AsposeResponse<ParagraphResponse>> insertParagraph(
    	std::shared_ptr<InsertParagraphRequest> request
    );

    /// <summary>
    /// Inserts a new Run object to the paragraph.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="paragraphPath">The path to the paragraph in the document tree.</param>
    /// <param name="run">The properties of the Run object.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="insertBeforeNode">The index of the node. A new Run object will be inserted before the node with the specified node Id. (optional)</param>
    pplx::task<AsposeResponse<RunResponse>> insertRun(
    	std::shared_ptr<InsertRunRequest> request
    );

    /// <summary>
    /// Inserts a new style to the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="styleInsert">The properties of the style.</param>
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
    /// Inserts a new table to the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="table">The properties of the table.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
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
    /// Inserts a new cell to the table row.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="cell">The properties of the cell.</param>
    /// <param name="tableRowPath">The path to the table row in the document tree.</param>
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
    /// Inserts a new row to the table.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="row">The properties of the row.</param>
    /// <param name="tablePath">The path to the table in the document tree.</param>
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
    pplx::task<AsposeResponse<DocumentResponse>> insertWatermarkImage(
    	std::shared_ptr<InsertWatermarkImageRequest> request
    );

    /// <summary>
    /// Inserts a new watermark text to the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="watermarkText">The watermark text to insert.</param>
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
    /// Downloads a document from the Web using URL and saves it to cloud storage in the specified format.
    /// </summary>
    /// <param name="data">The properties of data downloading.</param>
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
    pplx::task<std::shared_ptr<web::http::http_response>> optimizeDocument(
    	std::shared_ptr<OptimizeDocumentRequest> request
    );

    /// <summary>
    /// Adds protection to the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="protectionRequest">The protection settings.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    pplx::task<AsposeResponse<ProtectionDataResponse>> protectDocument(
    	std::shared_ptr<ProtectDocumentRequest> request
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
    pplx::task<AsposeResponse<RevisionsModificationResponse>> rejectAllRevisions(
    	std::shared_ptr<RejectAllRevisionsRequest> request
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
    pplx::task<AsposeResponse<DocumentResponse>> removeRange(
    	std::shared_ptr<RemoveRangeRequest> request
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
    pplx::task<HttpContent> renderDrawingObject(
    	std::shared_ptr<RenderDrawingObjectRequest> request
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
    pplx::task<HttpContent> renderMathObject(
    	std::shared_ptr<RenderMathObjectRequest> request
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
    pplx::task<HttpContent> renderPage(
    	std::shared_ptr<RenderPageRequest> request
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
    pplx::task<HttpContent> renderParagraph(
    	std::shared_ptr<RenderParagraphRequest> request
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
    pplx::task<HttpContent> renderTable(
    	std::shared_ptr<RenderTableRequest> request
    );

    /// <summary>
    /// Replaces text in the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="replaceText">The text replacement parameters.</param>
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
    /// Replaces a range with text in the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="rangeStartIdentifier">The range start identifier.</param>
    /// <param name="rangeText">The text replacement properties.</param>
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
    /// Clears the font cache.
    /// </summary>
    pplx::task<std::shared_ptr<web::http::http_response>> resetCache(
    	std::shared_ptr<ResetCacheRequest> request
    );

    /// <summary>
    /// Converts a document in cloud storage to the specified format.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="saveOptionsData">The save options.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    pplx::task<AsposeResponse<SaveResponse>> saveAs(
    	std::shared_ptr<SaveAsRequest> request
    );

    /// <summary>
    /// Saves a range as a new document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="rangeStartIdentifier">The range start identifier.</param>
    /// <param name="documentParameters">The parameters of a new document.</param>
    /// <param name="rangeEndIdentifier">The range end identifier. (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<AsposeResponse<DocumentResponse>> saveAsRange(
    	std::shared_ptr<SaveAsRangeRequest> request
    );

    /// <summary>
    /// Converts a document in cloud storage to TIFF format using detailed conversion settings.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="saveOptions">The save options to TIFF format.</param>
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
    pplx::task<AsposeResponse<SaveResponse>> saveAsTiff(
    	std::shared_ptr<SaveAsTiffRequest> request
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
    pplx::task<AsposeResponse<SearchResponse>> search(
    	std::shared_ptr<SearchRequest> request
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
    pplx::task<AsposeResponse<SplitDocumentResponse>> splitDocument(
    	std::shared_ptr<SplitDocumentRequest> request
    );

    /// <summary>
    /// Removes protection from the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="protectionRequest">The protection settings.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    pplx::task<AsposeResponse<ProtectionDataResponse>> unprotectDocument(
    	std::shared_ptr<UnprotectDocumentRequest> request
    );

    /// <summary>
    /// Updates a bookmark in the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="bookmarkData">The properties of the bookmark.</param>
    /// <param name="bookmarkName">The name of the bookmark.</param>
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
    /// The 'nodePath' parameter should refer to a paragraph, a cell or a row.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="borderProperties">The new border properties to update.</param>
    /// <param name="borderType">Border type.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
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
    /// Updates a comment in the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="commentIndex">The index of the comment.</param>
    /// <param name="comment">The properties of the comment.</param>
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
    pplx::task<AsposeResponse<DrawingObjectResponse>> updateDrawingObject(
    	std::shared_ptr<UpdateDrawingObjectRequest> request
    );

    /// <summary>
    /// Updates a field in the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="field">The properties of the field.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
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
    /// Reevaluates field values in the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">Original document storage. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    pplx::task<AsposeResponse<DocumentResponse>> updateFields(
    	std::shared_ptr<UpdateFieldsRequest> request
    );

    /// <summary>
    /// Updates a footnote in the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="footnoteDto">The properties of the footnote.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
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
    /// Updates a form field in the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="formField">The new form field properties.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
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
    /// Updates a list in the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="listUpdate">The properties of the list.</param>
    /// <param name="listId">The list Id.</param>
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
    /// Updates the level of a List element in the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="listUpdate">The properties of the List element.</param>
    /// <param name="listId">The list Id.</param>
    /// <param name="listLevel">The list level.</param>
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
    /// Updates the formatting properties of a paragraph in the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="dto">The formatting properties of a paragraph.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
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
    /// Updates the formatting properties of a paragraph list in the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="dto">The formatting properties of a paragraph list.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
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
    /// Updates a Run object in the paragraph.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="run">The properties of the Run object.</param>
    /// <param name="paragraphPath">The path to the paragraph in the document tree.</param>
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
    /// Updates the font properties of a Run object in the paragraph.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="fontDto">The font properties of a Run object.</param>
    /// <param name="paragraphPath">The path to the paragraph in the document tree.</param>
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
    /// Updates the page setup of a section in the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="sectionIndex">The index of the section.</param>
    /// <param name="pageSetup">The properties of the page setup.</param>
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
    /// Updates a style in the document.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="styleUpdate">The properties of the style.</param>
    /// <param name="styleName">The name of the style.</param>
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
    /// Updates the formatting properties of a cell in the table row.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="format">The cell format.</param>
    /// <param name="tableRowPath">The path to the table row in the document tree.</param>
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
    /// Updates properties of a table in the document node.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="properties">The properties of the table.</param>
    /// <param name="index">Object index.</param>
    /// <param name="nodePath">The path to the node in the document tree. (optional)</param>
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
    /// Updates the formatting properties of a table row.
    /// </summary>
    /// <param name="name">The filename of the input document.</param>
    /// <param name="format">The row format.</param>
    /// <param name="tablePath">The path to the table in the document tree.</param>
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
