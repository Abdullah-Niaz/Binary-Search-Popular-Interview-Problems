from collections import defaultdict


def groupAnagrams(strs):
    # Create a dictionary where values are lists
    anagram_groups = defaultdict(list)

    # Iterate over each string in the input list
    for s in strs:
        sorted_str = ''.join(sorted(s))  # Sort the string to create a key
        # Group anagrams by the sorted string
        anagram_groups[sorted_str].append(s)

    # Return all the values (grouped anagrams) as a list of lists
    return list(anagram_groups.values())


# Test cases
strs1 = ["eat", "tea", "tan", "ate", "nat", "bat"]
print(groupAnagrams(strs1))

strs2 = [""]
print(groupAnagrams(strs2))

strs3 = ["a"]
print(groupAnagrams(strs3))
