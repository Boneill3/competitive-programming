def processcase(case_num):
    (num_candy_bags, num_kids) = tuple(map(int, input().split()))
    candy_count = list(map(int, input().split()))

    total_candy = 0
    for i in range(num_candy_bags):
        total_candy += candy_count[i]
    
    amount_remaining = total_candy % num_kids

    print(f"Case #{case_num}: {amount_remaining}")

num_cases = int(input())
for i in range(num_cases):
    processcase(i+1)