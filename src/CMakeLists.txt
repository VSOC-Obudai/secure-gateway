add_executable(secure-gateway)

target_sources(secure-gateway
  PRIVATE
  __getchar.c
  __putchar.c
  app.c
  app.h
  assert.c
  assert.h
  can.c
  can.h
  config.h
  isr_config.h
  led.c
  led.h
  serial.c
  serial.h
  spinlock.c
  spinlock.h
  timer.c
  timer.h
  Cpu0_Main.c
  Cpu1_Main.c
  Cpu2_Main.c
)

target_include_directories(secure-gateway
  PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_link_libraries(secure-gateway infineon)

target_link_bin_output(secure-gateway)
target_link_hex_output(secure-gateway)
target_link_siz_output(secure-gateway)
target_link_dis_output(secure-gateway)
target_link_map_output(secure-gateway)
