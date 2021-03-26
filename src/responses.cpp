/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="responses.cpp">
*   Copyright (c) 2021 Aspose.Words for Cloud
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
#include <sstream>
#include "aspose_words_cloud.h"
#include "../thirdparty/json.hpp"

namespace aspose::words::cloud::responses {
    void ResponseModelBase::setStatusCode(int statusCode)
    {
        m_StatusCode = statusCode;
    }

    int ResponseModelBase::getStatusCode() const
    {
        return m_StatusCode;
    }

    void ResponseModelBase::setErrorMessage(const std::wstring& errorMessage)
    {
        m_ErrorMessage = errorMessage;
    }

    const std::wstring& ResponseModelBase::getErrorMessage() const
    {
        return m_ErrorMessage;
    }

    /*
     * AcceptAllRevisions request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::RevisionsModificationResponse > AcceptAllRevisionsResponse::getResult() const
    {
        return m_Result;
    }

    void AcceptAllRevisionsResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::RevisionsModificationResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * AcceptAllRevisionsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::RevisionsModificationResponse > AcceptAllRevisionsOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > AcceptAllRevisionsOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void AcceptAllRevisionsOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * AppendDocument request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > AppendDocumentResponse::getResult() const
    {
        return m_Result;
    }

    void AppendDocumentResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * AppendDocumentOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > AppendDocumentOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > AppendDocumentOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void AppendDocumentOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * ApplyStyleToDocumentElement request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::WordsResponse > ApplyStyleToDocumentElementResponse::getResult() const
    {
        return m_Result;
    }

    void ApplyStyleToDocumentElementResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::WordsResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * ApplyStyleToDocumentElementOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::WordsResponse > ApplyStyleToDocumentElementOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > ApplyStyleToDocumentElementOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void ApplyStyleToDocumentElementOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * BuildReport request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > BuildReportResponse::getResult() const
    {
        return m_Result;
    }

    void BuildReportResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * BuildReportOnline request implementation
     */
    std::shared_ptr< std::istream > BuildReportOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void BuildReportOnlineResponse::deserialize(const std::string& response)
    {
        auto* resultStream = new std::stringstream();
        resultStream->str(response);
        m_Result = std::shared_ptr< std::istream >(resultStream);
    }/*
     * Classify request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ClassificationResponse > ClassifyResponse::getResult() const
    {
        return m_Result;
    }

    void ClassifyResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ClassificationResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * ClassifyDocument request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ClassificationResponse > ClassifyDocumentResponse::getResult() const
    {
        return m_Result;
    }

    void ClassifyDocumentResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ClassificationResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * ClassifyDocumentOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ClassificationResponse > ClassifyDocumentOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void ClassifyDocumentOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ClassificationResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * CompareDocument request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > CompareDocumentResponse::getResult() const
    {
        return m_Result;
    }

    void CompareDocumentResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * CompareDocumentOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > CompareDocumentOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > CompareDocumentOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void CompareDocumentOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * ConvertDocument request implementation
     */
    std::shared_ptr< std::istream > ConvertDocumentResponse::getResult() const
    {
        return m_Result;
    }

    void ConvertDocumentResponse::deserialize(const std::string& response)
    {
        auto* resultStream = new std::stringstream();
        resultStream->str(response);
        m_Result = std::shared_ptr< std::istream >(resultStream);
    }/*
     * CopyFile request implementation
     */

    void CopyFileResponse::deserialize(const std::string& response)
    {
    }/*
     * CopyFolder request implementation
     */

    void CopyFolderResponse::deserialize(const std::string& response)
    {
    }/*
     * CopyStyle request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::StyleResponse > CopyStyleResponse::getResult() const
    {
        return m_Result;
    }

    void CopyStyleResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::StyleResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * CopyStyleOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::StyleResponse > CopyStyleOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > CopyStyleOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void CopyStyleOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * CreateDocument request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > CreateDocumentResponse::getResult() const
    {
        return m_Result;
    }

    void CreateDocumentResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * CreateFolder request implementation
     */

    void CreateFolderResponse::deserialize(const std::string& response)
    {
    }/*
     * CreateOrUpdateDocumentProperty request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentPropertyResponse > CreateOrUpdateDocumentPropertyResponse::getResult() const
    {
        return m_Result;
    }

    void CreateOrUpdateDocumentPropertyResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentPropertyResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * CreateOrUpdateDocumentPropertyOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentPropertyResponse > CreateOrUpdateDocumentPropertyOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > CreateOrUpdateDocumentPropertyOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void CreateOrUpdateDocumentPropertyOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * DeleteAllParagraphTabStops request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TabStopsResponse > DeleteAllParagraphTabStopsResponse::getResult() const
    {
        return m_Result;
    }

    void DeleteAllParagraphTabStopsResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TabStopsResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * DeleteAllParagraphTabStopsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TabStopsResponse > DeleteAllParagraphTabStopsOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > DeleteAllParagraphTabStopsOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteAllParagraphTabStopsOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * DeleteBorder request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BorderResponse > DeleteBorderResponse::getResult() const
    {
        return m_Result;
    }

    void DeleteBorderResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::BorderResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * DeleteBorderOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BorderResponse > DeleteBorderOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > DeleteBorderOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteBorderOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * DeleteBorders request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BordersResponse > DeleteBordersResponse::getResult() const
    {
        return m_Result;
    }

    void DeleteBordersResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::BordersResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * DeleteBordersOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BordersResponse > DeleteBordersOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > DeleteBordersOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteBordersOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * DeleteComment request implementation
     */

    void DeleteCommentResponse::deserialize(const std::string& response)
    {
    }/*
     * DeleteCommentOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteCommentOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteCommentOnlineResponse::deserialize(const std::string& response)
    {
        auto* documentStream = new std::stringstream();
        documentStream->str(response);
        m_Document = std::shared_ptr< std::istream >(documentStream);
    }/*
     * DeleteComments request implementation
     */

    void DeleteCommentsResponse::deserialize(const std::string& response)
    {
    }/*
     * DeleteCommentsOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteCommentsOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteCommentsOnlineResponse::deserialize(const std::string& response)
    {
        auto* documentStream = new std::stringstream();
        documentStream->str(response);
        m_Document = std::shared_ptr< std::istream >(documentStream);
    }/*
     * DeleteDocumentProperty request implementation
     */

