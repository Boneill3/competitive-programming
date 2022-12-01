def main():
  test_cases = int(input())
  for test_case in range(1, test_cases + 1):
    N, R, C, Sr, Sc = map(int, input().split())
    instructions = input()

    final_r, final_c = end_position(N, R, C, Sr, Sc, instructions)
    print(f'Case #{test_case}: {final_r} {final_c}')


def end_position(N, R, C, Sr, Sc, instructions):
  # the robot
  current_loc = (Sr, Sc)

  visited_rows = {}
  visited_cols = {}
  visited_rows[Sr] = (Sc, Sc)
  visited_cols[Sc] = (Sr, Sr)

  for i in range(0, N):
    instruction = instructions[i]
    if instruction == 'N':
      rows = visited_cols.get(current_loc[1])
      for row in rows:
        if row[0] <= current_loc[0] - 1 >= row[1]:
          current_loc[1] = row[0]

      row = visited_cols.get(current_loc[0] + 1)
      for value in row:
        if value[0] <= current_loc[1] >= value[1]:
          current_loc[1] = value[1]
      
    if instruction == 'S':
      current_loc = (current_loc[0] + 1, current_loc[1])
    if instruction == 'E':
      current_loc = (current_loc[0], current_loc[1] + 1)
    if instruction == 'W':
      current_loc = (current_loc[0], current_loc[1] -1)

    visited[current_loc] = True

  final_r, final_c = current_loc[0], current_loc[1]

  return final_r, final_c


if __name__ == '__main__':
  main()
