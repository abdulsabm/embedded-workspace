# rename the project first then run the below cmds
# cmake_minimum_required(VERSION 3.16)
# include($ENV{IDF_PATH}/tools/cmake/project.cmake)
# # Change "old_project_name" to your new name:
# project("ESP32_ST7789_I80")

# idf_component_register(SRCS "st7789_i80_display_rgb_test.c" INCLUDE_DIRS ".")
# idf_component_register(SRCS "esp32_st7789_send_text_test.c" INCLUDE_DIRS ".")
# idf_component_register(SRCS "esp32_spi_bitbang_test.c" INCLUDE_DIRS ".")
# idf_component_register(SRCS "esp32_spi_scope_display.c" INCLUDE_DIRS ".")
# idf_component_register(SRCS "esp32_spi_scope_csv.c" INCLUDE_DIRS ".")
# idf_component_register(SRCS "esp32_blinking_led.c" INCLUDE_DIRS ".")
idf_component_register(SRCS "esp32_blinking_led_using_xor.c" INCLUDE_DIRS ".")

