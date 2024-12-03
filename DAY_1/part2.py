from collections import Counter

left_list = []
right_list = []
with open("../DAY_1/input.txt", "r") as file:
    line = file.readline()
    while line:
        left, right = line.split()
        left_list.append(int(left))
        right_list.append(int(right))
        line = file.readline()

print(left_list)
print(right_list)

# sort left and right list
left_list.sort()
right_list.sort()

# counter how many times a number in left appears in right list
# Count occurrences of each number in the right list
right_count = Counter(right_list)

# Calculate the similarity score
similarity_score = 0
for number in left_list:
    similarity_score += number * right_count.get(number, 0)  # Multiply by the count in the right list

print("Similarity Score:", similarity_score)
"""
80421   40193
69841   31045
47850   64065
63141   52072
32908   83033

"""