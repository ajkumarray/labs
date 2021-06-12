principle = float(input("Enter Principle amount: "))
rate = float(input("Enter rate of interest: "))
time = float(input("Enter time period: "))
Amount = principle * (pow((1 + rate / 100), time))
CI = Amount - principle
print("Compount interest is", CI)
