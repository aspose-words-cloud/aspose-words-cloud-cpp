/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="WordsApi.h">
*   Copyright (c) 2018 Aspose.Words for Cloud
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

#ifndef IO_SWAGGER_CLIENT_API_WordsApi_H_
#define IO_SWAGGER_CLIENT_API_WordsApi_H_


#include "../ApiClient.h"

#include "requests/AcceptAllRevisionsRequest.h"
#include "requests/ClassifyRequest.h"
#include "requests/ClassifyDocumentRequest.h"
#include "requests/CreateOrUpdateDocumentPropertyRequest.h"
#include "requests/DeleteBorderRequest.h"
#include "requests/DeleteBordersRequest.h"
#include "requests/DeleteCommentRequest.h"
#include "requests/DeleteDocumentMacrosRequest.h"
#include "requests/DeleteDocumentPropertyRequest.h"
#include "requests/DeleteDocumentWatermarkRequest.h"
#include "requests/DeleteDrawingObjectRequest.h"
#include "requests/DeleteFieldRequest.h"
#include "requests/DeleteFieldsRequest.h"
#include "requests/DeleteFootnoteRequest.h"
#include "requests/DeleteFormFieldRequest.h"
#include "requests/DeleteHeaderFooterRequest.h"
#include "requests/DeleteHeadersFootersRequest.h"
#include "requests/DeleteOfficeMathObjectRequest.h"
#include "requests/DeleteParagraphRequest.h"
#include "requests/DeleteRunRequest.h"
#include "requests/DeleteTableRequest.h"
#include "requests/DeleteTableCellRequest.h"
#include "requests/DeleteTableRowRequest.h"
#include "requests/DeleteUnprotectDocumentRequest.h"
#include "requests/GetAvailableFontsRequest.h"
#include "requests/GetBorderRequest.h"
#include "requests/GetBordersRequest.h"
#include "requests/GetCommentRequest.h"
#include "requests/GetCommentsRequest.h"
#include "requests/GetDocumentRequest.h"
#include "requests/GetDocumentBookmarkByNameRequest.h"
#include "requests/GetDocumentBookmarksRequest.h"
#include "requests/GetDocumentDrawingObjectByIndexRequest.h"
#include "requests/GetDocumentDrawingObjectImageDataRequest.h"
#include "requests/GetDocumentDrawingObjectOleDataRequest.h"
#include "requests/GetDocumentDrawingObjectsRequest.h"
#include "requests/GetDocumentFieldNamesRequest.h"
#include "requests/GetDocumentHyperlinkByIndexRequest.h"
#include "requests/GetDocumentHyperlinksRequest.h"
#include "requests/GetDocumentParagraphRequest.h"
#include "requests/GetDocumentParagraphFormatRequest.h"
#include "requests/GetDocumentParagraphRunRequest.h"
#include "requests/GetDocumentParagraphRunFontRequest.h"
#include "requests/GetDocumentParagraphRunsRequest.h"
#include "requests/GetDocumentParagraphsRequest.h"
#include "requests/GetDocumentPropertiesRequest.h"
#include "requests/GetDocumentPropertyRequest.h"
#include "requests/GetDocumentProtectionRequest.h"
#include "requests/GetDocumentStatisticsRequest.h"
#include "requests/GetDocumentTextItemsRequest.h"
#include "requests/GetDocumentWithFormatRequest.h"
#include "requests/GetFieldRequest.h"
#include "requests/GetFieldsRequest.h"
#include "requests/GetFootnoteRequest.h"
#include "requests/GetFootnotesRequest.h"
#include "requests/GetFormFieldRequest.h"
#include "requests/GetFormFieldsRequest.h"
#include "requests/GetHeaderFooterRequest.h"
#include "requests/GetHeaderFooterOfSectionRequest.h"
#include "requests/GetHeaderFootersRequest.h"
#include "requests/GetOfficeMathObjectRequest.h"
#include "requests/GetOfficeMathObjectsRequest.h"
#include "requests/GetSectionRequest.h"
#include "requests/GetSectionPageSetupRequest.h"
#include "requests/GetSectionsRequest.h"
#include "requests/GetTableRequest.h"
#include "requests/GetTableCellRequest.h"
#include "requests/GetTableCellFormatRequest.h"
#include "requests/GetTablePropertiesRequest.h"
#include "requests/GetTableRowRequest.h"
#include "requests/GetTableRowFormatRequest.h"
#include "requests/GetTablesRequest.h"
#include "requests/InsertTableRequest.h"
#include "requests/InsertTableCellRequest.h"
#include "requests/InsertTableRowRequest.h"
#include "requests/PostAppendDocumentRequest.h"
#include "requests/PostChangeDocumentProtectionRequest.h"
#include "requests/PostCommentRequest.h"
#include "requests/PostCompareDocumentRequest.h"
#include "requests/PostDocumentExecuteMailMergeRequest.h"
#include "requests/PostDocumentParagraphFormatRequest.h"
#include "requests/PostDocumentParagraphRunFontRequest.h"
#include "requests/PostDocumentSaveAsRequest.h"
#include "requests/PostDrawingObjectRequest.h"
#include "requests/PostExecuteTemplateRequest.h"
#include "requests/PostFieldRequest.h"
#include "requests/PostFootnoteRequest.h"
#include "requests/PostFormFieldRequest.h"
#include "requests/PostInsertDocumentWatermarkImageRequest.h"
#include "requests/PostInsertDocumentWatermarkTextRequest.h"
#include "requests/PostInsertPageNumbersRequest.h"
#include "requests/PostLoadWebDocumentRequest.h"
#include "requests/PostReplaceTextRequest.h"
#include "requests/PostRunRequest.h"
#include "requests/PostSplitDocumentRequest.h"
#include "requests/PostUpdateDocumentBookmarkRequest.h"
#include "requests/PostUpdateDocumentFieldsRequest.h"
#include "requests/PutCommentRequest.h"
#include "requests/PutConvertDocumentRequest.h"
#include "requests/PutCreateDocumentRequest.h"
#include "requests/PutDocumentFieldNamesRequest.h"
#include "requests/PutDocumentSaveAsTiffRequest.h"
#include "requests/PutDrawingObjectRequest.h"
#include "requests/PutExecuteMailMergeOnlineRequest.h"
#include "requests/PutExecuteTemplateOnlineRequest.h"
#include "requests/PutFieldRequest.h"
#include "requests/PutFootnoteRequest.h"
#include "requests/PutFormFieldRequest.h"
#include "requests/PutHeaderFooterRequest.h"
#include "requests/PutParagraphRequest.h"
#include "requests/PutProtectDocumentRequest.h"
#include "requests/PutRunRequest.h"
#include "requests/RejectAllRevisionsRequest.h"
#include "requests/RenderDrawingObjectRequest.h"
#include "requests/RenderMathObjectRequest.h"
#include "requests/RenderPageRequest.h"
#include "requests/RenderParagraphRequest.h"
#include "requests/RenderTableRequest.h"
#include "requests/ResetCacheRequest.h"
#include "requests/SearchRequest.h"
#include "requests/UpdateBorderRequest.h"
#include "requests/UpdateSectionPageSetupRequest.h"
#include "requests/UpdateTableCellFormatRequest.h"
#include "requests/UpdateTablePropertiesRequest.h"
#include "requests/UpdateTableRowFormatRequest.h"

