// --------------------------NOTICE----------------------------------
//
// Copyright (C) 2019 Code Monad <code@lab-11.org>, All Rights Reserved
//
// This file is part of Laplace.
//
// Laplace is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Laplace is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Laplace.  If not, see <https://www.gnu.org/licenses/>.
// ------------------------------------------------------------------

#ifndef __LAPLACE_URI_HH__
#define __LAPLACE_URI_HH__

#include <laplace/net/exception.hh>
#include <laplace/net/symbol.hh>
#include <optional>
#include <string>
#include <string_view>

namespace laplace {
namespace net {
namespace uri {
template <typename _Char_T, class _Traits_T = std::char_traits<_Char_T>> class basic_uri {
  typedef std::basic_string_view<_Char_T, _Traits_T> string_view_type;
  typedef std::basic_string<_Char_T, _Traits_T> string_type;

public:
  basic_uri() : _size{0}, _data{} {}
  explicit basic_uri(string_view_type uri_data) : _data{uri_data} { this->parse(_data); }
  explicit basic_uri(string_type uri_data) : _data{uri_data} {}

  constexpr bool empty() noexcept { return _data.empty(); }
  const std::size_t size() noexcept { return _size; }

  virtual basic_uri& parse(string_view_type data) { return *this; }

  // Checkout
  // https://en.wikipedia.org/wiki/Uniform_Resource_Identifier#Generic_syntax
  // for details of each identifiers

  string_view_type scheme() noexcept { return _scheme; }

  string_view_type host() noexcept { return _host; }

  string_view_type target() noexcept { return _target; }

  string_view_type query() noexcept { return _query; }

  string_view_type fragment() noexcept { return _fragment; }

  void clear() {
    _size = 0;
    _data.clear();
    _scheme.reset();
    _host.clear();
    _target.clear();
    _query.clear();
    _fragment.clear();
  }

  virtual ~basic_uri(){};

private:
  std::size_t _size;
  string_view_type _data; // holds the raw uri string
  string_view_type _scheme;
  string_view_type _host;
  string_view_type _target;
  string_view_type _query;
  string_view_type _fragment;
};

typedef basic_uri<char> uri;
typedef basic_uri<wchar_t> wuri;

} // namespace uri
} // namespace net
} // namespace laplace

#endif // __LAPLACE_URI_HH__
