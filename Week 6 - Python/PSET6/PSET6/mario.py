def main():
    while True:
    # Keep prompting for input untill valid
        try:
            height = int(input("Height: "))
            if height > 0:
                break
        except ValueError:
            pass

    for space,star in zip(range(height-1,-1,-1), range(1,height+1)):
        print (" "*space+"#"*star+"  "+"#"*star)

if __name__ == "__main__":
    main()
