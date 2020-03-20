/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="WordsApi.h">
*   Copyright (c) 2019 Aspose.Words for Cloud
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
#include "requests/ClassifyRequest.h"
#include "requests/ClassifyDocumentRequest.h"
#include "requests/CompareDocumentRequest.h"
#include "requests/ConvertDocumentRequest.h"
#include "requests/CopyFileRequest.h"
#include "requests/CopyFolderRequest.h"
#include "requests/CreateDocumentRequest.h"
#include "requests/CreateFolderRequest.h"
#include "requests/CreateOrUpdateDocumentPropertyRequest.h"
#include "requests/DeleteBorderRequest.h"
#include "requests/DeleteBordersRequest.h"
#include "requests/DeleteCommentRequest.h"
#include "requests/DeleteDocumentPropertyRequest.h"
#include "requests/DeleteDrawingObjectRequest.h"
#include "requests/DeleteDrawingObjectWithoutNodePathRequest.h"
#include "requests/DeleteFieldRequest.h"
#include "requests/DeleteFieldWithoutNodePathRequest.h"
#include "requests/DeleteFieldsRequest.h"
#include "requests/DeleteFieldsWithoutNodePathRequest.h"
#include "requests/DeleteFileRequest.h"
#include "requests/DeleteFolderRequest.h"
#include "requests/DeleteFootnoteRequest.h"
#include "requests/DeleteFootnoteWithoutNodePathRequest.h"
#include "requests/DeleteFormFieldRequest.h"
#include "requests/DeleteFormFieldWithoutNodePathRequest.h"
#include "requests/DeleteHeaderFooterRequest.h"
#include "requests/DeleteHeadersFootersRequest.h"
#include "requests/DeleteMacrosRequest.h"
#include "requests/DeleteOfficeMathObjectRequest.h"
#include "requests/DeleteOfficeMathObjectWithoutNodePathRequest.h"
#include "requests/DeleteParagraphRequest.h"
#include "requests/DeleteParagraphWithoutNodePathRequest.h"
#include "requests/DeleteRunRequest.h"
#include "requests/DeleteSectionRequest.h"
#include "requests/DeleteTableRequest.h"
#include "requests/DeleteTableCellRequest.h"
#include "requests/DeleteTableRowRequest.h"
#include "requests/DeleteTableWithoutNodePathRequest.h"
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
#include "requests/GetDocumentDrawingObjectByIndexWithoutNodePathRequest.h"
#include "requests/GetDocumentDrawingObjectImageDataRequest.h"
#include "requests/GetDocumentDrawingObjectImageDataWithoutNodePathRequest.h"
#include "requests/GetDocumentDrawingObjectOleDataRequest.h"
#include "requests/GetDocumentDrawingObjectOleDataWithoutNodePathRequest.h"
#include "requests/GetDocumentDrawingObjectsRequest.h"
#include "requests/GetDocumentDrawingObjectsWithoutNodePathRequest.h"
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
#include "requests/GetFieldWithoutNodePathRequest.h"
#include "requests/GetFieldsRequest.h"
#include "requests/GetFieldsWithoutNodePathRequest.h"
#include "requests/GetFilesListRequest.h"
#include "requests/GetFootnoteRequest.h"
#include "requests/GetFootnoteWithoutNodePathRequest.h"
#include "requests/GetFootnotesRequest.h"
#include "requests/GetFootnotesWithoutNodePathRequest.h"
#include "requests/GetFormFieldRequest.h"
#include "requests/GetFormFieldWithoutNodePathRequest.h"
#include "requests/GetFormFieldsRequest.h"
#include "requests/GetFormFieldsWithoutNodePathRequest.h"
#include "requests/GetHeaderFooterRequest.h"
#include "requests/GetHeaderFooterOfSectionRequest.h"
#include "requests/GetHeaderFootersRequest.h"
#include "requests/GetOfficeMathObjectRequest.h"
#include "requests/GetOfficeMathObjectWithoutNodePathRequest.h"
#include "requests/GetOfficeMathObjectsRequest.h"
#include "requests/GetOfficeMathObjectsWithoutNodePathRequest.h"
#include "requests/GetParagraphRequest.h"
#include "requests/GetParagraphFormatRequest.h"
#include "requests/GetParagraphFormatWithoutNodePathRequest.h"
#include "requests/GetParagraphWithoutNodePathRequest.h"
#include "requests/GetParagraphsRequest.h"
#include "requests/GetParagraphsWithoutNodePathRequest.h"
#include "requests/GetRangeTextRequest.h"
#include "requests/GetRunRequest.h"
#include "requests/GetRunFontRequest.h"
#include "requests/GetRunsRequest.h"
#include "requests/GetSectionRequest.h"
#include "requests/GetSectionPageSetupRequest.h"
#include "requests/GetSectionsRequest.h"
#include "requests/GetTableRequest.h"
#include "requests/GetTableCellRequest.h"
#include "requests/GetTableCellFormatRequest.h"
#include "requests/GetTablePropertiesRequest.h"
#include "requests/GetTablePropertiesWithoutNodePathRequest.h"
#include "requests/GetTableRowRequest.h"
#include "requests/GetTableRowFormatRequest.h"
#include "requests/GetTableWithoutNodePathRequest.h"
#include "requests/GetTablesRequest.h"
#include "requests/GetTablesWithoutNodePathRequest.h"
#include "requests/InsertCommentRequest.h"
#include "requests/InsertDrawingObjectRequest.h"
#include "requests/InsertDrawingObjectWithoutNodePathRequest.h"
#include "requests/InsertFieldRequest.h"
#include "requests/InsertFieldWithoutNodePathRequest.h"
#include "requests/InsertFootnoteRequest.h"
#include "requests/InsertFootnoteWithoutNodePathRequest.h"
#include "requests/InsertFormFieldRequest.h"
#include "requests/InsertFormFieldWithoutNodePathRequest.h"
#include "requests/InsertHeaderFooterRequest.h"
#include "requests/InsertPageNumbersRequest.h"
#include "requests/InsertParagraphRequest.h"
#include "requests/InsertRunRequest.h"
#include "requests/InsertTableRequest.h"
#include "requests/InsertTableCellRequest.h"
#include "requests/InsertTableRowRequest.h"
#include "requests/InsertTableWithoutNodePathRequest.h"
#include "requests/InsertWatermarkImageRequest.h"
#include "requests/InsertWatermarkTextRequest.h"
#include "requests/LoadWebDocumentRequest.h"
#include "requests/MoveFileRequest.h"
#include "requests/MoveFolderRequest.h"
#include "requests/ProtectDocumentRequest.h"
#include "requests/RejectAllRevisionsRequest.h"
#include "requests/RemoveRangeRequest.h"
#include "requests/RenderDrawingObjectRequest.h"
#include "requests/RenderDrawingObjectWithoutNodePathRequest.h"
#include "requests/RenderMathObjectRequest.h"
#include "requests/RenderMathObjectWithoutNodePathRequest.h"
#include "requests/RenderPageRequest.h"
#include "requests/RenderParagraphRequest.h"
#include "requests/RenderParagraphWithoutNodePathRequest.h"
#include "requests/RenderTableRequest.h"
#include "requests/RenderTableWithoutNodePathRequest.h"
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
#include "requests/UpdateDrawingObjectWithoutNodePathRequest.h"
#include "requests/UpdateFieldRequest.h"
#include "requests/UpdateFieldsRequest.h"
#include "requests/UpdateFootnoteRequest.h"
#include "requests/UpdateFootnoteWithoutNodePathRequest.h"
#include "requests/UpdateFormFieldRequest.h"
#include "requests/UpdateFormFieldWithoutNodePathRequest.h"
#include "requests/UpdateParagraphFormatRequest.h"
#include "requests/UpdateRunRequest.h"
#include "requests/UpdateRunFontRequest.h"
#include "requests/UpdateSectionPageSetupRequest.h"
#include "requests/UpdateTableCellFormatRequest.h"
#include "requests/UpdateTablePropertiesRequest.h"
#include "requests/UpdateTablePropertiesWithoutNodePathRequest.h"
#include "requests/UpdateTableRowFormatRequest.h"
#include "requests/UploadFileRequest.h"

