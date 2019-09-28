# --------------------------NOTICE----------------------------------
# 
# Copyright (C) 2019 Code Monad <code@lab-11.org>, All Rights Reserved
# 
# This file is part of Laplace.
# 
# Laplace is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# Laplace is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with Laplace.  If not, see <https://www.gnu.org/licenses/>.
# ------------------------------------------------------------------

cmake_minimum_required(VERSION 3.11)

project(Laplace VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
SET(BOOST_MIN_VERSION "1.7.0") # Boost > 1.7 is required for building
find_package(Boost  ${BOOST_MIN_VERSION} REQUIRED)

# Laplace's Net Module
set(LAPLACE_NET_INC_DIR ${CMAKE_SOURCE_DIR}/include/laplace/net)
set(LAPLACE_NET_HEADER ${LAPLACE_NET_INC_DIR}/mime.hh ${LAPLACE_NET_INC_DIR}/session.hh ${LAPLACE_NET_INC_DIR}/net.hh)
set(LAPLACE_NET_SRC_DIR ${CMAKE_SOURCE_DIR}/src/net)
set(LAPLACE_NET_SRC ${LAPLACE_NET_SRC_DIR}/mime.cc ${LAPLACE_NET_SRC_DIR}/session.cc)
add_library(laplace_net SHARED ${LAPLACE_NET_HEADER} ${LAPLACE_NET_SRC})
target_compile_features(laplace_net PUBLIC cxx_std_17)
target_include_directories(laplace_net PUBLIC ${CMAKE_SOURCE_DIR}/include ${Boost_INCLUDE_DIRS})

if(BUILD_TEST)
  # Catch2 for unit testing
  add_subdirectory(${CMAKE_SOURCE_DIR}/third_party/Catch2)
  set(CATCH_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/third_party/Catch2/CMake)
  # Unit Tests
  add_subdirectory(${CMAKE_SOURCE_DIR}/unit_test)
endif()
