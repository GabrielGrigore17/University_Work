from Implementation import create_polynomial_matrix, evaluate_polynomial_matrix_in_point, \
    add_two_polynomial_matrices, print_polynomial_matrix, multiply_two_polynomial_matrices

test_matrix_1 = [[[2.0, 1.3, -4.6, 9.0, 5.0], [12.0, 2.453, 2.3, -0.12],
                  [5.4, 3.4, 3.0, 5.0, 1.0], [23.0, 4.0, 2.0]],
                 [[23.0, 43.0, 3.0, 2.0], [1.0, 2.0, 3.0, 4.0, 5.0],
                  [3.5, -4.0, -3.4, 2.0], [3.0, 2.0, 4.0, 1.0, -4.0]],
                 [[6.0, -4.0, 3.0], [2.0, 1.0, 2.0, 3.0], [3.0, 3.4],
                  [-4.3, -4.5, -6.0]],
                 [[11.0, 22.0, 33.0], [1.0, 5.0, 3.4, 2.324234],
                  [1.0, 2.0, 1.0, 2.0], [3.0, 3.3, 3.33]]]

test_matrix_2 = [[[2.0, 12.0, 3.4, 2.0], [-2.0, -3.0, 2.3456, 5.43, 2.0, 5.0],
                  [3.0, -3.0, 3.3, -3.3, 3.3333], [0.0, 21.0, 0.0, 0.0, 3.0]],
                 [[12.0, 0.0, 2.0], [2.3, 3.2, -2.3, -3.0, 0.3, 0.0, 2.0],
                  [6.0, 7.0, 5.0, 8.0], [12.0, 23.0, 34.0, 45.0, -2.0]],
                 [[1.0, 0.0, 2.0, 0.0, 3.0, 0.0, 4.0], [23.0, 0.0, 11.0],
                  [6.0, 5.0], [5.0, 4.0, 3.0, 0.0, 4.0]],
                 [[5.0, 0.0, 8.0], [-4.5555, -0.54, 0.0, 3.0],
                  [1.0, 2.0, 3.0, 0.4], [6.5, 5.4, 4.3]]]

test_matrix_easy_1 = [[[2.0, 3.0, 4.0], [4.0, 3.0]], [[5.0, 4.0, 8.0], [4.0, 3.0, 2.0, 1.0]]]
test_matrix_easy_2 = [[[-2.0, 3.0], [4.0, 3.0, 2.0, 1.0]], [[-5.0, -3.0], [1.0, 3.0, 2.0]]]

# CREATING A POLYNOMIAL MATRIX TEST:
# test_matrix = create_polynomial_matrix(2, 2)
# print("\nCREATING A POLYNOMIAL MATRIX TEST:\n")
# print_polynomial_matrix(test_matrix)

# the lines above test the "create_polynomial_matrix" function but it expects input
# so I decided to leave it out of the way in order to make the testing process of the other functions easier
# it can be un-commented at any time in order to test its implementation
# the rest of the functions will be tested using the already written matrices in order to make the process easier

# PRINTING A POLYNOMIAL MATRIX TEST:
print("\nPRINTING A POLYNOMIAL MATRIX TEST:\n")
print_polynomial_matrix(test_matrix_1)
# print_polynomial_matrix(test_matrix_easy_1)

# ADDING TWO POLYNOMIAL MATRICES TEST:
print("\nADDING TWO POLYNOMIAL MATRICES TEST:\n")
matrices_sum = add_two_polynomial_matrices(test_matrix_1, test_matrix_2)
print_polynomial_matrix(matrices_sum)
# matrices_sum_easy = add_two_polynomial_matrices(test_matrix_easy_1, test_matrix_easy_2)
# print_polynomial_matrix(matrices_sum_easy)

# MULTIPLYING TWO POLYNOMIAL MATRICES TEST:
print("\nMULTIPLYING TWO POLYNOMIAL MATRICES TEST:\n")
matrices_produce = multiply_two_polynomial_matrices(test_matrix_1, test_matrix_2)
print_polynomial_matrix(matrices_produce)
# matrices_produce_easy = multiply_two_polynomial_matrices(test_matrix_easy_1, test_matrix_easy_2)
# print_polynomial_matrix(matrices_produce_easy)

# EVALUATING A POLYNOMIAL MATRIX AT A GIVEN POINT TEST:
print("\nEVALUATING A POLYNOMIAL MATRIX AT A GIVEN POINT TEST:\n")
evaluate_polynomial_matrix_in_point(test_matrix_1, 3.42)
# evaluate_polynomial_matrix_in_point(test_matrix_easy_1, 2)
