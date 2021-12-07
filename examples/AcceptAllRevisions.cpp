#include "aspose_words_cloud.h"
using namespace aspose::words::cloud;

auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::wstring fileName = L"test_doc.docx";

// Upload original document to cloud storage.
auto myVar1 = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(fileName), std::istream::binary));
auto myVar2 = std::make_shared< std::wstring >(fileName);
std::shared_ptr< requests::UploadFileRequest > uploadFileRequest(
    new requests::UploadFileRequest(
        myVar1, myVar2
    )
);
wordsApi->uploadFile(uploadFileRequest);

// Calls AcceptAllRevisions method for document in cloud.
auto myVar3 = std::make_shared< std::wstring >(fileName);
std::shared_ptr< requests::AcceptAllRevisionsRequest > request(
    new requests::AcceptAllRevisionsRequest(
        myVar3
    )
);
wordsApi->acceptAllRevisions(request);