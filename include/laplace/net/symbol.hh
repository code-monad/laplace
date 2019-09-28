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

namespace laplace {
namespace net {
namespace symbol {
// Below defines a set of symbol chars and their alias, mostly used in
// the URI parsing, and one shall never use using-declaration to
// include this namespace (due to the hash sign)

// The colon symblo, for template
template <typename _Char_T, class _Traits_T = std::char_traits<_Char_T>>
constexpr const _Char_T basic_colon() noexcept {}

template <> constexpr const char basic_colon<char>() noexcept { return ':'; }

template <> constexpr const wchar_t basic_colon<wchar_t>() noexcept { return L':'; }

// covinience alias
constexpr const char colon = basic_colon<char>();
constexpr const wchar_t wcolon = basic_colon<wchar_t>();

// The slash symblo, for template
template <typename _Char_T, class _Traits_T = std::char_traits<_Char_T>>
constexpr const _Char_T basic_slash() noexcept {}
template <> constexpr const char basic_slash<char>() noexcept { return '/'; }
template <> constexpr const wchar_t basic_slash<wchar_t>() noexcept { return L'/'; }

// covinience alias
constexpr const char slash = basic_slash<char>();
constexpr const wchar_t wslash = basic_slash<wchar_t>();

// The question symblo, for template
template <typename _Char_T, class _Traits_T = std::char_traits<_Char_T>>
constexpr const _Char_T basic_question() noexcept {}
template <> constexpr const char basic_question<char>() noexcept { return '?'; }
template <> constexpr const wchar_t basic_question<wchar_t>() noexcept { return L'?'; }

// covinience alias
constexpr const char question = basic_question<char>();
constexpr const wchar_t wquestion = basic_question<wchar_t>();

// The hash symblo, for template
template <typename _Char_T, class _Traits_T = std::char_traits<_Char_T>>
constexpr const _Char_T basic_hash() noexcept {}
template <> constexpr const char basic_hash<char>() noexcept { return '#'; }
template <> constexpr const wchar_t basic_hash<wchar_t>() noexcept { return L'#'; }

// covinience alias
// WARN: Don't be confused between it and a hash function
constexpr const char hash = basic_hash<char>();
constexpr const wchar_t whash = basic_hash<wchar_t>();
} // namespace symbol

} // namespace net
} // namespace laplace