    void DeleteDocumentPropertyResponse::deserialize(const std::string& response)
    {
    }/*
     * DeleteDocumentPropertyOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteDocumentPropertyOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteDocumentPropertyOnlineResponse::deserialize(const std::string& response)
    {
        auto* documentStream = new std::stringstream();
        documentStream->str(response);
        m_Document = std::shared_ptr< std::istream >(documentStream);
    }/*
     * DeleteDrawingObject request implementation
     */

    void DeleteDrawingObjectResponse::deserialize(const std::string& response)
    {
    }/*
     * DeleteDrawingObjectOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteDrawingObjectOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteDrawingObjectOnlineResponse::deserialize(const std::string& response)
    {
        auto* documentStream = new std::stringstream();
        documentStream->str(response);
        m_Document = std::shared_ptr< std::istream >(documentStream);
    }/*
     * DeleteField request implementation
     */

    void DeleteFieldResponse::deserialize(const std::string& response)
    {
    }/*
     * DeleteFieldOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteFieldOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteFieldOnlineResponse::deserialize(const std::string& response)
    {
        auto* documentStream = new std::stringstream();
        documentStream->str(response);
        m_Document = std::shared_ptr< std::istream >(documentStream);
    }/*
     * DeleteFields request implementation
     */

    void DeleteFieldsResponse::deserialize(const std::string& response)
    {
    }/*
     * DeleteFieldsOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteFieldsOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteFieldsOnlineResponse::deserialize(const std::string& response)
    {
        auto* documentStream = new std::stringstream();
        documentStream->str(response);
        m_Document = std::shared_ptr< std::istream >(documentStream);
    }/*
     * DeleteFile request implementation
     */

    void DeleteFileResponse::deserialize(const std::string& response)
    {
    }/*
     * DeleteFolder request implementation
     */

    void DeleteFolderResponse::deserialize(const std::string& response)
    {
    }/*
     * DeleteFootnote request implementation
     */

    void DeleteFootnoteResponse::deserialize(const std::string& response)
    {
    }/*
     * DeleteFootnoteOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteFootnoteOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteFootnoteOnlineResponse::deserialize(const std::string& response)
    {
        auto* documentStream = new std::stringstream();
        documentStream->str(response);
        m_Document = std::shared_ptr< std::istream >(documentStream);
    }/*
     * DeleteFormField request implementation
     */

    void DeleteFormFieldResponse::deserialize(const std::string& response)
    {
    }/*
     * DeleteFormFieldOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteFormFieldOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteFormFieldOnlineResponse::deserialize(const std::string& response)
    {
        auto* documentStream = new std::stringstream();
        documentStream->str(response);
        m_Document = std::shared_ptr< std::istream >(documentStream);
    }/*
     * DeleteHeaderFooter request implementation
     */

    void DeleteHeaderFooterResponse::deserialize(const std::string& response)
    {
    }/*
     * DeleteHeaderFooterOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteHeaderFooterOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteHeaderFooterOnlineResponse::deserialize(const std::string& response)
    {
        auto* documentStream = new std::stringstream();
        documentStream->str(response);
        m_Document = std::shared_ptr< std::istream >(documentStream);
    }/*
     * DeleteHeadersFooters request implementation
     */

    void DeleteHeadersFootersResponse::deserialize(const std::string& response)
    {
    }/*
     * DeleteHeadersFootersOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteHeadersFootersOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteHeadersFootersOnlineResponse::deserialize(const std::string& response)
    {
        auto* documentStream = new std::stringstream();
        documentStream->str(response);
        m_Document = std::shared_ptr< std::istream >(documentStream);
    }/*
     * DeleteMacros request implementation
     */

    void DeleteMacrosResponse::deserialize(const std::string& response)
    {
    }/*
     * DeleteMacrosOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteMacrosOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteMacrosOnlineResponse::deserialize(const std::string& response)
    {
        auto* documentStream = new std::stringstream();
        documentStream->str(response);
        m_Document = std::shared_ptr< std::istream >(documentStream);
    }/*
     * DeleteOfficeMathObject request implementation
     */

    void DeleteOfficeMathObjectResponse::deserialize(const std::string& response)
    {
    }/*
     * DeleteOfficeMathObjectOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteOfficeMathObjectOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteOfficeMathObjectOnlineResponse::deserialize(const std::string& response)
    {
        auto* documentStream = new std::stringstream();
        documentStream->str(response);
        m_Document = std::shared_ptr< std::istream >(documentStream);
    }/*
     * DeleteParagraph request implementation
     */

    void DeleteParagraphResponse::deserialize(const std::string& response)
    {
    }/*
     * DeleteParagraphListFormat request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphListFormatResponse > DeleteParagraphListFormatResponse::getResult() const
    {
        return m_Result;
    }

    void DeleteParagraphListFormatResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ParagraphListFormatResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * DeleteParagraphListFormatOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphListFormatResponse > DeleteParagraphListFormatOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > DeleteParagraphListFormatOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteParagraphListFormatOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * DeleteParagraphOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteParagraphOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteParagraphOnlineResponse::deserialize(const std::string& response)
    {
        auto* documentStream = new std::stringstream();
        documentStream->str(response);
        m_Document = std::shared_ptr< std::istream >(documentStream);
    }/*
     * DeleteParagraphTabStop request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TabStopsResponse > DeleteParagraphTabStopResponse::getResult() const
    {
        return m_Result;
    }

    void DeleteParagraphTabStopResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TabStopsResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * DeleteParagraphTabStopOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TabStopsResponse > DeleteParagraphTabStopOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > DeleteParagraphTabStopOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteParagraphTabStopOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * DeleteRun request implementation
     */

    void DeleteRunResponse::deserialize(const std::string& response)
    {
    }/*
     * DeleteRunOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteRunOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteRunOnlineResponse::deserialize(const std::string& response)
    {
        auto* documentStream = new std::stringstream();
        documentStream->str(response);
        m_Document = std::shared_ptr< std::istream >(documentStream);
    }/*
     * DeleteSection request implementation
     */

