add_executable(secure-gateway)

target_sources(secure-gateway PRIVATE Cpu0_Main.c Cpu1_Main.c Cpu2_Main.c)

target_include_directories(secure-gateway PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(secure-gateway infineon-std infineon-board infineon-lwip)

target_link_bin_output(secure-gateway)
target_link_hex_output(secure-gateway)
target_link_siz_output(secure-gateway)
target_link_dis_output(secure-gateway)
target_link_map_output(secure-gateway)
