﻿/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="requests.cpp">
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

// USE THIRD PARTY LIBS ONLY IN CPP FILES!!!
#include "../thirdparty/utf8.h"

namespace aspose::words::cloud::requests {
    BatchRequest::BatchRequest(std::shared_ptr<RequestModelBase> request) :
        m_Request(request),
        m_RequestId(aspose::words::cloud::ApiClient::createRandomGuid())
    { }

    void BatchRequest::dependsOn(const BatchRequest& other) {
        m_DependsOn = other.m_RequestId;
    }

    std::shared_ptr<std::istream> BatchRequest::asResult() const {
        return std::shared_ptr<std::istream>(
            new std::istringstream("resultOf(" + m_RequestId + ")", std::ios_base::in)
        );
    }

    void BatchRequest::serialize(std::string& body) const {
        auto httpRequest = m_Request->createHttpRequest();
        auto method = httpRequest->getMethod();
        if (method == aspose::words::cloud::HttpRequestMethod::HttpGET) body.append("GET ");
        else if (method == aspose::words::cloud::HttpRequestMethod::HttpPOST) body.append("POST ");
        else if (method == aspose::words::cloud::HttpRequestMethod::HttpPUT) body.append("PUT ");
        else if (method == aspose::words::cloud::HttpRequestMethod::HttpDELETE) body.append("DELETE ");
        else throw "Undefined http method";

        static const std::string preffix("/words/");
        body.append(httpRequest->getFullPath().substr(preffix.size()));
        body.append(" \r\n");

        body.append("RequestId: ");
        body.append(m_RequestId);
        body.append("\r\n");

        if (!m_DependsOn.empty()) {
            body.append("DependsOn: ");
            body.append(m_DependsOn);
            body.append("\r\n");
        }

        for (auto& header : httpRequest->getHeaders()) {
            ::utf8::utf16to8(header.first.begin(), header.first.end(), back_inserter(body));
            body.append(": ");
            ::utf8::utf16to8(header.second.begin(), header.second.end(), back_inserter(body));
            body.append("\r\n");
        }

        body.append("\r\n");
        body.append(httpRequest->getBody());
    }

    std::shared_ptr<RequestModelBase> BatchRequest::get() const {
        return m_Request;
    }

