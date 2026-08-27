class Solution:
    def isPalindromeWithCast(self, x: int) -> bool:
        # num = str(x)
        # r_num = num[::-1]
        # if (num == r_num):
        #     return True
        # else:
        #     return False
        num = str(x)

        for i in range(len(num)):
            if num[i] != num[len(num) - 1 - i]:
                return False
            
        return True

    def isPalindromeWithoutCast(self, x: int) -> bool:
        return False
    
init = Solution()
print(init.isPalindromeWithCast(101))