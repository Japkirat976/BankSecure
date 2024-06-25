include_directories(${PROJECT_SOURCE_DIR}/inc)


add_executable(bank_secure bank_secure.cpp account.cpp auth.cpp customer.cpp encrypt.cpp kyc.cpp mysql_con.cpp screens.cpp transactions.cpp)

target_link_libraries(bank_secure mysqlcppconn mysqlclient)


			  