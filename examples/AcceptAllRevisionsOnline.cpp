﻿auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::wstring fileName = L"test_doc.docx";

// Calls AcceptAllRevisionsOnline method for document in cloud.
auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(fileName), std::istream::binary));
std::shared_ptr< requests::AcceptAllRevisionsOnlineRequest > request(
    new requests::AcceptAllRevisionsOnlineRequest(
        requestDocument
    )
);
auto acceptAllRevisionsOnlineResult = wordsApi->acceptAllRevisionsOnline(request);
{
    char buffer[1024];
    std::ofstream fileWriter("test_result.docx", std::ofstream::binary);
    const auto& fileData = *acceptAllRevisionsOnlineResult->getDocument()->begin();
    while(fileData.second->read(buffer, sizeof(buffer))) {
        fileWriter.write(buffer, sizeof(buffer));
    }
    fileWriter.write(buffer, fileData.second->gcount());
    fileWriter.close();
}