    /*
     * AcceptAllRevisions request implementation
     */
    AcceptAllRevisionsRequest::AcceptAllRevisionsRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName
    ) : 
        m_Name(name),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName)
    {
    }

    const std::shared_ptr< std::wstring > AcceptAllRevisionsRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > AcceptAllRevisionsRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > AcceptAllRevisionsRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > AcceptAllRevisionsRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > AcceptAllRevisionsRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > AcceptAllRevisionsRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > AcceptAllRevisionsRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/revisions/acceptAll");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > AcceptAllRevisionsRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::AcceptAllRevisionsResponse()
        );
    }

    /*
     * AcceptAllRevisionsOnline request implementation
     */
    AcceptAllRevisionsOnlineRequest::AcceptAllRevisionsOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName
    ) : 
        m_Document(document),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName)
    {
    }

    const std::shared_ptr< std::istream > AcceptAllRevisionsOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > AcceptAllRevisionsOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > AcceptAllRevisionsOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > AcceptAllRevisionsOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > AcceptAllRevisionsOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/revisions/acceptAll");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > AcceptAllRevisionsOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::AcceptAllRevisionsOnlineResponse()
        );
    }

    /*
     * AppendDocument request implementation
     */
    AppendDocumentRequest::AppendDocumentRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< aspose::words::cloud::models::DocumentEntryList > documentList,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_DocumentList(documentList),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > AppendDocumentRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< aspose::words::cloud::models::DocumentEntryList > AppendDocumentRequest::getDocumentList() const
    {
        return m_DocumentList;
    }

    const std::shared_ptr< std::wstring > AppendDocumentRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > AppendDocumentRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > AppendDocumentRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > AppendDocumentRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > AppendDocumentRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > AppendDocumentRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > AppendDocumentRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > AppendDocumentRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/appendDocument");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_DocumentList) result->setBody(*m_DocumentList);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'DocumentList' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > AppendDocumentRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::AppendDocumentResponse()
        );
    }

    /*
     * AppendDocumentOnline request implementation
     */
    AppendDocumentOnlineRequest::AppendDocumentOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::DocumentEntryList > documentList,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_DocumentList(documentList),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > AppendDocumentOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::DocumentEntryList > AppendDocumentOnlineRequest::getDocumentList() const
    {
        return m_DocumentList;
    }

    const std::shared_ptr< std::wstring > AppendDocumentOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > AppendDocumentOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > AppendDocumentOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > AppendDocumentOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > AppendDocumentOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > AppendDocumentOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/appendDocument");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_DocumentList) result->addFormDataParam(L"documentList", *m_DocumentList);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'DocumentList' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > AppendDocumentOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::AppendDocumentOnlineResponse()
        );
    }

    /*
     * ApplyStyleToDocumentElement request implementation
     */
    ApplyStyleToDocumentElementRequest::ApplyStyleToDocumentElementRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > styledNodePath,
        const std::shared_ptr< aspose::words::cloud::models::StyleApply > styleApply,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_StyledNodePath(styledNodePath),
        m_StyleApply(styleApply),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > ApplyStyleToDocumentElementRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > ApplyStyleToDocumentElementRequest::getStyledNodePath() const
    {
        return m_StyledNodePath;
    }

    const std::shared_ptr< aspose::words::cloud::models::StyleApply > ApplyStyleToDocumentElementRequest::getStyleApply() const
    {
        return m_StyleApply;
    }

    const std::shared_ptr< std::wstring > ApplyStyleToDocumentElementRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > ApplyStyleToDocumentElementRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > ApplyStyleToDocumentElementRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > ApplyStyleToDocumentElementRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > ApplyStyleToDocumentElementRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > ApplyStyleToDocumentElementRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > ApplyStyleToDocumentElementRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > ApplyStyleToDocumentElementRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/{styledNodePath}/style");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_StyledNodePath) throw aspose::words::cloud::ApiException(400, L"Parameter 'StyledNodePath' is required.");
        result->setPathParam(L"{styledNodePath}", *m_StyledNodePath);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_StyleApply) result->setBody(*m_StyleApply);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'StyleApply' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > ApplyStyleToDocumentElementRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::ApplyStyleToDocumentElementResponse()
        );
    }

    /*
     * ApplyStyleToDocumentElementOnline request implementation
     */
    ApplyStyleToDocumentElementOnlineRequest::ApplyStyleToDocumentElementOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > styledNodePath,
        const std::shared_ptr< aspose::words::cloud::models::StyleApply > styleApply,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_StyledNodePath(styledNodePath),
        m_StyleApply(styleApply),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > ApplyStyleToDocumentElementOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > ApplyStyleToDocumentElementOnlineRequest::getStyledNodePath() const
    {
        return m_StyledNodePath;
    }

    const std::shared_ptr< aspose::words::cloud::models::StyleApply > ApplyStyleToDocumentElementOnlineRequest::getStyleApply() const
    {
        return m_StyleApply;
    }

    const std::shared_ptr< std::wstring > ApplyStyleToDocumentElementOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > ApplyStyleToDocumentElementOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > ApplyStyleToDocumentElementOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > ApplyStyleToDocumentElementOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > ApplyStyleToDocumentElementOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > ApplyStyleToDocumentElementOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/{styledNodePath}/style");
        if (!m_StyledNodePath) throw aspose::words::cloud::ApiException(400, L"Parameter 'StyledNodePath' is required.");
        result->setPathParam(L"{styledNodePath}", *m_StyledNodePath);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_StyleApply) result->addFormDataParam(L"styleApply", *m_StyleApply);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'StyleApply' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > ApplyStyleToDocumentElementOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::ApplyStyleToDocumentElementOnlineResponse()
        );
    }

    /*
     * BuildReport request implementation
     */
    BuildReportRequest::BuildReportRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > data,
        const std::shared_ptr< aspose::words::cloud::models::ReportEngineSettings > reportEngineSettings,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName
    ) : 
        m_Name(name),
        m_Data(data),
        m_ReportEngineSettings(reportEngineSettings),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName)
    {
    }

    const std::shared_ptr< std::wstring > BuildReportRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > BuildReportRequest::getData() const
    {
        return m_Data;
    }

    const std::shared_ptr< aspose::words::cloud::models::ReportEngineSettings > BuildReportRequest::getReportEngineSettings() const
    {
        return m_ReportEngineSettings;
    }

    const std::shared_ptr< std::wstring > BuildReportRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > BuildReportRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > BuildReportRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > BuildReportRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > BuildReportRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > BuildReportRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/buildReport");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_Data) result->addFormDataParam(L"data", *m_Data);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Data' is required.");
        if (m_ReportEngineSettings) result->addFormDataParam(L"reportEngineSettings", *m_ReportEngineSettings);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'ReportEngineSettings' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > BuildReportRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::BuildReportResponse()
        );
    }

    /*
     * BuildReportOnline request implementation
     */
    BuildReportOnlineRequest::BuildReportOnlineRequest(
        const std::shared_ptr< std::istream > _template,
        const std::shared_ptr< std::wstring > data,
        const std::shared_ptr< aspose::words::cloud::models::ReportEngineSettings > reportEngineSettings,
        const std::shared_ptr< std::wstring > documentFileName
    ) : 
        m_Template(_template),
        m_Data(data),
        m_ReportEngineSettings(reportEngineSettings),
        m_DocumentFileName(documentFileName)
    {
    }

    const std::shared_ptr< std::istream > BuildReportOnlineRequest::getTemplate() const
    {
        return m_Template;
    }

    const std::shared_ptr< std::wstring > BuildReportOnlineRequest::getData() const
    {
        return m_Data;
    }

    const std::shared_ptr< aspose::words::cloud::models::ReportEngineSettings > BuildReportOnlineRequest::getReportEngineSettings() const
    {
        return m_ReportEngineSettings;
    }

    const std::shared_ptr< std::wstring > BuildReportOnlineRequest::getDocumentFileName() const
    {
        return m_DocumentFileName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > BuildReportOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/buildReport");
        if (m_DocumentFileName) result->addQueryParam(L"documentFileName", *m_DocumentFileName);
        if (m_Template) result->addFormDataParam(L"template", *m_Template);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Template' is required.");
        if (m_Data) result->addFormDataParam(L"data", *m_Data);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Data' is required.");
        if (m_ReportEngineSettings) result->addFormDataParam(L"reportEngineSettings", *m_ReportEngineSettings);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'ReportEngineSettings' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > BuildReportOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::BuildReportOnlineResponse()
        );
    }

    /*
     * Classify request implementation
     */
    ClassifyRequest::ClassifyRequest(
        const std::shared_ptr< std::wstring > text,
        const std::shared_ptr< std::wstring > bestClassesCount
    ) : 
        m_Text(text),
        m_BestClassesCount(bestClassesCount)
    {
    }

    const std::shared_ptr< std::wstring > ClassifyRequest::getText() const
    {
        return m_Text;
    }

    const std::shared_ptr< std::wstring > ClassifyRequest::getBestClassesCount() const
    {
        return m_BestClassesCount;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > ClassifyRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/classify");
        if (m_BestClassesCount) result->addQueryParam(L"bestClassesCount", *m_BestClassesCount);
        if (m_Text) result->setBodyJson(*m_Text);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Text' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > ClassifyRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::ClassifyResponse()
        );
    }

    /*
     * ClassifyDocument request implementation
     */
    ClassifyDocumentRequest::ClassifyDocumentRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > bestClassesCount,
        const std::shared_ptr< std::wstring > taxonomy
    ) : 
        m_Name(name),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_BestClassesCount(bestClassesCount),
        m_Taxonomy(taxonomy)
    {
    }

    const std::shared_ptr< std::wstring > ClassifyDocumentRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > ClassifyDocumentRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > ClassifyDocumentRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > ClassifyDocumentRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > ClassifyDocumentRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > ClassifyDocumentRequest::getBestClassesCount() const
    {
        return m_BestClassesCount;
    }

    const std::shared_ptr< std::wstring > ClassifyDocumentRequest::getTaxonomy() const
    {
        return m_Taxonomy;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > ClassifyDocumentRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/classify");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_BestClassesCount) result->addQueryParam(L"bestClassesCount", *m_BestClassesCount);
        if (m_Taxonomy) result->addQueryParam(L"taxonomy", *m_Taxonomy);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > ClassifyDocumentRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::ClassifyDocumentResponse()
        );
    }

    /*
     * ClassifyDocumentOnline request implementation
     */
    ClassifyDocumentOnlineRequest::ClassifyDocumentOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > bestClassesCount,
        const std::shared_ptr< std::wstring > taxonomy
    ) : 
        m_Document(document),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_BestClassesCount(bestClassesCount),
        m_Taxonomy(taxonomy)
    {
    }

    const std::shared_ptr< std::istream > ClassifyDocumentOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > ClassifyDocumentOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > ClassifyDocumentOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > ClassifyDocumentOnlineRequest::getBestClassesCount() const
    {
        return m_BestClassesCount;
    }

    const std::shared_ptr< std::wstring > ClassifyDocumentOnlineRequest::getTaxonomy() const
    {
        return m_Taxonomy;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > ClassifyDocumentOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/classify");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_BestClassesCount) result->addQueryParam(L"bestClassesCount", *m_BestClassesCount);
        if (m_Taxonomy) result->addQueryParam(L"taxonomy", *m_Taxonomy);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > ClassifyDocumentOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::ClassifyDocumentOnlineResponse()
        );
    }

    /*
     * CompareDocument request implementation
     */
    CompareDocumentRequest::CompareDocumentRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< aspose::words::cloud::models::CompareData > compareData,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName
    ) : 
        m_Name(name),
        m_CompareData(compareData),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName)
    {
    }

    const std::shared_ptr< std::wstring > CompareDocumentRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< aspose::words::cloud::models::CompareData > CompareDocumentRequest::getCompareData() const
    {
        return m_CompareData;
    }

    const std::shared_ptr< std::wstring > CompareDocumentRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > CompareDocumentRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > CompareDocumentRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > CompareDocumentRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > CompareDocumentRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > CompareDocumentRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/compareDocument");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_CompareData) result->setBody(*m_CompareData);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'CompareData' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > CompareDocumentRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::CompareDocumentResponse()
        );
    }

    /*
     * CompareDocumentOnline request implementation
     */
    CompareDocumentOnlineRequest::CompareDocumentOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::CompareData > compareData,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName
    ) : 
        m_Document(document),
        m_CompareData(compareData),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName)
    {
    }

    const std::shared_ptr< std::istream > CompareDocumentOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::CompareData > CompareDocumentOnlineRequest::getCompareData() const
    {
        return m_CompareData;
    }

    const std::shared_ptr< std::wstring > CompareDocumentOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > CompareDocumentOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > CompareDocumentOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > CompareDocumentOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/compareDocument");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_CompareData) result->addFormDataParam(L"compareData", *m_CompareData);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'CompareData' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > CompareDocumentOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::CompareDocumentOnlineResponse()
        );
    }

    /*
     * ConvertDocument request implementation
     */
    ConvertDocumentRequest::ConvertDocumentRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > format,
        const std::shared_ptr< std::wstring > outPath,
        const std::shared_ptr< std::wstring > fileNameFieldValue,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > fontsLocation
    ) : 
        m_Document(document),
        m_Format(format),
        m_OutPath(outPath),
        m_FileNameFieldValue(fileNameFieldValue),
        m_Storage(storage),
        m_FontsLocation(fontsLocation)
    {
    }

    const std::shared_ptr< std::istream > ConvertDocumentRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > ConvertDocumentRequest::getFormat() const
    {
        return m_Format;
    }

    const std::shared_ptr< std::wstring > ConvertDocumentRequest::getOutPath() const
    {
        return m_OutPath;
    }

    const std::shared_ptr< std::wstring > ConvertDocumentRequest::getFileNameFieldValue() const
    {
        return m_FileNameFieldValue;
    }

    const std::shared_ptr< std::wstring > ConvertDocumentRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > ConvertDocumentRequest::getFontsLocation() const
    {
        return m_FontsLocation;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > ConvertDocumentRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/convert");
        if (m_Format) result->addQueryParam(L"format", *m_Format);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Format' is required.");
        if (m_OutPath) result->addQueryParam(L"outPath", *m_OutPath);
        if (m_FileNameFieldValue) result->addQueryParam(L"fileNameFieldValue", *m_FileNameFieldValue);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_FontsLocation) result->addQueryParam(L"fontsLocation", *m_FontsLocation);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > ConvertDocumentRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::ConvertDocumentResponse()
        );
    }

    /*
     * CopyFile request implementation
     */
    CopyFileRequest::CopyFileRequest(
        const std::shared_ptr< std::wstring > destPath,
        const std::shared_ptr< std::wstring > srcPath,
        const std::shared_ptr< std::wstring > srcStorageName,
        const std::shared_ptr< std::wstring > destStorageName,
        const std::shared_ptr< std::wstring > versionId
    ) : 
        m_DestPath(destPath),
        m_SrcPath(srcPath),
        m_SrcStorageName(srcStorageName),
        m_DestStorageName(destStorageName),
        m_VersionId(versionId)
    {
    }

    const std::shared_ptr< std::wstring > CopyFileRequest::getDestPath() const
    {
        return m_DestPath;
    }

    const std::shared_ptr< std::wstring > CopyFileRequest::getSrcPath() const
    {
        return m_SrcPath;
    }

    const std::shared_ptr< std::wstring > CopyFileRequest::getSrcStorageName() const
    {
        return m_SrcStorageName;
    }

    const std::shared_ptr< std::wstring > CopyFileRequest::getDestStorageName() const
    {
        return m_DestStorageName;
    }

    const std::shared_ptr< std::wstring > CopyFileRequest::getVersionId() const
    {
        return m_VersionId;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > CopyFileRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/storage/file/copy/{srcPath}");
        if (!m_SrcPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'SrcPath' is required.");
        result->setPathParam(L"{srcPath}", *m_SrcPath);
        if (m_DestPath) result->addQueryParam(L"destPath", *m_DestPath);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'DestPath' is required.");
        if (m_SrcStorageName) result->addQueryParam(L"srcStorageName", *m_SrcStorageName);
        if (m_DestStorageName) result->addQueryParam(L"destStorageName", *m_DestStorageName);
        if (m_VersionId) result->addQueryParam(L"versionId", *m_VersionId);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > CopyFileRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::CopyFileResponse()
        );
    }

    /*
     * CopyFolder request implementation
     */
    CopyFolderRequest::CopyFolderRequest(
        const std::shared_ptr< std::wstring > destPath,
        const std::shared_ptr< std::wstring > srcPath,
        const std::shared_ptr< std::wstring > srcStorageName,
        const std::shared_ptr< std::wstring > destStorageName
    ) : 
        m_DestPath(destPath),
        m_SrcPath(srcPath),
        m_SrcStorageName(srcStorageName),
        m_DestStorageName(destStorageName)
    {
    }

    const std::shared_ptr< std::wstring > CopyFolderRequest::getDestPath() const
    {
        return m_DestPath;
    }

    const std::shared_ptr< std::wstring > CopyFolderRequest::getSrcPath() const
    {
        return m_SrcPath;
    }

    const std::shared_ptr< std::wstring > CopyFolderRequest::getSrcStorageName() const
    {
        return m_SrcStorageName;
    }

    const std::shared_ptr< std::wstring > CopyFolderRequest::getDestStorageName() const
    {
        return m_DestStorageName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > CopyFolderRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/storage/folder/copy/{srcPath}");
        if (!m_SrcPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'SrcPath' is required.");
        result->setPathParam(L"{srcPath}", *m_SrcPath);
        if (m_DestPath) result->addQueryParam(L"destPath", *m_DestPath);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'DestPath' is required.");
        if (m_SrcStorageName) result->addQueryParam(L"srcStorageName", *m_SrcStorageName);
        if (m_DestStorageName) result->addQueryParam(L"destStorageName", *m_DestStorageName);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > CopyFolderRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::CopyFolderResponse()
        );
    }

    /*
     * CopyStyle request implementation
     */
    CopyStyleRequest::CopyStyleRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< aspose::words::cloud::models::StyleCopy > styleCopy,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_StyleCopy(styleCopy),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > CopyStyleRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< aspose::words::cloud::models::StyleCopy > CopyStyleRequest::getStyleCopy() const
    {
        return m_StyleCopy;
    }

    const std::shared_ptr< std::wstring > CopyStyleRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > CopyStyleRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > CopyStyleRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > CopyStyleRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > CopyStyleRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > CopyStyleRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > CopyStyleRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > CopyStyleRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPOST);
        result->setPath(L"/words/{name}/styles/copy");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_StyleCopy) result->setBody(*m_StyleCopy);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'StyleCopy' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > CopyStyleRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::CopyStyleResponse()
        );
    }

    /*
     * CopyStyleOnline request implementation
     */
    CopyStyleOnlineRequest::CopyStyleOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::StyleCopy > styleCopy,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_StyleCopy(styleCopy),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > CopyStyleOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::StyleCopy > CopyStyleOnlineRequest::getStyleCopy() const
    {
        return m_StyleCopy;
    }

    const std::shared_ptr< std::wstring > CopyStyleOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > CopyStyleOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > CopyStyleOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > CopyStyleOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > CopyStyleOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > CopyStyleOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/post/styles/copy");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_StyleCopy) result->addFormDataParam(L"styleCopy", *m_StyleCopy);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'StyleCopy' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > CopyStyleOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::CopyStyleOnlineResponse()
        );
    }

    /*
     * CreateDocument request implementation
     */
    CreateDocumentRequest::CreateDocumentRequest(
        const std::shared_ptr< std::wstring > fileName,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage
    ) : 
        m_FileName(fileName),
        m_Folder(folder),
        m_Storage(storage)
    {
    }

    const std::shared_ptr< std::wstring > CreateDocumentRequest::getFileName() const
    {
        return m_FileName;
    }

    const std::shared_ptr< std::wstring > CreateDocumentRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > CreateDocumentRequest::getStorage() const
    {
        return m_Storage;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > CreateDocumentRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/create");
        if (m_FileName) result->addQueryParam(L"fileName", *m_FileName);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > CreateDocumentRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::CreateDocumentResponse()
        );
    }

    /*
     * CreateFolder request implementation
     */
    CreateFolderRequest::CreateFolderRequest(
        const std::shared_ptr< std::wstring > path,
        const std::shared_ptr< std::wstring > storageName
    ) : 
        m_Path(path),
        m_StorageName(storageName)
    {
    }

    const std::shared_ptr< std::wstring > CreateFolderRequest::getPath() const
    {
        return m_Path;
    }

    const std::shared_ptr< std::wstring > CreateFolderRequest::getStorageName() const
    {
        return m_StorageName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > CreateFolderRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/storage/folder/{path}");
        if (!m_Path) throw aspose::words::cloud::ApiException(400, L"Parameter 'Path' is required.");
        result->setPathParam(L"{path}", *m_Path);
        if (m_StorageName) result->addQueryParam(L"storageName", *m_StorageName);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > CreateFolderRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::CreateFolderResponse()
        );
    }

    /*
     * CreateOrUpdateDocumentProperty request implementation
     */
    CreateOrUpdateDocumentPropertyRequest::CreateOrUpdateDocumentPropertyRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > propertyName,
        const std::shared_ptr< aspose::words::cloud::models::DocumentPropertyCreateOrUpdate > property,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_PropertyName(propertyName),
        m_Property(property),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > CreateOrUpdateDocumentPropertyRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > CreateOrUpdateDocumentPropertyRequest::getPropertyName() const
    {
        return m_PropertyName;
    }

    const std::shared_ptr< aspose::words::cloud::models::DocumentPropertyCreateOrUpdate > CreateOrUpdateDocumentPropertyRequest::getProperty() const
    {
        return m_Property;
    }

    const std::shared_ptr< std::wstring > CreateOrUpdateDocumentPropertyRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > CreateOrUpdateDocumentPropertyRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > CreateOrUpdateDocumentPropertyRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > CreateOrUpdateDocumentPropertyRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > CreateOrUpdateDocumentPropertyRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > CreateOrUpdateDocumentPropertyRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > CreateOrUpdateDocumentPropertyRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > CreateOrUpdateDocumentPropertyRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/documentProperties/{propertyName}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_PropertyName) throw aspose::words::cloud::ApiException(400, L"Parameter 'PropertyName' is required.");
        result->setPathParam(L"{propertyName}", *m_PropertyName);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Property) result->setBody(*m_Property);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Property' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > CreateOrUpdateDocumentPropertyRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::CreateOrUpdateDocumentPropertyResponse()
        );
    }

    /*
     * CreateOrUpdateDocumentPropertyOnline request implementation
     */
    CreateOrUpdateDocumentPropertyOnlineRequest::CreateOrUpdateDocumentPropertyOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > propertyName,
        const std::shared_ptr< aspose::words::cloud::models::DocumentPropertyCreateOrUpdate > property,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_PropertyName(propertyName),
        m_Property(property),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > CreateOrUpdateDocumentPropertyOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > CreateOrUpdateDocumentPropertyOnlineRequest::getPropertyName() const
    {
        return m_PropertyName;
    }

    const std::shared_ptr< aspose::words::cloud::models::DocumentPropertyCreateOrUpdate > CreateOrUpdateDocumentPropertyOnlineRequest::getProperty() const
    {
        return m_Property;
    }

    const std::shared_ptr< std::wstring > CreateOrUpdateDocumentPropertyOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > CreateOrUpdateDocumentPropertyOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > CreateOrUpdateDocumentPropertyOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > CreateOrUpdateDocumentPropertyOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > CreateOrUpdateDocumentPropertyOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > CreateOrUpdateDocumentPropertyOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/documentProperties/{propertyName}");
        if (!m_PropertyName) throw aspose::words::cloud::ApiException(400, L"Parameter 'PropertyName' is required.");
        result->setPathParam(L"{propertyName}", *m_PropertyName);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_Property) result->addFormDataParam(L"property", *m_Property);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Property' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > CreateOrUpdateDocumentPropertyOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::CreateOrUpdateDocumentPropertyOnlineResponse()
        );
    }

    /*
     * DeleteAllParagraphTabStops request implementation
     */
    DeleteAllParagraphTabStopsRequest::DeleteAllParagraphTabStopsRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName
    ) : 
        m_Name(name),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName)
    {
    }

    const std::shared_ptr< std::wstring > DeleteAllParagraphTabStopsRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > DeleteAllParagraphTabStopsRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteAllParagraphTabStopsRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > DeleteAllParagraphTabStopsRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > DeleteAllParagraphTabStopsRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > DeleteAllParagraphTabStopsRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteAllParagraphTabStopsRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteAllParagraphTabStopsRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteAllParagraphTabStopsRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/{name}/{nodePath}/paragraphs/{index}/tabstops");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteAllParagraphTabStopsRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteAllParagraphTabStopsResponse()
        );
    }

    /*
     * DeleteAllParagraphTabStopsOnline request implementation
     */
    DeleteAllParagraphTabStopsOnlineRequest::DeleteAllParagraphTabStopsOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName
    ) : 
        m_Document(document),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName)
    {
    }

    const std::shared_ptr< std::istream > DeleteAllParagraphTabStopsOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > DeleteAllParagraphTabStopsOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteAllParagraphTabStopsOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > DeleteAllParagraphTabStopsOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteAllParagraphTabStopsOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteAllParagraphTabStopsOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteAllParagraphTabStopsOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/delete/{nodePath}/paragraphs/{index}/tabstops");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteAllParagraphTabStopsOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteAllParagraphTabStopsOnlineResponse()
        );
    }

    /*
     * DeleteBorder request implementation
     */
    DeleteBorderRequest::DeleteBorderRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > borderType,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_BorderType(borderType),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > DeleteBorderRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > DeleteBorderRequest::getBorderType() const
    {
        return m_BorderType;
    }

    const std::shared_ptr< std::wstring > DeleteBorderRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > DeleteBorderRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > DeleteBorderRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > DeleteBorderRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteBorderRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteBorderRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteBorderRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteBorderRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteBorderRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/{name}/{nodePath}/borders/{borderType}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_BorderType) throw aspose::words::cloud::ApiException(400, L"Parameter 'BorderType' is required.");
        result->setPathParam(L"{borderType}", *m_BorderType);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteBorderRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteBorderResponse()
        );
    }

    /*
     * DeleteBorderOnline request implementation
     */
    DeleteBorderOnlineRequest::DeleteBorderOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > borderType,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_BorderType(borderType),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > DeleteBorderOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > DeleteBorderOnlineRequest::getBorderType() const
    {
        return m_BorderType;
    }

    const std::shared_ptr< std::wstring > DeleteBorderOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > DeleteBorderOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteBorderOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteBorderOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteBorderOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteBorderOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteBorderOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/delete/{nodePath}/borders/{borderType}");
        if (!m_BorderType) throw aspose::words::cloud::ApiException(400, L"Parameter 'BorderType' is required.");
        result->setPathParam(L"{borderType}", *m_BorderType);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteBorderOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteBorderOnlineResponse()
        );
    }

    /*
     * DeleteBorders request implementation
     */
    DeleteBordersRequest::DeleteBordersRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > DeleteBordersRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > DeleteBordersRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > DeleteBordersRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > DeleteBordersRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > DeleteBordersRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteBordersRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteBordersRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteBordersRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteBordersRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteBordersRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/{name}/{nodePath}/borders");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteBordersRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteBordersResponse()
        );
    }

    /*
     * DeleteBordersOnline request implementation
     */
    DeleteBordersOnlineRequest::DeleteBordersOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > DeleteBordersOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > DeleteBordersOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > DeleteBordersOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteBordersOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteBordersOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteBordersOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteBordersOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteBordersOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/delete/{nodePath}/borders");
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteBordersOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteBordersOnlineResponse()
        );
    }

    /*
     * DeleteComment request implementation
     */
    DeleteCommentRequest::DeleteCommentRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > commentIndex,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_CommentIndex(commentIndex),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > DeleteCommentRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > DeleteCommentRequest::getCommentIndex() const
    {
        return m_CommentIndex;
    }

    const std::shared_ptr< std::wstring > DeleteCommentRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > DeleteCommentRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > DeleteCommentRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteCommentRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteCommentRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteCommentRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteCommentRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteCommentRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/{name}/comments/{commentIndex}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_CommentIndex) throw aspose::words::cloud::ApiException(400, L"Parameter 'CommentIndex' is required.");
        result->setPathParam(L"{commentIndex}", *m_CommentIndex);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteCommentRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteCommentResponse()
        );
    }

    /*
     * DeleteCommentOnline request implementation
     */
    DeleteCommentOnlineRequest::DeleteCommentOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > commentIndex,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_CommentIndex(commentIndex),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > DeleteCommentOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > DeleteCommentOnlineRequest::getCommentIndex() const
    {
        return m_CommentIndex;
    }

    const std::shared_ptr< std::wstring > DeleteCommentOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteCommentOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteCommentOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteCommentOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteCommentOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteCommentOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/delete/comments/{commentIndex}");
        if (!m_CommentIndex) throw aspose::words::cloud::ApiException(400, L"Parameter 'CommentIndex' is required.");
        result->setPathParam(L"{commentIndex}", *m_CommentIndex);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteCommentOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteCommentOnlineResponse()
        );
    }

    /*
     * DeleteComments request implementation
     */
    DeleteCommentsRequest::DeleteCommentsRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > DeleteCommentsRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > DeleteCommentsRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > DeleteCommentsRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > DeleteCommentsRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteCommentsRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteCommentsRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteCommentsRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteCommentsRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteCommentsRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/{name}/comments");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteCommentsRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteCommentsResponse()
        );
    }

    /*
     * DeleteCommentsOnline request implementation
     */
    DeleteCommentsOnlineRequest::DeleteCommentsOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > DeleteCommentsOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > DeleteCommentsOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteCommentsOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteCommentsOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteCommentsOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteCommentsOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteCommentsOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/delete/comments");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteCommentsOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteCommentsOnlineResponse()
        );
    }

    /*
     * DeleteDocumentProperty request implementation
     */
    DeleteDocumentPropertyRequest::DeleteDocumentPropertyRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > propertyName,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_PropertyName(propertyName),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > DeleteDocumentPropertyRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > DeleteDocumentPropertyRequest::getPropertyName() const
    {
        return m_PropertyName;
    }

    const std::shared_ptr< std::wstring > DeleteDocumentPropertyRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > DeleteDocumentPropertyRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > DeleteDocumentPropertyRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteDocumentPropertyRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteDocumentPropertyRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteDocumentPropertyRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteDocumentPropertyRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteDocumentPropertyRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/{name}/documentProperties/{propertyName}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_PropertyName) throw aspose::words::cloud::ApiException(400, L"Parameter 'PropertyName' is required.");
        result->setPathParam(L"{propertyName}", *m_PropertyName);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteDocumentPropertyRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteDocumentPropertyResponse()
        );
    }

    /*
     * DeleteDocumentPropertyOnline request implementation
     */
    DeleteDocumentPropertyOnlineRequest::DeleteDocumentPropertyOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > propertyName,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_PropertyName(propertyName),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > DeleteDocumentPropertyOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > DeleteDocumentPropertyOnlineRequest::getPropertyName() const
    {
        return m_PropertyName;
    }

    const std::shared_ptr< std::wstring > DeleteDocumentPropertyOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteDocumentPropertyOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteDocumentPropertyOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteDocumentPropertyOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteDocumentPropertyOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteDocumentPropertyOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/delete/documentProperties/{propertyName}");
        if (!m_PropertyName) throw aspose::words::cloud::ApiException(400, L"Parameter 'PropertyName' is required.");
        result->setPathParam(L"{propertyName}", *m_PropertyName);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteDocumentPropertyOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteDocumentPropertyOnlineResponse()
        );
    }

    /*
     * DeleteDrawingObject request implementation
     */
    DeleteDrawingObjectRequest::DeleteDrawingObjectRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > DeleteDrawingObjectRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > DeleteDrawingObjectRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteDrawingObjectRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > DeleteDrawingObjectRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > DeleteDrawingObjectRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > DeleteDrawingObjectRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteDrawingObjectRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteDrawingObjectRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteDrawingObjectRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteDrawingObjectRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteDrawingObjectRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/{name}/{nodePath}/drawingObjects/{index}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteDrawingObjectRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteDrawingObjectResponse()
        );
    }

    /*
     * DeleteDrawingObjectOnline request implementation
     */
    DeleteDrawingObjectOnlineRequest::DeleteDrawingObjectOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > DeleteDrawingObjectOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > DeleteDrawingObjectOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteDrawingObjectOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > DeleteDrawingObjectOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteDrawingObjectOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteDrawingObjectOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteDrawingObjectOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteDrawingObjectOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteDrawingObjectOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/delete/{nodePath}/drawingObjects/{index}");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteDrawingObjectOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteDrawingObjectOnlineResponse()
        );
    }

    /*
     * DeleteField request implementation
     */
    DeleteFieldRequest::DeleteFieldRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > DeleteFieldRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > DeleteFieldRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteFieldRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > DeleteFieldRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > DeleteFieldRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > DeleteFieldRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteFieldRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteFieldRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteFieldRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteFieldRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteFieldRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/{name}/{nodePath}/fields/{index}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteFieldRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteFieldResponse()
        );
    }

    /*
     * DeleteFieldOnline request implementation
     */
    DeleteFieldOnlineRequest::DeleteFieldOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > DeleteFieldOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > DeleteFieldOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteFieldOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > DeleteFieldOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteFieldOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteFieldOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteFieldOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteFieldOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteFieldOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/delete/{nodePath}/fields/{index}");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteFieldOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteFieldOnlineResponse()
        );
    }

    /*
     * DeleteFields request implementation
     */
    DeleteFieldsRequest::DeleteFieldsRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > DeleteFieldsRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > DeleteFieldsRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > DeleteFieldsRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > DeleteFieldsRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > DeleteFieldsRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteFieldsRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteFieldsRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteFieldsRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteFieldsRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteFieldsRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/{name}/{nodePath}/fields");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteFieldsRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteFieldsResponse()
        );
    }

    /*
     * DeleteFieldsOnline request implementation
     */
    DeleteFieldsOnlineRequest::DeleteFieldsOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > DeleteFieldsOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > DeleteFieldsOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > DeleteFieldsOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteFieldsOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteFieldsOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteFieldsOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteFieldsOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteFieldsOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/delete/{nodePath}/fields");
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteFieldsOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteFieldsOnlineResponse()
        );
    }

    /*
     * DeleteFile request implementation
     */
    DeleteFileRequest::DeleteFileRequest(
        const std::shared_ptr< std::wstring > path,
        const std::shared_ptr< std::wstring > storageName,
        const std::shared_ptr< std::wstring > versionId
    ) : 
        m_Path(path),
        m_StorageName(storageName),
        m_VersionId(versionId)
    {
    }

    const std::shared_ptr< std::wstring > DeleteFileRequest::getPath() const
    {
        return m_Path;
    }

    const std::shared_ptr< std::wstring > DeleteFileRequest::getStorageName() const
    {
        return m_StorageName;
    }

    const std::shared_ptr< std::wstring > DeleteFileRequest::getVersionId() const
    {
        return m_VersionId;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteFileRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/storage/file/{path}");
        if (!m_Path) throw aspose::words::cloud::ApiException(400, L"Parameter 'Path' is required.");
        result->setPathParam(L"{path}", *m_Path);
        if (m_StorageName) result->addQueryParam(L"storageName", *m_StorageName);
        if (m_VersionId) result->addQueryParam(L"versionId", *m_VersionId);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteFileRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteFileResponse()
        );
    }

    /*
     * DeleteFolder request implementation
     */
    DeleteFolderRequest::DeleteFolderRequest(
        const std::shared_ptr< std::wstring > path,
        const std::shared_ptr< std::wstring > storageName,
        const std::shared_ptr< bool > recursive
    ) : 
        m_Path(path),
        m_StorageName(storageName),
        m_Recursive(recursive)
    {
    }

    const std::shared_ptr< std::wstring > DeleteFolderRequest::getPath() const
    {
        return m_Path;
    }

    const std::shared_ptr< std::wstring > DeleteFolderRequest::getStorageName() const
    {
        return m_StorageName;
    }

    const std::shared_ptr< bool > DeleteFolderRequest::getRecursive() const
    {
        return m_Recursive;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteFolderRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/storage/folder/{path}");
        if (!m_Path) throw aspose::words::cloud::ApiException(400, L"Parameter 'Path' is required.");
        result->setPathParam(L"{path}", *m_Path);
        if (m_StorageName) result->addQueryParam(L"storageName", *m_StorageName);
        if (m_Recursive) result->addQueryParam(L"recursive", *m_Recursive);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteFolderRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteFolderResponse()
        );
    }

    /*
     * DeleteFootnote request implementation
     */
    DeleteFootnoteRequest::DeleteFootnoteRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > DeleteFootnoteRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > DeleteFootnoteRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteFootnoteRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > DeleteFootnoteRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > DeleteFootnoteRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > DeleteFootnoteRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteFootnoteRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteFootnoteRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteFootnoteRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteFootnoteRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteFootnoteRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/{name}/{nodePath}/footnotes/{index}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteFootnoteRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteFootnoteResponse()
        );
    }

    /*
     * DeleteFootnoteOnline request implementation
     */
    DeleteFootnoteOnlineRequest::DeleteFootnoteOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > DeleteFootnoteOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > DeleteFootnoteOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteFootnoteOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > DeleteFootnoteOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteFootnoteOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteFootnoteOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteFootnoteOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteFootnoteOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteFootnoteOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/delete/{nodePath}/footnotes/{index}");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteFootnoteOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteFootnoteOnlineResponse()
        );
    }

    /*
     * DeleteFormField request implementation
     */
    DeleteFormFieldRequest::DeleteFormFieldRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > DeleteFormFieldRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > DeleteFormFieldRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteFormFieldRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > DeleteFormFieldRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > DeleteFormFieldRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > DeleteFormFieldRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteFormFieldRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteFormFieldRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteFormFieldRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteFormFieldRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteFormFieldRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/{name}/{nodePath}/formfields/{index}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteFormFieldRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteFormFieldResponse()
        );
    }

    /*
     * DeleteFormFieldOnline request implementation
     */
    DeleteFormFieldOnlineRequest::DeleteFormFieldOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > DeleteFormFieldOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > DeleteFormFieldOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteFormFieldOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > DeleteFormFieldOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteFormFieldOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteFormFieldOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteFormFieldOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteFormFieldOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteFormFieldOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/delete/{nodePath}/formfields/{index}");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteFormFieldOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteFormFieldOnlineResponse()
        );
    }

    /*
     * DeleteHeaderFooter request implementation
     */
    DeleteHeaderFooterRequest::DeleteHeaderFooterRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > sectionPath,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_SectionPath(sectionPath),
        m_Index(index),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > DeleteHeaderFooterRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > DeleteHeaderFooterRequest::getSectionPath() const
    {
        return m_SectionPath;
    }

    const std::shared_ptr< int32_t > DeleteHeaderFooterRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteHeaderFooterRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > DeleteHeaderFooterRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > DeleteHeaderFooterRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteHeaderFooterRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteHeaderFooterRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteHeaderFooterRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteHeaderFooterRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteHeaderFooterRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/{name}/{sectionPath}/headersfooters/{index}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_SectionPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'SectionPath' is required.");
        result->setPathParam(L"{sectionPath}", *m_SectionPath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteHeaderFooterRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteHeaderFooterResponse()
        );
    }

    /*
     * DeleteHeaderFooterOnline request implementation
     */
    DeleteHeaderFooterOnlineRequest::DeleteHeaderFooterOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > sectionPath,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_SectionPath(sectionPath),
        m_Index(index),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > DeleteHeaderFooterOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > DeleteHeaderFooterOnlineRequest::getSectionPath() const
    {
        return m_SectionPath;
    }

    const std::shared_ptr< int32_t > DeleteHeaderFooterOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteHeaderFooterOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteHeaderFooterOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteHeaderFooterOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteHeaderFooterOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteHeaderFooterOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteHeaderFooterOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/delete/{sectionPath}/headersfooters/{index}");
        if (!m_SectionPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'SectionPath' is required.");
        result->setPathParam(L"{sectionPath}", *m_SectionPath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteHeaderFooterOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteHeaderFooterOnlineResponse()
        );
    }

    /*
     * DeleteHeadersFooters request implementation
     */
    DeleteHeadersFootersRequest::DeleteHeadersFootersRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > sectionPath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime,
        const std::shared_ptr< std::wstring > headersFootersTypes
    ) : 
        m_Name(name),
        m_SectionPath(sectionPath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime),
        m_HeadersFootersTypes(headersFootersTypes)
    {
    }

    const std::shared_ptr< std::wstring > DeleteHeadersFootersRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > DeleteHeadersFootersRequest::getSectionPath() const
    {
        return m_SectionPath;
    }

    const std::shared_ptr< std::wstring > DeleteHeadersFootersRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > DeleteHeadersFootersRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > DeleteHeadersFootersRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteHeadersFootersRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteHeadersFootersRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteHeadersFootersRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteHeadersFootersRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    const std::shared_ptr< std::wstring > DeleteHeadersFootersRequest::getHeadersFootersTypes() const
    {
        return m_HeadersFootersTypes;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteHeadersFootersRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/{name}/{sectionPath}/headersfooters");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_SectionPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'SectionPath' is required.");
        result->setPathParam(L"{sectionPath}", *m_SectionPath);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_HeadersFootersTypes) result->addQueryParam(L"headersFootersTypes", *m_HeadersFootersTypes);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteHeadersFootersRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteHeadersFootersResponse()
        );
    }

    /*
     * DeleteHeadersFootersOnline request implementation
     */
    DeleteHeadersFootersOnlineRequest::DeleteHeadersFootersOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > sectionPath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime,
        const std::shared_ptr< std::wstring > headersFootersTypes
    ) : 
        m_Document(document),
        m_SectionPath(sectionPath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime),
        m_HeadersFootersTypes(headersFootersTypes)
    {
    }

    const std::shared_ptr< std::istream > DeleteHeadersFootersOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > DeleteHeadersFootersOnlineRequest::getSectionPath() const
    {
        return m_SectionPath;
    }

    const std::shared_ptr< std::wstring > DeleteHeadersFootersOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteHeadersFootersOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteHeadersFootersOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteHeadersFootersOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteHeadersFootersOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    const std::shared_ptr< std::wstring > DeleteHeadersFootersOnlineRequest::getHeadersFootersTypes() const
    {
        return m_HeadersFootersTypes;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteHeadersFootersOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/delete/{sectionPath}/headersfooters");
        if (!m_SectionPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'SectionPath' is required.");
        result->setPathParam(L"{sectionPath}", *m_SectionPath);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_HeadersFootersTypes) result->addQueryParam(L"headersFootersTypes", *m_HeadersFootersTypes);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteHeadersFootersOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteHeadersFootersOnlineResponse()
        );
    }

    /*
     * DeleteMacros request implementation
     */
    DeleteMacrosRequest::DeleteMacrosRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > DeleteMacrosRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > DeleteMacrosRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > DeleteMacrosRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > DeleteMacrosRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteMacrosRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteMacrosRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteMacrosRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteMacrosRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteMacrosRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/{name}/macros");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteMacrosRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteMacrosResponse()
        );
    }

    /*
     * DeleteMacrosOnline request implementation
     */
    DeleteMacrosOnlineRequest::DeleteMacrosOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > DeleteMacrosOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > DeleteMacrosOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteMacrosOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteMacrosOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteMacrosOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteMacrosOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteMacrosOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/delete/macros");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteMacrosOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteMacrosOnlineResponse()
        );
    }

    /*
     * DeleteOfficeMathObject request implementation
     */
    DeleteOfficeMathObjectRequest::DeleteOfficeMathObjectRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > DeleteOfficeMathObjectRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > DeleteOfficeMathObjectRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteOfficeMathObjectRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > DeleteOfficeMathObjectRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > DeleteOfficeMathObjectRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > DeleteOfficeMathObjectRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteOfficeMathObjectRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteOfficeMathObjectRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteOfficeMathObjectRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteOfficeMathObjectRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteOfficeMathObjectRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/{name}/{nodePath}/OfficeMathObjects/{index}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteOfficeMathObjectRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteOfficeMathObjectResponse()
        );
    }

    /*
     * DeleteOfficeMathObjectOnline request implementation
     */
    DeleteOfficeMathObjectOnlineRequest::DeleteOfficeMathObjectOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > DeleteOfficeMathObjectOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > DeleteOfficeMathObjectOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteOfficeMathObjectOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > DeleteOfficeMathObjectOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteOfficeMathObjectOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteOfficeMathObjectOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteOfficeMathObjectOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteOfficeMathObjectOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteOfficeMathObjectOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/delete/{nodePath}/OfficeMathObjects/{index}");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteOfficeMathObjectOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteOfficeMathObjectOnlineResponse()
        );
    }

    /*
     * DeleteParagraph request implementation
     */
    DeleteParagraphRequest::DeleteParagraphRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > DeleteParagraphRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > DeleteParagraphRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteParagraphRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/{name}/{nodePath}/paragraphs/{index}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteParagraphRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteParagraphResponse()
        );
    }

    /*
     * DeleteParagraphListFormat request implementation
     */
    DeleteParagraphListFormatRequest::DeleteParagraphListFormatRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > DeleteParagraphListFormatRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > DeleteParagraphListFormatRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphListFormatRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphListFormatRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphListFormatRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphListFormatRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphListFormatRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphListFormatRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphListFormatRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphListFormatRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteParagraphListFormatRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/{name}/{nodePath}/paragraphs/{index}/listFormat");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteParagraphListFormatRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteParagraphListFormatResponse()
        );
    }

    /*
     * DeleteParagraphListFormatOnline request implementation
     */
    DeleteParagraphListFormatOnlineRequest::DeleteParagraphListFormatOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > DeleteParagraphListFormatOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > DeleteParagraphListFormatOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphListFormatOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphListFormatOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphListFormatOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphListFormatOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphListFormatOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphListFormatOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteParagraphListFormatOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/delete/{nodePath}/paragraphs/{index}/listFormat");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteParagraphListFormatOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteParagraphListFormatOnlineResponse()
        );
    }

    /*
     * DeleteParagraphOnline request implementation
     */
    DeleteParagraphOnlineRequest::DeleteParagraphOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > DeleteParagraphOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > DeleteParagraphOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteParagraphOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/delete/{nodePath}/paragraphs/{index}");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteParagraphOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteParagraphOnlineResponse()
        );
    }

    /*
     * DeleteParagraphTabStop request implementation
     */
    DeleteParagraphTabStopRequest::DeleteParagraphTabStopRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< double > position,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName
    ) : 
        m_Name(name),
        m_Position(position),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName)
    {
    }

    const std::shared_ptr< std::wstring > DeleteParagraphTabStopRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< double > DeleteParagraphTabStopRequest::getPosition() const
    {
        return m_Position;
    }

    const std::shared_ptr< int32_t > DeleteParagraphTabStopRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphTabStopRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphTabStopRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphTabStopRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphTabStopRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphTabStopRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphTabStopRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteParagraphTabStopRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/{name}/{nodePath}/paragraphs/{index}/tabstop");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Position) result->addQueryParam(L"position", *m_Position);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Position' is required.");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteParagraphTabStopRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteParagraphTabStopResponse()
        );
    }

    /*
     * DeleteParagraphTabStopOnline request implementation
     */
    DeleteParagraphTabStopOnlineRequest::DeleteParagraphTabStopOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< double > position,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName
    ) : 
        m_Document(document),
        m_Position(position),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName)
    {
    }

    const std::shared_ptr< std::istream > DeleteParagraphTabStopOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< double > DeleteParagraphTabStopOnlineRequest::getPosition() const
    {
        return m_Position;
    }

    const std::shared_ptr< int32_t > DeleteParagraphTabStopOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphTabStopOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphTabStopOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphTabStopOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteParagraphTabStopOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteParagraphTabStopOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/delete/{nodePath}/paragraphs/{index}/tabstop");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Position) result->addQueryParam(L"position", *m_Position);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Position' is required.");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteParagraphTabStopOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteParagraphTabStopOnlineResponse()
        );
    }

    /*
     * DeleteRun request implementation
     */
    DeleteRunRequest::DeleteRunRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > paragraphPath,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_ParagraphPath(paragraphPath),
        m_Index(index),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > DeleteRunRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > DeleteRunRequest::getParagraphPath() const
    {
        return m_ParagraphPath;
    }

    const std::shared_ptr< int32_t > DeleteRunRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteRunRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > DeleteRunRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > DeleteRunRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteRunRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteRunRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteRunRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteRunRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteRunRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/{name}/{paragraphPath}/runs/{index}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_ParagraphPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'ParagraphPath' is required.");
        result->setPathParam(L"{paragraphPath}", *m_ParagraphPath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteRunRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteRunResponse()
        );
    }

    /*
     * DeleteRunOnline request implementation
     */
    DeleteRunOnlineRequest::DeleteRunOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > paragraphPath,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_ParagraphPath(paragraphPath),
        m_Index(index),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > DeleteRunOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > DeleteRunOnlineRequest::getParagraphPath() const
    {
        return m_ParagraphPath;
    }

    const std::shared_ptr< int32_t > DeleteRunOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteRunOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteRunOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteRunOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteRunOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteRunOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteRunOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/delete/{paragraphPath}/runs/{index}");
        if (!m_ParagraphPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'ParagraphPath' is required.");
        result->setPathParam(L"{paragraphPath}", *m_ParagraphPath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteRunOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteRunOnlineResponse()
        );
    }

    /*
     * DeleteSection request implementation
     */
    DeleteSectionRequest::DeleteSectionRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > sectionIndex,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_SectionIndex(sectionIndex),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > DeleteSectionRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > DeleteSectionRequest::getSectionIndex() const
    {
        return m_SectionIndex;
    }

    const std::shared_ptr< std::wstring > DeleteSectionRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > DeleteSectionRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > DeleteSectionRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteSectionRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteSectionRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteSectionRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteSectionRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteSectionRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/{name}/sections/{sectionIndex}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_SectionIndex) throw aspose::words::cloud::ApiException(400, L"Parameter 'SectionIndex' is required.");
        result->setPathParam(L"{sectionIndex}", *m_SectionIndex);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteSectionRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteSectionResponse()
        );
    }

    /*
     * DeleteSectionOnline request implementation
     */
    DeleteSectionOnlineRequest::DeleteSectionOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > sectionIndex,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_SectionIndex(sectionIndex),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > DeleteSectionOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > DeleteSectionOnlineRequest::getSectionIndex() const
    {
        return m_SectionIndex;
    }

    const std::shared_ptr< std::wstring > DeleteSectionOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteSectionOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteSectionOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteSectionOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteSectionOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteSectionOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/delete/sections/{sectionIndex}");
        if (!m_SectionIndex) throw aspose::words::cloud::ApiException(400, L"Parameter 'SectionIndex' is required.");
        result->setPathParam(L"{sectionIndex}", *m_SectionIndex);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteSectionOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteSectionOnlineResponse()
        );
    }

    /*
     * DeleteTable request implementation
     */
    DeleteTableRequest::DeleteTableRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > DeleteTableRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > DeleteTableRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteTableRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > DeleteTableRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > DeleteTableRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > DeleteTableRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteTableRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteTableRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteTableRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteTableRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteTableRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/{name}/{nodePath}/tables/{index}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteTableRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteTableResponse()
        );
    }

    /*
     * DeleteTableCell request implementation
     */
    DeleteTableCellRequest::DeleteTableCellRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > tableRowPath,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_TableRowPath(tableRowPath),
        m_Index(index),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > DeleteTableCellRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > DeleteTableCellRequest::getTableRowPath() const
    {
        return m_TableRowPath;
    }

    const std::shared_ptr< int32_t > DeleteTableCellRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteTableCellRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > DeleteTableCellRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > DeleteTableCellRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteTableCellRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteTableCellRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteTableCellRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteTableCellRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteTableCellRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/{name}/{tableRowPath}/cells/{index}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_TableRowPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'TableRowPath' is required.");
        result->setPathParam(L"{tableRowPath}", *m_TableRowPath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteTableCellRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteTableCellResponse()
        );
    }

    /*
     * DeleteTableCellOnline request implementation
     */
    DeleteTableCellOnlineRequest::DeleteTableCellOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > tableRowPath,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_TableRowPath(tableRowPath),
        m_Index(index),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > DeleteTableCellOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > DeleteTableCellOnlineRequest::getTableRowPath() const
    {
        return m_TableRowPath;
    }

    const std::shared_ptr< int32_t > DeleteTableCellOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteTableCellOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteTableCellOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteTableCellOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteTableCellOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteTableCellOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteTableCellOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/delete/{tableRowPath}/cells/{index}");
        if (!m_TableRowPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'TableRowPath' is required.");
        result->setPathParam(L"{tableRowPath}", *m_TableRowPath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteTableCellOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteTableCellOnlineResponse()
        );
    }

    /*
     * DeleteTableOnline request implementation
     */
    DeleteTableOnlineRequest::DeleteTableOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > DeleteTableOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > DeleteTableOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteTableOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > DeleteTableOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteTableOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteTableOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteTableOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteTableOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteTableOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/delete/{nodePath}/tables/{index}");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteTableOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteTableOnlineResponse()
        );
    }

    /*
     * DeleteTableRow request implementation
     */
    DeleteTableRowRequest::DeleteTableRowRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > tablePath,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_TablePath(tablePath),
        m_Index(index),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > DeleteTableRowRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > DeleteTableRowRequest::getTablePath() const
    {
        return m_TablePath;
    }

    const std::shared_ptr< int32_t > DeleteTableRowRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteTableRowRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > DeleteTableRowRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > DeleteTableRowRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteTableRowRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteTableRowRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteTableRowRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteTableRowRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteTableRowRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/{name}/{tablePath}/rows/{index}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_TablePath) throw aspose::words::cloud::ApiException(400, L"Parameter 'TablePath' is required.");
        result->setPathParam(L"{tablePath}", *m_TablePath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteTableRowRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteTableRowResponse()
        );
    }

    /*
     * DeleteTableRowOnline request implementation
     */
    DeleteTableRowOnlineRequest::DeleteTableRowOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > tablePath,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_TablePath(tablePath),
        m_Index(index),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > DeleteTableRowOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > DeleteTableRowOnlineRequest::getTablePath() const
    {
        return m_TablePath;
    }

    const std::shared_ptr< int32_t > DeleteTableRowOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > DeleteTableRowOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteTableRowOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteTableRowOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteTableRowOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteTableRowOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteTableRowOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/delete/{tablePath}/rows/{index}");
        if (!m_TablePath) throw aspose::words::cloud::ApiException(400, L"Parameter 'TablePath' is required.");
        result->setPathParam(L"{tablePath}", *m_TablePath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteTableRowOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteTableRowOnlineResponse()
        );
    }

    /*
     * DeleteWatermark request implementation
     */
    DeleteWatermarkRequest::DeleteWatermarkRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > DeleteWatermarkRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > DeleteWatermarkRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > DeleteWatermarkRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > DeleteWatermarkRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteWatermarkRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteWatermarkRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteWatermarkRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteWatermarkRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteWatermarkRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPOST);
        result->setPath(L"/words/{name}/watermarks/deleteLast");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteWatermarkRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteWatermarkResponse()
        );
    }

    /*
     * DeleteWatermarkOnline request implementation
     */
    DeleteWatermarkOnlineRequest::DeleteWatermarkOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > DeleteWatermarkOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > DeleteWatermarkOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > DeleteWatermarkOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > DeleteWatermarkOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > DeleteWatermarkOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > DeleteWatermarkOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DeleteWatermarkOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/post/watermarks/deleteLast");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DeleteWatermarkOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DeleteWatermarkOnlineResponse()
        );
    }

    /*
     * DownloadFile request implementation
     */
    DownloadFileRequest::DownloadFileRequest(
        const std::shared_ptr< std::wstring > path,
        const std::shared_ptr< std::wstring > storageName,
        const std::shared_ptr< std::wstring > versionId
    ) : 
        m_Path(path),
        m_StorageName(storageName),
        m_VersionId(versionId)
    {
    }

    const std::shared_ptr< std::wstring > DownloadFileRequest::getPath() const
    {
        return m_Path;
    }

    const std::shared_ptr< std::wstring > DownloadFileRequest::getStorageName() const
    {
        return m_StorageName;
    }

    const std::shared_ptr< std::wstring > DownloadFileRequest::getVersionId() const
    {
        return m_VersionId;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > DownloadFileRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/storage/file/{path}");
        if (!m_Path) throw aspose::words::cloud::ApiException(400, L"Parameter 'Path' is required.");
        result->setPathParam(L"{path}", *m_Path);
        if (m_StorageName) result->addQueryParam(L"storageName", *m_StorageName);
        if (m_VersionId) result->addQueryParam(L"versionId", *m_VersionId);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > DownloadFileRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::DownloadFileResponse()
        );
    }

    /*
     * ExecuteMailMerge request implementation
     */
    ExecuteMailMergeRequest::ExecuteMailMergeRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > data,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< bool > withRegions,
        const std::shared_ptr< std::wstring > mailMergeDataFile,
        const std::shared_ptr< std::wstring > cleanup,
        const std::shared_ptr< bool > useWholeParagraphAsRegion,
        const std::shared_ptr< std::wstring > destFileName
    ) : 
        m_Name(name),
        m_Data(data),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_WithRegions(withRegions),
        m_MailMergeDataFile(mailMergeDataFile),
        m_Cleanup(cleanup),
        m_UseWholeParagraphAsRegion(useWholeParagraphAsRegion),
        m_DestFileName(destFileName)
    {
    }

    const std::shared_ptr< std::wstring > ExecuteMailMergeRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > ExecuteMailMergeRequest::getData() const
    {
        return m_Data;
    }

    const std::shared_ptr< std::wstring > ExecuteMailMergeRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > ExecuteMailMergeRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > ExecuteMailMergeRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > ExecuteMailMergeRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< bool > ExecuteMailMergeRequest::getWithRegions() const
    {
        return m_WithRegions;
    }

    const std::shared_ptr< std::wstring > ExecuteMailMergeRequest::getMailMergeDataFile() const
    {
        return m_MailMergeDataFile;
    }

    const std::shared_ptr< std::wstring > ExecuteMailMergeRequest::getCleanup() const
    {
        return m_Cleanup;
    }

    const std::shared_ptr< bool > ExecuteMailMergeRequest::getUseWholeParagraphAsRegion() const
    {
        return m_UseWholeParagraphAsRegion;
    }

    const std::shared_ptr< std::wstring > ExecuteMailMergeRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > ExecuteMailMergeRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/MailMerge");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_WithRegions) result->addQueryParam(L"withRegions", *m_WithRegions);
        if (m_MailMergeDataFile) result->addQueryParam(L"mailMergeDataFile", *m_MailMergeDataFile);
        if (m_Cleanup) result->addQueryParam(L"cleanup", *m_Cleanup);
        if (m_UseWholeParagraphAsRegion) result->addQueryParam(L"useWholeParagraphAsRegion", *m_UseWholeParagraphAsRegion);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_Data) result->setBodyText(*m_Data);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > ExecuteMailMergeRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::ExecuteMailMergeResponse()
        );
    }

    /*
     * ExecuteMailMergeOnline request implementation
     */
    ExecuteMailMergeOnlineRequest::ExecuteMailMergeOnlineRequest(
        const std::shared_ptr< std::istream > _template,
        const std::shared_ptr< std::istream > data,
        const std::shared_ptr< bool > withRegions,
        const std::shared_ptr< std::wstring > cleanup,
        const std::shared_ptr< std::wstring > documentFileName
    ) : 
        m_Template(_template),
        m_Data(data),
        m_WithRegions(withRegions),
        m_Cleanup(cleanup),
        m_DocumentFileName(documentFileName)
    {
    }

    const std::shared_ptr< std::istream > ExecuteMailMergeOnlineRequest::getTemplate() const
    {
        return m_Template;
    }

    const std::shared_ptr< std::istream > ExecuteMailMergeOnlineRequest::getData() const
    {
        return m_Data;
    }

    const std::shared_ptr< bool > ExecuteMailMergeOnlineRequest::getWithRegions() const
    {
        return m_WithRegions;
    }

    const std::shared_ptr< std::wstring > ExecuteMailMergeOnlineRequest::getCleanup() const
    {
        return m_Cleanup;
    }

    const std::shared_ptr< std::wstring > ExecuteMailMergeOnlineRequest::getDocumentFileName() const
    {
        return m_DocumentFileName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > ExecuteMailMergeOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/MailMerge");
        if (m_WithRegions) result->addQueryParam(L"withRegions", *m_WithRegions);
        if (m_Cleanup) result->addQueryParam(L"cleanup", *m_Cleanup);
        if (m_DocumentFileName) result->addQueryParam(L"documentFileName", *m_DocumentFileName);
        if (m_Template) result->addFormDataParam(L"template", *m_Template);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Template' is required.");
        if (m_Data) result->addFormDataParam(L"data", *m_Data);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Data' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > ExecuteMailMergeOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::ExecuteMailMergeOnlineResponse()
        );
    }

    /*
     * GetAvailableFonts request implementation
     */
    GetAvailableFontsRequest::GetAvailableFontsRequest(
        const std::shared_ptr< std::wstring > fontsLocation
    ) : 
        m_FontsLocation(fontsLocation)
    {
    }

    const std::shared_ptr< std::wstring > GetAvailableFontsRequest::getFontsLocation() const
    {
        return m_FontsLocation;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetAvailableFontsRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/fonts/available");
        if (m_FontsLocation) result->addQueryParam(L"fontsLocation", *m_FontsLocation);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetAvailableFontsRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetAvailableFontsResponse()
        );
    }

    /*
     * GetBookmarkByName request implementation
     */
    GetBookmarkByNameRequest::GetBookmarkByNameRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > bookmarkName,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_BookmarkName(bookmarkName),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetBookmarkByNameRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetBookmarkByNameRequest::getBookmarkName() const
    {
        return m_BookmarkName;
    }

    const std::shared_ptr< std::wstring > GetBookmarkByNameRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetBookmarkByNameRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetBookmarkByNameRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetBookmarkByNameRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetBookmarkByNameRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/bookmarks/{bookmarkName}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_BookmarkName) throw aspose::words::cloud::ApiException(400, L"Parameter 'BookmarkName' is required.");
        result->setPathParam(L"{bookmarkName}", *m_BookmarkName);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetBookmarkByNameRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetBookmarkByNameResponse()
        );
    }

    /*
     * GetBookmarkByNameOnline request implementation
     */
    GetBookmarkByNameOnlineRequest::GetBookmarkByNameOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > bookmarkName,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_BookmarkName(bookmarkName),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetBookmarkByNameOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetBookmarkByNameOnlineRequest::getBookmarkName() const
    {
        return m_BookmarkName;
    }

    const std::shared_ptr< std::wstring > GetBookmarkByNameOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetBookmarkByNameOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetBookmarkByNameOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/bookmarks/{bookmarkName}");
        if (!m_BookmarkName) throw aspose::words::cloud::ApiException(400, L"Parameter 'BookmarkName' is required.");
        result->setPathParam(L"{bookmarkName}", *m_BookmarkName);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetBookmarkByNameOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetBookmarkByNameOnlineResponse()
        );
    }

    /*
     * GetBookmarks request implementation
     */
    GetBookmarksRequest::GetBookmarksRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetBookmarksRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetBookmarksRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetBookmarksRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetBookmarksRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetBookmarksRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetBookmarksRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/bookmarks");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetBookmarksRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetBookmarksResponse()
        );
    }

    /*
     * GetBookmarksOnline request implementation
     */
    GetBookmarksOnlineRequest::GetBookmarksOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetBookmarksOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetBookmarksOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetBookmarksOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetBookmarksOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/bookmarks");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetBookmarksOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetBookmarksOnlineResponse()
        );
    }

    /*
     * GetBorder request implementation
     */
    GetBorderRequest::GetBorderRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > borderType,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_BorderType(borderType),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetBorderRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetBorderRequest::getBorderType() const
    {
        return m_BorderType;
    }

    const std::shared_ptr< std::wstring > GetBorderRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetBorderRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetBorderRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetBorderRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetBorderRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetBorderRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{nodePath}/borders/{borderType}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_BorderType) throw aspose::words::cloud::ApiException(400, L"Parameter 'BorderType' is required.");
        result->setPathParam(L"{borderType}", *m_BorderType);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetBorderRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetBorderResponse()
        );
    }

    /*
     * GetBorderOnline request implementation
     */
    GetBorderOnlineRequest::GetBorderOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > borderType,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_BorderType(borderType),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetBorderOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetBorderOnlineRequest::getBorderType() const
    {
        return m_BorderType;
    }

    const std::shared_ptr< std::wstring > GetBorderOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetBorderOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetBorderOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetBorderOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{nodePath}/borders/{borderType}");
        if (!m_BorderType) throw aspose::words::cloud::ApiException(400, L"Parameter 'BorderType' is required.");
        result->setPathParam(L"{borderType}", *m_BorderType);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetBorderOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetBorderOnlineResponse()
        );
    }

    /*
     * GetBorders request implementation
     */
    GetBordersRequest::GetBordersRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetBordersRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetBordersRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetBordersRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetBordersRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetBordersRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetBordersRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetBordersRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{nodePath}/borders");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetBordersRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetBordersResponse()
        );
    }

    /*
     * GetBordersOnline request implementation
     */
    GetBordersOnlineRequest::GetBordersOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetBordersOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetBordersOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetBordersOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetBordersOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetBordersOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{nodePath}/borders");
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetBordersOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetBordersOnlineResponse()
        );
    }

    /*
     * GetComment request implementation
     */
    GetCommentRequest::GetCommentRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > commentIndex,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_CommentIndex(commentIndex),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetCommentRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > GetCommentRequest::getCommentIndex() const
    {
        return m_CommentIndex;
    }

    const std::shared_ptr< std::wstring > GetCommentRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetCommentRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetCommentRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetCommentRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetCommentRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/comments/{commentIndex}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_CommentIndex) throw aspose::words::cloud::ApiException(400, L"Parameter 'CommentIndex' is required.");
        result->setPathParam(L"{commentIndex}", *m_CommentIndex);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetCommentRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetCommentResponse()
        );
    }

    /*
     * GetCommentOnline request implementation
     */
    GetCommentOnlineRequest::GetCommentOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > commentIndex,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_CommentIndex(commentIndex),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetCommentOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > GetCommentOnlineRequest::getCommentIndex() const
    {
        return m_CommentIndex;
    }

    const std::shared_ptr< std::wstring > GetCommentOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetCommentOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetCommentOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/comments/{commentIndex}");
        if (!m_CommentIndex) throw aspose::words::cloud::ApiException(400, L"Parameter 'CommentIndex' is required.");
        result->setPathParam(L"{commentIndex}", *m_CommentIndex);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetCommentOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetCommentOnlineResponse()
        );
    }

    /*
     * GetComments request implementation
     */
    GetCommentsRequest::GetCommentsRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetCommentsRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetCommentsRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetCommentsRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetCommentsRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetCommentsRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetCommentsRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/comments");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetCommentsRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetCommentsResponse()
        );
    }

    /*
     * GetCommentsOnline request implementation
     */
    GetCommentsOnlineRequest::GetCommentsOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetCommentsOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetCommentsOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetCommentsOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetCommentsOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/comments");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetCommentsOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetCommentsOnlineResponse()
        );
    }

    /*
     * GetDocument request implementation
     */
    GetDocumentRequest::GetDocumentRequest(
        const std::shared_ptr< std::wstring > documentName,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_DocumentName(documentName),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetDocumentRequest::getDocumentName() const
    {
        return m_DocumentName;
    }

    const std::shared_ptr< std::wstring > GetDocumentRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetDocumentRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetDocumentRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetDocumentRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetDocumentRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{documentName}");
        if (!m_DocumentName) throw aspose::words::cloud::ApiException(400, L"Parameter 'DocumentName' is required.");
        result->setPathParam(L"{documentName}", *m_DocumentName);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetDocumentRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetDocumentResponse()
        );
    }

    /*
     * GetDocumentDrawingObjectByIndex request implementation
     */
    GetDocumentDrawingObjectByIndexRequest::GetDocumentDrawingObjectByIndexRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectByIndexRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > GetDocumentDrawingObjectByIndexRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectByIndexRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectByIndexRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectByIndexRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectByIndexRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectByIndexRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetDocumentDrawingObjectByIndexRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{nodePath}/drawingObjects/{index}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetDocumentDrawingObjectByIndexRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetDocumentDrawingObjectByIndexResponse()
        );
    }

    /*
     * GetDocumentDrawingObjectByIndexOnline request implementation
     */
    GetDocumentDrawingObjectByIndexOnlineRequest::GetDocumentDrawingObjectByIndexOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetDocumentDrawingObjectByIndexOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > GetDocumentDrawingObjectByIndexOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectByIndexOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectByIndexOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectByIndexOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetDocumentDrawingObjectByIndexOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{nodePath}/drawingObjects/{index}");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetDocumentDrawingObjectByIndexOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetDocumentDrawingObjectByIndexOnlineResponse()
        );
    }

    /*
     * GetDocumentDrawingObjectImageData request implementation
     */
    GetDocumentDrawingObjectImageDataRequest::GetDocumentDrawingObjectImageDataRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectImageDataRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > GetDocumentDrawingObjectImageDataRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectImageDataRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectImageDataRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectImageDataRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectImageDataRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectImageDataRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetDocumentDrawingObjectImageDataRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{nodePath}/drawingObjects/{index}/imageData");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetDocumentDrawingObjectImageDataRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetDocumentDrawingObjectImageDataResponse()
        );
    }

    /*
     * GetDocumentDrawingObjectImageDataOnline request implementation
     */
    GetDocumentDrawingObjectImageDataOnlineRequest::GetDocumentDrawingObjectImageDataOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetDocumentDrawingObjectImageDataOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > GetDocumentDrawingObjectImageDataOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectImageDataOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectImageDataOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectImageDataOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetDocumentDrawingObjectImageDataOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{nodePath}/drawingObjects/{index}/imageData");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetDocumentDrawingObjectImageDataOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetDocumentDrawingObjectImageDataOnlineResponse()
        );
    }

    /*
     * GetDocumentDrawingObjectOleData request implementation
     */
    GetDocumentDrawingObjectOleDataRequest::GetDocumentDrawingObjectOleDataRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectOleDataRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > GetDocumentDrawingObjectOleDataRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectOleDataRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectOleDataRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectOleDataRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectOleDataRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectOleDataRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetDocumentDrawingObjectOleDataRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{nodePath}/drawingObjects/{index}/oleData");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetDocumentDrawingObjectOleDataRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetDocumentDrawingObjectOleDataResponse()
        );
    }

    /*
     * GetDocumentDrawingObjectOleDataOnline request implementation
     */
    GetDocumentDrawingObjectOleDataOnlineRequest::GetDocumentDrawingObjectOleDataOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetDocumentDrawingObjectOleDataOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > GetDocumentDrawingObjectOleDataOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectOleDataOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectOleDataOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectOleDataOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetDocumentDrawingObjectOleDataOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{nodePath}/drawingObjects/{index}/oleData");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetDocumentDrawingObjectOleDataOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetDocumentDrawingObjectOleDataOnlineResponse()
        );
    }

    /*
     * GetDocumentDrawingObjects request implementation
     */
    GetDocumentDrawingObjectsRequest::GetDocumentDrawingObjectsRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectsRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectsRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectsRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectsRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectsRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectsRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetDocumentDrawingObjectsRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{nodePath}/drawingObjects");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetDocumentDrawingObjectsRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetDocumentDrawingObjectsResponse()
        );
    }

    /*
     * GetDocumentDrawingObjectsOnline request implementation
     */
    GetDocumentDrawingObjectsOnlineRequest::GetDocumentDrawingObjectsOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetDocumentDrawingObjectsOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectsOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectsOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetDocumentDrawingObjectsOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetDocumentDrawingObjectsOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{nodePath}/drawingObjects");
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetDocumentDrawingObjectsOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetDocumentDrawingObjectsOnlineResponse()
        );
    }

    /*
     * GetDocumentFieldNames request implementation
     */
    GetDocumentFieldNamesRequest::GetDocumentFieldNamesRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< bool > useNonMergeFields
    ) : 
        m_Name(name),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_UseNonMergeFields(useNonMergeFields)
    {
    }

    const std::shared_ptr< std::wstring > GetDocumentFieldNamesRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetDocumentFieldNamesRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetDocumentFieldNamesRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetDocumentFieldNamesRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetDocumentFieldNamesRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< bool > GetDocumentFieldNamesRequest::getUseNonMergeFields() const
    {
        return m_UseNonMergeFields;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetDocumentFieldNamesRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/mailMerge/FieldNames");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_UseNonMergeFields) result->addQueryParam(L"useNonMergeFields", *m_UseNonMergeFields);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetDocumentFieldNamesRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetDocumentFieldNamesResponse()
        );
    }

    /*
     * GetDocumentFieldNamesOnline request implementation
     */
    GetDocumentFieldNamesOnlineRequest::GetDocumentFieldNamesOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< bool > useNonMergeFields
    ) : 
        m_Document(document),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_UseNonMergeFields(useNonMergeFields)
    {
    }

    const std::shared_ptr< std::istream > GetDocumentFieldNamesOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetDocumentFieldNamesOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetDocumentFieldNamesOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< bool > GetDocumentFieldNamesOnlineRequest::getUseNonMergeFields() const
    {
        return m_UseNonMergeFields;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetDocumentFieldNamesOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/mailMerge/FieldNames");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_UseNonMergeFields) result->addQueryParam(L"useNonMergeFields", *m_UseNonMergeFields);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetDocumentFieldNamesOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetDocumentFieldNamesOnlineResponse()
        );
    }

    /*
     * GetDocumentHyperlinkByIndex request implementation
     */
    GetDocumentHyperlinkByIndexRequest::GetDocumentHyperlinkByIndexRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > hyperlinkIndex,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_HyperlinkIndex(hyperlinkIndex),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetDocumentHyperlinkByIndexRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > GetDocumentHyperlinkByIndexRequest::getHyperlinkIndex() const
    {
        return m_HyperlinkIndex;
    }

    const std::shared_ptr< std::wstring > GetDocumentHyperlinkByIndexRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetDocumentHyperlinkByIndexRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetDocumentHyperlinkByIndexRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetDocumentHyperlinkByIndexRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetDocumentHyperlinkByIndexRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/hyperlinks/{hyperlinkIndex}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_HyperlinkIndex) throw aspose::words::cloud::ApiException(400, L"Parameter 'HyperlinkIndex' is required.");
        result->setPathParam(L"{hyperlinkIndex}", *m_HyperlinkIndex);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetDocumentHyperlinkByIndexRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetDocumentHyperlinkByIndexResponse()
        );
    }

    /*
     * GetDocumentHyperlinkByIndexOnline request implementation
     */
    GetDocumentHyperlinkByIndexOnlineRequest::GetDocumentHyperlinkByIndexOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > hyperlinkIndex,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_HyperlinkIndex(hyperlinkIndex),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetDocumentHyperlinkByIndexOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > GetDocumentHyperlinkByIndexOnlineRequest::getHyperlinkIndex() const
    {
        return m_HyperlinkIndex;
    }

    const std::shared_ptr< std::wstring > GetDocumentHyperlinkByIndexOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetDocumentHyperlinkByIndexOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetDocumentHyperlinkByIndexOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/hyperlinks/{hyperlinkIndex}");
        if (!m_HyperlinkIndex) throw aspose::words::cloud::ApiException(400, L"Parameter 'HyperlinkIndex' is required.");
        result->setPathParam(L"{hyperlinkIndex}", *m_HyperlinkIndex);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetDocumentHyperlinkByIndexOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetDocumentHyperlinkByIndexOnlineResponse()
        );
    }

    /*
     * GetDocumentHyperlinks request implementation
     */
    GetDocumentHyperlinksRequest::GetDocumentHyperlinksRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetDocumentHyperlinksRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetDocumentHyperlinksRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetDocumentHyperlinksRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetDocumentHyperlinksRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetDocumentHyperlinksRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetDocumentHyperlinksRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/hyperlinks");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetDocumentHyperlinksRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetDocumentHyperlinksResponse()
        );
    }

    /*
     * GetDocumentHyperlinksOnline request implementation
     */
    GetDocumentHyperlinksOnlineRequest::GetDocumentHyperlinksOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetDocumentHyperlinksOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetDocumentHyperlinksOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetDocumentHyperlinksOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetDocumentHyperlinksOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/hyperlinks");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetDocumentHyperlinksOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetDocumentHyperlinksOnlineResponse()
        );
    }

    /*
     * GetDocumentProperties request implementation
     */
    GetDocumentPropertiesRequest::GetDocumentPropertiesRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetDocumentPropertiesRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetDocumentPropertiesRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetDocumentPropertiesRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetDocumentPropertiesRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetDocumentPropertiesRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetDocumentPropertiesRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/documentProperties");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetDocumentPropertiesRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetDocumentPropertiesResponse()
        );
    }

    /*
     * GetDocumentPropertiesOnline request implementation
     */
    GetDocumentPropertiesOnlineRequest::GetDocumentPropertiesOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetDocumentPropertiesOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetDocumentPropertiesOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetDocumentPropertiesOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetDocumentPropertiesOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/documentProperties");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetDocumentPropertiesOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetDocumentPropertiesOnlineResponse()
        );
    }

    /*
     * GetDocumentProperty request implementation
     */
    GetDocumentPropertyRequest::GetDocumentPropertyRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > propertyName,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_PropertyName(propertyName),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetDocumentPropertyRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetDocumentPropertyRequest::getPropertyName() const
    {
        return m_PropertyName;
    }

    const std::shared_ptr< std::wstring > GetDocumentPropertyRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetDocumentPropertyRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetDocumentPropertyRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetDocumentPropertyRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetDocumentPropertyRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/documentProperties/{propertyName}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_PropertyName) throw aspose::words::cloud::ApiException(400, L"Parameter 'PropertyName' is required.");
        result->setPathParam(L"{propertyName}", *m_PropertyName);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetDocumentPropertyRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetDocumentPropertyResponse()
        );
    }

    /*
     * GetDocumentPropertyOnline request implementation
     */
    GetDocumentPropertyOnlineRequest::GetDocumentPropertyOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > propertyName,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_PropertyName(propertyName),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetDocumentPropertyOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetDocumentPropertyOnlineRequest::getPropertyName() const
    {
        return m_PropertyName;
    }

    const std::shared_ptr< std::wstring > GetDocumentPropertyOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetDocumentPropertyOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetDocumentPropertyOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/documentProperties/{propertyName}");
        if (!m_PropertyName) throw aspose::words::cloud::ApiException(400, L"Parameter 'PropertyName' is required.");
        result->setPathParam(L"{propertyName}", *m_PropertyName);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetDocumentPropertyOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetDocumentPropertyOnlineResponse()
        );
    }

    /*
     * GetDocumentProtection request implementation
     */
    GetDocumentProtectionRequest::GetDocumentProtectionRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetDocumentProtectionRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetDocumentProtectionRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetDocumentProtectionRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetDocumentProtectionRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetDocumentProtectionRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetDocumentProtectionRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/protection");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetDocumentProtectionRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetDocumentProtectionResponse()
        );
    }

    /*
     * GetDocumentProtectionOnline request implementation
     */
    GetDocumentProtectionOnlineRequest::GetDocumentProtectionOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetDocumentProtectionOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetDocumentProtectionOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetDocumentProtectionOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetDocumentProtectionOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/protection");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetDocumentProtectionOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetDocumentProtectionOnlineResponse()
        );
    }

    /*
     * GetDocumentStatistics request implementation
     */
    GetDocumentStatisticsRequest::GetDocumentStatisticsRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< bool > includeComments,
        const std::shared_ptr< bool > includeFootnotes,
        const std::shared_ptr< bool > includeTextInShapes
    ) : 
        m_Name(name),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_IncludeComments(includeComments),
        m_IncludeFootnotes(includeFootnotes),
        m_IncludeTextInShapes(includeTextInShapes)
    {
    }

    const std::shared_ptr< std::wstring > GetDocumentStatisticsRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetDocumentStatisticsRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetDocumentStatisticsRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetDocumentStatisticsRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetDocumentStatisticsRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< bool > GetDocumentStatisticsRequest::getIncludeComments() const
    {
        return m_IncludeComments;
    }

    const std::shared_ptr< bool > GetDocumentStatisticsRequest::getIncludeFootnotes() const
    {
        return m_IncludeFootnotes;
    }

    const std::shared_ptr< bool > GetDocumentStatisticsRequest::getIncludeTextInShapes() const
    {
        return m_IncludeTextInShapes;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetDocumentStatisticsRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/statistics");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_IncludeComments) result->addQueryParam(L"includeComments", *m_IncludeComments);
        if (m_IncludeFootnotes) result->addQueryParam(L"includeFootnotes", *m_IncludeFootnotes);
        if (m_IncludeTextInShapes) result->addQueryParam(L"includeTextInShapes", *m_IncludeTextInShapes);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetDocumentStatisticsRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetDocumentStatisticsResponse()
        );
    }

    /*
     * GetDocumentStatisticsOnline request implementation
     */
    GetDocumentStatisticsOnlineRequest::GetDocumentStatisticsOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< bool > includeComments,
        const std::shared_ptr< bool > includeFootnotes,
        const std::shared_ptr< bool > includeTextInShapes
    ) : 
        m_Document(document),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_IncludeComments(includeComments),
        m_IncludeFootnotes(includeFootnotes),
        m_IncludeTextInShapes(includeTextInShapes)
    {
    }

    const std::shared_ptr< std::istream > GetDocumentStatisticsOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetDocumentStatisticsOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetDocumentStatisticsOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< bool > GetDocumentStatisticsOnlineRequest::getIncludeComments() const
    {
        return m_IncludeComments;
    }

    const std::shared_ptr< bool > GetDocumentStatisticsOnlineRequest::getIncludeFootnotes() const
    {
        return m_IncludeFootnotes;
    }

    const std::shared_ptr< bool > GetDocumentStatisticsOnlineRequest::getIncludeTextInShapes() const
    {
        return m_IncludeTextInShapes;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetDocumentStatisticsOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/statistics");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_IncludeComments) result->addQueryParam(L"includeComments", *m_IncludeComments);
        if (m_IncludeFootnotes) result->addQueryParam(L"includeFootnotes", *m_IncludeFootnotes);
        if (m_IncludeTextInShapes) result->addQueryParam(L"includeTextInShapes", *m_IncludeTextInShapes);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetDocumentStatisticsOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetDocumentStatisticsOnlineResponse()
        );
    }

    /*
     * GetDocumentWithFormat request implementation
     */
    GetDocumentWithFormatRequest::GetDocumentWithFormatRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > format,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > outPath,
        const std::shared_ptr< std::wstring > fontsLocation
    ) : 
        m_Name(name),
        m_Format(format),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_OutPath(outPath),
        m_FontsLocation(fontsLocation)
    {
    }

    const std::shared_ptr< std::wstring > GetDocumentWithFormatRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetDocumentWithFormatRequest::getFormat() const
    {
        return m_Format;
    }

    const std::shared_ptr< std::wstring > GetDocumentWithFormatRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetDocumentWithFormatRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetDocumentWithFormatRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetDocumentWithFormatRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > GetDocumentWithFormatRequest::getOutPath() const
    {
        return m_OutPath;
    }

    const std::shared_ptr< std::wstring > GetDocumentWithFormatRequest::getFontsLocation() const
    {
        return m_FontsLocation;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetDocumentWithFormatRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Format) result->addQueryParam(L"format", *m_Format);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Format' is required.");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_OutPath) result->addQueryParam(L"outPath", *m_OutPath);
        if (m_FontsLocation) result->addQueryParam(L"fontsLocation", *m_FontsLocation);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetDocumentWithFormatRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetDocumentWithFormatResponse()
        );
    }

    /*
     * GetField request implementation
     */
    GetFieldRequest::GetFieldRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetFieldRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > GetFieldRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetFieldRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetFieldRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetFieldRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetFieldRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetFieldRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetFieldRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{nodePath}/fields/{index}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetFieldRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetFieldResponse()
        );
    }

    /*
     * GetFieldOnline request implementation
     */
    GetFieldOnlineRequest::GetFieldOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetFieldOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > GetFieldOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetFieldOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetFieldOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetFieldOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetFieldOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{nodePath}/fields/{index}");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetFieldOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetFieldOnlineResponse()
        );
    }

    /*
     * GetFields request implementation
     */
    GetFieldsRequest::GetFieldsRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetFieldsRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetFieldsRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetFieldsRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetFieldsRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetFieldsRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetFieldsRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetFieldsRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{nodePath}/fields");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetFieldsRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetFieldsResponse()
        );
    }

    /*
     * GetFieldsOnline request implementation
     */
    GetFieldsOnlineRequest::GetFieldsOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetFieldsOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetFieldsOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetFieldsOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetFieldsOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetFieldsOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{nodePath}/fields");
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetFieldsOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetFieldsOnlineResponse()
        );
    }

    /*
     * GetFilesList request implementation
     */
    GetFilesListRequest::GetFilesListRequest(
        const std::shared_ptr< std::wstring > path,
        const std::shared_ptr< std::wstring > storageName
    ) : 
        m_Path(path),
        m_StorageName(storageName)
    {
    }

    const std::shared_ptr< std::wstring > GetFilesListRequest::getPath() const
    {
        return m_Path;
    }

    const std::shared_ptr< std::wstring > GetFilesListRequest::getStorageName() const
    {
        return m_StorageName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetFilesListRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/storage/folder/{path}");
        if (!m_Path) throw aspose::words::cloud::ApiException(400, L"Parameter 'Path' is required.");
        result->setPathParam(L"{path}", *m_Path);
        if (m_StorageName) result->addQueryParam(L"storageName", *m_StorageName);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetFilesListRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetFilesListResponse()
        );
    }

    /*
     * GetFootnote request implementation
     */
    GetFootnoteRequest::GetFootnoteRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetFootnoteRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > GetFootnoteRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetFootnoteRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetFootnoteRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetFootnoteRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetFootnoteRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetFootnoteRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetFootnoteRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{nodePath}/footnotes/{index}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetFootnoteRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetFootnoteResponse()
        );
    }

    /*
     * GetFootnoteOnline request implementation
     */
    GetFootnoteOnlineRequest::GetFootnoteOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetFootnoteOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > GetFootnoteOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetFootnoteOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetFootnoteOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetFootnoteOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetFootnoteOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{nodePath}/footnotes/{index}");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetFootnoteOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetFootnoteOnlineResponse()
        );
    }

    /*
     * GetFootnotes request implementation
     */
    GetFootnotesRequest::GetFootnotesRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetFootnotesRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetFootnotesRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetFootnotesRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetFootnotesRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetFootnotesRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetFootnotesRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetFootnotesRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{nodePath}/footnotes");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetFootnotesRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetFootnotesResponse()
        );
    }

    /*
     * GetFootnotesOnline request implementation
     */
    GetFootnotesOnlineRequest::GetFootnotesOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetFootnotesOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetFootnotesOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetFootnotesOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetFootnotesOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetFootnotesOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{nodePath}/footnotes");
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetFootnotesOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetFootnotesOnlineResponse()
        );
    }

    /*
     * GetFormField request implementation
     */
    GetFormFieldRequest::GetFormFieldRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetFormFieldRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > GetFormFieldRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetFormFieldRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetFormFieldRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetFormFieldRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetFormFieldRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetFormFieldRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetFormFieldRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{nodePath}/formfields/{index}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetFormFieldRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetFormFieldResponse()
        );
    }

    /*
     * GetFormFieldOnline request implementation
     */
    GetFormFieldOnlineRequest::GetFormFieldOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetFormFieldOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > GetFormFieldOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetFormFieldOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetFormFieldOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetFormFieldOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetFormFieldOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{nodePath}/formfields/{index}");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetFormFieldOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetFormFieldOnlineResponse()
        );
    }

    /*
     * GetFormFields request implementation
     */
    GetFormFieldsRequest::GetFormFieldsRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetFormFieldsRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetFormFieldsRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetFormFieldsRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetFormFieldsRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetFormFieldsRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetFormFieldsRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetFormFieldsRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{nodePath}/formfields");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetFormFieldsRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetFormFieldsResponse()
        );
    }

    /*
     * GetFormFieldsOnline request implementation
     */
    GetFormFieldsOnlineRequest::GetFormFieldsOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetFormFieldsOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetFormFieldsOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetFormFieldsOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetFormFieldsOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetFormFieldsOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{nodePath}/formfields");
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetFormFieldsOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetFormFieldsOnlineResponse()
        );
    }

    /*
     * GetHeaderFooter request implementation
     */
    GetHeaderFooterRequest::GetHeaderFooterRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > headerFooterIndex,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > filterByType
    ) : 
        m_Name(name),
        m_HeaderFooterIndex(headerFooterIndex),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_FilterByType(filterByType)
    {
    }

    const std::shared_ptr< std::wstring > GetHeaderFooterRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > GetHeaderFooterRequest::getHeaderFooterIndex() const
    {
        return m_HeaderFooterIndex;
    }

    const std::shared_ptr< std::wstring > GetHeaderFooterRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetHeaderFooterRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetHeaderFooterRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetHeaderFooterRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > GetHeaderFooterRequest::getFilterByType() const
    {
        return m_FilterByType;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetHeaderFooterRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/headersfooters/{headerFooterIndex}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_HeaderFooterIndex) throw aspose::words::cloud::ApiException(400, L"Parameter 'HeaderFooterIndex' is required.");
        result->setPathParam(L"{headerFooterIndex}", *m_HeaderFooterIndex);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_FilterByType) result->addQueryParam(L"filterByType", *m_FilterByType);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetHeaderFooterRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetHeaderFooterResponse()
        );
    }

    /*
     * GetHeaderFooterOfSection request implementation
     */
    GetHeaderFooterOfSectionRequest::GetHeaderFooterOfSectionRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > headerFooterIndex,
        const std::shared_ptr< int32_t > sectionIndex,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > filterByType
    ) : 
        m_Name(name),
        m_HeaderFooterIndex(headerFooterIndex),
        m_SectionIndex(sectionIndex),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_FilterByType(filterByType)
    {
    }

    const std::shared_ptr< std::wstring > GetHeaderFooterOfSectionRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > GetHeaderFooterOfSectionRequest::getHeaderFooterIndex() const
    {
        return m_HeaderFooterIndex;
    }

    const std::shared_ptr< int32_t > GetHeaderFooterOfSectionRequest::getSectionIndex() const
    {
        return m_SectionIndex;
    }

    const std::shared_ptr< std::wstring > GetHeaderFooterOfSectionRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetHeaderFooterOfSectionRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetHeaderFooterOfSectionRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetHeaderFooterOfSectionRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > GetHeaderFooterOfSectionRequest::getFilterByType() const
    {
        return m_FilterByType;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetHeaderFooterOfSectionRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/sections/{sectionIndex}/headersfooters/{headerFooterIndex}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_HeaderFooterIndex) throw aspose::words::cloud::ApiException(400, L"Parameter 'HeaderFooterIndex' is required.");
        result->setPathParam(L"{headerFooterIndex}", *m_HeaderFooterIndex);
        if (!m_SectionIndex) throw aspose::words::cloud::ApiException(400, L"Parameter 'SectionIndex' is required.");
        result->setPathParam(L"{sectionIndex}", *m_SectionIndex);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_FilterByType) result->addQueryParam(L"filterByType", *m_FilterByType);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetHeaderFooterOfSectionRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetHeaderFooterOfSectionResponse()
        );
    }

    /*
     * GetHeaderFooterOfSectionOnline request implementation
     */
    GetHeaderFooterOfSectionOnlineRequest::GetHeaderFooterOfSectionOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > headerFooterIndex,
        const std::shared_ptr< int32_t > sectionIndex,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > filterByType
    ) : 
        m_Document(document),
        m_HeaderFooterIndex(headerFooterIndex),
        m_SectionIndex(sectionIndex),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_FilterByType(filterByType)
    {
    }

    const std::shared_ptr< std::istream > GetHeaderFooterOfSectionOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > GetHeaderFooterOfSectionOnlineRequest::getHeaderFooterIndex() const
    {
        return m_HeaderFooterIndex;
    }

    const std::shared_ptr< int32_t > GetHeaderFooterOfSectionOnlineRequest::getSectionIndex() const
    {
        return m_SectionIndex;
    }

    const std::shared_ptr< std::wstring > GetHeaderFooterOfSectionOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetHeaderFooterOfSectionOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > GetHeaderFooterOfSectionOnlineRequest::getFilterByType() const
    {
        return m_FilterByType;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetHeaderFooterOfSectionOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/sections/{sectionIndex}/headersfooters/{headerFooterIndex}");
        if (!m_HeaderFooterIndex) throw aspose::words::cloud::ApiException(400, L"Parameter 'HeaderFooterIndex' is required.");
        result->setPathParam(L"{headerFooterIndex}", *m_HeaderFooterIndex);
        if (!m_SectionIndex) throw aspose::words::cloud::ApiException(400, L"Parameter 'SectionIndex' is required.");
        result->setPathParam(L"{sectionIndex}", *m_SectionIndex);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_FilterByType) result->addQueryParam(L"filterByType", *m_FilterByType);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetHeaderFooterOfSectionOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetHeaderFooterOfSectionOnlineResponse()
        );
    }

    /*
     * GetHeaderFooterOnline request implementation
     */
    GetHeaderFooterOnlineRequest::GetHeaderFooterOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > headerFooterIndex,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > filterByType
    ) : 
        m_Document(document),
        m_HeaderFooterIndex(headerFooterIndex),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_FilterByType(filterByType)
    {
    }

    const std::shared_ptr< std::istream > GetHeaderFooterOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > GetHeaderFooterOnlineRequest::getHeaderFooterIndex() const
    {
        return m_HeaderFooterIndex;
    }

    const std::shared_ptr< std::wstring > GetHeaderFooterOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetHeaderFooterOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > GetHeaderFooterOnlineRequest::getFilterByType() const
    {
        return m_FilterByType;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetHeaderFooterOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/headersfooters/{headerFooterIndex}");
        if (!m_HeaderFooterIndex) throw aspose::words::cloud::ApiException(400, L"Parameter 'HeaderFooterIndex' is required.");
        result->setPathParam(L"{headerFooterIndex}", *m_HeaderFooterIndex);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_FilterByType) result->addQueryParam(L"filterByType", *m_FilterByType);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetHeaderFooterOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetHeaderFooterOnlineResponse()
        );
    }

    /*
     * GetHeaderFooters request implementation
     */
    GetHeaderFootersRequest::GetHeaderFootersRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > sectionPath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > filterByType
    ) : 
        m_Name(name),
        m_SectionPath(sectionPath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_FilterByType(filterByType)
    {
    }

    const std::shared_ptr< std::wstring > GetHeaderFootersRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetHeaderFootersRequest::getSectionPath() const
    {
        return m_SectionPath;
    }

    const std::shared_ptr< std::wstring > GetHeaderFootersRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetHeaderFootersRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetHeaderFootersRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetHeaderFootersRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > GetHeaderFootersRequest::getFilterByType() const
    {
        return m_FilterByType;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetHeaderFootersRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{sectionPath}/headersfooters");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_SectionPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'SectionPath' is required.");
        result->setPathParam(L"{sectionPath}", *m_SectionPath);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_FilterByType) result->addQueryParam(L"filterByType", *m_FilterByType);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetHeaderFootersRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetHeaderFootersResponse()
        );
    }

    /*
     * GetHeaderFootersOnline request implementation
     */
    GetHeaderFootersOnlineRequest::GetHeaderFootersOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > sectionPath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > filterByType
    ) : 
        m_Document(document),
        m_SectionPath(sectionPath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_FilterByType(filterByType)
    {
    }

    const std::shared_ptr< std::istream > GetHeaderFootersOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetHeaderFootersOnlineRequest::getSectionPath() const
    {
        return m_SectionPath;
    }

    const std::shared_ptr< std::wstring > GetHeaderFootersOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetHeaderFootersOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > GetHeaderFootersOnlineRequest::getFilterByType() const
    {
        return m_FilterByType;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetHeaderFootersOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{sectionPath}/headersfooters");
        if (!m_SectionPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'SectionPath' is required.");
        result->setPathParam(L"{sectionPath}", *m_SectionPath);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_FilterByType) result->addQueryParam(L"filterByType", *m_FilterByType);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetHeaderFootersOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetHeaderFootersOnlineResponse()
        );
    }

    /*
     * GetList request implementation
     */
    GetListRequest::GetListRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > listId,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_ListId(listId),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetListRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > GetListRequest::getListId() const
    {
        return m_ListId;
    }

    const std::shared_ptr< std::wstring > GetListRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetListRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetListRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetListRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetListRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/lists/{listId}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_ListId) throw aspose::words::cloud::ApiException(400, L"Parameter 'ListId' is required.");
        result->setPathParam(L"{listId}", *m_ListId);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetListRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetListResponse()
        );
    }

    /*
     * GetListOnline request implementation
     */
    GetListOnlineRequest::GetListOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > listId,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_ListId(listId),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetListOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > GetListOnlineRequest::getListId() const
    {
        return m_ListId;
    }

    const std::shared_ptr< std::wstring > GetListOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetListOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetListOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPOST);
        result->setPath(L"/words/online/get/lists/{listId}");
        if (!m_ListId) throw aspose::words::cloud::ApiException(400, L"Parameter 'ListId' is required.");
        result->setPathParam(L"{listId}", *m_ListId);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetListOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetListOnlineResponse()
        );
    }

    /*
     * GetLists request implementation
     */
    GetListsRequest::GetListsRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetListsRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetListsRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetListsRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetListsRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetListsRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetListsRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/lists");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetListsRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetListsResponse()
        );
    }

    /*
     * GetListsOnline request implementation
     */
    GetListsOnlineRequest::GetListsOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetListsOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetListsOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetListsOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetListsOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/lists");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetListsOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetListsOnlineResponse()
        );
    }

    /*
     * GetOfficeMathObject request implementation
     */
    GetOfficeMathObjectRequest::GetOfficeMathObjectRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetOfficeMathObjectRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > GetOfficeMathObjectRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetOfficeMathObjectRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetOfficeMathObjectRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetOfficeMathObjectRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetOfficeMathObjectRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetOfficeMathObjectRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetOfficeMathObjectRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{nodePath}/OfficeMathObjects/{index}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetOfficeMathObjectRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetOfficeMathObjectResponse()
        );
    }

    /*
     * GetOfficeMathObjectOnline request implementation
     */
    GetOfficeMathObjectOnlineRequest::GetOfficeMathObjectOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetOfficeMathObjectOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > GetOfficeMathObjectOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetOfficeMathObjectOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetOfficeMathObjectOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetOfficeMathObjectOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetOfficeMathObjectOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{nodePath}/OfficeMathObjects/{index}");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetOfficeMathObjectOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetOfficeMathObjectOnlineResponse()
        );
    }

    /*
     * GetOfficeMathObjects request implementation
     */
    GetOfficeMathObjectsRequest::GetOfficeMathObjectsRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetOfficeMathObjectsRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetOfficeMathObjectsRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetOfficeMathObjectsRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetOfficeMathObjectsRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetOfficeMathObjectsRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetOfficeMathObjectsRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetOfficeMathObjectsRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{nodePath}/OfficeMathObjects");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetOfficeMathObjectsRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetOfficeMathObjectsResponse()
        );
    }

    /*
     * GetOfficeMathObjectsOnline request implementation
     */
    GetOfficeMathObjectsOnlineRequest::GetOfficeMathObjectsOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetOfficeMathObjectsOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetOfficeMathObjectsOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetOfficeMathObjectsOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetOfficeMathObjectsOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetOfficeMathObjectsOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{nodePath}/OfficeMathObjects");
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetOfficeMathObjectsOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetOfficeMathObjectsOnlineResponse()
        );
    }

    /*
     * GetParagraph request implementation
     */
    GetParagraphRequest::GetParagraphRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetParagraphRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > GetParagraphRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetParagraphRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetParagraphRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetParagraphRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetParagraphRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetParagraphRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetParagraphRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{nodePath}/paragraphs/{index}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetParagraphRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetParagraphResponse()
        );
    }

    /*
     * GetParagraphFormat request implementation
     */
    GetParagraphFormatRequest::GetParagraphFormatRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetParagraphFormatRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > GetParagraphFormatRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetParagraphFormatRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetParagraphFormatRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetParagraphFormatRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetParagraphFormatRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetParagraphFormatRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetParagraphFormatRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{nodePath}/paragraphs/{index}/format");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetParagraphFormatRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetParagraphFormatResponse()
        );
    }

    /*
     * GetParagraphFormatOnline request implementation
     */
    GetParagraphFormatOnlineRequest::GetParagraphFormatOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetParagraphFormatOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > GetParagraphFormatOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetParagraphFormatOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetParagraphFormatOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetParagraphFormatOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetParagraphFormatOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{nodePath}/paragraphs/{index}/format");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetParagraphFormatOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetParagraphFormatOnlineResponse()
        );
    }

    /*
     * GetParagraphListFormat request implementation
     */
    GetParagraphListFormatRequest::GetParagraphListFormatRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetParagraphListFormatRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > GetParagraphListFormatRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetParagraphListFormatRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetParagraphListFormatRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetParagraphListFormatRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetParagraphListFormatRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetParagraphListFormatRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetParagraphListFormatRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{nodePath}/paragraphs/{index}/listFormat");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetParagraphListFormatRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetParagraphListFormatResponse()
        );
    }

    /*
     * GetParagraphListFormatOnline request implementation
     */
    GetParagraphListFormatOnlineRequest::GetParagraphListFormatOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetParagraphListFormatOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > GetParagraphListFormatOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetParagraphListFormatOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetParagraphListFormatOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetParagraphListFormatOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetParagraphListFormatOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{nodePath}/paragraphs/{index}/listFormat");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetParagraphListFormatOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetParagraphListFormatOnlineResponse()
        );
    }

    /*
     * GetParagraphOnline request implementation
     */
    GetParagraphOnlineRequest::GetParagraphOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetParagraphOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > GetParagraphOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetParagraphOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetParagraphOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetParagraphOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetParagraphOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{nodePath}/paragraphs/{index}");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetParagraphOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetParagraphOnlineResponse()
        );
    }

    /*
     * GetParagraphs request implementation
     */
    GetParagraphsRequest::GetParagraphsRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetParagraphsRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetParagraphsRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetParagraphsRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetParagraphsRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetParagraphsRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetParagraphsRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetParagraphsRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{nodePath}/paragraphs");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetParagraphsRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetParagraphsResponse()
        );
    }

    /*
     * GetParagraphsOnline request implementation
     */
    GetParagraphsOnlineRequest::GetParagraphsOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetParagraphsOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetParagraphsOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetParagraphsOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetParagraphsOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetParagraphsOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{nodePath}/paragraphs");
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetParagraphsOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetParagraphsOnlineResponse()
        );
    }

    /*
     * GetParagraphTabStops request implementation
     */
    GetParagraphTabStopsRequest::GetParagraphTabStopsRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetParagraphTabStopsRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > GetParagraphTabStopsRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetParagraphTabStopsRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetParagraphTabStopsRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetParagraphTabStopsRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetParagraphTabStopsRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetParagraphTabStopsRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetParagraphTabStopsRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{nodePath}/paragraphs/{index}/tabstops");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetParagraphTabStopsRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetParagraphTabStopsResponse()
        );
    }

    /*
     * GetParagraphTabStopsOnline request implementation
     */
    GetParagraphTabStopsOnlineRequest::GetParagraphTabStopsOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetParagraphTabStopsOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > GetParagraphTabStopsOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetParagraphTabStopsOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetParagraphTabStopsOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetParagraphTabStopsOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetParagraphTabStopsOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{nodePath}/paragraphs/{index}/tabstops");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetParagraphTabStopsOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetParagraphTabStopsOnlineResponse()
        );
    }

    /*
     * GetRangeText request implementation
     */
    GetRangeTextRequest::GetRangeTextRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > rangeStartIdentifier,
        const std::shared_ptr< std::wstring > rangeEndIdentifier,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_RangeStartIdentifier(rangeStartIdentifier),
        m_RangeEndIdentifier(rangeEndIdentifier),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetRangeTextRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetRangeTextRequest::getRangeStartIdentifier() const
    {
        return m_RangeStartIdentifier;
    }

    const std::shared_ptr< std::wstring > GetRangeTextRequest::getRangeEndIdentifier() const
    {
        return m_RangeEndIdentifier;
    }

    const std::shared_ptr< std::wstring > GetRangeTextRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetRangeTextRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetRangeTextRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetRangeTextRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetRangeTextRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/range/{rangeStartIdentifier}/{rangeEndIdentifier}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_RangeStartIdentifier) throw aspose::words::cloud::ApiException(400, L"Parameter 'RangeStartIdentifier' is required.");
        result->setPathParam(L"{rangeStartIdentifier}", *m_RangeStartIdentifier);
        result->setPathParam(L"{rangeEndIdentifier}", m_RangeEndIdentifier ? *m_RangeEndIdentifier : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetRangeTextRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetRangeTextResponse()
        );
    }

    /*
     * GetRangeTextOnline request implementation
     */
    GetRangeTextOnlineRequest::GetRangeTextOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > rangeStartIdentifier,
        const std::shared_ptr< std::wstring > rangeEndIdentifier,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_RangeStartIdentifier(rangeStartIdentifier),
        m_RangeEndIdentifier(rangeEndIdentifier),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetRangeTextOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetRangeTextOnlineRequest::getRangeStartIdentifier() const
    {
        return m_RangeStartIdentifier;
    }

    const std::shared_ptr< std::wstring > GetRangeTextOnlineRequest::getRangeEndIdentifier() const
    {
        return m_RangeEndIdentifier;
    }

    const std::shared_ptr< std::wstring > GetRangeTextOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetRangeTextOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetRangeTextOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/range/{rangeStartIdentifier}/{rangeEndIdentifier}");
        if (!m_RangeStartIdentifier) throw aspose::words::cloud::ApiException(400, L"Parameter 'RangeStartIdentifier' is required.");
        result->setPathParam(L"{rangeStartIdentifier}", *m_RangeStartIdentifier);
        result->setPathParam(L"{rangeEndIdentifier}", m_RangeEndIdentifier ? *m_RangeEndIdentifier : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetRangeTextOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetRangeTextOnlineResponse()
        );
    }

    /*
     * GetRun request implementation
     */
    GetRunRequest::GetRunRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > paragraphPath,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_ParagraphPath(paragraphPath),
        m_Index(index),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetRunRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetRunRequest::getParagraphPath() const
    {
        return m_ParagraphPath;
    }

    const std::shared_ptr< int32_t > GetRunRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetRunRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetRunRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetRunRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetRunRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetRunRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{paragraphPath}/runs/{index}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_ParagraphPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'ParagraphPath' is required.");
        result->setPathParam(L"{paragraphPath}", *m_ParagraphPath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetRunRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetRunResponse()
        );
    }

    /*
     * GetRunFont request implementation
     */
    GetRunFontRequest::GetRunFontRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > paragraphPath,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_ParagraphPath(paragraphPath),
        m_Index(index),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetRunFontRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetRunFontRequest::getParagraphPath() const
    {
        return m_ParagraphPath;
    }

    const std::shared_ptr< int32_t > GetRunFontRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetRunFontRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetRunFontRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetRunFontRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetRunFontRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetRunFontRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{paragraphPath}/runs/{index}/font");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_ParagraphPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'ParagraphPath' is required.");
        result->setPathParam(L"{paragraphPath}", *m_ParagraphPath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetRunFontRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetRunFontResponse()
        );
    }

    /*
     * GetRunFontOnline request implementation
     */
    GetRunFontOnlineRequest::GetRunFontOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > paragraphPath,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_ParagraphPath(paragraphPath),
        m_Index(index),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetRunFontOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetRunFontOnlineRequest::getParagraphPath() const
    {
        return m_ParagraphPath;
    }

    const std::shared_ptr< int32_t > GetRunFontOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetRunFontOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetRunFontOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetRunFontOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{paragraphPath}/runs/{index}/font");
        if (!m_ParagraphPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'ParagraphPath' is required.");
        result->setPathParam(L"{paragraphPath}", *m_ParagraphPath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetRunFontOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetRunFontOnlineResponse()
        );
    }

    /*
     * GetRunOnline request implementation
     */
    GetRunOnlineRequest::GetRunOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > paragraphPath,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_ParagraphPath(paragraphPath),
        m_Index(index),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetRunOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetRunOnlineRequest::getParagraphPath() const
    {
        return m_ParagraphPath;
    }

    const std::shared_ptr< int32_t > GetRunOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetRunOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetRunOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetRunOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{paragraphPath}/runs/{index}");
        if (!m_ParagraphPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'ParagraphPath' is required.");
        result->setPathParam(L"{paragraphPath}", *m_ParagraphPath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetRunOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetRunOnlineResponse()
        );
    }

    /*
     * GetRuns request implementation
     */
    GetRunsRequest::GetRunsRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > paragraphPath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_ParagraphPath(paragraphPath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetRunsRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetRunsRequest::getParagraphPath() const
    {
        return m_ParagraphPath;
    }

    const std::shared_ptr< std::wstring > GetRunsRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetRunsRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetRunsRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetRunsRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetRunsRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{paragraphPath}/runs");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_ParagraphPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'ParagraphPath' is required.");
        result->setPathParam(L"{paragraphPath}", *m_ParagraphPath);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetRunsRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetRunsResponse()
        );
    }

    /*
     * GetRunsOnline request implementation
     */
    GetRunsOnlineRequest::GetRunsOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > paragraphPath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_ParagraphPath(paragraphPath),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetRunsOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetRunsOnlineRequest::getParagraphPath() const
    {
        return m_ParagraphPath;
    }

    const std::shared_ptr< std::wstring > GetRunsOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetRunsOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetRunsOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{paragraphPath}/runs");
        if (!m_ParagraphPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'ParagraphPath' is required.");
        result->setPathParam(L"{paragraphPath}", *m_ParagraphPath);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetRunsOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetRunsOnlineResponse()
        );
    }

    /*
     * GetSection request implementation
     */
    GetSectionRequest::GetSectionRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > sectionIndex,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_SectionIndex(sectionIndex),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetSectionRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > GetSectionRequest::getSectionIndex() const
    {
        return m_SectionIndex;
    }

    const std::shared_ptr< std::wstring > GetSectionRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetSectionRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetSectionRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetSectionRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetSectionRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/sections/{sectionIndex}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_SectionIndex) throw aspose::words::cloud::ApiException(400, L"Parameter 'SectionIndex' is required.");
        result->setPathParam(L"{sectionIndex}", *m_SectionIndex);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetSectionRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetSectionResponse()
        );
    }

    /*
     * GetSectionOnline request implementation
     */
    GetSectionOnlineRequest::GetSectionOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > sectionIndex,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_SectionIndex(sectionIndex),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetSectionOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > GetSectionOnlineRequest::getSectionIndex() const
    {
        return m_SectionIndex;
    }

    const std::shared_ptr< std::wstring > GetSectionOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetSectionOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetSectionOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/sections/{sectionIndex}");
        if (!m_SectionIndex) throw aspose::words::cloud::ApiException(400, L"Parameter 'SectionIndex' is required.");
        result->setPathParam(L"{sectionIndex}", *m_SectionIndex);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetSectionOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetSectionOnlineResponse()
        );
    }

    /*
     * GetSectionPageSetup request implementation
     */
    GetSectionPageSetupRequest::GetSectionPageSetupRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > sectionIndex,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_SectionIndex(sectionIndex),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetSectionPageSetupRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > GetSectionPageSetupRequest::getSectionIndex() const
    {
        return m_SectionIndex;
    }

    const std::shared_ptr< std::wstring > GetSectionPageSetupRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetSectionPageSetupRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetSectionPageSetupRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetSectionPageSetupRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetSectionPageSetupRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/sections/{sectionIndex}/pageSetup");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_SectionIndex) throw aspose::words::cloud::ApiException(400, L"Parameter 'SectionIndex' is required.");
        result->setPathParam(L"{sectionIndex}", *m_SectionIndex);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetSectionPageSetupRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetSectionPageSetupResponse()
        );
    }

    /*
     * GetSectionPageSetupOnline request implementation
     */
    GetSectionPageSetupOnlineRequest::GetSectionPageSetupOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > sectionIndex,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_SectionIndex(sectionIndex),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetSectionPageSetupOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > GetSectionPageSetupOnlineRequest::getSectionIndex() const
    {
        return m_SectionIndex;
    }

    const std::shared_ptr< std::wstring > GetSectionPageSetupOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetSectionPageSetupOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetSectionPageSetupOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/sections/{sectionIndex}/pageSetup");
        if (!m_SectionIndex) throw aspose::words::cloud::ApiException(400, L"Parameter 'SectionIndex' is required.");
        result->setPathParam(L"{sectionIndex}", *m_SectionIndex);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetSectionPageSetupOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetSectionPageSetupOnlineResponse()
        );
    }

    /*
     * GetSections request implementation
     */
    GetSectionsRequest::GetSectionsRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetSectionsRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetSectionsRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetSectionsRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetSectionsRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetSectionsRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetSectionsRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/sections");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetSectionsRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetSectionsResponse()
        );
    }

    /*
     * GetSectionsOnline request implementation
     */
    GetSectionsOnlineRequest::GetSectionsOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetSectionsOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetSectionsOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetSectionsOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetSectionsOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/sections");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetSectionsOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetSectionsOnlineResponse()
        );
    }

    /*
     * GetStyle request implementation
     */
    GetStyleRequest::GetStyleRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > styleName,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_StyleName(styleName),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetStyleRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetStyleRequest::getStyleName() const
    {
        return m_StyleName;
    }

    const std::shared_ptr< std::wstring > GetStyleRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetStyleRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetStyleRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetStyleRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetStyleRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/styles/{styleName}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_StyleName) throw aspose::words::cloud::ApiException(400, L"Parameter 'StyleName' is required.");
        result->setPathParam(L"{styleName}", *m_StyleName);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetStyleRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetStyleResponse()
        );
    }

    /*
     * GetStyleFromDocumentElement request implementation
     */
    GetStyleFromDocumentElementRequest::GetStyleFromDocumentElementRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > styledNodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_StyledNodePath(styledNodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetStyleFromDocumentElementRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetStyleFromDocumentElementRequest::getStyledNodePath() const
    {
        return m_StyledNodePath;
    }

    const std::shared_ptr< std::wstring > GetStyleFromDocumentElementRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetStyleFromDocumentElementRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetStyleFromDocumentElementRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetStyleFromDocumentElementRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetStyleFromDocumentElementRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{styledNodePath}/style");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_StyledNodePath) throw aspose::words::cloud::ApiException(400, L"Parameter 'StyledNodePath' is required.");
        result->setPathParam(L"{styledNodePath}", *m_StyledNodePath);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetStyleFromDocumentElementRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetStyleFromDocumentElementResponse()
        );
    }

    /*
     * GetStyleFromDocumentElementOnline request implementation
     */
    GetStyleFromDocumentElementOnlineRequest::GetStyleFromDocumentElementOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > styledNodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_StyledNodePath(styledNodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetStyleFromDocumentElementOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetStyleFromDocumentElementOnlineRequest::getStyledNodePath() const
    {
        return m_StyledNodePath;
    }

    const std::shared_ptr< std::wstring > GetStyleFromDocumentElementOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetStyleFromDocumentElementOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetStyleFromDocumentElementOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{styledNodePath}/style");
        if (!m_StyledNodePath) throw aspose::words::cloud::ApiException(400, L"Parameter 'StyledNodePath' is required.");
        result->setPathParam(L"{styledNodePath}", *m_StyledNodePath);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetStyleFromDocumentElementOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetStyleFromDocumentElementOnlineResponse()
        );
    }

    /*
     * GetStyleOnline request implementation
     */
    GetStyleOnlineRequest::GetStyleOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > styleName,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_StyleName(styleName),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetStyleOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetStyleOnlineRequest::getStyleName() const
    {
        return m_StyleName;
    }

    const std::shared_ptr< std::wstring > GetStyleOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetStyleOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetStyleOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/styles/{styleName}");
        if (!m_StyleName) throw aspose::words::cloud::ApiException(400, L"Parameter 'StyleName' is required.");
        result->setPathParam(L"{styleName}", *m_StyleName);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetStyleOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetStyleOnlineResponse()
        );
    }

    /*
     * GetStyles request implementation
     */
    GetStylesRequest::GetStylesRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetStylesRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetStylesRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetStylesRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetStylesRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetStylesRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetStylesRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/styles");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetStylesRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetStylesResponse()
        );
    }

    /*
     * GetStylesOnline request implementation
     */
    GetStylesOnlineRequest::GetStylesOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetStylesOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetStylesOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetStylesOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetStylesOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/styles");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetStylesOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetStylesOnlineResponse()
        );
    }

    /*
     * GetTable request implementation
     */
    GetTableRequest::GetTableRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetTableRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > GetTableRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetTableRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetTableRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetTableRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetTableRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetTableRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetTableRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{nodePath}/tables/{index}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetTableRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetTableResponse()
        );
    }

    /*
     * GetTableCell request implementation
     */
    GetTableCellRequest::GetTableCellRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > tableRowPath,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_TableRowPath(tableRowPath),
        m_Index(index),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetTableCellRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetTableCellRequest::getTableRowPath() const
    {
        return m_TableRowPath;
    }

    const std::shared_ptr< int32_t > GetTableCellRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetTableCellRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetTableCellRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetTableCellRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetTableCellRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetTableCellRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{tableRowPath}/cells/{index}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_TableRowPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'TableRowPath' is required.");
        result->setPathParam(L"{tableRowPath}", *m_TableRowPath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetTableCellRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetTableCellResponse()
        );
    }

    /*
     * GetTableCellFormat request implementation
     */
    GetTableCellFormatRequest::GetTableCellFormatRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > tableRowPath,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_TableRowPath(tableRowPath),
        m_Index(index),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetTableCellFormatRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetTableCellFormatRequest::getTableRowPath() const
    {
        return m_TableRowPath;
    }

    const std::shared_ptr< int32_t > GetTableCellFormatRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetTableCellFormatRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetTableCellFormatRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetTableCellFormatRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetTableCellFormatRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetTableCellFormatRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{tableRowPath}/cells/{index}/cellformat");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_TableRowPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'TableRowPath' is required.");
        result->setPathParam(L"{tableRowPath}", *m_TableRowPath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetTableCellFormatRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetTableCellFormatResponse()
        );
    }

    /*
     * GetTableCellFormatOnline request implementation
     */
    GetTableCellFormatOnlineRequest::GetTableCellFormatOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > tableRowPath,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_TableRowPath(tableRowPath),
        m_Index(index),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetTableCellFormatOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetTableCellFormatOnlineRequest::getTableRowPath() const
    {
        return m_TableRowPath;
    }

    const std::shared_ptr< int32_t > GetTableCellFormatOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetTableCellFormatOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetTableCellFormatOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetTableCellFormatOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{tableRowPath}/cells/{index}/cellformat");
        if (!m_TableRowPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'TableRowPath' is required.");
        result->setPathParam(L"{tableRowPath}", *m_TableRowPath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetTableCellFormatOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetTableCellFormatOnlineResponse()
        );
    }

    /*
     * GetTableCellOnline request implementation
     */
    GetTableCellOnlineRequest::GetTableCellOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > tableRowPath,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_TableRowPath(tableRowPath),
        m_Index(index),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetTableCellOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetTableCellOnlineRequest::getTableRowPath() const
    {
        return m_TableRowPath;
    }

    const std::shared_ptr< int32_t > GetTableCellOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetTableCellOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetTableCellOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetTableCellOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{tableRowPath}/cells/{index}");
        if (!m_TableRowPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'TableRowPath' is required.");
        result->setPathParam(L"{tableRowPath}", *m_TableRowPath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetTableCellOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetTableCellOnlineResponse()
        );
    }

    /*
     * GetTableOnline request implementation
     */
    GetTableOnlineRequest::GetTableOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetTableOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > GetTableOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetTableOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetTableOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetTableOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetTableOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{nodePath}/tables/{index}");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetTableOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetTableOnlineResponse()
        );
    }

    /*
     * GetTableProperties request implementation
     */
    GetTablePropertiesRequest::GetTablePropertiesRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetTablePropertiesRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > GetTablePropertiesRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetTablePropertiesRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetTablePropertiesRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetTablePropertiesRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetTablePropertiesRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetTablePropertiesRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetTablePropertiesRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{nodePath}/tables/{index}/properties");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetTablePropertiesRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetTablePropertiesResponse()
        );
    }

    /*
     * GetTablePropertiesOnline request implementation
     */
    GetTablePropertiesOnlineRequest::GetTablePropertiesOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetTablePropertiesOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > GetTablePropertiesOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetTablePropertiesOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetTablePropertiesOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetTablePropertiesOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetTablePropertiesOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{nodePath}/tables/{index}/properties");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetTablePropertiesOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetTablePropertiesOnlineResponse()
        );
    }

    /*
     * GetTableRow request implementation
     */
    GetTableRowRequest::GetTableRowRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > tablePath,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_TablePath(tablePath),
        m_Index(index),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetTableRowRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetTableRowRequest::getTablePath() const
    {
        return m_TablePath;
    }

    const std::shared_ptr< int32_t > GetTableRowRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetTableRowRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetTableRowRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetTableRowRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetTableRowRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetTableRowRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{tablePath}/rows/{index}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_TablePath) throw aspose::words::cloud::ApiException(400, L"Parameter 'TablePath' is required.");
        result->setPathParam(L"{tablePath}", *m_TablePath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetTableRowRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetTableRowResponse()
        );
    }

    /*
     * GetTableRowFormat request implementation
     */
    GetTableRowFormatRequest::GetTableRowFormatRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > tablePath,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_TablePath(tablePath),
        m_Index(index),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetTableRowFormatRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetTableRowFormatRequest::getTablePath() const
    {
        return m_TablePath;
    }

    const std::shared_ptr< int32_t > GetTableRowFormatRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetTableRowFormatRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetTableRowFormatRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetTableRowFormatRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetTableRowFormatRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetTableRowFormatRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{tablePath}/rows/{index}/rowformat");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_TablePath) throw aspose::words::cloud::ApiException(400, L"Parameter 'TablePath' is required.");
        result->setPathParam(L"{tablePath}", *m_TablePath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetTableRowFormatRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetTableRowFormatResponse()
        );
    }

    /*
     * GetTableRowFormatOnline request implementation
     */
    GetTableRowFormatOnlineRequest::GetTableRowFormatOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > tablePath,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_TablePath(tablePath),
        m_Index(index),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetTableRowFormatOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetTableRowFormatOnlineRequest::getTablePath() const
    {
        return m_TablePath;
    }

    const std::shared_ptr< int32_t > GetTableRowFormatOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetTableRowFormatOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetTableRowFormatOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetTableRowFormatOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{tablePath}/rows/{index}/rowformat");
        if (!m_TablePath) throw aspose::words::cloud::ApiException(400, L"Parameter 'TablePath' is required.");
        result->setPathParam(L"{tablePath}", *m_TablePath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetTableRowFormatOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetTableRowFormatOnlineResponse()
        );
    }

    /*
     * GetTableRowOnline request implementation
     */
    GetTableRowOnlineRequest::GetTableRowOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > tablePath,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_TablePath(tablePath),
        m_Index(index),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetTableRowOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetTableRowOnlineRequest::getTablePath() const
    {
        return m_TablePath;
    }

    const std::shared_ptr< int32_t > GetTableRowOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > GetTableRowOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetTableRowOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetTableRowOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{tablePath}/rows/{index}");
        if (!m_TablePath) throw aspose::words::cloud::ApiException(400, L"Parameter 'TablePath' is required.");
        result->setPathParam(L"{tablePath}", *m_TablePath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetTableRowOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetTableRowOnlineResponse()
        );
    }

    /*
     * GetTables request implementation
     */
    GetTablesRequest::GetTablesRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > GetTablesRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > GetTablesRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetTablesRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > GetTablesRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > GetTablesRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetTablesRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetTablesRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{nodePath}/tables");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetTablesRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetTablesResponse()
        );
    }

    /*
     * GetTablesOnline request implementation
     */
    GetTablesOnlineRequest::GetTablesOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > GetTablesOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > GetTablesOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > GetTablesOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > GetTablesOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > GetTablesOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{nodePath}/tables");
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > GetTablesOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::GetTablesOnlineResponse()
        );
    }

    /*
     * InsertComment request implementation
     */
    InsertCommentRequest::InsertCommentRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< aspose::words::cloud::models::CommentInsert > comment,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_Comment(comment),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > InsertCommentRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< aspose::words::cloud::models::CommentInsert > InsertCommentRequest::getComment() const
    {
        return m_Comment;
    }

    const std::shared_ptr< std::wstring > InsertCommentRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > InsertCommentRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > InsertCommentRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertCommentRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertCommentRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertCommentRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertCommentRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertCommentRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPOST);
        result->setPath(L"/words/{name}/comments");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Comment) result->setBody(*m_Comment);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Comment' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertCommentRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertCommentResponse()
        );
    }

    /*
     * InsertCommentOnline request implementation
     */
    InsertCommentOnlineRequest::InsertCommentOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::CommentInsert > comment,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_Comment(comment),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > InsertCommentOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::CommentInsert > InsertCommentOnlineRequest::getComment() const
    {
        return m_Comment;
    }

    const std::shared_ptr< std::wstring > InsertCommentOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertCommentOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertCommentOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertCommentOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertCommentOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertCommentOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/post/comments");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_Comment) result->addFormDataParam(L"comment", *m_Comment);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Comment' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertCommentOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertCommentOnlineResponse()
        );
    }

    /*
     * InsertDrawingObject request implementation
     */
    InsertDrawingObjectRequest::InsertDrawingObjectRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< aspose::words::cloud::models::DrawingObjectInsert > drawingObject,
        const std::shared_ptr< std::istream > imageFile,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_DrawingObject(drawingObject),
        m_ImageFile(imageFile),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > InsertDrawingObjectRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< aspose::words::cloud::models::DrawingObjectInsert > InsertDrawingObjectRequest::getDrawingObject() const
    {
        return m_DrawingObject;
    }

    const std::shared_ptr< std::istream > InsertDrawingObjectRequest::getImageFile() const
    {
        return m_ImageFile;
    }

    const std::shared_ptr< std::wstring > InsertDrawingObjectRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > InsertDrawingObjectRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > InsertDrawingObjectRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > InsertDrawingObjectRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertDrawingObjectRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertDrawingObjectRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertDrawingObjectRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertDrawingObjectRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertDrawingObjectRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPOST);
        result->setPath(L"/words/{name}/{nodePath}/drawingObjects");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_DrawingObject) result->addFormDataParam(L"drawingObject", *m_DrawingObject);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'DrawingObject' is required.");
        if (m_ImageFile) result->addFormDataParam(L"imageFile", *m_ImageFile);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'ImageFile' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertDrawingObjectRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertDrawingObjectResponse()
        );
    }

    /*
     * InsertDrawingObjectOnline request implementation
     */
    InsertDrawingObjectOnlineRequest::InsertDrawingObjectOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::DrawingObjectInsert > drawingObject,
        const std::shared_ptr< std::istream > imageFile,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_DrawingObject(drawingObject),
        m_ImageFile(imageFile),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > InsertDrawingObjectOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::DrawingObjectInsert > InsertDrawingObjectOnlineRequest::getDrawingObject() const
    {
        return m_DrawingObject;
    }

    const std::shared_ptr< std::istream > InsertDrawingObjectOnlineRequest::getImageFile() const
    {
        return m_ImageFile;
    }

    const std::shared_ptr< std::wstring > InsertDrawingObjectOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > InsertDrawingObjectOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertDrawingObjectOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertDrawingObjectOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertDrawingObjectOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertDrawingObjectOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertDrawingObjectOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/post/{nodePath}/drawingObjects");
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_DrawingObject) result->addFormDataParam(L"drawingObject", *m_DrawingObject);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'DrawingObject' is required.");
        if (m_ImageFile) result->addFormDataParam(L"imageFile", *m_ImageFile);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'ImageFile' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertDrawingObjectOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertDrawingObjectOnlineResponse()
        );
    }

    /*
     * InsertField request implementation
     */
    InsertFieldRequest::InsertFieldRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< aspose::words::cloud::models::FieldInsert > field,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime,
        const std::shared_ptr< std::wstring > insertBeforeNode
    ) : 
        m_Name(name),
        m_Field(field),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime),
        m_InsertBeforeNode(insertBeforeNode)
    {
    }

    const std::shared_ptr< std::wstring > InsertFieldRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< aspose::words::cloud::models::FieldInsert > InsertFieldRequest::getField() const
    {
        return m_Field;
    }

    const std::shared_ptr< std::wstring > InsertFieldRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > InsertFieldRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > InsertFieldRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > InsertFieldRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertFieldRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertFieldRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertFieldRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertFieldRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    const std::shared_ptr< std::wstring > InsertFieldRequest::getInsertBeforeNode() const
    {
        return m_InsertBeforeNode;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertFieldRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPOST);
        result->setPath(L"/words/{name}/{nodePath}/fields");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_InsertBeforeNode) result->addQueryParam(L"insertBeforeNode", *m_InsertBeforeNode);
        if (m_Field) result->setBody(*m_Field);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Field' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertFieldRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertFieldResponse()
        );
    }

    /*
     * InsertFieldOnline request implementation
     */
    InsertFieldOnlineRequest::InsertFieldOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::FieldInsert > field,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime,
        const std::shared_ptr< std::wstring > insertBeforeNode
    ) : 
        m_Document(document),
        m_Field(field),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime),
        m_InsertBeforeNode(insertBeforeNode)
    {
    }

    const std::shared_ptr< std::istream > InsertFieldOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::FieldInsert > InsertFieldOnlineRequest::getField() const
    {
        return m_Field;
    }

    const std::shared_ptr< std::wstring > InsertFieldOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > InsertFieldOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertFieldOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertFieldOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertFieldOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertFieldOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    const std::shared_ptr< std::wstring > InsertFieldOnlineRequest::getInsertBeforeNode() const
    {
        return m_InsertBeforeNode;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertFieldOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/post/{nodePath}/fields");
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_InsertBeforeNode) result->addQueryParam(L"insertBeforeNode", *m_InsertBeforeNode);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_Field) result->addFormDataParam(L"field", *m_Field);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Field' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertFieldOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertFieldOnlineResponse()
        );
    }

    /*
     * InsertFootnote request implementation
     */
    InsertFootnoteRequest::InsertFootnoteRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< aspose::words::cloud::models::FootnoteInsert > footnoteDto,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_FootnoteDto(footnoteDto),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > InsertFootnoteRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< aspose::words::cloud::models::FootnoteInsert > InsertFootnoteRequest::getFootnoteDto() const
    {
        return m_FootnoteDto;
    }

    const std::shared_ptr< std::wstring > InsertFootnoteRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > InsertFootnoteRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > InsertFootnoteRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > InsertFootnoteRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertFootnoteRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertFootnoteRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertFootnoteRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertFootnoteRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertFootnoteRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPOST);
        result->setPath(L"/words/{name}/{nodePath}/footnotes");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_FootnoteDto) result->setBody(*m_FootnoteDto);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'FootnoteDto' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertFootnoteRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertFootnoteResponse()
        );
    }

    /*
     * InsertFootnoteOnline request implementation
     */
    InsertFootnoteOnlineRequest::InsertFootnoteOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::FootnoteInsert > footnoteDto,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_FootnoteDto(footnoteDto),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > InsertFootnoteOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::FootnoteInsert > InsertFootnoteOnlineRequest::getFootnoteDto() const
    {
        return m_FootnoteDto;
    }

    const std::shared_ptr< std::wstring > InsertFootnoteOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > InsertFootnoteOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertFootnoteOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertFootnoteOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertFootnoteOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertFootnoteOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertFootnoteOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/post/{nodePath}/footnotes");
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_FootnoteDto) result->addFormDataParam(L"footnoteDto", *m_FootnoteDto);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'FootnoteDto' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertFootnoteOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertFootnoteOnlineResponse()
        );
    }

    /*
     * InsertFormField request implementation
     */
    InsertFormFieldRequest::InsertFormFieldRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< aspose::words::cloud::models::FormField > formField,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime,
        const std::shared_ptr< std::wstring > insertBeforeNode
    ) : 
        m_Name(name),
        m_FormField(formField),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime),
        m_InsertBeforeNode(insertBeforeNode)
    {
    }

    const std::shared_ptr< std::wstring > InsertFormFieldRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< aspose::words::cloud::models::FormField > InsertFormFieldRequest::getFormField() const
    {
        return m_FormField;
    }

    const std::shared_ptr< std::wstring > InsertFormFieldRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > InsertFormFieldRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > InsertFormFieldRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > InsertFormFieldRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertFormFieldRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertFormFieldRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertFormFieldRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertFormFieldRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    const std::shared_ptr< std::wstring > InsertFormFieldRequest::getInsertBeforeNode() const
    {
        return m_InsertBeforeNode;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertFormFieldRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPOST);
        result->setPath(L"/words/{name}/{nodePath}/formfields");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_InsertBeforeNode) result->addQueryParam(L"insertBeforeNode", *m_InsertBeforeNode);
        if (m_FormField) result->setBody(*m_FormField);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'FormField' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertFormFieldRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertFormFieldResponse()
        );
    }

    /*
     * InsertFormFieldOnline request implementation
     */
    InsertFormFieldOnlineRequest::InsertFormFieldOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::FormField > formField,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime,
        const std::shared_ptr< std::wstring > insertBeforeNode
    ) : 
        m_Document(document),
        m_FormField(formField),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime),
        m_InsertBeforeNode(insertBeforeNode)
    {
    }

    const std::shared_ptr< std::istream > InsertFormFieldOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::FormField > InsertFormFieldOnlineRequest::getFormField() const
    {
        return m_FormField;
    }

    const std::shared_ptr< std::wstring > InsertFormFieldOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > InsertFormFieldOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertFormFieldOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertFormFieldOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertFormFieldOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertFormFieldOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    const std::shared_ptr< std::wstring > InsertFormFieldOnlineRequest::getInsertBeforeNode() const
    {
        return m_InsertBeforeNode;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertFormFieldOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/post/{nodePath}/formfields");
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_InsertBeforeNode) result->addQueryParam(L"insertBeforeNode", *m_InsertBeforeNode);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_FormField) result->addFormDataParam(L"formField", *m_FormField);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'FormField' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertFormFieldOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertFormFieldOnlineResponse()
        );
    }

    /*
     * InsertHeaderFooter request implementation
     */
    InsertHeaderFooterRequest::InsertHeaderFooterRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > sectionPath,
        const std::shared_ptr< std::wstring > headerFooterType,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_SectionPath(sectionPath),
        m_HeaderFooterType(headerFooterType),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > InsertHeaderFooterRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > InsertHeaderFooterRequest::getSectionPath() const
    {
        return m_SectionPath;
    }

    const std::shared_ptr< std::wstring > InsertHeaderFooterRequest::getHeaderFooterType() const
    {
        return m_HeaderFooterType;
    }

    const std::shared_ptr< std::wstring > InsertHeaderFooterRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > InsertHeaderFooterRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > InsertHeaderFooterRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertHeaderFooterRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertHeaderFooterRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertHeaderFooterRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertHeaderFooterRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertHeaderFooterRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/{sectionPath}/headersfooters");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_SectionPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'SectionPath' is required.");
        result->setPathParam(L"{sectionPath}", *m_SectionPath);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_HeaderFooterType) result->setBodyJson(*m_HeaderFooterType);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'HeaderFooterType' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertHeaderFooterRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertHeaderFooterResponse()
        );
    }

    /*
     * InsertHeaderFooterOnline request implementation
     */
    InsertHeaderFooterOnlineRequest::InsertHeaderFooterOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > sectionPath,
        const std::shared_ptr< std::wstring > headerFooterType,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_SectionPath(sectionPath),
        m_HeaderFooterType(headerFooterType),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > InsertHeaderFooterOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > InsertHeaderFooterOnlineRequest::getSectionPath() const
    {
        return m_SectionPath;
    }

    const std::shared_ptr< std::wstring > InsertHeaderFooterOnlineRequest::getHeaderFooterType() const
    {
        return m_HeaderFooterType;
    }

    const std::shared_ptr< std::wstring > InsertHeaderFooterOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertHeaderFooterOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertHeaderFooterOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertHeaderFooterOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertHeaderFooterOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertHeaderFooterOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/{sectionPath}/headersfooters");
        if (!m_SectionPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'SectionPath' is required.");
        result->setPathParam(L"{sectionPath}", *m_SectionPath);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_HeaderFooterType) result->addFormDataParam(L"headerFooterType", *m_HeaderFooterType);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'HeaderFooterType' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertHeaderFooterOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertHeaderFooterOnlineResponse()
        );
    }

    /*
     * InsertList request implementation
     */
    InsertListRequest::InsertListRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< aspose::words::cloud::models::ListInsert > listInsert,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_ListInsert(listInsert),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > InsertListRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< aspose::words::cloud::models::ListInsert > InsertListRequest::getListInsert() const
    {
        return m_ListInsert;
    }

    const std::shared_ptr< std::wstring > InsertListRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > InsertListRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > InsertListRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertListRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertListRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertListRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertListRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertListRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPOST);
        result->setPath(L"/words/{name}/lists");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_ListInsert) result->setBody(*m_ListInsert);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'ListInsert' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertListRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertListResponse()
        );
    }

    /*
     * InsertListOnline request implementation
     */
    InsertListOnlineRequest::InsertListOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::ListInsert > listInsert,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_ListInsert(listInsert),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > InsertListOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::ListInsert > InsertListOnlineRequest::getListInsert() const
    {
        return m_ListInsert;
    }

    const std::shared_ptr< std::wstring > InsertListOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertListOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertListOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertListOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertListOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertListOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/post/lists");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_ListInsert) result->addFormDataParam(L"listInsert", *m_ListInsert);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'ListInsert' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertListOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertListOnlineResponse()
        );
    }

    /*
     * InsertOrUpdateParagraphTabStop request implementation
     */
    InsertOrUpdateParagraphTabStopRequest::InsertOrUpdateParagraphTabStopRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< aspose::words::cloud::models::TabStopInsert > tabStopInsertDto,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName
    ) : 
        m_Name(name),
        m_Index(index),
        m_TabStopInsertDto(tabStopInsertDto),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName)
    {
    }

    const std::shared_ptr< std::wstring > InsertOrUpdateParagraphTabStopRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > InsertOrUpdateParagraphTabStopRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< aspose::words::cloud::models::TabStopInsert > InsertOrUpdateParagraphTabStopRequest::getTabStopInsertDto() const
    {
        return m_TabStopInsertDto;
    }

    const std::shared_ptr< std::wstring > InsertOrUpdateParagraphTabStopRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > InsertOrUpdateParagraphTabStopRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > InsertOrUpdateParagraphTabStopRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > InsertOrUpdateParagraphTabStopRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertOrUpdateParagraphTabStopRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertOrUpdateParagraphTabStopRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertOrUpdateParagraphTabStopRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPOST);
        result->setPath(L"/words/{name}/{nodePath}/paragraphs/{index}/tabstops");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_TabStopInsertDto) result->setBody(*m_TabStopInsertDto);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'TabStopInsertDto' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertOrUpdateParagraphTabStopRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertOrUpdateParagraphTabStopResponse()
        );
    }

    /*
     * InsertOrUpdateParagraphTabStopOnline request implementation
     */
    InsertOrUpdateParagraphTabStopOnlineRequest::InsertOrUpdateParagraphTabStopOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::TabStopInsert > tabStopInsertDto,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName
    ) : 
        m_Document(document),
        m_TabStopInsertDto(tabStopInsertDto),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName)
    {
    }

    const std::shared_ptr< std::istream > InsertOrUpdateParagraphTabStopOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::TabStopInsert > InsertOrUpdateParagraphTabStopOnlineRequest::getTabStopInsertDto() const
    {
        return m_TabStopInsertDto;
    }

    const std::shared_ptr< int32_t > InsertOrUpdateParagraphTabStopOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > InsertOrUpdateParagraphTabStopOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > InsertOrUpdateParagraphTabStopOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertOrUpdateParagraphTabStopOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertOrUpdateParagraphTabStopOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertOrUpdateParagraphTabStopOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/post/{nodePath}/paragraphs/{index}/tabstops");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_TabStopInsertDto) result->addFormDataParam(L"tabStopInsertDto", *m_TabStopInsertDto);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'TabStopInsertDto' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertOrUpdateParagraphTabStopOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertOrUpdateParagraphTabStopOnlineResponse()
        );
    }

    /*
     * InsertPageNumbers request implementation
     */
    InsertPageNumbersRequest::InsertPageNumbersRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< aspose::words::cloud::models::PageNumber > pageNumber,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_PageNumber(pageNumber),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > InsertPageNumbersRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< aspose::words::cloud::models::PageNumber > InsertPageNumbersRequest::getPageNumber() const
    {
        return m_PageNumber;
    }

    const std::shared_ptr< std::wstring > InsertPageNumbersRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > InsertPageNumbersRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > InsertPageNumbersRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertPageNumbersRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertPageNumbersRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertPageNumbersRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertPageNumbersRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertPageNumbersRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/PageNumbers");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_PageNumber) result->setBody(*m_PageNumber);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'PageNumber' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertPageNumbersRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertPageNumbersResponse()
        );
    }

    /*
     * InsertPageNumbersOnline request implementation
     */
    InsertPageNumbersOnlineRequest::InsertPageNumbersOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::PageNumber > pageNumber,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_PageNumber(pageNumber),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > InsertPageNumbersOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::PageNumber > InsertPageNumbersOnlineRequest::getPageNumber() const
    {
        return m_PageNumber;
    }

    const std::shared_ptr< std::wstring > InsertPageNumbersOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertPageNumbersOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertPageNumbersOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertPageNumbersOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertPageNumbersOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertPageNumbersOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/PageNumbers");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_PageNumber) result->addFormDataParam(L"pageNumber", *m_PageNumber);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'PageNumber' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertPageNumbersOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertPageNumbersOnlineResponse()
        );
    }

    /*
     * InsertParagraph request implementation
     */
    InsertParagraphRequest::InsertParagraphRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< aspose::words::cloud::models::ParagraphInsert > paragraph,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime,
        const std::shared_ptr< std::wstring > insertBeforeNode
    ) : 
        m_Name(name),
        m_Paragraph(paragraph),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime),
        m_InsertBeforeNode(insertBeforeNode)
    {
    }

    const std::shared_ptr< std::wstring > InsertParagraphRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< aspose::words::cloud::models::ParagraphInsert > InsertParagraphRequest::getParagraph() const
    {
        return m_Paragraph;
    }

    const std::shared_ptr< std::wstring > InsertParagraphRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > InsertParagraphRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > InsertParagraphRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > InsertParagraphRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertParagraphRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertParagraphRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertParagraphRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertParagraphRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    const std::shared_ptr< std::wstring > InsertParagraphRequest::getInsertBeforeNode() const
    {
        return m_InsertBeforeNode;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertParagraphRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPOST);
        result->setPath(L"/words/{name}/{nodePath}/paragraphs");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_InsertBeforeNode) result->addQueryParam(L"insertBeforeNode", *m_InsertBeforeNode);
        if (m_Paragraph) result->setBody(*m_Paragraph);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Paragraph' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertParagraphRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertParagraphResponse()
        );
    }

    /*
     * InsertParagraphOnline request implementation
     */
    InsertParagraphOnlineRequest::InsertParagraphOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::ParagraphInsert > paragraph,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime,
        const std::shared_ptr< std::wstring > insertBeforeNode
    ) : 
        m_Document(document),
        m_Paragraph(paragraph),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime),
        m_InsertBeforeNode(insertBeforeNode)
    {
    }

    const std::shared_ptr< std::istream > InsertParagraphOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::ParagraphInsert > InsertParagraphOnlineRequest::getParagraph() const
    {
        return m_Paragraph;
    }

    const std::shared_ptr< std::wstring > InsertParagraphOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > InsertParagraphOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertParagraphOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertParagraphOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertParagraphOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertParagraphOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    const std::shared_ptr< std::wstring > InsertParagraphOnlineRequest::getInsertBeforeNode() const
    {
        return m_InsertBeforeNode;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertParagraphOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/post/{nodePath}/paragraphs");
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_InsertBeforeNode) result->addQueryParam(L"insertBeforeNode", *m_InsertBeforeNode);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_Paragraph) result->addFormDataParam(L"paragraph", *m_Paragraph);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Paragraph' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertParagraphOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertParagraphOnlineResponse()
        );
    }

    /*
     * InsertRun request implementation
     */
    InsertRunRequest::InsertRunRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > paragraphPath,
        const std::shared_ptr< aspose::words::cloud::models::RunInsert > run,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime,
        const std::shared_ptr< std::wstring > insertBeforeNode
    ) : 
        m_Name(name),
        m_ParagraphPath(paragraphPath),
        m_Run(run),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime),
        m_InsertBeforeNode(insertBeforeNode)
    {
    }

    const std::shared_ptr< std::wstring > InsertRunRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > InsertRunRequest::getParagraphPath() const
    {
        return m_ParagraphPath;
    }

    const std::shared_ptr< aspose::words::cloud::models::RunInsert > InsertRunRequest::getRun() const
    {
        return m_Run;
    }

    const std::shared_ptr< std::wstring > InsertRunRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > InsertRunRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > InsertRunRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertRunRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertRunRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertRunRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertRunRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    const std::shared_ptr< std::wstring > InsertRunRequest::getInsertBeforeNode() const
    {
        return m_InsertBeforeNode;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertRunRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPOST);
        result->setPath(L"/words/{name}/{paragraphPath}/runs");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_ParagraphPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'ParagraphPath' is required.");
        result->setPathParam(L"{paragraphPath}", *m_ParagraphPath);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_InsertBeforeNode) result->addQueryParam(L"insertBeforeNode", *m_InsertBeforeNode);
        if (m_Run) result->setBody(*m_Run);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Run' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertRunRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertRunResponse()
        );
    }

    /*
     * InsertRunOnline request implementation
     */
    InsertRunOnlineRequest::InsertRunOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > paragraphPath,
        const std::shared_ptr< aspose::words::cloud::models::RunInsert > run,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime,
        const std::shared_ptr< std::wstring > insertBeforeNode
    ) : 
        m_Document(document),
        m_ParagraphPath(paragraphPath),
        m_Run(run),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime),
        m_InsertBeforeNode(insertBeforeNode)
    {
    }

    const std::shared_ptr< std::istream > InsertRunOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > InsertRunOnlineRequest::getParagraphPath() const
    {
        return m_ParagraphPath;
    }

    const std::shared_ptr< aspose::words::cloud::models::RunInsert > InsertRunOnlineRequest::getRun() const
    {
        return m_Run;
    }

    const std::shared_ptr< std::wstring > InsertRunOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertRunOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertRunOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertRunOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertRunOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    const std::shared_ptr< std::wstring > InsertRunOnlineRequest::getInsertBeforeNode() const
    {
        return m_InsertBeforeNode;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertRunOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/post/{paragraphPath}/runs");
        if (!m_ParagraphPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'ParagraphPath' is required.");
        result->setPathParam(L"{paragraphPath}", *m_ParagraphPath);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_InsertBeforeNode) result->addQueryParam(L"insertBeforeNode", *m_InsertBeforeNode);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_Run) result->addFormDataParam(L"run", *m_Run);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Run' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertRunOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertRunOnlineResponse()
        );
    }

    /*
     * InsertStyle request implementation
     */
    InsertStyleRequest::InsertStyleRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< aspose::words::cloud::models::StyleInsert > styleInsert,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_StyleInsert(styleInsert),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > InsertStyleRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< aspose::words::cloud::models::StyleInsert > InsertStyleRequest::getStyleInsert() const
    {
        return m_StyleInsert;
    }

    const std::shared_ptr< std::wstring > InsertStyleRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > InsertStyleRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > InsertStyleRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertStyleRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertStyleRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertStyleRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertStyleRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertStyleRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPOST);
        result->setPath(L"/words/{name}/styles/insert");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_StyleInsert) result->setBody(*m_StyleInsert);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'StyleInsert' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertStyleRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertStyleResponse()
        );
    }

    /*
     * InsertStyleOnline request implementation
     */
    InsertStyleOnlineRequest::InsertStyleOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::StyleInsert > styleInsert,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_StyleInsert(styleInsert),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > InsertStyleOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::StyleInsert > InsertStyleOnlineRequest::getStyleInsert() const
    {
        return m_StyleInsert;
    }

    const std::shared_ptr< std::wstring > InsertStyleOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertStyleOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertStyleOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertStyleOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertStyleOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertStyleOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/post/styles/insert");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_StyleInsert) result->addFormDataParam(L"styleInsert", *m_StyleInsert);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'StyleInsert' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertStyleOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertStyleOnlineResponse()
        );
    }

    /*
     * InsertTable request implementation
     */
    InsertTableRequest::InsertTableRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< aspose::words::cloud::models::TableInsert > table,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_Table(table),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > InsertTableRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< aspose::words::cloud::models::TableInsert > InsertTableRequest::getTable() const
    {
        return m_Table;
    }

    const std::shared_ptr< std::wstring > InsertTableRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > InsertTableRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > InsertTableRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > InsertTableRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertTableRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertTableRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertTableRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertTableRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertTableRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPOST);
        result->setPath(L"/words/{name}/{nodePath}/tables");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Table) result->setBody(*m_Table);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Table' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertTableRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertTableResponse()
        );
    }

    /*
     * InsertTableCell request implementation
     */
    InsertTableCellRequest::InsertTableCellRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > tableRowPath,
        const std::shared_ptr< aspose::words::cloud::models::TableCellInsert > cell,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_TableRowPath(tableRowPath),
        m_Cell(cell),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > InsertTableCellRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > InsertTableCellRequest::getTableRowPath() const
    {
        return m_TableRowPath;
    }

    const std::shared_ptr< aspose::words::cloud::models::TableCellInsert > InsertTableCellRequest::getCell() const
    {
        return m_Cell;
    }

    const std::shared_ptr< std::wstring > InsertTableCellRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > InsertTableCellRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > InsertTableCellRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertTableCellRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertTableCellRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertTableCellRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertTableCellRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertTableCellRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPOST);
        result->setPath(L"/words/{name}/{tableRowPath}/cells");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_TableRowPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'TableRowPath' is required.");
        result->setPathParam(L"{tableRowPath}", *m_TableRowPath);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Cell) result->setBody(*m_Cell);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Cell' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertTableCellRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertTableCellResponse()
        );
    }

    /*
     * InsertTableCellOnline request implementation
     */
    InsertTableCellOnlineRequest::InsertTableCellOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > tableRowPath,
        const std::shared_ptr< aspose::words::cloud::models::TableCellInsert > cell,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_TableRowPath(tableRowPath),
        m_Cell(cell),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > InsertTableCellOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > InsertTableCellOnlineRequest::getTableRowPath() const
    {
        return m_TableRowPath;
    }

    const std::shared_ptr< aspose::words::cloud::models::TableCellInsert > InsertTableCellOnlineRequest::getCell() const
    {
        return m_Cell;
    }

    const std::shared_ptr< std::wstring > InsertTableCellOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertTableCellOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertTableCellOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertTableCellOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertTableCellOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertTableCellOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/post/{tableRowPath}/cells");
        if (!m_TableRowPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'TableRowPath' is required.");
        result->setPathParam(L"{tableRowPath}", *m_TableRowPath);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_Cell) result->addFormDataParam(L"cell", *m_Cell);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Cell' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertTableCellOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertTableCellOnlineResponse()
        );
    }

    /*
     * InsertTableOnline request implementation
     */
    InsertTableOnlineRequest::InsertTableOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::TableInsert > table,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_Table(table),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > InsertTableOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::TableInsert > InsertTableOnlineRequest::getTable() const
    {
        return m_Table;
    }

    const std::shared_ptr< std::wstring > InsertTableOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > InsertTableOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertTableOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertTableOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertTableOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertTableOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertTableOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/post/{nodePath}/tables");
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_Table) result->addFormDataParam(L"table", *m_Table);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Table' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertTableOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertTableOnlineResponse()
        );
    }

    /*
     * InsertTableRow request implementation
     */
    InsertTableRowRequest::InsertTableRowRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > tablePath,
        const std::shared_ptr< aspose::words::cloud::models::TableRowInsert > row,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_TablePath(tablePath),
        m_Row(row),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > InsertTableRowRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > InsertTableRowRequest::getTablePath() const
    {
        return m_TablePath;
    }

    const std::shared_ptr< aspose::words::cloud::models::TableRowInsert > InsertTableRowRequest::getRow() const
    {
        return m_Row;
    }

    const std::shared_ptr< std::wstring > InsertTableRowRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > InsertTableRowRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > InsertTableRowRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertTableRowRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertTableRowRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertTableRowRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertTableRowRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertTableRowRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPOST);
        result->setPath(L"/words/{name}/{tablePath}/rows");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_TablePath) throw aspose::words::cloud::ApiException(400, L"Parameter 'TablePath' is required.");
        result->setPathParam(L"{tablePath}", *m_TablePath);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Row) result->setBody(*m_Row);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Row' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertTableRowRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertTableRowResponse()
        );
    }

    /*
     * InsertTableRowOnline request implementation
     */
    InsertTableRowOnlineRequest::InsertTableRowOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > tablePath,
        const std::shared_ptr< aspose::words::cloud::models::TableRowInsert > row,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_TablePath(tablePath),
        m_Row(row),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > InsertTableRowOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > InsertTableRowOnlineRequest::getTablePath() const
    {
        return m_TablePath;
    }

    const std::shared_ptr< aspose::words::cloud::models::TableRowInsert > InsertTableRowOnlineRequest::getRow() const
    {
        return m_Row;
    }

    const std::shared_ptr< std::wstring > InsertTableRowOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertTableRowOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertTableRowOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertTableRowOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertTableRowOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertTableRowOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/post/{tablePath}/rows");
        if (!m_TablePath) throw aspose::words::cloud::ApiException(400, L"Parameter 'TablePath' is required.");
        result->setPathParam(L"{tablePath}", *m_TablePath);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_Row) result->addFormDataParam(L"row", *m_Row);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Row' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertTableRowOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertTableRowOnlineResponse()
        );
    }

    /*
     * InsertWatermarkImage request implementation
     */
    InsertWatermarkImageRequest::InsertWatermarkImageRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::istream > imageFile,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime,
        const std::shared_ptr< double > rotationAngle,
        const std::shared_ptr< std::wstring > image
    ) : 
        m_Name(name),
        m_ImageFile(imageFile),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime),
        m_RotationAngle(rotationAngle),
        m_Image(image)
    {
    }

    const std::shared_ptr< std::wstring > InsertWatermarkImageRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::istream > InsertWatermarkImageRequest::getImageFile() const
    {
        return m_ImageFile;
    }

    const std::shared_ptr< std::wstring > InsertWatermarkImageRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > InsertWatermarkImageRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > InsertWatermarkImageRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertWatermarkImageRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertWatermarkImageRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertWatermarkImageRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertWatermarkImageRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    const std::shared_ptr< double > InsertWatermarkImageRequest::getRotationAngle() const
    {
        return m_RotationAngle;
    }

    const std::shared_ptr< std::wstring > InsertWatermarkImageRequest::getImage() const
    {
        return m_Image;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertWatermarkImageRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPOST);
        result->setPath(L"/words/{name}/watermarks/images");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_RotationAngle) result->addQueryParam(L"rotationAngle", *m_RotationAngle);
        if (m_Image) result->addQueryParam(L"image", *m_Image);
        if (m_ImageFile) result->setBody(*m_ImageFile);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertWatermarkImageRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertWatermarkImageResponse()
        );
    }

    /*
     * InsertWatermarkImageOnline request implementation
     */
    InsertWatermarkImageOnlineRequest::InsertWatermarkImageOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::istream > imageFile,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime,
        const std::shared_ptr< double > rotationAngle,
        const std::shared_ptr< std::wstring > image
    ) : 
        m_Document(document),
        m_ImageFile(imageFile),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime),
        m_RotationAngle(rotationAngle),
        m_Image(image)
    {
    }

    const std::shared_ptr< std::istream > InsertWatermarkImageOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::istream > InsertWatermarkImageOnlineRequest::getImageFile() const
    {
        return m_ImageFile;
    }

    const std::shared_ptr< std::wstring > InsertWatermarkImageOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertWatermarkImageOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertWatermarkImageOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertWatermarkImageOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertWatermarkImageOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    const std::shared_ptr< double > InsertWatermarkImageOnlineRequest::getRotationAngle() const
    {
        return m_RotationAngle;
    }

    const std::shared_ptr< std::wstring > InsertWatermarkImageOnlineRequest::getImage() const
    {
        return m_Image;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertWatermarkImageOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/post/watermarks/images");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_RotationAngle) result->addQueryParam(L"rotationAngle", *m_RotationAngle);
        if (m_Image) result->addQueryParam(L"image", *m_Image);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_ImageFile) result->addFormDataParam(L"imageFile", *m_ImageFile);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'ImageFile' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertWatermarkImageOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertWatermarkImageOnlineResponse()
        );
    }

    /*
     * InsertWatermarkText request implementation
     */
    InsertWatermarkTextRequest::InsertWatermarkTextRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< aspose::words::cloud::models::WatermarkText > watermarkText,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_WatermarkText(watermarkText),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > InsertWatermarkTextRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< aspose::words::cloud::models::WatermarkText > InsertWatermarkTextRequest::getWatermarkText() const
    {
        return m_WatermarkText;
    }

    const std::shared_ptr< std::wstring > InsertWatermarkTextRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > InsertWatermarkTextRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > InsertWatermarkTextRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertWatermarkTextRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertWatermarkTextRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertWatermarkTextRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertWatermarkTextRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertWatermarkTextRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPOST);
        result->setPath(L"/words/{name}/watermarks/texts");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_WatermarkText) result->setBody(*m_WatermarkText);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'WatermarkText' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertWatermarkTextRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertWatermarkTextResponse()
        );
    }

    /*
     * InsertWatermarkTextOnline request implementation
     */
    InsertWatermarkTextOnlineRequest::InsertWatermarkTextOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::WatermarkText > watermarkText,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_WatermarkText(watermarkText),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > InsertWatermarkTextOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::WatermarkText > InsertWatermarkTextOnlineRequest::getWatermarkText() const
    {
        return m_WatermarkText;
    }

    const std::shared_ptr< std::wstring > InsertWatermarkTextOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > InsertWatermarkTextOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > InsertWatermarkTextOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > InsertWatermarkTextOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > InsertWatermarkTextOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > InsertWatermarkTextOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/post/watermarks/texts");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_WatermarkText) result->addFormDataParam(L"watermarkText", *m_WatermarkText);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'WatermarkText' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > InsertWatermarkTextOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::InsertWatermarkTextOnlineResponse()
        );
    }

    /*
     * LoadWebDocument request implementation
     */
    LoadWebDocumentRequest::LoadWebDocumentRequest(
        const std::shared_ptr< aspose::words::cloud::models::LoadWebDocumentData > data,
        const std::shared_ptr< std::wstring > storage
    ) : 
        m_Data(data),
        m_Storage(storage)
    {
    }

    const std::shared_ptr< aspose::words::cloud::models::LoadWebDocumentData > LoadWebDocumentRequest::getData() const
    {
        return m_Data;
    }

    const std::shared_ptr< std::wstring > LoadWebDocumentRequest::getStorage() const
    {
        return m_Storage;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > LoadWebDocumentRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/loadWebDocument");
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_Data) result->setBody(*m_Data);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Data' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > LoadWebDocumentRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::LoadWebDocumentResponse()
        );
    }

    /*
     * MoveFile request implementation
     */
    MoveFileRequest::MoveFileRequest(
        const std::shared_ptr< std::wstring > destPath,
        const std::shared_ptr< std::wstring > srcPath,
        const std::shared_ptr< std::wstring > srcStorageName,
        const std::shared_ptr< std::wstring > destStorageName,
        const std::shared_ptr< std::wstring > versionId
    ) : 
        m_DestPath(destPath),
        m_SrcPath(srcPath),
        m_SrcStorageName(srcStorageName),
        m_DestStorageName(destStorageName),
        m_VersionId(versionId)
    {
    }

    const std::shared_ptr< std::wstring > MoveFileRequest::getDestPath() const
    {
        return m_DestPath;
    }

    const std::shared_ptr< std::wstring > MoveFileRequest::getSrcPath() const
    {
        return m_SrcPath;
    }

    const std::shared_ptr< std::wstring > MoveFileRequest::getSrcStorageName() const
    {
        return m_SrcStorageName;
    }

    const std::shared_ptr< std::wstring > MoveFileRequest::getDestStorageName() const
    {
        return m_DestStorageName;
    }

    const std::shared_ptr< std::wstring > MoveFileRequest::getVersionId() const
    {
        return m_VersionId;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > MoveFileRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/storage/file/move/{srcPath}");
        if (!m_SrcPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'SrcPath' is required.");
        result->setPathParam(L"{srcPath}", *m_SrcPath);
        if (m_DestPath) result->addQueryParam(L"destPath", *m_DestPath);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'DestPath' is required.");
        if (m_SrcStorageName) result->addQueryParam(L"srcStorageName", *m_SrcStorageName);
        if (m_DestStorageName) result->addQueryParam(L"destStorageName", *m_DestStorageName);
        if (m_VersionId) result->addQueryParam(L"versionId", *m_VersionId);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > MoveFileRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::MoveFileResponse()
        );
    }

    /*
     * MoveFolder request implementation
     */
    MoveFolderRequest::MoveFolderRequest(
        const std::shared_ptr< std::wstring > destPath,
        const std::shared_ptr< std::wstring > srcPath,
        const std::shared_ptr< std::wstring > srcStorageName,
        const std::shared_ptr< std::wstring > destStorageName
    ) : 
        m_DestPath(destPath),
        m_SrcPath(srcPath),
        m_SrcStorageName(srcStorageName),
        m_DestStorageName(destStorageName)
    {
    }

    const std::shared_ptr< std::wstring > MoveFolderRequest::getDestPath() const
    {
        return m_DestPath;
    }

    const std::shared_ptr< std::wstring > MoveFolderRequest::getSrcPath() const
    {
        return m_SrcPath;
    }

    const std::shared_ptr< std::wstring > MoveFolderRequest::getSrcStorageName() const
    {
        return m_SrcStorageName;
    }

    const std::shared_ptr< std::wstring > MoveFolderRequest::getDestStorageName() const
    {
        return m_DestStorageName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > MoveFolderRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/storage/folder/move/{srcPath}");
        if (!m_SrcPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'SrcPath' is required.");
        result->setPathParam(L"{srcPath}", *m_SrcPath);
        if (m_DestPath) result->addQueryParam(L"destPath", *m_DestPath);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'DestPath' is required.");
        if (m_SrcStorageName) result->addQueryParam(L"srcStorageName", *m_SrcStorageName);
        if (m_DestStorageName) result->addQueryParam(L"destStorageName", *m_DestStorageName);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > MoveFolderRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::MoveFolderResponse()
        );
    }

    /*
     * OptimizeDocument request implementation
     */
    OptimizeDocumentRequest::OptimizeDocumentRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< aspose::words::cloud::models::OptimizationOptions > options,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_Options(options),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > OptimizeDocumentRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< aspose::words::cloud::models::OptimizationOptions > OptimizeDocumentRequest::getOptions() const
    {
        return m_Options;
    }

    const std::shared_ptr< std::wstring > OptimizeDocumentRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > OptimizeDocumentRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > OptimizeDocumentRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > OptimizeDocumentRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > OptimizeDocumentRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > OptimizeDocumentRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > OptimizeDocumentRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > OptimizeDocumentRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/compatibility/optimize");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Options) result->setBody(*m_Options);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Options' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > OptimizeDocumentRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::OptimizeDocumentResponse()
        );
    }

    /*
     * OptimizeDocumentOnline request implementation
     */
    OptimizeDocumentOnlineRequest::OptimizeDocumentOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::OptimizationOptions > options,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_Options(options),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > OptimizeDocumentOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::OptimizationOptions > OptimizeDocumentOnlineRequest::getOptions() const
    {
        return m_Options;
    }

    const std::shared_ptr< std::wstring > OptimizeDocumentOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > OptimizeDocumentOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > OptimizeDocumentOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > OptimizeDocumentOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > OptimizeDocumentOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > OptimizeDocumentOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/compatibility/optimize");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_Options) result->addFormDataParam(L"options", *m_Options);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Options' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > OptimizeDocumentOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::OptimizeDocumentOnlineResponse()
        );
    }

    /*
     * ProtectDocument request implementation
     */
    ProtectDocumentRequest::ProtectDocumentRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< aspose::words::cloud::models::ProtectionRequest > protectionRequest,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName
    ) : 
        m_Name(name),
        m_ProtectionRequest(protectionRequest),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName)
    {
    }

    const std::shared_ptr< std::wstring > ProtectDocumentRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< aspose::words::cloud::models::ProtectionRequest > ProtectDocumentRequest::getProtectionRequest() const
    {
        return m_ProtectionRequest;
    }

    const std::shared_ptr< std::wstring > ProtectDocumentRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > ProtectDocumentRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > ProtectDocumentRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > ProtectDocumentRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > ProtectDocumentRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > ProtectDocumentRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/protection");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_ProtectionRequest) result->setBody(*m_ProtectionRequest);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'ProtectionRequest' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > ProtectDocumentRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::ProtectDocumentResponse()
        );
    }

    /*
     * ProtectDocumentOnline request implementation
     */
    ProtectDocumentOnlineRequest::ProtectDocumentOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::ProtectionRequest > protectionRequest,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName
    ) : 
        m_Document(document),
        m_ProtectionRequest(protectionRequest),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName)
    {
    }

    const std::shared_ptr< std::istream > ProtectDocumentOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::ProtectionRequest > ProtectDocumentOnlineRequest::getProtectionRequest() const
    {
        return m_ProtectionRequest;
    }

    const std::shared_ptr< std::wstring > ProtectDocumentOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > ProtectDocumentOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > ProtectDocumentOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > ProtectDocumentOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/protection");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_ProtectionRequest) result->addFormDataParam(L"protectionRequest", *m_ProtectionRequest);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'ProtectionRequest' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > ProtectDocumentOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::ProtectDocumentOnlineResponse()
        );
    }

    /*
     * RejectAllRevisions request implementation
     */
    RejectAllRevisionsRequest::RejectAllRevisionsRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName
    ) : 
        m_Name(name),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName)
    {
    }

    const std::shared_ptr< std::wstring > RejectAllRevisionsRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > RejectAllRevisionsRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > RejectAllRevisionsRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > RejectAllRevisionsRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > RejectAllRevisionsRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > RejectAllRevisionsRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > RejectAllRevisionsRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/revisions/rejectAll");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > RejectAllRevisionsRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::RejectAllRevisionsResponse()
        );
    }

    /*
     * RejectAllRevisionsOnline request implementation
     */
    RejectAllRevisionsOnlineRequest::RejectAllRevisionsOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName
    ) : 
        m_Document(document),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName)
    {
    }

    const std::shared_ptr< std::istream > RejectAllRevisionsOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > RejectAllRevisionsOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > RejectAllRevisionsOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > RejectAllRevisionsOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > RejectAllRevisionsOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/revisions/rejectAll");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > RejectAllRevisionsOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::RejectAllRevisionsOnlineResponse()
        );
    }

    /*
     * RemoveRange request implementation
     */
    RemoveRangeRequest::RemoveRangeRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > rangeStartIdentifier,
        const std::shared_ptr< std::wstring > rangeEndIdentifier,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName
    ) : 
        m_Name(name),
        m_RangeStartIdentifier(rangeStartIdentifier),
        m_RangeEndIdentifier(rangeEndIdentifier),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName)
    {
    }

    const std::shared_ptr< std::wstring > RemoveRangeRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > RemoveRangeRequest::getRangeStartIdentifier() const
    {
        return m_RangeStartIdentifier;
    }

    const std::shared_ptr< std::wstring > RemoveRangeRequest::getRangeEndIdentifier() const
    {
        return m_RangeEndIdentifier;
    }

    const std::shared_ptr< std::wstring > RemoveRangeRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > RemoveRangeRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > RemoveRangeRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > RemoveRangeRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > RemoveRangeRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > RemoveRangeRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/{name}/range/{rangeStartIdentifier}/{rangeEndIdentifier}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_RangeStartIdentifier) throw aspose::words::cloud::ApiException(400, L"Parameter 'RangeStartIdentifier' is required.");
        result->setPathParam(L"{rangeStartIdentifier}", *m_RangeStartIdentifier);
        result->setPathParam(L"{rangeEndIdentifier}", m_RangeEndIdentifier ? *m_RangeEndIdentifier : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > RemoveRangeRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::RemoveRangeResponse()
        );
    }

    /*
     * RemoveRangeOnline request implementation
     */
    RemoveRangeOnlineRequest::RemoveRangeOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > rangeStartIdentifier,
        const std::shared_ptr< std::wstring > rangeEndIdentifier,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName
    ) : 
        m_Document(document),
        m_RangeStartIdentifier(rangeStartIdentifier),
        m_RangeEndIdentifier(rangeEndIdentifier),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName)
    {
    }

    const std::shared_ptr< std::istream > RemoveRangeOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > RemoveRangeOnlineRequest::getRangeStartIdentifier() const
    {
        return m_RangeStartIdentifier;
    }

    const std::shared_ptr< std::wstring > RemoveRangeOnlineRequest::getRangeEndIdentifier() const
    {
        return m_RangeEndIdentifier;
    }

    const std::shared_ptr< std::wstring > RemoveRangeOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > RemoveRangeOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > RemoveRangeOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > RemoveRangeOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/delete/range/{rangeStartIdentifier}/{rangeEndIdentifier}");
        if (!m_RangeStartIdentifier) throw aspose::words::cloud::ApiException(400, L"Parameter 'RangeStartIdentifier' is required.");
        result->setPathParam(L"{rangeStartIdentifier}", *m_RangeStartIdentifier);
        result->setPathParam(L"{rangeEndIdentifier}", m_RangeEndIdentifier ? *m_RangeEndIdentifier : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > RemoveRangeOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::RemoveRangeOnlineResponse()
        );
    }

    /*
     * RenderDrawingObject request implementation
     */
    RenderDrawingObjectRequest::RenderDrawingObjectRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > format,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > fontsLocation
    ) : 
        m_Name(name),
        m_Format(format),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_FontsLocation(fontsLocation)
    {
    }

    const std::shared_ptr< std::wstring > RenderDrawingObjectRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > RenderDrawingObjectRequest::getFormat() const
    {
        return m_Format;
    }

    const std::shared_ptr< int32_t > RenderDrawingObjectRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > RenderDrawingObjectRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > RenderDrawingObjectRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > RenderDrawingObjectRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > RenderDrawingObjectRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > RenderDrawingObjectRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > RenderDrawingObjectRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > RenderDrawingObjectRequest::getFontsLocation() const
    {
        return m_FontsLocation;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > RenderDrawingObjectRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{nodePath}/drawingObjects/{index}/render");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Format) result->addQueryParam(L"format", *m_Format);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Format' is required.");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_FontsLocation) result->addQueryParam(L"fontsLocation", *m_FontsLocation);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > RenderDrawingObjectRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::RenderDrawingObjectResponse()
        );
    }

    /*
     * RenderDrawingObjectOnline request implementation
     */
    RenderDrawingObjectOnlineRequest::RenderDrawingObjectOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > format,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > fontsLocation
    ) : 
        m_Document(document),
        m_Format(format),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_FontsLocation(fontsLocation)
    {
    }

    const std::shared_ptr< std::istream > RenderDrawingObjectOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > RenderDrawingObjectOnlineRequest::getFormat() const
    {
        return m_Format;
    }

    const std::shared_ptr< int32_t > RenderDrawingObjectOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > RenderDrawingObjectOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > RenderDrawingObjectOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > RenderDrawingObjectOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > RenderDrawingObjectOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > RenderDrawingObjectOnlineRequest::getFontsLocation() const
    {
        return m_FontsLocation;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > RenderDrawingObjectOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{nodePath}/drawingObjects/{index}/render");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Format) result->addQueryParam(L"format", *m_Format);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Format' is required.");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_FontsLocation) result->addQueryParam(L"fontsLocation", *m_FontsLocation);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > RenderDrawingObjectOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::RenderDrawingObjectOnlineResponse()
        );
    }

    /*
     * RenderMathObject request implementation
     */
    RenderMathObjectRequest::RenderMathObjectRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > format,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > fontsLocation
    ) : 
        m_Name(name),
        m_Format(format),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_FontsLocation(fontsLocation)
    {
    }

    const std::shared_ptr< std::wstring > RenderMathObjectRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > RenderMathObjectRequest::getFormat() const
    {
        return m_Format;
    }

    const std::shared_ptr< int32_t > RenderMathObjectRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > RenderMathObjectRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > RenderMathObjectRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > RenderMathObjectRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > RenderMathObjectRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > RenderMathObjectRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > RenderMathObjectRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > RenderMathObjectRequest::getFontsLocation() const
    {
        return m_FontsLocation;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > RenderMathObjectRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{nodePath}/OfficeMathObjects/{index}/render");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Format) result->addQueryParam(L"format", *m_Format);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Format' is required.");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_FontsLocation) result->addQueryParam(L"fontsLocation", *m_FontsLocation);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > RenderMathObjectRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::RenderMathObjectResponse()
        );
    }

    /*
     * RenderMathObjectOnline request implementation
     */
    RenderMathObjectOnlineRequest::RenderMathObjectOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > format,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > fontsLocation
    ) : 
        m_Document(document),
        m_Format(format),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_FontsLocation(fontsLocation)
    {
    }

    const std::shared_ptr< std::istream > RenderMathObjectOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > RenderMathObjectOnlineRequest::getFormat() const
    {
        return m_Format;
    }

    const std::shared_ptr< int32_t > RenderMathObjectOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > RenderMathObjectOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > RenderMathObjectOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > RenderMathObjectOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > RenderMathObjectOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > RenderMathObjectOnlineRequest::getFontsLocation() const
    {
        return m_FontsLocation;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > RenderMathObjectOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{nodePath}/OfficeMathObjects/{index}/render");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Format) result->addQueryParam(L"format", *m_Format);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Format' is required.");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_FontsLocation) result->addQueryParam(L"fontsLocation", *m_FontsLocation);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > RenderMathObjectOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::RenderMathObjectOnlineResponse()
        );
    }

    /*
     * RenderPage request implementation
     */
    RenderPageRequest::RenderPageRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > pageIndex,
        const std::shared_ptr< std::wstring > format,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > fontsLocation
    ) : 
        m_Name(name),
        m_PageIndex(pageIndex),
        m_Format(format),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_FontsLocation(fontsLocation)
    {
    }

    const std::shared_ptr< std::wstring > RenderPageRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > RenderPageRequest::getPageIndex() const
    {
        return m_PageIndex;
    }

    const std::shared_ptr< std::wstring > RenderPageRequest::getFormat() const
    {
        return m_Format;
    }

    const std::shared_ptr< std::wstring > RenderPageRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > RenderPageRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > RenderPageRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > RenderPageRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > RenderPageRequest::getFontsLocation() const
    {
        return m_FontsLocation;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > RenderPageRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/pages/{pageIndex}/render");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_PageIndex) throw aspose::words::cloud::ApiException(400, L"Parameter 'PageIndex' is required.");
        result->setPathParam(L"{pageIndex}", *m_PageIndex);
        if (m_Format) result->addQueryParam(L"format", *m_Format);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Format' is required.");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_FontsLocation) result->addQueryParam(L"fontsLocation", *m_FontsLocation);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > RenderPageRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::RenderPageResponse()
        );
    }

    /*
     * RenderPageOnline request implementation
     */
    RenderPageOnlineRequest::RenderPageOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > pageIndex,
        const std::shared_ptr< std::wstring > format,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > fontsLocation
    ) : 
        m_Document(document),
        m_PageIndex(pageIndex),
        m_Format(format),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_FontsLocation(fontsLocation)
    {
    }

    const std::shared_ptr< std::istream > RenderPageOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > RenderPageOnlineRequest::getPageIndex() const
    {
        return m_PageIndex;
    }

    const std::shared_ptr< std::wstring > RenderPageOnlineRequest::getFormat() const
    {
        return m_Format;
    }

    const std::shared_ptr< std::wstring > RenderPageOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > RenderPageOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > RenderPageOnlineRequest::getFontsLocation() const
    {
        return m_FontsLocation;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > RenderPageOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/pages/{pageIndex}/render");
        if (!m_PageIndex) throw aspose::words::cloud::ApiException(400, L"Parameter 'PageIndex' is required.");
        result->setPathParam(L"{pageIndex}", *m_PageIndex);
        if (m_Format) result->addQueryParam(L"format", *m_Format);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Format' is required.");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_FontsLocation) result->addQueryParam(L"fontsLocation", *m_FontsLocation);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > RenderPageOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::RenderPageOnlineResponse()
        );
    }

    /*
     * RenderParagraph request implementation
     */
    RenderParagraphRequest::RenderParagraphRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > format,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > fontsLocation
    ) : 
        m_Name(name),
        m_Format(format),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_FontsLocation(fontsLocation)
    {
    }

    const std::shared_ptr< std::wstring > RenderParagraphRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > RenderParagraphRequest::getFormat() const
    {
        return m_Format;
    }

    const std::shared_ptr< int32_t > RenderParagraphRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > RenderParagraphRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > RenderParagraphRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > RenderParagraphRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > RenderParagraphRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > RenderParagraphRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > RenderParagraphRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > RenderParagraphRequest::getFontsLocation() const
    {
        return m_FontsLocation;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > RenderParagraphRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{nodePath}/paragraphs/{index}/render");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Format) result->addQueryParam(L"format", *m_Format);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Format' is required.");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_FontsLocation) result->addQueryParam(L"fontsLocation", *m_FontsLocation);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > RenderParagraphRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::RenderParagraphResponse()
        );
    }

    /*
     * RenderParagraphOnline request implementation
     */
    RenderParagraphOnlineRequest::RenderParagraphOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > format,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > fontsLocation
    ) : 
        m_Document(document),
        m_Format(format),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_FontsLocation(fontsLocation)
    {
    }

    const std::shared_ptr< std::istream > RenderParagraphOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > RenderParagraphOnlineRequest::getFormat() const
    {
        return m_Format;
    }

    const std::shared_ptr< int32_t > RenderParagraphOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > RenderParagraphOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > RenderParagraphOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > RenderParagraphOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > RenderParagraphOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > RenderParagraphOnlineRequest::getFontsLocation() const
    {
        return m_FontsLocation;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > RenderParagraphOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{nodePath}/paragraphs/{index}/render");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Format) result->addQueryParam(L"format", *m_Format);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Format' is required.");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_FontsLocation) result->addQueryParam(L"fontsLocation", *m_FontsLocation);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > RenderParagraphOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::RenderParagraphOnlineResponse()
        );
    }

    /*
     * RenderTable request implementation
     */
    RenderTableRequest::RenderTableRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > format,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > fontsLocation
    ) : 
        m_Name(name),
        m_Format(format),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_FontsLocation(fontsLocation)
    {
    }

    const std::shared_ptr< std::wstring > RenderTableRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > RenderTableRequest::getFormat() const
    {
        return m_Format;
    }

    const std::shared_ptr< int32_t > RenderTableRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > RenderTableRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > RenderTableRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > RenderTableRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > RenderTableRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > RenderTableRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > RenderTableRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > RenderTableRequest::getFontsLocation() const
    {
        return m_FontsLocation;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > RenderTableRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/{nodePath}/tables/{index}/render");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Format) result->addQueryParam(L"format", *m_Format);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Format' is required.");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_FontsLocation) result->addQueryParam(L"fontsLocation", *m_FontsLocation);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > RenderTableRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::RenderTableResponse()
        );
    }

    /*
     * RenderTableOnline request implementation
     */
    RenderTableOnlineRequest::RenderTableOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > format,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > fontsLocation
    ) : 
        m_Document(document),
        m_Format(format),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_FontsLocation(fontsLocation)
    {
    }

    const std::shared_ptr< std::istream > RenderTableOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > RenderTableOnlineRequest::getFormat() const
    {
        return m_Format;
    }

    const std::shared_ptr< int32_t > RenderTableOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > RenderTableOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > RenderTableOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > RenderTableOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > RenderTableOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > RenderTableOnlineRequest::getFontsLocation() const
    {
        return m_FontsLocation;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > RenderTableOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/{nodePath}/tables/{index}/render");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Format) result->addQueryParam(L"format", *m_Format);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Format' is required.");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_FontsLocation) result->addQueryParam(L"fontsLocation", *m_FontsLocation);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > RenderTableOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::RenderTableOnlineResponse()
        );
    }

    /*
     * ReplaceText request implementation
     */
    ReplaceTextRequest::ReplaceTextRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< aspose::words::cloud::models::ReplaceTextParameters > replaceText,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_ReplaceText(replaceText),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > ReplaceTextRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< aspose::words::cloud::models::ReplaceTextParameters > ReplaceTextRequest::getReplaceText() const
    {
        return m_ReplaceText;
    }

    const std::shared_ptr< std::wstring > ReplaceTextRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > ReplaceTextRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > ReplaceTextRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > ReplaceTextRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > ReplaceTextRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > ReplaceTextRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > ReplaceTextRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > ReplaceTextRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/replaceText");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_ReplaceText) result->setBody(*m_ReplaceText);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'ReplaceText' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > ReplaceTextRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::ReplaceTextResponse()
        );
    }

    /*
     * ReplaceTextOnline request implementation
     */
    ReplaceTextOnlineRequest::ReplaceTextOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::ReplaceTextParameters > replaceText,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_ReplaceText(replaceText),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > ReplaceTextOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::ReplaceTextParameters > ReplaceTextOnlineRequest::getReplaceText() const
    {
        return m_ReplaceText;
    }

    const std::shared_ptr< std::wstring > ReplaceTextOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > ReplaceTextOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > ReplaceTextOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > ReplaceTextOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > ReplaceTextOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > ReplaceTextOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/replaceText");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_ReplaceText) result->addFormDataParam(L"replaceText", *m_ReplaceText);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'ReplaceText' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > ReplaceTextOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::ReplaceTextOnlineResponse()
        );
    }

    /*
     * ReplaceWithText request implementation
     */
    ReplaceWithTextRequest::ReplaceWithTextRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > rangeStartIdentifier,
        const std::shared_ptr< aspose::words::cloud::models::ReplaceRange > rangeText,
        const std::shared_ptr< std::wstring > rangeEndIdentifier,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName
    ) : 
        m_Name(name),
        m_RangeStartIdentifier(rangeStartIdentifier),
        m_RangeText(rangeText),
        m_RangeEndIdentifier(rangeEndIdentifier),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName)
    {
    }

    const std::shared_ptr< std::wstring > ReplaceWithTextRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > ReplaceWithTextRequest::getRangeStartIdentifier() const
    {
        return m_RangeStartIdentifier;
    }

    const std::shared_ptr< aspose::words::cloud::models::ReplaceRange > ReplaceWithTextRequest::getRangeText() const
    {
        return m_RangeText;
    }

    const std::shared_ptr< std::wstring > ReplaceWithTextRequest::getRangeEndIdentifier() const
    {
        return m_RangeEndIdentifier;
    }

    const std::shared_ptr< std::wstring > ReplaceWithTextRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > ReplaceWithTextRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > ReplaceWithTextRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > ReplaceWithTextRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > ReplaceWithTextRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > ReplaceWithTextRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPOST);
        result->setPath(L"/words/{name}/range/{rangeStartIdentifier}/{rangeEndIdentifier}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_RangeStartIdentifier) throw aspose::words::cloud::ApiException(400, L"Parameter 'RangeStartIdentifier' is required.");
        result->setPathParam(L"{rangeStartIdentifier}", *m_RangeStartIdentifier);
        result->setPathParam(L"{rangeEndIdentifier}", m_RangeEndIdentifier ? *m_RangeEndIdentifier : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RangeText) result->setBody(*m_RangeText);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'RangeText' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > ReplaceWithTextRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::ReplaceWithTextResponse()
        );
    }

    /*
     * ReplaceWithTextOnline request implementation
     */
    ReplaceWithTextOnlineRequest::ReplaceWithTextOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > rangeStartIdentifier,
        const std::shared_ptr< aspose::words::cloud::models::ReplaceRange > rangeText,
        const std::shared_ptr< std::wstring > rangeEndIdentifier,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName
    ) : 
        m_Document(document),
        m_RangeStartIdentifier(rangeStartIdentifier),
        m_RangeText(rangeText),
        m_RangeEndIdentifier(rangeEndIdentifier),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName)
    {
    }

    const std::shared_ptr< std::istream > ReplaceWithTextOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > ReplaceWithTextOnlineRequest::getRangeStartIdentifier() const
    {
        return m_RangeStartIdentifier;
    }

    const std::shared_ptr< aspose::words::cloud::models::ReplaceRange > ReplaceWithTextOnlineRequest::getRangeText() const
    {
        return m_RangeText;
    }

    const std::shared_ptr< std::wstring > ReplaceWithTextOnlineRequest::getRangeEndIdentifier() const
    {
        return m_RangeEndIdentifier;
    }

    const std::shared_ptr< std::wstring > ReplaceWithTextOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > ReplaceWithTextOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > ReplaceWithTextOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > ReplaceWithTextOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/post/range/{rangeStartIdentifier}/{rangeEndIdentifier}");
        if (!m_RangeStartIdentifier) throw aspose::words::cloud::ApiException(400, L"Parameter 'RangeStartIdentifier' is required.");
        result->setPathParam(L"{rangeStartIdentifier}", *m_RangeStartIdentifier);
        result->setPathParam(L"{rangeEndIdentifier}", m_RangeEndIdentifier ? *m_RangeEndIdentifier : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_RangeText) result->addFormDataParam(L"rangeText", *m_RangeText);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'RangeText' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > ReplaceWithTextOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::ReplaceWithTextOnlineResponse()
        );
    }

    /*
     * ResetCache request implementation
     */
    ResetCacheRequest::ResetCacheRequest(
    ) 
    {
    }


    std::shared_ptr< aspose::words::cloud::HttpRequestData > ResetCacheRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/fonts/cache");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > ResetCacheRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::ResetCacheResponse()
        );
    }

    /*
     * SaveAs request implementation
     */
    SaveAsRequest::SaveAsRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< aspose::words::cloud::models::SaveOptionsData > saveOptionsData,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > fontsLocation
    ) : 
        m_Name(name),
        m_SaveOptionsData(saveOptionsData),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_FontsLocation(fontsLocation)
    {
    }

    const std::shared_ptr< std::wstring > SaveAsRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< aspose::words::cloud::models::SaveOptionsData > SaveAsRequest::getSaveOptionsData() const
    {
        return m_SaveOptionsData;
    }

    const std::shared_ptr< std::wstring > SaveAsRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > SaveAsRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > SaveAsRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > SaveAsRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > SaveAsRequest::getFontsLocation() const
    {
        return m_FontsLocation;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > SaveAsRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/saveAs");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_FontsLocation) result->addQueryParam(L"fontsLocation", *m_FontsLocation);
        if (m_SaveOptionsData) result->setBody(*m_SaveOptionsData);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'SaveOptionsData' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > SaveAsRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::SaveAsResponse()
        );
    }

    /*
     * SaveAsOnline request implementation
     */
    SaveAsOnlineRequest::SaveAsOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::SaveOptionsData > saveOptionsData,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > fontsLocation
    ) : 
        m_Document(document),
        m_SaveOptionsData(saveOptionsData),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_FontsLocation(fontsLocation)
    {
    }

    const std::shared_ptr< std::istream > SaveAsOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::SaveOptionsData > SaveAsOnlineRequest::getSaveOptionsData() const
    {
        return m_SaveOptionsData;
    }

    const std::shared_ptr< std::wstring > SaveAsOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > SaveAsOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > SaveAsOnlineRequest::getFontsLocation() const
    {
        return m_FontsLocation;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > SaveAsOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/saveAs");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_FontsLocation) result->addQueryParam(L"fontsLocation", *m_FontsLocation);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_SaveOptionsData) result->addFormDataParam(L"saveOptionsData", *m_SaveOptionsData);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'SaveOptionsData' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > SaveAsOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::SaveAsOnlineResponse()
        );
    }

    /*
     * SaveAsRange request implementation
     */
    SaveAsRangeRequest::SaveAsRangeRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > rangeStartIdentifier,
        const std::shared_ptr< aspose::words::cloud::models::RangeDocument > documentParameters,
        const std::shared_ptr< std::wstring > rangeEndIdentifier,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_RangeStartIdentifier(rangeStartIdentifier),
        m_DocumentParameters(documentParameters),
        m_RangeEndIdentifier(rangeEndIdentifier),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > SaveAsRangeRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > SaveAsRangeRequest::getRangeStartIdentifier() const
    {
        return m_RangeStartIdentifier;
    }

    const std::shared_ptr< aspose::words::cloud::models::RangeDocument > SaveAsRangeRequest::getDocumentParameters() const
    {
        return m_DocumentParameters;
    }

    const std::shared_ptr< std::wstring > SaveAsRangeRequest::getRangeEndIdentifier() const
    {
        return m_RangeEndIdentifier;
    }

    const std::shared_ptr< std::wstring > SaveAsRangeRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > SaveAsRangeRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > SaveAsRangeRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > SaveAsRangeRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > SaveAsRangeRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPOST);
        result->setPath(L"/words/{name}/range/{rangeStartIdentifier}/{rangeEndIdentifier}/SaveAs");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_RangeStartIdentifier) throw aspose::words::cloud::ApiException(400, L"Parameter 'RangeStartIdentifier' is required.");
        result->setPathParam(L"{rangeStartIdentifier}", *m_RangeStartIdentifier);
        result->setPathParam(L"{rangeEndIdentifier}", m_RangeEndIdentifier ? *m_RangeEndIdentifier : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DocumentParameters) result->setBody(*m_DocumentParameters);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'DocumentParameters' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > SaveAsRangeRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::SaveAsRangeResponse()
        );
    }

    /*
     * SaveAsRangeOnline request implementation
     */
    SaveAsRangeOnlineRequest::SaveAsRangeOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > rangeStartIdentifier,
        const std::shared_ptr< aspose::words::cloud::models::RangeDocument > documentParameters,
        const std::shared_ptr< std::wstring > rangeEndIdentifier,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_RangeStartIdentifier(rangeStartIdentifier),
        m_DocumentParameters(documentParameters),
        m_RangeEndIdentifier(rangeEndIdentifier),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > SaveAsRangeOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > SaveAsRangeOnlineRequest::getRangeStartIdentifier() const
    {
        return m_RangeStartIdentifier;
    }

    const std::shared_ptr< aspose::words::cloud::models::RangeDocument > SaveAsRangeOnlineRequest::getDocumentParameters() const
    {
        return m_DocumentParameters;
    }

    const std::shared_ptr< std::wstring > SaveAsRangeOnlineRequest::getRangeEndIdentifier() const
    {
        return m_RangeEndIdentifier;
    }

    const std::shared_ptr< std::wstring > SaveAsRangeOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > SaveAsRangeOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > SaveAsRangeOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/post/range/{rangeStartIdentifier}/{rangeEndIdentifier}/SaveAs");
        if (!m_RangeStartIdentifier) throw aspose::words::cloud::ApiException(400, L"Parameter 'RangeStartIdentifier' is required.");
        result->setPathParam(L"{rangeStartIdentifier}", *m_RangeStartIdentifier);
        result->setPathParam(L"{rangeEndIdentifier}", m_RangeEndIdentifier ? *m_RangeEndIdentifier : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_DocumentParameters) result->addFormDataParam(L"documentParameters", *m_DocumentParameters);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'DocumentParameters' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > SaveAsRangeOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::SaveAsRangeOnlineResponse()
        );
    }

    /*
     * SaveAsTiff request implementation
     */
    SaveAsTiffRequest::SaveAsTiffRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< aspose::words::cloud::models::TiffSaveOptionsData > saveOptions,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< bool > useAntiAliasing,
        const std::shared_ptr< bool > useHighQualityRendering,
        const std::shared_ptr< double > imageBrightness,
        const std::shared_ptr< std::wstring > imageColorMode,
        const std::shared_ptr< double > imageContrast,
        const std::shared_ptr< std::wstring > numeralFormat,
        const std::shared_ptr< int32_t > pageCount,
        const std::shared_ptr< int32_t > pageIndex,
        const std::shared_ptr< std::wstring > paperColor,
        const std::shared_ptr< std::wstring > pixelFormat,
        const std::shared_ptr< double > resolution,
        const std::shared_ptr< double > scale,
        const std::shared_ptr< std::wstring > tiffCompression,
        const std::shared_ptr< std::wstring > dmlRenderingMode,
        const std::shared_ptr< std::wstring > dmlEffectsRenderingMode,
        const std::shared_ptr< std::wstring > tiffBinarizationMethod,
        const std::shared_ptr< bool > zipOutput,
        const std::shared_ptr< std::wstring > fontsLocation
    ) : 
        m_Name(name),
        m_SaveOptions(saveOptions),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_UseAntiAliasing(useAntiAliasing),
        m_UseHighQualityRendering(useHighQualityRendering),
        m_ImageBrightness(imageBrightness),
        m_ImageColorMode(imageColorMode),
        m_ImageContrast(imageContrast),
        m_NumeralFormat(numeralFormat),
        m_PageCount(pageCount),
        m_PageIndex(pageIndex),
        m_PaperColor(paperColor),
        m_PixelFormat(pixelFormat),
        m_Resolution(resolution),
        m_Scale(scale),
        m_TiffCompression(tiffCompression),
        m_DmlRenderingMode(dmlRenderingMode),
        m_DmlEffectsRenderingMode(dmlEffectsRenderingMode),
        m_TiffBinarizationMethod(tiffBinarizationMethod),
        m_ZipOutput(zipOutput),
        m_FontsLocation(fontsLocation)
    {
    }

    const std::shared_ptr< std::wstring > SaveAsTiffRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< aspose::words::cloud::models::TiffSaveOptionsData > SaveAsTiffRequest::getSaveOptions() const
    {
        return m_SaveOptions;
    }

    const std::shared_ptr< std::wstring > SaveAsTiffRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > SaveAsTiffRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > SaveAsTiffRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > SaveAsTiffRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< bool > SaveAsTiffRequest::getUseAntiAliasing() const
    {
        return m_UseAntiAliasing;
    }

    const std::shared_ptr< bool > SaveAsTiffRequest::getUseHighQualityRendering() const
    {
        return m_UseHighQualityRendering;
    }

    const std::shared_ptr< double > SaveAsTiffRequest::getImageBrightness() const
    {
        return m_ImageBrightness;
    }

    const std::shared_ptr< std::wstring > SaveAsTiffRequest::getImageColorMode() const
    {
        return m_ImageColorMode;
    }

    const std::shared_ptr< double > SaveAsTiffRequest::getImageContrast() const
    {
        return m_ImageContrast;
    }

    const std::shared_ptr< std::wstring > SaveAsTiffRequest::getNumeralFormat() const
    {
        return m_NumeralFormat;
    }

    const std::shared_ptr< int32_t > SaveAsTiffRequest::getPageCount() const
    {
        return m_PageCount;
    }

    const std::shared_ptr< int32_t > SaveAsTiffRequest::getPageIndex() const
    {
        return m_PageIndex;
    }

    const std::shared_ptr< std::wstring > SaveAsTiffRequest::getPaperColor() const
    {
        return m_PaperColor;
    }

    const std::shared_ptr< std::wstring > SaveAsTiffRequest::getPixelFormat() const
    {
        return m_PixelFormat;
    }

    const std::shared_ptr< double > SaveAsTiffRequest::getResolution() const
    {
        return m_Resolution;
    }

    const std::shared_ptr< double > SaveAsTiffRequest::getScale() const
    {
        return m_Scale;
    }

    const std::shared_ptr< std::wstring > SaveAsTiffRequest::getTiffCompression() const
    {
        return m_TiffCompression;
    }

    const std::shared_ptr< std::wstring > SaveAsTiffRequest::getDmlRenderingMode() const
    {
        return m_DmlRenderingMode;
    }

    const std::shared_ptr< std::wstring > SaveAsTiffRequest::getDmlEffectsRenderingMode() const
    {
        return m_DmlEffectsRenderingMode;
    }

    const std::shared_ptr< std::wstring > SaveAsTiffRequest::getTiffBinarizationMethod() const
    {
        return m_TiffBinarizationMethod;
    }

    const std::shared_ptr< bool > SaveAsTiffRequest::getZipOutput() const
    {
        return m_ZipOutput;
    }

    const std::shared_ptr< std::wstring > SaveAsTiffRequest::getFontsLocation() const
    {
        return m_FontsLocation;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > SaveAsTiffRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/saveAs/tiff");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_UseAntiAliasing) result->addQueryParam(L"useAntiAliasing", *m_UseAntiAliasing);
        if (m_UseHighQualityRendering) result->addQueryParam(L"useHighQualityRendering", *m_UseHighQualityRendering);
        if (m_ImageBrightness) result->addQueryParam(L"imageBrightness", *m_ImageBrightness);
        if (m_ImageColorMode) result->addQueryParam(L"imageColorMode", *m_ImageColorMode);
        if (m_ImageContrast) result->addQueryParam(L"imageContrast", *m_ImageContrast);
        if (m_NumeralFormat) result->addQueryParam(L"numeralFormat", *m_NumeralFormat);
        if (m_PageCount) result->addQueryParam(L"pageCount", *m_PageCount);
        if (m_PageIndex) result->addQueryParam(L"pageIndex", *m_PageIndex);
        if (m_PaperColor) result->addQueryParam(L"paperColor", *m_PaperColor);
        if (m_PixelFormat) result->addQueryParam(L"pixelFormat", *m_PixelFormat);
        if (m_Resolution) result->addQueryParam(L"resolution", *m_Resolution);
        if (m_Scale) result->addQueryParam(L"scale", *m_Scale);
        if (m_TiffCompression) result->addQueryParam(L"tiffCompression", *m_TiffCompression);
        if (m_DmlRenderingMode) result->addQueryParam(L"dmlRenderingMode", *m_DmlRenderingMode);
        if (m_DmlEffectsRenderingMode) result->addQueryParam(L"dmlEffectsRenderingMode", *m_DmlEffectsRenderingMode);
        if (m_TiffBinarizationMethod) result->addQueryParam(L"tiffBinarizationMethod", *m_TiffBinarizationMethod);
        if (m_ZipOutput) result->addQueryParam(L"zipOutput", *m_ZipOutput);
        if (m_FontsLocation) result->addQueryParam(L"fontsLocation", *m_FontsLocation);
        if (m_SaveOptions) result->setBody(*m_SaveOptions);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'SaveOptions' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > SaveAsTiffRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::SaveAsTiffResponse()
        );
    }

    /*
     * SaveAsTiffOnline request implementation
     */
    SaveAsTiffOnlineRequest::SaveAsTiffOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::TiffSaveOptionsData > saveOptions,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< bool > useAntiAliasing,
        const std::shared_ptr< bool > useHighQualityRendering,
        const std::shared_ptr< double > imageBrightness,
        const std::shared_ptr< std::wstring > imageColorMode,
        const std::shared_ptr< double > imageContrast,
        const std::shared_ptr< std::wstring > numeralFormat,
        const std::shared_ptr< int32_t > pageCount,
        const std::shared_ptr< int32_t > pageIndex,
        const std::shared_ptr< std::wstring > paperColor,
        const std::shared_ptr< std::wstring > pixelFormat,
        const std::shared_ptr< double > resolution,
        const std::shared_ptr< double > scale,
        const std::shared_ptr< std::wstring > tiffCompression,
        const std::shared_ptr< std::wstring > dmlRenderingMode,
        const std::shared_ptr< std::wstring > dmlEffectsRenderingMode,
        const std::shared_ptr< std::wstring > tiffBinarizationMethod,
        const std::shared_ptr< bool > zipOutput,
        const std::shared_ptr< std::wstring > fontsLocation
    ) : 
        m_Document(document),
        m_SaveOptions(saveOptions),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_UseAntiAliasing(useAntiAliasing),
        m_UseHighQualityRendering(useHighQualityRendering),
        m_ImageBrightness(imageBrightness),
        m_ImageColorMode(imageColorMode),
        m_ImageContrast(imageContrast),
        m_NumeralFormat(numeralFormat),
        m_PageCount(pageCount),
        m_PageIndex(pageIndex),
        m_PaperColor(paperColor),
        m_PixelFormat(pixelFormat),
        m_Resolution(resolution),
        m_Scale(scale),
        m_TiffCompression(tiffCompression),
        m_DmlRenderingMode(dmlRenderingMode),
        m_DmlEffectsRenderingMode(dmlEffectsRenderingMode),
        m_TiffBinarizationMethod(tiffBinarizationMethod),
        m_ZipOutput(zipOutput),
        m_FontsLocation(fontsLocation)
    {
    }

    const std::shared_ptr< std::istream > SaveAsTiffOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::TiffSaveOptionsData > SaveAsTiffOnlineRequest::getSaveOptions() const
    {
        return m_SaveOptions;
    }

    const std::shared_ptr< std::wstring > SaveAsTiffOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > SaveAsTiffOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< bool > SaveAsTiffOnlineRequest::getUseAntiAliasing() const
    {
        return m_UseAntiAliasing;
    }

    const std::shared_ptr< bool > SaveAsTiffOnlineRequest::getUseHighQualityRendering() const
    {
        return m_UseHighQualityRendering;
    }

    const std::shared_ptr< double > SaveAsTiffOnlineRequest::getImageBrightness() const
    {
        return m_ImageBrightness;
    }

    const std::shared_ptr< std::wstring > SaveAsTiffOnlineRequest::getImageColorMode() const
    {
        return m_ImageColorMode;
    }

    const std::shared_ptr< double > SaveAsTiffOnlineRequest::getImageContrast() const
    {
        return m_ImageContrast;
    }

    const std::shared_ptr< std::wstring > SaveAsTiffOnlineRequest::getNumeralFormat() const
    {
        return m_NumeralFormat;
    }

    const std::shared_ptr< int32_t > SaveAsTiffOnlineRequest::getPageCount() const
    {
        return m_PageCount;
    }

    const std::shared_ptr< int32_t > SaveAsTiffOnlineRequest::getPageIndex() const
    {
        return m_PageIndex;
    }

    const std::shared_ptr< std::wstring > SaveAsTiffOnlineRequest::getPaperColor() const
    {
        return m_PaperColor;
    }

    const std::shared_ptr< std::wstring > SaveAsTiffOnlineRequest::getPixelFormat() const
    {
        return m_PixelFormat;
    }

    const std::shared_ptr< double > SaveAsTiffOnlineRequest::getResolution() const
    {
        return m_Resolution;
    }

    const std::shared_ptr< double > SaveAsTiffOnlineRequest::getScale() const
    {
        return m_Scale;
    }

    const std::shared_ptr< std::wstring > SaveAsTiffOnlineRequest::getTiffCompression() const
    {
        return m_TiffCompression;
    }

    const std::shared_ptr< std::wstring > SaveAsTiffOnlineRequest::getDmlRenderingMode() const
    {
        return m_DmlRenderingMode;
    }

    const std::shared_ptr< std::wstring > SaveAsTiffOnlineRequest::getDmlEffectsRenderingMode() const
    {
        return m_DmlEffectsRenderingMode;
    }

    const std::shared_ptr< std::wstring > SaveAsTiffOnlineRequest::getTiffBinarizationMethod() const
    {
        return m_TiffBinarizationMethod;
    }

    const std::shared_ptr< bool > SaveAsTiffOnlineRequest::getZipOutput() const
    {
        return m_ZipOutput;
    }

    const std::shared_ptr< std::wstring > SaveAsTiffOnlineRequest::getFontsLocation() const
    {
        return m_FontsLocation;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > SaveAsTiffOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/saveAs/tiff");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_UseAntiAliasing) result->addQueryParam(L"useAntiAliasing", *m_UseAntiAliasing);
        if (m_UseHighQualityRendering) result->addQueryParam(L"useHighQualityRendering", *m_UseHighQualityRendering);
        if (m_ImageBrightness) result->addQueryParam(L"imageBrightness", *m_ImageBrightness);
        if (m_ImageColorMode) result->addQueryParam(L"imageColorMode", *m_ImageColorMode);
        if (m_ImageContrast) result->addQueryParam(L"imageContrast", *m_ImageContrast);
        if (m_NumeralFormat) result->addQueryParam(L"numeralFormat", *m_NumeralFormat);
        if (m_PageCount) result->addQueryParam(L"pageCount", *m_PageCount);
        if (m_PageIndex) result->addQueryParam(L"pageIndex", *m_PageIndex);
        if (m_PaperColor) result->addQueryParam(L"paperColor", *m_PaperColor);
        if (m_PixelFormat) result->addQueryParam(L"pixelFormat", *m_PixelFormat);
        if (m_Resolution) result->addQueryParam(L"resolution", *m_Resolution);
        if (m_Scale) result->addQueryParam(L"scale", *m_Scale);
        if (m_TiffCompression) result->addQueryParam(L"tiffCompression", *m_TiffCompression);
        if (m_DmlRenderingMode) result->addQueryParam(L"dmlRenderingMode", *m_DmlRenderingMode);
        if (m_DmlEffectsRenderingMode) result->addQueryParam(L"dmlEffectsRenderingMode", *m_DmlEffectsRenderingMode);
        if (m_TiffBinarizationMethod) result->addQueryParam(L"tiffBinarizationMethod", *m_TiffBinarizationMethod);
        if (m_ZipOutput) result->addQueryParam(L"zipOutput", *m_ZipOutput);
        if (m_FontsLocation) result->addQueryParam(L"fontsLocation", *m_FontsLocation);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_SaveOptions) result->addFormDataParam(L"saveOptions", *m_SaveOptions);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'SaveOptions' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > SaveAsTiffOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::SaveAsTiffOnlineResponse()
        );
    }

    /*
     * Search request implementation
     */
    SearchRequest::SearchRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > pattern,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Name(name),
        m_Pattern(pattern),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::wstring > SearchRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > SearchRequest::getPattern() const
    {
        return m_Pattern;
    }

    const std::shared_ptr< std::wstring > SearchRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > SearchRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > SearchRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > SearchRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > SearchRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpGET);
        result->setPath(L"/words/{name}/search");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Pattern) result->addQueryParam(L"pattern", *m_Pattern);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Pattern' is required.");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > SearchRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::SearchResponse()
        );
    }

    /*
     * SearchOnline request implementation
     */
    SearchOnlineRequest::SearchOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > pattern,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password
    ) : 
        m_Document(document),
        m_Pattern(pattern),
        m_LoadEncoding(loadEncoding),
        m_Password(password)
    {
    }

    const std::shared_ptr< std::istream > SearchOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > SearchOnlineRequest::getPattern() const
    {
        return m_Pattern;
    }

    const std::shared_ptr< std::wstring > SearchOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > SearchOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > SearchOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/get/search");
        if (m_Pattern) result->addQueryParam(L"pattern", *m_Pattern);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Pattern' is required.");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > SearchOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::SearchOnlineResponse()
        );
    }

    /*
     * SplitDocument request implementation
     */
    SplitDocumentRequest::SplitDocumentRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > format,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< int32_t > from,
        const std::shared_ptr< int32_t > to,
        const std::shared_ptr< bool > zipOutput,
        const std::shared_ptr< std::wstring > fontsLocation
    ) : 
        m_Name(name),
        m_Format(format),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_From(from),
        m_To(to),
        m_ZipOutput(zipOutput),
        m_FontsLocation(fontsLocation)
    {
    }

    const std::shared_ptr< std::wstring > SplitDocumentRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > SplitDocumentRequest::getFormat() const
    {
        return m_Format;
    }

    const std::shared_ptr< std::wstring > SplitDocumentRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > SplitDocumentRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > SplitDocumentRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > SplitDocumentRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > SplitDocumentRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< int32_t > SplitDocumentRequest::getFrom() const
    {
        return m_From;
    }

    const std::shared_ptr< int32_t > SplitDocumentRequest::getTo() const
    {
        return m_To;
    }

    const std::shared_ptr< bool > SplitDocumentRequest::getZipOutput() const
    {
        return m_ZipOutput;
    }

    const std::shared_ptr< std::wstring > SplitDocumentRequest::getFontsLocation() const
    {
        return m_FontsLocation;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > SplitDocumentRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/split");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Format) result->addQueryParam(L"format", *m_Format);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Format' is required.");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_From) result->addQueryParam(L"from", *m_From);
        if (m_To) result->addQueryParam(L"to", *m_To);
        if (m_ZipOutput) result->addQueryParam(L"zipOutput", *m_ZipOutput);
        if (m_FontsLocation) result->addQueryParam(L"fontsLocation", *m_FontsLocation);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > SplitDocumentRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::SplitDocumentResponse()
        );
    }

    /*
     * SplitDocumentOnline request implementation
     */
    SplitDocumentOnlineRequest::SplitDocumentOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > format,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< int32_t > from,
        const std::shared_ptr< int32_t > to,
        const std::shared_ptr< bool > zipOutput,
        const std::shared_ptr< std::wstring > fontsLocation
    ) : 
        m_Document(document),
        m_Format(format),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_From(from),
        m_To(to),
        m_ZipOutput(zipOutput),
        m_FontsLocation(fontsLocation)
    {
    }

    const std::shared_ptr< std::istream > SplitDocumentOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > SplitDocumentOnlineRequest::getFormat() const
    {
        return m_Format;
    }

    const std::shared_ptr< std::wstring > SplitDocumentOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > SplitDocumentOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > SplitDocumentOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< int32_t > SplitDocumentOnlineRequest::getFrom() const
    {
        return m_From;
    }

    const std::shared_ptr< int32_t > SplitDocumentOnlineRequest::getTo() const
    {
        return m_To;
    }

    const std::shared_ptr< bool > SplitDocumentOnlineRequest::getZipOutput() const
    {
        return m_ZipOutput;
    }

    const std::shared_ptr< std::wstring > SplitDocumentOnlineRequest::getFontsLocation() const
    {
        return m_FontsLocation;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > SplitDocumentOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/split");
        if (m_Format) result->addQueryParam(L"format", *m_Format);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Format' is required.");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_From) result->addQueryParam(L"from", *m_From);
        if (m_To) result->addQueryParam(L"to", *m_To);
        if (m_ZipOutput) result->addQueryParam(L"zipOutput", *m_ZipOutput);
        if (m_FontsLocation) result->addQueryParam(L"fontsLocation", *m_FontsLocation);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > SplitDocumentOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::SplitDocumentOnlineResponse()
        );
    }

    /*
     * UnprotectDocument request implementation
     */
    UnprotectDocumentRequest::UnprotectDocumentRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< aspose::words::cloud::models::ProtectionRequest > protectionRequest,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName
    ) : 
        m_Name(name),
        m_ProtectionRequest(protectionRequest),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName)
    {
    }

    const std::shared_ptr< std::wstring > UnprotectDocumentRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< aspose::words::cloud::models::ProtectionRequest > UnprotectDocumentRequest::getProtectionRequest() const
    {
        return m_ProtectionRequest;
    }

    const std::shared_ptr< std::wstring > UnprotectDocumentRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > UnprotectDocumentRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > UnprotectDocumentRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UnprotectDocumentRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UnprotectDocumentRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UnprotectDocumentRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpDELETE);
        result->setPath(L"/words/{name}/protection");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_ProtectionRequest) result->setBody(*m_ProtectionRequest);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'ProtectionRequest' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UnprotectDocumentRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UnprotectDocumentResponse()
        );
    }

    /*
     * UnprotectDocumentOnline request implementation
     */
    UnprotectDocumentOnlineRequest::UnprotectDocumentOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::ProtectionRequest > protectionRequest,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName
    ) : 
        m_Document(document),
        m_ProtectionRequest(protectionRequest),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName)
    {
    }

    const std::shared_ptr< std::istream > UnprotectDocumentOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::ProtectionRequest > UnprotectDocumentOnlineRequest::getProtectionRequest() const
    {
        return m_ProtectionRequest;
    }

    const std::shared_ptr< std::wstring > UnprotectDocumentOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UnprotectDocumentOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UnprotectDocumentOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UnprotectDocumentOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/delete/protection");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_ProtectionRequest) result->addFormDataParam(L"protectionRequest", *m_ProtectionRequest);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'ProtectionRequest' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UnprotectDocumentOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UnprotectDocumentOnlineResponse()
        );
    }

    /*
     * UpdateBookmark request implementation
     */
    UpdateBookmarkRequest::UpdateBookmarkRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > bookmarkName,
        const std::shared_ptr< aspose::words::cloud::models::BookmarkData > bookmarkData,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_BookmarkName(bookmarkName),
        m_BookmarkData(bookmarkData),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > UpdateBookmarkRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > UpdateBookmarkRequest::getBookmarkName() const
    {
        return m_BookmarkName;
    }

    const std::shared_ptr< aspose::words::cloud::models::BookmarkData > UpdateBookmarkRequest::getBookmarkData() const
    {
        return m_BookmarkData;
    }

    const std::shared_ptr< std::wstring > UpdateBookmarkRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > UpdateBookmarkRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > UpdateBookmarkRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateBookmarkRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateBookmarkRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateBookmarkRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateBookmarkRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateBookmarkRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/bookmarks/{bookmarkName}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_BookmarkName) throw aspose::words::cloud::ApiException(400, L"Parameter 'BookmarkName' is required.");
        result->setPathParam(L"{bookmarkName}", *m_BookmarkName);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_BookmarkData) result->setBody(*m_BookmarkData);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'BookmarkData' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateBookmarkRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateBookmarkResponse()
        );
    }

    /*
     * UpdateBookmarkOnline request implementation
     */
    UpdateBookmarkOnlineRequest::UpdateBookmarkOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > bookmarkName,
        const std::shared_ptr< aspose::words::cloud::models::BookmarkData > bookmarkData,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_BookmarkName(bookmarkName),
        m_BookmarkData(bookmarkData),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > UpdateBookmarkOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > UpdateBookmarkOnlineRequest::getBookmarkName() const
    {
        return m_BookmarkName;
    }

    const std::shared_ptr< aspose::words::cloud::models::BookmarkData > UpdateBookmarkOnlineRequest::getBookmarkData() const
    {
        return m_BookmarkData;
    }

    const std::shared_ptr< std::wstring > UpdateBookmarkOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateBookmarkOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateBookmarkOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateBookmarkOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateBookmarkOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateBookmarkOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/bookmarks/{bookmarkName}");
        if (!m_BookmarkName) throw aspose::words::cloud::ApiException(400, L"Parameter 'BookmarkName' is required.");
        result->setPathParam(L"{bookmarkName}", *m_BookmarkName);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_BookmarkData) result->addFormDataParam(L"bookmarkData", *m_BookmarkData);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'BookmarkData' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateBookmarkOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateBookmarkOnlineResponse()
        );
    }

    /*
     * UpdateBorder request implementation
     */
    UpdateBorderRequest::UpdateBorderRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > borderType,
        const std::shared_ptr< aspose::words::cloud::models::Border > borderProperties,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_BorderType(borderType),
        m_BorderProperties(borderProperties),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > UpdateBorderRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > UpdateBorderRequest::getBorderType() const
    {
        return m_BorderType;
    }

    const std::shared_ptr< aspose::words::cloud::models::Border > UpdateBorderRequest::getBorderProperties() const
    {
        return m_BorderProperties;
    }

    const std::shared_ptr< std::wstring > UpdateBorderRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > UpdateBorderRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > UpdateBorderRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > UpdateBorderRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateBorderRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateBorderRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateBorderRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateBorderRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateBorderRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/{nodePath}/borders/{borderType}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_BorderType) throw aspose::words::cloud::ApiException(400, L"Parameter 'BorderType' is required.");
        result->setPathParam(L"{borderType}", *m_BorderType);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_BorderProperties) result->setBody(*m_BorderProperties);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'BorderProperties' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateBorderRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateBorderResponse()
        );
    }

    /*
     * UpdateBorderOnline request implementation
     */
    UpdateBorderOnlineRequest::UpdateBorderOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::Border > borderProperties,
        const std::shared_ptr< std::wstring > borderType,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_BorderProperties(borderProperties),
        m_BorderType(borderType),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > UpdateBorderOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::Border > UpdateBorderOnlineRequest::getBorderProperties() const
    {
        return m_BorderProperties;
    }

    const std::shared_ptr< std::wstring > UpdateBorderOnlineRequest::getBorderType() const
    {
        return m_BorderType;
    }

    const std::shared_ptr< std::wstring > UpdateBorderOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > UpdateBorderOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateBorderOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateBorderOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateBorderOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateBorderOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateBorderOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/{nodePath}/borders/{borderType}");
        if (!m_BorderType) throw aspose::words::cloud::ApiException(400, L"Parameter 'BorderType' is required.");
        result->setPathParam(L"{borderType}", *m_BorderType);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_BorderProperties) result->addFormDataParam(L"borderProperties", *m_BorderProperties);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'BorderProperties' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateBorderOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateBorderOnlineResponse()
        );
    }

    /*
     * UpdateComment request implementation
     */
    UpdateCommentRequest::UpdateCommentRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > commentIndex,
        const std::shared_ptr< aspose::words::cloud::models::CommentUpdate > comment,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_CommentIndex(commentIndex),
        m_Comment(comment),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > UpdateCommentRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > UpdateCommentRequest::getCommentIndex() const
    {
        return m_CommentIndex;
    }

    const std::shared_ptr< aspose::words::cloud::models::CommentUpdate > UpdateCommentRequest::getComment() const
    {
        return m_Comment;
    }

    const std::shared_ptr< std::wstring > UpdateCommentRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > UpdateCommentRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > UpdateCommentRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateCommentRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateCommentRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateCommentRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateCommentRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateCommentRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/comments/{commentIndex}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_CommentIndex) throw aspose::words::cloud::ApiException(400, L"Parameter 'CommentIndex' is required.");
        result->setPathParam(L"{commentIndex}", *m_CommentIndex);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Comment) result->setBody(*m_Comment);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Comment' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateCommentRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateCommentResponse()
        );
    }

    /*
     * UpdateCommentOnline request implementation
     */
    UpdateCommentOnlineRequest::UpdateCommentOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > commentIndex,
        const std::shared_ptr< aspose::words::cloud::models::CommentUpdate > comment,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_CommentIndex(commentIndex),
        m_Comment(comment),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > UpdateCommentOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > UpdateCommentOnlineRequest::getCommentIndex() const
    {
        return m_CommentIndex;
    }

    const std::shared_ptr< aspose::words::cloud::models::CommentUpdate > UpdateCommentOnlineRequest::getComment() const
    {
        return m_Comment;
    }

    const std::shared_ptr< std::wstring > UpdateCommentOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateCommentOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateCommentOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateCommentOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateCommentOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateCommentOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/comments/{commentIndex}");
        if (!m_CommentIndex) throw aspose::words::cloud::ApiException(400, L"Parameter 'CommentIndex' is required.");
        result->setPathParam(L"{commentIndex}", *m_CommentIndex);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_Comment) result->addFormDataParam(L"comment", *m_Comment);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Comment' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateCommentOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateCommentOnlineResponse()
        );
    }

    /*
     * UpdateDrawingObject request implementation
     */
    UpdateDrawingObjectRequest::UpdateDrawingObjectRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< aspose::words::cloud::models::DrawingObjectUpdate > drawingObject,
        const std::shared_ptr< std::istream > imageFile,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_DrawingObject(drawingObject),
        m_ImageFile(imageFile),
        m_Index(index),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > UpdateDrawingObjectRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< aspose::words::cloud::models::DrawingObjectUpdate > UpdateDrawingObjectRequest::getDrawingObject() const
    {
        return m_DrawingObject;
    }

    const std::shared_ptr< std::istream > UpdateDrawingObjectRequest::getImageFile() const
    {
        return m_ImageFile;
    }

    const std::shared_ptr< int32_t > UpdateDrawingObjectRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > UpdateDrawingObjectRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > UpdateDrawingObjectRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > UpdateDrawingObjectRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > UpdateDrawingObjectRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateDrawingObjectRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateDrawingObjectRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateDrawingObjectRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateDrawingObjectRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateDrawingObjectRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/{nodePath}/drawingObjects/{index}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_DrawingObject) result->addFormDataParam(L"drawingObject", *m_DrawingObject);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'DrawingObject' is required.");
        if (m_ImageFile) result->addFormDataParam(L"imageFile", *m_ImageFile);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'ImageFile' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateDrawingObjectRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateDrawingObjectResponse()
        );
    }

    /*
     * UpdateDrawingObjectOnline request implementation
     */
    UpdateDrawingObjectOnlineRequest::UpdateDrawingObjectOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::DrawingObjectUpdate > drawingObject,
        const std::shared_ptr< std::istream > imageFile,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_DrawingObject(drawingObject),
        m_ImageFile(imageFile),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > UpdateDrawingObjectOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::DrawingObjectUpdate > UpdateDrawingObjectOnlineRequest::getDrawingObject() const
    {
        return m_DrawingObject;
    }

    const std::shared_ptr< std::istream > UpdateDrawingObjectOnlineRequest::getImageFile() const
    {
        return m_ImageFile;
    }

    const std::shared_ptr< int32_t > UpdateDrawingObjectOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > UpdateDrawingObjectOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > UpdateDrawingObjectOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateDrawingObjectOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateDrawingObjectOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateDrawingObjectOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateDrawingObjectOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateDrawingObjectOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/{nodePath}/drawingObjects/{index}");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_DrawingObject) result->addFormDataParam(L"drawingObject", *m_DrawingObject);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'DrawingObject' is required.");
        if (m_ImageFile) result->addFormDataParam(L"imageFile", *m_ImageFile);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'ImageFile' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateDrawingObjectOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateDrawingObjectOnlineResponse()
        );
    }

    /*
     * UpdateField request implementation
     */
    UpdateFieldRequest::UpdateFieldRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< aspose::words::cloud::models::FieldUpdate > field,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_Index(index),
        m_Field(field),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > UpdateFieldRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > UpdateFieldRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< aspose::words::cloud::models::FieldUpdate > UpdateFieldRequest::getField() const
    {
        return m_Field;
    }

    const std::shared_ptr< std::wstring > UpdateFieldRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > UpdateFieldRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > UpdateFieldRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > UpdateFieldRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateFieldRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateFieldRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateFieldRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateFieldRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateFieldRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/{nodePath}/fields/{index}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Field) result->setBody(*m_Field);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Field' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateFieldRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateFieldResponse()
        );
    }

    /*
     * UpdateFieldOnline request implementation
     */
    UpdateFieldOnlineRequest::UpdateFieldOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::FieldUpdate > field,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_Field(field),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > UpdateFieldOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::FieldUpdate > UpdateFieldOnlineRequest::getField() const
    {
        return m_Field;
    }

    const std::shared_ptr< int32_t > UpdateFieldOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > UpdateFieldOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > UpdateFieldOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateFieldOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateFieldOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateFieldOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateFieldOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateFieldOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/{nodePath}/fields/{index}");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_Field) result->addFormDataParam(L"field", *m_Field);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Field' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateFieldOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateFieldOnlineResponse()
        );
    }

    /*
     * UpdateFields request implementation
     */
    UpdateFieldsRequest::UpdateFieldsRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName
    ) : 
        m_Name(name),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName)
    {
    }

    const std::shared_ptr< std::wstring > UpdateFieldsRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > UpdateFieldsRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > UpdateFieldsRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > UpdateFieldsRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateFieldsRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateFieldsRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateFieldsRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/updateFields");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateFieldsRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateFieldsResponse()
        );
    }

    /*
     * UpdateFieldsOnline request implementation
     */
    UpdateFieldsOnlineRequest::UpdateFieldsOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName
    ) : 
        m_Document(document),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName)
    {
    }

    const std::shared_ptr< std::istream > UpdateFieldsOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > UpdateFieldsOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateFieldsOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateFieldsOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateFieldsOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/updateFields");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_Document) result->setBody(*m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateFieldsOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateFieldsOnlineResponse()
        );
    }

    /*
     * UpdateFootnote request implementation
     */
    UpdateFootnoteRequest::UpdateFootnoteRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< aspose::words::cloud::models::FootnoteUpdate > footnoteDto,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_Index(index),
        m_FootnoteDto(footnoteDto),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > UpdateFootnoteRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > UpdateFootnoteRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< aspose::words::cloud::models::FootnoteUpdate > UpdateFootnoteRequest::getFootnoteDto() const
    {
        return m_FootnoteDto;
    }

    const std::shared_ptr< std::wstring > UpdateFootnoteRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > UpdateFootnoteRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > UpdateFootnoteRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > UpdateFootnoteRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateFootnoteRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateFootnoteRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateFootnoteRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateFootnoteRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateFootnoteRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/{nodePath}/footnotes/{index}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_FootnoteDto) result->setBody(*m_FootnoteDto);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'FootnoteDto' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateFootnoteRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateFootnoteResponse()
        );
    }

    /*
     * UpdateFootnoteOnline request implementation
     */
    UpdateFootnoteOnlineRequest::UpdateFootnoteOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::FootnoteUpdate > footnoteDto,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_FootnoteDto(footnoteDto),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > UpdateFootnoteOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::FootnoteUpdate > UpdateFootnoteOnlineRequest::getFootnoteDto() const
    {
        return m_FootnoteDto;
    }

    const std::shared_ptr< int32_t > UpdateFootnoteOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > UpdateFootnoteOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > UpdateFootnoteOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateFootnoteOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateFootnoteOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateFootnoteOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateFootnoteOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateFootnoteOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/{nodePath}/footnotes/{index}");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_FootnoteDto) result->addFormDataParam(L"footnoteDto", *m_FootnoteDto);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'FootnoteDto' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateFootnoteOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateFootnoteOnlineResponse()
        );
    }

    /*
     * UpdateFormField request implementation
     */
    UpdateFormFieldRequest::UpdateFormFieldRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< aspose::words::cloud::models::FormField > formField,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_Index(index),
        m_FormField(formField),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > UpdateFormFieldRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > UpdateFormFieldRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< aspose::words::cloud::models::FormField > UpdateFormFieldRequest::getFormField() const
    {
        return m_FormField;
    }

    const std::shared_ptr< std::wstring > UpdateFormFieldRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > UpdateFormFieldRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > UpdateFormFieldRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > UpdateFormFieldRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateFormFieldRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateFormFieldRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateFormFieldRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateFormFieldRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateFormFieldRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/{nodePath}/formfields/{index}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_FormField) result->setBody(*m_FormField);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'FormField' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateFormFieldRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateFormFieldResponse()
        );
    }

    /*
     * UpdateFormFieldOnline request implementation
     */
    UpdateFormFieldOnlineRequest::UpdateFormFieldOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::FormField > formField,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_FormField(formField),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > UpdateFormFieldOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::FormField > UpdateFormFieldOnlineRequest::getFormField() const
    {
        return m_FormField;
    }

    const std::shared_ptr< int32_t > UpdateFormFieldOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > UpdateFormFieldOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > UpdateFormFieldOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateFormFieldOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateFormFieldOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateFormFieldOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateFormFieldOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateFormFieldOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/{nodePath}/formfields/{index}");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_FormField) result->addFormDataParam(L"formField", *m_FormField);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'FormField' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateFormFieldOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateFormFieldOnlineResponse()
        );
    }

    /*
     * UpdateList request implementation
     */
    UpdateListRequest::UpdateListRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > listId,
        const std::shared_ptr< aspose::words::cloud::models::ListUpdate > listUpdate,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_ListId(listId),
        m_ListUpdate(listUpdate),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > UpdateListRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > UpdateListRequest::getListId() const
    {
        return m_ListId;
    }

    const std::shared_ptr< aspose::words::cloud::models::ListUpdate > UpdateListRequest::getListUpdate() const
    {
        return m_ListUpdate;
    }

    const std::shared_ptr< std::wstring > UpdateListRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > UpdateListRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > UpdateListRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateListRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateListRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateListRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateListRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateListRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/lists/{listId}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_ListId) throw aspose::words::cloud::ApiException(400, L"Parameter 'ListId' is required.");
        result->setPathParam(L"{listId}", *m_ListId);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_ListUpdate) result->setBody(*m_ListUpdate);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'ListUpdate' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateListRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateListResponse()
        );
    }

    /*
     * UpdateListLevel request implementation
     */
    UpdateListLevelRequest::UpdateListLevelRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > listId,
        const std::shared_ptr< int32_t > listLevel,
        const std::shared_ptr< aspose::words::cloud::models::ListLevelUpdate > listUpdate,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_ListId(listId),
        m_ListLevel(listLevel),
        m_ListUpdate(listUpdate),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > UpdateListLevelRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > UpdateListLevelRequest::getListId() const
    {
        return m_ListId;
    }

    const std::shared_ptr< int32_t > UpdateListLevelRequest::getListLevel() const
    {
        return m_ListLevel;
    }

    const std::shared_ptr< aspose::words::cloud::models::ListLevelUpdate > UpdateListLevelRequest::getListUpdate() const
    {
        return m_ListUpdate;
    }

    const std::shared_ptr< std::wstring > UpdateListLevelRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > UpdateListLevelRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > UpdateListLevelRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateListLevelRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateListLevelRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateListLevelRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateListLevelRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateListLevelRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/lists/{listId}/listLevels/{listLevel}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_ListId) throw aspose::words::cloud::ApiException(400, L"Parameter 'ListId' is required.");
        result->setPathParam(L"{listId}", *m_ListId);
        if (!m_ListLevel) throw aspose::words::cloud::ApiException(400, L"Parameter 'ListLevel' is required.");
        result->setPathParam(L"{listLevel}", *m_ListLevel);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_ListUpdate) result->setBody(*m_ListUpdate);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'ListUpdate' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateListLevelRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateListLevelResponse()
        );
    }

    /*
     * UpdateListLevelOnline request implementation
     */
    UpdateListLevelOnlineRequest::UpdateListLevelOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > listId,
        const std::shared_ptr< aspose::words::cloud::models::ListLevelUpdate > listUpdate,
        const std::shared_ptr< int32_t > listLevel,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_ListId(listId),
        m_ListUpdate(listUpdate),
        m_ListLevel(listLevel),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > UpdateListLevelOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > UpdateListLevelOnlineRequest::getListId() const
    {
        return m_ListId;
    }

    const std::shared_ptr< aspose::words::cloud::models::ListLevelUpdate > UpdateListLevelOnlineRequest::getListUpdate() const
    {
        return m_ListUpdate;
    }

    const std::shared_ptr< int32_t > UpdateListLevelOnlineRequest::getListLevel() const
    {
        return m_ListLevel;
    }

    const std::shared_ptr< std::wstring > UpdateListLevelOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateListLevelOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateListLevelOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateListLevelOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateListLevelOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateListLevelOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/lists/{listId}/listLevels/{listLevel}");
        if (!m_ListId) throw aspose::words::cloud::ApiException(400, L"Parameter 'ListId' is required.");
        result->setPathParam(L"{listId}", *m_ListId);
        if (!m_ListLevel) throw aspose::words::cloud::ApiException(400, L"Parameter 'ListLevel' is required.");
        result->setPathParam(L"{listLevel}", *m_ListLevel);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_ListUpdate) result->addFormDataParam(L"listUpdate", *m_ListUpdate);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'ListUpdate' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateListLevelOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateListLevelOnlineResponse()
        );
    }

    /*
     * UpdateListOnline request implementation
     */
    UpdateListOnlineRequest::UpdateListOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > listId,
        const std::shared_ptr< aspose::words::cloud::models::ListUpdate > listUpdate,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_ListId(listId),
        m_ListUpdate(listUpdate),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > UpdateListOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > UpdateListOnlineRequest::getListId() const
    {
        return m_ListId;
    }

    const std::shared_ptr< aspose::words::cloud::models::ListUpdate > UpdateListOnlineRequest::getListUpdate() const
    {
        return m_ListUpdate;
    }

    const std::shared_ptr< std::wstring > UpdateListOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateListOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateListOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateListOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateListOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateListOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/lists/{listId}");
        if (!m_ListId) throw aspose::words::cloud::ApiException(400, L"Parameter 'ListId' is required.");
        result->setPathParam(L"{listId}", *m_ListId);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_ListUpdate) result->addFormDataParam(L"listUpdate", *m_ListUpdate);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'ListUpdate' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateListOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateListOnlineResponse()
        );
    }

    /*
     * UpdateParagraphFormat request implementation
     */
    UpdateParagraphFormatRequest::UpdateParagraphFormatRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< aspose::words::cloud::models::ParagraphFormatUpdate > paragraphFormatDto,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_Index(index),
        m_ParagraphFormatDto(paragraphFormatDto),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > UpdateParagraphFormatRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > UpdateParagraphFormatRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< aspose::words::cloud::models::ParagraphFormatUpdate > UpdateParagraphFormatRequest::getParagraphFormatDto() const
    {
        return m_ParagraphFormatDto;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphFormatRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphFormatRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphFormatRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphFormatRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphFormatRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphFormatRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphFormatRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphFormatRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateParagraphFormatRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/{nodePath}/paragraphs/{index}/format");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_ParagraphFormatDto) result->setBody(*m_ParagraphFormatDto);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'ParagraphFormatDto' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateParagraphFormatRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateParagraphFormatResponse()
        );
    }

    /*
     * UpdateParagraphFormatOnline request implementation
     */
    UpdateParagraphFormatOnlineRequest::UpdateParagraphFormatOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::ParagraphFormatUpdate > paragraphFormatDto,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_ParagraphFormatDto(paragraphFormatDto),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > UpdateParagraphFormatOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::ParagraphFormatUpdate > UpdateParagraphFormatOnlineRequest::getParagraphFormatDto() const
    {
        return m_ParagraphFormatDto;
    }

    const std::shared_ptr< int32_t > UpdateParagraphFormatOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphFormatOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphFormatOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphFormatOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphFormatOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphFormatOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphFormatOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateParagraphFormatOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/{nodePath}/paragraphs/{index}/format");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_ParagraphFormatDto) result->addFormDataParam(L"paragraphFormatDto", *m_ParagraphFormatDto);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'ParagraphFormatDto' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateParagraphFormatOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateParagraphFormatOnlineResponse()
        );
    }

    /*
     * UpdateParagraphListFormat request implementation
     */
    UpdateParagraphListFormatRequest::UpdateParagraphListFormatRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< aspose::words::cloud::models::ListFormatUpdate > listFormatDto,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_Index(index),
        m_ListFormatDto(listFormatDto),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > UpdateParagraphListFormatRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > UpdateParagraphListFormatRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< aspose::words::cloud::models::ListFormatUpdate > UpdateParagraphListFormatRequest::getListFormatDto() const
    {
        return m_ListFormatDto;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphListFormatRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphListFormatRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphListFormatRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphListFormatRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphListFormatRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphListFormatRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphListFormatRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphListFormatRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateParagraphListFormatRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/{nodePath}/paragraphs/{index}/listFormat");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_ListFormatDto) result->setBody(*m_ListFormatDto);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'ListFormatDto' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateParagraphListFormatRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateParagraphListFormatResponse()
        );
    }

    /*
     * UpdateParagraphListFormatOnline request implementation
     */
    UpdateParagraphListFormatOnlineRequest::UpdateParagraphListFormatOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::ListFormatUpdate > listFormatDto,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_ListFormatDto(listFormatDto),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > UpdateParagraphListFormatOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::ListFormatUpdate > UpdateParagraphListFormatOnlineRequest::getListFormatDto() const
    {
        return m_ListFormatDto;
    }

    const std::shared_ptr< int32_t > UpdateParagraphListFormatOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphListFormatOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphListFormatOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphListFormatOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphListFormatOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphListFormatOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateParagraphListFormatOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateParagraphListFormatOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/{nodePath}/paragraphs/{index}/listFormat");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_ListFormatDto) result->addFormDataParam(L"listFormatDto", *m_ListFormatDto);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'ListFormatDto' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateParagraphListFormatOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateParagraphListFormatOnlineResponse()
        );
    }

    /*
     * UpdateRun request implementation
     */
    UpdateRunRequest::UpdateRunRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > paragraphPath,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< aspose::words::cloud::models::RunUpdate > run,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_ParagraphPath(paragraphPath),
        m_Index(index),
        m_Run(run),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > UpdateRunRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > UpdateRunRequest::getParagraphPath() const
    {
        return m_ParagraphPath;
    }

    const std::shared_ptr< int32_t > UpdateRunRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< aspose::words::cloud::models::RunUpdate > UpdateRunRequest::getRun() const
    {
        return m_Run;
    }

    const std::shared_ptr< std::wstring > UpdateRunRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > UpdateRunRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > UpdateRunRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateRunRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateRunRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateRunRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateRunRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateRunRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/{paragraphPath}/runs/{index}");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_ParagraphPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'ParagraphPath' is required.");
        result->setPathParam(L"{paragraphPath}", *m_ParagraphPath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Run) result->setBody(*m_Run);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Run' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateRunRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateRunResponse()
        );
    }

    /*
     * UpdateRunFont request implementation
     */
    UpdateRunFontRequest::UpdateRunFontRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > paragraphPath,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< aspose::words::cloud::models::Font > fontDto,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_ParagraphPath(paragraphPath),
        m_Index(index),
        m_FontDto(fontDto),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > UpdateRunFontRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > UpdateRunFontRequest::getParagraphPath() const
    {
        return m_ParagraphPath;
    }

    const std::shared_ptr< int32_t > UpdateRunFontRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< aspose::words::cloud::models::Font > UpdateRunFontRequest::getFontDto() const
    {
        return m_FontDto;
    }

    const std::shared_ptr< std::wstring > UpdateRunFontRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > UpdateRunFontRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > UpdateRunFontRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateRunFontRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateRunFontRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateRunFontRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateRunFontRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateRunFontRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/{paragraphPath}/runs/{index}/font");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_ParagraphPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'ParagraphPath' is required.");
        result->setPathParam(L"{paragraphPath}", *m_ParagraphPath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_FontDto) result->setBody(*m_FontDto);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'FontDto' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateRunFontRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateRunFontResponse()
        );
    }

    /*
     * UpdateRunFontOnline request implementation
     */
    UpdateRunFontOnlineRequest::UpdateRunFontOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > paragraphPath,
        const std::shared_ptr< aspose::words::cloud::models::Font > fontDto,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_ParagraphPath(paragraphPath),
        m_FontDto(fontDto),
        m_Index(index),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > UpdateRunFontOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > UpdateRunFontOnlineRequest::getParagraphPath() const
    {
        return m_ParagraphPath;
    }

    const std::shared_ptr< aspose::words::cloud::models::Font > UpdateRunFontOnlineRequest::getFontDto() const
    {
        return m_FontDto;
    }

    const std::shared_ptr< int32_t > UpdateRunFontOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > UpdateRunFontOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateRunFontOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateRunFontOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateRunFontOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateRunFontOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateRunFontOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/{paragraphPath}/runs/{index}/font");
        if (!m_ParagraphPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'ParagraphPath' is required.");
        result->setPathParam(L"{paragraphPath}", *m_ParagraphPath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_FontDto) result->addFormDataParam(L"fontDto", *m_FontDto);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'FontDto' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateRunFontOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateRunFontOnlineResponse()
        );
    }

    /*
     * UpdateRunOnline request implementation
     */
    UpdateRunOnlineRequest::UpdateRunOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > paragraphPath,
        const std::shared_ptr< aspose::words::cloud::models::RunUpdate > run,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_ParagraphPath(paragraphPath),
        m_Run(run),
        m_Index(index),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > UpdateRunOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > UpdateRunOnlineRequest::getParagraphPath() const
    {
        return m_ParagraphPath;
    }

    const std::shared_ptr< aspose::words::cloud::models::RunUpdate > UpdateRunOnlineRequest::getRun() const
    {
        return m_Run;
    }

    const std::shared_ptr< int32_t > UpdateRunOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > UpdateRunOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateRunOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateRunOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateRunOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateRunOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateRunOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/{paragraphPath}/runs/{index}");
        if (!m_ParagraphPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'ParagraphPath' is required.");
        result->setPathParam(L"{paragraphPath}", *m_ParagraphPath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_Run) result->addFormDataParam(L"run", *m_Run);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Run' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateRunOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateRunOnlineResponse()
        );
    }

    /*
     * UpdateSectionPageSetup request implementation
     */
    UpdateSectionPageSetupRequest::UpdateSectionPageSetupRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > sectionIndex,
        const std::shared_ptr< aspose::words::cloud::models::PageSetup > pageSetup,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_SectionIndex(sectionIndex),
        m_PageSetup(pageSetup),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > UpdateSectionPageSetupRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > UpdateSectionPageSetupRequest::getSectionIndex() const
    {
        return m_SectionIndex;
    }

    const std::shared_ptr< aspose::words::cloud::models::PageSetup > UpdateSectionPageSetupRequest::getPageSetup() const
    {
        return m_PageSetup;
    }

    const std::shared_ptr< std::wstring > UpdateSectionPageSetupRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > UpdateSectionPageSetupRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > UpdateSectionPageSetupRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateSectionPageSetupRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateSectionPageSetupRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateSectionPageSetupRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateSectionPageSetupRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateSectionPageSetupRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/sections/{sectionIndex}/pageSetup");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_SectionIndex) throw aspose::words::cloud::ApiException(400, L"Parameter 'SectionIndex' is required.");
        result->setPathParam(L"{sectionIndex}", *m_SectionIndex);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_PageSetup) result->setBody(*m_PageSetup);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'PageSetup' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateSectionPageSetupRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateSectionPageSetupResponse()
        );
    }

    /*
     * UpdateSectionPageSetupOnline request implementation
     */
    UpdateSectionPageSetupOnlineRequest::UpdateSectionPageSetupOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< int32_t > sectionIndex,
        const std::shared_ptr< aspose::words::cloud::models::PageSetup > pageSetup,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_SectionIndex(sectionIndex),
        m_PageSetup(pageSetup),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > UpdateSectionPageSetupOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< int32_t > UpdateSectionPageSetupOnlineRequest::getSectionIndex() const
    {
        return m_SectionIndex;
    }

    const std::shared_ptr< aspose::words::cloud::models::PageSetup > UpdateSectionPageSetupOnlineRequest::getPageSetup() const
    {
        return m_PageSetup;
    }

    const std::shared_ptr< std::wstring > UpdateSectionPageSetupOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateSectionPageSetupOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateSectionPageSetupOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateSectionPageSetupOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateSectionPageSetupOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateSectionPageSetupOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/sections/{sectionIndex}/pageSetup");
        if (!m_SectionIndex) throw aspose::words::cloud::ApiException(400, L"Parameter 'SectionIndex' is required.");
        result->setPathParam(L"{sectionIndex}", *m_SectionIndex);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_PageSetup) result->addFormDataParam(L"pageSetup", *m_PageSetup);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'PageSetup' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateSectionPageSetupOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateSectionPageSetupOnlineResponse()
        );
    }

    /*
     * UpdateStyle request implementation
     */
    UpdateStyleRequest::UpdateStyleRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > styleName,
        const std::shared_ptr< aspose::words::cloud::models::StyleUpdate > styleUpdate,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_StyleName(styleName),
        m_StyleUpdate(styleUpdate),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > UpdateStyleRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > UpdateStyleRequest::getStyleName() const
    {
        return m_StyleName;
    }

    const std::shared_ptr< aspose::words::cloud::models::StyleUpdate > UpdateStyleRequest::getStyleUpdate() const
    {
        return m_StyleUpdate;
    }

    const std::shared_ptr< std::wstring > UpdateStyleRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > UpdateStyleRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > UpdateStyleRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateStyleRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateStyleRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateStyleRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateStyleRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateStyleRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/styles/{styleName}/update");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_StyleName) throw aspose::words::cloud::ApiException(400, L"Parameter 'StyleName' is required.");
        result->setPathParam(L"{styleName}", *m_StyleName);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_StyleUpdate) result->setBody(*m_StyleUpdate);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'StyleUpdate' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateStyleRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateStyleResponse()
        );
    }

    /*
     * UpdateStyleOnline request implementation
     */
    UpdateStyleOnlineRequest::UpdateStyleOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > styleName,
        const std::shared_ptr< aspose::words::cloud::models::StyleUpdate > styleUpdate,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_StyleName(styleName),
        m_StyleUpdate(styleUpdate),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > UpdateStyleOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > UpdateStyleOnlineRequest::getStyleName() const
    {
        return m_StyleName;
    }

    const std::shared_ptr< aspose::words::cloud::models::StyleUpdate > UpdateStyleOnlineRequest::getStyleUpdate() const
    {
        return m_StyleUpdate;
    }

    const std::shared_ptr< std::wstring > UpdateStyleOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateStyleOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateStyleOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateStyleOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateStyleOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateStyleOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/styles/{styleName}/update");
        if (!m_StyleName) throw aspose::words::cloud::ApiException(400, L"Parameter 'StyleName' is required.");
        result->setPathParam(L"{styleName}", *m_StyleName);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_StyleUpdate) result->addFormDataParam(L"styleUpdate", *m_StyleUpdate);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'StyleUpdate' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateStyleOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateStyleOnlineResponse()
        );
    }

    /*
     * UpdateTableCellFormat request implementation
     */
    UpdateTableCellFormatRequest::UpdateTableCellFormatRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > tableRowPath,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< aspose::words::cloud::models::TableCellFormat > format,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_TableRowPath(tableRowPath),
        m_Index(index),
        m_Format(format),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > UpdateTableCellFormatRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > UpdateTableCellFormatRequest::getTableRowPath() const
    {
        return m_TableRowPath;
    }

    const std::shared_ptr< int32_t > UpdateTableCellFormatRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< aspose::words::cloud::models::TableCellFormat > UpdateTableCellFormatRequest::getFormat() const
    {
        return m_Format;
    }

    const std::shared_ptr< std::wstring > UpdateTableCellFormatRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > UpdateTableCellFormatRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > UpdateTableCellFormatRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateTableCellFormatRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateTableCellFormatRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateTableCellFormatRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateTableCellFormatRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateTableCellFormatRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/{tableRowPath}/cells/{index}/cellformat");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_TableRowPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'TableRowPath' is required.");
        result->setPathParam(L"{tableRowPath}", *m_TableRowPath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Format) result->setBody(*m_Format);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Format' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateTableCellFormatRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateTableCellFormatResponse()
        );
    }

    /*
     * UpdateTableCellFormatOnline request implementation
     */
    UpdateTableCellFormatOnlineRequest::UpdateTableCellFormatOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > tableRowPath,
        const std::shared_ptr< aspose::words::cloud::models::TableCellFormat > format,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_TableRowPath(tableRowPath),
        m_Format(format),
        m_Index(index),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > UpdateTableCellFormatOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > UpdateTableCellFormatOnlineRequest::getTableRowPath() const
    {
        return m_TableRowPath;
    }

    const std::shared_ptr< aspose::words::cloud::models::TableCellFormat > UpdateTableCellFormatOnlineRequest::getFormat() const
    {
        return m_Format;
    }

    const std::shared_ptr< int32_t > UpdateTableCellFormatOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > UpdateTableCellFormatOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateTableCellFormatOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateTableCellFormatOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateTableCellFormatOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateTableCellFormatOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateTableCellFormatOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/{tableRowPath}/cells/{index}/cellformat");
        if (!m_TableRowPath) throw aspose::words::cloud::ApiException(400, L"Parameter 'TableRowPath' is required.");
        result->setPathParam(L"{tableRowPath}", *m_TableRowPath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_Format) result->addFormDataParam(L"format", *m_Format);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Format' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateTableCellFormatOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateTableCellFormatOnlineResponse()
        );
    }

    /*
     * UpdateTableProperties request implementation
     */
    UpdateTablePropertiesRequest::UpdateTablePropertiesRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< aspose::words::cloud::models::TableProperties > properties,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_Index(index),
        m_Properties(properties),
        m_NodePath(nodePath),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > UpdateTablePropertiesRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< int32_t > UpdateTablePropertiesRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< aspose::words::cloud::models::TableProperties > UpdateTablePropertiesRequest::getProperties() const
    {
        return m_Properties;
    }

    const std::shared_ptr< std::wstring > UpdateTablePropertiesRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > UpdateTablePropertiesRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > UpdateTablePropertiesRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > UpdateTablePropertiesRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateTablePropertiesRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateTablePropertiesRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateTablePropertiesRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateTablePropertiesRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateTablePropertiesRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/{nodePath}/tables/{index}/properties");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Properties) result->setBody(*m_Properties);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Properties' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateTablePropertiesRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateTablePropertiesResponse()
        );
    }

    /*
     * UpdateTablePropertiesOnline request implementation
     */
    UpdateTablePropertiesOnlineRequest::UpdateTablePropertiesOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< aspose::words::cloud::models::TableProperties > properties,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > nodePath,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_Properties(properties),
        m_Index(index),
        m_NodePath(nodePath),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > UpdateTablePropertiesOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< aspose::words::cloud::models::TableProperties > UpdateTablePropertiesOnlineRequest::getProperties() const
    {
        return m_Properties;
    }

    const std::shared_ptr< int32_t > UpdateTablePropertiesOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > UpdateTablePropertiesOnlineRequest::getNodePath() const
    {
        return m_NodePath;
    }

    const std::shared_ptr< std::wstring > UpdateTablePropertiesOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateTablePropertiesOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateTablePropertiesOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateTablePropertiesOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateTablePropertiesOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateTablePropertiesOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/{nodePath}/tables/{index}/properties");
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        result->setPathParam(L"{nodePath}", m_NodePath ? *m_NodePath : L"");
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_Properties) result->addFormDataParam(L"properties", *m_Properties);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Properties' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateTablePropertiesOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateTablePropertiesOnlineResponse()
        );
    }

    /*
     * UpdateTableRowFormat request implementation
     */
    UpdateTableRowFormatRequest::UpdateTableRowFormatRequest(
        const std::shared_ptr< std::wstring > name,
        const std::shared_ptr< std::wstring > tablePath,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< aspose::words::cloud::models::TableRowFormat > format,
        const std::shared_ptr< std::wstring > folder,
        const std::shared_ptr< std::wstring > storage,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Name(name),
        m_TablePath(tablePath),
        m_Index(index),
        m_Format(format),
        m_Folder(folder),
        m_Storage(storage),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::wstring > UpdateTableRowFormatRequest::getName() const
    {
        return m_Name;
    }

    const std::shared_ptr< std::wstring > UpdateTableRowFormatRequest::getTablePath() const
    {
        return m_TablePath;
    }

    const std::shared_ptr< int32_t > UpdateTableRowFormatRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< aspose::words::cloud::models::TableRowFormat > UpdateTableRowFormatRequest::getFormat() const
    {
        return m_Format;
    }

    const std::shared_ptr< std::wstring > UpdateTableRowFormatRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::shared_ptr< std::wstring > UpdateTableRowFormatRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::shared_ptr< std::wstring > UpdateTableRowFormatRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateTableRowFormatRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateTableRowFormatRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateTableRowFormatRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateTableRowFormatRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateTableRowFormatRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/{name}/{tablePath}/rows/{index}/rowformat");
        if (!m_Name) throw aspose::words::cloud::ApiException(400, L"Parameter 'Name' is required.");
        result->setPathParam(L"{name}", *m_Name);
        if (!m_TablePath) throw aspose::words::cloud::ApiException(400, L"Parameter 'TablePath' is required.");
        result->setPathParam(L"{tablePath}", *m_TablePath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_Folder) result->addQueryParam(L"folder", *m_Folder);
        if (m_Storage) result->addQueryParam(L"storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Format) result->setBody(*m_Format);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Format' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateTableRowFormatRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateTableRowFormatResponse()
        );
    }

    /*
     * UpdateTableRowFormatOnline request implementation
     */
    UpdateTableRowFormatOnlineRequest::UpdateTableRowFormatOnlineRequest(
        const std::shared_ptr< std::istream > document,
        const std::shared_ptr< std::wstring > tablePath,
        const std::shared_ptr< aspose::words::cloud::models::TableRowFormat > format,
        const std::shared_ptr< int32_t > index,
        const std::shared_ptr< std::wstring > loadEncoding,
        const std::shared_ptr< std::wstring > password,
        const std::shared_ptr< std::wstring > destFileName,
        const std::shared_ptr< std::wstring > revisionAuthor,
        const std::shared_ptr< std::wstring > revisionDateTime
    ) : 
        m_Document(document),
        m_TablePath(tablePath),
        m_Format(format),
        m_Index(index),
        m_LoadEncoding(loadEncoding),
        m_Password(password),
        m_DestFileName(destFileName),
        m_RevisionAuthor(revisionAuthor),
        m_RevisionDateTime(revisionDateTime)
    {
    }

    const std::shared_ptr< std::istream > UpdateTableRowFormatOnlineRequest::getDocument() const
    {
        return m_Document;
    }

    const std::shared_ptr< std::wstring > UpdateTableRowFormatOnlineRequest::getTablePath() const
    {
        return m_TablePath;
    }

    const std::shared_ptr< aspose::words::cloud::models::TableRowFormat > UpdateTableRowFormatOnlineRequest::getFormat() const
    {
        return m_Format;
    }

    const std::shared_ptr< int32_t > UpdateTableRowFormatOnlineRequest::getIndex() const
    {
        return m_Index;
    }

    const std::shared_ptr< std::wstring > UpdateTableRowFormatOnlineRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::shared_ptr< std::wstring > UpdateTableRowFormatOnlineRequest::getPassword() const
    {
        return m_Password;
    }

    const std::shared_ptr< std::wstring > UpdateTableRowFormatOnlineRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    const std::shared_ptr< std::wstring > UpdateTableRowFormatOnlineRequest::getRevisionAuthor() const
    {
        return m_RevisionAuthor;
    }

    const std::shared_ptr< std::wstring > UpdateTableRowFormatOnlineRequest::getRevisionDateTime() const
    {
        return m_RevisionDateTime;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UpdateTableRowFormatOnlineRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/online/put/{tablePath}/rows/{index}/rowformat");
        if (!m_TablePath) throw aspose::words::cloud::ApiException(400, L"Parameter 'TablePath' is required.");
        result->setPathParam(L"{tablePath}", *m_TablePath);
        if (!m_Index) throw aspose::words::cloud::ApiException(400, L"Parameter 'Index' is required.");
        result->setPathParam(L"{index}", *m_Index);
        if (m_LoadEncoding) result->addQueryParam(L"loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam(L"password", *m_Password);
        if (m_DestFileName) result->addQueryParam(L"destFileName", *m_DestFileName);
        if (m_RevisionAuthor) result->addQueryParam(L"revisionAuthor", *m_RevisionAuthor);
        if (m_RevisionDateTime) result->addQueryParam(L"revisionDateTime", *m_RevisionDateTime);
        if (m_Document) result->addFormDataParam(L"document", *m_Document);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Document' is required.");
        if (m_Format) result->addFormDataParam(L"format", *m_Format);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'Format' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UpdateTableRowFormatOnlineRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UpdateTableRowFormatOnlineResponse()
        );
    }

    /*
     * UploadFile request implementation
     */
    UploadFileRequest::UploadFileRequest(
        const std::shared_ptr< std::istream > fileContent,
        const std::shared_ptr< std::wstring > path,
        const std::shared_ptr< std::wstring > storageName
    ) : 
        m_FileContent(fileContent),
        m_Path(path),
        m_StorageName(storageName)
    {
    }

    const std::shared_ptr< std::istream > UploadFileRequest::getFileContent() const
    {
        return m_FileContent;
    }

    const std::shared_ptr< std::wstring > UploadFileRequest::getPath() const
    {
        return m_Path;
    }

    const std::shared_ptr< std::wstring > UploadFileRequest::getStorageName() const
    {
        return m_StorageName;
    }

    std::shared_ptr< aspose::words::cloud::HttpRequestData > UploadFileRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod(HttpRequestMethod::HttpPUT);
        result->setPath(L"/words/storage/file/{path}");
        if (!m_Path) throw aspose::words::cloud::ApiException(400, L"Parameter 'Path' is required.");
        result->setPathParam(L"{path}", *m_Path);
        if (m_StorageName) result->addQueryParam(L"storageName", *m_StorageName);
        if (m_FileContent) result->setBody(*m_FileContent);
        else throw aspose::words::cloud::ApiException(400, L"Parameter 'FileContent' is required.");
        return result;
    }

    std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > UploadFileRequest::createResponse() const
    {
        return std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase >(
            new aspose::words::cloud::responses::UploadFileResponse()
        );
    }
}