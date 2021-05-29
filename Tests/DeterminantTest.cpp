#include "pch.h"

class DeterminantTests : public ::testing::TestWithParam<pair<Matrix, double>> {

};

TEST_P(DeterminantTests, CheckDeterminant)
{
	Matrix A = get<0>(GetParam());
	double expected_result = get<1>(GetParam());
	double determinant = A.determinant();
	ASSERT_EQ(determinant,expected_result);
}

INSTANTIATE_TEST_CASE_P(
	DeterminantTest,
	DeterminantTests,
	::testing::Values(
		make_pair(Matrix(3, 1.0), 0.0),
		make_pair(Matrix(3, 0.0), 0.0),
		make_pair(Matrix(3, vector<double>({1,0,0,0,1,0,0,0,1})), 1.0),
		make_pair(Matrix(3, vector<double>({ -1,0,0,0,-1,0,0,0,-1 })), -1.0),
		make_pair(Matrix(2, vector<double>({ 1,2,3,4 })), -2.0),
		make_pair(Matrix(2, vector<double>({ -3,5,-6,7 })), 9.0),
		make_pair(Matrix(4, vector<double>({ 1,-1,2,4,0,1,0,3,5,7,-2,0,2,0,-1,4 })), -160.0),
		make_pair(Matrix(1, 1.0), 1.0),
		make_pair(Matrix(1, -6.0), -6.0)
	)
);