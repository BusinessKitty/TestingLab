#include "pch.h"

class LoadDataTests_Array : public ::testing::TestWithParam<tuple<Matrix, double**, Matrix>> {

};
TEST_P(LoadDataTests_Array, CheckLoadData)
{
	Matrix A = get<0>(GetParam());
	double** data = get<1>(GetParam());
	Matrix expected_result = get<2>(GetParam());
	A.load_data(data);
	ASSERT_TRUE(A == expected_result);
}

INSTANTIATE_TEST_CASE_P(LoadDataTest_Array, LoadDataTests_Array,
	::testing::Values(
		make_tuple(
			Matrix(2, 3, vector<double>({ 3,5,10,1,2,15 })),
			,
			Matrix(2, 3, vector<double>({ 5,10,8,5,-2,20 }))
		),
		make_tuple(
			Matrix(3, 2, vector<double>({ 1,5,4,8,5,2 })),
			,
			Matrix(3, 2, vector<double>({ 3,10,10,18,12,14 }))
		),
		make_tuple(
			Matrix(2, vector<double>({ 1,2,3,4 })),
			,
			Matrix(2, 5.0)
		),
		make_tuple(
			Matrix(1, 2.0),
		Matrix(1, -2.0),
			Matrix(1, 0.0)
		),
		make_tuple(
			Matrix(1, 0.5),
			Matrix(1, -0.5),
			Matrix(1, 0.0)
		),
		make_tuple(
			Matrix(2, vector<double>({ -0.2,  0.5,  2.0,  1.0 })),
			Matrix(2, vector<double>({ 0.2, -0.5, -2.0, -1.0 })),
			Matrix(2, 0.0)
		)
	)
);
