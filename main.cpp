#include <boost/functionoid/functionoid.hpp>

struct DefaultFunctionTraits : boost::functionoid::default_traits
{
    static constexpr auto copyable             = boost::functionoid::support_level::na;
    static constexpr auto moveable             = boost::functionoid::support_level::nofail;
    static constexpr auto destructor           = boost::functionoid::support_level::nofail;
    static constexpr auto rtti                 = false;
    static constexpr auto dll_safe_empty_check = false;

    using empty_handler = boost::functionoid::assert_on_empty;
}; // struct DefaultFunctionTraits

template < typename Signature, typename Traits = DefaultFunctionTraits >
using Function = boost::functionoid::callable< Signature, Traits >;

int main()
{
    Function< int() > f{ []() noexcept { return 3; } };

    auto n = f();

    f = []() noexcept { return 4; };
    return n + f();
}
