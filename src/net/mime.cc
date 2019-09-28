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

#include <boost/beast/core.hpp>
#include <laplace/net/mime.hh>
#include <string_view>

namespace laplace {
namespace net {
std::string_view mime_type(std::string_view path) {
  const auto extension = [&path] {
    const auto dot_pos = path.rfind("."); // cut-up position by dot
    if (dot_pos == std::string_view::npos)
      return std::string_view{};
    return path.substr(dot_pos);
  }();

  // text files
  if (boost::beast::iequals(extension.data(), ".htm"))
    return "text/html";
  if (boost::beast::iequals(extension.data(), ".html"))
    return "text/html";
  if (boost::beast::iequals(extension.data(), ".css"))
    return "text/css";
  if (boost::beast::iequals(extension.data(), ".txt"))
    return "text/plain";
  if (boost::beast::iequals(extension.data(), ".js"))
    return "application/javascript";
  if (boost::beast::iequals(extension.data(), ".json"))
    return "application/json";
  if (boost::beast::iequals(extension.data(), ".xml"))
    return "application/xml";

  // font files

  if (boost::beast::iequals(extension.data(), ".ttf"))
    return "font/ttf";
  if (boost::beast::iequals(extension.data(), ".otf"))
    return "font/otf";

  // pics
  if (boost::beast::iequals(extension.data(), ".png"))
    return "image/png";
  if (boost::beast::iequals(extension.data(), ".jpe"))
    return "image/jpeg";
  if (boost::beast::iequals(extension.data(), ".jpeg"))
    return "image/jpeg";
  if (boost::beast::iequals(extension.data(), ".jpg"))
    return "image/jpeg";
  if (boost::beast::iequals(extension.data(), ".gif"))
    return "image/gif";
  if (boost::beast::iequals(extension.data(), ".bmp"))
    return "image/bmp";
  if (boost::beast::iequals(extension.data(), ".ico"))
    return "image/x-icon";
  if (boost::beast::iequals(extension.data(), ".tiff"))
    return "image/tiff";
  if (boost::beast::iequals(extension.data(), ".tif"))
    return "image/tiff";
  if (boost::beast::iequals(extension.data(), ".svg"))
    return "image/svg+xml";
  if (boost::beast::iequals(extension.data(), ".svgz"))
    return "image/svg+xml";
  if (boost::beast::iequals(extension.data(), ".webp"))
    return "image/webp";

  // sound files
  if (boost::beast::iequals(extension.data(), ".wav"))
    return "audio/wav";
  if (boost::beast::iequals(extension.data(), ".ogg"))
    return "application/ogg";

  // video files
  if (boost::beast::iequals(extension.data(), ".flv"))
    return "video/x-flv";
  if (boost::beast::iequals(extension.data(), ".mp4"))
    return "video/mp4";
  if (boost::beast::iequals(extension.data(), ".webm"))
    return "video/webm";

  return "application/text";
}
} // namespace net
} // namespace laplace