    void DeleteSectionResponse::deserialize(const std::string& response)
    {
    }/*
     * DeleteSectionOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteSectionOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteSectionOnlineResponse::deserialize(const std::string& response)
    {
        auto* documentStream = new std::stringstream();
        documentStream->str(response);
        m_Document = std::shared_ptr< std::istream >(documentStream);
    }/*
     * DeleteTable request implementation
     */

    void DeleteTableResponse::deserialize(const std::string& response)
    {
    }/*
     * DeleteTableCell request implementation
     */

    void DeleteTableCellResponse::deserialize(const std::string& response)
    {
    }/*
     * DeleteTableCellOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteTableCellOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteTableCellOnlineResponse::deserialize(const std::string& response)
    {
        auto* documentStream = new std::stringstream();
        documentStream->str(response);
        m_Document = std::shared_ptr< std::istream >(documentStream);
    }/*
     * DeleteTableOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteTableOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteTableOnlineResponse::deserialize(const std::string& response)
    {
        auto* documentStream = new std::stringstream();
        documentStream->str(response);
        m_Document = std::shared_ptr< std::istream >(documentStream);
    }/*
     * DeleteTableRow request implementation
     */

    void DeleteTableRowResponse::deserialize(const std::string& response)
    {
    }/*
     * DeleteTableRowOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteTableRowOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteTableRowOnlineResponse::deserialize(const std::string& response)
    {
        auto* documentStream = new std::stringstream();
        documentStream->str(response);
        m_Document = std::shared_ptr< std::istream >(documentStream);
    }/*
     * DeleteWatermark request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > DeleteWatermarkResponse::getResult() const
    {
        return m_Result;
    }

    void DeleteWatermarkResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * DeleteWatermarkOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > DeleteWatermarkOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > DeleteWatermarkOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteWatermarkOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * DownloadFile request implementation
     */
    std::shared_ptr< std::istream > DownloadFileResponse::getResult() const
    {
        return m_Result;
    }

