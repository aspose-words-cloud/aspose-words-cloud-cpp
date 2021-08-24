auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::InsertHeaderFooterRequest > insertRequest(
    new requests::InsertHeaderFooterRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L""), std::make_shared< std::wstring >(L"FooterEven")
    )
);
wordsApi->insertHeaderFooter(insertRequest);