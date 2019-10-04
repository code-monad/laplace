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
#ifndef __LAPLACE_NET_EXCEPTION_HH__
#define __LAPLACE_NET_EXCEPTION_HH__

#include <stdexcept>
#include <string_view>

namespace laplace {
namespace net {
class exception : public std::exception {
public:
  exception();
  virtual const char* what() const noexcept = 0;
  virtual ~exception() = default;
};

class invalid_uri : public laplace::net::exception, public std::invalid_argument {
public:
  explicit invalid_uri(const std::string& what_arg);
  explicit invalid_uri(const char* what_arg);
  const char* what() const noexcept;
  ~invalid_uri() = default;

private:
  std::string_view _what;
};

} // namespace net
} // namespace laplace

#endif // __LAPLACE_NET_EXCEPTION_HH__
