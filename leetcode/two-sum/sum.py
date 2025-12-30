class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        sum = 0
        for i, first in enumerate(nums):
           for j, second in enumerate(nums[i+1:], start=i+1):
                sum = int(first + second)
                if sum == target:
                    return [i, j]
    
    def twoSumHash(self, nums, target):
        seen_numbers = {}

        for i, num in enumerate(nums):
            number_to_sum = target - num

            if number_to_sum in seen_numbers:
                return [seen_numbers[number_to_sum], i]

            seen_numbers[num] = i

        return None

script = Solution()
# teste = script.twoSum([-1,-2,-3,-4,-5], -8)
teste = script.twoSumHash([3, 3], 6)
print(teste)
