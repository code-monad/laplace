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

#ifndef __LAPLACE_SESSION_HH__
#define __LAPLACE_SESSION_HH__

#include <boost/asio/io_context.hpp>
#include <boost/beast/core/tcp_stream.hpp>
#include <boost/beast/websocket/stream.hpp>
#include <laplace/net/types.hh>

namespace laplace {
namespace net {

enum class session_type { none = 0, http = 1, websocket = 2 };

class session : public std::enable_shared_from_this<session> {
public:
  session() = delete;
  explicit session(boost::asio::io_context &context);
  virtual ~session();

private:
  boost::asio::io_context &_context;
  boost::beast::websocket::stream<boost::beast::tcp_stream> _ws;
};
} // namespace net
} // namespace laplace

#endif // __LAPLACE_SESSION_HH__
