#include "gtest/gtest.h"

#include "Decimator.h"

class DecimatorTest : public ::testing::Test
{
	protected:
		virtual void SetUp( )
		{
		}

		virtual void TearDown( )
		{
		}
};

TEST_F( DecimatorTest, Compiles )
{
	EXPECT_EQ( 0, 0 );
}
