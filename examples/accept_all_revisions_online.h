std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::wstring fileName  = L"test_doc.docx";

// Calls AcceptAllRevisionsOnline method for document in cloud.
auto documentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + fileName), std::istream::binary));
std::shared_ptr< requests::AcceptAllRevisionsOnlineRequest > request(
    new requests::AcceptAllRevisionsOnlineRequest(
        documentStream
    )
);
auto acceptAllRevisionsOnlineResult = wordsApi->acceptAllRevisionsOnline(request);
{
    char buffer[1024];
    std::ofstream fileWriter("test_result.docx", std::ofstream::binary);
    while(acceptAllRevisionsOnlineResult->getDocument()->read(buffer, sizeof(buffer))) {
        fileWriter.write(buffer, sizeof(buffer));
    }
    fileWriter.write(buffer, acceptAllRevisionsOnlineResult->getDocument()->gcount());
    fileWriter.close();
}