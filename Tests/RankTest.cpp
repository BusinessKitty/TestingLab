#include "pch.h"

class RankTests : public ::testing::TestWithParam<pair<Matrix, int>> {

};

TEST_P(RankTests, CheckRank)
{
	Matrix A = get<0>(GetParam());
	int expected_result = get<1>(GetParam());
	int rank = A.rank();
	ASSERT_EQ(rank, expected_result);
}

INSTANTIATE_TEST_CASE_P(
	RankTest,
	RankTests,
	::testing::Values(
		make_pair(Matrix(4, 0.0), 0.0),																//1
		make_pair(Matrix(4, vector<double>({ 2,8,3,-4,1,4,1,-2,5,20,0,-10,-3,-12,-2,6 })), 2.0),	//2
		make_pair(Matrix(2, vector<double>({ 1,0,0,1 })), 2.0),										//3
		make_pair(Matrix(1, 1), 1.0)																//4
	)
);