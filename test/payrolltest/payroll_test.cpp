#include "gtest/gtest.h"
#include "Payroll.h"

TEST(payrollTest, getOTHours_when_hours_less_than_40){
    EXPECT_EQ(0, getOTHours(30));
}

TEST(payrollTest, getOTHours_when_hours_greater_than_40){
    EXPECT_EQ(10, getOTHours(50));
}

TEST(payrollTest, makeNumber_when_sent_string_including_letters){
    EXPECT_EQ(-1, makeNumber("12dt5"));
}

TEST(payrollTest, makeNumber_when_sent_string_of_numbers_only){
    EXPECT_EQ(12345, makeNumber("12345"));
}

