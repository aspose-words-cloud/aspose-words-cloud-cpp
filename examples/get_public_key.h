auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::GetPublicKeyRequest > request(
    new requests::GetPublicKeyRequest(
    )
);
wordsApi->getPublicKey(request);