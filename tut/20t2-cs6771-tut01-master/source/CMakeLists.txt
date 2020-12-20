cxx_executable(
   TARGET cat
   FILENAME "cat.cpp"
)

cxx_executable(
   TARGET add_numbers
   FILENAME "add_numbers.cpp"
)

cxx_library(
   TARGET sort3
   FILENAME "sort3.cpp"
   LINK range-v3
)
