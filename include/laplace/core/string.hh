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

#include <string>
#include <string_view>

namespace laplace {
namespace string {

// Defines a range of a string(_view)

template <typename _Char_T, class _Traits_T = std::char_traits<_Char_T>>
typedef std::pair<std::basic_string_view<_Char_T, _Traits_T>::iterator,
                  std::basic_string_view<_Char_T, _Traits_T>::iterator>
    range_t;

template <typename _Char_T, class _Traits_T = std::char_traits<_Char_T>>
typedef std::pair<std::basic_string_view<_Char_T, _Traits_T>::iterator,
                  std::basic_string_view<_Char_T, _Traits_T>::iterator>
    view_range_t;

} // namespace string
} // namespace laplace
