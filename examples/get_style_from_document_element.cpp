auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::GetStyleFromDocumentElementRequest > request(
    new requests::GetStyleFromDocumentElementRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"paragraphs/1/paragraphFormat")
    )
);
wordsApi->getStyleFromDocumentElement(request);