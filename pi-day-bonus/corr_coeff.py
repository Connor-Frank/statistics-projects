import math


def correlation_coefficient(x, y):
    n = len(x)
    sum_x = sum_y = sum_xy = square_sum_x = square_sum_y = 0

    for i in range(0, n, 1):
        sum_x += x[i]
        sum_y += y[i]
        sum_xy += x[i] * y[i]
        square_sum_x += x[i] * x[i]
        square_sum_y += y[i] * y[i]

    return float(n * sum_xy - sum_x * sum_y) / float(math.sqrt((n * square_sum_x -
                                                                sum_x ** 2) * (n * square_sum_y -
                                                                               sum_y ** 2)))
