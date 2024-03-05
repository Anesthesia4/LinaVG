#-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
# This file is a part of: LinaVG
# https://github.com/inanevin/LinaVG
# 
# Author: Inan Evin
# http://www.inanevin.com
# 
# The 2-Clause BSD License
# 
# Copyright (c) [2022-] Inan Evin
# 
# Redistribution and use in source and binary forms, with or without modification,
# are permitted provided that the following conditions are met:
# 
#    1. Redistributions of source code must retain the above copyright notice, this
#       list of conditions and the following disclaimer.
# 
#    2. Redistributions in binary form must reproduce the above copyright notice,
#       this list of conditions and the following disclaimer in the documentation
#       and/or other materials provided with the distribution.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
# IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
# INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
# OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
# OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
# OF THE POSSIBILITY OF SUCH DAMAGE.
#-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

add_subdirectory(Dependencies/glad)
add_subdirectory(Dependencies/glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC glad)
set_property(TARGET glad PROPERTY FOLDER ${LINAVG_FOLDER_BASE}/Dependencies)
set_property(TARGET glfw PROPERTY FOLDER ${LINAVG_FOLDER_BASE}/Dependencies)
message("LinaVGExample -> glad has been linked.")
message("LinaVGExample -> glfw has been linked.")
