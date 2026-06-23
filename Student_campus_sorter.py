# Campus Fest - Student Campus Sorter
def detect_campus(usn):

    # Convert USN to uppercase for consistency
    usn = usn.upper()

    # North Campus
    if "CS" in usn:
        return "North Campus (CS)"

    elif "CI" in usn:
        return "North Campus (AI)"

    # South Campus
    elif "EE" in usn:
        return "South Campus (Electrical)"

    elif "EC" in usn:
        return "South Campus (Electronics)"

    elif "ME" in usn:
        return "South Campus (Mechanical)"

    elif "CV" in usn:
        return "South Campus (Civil)"

    # Otherwise
    else:
        return "Unknown Campus"
# Input
u = input("Enter USN: ")
# Function call
a = detect_campus(u)
# Output
print(u, "-->", a)
