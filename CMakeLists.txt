cmake_minimum_required(VERSION 3.21)
project(LambdaStory)

add_executable(c++98_03_callable_object
    c++98_03_callable_object.cpp
)

target_compile_features(c++98_03_callable_object
    PRIVATE
        cxx_std_98
)

set_target_properties(c++98_03_callable_object
    PROPERTIES 
        CXX_STANDARD 98
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
)

add_executable(c++11_lambda
    c++11_lambda.cpp
)

set_target_properties(c++11_lambda
    PROPERTIES 
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
)

add_executable(c++14_lambda
    c++14_lambda.cpp
)

set_target_properties(c++14_lambda
    PROPERTIES 
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
)

add_executable(c++17_lambda
    c++17_lambda.cpp
)

set_target_properties(c++17_lambda
    PROPERTIES 
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
)

add_executable(c++20_lambda
    c++20_lambda.cpp
)

set_target_properties(c++20_lambda
    PROPERTIES 
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
)

add_executable(c++20_lambda_test
    c++20_lambda_test.cpp
)

set_target_properties(c++20_lambda_test
    PROPERTIES 
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
)