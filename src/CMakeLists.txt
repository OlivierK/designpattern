INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_PATH})
LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
ADD_EXECUTABLE(test1 test.cpp designp.cpp noeud.cpp feuille.cpp composant.cpp variable.cpp expression.cpp)
ADD_TEST(designp_test test1)
ADD_LIBRARY(designp SHARED designp.cpp designp.hpp wrapper.cpp)
TARGET_LINK_LIBRARIES(test1 ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${PYTHON_LIBRARIES})

INSTALL(TARGETS designp DESTINATION lib/python${PYTHON_VERSION}/lib-dynload)