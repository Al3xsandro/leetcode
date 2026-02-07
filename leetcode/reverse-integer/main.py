class Solution:
    def reverse(self, x: int) -> int:
        is_negative = True if x < 0 else False
        x = str(abs(int(x)))

        # first: reverse 32-bit and verify if is negative
        reversed_num = int(x[::-1])
        if is_negative:
            reversed_num = reversed_num * (-1)

        # second: verify if the value is in 32-bit range
        MIN_VAL = -2147483648  # -2**31
        MAX_VAL = 2147483647  # 2**31 - 1

        if reversed_num >= MIN_VAL and reversed_num <= MAX_VAL:
            return reversed_num

        return 0


main = Solution()

x = main.reverse(123)  # output: 321
y = main.reverse(-123)  # output: -321

print(f"reverse of 123 is {x} and reverse of -123 is {y}")