    void DownloadFileResponse::deserialize(const std::string& response)
    {
        auto* resultStream = new std::stringstream();
        resultStream->str(response);
        m_Result = std::shared_ptr< std::istream >(resultStream);
    }/*
     * ExecuteMailMerge request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > ExecuteMailMergeResponse::getResult() const
    {
        return m_Result;
    }

    void ExecuteMailMergeResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * ExecuteMailMergeOnline request implementation
     */
    std::shared_ptr< std::istream > ExecuteMailMergeOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void ExecuteMailMergeOnlineResponse::deserialize(const std::string& response)
    {
        auto* resultStream = new std::stringstream();
        resultStream->str(response);
        m_Result = std::shared_ptr< std::istream >(resultStream);
    }/*
     * GetAvailableFonts request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::AvailableFontsResponse > GetAvailableFontsResponse::getResult() const
    {
        return m_Result;
    }

    void GetAvailableFontsResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::AvailableFontsResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetBookmarkByName request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BookmarkResponse > GetBookmarkByNameResponse::getResult() const
    {
        return m_Result;
    }

    void GetBookmarkByNameResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::BookmarkResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetBookmarkByNameOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BookmarkResponse > GetBookmarkByNameOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetBookmarkByNameOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::BookmarkResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetBookmarks request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BookmarksResponse > GetBookmarksResponse::getResult() const
    {
        return m_Result;
    }

    void GetBookmarksResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::BookmarksResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetBookmarksOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BookmarksResponse > GetBookmarksOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetBookmarksOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::BookmarksResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetBorder request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BorderResponse > GetBorderResponse::getResult() const
    {
        return m_Result;
    }

    void GetBorderResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::BorderResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetBorderOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BorderResponse > GetBorderOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetBorderOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::BorderResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetBorders request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BordersResponse > GetBordersResponse::getResult() const
    {
        return m_Result;
    }

    void GetBordersResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::BordersResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetBordersOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BordersResponse > GetBordersOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetBordersOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::BordersResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetComment request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::CommentResponse > GetCommentResponse::getResult() const
    {
        return m_Result;
    }

    void GetCommentResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::CommentResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetCommentOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::CommentResponse > GetCommentOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetCommentOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::CommentResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetComments request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::CommentsResponse > GetCommentsResponse::getResult() const
    {
        return m_Result;
    }

    void GetCommentsResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::CommentsResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetCommentsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::CommentsResponse > GetCommentsOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetCommentsOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::CommentsResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetDocument request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > GetDocumentResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetDocumentDrawingObjectByIndex request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DrawingObjectResponse > GetDocumentDrawingObjectByIndexResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentDrawingObjectByIndexResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DrawingObjectResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetDocumentDrawingObjectByIndexOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DrawingObjectResponse > GetDocumentDrawingObjectByIndexOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentDrawingObjectByIndexOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DrawingObjectResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetDocumentDrawingObjectImageData request implementation
     */
    std::shared_ptr< std::istream > GetDocumentDrawingObjectImageDataResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentDrawingObjectImageDataResponse::deserialize(const std::string& response)
    {
        auto* resultStream = new std::stringstream();
        resultStream->str(response);
        m_Result = std::shared_ptr< std::istream >(resultStream);
    }/*
     * GetDocumentDrawingObjectImageDataOnline request implementation
     */
    std::shared_ptr< std::istream > GetDocumentDrawingObjectImageDataOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentDrawingObjectImageDataOnlineResponse::deserialize(const std::string& response)
    {
        auto* resultStream = new std::stringstream();
        resultStream->str(response);
        m_Result = std::shared_ptr< std::istream >(resultStream);
    }/*
     * GetDocumentDrawingObjectOleData request implementation
     */
    std::shared_ptr< std::istream > GetDocumentDrawingObjectOleDataResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentDrawingObjectOleDataResponse::deserialize(const std::string& response)
    {
        auto* resultStream = new std::stringstream();
        resultStream->str(response);
        m_Result = std::shared_ptr< std::istream >(resultStream);
    }/*
     * GetDocumentDrawingObjectOleDataOnline request implementation
     */
    std::shared_ptr< std::istream > GetDocumentDrawingObjectOleDataOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentDrawingObjectOleDataOnlineResponse::deserialize(const std::string& response)
    {
        auto* resultStream = new std::stringstream();
        resultStream->str(response);
        m_Result = std::shared_ptr< std::istream >(resultStream);
    }/*
     * GetDocumentDrawingObjects request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DrawingObjectsResponse > GetDocumentDrawingObjectsResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentDrawingObjectsResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DrawingObjectsResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetDocumentDrawingObjectsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DrawingObjectsResponse > GetDocumentDrawingObjectsOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentDrawingObjectsOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DrawingObjectsResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetDocumentFieldNames request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FieldNamesResponse > GetDocumentFieldNamesResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentFieldNamesResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FieldNamesResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetDocumentFieldNamesOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FieldNamesResponse > GetDocumentFieldNamesOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentFieldNamesOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FieldNamesResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetDocumentHyperlinkByIndex request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::HyperlinkResponse > GetDocumentHyperlinkByIndexResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentHyperlinkByIndexResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::HyperlinkResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetDocumentHyperlinkByIndexOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::HyperlinkResponse > GetDocumentHyperlinkByIndexOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentHyperlinkByIndexOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::HyperlinkResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetDocumentHyperlinks request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::HyperlinksResponse > GetDocumentHyperlinksResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentHyperlinksResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::HyperlinksResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetDocumentHyperlinksOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::HyperlinksResponse > GetDocumentHyperlinksOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentHyperlinksOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::HyperlinksResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetDocumentProperties request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentPropertiesResponse > GetDocumentPropertiesResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentPropertiesResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentPropertiesResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetDocumentPropertiesOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentPropertiesResponse > GetDocumentPropertiesOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentPropertiesOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentPropertiesResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetDocumentProperty request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentPropertyResponse > GetDocumentPropertyResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentPropertyResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentPropertyResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetDocumentPropertyOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentPropertyResponse > GetDocumentPropertyOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentPropertyOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentPropertyResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetDocumentProtection request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ProtectionDataResponse > GetDocumentProtectionResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentProtectionResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ProtectionDataResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetDocumentProtectionOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ProtectionDataResponse > GetDocumentProtectionOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentProtectionOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ProtectionDataResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetDocumentStatistics request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::StatDataResponse > GetDocumentStatisticsResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentStatisticsResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::StatDataResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetDocumentStatisticsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::StatDataResponse > GetDocumentStatisticsOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentStatisticsOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::StatDataResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetDocumentWithFormat request implementation
     */
    std::shared_ptr< std::istream > GetDocumentWithFormatResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentWithFormatResponse::deserialize(const std::string& response)
    {
        auto* resultStream = new std::stringstream();
        resultStream->str(response);
        m_Result = std::shared_ptr< std::istream >(resultStream);
    }/*
     * GetField request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FieldResponse > GetFieldResponse::getResult() const
    {
        return m_Result;
    }

    void GetFieldResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FieldResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetFieldOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FieldResponse > GetFieldOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetFieldOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FieldResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetFields request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FieldsResponse > GetFieldsResponse::getResult() const
    {
        return m_Result;
    }

    void GetFieldsResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FieldsResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetFieldsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FieldsResponse > GetFieldsOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetFieldsOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FieldsResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetFilesList request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FilesList > GetFilesListResponse::getResult() const
    {
        return m_Result;
    }

    void GetFilesListResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FilesList >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetFootnote request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FootnoteResponse > GetFootnoteResponse::getResult() const
    {
        return m_Result;
    }

    void GetFootnoteResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FootnoteResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetFootnoteOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FootnoteResponse > GetFootnoteOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetFootnoteOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FootnoteResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetFootnotes request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FootnotesResponse > GetFootnotesResponse::getResult() const
    {
        return m_Result;
    }

    void GetFootnotesResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FootnotesResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetFootnotesOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FootnotesResponse > GetFootnotesOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetFootnotesOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FootnotesResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetFormField request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FormFieldResponse > GetFormFieldResponse::getResult() const
    {
        return m_Result;
    }

    void GetFormFieldResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FormFieldResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetFormFieldOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FormFieldResponse > GetFormFieldOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetFormFieldOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FormFieldResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetFormFields request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FormFieldsResponse > GetFormFieldsResponse::getResult() const
    {
        return m_Result;
    }

    void GetFormFieldsResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FormFieldsResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetFormFieldsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FormFieldsResponse > GetFormFieldsOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetFormFieldsOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FormFieldsResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetHeaderFooter request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::HeaderFooterResponse > GetHeaderFooterResponse::getResult() const
    {
        return m_Result;
    }

    void GetHeaderFooterResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::HeaderFooterResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetHeaderFooterOfSection request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::HeaderFooterResponse > GetHeaderFooterOfSectionResponse::getResult() const
    {
        return m_Result;
    }

    void GetHeaderFooterOfSectionResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::HeaderFooterResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetHeaderFooterOfSectionOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::HeaderFooterResponse > GetHeaderFooterOfSectionOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetHeaderFooterOfSectionOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::HeaderFooterResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetHeaderFooterOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::HeaderFooterResponse > GetHeaderFooterOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetHeaderFooterOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::HeaderFooterResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetHeaderFooters request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::HeaderFootersResponse > GetHeaderFootersResponse::getResult() const
    {
        return m_Result;
    }

    void GetHeaderFootersResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::HeaderFootersResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetHeaderFootersOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::HeaderFootersResponse > GetHeaderFootersOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetHeaderFootersOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::HeaderFootersResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetList request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ListResponse > GetListResponse::getResult() const
    {
        return m_Result;
    }

    void GetListResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ListResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetListOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ListResponse > GetListOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetListOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ListResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetLists request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ListsResponse > GetListsResponse::getResult() const
    {
        return m_Result;
    }

    void GetListsResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ListsResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetListsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ListsResponse > GetListsOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetListsOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ListsResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetOfficeMathObject request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::OfficeMathObjectResponse > GetOfficeMathObjectResponse::getResult() const
    {
        return m_Result;
    }

    void GetOfficeMathObjectResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::OfficeMathObjectResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetOfficeMathObjectOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::OfficeMathObjectResponse > GetOfficeMathObjectOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetOfficeMathObjectOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::OfficeMathObjectResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetOfficeMathObjects request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::OfficeMathObjectsResponse > GetOfficeMathObjectsResponse::getResult() const
    {
        return m_Result;
    }

    void GetOfficeMathObjectsResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::OfficeMathObjectsResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetOfficeMathObjectsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::OfficeMathObjectsResponse > GetOfficeMathObjectsOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetOfficeMathObjectsOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::OfficeMathObjectsResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetParagraph request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphResponse > GetParagraphResponse::getResult() const
    {
        return m_Result;
    }

    void GetParagraphResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ParagraphResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetParagraphFormat request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphFormatResponse > GetParagraphFormatResponse::getResult() const
    {
        return m_Result;
    }

    void GetParagraphFormatResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ParagraphFormatResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetParagraphFormatOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphFormatResponse > GetParagraphFormatOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetParagraphFormatOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ParagraphFormatResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetParagraphListFormat request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphListFormatResponse > GetParagraphListFormatResponse::getResult() const
    {
        return m_Result;
    }

    void GetParagraphListFormatResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ParagraphListFormatResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetParagraphListFormatOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphListFormatResponse > GetParagraphListFormatOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetParagraphListFormatOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ParagraphListFormatResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetParagraphOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphResponse > GetParagraphOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetParagraphOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ParagraphResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetParagraphs request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphLinkCollectionResponse > GetParagraphsResponse::getResult() const
    {
        return m_Result;
    }

    void GetParagraphsResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ParagraphLinkCollectionResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetParagraphsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphLinkCollectionResponse > GetParagraphsOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetParagraphsOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ParagraphLinkCollectionResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetParagraphTabStops request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TabStopsResponse > GetParagraphTabStopsResponse::getResult() const
    {
        return m_Result;
    }

    void GetParagraphTabStopsResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TabStopsResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetParagraphTabStopsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TabStopsResponse > GetParagraphTabStopsOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetParagraphTabStopsOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TabStopsResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetRangeText request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::RangeTextResponse > GetRangeTextResponse::getResult() const
    {
        return m_Result;
    }

    void GetRangeTextResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::RangeTextResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetRangeTextOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::RangeTextResponse > GetRangeTextOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetRangeTextOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::RangeTextResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetRun request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::RunResponse > GetRunResponse::getResult() const
    {
        return m_Result;
    }

    void GetRunResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::RunResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetRunFont request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FontResponse > GetRunFontResponse::getResult() const
    {
        return m_Result;
    }

    void GetRunFontResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FontResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetRunFontOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FontResponse > GetRunFontOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetRunFontOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FontResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetRunOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::RunResponse > GetRunOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetRunOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::RunResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetRuns request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::RunsResponse > GetRunsResponse::getResult() const
    {
        return m_Result;
    }

    void GetRunsResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::RunsResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetRunsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::RunsResponse > GetRunsOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetRunsOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::RunsResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetSection request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SectionResponse > GetSectionResponse::getResult() const
    {
        return m_Result;
    }

    void GetSectionResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::SectionResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetSectionOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SectionResponse > GetSectionOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetSectionOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::SectionResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetSectionPageSetup request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SectionPageSetupResponse > GetSectionPageSetupResponse::getResult() const
    {
        return m_Result;
    }

    void GetSectionPageSetupResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::SectionPageSetupResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetSectionPageSetupOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SectionPageSetupResponse > GetSectionPageSetupOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetSectionPageSetupOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::SectionPageSetupResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetSections request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SectionLinkCollectionResponse > GetSectionsResponse::getResult() const
    {
        return m_Result;
    }

    void GetSectionsResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::SectionLinkCollectionResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetSectionsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SectionLinkCollectionResponse > GetSectionsOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetSectionsOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::SectionLinkCollectionResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetStyle request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::StyleResponse > GetStyleResponse::getResult() const
    {
        return m_Result;
    }

    void GetStyleResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::StyleResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetStyleFromDocumentElement request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::StyleResponse > GetStyleFromDocumentElementResponse::getResult() const
    {
        return m_Result;
    }

    void GetStyleFromDocumentElementResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::StyleResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetStyleFromDocumentElementOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::StyleResponse > GetStyleFromDocumentElementOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetStyleFromDocumentElementOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::StyleResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetStyleOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::StyleResponse > GetStyleOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetStyleOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::StyleResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetStyles request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::StylesResponse > GetStylesResponse::getResult() const
    {
        return m_Result;
    }

    void GetStylesResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::StylesResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetStylesOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::StylesResponse > GetStylesOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetStylesOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::StylesResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetTable request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableResponse > GetTableResponse::getResult() const
    {
        return m_Result;
    }

    void GetTableResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetTableCell request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableCellResponse > GetTableCellResponse::getResult() const
    {
        return m_Result;
    }

    void GetTableCellResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableCellResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetTableCellFormat request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableCellFormatResponse > GetTableCellFormatResponse::getResult() const
    {
        return m_Result;
    }

    void GetTableCellFormatResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableCellFormatResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetTableCellFormatOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableCellFormatResponse > GetTableCellFormatOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetTableCellFormatOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableCellFormatResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetTableCellOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableCellResponse > GetTableCellOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetTableCellOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableCellResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetTableOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableResponse > GetTableOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetTableOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetTableProperties request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TablePropertiesResponse > GetTablePropertiesResponse::getResult() const
    {
        return m_Result;
    }

    void GetTablePropertiesResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TablePropertiesResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetTablePropertiesOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TablePropertiesResponse > GetTablePropertiesOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetTablePropertiesOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TablePropertiesResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetTableRow request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableRowResponse > GetTableRowResponse::getResult() const
    {
        return m_Result;
    }

    void GetTableRowResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableRowResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetTableRowFormat request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableRowFormatResponse > GetTableRowFormatResponse::getResult() const
    {
        return m_Result;
    }

    void GetTableRowFormatResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableRowFormatResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetTableRowFormatOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableRowFormatResponse > GetTableRowFormatOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetTableRowFormatOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableRowFormatResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetTableRowOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableRowResponse > GetTableRowOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetTableRowOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableRowResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetTables request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableLinkCollectionResponse > GetTablesResponse::getResult() const
    {
        return m_Result;
    }

    void GetTablesResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableLinkCollectionResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * GetTablesOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableLinkCollectionResponse > GetTablesOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetTablesOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableLinkCollectionResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * InsertComment request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::CommentResponse > InsertCommentResponse::getResult() const
    {
        return m_Result;
    }

    void InsertCommentResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::CommentResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * InsertCommentOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::CommentResponse > InsertCommentOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > InsertCommentOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void InsertCommentOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * InsertDrawingObject request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DrawingObjectResponse > InsertDrawingObjectResponse::getResult() const
    {
        return m_Result;
    }

    void InsertDrawingObjectResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DrawingObjectResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * InsertDrawingObjectOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DrawingObjectResponse > InsertDrawingObjectOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > InsertDrawingObjectOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void InsertDrawingObjectOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * InsertField request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FieldResponse > InsertFieldResponse::getResult() const
    {
        return m_Result;
    }

    void InsertFieldResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FieldResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * InsertFieldOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FieldResponse > InsertFieldOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > InsertFieldOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void InsertFieldOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * InsertFootnote request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FootnoteResponse > InsertFootnoteResponse::getResult() const
    {
        return m_Result;
    }

    void InsertFootnoteResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FootnoteResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * InsertFootnoteOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FootnoteResponse > InsertFootnoteOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > InsertFootnoteOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void InsertFootnoteOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * InsertFormField request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FormFieldResponse > InsertFormFieldResponse::getResult() const
    {
        return m_Result;
    }

    void InsertFormFieldResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FormFieldResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * InsertFormFieldOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FormFieldResponse > InsertFormFieldOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > InsertFormFieldOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void InsertFormFieldOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * InsertHeaderFooter request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::HeaderFooterResponse > InsertHeaderFooterResponse::getResult() const
    {
        return m_Result;
    }

    void InsertHeaderFooterResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::HeaderFooterResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * InsertHeaderFooterOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::HeaderFooterResponse > InsertHeaderFooterOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > InsertHeaderFooterOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void InsertHeaderFooterOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * InsertList request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ListResponse > InsertListResponse::getResult() const
    {
        return m_Result;
    }

    void InsertListResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ListResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * InsertListOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ListResponse > InsertListOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > InsertListOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void InsertListOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * InsertOrUpdateParagraphTabStop request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TabStopsResponse > InsertOrUpdateParagraphTabStopResponse::getResult() const
    {
        return m_Result;
    }

    void InsertOrUpdateParagraphTabStopResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TabStopsResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * InsertOrUpdateParagraphTabStopOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TabStopsResponse > InsertOrUpdateParagraphTabStopOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > InsertOrUpdateParagraphTabStopOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void InsertOrUpdateParagraphTabStopOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * InsertPageNumbers request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > InsertPageNumbersResponse::getResult() const
    {
        return m_Result;
    }

    void InsertPageNumbersResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * InsertPageNumbersOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > InsertPageNumbersOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > InsertPageNumbersOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void InsertPageNumbersOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * InsertParagraph request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphResponse > InsertParagraphResponse::getResult() const
    {
        return m_Result;
    }

    void InsertParagraphResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ParagraphResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * InsertParagraphOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphResponse > InsertParagraphOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > InsertParagraphOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void InsertParagraphOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * InsertRun request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::RunResponse > InsertRunResponse::getResult() const
    {
        return m_Result;
    }

    void InsertRunResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::RunResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * InsertRunOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::RunResponse > InsertRunOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > InsertRunOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void InsertRunOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * InsertStyle request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::StyleResponse > InsertStyleResponse::getResult() const
    {
        return m_Result;
    }

    void InsertStyleResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::StyleResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * InsertStyleOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::StyleResponse > InsertStyleOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > InsertStyleOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void InsertStyleOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * InsertTable request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableResponse > InsertTableResponse::getResult() const
    {
        return m_Result;
    }

    void InsertTableResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * InsertTableCell request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableCellResponse > InsertTableCellResponse::getResult() const
    {
        return m_Result;
    }

    void InsertTableCellResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableCellResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * InsertTableCellOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableCellResponse > InsertTableCellOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > InsertTableCellOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void InsertTableCellOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * InsertTableOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableResponse > InsertTableOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > InsertTableOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void InsertTableOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * InsertTableRow request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableRowResponse > InsertTableRowResponse::getResult() const
    {
        return m_Result;
    }

    void InsertTableRowResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableRowResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * InsertTableRowOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableRowResponse > InsertTableRowOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > InsertTableRowOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void InsertTableRowOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * InsertWatermarkImage request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > InsertWatermarkImageResponse::getResult() const
    {
        return m_Result;
    }

    void InsertWatermarkImageResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * InsertWatermarkImageOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > InsertWatermarkImageOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > InsertWatermarkImageOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void InsertWatermarkImageOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * InsertWatermarkText request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > InsertWatermarkTextResponse::getResult() const
    {
        return m_Result;
    }

    void InsertWatermarkTextResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * InsertWatermarkTextOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > InsertWatermarkTextOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > InsertWatermarkTextOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void InsertWatermarkTextOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * LoadWebDocument request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SaveResponse > LoadWebDocumentResponse::getResult() const
    {
        return m_Result;
    }

    void LoadWebDocumentResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::SaveResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * MoveFile request implementation
     */

