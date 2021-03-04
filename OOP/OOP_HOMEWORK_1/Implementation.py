def create_polynomial_matrix(number_of_rows: int, number_of_cols: int) -> list:
    """
    This function asks the `user` for `input` and stores that `input` in a matrix that is returned at the end.
    The `input` consists in coefficients for each power of `X` from every polynomial. The user can also choose how many
    coefficients should be stored for every polynomial by following the `directions` printed in the prompt.

    :param number_of_rows: The number of rows
    :param number_of_cols: The number of columns
    :return: matrix with desired dimensions, polynomials and coefficients
    """
    print("Starting to create a matrix...")
    print("We are going to need you to insert {} polynomials".format(number_of_cols * number_of_rows))
    print("For each polynomial you need to insert coefficients for as many powers of X as you \n"
          "like (starting from 0 of course; first is X^0, then X^1 and so on)")
    print('When you are ready to move on to the next polynomial, just type anything that isn\'t a \n'
          'number (ex.."next", "n", "stop here" "why am I doing this" etc..) ')
    print("Press ENTER to start!")
    input()
    print("The first polynomial:")
    matrix = []  # declaring the matrix that will be returned
    for i in range(number_of_rows):
        matrix.append([])  # adding empty lists to signal that we are making multidimensional lists
        for j in range(number_of_cols):
            matrix[i].append([])  # same as line 22 but for the third dimension
            counter = 0  # stores the current power of X in order to help with user input
            while True:
                coefficient = input("X^{}: ".format(counter))  # getting input from the user
                counter += 1  # incrementing the power of x
                try:  # adding the user input to the matrix if it's valid numerical input (no letters or characters)
                    matrix[i][j].append(float(coefficient))
                except ValueError:  # if the input is not valid we signal that we move to the next polynomial
                    # we test to see if we have reached the end polynomial in order to skip the "Moving.." message
                    if i * number_of_cols + j + 2 != number_of_cols * number_of_rows + 1:
                        print("Moving to polynomial number {}:".format(i * number_of_cols + j + 2))
                    break
    print("The matrix is complete!")
    return matrix  # returning the newly created matrix


def print_polynomial_matrix(matrix: list) -> None:
    """
    This function prints the polynomial matrix to the console in a format that is easy to follow and understand.
    Since three-dimensional matrices are hard to visualise on a two-dimensional console, the output will distort the
    matrix in order to make it easier to navigate through it.

    :param matrix: The polynomial matrix that needs to be printed
    :return: None
    """
    if matrix is None:  # testing for empty matrices (they might result from the misuse of the other functions)
        print("ERROR: Expected '3d list' but instead got 'None'. Please check if your argument is valid")
        return
    print("#" * 80)  # making the output easier to follow
    for i in range(len(matrix)):
        print("Line {}".format(i + 1))  # declaring the line we are currently on
        for j in range(len(matrix[0])):
            print("\tColumn {}".format(j + 1))  # declaring the column we are currently on
            print("\t\t", end='')  # helps with the formatting of the output
            for k in range(len(matrix[i][j])):
                if k != len(matrix[i][j]) - 1:  # testing for the end of the polynomial
                    # getting rid of excess decimals via the inbuilt round() function
                    print("{}X^{} + ".format(round(matrix[i][j][k], 2), k), end='')
                else:
                    # same output but without the "+" at the end (only for the last element in the polynomial)
                    print("{}X^{}".format(round(matrix[i][j][k], 2), k), end='')

            print()  # \n
        print()  # \n
    print()  # \n
    print("#" * 80)  # same as line 52


def add_two_polynomial_matrices(matrix_1: list, matrix_2: list):
    """
    This functions expects two `matrices` and returns a `matrix` representing their `sum`. It doesn't get
    any easier than this! If the matrices have different sizes then the function prints an `ERROR` message
    and returns `None`.

    :param matrix_1: first matrix
    :param matrix_2: second matrix
    :return: matrix representing the sum of the arguments
    """
    if len(matrix_1) != len(matrix_2) or len(matrix_1[0]) != len(matrix_2[0]):  # checking for size equality
        print("ERROR: Cannot add two matrices that have different sizes...")  # ERROR message if conditions are
        return                                                                # not met
    matrix = []  # declaring the matrix that will be returned
    for i in range(len(matrix_1)):
        matrix.append([])  # adding empty lists to signal that we are making multidimensional lists
        for j in range(len(matrix_1[0])):
            matrix[i].append([])  # same as line 87 but for the third dimension
            # storing the length of the shortest polynomial via the inbuilt min() function
            minimum_length = min(len(matrix_1[i][j]), len(matrix_2[i][j]))
            # adding the coefficients for every power of X up until the shortest one ends and appending the sum
            for k in range(minimum_length):
                matrix[i][j].append(matrix_1[i][j][k] + matrix_2[i][j][k])
            # figuring out which polynomial is longer and appending all of the coefficients that are left
            if len(matrix_1[i][j]) > len(matrix_2[i][j]):
                # using the inbuilt function range() to iterate through the coefficients that are left
                for k in range(len(matrix_2[i][j]), len(matrix_1[i][j])):
                    matrix[i][j].append(matrix_1[i][j][k])
            else:
                # I intentionally checked both for '>' and '<' in order to rule out the case in which they are equal
                if len(matrix_1[i][j]) < len(matrix_2[i][j]):
                    # using the inbuilt function range() to iterate through the coefficients that are left
                    for k in range(len(matrix_1[i][j]), len(matrix_2[i][j])):
                        matrix[i][j].append(matrix_2[i][j][k])
    return matrix  # returning a matrix representing the sum of the arguments


