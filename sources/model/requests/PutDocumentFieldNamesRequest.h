//PutDocumentFieldNamesRequest.h
#include "cpprest/details/basic_types.h"
#undef U
#include "HttpContent.h"
#include <boost/optional.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

class PutDocumentFieldNamesRequest{
    public: 
    PutDocumentFieldNamesRequest(
        std::shared_ptr<HttpContent> _template,
                boost::optional<bool> useNonMergeFields
        );

    public:
        std::shared_ptr<HttpContent> _template;
        boost::optional<bool> useNonMergeFields;
};

}
}
}
}
