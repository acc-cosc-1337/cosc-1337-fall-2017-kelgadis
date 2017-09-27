#include "gtest/gtest.h"
#include "Payroll.h"

TEST(payrollTest, getOTHours_when_hours_less_than_40){
    EXPECT_EQ(0.0, getOTHours(30.0));
}

TEST(payrollTest, getOTHours_when_hours_greater_than_40){
    EXPECT_EQ(10.0, getOTHours(50.0));
}

TEST(payrollTest, makeNumber_when_sent_string_including_letters){
    EXPECT_EQ(-1.0, makeNumber("12dt5"));
}

TEST(payrollTest, makeNumber_when_sent_string_of_numbers_only){
    EXPECT_EQ(12345.0, makeNumber("12345"));
}

TEST(payrollTest, isInRange_when_sent_number_in_range){
    EXPECT_EQ(50.0, isInRange(50.0, 0.0, 60.0));
}

TEST(payrollTest, isInRange_when_sent_number_out_of_range){
    EXPECT_EQ(-1.0, isInRange(100.0, 0.0, 60.0));
}

TEST(payrollTest, getOTPay_when_otHours_greater_than_zero){
    EXPECT_EQ(200.0, getOTPay(20.0, 10.0));
}

TEST(payrollTest, getOTPay_when_otHours_equal_to_zero) {
    EXPECT_EQ(0.0, getOTPay(20.0, 0.0));
}
