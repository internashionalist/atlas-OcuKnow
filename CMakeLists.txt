cmake_minimum_required(VERSION 3.16)
project(OcuKnow)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Multimedia)

qt6_add_resources(OcuKnowResources resources.qrc)

qt_add_executable(OcuKnow)

target_sources(OcuKnow
	PRIVATE
		main.cpp
		UI/introwidget.cpp
		UI/introwidget.h
		${OcuKnowResources}
)

set_property(SOURCE UI/introwidget.h PROPERTY SKIP_AUTOMOC OFF)

target_link_libraries(OcuKnow
	PRIVATE
		Qt6::Core
		Qt6::Gui
		Qt6::Widgets
		Qt6::Multimedia
)

qt6_wrap_cpp(MOC_SRCS UI/introwidget.h)
target_sources(OcuKnow PRIVATE ${MOC_SRCS})