#include "AsposeResponse.h"
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
#include "HttpContent.h"
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
#include "ReplaceTextRequest.h"
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
#include "TextItemsResponse.h"
#include "TiffSaveOptionsData.h"
#include "WatermarkText.h"
#include <cpprest/details/basic_types.h>
#undef U
#include <boost/optional.hpp>
namespace io {
namespace swagger {
namespace client {
namespace api {

using namespace io::swagger::client::model;

class  WordsApi
{
public:
    ///<summary>
    ///Accept all revisions in document
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    pplx::task<std::shared_ptr<RevisionsModificationResponse>> acceptAllRevisions(
        std::shared_ptr<AcceptAllRevisionsRequest> request
        );
    ///<summary>
    ///Classify raw text.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="text">Text to classify.</param>
    /// <param name="bestClassesCount">Count of the best classes to return. (optional, default to 1)</param>
    pplx::task<std::shared_ptr<ClassificationResponse>> classify(
        std::shared_ptr<ClassifyRequest> request
        );
    ///<summary>
    ///Classify document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="documentName">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="bestClassesCount">Count of the best classes to return. (optional, default to 1)</param>
    /// <param name="taxonomy">Taxonomy to use for classification return. (optional, default to default)</param>
    pplx::task<std::shared_ptr<ClassificationResponse>> classifyDocument(
        std::shared_ptr<ClassifyDocumentRequest> request
        );
    ///<summary>
    ///Add new or update existing document property.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="propertyName">The property name.</param>
    /// <param name="property">The property with new value.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<DocumentPropertyResponse>> createOrUpdateDocumentProperty(
        std::shared_ptr<CreateOrUpdateDocumentPropertyRequest> request
        );
    ///<summary>
    ///Resets border properties to default values.             
    ///</summary>
    ///<remarks>
    ///&#39;nodePath&#39; should refer to node with cell or row
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="nodePath">Path to node with border(node should be cell or row).</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<BorderResponse>> deleteBorder(
        std::shared_ptr<DeleteBorderRequest> request
        );
    ///<summary>
    ///Resets borders properties to default values.             
    ///</summary>
    ///<remarks>
    ///&#39;nodePath&#39; should refer to node with cell or row
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="nodePath">Path to node with borders(node should be cell or row).</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<BordersResponse>> deleteBorders(
        std::shared_ptr<DeleteBordersRequest> request
        );
    ///<summary>
    ///Remove comment from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The file name.</param>
    /// <param name="commentIndex">Comment index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<AsposeResponse>> deleteComment(
        std::shared_ptr<DeleteCommentRequest> request
        );
    ///<summary>
    ///Remove macros from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The file name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<AsposeResponse>> deleteDocumentMacros(
        std::shared_ptr<DeleteDocumentMacrosRequest> request
        );
    ///<summary>
    ///Delete document property.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="propertyName">The property name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<AsposeResponse>> deleteDocumentProperty(
        std::shared_ptr<DeleteDocumentPropertyRequest> request
        );
    ///<summary>
    ///Delete watermark (for deleting last watermark from the document).
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<DocumentResponse>> deleteDocumentWatermark(
        std::shared_ptr<DeleteDocumentWatermarkRequest> request
        );
    ///<summary>
    ///Removes drawing object from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The file name.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="nodePath">Path to node, which contains collection of drawing objects. (optional)</param>
    pplx::task<std::shared_ptr<AsposeResponse>> deleteDrawingObject(
        std::shared_ptr<DeleteDrawingObjectRequest> request
        );
    ///<summary>
    ///Delete field from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The file name.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="nodePath">Path to node, which contains collection of fields. (optional)</param>
    pplx::task<std::shared_ptr<AsposeResponse>> deleteField(
        std::shared_ptr<DeleteFieldRequest> request
        );
    ///<summary>
    ///Remove fields from section paragraph.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The file name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="nodePath">Path to node, which contains collection of fields. (optional)</param>
    pplx::task<std::shared_ptr<AsposeResponse>> deleteFields(
        std::shared_ptr<DeleteFieldsRequest> request
        );
    ///<summary>
    ///Removes footnote from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The file name.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="nodePath">Path to node, which contains collection of footnotes. (optional)</param>
    pplx::task<std::shared_ptr<AsposeResponse>> deleteFootnote(
        std::shared_ptr<DeleteFootnoteRequest> request
        );
    ///<summary>
    ///Removes form field from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="nodePath">Path to node that contains collection of formfields. (optional)</param>
    pplx::task<std::shared_ptr<AsposeResponse>> deleteFormField(
        std::shared_ptr<DeleteFormFieldRequest> request
        );
    ///<summary>
    ///Delete header/footer from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="sectionPath">Path to parent section. (optional)</param>
    pplx::task<std::shared_ptr<AsposeResponse>> deleteHeaderFooter(
        std::shared_ptr<DeleteHeaderFooterRequest> request
        );
    ///<summary>
    ///Delete document headers and footers.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="sectionPath">Path to parent section. (optional)</param>
    /// <param name="headersFootersTypes">List of types of headers and footers. (optional)</param>
    pplx::task<std::shared_ptr<AsposeResponse>> deleteHeadersFooters(
        std::shared_ptr<DeleteHeadersFootersRequest> request
        );
    ///<summary>
    ///Removes OfficeMath object from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The file name.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="nodePath">Path to node, which contains collection of OfficeMath objects. (optional)</param>
    pplx::task<std::shared_ptr<AsposeResponse>> deleteOfficeMathObject(
        std::shared_ptr<DeleteOfficeMathObjectRequest> request
        );
    ///<summary>
    ///Remove paragraph from section.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The file name.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="nodePath">Path to node which contains paragraphs. (optional)</param>
    pplx::task<std::shared_ptr<AsposeResponse>> deleteParagraph(
        std::shared_ptr<DeleteParagraphRequest> request
        );
    ///<summary>
    ///Removes run from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The file name.</param>
    /// <param name="paragraphPath">Path to parent paragraph.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<AsposeResponse>> deleteRun(
        std::shared_ptr<DeleteRunRequest> request
        );
    ///<summary>
    ///Delete a table.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="nodePath">Path to node, which contains tables. (optional)</param>
    pplx::task<std::shared_ptr<AsposeResponse>> deleteTable(
        std::shared_ptr<DeleteTableRequest> request
        );
    ///<summary>
    ///Delete a table cell.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="tableRowPath">Path to table row.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<AsposeResponse>> deleteTableCell(
        std::shared_ptr<DeleteTableCellRequest> request
        );
    ///<summary>
    ///Delete a table row.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="tablePath">Path to table.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<AsposeResponse>> deleteTableRow(
        std::shared_ptr<DeleteTableRowRequest> request
        );
    ///<summary>
    ///Unprotect document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="protectionRequest">with protection settings.            </param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    pplx::task<std::shared_ptr<ProtectionDataResponse>> deleteUnprotectDocument(
        std::shared_ptr<DeleteUnprotectDocumentRequest> request
        );
    ///<summary>
    ///Gets the list of fonts, available for document processing
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    pplx::task<std::shared_ptr<AvailableFontsResponse>> getAvailableFonts(
        std::shared_ptr<GetAvailableFontsRequest> request
        );
    ///<summary>
    ///Return a border.
    ///</summary>
    ///<remarks>
    ///&#39;nodePath&#39; should refer to node with cell or row
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="nodePath">Path to node with border(node should be cell or row).</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<std::shared_ptr<BorderResponse>> getBorder(
        std::shared_ptr<GetBorderRequest> request
        );
    ///<summary>
    ///Return a collection of borders.
    ///</summary>
    ///<remarks>
    ///&#39;nodePath&#39; should refer to node with cell or row
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="nodePath">Path to node with borders(node should be cell or row).</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<std::shared_ptr<BordersResponse>> getBorders(
        std::shared_ptr<GetBordersRequest> request
        );
    ///<summary>
    ///Get comment from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The file name.</param>
    /// <param name="commentIndex">Comment index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<std::shared_ptr<CommentResponse>> getComment(
        std::shared_ptr<GetCommentRequest> request
        );
    ///<summary>
    ///Get comments from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The file name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<std::shared_ptr<CommentsResponse>> getComments(
        std::shared_ptr<GetCommentsRequest> request
        );
    ///<summary>
    ///Read document common info.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="documentName">The file name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<std::shared_ptr<DocumentResponse>> getDocument(
        std::shared_ptr<GetDocumentRequest> request
        );
    ///<summary>
    ///Read document bookmark data by its name.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="bookmarkName">The bookmark name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<std::shared_ptr<BookmarkResponse>> getDocumentBookmarkByName(
        std::shared_ptr<GetDocumentBookmarkByNameRequest> request
        );
    ///<summary>
    ///Read document bookmarks common info.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<std::shared_ptr<BookmarksResponse>> getDocumentBookmarks(
        std::shared_ptr<GetDocumentBookmarksRequest> request
        );
    ///<summary>
    ///Read document drawing object common info by its index or convert to format specified.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="nodePath">Path to node, which contains collection of drawing objects. (optional)</param>
    pplx::task<std::shared_ptr<DrawingObjectResponse>> getDocumentDrawingObjectByIndex(
        std::shared_ptr<GetDocumentDrawingObjectByIndexRequest> request
        );
    ///<summary>
    ///Read drawing object image data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="nodePath">Path to node, which contains collection of drawing objects. (optional)</param>
    pplx::task<HttpContent> getDocumentDrawingObjectImageData(
        std::shared_ptr<GetDocumentDrawingObjectImageDataRequest> request
        );
    ///<summary>
    ///Get drawing object OLE data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="nodePath">Path to node, which contains collection of drawing objects. (optional)</param>
    pplx::task<HttpContent> getDocumentDrawingObjectOleData(
        std::shared_ptr<GetDocumentDrawingObjectOleDataRequest> request
        );
    ///<summary>
    ///Read document drawing objects common info.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="nodePath">Path to node, which contains collection of drawing objects. (optional)</param>
    pplx::task<std::shared_ptr<DrawingObjectsResponse>> getDocumentDrawingObjects(
        std::shared_ptr<GetDocumentDrawingObjectsRequest> request
        );
    ///<summary>
    ///Read document field names.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="useNonMergeFields">If true, result includes \&quot;mustache\&quot; field names. (optional, default to false)</param>
    pplx::task<std::shared_ptr<FieldNamesResponse>> getDocumentFieldNames(
        std::shared_ptr<GetDocumentFieldNamesRequest> request
        );
    ///<summary>
    ///Read document hyperlink by its index.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="hyperlinkIndex">The hyperlink index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<std::shared_ptr<HyperlinkResponse>> getDocumentHyperlinkByIndex(
        std::shared_ptr<GetDocumentHyperlinkByIndexRequest> request
        );
    ///<summary>
    ///Read document hyperlinks common info.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<std::shared_ptr<HyperlinksResponse>> getDocumentHyperlinks(
        std::shared_ptr<GetDocumentHyperlinksRequest> request
        );
    ///<summary>
    ///This resource represents one of the paragraphs contained in the document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="nodePath">Path to node which contains paragraphs. (optional)</param>
    pplx::task<std::shared_ptr<ParagraphResponse>> getDocumentParagraph(
        std::shared_ptr<GetDocumentParagraphRequest> request
        );
    ///<summary>
    ///Represents all the formatting for a paragraph.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="nodePath">Path to node which contains paragraphs. (optional)</param>
    pplx::task<std::shared_ptr<ParagraphFormatResponse>> getDocumentParagraphFormat(
        std::shared_ptr<GetDocumentParagraphFormatRequest> request
        );
    ///<summary>
    ///This resource represents run of text contained in the document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="paragraphPath">Path to parent paragraph.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<std::shared_ptr<RunResponse>> getDocumentParagraphRun(
        std::shared_ptr<GetDocumentParagraphRunRequest> request
        );
    ///<summary>
    ///This resource represents font of run.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="paragraphPath">Path to parent paragraph.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<std::shared_ptr<FontResponse>> getDocumentParagraphRunFont(
        std::shared_ptr<GetDocumentParagraphRunFontRequest> request
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
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<std::shared_ptr<RunsResponse>> getDocumentParagraphRuns(
        std::shared_ptr<GetDocumentParagraphRunsRequest> request
        );
    ///<summary>
    ///Return a list of paragraphs that are contained in the document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="nodePath">Path to node which contains paragraphs. (optional)</param>
    pplx::task<std::shared_ptr<ParagraphLinkCollectionResponse>> getDocumentParagraphs(
        std::shared_ptr<GetDocumentParagraphsRequest> request
        );
    ///<summary>
    ///Read document properties info.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document&#39;s name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<std::shared_ptr<DocumentPropertiesResponse>> getDocumentProperties(
        std::shared_ptr<GetDocumentPropertiesRequest> request
        );
    ///<summary>
    ///Read document property info by the property name.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="propertyName">The property name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<std::shared_ptr<DocumentPropertyResponse>> getDocumentProperty(
        std::shared_ptr<GetDocumentPropertyRequest> request
        );
    ///<summary>
    ///Read document protection common info.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<std::shared_ptr<ProtectionDataResponse>> getDocumentProtection(
        std::shared_ptr<GetDocumentProtectionRequest> request
        );
    ///<summary>
    ///Read document statistics.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="includeComments">Support including/excluding comments from the WordCount. Default value is \&quot;true\&quot;. (optional, default to false)</param>
    /// <param name="includeFootnotes">Support including/excluding footnotes from the WordCount. Default value is \&quot;false\&quot;. (optional, default to false)</param>
    /// <param name="includeTextInShapes">Support including/excluding shape&#39;s text from the WordCount. Default value is \&quot;false\&quot; (optional, default to false)</param>
    pplx::task<std::shared_ptr<StatDataResponse>> getDocumentStatistics(
        std::shared_ptr<GetDocumentStatisticsRequest> request
        );
    ///<summary>
    ///Read document text items.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<std::shared_ptr<TextItemsResponse>> getDocumentTextItems(
        std::shared_ptr<GetDocumentTextItemsRequest> request
        );
    ///<summary>
    ///Export the document into the specified format.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The file name.</param>
    /// <param name="format">The destination format.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="outPath">Path to save result (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    pplx::task<HttpContent> getDocumentWithFormat(
        std::shared_ptr<GetDocumentWithFormatRequest> request
        );
    ///<summary>
    ///Get field from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The file name.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="nodePath">Path to node, which contains collection of fields. (optional)</param>
    pplx::task<std::shared_ptr<FieldResponse>> getField(
        std::shared_ptr<GetFieldRequest> request
        );
    ///<summary>
    ///Get fields from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The file name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="nodePath">Path to node, which contains collection of fields. (optional)</param>
    pplx::task<std::shared_ptr<FieldsResponse>> getFields(
        std::shared_ptr<GetFieldsRequest> request
        );
    ///<summary>
    ///Read footnote by index.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="nodePath">Path to node, which contains collection of footnotes. (optional)</param>
    pplx::task<std::shared_ptr<FootnoteResponse>> getFootnote(
        std::shared_ptr<GetFootnoteRequest> request
        );
    ///<summary>
    ///Get footnotes from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The file name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="nodePath">Path to node, which contains collection of footnotes. (optional)</param>
    pplx::task<std::shared_ptr<FootnotesResponse>> getFootnotes(
        std::shared_ptr<GetFootnotesRequest> request
        );
    ///<summary>
    ///Returns representation of an one of the form field.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="nodePath">Path to node that contains collection of formfields. (optional)</param>
    pplx::task<std::shared_ptr<FormFieldResponse>> getFormField(
        std::shared_ptr<GetFormFieldRequest> request
        );
    ///<summary>
    ///Get form fields from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The file name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="nodePath">Path to node containing collection of form fields. (optional)</param>
    pplx::task<std::shared_ptr<FormFieldsResponse>> getFormFields(
        std::shared_ptr<GetFormFieldsRequest> request
        );
    ///<summary>
    ///Return a header/footer that is contained in the document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="headerFooterIndex">Header/footer index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="filterByType">List of types of headers and footers. (optional)</param>
    pplx::task<std::shared_ptr<HeaderFooterResponse>> getHeaderFooter(
        std::shared_ptr<GetHeaderFooterRequest> request
        );
    ///<summary>
    ///Return a header/footer that is contained in the document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="headerFooterIndex">Header/footer index.</param>
    /// <param name="sectionIndex">Section index.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="filterByType">List of types of headers and footers. (optional)</param>
    pplx::task<std::shared_ptr<HeaderFooterResponse>> getHeaderFooterOfSection(
        std::shared_ptr<GetHeaderFooterOfSectionRequest> request
        );
    ///<summary>
    ///Return a list of header/footers that are contained in the document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="sectionPath">Path to parent section. (optional)</param>
    /// <param name="filterByType">List of types of headers and footers. (optional)</param>
    pplx::task<std::shared_ptr<HeaderFootersResponse>> getHeaderFooters(
        std::shared_ptr<GetHeaderFootersRequest> request
        );
    ///<summary>
    ///Read OfficeMath object by index.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="nodePath">Path to node, which contains collection of OfficeMath objects. (optional)</param>
    pplx::task<std::shared_ptr<OfficeMathObjectResponse>> getOfficeMathObject(
        std::shared_ptr<GetOfficeMathObjectRequest> request
        );
    ///<summary>
    ///Get OfficeMath objects from document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The file name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="nodePath">Path to node, which contains collection of OfficeMath objects. (optional)</param>
    pplx::task<std::shared_ptr<OfficeMathObjectsResponse>> getOfficeMathObjects(
        std::shared_ptr<GetOfficeMathObjectsRequest> request
        );
    ///<summary>
    ///Get document section by index.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="sectionIndex">Section index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<std::shared_ptr<SectionResponse>> getSection(
        std::shared_ptr<GetSectionRequest> request
        );
    ///<summary>
    ///Get page setup of section.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="sectionIndex">Section index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<std::shared_ptr<SectionPageSetupResponse>> getSectionPageSetup(
        std::shared_ptr<GetSectionPageSetupRequest> request
        );
    ///<summary>
    ///Return a list of sections that are contained in the document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<std::shared_ptr<SectionLinkCollectionResponse>> getSections(
        std::shared_ptr<GetSectionsRequest> request
        );
    ///<summary>
    ///Return a table.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="nodePath">Path to node, which contains tables. (optional)</param>
    pplx::task<std::shared_ptr<TableResponse>> getTable(
        std::shared_ptr<GetTableRequest> request
        );
    ///<summary>
    ///Return a table cell.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="tableRowPath">Path to table row.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<std::shared_ptr<TableCellResponse>> getTableCell(
        std::shared_ptr<GetTableCellRequest> request
        );
    ///<summary>
    ///Return a table cell format.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="tableRowPath">Path to table row.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<std::shared_ptr<TableCellFormatResponse>> getTableCellFormat(
        std::shared_ptr<GetTableCellFormatRequest> request
        );
    ///<summary>
    ///Return a table properties.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="nodePath">Path to node, which contains tables. (optional)</param>
    pplx::task<std::shared_ptr<TablePropertiesResponse>> getTableProperties(
        std::shared_ptr<GetTablePropertiesRequest> request
        );
    ///<summary>
    ///Return a table row.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="tablePath">Path to table.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<std::shared_ptr<TableRowResponse>> getTableRow(
        std::shared_ptr<GetTableRowRequest> request
        );
    ///<summary>
    ///Return a table row format.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="tablePath">Path to table.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<std::shared_ptr<TableRowFormatResponse>> getTableRowFormat(
        std::shared_ptr<GetTableRowFormatRequest> request
        );
    ///<summary>
    ///Return a list of tables that are contained in the document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="nodePath">Path to node, which contains tables. (optional)</param>
    pplx::task<std::shared_ptr<TableLinkCollectionResponse>> getTables(
        std::shared_ptr<GetTablesRequest> request
        );
    ///<summary>
    ///Adds table to document, returns added table&#39;s data.             
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="table">Table parameters/ (optional)</param>
    /// <param name="nodePath">Path to node, which contains tables. (optional)</param>
    pplx::task<std::shared_ptr<TableResponse>> insertTable(
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
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="cell">Table cell parameters/ (optional)</param>
    pplx::task<std::shared_ptr<TableCellResponse>> insertTableCell(
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
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="row">Table row parameters/ (optional)</param>
    pplx::task<std::shared_ptr<TableRowResponse>> insertTableRow(
        std::shared_ptr<InsertTableRowRequest> request
        );
    ///<summary>
    ///Append documents to original document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">Original document name.</param>
    /// <param name="documentList">with a list of documents to append.            </param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<DocumentResponse>> postAppendDocument(
        std::shared_ptr<PostAppendDocumentRequest> request
        );
    ///<summary>
    ///Change document protection.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="protectionRequest">with protection settings.            </param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    pplx::task<std::shared_ptr<ProtectionDataResponse>> postChangeDocumentProtection(
        std::shared_ptr<PostChangeDocumentProtectionRequest> request
        );
    ///<summary>
    ///Updates the comment, returns updated comment&#39;s data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="commentIndex">Comment index</param>
    /// <param name="comment">Comment data.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<CommentResponse>> postComment(
        std::shared_ptr<PostCommentRequest> request
        );
    ///<summary>
    ///Compare document with original document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">Original document name.</param>
    /// <param name="compareData">with a document to compare.            </param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    pplx::task<std::shared_ptr<DocumentResponse>> postCompareDocument(
        std::shared_ptr<PostCompareDocumentRequest> request
        );
    ///<summary>
    ///Execute document mail merge operation.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="data">Mail merge data (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="withRegions">With regions flag. (optional, default to false)</param>
    /// <param name="mailMergeDataFile">Mail merge data. (optional)</param>
    /// <param name="cleanup">Clean up options. (optional)</param>
    /// <param name="useWholeParagraphAsRegion">Gets or sets a value indicating whether paragraph with TableStart or              TableEnd field should be fully included into mail merge region or particular range between TableStart and TableEnd fields.              The default value is true. (optional, default to true)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved with autogenerated name. (optional)</param>
    pplx::task<std::shared_ptr<DocumentResponse>> postDocumentExecuteMailMerge(
        std::shared_ptr<PostDocumentExecuteMailMergeRequest> request
        );
    ///<summary>
    ///Updates paragrpaph format properties, returns updated format properties.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="dto">Paragraph format object</param>
    /// <param name="nodePath">Path to node which contains paragraphs.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<ParagraphFormatResponse>> postDocumentParagraphFormat(
        std::shared_ptr<PostDocumentParagraphFormatRequest> request
        );
    ///<summary>
    ///Updates font properties, returns updated font data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="fontDto">Font dto object</param>
    /// <param name="paragraphPath">Path to parent paragraph.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<FontResponse>> postDocumentParagraphRunFont(
        std::shared_ptr<PostDocumentParagraphRunFontRequest> request
        );
    ///<summary>
    ///Convert document to destination format with detailed settings and save result to storage.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="saveOptionsData">Save options.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    pplx::task<std::shared_ptr<SaveResponse>> postDocumentSaveAs(
        std::shared_ptr<PostDocumentSaveAsRequest> request
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
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="nodePath">Path to node, which contains collection of drawing objects. (optional)</param>
    pplx::task<std::shared_ptr<DrawingObjectResponse>> postDrawingObject(
        std::shared_ptr<PostDrawingObjectRequest> request
        );
    ///<summary>
    ///Populate document template with data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The template document name.</param>
    /// <param name="data">Mail merge data</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="cleanup">Clean up options. (optional)</param>
    /// <param name="useWholeParagraphAsRegion">Gets or sets a value indicating whether paragraph with TableStart or  TableEnd field should be fully included into mail merge region or particular range between TableStart and TableEnd fields.   The default value is true. (optional, default to true)</param>
    /// <param name="withRegions">Merge with regions or not. True by default (optional, default to true)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved with autogenerated name. (optional)</param>
    pplx::task<std::shared_ptr<DocumentResponse>> postExecuteTemplate(
        std::shared_ptr<PostExecuteTemplateRequest> request
        );
    ///<summary>
    ///Updates field&#39;s properties, returns updated field&#39;s data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="field">Field data.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="nodePath">Path to node, which contains collection of fields. (optional)</param>
    pplx::task<std::shared_ptr<FieldResponse>> postField(
        std::shared_ptr<PostFieldRequest> request
        );
    ///<summary>
    ///Updates footnote&#39;s properties, returns updated run&#39;s data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="footnoteDto">Footnote data.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="nodePath">Path to node, which contains collection of footnotes. (optional)</param>
    pplx::task<std::shared_ptr<FootnoteResponse>> postFootnote(
        std::shared_ptr<PostFootnoteRequest> request
        );
    ///<summary>
    ///Updates properties of form field, returns updated form field.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="formField">From field data.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="nodePath">Path to node that contains collection of formfields. (optional)</param>
    pplx::task<std::shared_ptr<FormFieldResponse>> postFormField(
        std::shared_ptr<PostFormFieldRequest> request
        );
    ///<summary>
    ///Insert document watermark image.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="imageFile">File with image (optional)</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="rotationAngle">The watermark rotation angle. (optional, default to 0.0)</param>
    /// <param name="image">The image file server full name. If the name is empty the image is expected in request content. (optional)</param>
    pplx::task<std::shared_ptr<DocumentResponse>> postInsertDocumentWatermarkImage(
        std::shared_ptr<PostInsertDocumentWatermarkImageRequest> request
        );
    ///<summary>
    ///Insert document watermark text.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="watermarkText">with the watermark data.            </param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<DocumentResponse>> postInsertDocumentWatermarkText(
        std::shared_ptr<PostInsertDocumentWatermarkTextRequest> request
        );
    ///<summary>
    ///Insert document page numbers.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">A document name.</param>
    /// <param name="pageNumber">with the page numbers settings.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<DocumentResponse>> postInsertPageNumbers(
        std::shared_ptr<PostInsertPageNumbersRequest> request
        );
    ///<summary>
    ///Loads new document from web into the file with any supported format of data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="data">Parameters of loading.</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    pplx::task<std::shared_ptr<SaveResponse>> postLoadWebDocument(
        std::shared_ptr<PostLoadWebDocumentRequest> request
        );
    ///<summary>
    ///Replace document text.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="replaceText">with the replace operation settings.            </param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<ReplaceTextResponse>> postReplaceText(
        std::shared_ptr<PostReplaceTextRequest> request
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
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<RunResponse>> postRun(
        std::shared_ptr<PostRunRequest> request
        );
    ///<summary>
    ///Split document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">Original document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="format">Format to split. (optional)</param>
    /// <param name="from">Start page. (optional)</param>
    /// <param name="to">End page. (optional)</param>
    /// <param name="zipOutput">ZipOutput or not. (optional, default to false)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    pplx::task<std::shared_ptr<SplitDocumentResponse>> postSplitDocument(
        std::shared_ptr<PostSplitDocumentRequest> request
        );
    ///<summary>
    ///Update document bookmark.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="bookmarkData">with new bookmark data.            </param>
    /// <param name="bookmarkName">The bookmark name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<BookmarkResponse>> postUpdateDocumentBookmark(
        std::shared_ptr<PostUpdateDocumentBookmarkRequest> request
        );
    ///<summary>
    ///Update (reevaluate) fields in document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    pplx::task<std::shared_ptr<DocumentResponse>> postUpdateDocumentFields(
        std::shared_ptr<PostUpdateDocumentFieldsRequest> request
        );
    ///<summary>
    ///Adds comment to document, returns inserted comment&#39;s data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="comment">Comment data.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<CommentResponse>> putComment(
        std::shared_ptr<PutCommentRequest> request
        );
    ///<summary>
    ///Convert document from request content to format specified.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="document">Converting document</param>
    /// <param name="format">Format to convert.</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="outPath">Path for saving operation result to the local storage. (optional)</param>
    /// <param name="documentFileName">This file name will be used when resulting document has dynamic field for document file name {filename}. If it is not setted, \&quot;sourceFilename\&quot; will be used instead.  (optional, default to sourceFilename)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    pplx::task<HttpContent> putConvertDocument(
        std::shared_ptr<PutConvertDocumentRequest> request
        );
    ///<summary>
    ///Creates new document. Document is created with format which is recognized from file extensions.  Supported extentions: \&quot;.doc\&quot;, \&quot;.docx\&quot;, \&quot;.docm\&quot;, \&quot;.dot\&quot;, \&quot;.dotm\&quot;, \&quot;.dotx\&quot;, \&quot;.flatopc\&quot;, \&quot;.fopc\&quot;, \&quot;.flatopc_macro\&quot;, \&quot;.fopc_macro\&quot;, \&quot;.flatopc_template\&quot;, \&quot;.fopc_template\&quot;, \&quot;.flatopc_template_macro\&quot;, \&quot;.fopc_template_macro\&quot;, \&quot;.wordml\&quot;, \&quot;.wml\&quot;, \&quot;.rtf\&quot;
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="fileName">The file name. (optional)</param>
    /// <param name="folder">The document folder. (optional)</param>
    pplx::task<std::shared_ptr<DocumentResponse>> putCreateDocument(
        std::shared_ptr<PutCreateDocumentRequest> request
        );
    ///<summary>
    ///Read document field names.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="_template">File with template</param>
    /// <param name="useNonMergeFields">Use non merge fields or not. (optional, default to false)</param>
    pplx::task<std::shared_ptr<FieldNamesResponse>> putDocumentFieldNames(
        std::shared_ptr<PutDocumentFieldNamesRequest> request
        );
    ///<summary>
    ///Convert document to tiff with detailed settings and save result to storage.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="saveOptions">Tiff save options.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="resultFile">The resulting file name. (optional)</param>
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
    pplx::task<std::shared_ptr<SaveResponse>> putDocumentSaveAsTiff(
        std::shared_ptr<PutDocumentSaveAsTiffRequest> request
        );
    ///<summary>
    ///Adds  drawing object to document, returns added  drawing object&#39;s data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="drawingObject">Drawing object parameters</param>
    /// <param name="imageFile">File with image</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="nodePath">Path to node, which contains collection of drawing objects. (optional)</param>
    pplx::task<std::shared_ptr<DrawingObjectResponse>> putDrawingObject(
        std::shared_ptr<PutDrawingObjectRequest> request
        );
    ///<summary>
    ///Execute document mail merge online.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="_template">File with template</param>
    /// <param name="data">File with mailmerge data</param>
    /// <param name="withRegions">With regions flag. (optional, default to false)</param>
    /// <param name="cleanup">Clean up options. (optional)</param>
    /// <param name="documentFileName">This file name will be used when resulting document has dynamic field for document file name {filename}. If it is not setted, \&quot;template\&quot; will be used instead.  (optional, default to template)</param>
    pplx::task<HttpContent> putExecuteMailMergeOnline(
        std::shared_ptr<PutExecuteMailMergeOnlineRequest> request
        );
    ///<summary>
    ///Populate document template with data online.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="_template">File with template</param>
    /// <param name="data">File with mailmerge data</param>
    /// <param name="cleanup">Clean up options. (optional)</param>
    /// <param name="useWholeParagraphAsRegion">Gets or sets a value indicating whether paragraph with TableStart or              TableEnd field should be fully included into mail merge region or particular range between TableStart and TableEnd fields.              The default value is true. (optional, default to true)</param>
    /// <param name="withRegions">Merge with regions or not. True by default (optional, default to true)</param>
    /// <param name="documentFileName">This file name will be used when resulting document has dynamic field for document file name {filename}.  If it is not setted, \&quot;template\&quot; will be used instead.  Note: if withRegions &#x3D;&#x3D; true executeTemplate updates fields only inside regions (optional, default to template)</param>
    pplx::task<HttpContent> putExecuteTemplateOnline(
        std::shared_ptr<PutExecuteTemplateOnlineRequest> request
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
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="nodePath">Path to node, which contains collection of fields. (optional)</param>
    /// <param name="insertBeforeNode">Field will be inserted before node with id&#x3D;\&quot;nodeId\&quot;. (optional)</param>
    pplx::task<std::shared_ptr<FieldResponse>> putField(
        std::shared_ptr<PutFieldRequest> request
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
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="nodePath">Path to node, which contains collection of footnotes. (optional)</param>
    pplx::task<std::shared_ptr<FootnoteResponse>> putFootnote(
        std::shared_ptr<PutFootnoteRequest> request
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
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="nodePath">Path to node that contains collection of formfields. (optional)</param>
    /// <param name="insertBeforeNode">Form field will be inserted before node with index. (optional)</param>
    pplx::task<std::shared_ptr<FormFieldResponse>> putFormField(
        std::shared_ptr<PutFormFieldRequest> request
        );
    ///<summary>
    ///Insert to document header or footer.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="headerFooterType">Type of header/footer.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="sectionPath">Path to parent section. (optional)</param>
    pplx::task<std::shared_ptr<HeaderFooterResponse>> putHeaderFooter(
        std::shared_ptr<PutHeaderFooterRequest> request
        );
    ///<summary>
    ///Adds paragraph to document, returns added paragraph&#39;s data.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="paragraph">Paragraph data.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="nodePath">Path to node which contains paragraphs. (optional)</param>
    /// <param name="insertBeforeNode">Paragraph will be inserted before node with index. (optional)</param>
    pplx::task<std::shared_ptr<ParagraphResponse>> putParagraph(
        std::shared_ptr<PutParagraphRequest> request
        );
    ///<summary>
    ///Protect document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="protectionRequest">with protection settings.            </param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    pplx::task<std::shared_ptr<ProtectionDataResponse>> putProtectDocument(
        std::shared_ptr<PutProtectDocumentRequest> request
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
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="insertBeforeNode">Paragraph will be inserted before node with index. (optional)</param>
    pplx::task<std::shared_ptr<RunResponse>> putRun(
        std::shared_ptr<PutRunRequest> request
        );
    ///<summary>
    ///Reject all revisions in document
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    pplx::task<std::shared_ptr<RevisionsModificationResponse>> rejectAllRevisions(
        std::shared_ptr<RejectAllRevisionsRequest> request
        );
    ///<summary>
    ///Renders drawing object to specified format.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The file name.</param>
    /// <param name="format">The destination format.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="nodePath">Path to node, which contains drawing objects. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    pplx::task<HttpContent> renderDrawingObject(
        std::shared_ptr<RenderDrawingObjectRequest> request
        );
    ///<summary>
    ///Renders math object to specified format.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The file name.</param>
    /// <param name="format">The destination format.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="nodePath">Path to node, which contains office math objects. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    pplx::task<HttpContent> renderMathObject(
        std::shared_ptr<RenderMathObjectRequest> request
        );
    ///<summary>
    ///Renders page to specified format.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The file name.</param>
    /// <param name="pageIndex">Comment index</param>
    /// <param name="format">The destination format.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
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
    /// <param name="name">The file name.</param>
    /// <param name="format">The destination format.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="nodePath">Path to node, which contains paragraphs. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    pplx::task<HttpContent> renderParagraph(
        std::shared_ptr<RenderParagraphRequest> request
        );
    ///<summary>
    ///Renders table to specified format.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The file name.</param>
    /// <param name="format">The destination format.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="nodePath">Path to node, which contains tables. (optional)</param>
    /// <param name="fontsLocation">Folder in filestorage with custom fonts. (optional)</param>
    pplx::task<HttpContent> renderTable(
        std::shared_ptr<RenderTableRequest> request
        );
    ///<summary>
    ///Resets font&#39;s cache.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    pplx::task<std::shared_ptr<AsposeResponse>> resetCache(
        std::shared_ptr<ResetCacheRequest> request
        );
    ///<summary>
    ///Search text in document.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="pattern">The regular expression used to find matches.</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    pplx::task<std::shared_ptr<SearchResponse>> search(
        std::shared_ptr<SearchRequest> request
        );
    ///<summary>
    ///Updates border properties.             
    ///</summary>
    ///<remarks>
    ///&#39;nodePath&#39; should refer to node with cell or row
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="borderProperties">Border properties</param>
    /// <param name="nodePath">Path to node with border(node should be cell or row).</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<BorderResponse>> updateBorder(
        std::shared_ptr<UpdateBorderRequest> request
        );
    ///<summary>
    ///Update page setup of section.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="sectionIndex">Section index</param>
    /// <param name="pageSetup">Page setup properties dto</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    pplx::task<std::shared_ptr<SectionPageSetupResponse>> updateSectionPageSetup(
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
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="format">The properties. (optional)</param>
    pplx::task<std::shared_ptr<TableCellFormatResponse>> updateTableCellFormat(
        std::shared_ptr<UpdateTableCellFormatRequest> request
        );
    ///<summary>
    ///Updates a table properties.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="properties">The properties. (optional)</param>
    /// <param name="nodePath">Path to node, which contains tables. (optional)</param>
    pplx::task<std::shared_ptr<TablePropertiesResponse>> updateTableProperties(
        std::shared_ptr<UpdateTablePropertiesRequest> request
        );
    ///<summary>
    ///Updates a table row format.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">The document name.</param>
    /// <param name="tablePath">Path to table.</param>
    /// <param name="index">Object&#39;s index</param>
    /// <param name="folder">Original document folder. (optional)</param>
    /// <param name="storage">File storage, which have to be used. (optional)</param>
    /// <param name="loadEncoding">Encoding that will be used to load an HTML (or TXT) document if the encoding is not specified in HTML. (optional)</param>
    /// <param name="password">Password for opening an encrypted document. (optional)</param>
    /// <param name="destFileName">Result name of the document after the operation. If this parameter is omitted then result of the operation will be saved as the source document. (optional)</param>
    /// <param name="revisionAuthor">Initials of the author to use for revisions.If you set this parameter and then make some changes to the document programmatically, save the document and later open the document in MS Word you will see these changes as revisions. (optional)</param>
    /// <param name="revisionDateTime">The date and time to use for revisions. (optional)</param>
    /// <param name="format">Table row format. (optional)</param>
    pplx::task<std::shared_ptr<TableRowFormatResponse>> updateTableRowFormat(
        std::shared_ptr<UpdateTableRowFormatRequest> request
        );

public:
    WordsApi( std::shared_ptr<ApiClient> apiClient );
    virtual ~WordsApi();
    
protected:
    std::shared_ptr<ApiClient> m_ApiClient;
};

}
}
}
}

#endif /* IO_SWAGGER_CLIENT_API_WordsApi_H_ */


