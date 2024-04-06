def get_data():
    n = int(input())
    nums = list(map(int, input().split(" ")))
    count = int(input())
    for q in range(count):
        l = list(map(int, input().split(" ")))
        nums = main(nums, l)

def main(nums, commands):
    if commands[0] == 1:
        i, x = commands[1], commands[2]
        nums[i-1] = x
    else: 
        k = commands[1]
        n2 = nums[::-1][k:][::-1]
        nums = nums[::-1][:k][::-1] + n2

    print(sum(nums))
    return nums

