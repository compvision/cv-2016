find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS system thread)

#add_executable(cv_a1 cv_a1.cpp Target.cpp TargetDetector.cpp VideoDevice.cpp)
#target_link_libraries(cv_a1 ${OpenCV_LIBS})

#add_executable(cv_a2 cv_a2.cpp TargetProcessor.cpp Target.cpp)
#target_link_libraries(cv_a2 ${OpenCV_LIBS})

#add_executable(cv_b cv_b.cpp NetworkController.cpp AppConfig.cpp CmdLineInterface.cpp GUIManager.cpp)
#target_link_libraries(cv_b ${OpenCV_LIBS} ${Boost_LIBRARIES})

add_executable(cv-2016 cv-2016.cpp Target.cpp TargetDetector.cpp TargetProcessor.cpp NetworkController.cpp VideoDevice.cpp GUIManager.cpp CmdLineInterface.cpp AppConfig.cpp)
target_link_libraries(cv-2016 ${OpenCV_LIBS} ${Boost_LIBRARIES})