    void MoveFileResponse::deserialize(const std::string& response)
    {
    }/*
     * MoveFolder request implementation
     */

    void MoveFolderResponse::deserialize(const std::string& response)
    {
    }/*
     * OptimizeDocument request implementation
     */

    void OptimizeDocumentResponse::deserialize(const std::string& response)
    {
    }/*
     * OptimizeDocumentOnline request implementation
     */
    std::shared_ptr< std::istream > OptimizeDocumentOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void OptimizeDocumentOnlineResponse::deserialize(const std::string& response)
    {
        auto* documentStream = new std::stringstream();
        documentStream->str(response);
        m_Document = std::shared_ptr< std::istream >(documentStream);
    }/*
     * ProtectDocument request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ProtectionDataResponse > ProtectDocumentResponse::getResult() const
    {
        return m_Result;
    }

    void ProtectDocumentResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ProtectionDataResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * ProtectDocumentOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ProtectionDataResponse > ProtectDocumentOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > ProtectDocumentOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void ProtectDocumentOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * RejectAllRevisions request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::RevisionsModificationResponse > RejectAllRevisionsResponse::getResult() const
    {
        return m_Result;
    }

    void RejectAllRevisionsResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::RevisionsModificationResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * RejectAllRevisionsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::RevisionsModificationResponse > RejectAllRevisionsOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > RejectAllRevisionsOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void RejectAllRevisionsOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * RemoveRange request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > RemoveRangeResponse::getResult() const
    {
        return m_Result;
    }

    void RemoveRangeResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * RemoveRangeOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > RemoveRangeOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > RemoveRangeOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void RemoveRangeOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * RenderDrawingObject request implementation
     */
    std::shared_ptr< std::istream > RenderDrawingObjectResponse::getResult() const
    {
        return m_Result;
    }

