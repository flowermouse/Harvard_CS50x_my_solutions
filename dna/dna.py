import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print('invalid usage')
        exit()

    # TODO: Read database file into a variable
    with open(sys.argv[1], 'r') as database_f:
        database = list(csv.DictReader(database_f))  # 本质上是iterator
        STR = list(database[0])
        STR = STR[1:]

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], 'r') as dna_f:
        dna = dna_f.read()

    # TODO: Find longest match of each STR in DNA sequence
    result = {}
    for each in STR:
        # result[each] = longest_match(dna, each)        #不重复造轮子
        str = each
        matches = 0
        while str in dna:
            matches += 1
            str += each
        result[each] = matches

    # TODO: Check database for matching profiles
    for person in database:
        if all([int(person[str]) == result[str] for str in STR]):  # 注意：这里的字典中的val是string
            print(person['name'])
            return
    print('No match')
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
