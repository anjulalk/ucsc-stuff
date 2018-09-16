def main():
    print("Sum of the first n integers:")
    n = int(input("n = "))
    print("Sum =", sum_n(n))

def sum_n(n):
    if n == 1:
        return 1

    return n + sum_n(n - 1)

if __name__ == "__main__":
    main()