    void RenderDrawingObjectResponse::deserialize(const std::string& response)
    {
        auto* resultStream = new std::stringstream();
        resultStream->str(response);
        m_Result = std::shared_ptr< std::istream >(resultStream);
    }/*
     * RenderDrawingObjectOnline request implementation
     */
    std::shared_ptr< std::istream > RenderDrawingObjectOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void RenderDrawingObjectOnlineResponse::deserialize(const std::string& response)
    {
        auto* resultStream = new std::stringstream();
        resultStream->str(response);
        m_Result = std::shared_ptr< std::istream >(resultStream);
    }/*
     * RenderMathObject request implementation
     */
    std::shared_ptr< std::istream > RenderMathObjectResponse::getResult() const
    {
        return m_Result;
    }

    void RenderMathObjectResponse::deserialize(const std::string& response)
    {
        auto* resultStream = new std::stringstream();
        resultStream->str(response);
        m_Result = std::shared_ptr< std::istream >(resultStream);
    }/*
     * RenderMathObjectOnline request implementation
     */
    std::shared_ptr< std::istream > RenderMathObjectOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void RenderMathObjectOnlineResponse::deserialize(const std::string& response)
    {
        auto* resultStream = new std::stringstream();
        resultStream->str(response);
        m_Result = std::shared_ptr< std::istream >(resultStream);
    }/*
     * RenderPage request implementation
     */
    std::shared_ptr< std::istream > RenderPageResponse::getResult() const
    {
        return m_Result;
    }