#include "AvailableFontsResponse.h"
#include "BookmarkData.h"
#include "BookmarkResponse.h"
#include "BookmarksResponse.h"
#include "Border.h"
#include "BorderResponse.h"
#include "BordersResponse.h"
#include "ClassificationResponse.h"
#include "Comment.h"
#include "CommentResponse.h"
#include "CommentsResponse.h"
#include "CompareData.h"
#include "DocumentEntryList.h"
#include "DocumentPropertiesResponse.h"
#include "DocumentProperty.h"
#include "DocumentPropertyResponse.h"
#include "DocumentResponse.h"
#include "DrawingObjectResponse.h"
#include "DrawingObjectsResponse.h"
#include "Field.h"
#include "FieldNamesResponse.h"
#include "FieldResponse.h"
#include "FieldsResponse.h"
#include "FilesList.h"
#include "FilesUploadResult.h"
#include "Font.h"
#include "FontResponse.h"
#include "Footnote.h"
#include "FootnoteResponse.h"
#include "FootnotesResponse.h"
#include "FormField.h"
#include "FormFieldResponse.h"
#include "FormFieldsResponse.h"
#include "HeaderFooterResponse.h"
#include "HeaderFootersResponse.h"
#include "HyperlinkResponse.h"
#include "HyperlinksResponse.h"
#include "LoadWebDocumentData.h"
#include "OfficeMathObjectResponse.h"
#include "OfficeMathObjectsResponse.h"
#include "PageNumber.h"
#include "PageSetup.h"
#include "ParagraphFormat.h"
#include "ParagraphFormatResponse.h"
#include "ParagraphInsert.h"
#include "ParagraphLinkCollectionResponse.h"
#include "ParagraphResponse.h"
#include "ProtectionDataResponse.h"
#include "ProtectionRequest.h"
#include "RangeDocument.h"
#include "RangeTextResponse.h"
#include "ReplaceRange.h"
#include "ReplaceTextParameters.h"
#include "ReplaceTextResponse.h"
#include "RevisionsModificationResponse.h"
#include "Run.h"
#include "RunResponse.h"
#include "RunsResponse.h"
#include "SaveOptionsData.h"
#include "SaveResponse.h"
#include "SearchResponse.h"
#include "SectionLinkCollectionResponse.h"
#include "SectionPageSetupResponse.h"
#include "SectionResponse.h"
#include "SplitDocumentResponse.h"
#include "StatDataResponse.h"
#include "TableCellFormat.h"
#include "TableCellFormatResponse.h"
#include "TableCellInsert.h"
#include "TableCellResponse.h"
#include "TableInsert.h"
#include "TableLinkCollectionResponse.h"
#include "TableProperties.h"
#include "TablePropertiesResponse.h"
#include "TableResponse.h"
#include "TableRowFormat.h"
#include "TableRowFormatResponse.h"
#include "TableRowInsert.h"
#include "TableRowResponse.h"
#include "TiffSaveOptionsData.h"
#include "WatermarkText.h"
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

