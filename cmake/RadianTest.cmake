function(radian_test test_name)
  set(test_target test_${test_name})

  add_executable(${test_target} ${PROJECT_SOURCE_DIR}/${test_target}.c)
  target_link_libraries(${test_target} PRIVATE
    radian::radian
    unity)
  add_test(${test_target} ${test_target})
endfunction()
