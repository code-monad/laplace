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

project(LaplaceUnit)

# MIME test
add_executable(mime_test ${CMAKE_CURRENT_SOURCE_DIR}/src/mime_test.cc)
target_include_directories(mime_test PUBLIC ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/third_party/Catch2/single_include)
target_link_libraries(mime_test laplace_net pthread Catch2::Catch2)

# URI test
add_executable(uri_test ${CMAKE_CURRENT_SOURCE_DIR}/src/uri_test.cc)
target_include_directories(uri_test PUBLIC ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/third_party/Catch2/single_include)
target_link_libraries(uri_test laplace_net pthread Catch2::Catch2)
