"""
Problem: You have to make a change of an amount using the smallest possible number of coins.

Amount: $18
Available coins are
  $5 coin
  $2 coin
  $1 coin
There is no limit to the number of each coin you can use.

-> 5+5+5+2+1 = 18

"""
amount = int(input("amount: "))
cnt = int(input("count of coins: "))
coins = []
for i in range(cnt):
    coins.append(int(input(f"{i+1} coin: ")))
coins.sort()
def main():
    s = max(coins)
    print(coins)
    solutions = [max(coins)]
    while s < amount:
        for i in coins:
            if i + s <= amount:
                s += i
                solutions.append(i)
    print(solutions)
main()


