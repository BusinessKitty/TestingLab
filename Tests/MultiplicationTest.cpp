#include "pch.h"

class MultiplicationByIntTests : public ::testing::TestWithParam<tuple<Matrix, int, Matrix>> {

};

TEST_P(MultiplicationByIntTests, CheckIntMultiplication)
{
	Matrix A = get<0>(GetParam());
	int multiplier = get<1>(GetParam());
	Matrix expected_result = get<2>(GetParam());
	A = A * multiplier;
	for (int i = 0; i < A.rows; i++) {
		for (int j = 0; j < A.columns; j++) {
			EXPECT_EQ(A(i, j), expected_result(i, j)) << " wiersz = " << i << " kolumna = " << j;;
		}
	}
}

INSTANTIATE_TEST_CASE_P(
	MultiplicationByIntTest, 
	MultiplicationByIntTests,
	::testing::Values(
		make_tuple(Matrix(2, 1.0),    2, Matrix(2, 2.0)),		//0
		make_tuple(Matrix(5, 3, 1.0), 2, Matrix(5, 3, 2.0)),	//1
		make_tuple(Matrix(5, 1.0),	 10, Matrix(5, 10.0)),		//2
		make_tuple(Matrix(5, 1.0),    0, Matrix(5, 0.0)),		//3
		make_tuple(Matrix(5, 1.0),   -1, Matrix(5, -1.0)),		//4
		make_tuple(Matrix(2, 1.0),    4, Matrix(2, 4.0)),		//5
		make_tuple(Matrix(2, 2.0),    2, Matrix(2, 4.0)),		//6
		make_tuple(Matrix(2, 3.0),    2, Matrix(2, 6.0)),		//7
		make_tuple(Matrix(4, 1.0),    1, Matrix(4, 1.0)),		//8
		make_tuple(Matrix(2, 2.0),    5, Matrix(2, 10.0)),		//9
		make_tuple(Matrix(3, 0.5),   13, Matrix(3, 6.5)),		//10
		make_tuple(Matrix(2, 2.0),   -5, Matrix(2, -10.0)),		//11
		make_tuple(Matrix(1, 0.5),    2, Matrix(1, 1.0))		//12
	)
);

class MultiplicationByMatrixTests : public ::testing::TestWithParam<tuple<Matrix, Matrix, Matrix>> {

};

TEST_P(MultiplicationByMatrixTests, CheckMatrixMultiplication)
{
	Matrix A = get<0>(GetParam());
	Matrix B = get<1>(GetParam());
	Matrix expected_result = get<2>(GetParam());
	A = A * B;
	for (int i = 0; i < A.rows; i++) {
		for (int j = 0; j < A.columns; j++) {
			EXPECT_EQ(A(i, j), expected_result(i, j)) << " wiersz = " << i << " kolumna = " << j;;
		}
	}
}

INSTANTIATE_TEST_CASE_P(
	MultiplicationByMatrixTest,
	MultiplicationByMatrixTests,
	::testing::Values(
		//0
		make_tuple(
			Matrix(3, 1.0),
			Matrix(3, 2.0),
			Matrix(3, 6.0)
		),
		//1
		make_tuple(
			Matrix(3, 2.0),
			Matrix(3),
			Matrix(3)
		),
		//2
		make_tuple(
			Matrix(2,3, 1.0),
			Matrix(3,2, 2.0),
			Matrix(2,6.0)
		),
		//3
		make_tuple(
			Matrix(3,2, 1.0),
			Matrix(2,3, 2.0),
			Matrix(3, 4.0)
		),
		//4
		make_tuple(
			Matrix(1, 2.0),
			Matrix(1, -2.0),
			Matrix(1, -4.0)
		),
		//5
		make_tuple(
			Matrix(3, vector<double>({ -1,-2,3,0,2,-1,-1,3,0 })),
			Matrix(3, vector<double>({ 1,5,1,2,1,2,3,2,3 })),
			Matrix(3, vector<double>({ 4,-1,4,1,0,1,5,-2,5 }))
		),
		//6
		make_tuple(
			Matrix(2, vector<double>({ 0.5,0.75,0.5,0.75 })),
			Matrix(2, vector<double>({ 0.75,0.5,0.5,0.75 })),
			Matrix(2, vector<double>({ 0.75,0.8125,0.75,0.8125 }))
		),
		//7
		make_tuple(
			Matrix(2, 1.5),
			Matrix(2, 2.5),
			Matrix(2, 7.5)
		),
		//8
		make_tuple(
			Matrix(2, 1.5),
			Matrix(2, -2.5),
			Matrix(2, -7.5)
		)
	)
);
