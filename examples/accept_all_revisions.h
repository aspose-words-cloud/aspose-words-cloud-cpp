#include "aspose_words_cloud.h"
using namespace aspose::words::cloud;

std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::wstring fileName  = L"test_doc.docx";

// Upload original document to cloud storage.
auto fileContentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + fileName), std::istream::binary));
std::shared_ptr< requests::UploadFileRequest > uploadFileRequest(
    new requests::UploadFileRequest(
        fileContentStream, std::make_shared< std::wstring >(fileName)
    )
);
wordsApi->uploadFile(uploadFileRequest);

// Calls AcceptAllRevisions method for document in cloud.
std::shared_ptr< requests::AcceptAllRevisionsRequest > request(
    new requests::AcceptAllRevisionsRequest(
        std::make_shared< std::wstring >(fileName)
    )
);
wordsApi->acceptAllRevisions(request);