def evaluate_polynomial_matrix_in_point(matrix: list, point: float) -> list:
    """
    This function returns a normal two-dimensional matrix that contains the evaluation of every polynomial
    in a specified `point`. The matrix is also printed to the `console`.

    :param matrix: the polynomial matrix that needs to be evaluated
    :param point: a real number representing the point of evaluation (the value of 'X')
    :return: normal two-dimensional matrix
    """
    return_matrix = []  # declaring the matrix that will be returned
    for i in range(len(matrix)):
        return_matrix.append([])  # adding empty lists to signal that we are making multidimensional lists
        for j in range(len(matrix[0])):
            return_matrix[i].append([])
            sum_of_polynomial = 0  # the sum of every power of 'X' multiplied by its coefficient
            for k in range(len(matrix[i][j])):
                sum_of_polynomial += matrix[i][j][k] * (point ** k)  # updating the sum for every power of 'X'
            return_matrix[i][j] = sum_of_polynomial  # storing the sum in its specific place in the return_matrix
    print("#" * 80)
    print("The equivalent matrix evaluated at the given point {} is:".format(point))
    print_normal_matrix(return_matrix)  # calling an internal function to print the matrix to the console
    print("#" * 80)
    return return_matrix  # returning the matrix containing the appropriate evaluations


def multiply_two_polynomial_matrices(matrix_1: list, matrix_2: list):
    """
    This function expects two `matrices` that `CAN` be multiplied and returns a `matrix` that contains
    the `result`. If the matrices don't respect the conditions imposed by the rules of multiplication, the function
    prints an `ERROR` message to the `console` and returns `None`.

    :param matrix_1: The first matrix
    :param matrix_2: The second matrix
    :return: A matrix that represents the multiplication of the two arguments
    """
    if len(matrix_1[0]) is not len(matrix_2):  # testing for the matrix multiplication condition
        print("ERROR: The format of the matrices doesn't allow for multiplication")
        return
    return_matrix = []  # declaring the matrix that will be returned
    for i in range(len(matrix_1)):  # iterating through the rows of the first matrix
        return_matrix.append([])  # adding empty lists to signal that we are making multidimensional lists
        for j in range(len(matrix_2[0])):  # iterating through the columns of the second matrix
            return_matrix[i].append([])   # same as line 149 but for the third dimension
            for k in range(len(matrix_2)):  # iterating through the rows of the second matrix
                # storing the produce of the adequate polynomials in 'produce' via calling an internal function
                produce = multiply_two_polynomials(matrix_1[i][k], matrix_2[k][j])
                # adding the current produce to the sum of polynomials stored in the adequate position of the
                # return_matrix via calling an internal function
                return_matrix[i][j] = add_two_polynomials(return_matrix[i][j], produce)
    return return_matrix  # returning the matrix that represents the produce of the arguments


# The functions implemented below this line are internal functions. The main module doesn't have access to them.


def print_normal_matrix(matrix: list) -> None:
    """
    This function expects a normal two-dimensional matrix and displays it to the `console`.
    This function does not return anything

    :param matrix: normal two-dimensional matrix
    :return: None
    """
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            # using the inbuilt function round() to get rid of excessive decimals that could ruin the format
            print(round(matrix[i][j], 2), " ", end='')
        print()  # \n


def multiply_two_polynomials(polynomial_1: list, polynomial_2: list) -> list:
    """
    This function expects two `polynomials` and returns a `polynomial` that contains
    their `produce`.

    :param polynomial_1: First polynomial
    :param polynomial_2: Second polynomial
    :return: A polynomial representing the produce of the two polynomials
    """
    # initializing a list that is big enough to store the coefficients for every power of 'X'
    return_polynomial = [0] * (len(polynomial_1) + len(polynomial_2) - 1)
    for i in range(len(polynomial_1)):
        for j in range(len(polynomial_2)):
            # updating the coefficient to the appropriate value
            return_polynomial[i + j] += polynomial_1[i] * polynomial_2[j]
    return return_polynomial  # returning a polynomial that represents the produce of the two arguments


def add_two_polynomials(polynomial_1: list, polynomial_2: list) -> list:
    """
    This function expects two `polynomials` and returns a `polynomial` that contains
    their `sum`.

    :param polynomial_1: First polynomial
    :param polynomial_2: Second polynomial
    :return: A polynomial representing the sum of the two polynomials
    """
    # declaring the polynomial that will be returned (the sum)
    return_polynomial = []
    # storing the length of the shortest polynomial via the inbuilt min() function
    minimum_length = min(len(polynomial_1), len(polynomial_2))
    # adding the coefficients for every power of X up until the shortest one ends and appending the sum
    for k in range(minimum_length):
        return_polynomial.append(polynomial_1[k] + polynomial_2[k])
    # figuring out which polynomial is longer and appending all of the coefficients that are left
    if len(polynomial_1) > len(polynomial_2):
        # using the inbuilt function range() to iterate through the coefficients that are left
        for k in range(len(polynomial_2), len(polynomial_1)):
            return_polynomial.append(polynomial_1[k])
    else:
        # I intentionally checked both for '>' and '<' in order to rule out the case in which they are equal
        if len(polynomial_1) < len(polynomial_2):
            # using the inbuilt function range() to iterate through the coefficients that are left
            for k in range(len(polynomial_1), len(polynomial_2)):
                return_polynomial.append(polynomial_2[k])
    return return_polynomial # returning a polynomial representing the sum of the two arguments
