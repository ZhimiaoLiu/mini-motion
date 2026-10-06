# Project-wide compiler settings.

# MSVC: read source files as UTF-8. Without this, MSVC on a Japanese/Chinese
# Windows reads files in the local code page and non-ASCII comments trigger
# warning C4819 (which /WX turns into a build error).
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

# Sanitizers are applied globally (including GoogleTest) because MSVC refuses to
# link ASan and non-ASan objects together.
if(MOTION_ENABLE_SANITIZERS)
  if(MSVC)
    add_compile_options(/fsanitize=address /Zi)
    add_link_options(/INCREMENTAL:NO /DEBUG)
  else()
    add_compile_options(-fsanitize=address,undefined -fno-sanitize-recover=undefined -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address,undefined)
  endif()
endif()

# Strict warnings for our own targets only (third-party code is left alone).
function(motion_set_warnings target)
  if(MSVC)
    target_compile_options(${target} PRIVATE /W4 /permissive-)
    if(MOTION_WARNINGS_AS_ERRORS)
      target_compile_options(${target} PRIVATE /WX)
    endif()
  else()
    target_compile_options(
      ${target}
      PRIVATE -Wall
              -Wextra
              -Wpedantic
              -Wshadow
              -Wconversion
              -Wnon-virtual-dtor
              -Wold-style-cast
              -Woverloaded-virtual)
    if(MOTION_WARNINGS_AS_ERRORS)
      target_compile_options(${target} PRIVATE -Werror)
    endif()
  endif()
endfunction()
