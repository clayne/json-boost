//
// Copyright (c) 2019 Vinnie Falco (vinnie.falco@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/cppalliance/json
//

#ifndef BOOST_JSON_DETAIL_EXCEPT_HPP
#define BOOST_JSON_DETAIL_EXCEPT_HPP

#include <boost/json/error.hpp>

#ifndef BOOST_JSON_STANDALONE
#include <boost/assert/source_location.hpp>
#include <boost/exception/diagnostic_information.hpp>
#endif

BOOST_JSON_NS_BEGIN
namespace detail {

#ifndef BOOST_JSON_STANDALONE
using source_location = boost::source_location;
#else
#define BOOST_CURRENT_LOCATION {}
struct source_location
{
};
#endif

BOOST_JSON_DECL void BOOST_NORETURN throw_bad_alloc(source_location const& loc);
BOOST_JSON_DECL void BOOST_NORETURN throw_invalid_argument(char const* what, source_location const& loc);
BOOST_JSON_DECL void BOOST_NORETURN throw_length_error(char const* what, source_location const& loc);
BOOST_JSON_DECL void BOOST_NORETURN throw_out_of_range(source_location const& loc);
BOOST_JSON_DECL void BOOST_NORETURN throw_system_error(error_code const& ec, source_location const& loc);

} // detail
BOOST_JSON_NS_END

#ifdef BOOST_JSON_HEADER_ONLY
#include <boost/json/detail/impl/except.ipp>
#endif

#endif