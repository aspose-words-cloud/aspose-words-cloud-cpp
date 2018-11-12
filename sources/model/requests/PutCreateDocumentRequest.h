//PutCreateDocumentRequest.h
#include "cpprest/details/basic_types.h"
#undef U
#include <boost/optional.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

class PutCreateDocumentRequest{
    public: 
    PutCreateDocumentRequest(
        boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> fileName,
                boost::optional<utility::string_t> folder
        );

    public:
        boost::optional<utility::string_t> storage;
        boost::optional<utility::string_t> fileName;
        boost::optional<utility::string_t> folder;
};

}
}
}
}
