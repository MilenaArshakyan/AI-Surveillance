# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/MultimediaLib_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/MultimediaLib_autogen.dir/ParseCache.txt"
  "MultimediaLib_autogen"
  )
endif()
