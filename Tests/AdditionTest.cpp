#include "pch.h"

class AdditionTests : public ::testing::TestWithParam<tuple<Matrix, Matrix, Matrix>> {

};
TEST_P(AdditionTests, CheckAddition)
{
	Matrix A = get<0>(GetParam());
	Matrix B = get<1>(GetParam());
	Matrix expected_result = get<2>(GetParam());
	A = A + B;
	for (int i = 0; i < A.rows; i++) {
		for (int j = 0; j < A.columns; j++) {
			EXPECT_EQ(A(i, j), expected_result(i, j)) <<" wiersz = "<< i <<" kolumna = "<< j ;
		}
	}
}

INSTANTIATE_TEST_CASE_P(AdditionTest, AdditionTests,
	::testing::Values(
		//0
		make_tuple(
			Matrix(2, 3, vector<double>({ 3,5,10,1,2,15 })),
			Matrix(2, 3, vector<double>({ 2,5,-2,4,-4,5 })),
			Matrix(2, 3, vector<double>({ 5,10,8,5,-2,20 }))
		),
		//1
		make_tuple(
			Matrix(3, 2, vector<double>({ 1,5,4,8,5,2 })),
			Matrix(3, 2, vector<double>({ 2,5,6,10,7,12 })),
			Matrix(3, 2, vector<double>({ 3,10,10,18,12,14 }))
		),
		//2
		make_tuple(
			Matrix(2, vector<double>({ 1,2,3,4 })), 
			Matrix(2, vector<double>({ 4,3,2,1 })), 
			Matrix(2,5.0)
		),
		//3
		make_tuple(
			Matrix(1, 2.0), 
			Matrix(1, -2.0), 
			Matrix(1, 0.0)
		),
		//4
		make_tuple(
			Matrix(1, 0.5),
			Matrix(1, -0.5),
			Matrix(1, 0.0)
		),
		//5
		make_tuple(
			Matrix(2, vector<double>({ -0.2,  0.5,  2.0,  1.0 })),
			Matrix(2, vector<double>({  0.2, -0.5, -2.0, -1.0 })),
			Matrix(2, 0.0)
		),
		//6
		make_tuple(
			Matrix(2, 0.3),
			Matrix(2, 0.2),
			Matrix(2, 0.5)
		),
		//7
		make_tuple(
			Matrix(2,3, 0.1),
			Matrix(2,3, 0.1),
			Matrix(2,3, 0.2)
		),
		make_tuple(
			Matrix(2, 0.1),
			Matrix(2, -0.1),
			Matrix(2, 0.0)
		),
		make_tuple(
			Matrix(2, 3, 1.1),
			Matrix(2, 3, 1.1),
			Matrix(2, 3, 2.2)
		)
	)
);
