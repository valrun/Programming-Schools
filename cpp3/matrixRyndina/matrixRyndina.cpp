#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>
#include "Matrix.h"

struct Matrix {
	int row = 0, column = 0;
	double** arr;

	void create(int row, int column) {
		this->row = row;
		this->column = column;

		arr = (double**) malloc(row * sizeof(double*));
		for (int i = 0; i < row; i++) {
			arr[i] = (double*) calloc(column, sizeof(double));
		}

	}

	void create(Matrix* other) {
		this->row = other->row;
		this->column = other->column;

		arr = (double**) malloc(row * sizeof(double*));
		for (int i = 0; i < row; i++) {
			arr[i] = (double*) calloc(column, sizeof(double));

			for (int j = 0; j < column; j++) {
				arr[i][j] = other->arr[i][j];
			}
		}
	}

	void init() {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				arr[i][j] = (rand() % 100 + 1) / 10.0;
			}
		}
	}

	void print() {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				printf("%6.2f   ", arr[i][j]);
			}
			printf("\n");
		}
	}

	Matrix* add(Matrix* other) {
		assert(other->row == row && other->column == column);

		Matrix* tmp = (Matrix*) malloc(sizeof(Matrix));
		tmp->create(other);

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				tmp->arr[i][j] += arr[i][j];
			}
		}
		return tmp;
	}

	Matrix* multiplyByScalar(double k) {
		Matrix* tmp = (Matrix*) malloc(sizeof(Matrix));
		tmp->create(this);

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				tmp->arr[i][j] *= k;
			}
		}
		return tmp;
	}

	Matrix* multiply(Matrix* other) {
		assert(other->column == row);

		Matrix* tmp = (Matrix*) malloc(sizeof(Matrix));
		tmp->create(row, other->column);

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < other->column; j++) {
				tmp->arr[i][j] = 0;

				for (int r = 0; r < other->row; r++) {
					tmp->arr[i][j] += arr[i][r] * other->arr[r][j];
				}
			}
		}
		return tmp;
	}

	Matrix* transpone() {
		Matrix* tmp = (Matrix*) malloc(sizeof(Matrix));
		tmp->create(column, row);

		for (int i = 0; i < tmp->row; i++) {
			for (int j = 0; j < tmp->column; j++) {
				tmp->arr[i][j] = arr[j][i];
			}
		}
		return tmp;
	}

	double determinant() {
		assert(column == row);
		if (column == 1) {
			return arr[0][0];
		}

		if (column == 2) {
			return arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
		}

		double sum = 0.0;
		for (int k = 0; k < column; k++) {
			Matrix tmp;
			tmp.create(row - 1, column - 1);

			for (int i = 0; i < tmp.row; i++) {
				for (int j = 0; j < tmp.column; j++) {
					tmp.arr[i][j] = arr[i + 1][j + (j < k ? 0 : 1)];
				}
			}

			sum += arr[0][k] * (k % 2 == 0 ? 1 : -1) * tmp.determinant();
			tmp.destruct();
		}
		return sum;
	}

	void destruct() {
		for (int i = 0; i < row; i++) {
			free(arr[i]);
		}
		free(arr);
		arr = NULL;
	}
};

int main() {
	srand(time(NULL));

	//=====================================================
	printf(" m1\n");

	Matrix* m1 = (Matrix*) malloc(sizeof(Matrix));
	m1->create(2, 3);

	int tmp = 1;
	for (int i = 0; i < m1->row; i++) {
		for (int j = 0; j < m1->column; j++) {
			m1->arr[i][j] = tmp;
			tmp++;
		}
	}

	m1->print();

	//=====================================================
	printf("\n transpone m1\n");

	Matrix* trm1 = (Matrix*) malloc(sizeof(Matrix));
	trm1->create(m1->transpone());

	trm1->print();

	//=====================================================
	printf("\n m2\n");

	Matrix* m2 = (Matrix*) malloc(sizeof(Matrix));
	m2->create(3, 2);

	tmp = 1;
	for (int i = 0; i < m2->row; i++) {
		for (int j = 0; j < m2->column; j++) {
			m2->arr[i][j] = tmp;
			tmp++;
		}
	}

	m2->print();

	//=====================================================
	printf("\n m1 * m2\n");

	Matrix* tm2 = (Matrix*) malloc(sizeof(Matrix));
	tm2 = m1->multiply(m2);

	tm2->print();

	//=====================================================
	printf("\n transpone m1 + m2\n");

	Matrix* tm3 = (Matrix*) malloc(sizeof(Matrix));
	tm3 = m2->add(trm1);

	tm3->print();

	//=====================================================
	printf("\n m3 random\n");

	Matrix* m3 = (Matrix*) malloc(sizeof(Matrix));
	m3->create(3, 3);
	m3->random();

	m3->print();

	//=====================================================
	printf("\n m3 determinant\n");
	printf("%6.2f\n", m3->determinant());

	//=====================================================
	
	m1->destruct();
	trm1->destruct();
	m2->destruct();
	m3->destruct();
	tm2->destruct();
	tm3->destruct();

	free(m1);
	free(trm1);
	free(m2);
	free(m3);
	free(tm2);
	free(tm3);

	return 0;
}