    void RenderPageResponse::deserialize(const std::string& response)
    {
        auto* resultStream = new std::stringstream();
        resultStream->str(response);
        m_Result = std::shared_ptr< std::istream >(resultStream);
    }/*
     * RenderPageOnline request implementation
     */
    std::shared_ptr< std::istream > RenderPageOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void RenderPageOnlineResponse::deserialize(const std::string& response)
    {
        auto* resultStream = new std::stringstream();
        resultStream->str(response);
        m_Result = std::shared_ptr< std::istream >(resultStream);
    }/*
     * RenderParagraph request implementation
     */
    std::shared_ptr< std::istream > RenderParagraphResponse::getResult() const
    {
        return m_Result;
    }

    void RenderParagraphResponse::deserialize(const std::string& response)
    {
        auto* resultStream = new std::stringstream();
        resultStream->str(response);
        m_Result = std::shared_ptr< std::istream >(resultStream);
    }/*
     * RenderParagraphOnline request implementation
     */
    std::shared_ptr< std::istream > RenderParagraphOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void RenderParagraphOnlineResponse::deserialize(const std::string& response)
    {
        auto* resultStream = new std::stringstream();
        resultStream->str(response);
        m_Result = std::shared_ptr< std::istream >(resultStream);
    }/*
     * RenderTable request implementation
     */
    std::shared_ptr< std::istream > RenderTableResponse::getResult() const
    {
        return m_Result;
    }

    void RenderTableResponse::deserialize(const std::string& response)
    {
        auto* resultStream = new std::stringstream();
        resultStream->str(response);
        m_Result = std::shared_ptr< std::istream >(resultStream);
    }/*
     * RenderTableOnline request implementation
     */
    std::shared_ptr< std::istream > RenderTableOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void RenderTableOnlineResponse::deserialize(const std::string& response)
    {
        auto* resultStream = new std::stringstream();
        resultStream->str(response);
        m_Result = std::shared_ptr< std::istream >(resultStream);
    }/*
     * ReplaceText request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ReplaceTextResponse > ReplaceTextResponse::getResult() const
    {
        return m_Result;
    }

    void ReplaceTextResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ReplaceTextResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * ReplaceTextOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ReplaceTextResponse > ReplaceTextOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > ReplaceTextOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void ReplaceTextOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * ReplaceWithText request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > ReplaceWithTextResponse::getResult() const
    {
        return m_Result;
    }

    void ReplaceWithTextResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * ReplaceWithTextOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > ReplaceWithTextOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > ReplaceWithTextOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void ReplaceWithTextOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * ResetCache request implementation
     */

