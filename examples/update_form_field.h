auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::wstring remoteFileName = L"Sample.docx";

auto requestFormField = std::make_shared< aspose::words::cloud::models::FormFieldTextInput >();
requestFormField->setName(std::make_shared< std::wstring >(L"FullName"));
requestFormField->setEnabled(std::make_shared< bool >(true));
requestFormField->setCalculateOnExit(std::make_shared< bool >(true));
requestFormField->setStatusText(std::make_shared< std::wstring >(L""));
requestFormField->setTextInputType(std::make_shared< aspose::words::cloud::models::FormFieldTextInput::TextInputType >(aspose::words::cloud::models::FormFieldTextInput::TextInputType::REGULAR));
requestFormField->setTextInputDefault(std::make_shared< std::wstring >(L"No name"));

std::shared_ptr< requests::UpdateFormFieldRequest > updateRequest(
    new requests::UpdateFormFieldRequest(
        std::make_shared< std::wstring >(remoteFileName), std::make_shared< int32_t >(0), requestFormField, std::make_shared< std::wstring >(remoteFileName)
    )
);
wordsApi->updateFormField(updateRequest);