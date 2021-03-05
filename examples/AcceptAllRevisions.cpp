#include <boost/filesystem.hpp>
#include "WordsApi.h"
using namespace aspose::words::cloud::api;

utility::string_t documentsDir = STCONVERT("...");
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ STCONVERT("####-####-####-####-####"), /*clientSecret*/ STCONVERT("##################"));
auto wordsApi = std::make_shared<WordsApi>(config);
utility::string_t fileName  = STCONVERT("test_doc.docx");

// Upload original document to cloud storage.
auto fileContentContent = std::make_shared<HttpContent>();
auto fileContentStream = std::make_shared<boost::filesystem::ifstream>(documentsDir + STCONVERT("/fileName"), std::ifstream::binary);
fileContentContent->setData(fileContentStream);
fileContentContent->setContentDisposition(_XPLATSTR("form-data"));

auto uploadFileRequest = std::make_shared< UploadFileRequest >(fileContentContent, fileName, boost::none);
wordsApi->uploadFile(uploadFileRequest);

// Calls AcceptAllRevisions method for document in cloud.

auto request = std::make_shared< AcceptAllRevisionsRequest >(fileName, boost::none, boost::none, boost::none, boost::none, boost::none);
wordsApi->acceptAllRevisions(request);
