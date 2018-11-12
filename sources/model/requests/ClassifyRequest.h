//ClassifyRequest.h
#include "cpprest/details/basic_types.h"
#undef U
#include <boost/optional.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

class ClassifyRequest{
    public: 
    ClassifyRequest(
        utility::string_t text,
                boost::optional<utility::string_t> bestClassesCount
        );

    public:
        utility::string_t text;
        boost::optional<utility::string_t> bestClassesCount;
};

}
}
}
}
