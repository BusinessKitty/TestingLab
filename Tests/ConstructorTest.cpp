#include "pch.h"

class ShapeTests : public ::testing::TestWithParam<pair<Matrix, int>> {

};

TEST_P(ShapeTests, CheckShape)
{
	int shape = get<0>(GetParam()).rows;
	int expected_result = get<1>(GetParam());
	ASSERT_EQ(shape,expected_result);
}

INSTANTIATE_TEST_CASE_P(
	ShapeTest,
	ShapeTests,
	::testing::Values(
		make_pair(Matrix(0, 0.0), 0),		//0
		make_pair(Matrix(-1, 0.0), -1),		//1
		make_pair(Matrix(-256, 0.0), -256),	//2
		make_pair(Matrix(-512, 0.0), -512),	//3
		make_pair(Matrix(-600, 0.0), -600),	//4
		make_pair(Matrix(255, 0.0), 255),	//5
		make_pair(Matrix(256, 0.0), 256),	//6
		make_pair(Matrix(512, 0.0), 512),	//7
		make_pair(Matrix(600, 0.0), 600)	//8
	)
);

class WidthHeightTests : public ::testing::TestWithParam<tuple<Matrix, int, int>> {

};

TEST_P(WidthHeightTests, CheckWidthHeight)
{
	int rows = get<0>(GetParam()).rows;
	int cols = get<0>(GetParam()).columns;
	int expected_rows = get<1>(GetParam());
	int expected_cols = get<2>(GetParam());
	EXPECT_EQ(rows,expected_rows);
	EXPECT_EQ(cols, expected_cols);
}

INSTANTIATE_TEST_CASE_P(
	WidthHeightTest,
	WidthHeightTests,
	::testing::Values(
		make_tuple(Matrix(0,1, 0.0), 0,1),			//0
		make_tuple(Matrix(-1,-2, 0.0), -1,-2),		//1
		make_tuple(Matrix(255,255, 0.0), 255,255),	//2
		make_tuple(Matrix(256,256, 0.0), 256,256),	//3
		make_tuple(Matrix(400,400, 0.0), 400,400),	//4
		make_tuple(Matrix(800,100, 0.0), 800,100),	//5
		make_tuple(Matrix(100, 800, 0.0), 100, 800)	//6
	)
);