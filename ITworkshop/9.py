principle = float(input("Enter principle amount: "))
rate = float(input("Enter interest rate: "))
time = float(input("Enter time period(in years): "))

amount = principle * pow((1 + rate / 100), time) - principle
print("Compound Interest generated is: ", amount)