    void ResetCacheResponse::deserialize(const std::string& response)
    {
    }/*
     * SaveAs request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SaveResponse > SaveAsResponse::getResult() const
    {
        return m_Result;
    }

    void SaveAsResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::SaveResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * SaveAsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SaveResponse > SaveAsOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > SaveAsOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void SaveAsOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * SaveAsRange request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > SaveAsRangeResponse::getResult() const
    {
        return m_Result;
    }

    void SaveAsRangeResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * SaveAsRangeOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > SaveAsRangeOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > SaveAsRangeOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void SaveAsRangeOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * SaveAsTiff request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SaveResponse > SaveAsTiffResponse::getResult() const
    {
        return m_Result;
    }

    void SaveAsTiffResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::SaveResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * SaveAsTiffOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SaveResponse > SaveAsTiffOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > SaveAsTiffOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void SaveAsTiffOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * Search request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SearchResponse > SearchResponse::getResult() const
    {
        return m_Result;
    }

    void SearchResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::SearchResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * SearchOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SearchResponse > SearchOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void SearchOnlineResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::SearchResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * SplitDocument request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SplitDocumentResponse > SplitDocumentResponse::getResult() const
    {
        return m_Result;
    }

    void SplitDocumentResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::SplitDocumentResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * SplitDocumentOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SplitDocumentResponse > SplitDocumentOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > SplitDocumentOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void SplitDocumentOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * UnprotectDocument request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ProtectionDataResponse > UnprotectDocumentResponse::getResult() const
    {
        return m_Result;
    }

    void UnprotectDocumentResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ProtectionDataResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * UnprotectDocumentOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ProtectionDataResponse > UnprotectDocumentOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > UnprotectDocumentOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void UnprotectDocumentOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * UpdateBookmark request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BookmarkResponse > UpdateBookmarkResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateBookmarkResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::BookmarkResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * UpdateBookmarkOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BookmarkResponse > UpdateBookmarkOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > UpdateBookmarkOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void UpdateBookmarkOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * UpdateBorder request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BorderResponse > UpdateBorderResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateBorderResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::BorderResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * UpdateBorderOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BorderResponse > UpdateBorderOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > UpdateBorderOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void UpdateBorderOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * UpdateComment request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::CommentResponse > UpdateCommentResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateCommentResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::CommentResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * UpdateCommentOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::CommentResponse > UpdateCommentOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > UpdateCommentOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void UpdateCommentOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * UpdateDrawingObject request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DrawingObjectResponse > UpdateDrawingObjectResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateDrawingObjectResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DrawingObjectResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * UpdateDrawingObjectOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DrawingObjectResponse > UpdateDrawingObjectOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > UpdateDrawingObjectOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void UpdateDrawingObjectOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * UpdateField request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FieldResponse > UpdateFieldResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateFieldResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FieldResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * UpdateFieldOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FieldResponse > UpdateFieldOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > UpdateFieldOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void UpdateFieldOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * UpdateFields request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > UpdateFieldsResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateFieldsResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * UpdateFieldsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > UpdateFieldsOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > UpdateFieldsOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void UpdateFieldsOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * UpdateFootnote request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FootnoteResponse > UpdateFootnoteResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateFootnoteResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FootnoteResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * UpdateFootnoteOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FootnoteResponse > UpdateFootnoteOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > UpdateFootnoteOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void UpdateFootnoteOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * UpdateFormField request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FormFieldResponse > UpdateFormFieldResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateFormFieldResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FormFieldResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * UpdateFormFieldOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FormFieldResponse > UpdateFormFieldOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > UpdateFormFieldOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void UpdateFormFieldOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * UpdateList request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ListResponse > UpdateListResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateListResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ListResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * UpdateListLevel request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ListResponse > UpdateListLevelResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateListLevelResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ListResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * UpdateListLevelOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ListResponse > UpdateListLevelOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > UpdateListLevelOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void UpdateListLevelOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * UpdateListOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ListResponse > UpdateListOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > UpdateListOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void UpdateListOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * UpdateParagraphFormat request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphFormatResponse > UpdateParagraphFormatResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateParagraphFormatResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ParagraphFormatResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * UpdateParagraphFormatOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphFormatResponse > UpdateParagraphFormatOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > UpdateParagraphFormatOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void UpdateParagraphFormatOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * UpdateParagraphListFormat request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphListFormatResponse > UpdateParagraphListFormatResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateParagraphListFormatResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ParagraphListFormatResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * UpdateParagraphListFormatOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphListFormatResponse > UpdateParagraphListFormatOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > UpdateParagraphListFormatOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void UpdateParagraphListFormatOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * UpdateRun request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::RunResponse > UpdateRunResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateRunResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::RunResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * UpdateRunFont request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FontResponse > UpdateRunFontResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateRunFontResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FontResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * UpdateRunFontOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FontResponse > UpdateRunFontOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > UpdateRunFontOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void UpdateRunFontOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * UpdateRunOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::RunResponse > UpdateRunOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > UpdateRunOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void UpdateRunOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * UpdateSectionPageSetup request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SectionPageSetupResponse > UpdateSectionPageSetupResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateSectionPageSetupResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::SectionPageSetupResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * UpdateSectionPageSetupOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SectionPageSetupResponse > UpdateSectionPageSetupOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > UpdateSectionPageSetupOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void UpdateSectionPageSetupOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * UpdateStyle request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::StyleResponse > UpdateStyleResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateStyleResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::StyleResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * UpdateStyleOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::StyleResponse > UpdateStyleOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > UpdateStyleOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void UpdateStyleOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * UpdateTableCellFormat request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableCellFormatResponse > UpdateTableCellFormatResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateTableCellFormatResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableCellFormatResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * UpdateTableCellFormatOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableCellFormatResponse > UpdateTableCellFormatOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > UpdateTableCellFormatOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void UpdateTableCellFormatOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * UpdateTableProperties request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TablePropertiesResponse > UpdateTablePropertiesResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateTablePropertiesResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TablePropertiesResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * UpdateTablePropertiesOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TablePropertiesResponse > UpdateTablePropertiesOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > UpdateTablePropertiesOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void UpdateTablePropertiesOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * UpdateTableRowFormat request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableRowFormatResponse > UpdateTableRowFormatResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateTableRowFormatResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableRowFormatResponse >();
        m_Result->fromJson(&resultJson);
    }/*
     * UpdateTableRowFormatOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableRowFormatResponse > UpdateTableRowFormatOnlineResponse::getModel() const
    {
        return m_Model;
    }

    std::shared_ptr< std::istream > UpdateTableRowFormatOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void UpdateTableRowFormatOnlineResponse::deserialize(const std::string& response)
    {
        // ONLINE METHODS NOT SUPPORTED
    }/*
     * UploadFile request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FilesUploadResult > UploadFileResponse::getResult() const
    {
        return m_Result;
    }

    void UploadFileResponse::deserialize(const std::string& response)
    {
        auto resultJson = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FilesUploadResult >();
        m_Result->fromJson(&resultJson);
    }
}