
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SearchResponse.h">
*   Copyright (c) 2018 Aspose.Words for Cloud
* </copyright>
* <summary>
*   Permission is hereby granted, free of charge, to any person obtaining a copy
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is
*  furnished to do so, subject to the following conditions:
* 
*  The above copyright notice and this permission notice shall be included in all
*  copies or substantial portions of the Software.
* 
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*  SOFTWARE.
* </summary> 
-------------------------------------------------------------------------------------------------------------------- **/

#ifndef IO_SWAGGER_CLIENT_MODEL_SearchResponse_H_
#define IO_SWAGGER_CLIENT_MODEL_SearchResponse_H_


#include "AsposeResponse.h"
#include "SearchResultsCollection.h"
#include <cpprest/details/basic_types.h>

namespace io {
namespace swagger {
namespace client {
namespace model {

/// <summary>
/// This response should be returned by the service when handling: GET http://api.aspose.com/v1.1/words/Test.doc/search 
/// </summary>
class  SearchResponse
    : public AsposeResponse
{
public:
    SearchResponse();
    virtual ~SearchResponse();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// SearchResponse members

    /// <summary>
    /// A regular expression pattern used to find matches.
    /// </summary>
    utility::string_t getSearchingPattern() const;
    bool searchingPatternIsSet() const;
    void unsetSearchingPattern();
    void setSearchingPattern(utility::string_t value);
    /// <summary>
    /// Collection of search results.
    /// </summary>
    std::shared_ptr<SearchResultsCollection> getSearchResults() const;
    bool searchResultsIsSet() const;
    void unsetSearchResults();
    void setSearchResults(std::shared_ptr<SearchResultsCollection> value);

protected:
    utility::string_t m_SearchingPattern;
    bool m_SearchingPatternIsSet;
    std::shared_ptr<SearchResultsCollection> m_SearchResults;
    bool m_SearchResultsIsSet;
};

}
}
}
}

#endif /* IO_SWAGGER_CLIENT_MODEL_SearchResponse_H_ */
