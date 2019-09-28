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

#include <laplace/net/exception.hh>
#include <sstream>
#include <stdexcept>

invalid_uri::invalid_uri(const std::string& what_arg)
    : std::invalid_argument(what_arg) {}

invalid_uri::invalid_uri(const char* what_arg)
    : std::invalid_argument(what_arg) {}

const char* invalid_uri::what() const noexcept {
  std::ostringstream ss;
  ss << _what << " is not a valid uri";
  return ss.str();
}