class  WordsApi
{
public:
    ///<summary>
    ///Accepts all revisions in document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    	pplx::task<AsposeResponse<RevisionsModificationResponse>> acceptAllRevisions(
		std::shared_ptr<AcceptAllRevisionsRequest> request
	);
    ///<summary>
    ///Appends documents to original document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">Original document name.</param>
        /// <param name="documentList">DocumentEntryList with a list of documents to append.</param>
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
    ///<summary>
    ///Classifies raw text.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="text">Text to classify.</param>
        /// <param name="bestClassesCount">Number of the best classes to return. (optional, default to 1)</param>
    	pplx::task<AsposeResponse<ClassificationResponse>> classify(
		std::shared_ptr<ClassifyRequest> request
	);
    ///<summary>
    ///Classifies document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="documentName">The document name.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="bestClassesCount">Count of the best classes to return. (optional, default to 1)</param>
        /// <param name="taxonomy">Taxonomy to use for classification return. (optional, default to default)</param>
    	pplx::task<AsposeResponse<ClassificationResponse>> classifyDocument(
		std::shared_ptr<ClassifyDocumentRequest> request
	);
    ///<summary>
    ///Compares document with original document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Converts document from the request&#39;s content to the specified format .
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="document">Converting document</param>
        /// <param name="format">Format to convert.</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="outPath">Path for saving operation result to the local storage. (optional)</param>
        /// <param name="fileNameFieldValue">This file name will be used when resulting document has dynamic field for document file name {filename}. If it is not set, &quot;sourceFilename&quot; will be used instead.  (optional, default to sourceFilename)</param>
        /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    	pplx::task<HttpContent> convertDocument(
		std::shared_ptr<ConvertDocumentRequest> request
	);
    ///<summary>
    ///Copy file
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="destPath">Destination file path</param>
        /// <param name="srcPath">Source file&#39;s path e.g. &#39;/Folder 1/file.ext&#39; or &#39;/Bucket/Folder 1/file.ext&#39;</param>
        /// <param name="srcStorageName">Source storage name (optional)</param>
        /// <param name="destStorageName">Destination storage name (optional)</param>
        /// <param name="versionId">File version ID to copy (optional)</param>
    	pplx::task<std::shared_ptr<web::http::http_response>> copyFile(
		std::shared_ptr<CopyFileRequest> request
	);
    ///<summary>
    ///Copy folder
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="destPath">Destination folder path e.g. &#39;/dst&#39;</param>
        /// <param name="srcPath">Source folder path e.g. /Folder1</param>
        /// <param name="srcStorageName">Source storage name (optional)</param>
        /// <param name="destStorageName">Destination storage name (optional)</param>
    	pplx::task<std::shared_ptr<web::http::http_response>> copyFolder(
		std::shared_ptr<CopyFolderRequest> request
	);
    ///<summary>
    ///Creates new document. Document is created with format which is recognized from file extensions. Supported extensions: \&quot;.doc\&quot;, \&quot;.docx\&quot;, \&quot;.docm\&quot;, \&quot;.dot\&quot;, \&quot;.dotm\&quot;, \&quot;.dotx\&quot;, \&quot;.flatopc\&quot;, \&quot;.fopc\&quot;, \&quot;.flatopc_macro\&quot;, \&quot;.fopc_macro\&quot;, \&quot;.flatopc_template\&quot;, \&quot;.fopc_template\&quot;, \&quot;.flatopc_template_macro\&quot;, \&quot;.fopc_template_macro\&quot;, \&quot;.wordml\&quot;, \&quot;.wml\&quot;, \&quot;.rtf\&quot;.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="fileName">The document name. (optional)</param>
        /// <param name="folder">The document folder. (optional)</param>
    	pplx::task<AsposeResponse<DocumentResponse>> createDocument(
		std::shared_ptr<CreateDocumentRequest> request
	);
    ///<summary>
    ///Create the folder
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="path">Target folder&#39;s path e.g. Folder1/Folder2/. The folders will be created recursively</param>
        /// <param name="storageName">Storage name (optional)</param>
    	pplx::task<std::shared_ptr<web::http::http_response>> createFolder(
		std::shared_ptr<CreateFolderRequest> request
	);
    ///<summary>
    ///Adds new or update existing document property.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Resets border properties to default values.             
    ///</summary>
    ///<remarks>
    ///&#39;nodePath&#39; should refer to paragraph, cell or row.
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node with border(node should be paragraph, cell or row).</param>
        /// <param name="borderType">Border type.</param>
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
    ///<summary>
    ///Resets borders properties to default values.             
    ///</summary>
    ///<remarks>
    ///&#39;nodePath&#39; should refer to paragraph, cell or row.
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node with borders(node should be paragraph, cell or row).</param>
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
    ///<summary>
    ///Removes comment from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Deletes document property.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Removes drawing object from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node, which contains collection of drawing objects.</param>
        /// <param name="index">Object index.</param>
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
    ///<summary>
    ///Removes drawing object from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
        /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
        /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    	pplx::task<std::shared_ptr<web::http::http_response>> deleteDrawingObjectWithoutNodePath(
		std::shared_ptr<DeleteDrawingObjectWithoutNodePathRequest> request
	);
    ///<summary>
    ///Deletes field from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node, which contains collection of fields.</param>
        /// <param name="index">Object index.</param>
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
    ///<summary>
    ///Deletes field from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
        /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
        /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    	pplx::task<std::shared_ptr<web::http::http_response>> deleteFieldWithoutNodePath(
		std::shared_ptr<DeleteFieldWithoutNodePathRequest> request
	);
    ///<summary>
    ///Removes fields from section paragraph.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node, which contains collection of fields.</param>
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
    ///<summary>
    ///Removes fields from section paragraph.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
        /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
        /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    	pplx::task<std::shared_ptr<web::http::http_response>> deleteFieldsWithoutNodePath(
		std::shared_ptr<DeleteFieldsWithoutNodePathRequest> request
	);
    ///<summary>
    ///Delete file
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="path">Path of the file including file name and extension e.g. /Folder1/file.ext</param>
        /// <param name="storageName">Storage name (optional)</param>
        /// <param name="versionId">File version ID to delete (optional)</param>
    	pplx::task<std::shared_ptr<web::http::http_response>> deleteFile(
		std::shared_ptr<DeleteFileRequest> request
	);
    ///<summary>
    ///Delete folder
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="path">Folder path e.g. /Folder1s</param>
        /// <param name="storageName">Storage name (optional)</param>
        /// <param name="recursive">Enable to delete folders, subfolders and files (optional)</param>
    	pplx::task<std::shared_ptr<web::http::http_response>> deleteFolder(
		std::shared_ptr<DeleteFolderRequest> request
	);
    ///<summary>
    ///Removes footnote from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node, which contains collection of footnotes.</param>
        /// <param name="index">Object index.</param>
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
    ///<summary>
    ///Removes footnote from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
        /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
        /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    	pplx::task<std::shared_ptr<web::http::http_response>> deleteFootnoteWithoutNodePath(
		std::shared_ptr<DeleteFootnoteWithoutNodePathRequest> request
	);
    ///<summary>
    ///Removes form field from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node that contains collection of formfields.</param>
        /// <param name="index">Object index.</param>
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
    ///<summary>
    ///Removes form field from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
        /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
        /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    	pplx::task<std::shared_ptr<web::http::http_response>> deleteFormFieldWithoutNodePath(
		std::shared_ptr<DeleteFormFieldWithoutNodePathRequest> request
	);
    ///<summary>
    ///Deletes header/footer from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Deletes document headers and footers.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Removes macros from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Removes OfficeMath object from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node, which contains collection of OfficeMath objects.</param>
        /// <param name="index">Object index.</param>
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
    ///<summary>
    ///Removes OfficeMath object from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
        /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
        /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    	pplx::task<std::shared_ptr<web::http::http_response>> deleteOfficeMathObjectWithoutNodePath(
		std::shared_ptr<DeleteOfficeMathObjectWithoutNodePathRequest> request
	);
    ///<summary>
    ///Removes paragraph from section.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The file name.</param>
        /// <param name="nodePath">Path to the node which contains paragraphs.</param>
        /// <param name="index">Object index.</param>
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
    ///<summary>
    ///Removes paragraph from section.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The file name.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
        /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
        /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    	pplx::task<std::shared_ptr<web::http::http_response>> deleteParagraphWithoutNodePath(
		std::shared_ptr<DeleteParagraphWithoutNodePathRequest> request
	);
    ///<summary>
    ///Removes run from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Removes section from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Deletes a table.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node, which contains tables.</param>
        /// <param name="index">Object index.</param>
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
    ///<summary>
    ///Deletes a table cell.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Deletes a table row.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Deletes a table.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
        /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
        /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    	pplx::task<std::shared_ptr<web::http::http_response>> deleteTableWithoutNodePath(
		std::shared_ptr<DeleteTableWithoutNodePathRequest> request
	);
    ///<summary>
    ///Deletes watermark (for deleting last watermark from the document).
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Download file
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="path">Path of the file including the file name and extension e.g. /folder1/file.ext</param>
        /// <param name="storageName">Storage name (optional)</param>
        /// <param name="versionId">File version ID to download (optional)</param>
    	pplx::task<HttpContent> downloadFile(
		std::shared_ptr<DownloadFileRequest> request
	);
    ///<summary>
    ///Executes document mail merge operation.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="data">Mail merge data (optional)</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="withRegions">With regions flag. (optional)</param>
        /// <param name="mailMergeDataFile">Mail merge data. (optional)</param>
        /// <param name="cleanup">Clean up options. (optional)</param>
        /// <param name="useWholeParagraphAsRegion">Gets or sets a value indicating whether paragraph with TableStart or             TableEnd field should be fully included into mail merge region or particular range between TableStart and TableEnd fields.             The default value is true. (optional, default to {paramName&#x3D;useWholeParagraphAsRegion, baseName&#x3D;UseWholeParagraphAsRegion, snakeName&#x3D;use_whole_paragraph_as_region, phpName&#x3D;use_whole_paragraph_as_region, cppName&#x3D;useWholeParagraphAsRegion, position&#x3D;null, description&#x3D;Gets or sets a value indicating whether paragraph with TableStart or             TableEnd field should be fully included into mail merge region or particular range between TableStart and TableEnd fields.             The default value is true., dataType&#x3D;{isPrimitive&#x3D;true, isList&#x3D;null, isString&#x3D;null, isDateTime&#x3D;null, isInteger&#x3D;null, net&#x3D;bool?, java&#x3D;Boolean, node&#x3D;boolean, python&#x3D;bool, php&#x3D;bool, cpp&#x3D;bool}, required&#x3D;false, nullable&#x3D;false, isFile&#x3D;false, defaultValue&#x3D;true, isPath&#x3D;false, isQuery&#x3D;true, isHeader&#x3D;false, isBody&#x3D;false, isForm&#x3D;false, hasMore&#x3D;true, hasMoreByPosition&#x3D;true})</param>
        /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved with autogenerated name. (optional)</param>
    	pplx::task<AsposeResponse<DocumentResponse>> executeMailMerge(
		std::shared_ptr<ExecuteMailMergeRequest> request
	);
    ///<summary>
    ///Executes document mail merge online.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="template">File with template</param>
        /// <param name="data">File with mailmerge data</param>
        /// <param name="withRegions">With regions flag. (optional)</param>
        /// <param name="cleanup">Clean up options. (optional)</param>
        /// <param name="documentFileName">This file name will be used when resulting document has dynamic field for document file name {filename}. If it is not setted, &quot;template&quot; will be used instead.  (optional, default to template)</param>
    	pplx::task<HttpContent> executeMailMergeOnline(
		std::shared_ptr<ExecuteMailMergeOnlineRequest> request
	);
    ///<summary>
    ///Gets the list of fonts, available for document processing.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    	pplx::task<AsposeResponse<AvailableFontsResponse>> getAvailableFonts(
		std::shared_ptr<GetAvailableFontsRequest> request
	);
    ///<summary>
    ///Reads document bookmark data by its name.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="bookmarkName">The bookmark name.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<BookmarkResponse>> getBookmarkByName(
		std::shared_ptr<GetBookmarkByNameRequest> request
	);
    ///<summary>
    ///Reads document bookmarks common info.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<BookmarksResponse>> getBookmarks(
		std::shared_ptr<GetBookmarksRequest> request
	);
    ///<summary>
    ///Returns a border.
    ///</summary>
    ///<remarks>
    ///&#39;nodePath&#39; should refer to paragraph, cell or row.
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node with border(node should be paragraph, cell or row).</param>
        /// <param name="borderType">Border type.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<BorderResponse>> getBorder(
		std::shared_ptr<GetBorderRequest> request
	);
    ///<summary>
    ///Returns a collection of borders.
    ///</summary>
    ///<remarks>
    ///&#39;nodePath&#39; should refer to paragraph, cell or row.
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node with borders (node should be paragraph, cell or row).</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<BordersResponse>> getBorders(
		std::shared_ptr<GetBordersRequest> request
	);
    ///<summary>
    ///Gets comment from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="commentIndex">The comment index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<CommentResponse>> getComment(
		std::shared_ptr<GetCommentRequest> request
	);
    ///<summary>
    ///Gets comments from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<CommentsResponse>> getComments(
		std::shared_ptr<GetCommentsRequest> request
	);
    ///<summary>
    ///Reads document common info.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="documentName">The document name.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<DocumentResponse>> getDocument(
		std::shared_ptr<GetDocumentRequest> request
	);
    ///<summary>
    ///Reads document drawing object common info by its index or convert to format specified.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node, which contains collection of drawing objects.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<DrawingObjectResponse>> getDocumentDrawingObjectByIndex(
		std::shared_ptr<GetDocumentDrawingObjectByIndexRequest> request
	);
    ///<summary>
    ///Reads document drawing object common info by its index or convert to format specified.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<DrawingObjectResponse>> getDocumentDrawingObjectByIndexWithoutNodePath(
		std::shared_ptr<GetDocumentDrawingObjectByIndexWithoutNodePathRequest> request
	);
    ///<summary>
    ///Reads drawing object image data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node, which contains collection of drawing objects.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<HttpContent> getDocumentDrawingObjectImageData(
		std::shared_ptr<GetDocumentDrawingObjectImageDataRequest> request
	);
    ///<summary>
    ///Reads drawing object image data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<HttpContent> getDocumentDrawingObjectImageDataWithoutNodePath(
		std::shared_ptr<GetDocumentDrawingObjectImageDataWithoutNodePathRequest> request
	);
    ///<summary>
    ///Gets drawing object OLE data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node, which contains collection of drawing objects.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<HttpContent> getDocumentDrawingObjectOleData(
		std::shared_ptr<GetDocumentDrawingObjectOleDataRequest> request
	);
    ///<summary>
    ///Gets drawing object OLE data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<HttpContent> getDocumentDrawingObjectOleDataWithoutNodePath(
		std::shared_ptr<GetDocumentDrawingObjectOleDataWithoutNodePathRequest> request
	);
    ///<summary>
    ///Reads document drawing objects common info.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node, which contains collection of drawing objects.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<DrawingObjectsResponse>> getDocumentDrawingObjects(
		std::shared_ptr<GetDocumentDrawingObjectsRequest> request
	);
    ///<summary>
    ///Reads document drawing objects common info.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<DrawingObjectsResponse>> getDocumentDrawingObjectsWithoutNodePath(
		std::shared_ptr<GetDocumentDrawingObjectsWithoutNodePathRequest> request
	);
    ///<summary>
    ///Reads document field names.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="useNonMergeFields">If true, result includes &quot;mustache&quot; field names. (optional)</param>
    	pplx::task<AsposeResponse<FieldNamesResponse>> getDocumentFieldNames(
		std::shared_ptr<GetDocumentFieldNamesRequest> request
	);
    ///<summary>
    ///Reads document field names.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="template">File with template</param>
        /// <param name="useNonMergeFields">Use non merge fields or not. (optional)</param>
    	pplx::task<AsposeResponse<FieldNamesResponse>> getDocumentFieldNamesOnline(
		std::shared_ptr<GetDocumentFieldNamesOnlineRequest> request
	);
    ///<summary>
    ///Reads document hyperlink by its index.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="hyperlinkIndex">The hyperlink index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<HyperlinkResponse>> getDocumentHyperlinkByIndex(
		std::shared_ptr<GetDocumentHyperlinkByIndexRequest> request
	);
    ///<summary>
    ///Reads document hyperlinks common info.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<HyperlinksResponse>> getDocumentHyperlinks(
		std::shared_ptr<GetDocumentHyperlinksRequest> request
	);
    ///<summary>
    ///Reads document properties info.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document&#39;s name.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<DocumentPropertiesResponse>> getDocumentProperties(
		std::shared_ptr<GetDocumentPropertiesRequest> request
	);
    ///<summary>
    ///Reads document property info by the property name.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="propertyName">The property name.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<DocumentPropertyResponse>> getDocumentProperty(
		std::shared_ptr<GetDocumentPropertyRequest> request
	);
    ///<summary>
    ///Reads document protection common info.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<ProtectionDataResponse>> getDocumentProtection(
		std::shared_ptr<GetDocumentProtectionRequest> request
	);
    ///<summary>
    ///Reads document statistics.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="includeComments">Support including/excluding comments from the WordCount. Default value is &quot;false&quot;. (optional)</param>
        /// <param name="includeFootnotes">Support including/excluding footnotes from the WordCount. Default value is &quot;false&quot;. (optional)</param>
        /// <param name="includeTextInShapes">Support including/excluding shape&#39;s text from the WordCount. Default value is &quot;false&quot;. (optional)</param>
    	pplx::task<AsposeResponse<StatDataResponse>> getDocumentStatistics(
		std::shared_ptr<GetDocumentStatisticsRequest> request
	);
    ///<summary>
    ///Exports the document into the specified format.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Gets field from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node, which contains collection of fields.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<FieldResponse>> getField(
		std::shared_ptr<GetFieldRequest> request
	);
    ///<summary>
    ///Gets field from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<FieldResponse>> getFieldWithoutNodePath(
		std::shared_ptr<GetFieldWithoutNodePathRequest> request
	);
    ///<summary>
    ///Get fields from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node, which contains collection of fields.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<FieldsResponse>> getFields(
		std::shared_ptr<GetFieldsRequest> request
	);
    ///<summary>
    ///Get fields from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<FieldsResponse>> getFieldsWithoutNodePath(
		std::shared_ptr<GetFieldsWithoutNodePathRequest> request
	);
    ///<summary>
    ///Get all files and folders within a folder
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="path">Folder path e.g. /Folder1</param>
        /// <param name="storageName">Storage name (optional)</param>
    	pplx::task<AsposeResponse<FilesList>> getFilesList(
		std::shared_ptr<GetFilesListRequest> request
	);
    ///<summary>
    ///Reads footnote by index.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node, which contains collection of footnotes.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<FootnoteResponse>> getFootnote(
		std::shared_ptr<GetFootnoteRequest> request
	);
    ///<summary>
    ///Reads footnote by index.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<FootnoteResponse>> getFootnoteWithoutNodePath(
		std::shared_ptr<GetFootnoteWithoutNodePathRequest> request
	);
    ///<summary>
    ///Gets footnotes from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node, which contains collection of footnotes.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<FootnotesResponse>> getFootnotes(
		std::shared_ptr<GetFootnotesRequest> request
	);
    ///<summary>
    ///Gets footnotes from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<FootnotesResponse>> getFootnotesWithoutNodePath(
		std::shared_ptr<GetFootnotesWithoutNodePathRequest> request
	);
    ///<summary>
    ///Returns representation of an one of the form field.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node that contains collection of formfields.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<FormFieldResponse>> getFormField(
		std::shared_ptr<GetFormFieldRequest> request
	);
    ///<summary>
    ///Returns representation of an one of the form field.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<FormFieldResponse>> getFormFieldWithoutNodePath(
		std::shared_ptr<GetFormFieldWithoutNodePathRequest> request
	);
    ///<summary>
    ///Gets form fields from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node containing collection of form fields.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<FormFieldsResponse>> getFormFields(
		std::shared_ptr<GetFormFieldsRequest> request
	);
    ///<summary>
    ///Gets form fields from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<FormFieldsResponse>> getFormFieldsWithoutNodePath(
		std::shared_ptr<GetFormFieldsWithoutNodePathRequest> request
	);
    ///<summary>
    ///Returns a header/footer from the document by index.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Returns a header/footer from the document section.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Returns a list of header/footers from the document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Reads OfficeMath object by index.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node, which contains collection of OfficeMath objects.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<OfficeMathObjectResponse>> getOfficeMathObject(
		std::shared_ptr<GetOfficeMathObjectRequest> request
	);
    ///<summary>
    ///Reads OfficeMath object by index.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<OfficeMathObjectResponse>> getOfficeMathObjectWithoutNodePath(
		std::shared_ptr<GetOfficeMathObjectWithoutNodePathRequest> request
	);
    ///<summary>
    ///Gets OfficeMath objects from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node, which contains collection of OfficeMath objects.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<OfficeMathObjectsResponse>> getOfficeMathObjects(
		std::shared_ptr<GetOfficeMathObjectsRequest> request
	);
    ///<summary>
    ///Gets OfficeMath objects from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<OfficeMathObjectsResponse>> getOfficeMathObjectsWithoutNodePath(
		std::shared_ptr<GetOfficeMathObjectsWithoutNodePathRequest> request
	);
    ///<summary>
    ///This resource represents one of the paragraphs contained in the document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node which contains paragraphs.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<ParagraphResponse>> getParagraph(
		std::shared_ptr<GetParagraphRequest> request
	);
    ///<summary>
    ///Represents all the formatting for a paragraph.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node which contains paragraphs.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<ParagraphFormatResponse>> getParagraphFormat(
		std::shared_ptr<GetParagraphFormatRequest> request
	);
    ///<summary>
    ///Represents all the formatting for a paragraph.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<ParagraphFormatResponse>> getParagraphFormatWithoutNodePath(
		std::shared_ptr<GetParagraphFormatWithoutNodePathRequest> request
	);
    ///<summary>
    ///This resource represents one of the paragraphs contained in the document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<ParagraphResponse>> getParagraphWithoutNodePath(
		std::shared_ptr<GetParagraphWithoutNodePathRequest> request
	);
    ///<summary>
    ///Returns a list of paragraphs that are contained in the document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node which contains paragraphs.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<ParagraphLinkCollectionResponse>> getParagraphs(
		std::shared_ptr<GetParagraphsRequest> request
	);
    ///<summary>
    ///Returns a list of paragraphs that are contained in the document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<ParagraphLinkCollectionResponse>> getParagraphsWithoutNodePath(
		std::shared_ptr<GetParagraphsWithoutNodePathRequest> request
	);
    ///<summary>
    ///Gets the text from the range.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document.</param>
        /// <param name="rangeStartIdentifier">The range start identifier. Identifier is the value of the &quot;nodeId&quot; field, which every document node has, extended with the prefix &quot;id&quot;. It looks like &quot;id0.0.7&quot;. Also values like &quot;image5&quot; and &quot;table3&quot; can be used as an identifier for images and tables, where the number is an index of the image/table.</param>
        /// <param name="rangeEndIdentifier">The range end identifier. (optional)</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<RangeTextResponse>> getRangeText(
		std::shared_ptr<GetRangeTextRequest> request
	);
    ///<summary>
    ///This resource represents run of text contained in the document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///This resource represents font of run.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///This resource represents collection of runs in the paragraph.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="paragraphPath">Path to parent paragraph.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<RunsResponse>> getRuns(
		std::shared_ptr<GetRunsRequest> request
	);
    ///<summary>
    ///Gets document section by index.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="sectionIndex">Section index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<SectionResponse>> getSection(
		std::shared_ptr<GetSectionRequest> request
	);
    ///<summary>
    ///Gets page setup of section.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="sectionIndex">Section index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<SectionPageSetupResponse>> getSectionPageSetup(
		std::shared_ptr<GetSectionPageSetupRequest> request
	);
    ///<summary>
    ///Returns a list of sections that are contained in the document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<SectionLinkCollectionResponse>> getSections(
		std::shared_ptr<GetSectionsRequest> request
	);
    ///<summary>
    ///Returns a table.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node, which contains tables.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<TableResponse>> getTable(
		std::shared_ptr<GetTableRequest> request
	);
    ///<summary>
    ///Returns a table cell.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Returns a table cell format.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Returns a table properties.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node, which contains tables.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<TablePropertiesResponse>> getTableProperties(
		std::shared_ptr<GetTablePropertiesRequest> request
	);
    ///<summary>
    ///Returns a table properties.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<TablePropertiesResponse>> getTablePropertiesWithoutNodePath(
		std::shared_ptr<GetTablePropertiesWithoutNodePathRequest> request
	);
    ///<summary>
    ///Returns a table row.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Returns a table row format.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Returns a table.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<TableResponse>> getTableWithoutNodePath(
		std::shared_ptr<GetTableWithoutNodePathRequest> request
	);
    ///<summary>
    ///Returns a list of tables that are contained in the document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node, which contains tables.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<TableLinkCollectionResponse>> getTables(
		std::shared_ptr<GetTablesRequest> request
	);
    ///<summary>
    ///Returns a list of tables that are contained in the document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<TableLinkCollectionResponse>> getTablesWithoutNodePath(
		std::shared_ptr<GetTablesWithoutNodePathRequest> request
	);
    ///<summary>
    ///Adds comment to document, returns inserted comment data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Adds drawing object to document, returns added  drawing object&#39;s data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="drawingObject">Drawing object parameters</param>
        /// <param name="imageFile">File with image</param>
        /// <param name="nodePath">Path to the node, which contains collection of drawing objects.</param>
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
    ///<summary>
    ///Adds drawing object to document, returns added  drawing object&#39;s data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="drawingObject">Drawing object parameters</param>
        /// <param name="imageFile">File with image</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
        /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
        /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    	pplx::task<AsposeResponse<DrawingObjectResponse>> insertDrawingObjectWithoutNodePath(
		std::shared_ptr<InsertDrawingObjectWithoutNodePathRequest> request
	);
    ///<summary>
    ///Adds field to document, returns inserted field&#39;s data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="field">Field data.</param>
        /// <param name="nodePath">Path to the node, which contains collection of fields.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
        /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
        /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
        /// <param name="insertBeforeNode">Field will be inserted before node with id&#x3D;&quot;nodeId&quot;. (optional)</param>
    	pplx::task<AsposeResponse<FieldResponse>> insertField(
		std::shared_ptr<InsertFieldRequest> request
	);
    ///<summary>
    ///Adds field to document, returns inserted field&#39;s data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="field">Field data.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
        /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
        /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
        /// <param name="insertBeforeNode">Field will be inserted before node with id&#x3D;&quot;nodeId&quot;. (optional)</param>
    	pplx::task<AsposeResponse<FieldResponse>> insertFieldWithoutNodePath(
		std::shared_ptr<InsertFieldWithoutNodePathRequest> request
	);
    ///<summary>
    ///Adds footnote to document, returns added footnote&#39;s data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="footnoteDto">Footnote data.</param>
        /// <param name="nodePath">Path to the node, which contains collection of footnotes.</param>
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
    ///<summary>
    ///Adds footnote to document, returns added footnote&#39;s data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="footnoteDto">Footnote data.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
        /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
        /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    	pplx::task<AsposeResponse<FootnoteResponse>> insertFootnoteWithoutNodePath(
		std::shared_ptr<InsertFootnoteWithoutNodePathRequest> request
	);
    ///<summary>
    ///Adds form field to paragraph, returns added form field&#39;s data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="formField">From field data.</param>
        /// <param name="nodePath">Path to the node that contains collection of formfields.</param>
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
    ///<summary>
    ///Adds form field to paragraph, returns added form field&#39;s data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="formField">From field data.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
        /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
        /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
        /// <param name="insertBeforeNode">Form field will be inserted before node with index. (optional)</param>
    	pplx::task<AsposeResponse<FormFieldResponse>> insertFormFieldWithoutNodePath(
		std::shared_ptr<InsertFormFieldWithoutNodePathRequest> request
	);
    ///<summary>
    ///Inserts to document header or footer.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Inserts document page numbers.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Adds paragraph to document, returns added paragraph&#39;s data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="paragraph">Paragraph data.</param>
        /// <param name="nodePath">Path to the node which contains paragraphs.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
        /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
        /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
        /// <param name="insertBeforeNode">Paragraph will be inserted before node with index. (optional)</param>
    	pplx::task<AsposeResponse<ParagraphResponse>> insertParagraph(
		std::shared_ptr<InsertParagraphRequest> request
	);
    ///<summary>
    ///Adds run to document, returns added paragraph&#39;s data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Adds table to document, returns added table&#39;s data.             
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node, which contains tables.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
        /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
        /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
        /// <param name="table">Table parameters/.</param>
    	pplx::task<AsposeResponse<TableResponse>> insertTable(
		std::shared_ptr<InsertTableRequest> request
	);
    ///<summary>
    ///Adds table cell to table, returns added cell&#39;s data.             
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="tableRowPath">Path to table row.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
        /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
        /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
        /// <param name="cell">Table cell parameters/.</param>
    	pplx::task<AsposeResponse<TableCellResponse>> insertTableCell(
		std::shared_ptr<InsertTableCellRequest> request
	);
    ///<summary>
    ///Adds table row to table, returns added row&#39;s data.             
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="tablePath">Path to table.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
        /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
        /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
        /// <param name="row">Table row parameters/.</param>
    	pplx::task<AsposeResponse<TableRowResponse>> insertTableRow(
		std::shared_ptr<InsertTableRowRequest> request
	);
    ///<summary>
    ///Adds table to document, returns added table&#39;s data.             
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
        /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
        /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
        /// <param name="table">Table parameters/.</param>
    	pplx::task<AsposeResponse<TableResponse>> insertTableWithoutNodePath(
		std::shared_ptr<InsertTableWithoutNodePathRequest> request
	);
    ///<summary>
    ///Inserts document watermark image.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="imageFile">File with image (optional)</param>
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
    ///<summary>
    ///Inserts document watermark text.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="watermarkText">WatermarkText with the watermark data.             </param>
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
    ///<summary>
    ///Loads new document from web into the file with any supported format of data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="data">Parameters of loading.</param>
        /// <param name="storage">Original document storage. (optional)</param>
    	pplx::task<AsposeResponse<SaveResponse>> loadWebDocument(
		std::shared_ptr<LoadWebDocumentRequest> request
	);
    ///<summary>
    ///Move file
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="destPath">Destination file path e.g. &#39;/dest.ext&#39;</param>
        /// <param name="srcPath">Source file&#39;s path e.g. &#39;/Folder 1/file.ext&#39; or &#39;/Bucket/Folder 1/file.ext&#39;</param>
        /// <param name="srcStorageName">Source storage name (optional)</param>
        /// <param name="destStorageName">Destination storage name (optional)</param>
        /// <param name="versionId">File version ID to move (optional)</param>
    	pplx::task<std::shared_ptr<web::http::http_response>> moveFile(
		std::shared_ptr<MoveFileRequest> request
	);
    ///<summary>
    ///Move folder
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="destPath">Destination folder path to move to e.g &#39;/dst&#39;</param>
        /// <param name="srcPath">Source folder path e.g. /Folder1</param>
        /// <param name="srcStorageName">Source storage name (optional)</param>
        /// <param name="destStorageName">Destination storage name (optional)</param>
    	pplx::task<std::shared_ptr<web::http::http_response>> moveFolder(
		std::shared_ptr<MoveFolderRequest> request
	);
    ///<summary>
    ///Protects document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Rejects all revisions in document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    	pplx::task<AsposeResponse<RevisionsModificationResponse>> rejectAllRevisions(
		std::shared_ptr<RejectAllRevisionsRequest> request
	);
    ///<summary>
    ///Removes the range from the document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document.</param>
        /// <param name="rangeStartIdentifier">The range start identifier. Identifier is the value of the &quot;nodeId&quot; field, which every document node has, extended with the prefix &quot;id&quot;. It looks like &quot;id0.0.7&quot;. Also values like &quot;image5&quot; and &quot;table3&quot; can be used as an identifier for images and tables, where the number is an index of the image/table.</param>
        /// <param name="rangeEndIdentifier">The range end identifier. (optional)</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    	pplx::task<AsposeResponse<DocumentResponse>> removeRange(
		std::shared_ptr<RemoveRangeRequest> request
	);
    ///<summary>
    ///Renders drawing object to specified format.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="format">The destination format.</param>
        /// <param name="nodePath">Path to the node, which contains drawing objects.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    	pplx::task<HttpContent> renderDrawingObject(
		std::shared_ptr<RenderDrawingObjectRequest> request
	);
    ///<summary>
    ///Renders drawing object to specified format.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="format">The destination format.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    	pplx::task<HttpContent> renderDrawingObjectWithoutNodePath(
		std::shared_ptr<RenderDrawingObjectWithoutNodePathRequest> request
	);
    ///<summary>
    ///Renders math object to specified format.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="format">The destination format.</param>
        /// <param name="nodePath">Path to the node, which contains office math objects.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    	pplx::task<HttpContent> renderMathObject(
		std::shared_ptr<RenderMathObjectRequest> request
	);
    ///<summary>
    ///Renders math object to specified format.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="format">The destination format.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    	pplx::task<HttpContent> renderMathObjectWithoutNodePath(
		std::shared_ptr<RenderMathObjectWithoutNodePathRequest> request
	);
    ///<summary>
    ///Renders page to specified format.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Renders paragraph to specified format.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="format">The destination format.</param>
        /// <param name="nodePath">Path to the node, which contains paragraphs.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    	pplx::task<HttpContent> renderParagraph(
		std::shared_ptr<RenderParagraphRequest> request
	);
    ///<summary>
    ///Renders paragraph to specified format.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="format">The destination format.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    	pplx::task<HttpContent> renderParagraphWithoutNodePath(
		std::shared_ptr<RenderParagraphWithoutNodePathRequest> request
	);
    ///<summary>
    ///Renders table to specified format.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="format">The destination format.</param>
        /// <param name="nodePath">Path to the node, which contains tables.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    	pplx::task<HttpContent> renderTable(
		std::shared_ptr<RenderTableRequest> request
	);
    ///<summary>
    ///Renders table to specified format.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="format">The destination format.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    	pplx::task<HttpContent> renderTableWithoutNodePath(
		std::shared_ptr<RenderTableWithoutNodePathRequest> request
	);
    ///<summary>
    ///Replaces document text.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Replaces the content in the range.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document.</param>
        /// <param name="rangeStartIdentifier">The range start identifier. Identifier is the value of the &quot;nodeId&quot; field, which every document node has, extended with the prefix &quot;id&quot;. It looks like &quot;id0.0.7&quot;. Also values like &quot;image5&quot; and &quot;table3&quot; can be used as an identifier for images and tables, where the number is an index of the image/table.</param>
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
    ///<summary>
    ///Resets font&#39;s cache.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
	pplx::task<std::shared_ptr<web::http::http_response>> resetCache(
		std::shared_ptr<ResetCacheRequest> request
	);
    ///<summary>
    ///Converts document to destination format with detailed settings and saves result to storage.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Saves the selected range as a new document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document.</param>
        /// <param name="rangeStartIdentifier">The range start identifier. Identifier is the value of the &quot;nodeId&quot; field, which every document node has, extended with the prefix &quot;id&quot;. It looks like &quot;id0.0.7&quot;. Also values like &quot;image5&quot; and &quot;table3&quot; can be used as an identifier for images and tables, where the number is an index of the image/table.</param>
        /// <param name="documentParameters">Parameters of a new document.</param>
        /// <param name="rangeEndIdentifier">The range end identifier. (optional)</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<DocumentResponse>> saveAsRange(
		std::shared_ptr<SaveAsRangeRequest> request
	);
    ///<summary>
    ///Converts document to tiff with detailed settings and saves result to storage.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Searches text in document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="pattern">The regular expression used to find matches.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
    	pplx::task<AsposeResponse<SearchResponse>> search(
		std::shared_ptr<SearchRequest> request
	);
    ///<summary>
    ///Splits document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">Original document name.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
        /// <param name="format">Format to split. (optional)</param>
        /// <param name="from">Start page. (optional)</param>
        /// <param name="to">End page. (optional)</param>
        /// <param name="zipOutput">ZipOutput or not. (optional)</param>
        /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    	pplx::task<AsposeResponse<SplitDocumentResponse>> splitDocument(
		std::shared_ptr<SplitDocumentRequest> request
	);
    ///<summary>
    ///Unprotects document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Updates document bookmark.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Updates border properties.             
    ///</summary>
    ///<remarks>
    ///&#39;nodePath&#39; should refer to paragraph, cell or row.
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="borderProperties">Border properties.</param>
        /// <param name="nodePath">Path to the node with border(node should be paragraph, cell or row).</param>
        /// <param name="borderType">Border type.</param>
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
    ///<summary>
    ///Updates the comment, returns updated comment data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Updates drawing object, returns updated  drawing object&#39;s data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="drawingObject">Drawing object parameters</param>
        /// <param name="imageFile">File with image</param>
        /// <param name="nodePath">Path to the node, which contains collection of drawing objects.</param>
        /// <param name="index">Object index.</param>
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
    ///<summary>
    ///Updates drawing object, returns updated  drawing object&#39;s data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="drawingObject">Drawing object parameters</param>
        /// <param name="imageFile">File with image</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
        /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
        /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    	pplx::task<AsposeResponse<DrawingObjectResponse>> updateDrawingObjectWithoutNodePath(
		std::shared_ptr<UpdateDrawingObjectWithoutNodePathRequest> request
	);
    ///<summary>
    ///Updates field&#39;s properties, returns updated field&#39;s data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="field">Field data.</param>
        /// <param name="nodePath">Path to the node, which contains collection of fields.</param>
        /// <param name="index">Object index.</param>
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
    ///<summary>
    ///Updates (reevaluate) fields in document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    	pplx::task<AsposeResponse<DocumentResponse>> updateFields(
		std::shared_ptr<UpdateFieldsRequest> request
	);
    ///<summary>
    ///Updates footnote&#39;s properties, returns updated run&#39;s data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="footnoteDto">Footnote data.</param>
        /// <param name="nodePath">Path to the node, which contains collection of footnotes.</param>
        /// <param name="index">Object index.</param>
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
    ///<summary>
    ///Updates footnote&#39;s properties, returns updated run&#39;s data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="footnoteDto">Footnote data.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
        /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
        /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    	pplx::task<AsposeResponse<FootnoteResponse>> updateFootnoteWithoutNodePath(
		std::shared_ptr<UpdateFootnoteWithoutNodePathRequest> request
	);
    ///<summary>
    ///Updates properties of form field, returns updated form field.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="formField">From field data.</param>
        /// <param name="nodePath">Path to the node that contains collection of formfields.</param>
        /// <param name="index">Object index.</param>
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
    ///<summary>
    ///Updates properties of form field, returns updated form field.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="formField">From field data.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
        /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
        /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    	pplx::task<AsposeResponse<FormFieldResponse>> updateFormFieldWithoutNodePath(
		std::shared_ptr<UpdateFormFieldWithoutNodePathRequest> request
	);
    ///<summary>
    ///Updates paragraph format properties, returns updated format properties.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="dto">Paragraph format object.</param>
        /// <param name="nodePath">Path to the node which contains paragraphs.</param>
        /// <param name="index">Object index.</param>
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
    ///<summary>
    ///Updates run&#39;s properties, returns updated run&#39;s data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Updates font properties, returns updated font data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Updates page setup of section.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
    ///<summary>
    ///Updates a table cell format.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
        /// <param name="format">The properties.</param>
    	pplx::task<AsposeResponse<TableCellFormatResponse>> updateTableCellFormat(
		std::shared_ptr<UpdateTableCellFormatRequest> request
	);
    ///<summary>
    ///Updates a table properties.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="nodePath">Path to the node, which contains tables.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
        /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
        /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
        /// <param name="properties">The properties.</param>
    	pplx::task<AsposeResponse<TablePropertiesResponse>> updateTableProperties(
		std::shared_ptr<UpdateTablePropertiesRequest> request
	);
    ///<summary>
    ///Updates a table properties.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
        /// <param name="index">Object index.</param>
        /// <param name="folder">Original document folder. (optional)</param>
        /// <param name="storage">Original document storage. (optional)</param>
        /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
        /// <param name="password">Password for opening an encrypted document. (optional)</param>
        /// <param name="destFileName">Result path of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
        /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
        /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
        /// <param name="properties">The properties.</param>
    	pplx::task<AsposeResponse<TablePropertiesResponse>> updateTablePropertiesWithoutNodePath(
		std::shared_ptr<UpdateTablePropertiesWithoutNodePathRequest> request
	);
    ///<summary>
    ///Updates a table row format.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
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
        /// <param name="format">Table row format.</param>
    	pplx::task<AsposeResponse<TableRowFormatResponse>> updateTableRowFormat(
		std::shared_ptr<UpdateTableRowFormatRequest> request
	);
    ///<summary>
    ///Upload file
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="fileContent">File to upload</param>
        /// <param name="path">Path where to upload including filename and extension e.g. /file.ext or /Folder 1/file.ext             If the content is multipart and path does not contains the file name it tries to get them from filename parameter             from Content-Disposition header.</param>
        /// <param name="storageName">Storage name (optional)</param>
    	pplx::task<AsposeResponse<FilesUploadResult>> uploadFile(
		std::shared_ptr<UploadFileRequest> request
	);

public:
    explicit WordsApi(std::shared_ptr<ApiClient> apiClient );
    virtual ~WordsApi() = default;
    
protected:
    std::shared_ptr<ApiClient> m_ApiClient;
};

}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_WordsApi_H_ */


