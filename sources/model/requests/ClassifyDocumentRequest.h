//ClassifyDocumentRequest.h
#include "cpprest/details/basic_types.h"
#undef U
#include <boost/optional.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

class ClassifyDocumentRequest{
    public: 
    ClassifyDocumentRequest(
        utility::string_t documentName,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> bestClassesCount,
                boost::optional<utility::string_t> taxonomy
        );

    public:
        utility::string_t documentName;
        boost::optional<utility::string_t> folder;
        boost::optional<utility::string_t> storage;
        boost::optional<utility::string_t> loadEncoding;
        boost::optional<utility::string_t> password;
        boost::optional<utility::string_t> bestClassesCount;
        boost::optional<utility::string_t> taxonomy;
};

}
}
}
}
