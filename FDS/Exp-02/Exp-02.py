'''
Experiment Number 2 : Write a python program to store marks stored in subject "Fundamentals of Data Structure" by
                         N students in the class. Write functions to compute following:
                         1. The average score of the class.
                         2. Highest score and lowest score of the class.
                         3. Count of students who were absent for the test.
                         4. Display mark with highest frequency.
--------------------------------------------------------------
'''
#<---------------------------------------------------------------------------------------->
# Student details
print("------------------------------------------------------")
print("Name: Bhupen Jitendra Chirmader")
print("Class: SE Computer (A)")
print("Roll Number: 22")
print("------------------------------------------------------")
#<---------------------------------------------------------------------------------------->


# Function for average score of the class
def average(listofmarks):
    total = sum(marks for marks in listofmarks if isinstance(marks, int))
    count = len([marks for marks in listofmarks if isinstance(marks, int)])
    avg = total / count if count else 0
    print("Total Marks: ", total)
    print("Average Marks: {:.2f}".format(avg))


# Function for Highest score in the test for the class
def Maximum(listofmarks):
    valid_marks = [marks for marks in listofmarks if isinstance(marks, int)]
    return max(valid_marks) if valid_marks else None


# Function for Lowest score in the test for the class
def Minimum(listofmarks):
    valid_marks = [marks for marks in listofmarks if isinstance(marks, int)]
    return min(valid_marks) if valid_marks else None


# Function for counting the number of students absent for the test
def absentcount(listofmarks):
    return listofmarks.count("A")


# Function for displaying marks with highest frequency
def maxFrequency(listofmarks):
    frequency = {marks: listofmarks.count(marks) for marks in set(listofmarks) if isinstance(marks, int)}
    mark = max(frequency, key=frequency.get) if frequency else None
    return mark, frequency.get(mark, 0)


# Main function
marksinFDS = []
numberofstudents = int(input("Enter total number of students: "))
for i in range(numberofstudents):
    marks_input = input(f"Enter marks of student {i + 1} (enter 'A' for absent): ")
    marks = int(marks_input) if marks_input.isdigit() else "A"
    marksinFDS.append(marks)

flag = 1
while flag == 1:
    print("\n\n--------------------MENU--------------------\n")
    print("1. Total and Average Marks of the Class")
    print("2. Highest and Lowest Marks in the Class")
    print("3. Number of Students absent for the test")
    print("4. Marks with Highest Frequency")
    print("5. Exit\n")
    ch = int(input("Enter your Choice (from 1 to 5): "))

    if ch == 1:
        average(marksinFDS)
    elif ch == 2:
        print("Highest Score in Class:", Maximum(marksinFDS))
        print("Lowest Score in Class:", Minimum(marksinFDS))
    elif ch == 3:
        print("Number of Students absent in the test:", absentcount(marksinFDS))
    elif ch == 4:
        mark, freq = maxFrequency(marksinFDS)
        if mark is not None:
            print(f"Highest frequency is of marks {mark} that appears {freq} times.")
        else:
            print("No marks to display frequency.")
    elif ch == 5:
        print("Thanks for using this program!")
        break
    else:
        print("!!Wrong Choice!!")

    a = input("Do you want to continue (yes/no): ")
    flag = 1 if a.lower() == "yes" else 0
