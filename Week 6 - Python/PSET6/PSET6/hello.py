def main():
    while True:
    # Keep prompting for input untill valid
        try:
            name = input("What is your name?\n")
            if len(name) > 0:
                break
        except ValueError:
            pass

    print ("hello, "+name)

if __name__ == "__main__":
    main()
