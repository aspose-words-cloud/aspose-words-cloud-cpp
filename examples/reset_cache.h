auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::ResetCacheRequest > resetRequest(
    new requests::ResetCacheRequest(
    )
);
wordsApi->resetCache(resetRequest);