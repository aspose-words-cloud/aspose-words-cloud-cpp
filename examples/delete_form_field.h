auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::wstring remoteFileName = L"Sample.docx";

std::shared_ptr< requests::DeleteFormFieldRequest > deleteRequest(
    new requests::DeleteFormFieldRequest(
        std::make_shared< std::wstring >(remoteFileName), std::make_shared< int32_t >(0), std::make_shared< std::wstring >(remoteFileName)
    )
);
wordsApi->deleteFormField(deleteRequest);