﻿/** --------------------------------------------------------------------------------------------------------------------
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
#include <unordered_map>
#include <vector>
#include <string_view>
#include <charconv>
#include "aspose_words_cloud.h"

// USE THIRD PARTY LIBS ONLY IN CPP FILES!!!
#include "../thirdparty/json.hpp"
#include "../thirdparty/utf8.h"

namespace aspose::words::cloud::responses {
    void parseMultipart(const std::string_view& data, std::vector<std::string_view>& result) {
        auto boundaryIndex = data.find("\r\n");
        if (boundaryIndex == std::string_view::npos)
            throw ApiException(400, L"Failed to parse multipart data.");

        auto boundary = data.substr(0, boundaryIndex);
        while (true) {
            auto lastBoundaryIndex = boundaryIndex;
            boundaryIndex = data.find(boundary, boundaryIndex + 2);
            if (boundaryIndex == std::string_view::npos)
                break;

            auto part = data.substr(lastBoundaryIndex + 2, boundaryIndex - lastBoundaryIndex - 4);
            result.push_back(part);
            boundaryIndex = boundaryIndex + boundary.size();
        }
    }

    void parseMultipart(const std::string_view& data, std::unordered_map<std::string, std::string_view>& result) {
        std::vector<std::string_view> parts;
        parseMultipart(data, parts);
        for (auto& part : parts) {
            auto bodyIndex = part.find("\r\n\r\n");
            if (bodyIndex == std::string_view::npos)
                throw ApiException(400, L"Failed to parse multipart data.");

            auto headersData = part.substr(0, bodyIndex + 2);
            auto bodyData = part.substr(bodyIndex + 4);

            size_t headerIndex = 0;
            while (true) {
                auto headerLastIndex = headerIndex;
                headerIndex = headersData.find("\r\n", headerIndex);
                if (headerIndex == std::string_view::npos)
                    throw ApiException(400, L"Failed to parse multipart data.");

                auto header = headersData.substr(headerLastIndex, headerIndex - headerLastIndex);
                auto headerDelimilter = header.find(":");
                if (headerDelimilter == std::string_view::npos)
                    throw ApiException(400, L"Failed to parse multipart data.");

                auto headerName = header.substr(0, headerDelimilter);
                if (headerName == "Content-Disposition") {
                    auto headerValue = header.substr(headerDelimilter + 1);
                    auto partNameIndex = headerValue.find("name=");
                    if (partNameIndex == std::string_view::npos)
                        throw ApiException(400, L"Failed to parse multipart data.");

                    auto partName = headerValue.substr(partNameIndex + 5, headerValue.find(";", partNameIndex + 5));
                    result.emplace(partName, bodyData);
                    break;
                }

                headerIndex = headerIndex + 2;
            }
        }
    }

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

    void BatchResponse::initialize(const std::vector<aspose::words::cloud::requests::BatchRequest>& requests)
    {
        m_Result = std::make_shared< std::vector< std::shared_ptr< ResponseModelBase > > >();
        m_Result->reserve(requests.size());

        for (auto& request : requests) {
            m_Result->push_back(request.get()->createResponse());
        }
    }

    void BatchResponse::deserialize(const std::string_view& response)
    {
        std::vector<std::string_view> parts;
        parseMultipart(response, parts);
        for (size_t i = 0; i < parts.size(); i++) {
            auto& part = parts.at(i);
            auto& result = m_Result->at(i);
            auto bodyIndex = part.find("\r\n\r\n");
            if (bodyIndex == std::string::npos)
                throw aspose::words::cloud::ApiException(400, L"Failed to parse batch response");

            auto bodyData = part.substr(bodyIndex + 4);
            auto contentIndex = bodyData.find("\r\n\r\n");
            if (contentIndex == std::string::npos)
                throw aspose::words::cloud::ApiException(400, L"Failed to parse batch response");

            int statusCode;
            auto headersData = bodyData.substr(0, contentIndex);
            auto statusCodeIndex = headersData.find(" ");
            if (statusCodeIndex == std::string::npos)
                throw aspose::words::cloud::ApiException(400, L"Failed to parse batch response");
            auto statusCodeStr = headersData.substr(0, statusCodeIndex);
            if (std::from_chars(statusCodeStr.data(), statusCodeStr.data() + statusCodeStr.size(), statusCode).ec == std::errc::invalid_argument)
                throw aspose::words::cloud::ApiException(400, L"Failed to parse batch response");

            auto contentData = bodyData.substr(contentIndex + 4);
            result->setStatusCode(statusCode);
            if (statusCode == 200) {
                result->deserialize(contentData);
            }
            else {
                std::wstring errorMessage;
                ::utf8::utf8to16(contentData.begin(), contentData.end(), back_inserter(errorMessage));
                result->setErrorMessage(errorMessage);
            }
        }
    }

    /*
     * AcceptAllRevisions request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::RevisionsModificationResponse > AcceptAllRevisionsResponse::getResult() const
    {
        return m_Result;
    }

    void AcceptAllRevisionsResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::RevisionsModificationResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void AcceptAllRevisionsOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::RevisionsModificationResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * AppendDocument request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > AppendDocumentResponse::getResult() const
    {
        return m_Result;
    }

    void AppendDocumentResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void AppendDocumentOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * ApplyStyleToDocumentElement request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::WordsResponse > ApplyStyleToDocumentElementResponse::getResult() const
    {
        return m_Result;
    }

    void ApplyStyleToDocumentElementResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::WordsResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void ApplyStyleToDocumentElementOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::WordsResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * BuildReport request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > BuildReportResponse::getResult() const
    {
        return m_Result;
    }

    void BuildReportResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * BuildReportOnline request implementation
     */
    std::shared_ptr< std::istream > BuildReportOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void BuildReportOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Result = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * Classify request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ClassificationResponse > ClassifyResponse::getResult() const
    {
        return m_Result;
    }

    void ClassifyResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ClassificationResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * ClassifyDocument request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ClassificationResponse > ClassifyDocumentResponse::getResult() const
    {
        return m_Result;
    }

    void ClassifyDocumentResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ClassificationResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * ClassifyDocumentOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ClassificationResponse > ClassifyDocumentOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void ClassifyDocumentOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ClassificationResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * CompareDocument request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > CompareDocumentResponse::getResult() const
    {
        return m_Result;
    }

    void CompareDocumentResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void CompareDocumentOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * ConvertDocument request implementation
     */
    std::shared_ptr< std::istream > ConvertDocumentResponse::getResult() const
    {
        return m_Result;
    }

    void ConvertDocumentResponse::deserialize(const std::string_view& response)
    {
        m_Result = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * CopyFile request implementation
     */

    void CopyFileResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * CopyFolder request implementation
     */

    void CopyFolderResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * CopyStyle request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::StyleResponse > CopyStyleResponse::getResult() const
    {
        return m_Result;
    }

    void CopyStyleResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::StyleResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void CopyStyleOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::StyleResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * CreateDocument request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > CreateDocumentResponse::getResult() const
    {
        return m_Result;
    }

    void CreateDocumentResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * CreateFolder request implementation
     */

    void CreateFolderResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * CreateOrUpdateDocumentProperty request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentPropertyResponse > CreateOrUpdateDocumentPropertyResponse::getResult() const
    {
        return m_Result;
    }

    void CreateOrUpdateDocumentPropertyResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentPropertyResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void CreateOrUpdateDocumentPropertyOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::DocumentPropertyResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * DeleteAllParagraphTabStops request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TabStopsResponse > DeleteAllParagraphTabStopsResponse::getResult() const
    {
        return m_Result;
    }

    void DeleteAllParagraphTabStopsResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TabStopsResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void DeleteAllParagraphTabStopsOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::TabStopsResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * DeleteBorder request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BorderResponse > DeleteBorderResponse::getResult() const
    {
        return m_Result;
    }

    void DeleteBorderResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::BorderResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void DeleteBorderOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::BorderResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * DeleteBorders request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BordersResponse > DeleteBordersResponse::getResult() const
    {
        return m_Result;
    }

    void DeleteBordersResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::BordersResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void DeleteBordersOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::BordersResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * DeleteComment request implementation
     */

    void DeleteCommentResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * DeleteCommentOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteCommentOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteCommentOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * DeleteComments request implementation
     */

    void DeleteCommentsResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * DeleteCommentsOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteCommentsOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteCommentsOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * DeleteDocumentProperty request implementation
     */

    void DeleteDocumentPropertyResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * DeleteDocumentPropertyOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteDocumentPropertyOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteDocumentPropertyOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * DeleteDrawingObject request implementation
     */

    void DeleteDrawingObjectResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * DeleteDrawingObjectOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteDrawingObjectOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteDrawingObjectOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * DeleteField request implementation
     */

    void DeleteFieldResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * DeleteFieldOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteFieldOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteFieldOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * DeleteFields request implementation
     */

    void DeleteFieldsResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * DeleteFieldsOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteFieldsOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteFieldsOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * DeleteFile request implementation
     */

    void DeleteFileResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * DeleteFolder request implementation
     */

    void DeleteFolderResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * DeleteFootnote request implementation
     */

    void DeleteFootnoteResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * DeleteFootnoteOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteFootnoteOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteFootnoteOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * DeleteFormField request implementation
     */

    void DeleteFormFieldResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * DeleteFormFieldOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteFormFieldOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteFormFieldOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * DeleteHeaderFooter request implementation
     */

    void DeleteHeaderFooterResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * DeleteHeaderFooterOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteHeaderFooterOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteHeaderFooterOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * DeleteHeadersFooters request implementation
     */

    void DeleteHeadersFootersResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * DeleteHeadersFootersOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteHeadersFootersOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteHeadersFootersOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * DeleteMacros request implementation
     */

    void DeleteMacrosResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * DeleteMacrosOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteMacrosOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteMacrosOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * DeleteOfficeMathObject request implementation
     */

    void DeleteOfficeMathObjectResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * DeleteOfficeMathObjectOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteOfficeMathObjectOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteOfficeMathObjectOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * DeleteParagraph request implementation
     */

    void DeleteParagraphResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * DeleteParagraphListFormat request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphListFormatResponse > DeleteParagraphListFormatResponse::getResult() const
    {
        return m_Result;
    }

    void DeleteParagraphListFormatResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ParagraphListFormatResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void DeleteParagraphListFormatOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::ParagraphListFormatResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * DeleteParagraphOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteParagraphOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteParagraphOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * DeleteParagraphTabStop request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TabStopsResponse > DeleteParagraphTabStopResponse::getResult() const
    {
        return m_Result;
    }

    void DeleteParagraphTabStopResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TabStopsResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void DeleteParagraphTabStopOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::TabStopsResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * DeleteRun request implementation
     */

    void DeleteRunResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * DeleteRunOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteRunOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteRunOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * DeleteSection request implementation
     */

    void DeleteSectionResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * DeleteSectionOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteSectionOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteSectionOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * DeleteTable request implementation
     */

    void DeleteTableResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * DeleteTableCell request implementation
     */

    void DeleteTableCellResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * DeleteTableCellOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteTableCellOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteTableCellOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * DeleteTableOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteTableOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteTableOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * DeleteTableRow request implementation
     */

    void DeleteTableRowResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * DeleteTableRowOnline request implementation
     */
    std::shared_ptr< std::istream > DeleteTableRowOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void DeleteTableRowOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * DeleteWatermark request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > DeleteWatermarkResponse::getResult() const
    {
        return m_Result;
    }

    void DeleteWatermarkResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void DeleteWatermarkOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * DownloadFile request implementation
     */
    std::shared_ptr< std::istream > DownloadFileResponse::getResult() const
    {
        return m_Result;
    }

    void DownloadFileResponse::deserialize(const std::string_view& response)
    {
        m_Result = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * ExecuteMailMerge request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > ExecuteMailMergeResponse::getResult() const
    {
        return m_Result;
    }

    void ExecuteMailMergeResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * ExecuteMailMergeOnline request implementation
     */
    std::shared_ptr< std::istream > ExecuteMailMergeOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void ExecuteMailMergeOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Result = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * GetAvailableFonts request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::AvailableFontsResponse > GetAvailableFontsResponse::getResult() const
    {
        return m_Result;
    }

    void GetAvailableFontsResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::AvailableFontsResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetBookmarkByName request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BookmarkResponse > GetBookmarkByNameResponse::getResult() const
    {
        return m_Result;
    }

    void GetBookmarkByNameResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::BookmarkResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetBookmarkByNameOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BookmarkResponse > GetBookmarkByNameOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetBookmarkByNameOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::BookmarkResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetBookmarks request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BookmarksResponse > GetBookmarksResponse::getResult() const
    {
        return m_Result;
    }

    void GetBookmarksResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::BookmarksResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetBookmarksOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BookmarksResponse > GetBookmarksOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetBookmarksOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::BookmarksResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetBorder request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BorderResponse > GetBorderResponse::getResult() const
    {
        return m_Result;
    }

    void GetBorderResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::BorderResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetBorderOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BorderResponse > GetBorderOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetBorderOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::BorderResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetBorders request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BordersResponse > GetBordersResponse::getResult() const
    {
        return m_Result;
    }

    void GetBordersResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::BordersResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetBordersOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BordersResponse > GetBordersOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetBordersOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::BordersResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetComment request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::CommentResponse > GetCommentResponse::getResult() const
    {
        return m_Result;
    }

    void GetCommentResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::CommentResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetCommentOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::CommentResponse > GetCommentOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetCommentOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::CommentResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetComments request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::CommentsResponse > GetCommentsResponse::getResult() const
    {
        return m_Result;
    }

    void GetCommentsResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::CommentsResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetCommentsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::CommentsResponse > GetCommentsOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetCommentsOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::CommentsResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetDocument request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > GetDocumentResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetDocumentDrawingObjectByIndex request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DrawingObjectResponse > GetDocumentDrawingObjectByIndexResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentDrawingObjectByIndexResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DrawingObjectResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetDocumentDrawingObjectByIndexOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DrawingObjectResponse > GetDocumentDrawingObjectByIndexOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentDrawingObjectByIndexOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DrawingObjectResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetDocumentDrawingObjectImageData request implementation
     */
    std::shared_ptr< std::istream > GetDocumentDrawingObjectImageDataResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentDrawingObjectImageDataResponse::deserialize(const std::string_view& response)
    {
        m_Result = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * GetDocumentDrawingObjectImageDataOnline request implementation
     */
    std::shared_ptr< std::istream > GetDocumentDrawingObjectImageDataOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentDrawingObjectImageDataOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Result = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * GetDocumentDrawingObjectOleData request implementation
     */
    std::shared_ptr< std::istream > GetDocumentDrawingObjectOleDataResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentDrawingObjectOleDataResponse::deserialize(const std::string_view& response)
    {
        m_Result = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * GetDocumentDrawingObjectOleDataOnline request implementation
     */
    std::shared_ptr< std::istream > GetDocumentDrawingObjectOleDataOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentDrawingObjectOleDataOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Result = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * GetDocumentDrawingObjects request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DrawingObjectsResponse > GetDocumentDrawingObjectsResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentDrawingObjectsResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DrawingObjectsResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetDocumentDrawingObjectsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DrawingObjectsResponse > GetDocumentDrawingObjectsOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentDrawingObjectsOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DrawingObjectsResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetDocumentFieldNames request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FieldNamesResponse > GetDocumentFieldNamesResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentFieldNamesResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FieldNamesResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetDocumentFieldNamesOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FieldNamesResponse > GetDocumentFieldNamesOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentFieldNamesOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FieldNamesResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetDocumentHyperlinkByIndex request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::HyperlinkResponse > GetDocumentHyperlinkByIndexResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentHyperlinkByIndexResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::HyperlinkResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetDocumentHyperlinkByIndexOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::HyperlinkResponse > GetDocumentHyperlinkByIndexOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentHyperlinkByIndexOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::HyperlinkResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetDocumentHyperlinks request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::HyperlinksResponse > GetDocumentHyperlinksResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentHyperlinksResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::HyperlinksResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetDocumentHyperlinksOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::HyperlinksResponse > GetDocumentHyperlinksOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentHyperlinksOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::HyperlinksResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetDocumentProperties request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentPropertiesResponse > GetDocumentPropertiesResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentPropertiesResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentPropertiesResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetDocumentPropertiesOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentPropertiesResponse > GetDocumentPropertiesOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentPropertiesOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentPropertiesResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetDocumentProperty request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentPropertyResponse > GetDocumentPropertyResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentPropertyResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentPropertyResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetDocumentPropertyOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentPropertyResponse > GetDocumentPropertyOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentPropertyOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentPropertyResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetDocumentProtection request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ProtectionDataResponse > GetDocumentProtectionResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentProtectionResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ProtectionDataResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetDocumentProtectionOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ProtectionDataResponse > GetDocumentProtectionOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentProtectionOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ProtectionDataResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetDocumentStatistics request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::StatDataResponse > GetDocumentStatisticsResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentStatisticsResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::StatDataResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetDocumentStatisticsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::StatDataResponse > GetDocumentStatisticsOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentStatisticsOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::StatDataResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetDocumentWithFormat request implementation
     */
    std::shared_ptr< std::istream > GetDocumentWithFormatResponse::getResult() const
    {
        return m_Result;
    }

    void GetDocumentWithFormatResponse::deserialize(const std::string_view& response)
    {
        m_Result = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * GetField request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FieldResponse > GetFieldResponse::getResult() const
    {
        return m_Result;
    }

    void GetFieldResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FieldResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetFieldOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FieldResponse > GetFieldOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetFieldOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FieldResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetFields request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FieldsResponse > GetFieldsResponse::getResult() const
    {
        return m_Result;
    }

    void GetFieldsResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FieldsResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetFieldsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FieldsResponse > GetFieldsOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetFieldsOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FieldsResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetFilesList request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FilesList > GetFilesListResponse::getResult() const
    {
        return m_Result;
    }

    void GetFilesListResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FilesList >();
        m_Result->fromJson(&json);
    }

    /*
     * GetFootnote request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FootnoteResponse > GetFootnoteResponse::getResult() const
    {
        return m_Result;
    }

    void GetFootnoteResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FootnoteResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetFootnoteOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FootnoteResponse > GetFootnoteOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetFootnoteOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FootnoteResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetFootnotes request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FootnotesResponse > GetFootnotesResponse::getResult() const
    {
        return m_Result;
    }

    void GetFootnotesResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FootnotesResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetFootnotesOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FootnotesResponse > GetFootnotesOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetFootnotesOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FootnotesResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetFormField request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FormFieldResponse > GetFormFieldResponse::getResult() const
    {
        return m_Result;
    }

    void GetFormFieldResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FormFieldResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetFormFieldOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FormFieldResponse > GetFormFieldOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetFormFieldOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FormFieldResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetFormFields request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FormFieldsResponse > GetFormFieldsResponse::getResult() const
    {
        return m_Result;
    }

    void GetFormFieldsResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FormFieldsResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetFormFieldsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FormFieldsResponse > GetFormFieldsOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetFormFieldsOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FormFieldsResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetHeaderFooter request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::HeaderFooterResponse > GetHeaderFooterResponse::getResult() const
    {
        return m_Result;
    }

    void GetHeaderFooterResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::HeaderFooterResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetHeaderFooterOfSection request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::HeaderFooterResponse > GetHeaderFooterOfSectionResponse::getResult() const
    {
        return m_Result;
    }

    void GetHeaderFooterOfSectionResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::HeaderFooterResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetHeaderFooterOfSectionOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::HeaderFooterResponse > GetHeaderFooterOfSectionOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetHeaderFooterOfSectionOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::HeaderFooterResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetHeaderFooterOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::HeaderFooterResponse > GetHeaderFooterOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetHeaderFooterOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::HeaderFooterResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetHeaderFooters request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::HeaderFootersResponse > GetHeaderFootersResponse::getResult() const
    {
        return m_Result;
    }

    void GetHeaderFootersResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::HeaderFootersResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetHeaderFootersOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::HeaderFootersResponse > GetHeaderFootersOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetHeaderFootersOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::HeaderFootersResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetList request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ListResponse > GetListResponse::getResult() const
    {
        return m_Result;
    }

    void GetListResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ListResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetListOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ListResponse > GetListOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetListOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ListResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetLists request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ListsResponse > GetListsResponse::getResult() const
    {
        return m_Result;
    }

    void GetListsResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ListsResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetListsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ListsResponse > GetListsOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetListsOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ListsResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetOfficeMathObject request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::OfficeMathObjectResponse > GetOfficeMathObjectResponse::getResult() const
    {
        return m_Result;
    }

    void GetOfficeMathObjectResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::OfficeMathObjectResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetOfficeMathObjectOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::OfficeMathObjectResponse > GetOfficeMathObjectOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetOfficeMathObjectOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::OfficeMathObjectResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetOfficeMathObjects request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::OfficeMathObjectsResponse > GetOfficeMathObjectsResponse::getResult() const
    {
        return m_Result;
    }

    void GetOfficeMathObjectsResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::OfficeMathObjectsResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetOfficeMathObjectsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::OfficeMathObjectsResponse > GetOfficeMathObjectsOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetOfficeMathObjectsOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::OfficeMathObjectsResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetParagraph request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphResponse > GetParagraphResponse::getResult() const
    {
        return m_Result;
    }

    void GetParagraphResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ParagraphResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetParagraphFormat request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphFormatResponse > GetParagraphFormatResponse::getResult() const
    {
        return m_Result;
    }

    void GetParagraphFormatResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ParagraphFormatResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetParagraphFormatOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphFormatResponse > GetParagraphFormatOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetParagraphFormatOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ParagraphFormatResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetParagraphListFormat request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphListFormatResponse > GetParagraphListFormatResponse::getResult() const
    {
        return m_Result;
    }

    void GetParagraphListFormatResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ParagraphListFormatResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetParagraphListFormatOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphListFormatResponse > GetParagraphListFormatOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetParagraphListFormatOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ParagraphListFormatResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetParagraphOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphResponse > GetParagraphOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetParagraphOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ParagraphResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetParagraphs request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphLinkCollectionResponse > GetParagraphsResponse::getResult() const
    {
        return m_Result;
    }

    void GetParagraphsResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ParagraphLinkCollectionResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetParagraphsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphLinkCollectionResponse > GetParagraphsOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetParagraphsOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ParagraphLinkCollectionResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetParagraphTabStops request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TabStopsResponse > GetParagraphTabStopsResponse::getResult() const
    {
        return m_Result;
    }

    void GetParagraphTabStopsResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TabStopsResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetParagraphTabStopsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TabStopsResponse > GetParagraphTabStopsOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetParagraphTabStopsOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TabStopsResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetRangeText request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::RangeTextResponse > GetRangeTextResponse::getResult() const
    {
        return m_Result;
    }

    void GetRangeTextResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::RangeTextResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetRangeTextOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::RangeTextResponse > GetRangeTextOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetRangeTextOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::RangeTextResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetRun request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::RunResponse > GetRunResponse::getResult() const
    {
        return m_Result;
    }

    void GetRunResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::RunResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetRunFont request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FontResponse > GetRunFontResponse::getResult() const
    {
        return m_Result;
    }

    void GetRunFontResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FontResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetRunFontOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FontResponse > GetRunFontOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetRunFontOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FontResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetRunOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::RunResponse > GetRunOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetRunOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::RunResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetRuns request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::RunsResponse > GetRunsResponse::getResult() const
    {
        return m_Result;
    }

    void GetRunsResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::RunsResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetRunsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::RunsResponse > GetRunsOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetRunsOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::RunsResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetSection request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SectionResponse > GetSectionResponse::getResult() const
    {
        return m_Result;
    }

    void GetSectionResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::SectionResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetSectionOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SectionResponse > GetSectionOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetSectionOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::SectionResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetSectionPageSetup request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SectionPageSetupResponse > GetSectionPageSetupResponse::getResult() const
    {
        return m_Result;
    }

    void GetSectionPageSetupResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::SectionPageSetupResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetSectionPageSetupOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SectionPageSetupResponse > GetSectionPageSetupOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetSectionPageSetupOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::SectionPageSetupResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetSections request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SectionLinkCollectionResponse > GetSectionsResponse::getResult() const
    {
        return m_Result;
    }

    void GetSectionsResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::SectionLinkCollectionResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetSectionsOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SectionLinkCollectionResponse > GetSectionsOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetSectionsOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::SectionLinkCollectionResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetStyle request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::StyleResponse > GetStyleResponse::getResult() const
    {
        return m_Result;
    }

    void GetStyleResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::StyleResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetStyleFromDocumentElement request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::StyleResponse > GetStyleFromDocumentElementResponse::getResult() const
    {
        return m_Result;
    }

    void GetStyleFromDocumentElementResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::StyleResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetStyleFromDocumentElementOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::StyleResponse > GetStyleFromDocumentElementOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetStyleFromDocumentElementOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::StyleResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetStyleOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::StyleResponse > GetStyleOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetStyleOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::StyleResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetStyles request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::StylesResponse > GetStylesResponse::getResult() const
    {
        return m_Result;
    }

    void GetStylesResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::StylesResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetStylesOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::StylesResponse > GetStylesOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetStylesOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::StylesResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetTable request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableResponse > GetTableResponse::getResult() const
    {
        return m_Result;
    }

    void GetTableResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetTableCell request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableCellResponse > GetTableCellResponse::getResult() const
    {
        return m_Result;
    }

    void GetTableCellResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableCellResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetTableCellFormat request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableCellFormatResponse > GetTableCellFormatResponse::getResult() const
    {
        return m_Result;
    }

    void GetTableCellFormatResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableCellFormatResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetTableCellFormatOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableCellFormatResponse > GetTableCellFormatOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetTableCellFormatOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableCellFormatResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetTableCellOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableCellResponse > GetTableCellOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetTableCellOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableCellResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetTableOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableResponse > GetTableOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetTableOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetTableProperties request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TablePropertiesResponse > GetTablePropertiesResponse::getResult() const
    {
        return m_Result;
    }

    void GetTablePropertiesResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TablePropertiesResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetTablePropertiesOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TablePropertiesResponse > GetTablePropertiesOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetTablePropertiesOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TablePropertiesResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetTableRow request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableRowResponse > GetTableRowResponse::getResult() const
    {
        return m_Result;
    }

    void GetTableRowResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableRowResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetTableRowFormat request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableRowFormatResponse > GetTableRowFormatResponse::getResult() const
    {
        return m_Result;
    }

    void GetTableRowFormatResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableRowFormatResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetTableRowFormatOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableRowFormatResponse > GetTableRowFormatOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetTableRowFormatOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableRowFormatResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetTableRowOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableRowResponse > GetTableRowOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetTableRowOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableRowResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetTables request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableLinkCollectionResponse > GetTablesResponse::getResult() const
    {
        return m_Result;
    }

    void GetTablesResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableLinkCollectionResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * GetTablesOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableLinkCollectionResponse > GetTablesOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void GetTablesOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableLinkCollectionResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * InsertComment request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::CommentResponse > InsertCommentResponse::getResult() const
    {
        return m_Result;
    }

    void InsertCommentResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::CommentResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void InsertCommentOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::CommentResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * InsertDrawingObject request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DrawingObjectResponse > InsertDrawingObjectResponse::getResult() const
    {
        return m_Result;
    }

    void InsertDrawingObjectResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DrawingObjectResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void InsertDrawingObjectOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::DrawingObjectResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * InsertField request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FieldResponse > InsertFieldResponse::getResult() const
    {
        return m_Result;
    }

    void InsertFieldResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FieldResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void InsertFieldOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::FieldResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * InsertFootnote request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FootnoteResponse > InsertFootnoteResponse::getResult() const
    {
        return m_Result;
    }

    void InsertFootnoteResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FootnoteResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void InsertFootnoteOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::FootnoteResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * InsertFormField request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FormFieldResponse > InsertFormFieldResponse::getResult() const
    {
        return m_Result;
    }

    void InsertFormFieldResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FormFieldResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void InsertFormFieldOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::FormFieldResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * InsertHeaderFooter request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::HeaderFooterResponse > InsertHeaderFooterResponse::getResult() const
    {
        return m_Result;
    }

    void InsertHeaderFooterResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::HeaderFooterResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void InsertHeaderFooterOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::HeaderFooterResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * InsertList request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ListResponse > InsertListResponse::getResult() const
    {
        return m_Result;
    }

    void InsertListResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ListResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void InsertListOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::ListResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * InsertOrUpdateParagraphTabStop request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TabStopsResponse > InsertOrUpdateParagraphTabStopResponse::getResult() const
    {
        return m_Result;
    }

    void InsertOrUpdateParagraphTabStopResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TabStopsResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void InsertOrUpdateParagraphTabStopOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::TabStopsResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * InsertPageNumbers request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > InsertPageNumbersResponse::getResult() const
    {
        return m_Result;
    }

    void InsertPageNumbersResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void InsertPageNumbersOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * InsertParagraph request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphResponse > InsertParagraphResponse::getResult() const
    {
        return m_Result;
    }

    void InsertParagraphResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ParagraphResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void InsertParagraphOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::ParagraphResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * InsertRun request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::RunResponse > InsertRunResponse::getResult() const
    {
        return m_Result;
    }

    void InsertRunResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::RunResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void InsertRunOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::RunResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * InsertStyle request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::StyleResponse > InsertStyleResponse::getResult() const
    {
        return m_Result;
    }

    void InsertStyleResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::StyleResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void InsertStyleOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::StyleResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * InsertTable request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableResponse > InsertTableResponse::getResult() const
    {
        return m_Result;
    }

    void InsertTableResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * InsertTableCell request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableCellResponse > InsertTableCellResponse::getResult() const
    {
        return m_Result;
    }

    void InsertTableCellResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableCellResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void InsertTableCellOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::TableCellResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
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

    void InsertTableOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::TableResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * InsertTableRow request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableRowResponse > InsertTableRowResponse::getResult() const
    {
        return m_Result;
    }

    void InsertTableRowResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableRowResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void InsertTableRowOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::TableRowResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * InsertWatermarkImage request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > InsertWatermarkImageResponse::getResult() const
    {
        return m_Result;
    }

    void InsertWatermarkImageResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void InsertWatermarkImageOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * InsertWatermarkText request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > InsertWatermarkTextResponse::getResult() const
    {
        return m_Result;
    }

    void InsertWatermarkTextResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void InsertWatermarkTextOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * LoadWebDocument request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SaveResponse > LoadWebDocumentResponse::getResult() const
    {
        return m_Result;
    }

    void LoadWebDocumentResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::SaveResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * MoveFile request implementation
     */

    void MoveFileResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * MoveFolder request implementation
     */

    void MoveFolderResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * OptimizeDocument request implementation
     */

    void OptimizeDocumentResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * OptimizeDocumentOnline request implementation
     */
    std::shared_ptr< std::istream > OptimizeDocumentOnlineResponse::getDocument() const
    {
        return m_Document;
    }

    void OptimizeDocumentOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * ProtectDocument request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ProtectionDataResponse > ProtectDocumentResponse::getResult() const
    {
        return m_Result;
    }

    void ProtectDocumentResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ProtectionDataResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void ProtectDocumentOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::ProtectionDataResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * RejectAllRevisions request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::RevisionsModificationResponse > RejectAllRevisionsResponse::getResult() const
    {
        return m_Result;
    }

    void RejectAllRevisionsResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::RevisionsModificationResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void RejectAllRevisionsOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::RevisionsModificationResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * RemoveRange request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > RemoveRangeResponse::getResult() const
    {
        return m_Result;
    }

    void RemoveRangeResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void RemoveRangeOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * RenderDrawingObject request implementation
     */
    std::shared_ptr< std::istream > RenderDrawingObjectResponse::getResult() const
    {
        return m_Result;
    }

    void RenderDrawingObjectResponse::deserialize(const std::string_view& response)
    {
        m_Result = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * RenderDrawingObjectOnline request implementation
     */
    std::shared_ptr< std::istream > RenderDrawingObjectOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void RenderDrawingObjectOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Result = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * RenderMathObject request implementation
     */
    std::shared_ptr< std::istream > RenderMathObjectResponse::getResult() const
    {
        return m_Result;
    }

    void RenderMathObjectResponse::deserialize(const std::string_view& response)
    {
        m_Result = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * RenderMathObjectOnline request implementation
     */
    std::shared_ptr< std::istream > RenderMathObjectOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void RenderMathObjectOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Result = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * RenderPage request implementation
     */
    std::shared_ptr< std::istream > RenderPageResponse::getResult() const
    {
        return m_Result;
    }

    void RenderPageResponse::deserialize(const std::string_view& response)
    {
        m_Result = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * RenderPageOnline request implementation
     */
    std::shared_ptr< std::istream > RenderPageOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void RenderPageOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Result = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * RenderParagraph request implementation
     */
    std::shared_ptr< std::istream > RenderParagraphResponse::getResult() const
    {
        return m_Result;
    }

    void RenderParagraphResponse::deserialize(const std::string_view& response)
    {
        m_Result = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * RenderParagraphOnline request implementation
     */
    std::shared_ptr< std::istream > RenderParagraphOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void RenderParagraphOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Result = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * RenderTable request implementation
     */
    std::shared_ptr< std::istream > RenderTableResponse::getResult() const
    {
        return m_Result;
    }

    void RenderTableResponse::deserialize(const std::string_view& response)
    {
        m_Result = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * RenderTableOnline request implementation
     */
    std::shared_ptr< std::istream > RenderTableOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void RenderTableOnlineResponse::deserialize(const std::string_view& response)
    {
        m_Result = std::shared_ptr< std::istream >(new std::istringstream(std::string(response), std::ios_base::in));
    }

    /*
     * ReplaceText request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ReplaceTextResponse > ReplaceTextResponse::getResult() const
    {
        return m_Result;
    }

    void ReplaceTextResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ReplaceTextResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void ReplaceTextOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::ReplaceTextResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * ReplaceWithText request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > ReplaceWithTextResponse::getResult() const
    {
        return m_Result;
    }

    void ReplaceWithTextResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void ReplaceWithTextOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * ResetCache request implementation
     */

    void ResetCacheResponse::deserialize(const std::string_view& response)
    {
    }

    /*
     * SaveAs request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SaveResponse > SaveAsResponse::getResult() const
    {
        return m_Result;
    }

    void SaveAsResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::SaveResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void SaveAsOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::SaveResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * SaveAsRange request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > SaveAsRangeResponse::getResult() const
    {
        return m_Result;
    }

    void SaveAsRangeResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void SaveAsRangeOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * SaveAsTiff request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SaveResponse > SaveAsTiffResponse::getResult() const
    {
        return m_Result;
    }

    void SaveAsTiffResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::SaveResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void SaveAsTiffOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::SaveResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * Search request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SearchResponse > SearchResponse::getResult() const
    {
        return m_Result;
    }

    void SearchResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::SearchResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * SearchOnline request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SearchResponse > SearchOnlineResponse::getResult() const
    {
        return m_Result;
    }

    void SearchOnlineResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::SearchResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * SplitDocument request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SplitDocumentResponse > SplitDocumentResponse::getResult() const
    {
        return m_Result;
    }

    void SplitDocumentResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::SplitDocumentResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void SplitDocumentOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::SplitDocumentResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * UnprotectDocument request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ProtectionDataResponse > UnprotectDocumentResponse::getResult() const
    {
        return m_Result;
    }

    void UnprotectDocumentResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ProtectionDataResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void UnprotectDocumentOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::ProtectionDataResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * UpdateBookmark request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BookmarkResponse > UpdateBookmarkResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateBookmarkResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::BookmarkResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void UpdateBookmarkOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::BookmarkResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * UpdateBorder request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::BorderResponse > UpdateBorderResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateBorderResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::BorderResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void UpdateBorderOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::BorderResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * UpdateComment request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::CommentResponse > UpdateCommentResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateCommentResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::CommentResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void UpdateCommentOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::CommentResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * UpdateDrawingObject request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DrawingObjectResponse > UpdateDrawingObjectResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateDrawingObjectResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DrawingObjectResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void UpdateDrawingObjectOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::DrawingObjectResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * UpdateField request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FieldResponse > UpdateFieldResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateFieldResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FieldResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void UpdateFieldOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::FieldResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * UpdateFields request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::DocumentResponse > UpdateFieldsResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateFieldsResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void UpdateFieldsOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::DocumentResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * UpdateFootnote request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FootnoteResponse > UpdateFootnoteResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateFootnoteResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FootnoteResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void UpdateFootnoteOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::FootnoteResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * UpdateFormField request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FormFieldResponse > UpdateFormFieldResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateFormFieldResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FormFieldResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void UpdateFormFieldOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::FormFieldResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * UpdateList request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ListResponse > UpdateListResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateListResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ListResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * UpdateListLevel request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ListResponse > UpdateListLevelResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateListLevelResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ListResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void UpdateListLevelOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::ListResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
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

    void UpdateListOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::ListResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * UpdateParagraphFormat request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphFormatResponse > UpdateParagraphFormatResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateParagraphFormatResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ParagraphFormatResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void UpdateParagraphFormatOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::ParagraphFormatResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * UpdateParagraphListFormat request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::ParagraphListFormatResponse > UpdateParagraphListFormatResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateParagraphListFormatResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::ParagraphListFormatResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void UpdateParagraphListFormatOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::ParagraphListFormatResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * UpdateRun request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::RunResponse > UpdateRunResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateRunResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::RunResponse >();
        m_Result->fromJson(&json);
    }

    /*
     * UpdateRunFont request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FontResponse > UpdateRunFontResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateRunFontResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FontResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void UpdateRunFontOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::FontResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
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

    void UpdateRunOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::RunResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * UpdateSectionPageSetup request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::SectionPageSetupResponse > UpdateSectionPageSetupResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateSectionPageSetupResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::SectionPageSetupResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void UpdateSectionPageSetupOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::SectionPageSetupResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * UpdateStyle request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::StyleResponse > UpdateStyleResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateStyleResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::StyleResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void UpdateStyleOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::StyleResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * UpdateTableCellFormat request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableCellFormatResponse > UpdateTableCellFormatResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateTableCellFormatResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableCellFormatResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void UpdateTableCellFormatOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::TableCellFormatResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * UpdateTableProperties request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TablePropertiesResponse > UpdateTablePropertiesResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateTablePropertiesResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TablePropertiesResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void UpdateTablePropertiesOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::TablePropertiesResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * UpdateTableRowFormat request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::TableRowFormatResponse > UpdateTableRowFormatResponse::getResult() const
    {
        return m_Result;
    }

    void UpdateTableRowFormatResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::TableRowFormatResponse >();
        m_Result->fromJson(&json);
    }

    /*
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

    void UpdateTableRowFormatOnlineResponse::deserialize(const std::string_view& response)
    {
        std::unordered_map<std::string, std::string_view> parts;
        parseMultipart(response, parts);
        if (parts.find("Model") != parts.end()) {
            const std::string_view& part = parts.at("Model");
            auto json = ::nlohmann::json::parse(part);
            m_Model = std::make_shared< aspose::words::cloud::models::TableRowFormatResponse >();
            m_Model->fromJson(&json);
        }
        if (parts.find("Document") != parts.end()) {
            const std::string_view& part = parts.at("Document");
            m_Document = std::shared_ptr< std::istream >(new std::istringstream(std::string(part), std::ios_base::in));
        }
    }

    /*
     * UploadFile request implementation
     */
    std::shared_ptr< aspose::words::cloud::models::FilesUploadResult > UploadFileResponse::getResult() const
    {
        return m_Result;
    }

    void UploadFileResponse::deserialize(const std::string_view& response)
    {
        auto json = ::nlohmann::json::parse(response);
        m_Result = std::make_shared< aspose::words::cloud::models::FilesUploadResult >();
        m_Result->fromJson(&json);
    }
}