//PostLoadWebDocumentRequest.h
#include "cpprest/details/basic_types.h"
#undef U
#include "LoadWebDocumentData.h"
#include <boost/optional.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

class PostLoadWebDocumentRequest{
    public: 
    PostLoadWebDocumentRequest(
        std::shared_ptr<LoadWebDocumentData> data,
                boost::optional<utility::string_t> storage
        );

    public:
        std::shared_ptr<LoadWebDocumentData> data;
        boost::optional<utility::string_t> storage;
};

}
}
}
}
