std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
auto requestFormField = std::make_shared< aspose::words::cloud::models::FormFieldTextInput >();
requestFormField->setName(std::make_shared< std::wstring >(L"FullName"));
requestFormField->setEnabled(std::make_shared< bool >(true));
requestFormField->setCalculateOnExit(std::make_shared< bool >(true));
requestFormField->setStatusText(std::make_shared< std::wstring >(L""));
requestFormField->setTextInputType(std::make_shared< aspose::words::cloud::models::FormFieldTextInput::TextInputType >(aspose::words::cloud::models::FormFieldTextInput::TextInputType::REGULAR));
requestFormField->setTextInputDefault(std::make_shared< std::wstring >(L"No name"));

std::shared_ptr< requests::UpdateFormFieldOnlineRequest > updateRequest(
    new requests::UpdateFormFieldOnlineRequest(
        requestDocumentStream, requestFormField, std::make_shared< int32_t >(0), std::make_shared< std::wstring >(L"sections/0")
    )
);
wordsApi->updateFormFieldOnline(updateRequest);