def number_of_record_breaking_days(number_of_days, vistors):
  record_breaking_days = 0

  current_max = 0
  for i in range(0, number_of_days):
    # Edge case first
    if i == 0 and number_of_days > 1:
      if vistors[i] > vistors[i+1]:
        record_breaking_days += 1
    
    elif i == number_of_days - 1:
      if vistors[i] > current_max:
        record_breaking_days += 1

    # Typical case
    elif vistors[i] > current_max and vistors[i] > vistors[i+1]:
      record_breaking_days += 1
    
    if vistors[i] > current_max:
      current_max = vistors[i]

  return record_breaking_days

def main():
  test_cases = int(input())
  for test_case in range(1, test_cases + 1, 1):
    number_of_days = int(input())
    vistors = list(map(int, input().split()))
    ans = number_of_record_breaking_days(number_of_days, vistors)

    print("Case #{}: {}".format(test_case, ans))

if __name__ == "__main__":
  main()
