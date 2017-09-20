#include "gtest/gtest.h"
#include "Payroll.h"

TEST(payrollTest, getOTHours_when_hours_less_than_40){
    EXPECT_EQ(0, getOTHours(30));
}

TEST(ayrollTest, getOTHours_when_hours_greater_than_40){
    EXPECT_EQ(10, getOTHours(50));
}
